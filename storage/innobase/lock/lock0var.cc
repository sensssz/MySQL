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

/*************************************************************//**
Do initilization for the min-variance scheduling algorithm. */
UNIV_INTERN
void
indi_init()
{
}

static
double
estimate(
  work_wait &parameters,
  transaction_type type,
  char lock_type)
{
  double result = 0;
  switch (type) {
    case NEW_ORDER:
      result =  new_order_estimate(parameters);
    case PAYMENT:
      result =  payment_estimate(parameters);
//    case ORDER_STATUS:
//    case DELIVERY:
//      return delivery_estimate(parameters);
    case STOCK_LEVEL:
      result = stock_level_estimate(parameters);
    default:
      result = tpcc_estimate(parameters);
  }
//  TraceTool::get_instance()->get_log() << lock_type << "," << parameters.work_so_far + parameters.wait_so_far << "," << result << endl;
  return result;
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
Calculat the mean of a list of numbers. */
static
double
mean(
  vector<long> &numbers)
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
  vector<long> &numbers)
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
  vector<long> &rolling_sum)
{
  long sum_of_previous_process_time = 0;
  int previous_ranking = 0;
  long max_process = 0;
  
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
  vector<long> &rolling_sum)
{
  long sum_of_previous_process_time = 0;
  int previous_ranking = 0;
  long max_process = 0;
  
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
bool
compare_by_process(
  lock_t *lock1,
  lock_t *lock2)
{
  return lock1->process_time > lock2->process_time;
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
double
heuristic(
  list<lock_t *> &candidates,
  vector<lock_t *> &locks,
  vector<lock_t *> &read_locks)
{
  int index = 0;
  for (list<lock_t *>::iterator iter = candidates.begin(); iter != candidates.end(); ++iter)
  {
    lock_t *lock = *iter;
    lock->ranking = index;
    if (lock_get_mode(lock) == LOCK_S)
    {
      for (ulint read_index = 0, read_size = read_locks.size();
           read_index < read_size; ++read_index)
      {
        read_locks[read_index]->ranking = index;
      }
    }
    ++index;
  }
  sort(locks.begin(), locks.end(), compare_by_ranking);
  vector<long> rolling_sum;
  cumsum(locks, rolling_sum);
  return var(rolling_sum);
}

static
double
heuristic(
  vector<lock_t *> candidates,
  vector<lock_t *> &locks,
  vector<lock_t *> &read_locks)
{
  int index = 0;
  for (vector<lock_t *>::iterator iter = candidates.begin(); iter != candidates.end(); ++iter)
  {
    lock_t *lock = *iter;
    lock->ranking = index;
    if (lock_get_mode(lock) == LOCK_S)
    {
      for (ulint read_index = 0, read_size = read_locks.size();
           read_index < read_size; ++read_index)
      {
        read_locks[read_index]->ranking = index;
      }
    }
    ++index;
  }
  sort(locks.begin(), locks.end(), compare_by_ranking);
  vector<long> rolling_sum;
  cumsum(locks, rolling_sum);
  return var(rolling_sum);
}

static
double
heuristic(
  vector<lock_t *> &locks)
{
  sort(locks.begin(), locks.end(), compare_by_ranking);
  vector<long> rolling_sum;
  cumsum(locks, rolling_sum);
  return var(rolling_sum);
}

static
void
merge_read_locks(
  vector<lock_t *> &wait_locks,
  vector<lock_t *> &merged_locks,
  vector<lock_t *> &read_locks)
{
  long longest_time_so_far = 0;
  long longest_process = 0;
  for (ulint index = 0, size = wait_locks.size();
       index < size; ++index)
  {
    lock_t *lock = wait_locks[index];
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
  // If odd, pick evens. If even, pick odds
  ulint start = odd_after ? 2 : 1;
  for (ulint index = start; index < size - 1; index += 2)
  {
    reordered.push_back(locks[index]);
  }
  reordered.push_back(locks[size - 1]);
  
  start = odd_after ? last_odd(size) : last_even(size);
  for (int index = start; index > 0; index -= 2)
  {
    reordered.push_back(locks[index]);
  }
}

static
list<lock_t *>::iterator
min_iter(
  list<lock_t *> &locks)
{
  long min_process = LONG_MAX;
  list<lock_t *>::iterator min_iter;
  
  for (list<lock_t *>::iterator iter = locks.begin(); iter != locks.end(); ++iter)
  {
    long process = (*iter)->process_time;
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
  vector<lock_t *> &locks,
  vector<lock_t *> &read_locks,
  double min_heuristic)
{
  lock_t *lock = *iter;
  lock->marked = true;
  iter = candidate_as_list.erase(iter);
  list<lock_t *>::iterator insert_iter = insert_descending(candidate_as_list, min_process_iter, lock);
  double heu = heuristic(candidate_as_list, locks, read_locks);
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
  vector<lock_t *> &locks,
  vector<lock_t *> &read_locks,
  double min_heuristic)
{
  lock_t *lock = *iter;
  lock->marked = true;
  iter = candidate_as_list.erase(iter);
  list<lock_t *>::iterator insert_iter = insert_ascending(candidate_as_list, min_process_iter, lock);
  double heu = heuristic(candidate_as_list, locks, read_locks);
  if (heu < min_heuristic)
  {
    min_heuristic = heu;
  }
  else
  {
    // Put the lock back to its original position
    candidate_as_list.erase(insert_iter);
    candidate_as_list.insert(iter, lock);
  }
  
  return min_heuristic;
}

static
double
find_min_heuristic_on_process(
  vector<lock_t *> &candidates,
  vector<lock_t *> &locks,
  vector<lock_t *> &read_locks)
{
  int ranking = 0;
  for (vector<lock_t *>::iterator iter = candidates.begin(); iter != candidates.end(); ++iter)
  {
    lock_t *lock = *iter;
    lock->ranking = ranking;
    if (lock_get_mode(lock) == LOCK_S)
    {
      for (ulint read_index = 0, read_size = read_locks.size();
           read_index < read_size; ++read_index)
      {
        read_locks[read_index]->ranking = ranking;
      }
    }
    ++ranking;
  }
  sort(locks.begin(), locks.end(), compare_by_ranking);
  vector<long> rolling_sum;
  cumsum(locks, rolling_sum);
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
                                    iter, locks, read_locks, min_heuristic);
    }
    else if (average > TraceTool::mean_latency)
    {
      list<lock_t *>::iterator iter = find_left_most_unmarked(candidate_as_list);
      if (iter == min_process_iter)
      {
        break;
      }
      min_heuristic = try_move_right(candidate_as_list, min_process_iter,
                                     iter, locks, read_locks, min_heuristic);
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
  vector<lock_t *> &locks,
  vector<lock_t *> &read_locks,
  ulint index,
  double &min_heuristic)
{
  lock_t *temp = candidates[index];
  candidates[index] = candidates[index + 1];
  candidates[index + 1] = temp;
  
  double heu = heuristic(candidates, locks, read_locks);
  
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
  vector<lock_t *> &locks,
  vector<lock_t *> &read_locks)
{
  double min_heuristic = find_min_heuristic_on_process(candidates, locks, read_locks);
  vector<pair_t> swapped_pairs;
  bool swap = true;
  while (swap)
  {
    swap = false;
    long min_difference = LONG_MAX;
    ulint min_index = candidates.size();
    long min_process = candidates[0]->process_time;
    for (ulint index = 0, size = candidates.size(); index < size - 1; ++index)
    {
      lock_t *lock1 = candidates[index];
      lock_t *lock2 = candidates[index + 1];
      if (lock1->time_so_far <= lock2->time_so_far &&
          !contains(swapped_pairs, lock1, lock2))
      {
        long difference = lock2->time_so_far - lock1->time_so_far;
        if (difference < min_difference)
        {
          min_difference = difference;
          min_index = index;
        }
      }
      if (lock2->process_time < min_process)
      {
        min_process = lock2->process_time;
      }
    }
    
    lock_t *lock1 = candidates[min_index];
    lock_t *lock2 = candidates[min_index + 1];
    if (min_index < candidates.size())
    {
      if (lock1->process_time >= lock2->process_time)
      {
        lock_t *temp = candidates[min_index];
        candidates[min_index] = candidates[min_index + 1];
        candidates[min_index + 1] = temp;
        pair_t pair = make_pair(candidates[min_index], candidates[min_index + 1]);
        swapped_pairs.push_back(pair);
        swap = true;
      }
      else
      {
        long L1 = lock1->time_so_far;
        long L2 = lock2->time_so_far;
        long R1 = lock1->process_time;
        long R2 = lock2->process_time;
        if ((L2 - L1) > (R2 - R1) * (1 + ((long) min_index * min_process + L2) / R2))
        {
          // We can do a swap
          try_swap(candidates, locks, read_locks, min_index, min_heuristic);
          pair_t pair = make_pair(candidates[min_index], candidates[min_index + 1]);
          swapped_pairs.push_back(pair);
          swap = true;
        }
      }
    }
  }
  
  for (ulint index = 0, size = locks.size(); index < size; ++index)
  {
    lock_t *lock = locks[index];
    lock->marked = false;
  }
  
  return min_heuristic;
}

char lock_get_type(
  lock_t *lock)
{
  return lock_get_mode(lock) == LOCK_S ? 'S' : 'X';
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
  estimate_mutex_enter();
  for (ulint index = 0, size = wait_locks.size(); index < size; ++index)
  {
    lock_t *lock = wait_locks[index];
    trx_t *trx = lock->trx;
    lock->time_so_far = TraceTool::difftime(trx->trx_start_time, now);
    long wait_so_far = trx->total_wait_time + TraceTool::difftime(lock->wait_start, now);
    long work_so_far = lock->time_so_far - wait_so_far;
    long num_locks = UT_LIST_GET_LEN(trx->lock.trx_locks);
    work_wait parameters = TraceTool::get_instance()->parameters_necessary(work_so_far, wait_so_far, num_locks,
                                                                 wait_locks.size(), trx->transaction_id);
    lock->process_time = estimate(parameters, trx->type, lock_get_type(lock));
    
//    if ((rand() % 100 < 20 ||
//         trx->type == ORDER_STATUS ||
//         trx->type == DELIVERY ||
//         trx->type == STOCK_LEVEL) &&
//        trx->is_user_trx)
//    {
//      lock->time_at_grant = TraceTool::get_instance()->add_work_wait(work_so_far, wait_so_far, num_locks,
//                                                                     wait_locks.size(), lock->process_time, trx->transaction_id);
//    }
  }
  
  estimate_mutex_exit();
  
  vector<lock_t *> merged_locks;
  vector<lock_t *> read_locks;
  vector<lock_t *> *min_order = NULL;
  
  merge_read_locks(wait_locks, merged_locks, read_locks);
  sort(merged_locks.begin(), merged_locks.end(), compare_by_process);
  vector<lock_t *> odd_after;
  vector<lock_t *> even_after;
  double mean_latency = TraceTool::mean_latency;
  
  if (merged_locks.size() > 2)
  {
    var_mutex_enter();
    rearrange(merged_locks, odd_after, true);
    rearrange(merged_locks, even_after, false);
    double min_heu1 = min_var_order(odd_after, wait_locks, read_locks);
    double min_heu2 = min_var_order(even_after, wait_locks, read_locks);
    min_order = min_heu1 < min_heu2 ? &odd_after : &even_after;
    var_mutex_exit();
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
      lock->process_time = lock->original_process;
      for (ulint read_index = 0, read_size = read_locks.size();
           read_index < read_size; ++read_index)
      {
        read_locks[read_index]->ranking = index;
      }
    }
  }
  
  lock_t *lock = wait_locks[0];
//  TraceTool::get_instance()->get_log() << lock->un_member.rec_lock.space << ","
//  << lock->un_member.rec_lock.page_no << "," << lock_rec_find_set_bit(lock) << endl;
  bool do_monitor = lock->un_member.rec_lock.space == 86 &&
                    lock->un_member.rec_lock.page_no == 3 &&
                    lock_rec_find_set_bit(lock) == 13 && false;
  if (do_monitor)
  {
    ofstream &log = TraceTool::get_instance()->get_log();
    log << min_order->size() << "," << read_locks.size() << endl;
    log << "  mean_latency = " << mean_latency << ";" << endl;
    for (ulint index = 0, size = wait_locks.size(); index < size; ++index)
    {
      lock_t *lock = wait_locks[index];
      trx_t *trx = lock->trx;
      log << "  lock_t lock" << index << "={" << trx->id << ",'" << lock_get_mode_str(lock) << "',"
          << lock->ranking << "," << lock->time_so_far << "," << lock->process_time << "," << "0,0,false};" << endl;
    }
    log << endl;
  }
  
  
  for (ulint index = 0, size = wait_locks.size(); index < size; ++index)
  {
    if (wait_locks[index]->ranking == 0)
    {
      locks_to_grant.push_back(wait_locks[index]);
    }
  }
//  TraceTool::get_instance()->get_log() << endl;
  
//  timespec sleep_time;
//  timespec remaining;
//  
//  sleep_time.tv_sec = 0;
//  sleep_time.tv_nsec = 10000;
//  nanosleep(&sleep_time, &remaining);
}

/*************************************************************//**
Clean up resources. */
UNIV_INTERN
void
indi_cleanup()
{
}

