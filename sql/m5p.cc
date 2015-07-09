#include "my_global.h"
#include "m5p.h"
#include "trace_tool.h"

double
new_order_estimate(work_wait &parameters){
  double actual_remaining =

      1.3698 * parameters.work_so_far +
     -0.1974 * parameters.wait_so_far +
-9977520.7623 * parameters.num_of_wait_locks +
 422346.9218 * parameters.total_wait_locks +
     15.334  * parameters.total_granted_locks +
     -3.5559 * parameters.mean_work_of_all +
     -0.6286 * parameters.mean_wait_of_all +
-302637908.7074 * parameters.cpu_usage +
      0.2304 * parameters.avg_work_of_same_past_second +
     -0.5576 * parameters.avg_wait_of_same_past_second +
      0.2727 * parameters.avg_latency_of_all_past_second +
      0.1571 * parameters.avg_latency_of_same_past_5_seconds +
      0.1951 * parameters.avg_latency_of_same_last_20 +
530845063.2462;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
payment_estimate(work_wait &parameters){
  double actual_remaining =

      0.0542 * parameters.work_so_far +
     -0.003  * parameters.wait_so_far +
  29541.0428 * parameters.total_wait_locks +
      1.2627 * parameters.total_granted_locks +
     -0.478  * parameters.mean_work_of_all +
-29231543.4462 * parameters.cpu_usage +
      0.1421 * parameters.avg_work_of_same_past_second +
      0.0451 * parameters.avg_wait_of_same_past_second +
     -0.0673 * parameters.avg_latency_of_all_past_second +
      0.004  * parameters.avg_latency_of_same_past_5_seconds +
      0.0226 * parameters.avg_latency_of_same_last_20 +
      0.0023 * parameters.max_latency_of_same_last_50 +
62152466.863;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
