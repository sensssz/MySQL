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

using std::sort;
using std::ifstream;

static ulint *work_wait_so_far = NULL;
static ulint *estimated_work_wait = NULL;
static ulint length = 0;

/*************************************************************//**
Do initilization for the min-variance scheduling algorithm. */
UNIV_INTERN
void
indi_init()
{
  ifstream isotonic_file("isotonic_original");
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
Estimate remaining time given total time so far. */
UNIV_INTERN
ulint
estimate(
  ulint time_so_far)
{
  ulint y_index = binary_search(work_wait_so_far, length, time_so_far);
  if (y_index == length - 1)
  {
    y_index = length - 2;
  }
  return estimated_work_wait[y_index + 1];
}

static
bool
compare(lock_t *lock1, lock_t *lock2)
{
  return lock1->process_time < lock2->process_time;
}

/*************************************************************//**
Find the lock that gives minimum CTV. */
UNIV_INTERN
void
CTV_schedule(vector<lock_t *> &locks) /*!< candidate locks */
{
  ulint size = locks.size() - 1;
  double *as = new double[size];
  double *betas = new double[size];
  double *gammas = new double[size];
  double *gamma_stars = new double[size];
  bool *quadratic_solution = new bool[size];
  lock_t **final_schedule = new lock_t *[size + 1];
  
  timespec now = TraceTool::get_time();
  for (ulint index = 0; index <= size; ++index)
  {
    lock_t *lock = locks[index];
    ulint time_so_far = TraceTool::difftime(lock->trx->trx_start_time, now);
    lock->process_time = estimate(time_so_far);
  }
  sort(locks.begin(), locks.end(), compare);
  final_schedule[0] = locks.back();
  for (ulint index = 0; index < size; ++index)
  {
    ulint sum = 0;
    ulint process_time = locks[index]->process_time;
    for (ulint i = 0; i < index - 1; ++i)
    {
      sum += locks[i]->process_time / 2.0;
    }
    as[index] = process_time + sum / 2.0;
    betas[index] = (size - index) * process_time + 2 * as[index];
    gammas[index] = (index + 1) * process_time - 2 * as[index];
    if (index == 0)
    {
      gamma_stars[index] = gammas[index];
    }
    else
    {
      gamma_stars[index] = gamma_stars[index - 1] + gammas[index];
    }
  }
  
  delete[] as;
  delete[] betas;
  delete[] gammas;
  delete[] gamma_stars;
  delete[] quadratic_solution;
  delete[] final_schedule;
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

