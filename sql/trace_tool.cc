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
#define MONITOR

#define NEW_ORDER_MARKER "SELECT C_DISCOUNT, C_LAST, C_CREDIT, W_TAX  FROM CUSTOMER, WAREHOUSE WHERE"
#define PAYMENT_MARKER "UPDATE WAREHOUSE SET W_YTD = W_YTD"
#define ORDER_STATUS_MARKER "SELECT C_FIRST, C_MIDDLE"
#define DELIVERY_MARKER "SELECT NO_O_ID FROM NEW_ORDER WHERE NO_D_ID ="
#define STOCK_LEVEL_MARKER "SELECT D_NEXT_O_ID FROM DISTRICT WHERE D_W_ID ="

#define WRITER_MARKER "UPDATE Snape SET NAME='Marvin' WHERE ID = 1"
#define READ_MARKER "SELECT AGE FROM Snape WHERE ID = 1"

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

ulint TraceTool::num_trans = 0;
double TraceTool::mean_latency = 0;
double TraceTool::var_latency = 0;
double TraceTool::mean_work = 0;
double TraceTool::mean_wait = 0;
ulint TraceTool::total_wait_locks = 0;
ulint TraceTool::total_granted_locks= 0;
double TraceTool::cpu_usage = 0;
pthread_mutex_t TraceTool::var_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t TraceTool::estimate_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t TraceTool::work_wait_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t TraceTool::last_second_mutex = PTHREAD_MUTEX_INITIALIZER;

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
  previous_user = 0;
  previous_nice = 0;
  previous_system = 0;
  previous_idle = 0;
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
  times_so_far.reserve(500000);
  estimated_remainings.reserve(500000);
  transaction_ids.reserve(500000);
  work_waits.reserve(5000000);
  
  srand(time(0));
}

bool TraceTool::should_monitor()
{
  return path_count == TARGET_PATH_COUNT;
}

double TraceTool::get_cpu_usage()
{
  ulint total_user = 0;
  ulint total_nice = 0;
  ulint total_system = 0;
  ulint total_idle = 0;
  ulint per_core_user = 0;
  ulint per_core_nice = 0;
  ulint per_core_system = 0;
  ulint per_core_idle = 0;
  double usage = 0;
  ifstream stat("/proc/stat");
  string garbage;
  getline(stat, garbage);
  for (ulint index = 0; index < NUM_CORES; ++index)
  {
    stat >> garbage >> per_core_user >> per_core_nice >> per_core_system >> per_core_idle;
    getline(stat, garbage);
    total_user += per_core_user;
    total_nice += per_core_nice;
    total_system += per_core_system;
    total_idle += per_core_idle;
  }
  stat.close();
  
  if (previous_user > 0)
  {
    ulint user_delta = total_user - previous_user;
    ulint nice_delta = total_nice - previous_nice;
    ulint system_delta = total_system - previous_system;
    ulint idle_delta = total_idle - previous_idle;
    double sum = user_delta + nice_delta + system_delta + idle_delta;
    usage = (sum - idle_delta) / sum;
  }
  
  previous_user = total_user;
  previous_nice = total_nice;
  previous_system = total_system;
  previous_idle = total_idle;
  
  return usage;
}

