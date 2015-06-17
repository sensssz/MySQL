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
#include <utility>

using std::list;
using std::ifstream;
using std::sort;
using std::find;
using std::string;
using std::pair;

typedef pair<lock_t *, lock_t *> pair_t;

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

static
double
new_order_estimate(ulint work, ulint wait, ulint num_locks)
{
  double result = 0.391422 * work + -0.035204 * wait + -5778412.679344 * num_locks + 151676562.841838;
  return result > 0 ? result : work + wait;
}
static
double
payment_estimate(ulint work, ulint wait, ulint num_locks)
{
  double result = 0.167429 * work + 0.018503 * wait + 484540.671643 * num_locks + 14373517.557892;
  return result > 0 ? result : work + wait;
}
static
double
delivery_estimate(ulint work, ulint wait, ulint num_locks)
{
  double result = 0.335207 * work + 0.012636 * wait + -3567320.906844 * num_locks + 215839241.070575;
  return result > 0 ? result : work + wait;
}
static
double
stock_level_estimate(ulint work, ulint wait, ulint num_locks)
{
  double result = 0.254872 * work + -0.030642 * wait + -101840.123786 * num_locks + 22112874.484210;
  return result > 0 ? result : work + wait;
}
static
double
tpcc_estimate(ulint work, ulint wait, ulint num_locks)
{
  double result = 0.327740 * work + 0.008922 * wait + -50320.149374 * num_locks + 56625490.273089;
  return result > 0 ? result : work + wait;
}

static
double
estimate(
  ulint work,
  ulint wait,
  ulint num_locks,
  transaction_type type)
{
  switch (type) {
    case NEW_ORDER:
//      return 1000000;
      return new_order_estimate(work, wait, num_locks);
    case PAYMENT:
//      return 2000000;
      return payment_estimate(work, wait, num_locks);
//    case ORDER_STATUS:
//      return 4000000;
    case DELIVERY:
//      return 3000000;
      return delivery_estimate(work, wait, num_locks);
    case STOCK_LEVEL:
      return stock_level_estimate(work, wait, num_locks);
    default:
      return tpcc_estimate(work, wait, num_locks);
  }
}

