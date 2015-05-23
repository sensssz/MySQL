/*
 @file lock/lock0var.cc
 The transaction lock system
 */
#define LOCK_MODULE_IMPLEMENTATION

#include "lock0lock.h"
#include "lock0priv.h"
#include "lock0var.h"
#include "trx0trx.h"
#include "trace_tool.h"

#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <float.h>
#include <list>

// 0.05, 0.1, 0.2, 0.5, 1, 2, 5
#define RELATIVE_ERROR 0.1

using std::list;
using std::unordered_map;
using std::ifstream;
using std::sort;
using std::find;

static ulint *tpcc_work_wait = NULL;
static ulint *tpcc_estimated = NULL;
static ulint *new_order_work_wait = NULL;
static ulint *new_order_estimated = NULL;
static ulint *payment_work_wait = NULL;
static ulint *payment_estimated = NULL;
static ulint *order_status_work_wait = NULL;
static ulint *order_status_estimated = NULL;
static ulint *delivery_work_wait = NULL;
static ulint *delivery_estimated = NULL;
static ulint *stock_level_work_wait = NULL;
static ulint *stock_level_estimated = NULL;

static ulint tpcc_length = 0;
static ulint new_order_length = 0;
static ulint payment_length = 0;
static ulint order_status_length = 0;
static ulint delivery_length = 0;
static ulint stock_level_length = 0;

bool double_equals(double a, double b, double epsilon = 0.00001)
{
  return std::abs(a - b) < epsilon;
}

struct parameters
{
  ulint k;
  double heu;
  
  bool operator==(const struct parameters &another) const
  {
    return k == another.k && double_equals(heu, another.heu);
  }
};
typedef struct parameters parameters;
namespace std
{
  template<>
  struct hash<parameters>
  {
    ulint operator()(const struct parameters &parameter) const
    {
      size_t hash1 = hash<long>()(parameter.k);
      size_t hash2 = hash<double>()(parameter.heu);
      return hash1 ^ hash2;
    }
  };
}

struct record
{
  ulint space_id;
  ulint page_no;
  ulint heap_no;
  
  bool operator==(const struct record &another) const
  {
    return space_id == another.space_id &&
           page_no == another.page_no &&
           heap_no == another.heap_no;
  }
};
typedef struct record record;
namespace std
{
  template<>
  struct hash<record>
  {
    ulint operator()(const record &record) const
    {
      size_t hash1 = hash<long>()(record.space_id);
      size_t hash2 = hash<long>()(record.page_no);
      size_t hash3 = hash<long>()(record.heap_no);
      return hash1 ^ hash2 ^ hash3;
    }
  };
}

static void g_starter(ulint size, double *betas, double *gammas, double *beta_stars, bool *solution);
static double g_recursive(parameters &para, ulint size,
                          double *betas, double *gammas, double *beta_stars,
                          unordered_map<parameters, double> &cache,
                          bool *solution);
static void h_starter(ulint size, double *betas, double *gammas, double *gamma_stars, bool *solution);
static double h_recursive(parameters &para, ulint size,
                          double *betas, double *gammas, double *gamma_stars,
                          unordered_map<parameters, double> &cache,
                          bool *solution);

static
void
read_isotonic(
  const char *name,
  ulint *&so_far,
  ulint *&estimated,
  ulint &length)
{
  ifstream isotonic_file(name);
  isotonic_file >> length >> length;
//  TraceTool::get_instance()->get_log() << length << endl;
  so_far = (ulint *)malloc(sizeof(ulint) * length);
  estimated = (ulint *)malloc(sizeof(ulint) * length);
  double x = 0;
  double y = 0;
  for (ulint index = 0; index < length; ++index)
  {
    isotonic_file >> x >> y;
    so_far[index] = x;
    estimated[index] = y;
  }
  isotonic_file.close();
}

