#include "my_global.h"
#include "m5p.h"
#include "trace_tool.h"

double
new_order_estimate(work_wait &parameters){
  double actual_remaining =

      1.1926 * parameters.work_so_far +
     -0.1166 * parameters.wait_so_far +
-3897818.6758 * parameters.num_of_wait_locks +
1808409.07   * parameters.total_wait_locks +
    -49.2412 * parameters.total_granted_locks +
      1.9466 * parameters.mean_work_of_all +
     -0.8364 * parameters.mean_wait_of_all +
-170212005.4485 * parameters.cpu_usage +
     -0.8098 * parameters.avg_work_of_same_past_second +
     -1.1576 * parameters.avg_wait_of_same_past_second +
      1.066  * parameters.avg_latency_of_all_past_second +
     -0.1517 * parameters.avg_latency_of_same_past_5_seconds +
     -0.05   * parameters.avg_latency_of_same_last_20 +
     -0.0289 * parameters.max_latency_of_same_last_50 +
180391210.9323;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
payment_estimate(work_wait &parameters){
  double actual_remaining =

     -0.1032 * parameters.work_so_far +
      0.0047 * parameters.wait_so_far +
2068523.4291 * parameters.num_of_wait_locks +
 222277.5028 * parameters.total_wait_locks +
     -6.2182 * parameters.total_granted_locks +
      0.144  * parameters.mean_work_of_all +
     -0.1915 * parameters.mean_wait_of_all +
-31891257.0078 * parameters.cpu_usage +
      0.2307 * parameters.avg_work_of_same_past_second +
      0.1477 * parameters.avg_wait_of_same_past_second +
     -0.1894 * parameters.avg_latency_of_all_past_second +
      0.0557 * parameters.avg_latency_of_same_past_5_seconds +
     -0.0107 * parameters.avg_latency_of_same_last_20 +
     -0.0062 * parameters.max_latency_of_same_last_50 +
37084358.0135;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
stock_level_estimate(work_wait &parameters){
  double actual_remaining =

 +
6097506.7143;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
tpcc_estimate(work_wait &parameters){
  double actual_remaining =

      0.2577 * parameters.work_so_far +
     -0.0491 * parameters.wait_so_far +
 803068.7035 * parameters.total_wait_locks +
    -22.0914 * parameters.total_granted_locks +
     -0.2114 * parameters.mean_wait_of_all +
-76884814.3922 * parameters.cpu_usage +
      1.2585 * parameters.avg_work_of_same_past_second +
      0.8312 * parameters.avg_wait_of_same_past_second +
     -0.9923 * parameters.avg_latency_of_all_past_second +
      0.0518 * parameters.avg_latency_of_same_past_5_seconds +
     -0.0421 * parameters.avg_latency_of_same_last_20 +
     -0.0118 * parameters.max_latency_of_same_last_50 +
101799027.23;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
