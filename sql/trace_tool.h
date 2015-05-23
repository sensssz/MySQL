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

#define TRACE_S_E(function_call, index) (TRACE_START()|(function_call)|TRACE_END(index))

typedef unsigned long int ulint;
typedef unsigned int uint;

using std::ofstream;
using std::list;
using std::vector;
using std::endl;
using std::unordered_map;
using std::string;

extern ulint transaction_id;
void TRACE_FUNCTION_START();
void TRACE_FUNCTION_END();
bool TRACE_START();
bool TRACE_END(int index);

enum transaction_type
{
    NEW_ORDER, PAYMENT, ORDER_STATUS, DELIVERY, STOCK_LEVEL, NONE
};

typedef enum transaction_type transaction_type;

struct lock_time_info
{
    ulint transaction_id;
    ulint trx_id;
    ulint work_time_so_far;
    ulint wait_time_so_far;
    uint num_of_locks_so_far;
    
    lock_time_info(ulint trans_id, ulint tid, ulint work_time, ulint wait_time, uint locks):
    transaction_id(trans_id), trx_id(tid), work_time_so_far(work_time),
    wait_time_so_far(wait_time), num_of_locks_so_far(locks)
    {}
};

typedef struct lock_time_info lock_time_info;

class TraceTool
{
private:
    static TraceTool *instance;
    static pthread_mutex_t instance_mutex;
    
    static __thread timespec last_query;
    
    static timespec start_time;
    static timespec global_last_query;
    static pthread_mutex_t last_query_mutex;
    static pthread_mutex_t record_lock_mutex;
    static pthread_mutex_t average_mutex;
    static ulint commited_trans;
    
    static __thread timespec function_start;
    static __thread timespec function_end;
    static __thread timespec call_start;
    static __thread timespec call_end;
    static __thread bool new_transaction;
    static __thread timespec trans_start;
    
    ofstream log_file;
    static pthread_rwlock_t data_lock;
    vector<vector<ulint> > function_times;
    vector<ulint> transaction_start_times;
    vector<transaction_type> transaction_types;
    unordered_map<lock_info, record_lock *> record_lock_map;
    
    list<lock_time_info> lock_time_infos;
    os_ib_mutex_t lock_time_mutex;
    
    TraceTool();
    TraceTool(TraceTool const&){};
public:
    static __thread ulint current_transaction_id;
    static ulint num_of_deadlocks;
    static __thread int path_count;
    static __thread bool is_commit;
    static __thread bool query_is_commit;
    static __thread bool commit_successful;
    static __thread char *query;
    static __thread transaction_type type;
    static double average_latency;
    static ulint num_of_trans;
    static ulint num_of_rollback;
    
    static TraceTool *get_instance();
    static bool should_monitor();
    static ulint difftime(timespec start, timespec end);
    static void *check_write_log(void *);
    static timespec get_time();
    static ulint now_micro();
    
    void start_waiting(lock_info *lock_info, lock_request *request);
    void end_waiting(lock_request *request);
    ofstream &get_log()
    {
        return log_file;
    }
    void lock_wait_info(ulint trans_id, ulint trx_id, ulint work_time,
                        ulint wait_time, uint num_of_locks);
    void remove(ulint trx_id);
    void start_new_query();
    void set_query(const char *query);
    void print_query();
    void end_query();
    void end_transaction();
    void write_work_wait();
    void write_latency();
    void write_lock_wait();
    void write_log();
    void add_record(int function_index, long duration);
    void add_record_if_zero(int function_index, long duration);
};

#endif
