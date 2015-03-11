#ifndef MY_TRACE_TOOL_H
#define MY_TRACE_TOOL_H

#include <fstream>
#include <deque>
#include <vector>
#include <pthread.h>
#include <time.h>

#define TRACE_S_E(function_call, index) (TRACE_START()|(function_call)|TRACE_END(index))

using std::ofstream;
using std::deque;
using std::vector;
using std::endl;

extern long transaction_id;
void TRACE_FUNCTION_START();
void TRACE_FUNCTION_END();
bool TRACE_START();
bool TRACE_END(int index);

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
    
    static __thread timespec function_start;
    static __thread timespec function_end;
    static __thread timespec call_start;
    static __thread timespec call_end;
    static __thread bool new_transaction;
    
    ofstream log_file;
    static pthread_rwlock_t data_lock;
    vector<vector<long> > function_times;
    vector<long> transaction_start_times;
    
    TraceTool();
    TraceTool(TraceTool const&){};
public:
    static __thread int path_count;
    static __thread bool is_commit;
    static __thread bool commit_successful;
    
    static long get_current_transaction_id()
    {
        return current_transaction_id;
    }
    static TraceTool *get_instance();
    static bool should_monitor();
    static long difftime(timespec start, timespec end);
    static void *check_write_log(void *);
    static timespec get_time();
    
    ofstream &get_log()
    {
        return log_file;
    }
    void start_new_query();
    void end_query();
    void end_transaction();
    void write_log();
    void add_record(int function_index, long duration);
};

#endif
