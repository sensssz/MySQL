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
double
tpcc_estimate(ulint num_locks, ulint work, ulint wait)
{
  double result = -2976129.550262 * num_locks + 1.474113 * work + 0.845159 * wait + 179159173.216593;
  if (result < 0)
  {
    return work + wait;
  }
  else
  {
    return result;
  }
}

static
double
new_order_estimate(ulint num_locks, ulint work, ulint wait)
{
  double result = -5152980.542941 * num_locks + 1.538377 * work + 0.797703 * wait + 240783215.910486;
  if (result < 0)
  {
    return work + wait;
  }
  else
  {
    return result;
  }
}
static
double
payment_estimate(ulint num_locks, ulint work, ulint wait)
{
  double result = -11575590.190602 * num_locks + 1.190319 * work + 0.833996 * wait + 172714956.024506;
  if (result < 0)
  {
    return work + wait;
  }
  else
  {
    return result;
  }
}
static
double
delivery_estimate(ulint num_locks, ulint work, ulint wait)
{
  double result = -5042302.489343 * num_locks + 1.134626 * work + 0.628491 * wait + 485844457.840212;
  if (result < 0)
  {
    return work + wait;
  }
  else
  {
    return result;
  }
}
static
double
stock_level_estimate(ulint num_locks, ulint work, ulint wait)
{
  double result = -475639.543715 * num_locks + 22.781991 * work + 1.191586 * wait + 27762623.428666;
  if (result < 0)
  {
    return work + wait;
  }
  else
  {
    return result;
  }
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
    case NEW_ORDER:
      return new_order_estimate(num_locks, work, wait);
      break;
    case PAYMENT:
      return payment_estimate(num_locks, work, wait);
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

static
double
tpcc_estimate(ulint work, ulint wait)
{
  return 1.087953 * work + 0.871685 * wait + 155858803.591282;
}
static
double
new_order_estimate(ulint work, ulint wait)
{
  return 0.983699 * work + 0.899907 * wait + 164959303.581966;
}
static
double
payment_estimate(ulint work, ulint wait)
{
  return 0.437855 * work + 0.829758 * wait + 148211963.984209;
}
static
double
delivery_estimate(ulint work, ulint wait)
{
  return 0.762453 * work + 0.714653 * wait + 394290913.655502;
}
static
double
stock_level_estimate(ulint work, ulint wait)
{
  return 20.537997 * work + 1.250428 * wait + 734536.530398;
}

/*************************************************************//**
Estimate remaining time given total time so far. */
UNIV_INTERN
ulint
estimate(
  ulint work,
  ulint wait,
  transaction_type type)
{
  switch (type) {
    case NEW_ORDER:
      return new_order_estimate(work, wait);
      break;
    case PAYMENT:
      return payment_estimate(work, wait);
      break;
    case DELIVERY:
      return delivery_estimate(work, wait);
      break;
    case STOCK_LEVEL:
      return stock_level_estimate(work, wait);
      break;
    default:
      return tpcc_estimate(work, wait);
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

/*********************************************************************//**
Gets the wait flag of a lock.
@return LOCK_WAIT if waiting, 0 if not */
UNIV_INLINE
ulint
lock_get_wait(
/*==========*/
  const lock_t* lock) /*!< in: lock */
{
  return(lock->type_mode & LOCK_WAIT);
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
  
  
  vector<lock_t *> all_locks(granted_locks.begin(), granted_locks.end());
  all_locks.insert(all_locks.end(), waiting_locks.begin(), waiting_locks.end());
  
  timespec now = TraceTool::get_time();
  for (ulint index = 0, size = all_locks.size(); index < size; ++index)
  {
    lock_t *lock = all_locks[index];
    trx_t *trx = lock->trx;
    lock->time_so_far = TraceTool::difftime(lock->trx->trx_start_time, now);
    ulint wait_so_far = trx->total_wait_time;
    if (lock_get_wait(lock))
    {
      wait_so_far += TraceTool::difftime(lock->wait_start, now);
    }
    ulint work_so_far = lock->time_so_far - wait_so_far;
    ulint estimation = estimate(work_so_far, wait_so_far, lock->trx->type);
    if (estimation > lock->time_so_far)
    {
      lock->process_time = estimation - lock->time_so_far;
    }
    else
    {
      lock->process_time = lock->time_so_far;
    }
    
    if (lock->trx->type != NONE &&
        trx->is_user_trx)
    {
      TraceTool::get_instance()->add_estimate_record(estimation, lock->trx->transaction_id);
    }
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
