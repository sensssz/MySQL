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

#define RELATIVE_ERROR 0.05

using std::unordered_map;
using std::sort;
using std::ifstream;

static ulint *work_wait_so_far = NULL;
static ulint *estimated_work_wait = NULL;
static ulint length = 0;

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
  }
}

static unordered_map<record, vector<lock_t *> *> lock_candidates;

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

/*************************************************************//**
Do initilization for the min-variance scheduling algorithm. */
UNIV_INTERN
void
indi_init()
{
  ifstream isotonic_file("isotonic_original");
  isotonic_file >> length >> length;
  work_wait_so_far = (ulint *)malloc(sizeof(ulint) * length);
  estimated_work_wait = (ulint *)malloc(sizeof(ulint) * length);
  ulint x = 0;
  ulint y = 0;
  for (ulint index = 0; index < length; ++index)
  {
    isotonic_file >> x >> y;
    work_wait_so_far[index] = x;
    estimated_work_wait[index] = y;
  }
  isotonic_file.close();
  
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
  
  while (left <= right)
  {
    int middle = (left + right) / 2;
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
  ulint time_so_far)
{
  ulint y_index = binary_search(work_wait_so_far, length, time_so_far);
  if (y_index == length - 1)
  {
    y_index = length - 2;
  }
  return estimated_work_wait[y_index + 1];
}

/*************************************************************//**
Estimate remaining time given total time so far. */
UNIV_INTERN
void
set_lock_candidate(
  vector<lock_t *>  &locks,     /*!< candidates */
  ulint             space_id,   /*!< space id of the record */
  ulint             page_no,    /*!< page no of the record */
  ulint             heap_no)    /*!< heap no of the record */
{
  record record;
  record.space_id = space_id;
  record.page_no = page_no;
  record.heap_no = heap_no;
  CTV_schedule(locks);
  vector<lock_t *> *lock_vector = lock_candidates[record];
  lock_vector->insert(lock_vector->end(), locks);
}

/*************************************************************//**
Return the next lock from the CTV schedule.
NULL if runs out of locks. */
UNIV_INTERN
lock_t *
next_lock(
  ulint             space_id,   /*!< space id of the record */
  ulint             page_no,    /*!< page no of the record */
  ulint             heap_no)    /*!< heap no of the record */
{
  record record;
  record.space_id = space_id;
  record.page_no = page_no;
  record.heap_no = heap_no;
  unordered_map<record, vector<lock_t *> *>::iterator ite = lock_candidates.find(record);
  if (ite == lock_candidates.end())
  {
    lock_candidates[record] = new vector<lock_t *>;
  }
  vector<lock_t *> *lock_vector = lock_candidates[record];
  if (lock_vector == NULL)
  {
    lock_candidates[record] = new vector<lock_t *>;
    return NULL;
  }
  else
  {
    lock_t *lock = lock_vector->back();
    lock_vector->pop_back();
    return lock;
  }
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
  for (int index = size - 3; index > 0; --index)
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
  for (int index = 2; index < size - 1; ++index)
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
void
CTV_schedule(vector<lock_t *> &locks) /*!< candidate locks */
{
  if (locks.size() < 2)
  {
    return;
  }
  
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
    lock->process_time = estimate(time_so_far);
  }
  sort(locks.begin(), locks.end(), compare);
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
  
  beta_stars[size - 2] = betas[size - 1];
  gamma_stars[1] = gammas[1];
  // Calculate beta stars and gamma stars
  for (int index = size - 3; index > 0; --index)
  {
    beta_stars[index] = beta_stars[index + 1] + betas[index + 1];
  }
  for (int index = 2; index < size - 1; ++index)
  {
    gamma_stars[index] = gamma_stars[index - 1] + gammas[index];
  }
  // The last one is always at the first place
  quadratic_solution[size - 1] = 0;
  quadratic_solution[0] = 0;
  quadratic_solution[1] = 0;
  
  if (size + 1 > 3)
  {
    if (beta_stars[1] < gamma_stars[size - 2])
    {
      g_starter(size, betas, gammas, beta_stars, quadratic_solution);
    }
    else
    {
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
  for (int solution_index = 1; solution_index < size; ++solution_index)
  {
    // Should be moved after the shortest job
    if (quadratic_solution[solution_index] == 1)
    {
      final_schedule[schedule_index++] = locks[solution_index];
    }
  }
  
  for (int index = 0; index <= size; ++index)
  {
    // Store the locks in reverse order
    locks[size - index] = final_schedule[index];
  }
  
  delete[] as;
  delete[] betas;
  delete[] beta_stars;
  delete[] gammas;
  delete[] gamma_stars;
  delete[] quadratic_solution;
  delete[] final_schedule;
}

/*************************************************************//**
Clean up resources. */
UNIV_INTERN
void
indi_cleanup()
{
  free(work_wait_so_far);
  free(estimated_work_wait);
  
  for (unordered_map<record, vector<lock_t *> *>::iterator iterator = lock_candidates.begin();
       iterator != lock_candidates.end(); ++iterator)
  {
    delete iterator->second;
  }
}

