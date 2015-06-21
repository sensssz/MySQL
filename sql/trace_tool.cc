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

#define NUM_CORES 2
#define TARGET_PATH_COUNT 14
#define NUMBER_OF_FUNCTIONS 0
#define LATENCY

#define NEW_ORDER_MARKER "SELECT C_DISCOUNT, C_LAST, C_CREDIT, W_TAX  FROM CUSTOMER, WAREHOUSE WHERE"
#define PAYMENT_MARKER "UPDATE WAREHOUSE SET W_YTD = W_YTD"
#define ORDER_STATUS_MARKER "SELECT C_FIRST, C_MIDDLE"
#define DELIVERY_MARKER "SELECT NO_O_ID FROM NEW_ORDER WHERE NO_D_ID ="
#define STOCK_LEVEL_MARKER "SELECT D_NEXT_O_ID FROM DISTRICT WHERE D_W_ID ="

#define WRITE1_MARKER "UPDATE Snape SET NAME='Marvin' WHERE ID = 1"
#define WRITE2_MARKER "UPDATE Snape SET NAME='Severus' WHERE ID = 1"
#define READ1_MARKER "SELECT AGE FROM Snape WHERE ID = 1"
#define READ2_MARKER "SELECT NAME FROM Snape WHERE ID = 1"

#define EQUAL(struct1, struct2, field) (struct1->field == struct2->field)

using std::endl;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::stringstream;
using std::sort;
using std::getline;

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

__thread vector<ulint> TraceTool::inclusive_times_so_far;
__thread vector<ulint> TraceTool::exclusive_times_so_far;
vector<ulint> TraceTool::inclusive_remainings;
vector<ulint> TraceTool::exclusive_remainings;
pthread_mutex_t TraceTool::remaining_mutex = PTHREAD_MUTEX_INITIALIZER;

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
#if defined(MONITOR) || defined(WORK_WAIT)
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
  inclusive_times_so_far.reserve(50);
  inclusive_times_so_far.reserve(50);
  
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
    
    pthread_rwlock_rdlock(&data_lock);
    transaction_types[current_transaction_id] = type;
    pthread_rwlock_unlock(&data_lock);
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
#endif
  pthread_mutex_lock(&remaining_mutex);
  inclusive_remainings.insert(inclusive_remainings.end(), inclusive_times_so_far.begin(), inclusive_times_so_far.end());
  exclusive_remainings.insert(exclusive_remainings.end(), exclusive_times_so_far.begin(), exclusive_times_so_far.end());
  pthread_mutex_unlock(&remaining_mutex);
  inclusive_times_so_far.clear();
  exclusive_times_so_far.clear();
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

void TraceTool::add_estimate_record(ulint time_so_far, bool inclusive)
{
  if (inclusive)
  {
    inclusive_times_so_far.push_back(time_so_far);
  }
  else
  {
    exclusive_times_so_far.push_back(time_so_far);
  }
}

static ulint TraceTool::estimate(bool inclusive)
{
  if (inclusive &&
      inclusive_remainings.size() > 0)
  {
    int index = rand() % inclusive_remainings.size();
    return inclusive_remainings[index];
  }
  else if (!inclusive &&
           exclusive_remainings.size() > 0)
  {
    int index = rand() % exclusive_remainings.size();
    return exclusive_remainings[index];
  }
  return 0;
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

void TraceTool::write_log()
{
  write_latency("latency/original/");
}