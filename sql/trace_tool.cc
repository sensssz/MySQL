#include "my_global.h"
#include "trace_tool.h"
#include <algorithm>
#include <pthread.h>
#include <fstream>
#include <time.h>
#include <cstring>
#include <sstream>

#define TARGET_PATH_COUNT 13
#define NUMBER_OF_FUNCTIONS 0
#define LATENCY

#define EQUAL(struct1, struct2, field) (struct1->field == struct2->field)

using std::endl;
using std::ofstream;
using std::vector;
using std::stringstream;
using std::sort;

long transaction_id = 0;

TraceTool *TraceTool::instance = NULL;
pthread_mutex_t TraceTool::instance_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_rwlock_t TraceTool::data_lock = PTHREAD_RWLOCK_INITIALIZER;
__thread long TraceTool::current_transaction_id = 0;
__thread timespec TraceTool::last_query;

timespec TraceTool::start_time = {0, 0};
timespec TraceTool::global_last_query;
pthread_mutex_t TraceTool::last_query_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t TraceTool::record_lock_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t TraceTool::average_mutex = PTHREAD_MUTEX_INITIALIZER;
long TraceTool::commited_trans = 0;
double TraceTool::average_latency = 0;
double TraceTool::average_work_time = 0;
ulint TraceTool::num_of_deadlocks = 0;

vector<lock_time_info> TraceTool::lock_time_infos;
os_ib_mutex_t TraceTool::lock_time_mutex = os_mutex_create();
__thread bool TraceTool::do_monitor = false;

long TraceTool::total_release_time = 0;
long TraceTool::have_choice_time = 0;
long TraceTool::needs_to_grant = 0;

__thread int TraceTool::path_count = 0;
__thread bool TraceTool::is_commit = false;
__thread bool TraceTool::commit_successful = false;
__thread bool TraceTool::new_transaction = true;


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
  const int number_of_functions = NUMBER_OF_FUNCTIONS + 2;
#endif
  for (int index = 0; index < number_of_functions; index++)
  {
    vector<ulint> function_time;
    function_time.reserve(500000);
    function_time.push_back(0);
    function_times.push_back(function_time);
  }
  transaction_start_times.push_back(0);
}

bool TraceTool::should_monitor()
{
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
      
      TraceTool *old_instace = instance;
      instance = new TraceTool;
      transaction_id = 0;
      
      old_instace->write_log();
      delete old_instace;
      
      total_release_time = 0;
      have_choice_time = 0;
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

long TraceTool::difftime(timespec start, timespec end)
{
  return (end.tv_sec - start.tv_sec) * 1000000000 + (end.tv_nsec - start.tv_nsec);
}

long now_micro()
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

record_lock *TraceTool::find_record_lock(lock_info *lock_info)
{
//  for (vector<record_lock *>::iterator iterator = record_locks.begin(); iterator != record_locks.end(); ++iterator)
//  {
//    if (lock_equal(&(*iterator)->info, lock_info))
//    {
//      return *iterator;
//    }
//  }
  return NULL;
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

void TraceTool::start_new_query()
{
  is_commit = false;
#ifdef LATENCY
  if (new_transaction)
  {
    new_transaction = false;
    pthread_rwlock_wrlock(&data_lock);
    current_transaction_id = transaction_id++;
    transaction_start_times[current_transaction_id] = now_micro();
    
    for (vector<vector<ulint> >::iterator iterator = function_times.begin(); iterator != function_times.end(); ++iterator)
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

void TraceTool::end_query()
{
#ifdef LATENCY
  if (current_transaction_id > transaction_id)
  {
    current_transaction_id = 0;
  }
  timespec now = get_time();
  long latency = difftime(last_query, now);
  pthread_rwlock_rdlock(&data_lock);
  function_times.back()[current_transaction_id] += latency;
  pthread_rwlock_unlock(&data_lock);
#endif
}

void TraceTool::end_transaction()
{
#ifdef LATENCY
  if (commit_successful)
  {
    new_transaction = true;
  }
  else
  {
    // Reuse the last transaction
    function_times.back()[current_transaction_id] = 0;
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

bool compare_record_lock(record_lock *lock1, record_lock *lock2)
{
  return lock1->waiting_times.size() > lock2->waiting_times.size();
}

void TraceTool::write_log()
{
  ofstream work_wait("lock_wait");
  os_mutex_enter(lock_time_mutex);
  for (auto info : lock_time_infos)
  {
    work_wait << info.work_time_so_far << "," << info.wait_time_so_far << "," << info.total_work_time << endl;
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
    log << transaction_start_times[index] << endl;
  }
  
  for (vector<vector<ulint> >::iterator iterator = function_times.begin(); iterator != function_times.end(); ++iterator)
  {
    long number_of_transactions = iterator->size();
    for (long index = 0; index < number_of_transactions; ++index)
    {
      log << function_index << ',' << (*iterator)[index] << endl;
    }
    function_index++;
    iterator->clear();
  }
  function_times.clear();
  pthread_rwlock_unlock(&data_lock);
  log.close();
  
  log_file << "Number of deadlocks: " << num_of_deadlocks << endl;
  
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