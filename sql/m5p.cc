#include "my_global.h"
#include "m5p.h"
#include "trace_tool.h"

double
new_order_estimate(work_wait &parameters){
  double actual_remaining =

      0.228  * parameters.work_so_far +
     -0.2029 * parameters.wait_so_far +
-7624759.0437 * parameters.num_locks_so_far +
-21471915.6666 * parameters.num_of_wait_locks +
 314323.8183 * parameters.total_wait_locks +
     31.4526 * parameters.total_granted_locks +
      4.4094 * parameters.mean_work_of_all +
     -3.112  * parameters.mean_wait_of_all +
204929514.9779 * parameters.cpu_usage +
     -0.0633 * parameters.avg_work_of_same_past_second +
      0.0463 * parameters.avg_wait_of_same_past_second +
      0.0537 * parameters.avg_latency_of_all_past_second +
      0.1036 * parameters.avg_latency_of_same_past_5_seconds +
      0.3259 * parameters.avg_latency_of_same_last_20 +
     -0.0284 * parameters.max_latency_of_same_last_50 +
-118129507.8763;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
payment_estimate(work_wait &parameters){
  double actual_remaining =

      0.0631 * parameters.work_so_far +
     -0.0063 * parameters.wait_so_far +
1822979.0028 * parameters.num_of_wait_locks +
 -97639.8361 * parameters.total_wait_locks +
     17.663  * parameters.total_granted_locks +
      0.2263 * parameters.mean_work_of_all +
      0.1086 * parameters.mean_wait_of_all +
18314016.3889 * parameters.cpu_usage +
      0.0661 * parameters.avg_wait_of_same_past_second +
     -0.0617 * parameters.avg_latency_of_all_past_second +
      0.0197 * parameters.avg_latency_of_same_last_20 +
-24764634.1091;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
delivery_estimate(work_wait &parameters){
  double actual_remaining =

      0.2737 * parameters.work_so_far +
     -0.2231 * parameters.wait_so_far +
 515195.6798 * parameters.total_wait_locks +
      1.4691 * parameters.mean_work_of_all +
      0.6083 * parameters.mean_wait_of_all +
     -0.0186 * parameters.avg_work_of_same_past_second +
-53944068.8089;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
stock_level_estimate(work_wait &parameters){
  double actual_remaining =

-242872.6761 * parameters.total_wait_locks +
     62.9083 * parameters.total_granted_locks +
     -1.8688 * parameters.avg_work_of_same_past_second +
     -0.6479 * parameters.avg_wait_of_same_past_second +
      0.1848 * parameters.avg_latency_of_same_last_20 +
      0.0428 * parameters.max_latency_of_same_last_50 +
-51148204.8682;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
tpcc_estimate(work_wait &parameters){
  double actual_remaining =

      0.1187 * parameters.work_so_far +
     -0.0869 * parameters.wait_so_far +
-7969379.3652 * parameters.num_of_wait_locks +
  89865.8285 * parameters.total_wait_locks +
     15.2653 * parameters.total_granted_locks +
      1.1224 * parameters.mean_work_of_all +
     -0.8585 * parameters.mean_wait_of_all +
101108874.6407 * parameters.cpu_usage +
      0.4683 * parameters.avg_work_of_same_past_second +
      0.1885 * parameters.avg_wait_of_same_past_second +
     -0.2834 * parameters.avg_latency_of_all_past_second +
      0.1108 * parameters.avg_latency_of_same_past_5_seconds +
      0.1437 * parameters.avg_latency_of_same_last_20 +
     -0.0109 * parameters.max_latency_of_same_last_50 +
      0      * parameters.prediction +
-104372232.6109;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
