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

#include <algorithm>
#include <fstream>
#include <float.h>
#include <list>
#include <string>

using std::list;
using std::ifstream;
using std::sort;
using std::find;
using std::string;

/* Isotonic models for estimating latency */
static ulint *tpcc_work_wait_latency = NULL;
static ulint *tpcc_estimate_latency = NULL;
static ulint *new_order_work_wait_latency = NULL;
static ulint *new_order_estimate_latency = NULL;
static ulint *payment_work_wait_latency = NULL;
static ulint *payment_estimate_latency = NULL;
static ulint *delivery_work_wait_latency = NULL;
static ulint *delivery_estimate_latency = NULL;
static ulint *stock_level_work_wait_latency = NULL;
static ulint *stock_level_estimate_latency = NULL;

static ulint tpcc_length_latency = 0;
static ulint new_order_length_latency = 0;
static ulint payment_length_latency = 0;
static ulint delivery_length_latency = 0;
static ulint stock_level_length_latency = 0;

/* Isotonic models for estimating wait time */
static ulint *tpcc_work_wait_wait = NULL;
static ulint *tpcc_estimate_wait = NULL;
static ulint *new_order_work_wait_wait = NULL;
static ulint *new_order_estimate_wait = NULL;
static ulint *payment_work_wait_wait = NULL;
static ulint *payment_estimate_wait = NULL;
static ulint *delivery_work_wait_wait = NULL;
static ulint *delivery_estimate_wait = NULL;
static ulint *stock_level_work_wait_wait = NULL;
static ulint *stock_level_estimate_wait = NULL;

static ulint tpcc_length_wait = 0;
static ulint new_order_length_wait = 0;
static ulint payment_length_wait = 0;
static ulint delivery_length_wait = 0;
static ulint stock_level_length_wait = 0;

