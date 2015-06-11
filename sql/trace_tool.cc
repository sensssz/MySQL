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

#define TARGET_PATH_COUNT 42
#define NUMBER_OF_FUNCTIONS 0
#define LATENCY

#define NEW_ORDER_MARKER "SELECT C_DISCOUNT, C_LAST, C_CREDIT, W_TAX  FROM CUSTOMER, WAREHOUSE WHERE"
#define PAYMENT_MARKER "UPDATE WAREHOUSE SET W_YTD = W_YTD"
#define ORDER_STATUS_MARKER "SELECT C_FIRST, C_MIDDLE"
#define DELIVERY_MARKER "SELECT NO_O_ID FROM NEW_ORDER WHERE NO_D_ID ="
#define STOCK_LEVEL_MARKER "SELECT D_NEXT_O_ID FROM DISTRICT WHERE D_W_ID ="

#define WRITE_MARKER "UPDATE Snape SET NAME='Marvin' WHERE ID = 1"
#define READ_MARKER "SELECT AGE FROM Snape WHERE ID = 1"

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

timespec TraceTool::global_last_query;
pthread_mutex_t TraceTool::last_query_mutex = PTHREAD_MUTEX_INITIALIZER;

__thread int TraceTool::path_count = 0;
__thread bool TraceTool::is_commit = false;
__thread bool TraceTool::commit_successful = true;
__thread bool TraceTool::new_transaction = true;
__thread timespec TraceTool::trans_start;
__thread transaction_type TraceTool::type = NONE;

ulint TraceTool::num_trans = 0;
double TraceTool::mean_latency = 0;
double TraceTool::var_latency = 0;
pthread_mutex_t TraceTool::var_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t TraceTool::work_wait_mutex = PTHREAD_MUTEX_INITIALIZER;

static const size_t NEW_ORDER_LENGTH = strlen(NEW_ORDER_MARKER);
static const size_t PAYMENT_LENGTH = strlen(PAYMENT_MARKER);
static const size_t ORDER_STATUS_LENGTH = strlen(ORDER_STATUS_MARKER);
static const size_t DELIVERY_LENGTH = strlen(DELIVERY_MARKER);
static const size_t STOCK_LEVEL_LENGTH = strlen(STOCK_LEVEL_MARKER);

/* Define MONITOR if needs to trace running time of functions. */
#ifdef MONITOR
static __thread timespec function_start;
static __thread timespec function_end;
static __thread timespec call_start;
static __thread timespec call_end;
#endif

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

