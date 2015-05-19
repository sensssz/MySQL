#include "my_global.h"
#include "trace_tool.h"
#include "../storage/innobase/include/lock0var.h"
#include <algorithm>
#include <pthread.h>
#include <fstream>
#include <time.h>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cassert>

#define TARGET_PATH_COUNT 13
#define NUMBER_OF_FUNCTIONS 0
#define LATENCY

#define EQUAL(struct1, struct2, field) (struct1->field == struct2->field)

using std::endl;
using std::ofstream;
using std::vector;
using std::stringstream;
using std::sort;

ulint transaction_id = 0;

TraceTool *TraceTool::instance = NULL;
pthread_mutex_t TraceTool::instance_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_rwlock_t TraceTool::data_lock = PTHREAD_RWLOCK_INITIALIZER;
__thread ulint TraceTool::current_transaction_id = 0;
__thread timespec TraceTool::last_query;

timespec TraceTool::start_time = {0, 0};
timespec TraceTool::global_last_query;
pthread_mutex_t TraceTool::last_query_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t TraceTool::record_lock_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t TraceTool::average_mutex = PTHREAD_MUTEX_INITIALIZER;
ulint TraceTool::num_of_deadlocks = 0;
double TraceTool::average_latency = 0;
ulint TraceTool::num_of_trans = 0;
ulint TraceTool::num_of_rollback = 0;

__thread int TraceTool::path_count = 0;
__thread bool TraceTool::is_commit = false;
__thread bool TraceTool::commit_successful = true;
__thread bool TraceTool::new_transaction = true;
__thread timespec TraceTool::trans_start;
__thread char * TraceTool::query = NULL;

#ifdef MONITOR
static __thread timespec function_start;
static __thread timespec function_end;
static __thread timespec call_start;
static __thread timespec call_end;
#endif


static int log_index = 0;

void TRACE_FUNCTION_START()
{
#ifdef MONITOR
  if (TraceTool::should_monitor())
  {
    clock_gettime(CLOCK_REALTIME, &function_start);
  }
#endif
}

void TRACE_FUNCTION_END()
{
#ifdef MONITOR
  if (TraceTool::should_monitor())
  {
    clock_gettime(CLOCK_REALTIME, &function_end);
    TraceTool::get_instance()->add_record(0, TraceTool::difftime(function_start, function_end));
  }
#endif
}

bool TRACE_START()
{
#ifdef MONITOR
  if (TraceTool::should_monitor())
  {
    clock_gettime(CLOCK_REALTIME, &call_start);
  }
#endif
  return false;
}

bool TRACE_END(int index)
{
#ifdef MONITOR
  if (TraceTool::should_monitor())
  {
    clock_gettime(CLOCK_REALTIME, &call_end);
    TraceTool::get_instance()->add_record(index, TraceTool::difftime(call_start, call_end));
  }
#endif
  return false;
}

TraceTool *TraceTool::get_instance()
{
  if (instance == NULL)
  {
    pthread_mutex_lock(&instance_mutex);
    if (instance == NULL)
    {
      instance = new TraceTool;
#ifdef LATENCY
      start_time = get_time();
      pthread_t write_thread;
      pthread_create(&write_thread, NULL, check_write_log, NULL);
#endif
    }
    pthread_mutex_unlock(&instance_mutex);
  }
  return instance;
}

TraceTool::TraceTool() : function_times()
{
  log_file.open("trace.log");
#ifdef MONITOR
  const int number_of_functions = NUMBER_OF_FUNCTIONS + 2;
#else
  const int number_of_functions = NUMBER_OF_FUNCTIONS + 1;
#endif
  for (int index = 0; index < number_of_functions; index++)
  {
    vector<ulint> function_time;
    function_time.reserve(500000);
    function_time.push_back(0);
    function_times.push_back(function_time);
  }
  transaction_start_times.reserve(500000);
  transaction_start_times.push_back(0);
  lock_time_mutex = os_mutex_create();
//  srand(now_micro());
}

bool TraceTool::should_monitor()
{
  return true;
  return path_count == TARGET_PATH_COUNT;
}

void *TraceTool::check_write_log(void *arg)
{
  while (true)
  {
    sleep(5);
    timespec now = get_time();
    if (now.tv_sec - global_last_query.tv_sec >= 5 && transaction_id > 0)
    {
      std::ifstream src("trace.log", std::ios::binary);
      std::ofstream dst("trace.bak", std::ios::binary);
      dst << src.rdbuf();
      src.close();
      dst.close();
      
      TraceTool *old_instace = instance;
      instance = new TraceTool;
      transaction_id = 0;
      
      old_instace->write_log();
      delete old_instace;
    }
  }
  return NULL;
}