void *TraceTool::check_write_log(void *arg)
{
  /* Runs in an infinite loop and for every 5 seconds,
     check if there's any query comes in. If not, then
     dump data to log files. */
  while (true)
  {
    sleep(1);
#ifdef WORK_WAIT
    cpu_usage = instance->get_cpu_usage();
#endif
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
      mean_work = 0;
      mean_wait = 0;
      total_wait_locks = 0;
      total_granted_locks= 0;
      cpu_usage = 0;
      
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
  
#ifdef WORK_WAIT
  ulint wait_time = function_times[0][current_transaction_id];
  ulint work_time = latency - wait_time;
  mean_work = mean_work + (work_time - mean_work) / num_trans;
  mean_wait = mean_wait + (wait_time - mean_wait) / num_trans;
#endif
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
    pthread_mutex_lock(&last_second_mutex);
    ulint now_in_micro = now_micro();
    last_second_commit_times.push_back(now_micro());
    last_second_transaction_ids.push_back(current_transaction_id);
    while (last_second_commit_times.size() > 0 &&
           now_in_micro - last_second_commit_times[0] > 2000000)
    {
      last_second_commit_times.pop_front();
      last_second_transaction_ids.pop_front();
    }
    pthread_mutex_unlock(&last_second_mutex);
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

void TraceTool::add_work_wait(ulint work_so_far, ulint wait_so_far, ulint num_locks,
                              ulint num_of_wait_locks, ulint time_so_far, ulint transaction_id)
{
  work_wait record;
  record.work_so_far = work_so_far;
  record.wait_so_far = wait_so_far;
  record.num_locks_so_far = num_locks;
  record.num_of_wait_locks = num_of_wait_locks;
  record.total_wait_locks = total_wait_locks;
  record.total_granted_locks = total_granted_locks;
  record.mean_work = mean_work;
  record.mean_wait = mean_wait;
  record.cpu_usage = cpu_usage;
  record.avg_latency_last_second = 0;
  record.time_so_far = time_so_far;
  record.transaction_id = transaction_id;
  
  transaction_type type = transaction_types[transaction_id];
  ulint num_of_trx = 0;
  double sum_latency = 0;
  
  pthread_mutex_lock(&last_second_mutex);
  for (ulint index = 0, size = last_second_commit_times.size();
       index < size; ++index)
  {
    ulint trx_id = last_second_transaction_ids[index];
    if (type == transaction_types[trx_id])
    {
      sum_latency += function_times.back()[trx_id];
      ++num_of_trx;
    }
  }
  pthread_mutex_unlock(&last_second_mutex);
  if (num_of_trx > 0)
  {
    record.avg_latency_last_second = sum_latency / num_of_trx;
  }
  
  pthread_mutex_lock(&work_wait_mutex);
  work_waits.push_back(record);
  pthread_mutex_unlock(&work_wait_mutex);
}

void TraceTool::add_estimate_record(ulint time_so_far, ulint estimated_remaining, ulint transasction_id)
{
  pthread_mutex_lock(&estimate_mutex);
  times_so_far.push_back(time_so_far);
  estimated_remainings.push_back(estimated_remaining);
  transaction_ids.push_back(transaction_id);
  pthread_mutex_unlock(&estimate_mutex);
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

void TraceTool::write_isotonic_accuracy()
{
  ofstream new_order_accuracy("accuracy/new_order");
  ofstream payment_accuracy("accuracy/payment");
  ofstream order_status_accuracy("accuracy/order_status");
  ofstream delivery_accuracy("accuracy/delivery");
  ofstream stock_level_accuracy("accuracy/stock_level");
  for (ulint index = 0, size = estimated_remainings.size(); index < size; ++index)
  {
    ulint transaction_id = transaction_ids[index];
    ulint time_so_far = times_so_far[index];
    ulint estimated_remaining = estimated_remainings[index];
    
    transaction_type type = transaction_types[transaction_id];
    ulint latency = function_times.back()[transaction_id];
    
    if (latency < time_so_far)
    {
      continue;
    }
    
    ulint actual_remaining = latency - time_so_far;
    
    if (transaction_start_times[index])
    {
      switch (type)
      {
        case NEW_ORDER:
          new_order_accuracy << estimated_remaining << ',' << actual_remaining << endl;
          break;
        case PAYMENT:
          payment_accuracy << estimated_remaining << ',' << actual_remaining << endl;
          break;
        case ORDER_STATUS:
          order_status_accuracy << estimated_remaining << ',' << actual_remaining << endl;
          break;
        case DELIVERY:
          delivery_accuracy << estimated_remaining << ',' << actual_remaining << endl;
          break;
        case STOCK_LEVEL:
          stock_level_accuracy << estimated_remaining << ',' << actual_remaining << endl;
          break;
        default:
          break;
      }
    }
  }
  estimated_remainings.clear();
  transaction_ids.clear();
  new_order_accuracy.close();
  payment_accuracy.close();
  order_status_accuracy.close();
  delivery_accuracy.close();
  stock_level_accuracy.close();
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
      ulint actual_remaining = latency - record.time_so_far;
      ut_a(latency > total_wait);
      ut_a(total_wait > record.wait_so_far);
      ut_a(total_work > record.work_so_far);
      
      stringstream line;
      
      line << actual_remaining << "," << type + 1 << "," << record.work_so_far
           << "," << record.wait_so_far << "," << record.num_locks_so_far
           << "," << record.num_of_wait_locks << "," << record.total_wait_locks
           << "," << record.total_granted_locks << "," << record.mean_work
           << "," << record.mean_wait << "," << record.cpu_usage
           << "," << record.avg_latency_last_second << endl;
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
#ifdef WORK_WAIT
  write_isotonic_accuracy();
  write_work_wait();
#endif
  write_latency("latency/original/");
}
