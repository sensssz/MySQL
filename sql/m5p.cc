#include "my_global.h"
#include "m5p.h"
#include "trace_tool.h"

double
new_order_estimate(work_wait &parameters){
  double actual_remaining =

      0.6681 * parameters.work_so_far +
     -0.2153 * parameters.wait_so_far +
-17257442.5912 * parameters.num_of_wait_locks +
 449464.6324 * parameters.total_wait_locks +
      1.9112 * parameters.mean_work_of_all +
     -2.0515 * parameters.mean_wait_of_all +
145423027.4912 * parameters.cpu_usage +
     -0.7109 * parameters.avg_wait_of_same_past_second +
      0.4373 * parameters.avg_latency_of_all_past_second +
      0.2748 * parameters.avg_latency_of_same_past_5_seconds +
      0.2202 * parameters.avg_latency_of_same_last_20 +
-51172072.9587;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
payment_estimate(work_wait &parameters){
  double actual_remaining =

     -0.0065 * parameters.wait_so_far +
1536843.3992 * parameters.num_of_wait_locks +
 -10851.6834 * parameters.total_wait_locks +
      5.0623 * parameters.total_granted_locks +
      0.1454 * parameters.mean_work_of_all +
     -0.087  * parameters.mean_wait_of_all +
      0.1072 * parameters.avg_work_of_same_past_second +
      0.063  * parameters.avg_wait_of_same_past_second +
     -0.0817 * parameters.avg_latency_of_all_past_second +
      0.0243 * parameters.avg_latency_of_same_past_5_seconds +
      0.0259 * parameters.avg_latency_of_same_last_20 +
3777975.9102;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
delivery_estimate(work_wait &parameters){
  double actual_remaining =

 +
10468864;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
stock_level_estimate(work_wait &parameters){
  double actual_remaining =

 +
13162856.625;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
tpcc_estimate(work_wait &parameters){
  double actual_remaining =

      0.298  * parameters.work_so_far +
     -0.0965 * parameters.wait_so_far +
 932390.1032 * parameters.num_locks_so_far +
-6495093.36 * parameters.num_of_wait_locks +
 202623.5043 * parameters.total_wait_locks +
      0.4914 * parameters.mean_work_of_all +
     -0.7789 * parameters.mean_wait_of_all +
71569308.856 * parameters.cpu_usage +
      0.9338 * parameters.avg_work_of_same_past_second +
     -0.1778 * parameters.avg_wait_of_same_past_second +
     -0.1693 * parameters.avg_latency_of_all_past_second +
      0.2391 * parameters.avg_latency_of_same_past_5_seconds +
      0.1074 * parameters.avg_latency_of_same_last_20 +
-34220105.0114;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
