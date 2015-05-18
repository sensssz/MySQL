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

#include <fstream>
#include <float.h>

using std::ifstream;

#define NUM_SEPARATOR 40

#define sep_mutex_enter()\
os_mutex_enter(separator_mutex)

#define sep_mutex_exit()\
os_mutex_exit(separator_mutex)

static ulint separators[] = {
  0, 13066, 13634, 13915, 14179, 14477, 14859, 15388, 16063, 16889,
  17940, 19946, 25808, 32831, 52234, 994015, 1168801, 1284194,
  1440112, 1782028, 2829740, 3903815, 4931228, 6060642, 7351262,
  9164885, 12140346, 16511690, 22864670, 32563045, 47335620, 68937876,
  99516117, 141522083, 198368469, 271102064, 351654643, 445456010,
  562961037, 742457104};
static ulint separator_frequency[NUM_SEPARATOR];
static timespec separator_last_access[NUM_SEPARATOR];
static ulint total_frequency = NUM_SEPARATOR;
static os_ib_mutex_t separator_mutex;
static ulint *work_wait_so_far = NULL;
static ulint *estimated_work_wait = NULL;
static ulint length = -1;

/*************************************************************//**
Do initilization for the min-variance scheduling algorithm. */
UNIV_INTERN
void
indi_init()
{
  separator_mutex = os_mutex_create();
  timespec now = TraceTool::get_time();
  for (int index = 0; index < NUM_SEPARATOR; ++index)
  {
    separator_frequency[index] = 1;
    separator_last_access[index] = now;
  }
  
  ifstream isotonic_file("isotonic_work_wait.csv");
  isotonic_file >> length >> length;
  work_wait_so_far = (ulint *)malloc(sizeof(ulint) * num_of_items);
  estimated_work_wait = (ulint *)malloc(sizeof(ulint) * num_of_items);
  int x = 0;
  int y = 0;
  int index = 0;
  while (isotonic_file >> x >> y)
  {
    work_wait_so_far[index] = x;
    estimated_work_wait[index] = y;
    ++index;
  }
  isotonic_file.close();
}

/*************************************************************//**
Do a binary in the separators to find the bucket for the specific
remaining time. */
static
int
binary_search(
  double time)  /*!< estiamted remaining time */
{
  int left = 0;
  int right = NUM_SEPARATOR;
  
  while (left < right)
  {
    int middle = (left + right) / 2;
    if (time < separators[middle])
    {
      right = middle;
    }
    else if (time >= separators[middle + 1])
    {
      left = middle;
    }
    else
    {
      return middle;
    }
  }
  
  return NUM_SEPARATOR - 1;
}

/*************************************************************//**
Do a binary in the separators to find the bucket for the specific
remaining time. */
static
int
linear_search(
  ulint *array,
  ulint length,
  double time)
{
  for (ulint index = 0; index < length - 1; ++index)
  {
    if (array[index] <= time &&
        time < array[index])
    {
      return index;
    }
  }
  return length - 1;
}

static
ulint
estimate(
  ulint x)
{
  int y_index = linear_search(work_wait_so_far, length - 1, x);
  return estimated_work_wait[y_index];
}

/*************************************************************//**
Calculate the mean for the indicator value. */
static
double
get_mean(
  const vector<lock_t *>  &locks,                   /*!< candidate locks */
  vector<double>          &remaining_time,          /*!< vector to store estimated remaining time
                          for each lock */
  vector<double>          &probabilities,           /*!< vector to store access probabilities for
                          each lock */
  vector<ulint>           &times_since_last_access) /*!< vector to store time since last access
                          for each lock */
{
  double mean = 0;
  timespec now = TraceTool::get_time();
  for (int lock_index = 0, size = locks.size(); lock_index < size; ++lock_index)
  {
    lock_t *lock = locks[lock_index];
    ulint time_so_far = TraceTool::difftime(lock->trx->trx_start_time, now);
    double estimated_remaining = estimate(time_so_far);
    int index = linear_search(separators, NUM_SEPARATOR, estimated_remaining);
    double probability = ((double) separator_frequency[index]) / total_frequency;
    ulint time_since_last_access = TraceTool::difftime(separator_last_access[index], now);
    mean += probability * time_since_last_access;
    
    remaining_time.push_back(estimated_remaining);
    probabilities.push_back(probability);
    times_since_last_access.push_back(time_since_last_access);
  }
  
  return mean;
}

/*************************************************************//**
Calculate the indicator value for one lock. */
static
double
get_indicator_value(
  lock_t  *lock,                  /*!< lock to calcualte the indicator value for */
  double  probability,            /*!< probability of the remaining time bucket being accessed */
  ulint   time_since_last_access, /*!< time since the remaining time bucket is last accessed */
  double  estimated_remaining,    /*!< estimated remainging time for the trx */
  double  mean)                   /*!< mean value for calculating the indicator value */
{
  // Do division first in case the number overflows
  return (probability * time_since_last_access * (time_since_last_access / estimated_remaining))
       * (2.0 * time_since_last_access / 3 - mean / 2);
}

/*************************************************************//**
Find the lock request that minimizes variance. */
UNIV_INTERN
lock_t *
find_min_var_lock(
  const vector<lock_t *> &locks) /*!<  list of locks on the same record */
{
  if (locks.size() == 0)
  {
    return NULL;
  }
  
  if (locks.size() == 1)
  {
    return locks[0];
  }
  
  sep_mutex_enter();
  vector<double> estimated_remaining_time;
  vector<double> probabilities;
  vector<ulint> times_since_last_access;
  double mean = get_mean(locks, estimated_remaining_time,
                         probabilities, times_since_last_access);
  sep_mutex_exit();
  
  double max_indicator = -DBL_MAX;
  lock_t *lock_to_grant = NULL;
  for (int index = 0, size = locks.size(); index < size; ++index)
  {
    lock_t *lock = locks[index];
    double indicator = get_indicator_value(lock, probabilities[index],
       times_since_last_access[index], estimated_remaining_time[index], mean);
    if (indicator > max_indicator)
    {
      max_indicator = indicator;
      lock_to_grant = lock;
    }
  }
  
  return lock_to_grant;
}

/*************************************************************//**
Update the last access time for one of the buckets of remaining time. */
UNIV_INTERN
void
update_access(
  double  remaining_time) /*!< real remaining time */
{
  int index = linear_search(separators, NUM_SEPARATOR, remaining_time);
  sep_mutex_enter();
  ++total_frequency;
  ++separator_frequency[index];
  separator_last_access[index] = TraceTool::get_time();
  
  /* fix overflow */
  if (total_frequency == 0)
  {
    --total_frequency;
    ulint min_frequency = total_frequency; /* find the min non-zero frequency */
    for (int index = 0; index < NUM_SEPARATOR; ++index)
    {
      if (separator_frequency[index] > 0 &&
          separator_frequency[index] < min_frequency)
      {
        min_frequency = separator_frequency[index];
      }
    }
    
    total_frequency = 0;
    for (int index = 0; index < NUM_SEPARATOR; ++index)
    {
      separator_frequency[index] /= min_frequency;
      total_frequency += separator_frequency[index];
    }
  }
  sep_mutex_exit();
  ut_ad(total_frequency > 0);
}

/*************************************************************//**
Clean up resources. */
UNIV_INTERN
void
indi_cleanup()
{
  free(work_wait_so_far);
  free(estimated_work_wait);
}

