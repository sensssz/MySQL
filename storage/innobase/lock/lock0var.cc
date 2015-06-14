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

typedef pair<lock_t *, lock_t *> pair_t;

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
  read_isotonic("isotonics/tpcc", tpcc_work_wait,
                tpcc_estimated, tpcc_length);
  read_isotonic("isotonics/new_order", new_order_work_wait,
                new_order_estimated, new_order_length);
  read_isotonic("isotonics/payment", payment_work_wait,
                payment_estimated, payment_length);
  read_isotonic("isotonics/order_status", order_status_work_wait,
                order_status_estimated, order_status_length);
  read_isotonic("isotonics/delivery", delivery_work_wait,
                delivery_estimated, delivery_length);
  read_isotonic("isotonics/stock_level", stock_level_work_wait,
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
  if (type == PAYMENT)
  {
    return 20000000;
  }
  else
  {
    return 40000000;
  }
  
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
  return result - time_so_far;
}

static
double
new_order_estimate(ulint work, ulint wait, ulint num_locks)
{
  double result = -16578373.144800 * num_locks + 1.059596 * work + 0.935827 * wait + 460314291.033181;
  return result > 0 ? result : work + wait;
}
static
double
payment_estimate(ulint work, ulint wait, ulint num_locks)
{
  double result = -17953038.503848 * num_locks + 1.349622 * work + 0.792085 * wait + 163472860.400916;
  return result > 0 ? result : work + wait;
}

static
double
delivery_estimate(ulint work, ulint wait, ulint num_locks)
{
  double result = -17776597.175086 * num_locks + 1.207660 * work + 0.000000 * wait + 871024730.396978;
  return result > 0 ? result : work + wait;
}
static
double
tpcc_estimate(ulint work, ulint wait, ulint num_locks)
{
  double result = -1487014.227070 * num_locks + 1.286214 * work + 0.794002 * wait + 121590714.641695;
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
      return new_order_estimate(work, wait, num_locks);
    case PAYMENT:
      return payment_estimate(work, wait, num_locks);
    case DELIVERY:
      return delivery_estimate(work, wait, num_locks);
    default:
      return tpcc_estimate(work, wait, num_locks);
  }
}

static
double
square(
  double number)
{
  return number * number;
}


/*************************************************************//**
Calculat the mean of a list of numbers. */
static
double
mean(
  vector<ulint> &numbers)
{
  double total = 0;
  
  for (ulint index = 0, size = numbers.size(); index < size; ++index)
  {
    total += numbers[index];
  }
  
  return total / numbers.size();
}

