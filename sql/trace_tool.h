#ifndef MY_TRACE_TOOL_H
#define MY_TRACE_TOOL_H

#include "../storage/innobase/include/os0sync.h"
#include "../storage/innobase/include/lock0types.h"
#include <fstream>
#include <list>
#include <vector>
#include <deque>
#include <pthread.h>
#include <time.h>
#include <unordered_map>
#include <cstdlib>
#include <string>

/** This macro is used for tracing the running time of
    a function call which appears inside an if statement*/
#define TRACE_S_E(function_call, index) (TRACE_START()|(function_call)|TRACE_END(index))

#define var_mutex_enter() pthread_mutex_lock(&TraceTool::var_mutex)
#define var_mutex_exit() pthread_mutex_unlock(&TraceTool::var_mutex)
#define estimate_mutex_enter() pthread_mutex_lock(&TraceTool::last_second_mutex); pthread_rwlock_rdlock(&TraceTool::data_lock);
#define estimate_mutex_exit() pthread_mutex_unlock(&TraceTool::last_second_mutex); pthread_rwlock_unlock(&TraceTool::data_lock)

typedef unsigned long int ulint;
typedef unsigned int uint;

using std::ofstream;
using std::list;
using std::vector;
using std::endl;
using std::unordered_map;
using std::string;

/** The global transaction id counter */
extern ulint transaction_id;

/********************************************************************//**
To break down the variance of a function, we need to trace the running
time of a function and the functions it calls. */

/********************************************************************//**
This function marks the start of a function call */
void TRACE_FUNCTION_START();

/********************************************************************//**
This function marks the end of a function call */
void TRACE_FUNCTION_END();

/********************************************************************//**
This function marks the start of a child function call. */
bool TRACE_START();

/********************************************************************//**
This function marks the end of a child function call. */
bool TRACE_END(
  int index);   /*!< Index of the child function call. */

/********************************************************************//**
Transaction types in TPCC workload. */
enum transaction_type
{
    NEW_ORDER, PAYMENT, ORDER_STATUS, DELIVERY, STOCK_LEVEL, NONE
};
typedef enum transaction_type transaction_type;

typedef struct work_wait
{
    ulint work_so_far;
    ulint wait_so_far;
    ulint num_locks_so_far;
    ulint num_of_wait_locks;
    ulint total_wait_locks;
    ulint total_granted_locks;
    double mean_work_of_all;
    double mean_wait_of_all;
    double cpu_usage;
    double avg_latency_of_same_past_second;
    double avg_work_of_same_past_second;
    double avg_wait_of_same_past_second;
    double avg_latency_of_all_past_second;
    double avg_latency_of_same_past_5_seconds;
    double avg_latency_of_same_last_20;
    double max_latency_of_same_last_50;
    double avg_latency_of_trx_hold_locks;
    ulint time_so_far;
    ulint prediction;
    ulint transaction_id;
} work_wait;

class TraceTool
{
private:
    static TraceTool *instance;             /*!< Instance for the Singleton pattern. */
    static pthread_mutex_t instance_mutex;  /*!< Mutex for protecting instance. */
    
    static timespec global_last_query;      /*!< Time when MySQL receives the most recent query. */
    static pthread_mutex_t last_query_mutex;/*!< Mutex for protecting global_last_query */
    
    static __thread timespec function_start;/*!< Time for the start of a function call. */
    static __thread timespec function_end;  /*!< Time for the end of a function call. */
    static __thread timespec call_start;    /*!< Time for the start of a child function call. */
    static __thread timespec call_end;      /*!< Time for the end of a child function call. */
    static __thread bool new_transaction;   /*!< True if we need to start a new transaction. */
    static __thread timespec trans_start;   /*!< Start time of the current transaction. */
    
    ofstream log_file;                      /*!< An log file for outputing debug messages. */
    
    vector<vector<ulint> > function_times;  /*!< Stores the running time of the child functions
                                                 and also transaction latency (the last one). */
    vector<ulint> transaction_start_times;  /*!< Stores the start time of transactions. */
    vector<transaction_type> transaction_types;/*!< Stores the transaction types of transactions. */
    
    vector<ulint> times_so_far;             /*!< Time so far when a lock is granted. */
    vector<ulint> estimated_remainings;     /*!< Estimated latency of an isotonic model. */
    vector<ulint> transaction_ids;          /*!< Corresponding transaction ID for time so far. */
    static pthread_mutex_t estimate_mutex;
    
