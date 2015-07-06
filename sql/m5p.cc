#include "my_global.h"
#include "m5p.h"
#include "trace_tool.h"

double
new_order_estimate(work_wait &parameters){
  double actual_remaining =

      0.5137 * parameters.work_so_far +
     -0.1909 * parameters.wait_so_far +
-13538627.7171 * parameters.num_of_wait_locks +
 226808.1259 * parameters.total_wait_locks +
     26.409  * parameters.total_granted_locks +
     -0.5742 * parameters.mean_work_of_all +
     -0.9763 * parameters.mean_wait_of_all +
-118768775.5274 * parameters.cpu_usage +
      0.6616 * parameters.avg_work_of_same_past_second +
      0.6511 * parameters.avg_wait_of_same_past_second +
     -0.724  * parameters.avg_latency_of_all_past_second +
      0.115  * parameters.avg_latency_of_same_past_5_seconds +
      0.25   * parameters.avg_latency_of_same_last_20 +
     -0.0169 * parameters.max_latency_of_same_last_50 +
296198308.5656;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
payment_estimate(work_wait &parameters){
  double actual_remaining =

      0.0825 * parameters.work_so_far +
     -0.0027 * parameters.wait_so_far +
 512424.1785 * parameters.num_of_wait_locks +
  10445.895  * parameters.total_wait_locks +
      2.5583 * parameters.total_granted_locks +
      0.2973 * parameters.mean_work_of_all +
     -0.1855 * parameters.mean_wait_of_all +
     -0.0832 * parameters.avg_wait_of_same_past_second +
      0.075  * parameters.avg_latency_of_all_past_second +
      0.004  * parameters.avg_latency_of_same_past_5_seconds +
      0.0291 * parameters.avg_latency_of_same_last_20 +
     -0.0043 * parameters.max_latency_of_same_last_50 +
3215940.5987;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
stock_level_estimate(work_wait &parameters){
  double actual_remaining =

      1.5783 * parameters.work_so_far +
 159464.8718 * parameters.total_wait_locks +
    -24.4693 * parameters.total_granted_locks +
     -0.537  * parameters.mean_wait_of_all +
648091997.1567 * parameters.cpu_usage +
     -0.114  * parameters.avg_latency_of_all_past_second +
      0.0961 * parameters.avg_latency_of_same_last_20 +
-564270460.7312;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
tpcc_estimate(work_wait &parameters){
  double actual_remaining =

      0.3008 * parameters.work_so_far +
     -0.0871 * parameters.wait_so_far +
1016167.7483 * parameters.num_locks_so_far +
-4791036.2756 * parameters.num_of_wait_locks +
  80246.462  * parameters.total_wait_locks +
      9.113  * parameters.total_granted_locks +
     -0.3021 * parameters.mean_work_of_all +
     -0.3015 * parameters.mean_wait_of_all +
      1.0923 * parameters.avg_work_of_same_past_second +
      0.096  * parameters.avg_wait_of_same_past_second +
     -0.3563 * parameters.avg_latency_of_all_past_second +
      0.1371 * parameters.avg_latency_of_same_past_5_seconds +
      0.1211 * parameters.avg_latency_of_same_last_20 +
     -0.0081 * parameters.max_latency_of_same_last_50 +
61041805.6173;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
