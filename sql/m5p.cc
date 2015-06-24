#include "my_global.h"
#include "m5p.h"
#include "trace_tool.h"

double
new_order_estimate(work_wait &parameters){
  double actual_remaining =

      1.2313 * parameters.work_so_far +
      0.7547 * parameters.wait_so_far +
-5915557.4524 * parameters.num_locks_so_far +
-26960433.5977 * parameters.num_of_wait_locks +
 593322.3305 * parameters.total_wait_locks +
     39.863  * parameters.total_granted_locks +
     -3.043  * parameters.mean_wait_of_all +
-213755337.9338 * parameters.cpu_usage +
     -0.3065 * parameters.avg_work_of_same_past_second +
     -0.3961 * parameters.avg_wait_of_same_past_second +
      0.3495 * parameters.avg_latency_of_all_past_second +
      0.1721 * parameters.avg_latency_of_same_past_5_seconds +
      0.1766 * parameters.avg_latency_of_same_last_20 +
     -0.031  * parameters.max_latency_of_same_last_50 +
468277055.8679;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
payment_estimate(work_wait &parameters){
  double actual_remaining =

      1.1659 * parameters.work_so_far +
      0.6939 * parameters.wait_so_far +
-14243238.1056 * parameters.num_locks_so_far +
-49593253.1175 * parameters.num_of_wait_locks +
 871214.8337 * parameters.total_wait_locks +
     36.4168 * parameters.total_granted_locks +
      5.3166 * parameters.mean_work_of_all +
     -6.772  * parameters.mean_wait_of_all +
-149160252.0257 * parameters.cpu_usage +
      0.1793 * parameters.avg_latency_of_same_past_5_seconds +
      0.1071 * parameters.avg_latency_of_same_last_20 +
245027925.9684;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
delivery_estimate(work_wait &parameters){
  double actual_remaining =

      0.8621 * parameters.work_so_far +
      0.497  * parameters.wait_so_far +
-6773831.9298 * parameters.num_locks_so_far +
 678292.5868 * parameters.total_wait_locks +
    101.2812 * parameters.total_granted_locks +
      4.8763 * parameters.mean_work_of_all +
     -5.4918 * parameters.mean_wait_of_all +
-344688446.7057 * parameters.cpu_usage +
     -0.9409 * parameters.avg_wait_of_same_past_second +
      0.1623 * parameters.avg_latency_of_same_past_5_seconds +
      0.4197 * parameters.avg_latency_of_same_last_20 +
584554472.1297;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
tpcc_estimate(work_wait &parameters){
  double actual_remaining =

      1.1159 * parameters.work_so_far +
      0.7135 * parameters.wait_so_far +
-5243651.7726 * parameters.num_locks_so_far +
-37703007.2066 * parameters.num_of_wait_locks +
 769182.4632 * parameters.total_wait_locks +
     36.7706 * parameters.total_granted_locks +
      2.4973 * parameters.mean_work_of_all +
     -4.9993 * parameters.mean_wait_of_all +
-171682811.5037 * parameters.cpu_usage +
      0.333  * parameters.avg_work_of_same_past_second +
     -0.1127 * parameters.avg_wait_of_same_past_second +
     -0.0793 * parameters.avg_latency_of_all_past_second +
      0.2416 * parameters.avg_latency_of_same_past_5_seconds +
      0.1596 * parameters.avg_latency_of_same_last_20 +
     -0.0213 * parameters.max_latency_of_same_last_50 +
328197411.4417;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