    vector<ulint> last_second_commit_times;  /*!< Stores the commit time of transactions. */
    vector<ulint> last_second_transaction_ids;
    
    vector<work_wait> work_waits;
    static pthread_mutex_t work_wait_mutex;
    
    ulint previous_user;
    ulint previous_nice;
    ulint previous_system;
    ulint previous_idle;
    ulint previous_total;
    
    TraceTool();
    TraceTool(TraceTool const&){};
public:
    static pthread_rwlock_t data_lock;      /*!< A read-write lock for protecting function_times. */
    static __thread ulint current_transaction_id;   /*!< Each thread can execute only one transaction at
                                                         a time. This is the ID of the current transactions. */
    
    static __thread int path_count;         /*!< Number of node in the function call path. Used for
                                                 tracing running time of functions. */
    
    static __thread bool is_commit;         /*!< True if the current transactions commits. */
    static __thread bool query_is_commit;   /*!< True if the current query is a commit query (Note that
                                                 these two doesn't have to be true at the same time). */
    static __thread bool commit_successful; /*!< True if the current transaction successfully commits. */
    static __thread transaction_type type;  /*!< Type of the current transaction. */
    static ulint num_trans;                 /*!< Number of successfully submitted transactions. */
    static double mean_latency;             /*!< Mean of total wait time of successfully committed
                                             transactions*/
    static double mean_work_of_all;
    static double mean_wait_of_all;
    static ulint total_wait_locks;
    static ulint total_granted_locks;
    static ulint max_num_locks;
    static pthread_mutex_t var_mutex;
    static pthread_mutex_t last_second_mutex;
    
    static double cpu_usage;
    
    /********************************************************************//**
    The Singleton pattern. Used for getting the instance of this class. */
    static TraceTool *get_instance();
    
    /********************************************************************//**
    Check if we should trace the running time of function calls. */
    static bool should_monitor();
    
    /********************************************************************//**
    Calcualte time interval in nanoseconds. */
    static ulint difftime(timespec start, timespec end);
    
    double get_cpu_usage();
    
    /********************************************************************//**
    Periododically checks if any query comes in in the last 5 second.
    If no then dump all logs to disk. */
    static void *check_write_log(void *);
    
    /********************************************************************//**
    Get the current time in nanosecond. */
    static timespec get_time();
    /********************************************************************//**
    Get the current tiem in microsecond. */
    static ulint now_micro();
    
    /********************************************************************//**
    Retruns the log file for outputing debug information. */
    ofstream &get_log()
    {
        return log_file;
    }

    /********************************************************************//**
    Sumbits the total wait time of a transaction. */
    void update_ctv(ulint latency);
    
    /********************************************************************//**
    Start a new query. This may also start a new transaction. */
    void start_new_query();
    /********************************************************************//**
    End a new query. This may also end the current transaction. */
    void end_query();
    /********************************************************************//**
    End the current transaction. */
    void end_transaction();
    
    /********************************************************************//**
    Analysis the current query to find out the transaction type. */
    void set_query(const char *query);
    
    /********************************************************************//**
    Add a record about work time and wait time. */
    ulint *add_work_wait(ulint work_so_far, ulint wait_so_far, ulint num_locks,
                       ulint num_of_wait_locks, ulint prediction, ulint transaction_id);
    
    work_wait parameters(ulint work_so_far, ulint wait_so_far, ulint num_locks,
                       ulint num_of_wait_locks, ulint transaction_id);

    /********************************************************************//**
    Add a record about estimating latency using isotonic models. */
    void add_estimate_record(ulint time_so_far, ulint estimated_remaining, ulint transasction_id);
    
    /********************************************************************//**
    Dump data about work time and wait time to log file. */
    void write_work_wait();
    /********************************************************************//**
    Dump data about function running time and latency to log file. */
    void write_isotonic_accuracy();
    /********************************************************************//**
    Dump data about function running time and latency to log file. */
    void write_latency(string dir);
    /********************************************************************//**
    Write necessary data to log files. */
    void write_log();
    
    /********************************************************************//**
    Record running time of a function. */
    void add_record(int function_index, long duration);
};

#endif
