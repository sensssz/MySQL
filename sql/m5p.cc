#include "my_global.h"
#include "m5p.h"
#include "trace_tool.h"

double
new_order_estimate(work_wait &parameters){
  double actual_remaining =

      0.1617 * parameters.work_so_far +
     -0.1655 * parameters.wait_so_far +
-5109802.3424 * parameters.num_locks_so_far +
-6154094.8557 * parameters.num_of_wait_locks +
 242866.7793 * parameters.total_wait_locks +
      1.0102 * parameters.mean_work_of_all +
     -0.7226 * parameters.mean_wait_of_all +
-69377046.0642 * parameters.cpu_usage +
     -0.3515 * parameters.avg_wait_of_same_past_second +
      0.2386 * parameters.avg_latency_of_all_past_second +
      0.1462 * parameters.avg_latency_of_same_past_5_seconds +
      0.2612 * parameters.avg_latency_of_same_last_20 +
     -0.0227 * parameters.max_latency_of_same_last_50 +
150536733.4958;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
payment_estimate(work_wait &parameters){
  double actual_remaining =

     -0.0021 * parameters.wait_so_far +
-621685.2952 * parameters.num_of_wait_locks +
      2.0374 * parameters.total_granted_locks +
      0.1574 * parameters.mean_work_of_all +
     -0.059  * parameters.mean_wait_of_all +
15675713.8239 * parameters.cpu_usage +
     -0.0503 * parameters.avg_work_of_same_past_second +
     -0.0522 * parameters.avg_wait_of_same_past_second +
      0.0491 * parameters.avg_latency_of_all_past_second +
      0.0101 * parameters.avg_latency_of_same_past_5_seconds +
      0.0189 * parameters.avg_latency_of_same_last_20 +
      0.0022 * parameters.max_latency_of_same_last_50 +
-11574333.1067;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
delivery_estimate(work_wait &parameters){
  double actual_remaining =

     -2.6917 * parameters.work_so_far +
     -0.2238 * parameters.wait_so_far +
 411843.4553 * parameters.total_wait_locks +
     15.6567 * parameters.total_granted_locks +
      2.977  * parameters.mean_work_of_all +
     -1.5747 * parameters.mean_wait_of_all +
-367014679.8495 * parameters.cpu_usage +
     -0.1327 * parameters.avg_work_of_same_past_second +
      0.3046 * parameters.avg_wait_of_same_past_second +
      0.1706 * parameters.avg_latency_of_all_past_second +
      0.6655 * parameters.avg_latency_of_same_last_20 +
     -0.0357 * parameters.max_latency_of_same_last_50 +
444412779.9826;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
stock_level_estimate(work_wait &parameters){
  double actual_remaining =

     -0.0397 * parameters.wait_so_far +
-175998.0477 * parameters.num_locks_so_far +
  41112.8724 * parameters.total_wait_locks +
     -0.6204 * parameters.mean_work_of_all +
-95661702.5645 * parameters.cpu_usage +
      0.3562 * parameters.avg_work_of_same_past_second +
     -0.3782 * parameters.avg_wait_of_same_past_second +
      0.0503 * parameters.avg_latency_of_all_past_second +
      0.008  * parameters.max_latency_of_same_last_50 +
133723518.1537;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
tpcc_estimate(work_wait &parameters){
  double actual_remaining =

      0.1447 * parameters.work_so_far +
     -0.1188 * parameters.wait_so_far +
-606732.6597 * parameters.num_locks_so_far +
3170501.5204 * parameters.num_of_wait_locks +
 122721.8063 * parameters.total_wait_locks +
     -0.3126 * parameters.mean_work_of_all +
     -0.1767 * parameters.mean_wait_of_all +
-52020905.9221 * parameters.cpu_usage +
      0.4246 * parameters.avg_work_of_same_past_second +
     -0.3077 * parameters.avg_wait_of_same_past_second +
      0.0299 * parameters.avg_latency_of_all_past_second +
      0.2047 * parameters.avg_latency_of_same_past_5_seconds +
      0.1804 * parameters.avg_latency_of_same_last_20 +
     -0.0126 * parameters.max_latency_of_same_last_50 +
86295186.3728;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
