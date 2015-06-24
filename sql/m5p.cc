#include "my_global.h"
#include "m5p.h"
#include "trace_tool.h"

double
new_order_estimate(work_wait &parameters){
  double actual_remaining =

      0.1874 * parameters.work_so_far +
     -0.1657 * parameters.wait_so_far +
-6477039.1806 * parameters.num_locks_so_far +
-11354061.7897 * parameters.num_of_wait_locks +
 482648.8196 * parameters.total_wait_locks +
      0.563  * parameters.mean_work_of_all +
     -1.7645 * parameters.mean_wait_of_all +
-152994150.628 * parameters.cpu_usage +
      0.2067 * parameters.avg_work_of_same_past_second +
     -0.1708 * parameters.avg_latency_of_all_past_second +
      0.266  * parameters.avg_latency_of_same_past_5_seconds +
      0.23   * parameters.avg_latency_of_same_last_20 +
     -0.0129 * parameters.max_latency_of_same_last_50 +
250829724.7088;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
payment_estimate(work_wait &parameters){
  double actual_remaining =

      0.0835 * parameters.work_so_far +
-594019.474  * parameters.num_of_wait_locks +
 -49486.2476 * parameters.total_wait_locks +
      6.2763 * parameters.total_granted_locks +
     -0.2774 * parameters.mean_work_of_all +
      0.2145 * parameters.mean_wait_of_all +
-23200647.0694 * parameters.cpu_usage +
     -0.0858 * parameters.avg_work_of_same_past_second +
     -0.0366 * parameters.avg_wait_of_same_past_second +
      0.0365 * parameters.avg_latency_of_all_past_second +
      0.0187 * parameters.avg_latency_of_same_past_5_seconds +
      0.0275 * parameters.avg_latency_of_same_last_20 +
     -0.002  * parameters.max_latency_of_same_last_50 +
36199751.2508;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
delivery_estimate(work_wait &parameters){
  double actual_remaining =

     -0.2048 * parameters.wait_so_far +
-4745192.2373 * parameters.num_locks_so_far +
20006832.8952 * parameters.num_of_wait_locks +
 192066.5452 * parameters.total_wait_locks +
     66.2729 * parameters.total_granted_locks +
      3.5127 * parameters.mean_work_of_all +
     -2.2249 * parameters.mean_wait_of_all +
-140902393.7155 * parameters.cpu_usage +
     -0.1952 * parameters.avg_work_of_same_past_second +
     -0.2761 * parameters.avg_wait_of_same_past_second +
      0.3539 * parameters.avg_latency_of_all_past_second +
      0.0483 * parameters.avg_latency_of_same_past_5_seconds +
      0.6413 * parameters.avg_latency_of_same_last_20 +
     -0.0384 * parameters.max_latency_of_same_last_50 +
132691985.1154;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
stock_level_estimate(work_wait &parameters){
  double actual_remaining =

     -0.0507 * parameters.wait_so_far +
-129393.3949 * parameters.num_locks_so_far +
  76204.4392 * parameters.total_wait_locks +
     -0.1782 * parameters.mean_wait_of_all +
      0.0804 * parameters.avg_latency_of_all_past_second +
     -0.2025 * parameters.avg_latency_of_same_past_5_seconds +
19210285.8719;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
tpcc_estimate(work_wait &parameters){
  double actual_remaining =

     -0.1025 * parameters.work_so_far +
     -0.114  * parameters.wait_so_far +
-762357.5591 * parameters.num_locks_so_far +
 206950.1077 * parameters.total_wait_locks +
     -0.3052 * parameters.mean_work_of_all +
     -0.6084 * parameters.mean_wait_of_all +
-87379888.6491 * parameters.cpu_usage +
      0.3191 * parameters.avg_work_of_same_past_second +
     -0.3957 * parameters.avg_wait_of_same_past_second +
      0.094  * parameters.avg_latency_of_all_past_second +
      0.2591 * parameters.avg_latency_of_same_past_5_seconds +
      0.1673 * parameters.avg_latency_of_same_last_20 +
     -0.0076 * parameters.max_latency_of_same_last_50 +
120179869.517;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
