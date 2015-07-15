#include "my_global.h"
#include "trace_tool.h"

double
new_order_estimate(work_wait &parameters){
  double actual_remaining =

      0.7904 * parameters.work_so_far +
10995698.1218 * parameters.number_of_locks_in_current_queue +
 230729.1275 * parameters.total_wait_locks +
     85.3966 * parameters.total_granted_locks +
    -12.8023 * parameters.mean_wait_of_all +
-154753241.6875 * parameters.cpu_usage +
      0.6029 * parameters.avg_work_of_same_past_second +
      0.7756 * parameters.avg_wait_of_same_past_second +
     -0.5936 * parameters.average_latency_of_all_over_past_second +
      0.2135 * parameters.mean_latency_of_trx_of_this_type_over_past_5_seconds +
      0.1067 * parameters.avg_latency_of_same_last_20 +
150965135.2245;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
payment_estimate(work_wait &parameters){
  double actual_remaining =

      0.1705 * parameters.work_so_far +
      0.0971 * parameters.wait_so_far +
24053679.4416 * parameters.number_of_locks_in_current_queue +
  71275.133  * parameters.total_wait_locks +
     38.6859 * parameters.total_granted_locks +
    -10.2111 * parameters.mean_work_of_all +
      1.2664 * parameters.mean_wait_of_all +
      0.2104 * parameters.avg_work_of_same_past_second +
      0.0219 * parameters.avg_wait_of_same_past_second +
     -0.0503 * parameters.average_latency_of_all_over_past_second +
      0.0323 * parameters.avg_latency_of_same_last_20 +
      0.0051 * parameters.max_latency_of_same_last_50 +
-49762002.5187;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
delivery_estimate(work_wait &parameters){
  double actual_remaining =

     18.4866 * parameters.work_so_far +
     -0.1585 * parameters.wait_so_far +
-141628.7027 * parameters.total_wait_locks +
     61.6425 * parameters.total_granted_locks +
      6.5004 * parameters.mean_wait_of_all +
     -0.7847 * parameters.avg_wait_of_same_past_second +
      0.5728 * parameters.average_latency_of_all_over_past_second +
      0.0942 * parameters.max_latency_of_same_last_50 +
117316686.406;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
stock_level_estimate(work_wait &parameters){
  double actual_remaining =

      3.3992 * parameters.avg_work_of_same_past_second +
     -0.2068 * parameters.average_latency_of_all_over_past_second +
-4726914.1893;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
tpcc_estimate(work_wait &parameters){
  double actual_remaining =

      0.4943 * parameters.work_so_far +
      0.0656 * parameters.wait_so_far +
19701264.78 * parameters.number_of_locks_in_current_queue +
 132426.5394 * parameters.total_wait_locks +
     49.4743 * parameters.total_granted_locks +
     -7.9098 * parameters.mean_wait_of_all +
      0.382  * parameters.avg_work_of_same_past_second +
     -0.7035 * parameters.avg_wait_of_same_past_second +
      0.4193 * parameters.average_latency_of_all_over_past_second +
      0.151  * parameters.mean_latency_of_trx_of_this_type_over_past_5_seconds +
      0.0507 * parameters.avg_latency_of_same_last_20 +
      0.0081 * parameters.max_latency_of_same_last_50 +
-47386586.4936;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