/********************************************************************//**
Get the current TraceTool instance. */
TraceTool *TraceTool::get_instance()
{
  if (instance == NULL)
  {
    pthread_mutex_lock(&instance_mutex);
    /* Check instance again after entering the ciritical section
       to prevent double initilization. */
    if (instance == NULL)
    {
      instance = new TraceTool;
#ifdef LATENCY
      /* Create a background thread for dumping function running time
         and latency data. */
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
  /* Open the log file in append mode so that it won't be overwritten */
  log_file.open("logs/trace.log");
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
  transaction_types.reserve(500000);
  transaction_types.push_back(NONE);
  
  srand(time(0));
}

bool TraceTool::should_monitor()
{
  return path_count == TARGET_PATH_COUNT;
}

void *TraceTool::check_write_log(void *arg)
{
  /* Runs in an infinite loop and for every 5 seconds,
     check if there's any query comes in. If not, then
     dump data to log files. */
  while (true)
  {
    sleep(5);
    timespec now = get_time();
    if (now.tv_sec - global_last_query.tv_sec >= 5 && transaction_id > 0)
    {
      /* Create a back up of the debug log file in case it's overwritten. */
      std::ifstream src("logs/trace.log", std::ios::binary);
      std::ofstream dst("logs/trace.bak", std::ios::binary);
      dst << src.rdbuf();
      src.close();
      dst.close();
      
      /* Create a new TraceTool instnance. */
      TraceTool *old_instace = instance;
      instance = new TraceTool;
      
      /* Reset the global transaction ID. */
      transaction_id = 0;
      
      num_trans = 0;
      mean_latency = 0;
      var_latency = 0;
      
      /* Dump data in the old instance to log files and
         reclaim memory. */
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

/********************************************************************//**
Start a new query. This may also start a new transaction. */
void TraceTool::start_new_query()
{
  is_commit = false;
  /* This happens when a log write happens, which marks the end of a phase. */
  if (current_transaction_id > transaction_id)
  {
    current_transaction_id = 0;
    new_transaction = true;
    commit_successful = true;
  }
#ifdef LATENCY
  /* Start a new transaction. Note that we don't reset the value of new_transaction here.
     We do it in set_query after looking at the first query of a transaction. */
  if (new_transaction)
  {
    trans_start = get_time();
    commit_successful = true;
    /* Use a write lock here because we are appending content to the vector. */
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
    else
    {
      type = NONE;
      commit_successful = false;
    }
    
    transaction_types[current_transaction_id] = type;
    /* Reset the value of new_transaction. */
    new_transaction = false;
  }
}

void TraceTool::end_query()
{
#ifdef LATENCY
  if (is_commit)
  {
    end_transaction();
  }
#endif
}

/********************************************************************//**
Sumbits the total wait time of a transaction. */
void TraceTool::update_ctv(ulint latency)
{
  ++num_trans;
  double old_mean = mean_latency;
  double old_variance = var_latency;
  mean_latency = old_mean + (latency - old_mean) / num_trans;
  var_latency = old_variance + (latency - old_mean) * (latency - mean_latency);
}

/********************************************************************//**
Sumbits the total wait time of a transaction. */
void TraceTool::update_ctv(ulint latency, ulint &num_trans, double &mean, double &variance)
{
  ++num_trans;
  double old_mean = mean;
  double old_variance = variance;
  mean = old_mean + (latency - old_mean) / num_trans;
  variance = old_variance + (latency - old_mean) * (latency - mean);
}

void TraceTool::end_transaction()
{
  new_transaction = true;
  type = NONE;
#ifdef LATENCY
  timespec now = get_time();
  ulint latency = difftime(trans_start, now);
  pthread_rwlock_rdlock(&data_lock);
  function_times.back()[current_transaction_id] = latency;
  if (!commit_successful)
  {
    transaction_start_times[current_transaction_id] = 0;
  }
  pthread_rwlock_unlock(&data_lock);
  if (commit_successful)
  {
    pthread_mutex_lock(&var_mutex);
    update_ctv(latency);
    pthread_mutex_unlock(&var_mutex);
  }
#endif
}

void TraceTool::add_work_wait(ulint work_so_far, ulint wait_so_far, ulint num_locks, ulint transaction_id)
{
  work_wait record;
  record.work_so_far = work_so_far;
  record.wait_so_far = wait_so_far;
  record.num_locks_so_far = num_locks;
  record.transaction_id = transaction_id;
  pthread_mutex_lock(&work_wait_mutex);
  work_waits.push_back(record);
  pthread_mutex_unlock(&work_wait_mutex);
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

void TraceTool::write_latency(string dir)
{
  ofstream tpcc_log;
  ofstream new_order_log;
  ofstream payment_log;
  ofstream order_status_log;
  ofstream delivery_log;
  ofstream stock_level_log;
  
  tpcc_log.open(dir + "tpcc");
  new_order_log.open(dir + "new_order");
  payment_log.open(dir + "payment");
  order_status_log.open(dir + "order_status");
  delivery_log.open(dir + "delivery");
  stock_level_log.open(dir + "stock_level");
  
  pthread_rwlock_wrlock(&data_lock);
  for (ulint index = 0; index < transaction_start_times.size(); ++index)
  {
    ulint start_time = transaction_start_times[index];
    if (start_time > 0)
    {
      tpcc_log << start_time << endl;
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
  
  int function_index = 0;
  for (vector<vector<ulint> >::iterator iterator = function_times.begin(); iterator != function_times.end(); ++iterator)
  {
    ulint number_of_transactions = iterator->size();
    for (ulint index = 0; index < number_of_transactions; ++index)
    {
      if (transaction_start_times[index] > 0)
      {
        ulint latency = (*iterator)[index];
        tpcc_log << function_index << ',' << latency << endl;
        switch (transaction_types[index])
        {
          case NEW_ORDER:
            new_order_log << function_index << ',' << latency << endl;
            break;
          case PAYMENT:
            payment_log << function_index << ',' << latency << endl;
            break;
          case ORDER_STATUS:
            order_status_log << function_index << ',' << latency << endl;
            break;
          case DELIVERY:
            delivery_log << function_index << ',' << latency << endl;
            break;
          case STOCK_LEVEL:
            stock_level_log << function_index << ',' << latency << endl;
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
  tpcc_log.close();
  new_order_log.close();
  payment_log.close();
  order_status_log.close();
  delivery_log.close();
  stock_level_log.close();
}

void TraceTool::write_work_wait()
{
  ofstream tpcc("work_wait/tpcc");
  ofstream new_order("work_wait/new_order");
  ofstream payment("work_wait/payment");
  ofstream order_status("work_wait/order_status");
  ofstream delivery("work_wait/delivery");
  ofstream stock_level("work_wait/stock_level");
  
  for (ulint index = 0, size = work_waits.size();
       index < size; ++index)
  {
    work_wait &record = work_waits[index];
    if (transaction_start_times[record.transaction_id] > 0)
    {
      transaction_type type = transaction_types[record.transaction_id];
      ulint latency = function_times.back()[record.transaction_id];
      ulint total_wait = function_times[0][record.transaction_id];
      ulint total_work = latency - total_wait;
      
      if (latency <= total_wait ||
          total_wait < record.wait_so_far ||
          total_work < record.work_so_far)
      {
        continue;
      }
      
      stringstream line;
      
      line << record.work_so_far << "," << record.wait_so_far << ","
           << record.num_locks_so_far << "," << latency << endl;
      tpcc << line.str().c_str();
      switch (type)
      {
        case NEW_ORDER:
          new_order << line.str().c_str();
          break;
        case PAYMENT:
          payment << line.str().c_str();
          break;
        case ORDER_STATUS:
          order_status << line.str().c_str();
          break;
        case DELIVERY:
          delivery << line.str().c_str();
          break;
        case STOCK_LEVEL:
          stock_level << line.str().c_str();
          break;
        default:
          break;
      }
      
      line.str("");
    }
  }
  
  tpcc.close();
  new_order.close();
  payment.close();
  order_status.close();
  delivery.close();
  stock_level.close();
}

void TraceTool::write_log()
{
  write_work_wait();
  write_latency("latency/original/");
}
