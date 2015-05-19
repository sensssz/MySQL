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

#define NUM_SEPARATOR (sizeof(separators)/sizeof(ulint))

#define sep_mutex_enter()\
os_mutex_enter(separator_mutex)

#define sep_mutex_exit()\
os_mutex_exit(separator_mutex)

static ulint separators[] = {
  0,1755587,1943434,2449239,2758650,2888911,2985396,3073124,3160577,3252033,3346050,3448433,3574641,3735816,3949250,4255297,4739108,5557947,6967619,8938744,10172686,11219858,12230263,13244812,14288953,15330387,16437550,17473406,18592063,19704774,20874312,22048014,23276633,24532975,25846360,27231725,28836249,30594249,32525371,34741045,37088851,39649112,42585296,45778039,49191555,53067901,57371997,61990954,67453439,73184767,79497367,86563407,93922223,102247784,110910946,120231286,130145594,141266957,152995809,165576066,178787379,193058892,207688359,223141325,239575855,255598255,272421354,288624960,304697301,320967527,337893270,354468252,371722539,388426571,405959764,423150990,440506072,459092494,477390789,496231658,515182190,534406375,554587174,574526409,596313226,618396291,643105900,667354208,695991918,727917379,762149776,799518889,842905793,891456968,950790268,1017730825,1102566597,1217054178,1408186812,3574505531,3898895302};
static ulint separator_frequency[NUM_SEPARATOR];
static vector<vector<timespec> > separator_last_access;
static ulint total_frequency = NUM_SEPARATOR;
static os_ib_mutex_t separator_mutex;
static ulint *work_wait_so_far = NULL;
static ulint *estimated_work_wait = NULL;
static ulint length = 0;

/*************************************************************//**
Do initilization for the min-variance scheduling algorithm. */
UNIV_INTERN
void
indi_init()
{
  separator_mutex = os_mutex_create();
  timespec now = TraceTool::get_time();
  separator_last_access.reserve(NUM_SEPARATOR);
  for (ulint index = 0; index < NUM_SEPARATOR; ++index)
  {
    separator_frequency[index] = 1;
    vector<timespec> last_access;
    last_access.reserve(50000);
    last_access.push_back(now);
    separator_last_access.push_back(last_access);
  }
  
  ifstream isotonic_file("isotonic_work_wait");
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
Do a linear search in the separators to find the bucket for the specific
remaining time. */
static
ulint
linear_search(
  ulint *array,
  ulint length,
  double target)
{
  for (ulint index = 0; index < length - 2; ++index)
  {
    if (array[index] <= target &&
        target < array[index + 1])
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
//  return 0.958759617557516  * x + 115932574.391064;
  ulint y_index = binary_search(work_wait_so_far, length, x);
  if (y_index == length - 1)
  {
    y_index = length - 2;
  }
  return estimated_work_wait[y_index + 1];
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
    ulint estimated_remaining = estimate(time_so_far) - time_so_far;
    int index = binary_search(separators, NUM_SEPARATOR, estimated_remaining);
    double probability = ((double) separator_frequency[index]) / total_frequency;
    ulint time_since_last_access = TraceTool::difftime(separator_last_access[index].back(), now);
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
  ulint  remaining_time) /*!< real remaining time */
{
  int index = binary_search(separators, NUM_SEPARATOR, remaining_time);
//  TraceTool::get_instance()->get_log() << remaining_time << "," << index << endl;
  sep_mutex_enter();
  ++total_frequency;
  ++separator_frequency[index];
  separator_last_access[index].push_back(TraceTool::get_time());
  
  /* fix overflow */
  if (total_frequency == 0)
  {
    --total_frequency;
    ulint min_frequency = total_frequency; // find the min non-zero frequency
    for (ulint index = 0; index < NUM_SEPARATOR; ++index)
    {
      if (separator_frequency[index] > 0 &&
          separator_frequency[index] < min_frequency)
      {
        min_frequency = separator_frequency[index];
      }
    }
    
    total_frequency = 0;
    for (ulint index = 0; index < NUM_SEPARATOR; ++index)
    {
      separator_frequency[index] /= min_frequency;
      total_frequency += separator_frequency[index];
    }
  }
  sep_mutex_exit();
  ut_ad(total_frequency > 0);
}

UNIV_INTERN
void
write_separator_log()
{
  timespec now = TraceTool::get_time();
  ofstream log_file("last_access");
  for (ulint index = 0; index < NUM_SEPARATOR; ++index)
  {
    vector<timespec> &separator = separator_last_access[index];
    for (ulint access_index = 1, size = separator_last_access[index].size();
         access_index < size - 1; ++access_index)
    {
      log_file << TraceTool::difftime(separator[access_index], separator[access_index + 1]) << ',';
    }
    log_file << endl;
    separator.clear();
    separator.push_back(now);
  }
  log_file.close();
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

