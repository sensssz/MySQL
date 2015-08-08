#include "my_global.h"
#include "trace_tool.h"

double
new_order_estimate(work_wait &parameters){
  double actual_remaining =

      0.1027 * parameters.work_so_far +
     -0.1489 * parameters.wait_so_far +
-4537233.1922 * parameters.num_locks_so_far +
-3994567.1121 * parameters.num_of_wait_locks +
 163534.9574 * parameters.total_wait_locks +
     -5.6608 * parameters.total_granted_locks +
     -0.3491 * parameters.mean_work_of_all +
      0.1231 * parameters.mean_wait_of_all +
-80255068.6038 * parameters.cpu_usage +
      0.7812 * parameters.avg_work_of_same_past_second +
      0.2739 * parameters.avg_wait_of_same_past_second +
     -0.5295 * parameters.avg_latency_of_all_past_second +
      0.2027 * parameters.avg_latency_of_same_past_5_seconds +
      0.2288 * parameters.avg_latency_of_same_last_20 +
     -0.0096 * parameters.max_latency_of_same_last_50 +
155998777.2501;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
payment_estimate(work_wait &parameters){
  double actual_remaining =

      0.0183 * parameters.work_so_far +
-611468.8242 * parameters.num_of_wait_locks +
   4934.4996 * parameters.total_wait_locks +
      0.8414 * parameters.total_granted_locks +
      0.066  * parameters.mean_work_of_all +
     -0.0196 * parameters.mean_wait_of_all +
-14620630.4071 * parameters.cpu_usage +
     -0.0798 * parameters.avg_work_of_same_past_second +
     -0.0538 * parameters.avg_wait_of_same_past_second +
      0.0687 * parameters.avg_latency_of_all_past_second +
     -0.0067 * parameters.avg_latency_of_same_past_5_seconds +
      0.0208 * parameters.avg_latency_of_same_last_20 +
      0.0012 * parameters.max_latency_of_same_last_50 +
19535050.4656;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
delivery_estimate(work_wait &parameters){
  double actual_remaining =

     -0.1684 * parameters.wait_so_far +
-6941869.8618 * parameters.num_locks_so_far +
 260324.0945 * parameters.total_wait_locks +
      1.7246 * parameters.mean_work_of_all +
     -0.5793 * parameters.mean_wait_of_all +
-312945119.0108 * parameters.cpu_usage +
     -0.5029 * parameters.avg_wait_of_same_past_second +
      0.2653 * parameters.avg_latency_of_all_past_second +
      0.156  * parameters.avg_latency_of_same_past_5_seconds +
      0.6989 * parameters.avg_latency_of_same_last_20 +
     -0.0633 * parameters.max_latency_of_same_last_50 +
342122006.6135;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
stock_level_estimate(work_wait &parameters){
  double actual_remaining =

     -0.0451 * parameters.wait_so_far +
-168220.2267 * parameters.num_locks_so_far +
  87642.5313 * parameters.total_wait_locks +
     -9.1038 * parameters.total_granted_locks +
     -0.0356 * parameters.avg_latency_of_all_past_second +
      0.2925 * parameters.avg_latency_of_same_past_5_seconds +
      0.0279 * parameters.avg_latency_of_same_last_20 +
23975959.1177;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
tpcc_estimate(work_wait &parameters){
  double actual_remaining =

      0.068  * parameters.work_so_far +
     -0.1069 * parameters.wait_so_far +
-563327.0365 * parameters.num_locks_so_far +
3044335.4836 * parameters.num_of_wait_locks +
  89920.5103 * parameters.total_wait_locks +
     -4.239  * parameters.total_granted_locks +
     -0.4871 * parameters.mean_work_of_all +
      0.1611 * parameters.mean_wait_of_all +
-47852921.5736 * parameters.cpu_usage +
      0.4504 * parameters.avg_work_of_same_past_second +
     -0.3198 * parameters.avg_wait_of_same_past_second +
      0.0494 * parameters.avg_latency_of_all_past_second +
      0.1911 * parameters.avg_latency_of_same_past_5_seconds +
      0.1802 * parameters.avg_latency_of_same_last_20 +
     -0.0088 * parameters.max_latency_of_same_last_50 +
70946421.3152;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
