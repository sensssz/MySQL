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
#include <queue>

using std::list;
using std::ifstream;
using std::sort;
using std::find;
using std::string;
using std::pair;
using std::priority_queue;

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
    case DELIVERY:
      return delivery_estimate(parameters);
    case STOCK_LEVEL:
      result = stock_level_estimate(parameters);
    default:
      result = tpcc_estimate(parameters);
  }
//  TraceTool::get_instance()->get_log() << lock_type << "," << parameters.work_so_far + parameters.wait_so_far << "," << result << endl;
  return result;
}

double
max(
  double number)
{
  return number > 0 ? number : 0;
}

double
wpt_early(
  lock_t *lock,
  double average_process)
{
  double deadline = TraceTool::mean_latency[lock->trx->type];
  return (average_process - 2 * max(deadline - lock->time_so_far - lock->process_time)) / lock->process_time;
}

double
wpt_tardy(
  lock_t *lock,
  double average_process)
{
  double deadline = TraceTool::mean_latency[lock->trx->type];
  return (average_process + 2 * max(lock->time_so_far - deadline + lock->process_time)) / lock->process_time;
}

/*************************************************************//**
Find the lock that gives minimum CTV. */
UNIV_INTERN
lock_t *
LVM_schedule(
  vector<lock_t *> &wait_locks)  /*!< waiting locks */
{
  if (wait_locks.size() == 0)
  {
    return NULL;
  }
  if (wait_locks.size() == 1)
  {
    return wait_locks[0];
  }
  
  timespec now = TraceTool::get_time();
  double average_process = 0;
  estimate_mutex_enter();
  for (ulint index = 0, size = wait_locks.size(); index < size; ++index)
  {
    lock_t *lock = wait_locks[index];
    trx_t *trx = lock->trx;
    lock->time_so_far = TraceTool::difftime(trx->trx_start_time, now);
    long wait_so_far = trx->total_wait_time + TraceTool::difftime(lock->wait_start, now);
    long work_so_far = lock->time_so_far - wait_so_far;
    long num_locks = UT_LIST_GET_LEN(trx->lock.trx_locks);
    work_wait parameters = TraceTool::get_instance()->parameters(work_so_far, wait_so_far, num_locks,
                                                                           wait_locks.size(), trx->transaction_id);
    lock->process_time = estimate(parameters, trx->type, lock_get_type(lock));
    average_process += lock->process_time;
    
    if ((rand() % 100 < 20 ||
         trx->type == ORDER_STATUS ||
         trx->type == DELIVERY ||
         trx->type == STOCK_LEVEL) &&
        trx->is_user_trx)
    {
      lock->time_at_grant = TraceTool::get_instance()->add_work_wait(work_so_far, wait_so_far, num_locks,
                                                                     wait_locks.size(), lock->process_time, trx->transaction_id);
    }
  }
  estimate_mutex_exit();
  
  average_process /= wait_locks.size();
  
  var_mutex_enter();
  for (ulint index = 0, size = wait_locks.size(); index < size; ++index)
  {
    lock_t *lock = wait_locks[index];
    double deadline = TraceTool::mean_latency[lock->trx->type];
    double slack = deadline - lock->time_so_far - lock->process_time;
    lock->ranking = wpt_tardy(lock, average_process);
    if (slack > 0)
    {
      lock->ranking = min(lock->ranking, wpt_early(lock, average_process));
    }
  }
  var_mutex_exit();
  
  double max_ranking = 0;
  lock_t *lock = NULL;
  
  for (ulint index = 0, size = wait_locks.size(); index < size; ++index)
  {
    if (wait_locks[index]->ranking > max_ranking)
    {
      max_ranking = wait_locks[index]->ranking;
      lock = wait_locks[index];
    }
  }
  
  return lock;
}

/*************************************************************//**
Clean up resources. */
UNIV_INTERN
void
indi_cleanup()
{
}

