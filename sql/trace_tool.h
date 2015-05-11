#ifndef MY_TRACE_TOOL_H
#define MY_TRACE_TOOL_H

#include "../storage/innobase/include/os0sync.h"
#include "../storage/innobase/include/lock0types.h"
#include <fstream>
#include <deque>
#include <vector>
#include <pthread.h>
#include <time.h>
#include <unordered_map>
#include <cstdlib>

#define TRACE_S_E(function_call, index) (TRACE_START()|(function_call)|TRACE_END(index))

typedef unsigned long int ulint;

using std::ofstream;
using std::deque;
using std::vector;
using std::endl;
using std::unordered_map;

extern long transaction_id;
void TRACE_FUNCTION_START();
void TRACE_FUNCTION_END();
bool TRACE_START();
bool TRACE_END(int index);

struct lock_time_info
{
    ulint work_time_so_far;
    ulint wait_time_so_far;
    ulint &total_work_time;
    
    lock_time_info(ulint work_time, ulint wait_time, ulint &total):
    work_time_so_far(work_time), wait_time_so_far(wait_time),
    total_work_time(total)
    {}
};

typedef struct lock_time_info lock_time_info;

class TraceTool
{
private:
    static TraceTool *instance;
    static pthread_mutex_t instance_mutex;
    
    static __thread long current_transaction_id;
    static __thread timespec last_query;
    
    static timespec start_time;
    static timespec global_last_query;
    static pthread_mutex_t last_query_mutex;
    static pthread_mutex_t record_lock_mutex;
    static pthread_mutex_t average_mutex;
    static long commited_trans;
    
    static vector<lock_time_info> lock_time_infos;
    static os_ib_mutex_t lock_time_mutex;
    
    static __thread timespec function_start;
    static __thread timespec function_end;
    static __thread timespec call_start;
    static __thread timespec call_end;
    static __thread bool new_transaction;
    
    ofstream log_file;
    static pthread_rwlock_t data_lock;
    vector<vector<ulint> > function_times;
    vector<ulint> transaction_start_times;
    unordered_map<lock_info, record_lock *> record_lock_map;
    
    TraceTool();
    TraceTool(TraceTool const&){};
public:
    static long total_release_time;
    static long have_choice_time;
    static long needs_to_grant;
    static double average_latency;
    static double average_work_time;
    static ulint num_of_deadlocks;
    static __thread int path_count;
    static __thread bool is_commit;
    static __thread bool commit_successful;
    static __thread bool do_monitor;
    
    static long get_current_transaction_id()
    {
        return current_transaction_id;
    }
    static void start_release()
    {
        srand(ut_time());
        int random = rand() % 100;
        do_monitor = random < 50;
    }
    static TraceTool *get_instance();
    static bool should_monitor();
    static long difftime(timespec start, timespec end);
    static void *check_write_log(void *);
    static timespec get_time();
    
    record_lock *find_record_lock(lock_info *lock_info);
    void start_waiting(lock_info *lock_info, lock_request *request);
    void end_waiting(lock_request *request);
    ofstream &get_log()
    {
        return log_file;
    }
    void lock_wait_info(ulint work_time, ulint wait_time)
    {
        os_mutex_enter(lock_time_mutex);
        lock_time_info info(work_time, wait_time,
                            function_times[current_transaction_id][0]);
        lock_time_infos.push_back(info);
        os_mutex_exit(lock_time_mutex);
    }
    void start_new_query();
    void end_query();
    void end_transaction();
    void write_log();
    void add_record(int function_index, long duration);
};

#endif
