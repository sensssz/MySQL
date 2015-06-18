#include "my_global.h"
#include "m5p.h"
#include "trace_tool.h"

static
double
new_order_LM1(work_wait &parameters) {
  double actual_remaining = 
	3506.0031 * parameters.work_so_far 
	- 0.0017 * parameters.wait_so_far 
	+ 131365.8243 * parameters.total_wait_locks 
	+ 0.0017 * parameters.mean_wait_of_all 
	- 146252778.3642 * parameters.cpu_usage 
	+ 0.0012 * parameters.avg_latency_of_same_past_second 
	+ 91662725.2786;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM2(work_wait &parameters) {
  double actual_remaining = 
	1.5235 * parameters.work_so_far 
	- 0.1739 * parameters.wait_so_far 
	- 58895.9392 * parameters.num_locks_so_far 
	- 204899.6918 * parameters.num_of_wait_locks 
	+ 789810.0145 * parameters.total_wait_locks 
	+ 0.2952 * parameters.mean_wait_of_all 
	- 361723294.9325 * parameters.cpu_usage 
	+ 0.0027 * parameters.avg_latency_of_same_past_second 
	+ 371522791.4385;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM3(work_wait &parameters) {
  double actual_remaining = 
	0.8145 * parameters.work_so_far 
	- 0.0016 * parameters.wait_so_far 
	- 58895.9392 * parameters.num_locks_so_far 
	- 21310774.2185 * parameters.num_of_wait_locks 
	+ 1279762.8735 * parameters.total_wait_locks 
	- 6.3486 * parameters.mean_wait_of_all 
	- 292714164.5508 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_latency_of_same_past_second 
	+ 585646897.94;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM4(work_wait &parameters) {
  double actual_remaining = 
	0.6774 * parameters.work_so_far 
	- 0.103 * parameters.wait_so_far 
	- 71097.3791 * parameters.num_locks_so_far 
	- 26878686.4394 * parameters.num_of_wait_locks 
	+ 271065.5771 * parameters.total_wait_locks 
	+ 0.0005 * parameters.mean_wait_of_all 
	- 315500421.6452 * parameters.cpu_usage 
	+ 0.001 * parameters.avg_latency_of_same_past_second 
	+ 531470533.2478;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
new_order_estimate(work_wait &parameters){

  if (parameters.work_so_far <= 33893) {
    return new_order_LM1(parameters);
  } else {

    if (parameters.wait_so_far <= 197867896) {

      if (parameters.total_wait_locks <= 182.5) {
        return new_order_LM2(parameters);
      } else {
        return new_order_LM3(parameters);
      }
    } else {
      return new_order_LM4(parameters);
    }
  }
}
static
double
payment_LM1(work_wait &parameters) {
  double actual_remaining = 
	781.8936 * parameters.work_so_far 
	+ 0.0395 * parameters.wait_so_far 
	+ 39186.0373 * parameters.num_of_wait_locks 
	+ 9391.0451 * parameters.total_wait_locks 
	+ 0.0007 * parameters.mean_wait_of_all 
	- 541632.6025 * parameters.cpu_usage 
	- 0 * parameters.avg_latency_of_same_past_second 
	- 524910.8656;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM2(work_wait &parameters) {
  double actual_remaining = 
	1428.3053 * parameters.work_so_far 
	+ 0.0787 * parameters.wait_so_far 
	+ 63569.6435 * parameters.num_of_wait_locks 
	+ 356.5001 * parameters.total_wait_locks 
	+ 0.0094 * parameters.mean_wait_of_all 
	- 1878873.6226 * parameters.cpu_usage 
	- 0 * parameters.avg_latency_of_same_past_second 
	- 2514319.9817;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM3(work_wait &parameters) {
  double actual_remaining = 
	50.0172 * parameters.work_so_far 
	+ 0.0105 * parameters.wait_so_far 
	+ 63569.6435 * parameters.num_of_wait_locks 
	+ 70978.9245 * parameters.total_wait_locks 
	+ 0.0173 * parameters.mean_wait_of_all 
	+ 25625040.594 * parameters.cpu_usage 
	- 0 * parameters.avg_latency_of_same_past_second 
	- 14780642.1277;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM4(work_wait &parameters) {
  double actual_remaining = 
	50.0172 * parameters.work_so_far 
	+ 0.0105 * parameters.wait_so_far 
	+ 63569.6435 * parameters.num_of_wait_locks 
	+ 70978.9245 * parameters.total_wait_locks 
	+ 0.0173 * parameters.mean_wait_of_all 
	+ 25625040.594 * parameters.cpu_usage 
	- 0 * parameters.avg_latency_of_same_past_second 
	- 13073606.7412;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM5(work_wait &parameters) {
  double actual_remaining = 
	50.0172 * parameters.work_so_far 
	+ 0.3629 * parameters.wait_so_far 
	+ 63569.6435 * parameters.num_of_wait_locks 
	+ 356.5001 * parameters.total_wait_locks 
	+ 0.3828 * parameters.mean_wait_of_all 
	+ 19424646.6389 * parameters.cpu_usage 
	- 0 * parameters.avg_latency_of_same_past_second 
	- 28778595.2301;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM6(work_wait &parameters) {
  double actual_remaining = 
	50.0172 * parameters.work_so_far 
	+ 0.547 * parameters.wait_so_far 
	+ 63569.6435 * parameters.num_of_wait_locks 
	+ 356.5001 * parameters.total_wait_locks 
	+ 0.5021 * parameters.mean_wait_of_all 
	+ 19424646.6389 * parameters.cpu_usage 
	- 0 * parameters.avg_latency_of_same_past_second 
	- 37256733.8731;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM7(work_wait &parameters) {
  double actual_remaining = 
	6515.0905 * parameters.work_so_far 
	+ 0.4814 * parameters.wait_so_far 
	+ 63569.6435 * parameters.num_of_wait_locks 
	+ 356.5001 * parameters.total_wait_locks 
	+ 0.4519 * parameters.mean_wait_of_all 
	+ 19424646.6389 * parameters.cpu_usage 
	- 0 * parameters.avg_latency_of_same_past_second 
	- 86007856.8655;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM8(work_wait &parameters) {
  double actual_remaining = 
	8416.5827 * parameters.work_so_far 
	+ 0.4814 * parameters.wait_so_far 
	+ 63569.6435 * parameters.num_of_wait_locks 
	+ 356.5001 * parameters.total_wait_locks 
	+ 0.4519 * parameters.mean_wait_of_all 
	+ 19424646.6389 * parameters.cpu_usage 
	- 0 * parameters.avg_latency_of_same_past_second 
	- 100796736.4201;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM9(work_wait &parameters) {
  double actual_remaining = 
	50.0172 * parameters.work_so_far 
	+ 0.0105 * parameters.wait_so_far 
	+ 63569.6435 * parameters.num_of_wait_locks 
	+ 356.5001 * parameters.total_wait_locks 
	- 0.0956 * parameters.mean_wait_of_all 
	+ 19424646.6389 * parameters.cpu_usage 
	- 0 * parameters.avg_latency_of_same_past_second 
	+ 9394674.7341;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM10(work_wait &parameters) {
  double actual_remaining = 
	50.0172 * parameters.work_so_far 
	+ 0.0105 * parameters.wait_so_far 
	+ 63569.6435 * parameters.num_of_wait_locks 
	+ 151080.5564 * parameters.total_wait_locks 
	- 0.3017 * parameters.mean_wait_of_all 
	- 43114434.8489 * parameters.cpu_usage 
	- 0 * parameters.avg_latency_of_same_past_second 
	+ 30317769.4458;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM11(work_wait &parameters) {
  double actual_remaining = 
	50.0172 * parameters.work_so_far 
	+ 0.0105 * parameters.wait_so_far 
	+ 63569.6435 * parameters.num_of_wait_locks 
	+ 273095.2687 * parameters.total_wait_locks 
	- 0.5599 * parameters.mean_wait_of_all 
	- 112926868.1202 * parameters.cpu_usage 
	- 0 * parameters.avg_latency_of_same_past_second 
	+ 79885588.3583;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM12(work_wait &parameters) {
  double actual_remaining = 
	1197.4939 * parameters.work_so_far 
	+ 0.0034 * parameters.wait_so_far 
	+ 63569.6435 * parameters.num_of_wait_locks 
	+ 356.5001 * parameters.total_wait_locks 
	+ 0.0032 * parameters.mean_wait_of_all 
	- 2176113.6229 * parameters.cpu_usage 
	- 0 * parameters.avg_latency_of_same_past_second 
	- 399128.9564;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM13(work_wait &parameters) {
  double actual_remaining = 
	15.5544 * parameters.work_so_far 
	+ 0.0026 * parameters.wait_so_far 
	+ 2689086.7831 * parameters.num_of_wait_locks 
	+ 356.5001 * parameters.total_wait_locks 
	+ 0.0022 * parameters.mean_wait_of_all 
	- 1385751.5867 * parameters.cpu_usage 
	- 0 * parameters.avg_latency_of_same_past_second 
	+ 8793552.846;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM14(work_wait &parameters) {
  double actual_remaining = 
	15.5544 * parameters.work_so_far 
	+ 0.0027 * parameters.wait_so_far 
	+ 230237.8234 * parameters.num_of_wait_locks 
	+ 356.5001 * parameters.total_wait_locks 
	+ 0.8759 * parameters.mean_wait_of_all 
	- 25906763.4151 * parameters.cpu_usage 
	- 0 * parameters.avg_latency_of_same_past_second 
	+ 6876255.7443;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM15(work_wait &parameters) {
  double actual_remaining = 
	2775.2841 * parameters.work_so_far 
	+ 0.0027 * parameters.wait_so_far 
	+ 3594955.1039 * parameters.num_of_wait_locks 
	+ 356.5001 * parameters.total_wait_locks 
	+ 0.0178 * parameters.mean_wait_of_all 
	- 135715479.0744 * parameters.cpu_usage 
	- 0 * parameters.avg_latency_of_same_past_second 
	+ 97555479.8598;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM16(work_wait &parameters) {
  double actual_remaining = 
	0.0072 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	+ 461462.2706 * parameters.num_of_wait_locks 
	+ 25915.78 * parameters.total_wait_locks 
	- 0.3738 * parameters.mean_wait_of_all 
	+ 880833.1521 * parameters.cpu_usage 
	- 0.0078 * parameters.avg_latency_of_same_past_second 
	+ 46336017.4993;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM17(work_wait &parameters) {
  double actual_remaining = 
	0.0072 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	+ 461462.2706 * parameters.num_of_wait_locks 
	+ 25915.78 * parameters.total_wait_locks 
	- 0.3738 * parameters.mean_wait_of_all 
	+ 880833.1521 * parameters.cpu_usage 
	- 0.0078 * parameters.avg_latency_of_same_past_second 
	+ 33315855.6625;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM18(work_wait &parameters) {
  double actual_remaining = 
	0.0072 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	+ 461462.2706 * parameters.num_of_wait_locks 
	+ 25915.78 * parameters.total_wait_locks 
	- 0.3374 * parameters.mean_wait_of_all 
	+ 880833.1521 * parameters.cpu_usage 
	- 0.0078 * parameters.avg_latency_of_same_past_second 
	+ 23236911.7372;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM19(work_wait &parameters) {
  double actual_remaining = 
	0.0072 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	+ 535227.9986 * parameters.num_of_wait_locks 
	+ 372312.8286 * parameters.total_wait_locks 
	- 1.5988 * parameters.mean_wait_of_all 
	+ 7451679.4549 * parameters.cpu_usage 
	- 0.2368 * parameters.avg_latency_of_same_past_second 
	+ 45230193.5096;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM20(work_wait &parameters) {
  double actual_remaining = 
	0.0072 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	+ 937703.8378 * parameters.num_of_wait_locks 
	+ 12902.3927 * parameters.total_wait_locks 
	+ 5.0179 * parameters.mean_wait_of_all 
	+ 16848696.2106 * parameters.cpu_usage 
	+ 0.0223 * parameters.avg_latency_of_same_past_second 
	- 178708750.5296;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM21(work_wait &parameters) {
  double actual_remaining = 
	0.0072 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	+ 937703.8378 * parameters.num_of_wait_locks 
	+ 12902.3927 * parameters.total_wait_locks 
	+ 6.8888 * parameters.mean_wait_of_all 
	+ 16848696.2106 * parameters.cpu_usage 
	+ 0.1238 * parameters.avg_latency_of_same_past_second 
	- 240684565.15;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM22(work_wait &parameters) {
  double actual_remaining = 
	-4.2522 * parameters.work_so_far 
	+ 0.0349 * parameters.wait_so_far 
	+ 937703.8378 * parameters.num_of_wait_locks 
	+ 12902.3927 * parameters.total_wait_locks 
	+ 3.9658 * parameters.mean_wait_of_all 
	+ 16848696.2106 * parameters.cpu_usage 
	+ 0.0242 * parameters.avg_latency_of_same_past_second 
	- 162603437.271;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM23(work_wait &parameters) {
  double actual_remaining = 
	0.0283 * parameters.work_so_far 
	- 0.0017 * parameters.wait_so_far 
	+ 120197.6744 * parameters.num_of_wait_locks 
	+ 280327.1121 * parameters.total_wait_locks 
	- 3.6942 * parameters.mean_wait_of_all 
	+ 8933783.5728 * parameters.cpu_usage 
	+ 0.0028 * parameters.avg_latency_of_same_past_second 
	+ 122152843.0758;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM24(work_wait &parameters) {
  double actual_remaining = 
	0.122 * parameters.work_so_far 
	- 0.001 * parameters.wait_so_far 
	+ 120197.6744 * parameters.num_of_wait_locks 
	+ 4562.7406 * parameters.total_wait_locks 
	- 0.8902 * parameters.mean_wait_of_all 
	+ 3490066.9225 * parameters.cpu_usage 
	+ 0.0455 * parameters.avg_latency_of_same_past_second 
	+ 57144815.8933;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM25(work_wait &parameters) {
  double actual_remaining = 
	0.0024 * parameters.work_so_far 
	- 0.0139 * parameters.wait_so_far 
	+ 1944615.2763 * parameters.num_of_wait_locks 
	+ 47531.9713 * parameters.total_wait_locks 
	- 0.3329 * parameters.mean_wait_of_all 
	- 459689.4349 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_latency_of_same_past_second 
	+ 29053731.304;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM26(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	- 2068323.1622 * parameters.num_of_wait_locks 
	+ 38301.8945 * parameters.total_wait_locks 
	+ 0 * parameters.mean_wait_of_all 
	- 99354238.9793 * parameters.cpu_usage 
	+ 0.0004 * parameters.avg_latency_of_same_past_second 
	+ 111649788.9321;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM27(work_wait &parameters) {
  double actual_remaining = 
	31.9184 * parameters.work_so_far 
	- 0.0009 * parameters.wait_so_far 
	+ 28778.0547 * parameters.num_of_wait_locks 
	+ 27536.5969 * parameters.total_wait_locks 
	- 0.1134 * parameters.mean_wait_of_all 
	+ 155211563.5986 * parameters.cpu_usage 
	+ 0.0159 * parameters.avg_latency_of_same_past_second 
	- 119918885.5913;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM28(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.0009 * parameters.wait_so_far 
	+ 28778.0547 * parameters.num_of_wait_locks 
	+ 278348.3709 * parameters.total_wait_locks 
	- 0.1134 * parameters.mean_wait_of_all 
	+ 155211563.5986 * parameters.cpu_usage 
	+ 0.0159 * parameters.avg_latency_of_same_past_second 
	- 178037276.9652;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM29(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.0009 * parameters.wait_so_far 
	+ 28778.0547 * parameters.num_of_wait_locks 
	+ 306775.5775 * parameters.total_wait_locks 
	- 0.1134 * parameters.mean_wait_of_all 
	+ 155211563.5986 * parameters.cpu_usage 
	+ 0.0159 * parameters.avg_latency_of_same_past_second 
	- 182623041.9496;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM30(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.0009 * parameters.wait_so_far 
	- 23858831.6478 * parameters.num_of_wait_locks 
	- 242607.0407 * parameters.total_wait_locks 
	+ 1.5944 * parameters.mean_wait_of_all 
	+ 415849960.9644 * parameters.cpu_usage 
	- 0.0583 * parameters.avg_latency_of_same_past_second 
	- 234572797.0309;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM31(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	+ 0.5634 * parameters.wait_so_far 
	+ 28778.0547 * parameters.num_of_wait_locks 
	+ 7659.7203 * parameters.total_wait_locks 
	+ 1.5944 * parameters.mean_wait_of_all 
	+ 14659231.6131 * parameters.cpu_usage 
	- 0.0059 * parameters.avg_latency_of_same_past_second 
	- 81838287.5247;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM32(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.0009 * parameters.wait_so_far 
	+ 28778.0547 * parameters.num_of_wait_locks 
	- 596750.1487 * parameters.total_wait_locks 
	+ 3.2737 * parameters.mean_wait_of_all 
	- 2543526885.1952 * parameters.cpu_usage 
	+ 0.2415 * parameters.avg_latency_of_same_past_second 
	+ 2274865719.5416;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM33(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.0009 * parameters.wait_so_far 
	+ 28778.0547 * parameters.num_of_wait_locks 
	+ 1094247.8462 * parameters.total_wait_locks 
	- 2.3111 * parameters.mean_wait_of_all 
	+ 477366146.2646 * parameters.cpu_usage 
	+ 0.9848 * parameters.avg_latency_of_same_past_second 
	- 922045996.2777;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM34(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.0009 * parameters.wait_so_far 
	+ 28778.0547 * parameters.num_of_wait_locks 
	+ 1768588.1684 * parameters.total_wait_locks 
	- 24732.7705 * parameters.mean_wait_of_all 
	+ 477366146.2646 * parameters.cpu_usage 
	+ 0.9848 * parameters.avg_latency_of_same_past_second 
	+ 1670465335847.8674;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM35(work_wait &parameters) {
  double actual_remaining = 
	-1.8235 * parameters.work_so_far 
	- 0.0556 * parameters.wait_so_far 
	+ 28778.0547 * parameters.num_of_wait_locks 
	+ 535208.0125 * parameters.total_wait_locks 
	+ 0 * parameters.mean_wait_of_all 
	+ 477366146.2646 * parameters.cpu_usage 
	+ 1.6565 * parameters.avg_latency_of_same_past_second 
	- 1007775561.1127;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM36(work_wait &parameters) {
  double actual_remaining = 
	0.0036 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 39441.8496 * parameters.num_of_wait_locks 
	+ 39911.0411 * parameters.total_wait_locks 
	+ 0 * parameters.mean_wait_of_all 
	- 189585.3491 * parameters.cpu_usage 
	- 0.0005 * parameters.avg_latency_of_same_past_second 
	+ 18041968.0348;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM37(work_wait &parameters) {
  double actual_remaining = 
	0.6696 * parameters.work_so_far 
	+ 0.222 * parameters.wait_so_far 
	+ 2001360.7804 * parameters.num_of_wait_locks 
	- 25914.7862 * parameters.total_wait_locks 
	- 0.3576 * parameters.mean_wait_of_all 
	- 189585.3491 * parameters.cpu_usage 
	+ 0.8365 * parameters.avg_latency_of_same_past_second 
	- 2068137.0957;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM38(work_wait &parameters) {
  double actual_remaining = 
	-0.1488 * parameters.work_so_far 
	+ 0.1426 * parameters.wait_so_far 
	+ 325784.8821 * parameters.num_of_wait_locks 
	- 25914.7862 * parameters.total_wait_locks 
	- 0.6 * parameters.mean_wait_of_all 
	- 189585.3491 * parameters.cpu_usage 
	+ 0.523 * parameters.avg_latency_of_same_past_second 
	+ 69088804.172;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM39(work_wait &parameters) {
  double actual_remaining = 
	-0.1206 * parameters.work_so_far 
	+ 0.1426 * parameters.wait_so_far 
	+ 2001360.7804 * parameters.num_of_wait_locks 
	- 25914.7862 * parameters.total_wait_locks 
	- 0.6 * parameters.mean_wait_of_all 
	- 189585.3491 * parameters.cpu_usage 
	+ 0.523 * parameters.avg_latency_of_same_past_second 
	+ 68555755.1809;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM40(work_wait &parameters) {
  double actual_remaining = 
	-0.1206 * parameters.work_so_far 
	+ 0.1426 * parameters.wait_so_far 
	+ 2001360.7804 * parameters.num_of_wait_locks 
	- 25914.7862 * parameters.total_wait_locks 
	- 0.6 * parameters.mean_wait_of_all 
	- 189585.3491 * parameters.cpu_usage 
	+ 0.523 * parameters.avg_latency_of_same_past_second 
	+ 66225934.8982;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM41(work_wait &parameters) {
  double actual_remaining = 
	-0.1206 * parameters.work_so_far 
	+ 0.1426 * parameters.wait_so_far 
	+ 2001360.7804 * parameters.num_of_wait_locks 
	- 25914.7862 * parameters.total_wait_locks 
	- 0.6 * parameters.mean_wait_of_all 
	- 189585.3491 * parameters.cpu_usage 
	+ 0.523 * parameters.avg_latency_of_same_past_second 
	+ 66550460.12;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM42(work_wait &parameters) {
  double actual_remaining = 
	-0.0378 * parameters.work_so_far 
	+ 0.1426 * parameters.wait_so_far 
	+ 2001360.7804 * parameters.num_of_wait_locks 
	- 25914.7862 * parameters.total_wait_locks 
	- 0.7298 * parameters.mean_wait_of_all 
	- 189585.3491 * parameters.cpu_usage 
	+ 0.523 * parameters.avg_latency_of_same_past_second 
	+ 52131393.3096;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM43(work_wait &parameters) {
  double actual_remaining = 
	0.0248 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 1899244.268 * parameters.num_of_wait_locks 
	- 24128.7442 * parameters.total_wait_locks 
	- 0.0955 * parameters.mean_wait_of_all 
	- 189585.3491 * parameters.cpu_usage 
	- 0.0008 * parameters.avg_latency_of_same_past_second 
	+ 31761264.5113;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM44(work_wait &parameters) {
  double actual_remaining = 
	0.1464 * parameters.work_so_far 
	- 0.0717 * parameters.wait_so_far 
	+ 165531.5817 * parameters.num_of_wait_locks 
	+ 1768.8658 * parameters.total_wait_locks 
	- 0.0539 * parameters.mean_wait_of_all 
	- 189585.3491 * parameters.cpu_usage 
	- 0.0008 * parameters.avg_latency_of_same_past_second 
	+ 36169922.6241;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM45(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.0258 * parameters.wait_so_far 
	+ 648595.5517 * parameters.num_of_wait_locks 
	+ 60334.531 * parameters.total_wait_locks 
	- 1.5457 * parameters.mean_wait_of_all 
	- 25200488.0671 * parameters.cpu_usage 
	+ 0.4115 * parameters.avg_latency_of_same_past_second 
	+ 80272567.567;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM46(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.0143 * parameters.wait_so_far 
	- 4596394.059 * parameters.num_of_wait_locks 
	+ 34210.505 * parameters.total_wait_locks 
	+ 0.0003 * parameters.mean_wait_of_all 
	- 25200488.0671 * parameters.cpu_usage 
	+ 0.4401 * parameters.avg_latency_of_same_past_second 
	+ 60578463.3243;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM47(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.0753 * parameters.wait_so_far 
	+ 648595.5517 * parameters.num_of_wait_locks 
	- 123244.9218 * parameters.total_wait_locks 
	+ 0.0003 * parameters.mean_wait_of_all 
	- 25200488.0671 * parameters.cpu_usage 
	+ 0.6871 * parameters.avg_latency_of_same_past_second 
	+ 92496665.2498;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM48(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.0753 * parameters.wait_so_far 
	+ 648595.5517 * parameters.num_of_wait_locks 
	- 123244.9218 * parameters.total_wait_locks 
	+ 0.0003 * parameters.mean_wait_of_all 
	- 25200488.0671 * parameters.cpu_usage 
	+ 0.6871 * parameters.avg_latency_of_same_past_second 
	+ 90316254.8177;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM49(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.0923 * parameters.wait_so_far 
	+ 648595.5517 * parameters.num_of_wait_locks 
	- 166982.5404 * parameters.total_wait_locks 
	+ 0.0003 * parameters.mean_wait_of_all 
	- 25200488.0671 * parameters.cpu_usage 
	+ 0.6871 * parameters.avg_latency_of_same_past_second 
	+ 96165683.787;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM50(work_wait &parameters) {
  double actual_remaining = 
	-0.6655 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 5543058.1113 * parameters.num_of_wait_locks 
	+ 1990.8728 * parameters.total_wait_locks 
	+ 0.0003 * parameters.mean_wait_of_all 
	- 11745222.4877 * parameters.cpu_usage 
	- 0.0026 * parameters.avg_latency_of_same_past_second 
	+ 15961307.5626;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM51(work_wait &parameters) {
  double actual_remaining = 
	6.5008 * parameters.work_so_far 
	- 0.001 * parameters.wait_so_far 
	+ 3423368.8922 * parameters.num_of_wait_locks 
	- 46272.2156 * parameters.total_wait_locks 
	+ 0.1461 * parameters.mean_wait_of_all 
	- 11507543.4655 * parameters.cpu_usage 
	- 0.0152 * parameters.avg_latency_of_same_past_second 
	+ 25868876.6029;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM52(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.001 * parameters.wait_so_far 
	+ 490823.5722 * parameters.num_of_wait_locks 
	- 2143.1157 * parameters.total_wait_locks 
	+ 0.0805 * parameters.mean_wait_of_all 
	- 11507543.4655 * parameters.cpu_usage 
	- 0.009 * parameters.avg_latency_of_same_past_second 
	+ 25818755.3023;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM53(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.0182 * parameters.wait_so_far 
	+ 503511.6313 * parameters.num_of_wait_locks 
	+ 1255.1945 * parameters.total_wait_locks 
	+ 0.066 * parameters.mean_wait_of_all 
	- 631394641.5958 * parameters.cpu_usage 
	- 0.3263 * parameters.avg_latency_of_same_past_second 
	+ 739527894.2046;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM54(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	+ 0.0013 * parameters.wait_so_far 
	+ 115327.5268 * parameters.num_of_wait_locks 
	+ 262009.2214 * parameters.total_wait_locks 
	+ 0.1009 * parameters.mean_wait_of_all 
	- 6053851141.6568 * parameters.cpu_usage 
	- 0.0459 * parameters.avg_latency_of_same_past_second 
	+ 5831849918.9736;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM55(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	+ 0.0013 * parameters.wait_so_far 
	+ 115327.5268 * parameters.num_of_wait_locks 
	+ 11671.5961 * parameters.total_wait_locks 
	+ 0.1009 * parameters.mean_wait_of_all 
	- 670939841.9138 * parameters.cpu_usage 
	- 0.0506 * parameters.avg_latency_of_same_past_second 
	+ 681903802.5619;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM56(work_wait &parameters) {
  double actual_remaining = 
	0.1232 * parameters.work_so_far 
	+ 0.0012 * parameters.wait_so_far 
	+ 3844886.6979 * parameters.num_of_wait_locks 
	+ 25337.824 * parameters.total_wait_locks 
	+ 0.1009 * parameters.mean_wait_of_all 
	- 102358749.6775 * parameters.cpu_usage 
	- 0.0153 * parameters.avg_latency_of_same_past_second 
	+ 98284435.6383;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM57(work_wait &parameters) {
  double actual_remaining = 
	0.2948 * parameters.work_so_far 
	+ 0.0012 * parameters.wait_so_far 
	+ 888433.519 * parameters.num_of_wait_locks 
	+ 27441.3089 * parameters.total_wait_locks 
	- 0.6541 * parameters.mean_wait_of_all 
	+ 437705961.9332 * parameters.cpu_usage 
	- 0.0153 * parameters.avg_latency_of_same_past_second 
	- 391598572.2793;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM58(work_wait &parameters) {
  double actual_remaining = 
	0.3802 * parameters.work_so_far 
	+ 0.0012 * parameters.wait_so_far 
	+ 888433.519 * parameters.num_of_wait_locks 
	+ 27441.3089 * parameters.total_wait_locks 
	+ 42.8082 * parameters.mean_wait_of_all 
	+ 737741912.8281 * parameters.cpu_usage 
	- 0.0153 * parameters.avg_latency_of_same_past_second 
	- 2403710736.7917;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM59(work_wait &parameters) {
  double actual_remaining = 
	-0.9538 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 8045607.3727 * parameters.num_of_wait_locks 
	+ 2711.2912 * parameters.total_wait_locks 
	- 49.9055 * parameters.mean_wait_of_all 
	- 120439154.6661 * parameters.cpu_usage 
	+ 0.3959 * parameters.avg_latency_of_same_past_second 
	+ 2711074039.0013;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM60(work_wait &parameters) {
  double actual_remaining = 
	-0.9538 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 9792163.8677 * parameters.num_of_wait_locks 
	+ 2711.2912 * parameters.total_wait_locks 
	- 67.4754 * parameters.mean_wait_of_all 
	- 120439154.6661 * parameters.cpu_usage 
	+ 0.5206 * parameters.avg_latency_of_same_past_second 
	+ 3599949375.6352;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM61(work_wait &parameters) {
  double actual_remaining = 
	-0.6779 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 2139444.7293 * parameters.num_of_wait_locks 
	+ 2711.2912 * parameters.total_wait_locks 
	- 4.9399 * parameters.mean_wait_of_all 
	+ 1157997896.5934 * parameters.cpu_usage 
	- 0.1375 * parameters.avg_latency_of_same_past_second 
	- 842477246.5362;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM62(work_wait &parameters) {
  double actual_remaining = 
	-0.6779 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 2139444.7293 * parameters.num_of_wait_locks 
	+ 2711.2912 * parameters.total_wait_locks 
	- 6.3938 * parameters.mean_wait_of_all 
	+ 1014887945.4695 * parameters.cpu_usage 
	- 0.141 * parameters.avg_latency_of_same_past_second 
	- 637226699.4306;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM63(work_wait &parameters) {
  double actual_remaining = 
	-0.6779 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 2139444.7293 * parameters.num_of_wait_locks 
	+ 2711.2912 * parameters.total_wait_locks 
	+ 0.294 * parameters.mean_wait_of_all 
	+ 167280969.0419 * parameters.cpu_usage 
	+ 0.0242 * parameters.avg_latency_of_same_past_second 
	- 146075257.529;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM64(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 184047.446 * parameters.num_of_wait_locks 
	+ 1813.161 * parameters.total_wait_locks 
	- 0.2751 * parameters.mean_wait_of_all 
	- 9682484.7719 * parameters.cpu_usage 
	- 0.0363 * parameters.avg_latency_of_same_past_second 
	+ 48548034.7384;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM65(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 211643.634 * parameters.num_of_wait_locks 
	+ 1813.161 * parameters.total_wait_locks 
	+ 0.0003 * parameters.mean_wait_of_all 
	- 9682484.7719 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_latency_of_same_past_second 
	+ 34112964.5117;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM66(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 2090052.9821 * parameters.num_of_wait_locks 
	+ 9977.0481 * parameters.total_wait_locks 
	+ 0.0007 * parameters.mean_wait_of_all 
	+ 16800327.4489 * parameters.cpu_usage 
	- 0.0192 * parameters.avg_latency_of_same_past_second 
	- 8590324.4925;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM67(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 557102.6517 * parameters.num_of_wait_locks 
	+ 4471.3617 * parameters.total_wait_locks 
	+ 0.0007 * parameters.mean_wait_of_all 
	+ 16800327.4489 * parameters.cpu_usage 
	- 0.036 * parameters.avg_latency_of_same_past_second 
	+ 10204886.0757;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM68(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 166749.9191 * parameters.num_of_wait_locks 
	+ 39797.5428 * parameters.total_wait_locks 
	+ 0.017 * parameters.mean_wait_of_all 
	- 13331489.5645 * parameters.cpu_usage 
	+ 0.004 * parameters.avg_latency_of_same_past_second 
	+ 20323334.7109;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM69(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 166749.9191 * parameters.num_of_wait_locks 
	- 211466.9853 * parameters.total_wait_locks 
	+ 0.2462 * parameters.mean_wait_of_all 
	- 13331489.5645 * parameters.cpu_usage 
	+ 0.004 * parameters.avg_latency_of_same_past_second 
	+ 17338435.7377;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM70(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 166749.9191 * parameters.num_of_wait_locks 
	- 342438.9885 * parameters.total_wait_locks 
	+ 0.3644 * parameters.mean_wait_of_all 
	- 13331489.5645 * parameters.cpu_usage 
	+ 0.004 * parameters.avg_latency_of_same_past_second 
	+ 10030205.1609;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM71(work_wait &parameters) {
  double actual_remaining = 
	0.7154 * parameters.work_so_far 
	- 0.0178 * parameters.wait_so_far 
	+ 166749.9191 * parameters.num_of_wait_locks 
	+ 149207.3759 * parameters.total_wait_locks 
	+ 0.0421 * parameters.mean_wait_of_all 
	- 13331489.5645 * parameters.cpu_usage 
	+ 0.004 * parameters.avg_latency_of_same_past_second 
	+ 22263917.4722;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM72(work_wait &parameters) {
  double actual_remaining = 
	0.1982 * parameters.work_so_far 
	+ 0.0023 * parameters.wait_so_far 
	+ 166749.9191 * parameters.num_of_wait_locks 
	+ 267160.6996 * parameters.total_wait_locks 
	+ 2.7047 * parameters.mean_wait_of_all 
	- 790766323.7381 * parameters.cpu_usage 
	+ 0.0022 * parameters.avg_latency_of_same_past_second 
	+ 554137762.9133;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM73(work_wait &parameters) {
  double actual_remaining = 
	0.1982 * parameters.work_so_far 
	+ 0.0023 * parameters.wait_so_far 
	+ 166749.9191 * parameters.num_of_wait_locks 
	+ 121023.6836 * parameters.total_wait_locks 
	+ 38.663 * parameters.mean_wait_of_all 
	- 645139333.9186 * parameters.cpu_usage 
	+ 0.0022 * parameters.avg_latency_of_same_past_second 
	- 1897098938.6368;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM74(work_wait &parameters) {
  double actual_remaining = 
	0.1583 * parameters.work_so_far 
	+ 0.0266 * parameters.wait_so_far 
	+ 166749.9191 * parameters.num_of_wait_locks 
	- 27018.3612 * parameters.total_wait_locks 
	- 0.0575 * parameters.mean_wait_of_all 
	- 6361853.3691 * parameters.cpu_usage 
	+ 0.0022 * parameters.avg_latency_of_same_past_second 
	+ 38901797.0439;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM75(work_wait &parameters) {
  double actual_remaining = 
	0.1583 * parameters.work_so_far 
	+ 0.0272 * parameters.wait_so_far 
	+ 2066481.9061 * parameters.num_of_wait_locks 
	- 96880.6656 * parameters.total_wait_locks 
	- 0.0575 * parameters.mean_wait_of_all 
	- 6361853.3691 * parameters.cpu_usage 
	+ 0.0022 * parameters.avg_latency_of_same_past_second 
	+ 53036874.2469;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM76(work_wait &parameters) {
  double actual_remaining = 
	0.1583 * parameters.work_so_far 
	+ 0.0256 * parameters.wait_so_far 
	+ 3244657.5368 * parameters.num_of_wait_locks 
	- 164855.3561 * parameters.total_wait_locks 
	- 0.0575 * parameters.mean_wait_of_all 
	- 6361853.3691 * parameters.cpu_usage 
	+ 0.0022 * parameters.avg_latency_of_same_past_second 
	+ 76316960.4573;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM77(work_wait &parameters) {
  double actual_remaining = 
	-0.0444 * parameters.work_so_far 
	+ 0.0254 * parameters.wait_so_far 
	+ 3048324.6981 * parameters.num_of_wait_locks 
	- 164855.3561 * parameters.total_wait_locks 
	- 0.0575 * parameters.mean_wait_of_all 
	- 6361853.3691 * parameters.cpu_usage 
	+ 0.0022 * parameters.avg_latency_of_same_past_second 
	+ 77710006.8768;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM78(work_wait &parameters) {
  double actual_remaining = 
	0.1583 * parameters.work_so_far 
	+ 0.0256 * parameters.wait_so_far 
	+ 2433196.9174 * parameters.num_of_wait_locks 
	- 70524.3447 * parameters.total_wait_locks 
	- 0.0575 * parameters.mean_wait_of_all 
	- 6361853.3691 * parameters.cpu_usage 
	+ 0.0022 * parameters.avg_latency_of_same_past_second 
	+ 46418861.0706;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM79(work_wait &parameters) {
  double actual_remaining = 
	0.1583 * parameters.work_so_far 
	+ 0.0162 * parameters.wait_so_far 
	+ 166749.9191 * parameters.num_of_wait_locks 
	+ 205405.7428 * parameters.total_wait_locks 
	- 10.6031 * parameters.mean_wait_of_all 
	- 6361853.3691 * parameters.cpu_usage 
	+ 0.0022 * parameters.avg_latency_of_same_past_second 
	+ 736490846.5648;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM80(work_wait &parameters) {
  double actual_remaining = 
	0.1583 * parameters.work_so_far 
	+ 0.0176 * parameters.wait_so_far 
	+ 166749.9191 * parameters.num_of_wait_locks 
	- 72145.8395 * parameters.total_wait_locks 
	- 10.6031 * parameters.mean_wait_of_all 
	- 6361853.3691 * parameters.cpu_usage 
	+ 0.0022 * parameters.avg_latency_of_same_past_second 
	+ 813966464.6161;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM81(work_wait &parameters) {
  double actual_remaining = 
	0.1583 * parameters.work_so_far 
	+ 0.0162 * parameters.wait_so_far 
	- 1536485.7618 * parameters.num_of_wait_locks 
	- 27018.3612 * parameters.total_wait_locks 
	- 13.114 * parameters.mean_wait_of_all 
	- 6361853.3691 * parameters.cpu_usage 
	+ 0.0022 * parameters.avg_latency_of_same_past_second 
	+ 975779332.3528;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM82(work_wait &parameters) {
  double actual_remaining = 
	0.1583 * parameters.work_so_far 
	+ 0.0162 * parameters.wait_so_far 
	- 1536485.7618 * parameters.num_of_wait_locks 
	- 27018.3612 * parameters.total_wait_locks 
	- 13.114 * parameters.mean_wait_of_all 
	- 6361853.3691 * parameters.cpu_usage 
	+ 0.0022 * parameters.avg_latency_of_same_past_second 
	+ 975226655.1377;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM83(work_wait &parameters) {
  double actual_remaining = 
	0.1583 * parameters.work_so_far 
	+ 0.0018 * parameters.wait_so_far 
	+ 166749.9191 * parameters.num_of_wait_locks 
	- 13892.9083 * parameters.total_wait_locks 
	- 0.0379 * parameters.mean_wait_of_all 
	- 6361853.3691 * parameters.cpu_usage 
	+ 0.0022 * parameters.avg_latency_of_same_past_second 
	+ 39653930.2579;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM84(work_wait &parameters) {
  double actual_remaining = 
	-60.2475 * parameters.work_so_far 
	+ 0.0018 * parameters.wait_so_far 
	+ 166749.9191 * parameters.num_of_wait_locks 
	- 13892.9083 * parameters.total_wait_locks 
	- 74.7638 * parameters.mean_wait_of_all 
	- 6361853.3691 * parameters.cpu_usage 
	+ 0.0022 * parameters.avg_latency_of_same_past_second 
	+ 5111143982.8657;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM85(work_wait &parameters) {
  double actual_remaining = 
	-274.9813 * parameters.work_so_far 
	+ 0.0018 * parameters.wait_so_far 
	+ 166749.9191 * parameters.num_of_wait_locks 
	- 13892.9083 * parameters.total_wait_locks 
	- 74.7638 * parameters.mean_wait_of_all 
	- 6361853.3691 * parameters.cpu_usage 
	+ 0.0022 * parameters.avg_latency_of_same_past_second 
	+ 5117973207.3395;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM86(work_wait &parameters) {
  double actual_remaining = 
	0.1583 * parameters.work_so_far 
	+ 0.0018 * parameters.wait_so_far 
	+ 166749.9191 * parameters.num_of_wait_locks 
	- 13892.9083 * parameters.total_wait_locks 
	- 107.9753 * parameters.mean_wait_of_all 
	- 6361853.3691 * parameters.cpu_usage 
	+ 0.0022 * parameters.avg_latency_of_same_past_second 
	+ 7359203463.7505;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM87(work_wait &parameters) {
  double actual_remaining = 
	0.1583 * parameters.work_so_far 
	+ 0.0018 * parameters.wait_so_far 
	+ 166749.9191 * parameters.num_of_wait_locks 
	- 13892.9083 * parameters.total_wait_locks 
	- 0.0379 * parameters.mean_wait_of_all 
	- 6361853.3691 * parameters.cpu_usage 
	+ 0.0022 * parameters.avg_latency_of_same_past_second 
	+ 35474072.2102;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM88(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 56379.906 * parameters.num_of_wait_locks 
	+ 1133.7695 * parameters.total_wait_locks 
	- 0.014 * parameters.mean_wait_of_all 
	- 189585.3491 * parameters.cpu_usage 
	- 0.0357 * parameters.avg_latency_of_same_past_second 
	+ 36292037.5463;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
payment_estimate(work_wait &parameters){

  if (parameters.work_so_far <= 13351) {

    if (parameters.work_so_far <= 8015.5) {
      return payment_LM1(parameters);
    } else {

      if (parameters.wait_so_far <= 82561888.5) {

        if (parameters.cpu_usage <= 0.918) {

          if (parameters.mean_wait_of_all <= 45596600) {
            return payment_LM2(parameters);
          } else {

            if (parameters.total_wait_locks <= 232.5) {

              if (parameters.cpu_usage <= 0.854) {

                if (parameters.total_wait_locks <= 39) {
                  return payment_LM3(parameters);
                } else {
                  return payment_LM4(parameters);
                }
              } else {

                if (parameters.work_so_far <= 9055) {

                  if (parameters.total_wait_locks <= 31) {
                    return payment_LM5(parameters);
                  } else {

                    if (parameters.wait_so_far <= 10856393.5) {
                      return payment_LM6(parameters);
                    } else {

                      if (parameters.work_so_far <= 8790.5) {
                        return payment_LM7(parameters);
                      } else {
                        return payment_LM8(parameters);
                      }
                    }
                  }
                } else {
                  return payment_LM9(parameters);
                }
              }
            } else {

              if (parameters.total_wait_locks <= 264.5) {
                return payment_LM10(parameters);
              } else {
                return payment_LM11(parameters);
              }
            }
          }
        } else {
          return payment_LM12(parameters);
        }
      } else {

        if (parameters.wait_so_far <= 170806174) {
          return payment_LM13(parameters);
        } else {

          if (parameters.work_so_far <= 9331.5) {
            return payment_LM14(parameters);
          } else {
            return payment_LM15(parameters);
          }
        }
      }
    }
  } else {

    if (parameters.cpu_usage <= 0.923) {

      if (parameters.mean_wait_of_all <= 57371650) {

        if (parameters.cpu_usage <= 0.85) {

          if (parameters.total_wait_locks <= 212.5) {

            if (parameters.total_wait_locks <= 104.5) {

              if (parameters.mean_wait_of_all <= 35654600) {

                if (parameters.cpu_usage <= 0.82) {
                  return payment_LM16(parameters);
                } else {
                  return payment_LM17(parameters);
                }
              } else {
                return payment_LM18(parameters);
              }
            } else {

              if (parameters.cpu_usage <= 0.841) {
                return payment_LM19(parameters);
              } else {

                if (parameters.mean_wait_of_all <= 41435800) {

                  if (parameters.mean_wait_of_all <= 40300100) {
                    return payment_LM20(parameters);
                  } else {
                    return payment_LM21(parameters);
                  }
                } else {
                  return payment_LM22(parameters);
                }
              }
            }
          } else {

            if (parameters.avg_latency_of_same_past_second <= 78174300) {
              return payment_LM23(parameters);
            } else {
              return payment_LM24(parameters);
            }
          }
        } else {
          return payment_LM25(parameters);
        }
      } else {

        if (parameters.cpu_usage <= 0.898) {
          return payment_LM26(parameters);
        } else {

          if (parameters.avg_latency_of_same_past_second <= 318040000) {

            if (parameters.avg_latency_of_same_past_second <= 100172550) {

              if (parameters.avg_latency_of_same_past_second <= 96952400) {
                return payment_LM27(parameters);
              } else {

                if (parameters.total_wait_locks <= 250.5) {
                  return payment_LM28(parameters);
                } else {
                  return payment_LM29(parameters);
                }
              }
            } else {

              if (parameters.wait_so_far <= 43565802.5) {

                if (parameters.avg_latency_of_same_past_second <= 161016500) {
                  return payment_LM30(parameters);
                } else {
                  return payment_LM31(parameters);
                }
              } else {
                return payment_LM32(parameters);
              }
            }
          } else {

            if (parameters.avg_latency_of_same_past_second <= 361488500) {

              if (parameters.mean_wait_of_all <= 67513450) {
                return payment_LM33(parameters);
              } else {
                return payment_LM34(parameters);
              }
            } else {
              return payment_LM35(parameters);
            }
          }
        }
      }
    } else {

      if (parameters.wait_so_far <= 123892473.5) {

        if (parameters.work_so_far <= 37783.5) {
          return payment_LM36(parameters);
        } else {

          if (parameters.avg_latency_of_same_past_second <= 163801000) {

            if (parameters.avg_latency_of_same_past_second <= 85274000) {

              if (parameters.cpu_usage <= 0.948) {
                return payment_LM37(parameters);
              } else {

                if (parameters.mean_wait_of_all <= 51677700) {

                  if (parameters.mean_wait_of_all <= 37690900) {
                    return payment_LM38(parameters);
                  } else {

                    if (parameters.mean_wait_of_all <= 37703000) {
                      return payment_LM39(parameters);
                    } else {

                      if (parameters.total_wait_locks <= 167.5) {
                        return payment_LM40(parameters);
                      } else {
                        return payment_LM41(parameters);
                      }
                    }
                  }
                } else {
                  return payment_LM42(parameters);
                }
              }
            } else {
              return payment_LM43(parameters);
            }
          } else {
            return payment_LM44(parameters);
          }
        }
      } else {

        if (parameters.avg_latency_of_same_past_second <= 367598000) {

          if (parameters.mean_wait_of_all <= 61657900) {

            if (parameters.avg_latency_of_same_past_second <= 160939000) {

              if (parameters.avg_latency_of_same_past_second <= 72894250) {

                if (parameters.mean_wait_of_all <= 36911450) {
                  return payment_LM45(parameters);
                } else {

                  if (parameters.avg_latency_of_same_past_second <= 67112400) {
                    return payment_LM46(parameters);
                  } else {

                    if (parameters.wait_so_far <= 344465524.5) {

                      if (parameters.total_wait_locks <= 104) {
                        return payment_LM47(parameters);
                      } else {
                        return payment_LM48(parameters);
                      }
                    } else {
                      return payment_LM49(parameters);
                    }
                  }
                }
              } else {
                return payment_LM50(parameters);
              }
            } else {

              if (parameters.cpu_usage <= 0.961) {

                if (parameters.total_wait_locks <= 296.5) {

                  if (parameters.avg_latency_of_same_past_second <= 222799500) {
                    return payment_LM51(parameters);
                  } else {
                    return payment_LM52(parameters);
                  }
                } else {
                  return payment_LM53(parameters);
                }
              } else {

                if (parameters.cpu_usage <= 0.997) {

                  if (parameters.mean_wait_of_all <= 43353700) {

                    if (parameters.cpu_usage <= 0.969) {

                      if (parameters.avg_latency_of_same_past_second <= 270987000) {
                        return payment_LM54(parameters);
                      } else {
                        return payment_LM55(parameters);
                      }
                    } else {

                      if (parameters.total_wait_locks <= 230.5) {
                        return payment_LM56(parameters);
                      } else {

                        if (parameters.cpu_usage <= 0.995) {
                          return payment_LM57(parameters);
                        } else {
                          return payment_LM58(parameters);
                        }
                      }
                    }
                  } else {

                    if (parameters.cpu_usage <= 0.969) {

                      if (parameters.avg_latency_of_same_past_second <= 362500500) {
                        return payment_LM59(parameters);
                      } else {
                        return payment_LM60(parameters);
                      }
                    } else {

                      if (parameters.wait_so_far <= 224468494.5) {

                        if (parameters.mean_wait_of_all <= 45621750) {
                          return payment_LM61(parameters);
                        } else {
                          return payment_LM62(parameters);
                        }
                      } else {
                        return payment_LM63(parameters);
                      }
                    }
                  }
                } else {

                  if (parameters.avg_latency_of_same_past_second <= 297652500) {
                    return payment_LM64(parameters);
                  } else {
                    return payment_LM65(parameters);
                  }
                }
              }
            }
          } else {

            if (parameters.cpu_usage <= 0.959) {

              if (parameters.wait_so_far <= 187291374.5) {
                return payment_LM66(parameters);
              } else {
                return payment_LM67(parameters);
              }
            } else {

              if (parameters.avg_latency_of_same_past_second <= 224123500) {

                if (parameters.mean_wait_of_all <= 145936000) {
                  return payment_LM68(parameters);
                } else {

                  if (parameters.avg_latency_of_same_past_second <= 190179500) {

                    if (parameters.mean_wait_of_all <= 226005500) {
                      return payment_LM69(parameters);
                    } else {
                      return payment_LM70(parameters);
                    }
                  } else {
                    return payment_LM71(parameters);
                  }
                }
              } else {

                if (parameters.mean_wait_of_all <= 67670150) {

                  if (parameters.mean_wait_of_all <= 65041800) {
                    return payment_LM72(parameters);
                  } else {
                    return payment_LM73(parameters);
                  }
                } else {

                  if (parameters.avg_latency_of_same_past_second <= 317447000) {

                    if (parameters.mean_wait_of_all <= 68842400) {

                      if (parameters.mean_wait_of_all <= 68433800) {
                        return payment_LM74(parameters);
                      } else {

                        if (parameters.total_wait_locks <= 320) {
                          return payment_LM75(parameters);
                        } else {

                          if (parameters.total_wait_locks <= 331.5) {

                            if (parameters.num_of_wait_locks <= 3.5) {
                              return payment_LM76(parameters);
                            } else {
                              return payment_LM77(parameters);
                            }
                          } else {
                            return payment_LM78(parameters);
                          }
                        }
                      }
                    } else {

                      if (parameters.mean_wait_of_all <= 70080650) {

                        if (parameters.total_wait_locks <= 322) {
                          return payment_LM79(parameters);
                        } else {
                          return payment_LM80(parameters);
                        }
                      } else {

                        if (parameters.num_of_wait_locks <= 4.5) {
                          return payment_LM81(parameters);
                        } else {
                          return payment_LM82(parameters);
                        }
                      }
                    }
                  } else {

                    if (parameters.mean_wait_of_all <= 67820350) {

                      if (parameters.mean_wait_of_all <= 67767050) {
                        return payment_LM83(parameters);
                      } else {

                        if (parameters.mean_wait_of_all <= 67803950) {

                          if (parameters.work_so_far <= 31766.5) {
                            return payment_LM84(parameters);
                          } else {
                            return payment_LM85(parameters);
                          }
                        } else {
                          return payment_LM86(parameters);
                        }
                      }
                    } else {
                      return payment_LM87(parameters);
                    }
                  }
                }
              }
            }
          }
        } else {
          return payment_LM88(parameters);
        }
      }
    }
  }
}
static
double
stock_level_LM1(work_wait &parameters) {
  double actual_remaining = 
	1.1495 * parameters.work_so_far 
	- 12695623.8608;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
stock_level_estimate(work_wait &parameters){
  return stock_level_LM1(parameters);
}
static
double
tpcc_LM1(work_wait &parameters) {
  double actual_remaining = 
	780.6358 * parameters.work_so_far 
	+ 0.0393 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 43209.4151 * parameters.num_of_wait_locks 
	+ 9466.014 * parameters.total_wait_locks 
	+ 0.0005 * parameters.mean_wait_of_all 
	- 1026586.6601 * parameters.cpu_usage 
	+ 0.0004 * parameters.avg_latency_of_same_past_second 
	- 93016.5605;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM2(work_wait &parameters) {
  double actual_remaining = 
	1426.0071 * parameters.work_so_far 
	+ 0.0784 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 67553.7774 * parameters.num_of_wait_locks 
	+ 446.0095 * parameters.total_wait_locks 
	+ 0.0093 * parameters.mean_wait_of_all 
	- 2361675.4683 * parameters.cpu_usage 
	+ 0.0004 * parameters.avg_latency_of_same_past_second 
	- 2079223.838;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM3(work_wait &parameters) {
  double actual_remaining = 
	49.9373 * parameters.work_so_far 
	+ 0.0103 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 67553.7774 * parameters.num_of_wait_locks 
	+ 70954.7712 * parameters.total_wait_locks 
	+ 0.0171 * parameters.mean_wait_of_all 
	+ 25097972.7919 * parameters.cpu_usage 
	+ 0.0004 * parameters.avg_latency_of_same_past_second 
	- 14325804.0491;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM4(work_wait &parameters) {
  double actual_remaining = 
	49.9373 * parameters.work_so_far 
	+ 0.0103 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 67553.7774 * parameters.num_of_wait_locks 
	+ 70954.7712 * parameters.total_wait_locks 
	+ 0.0171 * parameters.mean_wait_of_all 
	- 14781433.9131 * parameters.cpu_usage 
	+ 0.0004 * parameters.avg_latency_of_same_past_second 
	+ 20239999.0812;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM5(work_wait &parameters) {
  double actual_remaining = 
	49.9373 * parameters.work_so_far 
	+ 0.3622 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 67553.7774 * parameters.num_of_wait_locks 
	+ 446.0095 * parameters.total_wait_locks 
	+ 0.3821 * parameters.mean_wait_of_all 
	+ 18907558.0117 * parameters.cpu_usage 
	+ 0.0004 * parameters.avg_latency_of_same_past_second 
	- 28301228.2571;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM6(work_wait &parameters) {
  double actual_remaining = 
	49.9373 * parameters.work_so_far 
	+ 0.546 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 67553.7774 * parameters.num_of_wait_locks 
	+ 446.0095 * parameters.total_wait_locks 
	+ 0.5011 * parameters.mean_wait_of_all 
	+ 18907558.0117 * parameters.cpu_usage 
	+ 0.0004 * parameters.avg_latency_of_same_past_second 
	- 36765721.8272;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM7(work_wait &parameters) {
  double actual_remaining = 
	6504.6054 * parameters.work_so_far 
	+ 0.4805 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 67553.7774 * parameters.num_of_wait_locks 
	+ 446.0095 * parameters.total_wait_locks 
	+ 0.4511 * parameters.mean_wait_of_all 
	+ 18907558.0117 * parameters.cpu_usage 
	+ 0.0004 * parameters.avg_latency_of_same_past_second 
	- 85438382.7117;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM8(work_wait &parameters) {
  double actual_remaining = 
	8403.0372 * parameters.work_so_far 
	+ 0.4805 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 67553.7774 * parameters.num_of_wait_locks 
	+ 446.0095 * parameters.total_wait_locks 
	+ 0.4511 * parameters.mean_wait_of_all 
	+ 18907558.0117 * parameters.cpu_usage 
	+ 0.0004 * parameters.avg_latency_of_same_past_second 
	- 100203460.4215;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM9(work_wait &parameters) {
  double actual_remaining = 
	49.9373 * parameters.work_so_far 
	+ 0.0103 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 67553.7774 * parameters.num_of_wait_locks 
	+ 446.0095 * parameters.total_wait_locks 
	- 0.0955 * parameters.mean_wait_of_all 
	+ 18907558.0117 * parameters.cpu_usage 
	+ 0.0004 * parameters.avg_latency_of_same_past_second 
	+ 9810604.0408;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM10(work_wait &parameters) {
  double actual_remaining = 
	49.9373 * parameters.work_so_far 
	+ 0.0103 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 67553.7774 * parameters.num_of_wait_locks 
	+ 150927.4843 * parameters.total_wait_locks 
	- 0.3013 * parameters.mean_wait_of_all 
	- 43530870.448 * parameters.cpu_usage 
	+ 0.0004 * parameters.avg_latency_of_same_past_second 
	+ 30700024.2439;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM11(work_wait &parameters) {
  double actual_remaining = 
	49.9373 * parameters.work_so_far 
	+ 0.0103 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 67553.7774 * parameters.num_of_wait_locks 
	+ 272745.821 * parameters.total_wait_locks 
	- 0.5592 * parameters.mean_wait_of_all 
	- 113230944.6528 * parameters.cpu_usage 
	+ 0.0004 * parameters.avg_latency_of_same_past_second 
	+ 80188066.6238;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM12(work_wait &parameters) {
  double actual_remaining = 
	1195.5672 * parameters.work_so_far 
	+ 0.0033 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 67553.7774 * parameters.num_of_wait_locks 
	+ 446.0095 * parameters.total_wait_locks 
	+ 0.003 * parameters.mean_wait_of_all 
	- 2658437.078 * parameters.cpu_usage 
	+ 0.0004 * parameters.avg_latency_of_same_past_second 
	+ 32562.91;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM13(work_wait &parameters) {
  double actual_remaining = 
	15.5299 * parameters.work_so_far 
	+ 0.0024 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 2688845.2992 * parameters.num_of_wait_locks 
	+ 446.0095 * parameters.total_wait_locks 
	+ 0.0021 * parameters.mean_wait_of_all 
	- 1869347.0837 * parameters.cpu_usage 
	+ 0.0004 * parameters.avg_latency_of_same_past_second 
	+ 9210449.6236;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM14(work_wait &parameters) {
  double actual_remaining = 
	15.5299 * parameters.work_so_far 
	+ 0.0025 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 233953.7145 * parameters.num_of_wait_locks 
	+ 446.0095 * parameters.total_wait_locks 
	+ 0.8743 * parameters.mean_wait_of_all 
	- 26350893.7643 * parameters.cpu_usage 
	+ 0.0004 * parameters.avg_latency_of_same_past_second 
	+ 7296238.3005;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM15(work_wait &parameters) {
  double actual_remaining = 
	2770.8181 * parameters.work_so_far 
	+ 0.0025 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 3593255.6774 * parameters.num_of_wait_locks 
	+ 446.0095 * parameters.total_wait_locks 
	+ 0.0176 * parameters.mean_wait_of_all 
	- 135982878.6581 * parameters.cpu_usage 
	+ 0.0004 * parameters.avg_latency_of_same_past_second 
	+ 97829519.4587;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM16(work_wait &parameters) {
  double actual_remaining = 
	0.0078 * parameters.work_so_far 
	- 0.0008 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 464806.0193 * parameters.num_of_wait_locks 
	+ 25964.1533 * parameters.total_wait_locks 
	- 0.3733 * parameters.mean_wait_of_all 
	+ 393589.7183 * parameters.cpu_usage 
	- 0.0074 * parameters.avg_latency_of_same_past_second 
	+ 46692491.8553;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM17(work_wait &parameters) {
  double actual_remaining = 
	0.0078 * parameters.work_so_far 
	- 0.0008 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 464806.0193 * parameters.num_of_wait_locks 
	+ 25964.1533 * parameters.total_wait_locks 
	- 0.3733 * parameters.mean_wait_of_all 
	+ 393589.7183 * parameters.cpu_usage 
	- 0.0074 * parameters.avg_latency_of_same_past_second 
	+ 33693285.2146;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM18(work_wait &parameters) {
  double actual_remaining = 
	0.0078 * parameters.work_so_far 
	- 0.0008 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 464806.0193 * parameters.num_of_wait_locks 
	+ 25964.1533 * parameters.total_wait_locks 
	- 0.337 * parameters.mean_wait_of_all 
	+ 393589.7183 * parameters.cpu_usage 
	- 0.0074 * parameters.avg_latency_of_same_past_second 
	+ 23630562.7655;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM19(work_wait &parameters) {
  double actual_remaining = 
	0.0078 * parameters.work_so_far 
	- 0.0008 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 538453.0256 * parameters.num_of_wait_locks 
	+ 371803.6959 * parameters.total_wait_locks 
	- 1.5963 * parameters.mean_wait_of_all 
	+ 6953860.6247 * parameters.cpu_usage 
	- 0.236 * parameters.avg_latency_of_same_past_second 
	+ 45588447.6252;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM20(work_wait &parameters) {
  double actual_remaining = 
	0.0078 * parameters.work_so_far 
	- 0.0008 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 940281.1032 * parameters.num_of_wait_locks 
	+ 12971.7103 * parameters.total_wait_locks 
	+ 5.0097 * parameters.mean_wait_of_all 
	+ 16335753.4263 * parameters.cpu_usage 
	+ 0.0227 * parameters.avg_latency_of_same_past_second 
	- 177990079.6586;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM21(work_wait &parameters) {
  double actual_remaining = 
	0.0078 * parameters.work_so_far 
	- 0.0008 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 940281.1032 * parameters.num_of_wait_locks 
	+ 12971.7103 * parameters.total_wait_locks 
	+ 6.8776 * parameters.mean_wait_of_all 
	+ 16335753.4263 * parameters.cpu_usage 
	+ 0.124 * parameters.avg_latency_of_same_past_second 
	- 239866147.7962;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM22(work_wait &parameters) {
  double actual_remaining = 
	-4.2448 * parameters.work_so_far 
	+ 0.0347 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 940281.1032 * parameters.num_of_wait_locks 
	+ 12971.7103 * parameters.total_wait_locks 
	+ 3.9593 * parameters.mean_wait_of_all 
	+ 16335753.4263 * parameters.cpu_usage 
	+ 0.0246 * parameters.avg_latency_of_same_past_second 
	- 161910686.9685;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM23(work_wait &parameters) {
  double actual_remaining = 
	0.0289 * parameters.work_so_far 
	- 0.0019 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 124090.6687 * parameters.num_of_wait_locks 
	+ 279966.0251 * parameters.total_wait_locks 
	- 3.6884 * parameters.mean_wait_of_all 
	+ 8433579.3819 * parameters.cpu_usage 
	+ 0.0032 * parameters.avg_latency_of_same_past_second 
	+ 122387294.6438;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM24(work_wait &parameters) {
  double actual_remaining = 
	0.1224 * parameters.work_so_far 
	- 0.0011 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 124090.6687 * parameters.num_of_wait_locks 
	+ 4645.4804 * parameters.total_wait_locks 
	- 0.8889 * parameters.mean_wait_of_all 
	+ 2998624.0781 * parameters.cpu_usage 
	+ 0.0459 * parameters.avg_latency_of_same_past_second 
	+ 57483894.1145;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM25(work_wait &parameters) {
  double actual_remaining = 
	0.003 * parameters.work_so_far 
	- 0.014 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 1945571.9761 * parameters.num_of_wait_locks 
	+ 47545.5546 * parameters.total_wait_locks 
	- 0.3325 * parameters.mean_wait_of_all 
	- 944775.3753 * parameters.cpu_usage 
	+ 0.0004 * parameters.avg_latency_of_same_past_second 
	+ 29438020.4982;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM26(work_wait &parameters) {
  double actual_remaining = 
	0.0019 * parameters.work_so_far 
	- 0.0005 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	- 2060907.8704 * parameters.num_of_wait_locks 
	+ 38330.333 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 99680159.8722 * parameters.cpu_usage 
	+ 0.0008 * parameters.avg_latency_of_same_past_second 
	+ 111901144.5572;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM27(work_wait &parameters) {
  double actual_remaining = 
	0.0019 * parameters.work_so_far 
	- 0.001 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 32818.1835 * parameters.num_of_wait_locks 
	+ 25172.4563 * parameters.total_wait_locks 
	- 0.1133 * parameters.mean_wait_of_all 
	+ 154475933.796 * parameters.cpu_usage 
	+ 0.0163 * parameters.avg_latency_of_same_past_second 
	- 117916286.0002;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM28(work_wait &parameters) {
  double actual_remaining = 
	0.0019 * parameters.work_so_far 
	- 0.001 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 32818.1835 * parameters.num_of_wait_locks 
	+ 277990.4686 * parameters.total_wait_locks 
	- 0.1133 * parameters.mean_wait_of_all 
	+ 154475933.796 * parameters.cpu_usage 
	+ 0.0163 * parameters.avg_latency_of_same_past_second 
	- 177319686.792;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM29(work_wait &parameters) {
  double actual_remaining = 
	0.0019 * parameters.work_so_far 
	- 0.001 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 32818.1835 * parameters.num_of_wait_locks 
	+ 306371.9232 * parameters.total_wait_locks 
	- 0.1133 * parameters.mean_wait_of_all 
	+ 154475933.796 * parameters.cpu_usage 
	+ 0.0163 * parameters.avg_latency_of_same_past_second 
	- 181898071.2534;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM30(work_wait &parameters) {
  double actual_remaining = 
	0.0019 * parameters.work_so_far 
	- 0.001 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	- 23816345.7952 * parameters.num_of_wait_locks 
	- 242126.4955 * parameters.total_wait_locks 
	+ 1.5917 * parameters.mean_wait_of_all 
	+ 414694848.7627 * parameters.cpu_usage 
	- 0.0577 * parameters.avg_latency_of_same_past_second 
	- 233764216.2138;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM31(work_wait &parameters) {
  double actual_remaining = 
	0.0019 * parameters.work_so_far 
	+ 0.5624 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 32818.1835 * parameters.num_of_wait_locks 
	+ 7737.4757 * parameters.total_wait_locks 
	+ 1.5917 * parameters.mean_wait_of_all 
	+ 14149812.6452 * parameters.cpu_usage 
	- 0.0055 * parameters.avg_latency_of_same_past_second 
	- 81275524.0512;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM32(work_wait &parameters) {
  double actual_remaining = 
	0.0019 * parameters.work_so_far 
	- 0.001 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 32818.1835 * parameters.num_of_wait_locks 
	- 595699.6307 * parameters.total_wait_locks 
	+ 3.2683 * parameters.mean_wait_of_all 
	- 2539919051.8291 * parameters.cpu_usage 
	+ 0.2415 * parameters.avg_latency_of_same_past_second 
	+ 2271635504.4629;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM33(work_wait &parameters) {
  double actual_remaining = 
	0.0019 * parameters.work_so_far 
	- 0.001 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 32818.1835 * parameters.num_of_wait_locks 
	+ 1092576.8009 * parameters.total_wait_locks 
	- 2.3076 * parameters.mean_wait_of_all 
	+ 476112027.3268 * parameters.cpu_usage 
	+ 0.9837 * parameters.avg_latency_of_same_past_second 
	- 920130967.1786;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM34(work_wait &parameters) {
  double actual_remaining = 
	0.0019 * parameters.work_so_far 
	- 0.001 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 32818.1835 * parameters.num_of_wait_locks 
	+ 1765831.8114 * parameters.total_wait_locks 
	- 24692.9647 * parameters.mean_wait_of_all 
	+ 476112027.3268 * parameters.cpu_usage 
	+ 0.9837 * parameters.avg_latency_of_same_past_second 
	+ 1667777249725.93;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM35(work_wait &parameters) {
  double actual_remaining = 
	-1.1863 * parameters.work_so_far 
	- 0.0366 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 32818.1835 * parameters.num_of_wait_locks 
	+ 534436.7094 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	+ 476112027.3268 * parameters.cpu_usage 
	+ 1.6543 * parameters.avg_latency_of_same_past_second 
	- 1019786751.1739;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM36(work_wait &parameters) {
  double actual_remaining = 
	-1.3645 * parameters.work_so_far 
	- 0.042 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 32818.1835 * parameters.num_of_wait_locks 
	+ 534436.7094 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	+ 476112027.3268 * parameters.cpu_usage 
	+ 1.6543 * parameters.avg_latency_of_same_past_second 
	- 1006454954.1457;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM37(work_wait &parameters) {
  double actual_remaining = 
	0.0042 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 43464.8157 * parameters.num_of_wait_locks 
	+ 39936.8898 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 675106.0063 * parameters.cpu_usage 
	- 0 * parameters.avg_latency_of_same_past_second 
	+ 18443980.0241;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM38(work_wait &parameters) {
  double actual_remaining = 
	0.6106 * parameters.work_so_far 
	+ 0.1824 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 2002226.1517 * parameters.num_of_wait_locks 
	- 25782.9947 * parameters.total_wait_locks 
	- 0.3572 * parameters.mean_wait_of_all 
	- 675106.0063 * parameters.cpu_usage 
	+ 0.8289 * parameters.avg_latency_of_same_past_second 
	+ 662829.5481;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM39(work_wait &parameters) {
  double actual_remaining = 
	-0.1479 * parameters.work_so_far 
	+ 0.1423 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 329346.9956 * parameters.num_of_wait_locks 
	- 25782.9947 * parameters.total_wait_locks 
	- 0.5992 * parameters.mean_wait_of_all 
	- 675106.0063 * parameters.cpu_usage 
	+ 0.5226 * parameters.avg_latency_of_same_past_second 
	+ 69408659.2361;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM40(work_wait &parameters) {
  double actual_remaining = 
	-0.1198 * parameters.work_so_far 
	+ 0.1423 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 2002226.1517 * parameters.num_of_wait_locks 
	- 25782.9947 * parameters.total_wait_locks 
	- 0.5992 * parameters.mean_wait_of_all 
	- 675106.0063 * parameters.cpu_usage 
	+ 0.5226 * parameters.avg_latency_of_same_past_second 
	+ 68876468.1564;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM41(work_wait &parameters) {
  double actual_remaining = 
	-0.1198 * parameters.work_so_far 
	+ 0.1423 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 2002226.1517 * parameters.num_of_wait_locks 
	- 25782.9947 * parameters.total_wait_locks 
	- 0.5992 * parameters.mean_wait_of_all 
	- 675106.0063 * parameters.cpu_usage 
	+ 0.5226 * parameters.avg_latency_of_same_past_second 
	+ 66550397.5846;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM42(work_wait &parameters) {
  double actual_remaining = 
	-0.1198 * parameters.work_so_far 
	+ 0.1423 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 2002226.1517 * parameters.num_of_wait_locks 
	- 25782.9947 * parameters.total_wait_locks 
	- 0.5992 * parameters.mean_wait_of_all 
	- 675106.0063 * parameters.cpu_usage 
	+ 0.5226 * parameters.avg_latency_of_same_past_second 
	+ 66874400.5018;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM43(work_wait &parameters) {
  double actual_remaining = 
	-0.0372 * parameters.work_so_far 
	+ 0.1423 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 2002226.1517 * parameters.num_of_wait_locks 
	- 25782.9947 * parameters.total_wait_locks 
	- 0.7288 * parameters.mean_wait_of_all 
	- 675106.0063 * parameters.cpu_usage 
	+ 0.5226 * parameters.avg_latency_of_same_past_second 
	+ 52478540.344;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM44(work_wait &parameters) {
  double actual_remaining = 
	0.0254 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 1900273.9899 * parameters.num_of_wait_locks 
	- 23999.8271 * parameters.total_wait_locks 
	- 0.0955 * parameters.mean_wait_of_all 
	- 675106.0063 * parameters.cpu_usage 
	- 0.0003 * parameters.avg_latency_of_same_past_second 
	+ 32141196.0877;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM45(work_wait &parameters) {
  double actual_remaining = 
	0.1468 * parameters.work_so_far 
	- 0.0717 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 169351.6137 * parameters.num_of_wait_locks 
	+ 1856.1021 * parameters.total_wait_locks 
	- 0.0539 * parameters.mean_wait_of_all 
	- 675106.0063 * parameters.cpu_usage 
	- 0.0003 * parameters.avg_latency_of_same_past_second 
	+ 36542758.7207;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM46(work_wait &parameters) {
  double actual_remaining = 
	0.0019 * parameters.work_so_far 
	- 0.0259 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 651638.1202 * parameters.num_of_wait_locks 
	+ 60327.5093 * parameters.total_wait_locks 
	- 1.5433 * parameters.mean_wait_of_all 
	- 25645755.1256 * parameters.cpu_usage 
	+ 0.4113 * parameters.avg_latency_of_same_past_second 
	+ 80574423.0119;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM47(work_wait &parameters) {
  double actual_remaining = 
	0.0019 * parameters.work_so_far 
	- 0.0144 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	- 4584909.9836 * parameters.num_of_wait_locks 
	+ 34245.5284 * parameters.total_wait_locks 
	+ 0.0002 * parameters.mean_wait_of_all 
	- 25645755.1256 * parameters.cpu_usage 
	+ 0.4399 * parameters.avg_latency_of_same_past_second 
	+ 60912015.2889;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM48(work_wait &parameters) {
  double actual_remaining = 
	0.0019 * parameters.work_so_far 
	- 0.0753 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 651638.1202 * parameters.num_of_wait_locks 
	- 122956.483 * parameters.total_wait_locks 
	+ 0.0002 * parameters.mean_wait_of_all 
	- 25645755.1256 * parameters.cpu_usage 
	+ 0.6864 * parameters.avg_latency_of_same_past_second 
	+ 92778846.7178;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM49(work_wait &parameters) {
  double actual_remaining = 
	0.0019 * parameters.work_so_far 
	- 0.0753 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 651638.1202 * parameters.num_of_wait_locks 
	- 122956.483 * parameters.total_wait_locks 
	+ 0.0002 * parameters.mean_wait_of_all 
	- 25645755.1256 * parameters.cpu_usage 
	+ 0.6864 * parameters.avg_latency_of_same_past_second 
	+ 90601945.5299;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM50(work_wait &parameters) {
  double actual_remaining = 
	0.0019 * parameters.work_so_far 
	- 0.0922 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 651638.1202 * parameters.num_of_wait_locks 
	- 166623.7084 * parameters.total_wait_locks 
	+ 0.0002 * parameters.mean_wait_of_all 
	- 25645755.1256 * parameters.cpu_usage 
	+ 0.6864 * parameters.avg_latency_of_same_past_second 
	+ 96441960.1822;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM51(work_wait &parameters) {
  double actual_remaining = 
	-0.6638 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 5538223.3259 * parameters.num_of_wait_locks 
	+ 2077.7519 * parameters.total_wait_locks 
	+ 0.0002 * parameters.mean_wait_of_all 
	- 12212145.0166 * parameters.cpu_usage 
	- 0.0021 * parameters.avg_latency_of_same_past_second 
	+ 16366668.2542;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM52(work_wait &parameters) {
  double actual_remaining = 
	0.0019 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 2003124.8373 * parameters.num_of_wait_locks 
	+ 1343.2576 * parameters.total_wait_locks 
	+ 0.0002 * parameters.mean_wait_of_all 
	- 1382365.2193 * parameters.cpu_usage 
	- 0.0008 * parameters.avg_latency_of_same_past_second 
	+ 15788155.4934;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM53(work_wait &parameters) {
  double actual_remaining = 
	0.0019 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 1048984.444 * parameters.num_of_wait_locks 
	+ 10051.0738 * parameters.total_wait_locks 
	+ 0.0006 * parameters.mean_wait_of_all 
	+ 16287462.5114 * parameters.cpu_usage 
	- 0.0187 * parameters.avg_latency_of_same_past_second 
	- 3978284.7139;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM54(work_wait &parameters) {
  double actual_remaining = 
	0.0019 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 560292.4728 * parameters.num_of_wait_locks 
	+ 4554.2485 * parameters.total_wait_locks 
	+ 0.0006 * parameters.mean_wait_of_all 
	+ 16287462.5114 * parameters.cpu_usage 
	- 0.0355 * parameters.avg_latency_of_same_past_second 
	+ 10619511.3942;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM55(work_wait &parameters) {
  double actual_remaining = 
	0.0019 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 170567.9902 * parameters.num_of_wait_locks 
	+ 39823.5741 * parameters.total_wait_locks 
	+ 0.0168 * parameters.mean_wait_of_all 
	- 13795859.0884 * parameters.cpu_usage 
	+ 0.0044 * parameters.avg_latency_of_same_past_second 
	+ 20721674.9727;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM56(work_wait &parameters) {
  double actual_remaining = 
	0.0019 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 170567.9902 * parameters.num_of_wait_locks 
	- 211036.5582 * parameters.total_wait_locks 
	+ 0.2457 * parameters.mean_wait_of_all 
	- 13795859.0884 * parameters.cpu_usage 
	+ 0.0044 * parameters.avg_latency_of_same_past_second 
	+ 17741580.0214;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM57(work_wait &parameters) {
  double actual_remaining = 
	0.0019 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 170567.9902 * parameters.num_of_wait_locks 
	- 341797.7696 * parameters.total_wait_locks 
	+ 0.3637 * parameters.mean_wait_of_all 
	- 13795859.0884 * parameters.cpu_usage 
	+ 0.0044 * parameters.avg_latency_of_same_past_second 
	+ 10445111.6183;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM58(work_wait &parameters) {
  double actual_remaining = 
	0.7149 * parameters.work_so_far 
	- 0.0179 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 170567.9902 * parameters.num_of_wait_locks 
	+ 149057.3185 * parameters.total_wait_locks 
	+ 0.0419 * parameters.mean_wait_of_all 
	- 13795859.0884 * parameters.cpu_usage 
	+ 0.0044 * parameters.avg_latency_of_same_past_second 
	+ 22659134.4784;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM59(work_wait &parameters) {
  double actual_remaining = 
	0.1984 * parameters.work_so_far 
	+ 0.0022 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 170567.9902 * parameters.num_of_wait_locks 
	+ 266820.8032 * parameters.total_wait_locks 
	+ 2.7002 * parameters.mean_wait_of_all 
	- 789979456.9409 * parameters.cpu_usage 
	+ 0.0026 * parameters.avg_latency_of_same_past_second 
	+ 553676959.782;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM60(work_wait &parameters) {
  double actual_remaining = 
	0.1984 * parameters.work_so_far 
	+ 0.0022 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 170567.9902 * parameters.num_of_wait_locks 
	+ 120918.9862 * parameters.total_wait_locks 
	+ 38.6006 * parameters.mean_wait_of_all 
	- 644586845.3239 * parameters.cpu_usage 
	+ 0.0026 * parameters.avg_latency_of_same_past_second 
	- 1893614618.3215;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM61(work_wait &parameters) {
  double actual_remaining = 
	0.1586 * parameters.work_so_far 
	+ 0.0017 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 1982595.6187 * parameters.num_of_wait_locks 
	- 26884.7935 * parameters.total_wait_locks 
	- 0.0576 * parameters.mean_wait_of_all 
	- 6837440.1186 * parameters.cpu_usage 
	+ 0.0026 * parameters.avg_latency_of_same_past_second 
	+ 39922127.2437;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM62(work_wait &parameters) {
  double actual_remaining = 
	0.1586 * parameters.work_so_far 
	+ 0.0017 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 3471182.2062 * parameters.num_of_wait_locks 
	- 96634.6585 * parameters.total_wait_locks 
	- 0.0576 * parameters.mean_wait_of_all 
	- 6837440.1186 * parameters.cpu_usage 
	+ 0.0026 * parameters.avg_latency_of_same_past_second 
	+ 56144025.0722;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM63(work_wait &parameters) {
  double actual_remaining = 
	0.1586 * parameters.work_so_far 
	+ 0.0017 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 4557415.6236 * parameters.num_of_wait_locks 
	- 164499.9477 * parameters.total_wait_locks 
	- 0.0576 * parameters.mean_wait_of_all 
	- 6837440.1186 * parameters.cpu_usage 
	+ 0.0026 * parameters.avg_latency_of_same_past_second 
	+ 79182205.0237;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM64(work_wait &parameters) {
  double actual_remaining = 
	-0.0404 * parameters.work_so_far 
	+ 0.0017 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 4361398.7712 * parameters.num_of_wait_locks 
	- 164499.9477 * parameters.total_wait_locks 
	- 0.0576 * parameters.mean_wait_of_all 
	- 6837440.1186 * parameters.cpu_usage 
	+ 0.0026 * parameters.avg_latency_of_same_past_second 
	+ 80491241.2583;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM65(work_wait &parameters) {
  double actual_remaining = 
	0.1586 * parameters.work_so_far 
	+ 0.0017 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 3747261.003 * parameters.num_of_wait_locks 
	- 70320.7567 * parameters.total_wait_locks 
	- 0.0576 * parameters.mean_wait_of_all 
	- 6837440.1186 * parameters.cpu_usage 
	+ 0.0026 * parameters.avg_latency_of_same_past_second 
	+ 49332224.8956;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM66(work_wait &parameters) {
  double actual_remaining = 
	0.1586 * parameters.work_so_far 
	+ 0.0017 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 170567.9902 * parameters.num_of_wait_locks 
	+ 205165.2374 * parameters.total_wait_locks 
	- 10.5862 * parameters.mean_wait_of_all 
	- 6837440.1186 * parameters.cpu_usage 
	+ 0.0026 * parameters.avg_latency_of_same_past_second 
	+ 740813507.4236;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM67(work_wait &parameters) {
  double actual_remaining = 
	0.1586 * parameters.work_so_far 
	+ 0.0017 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 170567.9902 * parameters.num_of_wait_locks 
	- 71939.6417 * parameters.total_wait_locks 
	- 10.5862 * parameters.mean_wait_of_all 
	- 6837440.1186 * parameters.cpu_usage 
	+ 0.0026 * parameters.avg_latency_of_same_past_second 
	+ 818671472.6738;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM68(work_wait &parameters) {
  double actual_remaining = 
	0.1586 * parameters.work_so_far 
	+ 0.0017 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	- 1529926.4315 * parameters.num_of_wait_locks 
	- 26884.7935 * parameters.total_wait_locks 
	- 13.093 * parameters.mean_wait_of_all 
	- 6837440.1186 * parameters.cpu_usage 
	+ 0.0026 * parameters.avg_latency_of_same_past_second 
	+ 979716872.2581;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM69(work_wait &parameters) {
  double actual_remaining = 
	0.1586 * parameters.work_so_far 
	+ 0.0017 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	- 1529926.4315 * parameters.num_of_wait_locks 
	- 26884.7935 * parameters.total_wait_locks 
	- 13.093 * parameters.mean_wait_of_all 
	- 6837440.1186 * parameters.cpu_usage 
	+ 0.0026 * parameters.avg_latency_of_same_past_second 
	+ 979165084.5449;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM70(work_wait &parameters) {
  double actual_remaining = 
	0.1586 * parameters.work_so_far 
	+ 0.0017 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 170567.9902 * parameters.num_of_wait_locks 
	- 13780.4652 * parameters.total_wait_locks 
	- 0.038 * parameters.mean_wait_of_all 
	- 6837440.1186 * parameters.cpu_usage 
	+ 0.0026 * parameters.avg_latency_of_same_past_second 
	+ 40021159.0461;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM71(work_wait &parameters) {
  double actual_remaining = 
	-60.15 * parameters.work_so_far 
	+ 0.0017 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 170567.9902 * parameters.num_of_wait_locks 
	- 13780.4652 * parameters.total_wait_locks 
	- 74.6436 * parameters.mean_wait_of_all 
	- 6837440.1186 * parameters.cpu_usage 
	+ 0.0026 * parameters.avg_latency_of_same_past_second 
	+ 5103348942.256;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM72(work_wait &parameters) {
  double actual_remaining = 
	-274.5382 * parameters.work_so_far 
	+ 0.0017 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 170567.9902 * parameters.num_of_wait_locks 
	- 13780.4652 * parameters.total_wait_locks 
	- 74.6436 * parameters.mean_wait_of_all 
	- 6837440.1186 * parameters.cpu_usage 
	+ 0.0026 * parameters.avg_latency_of_same_past_second 
	+ 5110167175.4886;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM73(work_wait &parameters) {
  double actual_remaining = 
	0.1586 * parameters.work_so_far 
	+ 0.0017 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 170567.9902 * parameters.num_of_wait_locks 
	- 13780.4652 * parameters.total_wait_locks 
	- 107.8017 * parameters.mean_wait_of_all 
	- 6837440.1186 * parameters.cpu_usage 
	+ 0.0026 * parameters.avg_latency_of_same_past_second 
	+ 7347790301.6586;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM74(work_wait &parameters) {
  double actual_remaining = 
	0.1586 * parameters.work_so_far 
	+ 0.0017 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 170567.9902 * parameters.num_of_wait_locks 
	- 13780.4652 * parameters.total_wait_locks 
	- 0.038 * parameters.mean_wait_of_all 
	- 6837440.1186 * parameters.cpu_usage 
	+ 0.0026 * parameters.avg_latency_of_same_past_second 
	+ 35848028.2378;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM75(work_wait &parameters) {
  double actual_remaining = 
	0.0019 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 15327.0454 * parameters.num_locks_so_far 
	+ 60375.6113 * parameters.num_of_wait_locks 
	+ 1222.028 * parameters.total_wait_locks 
	- 0.0141 * parameters.mean_wait_of_all 
	- 675106.0063 * parameters.cpu_usage 
	- 0.0352 * parameters.avg_latency_of_same_past_second 
	+ 36664677.106;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM76(work_wait &parameters) {
  double actual_remaining = 
	3497.418 * parameters.work_so_far 
	- 0.0019 * parameters.wait_so_far 
	+ 7471.2309 * parameters.num_locks_so_far 
	+ 6218.0689 * parameters.num_of_wait_locks 
	+ 131172.8539 * parameters.total_wait_locks 
	+ 0.0015 * parameters.mean_wait_of_all 
	- 146639668.5231 * parameters.cpu_usage 
	+ 0.0019 * parameters.avg_latency_of_same_past_second 
	+ 92163396.79;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM77(work_wait &parameters) {
  double actual_remaining = 
	1.5106 * parameters.work_so_far 
	- 0.1706 * parameters.wait_so_far 
	- 2389940.0814 * parameters.num_locks_so_far 
	- 193607.165 * parameters.num_of_wait_locks 
	+ 788004.6701 * parameters.total_wait_locks 
	+ 0.2925 * parameters.mean_wait_of_all 
	- 362150428.4623 * parameters.cpu_usage 
	+ 0.0034 * parameters.avg_latency_of_same_past_second 
	+ 381264894.0705;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM78(work_wait &parameters) {
  double actual_remaining = 
	0.0317 * parameters.work_so_far 
	- 0.0018 * parameters.wait_so_far 
	- 9190.0872 * parameters.num_locks_so_far 
	- 15847770.0935 * parameters.num_of_wait_locks 
	+ 1483662.8361 * parameters.total_wait_locks 
	- 6.7821 * parameters.mean_wait_of_all 
	- 12834788.3228 * parameters.cpu_usage 
	+ 0.0025 * parameters.avg_latency_of_same_past_second 
	+ 235005097.5268;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM79(work_wait &parameters) {
  double actual_remaining = 
	0.0264 * parameters.work_so_far 
	- 0.0018 * parameters.wait_so_far 
	- 9190.0872 * parameters.num_locks_so_far 
	- 22999121.2104 * parameters.num_of_wait_locks 
	+ 651510.0268 * parameters.total_wait_locks 
	- 3.375 * parameters.mean_wait_of_all 
	- 315555877.051 * parameters.cpu_usage 
	+ 0.0025 * parameters.avg_latency_of_same_past_second 
	+ 662400000.3313;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM80(work_wait &parameters) {
  double actual_remaining = 
	0.6767 * parameters.work_so_far 
	- 0.1029 * parameters.wait_so_far 
	+ 4793.1328 * parameters.num_locks_so_far 
	- 26803911.8448 * parameters.num_of_wait_locks 
	+ 270535.1551 * parameters.total_wait_locks 
	+ 0.0003 * parameters.mean_wait_of_all 
	- 315482491.7725 * parameters.cpu_usage 
	+ 0.0017 * parameters.avg_latency_of_same_past_second 
	+ 530613971.323;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
tpcc_estimate(work_wait &parameters){

  if (parameters.num_locks_so_far <= 3) {

    if (parameters.work_so_far <= 13351) {

      if (parameters.work_so_far <= 8015.5) {
        return tpcc_LM1(parameters);
      } else {

        if (parameters.wait_so_far <= 82561888.5) {

          if (parameters.cpu_usage <= 0.918) {

            if (parameters.mean_wait_of_all <= 45596600) {
              return tpcc_LM2(parameters);
            } else {

              if (parameters.total_wait_locks <= 232.5) {

                if (parameters.cpu_usage <= 0.854) {

                  if (parameters.total_wait_locks <= 39) {
                    return tpcc_LM3(parameters);
                  } else {
                    return tpcc_LM4(parameters);
                  }
                } else {

                  if (parameters.work_so_far <= 9055) {

                    if (parameters.total_wait_locks <= 31) {
                      return tpcc_LM5(parameters);
                    } else {

                      if (parameters.wait_so_far <= 10856393.5) {
                        return tpcc_LM6(parameters);
                      } else {

                        if (parameters.work_so_far <= 8790.5) {
                          return tpcc_LM7(parameters);
                        } else {
                          return tpcc_LM8(parameters);
                        }
                      }
                    }
                  } else {
                    return tpcc_LM9(parameters);
                  }
                }
              } else {

                if (parameters.total_wait_locks <= 264.5) {
                  return tpcc_LM10(parameters);
                } else {
                  return tpcc_LM11(parameters);
                }
              }
            }
          } else {
            return tpcc_LM12(parameters);
          }
        } else {

          if (parameters.wait_so_far <= 170806174) {
            return tpcc_LM13(parameters);
          } else {

            if (parameters.work_so_far <= 9331.5) {
              return tpcc_LM14(parameters);
            } else {
              return tpcc_LM15(parameters);
            }
          }
        }
      }
    } else {

      if (parameters.cpu_usage <= 0.923) {

        if (parameters.mean_wait_of_all <= 57371650) {

          if (parameters.cpu_usage <= 0.85) {

            if (parameters.total_wait_locks <= 212.5) {

              if (parameters.total_wait_locks <= 104.5) {

                if (parameters.mean_wait_of_all <= 35654600) {

                  if (parameters.cpu_usage <= 0.82) {
                    return tpcc_LM16(parameters);
                  } else {
                    return tpcc_LM17(parameters);
                  }
                } else {
                  return tpcc_LM18(parameters);
                }
              } else {

                if (parameters.cpu_usage <= 0.841) {
                  return tpcc_LM19(parameters);
                } else {

                  if (parameters.mean_wait_of_all <= 41435800) {

                    if (parameters.mean_wait_of_all <= 40300100) {
                      return tpcc_LM20(parameters);
                    } else {
                      return tpcc_LM21(parameters);
                    }
                  } else {
                    return tpcc_LM22(parameters);
                  }
                }
              }
            } else {

              if (parameters.avg_latency_of_same_past_second <= 78174300) {
                return tpcc_LM23(parameters);
              } else {
                return tpcc_LM24(parameters);
              }
            }
          } else {
            return tpcc_LM25(parameters);
          }
        } else {

          if (parameters.cpu_usage <= 0.898) {
            return tpcc_LM26(parameters);
          } else {

            if (parameters.avg_latency_of_same_past_second <= 318040000) {

              if (parameters.avg_latency_of_same_past_second <= 100172550) {

                if (parameters.avg_latency_of_same_past_second <= 96952400) {
                  return tpcc_LM27(parameters);
                } else {

                  if (parameters.total_wait_locks <= 250.5) {
                    return tpcc_LM28(parameters);
                  } else {
                    return tpcc_LM29(parameters);
                  }
                }
              } else {

                if (parameters.wait_so_far <= 43565802.5) {

                  if (parameters.avg_latency_of_same_past_second <= 161016500) {
                    return tpcc_LM30(parameters);
                  } else {
                    return tpcc_LM31(parameters);
                  }
                } else {
                  return tpcc_LM32(parameters);
                }
              }
            } else {

              if (parameters.avg_latency_of_same_past_second <= 361488500) {

                if (parameters.mean_wait_of_all <= 67513450) {
                  return tpcc_LM33(parameters);
                } else {
                  return tpcc_LM34(parameters);
                }
              } else {

                if (parameters.total_wait_locks <= 316.5) {
                  return tpcc_LM35(parameters);
                } else {
                  return tpcc_LM36(parameters);
                }
              }
            }
          }
        }
      } else {

        if (parameters.wait_so_far <= 123892473.5) {

          if (parameters.work_so_far <= 37783.5) {
            return tpcc_LM37(parameters);
          } else {

            if (parameters.avg_latency_of_same_past_second <= 163801000) {

              if (parameters.avg_latency_of_same_past_second <= 85274000) {

                if (parameters.cpu_usage <= 0.948) {
                  return tpcc_LM38(parameters);
                } else {

                  if (parameters.mean_wait_of_all <= 51677700) {

                    if (parameters.mean_wait_of_all <= 37690900) {
                      return tpcc_LM39(parameters);
                    } else {

                      if (parameters.mean_wait_of_all <= 37703000) {
                        return tpcc_LM40(parameters);
                      } else {

                        if (parameters.total_wait_locks <= 167.5) {
                          return tpcc_LM41(parameters);
                        } else {
                          return tpcc_LM42(parameters);
                        }
                      }
                    }
                  } else {
                    return tpcc_LM43(parameters);
                  }
                }
              } else {
                return tpcc_LM44(parameters);
              }
            } else {
              return tpcc_LM45(parameters);
            }
          }
        } else {

          if (parameters.avg_latency_of_same_past_second <= 367598000) {

            if (parameters.mean_wait_of_all <= 61657900) {

              if (parameters.avg_latency_of_same_past_second <= 160939000) {

                if (parameters.avg_latency_of_same_past_second <= 72894250) {

                  if (parameters.mean_wait_of_all <= 36911450) {
                    return tpcc_LM46(parameters);
                  } else {

                    if (parameters.avg_latency_of_same_past_second <= 67112400) {
                      return tpcc_LM47(parameters);
                    } else {

                      if (parameters.wait_so_far <= 344465524.5) {

                        if (parameters.total_wait_locks <= 104) {
                          return tpcc_LM48(parameters);
                        } else {
                          return tpcc_LM49(parameters);
                        }
                      } else {
                        return tpcc_LM50(parameters);
                      }
                    }
                  }
                } else {
                  return tpcc_LM51(parameters);
                }
              } else {
                return tpcc_LM52(parameters);
              }
            } else {

              if (parameters.cpu_usage <= 0.959) {

                if (parameters.wait_so_far <= 187291374.5) {
                  return tpcc_LM53(parameters);
                } else {
                  return tpcc_LM54(parameters);
                }
              } else {

                if (parameters.avg_latency_of_same_past_second <= 224123500) {

                  if (parameters.mean_wait_of_all <= 145936000) {
                    return tpcc_LM55(parameters);
                  } else {

                    if (parameters.avg_latency_of_same_past_second <= 190179500) {

                      if (parameters.mean_wait_of_all <= 226005500) {
                        return tpcc_LM56(parameters);
                      } else {
                        return tpcc_LM57(parameters);
                      }
                    } else {
                      return tpcc_LM58(parameters);
                    }
                  }
                } else {

                  if (parameters.mean_wait_of_all <= 67670150) {

                    if (parameters.mean_wait_of_all <= 65041800) {
                      return tpcc_LM59(parameters);
                    } else {
                      return tpcc_LM60(parameters);
                    }
                  } else {

                    if (parameters.avg_latency_of_same_past_second <= 317447000) {

                      if (parameters.mean_wait_of_all <= 68842400) {

                        if (parameters.mean_wait_of_all <= 68433800) {
                          return tpcc_LM61(parameters);
                        } else {

                          if (parameters.total_wait_locks <= 320) {
                            return tpcc_LM62(parameters);
                          } else {

                            if (parameters.total_wait_locks <= 331.5) {

                              if (parameters.num_of_wait_locks <= 3.5) {
                                return tpcc_LM63(parameters);
                              } else {
                                return tpcc_LM64(parameters);
                              }
                            } else {
                              return tpcc_LM65(parameters);
                            }
                          }
                        }
                      } else {

                        if (parameters.mean_wait_of_all <= 70080650) {

                          if (parameters.total_wait_locks <= 322) {
                            return tpcc_LM66(parameters);
                          } else {
                            return tpcc_LM67(parameters);
                          }
                        } else {

                          if (parameters.num_of_wait_locks <= 4.5) {
                            return tpcc_LM68(parameters);
                          } else {
                            return tpcc_LM69(parameters);
                          }
                        }
                      }
                    } else {

                      if (parameters.mean_wait_of_all <= 67820350) {

                        if (parameters.mean_wait_of_all <= 67767050) {
                          return tpcc_LM70(parameters);
                        } else {

                          if (parameters.mean_wait_of_all <= 67803950) {

                            if (parameters.work_so_far <= 31766.5) {
                              return tpcc_LM71(parameters);
                            } else {
                              return tpcc_LM72(parameters);
                            }
                          } else {
                            return tpcc_LM73(parameters);
                          }
                        }
                      } else {
                        return tpcc_LM74(parameters);
                      }
                    }
                  }
                }
              }
            }
          } else {
            return tpcc_LM75(parameters);
          }
        }
      }
    }
  } else {

    if (parameters.work_so_far <= 33893) {
      return tpcc_LM76(parameters);
    } else {

      if (parameters.wait_so_far <= 197867896) {

        if (parameters.total_wait_locks <= 182.5) {
          return tpcc_LM77(parameters);
        } else {

          if (parameters.work_so_far <= 50954) {
            return tpcc_LM78(parameters);
          } else {
            return tpcc_LM79(parameters);
          }
        }
      } else {
        return tpcc_LM80(parameters);
      }
    }
  }
}