#include "my_global.h"
#include "trace_tool.h"
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

#define NEW_ORDER_MARKER "SELECT C_DISCOUNT, C_LAST, C_CREDIT, W_TAX  FROM CUSTOMER, WAREHOUSE WHERE"
#define PAYMENT_MARKER "UPDATE WAREHOUSE SET W_YTD = W_YTD"
#define ORDER_STATUS_MARKER "SELECT C_FIRST, C_MIDDLE"
#define DELIVERY_MARKER "SELECT NO_O_ID FROM NEW_ORDER WHERE NO_D_ID ="
#define STOCK_LEVEL_MARKER "SELECT D_NEXT_O_ID FROM DISTRICT WHERE D_W_ID ="

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
__thread transaction_type TraceTool::type = NONE;
__thread char * TraceTool::query = NULL;

static const size_t NEW_ORDER_LENGTH = strlen(NEW_ORDER_MARKER);
static const size_t PAYMENT_LENGTH = strlen(PAYMENT_MARKER);
static const size_t ORDER_STATUS_LENGTH = strlen(ORDER_STATUS_MARKER);
static const size_t DELIVERY_LENGTH = strlen(DELIVERY_MARKER);
static const size_t STOCK_LEVEL_LENGTH = strlen(STOCK_LEVEL_MARKER);

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
  log_file.open("logs/trace.log");
#ifdef MONITOR
  const int number_of_functions = NUMBER_OF_FUNCTIONS + 2;
#else
  const int number_of_functions = NUMBER_OF_FUNCTIONS + 4;
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
  transaction_types.reserve(50000);
  transaction_types.push_back(NONE);
  lock_time_mutex = os_mutex_create();
  srand(now_micro());
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
      std::ifstream src("logs/trace.log", std::ios::binary);
      std::ofstream dst("logs/trace.bak", std::ios::binary);
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
    transaction_types.push_back(NONE);
    pthread_rwlock_unlock(&data_lock);
  }
  clock_gettime(CLOCK_REALTIME, &last_query);
  pthread_mutex_lock(&last_query_mutex);
  clock_gettime(CLOCK_REALTIME, &global_last_query);
  pthread_mutex_unlock(&last_query_mutex);
#endif
}

void TraceTool::set_query(const char *new_query)
{
  // Look at the first query of a transaction
  if (new_transaction)
  {
    if (strncmp(new_query, NEW_ORDER_MARKER, NEW_ORDER_LENGTH) == 0)
    {
      type = NEW_ORDER;
    }
    else if (strncmp(new_query, PAYMENT_MARKER, PAYMENT_LENGTH) == 0)
    {
      type = PAYMENT;
    }
    else if (strncmp(new_query, ORDER_STATUS_MARKER, ORDER_STATUS_LENGTH) == 0)
    {
      type = ORDER_STATUS;
    }
    else if (strncmp(new_query, DELIVERY_MARKER, DELIVERY_LENGTH) == 0)
    {
      type = DELIVERY;
    }
    else if (strncmp(new_query, STOCK_LEVEL_MARKER, STOCK_LEVEL_LENGTH) == 0)
    {
      type = STOCK_LEVEL;
    }
    
    transaction_types[current_transaction_id] = type;
    new_transaction = false;
  }
//  query = (char *) malloc(sizeof(char) * (length + 1));
//  strncpy(query, new_query, length);
//  query[length] = '\0';
}

void TraceTool::print_query()
{
  if (query != NULL)
  {
    log_file << query << endl;
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
  type = NONE;
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

void TraceTool::write_latency()
{
  ofstream overall_log;
  ofstream new_order_log;
  ofstream payment_log;
  ofstream order_status_log;
  ofstream delivery_log;
  ofstream stock_level_log;
  
  stringstream sstream;
  sstream << "logs/latency" << log_index;
  overall_log.open(sstream.str().c_str());
  
  sstream.str("");
  sstream << "logs/new_order_" << log_index;
  new_order_log.open(sstream.str().c_str());
  
  sstream.str("");
  sstream << "logs/payment_" << log_index;
  payment_log.open(sstream.str().c_str());
  
  sstream.str("");
  sstream << "logs/order_status_" << log_index;
  order_status_log.open(sstream.str().c_str());
  
  sstream.str("");
  sstream << "logs/delivery_" << log_index;
  delivery_log.open(sstream.str().c_str());
  
  sstream.str("");
  sstream << "logs/stock_level_" << log_index;
  stock_level_log.open(sstream.str().c_str());
  
//  ++log_index;
  
  int function_index = 0;
  pthread_rwlock_wrlock(&data_lock);
  for (unsigned long index = 0; index < transaction_start_times.size(); ++index)
  {
    ulint start_time = transaction_start_times[index];
    if (start_time > 0)
    {
      overall_log << start_time << endl;
      switch (transaction_types[index])
      {
        case NEW_ORDER:
          new_order_log << start_time << endl;
          break;
        case PAYMENT:
          payment_log << start_time << endl;
          break;
        case ORDER_STATUS:
          order_status_log << start_time << endl;
          break;
        case DELIVERY:
          delivery_log << start_time << endl;
          break;
        case STOCK_LEVEL:
          stock_level_log << start_time << endl;
          break;
        default:
          break;
      }
    }
  }
  
  for (vector<vector<ulint> >::iterator iterator = function_times.begin(); iterator != function_times.end(); ++iterator)
  {
    long number_of_transactions = iterator->size();
    for (long index = 0; index < number_of_transactions; ++index)
    {
      if (function_times.back()[index] > 0)
      {
        ulint latency = (*iterator)[index];
        overall_log << function_index << ',' << latency << endl;
        switch (transaction_types[index])
        {
          case NEW_ORDER:
            new_order_log << latency << endl;
            break;
          case PAYMENT:
            payment_log << latency << endl;
            break;
          case ORDER_STATUS:
            order_status_log << latency << endl;
            break;
          case DELIVERY:
            delivery_log << latency << endl;
            break;
          case STOCK_LEVEL:
            stock_level_log << latency << endl;
            break;
          default:
            break;
        }
      }
    }
    function_index++;
    iterator->clear();
  }
  function_times.clear();
  pthread_rwlock_unlock(&data_lock);
  overall_log.close();
  new_order_log.close();
  payment_log.close();
  order_status_log.close();
  delivery_log.close();
  stock_level_log.close();
}

void TraceTool::write_log()
{
  write_latency();
}