/*************************************************************//**
Calculat the variance of a list of numbers. */
static
double
var(
  vector<ulint> &numbers)
{
  double heuristic = 0;
  double mean = TraceTool::mean_latency;
  
  for (ulint index = 0, size = numbers.size(); index < size; ++index)
  {
    heuristic += square(numbers[index] - mean);
  }
  
  return heuristic;
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

/*************************************************************//**
Calculate the cumulative sum of latency for the list of given locks. */
static
void
cumsum(
  list<lock_t *> &locks,
  vector<ulint> &rolling_sum)
{
  ulint sum_of_previous_process_time = 0;
  int previous_ranking = 0;
  ulint max_process = 0;
  
  for (list<lock_t *>::iterator iter = locks.begin(); iter != locks.end(); ++iter)
  {
    lock_t *lock = *iter;
    
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
double
heuristic(
  list<lock_t *> &locks)
{
  vector<ulint> rolling_sum;
  cumsum(locks, rolling_sum);
  return var(rolling_sum);
}

static
double
heuristic(
  vector<lock_t *> &locks)
{
  vector<ulint> rolling_sum;
  cumsum(locks, rolling_sum);
  return var(rolling_sum);
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
void
merge_read_locks(
  vector<lock_t *> &all_locks,
  vector<lock_t *> &merged_locks,
  vector<lock_t *> &read_locks)
{
  ulint longest_time_so_far = 0;
  ulint longest_process = 0;
  for (ulint index = 0, size = all_locks.size();
       index < size; ++index)
  {
    lock_t *lock = all_locks[index];
    if (lock_get_mode(lock) == LOCK_S)
    {
      read_locks.push_back(lock);
      if (lock->time_so_far > longest_time_so_far)
      {
        longest_time_so_far = lock->time_so_far;
      }
      if (lock->process_time > longest_process)
      {
        longest_process = lock->process_time;
      }
    }
    else
    {
      merged_locks.push_back(lock);
    }
  }
  if (read_locks.size() > 0)
  {
    lock_t *lock = read_locks[0];
    lock->original_time_so_far = lock->time_so_far;
    lock->original_process = lock->process_time;
    lock->time_so_far = longest_time_so_far;
    lock->process_time = longest_process;
    merged_locks.push_back(lock);
  }
}

static
bool
compare_by_ranking(
  lock_t *lock1,
  lock_t *lock2)
{
  return lock1->ranking < lock2->ranking;
}

static
bool
compare_by_process(
  lock_t *lock1,
  lock_t *lock2)
{
  return lock1->process_time > lock2->process_time;
}

static
bool
even(
  ulint number)
{
  return number % 2 == 0;
}

static
ulint
last_odd(
  ulint size)
{
  ulint max_index = size - 2;
  return !even(max_index) ? max_index : max_index - 1;
}

static
ulint
last_even(
  ulint size)
{
  ulint max_index = size - 2;
  return even(max_index) ? max_index : max_index - 1;
}

static
void
rearrange(
  vector<lock_t *> &locks,
  vector<lock_t *> &reordered,
  bool odd_after)
{
  ulint size = locks.size();
  
  reordered.push_back(locks[0]);
  ulint start = odd_after ? 2 : 1;
  for (ulint index = start; index < size - 1; index += 2)
  {
    reordered.push_back(locks[index]);
  }
  reordered.push_back(locks[size - 1]);
  
  start = odd_after ? last_odd(size) : last_even(size);
  for (int index = (int) start; index > 0; index -= 2)
  {
    reordered.push_back(locks[index]);
  }
}

static
list<lock_t *>::iterator
min_iter(
  list<lock_t *> &locks)
{
  ulint min_process = ULONG_MAX;
  list<lock_t *>::iterator min_iter;
  
  for (list<lock_t *>::iterator iter = locks.begin(); iter != locks.end(); ++iter)
  {
    ulint process = (*iter)->process_time;
    if (process < min_process)
    {
      min_process = process;
      min_iter = iter;
    }
  }
  
  return min_iter;
}

static
list<lock_t *>::iterator
insert_descending(
  list<lock_t *> &candidates,
  list<lock_t *>::iterator min_iter,
  lock_t *lock_to_insert)
{
  list<lock_t *>::iterator iter = candidates.begin();
  while (iter != min_iter &&
         lock_to_insert->process_time < (*iter)->process_time)
  {
    ++iter;
  }
  iter = candidates.insert(iter, lock_to_insert);
  return iter;
}

static
list<lock_t *>::iterator
insert_ascending(
  list<lock_t *> &candidates,
  list<lock_t *>::iterator iter,
  lock_t *lock_to_insert)
{
  while (iter != candidates.end() &&
         lock_to_insert->process_time > (*iter)->process_time)
  {
    ++iter;
  }
  iter = candidates.insert(iter, lock_to_insert);
  return iter;
}

static
list<lock_t *>::iterator
find_left_most_unmarked(
  list<lock_t *> &locks)
{
  list<lock_t *>::iterator iter = locks.begin();
  while ((*iter)->marked)
  {
    ++iter;
  }
  
  return iter;
}

static
list<lock_t *>::iterator
find_right_most_unmarked(
  list<lock_t *> &locks)
{
  list<lock_t *>::iterator iter = locks.end();
  --iter;
  while ((*iter)->marked)
  {
    --iter;
  }
  
  return iter;
}

static
double
try_move_left(
  list<lock_t *> &candidate_as_list,
  list<lock_t *>::iterator min_process_iter,
  list<lock_t *>::iterator iter,
  double min_heuristic)
{
  lock_t *lock = *iter;
  lock->marked = true;
  iter = candidate_as_list.erase(iter);
  list<lock_t *>::iterator insert_iter = insert_descending(candidate_as_list, min_process_iter, lock);
  double heu = heuristic(candidate_as_list);
  if (heu < min_heuristic)
  {
    min_heuristic = heu;
  }
  else
  {
    candidate_as_list.erase(insert_iter);
    candidate_as_list.insert(iter, lock);
  }
  
  return min_heuristic;
}

static
double
try_move_right(
  list<lock_t *> &candidate_as_list,
  list<lock_t *>::iterator min_process_iter,
  list<lock_t *>::iterator iter,
  double min_heuristic)
{
  lock_t *lock = *iter;
  lock->marked = true;
  iter = candidate_as_list.erase(iter);
  list<lock_t *>::iterator insert_iter = insert_ascending(candidate_as_list, min_process_iter, lock);
  double heu = heuristic(candidate_as_list);
  if (heu < min_heuristic)
  {
    min_heuristic = heu;
  }
  else
  {
    candidate_as_list.erase(insert_iter);
    candidate_as_list.insert(iter, lock);
  }
  
  return min_heuristic;
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

static
double
find_min_heuristic_on_process(
  vector<lock_t *> &candidates,
  vector<lock_t *> &locks)
{
  vector<ulint> rolling_sum;
  cumsum(candidates, rolling_sum);
  double min_heuristic = var(rolling_sum);
  double average = mean(rolling_sum);
  
  list<lock_t *> candidate_as_list(candidates.begin(), candidates.end());
  list<lock_t *>::iterator min_process_iter = min_iter(candidate_as_list);
  
  while (true)
  {
    if (average < TraceTool::mean_latency)
    {
      list<lock_t *>::iterator iter = find_right_most_unmarked(candidate_as_list);
      if (iter == min_process_iter)
      {
        break;
      }
      min_heuristic = try_move_left(candidate_as_list, min_process_iter,
                                    iter, min_heuristic);
    }
    else if (average > TraceTool::mean_latency)
    {
      list<lock_t *>::iterator iter = find_left_most_unmarked(candidate_as_list);
      if (iter == min_process_iter)
      {
        break;
      }
      min_heuristic = try_move_right(candidate_as_list, min_process_iter,
                                     iter, min_heuristic);
    }
    
    rolling_sum.clear();
    cumsum(candidates, rolling_sum);
    average = mean(rolling_sum);
  }
  
  ulint index = 0;
  for (list<lock_t *>::iterator iter = candidate_as_list.begin(); iter != candidate_as_list.end(); ++iter)
  {
    candidates[index++] = *iter;
  }
  
  return min_heuristic;
}

static
bool
try_swap(
  vector<lock_t *> &candidates,
  ulint index,
  double &min_heuristic)
{
  lock_t *temp = candidates[index];
  candidates[index] = candidates[index + 1];
  candidates[index + 1] = temp;
  
  double heu = heuristic(candidates);
  
  if (heu < min_heuristic)
  {
    min_heuristic = heu;
    return true;
  }
  else
  {
    temp = candidates[index];
    candidates[index] = candidates[index + 1];
    candidates[index + 1] = temp;
    return false;
  }
}

static
bool
contains(
  vector<pair_t> &pairs,
  lock_t *lock1,
  lock_t *lock2)
{
  for (ulint index = 0, size = pairs.size(); index < size; ++index)
  {
    pair_t swapped_pair = pairs[index];
    if (swapped_pair.first == lock1 &&
        swapped_pair.second == lock2)
    {
      return true;
    }
  }
  return false;
}

static
double
min_var_order(
  vector<lock_t *> &candidates,
  vector<lock_t *> &locks)
{
  double min_heuristic = find_min_heuristic_on_process(candidates, locks);
  vector<pair_t> swapped_pairs;
  bool swap = true;
  while (swap)
  {
    swap = false;
    ulint min_difference = ULONG_MAX;
    ulint min_index = candidates.size();
    for (ulint index = 0, size = candidates.size(); index < size - 1; ++index)
    {
      lock_t *lock1 = candidates[index];
      lock_t *lock2 = candidates[index + 1];
      if (lock1->time_so_far > lock2->time_so_far &&
          !contains(swapped_pairs, lock1, lock2))
      {
        ulint difference = lock1->time_so_far - lock2->time_so_far;
        if (difference < min_difference)
        {
          min_difference = difference;
          min_index = index;
        }
      }
    }
    if (min_index < candidates.size())
    {
      // We can do a swap
      try_swap(candidates, min_index, min_heuristic);
      pair_t pair = make_pair(candidates[min_index], candidates[min_index + 1]);
      swapped_pairs.push_back(pair);
      swap = true;
    }
  }
  
  return min_heuristic;
}


/*************************************************************//**
Find the lock that gives minimum CTV. */
UNIV_INTERN
void
LVM_schedule(
  vector<lock_t *> &wait_locks,  /*!< waiting locks */
  vector<lock_t *> &locks_to_grant) /*!< locks to grant */
{
  if (wait_locks.size() == 0)
  {
    return;
  }
  if (wait_locks.size() == 1)
  {
    locks_to_grant.push_back(wait_locks[0]);
    return;
  }
  
  timespec now = TraceTool::get_time();
  for (ulint index = 0, size = wait_locks.size(); index < size; ++index)
  {
    lock_t *lock = wait_locks[index];
    trx_t *trx = lock->trx;
    lock->time_so_far = TraceTool::difftime(trx->trx_start_time, now);
    lock->process_time = lock->time_so_far;
    ulint wait_so_far = trx->total_wait_time;
    if (lock_get_wait(lock))
    {
      wait_so_far += TraceTool::difftime(lock->wait_start, now);
    }
    if (lock->time_so_far > wait_so_far)
    {
      ulint work_so_far = lock->time_so_far - wait_so_far;
      ulint num_locks = UT_LIST_GET_LEN(trx->lock.trx_locks);
      ulint latency = estimate(work_so_far, wait_so_far, num_locks, trx->type);
      if (latency > lock->time_so_far)
      {
        lock->process_time = latency - lock->time_so_far;
      }
      
//      if (trx->is_user_trx)
//      {
//        TraceTool::get_instance()->add_work_wait(work_so_far, wait_so_far, num_locks, trx->transaction_id);
//      }
    }
  }
  
  vector<lock_t *> *min_order;
  vector<lock_t *> merged_locks;
  vector<lock_t *> read_locks;
  merge_read_locks(wait_locks, merged_locks, read_locks);
  sort(merged_locks.begin(), merged_locks.end(), compare_by_process);
  vector<lock_t *> odd_after;
  vector<lock_t *> even_after;
  
  if (merged_locks.size() > 3)
  {
    rearrange(merged_locks, odd_after, true);
    rearrange(merged_locks, even_after, false);
    var_mutex_enter();
    double min_heu1 = min_var_order(odd_after, merged_locks);
    double min_heu2 = min_var_order(even_after, merged_locks);
    var_mutex_exit();
    min_order = min_heu1 < min_heu2 ? &odd_after : &even_after;
  }
  else
  {
    min_order = &merged_locks;
  }
  for (ulint index = 0, size = min_order->size(); index < size; ++index)
  {
    lock_t *lock = (*min_order)[index];
    lock->ranking = index;
    if (lock_get_mode(lock) == LOCK_S)
    {
      lock->time_so_far = lock->original_time_so_far;
      lock->process_time = lock->original_time_so_far;
      for (ulint read_index = 1, read_size = read_locks.size();
           read_index < read_size; ++read_index)
      {
        read_locks[read_index]->ranking = index;
      }
    }
  }
  
  for (ulint index = 0, size = wait_locks.size(); index < size; ++index)
  {
    if (wait_locks[index]->ranking == 0)
    {
      locks_to_grant.push_back(wait_locks[index]);
    }
  }
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