static
string
lock_get_mode(
  lock_t *lock);

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
  read_isotonic("isotonics/latency_tpcc", tpcc_work_wait_latency,
                tpcc_estimate_latency, tpcc_length_latency);
  read_isotonic("isotonics/latency_new_order", new_order_work_wait_latency,
                new_order_estimate_latency, new_order_length_latency);
  read_isotonic("isotonics/latency_payment", payment_work_wait_latency,
                payment_estimate_latency, payment_length_latency);
  read_isotonic("isotonics/latency_delivery", delivery_work_wait_latency,
                delivery_estimate_latency, delivery_length_latency);
  read_isotonic("isotonics/latency_stock_level", stock_level_work_wait_latency,
                stock_level_estimate_latency, stock_level_length_latency);
  
  read_isotonic("isotonics/wait_tpcc", tpcc_work_wait_wait,
                tpcc_estimate_wait, tpcc_length_wait);
  read_isotonic("isotonics/wait_new_order", new_order_work_wait_wait,
                new_order_estimate_wait, new_order_length_wait);
  read_isotonic("isotonics/wait_payment", payment_work_wait_wait,
                payment_estimate_wait, payment_length_wait);
  read_isotonic("isotonics/wait_delivery", delivery_work_wait_wait,
                delivery_estimate_wait, delivery_length_wait);
  read_isotonic("isotonics/wait_stock_level", stock_level_work_wait_wait,
                stock_level_estimate_wait, stock_level_length_wait);
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
estimate_wait(
  ulint time_so_far,
  transaction_type type)
{
  ulint *so_far = NULL;
  ulint *estimate = NULL;
  ulint length = 0;
  
  switch (type) {
    case NONE:
    case ORDER_STATUS:
      so_far = tpcc_work_wait_wait;
      estimate = tpcc_estimate_wait;
      length = tpcc_length_wait;
    case NEW_ORDER:
      so_far = new_order_work_wait_wait;
      estimate = new_order_estimate_wait;
      length = new_order_length_wait;
      break;
    case PAYMENT:
      so_far = payment_work_wait_wait;
      estimate = payment_estimate_wait;
      length = payment_length_wait;
      break;
    case DELIVERY:
      so_far = delivery_work_wait_wait;
      estimate = delivery_estimate_wait;
      length = delivery_length_wait;
      break;
    case STOCK_LEVEL:
      so_far = stock_level_work_wait_wait;
      estimate = stock_level_estimate_wait;
      length = stock_level_length_wait;
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
  return result - time_so_far;
}

/*************************************************************//**
Estimate remaining time given total time so far. */
UNIV_INTERN
ulint
estimate_latency(
  ulint time_so_far,
  transaction_type type)
{
  ulint *so_far = NULL;
  ulint *estimate = NULL;
  ulint length = 0;
  
  switch (type) {
    case NONE:
    case ORDER_STATUS:
      so_far = tpcc_work_wait_latency;
      estimate = tpcc_estimate_latency;
      length = tpcc_length_latency;
    case NEW_ORDER:
      so_far = new_order_work_wait_latency;
      estimate = new_order_estimate_latency;
      length = new_order_length_latency;
      break;
    case PAYMENT:
      so_far = payment_work_wait_latency;
      estimate = payment_estimate_latency;
      length = payment_length_latency;
      break;
    case DELIVERY:
      so_far = delivery_work_wait_latency;
      estimate = delivery_estimate_latency;
      length = delivery_length_latency;
      break;
    case STOCK_LEVEL:
      so_far = stock_level_work_wait_latency;
      estimate = stock_level_estimate_latency;
      length = stock_level_length_latency;
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
  return result - time_so_far;
}

/*************************************************************//**
Calculat the variance of a list of numbers. */
static
double
var(
  vector<ulint> &wait_times)
{
  double mean = 0;
  double variance = 0;
  
  TraceTool::get_instance()->update_wtv(wait_times[0], mean, variance);
  
  for (ulint index = 1; index < wait_times.size(); ++index)
  {
    TraceTool::get_instance()->update_wtv(wait_times[index], mean, variance, mean, variance);
  }
  
  return variance;
}

/*************************************************************//**
Calculate the cumulative sum of latency for the list of given locks. */
static
void
cumsum(
  vector<lock_t *> &locks,
  vector<ulint> &rolling_sum)
{
  ulint sum_of_previous_process_time = 0;
  int previous_ranking = 0;
  ulint max_process = 0;
  
  for (ulint index = 0, size = locks.size(); index < size; ++index)
  {
    lock_t *lock = locks[index];
    
    if (lock->ranking == previous_ranking)
    {
      if (lock->process_time > max_process)
      {
        max_process = lock->process_time;
      }
    }
    else
    {
      sum_of_previous_process_time += max_process;
      max_process = lock->process_time;
      previous_ranking = lock->ranking;
    }
    
    rolling_sum.push_back(lock->total_wait + sum_of_previous_process_time);
  }
}

static
bool
is_redundant(
  vector<int> &rankings,
  ulint num_of_ranking)
{
  vector<bool> rank_exists(num_of_ranking, false);
  int max_rank = 0;
  for (ulint index = 0, size = rankings.size(); index < size; ++index)
  {
    int ranking = rankings[index];
    rank_exists[ranking] = true;
    
    if (ranking > max_rank)
    {
      max_rank = ranking;
    }
  }
  
  for (int ranking = 1; ranking < max_rank; ++ranking)
  {
    if (!rank_exists[ranking])
    {
      return true;
    }
  }
  return false;
}

static
void
enumerate_rankings(
  vector<int> &rankings,
  int start,
  int end,
  list<vector<int> > &ranking_enumerations)
{
  for (int ranking = 0; ranking <= end + 1; ++ranking)
  {
    rankings[start] = ranking;
    if (start == end)
    {
      if (!is_redundant(rankings, end + 2))
      {
        ranking_enumerations.push_back(rankings);
      }
    }
    else
    {
      enumerate_rankings(rankings, start + 1, end, ranking_enumerations);
    }
  }
}

static
bool
lock_compatible(
  vector<lock_t *> &locks,
  lock_t *lock)
{
  for (ulint index = 0, size = locks.size(); index < size; ++index)
  {
    if (lock_has_to_wait(lock, locks[index]))
    {
      return false;
    }
  }
  return true;
}

static
string
lock_get_mode(
  lock_t *lock)
{
  string mode;
  if ((LOCK_MODE_MASK & lock->type_mode) == LOCK_X)
  {
    mode.append("X");
  }
  else
  {
    mode.append("R");
  }
  if (lock->type_mode & LOCK_INSERT_INTENTION)
  {
    mode.append("I");
  }
  else if (lock->type_mode & LOCK_GAP)
  {
    mode.append("G");
  }
  else if (lock->type_mode & LOCK_ORDINARY)
  {
    mode.append("N");
  }
  else if (lock->type_mode & LOCK_REC_NOT_GAP)
  {
    mode.append("R");
  }
  
  switch (lock->trx->type)
  {
    case NEW_ORDER:
      mode.append("O");
      break;
    case PAYMENT:
      mode.append("P");
      break;
    case ORDER_STATUS:
      mode.append("S");
      break;
    case DELIVERY:
      mode.append("D");
      break;
    case STOCK_LEVEL:
      mode.append("L");
      break;
    default:
      mode.append("N");
      break;
  }
  
  return mode;
}

static
void
remove_invalid_ranking(
  vector<lock_t *> &waiting_locks,
  vector<lock_t *> &granted_locks,
  list<vector<int> > &ranking_enumerations)
{
  ulint size = waiting_locks.size();
  
  lock_t **previous_locks = new lock_t *[size + 1];
  
  for (list<vector<int> >::iterator iterator = ranking_enumerations.begin();
       iterator != ranking_enumerations.end(); ++iterator)
  {
    vector<int> &enumeration = *iterator;
    
    if(granted_locks.size() > 0)
    {
      previous_locks[0] = granted_locks.back();
    }
    else
    {
      previous_locks[0] = NULL;
    }
    for (ulint index = 1; index <= size; ++index)
    {
      previous_locks[index] = NULL;
    }
    
    for (ulint index = 0; index < size; ++index)
    {
      int ranking = enumeration[index];
      lock_t *previous_lock = previous_locks[ranking];
      previous_locks[ranking] = waiting_locks[index];
      
      if (previous_lock != NULL &&
          lock_has_to_wait(waiting_locks[index], previous_lock))
      {
        iterator = --ranking_enumerations.erase(iterator);
        break;
      }
    }
  }
  
  delete[] previous_locks;
}

static
bool
compare(
  lock_t *lock1,
  lock_t *lock2)
{
  return lock1->ranking < lock2->ranking;
}

/*************************************************************//**
Find the lock that gives minimum CTV. */
UNIV_INTERN
void
LVM_schedule(
  vector<lock_t *> &waiting_locks,  /*!< waiting locks */
  vector<lock_t *> &granted_locks,  /*!< granted locks */
  vector<lock_t *> &locks_to_grant) /*!< locks to grant */
{
//  bool do_monitor = rand() % 100 < 2;
  
  if (waiting_locks.size() == 0)
  {
    return;
  }
  if (waiting_locks.size() == 1 &&
      granted_locks.size() == 0)
  {
    locks_to_grant.push_back(waiting_locks[0]);
    return;
  }
  
  for (ulint index = 0, size = granted_locks.size();
       index < size; ++index)
  {
    granted_locks[index]->ranking = 0;
    granted_locks[index]->in_batch = true;
  }
  
//  ofstream &log_file = TraceTool::get_instance()->get_log();
  
  vector<lock_t *> all_locks(granted_locks.begin(), granted_locks.end());
  all_locks.insert(all_locks.end(), waiting_locks.begin(), waiting_locks.end());
  
  timespec now = TraceTool::get_time();
  for (ulint index = 0, size = all_locks.size(); index < size; ++index)
  {
    lock_t *lock = all_locks[index];
    lock->time_so_far = TraceTool::difftime(lock->trx->trx_start_time, now);
    lock->process_time = estimate_latency(lock->time_so_far, lock->trx->type);
    lock->total_wait = estimate_wait(lock->time_so_far, lock->trx->type);
  }
  
  vector<int> rankings(waiting_locks.size());
  list<vector<int> > ranking_enumerations;
  enumerate_rankings(rankings, 0, waiting_locks.size() - 1, ranking_enumerations);
  remove_invalid_ranking(waiting_locks, granted_locks, ranking_enumerations);
  ut_a(ranking_enumerations.size() > 0);
  int granted_size = granted_locks.size();
  
  double min_variance = std::numeric_limits<double>::max();
  vector<int> *min_enum = NULL;
  for (list<vector<int> >::iterator iterator = ranking_enumerations.begin();
       iterator != ranking_enumerations.end(); ++iterator)
  {
    vector<int> &enumeration = *iterator;
    for (ulint index = 0, size = enumeration.size(); index < size; ++index)
    {
      waiting_locks[index]->ranking = enumeration[index];
    }
    sort(all_locks.begin() + granted_size, all_locks.end(), compare);
    vector<ulint> rolling_sum;
    cumsum(all_locks, rolling_sum);
    double variance = var(rolling_sum);
    if (variance < min_variance)
    {
      min_variance = variance;
      min_enum = &enumeration;
    }
  }
  
  int smallest_ranking = INT_MAX;
  for (ulint index = 0, size = min_enum->size(); index < size; ++index)
  {
    lock_t *lock = waiting_locks[index];
    lock->ranking = (*min_enum)[index];
    if (lock->ranking < smallest_ranking)
    {
      smallest_ranking = lock->ranking;
      locks_to_grant.clear();
      locks_to_grant.push_back(lock);
    }
    else if (lock->ranking == smallest_ranking)
    {
      locks_to_grant.push_back(lock);
    }
  }
  
//  if (do_monitor)
//  {
//    sort(all_locks.begin() + granted_size, all_locks.end(), compare);
//    log_file << granted_locks.size() << "," << waiting_locks.size() << endl;
//    for (ulint index = 0, size = granted_locks.size(); index < size; ++index)
//    {
//      lock_t *lock = granted_locks[index];
//      log_file << "lock_t lock" << index + 1 << "={" << lock->ranking << "," << lock->time_so_far << "," << lock->process_time << ",'"
//      << lock_get_mode(granted_locks[index]) << "'};" << endl;
//    }
//    log_file << endl;
//
//    for (ulint index = 0, size = waiting_locks.size(); index < size; ++index)
//    {
//      lock_t *lock = waiting_locks[index];
//      log_file << "lock_t lock" << index + 1 << "={" << lock->ranking << "," << lock->time_so_far << "," << lock->process_time << ",'"
//      << lock_get_mode(waiting_locks[index]) << "'};" << endl;
//    }
//    log_file << endl;
//  }
  
  if (granted_locks.size() > 0 &&
      smallest_ranking != 0)
  {
    locks_to_grant.clear();
  }
}

/*************************************************************//**
Clean up resources. */
UNIV_INTERN
void
indi_cleanup()
{
  free(tpcc_work_wait_latency);
  free(tpcc_estimate_latency);
  free(new_order_work_wait_latency);
  free(new_order_estimate_latency);
  free(payment_work_wait_latency);
  free(payment_estimate_latency);
  free(delivery_work_wait_latency);
  free(delivery_estimate_latency);
  free(stock_level_work_wait_latency);
  free(stock_level_estimate_latency);
  
  free(tpcc_work_wait_wait);
  free(tpcc_estimate_wait);
  free(new_order_work_wait_wait);
  free(new_order_estimate_wait);
  free(payment_work_wait_wait);
  free(payment_estimate_wait);
  free(delivery_work_wait_wait);
  free(delivery_estimate_wait);
  free(stock_level_work_wait_wait);
  free(stock_level_estimate_wait);
}

