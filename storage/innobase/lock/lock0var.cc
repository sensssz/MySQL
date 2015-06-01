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

static
ulint
tpcc_estimate(ulint num_locks, ulint work, ulint wait)
{
  return 5488089.615703 * num_locks + 1.942222 * work + 0.766192 * wait + 298666199.000513;
}

static
ulint
new_order_estimate(ulint num_locks, ulint work, ulint wait)
{
  return 9849050.582090 * num_locks + 2.393067 * work + 0.788607 * wait + 293570030.003463;
}

static
ulint
payment_estimate(ulint num_locks, ulint work, ulint wait)
{
  return 148662428.974091 * num_locks + 1.548239 * work + 0.736832 * wait + 0.000000;
}

static
ulint
delivery_estimate(ulint num_locks, ulint work, ulint wait)
{
  return -13306266.992916 * num_locks + 2.613634 * work + 0.652131 * wait + 907693255.087883;
}

static
ulint
stock_level_estimate(ulint num_locks, ulint work, ulint wait)
{
  return -444879.387608 * num_locks + 0.866669 * work + 0.944012 * wait + 193479572.897411;
}

/*************************************************************//**
Estimate remaining time given total time so far. */
UNIV_INTERN
ulint
estimate(
         ulint num_locks,
         ulint work,
         ulint wait,
         transaction_type type)
{
  switch (type) {
    case NONE:
      return tpcc_estimate(num_locks, work, wait);
    case NEW_ORDER:
      return new_order_estimate(num_locks, work, wait);
      break;
    case PAYMENT:
      return payment_estimate(num_locks, work, wait);
      break;
    case ORDER_STATUS:
      return tpcc_estimate(num_locks, work, wait);
      break;
    case DELIVERY:
      return delivery_estimate(num_locks, work, wait);
      break;
    case STOCK_LEVEL:
      return stock_level_estimate(num_locks, work, wait);
      break;
    default:
      return tpcc_estimate(num_locks, work, wait);
      break;
  }
}

/*************************************************************//**
Calculat the variance of a list of numbers. */
static
double
var(
  vector<ulint> &numbers)
{
  double mean = 0;
  for (ulint index = 0, size = numbers.size(); index < size; ++index)
  {
    mean += numbers[index];
  }
  mean /= numbers.size();
  
  double variance = 0;
  for (ulint index = 0, size = numbers.size(); index < size; ++index)
  {
    double difference = numbers[index] - mean;
    variance += difference * difference;
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
    
    rolling_sum.push_back(lock->time_so_far + lock->process_time + sum_of_previous_process_time);
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
  
  
  timespec now = TraceTool::get_time();
  for (ulint index = 0, size = waiting_locks.size(); index < size; ++index)
  {
    lock_t *lock = waiting_locks[index];
    trx_t *trx = lock->trx;
    lock->time_so_far = TraceTool::difftime(lock->trx->trx_start_time, now);
    ulint wait_so_far = trx->total_wait_time + TraceTool::difftime(lock->wait_start, now);
    ulint work_so_far = lock->time_so_far - wait_so_far;
    ulint num_locks = UT_LIST_GET_LEN(lock->trx->lock.trx_locks);
    ulint estimation = estimate(num_locks, work_so_far, wait_so_far, lock->trx->type);
    lock->process_time = estimation - lock->time_so_far;
    
    if (lock->trx->type != NONE &&
        lock->trx->real_transaction_id != NULL &&
        lock->trx->transaction_id == *(lock->trx->real_transaction_id))
    {
      TraceTool::get_instance()->add_estimate_record(estimation, lock->trx->transaction_id);
    }
  }
  
  vector<lock_t *> all_locks(granted_locks.begin(), granted_locks.end());
  all_locks.insert(all_locks.end(), waiting_locks.begin(), waiting_locks.end());
  
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
}