timespec TraceTool::get_time()
{
  timespec now;
  clock_gettime(CLOCK_REALTIME, &now);
  return now;
}

ulint TraceTool::difftime(timespec start, timespec end)
{
  return (end.tv_sec - start.tv_sec) * 1000000000 + (end.tv_nsec - start.tv_nsec);
}

ulint TraceTool::now_micro()
{
  timespec now;
  clock_gettime(CLOCK_REALTIME, &now);
  return now.tv_sec * 1000000 + now.tv_nsec / 1000;
}

bool lock_equal(lock_info *lock1, lock_info *lock2)
{
  return EQUAL(lock1, lock2, space_id) && EQUAL(lock1, lock2, page_no) &&
  EQUAL(lock1, lock2, heap_no) && EQUAL(lock1, lock2, type_mode);
}

void TraceTool::start_waiting(lock_info *lock_info, lock_request *request)
{
  pthread_mutex_lock(&record_lock_mutex);
  record_lock *lock_waiting_on = record_lock_map[*lock_info];
  if (lock_waiting_on == NULL)
  {
    lock_waiting_on = new record_lock;
    lock_waiting_on->info.space_id = lock_info->space_id;
    lock_waiting_on->info.page_no = lock_info->page_no;
    lock_waiting_on->info.heap_no = lock_info->heap_no;
    lock_waiting_on->info.type_mode = lock_info->type_mode;
    record_lock_map[*lock_info] = lock_waiting_on;
  }
  pthread_mutex_unlock(&record_lock_mutex);
  request->lock = lock_waiting_on;
  request->start_waiting_time = get_time();
}

void TraceTool::end_waiting(lock_request *request)
{
  if (request != NULL && request->lock_object != NULL)
  {
    long waiting_time = difftime(request->start_waiting_time, get_time());
    request->lock->waiting_times.push_back(waiting_time);
  }
}

void TraceTool::lock_wait_info(ulint trans_id, ulint trx_id, ulint work_time, ulint wait_time, uint num_of_locks)
{
  lock_time_info info(trans_id, trx_id, work_time, wait_time, num_of_locks);
  os_mutex_enter(lock_time_mutex);
  lock_time_infos.push_back(info);
  os_mutex_exit(lock_time_mutex);
}

void TraceTool::remove(ulint trx_id)
{
  int num_removed = 0;
  os_mutex_enter(lock_time_mutex);
  for (list<lock_time_info>::iterator iterator = lock_time_infos.begin();
       iterator != lock_time_infos.end();
       )
  {
    if (iterator->trx_id == trx_id)
    {
      // automatically moves the iterator forward
      iterator = lock_time_infos.erase(iterator);
      ++num_removed;
    }
    else
    {
      ++iterator;
    }
  }
  os_mutex_exit(lock_time_mutex);
}

void TraceTool::start_new_query()
{
  is_commit = false;
  if (current_transaction_id > transaction_id)
  {
    current_transaction_id = 0;
    new_transaction = true;
    commit_successful = true;
  }
#ifdef LATENCY
  if (new_transaction)
  {
    trans_start = get_time();
    new_transaction = false;
    commit_successful = true;
    pthread_rwlock_wrlock(&data_lock);
    current_transaction_id = transaction_id++;
    transaction_start_times[current_transaction_id] = now_micro();
    for (vector<vector<ulint> >::iterator iterator = function_times.begin();
         iterator != function_times.end();
         ++iterator)
    {
      iterator->push_back(0);
    }
    transaction_start_times.push_back(0);
    pthread_rwlock_unlock(&data_lock);
  }
  clock_gettime(CLOCK_REALTIME, &last_query);
  pthread_mutex_lock(&last_query_mutex);
  clock_gettime(CLOCK_REALTIME, &global_last_query);
  pthread_mutex_unlock(&last_query_mutex);
#endif
}

void TraceTool::set_query(const char *new_query, int length)
{
//  query = (char *) malloc(sizeof(char) * (length + 1));
//  strncpy(query, new_query, length);
//  query[length] = '\0';
}

void TraceTool::print_query()
{
  if (query != NULL)
  {
    log_file << query << "," << is_commit << "," << commit_successful << endl;
  }
}

