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
  0,21766249,22097361,22360018,22590549,22821568,23035448,23224109,23413564,23588415,23765839,23938801,24110187,24271515,24437504,24608675,24787746,24944293,25106640,25282268,25454968,25656398,25857761,26039370,26242922,26442906,26637133,26828287,27039542,27261065,27470198,27673389,27889963,28105569,28294087,28500745,28712412,28928450,29150483,29374583,29604582,29858095,30108317,30359396,30612015,30882339,31152119,31471999,31755970,32064347,32384318,32697544,33011688,33331756,33655996,33991261,34337825,34658726,35089301,35510115,35938579,36378403,36847468,37303943,37793170,38265215,38747459,39190873,39665861,40211828,40799001,41397395,41970892,42551886,43170605,43740889,44357672,44949792,45642919,46321584,47032215,47793963,48505082,49191108,49905773,50764439,51604928,52541420,53465447,54240990,55105874,56007486,57042741,58083614,59068850,60036212,61107269,62236915,63393302,64436039,65671062,66954389,68125168,69385571,70840519,72200450,73507484,74840588,76424901,77999218,79476366,81211770,82832220,84378722,86215344,88127665,89935481,92060102,94112850,96188924,98308809,100514095,102940176,105271027,107792852,110158304,112899228,115699478,118399086,121518740,124393262,127583386,130992632,134456816,138151393,142166530,145940729,150018453,154075768,158486151,163009570,167649988,172367522,177288890,182653064,187980901,193538992,199244551,205198389,211613928,217889164,224614591,231619444,238681865,246053254,254276003,262432992,270910665,279601192,289349864,298563653,308334551,317876116,327680977,337966673,348230953,358701998,369549717,381196852,392669869,404577394,417321858,429517692,442992155,455697640,468695228,482610341,495655890,509789607,523478233,538598612,553058346,567589204,582389440,598390552,615638123,633872287,652665256,673582191,696076552,720562541,745810077,773716879,806936681,843910010,888428250,938298681,1001099223,1079418252,1241223568,1980992218};
static ulint separator_frequency[NUM_SEPARATOR];
static timespec separator_last_access[NUM_SEPARATOR];
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
  for (ulint index = 0; index < NUM_SEPARATOR; ++index)
  {
    separator_frequency[index] = 1;
    separator_last_access[index] = now;
  }
  total_frequency = NUM_SEPARATOR;
  
  ifstream isotonic_file("isotonic_new_order");
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
  ulint  remaining_time) /*!< real remaining time */
{
  int index = binary_search(separators, NUM_SEPARATOR, remaining_time);
//  TraceTool::get_instance()->get_log() << remaining_time << "," << index << endl;
  sep_mutex_enter();
  ++total_frequency;
  ++separator_frequency[index];
  separator_last_access[index] = TraceTool::get_time();
  
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
//  timespec now = TraceTool::get_time();
//  ofstream log_file("last_access");
//  for (ulint index = 0; index < NUM_SEPARATOR; ++index)
//  {
//    vector<timespec> &separator = separator_last_access[index];
//    for (ulint access_index = 1, size = separator_last_access[index].size();
//         access_index < size - 1; ++access_index)
//    {
//      log_file << TraceTool::difftime(separator[access_index], separator[access_index + 1]) << ',';
//    }
//    log_file << endl;
//    separator.clear();
//    separator.push_back(now);
//  }
//  log_file.close();
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

