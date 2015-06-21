#include "my_global.h"
#include "m5p.h"
#include "trace_tool.h"

static
double
new_order_LM1(work_wait &parameters) {
  double actual_remaining = 
	1.2857 * parameters.work_so_far 
	+ 0.8307 * parameters.wait_so_far 
	- 1941200.3473 * parameters.num_locks_so_far 
	+ 19761434.4341 * parameters.num_of_wait_locks 
	+ 334303.2246 * parameters.total_wait_locks 
	- 10.8743 * parameters.total_granted_locks 
	- 0.0062 * parameters.mean_work_of_all 
	- 1.4313 * parameters.mean_wait_of_all 
	- 639198.4129 * parameters.cpu_usage 
	- 0.3025 * parameters.avg_work_of_same_past_second 
	- 0.236 * parameters.avg_wait_of_same_past_second 
	+ 0.3439 * parameters.avg_latency_of_all_past_second 
	- 0.0878 * parameters.avg_latency_of_same_past_5_seconds 
	+ 0.0975 * parameters.avg_latency_of_same_last_20 
	- 0.031 * parameters.max_latency_of_same_last_50 
	+ 0.7618 * parameters.prediction 
	+ 55784774.0459;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM2(work_wait &parameters) {
  double actual_remaining = 
	0.8724 * parameters.work_so_far 
	+ 0.5846 * parameters.wait_so_far 
	- 2626715.5849 * parameters.num_locks_so_far 
	- 24345.5308 * parameters.num_of_wait_locks 
	+ 968313.1701 * parameters.total_wait_locks 
	+ 30.8104 * parameters.total_granted_locks 
	- 0.0095 * parameters.mean_work_of_all 
	- 4.0933 * parameters.mean_wait_of_all 
	- 168939890.5037 * parameters.cpu_usage 
	+ 0.2626 * parameters.avg_work_of_same_past_second 
	+ 1.2176 * parameters.avg_wait_of_same_past_second 
	- 0.9623 * parameters.avg_latency_of_all_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_past_5_seconds 
	+ 0.1402 * parameters.avg_latency_of_same_last_20 
	- 0.0525 * parameters.max_latency_of_same_last_50 
	+ 0.3629 * parameters.prediction 
	+ 340826508.8041;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM3(work_wait &parameters) {
  double actual_remaining = 
	1.0697 * parameters.work_so_far 
	+ 0.7424 * parameters.wait_so_far 
	- 4617250.2388 * parameters.num_locks_so_far 
	- 10398253.3725 * parameters.num_of_wait_locks 
	+ 717112.3122 * parameters.total_wait_locks 
	- 827.2967 * parameters.total_granted_locks 
	- 14.9486 * parameters.mean_work_of_all 
	+ 16.6583 * parameters.mean_wait_of_all 
	- 86538481.8308 * parameters.cpu_usage 
	+ 0.4465 * parameters.avg_work_of_same_past_second 
	+ 0.2135 * parameters.avg_wait_of_same_past_second 
	- 0.4447 * parameters.avg_latency_of_all_past_second 
	- 0.4221 * parameters.avg_latency_of_same_past_5_seconds 
	+ 0.1128 * parameters.avg_latency_of_same_last_20 
	- 0.0223 * parameters.max_latency_of_same_last_50 
	+ 0.4358 * parameters.prediction 
	+ 2356806882.9591;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM4(work_wait &parameters) {
  double actual_remaining = 
	0.4304 * parameters.work_so_far 
	+ 0.2193 * parameters.wait_so_far 
	- 3995034.0172 * parameters.num_locks_so_far 
	- 66309.711 * parameters.num_of_wait_locks 
	+ 2230.2118 * parameters.total_wait_locks 
	+ 0.0068 * parameters.total_granted_locks 
	- 0.0024 * parameters.mean_work_of_all 
	- 0.0079 * parameters.mean_wait_of_all 
	- 1010512.1972 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_work_of_same_past_second 
	- 0.0006 * parameters.avg_wait_of_same_past_second 
	+ 0.2601 * parameters.avg_latency_of_all_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_past_5_seconds 
	+ 0.1819 * parameters.avg_latency_of_same_last_20 
	- 0.0597 * parameters.max_latency_of_same_last_50 
	+ 0.8578 * parameters.prediction 
	+ 47560437.9477;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM5(work_wait &parameters) {
  double actual_remaining = 
	1.1684 * parameters.work_so_far 
	+ 0.8435 * parameters.wait_so_far 
	- 5314436.4655 * parameters.num_locks_so_far 
	- 10280921.604 * parameters.num_of_wait_locks 
	- 157056.8754 * parameters.total_wait_locks 
	+ 40.0092 * parameters.total_granted_locks 
	- 0.004 * parameters.mean_work_of_all 
	- 0.0054 * parameters.mean_wait_of_all 
	- 266746471.2229 * parameters.cpu_usage 
	- 0.8703 * parameters.avg_work_of_same_past_second 
	- 0.8103 * parameters.avg_wait_of_same_past_second 
	+ 1.0385 * parameters.avg_latency_of_all_past_second 
	+ 0.0005 * parameters.avg_latency_of_same_past_5_seconds 
	+ 0.1766 * parameters.avg_latency_of_same_last_20 
	- 0.0209 * parameters.max_latency_of_same_last_50 
	+ 0.148 * parameters.prediction 
	+ 388803004.6836;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
new_order_estimate(work_wait &parameters){

  if (parameters.wait_so_far <= 313296800.5) {

    if (parameters.prediction <= 193387544.5) {
      return new_order_LM1(parameters);
    } else {

      if (parameters.prediction <= 431432776.5) {

        if (parameters.total_wait_locks <= 300.5) {
          return new_order_LM2(parameters);
        } else {
          return new_order_LM3(parameters);
        }
      } else {
        return new_order_LM4(parameters);
      }
    }
  } else {
    return new_order_LM5(parameters);
  }
}