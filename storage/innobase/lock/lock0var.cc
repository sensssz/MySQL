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
#include "m5p.h"

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
//
//void
//read_isotonic(
//  const char *name,
//  ulint *&so_far,
//  ulint *&estimated,
//  ulint &length)
//{
//  ifstream isotonic_file(name);
//  isotonic_file >> length >> length;
//  so_far = (ulint *)malloc(sizeof(ulint) * length);
//  estimated = (ulint *)malloc(sizeof(ulint) * length);
//  double x = 0;
//  double y = 0;
//  for (ulint index = 0; index < length; ++index)
//  {
//    isotonic_file >> x >> y;
//    so_far[index] = x;
//    estimated[index] = y;
//  }
//  isotonic_file.close();
//}
//
/*************************************************************//**
Do initilization for the min-variance scheduling algorithm. */
UNIV_INTERN
void
indi_init()
{
}
//
//static
//double
//new_order_estimate(ulint work, ulint wait, ulint num_locks)
//{
//  double result = 0.391422 * work + -0.035204 * wait + -5778412.679344 * num_locks + 151676562.841838;
//  return result > 0 ? result : work + wait;
//}
//static
//double
//payment_estimate(ulint work, ulint wait, ulint num_locks)
//{
//  double result = 0.167429 * work + 0.018503 * wait + 484540.671643 * num_locks + 14373517.557892;
//  return result > 0 ? result : work + wait;
//}
//static
//double
//delivery_estimate(ulint work, ulint wait, ulint num_locks)
//{
//  double result = 0.335207 * work + 0.012636 * wait + -3567320.906844 * num_locks + 215839241.070575;
//  return result > 0 ? result : work + wait;
//}
//static
//double
//stock_level_estimate(ulint work, ulint wait, ulint num_locks)
//{
//  double result = 0.254872 * work + -0.030642 * wait + -101840.123786 * num_locks + 22112874.484210;
//  return result > 0 ? result : work + wait;
//}
//static
//double
//tpcc_estimate(ulint work, ulint wait, ulint num_locks)
//{
//  double result = 0.327740 * work + 0.008922 * wait + -50320.149374 * num_locks + 56625490.273089;
//  return result > 0 ? result : work + wait;
//}
//
//static
//double
//estimate(
//  ulint work,
//  ulint wait,
//  ulint num_locks,
//  transaction_type type)
//{
//  switch (type) {
//    case NEW_ORDER:
////      return 1000000;
//      return new_order_estimate(work, wait, num_locks);
//    case PAYMENT:
////      return 2000000;
//      return payment_estimate(work, wait, num_locks);
////    case ORDER_STATUS:
////      return 4000000;
////    case DELIVERY:
////      return 3000000;
////      return delivery_estimate(work, wait, num_locks);
//    case STOCK_LEVEL:
//      return stock_level_estimate(work, wait, num_locks);
//    default:
//      return tpcc_estimate(work, wait, num_locks);
//  }
//}
//
///*
//static
//double
//new_order_estimate(work_wait &parameters)
//{
//  double actual_remaining =
//  
//  0.6681 * parameters.work_so_far +
//  -0.2153 * parameters.wait_so_far +
//  -17257442.5912 * parameters.num_of_wait_locks +
//  449464.6324 * parameters.total_wait_locks +
//  1.9112 * parameters.mean_work_of_all +
//  -2.0515 * parameters.mean_wait_of_all +
//  145423027.4912 * parameters.cpu_usage +
//  -0.7109 * parameters.avg_wait_of_same_past_second +
//  0.4373 * parameters.avg_latency_of_all_past_second +
//  0.2748 * parameters.avg_latency_of_same_past_5_seconds +
//  0.2202 * parameters.avg_latency_of_same_last_20 +
//  -51172072.9587;
//  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
//}
//
//static
//double
//payment_estimate(work_wait &parameters)
//{
//    double actual_remaining =
//    
//    -0.0065 * parameters.wait_so_far +
//    1536843.3992 * parameters.num_of_wait_locks +
//    -10851.6834 * parameters.total_wait_locks +
//    5.0623 * parameters.total_granted_locks +
//    0.1454 * parameters.mean_work_of_all +
//    -0.087  * parameters.mean_wait_of_all +
//    0.1072 * parameters.avg_work_of_same_past_second +
//    0.063  * parameters.avg_wait_of_same_past_second +
//    -0.0817 * parameters.avg_latency_of_all_past_second +
//    0.0243 * parameters.avg_latency_of_same_past_5_seconds +
//    0.0259 * parameters.avg_latency_of_same_last_20 +
//    3777975.9102;
//    return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
//}
//
//static
//double
//tpcc_estimate(work_wait &parameters)
//{
//    double actual_remaining =
//    
//    0.298  * parameters.work_so_far +
//    -0.0965 * parameters.wait_so_far +
//    932390.1032 * parameters.num_locks_so_far +
//    -6495093.36 * parameters.num_of_wait_locks +
//    202623.5043 * parameters.total_wait_locks +
//    0.4914 * parameters.mean_work_of_all +
//    -0.7789 * parameters.mean_wait_of_all +
//    71569308.856 * parameters.cpu_usage +
//    0.9338 * parameters.avg_work_of_same_past_second +
//    -0.1778 * parameters.avg_wait_of_same_past_second +
//    -0.1693 * parameters.avg_latency_of_all_past_second +
//    0.2391 * parameters.avg_latency_of_same_past_5_seconds +
//    0.1074 * parameters.avg_latency_of_same_last_20 +
//    -34220105.0114;
//    return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
//}
// */
//
//static
//double
//estimate(
//  work_wait &parameters,
//  transaction_type type)
//{
//  switch (type) {
//    case NEW_ORDER:
////      return 1000000;
//      return new_order_estimate(parameters);
//    case PAYMENT:
////      return 2000000;
//      return payment_estimate(parameters);
////    case ORDER_STATUS:
////      return 4000000;
////    case DELIVERY:
////      return 3000000;
////      return delivery_estimate(parameters);
//    case STOCK_LEVEL:
//      return stock_level_estimate(parameters);
//    default:
//      return tpcc_estimate(parameters);
//  }
//}
//
///*********************************************************************//**
//Gets the mode of a lock.
//@return mode */
//UNIV_INLINE
//enum lock_mode
//lock_get_mode(
///*==========*/
//  const lock_t* lock) /*!< in: lock */
//{
//  return(static_cast<enum lock_mode>(lock->type_mode & LOCK_MODE_MASK));
//}
//
//static
//double
//square(
//  double number)
//{
//  return number * number;
//}
//
//
///*************************************************************//**
//Calculat the mean of a list of numbers. */
//static
//double
//mean(
//  vector<ulint> &numbers)
//{
//  double total = 0;
//  
//  for (ulint index = 0, size = numbers.size(); index < size; ++index)
//  {
//    total += numbers[index];
//  }
//  
//  return total / numbers.size();
//}
//
///*************************************************************//**
//Calculat the variance of a list of numbers. */
//static
//double
//var(
//  vector<ulint> &numbers)
//{
//  double heuristic = 0;
//  double mean = TraceTool::mean_latency;
//  
//  for (ulint index = 0, size = numbers.size(); index < size; ++index)
//  {
//    heuristic += square(numbers[index] - mean);
//  }
//  
//  return heuristic;
//}
//
///*************************************************************//**
//Calculate the cumulative sum of latency for the list of given locks. */
//static
//void
//cumsum(
//  vector<lock_t *> &locks,
//  vector<ulint> &rolling_sum)
//{
//  ulint sum_of_previous_process_time = 0;
//  int previous_ranking = 0;
//  ulint max_process = 0;
//  
//  for (ulint index = 0, size = locks.size(); index < size; ++index)
//  {
//    lock_t *lock = locks[index];
//    
//    if (lock->ranking == previous_ranking)
//    {
//      if (lock->process_time > max_process)
//      {
//        max_process = lock->process_time;
//      }
//    }
//    else
//    {
//      sum_of_previous_process_time += max_process;
//      max_process = lock->process_time;
//      previous_ranking = lock->ranking;
//    }
//    
//    rolling_sum.push_back(lock->time_so_far + lock->process_time + sum_of_previous_process_time);
//  }
//}
//
///*************************************************************//**
//Calculate the cumulative sum of latency for the list of given locks. */
//static
//void
//cumsum(
//  list<lock_t *> &locks,
//  vector<ulint> &rolling_sum)
//{
//  ulint sum_of_previous_process_time = 0;
//  int previous_ranking = 0;
//  ulint max_process = 0;
//  
//  for (list<lock_t *>::iterator iter = locks.begin(); iter != locks.end(); ++iter)
//  {
//    lock_t *lock = *iter;
//    
//    if (lock->ranking == previous_ranking)
//    {
//      if (lock->process_time > max_process)
//      {
//        max_process = lock->process_time;
//      }
//    }
//    else
//    {
//      sum_of_previous_process_time += max_process;
//      max_process = lock->process_time;
//      previous_ranking = lock->ranking;
//    }
//    
//    rolling_sum.push_back(lock->time_so_far + lock->process_time + sum_of_previous_process_time);
//  }
//}
//
//static
//bool
//compare_by_process(
//  lock_t *lock1,
//  lock_t *lock2)
//{
//  return lock1->process_time > lock2->process_time;
//}
//
//static
//bool
//compare_by_ranking(
//  lock_t *lock1,
//  lock_t *lock2)
//{
//  return lock1->ranking < lock2->ranking;
//}
//
//static
//double
//heuristic(
//  list<lock_t *> &candidates,
//  vector<lock_t *> &locks,
//  vector<lock_t *> &read_locks)
//{
//  int index = 0;
//  for (list<lock_t *>::iterator iter = candidates.begin(); iter != candidates.end(); ++iter)
//  {
//    lock_t *lock = *iter;
//    lock->ranking = index;
//    if (lock_get_mode(lock) == LOCK_S)
//    {
//      for (ulint read_index = 0, read_size = read_locks.size();
//           read_index < read_size; ++read_index)
//      {
//        read_locks[read_index]->ranking = index;
//      }
//    }
//    ++index;
//  }
//  sort(locks.begin(), locks.end(), compare_by_ranking);
//  vector<ulint> rolling_sum;
//  cumsum(locks, rolling_sum);
//  return var(rolling_sum);
//}
//
//static
//double
//heuristic(
//  vector<lock_t *> candidates,
//  vector<lock_t *> &locks,
//  vector<lock_t *> &read_locks)
//{
//  int index = 0;
//  for (vector<lock_t *>::iterator iter = candidates.begin(); iter != candidates.end(); ++iter)
//  {
//    lock_t *lock = *iter;
//    lock->ranking = index;
//    if (lock_get_mode(lock) == LOCK_S)
//    {
//      for (ulint read_index = 0, read_size = read_locks.size();
//           read_index < read_size; ++read_index)
//      {
//        read_locks[read_index]->ranking = index;
//      }
//    }
//    ++index;
//  }
//  sort(locks.begin(), locks.end(), compare_by_ranking);
//  vector<ulint> rolling_sum;
//  cumsum(locks, rolling_sum);
//  return var(rolling_sum);
//}
//
//static
//double
//heuristic(
//  vector<lock_t *> &locks)
//{
//  sort(locks.begin(), locks.end(), compare_by_ranking);
//  vector<ulint> rolling_sum;
//  cumsum(locks, rolling_sum);
//  return var(rolling_sum);
//}
//
//static
//void
//merge_read_locks(
//  vector<lock_t *> &wait_locks,
//  vector<lock_t *> &merged_locks,
//  vector<lock_t *> &read_locks)
//{
//  ulint longest_time_so_far = 0;
//  ulint longest_process = 0;
//  for (ulint index = 0, size = wait_locks.size();
//       index < size; ++index)
//  {
//    lock_t *lock = wait_locks[index];
//    if (lock_get_mode(lock) == LOCK_S)
//    {
//      read_locks.push_back(lock);
//      if (lock->time_so_far > longest_time_so_far)
//      {
//        longest_time_so_far = lock->time_so_far;
//      }
//      if (lock->process_time > longest_process)
//      {
//        longest_process = lock->process_time;
//      }
//    }
//    else
//    {
//      merged_locks.push_back(lock);
//    }
//  }
//  if (read_locks.size() > 0)
//  {
//    lock_t *lock = read_locks[0];
//    lock->original_time_so_far = lock->time_so_far;
//    lock->original_process = lock->process_time;
//    lock->time_so_far = longest_time_so_far;
//    lock->process_time = longest_process;
//    merged_locks.push_back(lock);
//  }
//}
//
//static
//bool
//even(
//  ulint number)
//{
//  return number % 2 == 0;
//}
//
//static
//ulint
//last_odd(
//  ulint size)
//{
//  ulint max_index = size - 2;
//  return !even(max_index) ? max_index : max_index - 1;
//}
//
//static
//ulint
//last_even(
//  ulint size)
//{
//  ulint max_index = size - 2;
//  return even(max_index) ? max_index : max_index - 1;
//}
//
//static
//void
//rearrange(
//  vector<lock_t *> &locks,
//  vector<lock_t *> &reordered,
//  bool odd_after)
//{
//  ulint size = locks.size();
//  
//  reordered.push_back(locks[0]);
//  // If odd, pick evens. If even, pick odds
//  ulint start = odd_after ? 2 : 1;
//  for (ulint index = start; index < size - 1; index += 2)
//  {
//    reordered.push_back(locks[index]);
//  }
//  reordered.push_back(locks[size - 1]);
//  
//  start = odd_after ? last_odd(size) : last_even(size);
//  for (int index = start; index > 0; index -= 2)
//  {
//    reordered.push_back(locks[index]);
//  }
//}
//
//static
//list<lock_t *>::iterator
//min_iter(
//  list<lock_t *> &locks)
//{
//  ulint min_process = ULONG_MAX;
//  list<lock_t *>::iterator min_iter;
//  
//  for (list<lock_t *>::iterator iter = locks.begin(); iter != locks.end(); ++iter)
//  {
//    ulint process = (*iter)->process_time;
//    if (process < min_process)
//    {
//      min_process = process;
//      min_iter = iter;
//    }
//  }
//  
//  return min_iter;
//}
//
//static
//list<lock_t *>::iterator
//insert_descending(
//  list<lock_t *> &candidates,
//  list<lock_t *>::iterator min_iter,
//  lock_t *lock_to_insert)
//{
//  list<lock_t *>::iterator iter = candidates.begin();
//  while (iter != min_iter &&
//         lock_to_insert->process_time < (*iter)->process_time)
//  {
//    ++iter;
//  }
//  iter = candidates.insert(iter, lock_to_insert);
//  return iter;
//}
//
//static
//list<lock_t *>::iterator
//insert_ascending(
//  list<lock_t *> &candidates,
//  list<lock_t *>::iterator iter,
//  lock_t *lock_to_insert)
//{
//  while (iter != candidates.end() &&
//         lock_to_insert->process_time > (*iter)->process_time)
//  {
//    ++iter;
//  }
//  iter = candidates.insert(iter, lock_to_insert);
//  return iter;
//}
//
//static
//list<lock_t *>::iterator
//find_left_most_unmarked(
//  list<lock_t *> &locks)
//{
//  list<lock_t *>::iterator iter = locks.begin();
//  while ((*iter)->marked)
//  {
//    ++iter;
//  }
//  
//  return iter;
//}
//
//static
//list<lock_t *>::iterator
//find_right_most_unmarked(
//  list<lock_t *> &locks)
//{
//  list<lock_t *>::iterator iter = locks.end();
//  --iter;
//  while ((*iter)->marked)
//  {
//    --iter;
//  }
//  
//  return iter;
//}
//
//static
//double
//try_move_left(
//  list<lock_t *> &candidate_as_list,
//  list<lock_t *>::iterator min_process_iter,
//  list<lock_t *>::iterator iter,
//  vector<lock_t *> &locks,
//  vector<lock_t *> &read_locks,
//  double min_heuristic)
//{
//  lock_t *lock = *iter;
//  lock->marked = true;
//  iter = candidate_as_list.erase(iter);
//  list<lock_t *>::iterator insert_iter = insert_descending(candidate_as_list, min_process_iter, lock);
//  double heu = heuristic(candidate_as_list, locks, read_locks);
//  if (heu < min_heuristic)
//  {
//    min_heuristic = heu;
//  }
//  else
//  {
//    candidate_as_list.erase(insert_iter);
//    candidate_as_list.insert(iter, lock);
//  }
//  
//  return min_heuristic;
//}
//
//static
//double
//try_move_right(
//  list<lock_t *> &candidate_as_list,
//  list<lock_t *>::iterator min_process_iter,
//  list<lock_t *>::iterator iter,
//  vector<lock_t *> &locks,
//  vector<lock_t *> &read_locks,
//  double min_heuristic)
//{
//  lock_t *lock = *iter;
//  lock->marked = true;
//  iter = candidate_as_list.erase(iter);
//  list<lock_t *>::iterator insert_iter = insert_ascending(candidate_as_list, min_process_iter, lock);
//  double heu = heuristic(candidate_as_list, locks, read_locks);
//  if (heu < min_heuristic)
//  {
//    min_heuristic = heu;
//  }
//  else
//  {
//    // Put the lock back to its original position
//    candidate_as_list.erase(insert_iter);
//    candidate_as_list.insert(iter, lock);
//  }
//  
//  return min_heuristic;
//}
//
//static
//double
//find_min_heuristic_on_process(
//  vector<lock_t *> &candidates,
//  vector<lock_t *> &locks,
//  vector<lock_t *> &read_locks)
//{
//  int ranking = 0;
//  for (vector<lock_t *>::iterator iter = candidates.begin(); iter != candidates.end(); ++iter)
//  {
//    lock_t *lock = *iter;
//    lock->ranking = ranking;
//    if (lock_get_mode(lock) == LOCK_S)
//    {
//      for (ulint read_index = 0, read_size = read_locks.size();
//           read_index < read_size; ++read_index)
//      {
//        read_locks[read_index]->ranking = ranking;
//      }
//    }
//    ++ranking;
//  }
//  sort(locks.begin(), locks.end(), compare_by_ranking);
//  vector<ulint> rolling_sum;
//  cumsum(locks, rolling_sum);
//  double min_heuristic = var(rolling_sum);
//  double average = mean(rolling_sum);
//  
//  list<lock_t *> candidate_as_list(candidates.begin(), candidates.end());
//  list<lock_t *>::iterator min_process_iter = min_iter(candidate_as_list);
//  
//  while (true)
//  {
//    if (average < TraceTool::mean_latency)
//    {
//      list<lock_t *>::iterator iter = find_right_most_unmarked(candidate_as_list);
//      if (iter == min_process_iter)
//      {
//        break;
//      }
//      min_heuristic = try_move_left(candidate_as_list, min_process_iter,
//                                    iter, locks, read_locks, min_heuristic);
//    }
//    else if (average > TraceTool::mean_latency)
//    {
//      list<lock_t *>::iterator iter = find_left_most_unmarked(candidate_as_list);
//      if (iter == min_process_iter)
//      {
//        break;
//      }
//      min_heuristic = try_move_right(candidate_as_list, min_process_iter,
//                                     iter, locks, read_locks, min_heuristic);
//    }
//    
//    rolling_sum.clear();
//    cumsum(candidates, rolling_sum);
//    average = mean(rolling_sum);
//  }
//  
//  ulint index = 0;
//  for (list<lock_t *>::iterator iter = candidate_as_list.begin(); iter != candidate_as_list.end(); ++iter)
//  {
//    candidates[index++] = *iter;
//  }
//  
//  return min_heuristic;
//}
//
//static
//bool
//try_swap(
//  vector<lock_t *> &candidates,
//  vector<lock_t *> &locks,
//  vector<lock_t *> &read_locks,
//  ulint index,
//  double &min_heuristic)
//{
//  lock_t *temp = candidates[index];
//  candidates[index] = candidates[index + 1];
//  candidates[index + 1] = temp;
//  
//  double heu = heuristic(candidates, locks, read_locks);
//  
//  if (heu < min_heuristic)
//  {
//    min_heuristic = heu;
//    return true;
//  }
//  else
//  {
//    temp = candidates[index];
//    candidates[index] = candidates[index + 1];
//    candidates[index + 1] = temp;
//    return false;
//  }
//}
//
//static
//bool
//contains(
//  vector<pair_t> &pairs,
//  lock_t *lock1,
//  lock_t *lock2)
//{
//  for (ulint index = 0, size = pairs.size(); index < size; ++index)
//  {
//    pair_t swapped_pair = pairs[index];
//    if (swapped_pair.first == lock1 &&
//        swapped_pair.second == lock2)
//    {
//      return true;
//    }
//  }
//  return false;
//}
//
//static
//double
//min_var_order(
//  vector<lock_t *> &candidates,
//  vector<lock_t *> &locks,
//  vector<lock_t *> &read_locks)
//{
//  double min_heuristic = find_min_heuristic_on_process(candidates, locks, read_locks);
//  vector<pair_t> swapped_pairs;
//  bool swap = true;
//  while (swap)
//  {
//    swap = false;
//    ulint min_difference = ULONG_MAX;
//    ulint min_index = candidates.size();
//    for (ulint index = 0, size = candidates.size(); index < size - 1; ++index)
//    {
//      lock_t *lock1 = candidates[index];
//      lock_t *lock2 = candidates[index + 1];
//      if (lock1->time_so_far < lock2->time_so_far &&
//          !contains(swapped_pairs, lock1, lock2))
//      {
//        ulint difference = lock2->time_so_far - lock1->time_so_far;
//        if (difference < min_difference)
//        {
//          min_difference = difference;
//          min_index = index;
//        }
//      }
//    }
//    if (min_index < candidates.size())
//    {
//      // We can do a swap
//      try_swap(candidates, locks, read_locks, min_index, min_heuristic);
//      pair_t pair = make_pair(candidates[min_index], candidates[min_index + 1]);
//      swapped_pairs.push_back(pair);
//      swap = true;
//    }
//  }
//  
//  for (ulint index = 0, size = locks.size(); index < size; ++index)
//  {
//    lock_t *lock = locks[index];
//    lock->marked = false;
//  }
//  
//  return min_heuristic;
//}
//
//
///*************************************************************//**
//Find the lock that gives minimum CTV. */
//UNIV_INTERN
//void
//LVM_schedule(
//  vector<lock_t *> &wait_locks,  /*!< waiting locks */
//  vector<lock_t *> &locks_to_grant) /*!< locks to grant */
//{
//  if (wait_locks.size() == 0)
//  {
//    return;
//  }
//  if (wait_locks.size() == 1)
//  {
//    locks_to_grant.push_back(wait_locks[0]);
//    return;
//  }
//  
//  timespec now = TraceTool::get_time();
//  estimate_mutex_enter();
//  for (ulint index = 0, size = wait_locks.size(); index < size; ++index)
//  {
//    lock_t *lock = wait_locks[index];
//    trx_t *trx = lock->trx;
//    lock->time_so_far = TraceTool::difftime(trx->trx_start_time, now);
//    ulint wait_so_far = trx->total_wait_time + TraceTool::difftime(lock->wait_start, now);
//    ulint work_so_far = lock->time_so_far - wait_so_far;
//    ulint num_locks = UT_LIST_GET_LEN(trx->lock.trx_locks);
//    work_wait parameters = TraceTool::get_instance()->parameters_necessary(work_so_far, wait_so_far, num_locks,
//                                                                 wait_locks.size(), trx->transaction_id);
//    lock->process_time = estimate(parameters, trx->type);
//    
////    if ((rand() % 100 < 20 ||
////         trx->type == ORDER_STATUS) &&
////        trx->is_user_trx)
////    {
////      lock->time_at_grant = TraceTool::get_instance()->add_work_wait(work_so_far, wait_so_far, num_locks,
////                                                                     wait_locks.size(), lock->process_time, trx->transaction_id);
////    }
//  }
//  
//  estimate_mutex_exit();
//  
//  vector<lock_t *> merged_locks;
//  vector<lock_t *> read_locks;
//  vector<lock_t *> *min_order = NULL;
//  
//  merge_read_locks(wait_locks, merged_locks, read_locks);
//  sort(merged_locks.begin(), merged_locks.end(), compare_by_process);
//  vector<lock_t *> odd_after;
//  vector<lock_t *> even_after;
//  double mean_latency = TraceTool::mean_latency;
//  
//  if (merged_locks.size() > 2)
//  {
//    var_mutex_enter();
//    rearrange(merged_locks, odd_after, true);
//    rearrange(merged_locks, even_after, false);
//    double min_heu1 = min_var_order(odd_after, wait_locks, read_locks);
//    double min_heu2 = min_var_order(even_after, wait_locks, read_locks);
//    min_order = min_heu1 < min_heu2 ? &odd_after : &even_after;
//    var_mutex_exit();
//  }
//  else
//  {
//    min_order = &merged_locks;
//  }
//  
//  
//  for (ulint index = 0, size = min_order->size(); index < size; ++index)
//  {
//    lock_t *lock = (*min_order)[index];
//    lock->ranking = index;
//    if (lock_get_mode(lock) == LOCK_S)
//    {
//      lock->time_so_far = lock->original_time_so_far;
//      lock->process_time = lock->original_time_so_far;
//      for (ulint read_index = 0, read_size = read_locks.size();
//           read_index < read_size; ++read_index)
//      {
//        read_locks[read_index]->ranking = index;
//      }
//    }
//  }
//  
//  lock_t *lock = wait_locks[0];
//  bool do_monitor = lock->un_member.rec_lock.space == 34 &&
//                    lock->un_member.rec_lock.page_no == 3 &&
//                    lock_rec_find_set_bit(lock) == 30 && false;
//  if (do_monitor)
//  {
//    ofstream &log = TraceTool::get_instance()->get_log();
//    log << min_order->size() << "," << read_locks.size() << endl;
//    log << "  mean_latency = " << mean_latency << ";" << endl;
//    for (ulint index = 0, size = wait_locks.size(); index < size; ++index)
//    {
//      lock_t *lock = wait_locks[index];
//      trx_t *trx = lock->trx;
//      log << "  lock_t lock" << index << "={" << trx->id << ",'" << lock_get_mode_str(lock) << "',"
//          << lock->ranking << "," << lock->time_so_far << "," << lock->process_time << "," << "0,0,false};" << endl;
//    }
//    log << endl;
//  }
//  
//  
//  for (ulint index = 0, size = wait_locks.size(); index < size; ++index)
//  {
//    if (wait_locks[index]->ranking == 0)
//    {
//      locks_to_grant.push_back(wait_locks[index]);
//    }
//  }
//}

/*************************************************************//**
Clean up resources. */
UNIV_INTERN
void
indi_cleanup()
{
}

