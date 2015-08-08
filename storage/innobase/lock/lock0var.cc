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
  transaction_type type)
{
  switch (type) {
    case NEW_ORDER:
      return new_order_estimate(parameters);
    case PAYMENT:
      return payment_estimate(parameters);
//    case ORDER_STATUS:
    case DELIVERY:
      return delivery_estimate(parameters);
    case STOCK_LEVEL:
      return stock_level_estimate(parameters);
    default:
      return tpcc_estimate(parameters);
  }
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
  ut_ad(lock);

  return(lock->type_mode & LOCK_WAIT);
}

/*************************************************************//**
Find the lock that gives minimum CTV. */
UNIV_INTERN
void
estimate(
  list<lock_t *> &wait_locks)  /*!< waiting locks */
{
  
  timespec now = TraceTool::get_time();
  estimate_mutex_enter();
  for (list<lock_t *>::iterator iter = wait_locks.begin();
       iter != wait_locks.end(); ++iter)
  {
    lock_t *lock = *iter;
    trx_t *trx = lock->trx;
    lock->time_so_far = TraceTool::difftime(trx->trx_start_time, now);
    long wait_so_far = (long) trx->total_wait_time;
    if (lock_get_wait(lock))
    {
      wait_so_far += (long) TraceTool::difftime(lock->wait_start, now);
    }
    long work_so_far = lock->time_so_far - wait_so_far;
    long num_locks = UT_LIST_GET_LEN(trx->lock.trx_locks);
    work_wait parameters = TraceTool::get_instance()->parameters(work_so_far, wait_so_far, num_locks,
                                                                 wait_locks.size(), trx->transaction_id);
    lock->process_time = estimate(parameters, trx->type);
    
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
}

/*************************************************************//**
Clean up resources. */
UNIV_INTERN
void
indi_cleanup()
{
}