/*************************************************************//**
Do initilization for the min-variance scheduling algorithm. */
UNIV_INTERN
void
indi_init()
{
  read_isotonic("isotonic_original", tpcc_work_wait,
                tpcc_estimated, tpcc_length);
  read_isotonic("isotonic_new_order", new_order_work_wait,
                new_order_estimated, new_order_length);
  read_isotonic("isotonic_payment", payment_work_wait,
                payment_estimated, payment_length);
  read_isotonic("isotonic_order_status", order_status_work_wait,
                order_status_estimated, order_status_length);
  read_isotonic("isotonic_delivery", delivery_work_wait,
                delivery_estimated, delivery_length);
  read_isotonic("isotonic_stock_level", stock_level_work_wait,
                stock_level_estimated, stock_level_length);
}

/*************************************************************//**
Do a binary search in the separators to find the bucket for the specific
remaining time. */
ulint
binary_search(
  ulint *array,
  ulint length,
  double target)  /*!< estiamted remaining time */
{
  int left = 0;
  int right = length - 1;
  int middle = -1;
  
  if (target <= array[0])
  {
    return 0;
  }
  else if (target >= array[length - 1])
  {
    return length - 1;
  }
  
  while (left <= right)
  {
    int new_middle = (left + right) / 2;
    if (new_middle == middle)
    {
      break;
    }
    else
    {
      middle = new_middle;
    }
    if (target < array[middle])
    {
      right = middle;
    }
    else if (target >= array[middle + 1])
    {
      left = middle + 1;
    }
    else
    {
      // array[middle] <= target < array[middle + 1]
      return middle;
    }
  }
  
  return length - 1;
}

/*************************************************************//**
Estimate remaining time given total time so far. */
UNIV_INTERN
ulint
estimate(
  ulint time_so_far,
  transaction_type type)
{
  ulint *so_far = NULL;
  ulint *estimate = NULL;
  ulint length = 0;
  
  switch (type) {
    case NONE:
      so_far = tpcc_work_wait;
      estimate = tpcc_estimated;
      length = tpcc_length;
    case NEW_ORDER:
      so_far = new_order_work_wait;
      estimate = new_order_estimated;
      length = new_order_length;
      break;
    case PAYMENT:
      so_far = payment_work_wait;
      estimate = payment_estimated;
      length = payment_length;
      break;
    case ORDER_STATUS:
      so_far = order_status_work_wait;
      estimate = order_status_estimated;
      length = order_status_length;
      break;
    case DELIVERY:
      so_far = delivery_work_wait;
      estimate = delivery_estimated;
      length = delivery_length;
      break;
    case STOCK_LEVEL:
      so_far = stock_level_work_wait;
      estimate = stock_level_estimated;
      length = stock_level_length;
      break;
    default:
      break;
  }
  
  ulint y_index = binary_search(so_far, length, time_so_far);
  if (y_index == length - 1)
  {
    y_index = length - 2;
  }
  ulint result = estimate[y_index + 1];
  return result;
}

static
bool
compare(lock_t *lock1, lock_t *lock2)
{
  return lock1->process_time < lock2->process_time;
}


static
void
round(
  double *array,
  int length,
  int start,
  int end)
{
  double sum = 0;
  for (int index = start; index < end; ++index)
  {
    sum += array[index];
  }
  double mean = sum / (length - 2);
  double round_factor = RELATIVE_ERROR * mean / 2;
  for (int index = start; index < end; ++index)
  {
    array[index] = (int) (array[index] / round_factor);
  }
}

static
void
g_starter(ulint size, double *betas, double *gammas, double *beta_stars, bool *solution)
{
  parameters para;
  para.k = size - 2;
  para.heu = 0;

  round(betas, size, 2, size);
  beta_stars[size - 2] = betas[size - 1];
  for (ulint index = size - 3; index > 0; --index)
  {
    beta_stars[index] = beta_stars[index + 1] + betas[index + 1];
  }
  
  unordered_map<parameters, double> cache;
  g_recursive(para, size, betas, gammas, beta_stars, cache, solution);
}

