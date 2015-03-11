#include "my_global.h"
#include "trace_tool.h"

#include <pthread.h>
#include <fstream>
#include <time.h>
#include <cstring>
#include <execinfo.h>
#include <sstream>

#define TARGET_PATH_COUNT 2
#define NUMBER_OF_FUNCTIONS 4

using std::endl;
using std::ofstream;
using std::vector;
using std::stringstream;

long transaction_id = 0;

TraceTool *TraceTool::instance = NULL;
pthread_mutex_t TraceTool::instance_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_rwlock_t TraceTool::data_lock = PTHREAD_RWLOCK_INITIALIZER;
__thread long TraceTool::current_transaction_id = 0;
__thread timespec TraceTool::last_query;

timespec TraceTool::start_time = {0, 0};
timespec TraceTool::global_last_query;
pthread_mutex_t TraceTool::last_query_mutex = PTHREAD_MUTEX_INITIALIZER;

__thread int TraceTool::path_count = 0;
__thread bool TraceTool::is_commit = false;
__thread bool TraceTool::commit_successful = false;

static __thread timespec function_start;
static __thread timespec function_end;
static __thread timespec call_start;
static __thread timespec call_end;

__thread bool TraceTool::new_transaction = true;

static int log_index = 0;

void TRACE_FUNCTION_START()
{
  if (TraceTool::should_monitor())
  {
    clock_gettime(CLOCK_REALTIME, &function_start);
  }
}

void TRACE_FUNCTION_END()
{
  if (TraceTool::should_monitor())
  {
    clock_gettime(CLOCK_REALTIME, &function_end);
    TraceTool::get_instance()->add_record(0, TraceTool::difftime(function_start, function_end));
  }
}

bool TRACE_START()
{
  if (TraceTool::should_monitor())
  {
    clock_gettime(CLOCK_REALTIME, &call_start);
  }
  return false;
}

bool TRACE_END(int index)
{
  if (TraceTool::should_monitor())
  {
    clock_gettime(CLOCK_REALTIME, &call_end);
    TraceTool::get_instance()->add_record(index, TraceTool::difftime(call_start, call_end));
  }
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
      start_time = get_time();
      pthread_t write_thread;
      pthread_create(&write_thread, NULL, check_write_log, NULL);
    }
    pthread_mutex_unlock(&instance_mutex);
  }
  return instance;
}

TraceTool::TraceTool() : function_times()
{
  log_file.open("/usr/local/mysql/data/trace.log");
  const int number_of_functions = NUMBER_OF_FUNCTIONS + 2;
  for (int index = 0; index < number_of_functions; index++)
  {
    vector<long> function_time;
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
      std::ifstream src("/usr/local/mysql/data/trace.log", std::ios::binary);
      std::ofstream dst("/usr/local/mysql/data/trace.bak", std::ios::binary);
      dst << src.rdbuf();
      
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

void TraceTool::start_new_query()
{
  if (new_transaction)
  {
    new_transaction = false;
    pthread_rwlock_wrlock(&data_lock);
    current_transaction_id = transaction_id++;
    transaction_start_times[current_transaction_id] = now_micro();
    
    for (vector<vector<long> >::iterator iterator = function_times.begin(); iterator != function_times.end(); ++iterator)
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
}

void TraceTool::end_query()
{
  if (current_transaction_id > transaction_id)
  {
    current_transaction_id = 0;
  }
  timespec now = get_time();
  long latency = difftime(last_query, now);
  pthread_rwlock_rdlock(&data_lock);
  function_times.back()[current_transaction_id] += latency;
  pthread_rwlock_unlock(&data_lock);
}

void TraceTool::end_transaction()
{
  if (commit_successful)
  {
    new_transaction = true;
  }
  else
  {
    function_times.back()[current_transaction_id] = 0;
  }
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

void TraceTool::write_log()
{
  ofstream log;
  stringstream sstream;
  sstream << "/usr/local/mysql/data/trace" << log_index++;
  log.open(sstream.str().c_str());
  int function_index = 0;
  pthread_rwlock_wrlock(&data_lock);
  for (unsigned long index = 0; index < transaction_start_times.size(); ++index)
  {
    log << transaction_start_times[index] << endl;
  }
  for (vector<vector<long> >::iterator iterator = function_times.begin(); iterator != function_times.end(); ++iterator)
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
}