void TraceTool::end_query()
{
  free(query);
  query = NULL;
#ifdef LATENCY
  if (is_commit)
  {
    end_transaction();
  }
#endif
}

void TraceTool::end_transaction()
{
  new_transaction = true;
#ifdef LATENCY
  if (commit_successful)
  {
    timespec now = get_time();
    long latency = difftime(trans_start, now);
    pthread_rwlock_rdlock(&data_lock);
    function_times.back()[current_transaction_id] = latency;
    pthread_rwlock_unlock(&data_lock);
  }
  else
  {
    pthread_rwlock_rdlock(&data_lock);
    // Reuse the last transaction
    function_times.back()[current_transaction_id] = 0;
    transaction_start_times[current_transaction_id] = 0;
    pthread_rwlock_unlock(&data_lock);
  }
#endif
}

void TraceTool::add_record(int function_index, long duration)
{
  if (current_transaction_id > transaction_id)
  {
    current_transaction_id = 0;
  }
  pthread_rwlock_rdlock(&data_lock);
  function_times[function_index][current_transaction_id] += duration;
  pthread_rwlock_unlock(&data_lock);
}

void TraceTool::add_record_if_zero(int function_index, long duration)
{
  if (current_transaction_id > transaction_id)
  {
    current_transaction_id = 0;
  }
  pthread_rwlock_rdlock(&data_lock);
  function_times[function_index][current_transaction_id] = duration;
  pthread_rwlock_unlock(&data_lock);
}

bool compare_record_lock(record_lock *lock1, record_lock *lock2)
{
  return lock1->waiting_times.size() > lock2->waiting_times.size();
}

void TraceTool::write_log()
{
  write_separator_log();
  ofstream work_wait("lock_wait");
  os_mutex_enter(lock_time_mutex);
  for (list<lock_time_info>::iterator iterator = lock_time_infos.begin();
       iterator != lock_time_infos.end();
       ++iterator)
  {
    lock_time_info &info = *iterator;
    if (info.transaction_id != 0 &&
        function_times.back()[info.transaction_id] != 0)
    {
      assert(function_times[0][info.transaction_id] > info.work_time_so_far);
      assert(function_times[1][info.transaction_id] >= info.wait_time_so_far);
      assert(function_times[2][info.transaction_id] >= info.num_of_locks_so_far);
      work_wait << transaction_start_times[info.transaction_id] << "," << info.transaction_id << "," <<
                   info.work_time_so_far << "," << info.wait_time_so_far << "," << info.num_of_locks_so_far << "," <<
                   function_times[0][info.transaction_id] <<  "," << function_times[1][info.transaction_id] << "," <<
                   function_times[2][info.transaction_id] << endl;
    }
  }
  lock_time_infos.clear();
  os_mutex_exit(lock_time_mutex);
  work_wait.close();
  
  ofstream log;
  stringstream sstream;
  sstream << "trace" << log_index++;
  log.open(sstream.str().c_str());
  int function_index = 0;
  pthread_rwlock_wrlock(&data_lock);
  for (unsigned long index = 0; index < transaction_start_times.size(); ++index)
  {
    if (transaction_start_times[index] > 0)
    {
      log << transaction_start_times[index] << endl;
    }
  }
  
  for (vector<vector<ulint> >::iterator iterator = function_times.begin(); iterator != function_times.end(); ++iterator)
  {
    long number_of_transactions = iterator->size();
    for (long index = 0; index < number_of_transactions; ++index)
    {
      if (function_times.back()[index] > 0)
      {
        log << function_index << ',' << (*iterator)[index] << endl;
      }
    }
    function_index++;
    iterator->clear();
  }
  function_times.clear();
  pthread_rwlock_unlock(&data_lock);
  log.close();
  
  ofstream lock_waiting_log("lock");
  pthread_mutex_lock(&record_lock_mutex);
  lock_waiting_log << "Number of locks: " << record_lock_map.size() << endl;
  for (auto lock_map : record_lock_map)
  {
    record_lock *lock = lock_map.second;
    lock_waiting_log << "Lock: " << lock->info.space_id << "," << lock->info.page_no << ","
    << lock->info.heap_no << "," << lock->info.type_mode << "," << lock->waiting_times.size() << endl;
    for (auto time : lock->waiting_times)
    {
      lock_waiting_log << time << endl;
    }
    delete lock;
  }
  pthread_mutex_unlock(&record_lock_mutex);
  record_lock_map.clear();
  lock_waiting_log.close();
}