static
double
new_order_estimate(work_wait parameters)
{
  double actual_remaining =
  
  0.7864 * parameters.work_so_far +
  -0.0297 * parameters.wait_so_far +
  2942981.4508 * parameters.num_locks_so_far +
  -4235373.8011 * parameters.num_of_wait_locks +
  1004352.9371 * parameters.total_wait_locks +
  -14.1105 * parameters.total_granted_locks +
  1.0799 * parameters.mean_work_of_all +
  -1.6725 * parameters.mean_wait_of_all +
  -65678069.6481 * parameters.cpu_usage +
  0.5402 * parameters.avg_work_of_same_past_second +
  0.8986 * parameters.avg_wait_of_same_past_second +
  -0.74   * parameters.avg_latency_of_all_past_second +
  -0.1256 * parameters.avg_latency_of_same_past_5_seconds +
  0.361  * parameters.avg_latency_of_same_last_20 +
  -0.0531 * parameters.max_latency_of_same_last_50 +
  92356470.5408;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
static
double
payment_estimate(work_wait parameters)
{
  double actual_remaining =
  
  0.4896 * parameters.work_so_far +
  0.0396 * parameters.wait_so_far +
  19372717.5916 * parameters.num_locks_so_far +
  -8599030.6497 * parameters.num_of_wait_locks +
  353784.2308 * parameters.total_wait_locks +
  -5.9633 * parameters.total_granted_locks +
  -0.6071 * parameters.mean_wait_of_all +
  -0.4072 * parameters.avg_work_of_same_past_second +
  -0.3808 * parameters.avg_wait_of_same_past_second +
  0.3612 * parameters.avg_latency_of_all_past_second +
  0.0859 * parameters.avg_latency_of_same_last_20 +
  -0.0093 * parameters.max_latency_of_same_last_50 +
  -2874425.7536;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
static
double
delivery_estimate(work_wait parameters)
{
  double actual_remaining =
  
  0.5288 * parameters.work_so_far +
  -0.2784 * parameters.wait_so_far +
  -3353368.597 * parameters.num_locks_so_far +
  162570672.1884 * parameters.num_of_wait_locks +
  1274780.6497 * parameters.total_wait_locks +
  -20.5316 * parameters.total_granted_locks +
  -1.4657 * parameters.mean_work_of_all +
  0.2398 * parameters.avg_work_of_same_past_second +
  -0.3096 * parameters.avg_wait_of_same_past_second +
  -0.5545 * parameters.avg_latency_of_all_past_second +
  0.6522 * parameters.avg_latency_of_same_last_20 +
  0.0373 * parameters.max_latency_of_same_last_50 +
  -23975031.578;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
static
double
stock_level_estimate(work_wait parameters)
{
  double actual_remaining =
  
  -0.0722 * parameters.wait_so_far +
  -211081.0858 * parameters.num_locks_so_far +
  117801453.8488 * parameters.num_of_wait_locks +
  122501.2727 * parameters.total_wait_locks +
  1.057  * parameters.mean_work_of_all +
  -0.8101 * parameters.mean_wait_of_all +
  -0.298  * parameters.avg_work_of_same_past_second +
  0.2695 * parameters.avg_wait_of_same_past_second +
  0.043  * parameters.avg_latency_of_all_past_second +
  -0.2368 * parameters.avg_latency_of_same_past_5_seconds +
  0.0381 * parameters.avg_latency_of_same_last_20 +
  0.0178 * parameters.max_latency_of_same_last_50 +
  -120696837.0021;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
static
double
tpcc_estimate(work_wait parameters)
{
  double actual_remaining =
  
  0.7959 * parameters.work_so_far +
  -0.009  * parameters.wait_so_far +
  864001.7598 * parameters.num_locks_so_far +
  -7122050.386 * parameters.num_of_wait_locks +
  629163.2553 * parameters.total_wait_locks +
  -11.1112 * parameters.total_granted_locks +
  -0.2616 * parameters.mean_work_of_all +
  -0.8173 * parameters.mean_wait_of_all +
  -23403843.1769 * parameters.cpu_usage +
  0.5794 * parameters.avg_work_of_same_past_second +
  -0.1485 * parameters.avg_wait_of_same_past_second +
  -0.1637 * parameters.avg_latency_of_all_past_second +
  0.1016 * parameters.avg_latency_of_same_past_5_seconds +
  0.2213 * parameters.avg_latency_of_same_last_20 +
  -0.0263 * parameters.max_latency_of_same_last_50 +
  169357714.3522;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
estimate(
  work_wait parameters,
  transaction_type type)
{
  switch (type) {
    case NEW_ORDER:
//      return 1000000;
      return new_order_estimate(parameters);
    case PAYMENT:
//      return 2000000;
      return payment_estimate(parameters);
//    case ORDER_STATUS:
//      return 4000000;
    case DELIVERY:
//      return 3000000;
      return delivery_estimate(parameters);
    case STOCK_LEVEL:
      return stock_level_estimate(parameters);
    default:
      return tpcc_estimate(parameters);
  }
}

/*********************************************************************//**
Gets the mode of a lock.
@return mode */
UNIV_INLINE
enum lock_mode
lock_get_mode(
/*==========*/
  const lock_t* lock) /*!< in: lock */
{
  return(static_cast<enum lock_mode>(lock->type_mode & LOCK_MODE_MASK));
}

static
double
square(
  double number)
{
  return number * number;
}



/*************************************************************//**
Calculat the variance of a list of numbers. */
static
double
var(
  vector<ulint> &numbers)
{
  double mean = TraceTool::mean_latency;
  double variance = TraceTool::var_latency;
  ulint num_trans = TraceTool::num_trans;
  
  for (ulint index = 0, size = numbers.size(); index < size; ++index)
  {
    double latency = (double) numbers[index];
    ++num_trans;
    double old_mean = mean;
    double old_variance = variance;
    mean = old_mean + (latency - old_mean) / num_trans;
    variance = old_variance + (latency - old_mean) * (latency - mean);
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
  vector<lock_t *> &wait_locks,  /*!< waiting locks */
  vector<lock_t *> &granted_locks,  /*!< granted locks */
  vector<lock_t *> &locks_to_grant) /*!< locks to grant */
{
  if (wait_locks.size() == 0)
  {
    return;
  }
  if (wait_locks.size() == 1 &&
      granted_locks.size() == 0)
  {
    locks_to_grant.push_back(wait_locks[0]);
    return;
  }
  
  for (ulint index = 0, size = granted_locks.size();
       index < size; ++index)
  {
    granted_locks[index]->ranking = 0;
    granted_locks[index]->in_batch = true;
  }
  
  vector<lock_t *> all_locks(granted_locks.begin(), granted_locks.end());
  all_locks.insert(all_locks.end(), wait_locks.begin(), wait_locks.end());
  
  timespec now = TraceTool::get_time();
  estimate_mutex_enter();
  for (ulint index = 0, size = all_locks.size(); index < size; ++index)
  {
    lock_t *lock = all_locks[index];
    trx_t *trx = lock->trx;
    lock->time_so_far = TraceTool::difftime(trx->trx_start_time, now);
    ulint wait_so_far = trx->total_wait_time;
    if (lock_get_wait(lock))
    {
      wait_so_far += TraceTool::difftime(lock->wait_start, now);
    }
    ulint work_so_far = lock->time_so_far - wait_so_far;
    ulint num_locks = UT_LIST_GET_LEN(trx->lock.trx_locks);
    work_wait parameters = TraceTool::get_instance()->parameters(work_so_far, wait_so_far, num_locks,
                                                                 wait_locks.size(), trx->transaction_id);
    lock->process_time = estimate(parameters, trx->type);
    
    if ((rand() % 100 < 20 ||
         trx->type == ORDER_STATUS) &&
        trx->is_user_trx)
    {
      lock->time_at_grant = TraceTool::get_instance()->add_work_wait(work_so_far, wait_so_far, num_locks,
                                                                     wait_locks.size(), trx->transaction_id);
    }
  }
  estimate_mutex_exit();
  
  vector<int> rankings(wait_locks.size());
  list<vector<int> > ranking_enumerations;
  enumerate_rankings(rankings, 0, wait_locks.size() - 1, ranking_enumerations);
  remove_invalid_ranking(wait_locks, granted_locks, ranking_enumerations);
  ut_a(ranking_enumerations.size() > 0);
  int granted_size = granted_locks.size();
  
  double min_variance = std::numeric_limits<double>::max();
  vector<int> *min_enum = NULL;
  var_mutex_enter();
  for (list<vector<int> >::iterator iterator = ranking_enumerations.begin();
       iterator != ranking_enumerations.end(); ++iterator)
  {
    vector<int> &enumeration = *iterator;
    for (ulint index = 0, size = enumeration.size(); index < size; ++index)
    {
      wait_locks[index]->ranking = enumeration[index];
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
  var_mutex_exit();
  
  int smallest_ranking = INT_MAX;
  for (ulint index = 0, size = min_enum->size(); index < size; ++index)
  {
    lock_t *lock = wait_locks[index];
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