static
double
g_recursive(parameters &para, ulint size,
            double *betas, double *gammas, double *beta_stars,
            unordered_map<parameters, double> &cache,
            bool *solution)
{
  ulint k = para.k;
  double beta = para.heu;
  // g(1) = 0
  if (k == 0)
  {
    return 0;
  }
  unordered_map<parameters, double>::iterator iterator = cache.find(para);
  if (iterator != cache.end())
  {
    // Already calculated the value for this pair of parameters
    return iterator->second;
  }
  
  parameters new_para_before;
  new_para_before.k = k - 1;
  new_para_before.heu = beta;
  double recursive_before = g_recursive(new_para_before, size, betas, gammas, beta_stars, cache, solution);
  double put_before = recursive_before + gammas[k] * beta;
  
  parameters new_para_after;
  new_para_after.k = k - 1;
  new_para_after.heu = beta + betas[k];
  double recursive_after = g_recursive(new_para_after, size, betas, gammas, beta_stars, cache, solution);
  double put_after = recursive_after + gammas[k] * (beta_stars[k] - beta);
  
  cache[new_para_before] = recursive_before;
  cache[new_para_after] = recursive_after;
  
  if (put_before > put_after)
  {
    if (beta == 0)
    {
      solution[k] = 0;
    }
    return put_before;
  }
  else
  {
    if (beta == 0)
    {
      solution[k] = 1;
    }
    return put_after;
  }
}

static
void
h_starter(ulint size, double *betas, double *gammas, double *gamma_stars, bool *solution)
{
  parameters para;
  para.k = 2;
  para.heu = 0;
  
  round(gammas, size, 1, size - 1);
  gamma_stars[1] = gammas[1];
  for (ulint index = 2; index < size - 1; ++index)
  {
    gamma_stars[index] = gamma_stars[index - 1] + gammas[index];
  }
  
  unordered_map<parameters, double> cache;
  h_recursive(para, size, betas, gammas, gamma_stars, cache, solution);
}

static
double
h_recursive(parameters &para, ulint size,
            double *betas, double *gammas, double *gamma_stars,
            unordered_map<parameters, double> &cache,
            bool *solution)
{
  ulint k = para.k;
  double gamma = para.heu;
  // h(n + 1) = 0
  if (k == size)
  {
    return 0;
  }
  unordered_map<parameters, double>::iterator iterator = cache.find(para);
  if (iterator != cache.end())
  {
    // Already calculated the value for this pair of parameters
    return iterator->second;
  }
  
  parameters new_para_before;
  new_para_before.k = k + 1;
  new_para_before.heu = gamma;
  double recursive_before = h_recursive(new_para_before, size, betas, gammas, gamma_stars, cache, solution);
  double put_before = recursive_before + betas[k] * gamma;
  
  parameters new_para_after;
  new_para_after.k = k + 1;
  new_para_after.heu = gamma + gammas[k];
  double recursive_after = h_recursive(new_para_after, size, betas, gammas, gamma_stars, cache, solution);
  double put_after = recursive_after + betas[k] * (gamma_stars[k - 1] - gamma);
  
  cache[new_para_before] = recursive_before;
  cache[new_para_after] = recursive_after;
  
  if (put_before > put_after)
  {
    if (gamma == 0)
    {
      solution[k] = 0;
    }
    return put_before;
  }
  else
  {
    if (gamma == 0)
    {
      solution[k] = 1;
    }
    return put_after;
  }
}

