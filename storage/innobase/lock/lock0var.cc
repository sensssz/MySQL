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

/*************************************************************//**
Do initilization for the min-variance scheduling algorithm. */
UNIV_INTERN
void
indi_init()
{
}

/*************************************************************//**
Find the lock that gives minimum CTV. */
UNIV_INTERN
void
LVM_schedule(
  vector<lock_t *> &wait_locks,  /*!< waiting locks */
  vector<lock_t *> &locks_to_grant) /*!< locks to grant */
{
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
//  ulint wait_size = wait_locks.size();
//  estimate_mutex_enter();
//  for (ulint index = 0; index < wait_size; ++index)
//  {
//    lock_t *lock = wait_locks[index];
//    trx_t *trx = lock->trx;
//    lock->time_so_far = TraceTool::difftime(trx->trx_start_time, now);
//    long wait_so_far = trx->total_wait_time + TraceTool::difftime(lock->wait_start, now);
//    long work_so_far = lock->time_so_far - wait_so_far;
//    long num_locks = UT_LIST_GET_LEN(trx->lock.trx_locks);
//    work_wait parameters = TraceTool::get_instance()->parameters(work_so_far, wait_so_far, num_locks,
//                                                                 wait_locks.size(), trx->transaction_id);
//    lock->process_time = estimate(parameters, trx->type, lock_get_type(lock));
//    
////    if ((rand() % 100 < 20 ||
////         trx->type == ORDER_STATUS ||
////         trx->type == DELIVERY ||
////         trx->type == STOCK_LEVEL) &&
////        trx->is_user_trx)
////    {
////      lock->time_at_grant = TraceTool::get_instance()->add_work_wait(work_so_far, wait_so_far, num_locks,
////                                                                     wait_locks.size(), lock->process_time, trx->transaction_id);
////    }
//  }
//  
//  estimate_mutex_exit();
//  
//  vector<lock_t *> write_locks;
//  vector<lock_t *> read_locks;
//  vector<lock_t *> *min_order = NULL;
//  
//  double mean_latency = TraceTool::mean_latency;
//  var_mutex_enter();
//  merge_read_locks(wait_locks, write_locks, read_locks);
//  sort(write_locks.begin(), write_locks.end(), compare_by_process);
//  int num_write_locks = write_locks.size();
//  double min_var = std::numeric_limits<double>::max();
//  int min_var_read_index = -1;
//  for (int read_index = 0; read_index <= num_write_locks; ++read_index)
//  {
//    assign_rankings(write_locks, read_locks, wait_locks, read_index);
//    double var_heu = heuristic(wait_locks);
//    if (var_heu < min_var)
//    {
//      min_var = var_heu;
//      min_var_read_index = read_index;
//    }
//  }
//  var_mutex_exit();
//  assign_rankings(write_locks, read_locks, wait_locks, min_var_read_index);
//  for (ulint index = 0; index < wait_size; ++index)
//  {
//    wait_locks[index]->trx->queued = true;
//  }
//  
//  lock_t *lock = wait_locks[0];
////  TraceTool::get_instance()->get_log() << lock->un_member.rec_lock.space << ","
////  << lock->un_member.rec_lock.page_no << "," << lock_rec_find_set_bit(lock) << endl;
//  bool do_monitor = lock->un_member.rec_lock.space == 14 &&
//                    lock->un_member.rec_lock.page_no == 3 &&
//                    lock_rec_find_set_bit(lock) == 20 && false;
//  if (do_monitor)
//  {
//    ofstream &log = TraceTool::get_instance()->get_log();
////    log << min_order->size() << "," << read_locks.size() << endl;
//    log << "  mean_latency = " << mean_latency << ";" << endl;
//    for (ulint index = 0, size = wait_locks.size(); index < size; ++index)
//    {
//      lock_t *lock = wait_locks[index];
//      trx_t *trx = lock->trx;
//      log << "  lock_t lock" << index << "={" << trx->id << ",'" << lock_get_mode_str(lock) << "',"
//          << lock->ranking << "," << lock->time_so_far << "," << lock->process_time << "," << lock->trx->queued << "};" << endl;
//    }
//    log << endl;
//  }
//  
//  ofstream &log = TraceTool::get_instance()->get_log();
//  //    log << min_order->size() << "," << read_locks.size() << endl;
//  log << "  mean_latency = " << mean_latency << ";" << endl;
//  for (ulint index = 0, size = wait_locks.size(); index < size; ++index)
//  {
//    lock_t *lock = wait_locks[index];
//    trx_t *trx = lock->trx;
//    log << "  lock_t lock" << index << "={" << trx->id << ",'" << lock_get_mode_str(lock) << "',"
//    << lock->ranking << "," << lock->time_so_far << "," << lock->process_time << "," << "0,0,false};" << endl;
//  }
//  log << endl;
//  
//  
//  ulint index = 0;
//  while (index < wait_size &&
//         wait_locks[index]->ranking == 0)
//  {
//    locks_to_grant.push_back(wait_locks[index]);
//    ++index;
//  }
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

