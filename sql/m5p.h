#include "my_global.h"
#include "trace_tool.h"

static
double
new_order_LM1(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0362 * parameters.wait_so_far 
	- 7001.0951 * parameters.num_locks_so_far 
	+ 1162026.967 * parameters.total_wait_locks 
	- 9.3277 * parameters.mean_wait_of_all 
	+ 0.1188 * parameters.avg_work_of_same_past_second 
	- 0.1578 * parameters.avg_wait_of_same_past_second 
	+ 0.1934 * parameters.avg_latency_of_same_last_20 
	- 0.0112 * parameters.max_latency_of_same_last_50 
	+ 44278330.8237;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM2(work_wait &parameters) {
  double actual_remaining = 
	0.0507 * parameters.work_so_far 
	- 0.2307 * parameters.wait_so_far 
	- 5679.7677 * parameters.num_locks_so_far 
	- 483659.8943 * parameters.total_wait_locks 
	- 1.8575 * parameters.mean_wait_of_all 
	+ 41565752.3958 * parameters.cpu_usage 
	- 0.6383 * parameters.avg_work_of_same_past_second 
	- 0.0547 * parameters.avg_wait_of_same_past_second 
	+ 0.0019 * parameters.avg_latency_of_same_last_20 
	+ 0.0334 * parameters.max_latency_of_same_last_50 
	+ 874482403.9573;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM3(work_wait &parameters) {
  double actual_remaining = 
	0.0507 * parameters.work_so_far 
	- 0.1349 * parameters.wait_so_far 
	- 5679.7677 * parameters.num_locks_so_far 
	- 368264.4919 * parameters.total_wait_locks 
	+ 0.7937 * parameters.mean_wait_of_all 
	+ 41565752.3958 * parameters.cpu_usage 
	- 0.3867 * parameters.avg_work_of_same_past_second 
	- 0.0945 * parameters.avg_wait_of_same_past_second 
	+ 0.0019 * parameters.avg_latency_of_same_last_20 
	+ 0.025 * parameters.max_latency_of_same_last_50 
	+ 450393080.3778;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM4(work_wait &parameters) {
  double actual_remaining = 
	0.0507 * parameters.work_so_far 
	- 0.0037 * parameters.wait_so_far 
	- 5679.7677 * parameters.num_locks_so_far 
	- 450253.4423 * parameters.total_wait_locks 
	+ 11.8348 * parameters.mean_wait_of_all 
	+ 41565752.3958 * parameters.cpu_usage 
	+ 0.039 * parameters.avg_work_of_same_past_second 
	- 0.3169 * parameters.avg_wait_of_same_past_second 
	+ 0.0019 * parameters.avg_latency_of_same_last_20 
	+ 0.029 * parameters.max_latency_of_same_last_50 
	+ 440773827.1336;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM5(work_wait &parameters) {
  double actual_remaining = 
	0.9017 * parameters.work_so_far 
	- 0.0024 * parameters.wait_so_far 
	- 5679.7677 * parameters.num_locks_so_far 
	- 9877.9191 * parameters.total_wait_locks 
	+ 0.7833 * parameters.mean_wait_of_all 
	+ 1150010390.7082 * parameters.cpu_usage 
	+ 0.0265 * parameters.avg_work_of_same_past_second 
	- 0.0391 * parameters.avg_wait_of_same_past_second 
	+ 0.0019 * parameters.avg_latency_of_same_last_20 
	- 0.0503 * parameters.max_latency_of_same_last_50 
	- 652426581.0412;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM6(work_wait &parameters) {
  double actual_remaining = 
	12.405 * parameters.work_so_far 
	- 0.0042 * parameters.wait_so_far 
	- 5679.7677 * parameters.num_locks_so_far 
	- 92361.7153 * parameters.total_wait_locks 
	+ 2.6741 * parameters.mean_wait_of_all 
	+ 2811299.4491 * parameters.cpu_usage 
	+ 4.292 * parameters.avg_work_of_same_past_second 
	- 0.0528 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	- 0.0649 * parameters.max_latency_of_same_last_50 
	- 398777044.6151;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM7(work_wait &parameters) {
  double actual_remaining = 
	0.3157 * parameters.work_so_far 
	- 0.0042 * parameters.wait_so_far 
	- 5679.7677 * parameters.num_locks_so_far 
	- 58510.2254 * parameters.total_wait_locks 
	+ 1.5612 * parameters.mean_wait_of_all 
	+ 2811299.4491 * parameters.cpu_usage 
	+ 0.0584 * parameters.avg_work_of_same_past_second 
	- 0.0528 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	- 0.0011 * parameters.max_latency_of_same_last_50 
	+ 277259217.1165;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM8(work_wait &parameters) {
  double actual_remaining = 
	0.339 * parameters.work_so_far 
	- 1.2192 * parameters.wait_so_far 
	- 5679.7677 * parameters.num_locks_so_far 
	- 185474.1925 * parameters.total_wait_locks 
	+ 4.4562 * parameters.mean_wait_of_all 
	+ 2811299.4491 * parameters.cpu_usage 
	+ 0.1402 * parameters.avg_work_of_same_past_second 
	+ 17.735 * parameters.avg_wait_of_same_past_second 
	+ 0.4539 * parameters.avg_latency_of_same_last_20 
	- 0.4137 * parameters.max_latency_of_same_last_50 
	- 3538324845.3243;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM9(work_wait &parameters) {
  double actual_remaining = 
	0.339 * parameters.work_so_far 
	- 1.2192 * parameters.wait_so_far 
	- 5679.7677 * parameters.num_locks_so_far 
	- 185474.1925 * parameters.total_wait_locks 
	+ 4.4562 * parameters.mean_wait_of_all 
	+ 2811299.4491 * parameters.cpu_usage 
	+ 0.1402 * parameters.avg_work_of_same_past_second 
	+ 18.7945 * parameters.avg_wait_of_same_past_second 
	+ 0.4335 * parameters.avg_latency_of_same_last_20 
	- 0.4137 * parameters.max_latency_of_same_last_50 
	- 3757888987.1864;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM10(work_wait &parameters) {
  double actual_remaining = 
	0.339 * parameters.work_so_far 
	- 1.1357 * parameters.wait_so_far 
	- 5679.7677 * parameters.num_locks_so_far 
	- 185474.1925 * parameters.total_wait_locks 
	+ 4.4562 * parameters.mean_wait_of_all 
	+ 2811299.4491 * parameters.cpu_usage 
	+ 0.1402 * parameters.avg_work_of_same_past_second 
	+ 10.2019 * parameters.avg_wait_of_same_past_second 
	+ 0.553 * parameters.avg_latency_of_same_last_20 
	- 0.3897 * parameters.max_latency_of_same_last_50 
	- 1842748635.5437;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM11(work_wait &parameters) {
  double actual_remaining = 
	0.339 * parameters.work_so_far 
	- 0.0506 * parameters.wait_so_far 
	- 5679.7677 * parameters.num_locks_so_far 
	- 185474.1925 * parameters.total_wait_locks 
	+ 4.4562 * parameters.mean_wait_of_all 
	+ 2811299.4491 * parameters.cpu_usage 
	+ 0.1402 * parameters.avg_work_of_same_past_second 
	- 0.4923 * parameters.avg_wait_of_same_past_second 
	+ 0.0751 * parameters.avg_latency_of_same_last_20 
	- 0.0279 * parameters.max_latency_of_same_last_50 
	+ 454016359.0338;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM12(work_wait &parameters) {
  double actual_remaining = 
	0.339 * parameters.work_so_far 
	- 0.0375 * parameters.wait_so_far 
	- 5679.7677 * parameters.num_locks_so_far 
	- 153053.2879 * parameters.total_wait_locks 
	+ 3.6884 * parameters.mean_wait_of_all 
	+ 2811299.4491 * parameters.cpu_usage 
	+ 0.1402 * parameters.avg_work_of_same_past_second 
	- 0.3801 * parameters.avg_wait_of_same_past_second 
	+ 0.0191 * parameters.avg_latency_of_same_last_20 
	+ 0.0801 * parameters.max_latency_of_same_last_50 
	+ 207051632.7556;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM13(work_wait &parameters) {
  double actual_remaining = 
	0.1145 * parameters.work_so_far 
	- 0.008 * parameters.wait_so_far 
	- 5679.7677 * parameters.num_locks_so_far 
	- 56433.102 * parameters.total_wait_locks 
	- 12.6585 * parameters.mean_wait_of_all 
	+ 2811299.4491 * parameters.cpu_usage 
	- 19.4951 * parameters.avg_work_of_same_past_second 
	- 0.0545 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	+ 4053470096.7099;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM14(work_wait &parameters) {
  double actual_remaining = 
	0.0116 * parameters.work_so_far 
	- 0.0035 * parameters.wait_so_far 
	- 5679.7677 * parameters.num_locks_so_far 
	- 17529.7726 * parameters.total_wait_locks 
	+ 0.4112 * parameters.mean_wait_of_all 
	+ 2811299.4491 * parameters.cpu_usage 
	+ 0.0129 * parameters.avg_work_of_same_past_second 
	- 0.0252 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	+ 221536976.4761;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM15(work_wait &parameters) {
  double actual_remaining = 
	11.567 * parameters.work_so_far 
	- 0.006 * parameters.wait_so_far 
	+ 6224412.9435 * parameters.num_locks_so_far 
	+ 343520.7319 * parameters.total_wait_locks 
	+ 0.1852 * parameters.mean_wait_of_all 
	+ 3471997.3084 * parameters.cpu_usage 
	- 0.4158 * parameters.avg_work_of_same_past_second 
	- 0.0228 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	+ 116377720.7045;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM16(work_wait &parameters) {
  double actual_remaining = 
	8.0351 * parameters.work_so_far 
	- 0.006 * parameters.wait_so_far 
	+ 6224412.9435 * parameters.num_locks_so_far 
	+ 235998.9465 * parameters.total_wait_locks 
	+ 0.1852 * parameters.mean_wait_of_all 
	+ 3471997.3084 * parameters.cpu_usage 
	- 0.4158 * parameters.avg_work_of_same_past_second 
	- 0.0228 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	- 0.1197 * parameters.max_latency_of_same_last_50 
	+ 366489064.325;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM17(work_wait &parameters) {
  double actual_remaining = 
	0.0295 * parameters.work_so_far 
	- 0.006 * parameters.wait_so_far 
	+ 6224412.9435 * parameters.num_locks_so_far 
	+ 172368.0827 * parameters.total_wait_locks 
	- 7.7042 * parameters.mean_wait_of_all 
	+ 3471997.3084 * parameters.cpu_usage 
	- 76.6352 * parameters.avg_work_of_same_past_second 
	- 0.0228 * parameters.avg_wait_of_same_past_second 
	- 0.0555 * parameters.avg_latency_of_same_last_20 
	+ 14329837725.6196;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM18(work_wait &parameters) {
  double actual_remaining = 
	-29.9011 * parameters.work_so_far 
	+ 0.4207 * parameters.wait_so_far 
	+ 6224412.9435 * parameters.num_locks_so_far 
	+ 6000767.5575 * parameters.total_wait_locks 
	- 35.4543 * parameters.mean_wait_of_all 
	+ 3471997.3084 * parameters.cpu_usage 
	- 0.4158 * parameters.avg_work_of_same_past_second 
	- 0.0228 * parameters.avg_wait_of_same_past_second 
	- 0.1268 * parameters.avg_latency_of_same_last_20 
	- 847879522.2919;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM19(work_wait &parameters) {
  double actual_remaining = 
	-31.7319 * parameters.work_so_far 
	+ 0.4468 * parameters.wait_so_far 
	+ 6224412.9435 * parameters.num_locks_so_far 
	+ 3982594.6372 * parameters.total_wait_locks 
	- 35.4543 * parameters.mean_wait_of_all 
	+ 3471997.3084 * parameters.cpu_usage 
	- 0.4158 * parameters.avg_work_of_same_past_second 
	- 0.0228 * parameters.avg_wait_of_same_past_second 
	- 0.1268 * parameters.avg_latency_of_same_last_20 
	- 70536597.1496;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM20(work_wait &parameters) {
  double actual_remaining = 
	-36.1568 * parameters.work_so_far 
	+ 0.5099 * parameters.wait_so_far 
	+ 6224412.9435 * parameters.num_locks_so_far 
	+ 4425818.5865 * parameters.total_wait_locks 
	- 35.4543 * parameters.mean_wait_of_all 
	+ 3471997.3084 * parameters.cpu_usage 
	- 0.4158 * parameters.avg_work_of_same_past_second 
	- 0.0228 * parameters.avg_wait_of_same_past_second 
	- 0.1268 * parameters.avg_latency_of_same_last_20 
	- 178124197.2715;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM21(work_wait &parameters) {
  double actual_remaining = 
	0.0295 * parameters.work_so_far 
	- 0.006 * parameters.wait_so_far 
	+ 6224412.9435 * parameters.num_locks_so_far 
	+ 399142.0169 * parameters.total_wait_locks 
	- 42.2119 * parameters.mean_wait_of_all 
	+ 3471997.3084 * parameters.cpu_usage 
	- 0.4158 * parameters.avg_work_of_same_past_second 
	- 0.0228 * parameters.avg_wait_of_same_past_second 
	- 0.1268 * parameters.avg_latency_of_same_last_20 
	+ 1353983917.0176;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM22(work_wait &parameters) {
  double actual_remaining = 
	0.0295 * parameters.work_so_far 
	- 0.1074 * parameters.wait_so_far 
	+ 6224412.9435 * parameters.num_locks_so_far 
	- 685035.1606 * parameters.total_wait_locks 
	+ 0.1852 * parameters.mean_wait_of_all 
	+ 3471997.3084 * parameters.cpu_usage 
	- 0.2494 * parameters.avg_work_of_same_past_second 
	- 0.0228 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	+ 549734586.0516;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM23(work_wait &parameters) {
  double actual_remaining = 
	0.0295 * parameters.work_so_far 
	- 0.2345 * parameters.wait_so_far 
	+ 181427150.3501 * parameters.num_locks_so_far 
	- 1774744.6548 * parameters.total_wait_locks 
	+ 0.1852 * parameters.mean_wait_of_all 
	+ 3471997.3084 * parameters.cpu_usage 
	+ 0.358 * parameters.avg_work_of_same_past_second 
	- 0.0228 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	+ 291856295.0232;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM24(work_wait &parameters) {
  double actual_remaining = 
	1.0273 * parameters.work_so_far 
	- 0.0615 * parameters.wait_so_far 
	- 5679.7677 * parameters.num_locks_so_far 
	+ 403852.5456 * parameters.total_wait_locks 
	+ 0.1852 * parameters.mean_wait_of_all 
	+ 3471997.3084 * parameters.cpu_usage 
	+ 0.8225 * parameters.avg_work_of_same_past_second 
	- 0.8749 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	+ 221321136.2211;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM25(work_wait &parameters) {
  double actual_remaining = 
	2.1624 * parameters.work_so_far 
	- 0.0844 * parameters.wait_so_far 
	- 5679.7677 * parameters.num_locks_so_far 
	+ 8420.6691 * parameters.total_wait_locks 
	- 0.0598 * parameters.mean_wait_of_all 
	- 146452.7015 * parameters.cpu_usage 
	+ 0.0031 * parameters.avg_work_of_same_past_second 
	- 0.5339 * parameters.avg_wait_of_same_past_second 
	+ 0.0024 * parameters.avg_latency_of_same_last_20 
	+ 0.0436 * parameters.max_latency_of_same_last_50 
	+ 522834666.5463;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM26(work_wait &parameters) {
  double actual_remaining = 
	11.9332 * parameters.work_so_far 
	- 0.004 * parameters.wait_so_far 
	- 5679.7677 * parameters.num_locks_so_far 
	+ 4168143.8084 * parameters.total_wait_locks 
	- 167.5411 * parameters.mean_wait_of_all 
	+ 709414080.8042 * parameters.cpu_usage 
	- 1.6735 * parameters.avg_work_of_same_past_second 
	+ 1.404 * parameters.avg_wait_of_same_past_second 
	+ 0.0056 * parameters.avg_latency_of_same_last_20 
	+ 0.0761 * parameters.max_latency_of_same_last_50 
	+ 2764850052.2718;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM27(work_wait &parameters) {
  double actual_remaining = 
	0.8096 * parameters.work_so_far 
	- 0.1948 * parameters.wait_so_far 
	- 5679.7677 * parameters.num_locks_so_far 
	+ 467350.7629 * parameters.total_wait_locks 
	- 12.3829 * parameters.mean_wait_of_all 
	+ 60286730.6495 * parameters.cpu_usage 
	- 0.1088 * parameters.avg_work_of_same_past_second 
	+ 0.0702 * parameters.avg_wait_of_same_past_second 
	+ 0.0056 * parameters.avg_latency_of_same_last_20 
	+ 0.0048 * parameters.max_latency_of_same_last_50 
	+ 828815238.3261;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM28(work_wait &parameters) {
  double actual_remaining = 
	0.005 * parameters.work_so_far 
	- 0.1034 * parameters.wait_so_far 
	- 5679.7677 * parameters.num_locks_so_far 
	+ 39984.0847 * parameters.total_wait_locks 
	+ 80.4998 * parameters.mean_wait_of_all 
	- 610516571.2848 * parameters.cpu_usage 
	- 0.006 * parameters.avg_work_of_same_past_second 
	- 0.0058 * parameters.avg_wait_of_same_past_second 
	+ 0.1245 * parameters.avg_latency_of_same_last_20 
	- 1553243487.2808;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM29(work_wait &parameters) {
  double actual_remaining = 
	0.005 * parameters.work_so_far 
	- 0.0966 * parameters.wait_so_far 
	- 5679.7677 * parameters.num_locks_so_far 
	+ 39984.0847 * parameters.total_wait_locks 
	- 174.5215 * parameters.mean_wait_of_all 
	- 6748398.5786 * parameters.cpu_usage 
	+ 1.7519 * parameters.avg_work_of_same_past_second 
	- 0.0058 * parameters.avg_wait_of_same_past_second 
	+ 0.014 * parameters.avg_latency_of_same_last_20 
	- 0.0025 * parameters.max_latency_of_same_last_50 
	+ 5441858635.2937;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM30(work_wait &parameters) {
  double actual_remaining = 
	0.005 * parameters.work_so_far 
	- 0.1609 * parameters.wait_so_far 
	- 5679.7677 * parameters.num_locks_so_far 
	- 100269.6786 * parameters.total_wait_locks 
	+ 0.302 * parameters.mean_wait_of_all 
	- 6748398.5786 * parameters.cpu_usage 
	+ 0.0292 * parameters.avg_work_of_same_past_second 
	- 0.0058 * parameters.avg_wait_of_same_past_second 
	+ 0.0133 * parameters.avg_latency_of_same_last_20 
	- 0.1057 * parameters.max_latency_of_same_last_50 
	+ 669160205.7481;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM31(work_wait &parameters) {
  double actual_remaining = 
	0.005 * parameters.work_so_far 
	- 0.0206 * parameters.wait_so_far 
	- 5679.7677 * parameters.num_locks_so_far 
	- 270274.2401 * parameters.total_wait_locks 
	- 538.929 * parameters.mean_wait_of_all 
	- 6748398.5786 * parameters.cpu_usage 
	+ 0.0292 * parameters.avg_work_of_same_past_second 
	- 8.8687 * parameters.avg_wait_of_same_past_second 
	+ 0.0133 * parameters.avg_latency_of_same_last_20 
	- 0.0106 * parameters.max_latency_of_same_last_50 
	+ 22495381435.95;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM32(work_wait &parameters) {
  double actual_remaining = 
	0.4106 * parameters.work_so_far 
	- 1.1975 * parameters.wait_so_far 
	- 259934.0424 * parameters.num_locks_so_far 
	- 139761.3411 * parameters.total_wait_locks 
	- 32.8451 * parameters.mean_wait_of_all 
	+ 407079.1225 * parameters.cpu_usage 
	+ 0.0466 * parameters.avg_work_of_same_past_second 
	- 0.028 * parameters.avg_wait_of_same_past_second 
	+ 0.0019 * parameters.avg_latency_of_same_last_20 
	- 0.0669 * parameters.max_latency_of_same_last_50 
	+ 1661116217.5229;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM33(work_wait &parameters) {
  double actual_remaining = 
	0.5184 * parameters.work_so_far 
	- 0.0831 * parameters.wait_so_far 
	- 259934.0424 * parameters.num_locks_so_far 
	- 3165780.8397 * parameters.total_wait_locks 
	+ 1.7549 * parameters.mean_wait_of_all 
	+ 407079.1225 * parameters.cpu_usage 
	+ 1.8318 * parameters.avg_work_of_same_past_second 
	- 0.9244 * parameters.avg_wait_of_same_past_second 
	+ 0.0019 * parameters.avg_latency_of_same_last_20 
	- 0.0041 * parameters.max_latency_of_same_last_50 
	+ 2259329238.2752;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM34(work_wait &parameters) {
  double actual_remaining = 
	2.6412 * parameters.work_so_far 
	- 3.8747 * parameters.wait_so_far 
	- 259934.0424 * parameters.num_locks_so_far 
	- 1399090.0274 * parameters.total_wait_locks 
	+ 40.608 * parameters.mean_wait_of_all 
	+ 407079.1225 * parameters.cpu_usage 
	- 0.2923 * parameters.avg_work_of_same_past_second 
	+ 0.3887 * parameters.avg_wait_of_same_past_second 
	+ 0.0019 * parameters.avg_latency_of_same_last_20 
	- 0.0008 * parameters.max_latency_of_same_last_50 
	- 70560444.3906;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM35(work_wait &parameters) {
  double actual_remaining = 
	5.376 * parameters.work_so_far 
	- 7.012 * parameters.wait_so_far 
	- 259934.0424 * parameters.num_locks_so_far 
	- 3666494.2333 * parameters.total_wait_locks 
	+ 40.608 * parameters.mean_wait_of_all 
	+ 407079.1225 * parameters.cpu_usage 
	- 0.2923 * parameters.avg_work_of_same_past_second 
	+ 2.665 * parameters.avg_wait_of_same_past_second 
	- 1.3022 * parameters.avg_latency_of_same_last_20 
	- 0.0008 * parameters.max_latency_of_same_last_50 
	+ 1824653325.1649;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM36(work_wait &parameters) {
  double actual_remaining = 
	5.376 * parameters.work_so_far 
	- 6.4869 * parameters.wait_so_far 
	- 259934.0424 * parameters.num_locks_so_far 
	- 3099643.1819 * parameters.total_wait_locks 
	+ 40.608 * parameters.mean_wait_of_all 
	+ 407079.1225 * parameters.cpu_usage 
	- 0.2923 * parameters.avg_work_of_same_past_second 
	+ 2.665 * parameters.avg_wait_of_same_past_second 
	+ 0.3231 * parameters.avg_latency_of_same_last_20 
	- 0.0008 * parameters.max_latency_of_same_last_50 
	+ 910790135.824;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM37(work_wait &parameters) {
  double actual_remaining = 
	4.4422 * parameters.work_so_far 
	- 6.3396 * parameters.wait_so_far 
	- 259934.0424 * parameters.num_locks_so_far 
	- 1399090.0274 * parameters.total_wait_locks 
	+ 40.608 * parameters.mean_wait_of_all 
	+ 407079.1225 * parameters.cpu_usage 
	- 0.2923 * parameters.avg_work_of_same_past_second 
	+ 1.8877 * parameters.avg_wait_of_same_past_second 
	- 0.8569 * parameters.avg_latency_of_same_last_20 
	- 0.0008 * parameters.max_latency_of_same_last_50 
	- 17657218.061;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM38(work_wait &parameters) {
  double actual_remaining = 
	1.2719 * parameters.work_so_far 
	- 0.2667 * parameters.wait_so_far 
	- 259934.0424 * parameters.num_locks_so_far 
	- 5198402.5547 * parameters.total_wait_locks 
	+ 175.3442 * parameters.mean_wait_of_all 
	+ 407079.1225 * parameters.cpu_usage 
	- 0.1045 * parameters.avg_work_of_same_past_second 
	+ 1.4367 * parameters.avg_wait_of_same_past_second 
	+ 0.3526 * parameters.avg_latency_of_same_last_20 
	- 0.0008 * parameters.max_latency_of_same_last_50 
	- 3010115887.093;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM39(work_wait &parameters) {
  double actual_remaining = 
	0.3428 * parameters.work_so_far 
	- 0.0611 * parameters.wait_so_far 
	- 259934.0424 * parameters.num_locks_so_far 
	- 1822936.779 * parameters.total_wait_locks 
	+ 4.8393 * parameters.mean_wait_of_all 
	+ 407079.1225 * parameters.cpu_usage 
	+ 0.0026 * parameters.avg_work_of_same_past_second 
	- 0.5883 * parameters.avg_wait_of_same_past_second 
	+ 0.0019 * parameters.avg_latency_of_same_last_20 
	+ 0.1272 * parameters.max_latency_of_same_last_50 
	+ 1536237179.0299;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM40(work_wait &parameters) {
  double actual_remaining = 
	0.1709 * parameters.work_so_far 
	- 0.0089 * parameters.wait_so_far 
	- 124711638.5039 * parameters.num_locks_so_far 
	- 12449.7165 * parameters.total_wait_locks 
	+ 0.2586 * parameters.mean_wait_of_all 
	+ 15739498.2813 * parameters.cpu_usage 
	- 2.099 * parameters.avg_work_of_same_past_second 
	+ 1.1554 * parameters.avg_wait_of_same_past_second 
	+ 0.005 * parameters.avg_latency_of_same_last_20 
	+ 955673603.9548;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM41(work_wait &parameters) {
  double actual_remaining = 
	11.4266 * parameters.work_so_far 
	- 0.0089 * parameters.wait_so_far 
	- 2223873.6657 * parameters.num_locks_so_far 
	- 12449.7165 * parameters.total_wait_locks 
	+ 26.5948 * parameters.mean_wait_of_all 
	+ 16790864.1665 * parameters.cpu_usage 
	- 0.0237 * parameters.avg_work_of_same_past_second 
	+ 0.0069 * parameters.avg_wait_of_same_past_second 
	+ 0.2234 * parameters.avg_latency_of_same_last_20 
	- 892734236.2951;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM42(work_wait &parameters) {
  double actual_remaining = 
	0.0118 * parameters.work_so_far 
	- 0.0851 * parameters.wait_so_far 
	+ 49007494.3883 * parameters.num_locks_so_far 
	- 129882.0194 * parameters.total_wait_locks 
	- 0.0486 * parameters.mean_wait_of_all 
	+ 407079.1225 * parameters.cpu_usage 
	+ 0.0026 * parameters.avg_work_of_same_past_second 
	- 0.1905 * parameters.avg_wait_of_same_past_second 
	+ 0.0766 * parameters.avg_latency_of_same_last_20 
	+ 261446526.2533;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM43(work_wait &parameters) {
  double actual_remaining = 
	0.1184 * parameters.work_so_far 
	- 0.0053 * parameters.wait_so_far 
	- 115258652.4266 * parameters.num_locks_so_far 
	+ 854467.6594 * parameters.total_wait_locks 
	- 15.2578 * parameters.mean_wait_of_all 
	+ 28009289.4245 * parameters.cpu_usage 
	+ 0.0233 * parameters.avg_work_of_same_past_second 
	- 0.0234 * parameters.avg_wait_of_same_past_second 
	+ 0.0063 * parameters.avg_latency_of_same_last_20 
	+ 751490608.9336;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM44(work_wait &parameters) {
  double actual_remaining = 
	1.7957 * parameters.work_so_far 
	- 0.0094 * parameters.wait_so_far 
	+ 3088560.168 * parameters.num_locks_so_far 
	+ 2636600.3812 * parameters.total_wait_locks 
	- 78.9495 * parameters.mean_wait_of_all 
	+ 774684590.5357 * parameters.cpu_usage 
	+ 0.6277 * parameters.avg_work_of_same_past_second 
	- 0.0353 * parameters.avg_wait_of_same_past_second 
	+ 0.0063 * parameters.avg_latency_of_same_last_20 
	+ 677231192.1425;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM45(work_wait &parameters) {
  double actual_remaining = 
	0.235 * parameters.work_so_far 
	- 0.4537 * parameters.wait_so_far 
	+ 9091047.4751 * parameters.num_locks_so_far 
	+ 210118.2878 * parameters.total_wait_locks 
	- 6.3595 * parameters.mean_wait_of_all 
	+ 67122607.0153 * parameters.cpu_usage 
	+ 0.0563 * parameters.avg_work_of_same_past_second 
	- 0.0684 * parameters.avg_wait_of_same_past_second 
	+ 0.0063 * parameters.avg_latency_of_same_last_20 
	+ 459720993.6299;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM46(work_wait &parameters) {
  double actual_remaining = 
	-4.0812 * parameters.work_so_far 
	- 0.001 * parameters.wait_so_far 
	- 5679.7677 * parameters.num_locks_so_far 
	+ 23424.9757 * parameters.total_wait_locks 
	- 0.7681 * parameters.mean_wait_of_all 
	+ 821125320.92 * parameters.cpu_usage 
	+ 0.0131 * parameters.avg_work_of_same_past_second 
	- 0.7681 * parameters.avg_wait_of_same_past_second 
	+ 0.0228 * parameters.avg_latency_of_same_last_20 
	+ 0.0969 * parameters.max_latency_of_same_last_50 
	- 327516278.279;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM47(work_wait &parameters) {
  double actual_remaining = 
	9.2083 * parameters.work_so_far 
	- 0.001 * parameters.wait_so_far 
	- 5679.7677 * parameters.num_locks_so_far 
	- 1128424.5919 * parameters.total_wait_locks 
	- 6.5085 * parameters.mean_wait_of_all 
	+ 1216838045.2104 * parameters.cpu_usage 
	+ 0.3302 * parameters.avg_work_of_same_past_second 
	- 1.8735 * parameters.avg_wait_of_same_past_second 
	+ 2.0087 * parameters.avg_latency_of_same_last_20 
	+ 0.012 * parameters.max_latency_of_same_last_50 
	- 1113302922.2479;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM48(work_wait &parameters) {
  double actual_remaining = 
	-13.6733 * parameters.work_so_far 
	- 0.001 * parameters.wait_so_far 
	- 5679.7677 * parameters.num_locks_so_far 
	- 1128424.5919 * parameters.total_wait_locks 
	- 8.0033 * parameters.mean_wait_of_all 
	+ 1275282267.5853 * parameters.cpu_usage 
	+ 0.3302 * parameters.avg_work_of_same_past_second 
	- 4.612 * parameters.avg_wait_of_same_past_second 
	+ 0.817 * parameters.avg_latency_of_same_last_20 
	+ 0.012 * parameters.max_latency_of_same_last_50 
	+ 1255872747.4087;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM49(work_wait &parameters) {
  double actual_remaining = 
	0.0524 * parameters.work_so_far 
	- 0.001 * parameters.wait_so_far 
	- 5679.7677 * parameters.num_locks_so_far 
	- 724683.5064 * parameters.total_wait_locks 
	+ 13.9509 * parameters.mean_wait_of_all 
	+ 106397820.0864 * parameters.cpu_usage 
	+ 0.219 * parameters.avg_work_of_same_past_second 
	- 0.6557 * parameters.avg_wait_of_same_past_second 
	+ 0.1625 * parameters.avg_latency_of_same_last_20 
	+ 0.012 * parameters.max_latency_of_same_last_50 
	+ 352198538.1342;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
new_order_estimate(work_wait &parameters){

  if (parameters.mean_wait_of_all <= 21128150) {
    return new_order_LM1(parameters);
  } else {

    if (parameters.mean_wait_of_all <= 27842400) {

      if (parameters.cpu_usage <= 0.951) {

        if (parameters.avg_work_of_same_past_second <= 209177000) {

          if (parameters.mean_wait_of_all <= 25870000) {

            if (parameters.mean_wait_of_all <= 24184350) {
              return new_order_LM2(parameters);
            } else {
              return new_order_LM3(parameters);
            }
          } else {
            return new_order_LM4(parameters);
          }
        } else {
          return new_order_LM5(parameters);
        }
      } else {

        if (parameters.avg_work_of_same_past_second <= 180433500) {

          if (parameters.wait_so_far <= 236789229) {

            if (parameters.avg_work_of_same_past_second <= 173034000) {

              if (parameters.avg_work_of_same_past_second <= 169492000) {

                if (parameters.mean_wait_of_all <= 23147950) {
                  return new_order_LM6(parameters);
                } else {
                  return new_order_LM7(parameters);
                }
              } else {

                if (parameters.avg_wait_of_same_past_second <= 258525000) {

                  if (parameters.work_so_far <= 45288) {

                    if (parameters.wait_so_far <= 39154909) {

                      if (parameters.avg_wait_of_same_past_second <= 256257500) {
                        return new_order_LM8(parameters);
                      } else {
                        return new_order_LM9(parameters);
                      }
                    } else {
                      return new_order_LM10(parameters);
                    }
                  } else {
                    return new_order_LM11(parameters);
                  }
                } else {
                  return new_order_LM12(parameters);
                }
              }
            } else {
              return new_order_LM13(parameters);
            }
          } else {
            return new_order_LM14(parameters);
          }
        } else {

          if (parameters.avg_work_of_same_past_second <= 196094000) {

            if (parameters.avg_work_of_same_past_second <= 189436500) {

              if (parameters.avg_work_of_same_past_second <= 183050000) {

                if (parameters.avg_latency_of_same_last_20 <= 242701500) {

                  if (parameters.work_so_far <= 51929.5) {
                    return new_order_LM15(parameters);
                  } else {
                    return new_order_LM16(parameters);
                  }
                } else {

                  if (parameters.avg_work_of_same_past_second <= 182495000) {
                    return new_order_LM17(parameters);
                  } else {

                    if (parameters.total_wait_locks <= 471.5) {

                      if (parameters.total_wait_locks <= 374.5) {
                        return new_order_LM18(parameters);
                      } else {

                        if (parameters.wait_so_far <= 65286441.5) {
                          return new_order_LM19(parameters);
                        } else {
                          return new_order_LM20(parameters);
                        }
                      }
                    } else {
                      return new_order_LM21(parameters);
                    }
                  }
                }
              } else {
                return new_order_LM22(parameters);
              }
            } else {
              return new_order_LM23(parameters);
            }
          } else {
            return new_order_LM24(parameters);
          }
        }
      }
    } else {

      if (parameters.mean_wait_of_all <= 34215900) {

        if (parameters.mean_wait_of_all <= 30673150) {
          return new_order_LM25(parameters);
        } else {

          if (parameters.avg_wait_of_same_past_second <= 361775000) {

            if (parameters.total_wait_locks <= 615.5) {
              return new_order_LM26(parameters);
            } else {
              return new_order_LM27(parameters);
            }
          } else {

            if (parameters.mean_wait_of_all <= 32431600) {
              return new_order_LM28(parameters);
            } else {

              if (parameters.mean_wait_of_all <= 33275650) {
                return new_order_LM29(parameters);
              } else {

                if (parameters.avg_wait_of_same_past_second <= 405194000) {
                  return new_order_LM30(parameters);
                } else {
                  return new_order_LM31(parameters);
                }
              }
            }
          }
        }
      } else {

        if (parameters.avg_latency_of_same_last_20 <= 594008500) {

          if (parameters.wait_so_far <= 86195163) {

            if (parameters.mean_wait_of_all <= 39911950) {

              if (parameters.mean_wait_of_all <= 36378150) {

                if (parameters.work_so_far <= 66872) {
                  return new_order_LM32(parameters);
                } else {
                  return new_order_LM33(parameters);
                }
              } else {

                if (parameters.max_latency_of_same_last_50 <= 1227725000) {

                  if (parameters.avg_work_of_same_past_second <= 220509500) {

                    if (parameters.avg_latency_of_same_last_20 <= 226773500) {
                      return new_order_LM34(parameters);
                    } else {

                      if (parameters.avg_latency_of_same_last_20 <= 304250500) {

                        if (parameters.total_wait_locks <= 686) {
                          return new_order_LM35(parameters);
                        } else {
                          return new_order_LM36(parameters);
                        }
                      } else {
                        return new_order_LM37(parameters);
                      }
                    }
                  } else {
                    return new_order_LM38(parameters);
                  }
                } else {
                  return new_order_LM39(parameters);
                }
              }
            } else {

              if (parameters.avg_work_of_same_past_second <= 215889500) {
                return new_order_LM40(parameters);
              } else {
                return new_order_LM41(parameters);
              }
            }
          } else {
            return new_order_LM42(parameters);
          }
        } else {

          if (parameters.wait_so_far <= 433280363.5) {

            if (parameters.work_so_far <= 94590) {
              return new_order_LM43(parameters);
            } else {

              if (parameters.avg_wait_of_same_past_second <= 373997000) {
                return new_order_LM44(parameters);
              } else {
                return new_order_LM45(parameters);
              }
            }
          } else {

            if (parameters.avg_latency_of_same_last_20 <= 912236500) {
              return new_order_LM46(parameters);
            } else {

              if (parameters.wait_so_far <= 662601446) {

                if (parameters.cpu_usage <= 0.985) {
                  return new_order_LM47(parameters);
                } else {
                  return new_order_LM48(parameters);
                }
              } else {
                return new_order_LM49(parameters);
              }
            }
          }
        }
      }
    }
  }
}
static
double
payment_LM1(work_wait &parameters) {
  double actual_remaining = 
	0.5686 * parameters.work_so_far 
	+ 0.1058 * parameters.wait_so_far 
	+ 128942.8177 * parameters.total_wait_locks 
	- 1.9594 * parameters.mean_wait_of_all 
	+ 0.2045 * parameters.avg_work_of_same_past_second 
	+ 0.0867 * parameters.avg_latency_of_same_last_20 
	+ 16657958.1052;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
payment_estimate(work_wait &parameters){
  return payment_LM1(parameters);
}
static
double
stock_level_LM1(work_wait &parameters) {
  double actual_remaining = 
	+ 32678772.5946;
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
	1302.4861 * parameters.work_so_far 
	+ 0.0697 * parameters.wait_so_far 
	+ 13576939.9428 * parameters.num_locks_so_far 
	+ 99221.499 * parameters.total_wait_locks 
	- 1.753 * parameters.mean_wait_of_all 
	- 43994.8544 * parameters.cpu_usage 
	+ 0.2058 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0613 * parameters.avg_latency_of_same_last_20 
	- 0.0121 * parameters.max_latency_of_same_last_50 
	- 18627953.3137;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM2(work_wait &parameters) {
  double actual_remaining = 
	0.4295 * parameters.work_so_far 
	- 0.0481 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 954424.0622 * parameters.total_wait_locks 
	- 12.2349 * parameters.mean_wait_of_all 
	+ 267587150.3695 * parameters.cpu_usage 
	+ 1.7585 * parameters.avg_work_of_same_past_second 
	- 0.2542 * parameters.avg_wait_of_same_past_second 
	+ 0.0068 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	- 216619060.6455;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM3(work_wait &parameters) {
  double actual_remaining = 
	-11.6547 * parameters.work_so_far 
	- 0.0481 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	- 209968.7834 * parameters.total_wait_locks 
	+ 4.3802 * parameters.mean_wait_of_all 
	- 529897.2408 * parameters.cpu_usage 
	+ 0.0044 * parameters.avg_work_of_same_past_second 
	- 0.0007 * parameters.avg_wait_of_same_past_second 
	+ 0.0068 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	+ 133571023.332;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM4(work_wait &parameters) {
  double actual_remaining = 
	2.9953 * parameters.work_so_far 
	- 42.0184 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	- 180852.6447 * parameters.total_wait_locks 
	- 1.5385 * parameters.mean_wait_of_all 
	- 529897.2408 * parameters.cpu_usage 
	+ 3.3936 * parameters.avg_work_of_same_past_second 
	- 0.1901 * parameters.avg_wait_of_same_past_second 
	+ 0.0068 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	+ 378335592.3153;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM5(work_wait &parameters) {
  double actual_remaining = 
	7.8421 * parameters.work_so_far 
	- 47.0913 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 725440.1648 * parameters.total_wait_locks 
	- 24.3613 * parameters.mean_wait_of_all 
	- 529897.2408 * parameters.cpu_usage 
	+ 78.5902 * parameters.avg_work_of_same_past_second 
	- 0.4154 * parameters.avg_wait_of_same_past_second 
	- 0.3967 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	- 1704772082.7039;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM6(work_wait &parameters) {
  double actual_remaining = 
	6.8102 * parameters.work_so_far 
	- 64.6833 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 725440.1648 * parameters.total_wait_locks 
	- 24.3613 * parameters.mean_wait_of_all 
	- 529897.2408 * parameters.cpu_usage 
	+ 89.0461 * parameters.avg_work_of_same_past_second 
	- 0.4154 * parameters.avg_wait_of_same_past_second 
	- 0.3967 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	- 1961559917.1014;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM7(work_wait &parameters) {
  double actual_remaining = 
	5.9157 * parameters.work_so_far 
	- 19.5124 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 725440.1648 * parameters.total_wait_locks 
	- 24.3613 * parameters.mean_wait_of_all 
	- 193442814.8428 * parameters.cpu_usage 
	+ 44.0966 * parameters.avg_work_of_same_past_second 
	- 0.4154 * parameters.avg_wait_of_same_past_second 
	- 0.464 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	- 381521996.393;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM8(work_wait &parameters) {
  double actual_remaining = 
	2.7713 * parameters.work_so_far 
	- 0.0481 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	- 93305.206 * parameters.total_wait_locks 
	+ 2.0522 * parameters.mean_wait_of_all 
	- 529897.2408 * parameters.cpu_usage 
	+ 0.0044 * parameters.avg_work_of_same_past_second 
	- 0.0007 * parameters.avg_wait_of_same_past_second 
	+ 0.1483 * parameters.avg_latency_of_same_last_20 
	- 0.0118 * parameters.max_latency_of_same_last_50 
	+ 50622614.8062;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM9(work_wait &parameters) {
  double actual_remaining = 
	2.7713 * parameters.work_so_far 
	- 0.0481 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	- 93305.206 * parameters.total_wait_locks 
	+ 2.0522 * parameters.mean_wait_of_all 
	- 624599757.2314 * parameters.cpu_usage 
	+ 0.0044 * parameters.avg_work_of_same_past_second 
	- 0.0007 * parameters.avg_wait_of_same_past_second 
	+ 0.2068 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	+ 648508250.0127;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM10(work_wait &parameters) {
  double actual_remaining = 
	2.7713 * parameters.work_so_far 
	- 0.0481 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	- 93305.206 * parameters.total_wait_locks 
	+ 2.0522 * parameters.mean_wait_of_all 
	- 3712041961.5235 * parameters.cpu_usage 
	+ 0.0044 * parameters.avg_work_of_same_past_second 
	- 0.0007 * parameters.avg_wait_of_same_past_second 
	+ 0.2916 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	+ 3673305445.7697;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM11(work_wait &parameters) {
  double actual_remaining = 
	1.4185 * parameters.work_so_far 
	- 0.016 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 214965.2931 * parameters.total_wait_locks 
	- 3.569 * parameters.mean_wait_of_all 
	- 529897.2408 * parameters.cpu_usage 
	+ 0.0044 * parameters.avg_work_of_same_past_second 
	- 0.0007 * parameters.avg_wait_of_same_past_second 
	+ 0.1432 * parameters.avg_latency_of_same_last_20 
	- 0.0203 * parameters.max_latency_of_same_last_50 
	+ 41982601.8413;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM12(work_wait &parameters) {
  double actual_remaining = 
	-0.1181 * parameters.work_so_far 
	+ 0.0009 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 151360.9588 * parameters.total_wait_locks 
	- 1.5025 * parameters.mean_wait_of_all 
	- 1061703.92 * parameters.cpu_usage 
	- 3.3155 * parameters.avg_work_of_same_past_second 
	- 0.0084 * parameters.avg_wait_of_same_past_second 
	+ 0.0034 * parameters.avg_latency_of_same_last_20 
	- 0.0173 * parameters.max_latency_of_same_last_50 
	+ 110727664.3319;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM13(work_wait &parameters) {
  double actual_remaining = 
	-24129.2821 * parameters.work_so_far 
	+ 0.782 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 442167.387 * parameters.total_wait_locks 
	- 2.8545 * parameters.mean_wait_of_all 
	- 1061703.92 * parameters.cpu_usage 
	+ 0.0417 * parameters.avg_work_of_same_past_second 
	- 0.0084 * parameters.avg_wait_of_same_past_second 
	+ 0.0034 * parameters.avg_latency_of_same_last_20 
	- 0.0352 * parameters.max_latency_of_same_last_50 
	+ 977245021.5211;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM14(work_wait &parameters) {
  double actual_remaining = 
	-0.1181 * parameters.work_so_far 
	+ 0.1891 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 372768.3408 * parameters.total_wait_locks 
	- 2.8545 * parameters.mean_wait_of_all 
	- 1061703.92 * parameters.cpu_usage 
	+ 0.0417 * parameters.avg_work_of_same_past_second 
	- 0.0084 * parameters.avg_wait_of_same_past_second 
	+ 0.0034 * parameters.avg_latency_of_same_last_20 
	- 0.0352 * parameters.max_latency_of_same_last_50 
	+ 30931252.4817;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM15(work_wait &parameters) {
  double actual_remaining = 
	-0.1181 * parameters.work_so_far 
	+ 0.0009 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 373072.7628 * parameters.total_wait_locks 
	- 1.9173 * parameters.mean_wait_of_all 
	- 1061703.92 * parameters.cpu_usage 
	+ 0.0417 * parameters.avg_work_of_same_past_second 
	- 0.1409 * parameters.avg_wait_of_same_past_second 
	+ 0.0034 * parameters.avg_latency_of_same_last_20 
	- 0.0252 * parameters.max_latency_of_same_last_50 
	+ 20536178.8999;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM16(work_wait &parameters) {
  double actual_remaining = 
	-0.1181 * parameters.work_so_far 
	+ 0.0009 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 15300.7989 * parameters.total_wait_locks 
	- 0.237 * parameters.mean_wait_of_all 
	- 1061703.92 * parameters.cpu_usage 
	+ 0.0417 * parameters.avg_work_of_same_past_second 
	- 0.006 * parameters.avg_wait_of_same_past_second 
	+ 0.0034 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 54831538.1037;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM17(work_wait &parameters) {
  double actual_remaining = 
	-26.0279 * parameters.work_so_far 
	+ 0.0009 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 429914.5727 * parameters.total_wait_locks 
	- 7.9954 * parameters.mean_wait_of_all 
	- 208925639.1073 * parameters.cpu_usage 
	+ 0.0663 * parameters.avg_work_of_same_past_second 
	- 0.0178 * parameters.avg_wait_of_same_past_second 
	+ 0.0034 * parameters.avg_latency_of_same_last_20 
	- 0.0201 * parameters.max_latency_of_same_last_50 
	+ 394862016.3818;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM18(work_wait &parameters) {
  double actual_remaining = 
	730.7758 * parameters.work_so_far 
	+ 0.0009 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 429914.5727 * parameters.total_wait_locks 
	- 7.9954 * parameters.mean_wait_of_all 
	+ 93319112.3104 * parameters.cpu_usage 
	+ 0.0663 * parameters.avg_work_of_same_past_second 
	- 0.0178 * parameters.avg_wait_of_same_past_second 
	+ 0.0034 * parameters.avg_latency_of_same_last_20 
	- 0.0201 * parameters.max_latency_of_same_last_50 
	+ 82139869.8107;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM19(work_wait &parameters) {
  double actual_remaining = 
	-13.2457 * parameters.work_so_far 
	+ 0.0009 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 286100.2202 * parameters.total_wait_locks 
	- 5.3424 * parameters.mean_wait_of_all 
	+ 89133005.2789 * parameters.cpu_usage 
	+ 1.6064 * parameters.avg_work_of_same_past_second 
	- 0.0178 * parameters.avg_wait_of_same_past_second 
	+ 0.0034 * parameters.avg_latency_of_same_last_20 
	- 0.0201 * parameters.max_latency_of_same_last_50 
	- 36460698.5937;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM20(work_wait &parameters) {
  double actual_remaining = 
	-13.2457 * parameters.work_so_far 
	+ 0.0009 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 808643.7656 * parameters.total_wait_locks 
	- 12.8845 * parameters.mean_wait_of_all 
	+ 86817851.6542 * parameters.cpu_usage 
	+ 1.4754 * parameters.avg_work_of_same_past_second 
	- 0.0178 * parameters.avg_wait_of_same_past_second 
	+ 0.0034 * parameters.avg_latency_of_same_last_20 
	- 0.0201 * parameters.max_latency_of_same_last_50 
	- 62268101.3019;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM21(work_wait &parameters) {
  double actual_remaining = 
	-13.2457 * parameters.work_so_far 
	+ 0.0009 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 1123272.6036 * parameters.total_wait_locks 
	- 12.8845 * parameters.mean_wait_of_all 
	+ 86817851.6542 * parameters.cpu_usage 
	+ 1.4754 * parameters.avg_work_of_same_past_second 
	- 0.0178 * parameters.avg_wait_of_same_past_second 
	+ 0.0034 * parameters.avg_latency_of_same_last_20 
	- 0.0201 * parameters.max_latency_of_same_last_50 
	- 51304208.6167;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM22(work_wait &parameters) {
  double actual_remaining = 
	18.9253 * parameters.work_so_far 
	+ 0.0009 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 141663.8678 * parameters.total_wait_locks 
	- 2.6805 * parameters.mean_wait_of_all 
	+ 30594516.9032 * parameters.cpu_usage 
	+ 0.0663 * parameters.avg_work_of_same_past_second 
	- 0.0178 * parameters.avg_wait_of_same_past_second 
	+ 0.0034 * parameters.avg_latency_of_same_last_20 
	- 0.0208 * parameters.max_latency_of_same_last_50 
	+ 61748735.2572;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM23(work_wait &parameters) {
  double actual_remaining = 
	-0.1181 * parameters.work_so_far 
	+ 0.0009 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 321799.8486 * parameters.total_wait_locks 
	- 5.9332 * parameters.mean_wait_of_all 
	+ 7701308.2607 * parameters.cpu_usage 
	+ 0.0663 * parameters.avg_work_of_same_past_second 
	- 0.0169 * parameters.avg_wait_of_same_past_second 
	+ 0.0034 * parameters.avg_latency_of_same_last_20 
	- 0.003 * parameters.max_latency_of_same_last_50 
	+ 56633312.6017;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM24(work_wait &parameters) {
  double actual_remaining = 
	-25.8987 * parameters.work_so_far 
	+ 0.0009 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	- 40907.0278 * parameters.total_wait_locks 
	+ 0.9801 * parameters.mean_wait_of_all 
	- 1061703.92 * parameters.cpu_usage 
	+ 0.0229 * parameters.avg_work_of_same_past_second 
	- 0.002 * parameters.avg_wait_of_same_past_second 
	+ 0.004 * parameters.avg_latency_of_same_last_20 
	- 0.0246 * parameters.max_latency_of_same_last_50 
	+ 127488721.6899;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM25(work_wait &parameters) {
  double actual_remaining = 
	0.8753 * parameters.work_so_far 
	+ 0.0009 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 255113.221 * parameters.total_wait_locks 
	- 6.3401 * parameters.mean_wait_of_all 
	- 1061703.92 * parameters.cpu_usage 
	+ 0.022 * parameters.avg_work_of_same_past_second 
	- 0.0022 * parameters.avg_wait_of_same_past_second 
	+ 0.004 * parameters.avg_latency_of_same_last_20 
	+ 0.0399 * parameters.max_latency_of_same_last_50 
	+ 84030423.2827;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM26(work_wait &parameters) {
  double actual_remaining = 
	0.5425 * parameters.work_so_far 
	+ 0.1315 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 78251.1815 * parameters.total_wait_locks 
	- 1.4934 * parameters.mean_wait_of_all 
	- 1404494.7278 * parameters.cpu_usage 
	+ 0.0044 * parameters.avg_work_of_same_past_second 
	- 0.0007 * parameters.avg_wait_of_same_past_second 
	+ 0.046 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 31891522.3857;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM27(work_wait &parameters) {
  double actual_remaining = 
	0.0196 * parameters.work_so_far 
	+ 0.0007 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 110099.1849 * parameters.total_wait_locks 
	- 2.2447 * parameters.mean_wait_of_all 
	- 565211.7753 * parameters.cpu_usage 
	+ 0.0044 * parameters.avg_work_of_same_past_second 
	- 0.0007 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0.0235 * parameters.max_latency_of_same_last_50 
	+ 113774758.9;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM28(work_wait &parameters) {
  double actual_remaining = 
	0.0304 * parameters.work_so_far 
	+ 0.3039 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 202540.812 * parameters.total_wait_locks 
	- 3.9424 * parameters.mean_wait_of_all 
	- 565211.7753 * parameters.cpu_usage 
	+ 0.0044 * parameters.avg_work_of_same_past_second 
	- 0.0007 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 4198979.4269;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM29(work_wait &parameters) {
  double actual_remaining = 
	0.0304 * parameters.work_so_far 
	+ 0.0007 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 7679.0883 * parameters.total_wait_locks 
	+ 1.6082 * parameters.mean_wait_of_all 
	+ 676274059.2158 * parameters.cpu_usage 
	+ 0.0044 * parameters.avg_work_of_same_past_second 
	- 0.0007 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0.2061 * parameters.max_latency_of_same_last_50 
	- 393214154.7746;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM30(work_wait &parameters) {
  double actual_remaining = 
	0.0304 * parameters.work_so_far 
	+ 0.0007 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 7679.0883 * parameters.total_wait_locks 
	- 0.1359 * parameters.mean_wait_of_all 
	- 565211.7753 * parameters.cpu_usage 
	+ 0.0044 * parameters.avg_work_of_same_past_second 
	- 0.0007 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 161194811.4397;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM31(work_wait &parameters) {
  double actual_remaining = 
	0.0304 * parameters.work_so_far 
	- 0.4902 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 7679.0883 * parameters.total_wait_locks 
	- 0.1359 * parameters.mean_wait_of_all 
	- 1222397876.0999 * parameters.cpu_usage 
	+ 42.2688 * parameters.avg_work_of_same_past_second 
	- 0.0007 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 403177138.1623;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM32(work_wait &parameters) {
  double actual_remaining = 
	0.0304 * parameters.work_so_far 
	+ 0.0007 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 7679.0883 * parameters.total_wait_locks 
	- 0.1359 * parameters.mean_wait_of_all 
	- 565211.7753 * parameters.cpu_usage 
	+ 0.0044 * parameters.avg_work_of_same_past_second 
	- 0.0007 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	+ 0.7399 * parameters.max_latency_of_same_last_50 
	- 694018774.3353;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM33(work_wait &parameters) {
  double actual_remaining = 
	1.4604 * parameters.work_so_far 
	+ 0.0007 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 202159.4775 * parameters.total_wait_locks 
	- 3.6772 * parameters.mean_wait_of_all 
	- 565211.7753 * parameters.cpu_usage 
	+ 0.0044 * parameters.avg_work_of_same_past_second 
	- 0.0007 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 85664397.9184;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM34(work_wait &parameters) {
  double actual_remaining = 
	0.3048 * parameters.work_so_far 
	+ 0.0011 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 485997.6954 * parameters.total_wait_locks 
	- 5.6637 * parameters.mean_wait_of_all 
	- 174867.9469 * parameters.cpu_usage 
	+ 0.0044 * parameters.avg_work_of_same_past_second 
	- 0.2124 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	+ 0.0008 * parameters.max_latency_of_same_last_50 
	+ 113613308.2037;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM35(work_wait &parameters) {
  double actual_remaining = 
	0.0139 * parameters.work_so_far 
	- 0.1698 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 17505.022 * parameters.total_wait_locks 
	- 0.1368 * parameters.mean_wait_of_all 
	- 8968390.738 * parameters.cpu_usage 
	- 0.0643 * parameters.avg_work_of_same_past_second 
	- 0.0054 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	+ 0.0029 * parameters.max_latency_of_same_last_50 
	+ 114955150.8409;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM36(work_wait &parameters) {
  double actual_remaining = 
	0.0139 * parameters.work_so_far 
	- 0.0038 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 1866733.2879 * parameters.total_wait_locks 
	- 61.4242 * parameters.mean_wait_of_all 
	- 104640956.985 * parameters.cpu_usage 
	- 0.5144 * parameters.avg_work_of_same_past_second 
	- 0.0179 * parameters.avg_wait_of_same_past_second 
	+ 2.9344 * parameters.avg_latency_of_same_last_20 
	- 0.3544 * parameters.max_latency_of_same_last_50 
	+ 205870869.5946;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM37(work_wait &parameters) {
  double actual_remaining = 
	0.0139 * parameters.work_so_far 
	- 0.0038 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 196864.8612 * parameters.total_wait_locks 
	- 4.7926 * parameters.mean_wait_of_all 
	- 43950350.3136 * parameters.cpu_usage 
	- 0.2239 * parameters.avg_work_of_same_past_second 
	- 0.0179 * parameters.avg_wait_of_same_past_second 
	+ 0.0435 * parameters.avg_latency_of_same_last_20 
	+ 0.0023 * parameters.max_latency_of_same_last_50 
	+ 187099131.8491;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM38(work_wait &parameters) {
  double actual_remaining = 
	0.0139 * parameters.work_so_far 
	- 0.0038 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 353082.0315 * parameters.total_wait_locks 
	- 8.6599 * parameters.mean_wait_of_all 
	- 43950350.3136 * parameters.cpu_usage 
	- 0.2239 * parameters.avg_work_of_same_past_second 
	- 0.0179 * parameters.avg_wait_of_same_past_second 
	+ 0.1238 * parameters.avg_latency_of_same_last_20 
	+ 0.0023 * parameters.max_latency_of_same_last_50 
	+ 294260864.9302;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM39(work_wait &parameters) {
  double actual_remaining = 
	0.0139 * parameters.work_so_far 
	- 1.2103 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	- 150284.7772 * parameters.total_wait_locks 
	+ 91.2892 * parameters.mean_wait_of_all 
	- 3242217349.2072 * parameters.cpu_usage 
	- 0.0441 * parameters.avg_work_of_same_past_second 
	- 0.0254 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	+ 0.0023 * parameters.max_latency_of_same_last_50 
	+ 323746842.9002;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM40(work_wait &parameters) {
  double actual_remaining = 
	0.0139 * parameters.work_so_far 
	- 2.188 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	- 150284.7772 * parameters.total_wait_locks 
	+ 0.3657 * parameters.mean_wait_of_all 
	- 6379974.7551 * parameters.cpu_usage 
	- 0.0441 * parameters.avg_work_of_same_past_second 
	- 0.0254 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	+ 0.0023 * parameters.max_latency_of_same_last_50 
	+ 277817690.9797;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM41(work_wait &parameters) {
  double actual_remaining = 
	0.0139 * parameters.work_so_far 
	- 0.0442 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 155468.4418 * parameters.total_wait_locks 
	+ 2.038 * parameters.mean_wait_of_all 
	+ 148219103.6404 * parameters.cpu_usage 
	- 0.0441 * parameters.avg_work_of_same_past_second 
	- 0.0254 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	+ 0.0023 * parameters.max_latency_of_same_last_50 
	- 198288118.5675;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM42(work_wait &parameters) {
  double actual_remaining = 
	1.8925 * parameters.work_so_far 
	+ 0.0029 * parameters.wait_so_far 
	- 2728.672 * parameters.num_locks_so_far 
	+ 11349.1919 * parameters.total_wait_locks 
	- 0.1578 * parameters.mean_wait_of_all 
	- 174867.9469 * parameters.cpu_usage 
	+ 0.0044 * parameters.avg_work_of_same_past_second 
	- 0.0056 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	+ 0.0007 * parameters.max_latency_of_same_last_50 
	+ 145674205.7535;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM43(work_wait &parameters) {
  double actual_remaining = 
	4.668 * parameters.work_so_far 
	- 0.0836 * parameters.wait_so_far 
	- 38115.2905 * parameters.num_locks_so_far 
	+ 1073634.3172 * parameters.total_wait_locks 
	- 9.4577 * parameters.mean_wait_of_all 
	- 346166030.2475 * parameters.cpu_usage 
	+ 1.1901 * parameters.avg_work_of_same_past_second 
	- 0.4034 * parameters.avg_wait_of_same_past_second 
	- 0.254 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 384869745.25;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM44(work_wait &parameters) {
  double actual_remaining = 
	0.0153 * parameters.work_so_far 
	- 0.3257 * parameters.wait_so_far 
	- 38115.2905 * parameters.num_locks_so_far 
	+ 35081.795 * parameters.total_wait_locks 
	- 0.6419 * parameters.mean_wait_of_all 
	- 36222360.2558 * parameters.cpu_usage 
	- 0.0765 * parameters.avg_work_of_same_past_second 
	+ 0.9917 * parameters.avg_wait_of_same_past_second 
	+ 0.0014 * parameters.avg_latency_of_same_last_20 
	- 0.0693 * parameters.max_latency_of_same_last_50 
	+ 413171147.937;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM45(work_wait &parameters) {
  double actual_remaining = 
	0.0153 * parameters.work_so_far 
	- 0.0168 * parameters.wait_so_far 
	- 38115.2905 * parameters.num_locks_so_far 
	+ 35081.795 * parameters.total_wait_locks 
	- 0.6419 * parameters.mean_wait_of_all 
	- 37822774.4073 * parameters.cpu_usage 
	- 0.0809 * parameters.avg_work_of_same_past_second 
	- 0.0065 * parameters.avg_wait_of_same_past_second 
	+ 0.0014 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 248302531.3516;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM46(work_wait &parameters) {
  double actual_remaining = 
	0.0153 * parameters.work_so_far 
	- 0.0089 * parameters.wait_so_far 
	- 38115.2905 * parameters.num_locks_so_far 
	+ 35081.795 * parameters.total_wait_locks 
	- 8.4283 * parameters.mean_wait_of_all 
	+ 312384409.4619 * parameters.cpu_usage 
	- 0.0159 * parameters.avg_work_of_same_past_second 
	- 0.0065 * parameters.avg_wait_of_same_past_second 
	+ 0.0014 * parameters.avg_latency_of_same_last_20 
	- 0.141 * parameters.max_latency_of_same_last_50 
	+ 49290560.9124;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM47(work_wait &parameters) {
  double actual_remaining = 
	0.0106 * parameters.work_so_far 
	- 0.2293 * parameters.wait_so_far 
	- 2891419.0983 * parameters.num_locks_so_far 
	+ 983564.4077 * parameters.total_wait_locks 
	- 12.953 * parameters.mean_wait_of_all 
	+ 254159288.5912 * parameters.cpu_usage 
	+ 0.0099 * parameters.avg_work_of_same_past_second 
	- 0.4384 * parameters.avg_wait_of_same_past_second 
	+ 0.4596 * parameters.avg_latency_of_same_last_20 
	- 0.1982 * parameters.max_latency_of_same_last_50 
	+ 105203053.7124;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM48(work_wait &parameters) {
  double actual_remaining = 
	0.0011 * parameters.work_so_far 
	+ 0.0653 * parameters.wait_so_far 
	- 975.2833 * parameters.num_locks_so_far 
	+ 259.8502 * parameters.total_wait_locks 
	+ 0.9776 * parameters.mean_wait_of_all 
	- 63757.4017 * parameters.cpu_usage 
	+ 0.9413 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0786 * parameters.avg_latency_of_same_last_20 
	+ 24603934.9768;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM49(work_wait &parameters) {
  double actual_remaining = 
	0.0023 * parameters.work_so_far 
	- 0.051 * parameters.wait_so_far 
	- 21876.1661 * parameters.num_locks_so_far 
	+ 1072139.891 * parameters.total_wait_locks 
	- 9.5163 * parameters.mean_wait_of_all 
	+ 26273.3219 * parameters.cpu_usage 
	+ 0.2986 * parameters.avg_work_of_same_past_second 
	- 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.2176 * parameters.avg_latency_of_same_last_20 
	- 21032366.7684;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM50(work_wait &parameters) {
  double actual_remaining = 
	0.8901 * parameters.work_so_far 
	- 0.0515 * parameters.wait_so_far 
	- 30368.3636 * parameters.num_locks_so_far 
	- 947172.8223 * parameters.total_wait_locks 
	+ 43.6359 * parameters.mean_wait_of_all 
	+ 1017344168.7624 * parameters.cpu_usage 
	+ 0.6858 * parameters.avg_work_of_same_past_second 
	- 1.2458 * parameters.avg_wait_of_same_past_second 
	+ 0.0019 * parameters.avg_latency_of_same_last_20 
	- 1055530148.0466;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM51(work_wait &parameters) {
  double actual_remaining = 
	0.0117 * parameters.work_so_far 
	- 0.1141 * parameters.wait_so_far 
	- 30368.3636 * parameters.num_locks_so_far 
	- 668236.2928 * parameters.total_wait_locks 
	+ 15.2612 * parameters.mean_wait_of_all 
	+ 3250647.4602 * parameters.cpu_usage 
	+ 0.0129 * parameters.avg_work_of_same_past_second 
	- 0.897 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	+ 399814513.4557;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM52(work_wait &parameters) {
  double actual_remaining = 
	24.098 * parameters.work_so_far 
	- 0.0064 * parameters.wait_so_far 
	+ 6173855.812 * parameters.num_locks_so_far 
	- 39798.3579 * parameters.total_wait_locks 
	+ 0.6608 * parameters.mean_wait_of_all 
	+ 3931977.8901 * parameters.cpu_usage 
	- 0.4513 * parameters.avg_work_of_same_past_second 
	- 0.0223 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	- 0.101 * parameters.max_latency_of_same_last_50 
	+ 417467203.5627;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM53(work_wait &parameters) {
  double actual_remaining = 
	0.0296 * parameters.work_so_far 
	- 0.0064 * parameters.wait_so_far 
	+ 6173855.812 * parameters.num_locks_so_far 
	+ 140055.2709 * parameters.total_wait_locks 
	- 7.2184 * parameters.mean_wait_of_all 
	+ 3931977.8901 * parameters.cpu_usage 
	- 76.5727 * parameters.avg_work_of_same_past_second 
	- 0.0223 * parameters.avg_wait_of_same_past_second 
	- 0.0554 * parameters.avg_latency_of_same_last_20 
	+ 14319013829.7615;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM54(work_wait &parameters) {
  double actual_remaining = 
	-29.8625 * parameters.work_so_far 
	+ 0.4198 * parameters.wait_so_far 
	+ 6173855.812 * parameters.num_locks_so_far 
	+ 5960960.5647 * parameters.total_wait_locks 
	- 34.9329 * parameters.mean_wait_of_all 
	+ 3931977.8901 * parameters.cpu_usage 
	- 0.4513 * parameters.avg_work_of_same_past_second 
	- 0.0223 * parameters.avg_wait_of_same_past_second 
	- 0.1265 * parameters.avg_latency_of_same_last_20 
	- 839187844.3955;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM55(work_wait &parameters) {
  double actual_remaining = 
	-31.6909 * parameters.work_so_far 
	+ 0.4459 * parameters.wait_so_far 
	+ 6173855.812 * parameters.num_locks_so_far 
	+ 3945382.6198 * parameters.total_wait_locks 
	- 34.9329 * parameters.mean_wait_of_all 
	+ 3931977.8901 * parameters.cpu_usage 
	- 0.4513 * parameters.avg_work_of_same_past_second 
	- 0.0223 * parameters.avg_wait_of_same_past_second 
	- 0.1265 * parameters.avg_latency_of_same_last_20 
	- 62844430.1111;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM56(work_wait &parameters) {
  double actual_remaining = 
	-36.1102 * parameters.work_so_far 
	+ 0.5089 * parameters.wait_so_far 
	+ 6173855.812 * parameters.num_locks_so_far 
	+ 4388036.6698 * parameters.total_wait_locks 
	- 34.9329 * parameters.mean_wait_of_all 
	+ 3931977.8901 * parameters.cpu_usage 
	- 0.4513 * parameters.avg_work_of_same_past_second 
	- 0.0223 * parameters.avg_wait_of_same_past_second 
	- 0.1265 * parameters.avg_latency_of_same_last_20 
	- 170293693.6366;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM57(work_wait &parameters) {
  double actual_remaining = 
	0.0296 * parameters.work_so_far 
	- 0.0064 * parameters.wait_so_far 
	+ 6173855.812 * parameters.num_locks_so_far 
	+ 366537.6182 * parameters.total_wait_locks 
	- 41.6818 * parameters.mean_wait_of_all 
	+ 3931977.8901 * parameters.cpu_usage 
	- 0.4513 * parameters.avg_work_of_same_past_second 
	- 0.0223 * parameters.avg_wait_of_same_past_second 
	- 0.1265 * parameters.avg_latency_of_same_last_20 
	+ 1359844429.4861;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM58(work_wait &parameters) {
  double actual_remaining = 
	0.0296 * parameters.work_so_far 
	- 0.1076 * parameters.wait_so_far 
	+ 6173855.812 * parameters.num_locks_so_far 
	- 716484.9869 * parameters.total_wait_locks 
	+ 0.6608 * parameters.mean_wait_of_all 
	+ 3931977.8901 * parameters.cpu_usage 
	- 0.28 * parameters.avg_work_of_same_past_second 
	- 0.0223 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	+ 555666157.3333;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM59(work_wait &parameters) {
  double actual_remaining = 
	0.0296 * parameters.work_so_far 
	- 0.235 * parameters.wait_so_far 
	+ 181184791.677 * parameters.num_locks_so_far 
	- 1831481.8975 * parameters.total_wait_locks 
	+ 1.0314 * parameters.mean_wait_of_all 
	+ 3931977.8901 * parameters.cpu_usage 
	+ 0.3112 * parameters.avg_work_of_same_past_second 
	- 0.0223 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	+ 302287018.5469;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM60(work_wait &parameters) {
  double actual_remaining = 
	1.0265 * parameters.work_so_far 
	- 0.0615 * parameters.wait_so_far 
	- 30368.3636 * parameters.num_locks_so_far 
	+ 403567.3504 * parameters.total_wait_locks 
	+ 0.2059 * parameters.mean_wait_of_all 
	+ 3931977.8901 * parameters.cpu_usage 
	+ 0.8219 * parameters.avg_work_of_same_past_second 
	- 0.8735 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	+ 220176606.6748;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM61(work_wait &parameters) {
  double actual_remaining = 
	2.1626 * parameters.work_so_far 
	- 0.0843 * parameters.wait_so_far 
	- 9113.2184 * parameters.num_locks_so_far 
	+ 8434.4285 * parameters.total_wait_locks 
	- 0.0596 * parameters.mean_wait_of_all 
	+ 26273.3219 * parameters.cpu_usage 
	+ 0.003 * parameters.avg_work_of_same_past_second 
	- 0.5337 * parameters.avg_wait_of_same_past_second 
	+ 0.0023 * parameters.avg_latency_of_same_last_20 
	+ 0.0436 * parameters.max_latency_of_same_last_50 
	+ 522645536.5464;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM62(work_wait &parameters) {
  double actual_remaining = 
	11.9365 * parameters.work_so_far 
	- 0.0039 * parameters.wait_so_far 
	- 9113.2184 * parameters.num_locks_so_far 
	+ 4169440.6119 * parameters.total_wait_locks 
	- 167.5926 * parameters.mean_wait_of_all 
	+ 709805666.9394 * parameters.cpu_usage 
	- 1.6741 * parameters.avg_work_of_same_past_second 
	+ 1.4048 * parameters.avg_wait_of_same_past_second 
	+ 0.0055 * parameters.avg_latency_of_same_last_20 
	+ 0.0761 * parameters.max_latency_of_same_last_50 
	+ 2765352459.8005;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM63(work_wait &parameters) {
  double actual_remaining = 
	0.8094 * parameters.work_so_far 
	- 0.1948 * parameters.wait_so_far 
	- 9113.2184 * parameters.num_locks_so_far 
	+ 467506.0768 * parameters.total_wait_locks 
	- 12.3866 * parameters.mean_wait_of_all 
	+ 60478096.9618 * parameters.cpu_usage 
	- 0.1089 * parameters.avg_work_of_same_past_second 
	+ 0.0706 * parameters.avg_wait_of_same_past_second 
	+ 0.0055 * parameters.avg_latency_of_same_last_20 
	+ 0.0048 * parameters.max_latency_of_same_last_50 
	+ 828720486.3799;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM64(work_wait &parameters) {
  double actual_remaining = 
	0.0046 * parameters.work_so_far 
	- 0.1034 * parameters.wait_so_far 
	- 9113.2184 * parameters.num_locks_so_far 
	+ 40007.5797 * parameters.total_wait_locks 
	+ 80.5248 * parameters.mean_wait_of_all 
	- 610532110.6257 * parameters.cpu_usage 
	- 0.0061 * parameters.avg_work_of_same_past_second 
	- 0.0055 * parameters.avg_wait_of_same_past_second 
	+ 0.1245 * parameters.avg_latency_of_same_last_20 
	- 1554072972.367;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM65(work_wait &parameters) {
  double actual_remaining = 
	0.0046 * parameters.work_so_far 
	- 0.0965 * parameters.wait_so_far 
	- 9113.2184 * parameters.num_locks_so_far 
	+ 40007.5797 * parameters.total_wait_locks 
	- 174.5751 * parameters.mean_wait_of_all 
	- 6577708.8896 * parameters.cpu_usage 
	+ 1.7524 * parameters.avg_work_of_same_past_second 
	- 0.0055 * parameters.avg_wait_of_same_past_second 
	+ 0.0139 * parameters.avg_latency_of_same_last_20 
	- 0.0025 * parameters.max_latency_of_same_last_50 
	+ 5443186751.6519;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM66(work_wait &parameters) {
  double actual_remaining = 
	0.0046 * parameters.work_so_far 
	- 0.1608 * parameters.wait_so_far 
	- 9113.2184 * parameters.num_locks_so_far 
	- 100289.4441 * parameters.total_wait_locks 
	+ 0.3022 * parameters.mean_wait_of_all 
	- 6577708.8896 * parameters.cpu_usage 
	+ 0.0292 * parameters.avg_work_of_same_past_second 
	- 0.0055 * parameters.avg_wait_of_same_past_second 
	+ 0.0132 * parameters.avg_latency_of_same_last_20 
	- 0.1058 * parameters.max_latency_of_same_last_50 
	+ 669016209.0699;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM67(work_wait &parameters) {
  double actual_remaining = 
	0.0046 * parameters.work_so_far 
	- 0.0205 * parameters.wait_so_far 
	- 9113.2184 * parameters.num_locks_so_far 
	- 270346.4427 * parameters.total_wait_locks 
	- 539.095 * parameters.mean_wait_of_all 
	- 6577708.8896 * parameters.cpu_usage 
	+ 0.0292 * parameters.avg_work_of_same_past_second 
	- 8.8711 * parameters.avg_wait_of_same_past_second 
	+ 0.0132 * parameters.avg_latency_of_same_last_20 
	- 0.0106 * parameters.max_latency_of_same_last_50 
	+ 22501969619.2495;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM68(work_wait &parameters) {
  double actual_remaining = 
	0.4103 * parameters.work_so_far 
	- 1.1978 * parameters.wait_so_far 
	- 263445.9165 * parameters.num_locks_so_far 
	- 139793.2876 * parameters.total_wait_locks 
	- 32.8551 * parameters.mean_wait_of_all 
	+ 579975.8799 * parameters.cpu_usage 
	+ 0.0465 * parameters.avg_work_of_same_past_second 
	- 0.0276 * parameters.avg_wait_of_same_past_second 
	+ 0.0018 * parameters.avg_latency_of_same_last_20 
	- 0.0669 * parameters.max_latency_of_same_last_50 
	+ 1661278184.3155;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM69(work_wait &parameters) {
  double actual_remaining = 
	0.5182 * parameters.work_so_far 
	- 0.083 * parameters.wait_so_far 
	- 263445.9165 * parameters.num_locks_so_far 
	- 3166746.1456 * parameters.total_wait_locks 
	+ 1.7556 * parameters.mean_wait_of_all 
	+ 579975.8799 * parameters.cpu_usage 
	+ 1.8323 * parameters.avg_work_of_same_past_second 
	- 0.9243 * parameters.avg_wait_of_same_past_second 
	+ 0.0018 * parameters.avg_latency_of_same_last_20 
	- 0.0041 * parameters.max_latency_of_same_last_50 
	+ 2259675720.641;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM70(work_wait &parameters) {
  double actual_remaining = 
	2.6416 * parameters.work_so_far 
	- 3.8758 * parameters.wait_so_far 
	- 263445.9165 * parameters.num_locks_so_far 
	- 1399510.4071 * parameters.total_wait_locks 
	+ 40.6207 * parameters.mean_wait_of_all 
	+ 579975.8799 * parameters.cpu_usage 
	- 0.2925 * parameters.avg_work_of_same_past_second 
	+ 0.3892 * parameters.avg_wait_of_same_past_second 
	+ 0.0018 * parameters.avg_latency_of_same_last_20 
	- 0.0008 * parameters.max_latency_of_same_last_50 
	- 70932603.9054;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM71(work_wait &parameters) {
  double actual_remaining = 
	5.3772 * parameters.work_so_far 
	- 7.014 * parameters.wait_so_far 
	- 263445.9165 * parameters.num_locks_so_far 
	- 3667613.9816 * parameters.total_wait_locks 
	+ 40.6207 * parameters.mean_wait_of_all 
	+ 579975.8799 * parameters.cpu_usage 
	- 0.2925 * parameters.avg_work_of_same_past_second 
	+ 2.6661 * parameters.avg_wait_of_same_past_second 
	- 1.3027 * parameters.avg_latency_of_same_last_20 
	- 0.0008 * parameters.max_latency_of_same_last_50 
	+ 1824865734.0946;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM72(work_wait &parameters) {
  double actual_remaining = 
	5.3772 * parameters.work_so_far 
	- 6.4889 * parameters.wait_so_far 
	- 263445.9165 * parameters.num_locks_so_far 
	- 3100588.088 * parameters.total_wait_locks 
	+ 40.6207 * parameters.mean_wait_of_all 
	+ 579975.8799 * parameters.cpu_usage 
	- 0.2925 * parameters.avg_work_of_same_past_second 
	+ 2.6661 * parameters.avg_wait_of_same_past_second 
	+ 0.3231 * parameters.avg_latency_of_same_last_20 
	- 0.0008 * parameters.max_latency_of_same_last_50 
	+ 910720668.5919;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM73(work_wait &parameters) {
  double actual_remaining = 
	4.4431 * parameters.work_so_far 
	- 6.3415 * parameters.wait_so_far 
	- 263445.9165 * parameters.num_locks_so_far 
	- 1399510.4071 * parameters.total_wait_locks 
	+ 40.6207 * parameters.mean_wait_of_all 
	+ 579975.8799 * parameters.cpu_usage 
	- 0.2925 * parameters.avg_work_of_same_past_second 
	+ 1.8886 * parameters.avg_wait_of_same_past_second 
	- 0.8573 * parameters.avg_latency_of_same_last_20 
	- 0.0008 * parameters.max_latency_of_same_last_50 
	- 18013059.8616;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM74(work_wait &parameters) {
  double actual_remaining = 
	1.2719 * parameters.work_so_far 
	- 0.2667 * parameters.wait_so_far 
	- 263445.9165 * parameters.num_locks_so_far 
	- 5199994.8118 * parameters.total_wait_locks 
	+ 175.3984 * parameters.mean_wait_of_all 
	+ 579975.8799 * parameters.cpu_usage 
	- 0.1046 * parameters.avg_work_of_same_past_second 
	+ 1.4375 * parameters.avg_wait_of_same_past_second 
	+ 0.3526 * parameters.avg_latency_of_same_last_20 
	- 0.0008 * parameters.max_latency_of_same_last_50 
	- 3011394736.5972;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM75(work_wait &parameters) {
  double actual_remaining = 
	0.3425 * parameters.work_so_far 
	- 0.061 * parameters.wait_so_far 
	- 263445.9165 * parameters.num_locks_so_far 
	- 1823487.8919 * parameters.total_wait_locks 
	+ 4.8409 * parameters.mean_wait_of_all 
	+ 579975.8799 * parameters.cpu_usage 
	+ 0.0026 * parameters.avg_work_of_same_past_second 
	- 0.5882 * parameters.avg_wait_of_same_past_second 
	+ 0.0018 * parameters.avg_latency_of_same_last_20 
	+ 0.1272 * parameters.max_latency_of_same_last_50 
	+ 1536360627.5581;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM76(work_wait &parameters) {
  double actual_remaining = 
	0.1705 * parameters.work_so_far 
	- 0.0088 * parameters.wait_so_far 
	- 124753536.8336 * parameters.num_locks_so_far 
	- 12442.3944 * parameters.total_wait_locks 
	+ 0.2589 * parameters.mean_wait_of_all 
	+ 15917124.2405 * parameters.cpu_usage 
	- 2.0998 * parameters.avg_work_of_same_past_second 
	+ 1.1561 * parameters.avg_wait_of_same_past_second 
	+ 0.0049 * parameters.avg_latency_of_same_last_20 
	+ 955617980.7858;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM77(work_wait &parameters) {
  double actual_remaining = 
	11.4297 * parameters.work_so_far 
	- 0.0088 * parameters.wait_so_far 
	- 2227991.3063 * parameters.num_locks_so_far 
	- 12442.3944 * parameters.total_wait_locks 
	+ 26.6032 * parameters.mean_wait_of_all 
	+ 16968814.4138 * parameters.cpu_usage 
	- 0.0238 * parameters.avg_work_of_same_past_second 
	+ 0.0073 * parameters.avg_wait_of_same_past_second 
	+ 0.2233 * parameters.avg_latency_of_same_last_20 
	- 893359990.8725;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM78(work_wait &parameters) {
  double actual_remaining = 
	0.0114 * parameters.work_so_far 
	- 0.085 * parameters.wait_so_far 
	+ 49019178.7863 * parameters.num_locks_so_far 
	- 129910.9187 * parameters.total_wait_locks 
	- 0.0485 * parameters.mean_wait_of_all 
	+ 579975.8799 * parameters.cpu_usage 
	+ 0.0026 * parameters.avg_work_of_same_past_second 
	- 0.1902 * parameters.avg_wait_of_same_past_second 
	+ 0.0765 * parameters.avg_latency_of_same_last_20 
	+ 261176772.4943;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM79(work_wait &parameters) {
  double actual_remaining = 
	0.118 * parameters.work_so_far 
	- 0.0052 * parameters.wait_so_far 
	- 115297635.0339 * parameters.num_locks_so_far 
	+ 854742.3774 * parameters.total_wait_locks 
	- 15.2624 * parameters.mean_wait_of_all 
	+ 28190699.9345 * parameters.cpu_usage 
	+ 0.0232 * parameters.avg_work_of_same_past_second 
	- 0.0231 * parameters.avg_wait_of_same_past_second 
	+ 0.0062 * parameters.avg_latency_of_same_last_20 
	+ 751372006.6234;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM80(work_wait &parameters) {
  double actual_remaining = 
	1.7958 * parameters.work_so_far 
	- 0.0093 * parameters.wait_so_far 
	+ 3086081.1189 * parameters.num_locks_so_far 
	+ 2637424.7885 * parameters.total_wait_locks 
	- 78.9737 * parameters.mean_wait_of_all 
	+ 775096309.0068 * parameters.cpu_usage 
	+ 0.6279 * parameters.avg_work_of_same_past_second 
	- 0.035 * parameters.avg_wait_of_same_past_second 
	+ 0.0062 * parameters.avg_latency_of_same_last_20 
	+ 677089684.9165;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM81(work_wait &parameters) {
  double actual_remaining = 
	0.2347 * parameters.work_so_far 
	- 0.4538 * parameters.wait_so_far 
	+ 9090419.8607 * parameters.num_locks_so_far 
	+ 210194.2598 * parameters.total_wait_locks 
	- 6.3613 * parameters.mean_wait_of_all 
	+ 67316081.8167 * parameters.cpu_usage 
	+ 0.0563 * parameters.avg_work_of_same_past_second 
	- 0.0681 * parameters.avg_wait_of_same_past_second 
	+ 0.0062 * parameters.avg_latency_of_same_last_20 
	+ 459512396.5587;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM82(work_wait &parameters) {
  double actual_remaining = 
	-4.0829 * parameters.work_so_far 
	- 0.0009 * parameters.wait_so_far 
	- 9113.2184 * parameters.num_locks_so_far 
	+ 23443.3631 * parameters.total_wait_locks 
	- 0.7681 * parameters.mean_wait_of_all 
	+ 821551363.7834 * parameters.cpu_usage 
	+ 0.013 * parameters.avg_work_of_same_past_second 
	- 0.7679 * parameters.avg_wait_of_same_past_second 
	+ 0.0227 * parameters.avg_latency_of_same_last_20 
	+ 0.0969 * parameters.max_latency_of_same_last_50 
	- 327967694.432;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM83(work_wait &parameters) {
  double actual_remaining = 
	9.2108 * parameters.work_so_far 
	- 0.0009 * parameters.wait_so_far 
	- 9113.2184 * parameters.num_locks_so_far 
	- 1128761.4863 * parameters.total_wait_locks 
	- 6.5103 * parameters.mean_wait_of_all 
	+ 1217386143.525 * parameters.cpu_usage 
	+ 0.3302 * parameters.avg_work_of_same_past_second 
	- 1.8737 * parameters.avg_wait_of_same_past_second 
	+ 2.0093 * parameters.avg_latency_of_same_last_20 
	+ 0.012 * parameters.max_latency_of_same_last_50 
	- 1113996710.0445;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM84(work_wait &parameters) {
  double actual_remaining = 
	-13.6779 * parameters.work_so_far 
	- 0.0009 * parameters.wait_so_far 
	- 9113.2184 * parameters.num_locks_so_far 
	- 1128761.4863 * parameters.total_wait_locks 
	- 8.0057 * parameters.mean_wait_of_all 
	+ 1275848392.7045 * parameters.cpu_usage 
	+ 0.3302 * parameters.avg_work_of_same_past_second 
	- 4.6131 * parameters.avg_wait_of_same_past_second 
	+ 0.8172 * parameters.avg_latency_of_same_last_20 
	+ 0.012 * parameters.max_latency_of_same_last_50 
	+ 1255909719.0432;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM85(work_wait &parameters) {
  double actual_remaining = 
	0.052 * parameters.work_so_far 
	- 0.0009 * parameters.wait_so_far 
	- 9113.2184 * parameters.num_locks_so_far 
	- 724895.869 * parameters.total_wait_locks 
	+ 13.9554 * parameters.mean_wait_of_all 
	+ 106603409.115 * parameters.cpu_usage 
	+ 0.219 * parameters.avg_work_of_same_past_second 
	- 0.6556 * parameters.avg_wait_of_same_past_second 
	+ 0.1624 * parameters.avg_latency_of_same_last_20 
	+ 0.012 * parameters.max_latency_of_same_last_50 
	+ 351956776.3427;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
tpcc_estimate(work_wait &parameters){

  if (parameters.avg_work_of_same_past_second <= 142878500) {

    if (parameters.wait_so_far <= 437744683.5) {

      if (parameters.work_so_far <= 39729.5) {
        return tpcc_LM1(parameters);
      } else {

        if (parameters.num_locks_so_far <= 3) {

          if (parameters.avg_latency_of_same_last_20 <= 593926500) {

            if (parameters.wait_so_far <= 25651311) {

              if (parameters.wait_so_far <= 3548792.5) {

                if (parameters.mean_wait_of_all <= 28038800) {
                  return tpcc_LM2(parameters);
                } else {

                  if (parameters.cpu_usage <= 0.935) {
                    return tpcc_LM3(parameters);
                  } else {

                    if (parameters.avg_work_of_same_past_second <= 38451950) {

                      if (parameters.avg_work_of_same_past_second <= 33788250) {
                        return tpcc_LM4(parameters);
                      } else {

                        if (parameters.avg_latency_of_same_last_20 <= 486474000) {

                          if (parameters.avg_work_of_same_past_second <= 35706200) {
                            return tpcc_LM5(parameters);
                          } else {
                            return tpcc_LM6(parameters);
                          }
                        } else {
                          return tpcc_LM7(parameters);
                        }
                      }
                    } else {

                      if (parameters.wait_so_far <= 983235.5) {
                        return tpcc_LM8(parameters);
                      } else {

                        if (parameters.avg_latency_of_same_last_20 <= 551290500) {
                          return tpcc_LM9(parameters);
                        } else {
                          return tpcc_LM10(parameters);
                        }
                      }
                    }
                  }
                }
              } else {
                return tpcc_LM11(parameters);
              }
            } else {

              if (parameters.wait_so_far <= 243370597.5) {

                if (parameters.cpu_usage <= 0.979) {

                  if (parameters.work_so_far <= 2545259.5) {

                    if (parameters.avg_latency_of_same_last_20 <= 415057500) {

                      if (parameters.avg_work_of_same_past_second <= 31849850) {

                        if (parameters.cpu_usage <= 0.91) {

                          if (parameters.avg_latency_of_same_last_20 <= 369744000) {

                            if (parameters.mean_wait_of_all <= 20469800) {
                              return tpcc_LM12(parameters);
                            } else {

                              if (parameters.work_so_far <= 44457) {
                                return tpcc_LM13(parameters);
                              } else {
                                return tpcc_LM14(parameters);
                              }
                            }
                          } else {
                            return tpcc_LM15(parameters);
                          }
                        } else {
                          return tpcc_LM16(parameters);
                        }
                      } else {

                        if (parameters.avg_wait_of_same_past_second <= 382932500) {

                          if (parameters.max_latency_of_same_last_50 <= 1175480000) {

                            if (parameters.avg_work_of_same_past_second <= 37225650) {

                              if (parameters.avg_work_of_same_past_second <= 36145750) {
                                return tpcc_LM17(parameters);
                              } else {
                                return tpcc_LM18(parameters);
                              }
                            } else {

                              if (parameters.avg_work_of_same_past_second <= 45945450) {
                                return tpcc_LM19(parameters);
                              } else {

                                if (parameters.total_wait_locks <= 169.5) {
                                  return tpcc_LM20(parameters);
                                } else {
                                  return tpcc_LM21(parameters);
                                }
                              }
                            }
                          } else {
                            return tpcc_LM22(parameters);
                          }
                        } else {
                          return tpcc_LM23(parameters);
                        }
                      }
                    } else {
                      return tpcc_LM24(parameters);
                    }
                  } else {
                    return tpcc_LM25(parameters);
                  }
                } else {
                  return tpcc_LM26(parameters);
                }
              } else {

                if (parameters.avg_latency_of_same_last_20 <= 338357000) {
                  return tpcc_LM27(parameters);
                } else {

                  if (parameters.max_latency_of_same_last_50 <= 1245255000) {

                    if (parameters.avg_wait_of_same_past_second <= 353148500) {
                      return tpcc_LM28(parameters);
                    } else {

                      if (parameters.max_latency_of_same_last_50 <= 1179645000) {
                        return tpcc_LM29(parameters);
                      } else {

                        if (parameters.work_so_far <= 57444.5) {
                          return tpcc_LM30(parameters);
                        } else {

                          if (parameters.avg_work_of_same_past_second <= 30831300) {
                            return tpcc_LM31(parameters);
                          } else {
                            return tpcc_LM32(parameters);
                          }
                        }
                      }
                    }
                  } else {
                    return tpcc_LM33(parameters);
                  }
                }
              }
            }
          } else {

            if (parameters.wait_so_far <= 277186803.5) {

              if (parameters.total_wait_locks <= 581) {
                return tpcc_LM34(parameters);
              } else {

                if (parameters.max_latency_of_same_last_50 <= 1803070000) {
                  return tpcc_LM35(parameters);
                } else {

                  if (parameters.avg_wait_of_same_past_second <= 476929500) {

                    if (parameters.avg_latency_of_same_last_20 <= 694758000) {
                      return tpcc_LM36(parameters);
                    } else {

                      if (parameters.avg_latency_of_same_last_20 <= 940942000) {
                        return tpcc_LM37(parameters);
                      } else {
                        return tpcc_LM38(parameters);
                      }
                    }
                  } else {

                    if (parameters.wait_so_far <= 42707446) {

                      if (parameters.total_wait_locks <= 619.5) {
                        return tpcc_LM39(parameters);
                      } else {
                        return tpcc_LM40(parameters);
                      }
                    } else {
                      return tpcc_LM41(parameters);
                    }
                  }
                }
              }
            } else {
              return tpcc_LM42(parameters);
            }
          }
        } else {

          if (parameters.total_wait_locks <= 202.5) {

            if (parameters.total_wait_locks <= 139.5) {
              return tpcc_LM43(parameters);
            } else {

              if (parameters.mean_wait_of_all <= 7517055) {

                if (parameters.avg_work_of_same_past_second <= 130857000) {
                  return tpcc_LM44(parameters);
                } else {
                  return tpcc_LM45(parameters);
                }
              } else {
                return tpcc_LM46(parameters);
              }
            }
          } else {
            return tpcc_LM47(parameters);
          }
        }
      }
    } else {
      return tpcc_LM48(parameters);
    }
  } else {

    if (parameters.mean_wait_of_all <= 27842400) {

      if (parameters.mean_wait_of_all <= 21145200) {
        return tpcc_LM49(parameters);
      } else {

        if (parameters.cpu_usage <= 0.951) {
          return tpcc_LM50(parameters);
        } else {

          if (parameters.avg_work_of_same_past_second <= 180433500) {
            return tpcc_LM51(parameters);
          } else {

            if (parameters.avg_work_of_same_past_second <= 196094000) {

              if (parameters.avg_work_of_same_past_second <= 189436500) {

                if (parameters.avg_work_of_same_past_second <= 183050000) {

                  if (parameters.avg_latency_of_same_last_20 <= 242701500) {
                    return tpcc_LM52(parameters);
                  } else {

                    if (parameters.avg_work_of_same_past_second <= 182495000) {
                      return tpcc_LM53(parameters);
                    } else {

                      if (parameters.total_wait_locks <= 471.5) {

                        if (parameters.total_wait_locks <= 374.5) {
                          return tpcc_LM54(parameters);
                        } else {

                          if (parameters.wait_so_far <= 65286441.5) {
                            return tpcc_LM55(parameters);
                          } else {
                            return tpcc_LM56(parameters);
                          }
                        }
                      } else {
                        return tpcc_LM57(parameters);
                      }
                    }
                  }
                } else {
                  return tpcc_LM58(parameters);
                }
              } else {
                return tpcc_LM59(parameters);
              }
            } else {
              return tpcc_LM60(parameters);
            }
          }
        }
      }
    } else {

      if (parameters.mean_wait_of_all <= 34215900) {

        if (parameters.mean_wait_of_all <= 30673150) {
          return tpcc_LM61(parameters);
        } else {

          if (parameters.avg_wait_of_same_past_second <= 361775000) {

            if (parameters.total_wait_locks <= 615.5) {
              return tpcc_LM62(parameters);
            } else {
              return tpcc_LM63(parameters);
            }
          } else {

            if (parameters.mean_wait_of_all <= 32431600) {
              return tpcc_LM64(parameters);
            } else {

              if (parameters.mean_wait_of_all <= 33275650) {
                return tpcc_LM65(parameters);
              } else {

                if (parameters.avg_wait_of_same_past_second <= 405194000) {
                  return tpcc_LM66(parameters);
                } else {
                  return tpcc_LM67(parameters);
                }
              }
            }
          }
        }
      } else {

        if (parameters.avg_latency_of_same_last_20 <= 594008500) {

          if (parameters.wait_so_far <= 86195163) {

            if (parameters.mean_wait_of_all <= 39911950) {

              if (parameters.mean_wait_of_all <= 36378150) {

                if (parameters.work_so_far <= 66872) {
                  return tpcc_LM68(parameters);
                } else {
                  return tpcc_LM69(parameters);
                }
              } else {

                if (parameters.max_latency_of_same_last_50 <= 1227725000) {

                  if (parameters.avg_work_of_same_past_second <= 220509500) {

                    if (parameters.avg_latency_of_same_last_20 <= 226773500) {
                      return tpcc_LM70(parameters);
                    } else {

                      if (parameters.avg_latency_of_same_last_20 <= 304250500) {

                        if (parameters.total_wait_locks <= 686) {
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
                } else {
                  return tpcc_LM75(parameters);
                }
              }
            } else {

              if (parameters.avg_work_of_same_past_second <= 215889500) {
                return tpcc_LM76(parameters);
              } else {
                return tpcc_LM77(parameters);
              }
            }
          } else {
            return tpcc_LM78(parameters);
          }
        } else {

          if (parameters.wait_so_far <= 433280363.5) {

            if (parameters.work_so_far <= 94590) {
              return tpcc_LM79(parameters);
            } else {

              if (parameters.avg_wait_of_same_past_second <= 373997000) {
                return tpcc_LM80(parameters);
              } else {
                return tpcc_LM81(parameters);
              }
            }
          } else {

            if (parameters.avg_latency_of_same_last_20 <= 912236500) {
              return tpcc_LM82(parameters);
            } else {

              if (parameters.wait_so_far <= 662601446) {

                if (parameters.cpu_usage <= 0.985) {
                  return tpcc_LM83(parameters);
                } else {
                  return tpcc_LM84(parameters);
                }
              } else {
                return tpcc_LM85(parameters);
              }
            }
          }
        }
      }
    }
  }
}