/*************************************************************//**
Find the lock that gives minimum CTV. */
UNIV_INTERN
lock_t *
CTV_schedule(vector<lock_t *> &locks) /*!< candidate locks */
{
  if (locks.size() == 0)
  {
    return NULL;
  }
  else if (locks.size() == 1)
  {
    return locks[0];
  }
  
//  ofstream &log_file = TraceTool::get_instance()->get_log();
  ulint size = locks.size() - 1;
  double *as = new double[size];
  double *betas = new double[size];
  double *beta_stars = new double[size];
  double *gammas = new double[size];
  double *gamma_stars = new double[size];
  bool *quadratic_solution = new bool[size + 1];
  lock_t **final_schedule = new lock_t *[size + 1];
  
  timespec now = TraceTool::get_time();
  // Note that size here is actually length - 1
  for (ulint index = 0; index <= size; ++index)
  {
    lock_t *lock = locks[index];
    ulint time_so_far = TraceTool::difftime(lock->trx->trx_start_time, now);
    lock->process_time = estimate(time_so_far, lock->trx->type);
  }
//  log_file << "estimated process time" << endl;
  sort(locks.begin(), locks.end(), compare);
//  log_file << "locks sorted" << endl;
  
  // The last one is always at the first place
  quadratic_solution[size - 1] = 0;
  quadratic_solution[0] = 0;
  quadratic_solution[1] = 0;
  
  if (size + 1 > 3)
  {
    // Calculate betas and gammas
    for (ulint index = 0; index < size; ++index)
    {
      ulint sum = 0;
      ulint process_time = locks[index]->process_time;
      for (ulint i = 0; i < index; ++i)
      {
        sum += locks[i]->process_time;
      }
      as[index] = process_time + sum / 2.0;
      // We need to use index + 1 for calculating beta and gamma
      betas[index] = (size - index - 1) * process_time + 2 * as[index];
      gammas[index] = (index + 1 + 1) * process_time - 2 * as[index];
    }
//    log_file << "beta and gamma calcualted" << endl;
    
    beta_stars[size - 2] = betas[size - 1];
    gamma_stars[1] = gammas[1];
    // Calculate beta stars and gamma stars
    for (ulint index = size - 3; index > 0; --index)
    {
      beta_stars[index] = beta_stars[index + 1] + betas[index + 1];
    }
    for (ulint index = 2; index < size - 1; ++index)
    {
      gamma_stars[index] = gamma_stars[index - 1] + gammas[index];
    }
//    log_file << "beta_star and gamma_star calculated" << endl;
    
    if (beta_stars[1] < gamma_stars[size - 2])
    {
//      log_file << "using beta" << endl;
      g_starter(size, betas, gammas, beta_stars, quadratic_solution);
    }
    else
    {
//      log_file << "using gamma" << endl;
      h_starter(size, betas, gammas, gamma_stars, quadratic_solution);
    }
  }
  
  int schedule_index = 1;
  final_schedule[0] = locks.back();
  for (int solution_index = size - 1; solution_index > 0; --solution_index)
  {
    if (quadratic_solution[solution_index] == 0)
    {
      // Should be moved before the shortest job
      final_schedule[schedule_index++] = locks[solution_index];
    }
  }
  final_schedule[schedule_index++] = locks[0];
  for (ulint solution_index = 1; solution_index < size; ++solution_index)
  {
    // Should be moved after the shortest job
    if (quadratic_solution[solution_index] == 1)
    {
      final_schedule[schedule_index++] = locks[solution_index];
    }
  }
  
//  for (ulint index = 0; index <= size; ++index)
//  {
//    log_file << final_schedule[index]->process_time << ",";
//    final_schedule[index]->ranking = index;
//  }
//  log_file << endl;
  
  delete[] as;
  delete[] betas;
  delete[] beta_stars;
  delete[] gammas;
  delete[] gamma_stars;
  delete[] quadratic_solution;
  delete[] final_schedule;
  
  return locks[0];
}

/*************************************************************//**
Clean up resources. */
UNIV_INTERN
void
indi_cleanup()
{
  free(tpcc_work_wait);
  free(tpcc_estimated);
  free(new_order_work_wait);
  free(new_order_estimated);
  free(payment_work_wait);
  free(payment_estimated);
  free(order_status_work_wait);
  free(order_status_estimated);
  free(delivery_work_wait);
  free(delivery_estimated);
  free(stock_level_work_wait);
  free(stock_level_estimated);
}

