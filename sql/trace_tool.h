#ifndef MY_TRACE_TOOL_H
#define MY_TRACE_TOOL_H

#include "../storage/innobase/include/os0sync.h"
#include "../storage/innobase/include/lock0types.h"
#include <fstream>
#include <list>
#include <vector>
#include <pthread.h>
#include <time.h>
#include <unordered_map>
#include <cstdlib>
#include <string>

/** This macro is used for tracing the running time of
    a function call which appears inside an if statement*/
#define TRACE_S_E(function_call, index) (TRACE_START()|(function_call)|TRACE_END(index))

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

/********************************************************************//**
Infomration about work time so far and wait time so far. */
struct lock_time_info
{
    ulint transaction_id;     /*!< Transaction ID in our own system. */
    ulint trx_id;             /*!< Transaction ID in InnoDB. */
    ulint work_time_so_far;   /*!< Work time so far when a lock is granted */
    ulint wait_time_so_far;   /*!< Wait time so far when a lock is granted */
    uint num_of_locks_so_far; /*!< Number of locks a transaction hold when a lock is granted */
    
    lock_time_info(ulint trans_id, ulint tid, ulint work_time, ulint wait_time, uint locks):
    transaction_id(trans_id), trx_id(tid), work_time_so_far(work_time),
    wait_time_so_far(wait_time), num_of_locks_so_far(locks)
    {}
};
typedef struct lock_time_info lock_time_info;

class TraceTool
{
private:
    static TraceTool *instance;             /*!< Instance for the Singleton pattern. */
    static pthread_mutex_t instance_mutex;  /*!< Mutex for protecting instance. */
    
    static timespec global_last_query;      /*!< Time when MySQL receives the most recent query. */
    static pthread_mutex_t last_query_mutex;/*!< Mutex for protecting global_last_query */
    
    static pthread_mutex_t record_lock_mutex;/*!< Mutex for protecting record_lock_map. */
    static pthread_mutex_t average_mutex;   /*!< Mutex for protecting average_latency. */
    static ulint commited_trans;            /*!< Number of committed transactions. */
    
    static __thread timespec function_start;/*!< Time for the start of a function call. */
    static __thread timespec function_end;  /*!< Time for the end of a function call. */
    static __thread timespec call_start;    /*!< Time for the start of a child function call. */
    static __thread timespec call_end;      /*!< Time for the end of a child function call. */
    static __thread bool new_transaction;   /*!< True if we need to start a new transaction. */
    static __thread timespec trans_start;   /*!< Start time of the current transaction. */
    
    
    ofstream log_file;                      /*!< An log file for outputing debug messages. */
    static pthread_rwlock_t data_lock;      /*!< A read-write lock for protecting function_times. */
    vector<vector<ulint> > function_times;  /*!< Stores the running time of the child functions
                                                 and also transaction latency (the last one). */
    vector<ulint> transaction_start_times;  /*!< Stores the start time of transactions. */
    vector<transaction_type> transaction_types;/*!< Stores the transaction types of transactions. */
    unordered_map<lock_info, record_lock *> record_lock_map; /*!< Stores information for record locks
                                                                  See definitions of lock_info and
                                                                  record_lock. */
    
    list<lock_time_info> lock_time_infos;   /*!< Stores information about locks. */
    static pthread_mutex_t lock_time_mutex; /*!< Mutex for protecting lock_time_infos. */
    
    TraceTool();
    TraceTool(TraceTool const&){};
public:
    static __thread ulint current_transaction_id;   /*!< Each thread can execute only one transaction at
                                                         a time. This is the ID of the current transactions. */
    static ulint num_of_deadlocks;          /*!< Number of deadlocks. */
    
    static __thread int path_count;         /*!< Number of node in the function call path. Used for
                                                 tracing running time of functions. */
    
    static __thread bool is_commit;         /*!< True if the current transactions commits. */
    static __thread bool query_is_commit;   /*!< True if the current query is a commit query (Note that
                                                 these two doesn't have to be true at the same time). */
    static __thread bool commit_successful; /*!< True if the current transaction successfully commits. */
    static __thread transaction_type type;  /*!< Type of the current transaction. */
    
    static double average_latency;  /*!< Average latency of all transactions so far. */
    static ulint num_of_trans;      /*!< Number of transactions so far. */
    static ulint num_of_rollback;   /*!< Number of transactions that roll back so far. */
    
    /********************************************************************//**
    The Singleton pattern. Used for getting the instance of this class. */
    static TraceTool *get_instance();
    
    /********************************************************************//**
    Check if we should trace the running time of function calls. */
    static bool should_monitor();
    
    /********************************************************************//**
    Calcualte time interval in nanoseconds. */
    static ulint difftime(timespec start, timespec end);
    
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
    Marks the start of a lock waiting. Used for measuring lock information. */
    void start_waiting(lock_info *lock_info, lock_request *request);
    /********************************************************************//**
    Marks the end of a lock waiting. */
    void end_waiting(lock_request *request);
    
    /********************************************************************//**
    Retruns the log file for outputing debug information. */
    ofstream &get_log()
    {
        return log_file;
    }
    
    /********************************************************************//**
    Add a record about work time and wait time. */
    void lock_wait_info(ulint trans_id, ulint trx_id, ulint work_time,
                        ulint wait_time, uint num_of_locks);
    
    /********************************************************************//**
    Remove invalid record about work time and wait time given a transaction
    ID in InnoDB */
    void remove(ulint trx_id);
    
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
    Dump data about work time and wait time to log file. */
    void write_work_wait();
    /********************************************************************//**
    Dump data about function running time and latency to log file. */
    void write_latency();
    /********************************************************************//**
    Dump data about lock wait information to log file. */
    void write_lock_wait();
    /********************************************************************//**
    Write necessary data to log files. */
    void write_log();
    
    /********************************************************************//**
    Record running time of a function. */
    void add_record(int function_index, long duration);
    /********************************************************************//**
    Record running time of a function if it's zero. */
    void add_record_if_zero(int function_index, long duration);
};

#endif
