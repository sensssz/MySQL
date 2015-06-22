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

static double loop_times = 0;
static long call_times = 0;

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
Swap two elements in a vector. */
static
void
swap(
  vector<lock_t *> &locks,
  ulint index1,
  ulint index2)
{
  if (index1 != index2)
  {
    lock_t *temp = locks[index1];
    locks[index1] = locks[index2];
    locks[index2] = temp;
  }
}

/*************************************************************//**
Generate all possible permutations of the given vector. */
static
void
permutate(
  vector<lock_t *> &locks,
  ulint start,
  ulint end,
  vector<vector<lock_t *> > &permutations)
{
  if (start == end)
  {
    vector<lock_t *> permutation(locks);
    permutations.push_back(permutation);
    return;
  }
  
  for (ulint index = start; index <= end; ++index)
  {
    /* Swap these two elements. */
    swap(locks, start, index);
    permutate(locks, start + 1, end, permutations);
    /* Swap them back. */
    swap(locks, start, index);
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
  double variance = 0;
  double average = mean(numbers);
  
  for (ulint index = 0, size = numbers.size(); index < size; ++index)
  {
    variance += square(numbers[index] - average);
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
compare_by_ranking(
  lock_t *lock1,
  lock_t *lock2)
{
  return lock1->ranking < lock2->ranking;
}

static
void
merge_read_locks(
  vector<lock_t *> &wait_locks,
  vector<lock_t *> &merged_locks,
  vector<lock_t *> &read_locks)
{
  for (ulint index = 0, size = wait_locks.size();
       index < size; ++index)
  {
    lock_t *lock = wait_locks[index];
    if (lock_get_mode(lock) == LOCK_S)
    {
      read_locks.push_back(lock);
    }
    else
    {
      merged_locks.push_back(lock);
    }
  }
  if (read_locks.size() > 0)
  {
    lock_t *lock = read_locks[0];
    merged_locks.push_back(lock);
  }
}

void
assign_rankings(
  vector<lock_t *> permutation,
  vector<lock_t *> read_locks)
{
  for (ulint perm_index = 0, perm_size = permutation.size(); perm_index < perm_size; ++perm_index)
  {
    lock_t *lock = permutation[perm_index];
    lock->ranking = perm_index;
    if (lock_get_mode(lock) == LOCK_S)
    {
      for (ulint read_index = 0, read_size = read_locks.size(); read_index < read_size; ++read_index)
      {
        lock_t *read_lock = read_locks[read_index];
        read_lock->ranking = perm_index;
      }
    }
  }
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
  
  ofstream &log = TraceTool::get_instance()->get_log();
  timespec now = TraceTool::get_time();
  for (ulint index = 0, size = wait_locks.size(); index < size; ++index)
  {
      lock_t *lock = wait_locks[index];
      trx_t *trx = lock->trx;
      lock->time_so_far = TraceTool::difftime(trx->trx_start_time, now);
  }
  
  vector<lock_t *> merged_locks;
  vector<lock_t *> read_locks;
  merge_read_locks(wait_locks, merged_locks, read_locks);
  vector<vector<lock_t *> > permutations;
  permutate(merged_locks, 0, merged_locks.size() - 1, permutations);
  vector<double> variances;
  vector<ulint> hits;
  ulint min_var = ULONG_MAX;
  ulint min_var_index = 0;
  ulint num_perms = permutations.size();
  
  for (ulint index = 0; index < num_perms; ++index)
  {
    variances.push_back(0);
    hits.push_back(0);
  }
  
  double loops = 0;
  ulint start_prune_count = (merged_locks.size() == 5) ? 10 : 4;
  
  for (ulint count = 0; count < 30; ++count)
  {
    for (ulint index = 0, size = wait_locks.size(); index < size; ++index)
    {
      lock_t *lock = wait_locks[index];
      lock->process_time = TraceTool::estimate(lock_get_mode(lock) == LOCK_S);
    }
    for (ulint index = 0; index < num_perms; ++index)
    {
      if (count >= start_prune_count &&
          hits[index] == 0)
      {
        continue;
      }
      
      ++loops;
      assign_rankings(permutations[index], read_locks);
      sort(wait_locks.begin(), wait_locks.end(), compare_by_ranking);
      vector<ulint> rolling_sum;
      cumsum(wait_locks, rolling_sum);
      ulint variance = var(rolling_sum);
      variances[index] = variance;
      if (min_var > variances[index])
      {
        min_var = variances[index];
        min_var_index = index;
      }
    }
    ++hits[min_var_index];
  }
  
  ulint max_hit = 0;
  ulint max_hit_index = 0;
  for (ulint index = 0; index < num_perms; ++index)
  {
    ulint hit = hits[index];
    if (max_hit < hit)
    {
      max_hit = hit;
      max_hit_index = index;
    }
  }
  
//  ++call_times;
//  loop_times = loop_times + (loops - loop_times) / call_times;
  
  assign_rankings(permutations[max_hit_index], read_locks);
  
  lock_t *lock = wait_locks[0];
  bool do_monitor = lock->un_member.rec_lock.space == 34 &&
                    lock->un_member.rec_lock.page_no == 3 &&
                    lock_rec_find_set_bit(lock) == 30 && false;
  if (do_monitor)
  {
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
}

/*************************************************************//**
Clean up resources. */
UNIV_INTERN
void
indi_cleanup()
{
//  TraceTool::get_instance()->get_log() << loop_times << endl;
//  TraceTool::get_instance()->get_log().close();
}

