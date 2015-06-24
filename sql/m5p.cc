#include "my_global.h"
#include "m5p.h"
#include "trace_tool.h"

static
double
new_order_LM1(work_wait &parameters) {
  double actual_remaining = 
	0.004 * parameters.work_so_far 
	- 0.0015 * parameters.wait_so_far 
	- 2160866.6705 * parameters.num_locks_so_far 
	+ 542064.2863 * parameters.total_wait_locks 
	- 0.0089 * parameters.mean_wait_of_all 
	- 192793289.3535 * parameters.cpu_usage 
	+ 0.9445 * parameters.avg_work_of_same_past_second 
	- 0.0038 * parameters.avg_wait_of_same_past_second 
	+ 0.1304 * parameters.avg_latency_of_same_last_20 
	- 0.0007 * parameters.max_latency_of_same_last_50 
	+ 175845388.19;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM2(work_wait &parameters) {
  double actual_remaining = 
	-0.0111 * parameters.work_so_far 
	- 0.0015 * parameters.wait_so_far 
	- 70681.0727 * parameters.num_locks_so_far 
	+ 13986.8486 * parameters.total_wait_locks 
	- 0.0089 * parameters.mean_wait_of_all 
	- 3107566.8034 * parameters.cpu_usage 
	+ 0.0039 * parameters.avg_work_of_same_past_second 
	- 0.0068 * parameters.avg_wait_of_same_past_second 
	+ 0.1121 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	+ 37789635.8994;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM3(work_wait &parameters) {
  double actual_remaining = 
	-0.0526 * parameters.work_so_far 
	- 0.0015 * parameters.wait_so_far 
	- 70681.0727 * parameters.num_locks_so_far 
	+ 13986.8486 * parameters.total_wait_locks 
	- 0.0089 * parameters.mean_wait_of_all 
	- 3107566.8034 * parameters.cpu_usage 
	+ 0.0146 * parameters.avg_work_of_same_past_second 
	- 0.0148 * parameters.avg_wait_of_same_past_second 
	+ 0.0218 * parameters.avg_latency_of_same_last_20 
	- 0.0018 * parameters.max_latency_of_same_last_50 
	+ 62676257.1064;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM4(work_wait &parameters) {
  double actual_remaining = 
	0.3529 * parameters.work_so_far 
	- 0.1025 * parameters.wait_so_far 
	- 2995705.6328 * parameters.num_locks_so_far 
	+ 967696.8366 * parameters.total_wait_locks 
	- 1.471 * parameters.mean_wait_of_all 
	- 189180209.147 * parameters.cpu_usage 
	- 0.1514 * parameters.avg_wait_of_same_past_second 
	+ 0.1527 * parameters.avg_latency_of_same_last_20 
	- 0.049 * parameters.max_latency_of_same_last_50 
	+ 271868445.4597;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM5(work_wait &parameters) {
  double actual_remaining = 
	0.0043 * parameters.work_so_far 
	- 0.0032 * parameters.wait_so_far 
	- 5044934.6886 * parameters.num_locks_so_far 
	+ 666723.5166 * parameters.total_wait_locks 
	- 1.396 * parameters.mean_wait_of_all 
	- 233679346.5919 * parameters.cpu_usage 
	- 0.1342 * parameters.avg_wait_of_same_past_second 
	+ 0.0028 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 402357637.7894;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM6(work_wait &parameters) {
  double actual_remaining = 
	0.0166 * parameters.work_so_far 
	- 0.0034 * parameters.wait_so_far 
	- 188600.8995 * parameters.num_locks_so_far 
	- 1431115.4527 * parameters.total_wait_locks 
	+ 5.6637 * parameters.mean_wait_of_all 
	- 1994949.6724 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.1203 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	+ 357840386.1975;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM7(work_wait &parameters) {
  double actual_remaining = 
	0.0277 * parameters.work_so_far 
	- 0.0034 * parameters.wait_so_far 
	- 9878572.2026 * parameters.num_locks_so_far 
	- 494334.7705 * parameters.total_wait_locks 
	+ 2.3337 * parameters.mean_wait_of_all 
	- 1994949.6724 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.2163 * parameters.avg_latency_of_same_last_20 
	- 0.0914 * parameters.max_latency_of_same_last_50 
	+ 399459406.8094;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM8(work_wait &parameters) {
  double actual_remaining = 
	0.7744 * parameters.work_so_far 
	- 0.4708 * parameters.wait_so_far 
	- 8086452.9949 * parameters.num_locks_so_far 
	- 2328328.1283 * parameters.total_wait_locks 
	+ 6.6957 * parameters.mean_wait_of_all 
	- 3015929.2269 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0041 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 586201666.217;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM9(work_wait &parameters) {
  double actual_remaining = 
	0.0035 * parameters.work_so_far 
	- 0.0051 * parameters.wait_so_far 
	- 1651875.3653 * parameters.num_locks_so_far 
	+ 1631630.5293 * parameters.total_wait_locks 
	- 17.7681 * parameters.mean_wait_of_all 
	- 3015929.2269 * parameters.cpu_usage 
	- 3.5157 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0041 * parameters.avg_latency_of_same_last_20 
	- 0.1473 * parameters.max_latency_of_same_last_50 
	+ 2550161424.0007;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM10(work_wait &parameters) {
  double actual_remaining = 
	0.0035 * parameters.work_so_far 
	- 0.0051 * parameters.wait_so_far 
	- 1765433.8955 * parameters.num_locks_so_far 
	- 15518.7652 * parameters.total_wait_locks 
	- 0.019 * parameters.mean_wait_of_all 
	- 3015929.2269 * parameters.cpu_usage 
	+ 0.0323 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0041 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 242354312.9314;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM11(work_wait &parameters) {
  double actual_remaining = 
	2.3404 * parameters.work_so_far 
	- 0.0051 * parameters.wait_so_far 
	- 2423850.9758 * parameters.num_locks_so_far 
	- 15518.7652 * parameters.total_wait_locks 
	- 0.019 * parameters.mean_wait_of_all 
	- 3015929.2269 * parameters.cpu_usage 
	+ 0.0884 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0041 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 324650555.1494;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM12(work_wait &parameters) {
  double actual_remaining = 
	0.0035 * parameters.work_so_far 
	- 0.0051 * parameters.wait_so_far 
	- 286046.7739 * parameters.num_locks_so_far 
	- 20013.1845 * parameters.total_wait_locks 
	+ 0.0393 * parameters.mean_wait_of_all 
	- 3015929.2269 * parameters.cpu_usage 
	+ 0.3081 * parameters.avg_wait_of_same_past_second 
	+ 0.0041 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 154665062.985;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM13(work_wait &parameters) {
  double actual_remaining = 
	0.0035 * parameters.work_so_far 
	- 0.0029 * parameters.wait_so_far 
	- 212388.1897 * parameters.num_locks_so_far 
	- 1087897.5389 * parameters.total_wait_locks 
	+ 3.806 * parameters.mean_wait_of_all 
	- 5926244.0898 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.2943 * parameters.avg_latency_of_same_last_20 
	- 0.119 * parameters.max_latency_of_same_last_50 
	+ 408846806.1681;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM14(work_wait &parameters) {
  double actual_remaining = 
	0.0275 * parameters.work_so_far 
	- 0.4673 * parameters.wait_so_far 
	- 104758.1068 * parameters.num_locks_so_far 
	+ 500333.1937 * parameters.total_wait_locks 
	- 1.1509 * parameters.mean_wait_of_all 
	- 18123000.9877 * parameters.cpu_usage 
	- 0.248 * parameters.avg_wait_of_same_past_second 
	+ 0.3412 * parameters.avg_latency_of_same_last_20 
	- 0.0504 * parameters.max_latency_of_same_last_50 
	+ 255032042.0954;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM15(work_wait &parameters) {
  double actual_remaining = 
	0.1022 * parameters.work_so_far 
	- 0.0212 * parameters.wait_so_far 
	- 104758.1068 * parameters.num_locks_so_far 
	+ 89276.0112 * parameters.total_wait_locks 
	+ 0.371 * parameters.mean_wait_of_all 
	- 976962681.8999 * parameters.cpu_usage 
	- 0.1381 * parameters.avg_wait_of_same_past_second 
	+ 0.0188 * parameters.avg_latency_of_same_last_20 
	- 0.0008 * parameters.max_latency_of_same_last_50 
	+ 1064806818.7734;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM16(work_wait &parameters) {
  double actual_remaining = 
	0.1022 * parameters.work_so_far 
	- 0.0212 * parameters.wait_so_far 
	- 104758.1068 * parameters.num_locks_so_far 
	+ 192757.1067 * parameters.total_wait_locks 
	- 2.3671 * parameters.mean_wait_of_all 
	- 321969536.6915 * parameters.cpu_usage 
	- 0.1381 * parameters.avg_wait_of_same_past_second 
	+ 0.0188 * parameters.avg_latency_of_same_last_20 
	+ 0.1844 * parameters.max_latency_of_same_last_50 
	+ 535331344.8284;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM17(work_wait &parameters) {
  double actual_remaining = 
	0.1022 * parameters.work_so_far 
	- 0.0212 * parameters.wait_so_far 
	- 104758.1068 * parameters.num_locks_so_far 
	+ 192757.1067 * parameters.total_wait_locks 
	- 11.7237 * parameters.mean_wait_of_all 
	- 321969536.6915 * parameters.cpu_usage 
	- 0.1381 * parameters.avg_wait_of_same_past_second 
	+ 0.0188 * parameters.avg_latency_of_same_last_20 
	+ 0.281 * parameters.max_latency_of_same_last_50 
	+ 1371370014.0021;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM18(work_wait &parameters) {
  double actual_remaining = 
	1.686 * parameters.work_so_far 
	- 0.0212 * parameters.wait_so_far 
	- 104758.1068 * parameters.num_locks_so_far 
	+ 9817.3129 * parameters.total_wait_locks 
	+ 0.398 * parameters.mean_wait_of_all 
	- 37711914.8102 * parameters.cpu_usage 
	+ 1.0837 * parameters.avg_work_of_same_past_second 
	- 0.8118 * parameters.avg_wait_of_same_past_second 
	+ 0.0188 * parameters.avg_latency_of_same_last_20 
	- 0.0008 * parameters.max_latency_of_same_last_50 
	+ 176517380.6386;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM19(work_wait &parameters) {
  double actual_remaining = 
	0.0516 * parameters.work_so_far 
	- 0.0212 * parameters.wait_so_far 
	- 104758.1068 * parameters.num_locks_so_far 
	+ 9817.3129 * parameters.total_wait_locks 
	+ 1.9458 * parameters.mean_wait_of_all 
	- 35243849.6168 * parameters.cpu_usage 
	- 0.4415 * parameters.avg_wait_of_same_past_second 
	+ 0.0188 * parameters.avg_latency_of_same_last_20 
	- 0.0008 * parameters.max_latency_of_same_last_50 
	+ 175110091.5214;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM20(work_wait &parameters) {
  double actual_remaining = 
	0.0258 * parameters.work_so_far 
	- 0.0258 * parameters.wait_so_far 
	- 104758.1068 * parameters.num_locks_so_far 
	+ 9028.0186 * parameters.total_wait_locks 
	+ 0.7177 * parameters.mean_wait_of_all 
	- 14451184.5799 * parameters.cpu_usage 
	- 0.268 * parameters.avg_wait_of_same_past_second 
	+ 0.2935 * parameters.avg_latency_of_same_last_20 
	- 0.0584 * parameters.max_latency_of_same_last_50 
	+ 109457800.6237;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM21(work_wait &parameters) {
  double actual_remaining = 
	0.0077 * parameters.work_so_far 
	- 0.2287 * parameters.wait_so_far 
	- 4008213.7959 * parameters.num_locks_so_far 
	- 1308931.9591 * parameters.total_wait_locks 
	+ 3.7137 * parameters.mean_wait_of_all 
	- 5383265.7877 * parameters.cpu_usage 
	- 0.556 * parameters.avg_work_of_same_past_second 
	+ 0.2254 * parameters.avg_wait_of_same_past_second 
	+ 0.2298 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 450095499.9158;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM22(work_wait &parameters) {
  double actual_remaining = 
	0.0077 * parameters.work_so_far 
	+ 0.1164 * parameters.wait_so_far 
	- 520226.5003 * parameters.num_locks_so_far 
	- 17200.6666 * parameters.total_wait_locks 
	- 10.1406 * parameters.mean_wait_of_all 
	- 5383265.7877 * parameters.cpu_usage 
	+ 0.9921 * parameters.avg_work_of_same_past_second 
	- 0.0031 * parameters.avg_wait_of_same_past_second 
	- 0.0457 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 1414881318.7463;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM23(work_wait &parameters) {
  double actual_remaining = 
	47.2729 * parameters.work_so_far 
	+ 0.2266 * parameters.wait_so_far 
	- 520226.5003 * parameters.num_locks_so_far 
	- 17200.6666 * parameters.total_wait_locks 
	+ 0.071 * parameters.mean_wait_of_all 
	- 710354672.7409 * parameters.cpu_usage 
	- 1.3338 * parameters.avg_work_of_same_past_second 
	- 0.0031 * parameters.avg_wait_of_same_past_second 
	- 2.075 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 1905041251.531;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM24(work_wait &parameters) {
  double actual_remaining = 
	-1.1871 * parameters.work_so_far 
	+ 0.8643 * parameters.wait_so_far 
	- 520226.5003 * parameters.num_locks_so_far 
	+ 295362.8025 * parameters.total_wait_locks 
	- 5.2436 * parameters.mean_wait_of_all 
	+ 383728265.2558 * parameters.cpu_usage 
	- 0.371 * parameters.avg_work_of_same_past_second 
	- 0.0031 * parameters.avg_wait_of_same_past_second 
	- 0.3488 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 279802552.5531;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM25(work_wait &parameters) {
  double actual_remaining = 
	-1.2694 * parameters.work_so_far 
	+ 0.8643 * parameters.wait_so_far 
	- 520226.5003 * parameters.num_locks_so_far 
	+ 316918.9038 * parameters.total_wait_locks 
	- 0.4594 * parameters.mean_wait_of_all 
	+ 383728265.2558 * parameters.cpu_usage 
	- 0.3523 * parameters.avg_work_of_same_past_second 
	- 0.0031 * parameters.avg_wait_of_same_past_second 
	- 0.3488 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 407061821.7682;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM26(work_wait &parameters) {
  double actual_remaining = 
	-1.2694 * parameters.work_so_far 
	+ 0.8643 * parameters.wait_so_far 
	- 520226.5003 * parameters.num_locks_so_far 
	+ 316918.9038 * parameters.total_wait_locks 
	+ 1.2433 * parameters.mean_wait_of_all 
	+ 383728265.2558 * parameters.cpu_usage 
	- 0.3523 * parameters.avg_work_of_same_past_second 
	- 0.0031 * parameters.avg_wait_of_same_past_second 
	- 0.3488 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 634336379.2755;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM27(work_wait &parameters) {
  double actual_remaining = 
	0.0077 * parameters.work_so_far 
	+ 3.9002 * parameters.wait_so_far 
	- 520226.5003 * parameters.num_locks_so_far 
	- 17200.6666 * parameters.total_wait_locks 
	- 8.1068 * parameters.mean_wait_of_all 
	+ 1021202697.663 * parameters.cpu_usage 
	- 0.6422 * parameters.avg_work_of_same_past_second 
	- 0.0031 * parameters.avg_wait_of_same_past_second 
	- 0.3488 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 853057701.8302;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM28(work_wait &parameters) {
  double actual_remaining = 
	0.0077 * parameters.work_so_far 
	+ 3.1611 * parameters.wait_so_far 
	- 520226.5003 * parameters.num_locks_so_far 
	- 17200.6666 * parameters.total_wait_locks 
	- 8.1068 * parameters.mean_wait_of_all 
	+ 1021202697.663 * parameters.cpu_usage 
	- 0.6422 * parameters.avg_work_of_same_past_second 
	- 0.0031 * parameters.avg_wait_of_same_past_second 
	- 0.3488 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 578146965.2693;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM29(work_wait &parameters) {
  double actual_remaining = 
	0.0077 * parameters.work_so_far 
	- 0.0049 * parameters.wait_so_far 
	- 329836.7004 * parameters.num_locks_so_far 
	- 31417.3577 * parameters.total_wait_locks 
	+ 0.1093 * parameters.mean_wait_of_all 
	- 310991983.2579 * parameters.cpu_usage 
	- 0.0031 * parameters.avg_wait_of_same_past_second 
	+ 0.0055 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 459749115.858;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM30(work_wait &parameters) {
  double actual_remaining = 
	0.0025 * parameters.work_so_far 
	- 0.0284 * parameters.wait_so_far 
	- 2489115.0284 * parameters.num_locks_so_far 
	- 342077.1998 * parameters.total_wait_locks 
	+ 1.5884 * parameters.mean_wait_of_all 
	- 206582195.1015 * parameters.cpu_usage 
	+ 0.2664 * parameters.avg_work_of_same_past_second 
	- 0.0955 * parameters.avg_wait_of_same_past_second 
	+ 0.1467 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 257028373.8838;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM31(work_wait &parameters) {
  double actual_remaining = 
	0.0019 * parameters.work_so_far 
	- 0.1174 * parameters.wait_so_far 
	- 3547605.7325 * parameters.num_locks_so_far 
	- 630992.9985 * parameters.total_wait_locks 
	+ 2.6997 * parameters.mean_wait_of_all 
	- 2220001.2286 * parameters.cpu_usage 
	- 0.0005 * parameters.avg_wait_of_same_past_second 
	+ 0.2325 * parameters.avg_latency_of_same_last_20 
	- 0.0541 * parameters.max_latency_of_same_last_50 
	+ 243851217.41;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
new_order_estimate(work_wait &parameters){

  if (parameters.total_wait_locks <= 170.5) {

    if (parameters.total_wait_locks <= 69.5) {

      if (parameters.avg_work_of_same_past_second <= 55700750) {
        return new_order_LM1(parameters);
      } else {

        if (parameters.avg_latency_of_same_last_20 <= 131212000) {
          return new_order_LM2(parameters);
        } else {
          return new_order_LM3(parameters);
        }
      }
    } else {
      return new_order_LM4(parameters);
    }
  } else {

    if (parameters.wait_so_far <= 232915154) {

      if (parameters.mean_wait_of_all <= 64118700) {
        return new_order_LM5(parameters);
      } else {

        if (parameters.wait_so_far <= 50590166.5) {

          if (parameters.work_so_far <= 85140) {
            return new_order_LM6(parameters);
          } else {
            return new_order_LM7(parameters);
          }
        } else {

          if (parameters.avg_latency_of_same_last_20 <= 493413000) {

            if (parameters.mean_wait_of_all <= 104018500) {
              return new_order_LM8(parameters);
            } else {

              if (parameters.total_wait_locks <= 510.5) {

                if (parameters.avg_work_of_same_past_second <= 203234500) {
                  return new_order_LM9(parameters);
                } else {

                  if (parameters.avg_work_of_same_past_second <= 270512500) {
                    return new_order_LM10(parameters);
                  } else {
                    return new_order_LM11(parameters);
                  }
                }
              } else {
                return new_order_LM12(parameters);
              }
            }
          } else {
            return new_order_LM13(parameters);
          }
        }
      }
    } else {

      if (parameters.avg_latency_of_same_last_20 <= 497055500) {

        if (parameters.wait_so_far <= 469744990) {

          if (parameters.mean_wait_of_all <= 98860100) {

            if (parameters.wait_so_far <= 400646314.5) {

              if (parameters.avg_latency_of_same_last_20 <= 316449000) {
                return new_order_LM14(parameters);
              } else {

                if (parameters.cpu_usage <= 0.939) {

                  if (parameters.avg_work_of_same_past_second <= 175735500) {

                    if (parameters.mean_wait_of_all <= 68771800) {
                      return new_order_LM15(parameters);
                    } else {

                      if (parameters.max_latency_of_same_last_50 <= 1230730000) {
                        return new_order_LM16(parameters);
                      } else {
                        return new_order_LM17(parameters);
                      }
                    }
                  } else {
                    return new_order_LM18(parameters);
                  }
                } else {
                  return new_order_LM19(parameters);
                }
              }
            } else {
              return new_order_LM20(parameters);
            }
          } else {

            if (parameters.total_wait_locks <= 602.5) {

              if (parameters.mean_wait_of_all <= 137546000) {
                return new_order_LM21(parameters);
              } else {

                if (parameters.wait_so_far <= 378590680.5) {
                  return new_order_LM22(parameters);
                } else {

                  if (parameters.cpu_usage <= 0.888) {
                    return new_order_LM23(parameters);
                  } else {

                    if (parameters.cpu_usage <= 0.971) {

                      if (parameters.avg_work_of_same_past_second <= 205903500) {
                        return new_order_LM24(parameters);
                      } else {

                        if (parameters.mean_wait_of_all <= 143560500) {
                          return new_order_LM25(parameters);
                        } else {
                          return new_order_LM26(parameters);
                        }
                      }
                    } else {

                      if (parameters.total_wait_locks <= 587) {
                        return new_order_LM27(parameters);
                      } else {
                        return new_order_LM28(parameters);
                      }
                    }
                  }
                }
              }
            } else {
              return new_order_LM29(parameters);
            }
          }
        } else {
          return new_order_LM30(parameters);
        }
      } else {
        return new_order_LM31(parameters);
      }
    }
  }
}
static
double
payment_LM1(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	+ 0.0275 * parameters.wait_so_far 
	+ 816.2333 * parameters.total_wait_locks 
	+ 0.0004 * parameters.mean_wait_of_all 
	- 90750.1035 * parameters.cpu_usage 
	- 0.0499 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0508 * parameters.avg_latency_of_same_last_20 
	- 0.0031 * parameters.max_latency_of_same_last_50 
	+ 4756322.9903;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM2(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	+ 0.021 * parameters.wait_so_far 
	+ 107533.2821 * parameters.total_wait_locks 
	+ 0.0004 * parameters.mean_wait_of_all 
	- 90750.1035 * parameters.cpu_usage 
	- 0.0431 * parameters.avg_wait_of_same_past_second 
	+ 0.0497 * parameters.avg_latency_of_same_last_20 
	- 0.0082 * parameters.max_latency_of_same_last_50 
	+ 10096002.9114;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM3(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	+ 0.0225 * parameters.wait_so_far 
	+ 153226.2092 * parameters.total_wait_locks 
	- 0.3604 * parameters.mean_wait_of_all 
	- 43916044.7504 * parameters.cpu_usage 
	- 0.1306 * parameters.avg_work_of_same_past_second 
	- 0.1143 * parameters.avg_wait_of_same_past_second 
	- 0.0071 * parameters.avg_latency_of_same_last_20 
	+ 0.0262 * parameters.max_latency_of_same_last_50 
	+ 43686183.8513;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM4(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 13099.9175 * parameters.total_wait_locks 
	+ 13780.5889 * parameters.mean_wait_of_all 
	- 16726999.9633 * parameters.cpu_usage 
	- 0.1306 * parameters.avg_work_of_same_past_second 
	- 0.0512 * parameters.avg_wait_of_same_past_second 
	- 0.1045 * parameters.avg_latency_of_same_last_20 
	+ 0.0432 * parameters.max_latency_of_same_last_50 
	- 295234543502.8747;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM5(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 84208.3925 * parameters.total_wait_locks 
	+ 0.0013 * parameters.mean_wait_of_all 
	- 16726999.9633 * parameters.cpu_usage 
	- 0.1306 * parameters.avg_work_of_same_past_second 
	- 0.0512 * parameters.avg_wait_of_same_past_second 
	- 0.1105 * parameters.avg_latency_of_same_last_20 
	+ 0.0432 * parameters.max_latency_of_same_last_50 
	+ 53461481.4343;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM6(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 211789.824 * parameters.total_wait_locks 
	+ 0.0013 * parameters.mean_wait_of_all 
	- 16726999.9633 * parameters.cpu_usage 
	- 0.1306 * parameters.avg_work_of_same_past_second 
	- 0.0512 * parameters.avg_wait_of_same_past_second 
	- 0.1071 * parameters.avg_latency_of_same_last_20 
	+ 0.0432 * parameters.max_latency_of_same_last_50 
	+ 28978545.8792;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM7(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	+ 0.0067 * parameters.wait_so_far 
	- 26509.9728 * parameters.total_wait_locks 
	+ 0.2837 * parameters.mean_wait_of_all 
	- 137853667.4608 * parameters.cpu_usage 
	- 0.5435 * parameters.avg_work_of_same_past_second 
	+ 0.0389 * parameters.avg_wait_of_same_past_second 
	+ 0.0114 * parameters.avg_latency_of_same_last_20 
	+ 0.0072 * parameters.max_latency_of_same_last_50 
	+ 119313672.5946;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM8(work_wait &parameters) {
  double actual_remaining = 
	231.3083 * parameters.work_so_far 
	+ 0.0067 * parameters.wait_so_far 
	- 26509.9728 * parameters.total_wait_locks 
	+ 0.2837 * parameters.mean_wait_of_all 
	- 137853667.4608 * parameters.cpu_usage 
	- 0.5435 * parameters.avg_work_of_same_past_second 
	+ 0.0389 * parameters.avg_wait_of_same_past_second 
	+ 0.0114 * parameters.avg_latency_of_same_last_20 
	+ 0.0072 * parameters.max_latency_of_same_last_50 
	+ 116391991.4381;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM9(work_wait &parameters) {
  double actual_remaining = 
	0.082 * parameters.work_so_far 
	+ 0.0087 * parameters.wait_so_far 
	- 87114.2685 * parameters.total_wait_locks 
	+ 0.2554 * parameters.mean_wait_of_all 
	- 64927110.585 * parameters.cpu_usage 
	- 0.3121 * parameters.avg_work_of_same_past_second 
	+ 0.0635 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 0.0372 * parameters.max_latency_of_same_last_50 
	+ 92331854.9786;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM10(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	+ 0.0087 * parameters.wait_so_far 
	- 95119.0417 * parameters.total_wait_locks 
	+ 0.2554 * parameters.mean_wait_of_all 
	- 64927110.585 * parameters.cpu_usage 
	- 0.0667 * parameters.avg_work_of_same_past_second 
	+ 0.0667 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	+ 0.0072 * parameters.max_latency_of_same_last_50 
	+ 81441276.9431;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM11(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	+ 0.0076 * parameters.wait_so_far 
	- 20993.2344 * parameters.total_wait_locks 
	+ 0.2288 * parameters.mean_wait_of_all 
	- 64927110.585 * parameters.cpu_usage 
	- 0.4248 * parameters.avg_work_of_same_past_second 
	+ 0.034 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	+ 0.0567 * parameters.max_latency_of_same_last_50 
	+ 36814420.8128;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM12(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	- 2130.1489 * parameters.total_wait_locks 
	- 0.0721 * parameters.mean_wait_of_all 
	- 51194.1761 * parameters.cpu_usage 
	- 0.0069 * parameters.avg_work_of_same_past_second 
	+ 0.0031 * parameters.avg_wait_of_same_past_second 
	+ 0.0249 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 15239502.0293;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM13(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	- 0.0005 * parameters.wait_so_far 
	- 31108.4418 * parameters.total_wait_locks 
	- 0.0447 * parameters.mean_wait_of_all 
	- 51194.1761 * parameters.cpu_usage 
	- 0.0069 * parameters.avg_work_of_same_past_second 
	+ 0.0076 * parameters.avg_wait_of_same_past_second 
	- 0.0174 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 39963108.2751;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM14(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	- 0.0005 * parameters.wait_so_far 
	- 2308.1406 * parameters.total_wait_locks 
	- 0.0216 * parameters.mean_wait_of_all 
	- 51194.1761 * parameters.cpu_usage 
	- 0.0069 * parameters.avg_work_of_same_past_second 
	+ 0.0062 * parameters.avg_wait_of_same_past_second 
	+ 0.0014 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 26087977.2101;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM15(work_wait &parameters) {
  double actual_remaining = 
	-0.4129 * parameters.work_so_far 
	- 0.0153 * parameters.wait_so_far 
	- 52187.0844 * parameters.total_wait_locks 
	+ 0.125 * parameters.mean_wait_of_all 
	- 127969798.6419 * parameters.cpu_usage 
	+ 0.0719 * parameters.avg_work_of_same_past_second 
	+ 0.0058 * parameters.avg_wait_of_same_past_second 
	+ 0.0697 * parameters.avg_latency_of_same_last_20 
	- 0.0061 * parameters.max_latency_of_same_last_50 
	+ 120430098.192;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM16(work_wait &parameters) {
  double actual_remaining = 
	-0.4129 * parameters.work_so_far 
	- 0.0214 * parameters.wait_so_far 
	- 52187.0844 * parameters.total_wait_locks 
	+ 0.125 * parameters.mean_wait_of_all 
	- 127969798.6419 * parameters.cpu_usage 
	+ 0.0719 * parameters.avg_work_of_same_past_second 
	+ 0.0058 * parameters.avg_wait_of_same_past_second 
	+ 0.0881 * parameters.avg_latency_of_same_last_20 
	- 0.0061 * parameters.max_latency_of_same_last_50 
	+ 121698062.4108;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM17(work_wait &parameters) {
  double actual_remaining = 
	270.2733 * parameters.work_so_far 
	- 0.0176 * parameters.wait_so_far 
	- 52187.0844 * parameters.total_wait_locks 
	+ 0.125 * parameters.mean_wait_of_all 
	- 127969798.6419 * parameters.cpu_usage 
	+ 0.0719 * parameters.avg_work_of_same_past_second 
	+ 0.0058 * parameters.avg_wait_of_same_past_second 
	+ 0.1061 * parameters.avg_latency_of_same_last_20 
	- 0.0061 * parameters.max_latency_of_same_last_50 
	+ 96517361.1784;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM18(work_wait &parameters) {
  double actual_remaining = 
	562.1603 * parameters.work_so_far 
	- 0.0176 * parameters.wait_so_far 
	- 52187.0844 * parameters.total_wait_locks 
	+ 0.125 * parameters.mean_wait_of_all 
	- 127969798.6419 * parameters.cpu_usage 
	+ 0.0719 * parameters.avg_work_of_same_past_second 
	+ 0.0058 * parameters.avg_wait_of_same_past_second 
	+ 0.1061 * parameters.avg_latency_of_same_last_20 
	- 0.0061 * parameters.max_latency_of_same_last_50 
	+ 91756421.7128;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM19(work_wait &parameters) {
  double actual_remaining = 
	-0.4129 * parameters.work_so_far 
	- 0.0098 * parameters.wait_so_far 
	- 52187.0844 * parameters.total_wait_locks 
	+ 0.125 * parameters.mean_wait_of_all 
	- 127969798.6419 * parameters.cpu_usage 
	+ 0.0719 * parameters.avg_work_of_same_past_second 
	+ 0.0058 * parameters.avg_wait_of_same_past_second 
	+ 0.0754 * parameters.avg_latency_of_same_last_20 
	- 0.0106 * parameters.max_latency_of_same_last_50 
	+ 113342519.5717;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM20(work_wait &parameters) {
  double actual_remaining = 
	-0.3014 * parameters.work_so_far 
	- 0.0024 * parameters.wait_so_far 
	- 42760.83 * parameters.total_wait_locks 
	+ 0.0977 * parameters.mean_wait_of_all 
	- 93474894.0668 * parameters.cpu_usage 
	+ 0.0507 * parameters.avg_work_of_same_past_second 
	+ 0.0058 * parameters.avg_wait_of_same_past_second 
	+ 0.0014 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 105604840.6093;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM21(work_wait &parameters) {
  double actual_remaining = 
	0.1206 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 863478.8538 * parameters.total_wait_locks 
	- 5.9791 * parameters.mean_wait_of_all 
	- 84581957.8061 * parameters.cpu_usage 
	- 35.1479 * parameters.avg_work_of_same_past_second 
	- 0.0558 * parameters.avg_wait_of_same_past_second 
	+ 0.0102 * parameters.avg_latency_of_same_last_20 
	- 0.0394 * parameters.max_latency_of_same_last_50 
	+ 1473043026.9391;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM22(work_wait &parameters) {
  double actual_remaining = 
	2.7597 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 448815.4437 * parameters.total_wait_locks 
	- 1.6999 * parameters.mean_wait_of_all 
	- 188096235.0189 * parameters.cpu_usage 
	- 4.4436 * parameters.avg_work_of_same_past_second 
	+ 0.2907 * parameters.avg_wait_of_same_past_second 
	+ 0.0056 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 171879374.218;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM23(work_wait &parameters) {
  double actual_remaining = 
	0.7915 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 56633.6842 * parameters.total_wait_locks 
	- 0.2318 * parameters.mean_wait_of_all 
	- 337315066.3462 * parameters.cpu_usage 
	- 1.3243 * parameters.avg_work_of_same_past_second 
	+ 0.0647 * parameters.avg_wait_of_same_past_second 
	+ 0.0056 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 304401478.7749;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM24(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	- 0.005 * parameters.wait_so_far 
	- 2130.1489 * parameters.total_wait_locks 
	- 0.0068 * parameters.mean_wait_of_all 
	+ 766482.5468 * parameters.cpu_usage 
	- 0.052 * parameters.avg_work_of_same_past_second 
	+ 0.0266 * parameters.avg_wait_of_same_past_second 
	+ 0.0263 * parameters.avg_latency_of_same_last_20 
	- 0.0062 * parameters.max_latency_of_same_last_50 
	+ 13974208.6372;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM25(work_wait &parameters) {
  double actual_remaining = 
	0.8601 * parameters.work_so_far 
	- 0.0033 * parameters.wait_so_far 
	+ 75960.2708 * parameters.total_wait_locks 
	+ 0.5344 * parameters.mean_wait_of_all 
	- 36169890.8308 * parameters.cpu_usage 
	+ 0.0091 * parameters.avg_work_of_same_past_second 
	+ 0.003 * parameters.avg_wait_of_same_past_second 
	- 0.0038 * parameters.avg_latency_of_same_last_20 
	- 0.0199 * parameters.max_latency_of_same_last_50 
	+ 46972891.9614;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM26(work_wait &parameters) {
  double actual_remaining = 
	0.8601 * parameters.work_so_far 
	- 0.0033 * parameters.wait_so_far 
	+ 75960.2708 * parameters.total_wait_locks 
	- 3.9867 * parameters.mean_wait_of_all 
	- 36169890.8308 * parameters.cpu_usage 
	+ 0.0091 * parameters.avg_work_of_same_past_second 
	+ 0.003 * parameters.avg_wait_of_same_past_second 
	- 0.0038 * parameters.avg_latency_of_same_last_20 
	- 0.0665 * parameters.max_latency_of_same_last_50 
	+ 197720722.6643;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM27(work_wait &parameters) {
  double actual_remaining = 
	18.8361 * parameters.work_so_far 
	- 0.0033 * parameters.wait_so_far 
	- 232581.8381 * parameters.total_wait_locks 
	+ 6.2912 * parameters.mean_wait_of_all 
	- 36169890.8308 * parameters.cpu_usage 
	+ 0.0091 * parameters.avg_work_of_same_past_second 
	+ 0.1008 * parameters.avg_wait_of_same_past_second 
	- 0.0138 * parameters.avg_latency_of_same_last_20 
	- 0.0169 * parameters.max_latency_of_same_last_50 
	- 19127060.7475;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM28(work_wait &parameters) {
  double actual_remaining = 
	19.7404 * parameters.work_so_far 
	+ 0.0769 * parameters.wait_so_far 
	- 565130.2273 * parameters.total_wait_locks 
	- 0.275 * parameters.mean_wait_of_all 
	- 36169890.8308 * parameters.cpu_usage 
	+ 0.0091 * parameters.avg_work_of_same_past_second 
	+ 0.003 * parameters.avg_wait_of_same_past_second 
	- 0.1842 * parameters.avg_latency_of_same_last_20 
	- 0.0169 * parameters.max_latency_of_same_last_50 
	+ 272880764.7768;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM29(work_wait &parameters) {
  double actual_remaining = 
	14.3154 * parameters.work_so_far 
	- 0.0033 * parameters.wait_so_far 
	- 703528.7297 * parameters.total_wait_locks 
	+ 3.9014 * parameters.mean_wait_of_all 
	- 36169890.8308 * parameters.cpu_usage 
	+ 0.0091 * parameters.avg_work_of_same_past_second 
	+ 0.003 * parameters.avg_wait_of_same_past_second 
	- 0.0138 * parameters.avg_latency_of_same_last_20 
	- 0.0169 * parameters.max_latency_of_same_last_50 
	+ 128853670.3424;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM30(work_wait &parameters) {
  double actual_remaining = 
	-0.007 * parameters.work_so_far 
	- 0.0077 * parameters.wait_so_far 
	+ 282806.3404 * parameters.total_wait_locks 
	- 0.0567 * parameters.mean_wait_of_all 
	- 84566281.6995 * parameters.cpu_usage 
	- 0.1081 * parameters.avg_work_of_same_past_second 
	- 0.1183 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0.0147 * parameters.max_latency_of_same_last_50 
	+ 83853340.2366;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM31(work_wait &parameters) {
  double actual_remaining = 
	-0.007 * parameters.work_so_far 
	- 0.0077 * parameters.wait_so_far 
	+ 248578.9556 * parameters.total_wait_locks 
	- 0.0567 * parameters.mean_wait_of_all 
	- 84566281.6995 * parameters.cpu_usage 
	- 0.1081 * parameters.avg_work_of_same_past_second 
	- 0.1183 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0.0147 * parameters.max_latency_of_same_last_50 
	+ 88601459.3569;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM32(work_wait &parameters) {
  double actual_remaining = 
	-0.007 * parameters.work_so_far 
	- 0.0077 * parameters.wait_so_far 
	+ 190939.7321 * parameters.total_wait_locks 
	- 0.0312 * parameters.mean_wait_of_all 
	- 84566281.6995 * parameters.cpu_usage 
	- 0.1081 * parameters.avg_work_of_same_past_second 
	- 0.1404 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0.0147 * parameters.max_latency_of_same_last_50 
	+ 92869138.295;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM33(work_wait &parameters) {
  double actual_remaining = 
	-0.007 * parameters.work_so_far 
	- 0.0077 * parameters.wait_so_far 
	+ 217019.666 * parameters.total_wait_locks 
	+ 2.4501 * parameters.mean_wait_of_all 
	+ 227394971.516 * parameters.cpu_usage 
	- 0.1081 * parameters.avg_work_of_same_past_second 
	- 0.1517 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0.0147 * parameters.max_latency_of_same_last_50 
	- 230509537.3231;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM34(work_wait &parameters) {
  double actual_remaining = 
	-0.007 * parameters.work_so_far 
	- 0.0077 * parameters.wait_so_far 
	+ 217019.666 * parameters.total_wait_locks 
	+ 3.0568 * parameters.mean_wait_of_all 
	+ 157668726.9531 * parameters.cpu_usage 
	- 0.1081 * parameters.avg_work_of_same_past_second 
	- 0.1517 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0.0147 * parameters.max_latency_of_same_last_50 
	- 181911007.3889;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM35(work_wait &parameters) {
  double actual_remaining = 
	-0.007 * parameters.work_so_far 
	- 0.0077 * parameters.wait_so_far 
	+ 129279.6794 * parameters.total_wait_locks 
	+ 0.6301 * parameters.mean_wait_of_all 
	- 84566281.6995 * parameters.cpu_usage 
	- 0.113 * parameters.avg_work_of_same_past_second 
	- 0.1089 * parameters.avg_wait_of_same_past_second 
	+ 0.0326 * parameters.avg_latency_of_same_last_20 
	- 0.0149 * parameters.max_latency_of_same_last_50 
	+ 73845668.8373;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM36(work_wait &parameters) {
  double actual_remaining = 
	491.7249 * parameters.work_so_far 
	+ 0.0488 * parameters.wait_so_far 
	+ 30618.6291 * parameters.total_wait_locks 
	+ 0.4387 * parameters.mean_wait_of_all 
	- 46488914.015 * parameters.cpu_usage 
	- 0.5173 * parameters.avg_work_of_same_past_second 
	+ 0.0687 * parameters.avg_wait_of_same_past_second 
	- 0.0006 * parameters.avg_latency_of_same_last_20 
	- 0.005 * parameters.max_latency_of_same_last_50 
	+ 37479247.7802;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM37(work_wait &parameters) {
  double actual_remaining = 
	-0.0074 * parameters.work_so_far 
	+ 0.0242 * parameters.wait_so_far 
	+ 245264.3353 * parameters.total_wait_locks 
	- 0.848 * parameters.mean_wait_of_all 
	- 46488914.015 * parameters.cpu_usage 
	- 0.5173 * parameters.avg_work_of_same_past_second 
	+ 0.0687 * parameters.avg_wait_of_same_past_second 
	- 0.0006 * parameters.avg_latency_of_same_last_20 
	- 0.005 * parameters.max_latency_of_same_last_50 
	+ 93189668.136;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM38(work_wait &parameters) {
  double actual_remaining = 
	68.543 * parameters.work_so_far 
	+ 0.0242 * parameters.wait_so_far 
	+ 307329.9831 * parameters.total_wait_locks 
	- 1.2159 * parameters.mean_wait_of_all 
	- 46488914.015 * parameters.cpu_usage 
	- 0.5173 * parameters.avg_work_of_same_past_second 
	+ 0.0687 * parameters.avg_wait_of_same_past_second 
	- 0.0006 * parameters.avg_latency_of_same_last_20 
	- 0.005 * parameters.max_latency_of_same_last_50 
	+ 101188542.2639;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM39(work_wait &parameters) {
  double actual_remaining = 
	55.4858 * parameters.work_so_far 
	+ 0.0242 * parameters.wait_so_far 
	+ 307329.9831 * parameters.total_wait_locks 
	- 1.2159 * parameters.mean_wait_of_all 
	- 46488914.015 * parameters.cpu_usage 
	- 0.5173 * parameters.avg_work_of_same_past_second 
	+ 0.0687 * parameters.avg_wait_of_same_past_second 
	- 0.0006 * parameters.avg_latency_of_same_last_20 
	- 0.005 * parameters.max_latency_of_same_last_50 
	+ 101953915.9175;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM40(work_wait &parameters) {
  double actual_remaining = 
	-0.0074 * parameters.work_so_far 
	+ 0.0242 * parameters.wait_so_far 
	+ 336036.5576 * parameters.total_wait_locks 
	- 1.3931 * parameters.mean_wait_of_all 
	- 46488914.015 * parameters.cpu_usage 
	- 0.5173 * parameters.avg_work_of_same_past_second 
	+ 0.0687 * parameters.avg_wait_of_same_past_second 
	- 0.0006 * parameters.avg_latency_of_same_last_20 
	- 0.005 * parameters.max_latency_of_same_last_50 
	+ 105810119.371;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM41(work_wait &parameters) {
  double actual_remaining = 
	-0.0074 * parameters.work_so_far 
	+ 0.0037 * parameters.wait_so_far 
	+ 18541.3742 * parameters.total_wait_locks 
	+ 0.0187 * parameters.mean_wait_of_all 
	- 46488914.015 * parameters.cpu_usage 
	+ 0.4006 * parameters.avg_work_of_same_past_second 
	+ 0.058 * parameters.avg_wait_of_same_past_second 
	- 0.0006 * parameters.avg_latency_of_same_last_20 
	- 0.0039 * parameters.max_latency_of_same_last_50 
	+ 46219381.0382;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM42(work_wait &parameters) {
  double actual_remaining = 
	-0.0074 * parameters.work_so_far 
	+ 0.0102 * parameters.wait_so_far 
	- 22648.9377 * parameters.total_wait_locks 
	- 38.8127 * parameters.mean_wait_of_all 
	- 86453600.0812 * parameters.cpu_usage 
	- 0.5738 * parameters.avg_work_of_same_past_second 
	+ 0.0773 * parameters.avg_wait_of_same_past_second 
	- 0.0006 * parameters.avg_latency_of_same_last_20 
	+ 0.0531 * parameters.max_latency_of_same_last_50 
	+ 1285608671.8988;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM43(work_wait &parameters) {
  double actual_remaining = 
	-0.0074 * parameters.work_so_far 
	+ 0.0102 * parameters.wait_so_far 
	- 22648.9377 * parameters.total_wait_locks 
	+ 0.0649 * parameters.mean_wait_of_all 
	- 86453600.0812 * parameters.cpu_usage 
	- 0.5738 * parameters.avg_work_of_same_past_second 
	+ 0.0773 * parameters.avg_wait_of_same_past_second 
	- 0.0006 * parameters.avg_latency_of_same_last_20 
	+ 0.026 * parameters.max_latency_of_same_last_50 
	+ 104841326.2096;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM44(work_wait &parameters) {
  double actual_remaining = 
	344.4622 * parameters.work_so_far 
	- 0.0008 * parameters.wait_so_far 
	+ 16281.517 * parameters.total_wait_locks 
	- 0.086 * parameters.mean_wait_of_all 
	- 21050642.9706 * parameters.cpu_usage 
	- 0.2172 * parameters.avg_work_of_same_past_second 
	+ 0.0186 * parameters.avg_wait_of_same_past_second 
	- 0.0004 * parameters.avg_latency_of_same_last_20 
	- 0.0015 * parameters.max_latency_of_same_last_50 
	+ 33309412.9023;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM45(work_wait &parameters) {
  double actual_remaining = 
	-0.0074 * parameters.work_so_far 
	- 0.0008 * parameters.wait_so_far 
	+ 16940.4027 * parameters.total_wait_locks 
	- 0.086 * parameters.mean_wait_of_all 
	- 21050642.9706 * parameters.cpu_usage 
	- 0.2172 * parameters.avg_work_of_same_past_second 
	+ 0.0186 * parameters.avg_wait_of_same_past_second 
	- 0.0004 * parameters.avg_latency_of_same_last_20 
	- 0.0024 * parameters.max_latency_of_same_last_50 
	+ 38267430.0814;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM46(work_wait &parameters) {
  double actual_remaining = 
	0.3091 * parameters.work_so_far 
	- 0.0104 * parameters.wait_so_far 
	- 10930.086 * parameters.total_wait_locks 
	- 0.0778 * parameters.mean_wait_of_all 
	- 21050642.9706 * parameters.cpu_usage 
	- 0.2017 * parameters.avg_work_of_same_past_second 
	+ 0.0179 * parameters.avg_wait_of_same_past_second 
	- 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.0012 * parameters.max_latency_of_same_last_50 
	+ 63196176.9916;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM47(work_wait &parameters) {
  double actual_remaining = 
	-0.0071 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	- 63034.3293 * parameters.total_wait_locks 
	+ 0.2555 * parameters.mean_wait_of_all 
	+ 76263493.1277 * parameters.cpu_usage 
	+ 0.1289 * parameters.avg_work_of_same_past_second 
	+ 0.0469 * parameters.avg_wait_of_same_past_second 
	+ 0.0041 * parameters.avg_latency_of_same_last_20 
	- 0.0113 * parameters.max_latency_of_same_last_50 
	- 54629210.9727;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM48(work_wait &parameters) {
  double actual_remaining = 
	-0.0071 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	- 358423.5935 * parameters.total_wait_locks 
	+ 0.5234 * parameters.mean_wait_of_all 
	+ 76263493.1277 * parameters.cpu_usage 
	+ 0.4882 * parameters.avg_work_of_same_past_second 
	+ 0.0868 * parameters.avg_wait_of_same_past_second 
	- 0.008 * parameters.avg_latency_of_same_last_20 
	- 0.011 * parameters.max_latency_of_same_last_50 
	+ 16702351.1751;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM49(work_wait &parameters) {
  double actual_remaining = 
	-0.0071 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	- 152648.1323 * parameters.total_wait_locks 
	- 0.6757 * parameters.mean_wait_of_all 
	+ 76263493.1277 * parameters.cpu_usage 
	+ 0.4724 * parameters.avg_work_of_same_past_second 
	+ 0.0914 * parameters.avg_wait_of_same_past_second 
	- 0.183 * parameters.avg_latency_of_same_last_20 
	+ 0.0537 * parameters.max_latency_of_same_last_50 
	+ 109871493.8902;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM50(work_wait &parameters) {
  double actual_remaining = 
	-1.5589 * parameters.work_so_far 
	- 0.0052 * parameters.wait_so_far 
	- 131982.9552 * parameters.total_wait_locks 
	+ 0.3882 * parameters.mean_wait_of_all 
	- 694372009.4956 * parameters.cpu_usage 
	- 0.662 * parameters.avg_work_of_same_past_second 
	+ 0.0533 * parameters.avg_wait_of_same_past_second 
	+ 0.0406 * parameters.avg_latency_of_same_last_20 
	+ 0.1111 * parameters.max_latency_of_same_last_50 
	+ 507798350.8391;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM51(work_wait &parameters) {
  double actual_remaining = 
	0.6725 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	- 108763.5605 * parameters.total_wait_locks 
	+ 0.2424 * parameters.mean_wait_of_all 
	+ 170640877.9522 * parameters.cpu_usage 
	- 2.5587 * parameters.avg_work_of_same_past_second 
	+ 0.0533 * parameters.avg_wait_of_same_past_second 
	+ 0.0439 * parameters.avg_latency_of_same_last_20 
	+ 0.1237 * parameters.max_latency_of_same_last_50 
	- 149674790.9273;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM52(work_wait &parameters) {
  double actual_remaining = 
	0.6725 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	- 105513.9692 * parameters.total_wait_locks 
	+ 0.2424 * parameters.mean_wait_of_all 
	+ 170640877.9522 * parameters.cpu_usage 
	- 2.5587 * parameters.avg_work_of_same_past_second 
	+ 0.0533 * parameters.avg_wait_of_same_past_second 
	+ 0.0439 * parameters.avg_latency_of_same_last_20 
	+ 0.1237 * parameters.max_latency_of_same_last_50 
	- 151305326.3121;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM53(work_wait &parameters) {
  double actual_remaining = 
	-0.0071 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	- 221305.9239 * parameters.total_wait_locks 
	+ 0.2424 * parameters.mean_wait_of_all 
	+ 170640877.9522 * parameters.cpu_usage 
	- 2.2334 * parameters.avg_work_of_same_past_second 
	+ 0.0533 * parameters.avg_wait_of_same_past_second 
	+ 0.0439 * parameters.avg_latency_of_same_last_20 
	+ 0.1237 * parameters.max_latency_of_same_last_50 
	- 141899795.188;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM54(work_wait &parameters) {
  double actual_remaining = 
	-0.0071 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	- 218825.4084 * parameters.total_wait_locks 
	+ 0.2424 * parameters.mean_wait_of_all 
	+ 170640877.9522 * parameters.cpu_usage 
	- 2.2334 * parameters.avg_work_of_same_past_second 
	+ 0.0533 * parameters.avg_wait_of_same_past_second 
	+ 0.0439 * parameters.avg_latency_of_same_last_20 
	+ 0.1237 * parameters.max_latency_of_same_last_50 
	- 142577920.7782;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM55(work_wait &parameters) {
  double actual_remaining = 
	-0.0071 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	- 237094.2517 * parameters.total_wait_locks 
	+ 0.2424 * parameters.mean_wait_of_all 
	+ 170640877.9522 * parameters.cpu_usage 
	- 2.2334 * parameters.avg_work_of_same_past_second 
	+ 0.0533 * parameters.avg_wait_of_same_past_second 
	+ 0.0439 * parameters.avg_latency_of_same_last_20 
	+ 0.1237 * parameters.max_latency_of_same_last_50 
	- 141857897.8661;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM56(work_wait &parameters) {
  double actual_remaining = 
	-0.0071 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	- 47901.433 * parameters.total_wait_locks 
	+ 0.1871 * parameters.mean_wait_of_all 
	+ 65607863.8841 * parameters.cpu_usage 
	+ 0.0128 * parameters.avg_work_of_same_past_second 
	+ 0.0291 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 0.0036 * parameters.max_latency_of_same_last_50 
	- 41969808.0381;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM57(work_wait &parameters) {
  double actual_remaining = 
	-0.0071 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	- 49910.1556 * parameters.total_wait_locks 
	+ 0.1871 * parameters.mean_wait_of_all 
	+ 65607863.8841 * parameters.cpu_usage 
	+ 0.0128 * parameters.avg_work_of_same_past_second 
	- 0.0382 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 0.0036 * parameters.max_latency_of_same_last_50 
	- 10359911.6695;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM58(work_wait &parameters) {
  double actual_remaining = 
	-0.0071 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	- 49910.1556 * parameters.total_wait_locks 
	+ 0.1871 * parameters.mean_wait_of_all 
	+ 65607863.8841 * parameters.cpu_usage 
	+ 0.0128 * parameters.avg_work_of_same_past_second 
	- 0.0382 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 0.0036 * parameters.max_latency_of_same_last_50 
	- 5152530;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM59(work_wait &parameters) {
  double actual_remaining = 
	-0.0071 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 13865.0709 * parameters.total_wait_locks 
	+ 0.1871 * parameters.mean_wait_of_all 
	+ 65607863.8841 * parameters.cpu_usage 
	+ 0.0128 * parameters.avg_work_of_same_past_second 
	- 0.0382 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 0.0036 * parameters.max_latency_of_same_last_50 
	- 41904065.9954;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM60(work_wait &parameters) {
  double actual_remaining = 
	-0.0071 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	- 66025.8386 * parameters.total_wait_locks 
	+ 0.1871 * parameters.mean_wait_of_all 
	+ 65607863.8841 * parameters.cpu_usage 
	+ 0.0128 * parameters.avg_work_of_same_past_second 
	- 0.0382 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 0.0036 * parameters.max_latency_of_same_last_50 
	+ 6154330.5286;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM61(work_wait &parameters) {
  double actual_remaining = 
	35.752 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	- 49910.1556 * parameters.total_wait_locks 
	+ 0.1871 * parameters.mean_wait_of_all 
	+ 65607863.8841 * parameters.cpu_usage 
	+ 0.0128 * parameters.avg_work_of_same_past_second 
	- 0.0917 * parameters.avg_wait_of_same_past_second 
	+ 0.0142 * parameters.avg_latency_of_same_last_20 
	- 0.0036 * parameters.max_latency_of_same_last_50 
	- 9383287.8956;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM62(work_wait &parameters) {
  double actual_remaining = 
	8.7113 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 278882.0497 * parameters.total_wait_locks 
	+ 0.9683 * parameters.mean_wait_of_all 
	+ 347385.9156 * parameters.cpu_usage 
	- 16.8221 * parameters.avg_work_of_same_past_second 
	+ 0.0011 * parameters.avg_wait_of_same_past_second 
	+ 0.1247 * parameters.avg_latency_of_same_last_20 
	- 0.0037 * parameters.max_latency_of_same_last_50 
	+ 444645492.761;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM63(work_wait &parameters) {
  double actual_remaining = 
	8.7113 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 278882.0497 * parameters.total_wait_locks 
	- 144.1588 * parameters.mean_wait_of_all 
	+ 347385.9156 * parameters.cpu_usage 
	- 16.8221 * parameters.avg_work_of_same_past_second 
	+ 0.0011 * parameters.avg_wait_of_same_past_second 
	+ 0.1247 * parameters.avg_latency_of_same_last_20 
	- 0.0037 * parameters.max_latency_of_same_last_50 
	+ 12513756343.2072;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM64(work_wait &parameters) {
  double actual_remaining = 
	5.1052 * parameters.work_so_far 
	- 0.0102 * parameters.wait_so_far 
	- 334615.2462 * parameters.total_wait_locks 
	+ 0.9683 * parameters.mean_wait_of_all 
	+ 347385.9156 * parameters.cpu_usage 
	- 9.8027 * parameters.avg_work_of_same_past_second 
	+ 0.0011 * parameters.avg_wait_of_same_past_second 
	+ 0.122 * parameters.avg_latency_of_same_last_20 
	- 0.045 * parameters.max_latency_of_same_last_50 
	+ 297085423.0135;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM65(work_wait &parameters) {
  double actual_remaining = 
	0.0141 * parameters.work_so_far 
	+ 0.0109 * parameters.wait_so_far 
	- 90332.6917 * parameters.total_wait_locks 
	+ 0.3058 * parameters.mean_wait_of_all 
	+ 347385.9156 * parameters.cpu_usage 
	+ 0.107 * parameters.avg_work_of_same_past_second 
	+ 0.0239 * parameters.avg_wait_of_same_past_second 
	+ 0.0103 * parameters.avg_latency_of_same_last_20 
	- 0.0127 * parameters.max_latency_of_same_last_50 
	+ 24037234.6289;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM66(work_wait &parameters) {
  double actual_remaining = 
	0.0141 * parameters.work_so_far 
	- 0.0043 * parameters.wait_so_far 
	- 82334.8339 * parameters.total_wait_locks 
	+ 0.3654 * parameters.mean_wait_of_all 
	+ 347385.9156 * parameters.cpu_usage 
	+ 0.107 * parameters.avg_work_of_same_past_second 
	+ 0.1208 * parameters.avg_wait_of_same_past_second 
	+ 0.0568 * parameters.avg_latency_of_same_last_20 
	- 0.0353 * parameters.max_latency_of_same_last_50 
	- 14133675.8338;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM67(work_wait &parameters) {
  double actual_remaining = 
	0.0141 * parameters.work_so_far 
	- 0.0494 * parameters.wait_so_far 
	- 82334.8339 * parameters.total_wait_locks 
	+ 0.3651 * parameters.mean_wait_of_all 
	+ 347385.9156 * parameters.cpu_usage 
	+ 0.107 * parameters.avg_work_of_same_past_second 
	+ 0.1208 * parameters.avg_wait_of_same_past_second 
	+ 0.0697 * parameters.avg_latency_of_same_last_20 
	- 0.0283 * parameters.max_latency_of_same_last_50 
	- 5263222.9484;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM68(work_wait &parameters) {
  double actual_remaining = 
	0.0141 * parameters.work_so_far 
	- 0.0436 * parameters.wait_so_far 
	- 82334.8339 * parameters.total_wait_locks 
	+ 0.3651 * parameters.mean_wait_of_all 
	+ 347385.9156 * parameters.cpu_usage 
	+ 0.107 * parameters.avg_work_of_same_past_second 
	+ 0.1208 * parameters.avg_wait_of_same_past_second 
	+ 0.0697 * parameters.avg_latency_of_same_last_20 
	- 0.0283 * parameters.max_latency_of_same_last_50 
	- 10631385.8159;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM69(work_wait &parameters) {
  double actual_remaining = 
	0.0141 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 1289423.6144 * parameters.total_wait_locks 
	+ 0.2761 * parameters.mean_wait_of_all 
	+ 347385.9156 * parameters.cpu_usage 
	- 13.3015 * parameters.avg_work_of_same_past_second 
	+ 0.1962 * parameters.avg_wait_of_same_past_second 
	+ 0.0699 * parameters.avg_latency_of_same_last_20 
	- 0.0649 * parameters.max_latency_of_same_last_50 
	+ 1069724832.2202;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM70(work_wait &parameters) {
  double actual_remaining = 
	0.0141 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 156416.2223 * parameters.total_wait_locks 
	+ 0.2761 * parameters.mean_wait_of_all 
	+ 347385.9156 * parameters.cpu_usage 
	- 10.2072 * parameters.avg_work_of_same_past_second 
	+ 0.1458 * parameters.avg_wait_of_same_past_second 
	+ 0.0699 * parameters.avg_latency_of_same_last_20 
	- 0.0649 * parameters.max_latency_of_same_last_50 
	+ 320497072.827;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM71(work_wait &parameters) {
  double actual_remaining = 
	0.0141 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 186731.2948 * parameters.total_wait_locks 
	+ 0.6074 * parameters.mean_wait_of_all 
	+ 347385.9156 * parameters.cpu_usage 
	+ 0.1644 * parameters.avg_work_of_same_past_second 
	- 0.0005 * parameters.avg_wait_of_same_past_second 
	+ 0.0284 * parameters.avg_latency_of_same_last_20 
	- 0.0034 * parameters.max_latency_of_same_last_50 
	+ 30044965.889;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM72(work_wait &parameters) {
  double actual_remaining = 
	0.2501 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 224078.8152 * parameters.total_wait_locks 
	+ 1.321 * parameters.mean_wait_of_all 
	+ 347385.9156 * parameters.cpu_usage 
	+ 0.7841 * parameters.avg_work_of_same_past_second 
	- 0.3464 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	- 0.0119 * parameters.max_latency_of_same_last_50 
	+ 300402873.717;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM73(work_wait &parameters) {
  double actual_remaining = 
	0.1551 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 201850.6465 * parameters.total_wait_locks 
	+ 0.83 * parameters.mean_wait_of_all 
	+ 347385.9156 * parameters.cpu_usage 
	+ 0.7841 * parameters.avg_work_of_same_past_second 
	- 0.1861 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	- 0.1449 * parameters.max_latency_of_same_last_50 
	+ 116110140.2796;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM74(work_wait &parameters) {
  double actual_remaining = 
	0.1055 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 137061.1944 * parameters.total_wait_locks 
	+ 0.6322 * parameters.mean_wait_of_all 
	+ 347385.9156 * parameters.cpu_usage 
	+ 0.7841 * parameters.avg_work_of_same_past_second 
	- 0.0823 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	- 0.0154 * parameters.max_latency_of_same_last_50 
	+ 80859541.2354;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM75(work_wait &parameters) {
  double actual_remaining = 
	-0.1474 * parameters.work_so_far 
	- 0.005 * parameters.wait_so_far 
	- 33148.1581 * parameters.total_wait_locks 
	+ 0.1249 * parameters.mean_wait_of_all 
	+ 6664660.6692 * parameters.cpu_usage 
	- 0.0122 * parameters.avg_work_of_same_past_second 
	+ 0.0604 * parameters.avg_wait_of_same_past_second 
	+ 0.0261 * parameters.avg_latency_of_same_last_20 
	- 0.0097 * parameters.max_latency_of_same_last_50 
	- 3149640.506;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM76(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 249879.6693 * parameters.total_wait_locks 
	+ 0.8835 * parameters.mean_wait_of_all 
	+ 197056560.2186 * parameters.cpu_usage 
	- 0.5139 * parameters.avg_work_of_same_past_second 
	+ 0.0043 * parameters.avg_wait_of_same_past_second 
	+ 0.0413 * parameters.avg_latency_of_same_last_20 
	- 0.0181 * parameters.max_latency_of_same_last_50 
	- 104134750.6704;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM77(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 709614.8731 * parameters.total_wait_locks 
	+ 2.4014 * parameters.mean_wait_of_all 
	+ 176468823.7661 * parameters.cpu_usage 
	- 0.4543 * parameters.avg_work_of_same_past_second 
	+ 0.0043 * parameters.avg_wait_of_same_past_second 
	+ 0.1339 * parameters.avg_latency_of_same_last_20 
	- 0.0215 * parameters.max_latency_of_same_last_50 
	- 33261544.9816;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM78(work_wait &parameters) {
  double actual_remaining = 
	-873.862 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 391121.2569 * parameters.total_wait_locks 
	+ 1.2822 * parameters.mean_wait_of_all 
	+ 176468823.7661 * parameters.cpu_usage 
	- 0.4543 * parameters.avg_work_of_same_past_second 
	+ 0.0043 * parameters.avg_wait_of_same_past_second 
	+ 0.1744 * parameters.avg_latency_of_same_last_20 
	- 0.0215 * parameters.max_latency_of_same_last_50 
	- 67679008.0334;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM79(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	+ 0.0017 * parameters.wait_so_far 
	- 391121.2569 * parameters.total_wait_locks 
	+ 0.5534 * parameters.mean_wait_of_all 
	+ 176468823.7661 * parameters.cpu_usage 
	- 0.4543 * parameters.avg_work_of_same_past_second 
	+ 0.0043 * parameters.avg_wait_of_same_past_second 
	+ 0.1744 * parameters.avg_latency_of_same_last_20 
	- 0.0215 * parameters.max_latency_of_same_last_50 
	- 53346967.8882;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM80(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	+ 0.0019 * parameters.wait_so_far 
	- 391121.2569 * parameters.total_wait_locks 
	+ 0.3172 * parameters.mean_wait_of_all 
	+ 176468823.7661 * parameters.cpu_usage 
	- 0.4543 * parameters.avg_work_of_same_past_second 
	+ 0.0043 * parameters.avg_wait_of_same_past_second 
	+ 0.1744 * parameters.avg_latency_of_same_last_20 
	- 0.0215 * parameters.max_latency_of_same_last_50 
	- 39009724.6049;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM81(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	+ 0.0016 * parameters.wait_so_far 
	- 391121.2569 * parameters.total_wait_locks 
	+ 1.2553 * parameters.mean_wait_of_all 
	+ 176468823.7661 * parameters.cpu_usage 
	- 0.4543 * parameters.avg_work_of_same_past_second 
	+ 0.0043 * parameters.avg_wait_of_same_past_second 
	+ 0.1744 * parameters.avg_latency_of_same_last_20 
	- 0.0215 * parameters.max_latency_of_same_last_50 
	- 95758106.9049;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM82(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 227553.3925 * parameters.total_wait_locks 
	+ 0.7003 * parameters.mean_wait_of_all 
	+ 176468823.7661 * parameters.cpu_usage 
	- 0.4543 * parameters.avg_work_of_same_past_second 
	+ 0.0043 * parameters.avg_wait_of_same_past_second 
	+ 0.2285 * parameters.avg_latency_of_same_last_20 
	- 0.0215 * parameters.max_latency_of_same_last_50 
	- 111208170.4686;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM83(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 231862.0166 * parameters.total_wait_locks 
	+ 0.7003 * parameters.mean_wait_of_all 
	+ 176468823.7661 * parameters.cpu_usage 
	- 0.4543 * parameters.avg_work_of_same_past_second 
	+ 0.0043 * parameters.avg_wait_of_same_past_second 
	+ 0.2285 * parameters.avg_latency_of_same_last_20 
	- 0.0215 * parameters.max_latency_of_same_last_50 
	- 112393570.0528;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM84(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	- 0.006 * parameters.wait_so_far 
	- 410388.0424 * parameters.total_wait_locks 
	+ 1.4355 * parameters.mean_wait_of_all 
	+ 176468823.7661 * parameters.cpu_usage 
	- 1.1041 * parameters.avg_work_of_same_past_second 
	+ 0.0043 * parameters.avg_wait_of_same_past_second 
	+ 0.0548 * parameters.avg_latency_of_same_last_20 
	- 0.0174 * parameters.max_latency_of_same_last_50 
	- 53953076.5263;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM85(work_wait &parameters) {
  double actual_remaining = 
	0.3317 * parameters.work_so_far 
	- 0.0041 * parameters.wait_so_far 
	- 396130.6509 * parameters.total_wait_locks 
	+ 1.3888 * parameters.mean_wait_of_all 
	+ 176468823.7661 * parameters.cpu_usage 
	- 1.4715 * parameters.avg_work_of_same_past_second 
	+ 0.0043 * parameters.avg_wait_of_same_past_second 
	+ 0.0548 * parameters.avg_latency_of_same_last_20 
	- 0.0134 * parameters.max_latency_of_same_last_50 
	- 45957376.3323;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM86(work_wait &parameters) {
  double actual_remaining = 
	0.0883 * parameters.work_so_far 
	- 0.0041 * parameters.wait_so_far 
	- 396130.6509 * parameters.total_wait_locks 
	+ 1.3888 * parameters.mean_wait_of_all 
	+ 176468823.7661 * parameters.cpu_usage 
	- 1.4715 * parameters.avg_work_of_same_past_second 
	+ 0.0043 * parameters.avg_wait_of_same_past_second 
	+ 0.0548 * parameters.avg_latency_of_same_last_20 
	- 0.0134 * parameters.max_latency_of_same_last_50 
	- 46475334.7117;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM87(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	- 0.0249 * parameters.wait_so_far 
	- 686941.7221 * parameters.total_wait_locks 
	+ 1.7077 * parameters.mean_wait_of_all 
	+ 2616827.0561 * parameters.cpu_usage 
	- 11.5479 * parameters.avg_work_of_same_past_second 
	- 0.1412 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	+ 0.0227 * parameters.max_latency_of_same_last_50 
	+ 633085973.0366;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM88(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	- 0.0242 * parameters.wait_so_far 
	- 686941.7221 * parameters.total_wait_locks 
	+ 1.7077 * parameters.mean_wait_of_all 
	+ 2616827.0561 * parameters.cpu_usage 
	- 10.8371 * parameters.avg_work_of_same_past_second 
	- 0.1412 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	+ 0.0227 * parameters.max_latency_of_same_last_50 
	+ 605146013.2039;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM89(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	- 0.011 * parameters.wait_so_far 
	- 648479.8749 * parameters.total_wait_locks 
	+ 1.7077 * parameters.mean_wait_of_all 
	+ 2616827.0561 * parameters.cpu_usage 
	+ 3.2077 * parameters.avg_work_of_same_past_second 
	- 0.1072 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	+ 0.0227 * parameters.max_latency_of_same_last_50 
	+ 62476956.5207;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM90(work_wait &parameters) {
  double actual_remaining = 
	0.476 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 366426.3288 * parameters.total_wait_locks 
	+ 3.1702 * parameters.mean_wait_of_all 
	+ 2616827.0561 * parameters.cpu_usage 
	+ 11.4056 * parameters.avg_work_of_same_past_second 
	+ 0.1418 * parameters.avg_wait_of_same_past_second 
	+ 0.2493 * parameters.avg_latency_of_same_last_20 
	+ 0.0186 * parameters.max_latency_of_same_last_50 
	- 771171339.6419;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM91(work_wait &parameters) {
  double actual_remaining = 
	0.3831 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 255063.1669 * parameters.total_wait_locks 
	+ 3.6153 * parameters.mean_wait_of_all 
	+ 2616827.0561 * parameters.cpu_usage 
	+ 11.4056 * parameters.avg_work_of_same_past_second 
	+ 0.1418 * parameters.avg_wait_of_same_past_second 
	+ 0.1736 * parameters.avg_latency_of_same_last_20 
	+ 0.0186 * parameters.max_latency_of_same_last_50 
	- 813676663.4933;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM92(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 56563.3546 * parameters.total_wait_locks 
	+ 2.0777 * parameters.mean_wait_of_all 
	+ 2616827.0561 * parameters.cpu_usage 
	+ 11.6528 * parameters.avg_work_of_same_past_second 
	+ 0.265 * parameters.avg_wait_of_same_past_second 
	- 0.0562 * parameters.avg_latency_of_same_last_20 
	- 0.0035 * parameters.max_latency_of_same_last_50 
	- 721050541.9276;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM93(work_wait &parameters) {
  double actual_remaining = 
	-0.3012 * parameters.work_so_far 
	- 0.0347 * parameters.wait_so_far 
	- 145441.7536 * parameters.total_wait_locks 
	+ 0.5148 * parameters.mean_wait_of_all 
	+ 2616827.0561 * parameters.cpu_usage 
	- 3.43 * parameters.avg_work_of_same_past_second 
	+ 0.0209 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	- 0.0076 * parameters.max_latency_of_same_last_50 
	+ 201531194.4007;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM94(work_wait &parameters) {
  double actual_remaining = 
	-0.1742 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 145441.7536 * parameters.total_wait_locks 
	+ 0.5148 * parameters.mean_wait_of_all 
	+ 2616827.0561 * parameters.cpu_usage 
	+ 0.7518 * parameters.avg_work_of_same_past_second 
	+ 0.0209 * parameters.avg_wait_of_same_past_second 
	+ 0.0453 * parameters.avg_latency_of_same_last_20 
	- 0.0298 * parameters.max_latency_of_same_last_50 
	+ 16332884.9925;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM95(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	- 0.0032 * parameters.wait_so_far 
	- 231828.76 * parameters.total_wait_locks 
	+ 0.5617 * parameters.mean_wait_of_all 
	+ 2616827.0561 * parameters.cpu_usage 
	- 0.284 * parameters.avg_work_of_same_past_second 
	- 0.0304 * parameters.avg_wait_of_same_past_second 
	+ 0.0406 * parameters.avg_latency_of_same_last_20 
	+ 0.004 * parameters.max_latency_of_same_last_50 
	+ 64793480.8512;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM96(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	- 0.0015 * parameters.wait_so_far 
	- 255967.1725 * parameters.total_wait_locks 
	+ 1.0587 * parameters.mean_wait_of_all 
	+ 2616827.0561 * parameters.cpu_usage 
	- 0.284 * parameters.avg_work_of_same_past_second 
	- 0.0176 * parameters.avg_wait_of_same_past_second 
	- 0.0097 * parameters.avg_latency_of_same_last_20 
	+ 0.0014 * parameters.max_latency_of_same_last_50 
	+ 38822651.4953;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM97(work_wait &parameters) {
  double actual_remaining = 
	0.1526 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 425167.6036 * parameters.total_wait_locks 
	- 0.5449 * parameters.mean_wait_of_all 
	- 566510299.6309 * parameters.cpu_usage 
	- 5.4039 * parameters.avg_work_of_same_past_second 
	- 0.0179 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	- 0.0807 * parameters.max_latency_of_same_last_50 
	+ 859337022.551;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM98(work_wait &parameters) {
  double actual_remaining = 
	0.1526 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 74756.8096 * parameters.total_wait_locks 
	- 0.0194 * parameters.mean_wait_of_all 
	- 566510299.6309 * parameters.cpu_usage 
	- 2.5329 * parameters.avg_work_of_same_past_second 
	- 0.0179 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	- 0.0669 * parameters.max_latency_of_same_last_50 
	+ 749242711.2656;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM99(work_wait &parameters) {
  double actual_remaining = 
	0.4761 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 543811.6751 * parameters.total_wait_locks 
	+ 2.1534 * parameters.mean_wait_of_all 
	- 566510299.6309 * parameters.cpu_usage 
	+ 7.7978 * parameters.avg_work_of_same_past_second 
	- 0.0179 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	- 0.0211 * parameters.max_latency_of_same_last_50 
	+ 196263496.2133;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM100(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	+ 0.0341 * parameters.wait_so_far 
	+ 333865.7335 * parameters.total_wait_locks 
	+ 3.6121 * parameters.mean_wait_of_all 
	- 4583017944.9611 * parameters.cpu_usage 
	+ 18.6208 * parameters.avg_work_of_same_past_second 
	- 0.0179 * parameters.avg_wait_of_same_past_second 
	+ 0.0406 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	+ 2624099313.0603;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM101(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	+ 0.0361 * parameters.wait_so_far 
	+ 333865.7335 * parameters.total_wait_locks 
	+ 3.6121 * parameters.mean_wait_of_all 
	- 4583017944.9611 * parameters.cpu_usage 
	+ 18.6208 * parameters.avg_work_of_same_past_second 
	- 0.0179 * parameters.avg_wait_of_same_past_second 
	+ 0.0406 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	+ 2625426051.0977;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM102(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	- 0.0012 * parameters.wait_so_far 
	+ 394876.5353 * parameters.total_wait_locks 
	+ 3.1036 * parameters.mean_wait_of_all 
	- 3295759456.5667 * parameters.cpu_usage 
	+ 18.6208 * parameters.avg_work_of_same_past_second 
	- 0.0179 * parameters.avg_wait_of_same_past_second 
	+ 0.0527 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	+ 1485154379.5555;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM103(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 394876.5353 * parameters.total_wait_locks 
	+ 3.1861 * parameters.mean_wait_of_all 
	- 3295759456.5667 * parameters.cpu_usage 
	+ 18.6208 * parameters.avg_work_of_same_past_second 
	- 0.0179 * parameters.avg_wait_of_same_past_second 
	+ 0.0527 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	+ 1472314732.6271;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM104(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 394876.5353 * parameters.total_wait_locks 
	+ 3.1909 * parameters.mean_wait_of_all 
	- 3295759456.5667 * parameters.cpu_usage 
	+ 18.6208 * parameters.avg_work_of_same_past_second 
	- 0.0179 * parameters.avg_wait_of_same_past_second 
	+ 0.0527 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	+ 1472112520.9473;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM105(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 678844.4667 * parameters.total_wait_locks 
	+ 2.7342 * parameters.mean_wait_of_all 
	- 3295759456.5667 * parameters.cpu_usage 
	+ 18.6208 * parameters.avg_work_of_same_past_second 
	- 0.0179 * parameters.avg_wait_of_same_past_second 
	+ 0.0552 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	+ 1399937146.1036;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM106(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 115543.9469 * parameters.total_wait_locks 
	+ 0.4666 * parameters.mean_wait_of_all 
	+ 2616827.0561 * parameters.cpu_usage 
	- 0.4228 * parameters.avg_work_of_same_past_second 
	+ 0.011 * parameters.avg_wait_of_same_past_second 
	- 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	+ 35629422.2472;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM107(work_wait &parameters) {
  double actual_remaining = 
	-0.3253 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 989832.44 * parameters.total_wait_locks 
	+ 0.5948 * parameters.mean_wait_of_all 
	+ 704974764.8362 * parameters.cpu_usage 
	- 4.4237 * parameters.avg_work_of_same_past_second 
	+ 0.0177 * parameters.avg_wait_of_same_past_second 
	+ 0.01 * parameters.avg_latency_of_same_last_20 
	- 0.0139 * parameters.max_latency_of_same_last_50 
	+ 101716075.0957;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM108(work_wait &parameters) {
  double actual_remaining = 
	-0.3563 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 994357.9994 * parameters.total_wait_locks 
	+ 0.5948 * parameters.mean_wait_of_all 
	+ 704974764.8362 * parameters.cpu_usage 
	- 4.4237 * parameters.avg_work_of_same_past_second 
	+ 0.0177 * parameters.avg_wait_of_same_past_second 
	+ 0.0112 * parameters.avg_latency_of_same_last_20 
	- 0.0139 * parameters.max_latency_of_same_last_50 
	+ 105876227.1355;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM109(work_wait &parameters) {
  double actual_remaining = 
	-147.8458 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 833546.8317 * parameters.total_wait_locks 
	+ 0.5948 * parameters.mean_wait_of_all 
	+ 601583711.9227 * parameters.cpu_usage 
	+ 2.3635 * parameters.avg_work_of_same_past_second 
	- 1.3284 * parameters.avg_wait_of_same_past_second 
	+ 0.0716 * parameters.avg_latency_of_same_last_20 
	- 0.0139 * parameters.max_latency_of_same_last_50 
	+ 518464009.4176;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM110(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 428008.6507 * parameters.total_wait_locks 
	+ 0.5948 * parameters.mean_wait_of_all 
	+ 218331736.8826 * parameters.cpu_usage 
	- 1.9401 * parameters.avg_work_of_same_past_second 
	+ 0.0177 * parameters.avg_wait_of_same_past_second 
	+ 0.0186 * parameters.avg_latency_of_same_last_20 
	- 0.0134 * parameters.max_latency_of_same_last_50 
	+ 75751183.503;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM111(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	- 0.0084 * parameters.wait_so_far 
	- 109586.2431 * parameters.total_wait_locks 
	+ 0.4488 * parameters.mean_wait_of_all 
	+ 2616827.0561 * parameters.cpu_usage 
	+ 0.115 * parameters.avg_work_of_same_past_second 
	- 0.0018 * parameters.avg_wait_of_same_past_second 
	+ 0.0036 * parameters.avg_latency_of_same_last_20 
	+ 0.0049 * parameters.max_latency_of_same_last_50 
	+ 5718706.8927;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM112(work_wait &parameters) {
  double actual_remaining = 
	-1.0926 * parameters.work_so_far 
	- 0.0096 * parameters.wait_so_far 
	- 46795.5969 * parameters.total_wait_locks 
	- 0.4973 * parameters.mean_wait_of_all 
	+ 2616827.0561 * parameters.cpu_usage 
	- 0.0271 * parameters.avg_work_of_same_past_second 
	- 0.0045 * parameters.avg_wait_of_same_past_second 
	- 0.0403 * parameters.avg_latency_of_same_last_20 
	- 0.1659 * parameters.max_latency_of_same_last_50 
	+ 401484989.3856;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM113(work_wait &parameters) {
  double actual_remaining = 
	-1.4576 * parameters.work_so_far 
	- 0.0061 * parameters.wait_so_far 
	- 138437.9554 * parameters.total_wait_locks 
	- 0.5108 * parameters.mean_wait_of_all 
	+ 2616827.0561 * parameters.cpu_usage 
	- 0.0271 * parameters.avg_work_of_same_past_second 
	- 0.0045 * parameters.avg_wait_of_same_past_second 
	- 0.0403 * parameters.avg_latency_of_same_last_20 
	- 0.2404 * parameters.max_latency_of_same_last_50 
	+ 489867892.9175;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM114(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	- 0.0028 * parameters.wait_so_far 
	- 43981.0997 * parameters.total_wait_locks 
	+ 0.0249 * parameters.mean_wait_of_all 
	- 67447738.9919 * parameters.cpu_usage 
	- 0.0271 * parameters.avg_work_of_same_past_second 
	- 0.0045 * parameters.avg_wait_of_same_past_second 
	- 0.0119 * parameters.avg_latency_of_same_last_20 
	- 0.009 * parameters.max_latency_of_same_last_50 
	+ 127368950.3057;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM115(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	- 0.0107 * parameters.wait_so_far 
	- 43981.0997 * parameters.total_wait_locks 
	+ 0.0249 * parameters.mean_wait_of_all 
	- 382592764.5568 * parameters.cpu_usage 
	- 0.3277 * parameters.avg_work_of_same_past_second 
	- 0.0045 * parameters.avg_wait_of_same_past_second 
	- 0.156 * parameters.avg_latency_of_same_last_20 
	- 0.009 * parameters.max_latency_of_same_last_50 
	+ 548405367.1;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM116(work_wait &parameters) {
  double actual_remaining = 
	0.0004 * parameters.work_so_far 
	- 0.0088 * parameters.wait_so_far 
	- 43981.0997 * parameters.total_wait_locks 
	+ 0.0249 * parameters.mean_wait_of_all 
	- 310366976.8397 * parameters.cpu_usage 
	- 0.2546 * parameters.avg_work_of_same_past_second 
	- 0.0045 * parameters.avg_wait_of_same_past_second 
	- 0.0418 * parameters.avg_latency_of_same_last_20 
	- 0.009 * parameters.max_latency_of_same_last_50 
	+ 379882318.7526;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM117(work_wait &parameters) {
  double actual_remaining = 
	0.0148 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 105346.0855 * parameters.total_wait_locks 
	- 0.3486 * parameters.mean_wait_of_all 
	- 2290907.1822 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_work_of_same_past_second 
	- 0.0018 * parameters.avg_wait_of_same_past_second 
	- 0.001 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 16146337.544;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM118(work_wait &parameters) {
  double actual_remaining = 
	0.0796 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 1105458.0265 * parameters.total_wait_locks 
	- 2.7203 * parameters.mean_wait_of_all 
	- 278693441.6843 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_work_of_same_past_second 
	- 0.0143 * parameters.avg_wait_of_same_past_second 
	- 0.0262 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 280358459.1946;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM119(work_wait &parameters) {
  double actual_remaining = 
	0.0397 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 201184.2955 * parameters.total_wait_locks 
	- 0.4388 * parameters.mean_wait_of_all 
	- 11075381.5556 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_work_of_same_past_second 
	- 0.007 * parameters.avg_wait_of_same_past_second 
	- 0.0105 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 26892254.3223;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM120(work_wait &parameters) {
  double actual_remaining = 
	0.0195 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 5820.9984 * parameters.total_wait_locks 
	- 0.0135 * parameters.mean_wait_of_all 
	- 36687533.5905 * parameters.cpu_usage 
	- 0.0924 * parameters.avg_work_of_same_past_second 
	- 0.0043 * parameters.avg_wait_of_same_past_second 
	- 0.0028 * parameters.avg_latency_of_same_last_20 
	- 0.0158 * parameters.max_latency_of_same_last_50 
	+ 62423355.571;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM121(work_wait &parameters) {
  double actual_remaining = 
	0.0747 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 87828.9248 * parameters.total_wait_locks 
	+ 0.2974 * parameters.mean_wait_of_all 
	- 3589189.4104 * parameters.cpu_usage 
	- 0.5602 * parameters.avg_work_of_same_past_second 
	- 0.0064 * parameters.avg_wait_of_same_past_second 
	- 0.0549 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 63079174.7346;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM122(work_wait &parameters) {
  double actual_remaining = 
	0.0747 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 87828.9248 * parameters.total_wait_locks 
	+ 0.2974 * parameters.mean_wait_of_all 
	- 3589189.4104 * parameters.cpu_usage 
	- 0.4035 * parameters.avg_work_of_same_past_second 
	- 0.0064 * parameters.avg_wait_of_same_past_second 
	- 0.0549 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 57203092.1269;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM123(work_wait &parameters) {
  double actual_remaining = 
	0.1221 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 34520.507 * parameters.total_wait_locks 
	+ 0.1563 * parameters.mean_wait_of_all 
	+ 24677555.6196 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_work_of_same_past_second 
	- 0.0064 * parameters.avg_wait_of_same_past_second 
	- 0.0357 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 2364015.227;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM124(work_wait &parameters) {
  double actual_remaining = 
	0.0849 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 34520.507 * parameters.total_wait_locks 
	- 0.1444 * parameters.mean_wait_of_all 
	- 3589189.4104 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_work_of_same_past_second 
	- 0.0064 * parameters.avg_wait_of_same_past_second 
	- 0.0457 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 56989619.9092;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM125(work_wait &parameters) {
  double actual_remaining = 
	-4.8938 * parameters.work_so_far 
	+ 0.0309 * parameters.wait_so_far 
	+ 30072.0362 * parameters.total_wait_locks 
	- 0.0537 * parameters.mean_wait_of_all 
	- 133061.5358 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_work_of_same_past_second 
	+ 0.4718 * parameters.avg_wait_of_same_past_second 
	+ 0.0217 * parameters.avg_latency_of_same_last_20 
	+ 0.0031 * parameters.max_latency_of_same_last_50 
	- 1212955.5616;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM126(work_wait &parameters) {
  double actual_remaining = 
	-5.9883 * parameters.work_so_far 
	+ 0.0309 * parameters.wait_so_far 
	+ 30072.0362 * parameters.total_wait_locks 
	- 0.0537 * parameters.mean_wait_of_all 
	- 133061.5358 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_work_of_same_past_second 
	+ 0.4518 * parameters.avg_wait_of_same_past_second 
	+ 0.0217 * parameters.avg_latency_of_same_last_20 
	+ 0.0031 * parameters.max_latency_of_same_last_50 
	+ 6100265.5856;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM127(work_wait &parameters) {
  double actual_remaining = 
	0.5716 * parameters.work_so_far 
	+ 0.0309 * parameters.wait_so_far 
	+ 30072.0362 * parameters.total_wait_locks 
	- 0.0537 * parameters.mean_wait_of_all 
	- 133061.5358 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_work_of_same_past_second 
	- 0.0231 * parameters.avg_wait_of_same_past_second 
	+ 0.0217 * parameters.avg_latency_of_same_last_20 
	+ 0.0249 * parameters.max_latency_of_same_last_50 
	- 6448019.4961;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM128(work_wait &parameters) {
  double actual_remaining = 
	0.5716 * parameters.work_so_far 
	+ 0.0786 * parameters.wait_so_far 
	+ 30072.0362 * parameters.total_wait_locks 
	- 0.0537 * parameters.mean_wait_of_all 
	- 133061.5358 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_work_of_same_past_second 
	- 0.0132 * parameters.avg_wait_of_same_past_second 
	+ 0.3146 * parameters.avg_latency_of_same_last_20 
	+ 0.0031 * parameters.max_latency_of_same_last_50 
	- 47565041.7296;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM129(work_wait &parameters) {
  double actual_remaining = 
	3.6177 * parameters.work_so_far 
	+ 0.0107 * parameters.wait_so_far 
	+ 26159.9968 * parameters.total_wait_locks 
	- 0.2844 * parameters.mean_wait_of_all 
	- 133061.5358 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_work_of_same_past_second 
	- 0.0216 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 0.0031 * parameters.max_latency_of_same_last_50 
	+ 28340630.7359;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM130(work_wait &parameters) {
  double actual_remaining = 
	3.2014 * parameters.work_so_far 
	+ 0.0067 * parameters.wait_so_far 
	+ 26159.9968 * parameters.total_wait_locks 
	- 0.2093 * parameters.mean_wait_of_all 
	- 133061.5358 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_work_of_same_past_second 
	- 0.0216 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 0.0031 * parameters.max_latency_of_same_last_50 
	+ 21813719.9131;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM131(work_wait &parameters) {
  double actual_remaining = 
	1.1774 * parameters.work_so_far 
	- 0.0023 * parameters.wait_so_far 
	+ 26159.9968 * parameters.total_wait_locks 
	- 0.0426 * parameters.mean_wait_of_all 
	- 133061.5358 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_work_of_same_past_second 
	- 0.0165 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 0.0237 * parameters.max_latency_of_same_last_50 
	- 3955742.0596;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM132(work_wait &parameters) {
  double actual_remaining = 
	4.3165 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 33012.9561 * parameters.total_wait_locks 
	- 0.5465 * parameters.mean_wait_of_all 
	- 54705892.8105 * parameters.cpu_usage 
	+ 0.7506 * parameters.avg_work_of_same_past_second 
	- 0.0376 * parameters.avg_wait_of_same_past_second 
	- 0.0751 * parameters.avg_latency_of_same_last_20 
	+ 0.0035 * parameters.max_latency_of_same_last_50 
	+ 110622934.5688;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM133(work_wait &parameters) {
  double actual_remaining = 
	1.8151 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 33012.9561 * parameters.total_wait_locks 
	- 0.5384 * parameters.mean_wait_of_all 
	- 54705892.8105 * parameters.cpu_usage 
	+ 0.7352 * parameters.avg_work_of_same_past_second 
	- 0.037 * parameters.avg_wait_of_same_past_second 
	- 0.0056 * parameters.avg_latency_of_same_last_20 
	+ 0.0035 * parameters.max_latency_of_same_last_50 
	+ 76819927.3677;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM134(work_wait &parameters) {
  double actual_remaining = 
	0.4708 * parameters.work_so_far 
	+ 0.0074 * parameters.wait_so_far 
	+ 93474.9885 * parameters.total_wait_locks 
	- 0.04 * parameters.mean_wait_of_all 
	- 118871938.2205 * parameters.cpu_usage 
	- 0.0544 * parameters.avg_work_of_same_past_second 
	- 0.0073 * parameters.avg_wait_of_same_past_second 
	- 0.0029 * parameters.avg_latency_of_same_last_20 
	+ 0.0035 * parameters.max_latency_of_same_last_50 
	+ 120667319.8303;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM135(work_wait &parameters) {
  double actual_remaining = 
	0.1346 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 10103.8192 * parameters.total_wait_locks 
	- 1.2451 * parameters.mean_wait_of_all 
	- 38257952.9616 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_work_of_same_past_second 
	- 0.0104 * parameters.avg_wait_of_same_past_second 
	- 0.1276 * parameters.avg_latency_of_same_last_20 
	+ 0.0035 * parameters.max_latency_of_same_last_50 
	+ 191395697.8652;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM136(work_wait &parameters) {
  double actual_remaining = 
	32.4772 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 378074.6929 * parameters.total_wait_locks 
	- 0.0552 * parameters.mean_wait_of_all 
	- 28053262.1031 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_work_of_same_past_second 
	- 0.2411 * parameters.avg_wait_of_same_past_second 
	+ 0.2873 * parameters.avg_latency_of_same_last_20 
	+ 0.006 * parameters.max_latency_of_same_last_50 
	+ 148171227.9108;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM137(work_wait &parameters) {
  double actual_remaining = 
	47.2246 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 582979.7297 * parameters.total_wait_locks 
	- 0.0552 * parameters.mean_wait_of_all 
	- 28053262.1031 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_work_of_same_past_second 
	- 0.2411 * parameters.avg_wait_of_same_past_second 
	+ 0.1129 * parameters.avg_latency_of_same_last_20 
	+ 0.006 * parameters.max_latency_of_same_last_50 
	+ 164470351.2753;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM138(work_wait &parameters) {
  double actual_remaining = 
	0.033 * parameters.work_so_far 
	+ 0.0124 * parameters.wait_so_far 
	+ 181784.8011 * parameters.total_wait_locks 
	- 0.0552 * parameters.mean_wait_of_all 
	- 28053262.1031 * parameters.cpu_usage 
	+ 0.3978 * parameters.avg_work_of_same_past_second 
	- 0.1277 * parameters.avg_wait_of_same_past_second 
	+ 0.0531 * parameters.avg_latency_of_same_last_20 
	- 0.0329 * parameters.max_latency_of_same_last_50 
	+ 65434737.5038;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM139(work_wait &parameters) {
  double actual_remaining = 
	0.033 * parameters.work_so_far 
	+ 0.015 * parameters.wait_so_far 
	+ 203177.8275 * parameters.total_wait_locks 
	- 0.0552 * parameters.mean_wait_of_all 
	- 28053262.1031 * parameters.cpu_usage 
	+ 0.3978 * parameters.avg_work_of_same_past_second 
	- 0.1277 * parameters.avg_wait_of_same_past_second 
	+ 0.0531 * parameters.avg_latency_of_same_last_20 
	- 0.0329 * parameters.max_latency_of_same_last_50 
	+ 64648787.4631;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM140(work_wait &parameters) {
  double actual_remaining = 
	0.033 * parameters.work_so_far 
	+ 0.0034 * parameters.wait_so_far 
	+ 134726.7582 * parameters.total_wait_locks 
	- 0.334 * parameters.mean_wait_of_all 
	- 28053262.1031 * parameters.cpu_usage 
	+ 0.3978 * parameters.avg_work_of_same_past_second 
	- 0.1478 * parameters.avg_wait_of_same_past_second 
	+ 0.0531 * parameters.avg_latency_of_same_last_20 
	- 0.0171 * parameters.max_latency_of_same_last_50 
	+ 64683898.2052;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM141(work_wait &parameters) {
  double actual_remaining = 
	0.033 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 92366.0424 * parameters.total_wait_locks 
	- 0.0552 * parameters.mean_wait_of_all 
	- 28053262.1031 * parameters.cpu_usage 
	+ 0.6834 * parameters.avg_work_of_same_past_second 
	- 0.1277 * parameters.avg_wait_of_same_past_second 
	+ 0.3266 * parameters.avg_latency_of_same_last_20 
	+ 0.1483 * parameters.max_latency_of_same_last_50 
	- 157117734.6164;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM142(work_wait &parameters) {
  double actual_remaining = 
	0.033 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 92366.0424 * parameters.total_wait_locks 
	- 0.0552 * parameters.mean_wait_of_all 
	- 28053262.1031 * parameters.cpu_usage 
	+ 0.6834 * parameters.avg_work_of_same_past_second 
	- 0.1277 * parameters.avg_wait_of_same_past_second 
	+ 0.3704 * parameters.avg_latency_of_same_last_20 
	+ 0.006 * parameters.max_latency_of_same_last_50 
	- 5489160.4873;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM143(work_wait &parameters) {
  double actual_remaining = 
	0.033 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 145613.9312 * parameters.total_wait_locks 
	- 0.0552 * parameters.mean_wait_of_all 
	- 28053262.1031 * parameters.cpu_usage 
	+ 0.6834 * parameters.avg_work_of_same_past_second 
	- 0.1277 * parameters.avg_wait_of_same_past_second 
	+ 0.3704 * parameters.avg_latency_of_same_last_20 
	+ 0.006 * parameters.max_latency_of_same_last_50 
	- 8558930.3943;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM144(work_wait &parameters) {
  double actual_remaining = 
	0.033 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 148572.1473 * parameters.total_wait_locks 
	- 0.0552 * parameters.mean_wait_of_all 
	- 28053262.1031 * parameters.cpu_usage 
	+ 0.6834 * parameters.avg_work_of_same_past_second 
	- 0.1277 * parameters.avg_wait_of_same_past_second 
	+ 0.3704 * parameters.avg_latency_of_same_last_20 
	+ 0.006 * parameters.max_latency_of_same_last_50 
	- 8191600.3463;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM145(work_wait &parameters) {
  double actual_remaining = 
	0.033 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 92366.0424 * parameters.total_wait_locks 
	- 0.0552 * parameters.mean_wait_of_all 
	- 28053262.1031 * parameters.cpu_usage 
	+ 0.6834 * parameters.avg_work_of_same_past_second 
	- 0.1277 * parameters.avg_wait_of_same_past_second 
	+ 0.3704 * parameters.avg_latency_of_same_last_20 
	+ 0.006 * parameters.max_latency_of_same_last_50 
	- 1545771.8982;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM146(work_wait &parameters) {
  double actual_remaining = 
	0.033 * parameters.work_so_far 
	- 0.0228 * parameters.wait_so_far 
	+ 296279.4427 * parameters.total_wait_locks 
	- 0.7121 * parameters.mean_wait_of_all 
	- 28053262.1031 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_work_of_same_past_second 
	- 0.1152 * parameters.avg_wait_of_same_past_second 
	+ 0.026 * parameters.avg_latency_of_same_last_20 
	+ 0.006 * parameters.max_latency_of_same_last_50 
	+ 47179004.8403;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM147(work_wait &parameters) {
  double actual_remaining = 
	0.0035 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 25332.6138 * parameters.total_wait_locks 
	+ 0.0529 * parameters.mean_wait_of_all 
	- 133061.5358 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_work_of_same_past_second 
	- 0.0402 * parameters.avg_wait_of_same_past_second 
	+ 0.1138 * parameters.avg_latency_of_same_last_20 
	- 0.0038 * parameters.max_latency_of_same_last_50 
	- 17085451.3999;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM148(work_wait &parameters) {
  double actual_remaining = 
	0.0035 * parameters.work_so_far 
	+ 0.0302 * parameters.wait_so_far 
	- 127690.544 * parameters.total_wait_locks 
	+ 0.2217 * parameters.mean_wait_of_all 
	- 59826224.1048 * parameters.cpu_usage 
	- 0.2989 * parameters.avg_work_of_same_past_second 
	+ 0.0338 * parameters.avg_wait_of_same_past_second 
	+ 0.0602 * parameters.avg_latency_of_same_last_20 
	- 0.041 * parameters.max_latency_of_same_last_50 
	+ 103971791.9621;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM149(work_wait &parameters) {
  double actual_remaining = 
	0.0035 * parameters.work_so_far 
	+ 0.022 * parameters.wait_so_far 
	- 127690.544 * parameters.total_wait_locks 
	+ 0.2217 * parameters.mean_wait_of_all 
	- 77737436.9773 * parameters.cpu_usage 
	- 0.2989 * parameters.avg_work_of_same_past_second 
	+ 0.0496 * parameters.avg_wait_of_same_past_second 
	+ 0.0951 * parameters.avg_latency_of_same_last_20 
	- 0.041 * parameters.max_latency_of_same_last_50 
	+ 104128563.0961;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM150(work_wait &parameters) {
  double actual_remaining = 
	0.0035 * parameters.work_so_far 
	+ 0.0454 * parameters.wait_so_far 
	- 157381.2458 * parameters.total_wait_locks 
	+ 0.2217 * parameters.mean_wait_of_all 
	- 193239577.2663 * parameters.cpu_usage 
	- 0.2989 * parameters.avg_work_of_same_past_second 
	+ 0.1229 * parameters.avg_wait_of_same_past_second 
	+ 0.0602 * parameters.avg_latency_of_same_last_20 
	- 0.041 * parameters.max_latency_of_same_last_50 
	+ 224602655.5643;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM151(work_wait &parameters) {
  double actual_remaining = 
	0.0035 * parameters.work_so_far 
	+ 0.0058 * parameters.wait_so_far 
	- 86865.8291 * parameters.total_wait_locks 
	+ 0.2408 * parameters.mean_wait_of_all 
	- 133061.5358 * parameters.cpu_usage 
	- 0.198 * parameters.avg_work_of_same_past_second 
	+ 0.007 * parameters.avg_wait_of_same_past_second 
	+ 0.0807 * parameters.avg_latency_of_same_last_20 
	- 0.0138 * parameters.max_latency_of_same_last_50 
	+ 5401937.9307;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM152(work_wait &parameters) {
  double actual_remaining = 
	0.0035 * parameters.work_so_far 
	+ 0.0058 * parameters.wait_so_far 
	- 86865.8291 * parameters.total_wait_locks 
	+ 0.3308 * parameters.mean_wait_of_all 
	- 133061.5358 * parameters.cpu_usage 
	- 1.4427 * parameters.avg_work_of_same_past_second 
	+ 0.0147 * parameters.avg_wait_of_same_past_second 
	+ 0.1334 * parameters.avg_latency_of_same_last_20 
	- 0.0133 * parameters.max_latency_of_same_last_50 
	+ 5476478.9831;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM153(work_wait &parameters) {
  double actual_remaining = 
	175.5868 * parameters.work_so_far 
	- 0.0048 * parameters.wait_so_far 
	- 345068.4394 * parameters.total_wait_locks 
	+ 0.5784 * parameters.mean_wait_of_all 
	- 133061.5358 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_work_of_same_past_second 
	+ 0.0162 * parameters.avg_wait_of_same_past_second 
	+ 0.2188 * parameters.avg_latency_of_same_last_20 
	- 0.0463 * parameters.max_latency_of_same_last_50 
	+ 30734270.0386;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM154(work_wait &parameters) {
  double actual_remaining = 
	188.5017 * parameters.work_so_far 
	+ 0.0067 * parameters.wait_so_far 
	- 345068.4394 * parameters.total_wait_locks 
	+ 0.5784 * parameters.mean_wait_of_all 
	- 133061.5358 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_work_of_same_past_second 
	+ 0.0162 * parameters.avg_wait_of_same_past_second 
	+ 0.2188 * parameters.avg_latency_of_same_last_20 
	- 0.0463 * parameters.max_latency_of_same_last_50 
	+ 33473328.1982;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM155(work_wait &parameters) {
  double actual_remaining = 
	98.6818 * parameters.work_so_far 
	+ 0.014 * parameters.wait_so_far 
	- 249516.6482 * parameters.total_wait_locks 
	+ 0.5784 * parameters.mean_wait_of_all 
	- 66186154.0204 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_work_of_same_past_second 
	+ 0.0162 * parameters.avg_wait_of_same_past_second 
	+ 0.2017 * parameters.avg_latency_of_same_last_20 
	- 0.0463 * parameters.max_latency_of_same_last_50 
	+ 59846372.081;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM156(work_wait &parameters) {
  double actual_remaining = 
	98.6818 * parameters.work_so_far 
	+ 0.014 * parameters.wait_so_far 
	- 249516.6482 * parameters.total_wait_locks 
	+ 0.5784 * parameters.mean_wait_of_all 
	- 66186154.0204 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_work_of_same_past_second 
	+ 0.0162 * parameters.avg_wait_of_same_past_second 
	+ 0.2017 * parameters.avg_latency_of_same_last_20 
	- 0.0463 * parameters.max_latency_of_same_last_50 
	+ 60336472.2584;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM157(work_wait &parameters) {
  double actual_remaining = 
	98.6818 * parameters.work_so_far 
	+ 0.0067 * parameters.wait_so_far 
	- 268126.4365 * parameters.total_wait_locks 
	+ 0.5784 * parameters.mean_wait_of_all 
	- 48402629.1207 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_work_of_same_past_second 
	+ 0.0162 * parameters.avg_wait_of_same_past_second 
	+ 0.2017 * parameters.avg_latency_of_same_last_20 
	- 0.0463 * parameters.max_latency_of_same_last_50 
	+ 48081380.0582;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM158(work_wait &parameters) {
  double actual_remaining = 
	0.1709 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 213176.6309 * parameters.total_wait_locks 
	- 1.0964 * parameters.mean_wait_of_all 
	+ 6828464.2618 * parameters.cpu_usage 
	+ 2.249 * parameters.avg_work_of_same_past_second 
	- 0.0067 * parameters.avg_wait_of_same_past_second 
	- 0.0015 * parameters.avg_latency_of_same_last_20 
	- 0.0013 * parameters.max_latency_of_same_last_50 
	- 18283412.2657;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM159(work_wait &parameters) {
  double actual_remaining = 
	0.91 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 15462.5179 * parameters.total_wait_locks 
	+ 0.1412 * parameters.mean_wait_of_all 
	+ 8049700.0113 * parameters.cpu_usage 
	- 0.2672 * parameters.avg_work_of_same_past_second 
	- 0.0067 * parameters.avg_wait_of_same_past_second 
	- 0.0015 * parameters.avg_latency_of_same_last_20 
	- 0.0013 * parameters.max_latency_of_same_last_50 
	+ 15297303.4285;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM160(work_wait &parameters) {
  double actual_remaining = 
	0.3524 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 9927.1228 * parameters.total_wait_locks 
	- 0.0003 * parameters.mean_wait_of_all 
	- 122550096.1391 * parameters.cpu_usage 
	+ 0.0662 * parameters.avg_work_of_same_past_second 
	- 0.0142 * parameters.avg_wait_of_same_past_second 
	- 0.0044 * parameters.avg_latency_of_same_last_20 
	+ 0.1105 * parameters.max_latency_of_same_last_50 
	+ 24326813.2807;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM161(work_wait &parameters) {
  double actual_remaining = 
	0.0793 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 11218.1208 * parameters.total_wait_locks 
	- 0.2386 * parameters.mean_wait_of_all 
	- 20327637.9363 * parameters.cpu_usage 
	+ 0.5779 * parameters.avg_work_of_same_past_second 
	- 0.0168 * parameters.avg_wait_of_same_past_second 
	- 0.0054 * parameters.avg_latency_of_same_last_20 
	- 0.0022 * parameters.max_latency_of_same_last_50 
	+ 43097333.8461;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM162(work_wait &parameters) {
  double actual_remaining = 
	0.0014 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	- 75142.1338 * parameters.total_wait_locks 
	+ 0.3675 * parameters.mean_wait_of_all 
	- 133061.5358 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0332 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 14383437.3876;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM163(work_wait &parameters) {
  double actual_remaining = 
	0.0014 * parameters.work_so_far 
	- 0.0032 * parameters.wait_so_far 
	- 201353.0862 * parameters.total_wait_locks 
	+ 0.6849 * parameters.mean_wait_of_all 
	- 133061.5358 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0132 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 31331952.5746;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM164(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0223 * parameters.wait_so_far 
	- 62449.9265 * parameters.total_wait_locks 
	+ 0.0941 * parameters.mean_wait_of_all 
	- 2741031.406 * parameters.cpu_usage 
	+ 1.1176 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0022 * parameters.avg_latency_of_same_last_20 
	+ 0.0134 * parameters.max_latency_of_same_last_50 
	+ 9237455.1669;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM165(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0061 * parameters.wait_so_far 
	- 277394.4728 * parameters.total_wait_locks 
	+ 1.1258 * parameters.mean_wait_of_all 
	+ 143568171.4396 * parameters.cpu_usage 
	- 2.4851 * parameters.avg_work_of_same_past_second 
	+ 0.058 * parameters.avg_wait_of_same_past_second 
	- 0.0109 * parameters.avg_latency_of_same_last_20 
	+ 0.0209 * parameters.max_latency_of_same_last_50 
	- 82963758.3525;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM166(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0055 * parameters.wait_so_far 
	- 256726.728 * parameters.total_wait_locks 
	+ 1.0266 * parameters.mean_wait_of_all 
	+ 319700583.0335 * parameters.cpu_usage 
	+ 1.2394 * parameters.avg_work_of_same_past_second 
	+ 0.3946 * parameters.avg_wait_of_same_past_second 
	- 0.0109 * parameters.avg_latency_of_same_last_20 
	+ 0.0201 * parameters.max_latency_of_same_last_50 
	- 439281392.3252;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM167(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.016 * parameters.wait_so_far 
	- 62449.9265 * parameters.total_wait_locks 
	+ 0.0941 * parameters.mean_wait_of_all 
	- 2741031.406 * parameters.cpu_usage 
	+ 1.4652 * parameters.avg_work_of_same_past_second 
	- 0.028 * parameters.avg_wait_of_same_past_second 
	- 0.0153 * parameters.avg_latency_of_same_last_20 
	+ 0.0151 * parameters.max_latency_of_same_last_50 
	+ 42287671.701;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM168(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 326947.9612 * parameters.total_wait_locks 
	- 1.905 * parameters.mean_wait_of_all 
	- 2741031.406 * parameters.cpu_usage 
	+ 1.4652 * parameters.avg_work_of_same_past_second 
	- 0.028 * parameters.avg_wait_of_same_past_second 
	- 0.0153 * parameters.avg_latency_of_same_last_20 
	+ 0.0151 * parameters.max_latency_of_same_last_50 
	+ 132021639.2767;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM169(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0008 * parameters.wait_so_far 
	- 328586.5445 * parameters.total_wait_locks 
	+ 1.0802 * parameters.mean_wait_of_all 
	- 2741031.406 * parameters.cpu_usage 
	+ 0.2024 * parameters.avg_work_of_same_past_second 
	+ 0.035 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0067 * parameters.max_latency_of_same_last_50 
	+ 33154439.4666;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM170(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0014 * parameters.wait_so_far 
	- 2207651.4669 * parameters.total_wait_locks 
	+ 5.8248 * parameters.mean_wait_of_all 
	- 2741031.406 * parameters.cpu_usage 
	+ 3.1974 * parameters.avg_work_of_same_past_second 
	- 0.104 * parameters.avg_wait_of_same_past_second 
	- 0.0104 * parameters.avg_latency_of_same_last_20 
	+ 0.0294 * parameters.max_latency_of_same_last_50 
	+ 263532366.1696;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM171(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0014 * parameters.wait_so_far 
	- 976911.7169 * parameters.total_wait_locks 
	- 0.0425 * parameters.mean_wait_of_all 
	- 2741031.406 * parameters.cpu_usage 
	+ 3.7672 * parameters.avg_work_of_same_past_second 
	- 0.1409 * parameters.avg_wait_of_same_past_second 
	- 0.0104 * parameters.avg_latency_of_same_last_20 
	+ 0.0832 * parameters.max_latency_of_same_last_50 
	+ 305667169.7219;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM172(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0014 * parameters.wait_so_far 
	- 1207650.353 * parameters.total_wait_locks 
	+ 5.6551 * parameters.mean_wait_of_all 
	- 2741031.406 * parameters.cpu_usage 
	+ 1.6617 * parameters.avg_work_of_same_past_second 
	- 0.0497 * parameters.avg_wait_of_same_past_second 
	- 0.0104 * parameters.avg_latency_of_same_last_20 
	+ 0.0265 * parameters.max_latency_of_same_last_50 
	- 119301015.079;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM173(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0014 * parameters.wait_so_far 
	- 836289.3909 * parameters.total_wait_locks 
	+ 4.7123 * parameters.mean_wait_of_all 
	- 2741031.406 * parameters.cpu_usage 
	+ 2.6641 * parameters.avg_work_of_same_past_second 
	- 0.077 * parameters.avg_wait_of_same_past_second 
	- 0.0104 * parameters.avg_latency_of_same_last_20 
	+ 0.0209 * parameters.max_latency_of_same_last_50 
	- 186142202.2758;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM174(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0037 * parameters.wait_so_far 
	- 629855.185 * parameters.total_wait_locks 
	+ 2.6544 * parameters.mean_wait_of_all 
	- 2741031.406 * parameters.cpu_usage 
	+ 1.5905 * parameters.avg_work_of_same_past_second 
	- 0.0543 * parameters.avg_wait_of_same_past_second 
	- 0.0112 * parameters.avg_latency_of_same_last_20 
	+ 0.0125 * parameters.max_latency_of_same_last_50 
	- 27655684.2002;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM175(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0037 * parameters.wait_so_far 
	- 629855.185 * parameters.total_wait_locks 
	+ 2.6544 * parameters.mean_wait_of_all 
	- 2741031.406 * parameters.cpu_usage 
	+ 1.5905 * parameters.avg_work_of_same_past_second 
	- 0.0543 * parameters.avg_wait_of_same_past_second 
	- 0.0116 * parameters.avg_latency_of_same_last_20 
	+ 0.0125 * parameters.max_latency_of_same_last_50 
	- 27098977.478;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM176(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0091 * parameters.wait_so_far 
	- 629855.185 * parameters.total_wait_locks 
	+ 2.4117 * parameters.mean_wait_of_all 
	- 2741031.406 * parameters.cpu_usage 
	+ 1.5905 * parameters.avg_work_of_same_past_second 
	- 0.0543 * parameters.avg_wait_of_same_past_second 
	- 0.0079 * parameters.avg_latency_of_same_last_20 
	+ 0.0125 * parameters.max_latency_of_same_last_50 
	+ 356157.9928;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM177(work_wait &parameters) {
  double actual_remaining = 
	-1.1834 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 343547.728 * parameters.total_wait_locks 
	- 1.1716 * parameters.mean_wait_of_all 
	- 163991732.3605 * parameters.cpu_usage 
	- 2.0395 * parameters.avg_work_of_same_past_second 
	+ 0.0577 * parameters.avg_wait_of_same_past_second 
	+ 0.0475 * parameters.avg_latency_of_same_last_20 
	- 0.0411 * parameters.max_latency_of_same_last_50 
	+ 335924749.557;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM178(work_wait &parameters) {
  double actual_remaining = 
	-1.1834 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 378709.3957 * parameters.total_wait_locks 
	- 1.1181 * parameters.mean_wait_of_all 
	- 163991732.3605 * parameters.cpu_usage 
	- 2.0395 * parameters.avg_work_of_same_past_second 
	+ 0.0577 * parameters.avg_wait_of_same_past_second 
	+ 0.0475 * parameters.avg_latency_of_same_last_20 
	- 0.0411 * parameters.max_latency_of_same_last_50 
	+ 331475404.1682;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM179(work_wait &parameters) {
  double actual_remaining = 
	-0.5557 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 35049.4552 * parameters.total_wait_locks 
	+ 0.0755 * parameters.mean_wait_of_all 
	- 540008139.3376 * parameters.cpu_usage 
	- 1.174 * parameters.avg_work_of_same_past_second 
	+ 0.0577 * parameters.avg_wait_of_same_past_second 
	+ 0.1849 * parameters.avg_latency_of_same_last_20 
	- 0.1054 * parameters.max_latency_of_same_last_50 
	+ 658869678.9681;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM180(work_wait &parameters) {
  double actual_remaining = 
	0.0761 * parameters.work_so_far 
	+ 0.0548 * parameters.wait_so_far 
	- 289325.7105 * parameters.total_wait_locks 
	+ 0.7746 * parameters.mean_wait_of_all 
	+ 325431194.7415 * parameters.cpu_usage 
	- 2.9483 * parameters.avg_work_of_same_past_second 
	+ 0.4087 * parameters.avg_wait_of_same_past_second 
	+ 0.0065 * parameters.avg_latency_of_same_last_20 
	- 0.0031 * parameters.max_latency_of_same_last_50 
	- 299874975.6575;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM181(work_wait &parameters) {
  double actual_remaining = 
	0.0761 * parameters.work_so_far 
	+ 0.0516 * parameters.wait_so_far 
	- 289325.7105 * parameters.total_wait_locks 
	+ 0.7746 * parameters.mean_wait_of_all 
	+ 325431194.7415 * parameters.cpu_usage 
	- 2.9483 * parameters.avg_work_of_same_past_second 
	+ 0.4087 * parameters.avg_wait_of_same_past_second 
	+ 0.0065 * parameters.avg_latency_of_same_last_20 
	- 0.0031 * parameters.max_latency_of_same_last_50 
	- 291009084.3585;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM182(work_wait &parameters) {
  double actual_remaining = 
	0.0761 * parameters.work_so_far 
	+ 0.0514 * parameters.wait_so_far 
	- 289325.7105 * parameters.total_wait_locks 
	+ 0.7746 * parameters.mean_wait_of_all 
	+ 325431194.7415 * parameters.cpu_usage 
	- 2.9483 * parameters.avg_work_of_same_past_second 
	+ 0.4087 * parameters.avg_wait_of_same_past_second 
	+ 0.0065 * parameters.avg_latency_of_same_last_20 
	- 0.0031 * parameters.max_latency_of_same_last_50 
	- 291105715.1868;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM183(work_wait &parameters) {
  double actual_remaining = 
	0.0761 * parameters.work_so_far 
	+ 0.0548 * parameters.wait_so_far 
	- 289325.7105 * parameters.total_wait_locks 
	+ 0.7746 * parameters.mean_wait_of_all 
	+ 325431194.7415 * parameters.cpu_usage 
	- 2.9483 * parameters.avg_work_of_same_past_second 
	+ 0.4087 * parameters.avg_wait_of_same_past_second 
	+ 0.0065 * parameters.avg_latency_of_same_last_20 
	- 0.0031 * parameters.max_latency_of_same_last_50 
	- 290990234.0125;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM184(work_wait &parameters) {
  double actual_remaining = 
	0.0761 * parameters.work_so_far 
	+ 0.0237 * parameters.wait_so_far 
	- 289325.7105 * parameters.total_wait_locks 
	+ 0.7746 * parameters.mean_wait_of_all 
	+ 230922484.4877 * parameters.cpu_usage 
	- 0.0645 * parameters.avg_work_of_same_past_second 
	+ 0.349 * parameters.avg_wait_of_same_past_second 
	+ 0.0065 * parameters.avg_latency_of_same_last_20 
	- 0.0031 * parameters.max_latency_of_same_last_50 
	- 281583033.871;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM185(work_wait &parameters) {
  double actual_remaining = 
	0.0761 * parameters.work_so_far 
	+ 0.0733 * parameters.wait_so_far 
	- 289325.7105 * parameters.total_wait_locks 
	+ 0.7746 * parameters.mean_wait_of_all 
	+ 406588601.6599 * parameters.cpu_usage 
	+ 0.5606 * parameters.avg_work_of_same_past_second 
	+ 0.4513 * parameters.avg_wait_of_same_past_second 
	+ 0.0065 * parameters.avg_latency_of_same_last_20 
	- 0.0031 * parameters.max_latency_of_same_last_50 
	- 512196993.8593;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM186(work_wait &parameters) {
  double actual_remaining = 
	0.0761 * parameters.work_so_far 
	+ 0.0842 * parameters.wait_so_far 
	- 289325.7105 * parameters.total_wait_locks 
	+ 0.7746 * parameters.mean_wait_of_all 
	+ 433959437.8808 * parameters.cpu_usage 
	+ 0.5606 * parameters.avg_work_of_same_past_second 
	+ 0.4513 * parameters.avg_wait_of_same_past_second 
	+ 0.0065 * parameters.avg_latency_of_same_last_20 
	- 0.0031 * parameters.max_latency_of_same_last_50 
	- 537063926.2851;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM187(work_wait &parameters) {
  double actual_remaining = 
	0.1988 * parameters.work_so_far 
	- 0.0103 * parameters.wait_so_far 
	- 181793.6845 * parameters.total_wait_locks 
	+ 0.5127 * parameters.mean_wait_of_all 
	- 9030280.9538 * parameters.cpu_usage 
	- 0.2457 * parameters.avg_work_of_same_past_second 
	+ 0.0522 * parameters.avg_wait_of_same_past_second 
	- 0.1236 * parameters.avg_latency_of_same_last_20 
	- 0.0031 * parameters.max_latency_of_same_last_50 
	+ 92811906.6621;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM188(work_wait &parameters) {
  double actual_remaining = 
	-4.8056 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 205243.1579 * parameters.total_wait_locks 
	+ 1.1006 * parameters.mean_wait_of_all 
	- 9030280.9538 * parameters.cpu_usage 
	+ 0.4689 * parameters.avg_work_of_same_past_second 
	+ 0.3352 * parameters.avg_wait_of_same_past_second 
	- 0.022 * parameters.avg_latency_of_same_last_20 
	+ 0.0053 * parameters.max_latency_of_same_last_50 
	- 340384018.3942;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM189(work_wait &parameters) {
  double actual_remaining = 
	-2.5124 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 126133.069 * parameters.total_wait_locks 
	+ 1.1006 * parameters.mean_wait_of_all 
	- 9030280.9538 * parameters.cpu_usage 
	+ 0.4689 * parameters.avg_work_of_same_past_second 
	+ 0.2645 * parameters.avg_wait_of_same_past_second 
	- 0.0111 * parameters.avg_latency_of_same_last_20 
	+ 0.0124 * parameters.max_latency_of_same_last_50 
	- 285232194.5597;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM190(work_wait &parameters) {
  double actual_remaining = 
	-2.5124 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 16154.05 * parameters.total_wait_locks 
	+ 1.1006 * parameters.mean_wait_of_all 
	- 9030280.9538 * parameters.cpu_usage 
	+ 0.4689 * parameters.avg_work_of_same_past_second 
	+ 0.3149 * parameters.avg_wait_of_same_past_second 
	- 0.0111 * parameters.avg_latency_of_same_last_20 
	+ 0.0065 * parameters.max_latency_of_same_last_50 
	- 229465104.0718;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM191(work_wait &parameters) {
  double actual_remaining = 
	0.4648 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 181793.6845 * parameters.total_wait_locks 
	+ 0.8486 * parameters.mean_wait_of_all 
	- 9030280.9538 * parameters.cpu_usage 
	+ 0.1627 * parameters.avg_work_of_same_past_second 
	+ 0.0522 * parameters.avg_wait_of_same_past_second 
	+ 0.0103 * parameters.avg_latency_of_same_last_20 
	+ 0.0115 * parameters.max_latency_of_same_last_50 
	- 16344948.0741;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM192(work_wait &parameters) {
  double actual_remaining = 
	0.2679 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 403245.912 * parameters.total_wait_locks 
	- 2.203 * parameters.mean_wait_of_all 
	- 9030280.9538 * parameters.cpu_usage 
	- 4.9485 * parameters.avg_work_of_same_past_second 
	+ 0.0522 * parameters.avg_wait_of_same_past_second 
	+ 0.0103 * parameters.avg_latency_of_same_last_20 
	- 0.0031 * parameters.max_latency_of_same_last_50 
	+ 262913534.2853;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM193(work_wait &parameters) {
  double actual_remaining = 
	0.2679 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 292828.4877 * parameters.total_wait_locks 
	- 1.941 * parameters.mean_wait_of_all 
	- 9030280.9538 * parameters.cpu_usage 
	- 4.9485 * parameters.avg_work_of_same_past_second 
	+ 0.0522 * parameters.avg_wait_of_same_past_second 
	+ 0.0103 * parameters.avg_latency_of_same_last_20 
	- 0.0031 * parameters.max_latency_of_same_last_50 
	+ 282199762.9566;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM194(work_wait &parameters) {
  double actual_remaining = 
	0.3947 * parameters.work_so_far 
	- 0.0009 * parameters.wait_so_far 
	+ 262916.5285 * parameters.total_wait_locks 
	- 1.7488 * parameters.mean_wait_of_all 
	- 9030280.9538 * parameters.cpu_usage 
	- 5.6662 * parameters.avg_work_of_same_past_second 
	+ 0.0522 * parameters.avg_wait_of_same_past_second 
	+ 0.0103 * parameters.avg_latency_of_same_last_20 
	- 0.0031 * parameters.max_latency_of_same_last_50 
	+ 287294212.3714;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM195(work_wait &parameters) {
  double actual_remaining = 
	2.194 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 262916.5285 * parameters.total_wait_locks 
	- 1.7488 * parameters.mean_wait_of_all 
	- 9030280.9538 * parameters.cpu_usage 
	- 5.8707 * parameters.avg_work_of_same_past_second 
	+ 0.0522 * parameters.avg_wait_of_same_past_second 
	+ 0.0103 * parameters.avg_latency_of_same_last_20 
	- 0.0031 * parameters.max_latency_of_same_last_50 
	+ 290576014.0364;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM196(work_wait &parameters) {
  double actual_remaining = 
	0.2679 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 275145.3268 * parameters.total_wait_locks 
	- 1.627 * parameters.mean_wait_of_all 
	- 9030280.9538 * parameters.cpu_usage 
	- 4.9833 * parameters.avg_work_of_same_past_second 
	+ 0.0522 * parameters.avg_wait_of_same_past_second 
	+ 0.0103 * parameters.avg_latency_of_same_last_20 
	- 0.0031 * parameters.max_latency_of_same_last_50 
	+ 244200128.385;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM197(work_wait &parameters) {
  double actual_remaining = 
	0.1504 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 181793.6845 * parameters.total_wait_locks 
	+ 0.6167 * parameters.mean_wait_of_all 
	- 25592779.0368 * parameters.cpu_usage 
	- 0.2457 * parameters.avg_work_of_same_past_second 
	+ 0.0522 * parameters.avg_wait_of_same_past_second 
	+ 0.0112 * parameters.avg_latency_of_same_last_20 
	- 0.0031 * parameters.max_latency_of_same_last_50 
	+ 46871001.539;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM198(work_wait &parameters) {
  double actual_remaining = 
	8.2057 * parameters.work_so_far 
	- 0.0071 * parameters.wait_so_far 
	- 837058.1988 * parameters.total_wait_locks 
	+ 2.5906 * parameters.mean_wait_of_all 
	- 7482772.5153 * parameters.cpu_usage 
	- 3.4955 * parameters.avg_work_of_same_past_second 
	- 0.5065 * parameters.avg_wait_of_same_past_second 
	+ 0.0818 * parameters.avg_latency_of_same_last_20 
	- 0.0031 * parameters.max_latency_of_same_last_50 
	+ 441342609.7708;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM199(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0082 * parameters.wait_so_far 
	- 693697.7238 * parameters.total_wait_locks 
	+ 2.5906 * parameters.mean_wait_of_all 
	- 7482772.5153 * parameters.cpu_usage 
	- 3.4955 * parameters.avg_work_of_same_past_second 
	- 0.5065 * parameters.avg_wait_of_same_past_second 
	+ 0.0818 * parameters.avg_latency_of_same_last_20 
	- 0.0031 * parameters.max_latency_of_same_last_50 
	+ 372066172.7608;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM200(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0268 * parameters.wait_so_far 
	- 1450062.8799 * parameters.total_wait_locks 
	+ 1.8095 * parameters.mean_wait_of_all 
	- 7482772.5153 * parameters.cpu_usage 
	- 2.1337 * parameters.avg_work_of_same_past_second 
	- 1.1872 * parameters.avg_wait_of_same_past_second 
	+ 0.0512 * parameters.avg_latency_of_same_last_20 
	- 0.0031 * parameters.max_latency_of_same_last_50 
	+ 1205550463.3998;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM201(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0268 * parameters.wait_so_far 
	- 1465084.1297 * parameters.total_wait_locks 
	+ 1.8095 * parameters.mean_wait_of_all 
	- 7482772.5153 * parameters.cpu_usage 
	- 2.1337 * parameters.avg_work_of_same_past_second 
	- 1.1872 * parameters.avg_wait_of_same_past_second 
	+ 0.0512 * parameters.avg_latency_of_same_last_20 
	- 0.0031 * parameters.max_latency_of_same_last_50 
	+ 1212318481.2289;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM202(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0426 * parameters.wait_so_far 
	- 1806241.1353 * parameters.total_wait_locks 
	+ 3.2444 * parameters.mean_wait_of_all 
	- 7482772.5153 * parameters.cpu_usage 
	- 0.0398 * parameters.avg_work_of_same_past_second 
	- 0.1169 * parameters.avg_wait_of_same_past_second 
	+ 0.0512 * parameters.avg_latency_of_same_last_20 
	- 0.0031 * parameters.max_latency_of_same_last_50 
	+ 650824872.8497;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM203(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0282 * parameters.wait_so_far 
	- 996957.3126 * parameters.total_wait_locks 
	- 0.0463 * parameters.mean_wait_of_all 
	- 7482772.5153 * parameters.cpu_usage 
	- 0.4255 * parameters.avg_work_of_same_past_second 
	- 1.3455 * parameters.avg_wait_of_same_past_second 
	+ 0.0512 * parameters.avg_latency_of_same_last_20 
	- 0.0031 * parameters.max_latency_of_same_last_50 
	+ 1189914475.4571;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM204(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 368898.2341 * parameters.total_wait_locks 
	+ 0.7743 * parameters.mean_wait_of_all 
	- 51734137.6887 * parameters.cpu_usage 
	- 0.4514 * parameters.avg_work_of_same_past_second 
	+ 0.0259 * parameters.avg_wait_of_same_past_second 
	+ 0.0339 * parameters.avg_latency_of_same_last_20 
	- 0.0038 * parameters.max_latency_of_same_last_50 
	+ 144948819.4314;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM205(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0017 * parameters.wait_so_far 
	- 65008.8451 * parameters.total_wait_locks 
	- 0.3776 * parameters.mean_wait_of_all 
	+ 97602223.3858 * parameters.cpu_usage 
	- 1.2545 * parameters.avg_work_of_same_past_second 
	+ 0.1804 * parameters.avg_wait_of_same_past_second 
	+ 0.0188 * parameters.avg_latency_of_same_last_20 
	- 0.0077 * parameters.max_latency_of_same_last_50 
	- 58803964.8465;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM206(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0027 * parameters.wait_so_far 
	- 65008.8451 * parameters.total_wait_locks 
	- 0.3776 * parameters.mean_wait_of_all 
	+ 97602223.3858 * parameters.cpu_usage 
	- 1.2545 * parameters.avg_work_of_same_past_second 
	+ 0.2197 * parameters.avg_wait_of_same_past_second 
	+ 0.0188 * parameters.avg_latency_of_same_last_20 
	- 0.009 * parameters.max_latency_of_same_last_50 
	- 79088413.4798;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM207(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 65008.8451 * parameters.total_wait_locks 
	- 0.7948 * parameters.mean_wait_of_all 
	+ 97602223.3858 * parameters.cpu_usage 
	- 1.03 * parameters.avg_work_of_same_past_second 
	+ 0.0816 * parameters.avg_wait_of_same_past_second 
	+ 0.0317 * parameters.avg_latency_of_same_last_20 
	- 0.0054 * parameters.max_latency_of_same_last_50 
	+ 38126881.7304;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM208(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 65008.8451 * parameters.total_wait_locks 
	- 0.7948 * parameters.mean_wait_of_all 
	+ 97602223.3858 * parameters.cpu_usage 
	- 1.03 * parameters.avg_work_of_same_past_second 
	+ 0.0816 * parameters.avg_wait_of_same_past_second 
	+ 0.0317 * parameters.avg_latency_of_same_last_20 
	- 0.0054 * parameters.max_latency_of_same_last_50 
	+ 39120733.038;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM209(work_wait &parameters) {
  double actual_remaining = 
	12.0379 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 65008.8451 * parameters.total_wait_locks 
	+ 10.6273 * parameters.mean_wait_of_all 
	+ 97602223.3858 * parameters.cpu_usage 
	- 1.03 * parameters.avg_work_of_same_past_second 
	+ 0.0816 * parameters.avg_wait_of_same_past_second 
	+ 0.0317 * parameters.avg_latency_of_same_last_20 
	- 0.0054 * parameters.max_latency_of_same_last_50 
	- 1263773625.5073;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM210(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 100530.7928 * parameters.total_wait_locks 
	- 0.5372 * parameters.mean_wait_of_all 
	+ 97602223.3858 * parameters.cpu_usage 
	- 1.33 * parameters.avg_work_of_same_past_second 
	+ 0.0816 * parameters.avg_wait_of_same_past_second 
	+ 0.0314 * parameters.avg_latency_of_same_last_20 
	- 0.0054 * parameters.max_latency_of_same_last_50 
	+ 25526989.8369;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM211(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 555257.5441 * parameters.total_wait_locks 
	- 0.4131 * parameters.mean_wait_of_all 
	+ 97602223.3858 * parameters.cpu_usage 
	- 0.3284 * parameters.avg_work_of_same_past_second 
	+ 0.0816 * parameters.avg_wait_of_same_past_second 
	+ 0.0314 * parameters.avg_latency_of_same_last_20 
	- 0.0054 * parameters.max_latency_of_same_last_50 
	+ 197594578.3518;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM212(work_wait &parameters) {
  double actual_remaining = 
	-2.1164 * parameters.work_so_far 
	- 0.0023 * parameters.wait_so_far 
	+ 103624.9591 * parameters.total_wait_locks 
	+ 0.6208 * parameters.mean_wait_of_all 
	+ 542234886.7694 * parameters.cpu_usage 
	- 5.2191 * parameters.avg_work_of_same_past_second 
	+ 0.124 * parameters.avg_wait_of_same_past_second 
	+ 0.075 * parameters.avg_latency_of_same_last_20 
	- 0.0148 * parameters.max_latency_of_same_last_50 
	- 501220218.8358;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM213(work_wait &parameters) {
  double actual_remaining = 
	-2.1164 * parameters.work_so_far 
	- 0.0023 * parameters.wait_so_far 
	+ 248140.6428 * parameters.total_wait_locks 
	+ 0.6208 * parameters.mean_wait_of_all 
	+ 542234886.7694 * parameters.cpu_usage 
	- 5.2191 * parameters.avg_work_of_same_past_second 
	+ 0.124 * parameters.avg_wait_of_same_past_second 
	+ 0.0745 * parameters.avg_latency_of_same_last_20 
	- 0.0148 * parameters.max_latency_of_same_last_50 
	- 567565746.3624;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM214(work_wait &parameters) {
  double actual_remaining = 
	-1.1393 * parameters.work_so_far 
	- 0.0023 * parameters.wait_so_far 
	+ 103624.9591 * parameters.total_wait_locks 
	+ 0.6208 * parameters.mean_wait_of_all 
	+ 542234886.7694 * parameters.cpu_usage 
	- 2.5471 * parameters.avg_work_of_same_past_second 
	+ 0.124 * parameters.avg_wait_of_same_past_second 
	+ 0.0552 * parameters.avg_latency_of_same_last_20 
	- 0.0148 * parameters.max_latency_of_same_last_50 
	- 585324728.6567;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM215(work_wait &parameters) {
  double actual_remaining = 
	-527.3723 * parameters.work_so_far 
	- 0.0041 * parameters.wait_so_far 
	+ 917895.2705 * parameters.total_wait_locks 
	+ 0.1615 * parameters.mean_wait_of_all 
	+ 888935676.999 * parameters.cpu_usage 
	- 3.4701 * parameters.avg_work_of_same_past_second 
	+ 0.2118 * parameters.avg_wait_of_same_past_second 
	+ 0.0646 * parameters.avg_latency_of_same_last_20 
	- 0.022 * parameters.max_latency_of_same_last_50 
	- 1172588598.2408;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM216(work_wait &parameters) {
  double actual_remaining = 
	5.4467 * parameters.work_so_far 
	- 0.0041 * parameters.wait_so_far 
	+ 1126914.6635 * parameters.total_wait_locks 
	+ 0.383 * parameters.mean_wait_of_all 
	+ 888935676.999 * parameters.cpu_usage 
	- 3.4701 * parameters.avg_work_of_same_past_second 
	+ 0.2118 * parameters.avg_wait_of_same_past_second 
	+ 0.0646 * parameters.avg_latency_of_same_last_20 
	- 0.022 * parameters.max_latency_of_same_last_50 
	- 1330097786.2452;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM217(work_wait &parameters) {
  double actual_remaining = 
	0.1403 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	- 178836.0859 * parameters.total_wait_locks 
	+ 0.6345 * parameters.mean_wait_of_all 
	+ 60010081.3931 * parameters.cpu_usage 
	- 0.37 * parameters.avg_work_of_same_past_second 
	- 0.0417 * parameters.avg_wait_of_same_past_second 
	+ 0.0252 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 1400169.2935;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM218(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0054 * parameters.wait_so_far 
	- 18177.923 * parameters.total_wait_locks 
	+ 0.401 * parameters.mean_wait_of_all 
	- 71400573.7072 * parameters.cpu_usage 
	- 0.0091 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.3509 * parameters.avg_latency_of_same_last_20 
	- 0.0563 * parameters.max_latency_of_same_last_50 
	+ 3298472.5839;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM219(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0023 * parameters.wait_so_far 
	- 18177.923 * parameters.total_wait_locks 
	+ 0.9056 * parameters.mean_wait_of_all 
	- 25942430.1706 * parameters.cpu_usage 
	- 0.0091 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0068 * parameters.avg_latency_of_same_last_20 
	+ 0.0111 * parameters.max_latency_of_same_last_50 
	- 62498374.1528;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM220(work_wait &parameters) {
  double actual_remaining = 
	0.7542 * parameters.work_so_far 
	- 0.1839 * parameters.wait_so_far 
	- 165852.1254 * parameters.total_wait_locks 
	+ 0.8938 * parameters.mean_wait_of_all 
	- 1255300.4179 * parameters.cpu_usage 
	- 0.0021 * parameters.avg_work_of_same_past_second 
	+ 0.001 * parameters.avg_wait_of_same_past_second 
	+ 0.001 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 6121614.9313;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM221(work_wait &parameters) {
  double actual_remaining = 
	0.0106 * parameters.work_so_far 
	- 0.0005 * parameters.wait_so_far 
	- 10681.0147 * parameters.total_wait_locks 
	+ 0.0558 * parameters.mean_wait_of_all 
	- 1255300.4179 * parameters.cpu_usage 
	- 0.0021 * parameters.avg_work_of_same_past_second 
	+ 0.001 * parameters.avg_wait_of_same_past_second 
	+ 0.001 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 17120413.9845;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM222(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0144 * parameters.wait_so_far 
	- 27421.434 * parameters.total_wait_locks 
	+ 0.1648 * parameters.mean_wait_of_all 
	- 79710179.9827 * parameters.cpu_usage 
	- 0.0021 * parameters.avg_work_of_same_past_second 
	- 0.0947 * parameters.avg_wait_of_same_past_second 
	+ 0.0295 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 123587603.0814;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM223(work_wait &parameters) {
  double actual_remaining = 
	0.8818 * parameters.work_so_far 
	- 0.0008 * parameters.wait_so_far 
	- 72092.7715 * parameters.total_wait_locks 
	+ 0.3139 * parameters.mean_wait_of_all 
	- 844887.5339 * parameters.cpu_usage 
	- 0.0099 * parameters.avg_work_of_same_past_second 
	- 0.2115 * parameters.avg_wait_of_same_past_second 
	+ 0.0021 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 108110170.6466;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM224(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0008 * parameters.wait_so_far 
	- 1470885.2851 * parameters.total_wait_locks 
	+ 7.6048 * parameters.mean_wait_of_all 
	- 844887.5339 * parameters.cpu_usage 
	- 0.0099 * parameters.avg_work_of_same_past_second 
	- 0.2963 * parameters.avg_wait_of_same_past_second 
	+ 0.0021 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	- 38764547.3768;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM225(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0212 * parameters.wait_so_far 
	+ 499349.9359 * parameters.total_wait_locks 
	- 3.9953 * parameters.mean_wait_of_all 
	- 11749522.4445 * parameters.cpu_usage 
	- 1.3029 * parameters.avg_work_of_same_past_second 
	+ 0.0005 * parameters.avg_wait_of_same_past_second 
	+ 0.0056 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 375354009.5924;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM226(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0013 * parameters.wait_so_far 
	- 35517.3258 * parameters.total_wait_locks 
	+ 0.1575 * parameters.mean_wait_of_all 
	- 5421650.3613 * parameters.cpu_usage 
	- 0.0214 * parameters.avg_work_of_same_past_second 
	+ 0.0005 * parameters.avg_wait_of_same_past_second 
	+ 0.029 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 16937361.8952;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM227(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	- 288336.8068 * parameters.total_wait_locks 
	+ 2.9916 * parameters.mean_wait_of_all 
	- 115807554.4839 * parameters.cpu_usage 
	- 1.7723 * parameters.avg_work_of_same_past_second 
	+ 0.0005 * parameters.avg_wait_of_same_past_second 
	+ 0.0292 * parameters.avg_latency_of_same_last_20 
	- 0.0069 * parameters.max_latency_of_same_last_50 
	- 91721236.7113;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
payment_estimate(work_wait &parameters){

  if (parameters.total_wait_locks <= 66.5) {

    if (parameters.work_so_far <= 7418) {
      return payment_LM1(parameters);
    } else {
      return payment_LM2(parameters);
    }
  } else {

    if (parameters.cpu_usage <= 0.882) {

      if (parameters.cpu_usage <= 0.824) {

        if (parameters.mean_wait_of_all <= 102074000) {

          if (parameters.max_latency_of_same_last_50 <= 691828000) {

            if (parameters.cpu_usage <= 0.799) {

              if (parameters.max_latency_of_same_last_50 <= 638040000) {
                return payment_LM3(parameters);
              } else {

                if (parameters.total_wait_locks <= 95.5) {
                  return payment_LM4(parameters);
                } else {

                  if (parameters.avg_latency_of_same_last_20 <= 197192000) {
                    return payment_LM5(parameters);
                  } else {
                    return payment_LM6(parameters);
                  }
                }
              }
            } else {

              if (parameters.total_wait_locks <= 78.5) {

                if (parameters.max_latency_of_same_last_50 <= 623618000) {
                  return payment_LM7(parameters);
                } else {
                  return payment_LM8(parameters);
                }
              } else {

                if (parameters.max_latency_of_same_last_50 <= 495343000) {

                  if (parameters.avg_wait_of_same_past_second <= 17656200) {
                    return payment_LM9(parameters);
                  } else {
                    return payment_LM10(parameters);
                  }
                } else {
                  return payment_LM11(parameters);
                }
              }
            }
          } else {

            if (parameters.avg_latency_of_same_last_20 <= 392797000) {
              return payment_LM12(parameters);
            } else {

              if (parameters.cpu_usage <= 0.792) {

                if (parameters.avg_wait_of_same_past_second <= 365507500) {
                  return payment_LM13(parameters);
                } else {
                  return payment_LM14(parameters);
                }
              } else {

                if (parameters.work_so_far <= 34767.5) {

                  if (parameters.max_latency_of_same_last_50 <= 1392750000) {

                    if (parameters.total_wait_locks <= 220.5) {
                      return payment_LM15(parameters);
                    } else {

                      if (parameters.wait_so_far <= 94988952.5) {
                        return payment_LM16(parameters);
                      } else {

                        if (parameters.avg_latency_of_same_last_20 <= 546909500) {
                          return payment_LM17(parameters);
                        } else {
                          return payment_LM18(parameters);
                        }
                      }
                    }
                  } else {
                    return payment_LM19(parameters);
                  }
                } else {
                  return payment_LM20(parameters);
                }
              }
            }
          }
        } else {

          if (parameters.avg_work_of_same_past_second <= 28065250) {

            if (parameters.cpu_usage <= 0.793) {
              return payment_LM21(parameters);
            } else {

              if (parameters.avg_wait_of_same_past_second <= 443415500) {
                return payment_LM22(parameters);
              } else {
                return payment_LM23(parameters);
              }
            }
          } else {
            return payment_LM24(parameters);
          }
        }
      } else {

        if (parameters.avg_wait_of_same_past_second <= 352163500) {

          if (parameters.mean_wait_of_all <= 28919950) {

            if (parameters.wait_so_far <= 297669790) {

              if (parameters.total_wait_locks <= 130) {

                if (parameters.mean_wait_of_all <= 22658850) {
                  return payment_LM25(parameters);
                } else {
                  return payment_LM26(parameters);
                }
              } else {

                if (parameters.mean_wait_of_all <= 22341000) {
                  return payment_LM27(parameters);
                } else {

                  if (parameters.avg_wait_of_same_past_second <= 102862500) {
                    return payment_LM28(parameters);
                  } else {
                    return payment_LM29(parameters);
                  }
                }
              }
            } else {

              if (parameters.wait_so_far <= 403372299.5) {

                if (parameters.wait_so_far <= 368138848) {

                  if (parameters.mean_wait_of_all <= 22642000) {

                    if (parameters.mean_wait_of_all <= 22373500) {
                      return payment_LM30(parameters);
                    } else {
                      return payment_LM31(parameters);
                    }
                  } else {
                    return payment_LM32(parameters);
                  }
                } else {

                  if (parameters.mean_wait_of_all <= 24413300) {
                    return payment_LM33(parameters);
                  } else {
                    return payment_LM34(parameters);
                  }
                }
              } else {
                return payment_LM35(parameters);
              }
            }
          } else {

            if (parameters.avg_work_of_same_past_second <= 23743400) {

              if (parameters.avg_latency_of_same_last_20 <= 203525000) {

                if (parameters.avg_wait_of_same_past_second <= 142295000) {

                  if (parameters.avg_work_of_same_past_second <= 10959550) {

                    if (parameters.mean_wait_of_all <= 38198450) {
                      return payment_LM36(parameters);
                    } else {

                      if (parameters.avg_work_of_same_past_second <= 9043210) {
                        return payment_LM37(parameters);
                      } else {

                        if (parameters.mean_wait_of_all <= 54584600) {

                          if (parameters.total_wait_locks <= 110) {
                            return payment_LM38(parameters);
                          } else {
                            return payment_LM39(parameters);
                          }
                        } else {
                          return payment_LM40(parameters);
                        }
                      }
                    }
                  } else {
                    return payment_LM41(parameters);
                  }
                } else {

                  if (parameters.mean_wait_of_all <= 31387900) {
                    return payment_LM42(parameters);
                  } else {
                    return payment_LM43(parameters);
                  }
                }
              } else {

                if (parameters.max_latency_of_same_last_50 <= 1017285000) {

                  if (parameters.work_so_far <= 34604.5) {
                    return payment_LM44(parameters);
                  } else {
                    return payment_LM45(parameters);
                  }
                } else {
                  return payment_LM46(parameters);
                }
              }
            } else {

              if (parameters.max_latency_of_same_last_50 <= 1235800000) {

                if (parameters.max_latency_of_same_last_50 <= 1129185000) {

                  if (parameters.total_wait_locks <= 268.5) {
                    return payment_LM47(parameters);
                  } else {

                    if (parameters.mean_wait_of_all <= 98807800) {
                      return payment_LM48(parameters);
                    } else {
                      return payment_LM49(parameters);
                    }
                  }
                } else {

                  if (parameters.max_latency_of_same_last_50 <= 1203265000) {
                    return payment_LM50(parameters);
                  } else {

                    if (parameters.avg_work_of_same_past_second <= 30241850) {

                      if (parameters.avg_latency_of_same_last_20 <= 543688500) {
                        return payment_LM51(parameters);
                      } else {
                        return payment_LM52(parameters);
                      }
                    } else {

                      if (parameters.total_wait_locks <= 251) {

                        if (parameters.total_wait_locks <= 191) {
                          return payment_LM53(parameters);
                        } else {
                          return payment_LM54(parameters);
                        }
                      } else {
                        return payment_LM55(parameters);
                      }
                    }
                  }
                }
              } else {

                if (parameters.avg_wait_of_same_past_second <= 303766500) {
                  return payment_LM56(parameters);
                } else {

                  if (parameters.max_latency_of_same_last_50 <= 1456610000) {

                    if (parameters.max_latency_of_same_last_50 <= 1423545000) {
                      return payment_LM57(parameters);
                    } else {

                      if (parameters.total_wait_locks <= 332.5) {
                        return payment_LM58(parameters);
                      } else {

                        if (parameters.work_so_far <= 44605) {
                          return payment_LM59(parameters);
                        } else {
                          return payment_LM60(parameters);
                        }
                      }
                    }
                  } else {
                    return payment_LM61(parameters);
                  }
                }
              }
            }
          }
        } else {

          if (parameters.avg_work_of_same_past_second <= 28420000) {

            if (parameters.avg_work_of_same_past_second <= 25796850) {

              if (parameters.max_latency_of_same_last_50 <= 1293385000) {

                if (parameters.total_wait_locks <= 363.5) {

                  if (parameters.avg_work_of_same_past_second <= 20012050) {

                    if (parameters.total_wait_locks <= 333.5) {
                      return payment_LM62(parameters);
                    } else {
                      return payment_LM63(parameters);
                    }
                  } else {
                    return payment_LM64(parameters);
                  }
                } else {

                  if (parameters.work_so_far <= 37813.5) {
                    return payment_LM65(parameters);
                  } else {

                    if (parameters.avg_wait_of_same_past_second <= 414972500) {

                      if (parameters.avg_latency_of_same_last_20 <= 516728500) {
                        return payment_LM66(parameters);
                      } else {

                        if (parameters.wait_so_far <= 268980064.5) {
                          return payment_LM67(parameters);
                        } else {
                          return payment_LM68(parameters);
                        }
                      }
                    } else {

                      if (parameters.avg_work_of_same_past_second <= 23275650) {
                        return payment_LM69(parameters);
                      } else {
                        return payment_LM70(parameters);
                      }
                    }
                  }
                }
              } else {
                return payment_LM71(parameters);
              }
            } else {

              if (parameters.max_latency_of_same_last_50 <= 1354835000) {

                if (parameters.avg_wait_of_same_past_second <= 390892500) {
                  return payment_LM72(parameters);
                } else {
                  return payment_LM73(parameters);
                }
              } else {
                return payment_LM74(parameters);
              }
            }
          } else {

            if (parameters.avg_work_of_same_past_second <= 32729200) {
              return payment_LM75(parameters);
            } else {

              if (parameters.avg_work_of_same_past_second <= 50622450) {

                if (parameters.total_wait_locks <= 508.5) {

                  if (parameters.avg_work_of_same_past_second <= 44669850) {

                    if (parameters.avg_work_of_same_past_second <= 39030400) {

                      if (parameters.avg_latency_of_same_last_20 <= 657578000) {

                        if (parameters.avg_wait_of_same_past_second <= 494121000) {

                          if (parameters.cpu_usage <= 0.871) {
                            return payment_LM76(parameters);
                          } else {

                            if (parameters.max_latency_of_same_last_50 <= 1558135000) {

                              if (parameters.total_wait_locks <= 269) {
                                return payment_LM77(parameters);
                              } else {

                                if (parameters.avg_latency_of_same_last_20 <= 452112500) {

                                  if (parameters.wait_so_far <= 93088405) {
                                    return payment_LM78(parameters);
                                  } else {

                                    if (parameters.total_wait_locks <= 284.5) {

                                      if (parameters.max_latency_of_same_last_50 <= 1302930000) {
                                        return payment_LM79(parameters);
                                      } else {
                                        return payment_LM80(parameters);
                                      }
                                    } else {
                                      return payment_LM81(parameters);
                                    }
                                  }
                                } else {

                                  if (parameters.total_wait_locks <= 499.5) {
                                    return payment_LM82(parameters);
                                  } else {
                                    return payment_LM83(parameters);
                                  }
                                }
                              }
                            } else {

                              if (parameters.mean_wait_of_all <= 124864000) {
                                return payment_LM84(parameters);
                              } else {

                                if (parameters.avg_work_of_same_past_second <= 33676250) {
                                  return payment_LM85(parameters);
                                } else {
                                  return payment_LM86(parameters);
                                }
                              }
                            }
                          }
                        } else {

                          if (parameters.max_latency_of_same_last_50 <= 2084400000) {

                            if (parameters.avg_work_of_same_past_second <= 36543050) {

                              if (parameters.total_wait_locks <= 399) {

                                if (parameters.wait_so_far <= 143139996.5) {
                                  return payment_LM87(parameters);
                                } else {
                                  return payment_LM88(parameters);
                                }
                              } else {
                                return payment_LM89(parameters);
                              }
                            } else {

                              if (parameters.mean_wait_of_all <= 117555500) {
                                return payment_LM90(parameters);
                              } else {
                                return payment_LM91(parameters);
                              }
                            }
                          } else {
                            return payment_LM92(parameters);
                          }
                        }
                      } else {

                        if (parameters.avg_work_of_same_past_second <= 34667800) {
                          return payment_LM93(parameters);
                        } else {
                          return payment_LM94(parameters);
                        }
                      }
                    } else {

                      if (parameters.avg_wait_of_same_past_second <= 442255500) {
                        return payment_LM95(parameters);
                      } else {
                        return payment_LM96(parameters);
                      }
                    }
                  } else {

                    if (parameters.avg_work_of_same_past_second <= 49874450) {

                      if (parameters.total_wait_locks <= 412.5) {

                        if (parameters.avg_work_of_same_past_second <= 44850850) {
                          return payment_LM97(parameters);
                        } else {
                          return payment_LM98(parameters);
                        }
                      } else {
                        return payment_LM99(parameters);
                      }
                    } else {

                      if (parameters.cpu_usage <= 0.844) {

                        if (parameters.wait_so_far <= 588258864) {
                          return payment_LM100(parameters);
                        } else {
                          return payment_LM101(parameters);
                        }
                      } else {

                        if (parameters.avg_latency_of_same_last_20 <= 851593500) {

                          if (parameters.avg_latency_of_same_last_20 <= 418513500) {
                            return payment_LM102(parameters);
                          } else {

                            if (parameters.mean_wait_of_all <= 126213500) {
                              return payment_LM103(parameters);
                            } else {
                              return payment_LM104(parameters);
                            }
                          }
                        } else {
                          return payment_LM105(parameters);
                        }
                      }
                    }
                  }
                } else {

                  if (parameters.avg_wait_of_same_past_second <= 468554000) {
                    return payment_LM106(parameters);
                  } else {

                    if (parameters.avg_latency_of_same_last_20 <= 680373500) {

                      if (parameters.cpu_usage <= 0.871) {

                        if (parameters.avg_latency_of_same_last_20 <= 402839500) {
                          return payment_LM107(parameters);
                        } else {
                          return payment_LM108(parameters);
                        }
                      } else {
                        return payment_LM109(parameters);
                      }
                    } else {
                      return payment_LM110(parameters);
                    }
                  }
                }
              } else {

                if (parameters.avg_latency_of_same_last_20 <= 610884500) {
                  return payment_LM111(parameters);
                } else {

                  if (parameters.max_latency_of_same_last_50 <= 1298360000) {

                    if (parameters.mean_wait_of_all <= 75789200) {
                      return payment_LM112(parameters);
                    } else {
                      return payment_LM113(parameters);
                    }
                  } else {

                    if (parameters.avg_latency_of_same_last_20 <= 718859000) {
                      return payment_LM114(parameters);
                    } else {

                      if (parameters.wait_so_far <= 344561232.5) {
                        return payment_LM115(parameters);
                      } else {
                        return payment_LM116(parameters);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    } else {

      if (parameters.mean_wait_of_all <= 97368200) {

        if (parameters.avg_wait_of_same_past_second <= 312564000) {

          if (parameters.max_latency_of_same_last_50 <= 700360000) {

            if (parameters.work_so_far <= 12445.5) {
              return payment_LM117(parameters);
            } else {

              if (parameters.avg_latency_of_same_last_20 <= 144914000) {

                if (parameters.avg_wait_of_same_past_second <= 21456850) {
                  return payment_LM118(parameters);
                } else {
                  return payment_LM119(parameters);
                }
              } else {

                if (parameters.avg_latency_of_same_last_20 <= 261438500) {
                  return payment_LM120(parameters);
                } else {

                  if (parameters.total_wait_locks <= 131.5) {

                    if (parameters.avg_work_of_same_past_second <= 12153650) {
                      return payment_LM121(parameters);
                    } else {
                      return payment_LM122(parameters);
                    }
                  } else {

                    if (parameters.total_wait_locks <= 243) {
                      return payment_LM123(parameters);
                    } else {
                      return payment_LM124(parameters);
                    }
                  }
                }
              }
            }
          } else {

            if (parameters.max_latency_of_same_last_50 <= 1051515000) {

              if (parameters.avg_latency_of_same_last_20 <= 334873500) {

                if (parameters.cpu_usage <= 0.924) {

                  if (parameters.wait_so_far <= 164958835.5) {

                    if (parameters.total_wait_locks <= 193.5) {

                      if (parameters.mean_wait_of_all <= 24967800) {

                        if (parameters.avg_wait_of_same_past_second <= 30982000) {
                          return payment_LM125(parameters);
                        } else {
                          return payment_LM126(parameters);
                        }
                      } else {
                        return payment_LM127(parameters);
                      }
                    } else {
                      return payment_LM128(parameters);
                    }
                  } else {

                    if (parameters.max_latency_of_same_last_50 <= 757619500) {

                      if (parameters.mean_wait_of_all <= 26851750) {
                        return payment_LM129(parameters);
                      } else {
                        return payment_LM130(parameters);
                      }
                    } else {
                      return payment_LM131(parameters);
                    }
                  }
                } else {

                  if (parameters.max_latency_of_same_last_50 <= 900067000) {

                    if (parameters.mean_wait_of_all <= 48445800) {

                      if (parameters.avg_work_of_same_past_second <= 15803050) {

                        if (parameters.mean_wait_of_all <= 27313500) {
                          return payment_LM132(parameters);
                        } else {
                          return payment_LM133(parameters);
                        }
                      } else {
                        return payment_LM134(parameters);
                      }
                    } else {
                      return payment_LM135(parameters);
                    }
                  } else {

                    if (parameters.avg_wait_of_same_past_second <= 212846500) {

                      if (parameters.mean_wait_of_all <= 23599300) {

                        if (parameters.total_wait_locks <= 94.5) {
                          return payment_LM136(parameters);
                        } else {
                          return payment_LM137(parameters);
                        }
                      } else {

                        if (parameters.avg_work_of_same_past_second <= 25133100) {

                          if (parameters.max_latency_of_same_last_50 <= 950231000) {

                            if (parameters.mean_wait_of_all <= 25556300) {
                              return payment_LM138(parameters);
                            } else {
                              return payment_LM139(parameters);
                            }
                          } else {
                            return payment_LM140(parameters);
                          }
                        } else {

                          if (parameters.avg_latency_of_same_last_20 <= 301488000) {
                            return payment_LM141(parameters);
                          } else {

                            if (parameters.total_wait_locks <= 146.5) {
                              return payment_LM142(parameters);
                            } else {

                              if (parameters.total_wait_locks <= 262.5) {

                                if (parameters.total_wait_locks <= 179.5) {
                                  return payment_LM143(parameters);
                                } else {
                                  return payment_LM144(parameters);
                                }
                              } else {
                                return payment_LM145(parameters);
                              }
                            }
                          }
                        }
                      }
                    } else {
                      return payment_LM146(parameters);
                    }
                  }
                }
              } else {

                if (parameters.avg_latency_of_same_last_20 <= 408919000) {
                  return payment_LM147(parameters);
                } else {

                  if (parameters.avg_work_of_same_past_second <= 32135400) {

                    if (parameters.max_latency_of_same_last_50 <= 858271000) {

                      if (parameters.avg_wait_of_same_past_second <= 303797500) {

                        if (parameters.avg_wait_of_same_past_second <= 43638550) {
                          return payment_LM148(parameters);
                        } else {
                          return payment_LM149(parameters);
                        }
                      } else {
                        return payment_LM150(parameters);
                      }
                    } else {

                      if (parameters.max_latency_of_same_last_50 <= 973228000) {
                        return payment_LM151(parameters);
                      } else {
                        return payment_LM152(parameters);
                      }
                    }
                  } else {

                    if (parameters.total_wait_locks <= 202) {

                      if (parameters.work_so_far <= 29699) {
                        return payment_LM153(parameters);
                      } else {
                        return payment_LM154(parameters);
                      }
                    } else {

                      if (parameters.cpu_usage <= 0.901) {

                        if (parameters.wait_so_far <= 272543813) {
                          return payment_LM155(parameters);
                        } else {
                          return payment_LM156(parameters);
                        }
                      } else {
                        return payment_LM157(parameters);
                      }
                    }
                  }
                }
              }
            } else {

              if (parameters.mean_wait_of_all <= 45024550) {

                if (parameters.avg_work_of_same_past_second <= 22697750) {
                  return payment_LM158(parameters);
                } else {
                  return payment_LM159(parameters);
                }
              } else {

                if (parameters.max_latency_of_same_last_50 <= 1256005000) {
                  return payment_LM160(parameters);
                } else {
                  return payment_LM161(parameters);
                }
              }
            }
          }
        } else {

          if (parameters.wait_so_far <= 75047489) {
            return payment_LM162(parameters);
          } else {
            return payment_LM163(parameters);
          }
        }
      } else {

        if (parameters.total_wait_locks <= 521.5) {

          if (parameters.avg_work_of_same_past_second <= 34806450) {

            if (parameters.mean_wait_of_all <= 112283500) {

              if (parameters.total_wait_locks <= 405.5) {

                if (parameters.avg_latency_of_same_last_20 <= 296269500) {
                  return payment_LM164(parameters);
                } else {

                  if (parameters.avg_work_of_same_past_second <= 27731200) {

                    if (parameters.max_latency_of_same_last_50 <= 950901000) {
                      return payment_LM165(parameters);
                    } else {
                      return payment_LM166(parameters);
                    }
                  } else {

                    if (parameters.mean_wait_of_all <= 98064250) {
                      return payment_LM167(parameters);
                    } else {
                      return payment_LM168(parameters);
                    }
                  }
                }
              } else {

                if (parameters.max_latency_of_same_last_50 <= 1202900000) {
                  return payment_LM169(parameters);
                } else {

                  if (parameters.avg_latency_of_same_last_20 <= 578633000) {

                    if (parameters.mean_wait_of_all <= 109998000) {

                      if (parameters.wait_so_far <= 483186145) {

                        if (parameters.mean_wait_of_all <= 104965500) {
                          return payment_LM170(parameters);
                        } else {
                          return payment_LM171(parameters);
                        }
                      } else {
                        return payment_LM172(parameters);
                      }
                    } else {
                      return payment_LM173(parameters);
                    }
                  } else {

                    if (parameters.avg_work_of_same_past_second <= 29152850) {

                      if (parameters.avg_latency_of_same_last_20 <= 661183500) {
                        return payment_LM174(parameters);
                      } else {
                        return payment_LM175(parameters);
                      }
                    } else {
                      return payment_LM176(parameters);
                    }
                  }
                }
              }
            } else {

              if (parameters.avg_wait_of_same_past_second <= 465443000) {

                if (parameters.total_wait_locks <= 469.5) {

                  if (parameters.avg_work_of_same_past_second <= 22573150) {

                    if (parameters.total_wait_locks <= 456.5) {
                      return payment_LM177(parameters);
                    } else {
                      return payment_LM178(parameters);
                    }
                  } else {
                    return payment_LM179(parameters);
                  }
                } else {

                  if (parameters.avg_wait_of_same_past_second <= 433961000) {

                    if (parameters.max_latency_of_same_last_50 <= 968201000) {

                      if (parameters.avg_work_of_same_past_second <= 23276500) {

                        if (parameters.mean_wait_of_all <= 115438500) {
                          return payment_LM180(parameters);
                        } else {

                          if (parameters.wait_so_far <= 619200725.5) {

                            if (parameters.wait_so_far <= 465382309.5) {
                              return payment_LM181(parameters);
                            } else {
                              return payment_LM182(parameters);
                            }
                          } else {
                            return payment_LM183(parameters);
                          }
                        }
                      } else {

                        if (parameters.avg_wait_of_same_past_second <= 369148500) {
                          return payment_LM184(parameters);
                        } else {

                          if (parameters.wait_so_far <= 436929991) {
                            return payment_LM185(parameters);
                          } else {
                            return payment_LM186(parameters);
                          }
                        }
                      }
                    } else {

                      if (parameters.cpu_usage <= 0.962) {

                        if (parameters.avg_latency_of_same_last_20 <= 349329500) {
                          return payment_LM187(parameters);
                        } else {

                          if (parameters.mean_wait_of_all <= 122665500) {

                            if (parameters.avg_wait_of_same_past_second <= 402478500) {
                              return payment_LM188(parameters);
                            } else {

                              if (parameters.avg_latency_of_same_last_20 <= 584515000) {
                                return payment_LM189(parameters);
                              } else {
                                return payment_LM190(parameters);
                              }
                            }
                          } else {

                            if (parameters.avg_work_of_same_past_second <= 25007500) {
                              return payment_LM191(parameters);
                            } else {

                              if (parameters.avg_work_of_same_past_second <= 30162750) {

                                if (parameters.mean_wait_of_all <= 129975000) {

                                  if (parameters.avg_work_of_same_past_second <= 29691900) {
                                    return payment_LM192(parameters);
                                  } else {
                                    return payment_LM193(parameters);
                                  }
                                } else {

                                  if (parameters.avg_work_of_same_past_second <= 25642400) {
                                    return payment_LM194(parameters);
                                  } else {
                                    return payment_LM195(parameters);
                                  }
                                }
                              } else {
                                return payment_LM196(parameters);
                              }
                            }
                          }
                        }
                      } else {
                        return payment_LM197(parameters);
                      }
                    }
                  } else {

                    if (parameters.avg_latency_of_same_last_20 <= 337459000) {

                      if (parameters.wait_so_far <= 305850349) {
                        return payment_LM198(parameters);
                      } else {
                        return payment_LM199(parameters);
                      }
                    } else {

                      if (parameters.avg_wait_of_same_past_second <= 435066500) {

                        if (parameters.total_wait_locks <= 504.5) {
                          return payment_LM200(parameters);
                        } else {
                          return payment_LM201(parameters);
                        }
                      } else {

                        if (parameters.mean_wait_of_all <= 125179500) {
                          return payment_LM202(parameters);
                        } else {
                          return payment_LM203(parameters);
                        }
                      }
                    }
                  }
                }
              } else {

                if (parameters.avg_wait_of_same_past_second <= 497041000) {
                  return payment_LM204(parameters);
                } else {

                  if (parameters.mean_wait_of_all <= 120744000) {

                    if (parameters.avg_wait_of_same_past_second <= 527052000) {

                      if (parameters.max_latency_of_same_last_50 <= 1751265000) {
                        return payment_LM205(parameters);
                      } else {
                        return payment_LM206(parameters);
                      }
                    } else {

                      if (parameters.avg_work_of_same_past_second <= 29848950) {

                        if (parameters.avg_work_of_same_past_second <= 20381700) {

                          if (parameters.wait_so_far <= 258922175.5) {
                            return payment_LM207(parameters);
                          } else {
                            return payment_LM208(parameters);
                          }
                        } else {
                          return payment_LM209(parameters);
                        }
                      } else {

                        if (parameters.avg_work_of_same_past_second <= 33067200) {
                          return payment_LM210(parameters);
                        } else {
                          return payment_LM211(parameters);
                        }
                      }
                    }
                  } else {

                    if (parameters.cpu_usage <= 0.94) {

                      if (parameters.avg_work_of_same_past_second <= 29913000) {

                        if (parameters.avg_latency_of_same_last_20 <= 966643500) {
                          return payment_LM212(parameters);
                        } else {
                          return payment_LM213(parameters);
                        }
                      } else {
                        return payment_LM214(parameters);
                      }
                    } else {

                      if (parameters.work_so_far <= 33284) {
                        return payment_LM215(parameters);
                      } else {
                        return payment_LM216(parameters);
                      }
                    }
                  }
                }
              }
            }
          } else {

            if (parameters.avg_wait_of_same_past_second <= 514091500) {
              return payment_LM217(parameters);
            } else {

              if (parameters.wait_so_far <= 209191944) {
                return payment_LM218(parameters);
              } else {
                return payment_LM219(parameters);
              }
            }
          }
        } else {

          if (parameters.avg_wait_of_same_past_second <= 336143500) {

            if (parameters.wait_so_far <= 80724744.5) {
              return payment_LM220(parameters);
            } else {
              return payment_LM221(parameters);
            }
          } else {

            if (parameters.total_wait_locks <= 623.5) {

              if (parameters.mean_wait_of_all <= 136396500) {
                return payment_LM222(parameters);
              } else {

                if (parameters.max_latency_of_same_last_50 <= 1162935000) {

                  if (parameters.avg_wait_of_same_past_second <= 423688500) {
                    return payment_LM223(parameters);
                  } else {
                    return payment_LM224(parameters);
                  }
                } else {

                  if (parameters.cpu_usage <= 0.911) {
                    return payment_LM225(parameters);
                  } else {
                    return payment_LM226(parameters);
                  }
                }
              }
            } else {
              return payment_LM227(parameters);
            }
          }
        }
      }
    }
  }
}
static
double
delivery_LM1(work_wait &parameters) {
  double actual_remaining = 
	-0.0555 * parameters.wait_so_far 
	- 1007477.7821 * parameters.num_locks_so_far 
	+ 1275700.5445 * parameters.total_wait_locks 
	- 0.0235 * parameters.mean_wait_of_all 
	- 0.1809 * parameters.avg_work_of_same_past_second 
	+ 0.0163 * parameters.avg_latency_of_same_last_20 
	- 0.0007 * parameters.max_latency_of_same_last_50 
	+ 118761696.5394;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM2(work_wait &parameters) {
  double actual_remaining = 
	-0.3171 * parameters.wait_so_far 
	- 5278450.9629 * parameters.num_locks_so_far 
	+ 113567.6211 * parameters.total_wait_locks 
	+ 0.0159 * parameters.mean_wait_of_all 
	- 263993767.624 * parameters.cpu_usage 
	- 0.0011 * parameters.avg_work_of_same_past_second 
	+ 0.3927 * parameters.avg_latency_of_same_last_20 
	- 0.0007 * parameters.max_latency_of_same_last_50 
	+ 604878086.3506;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM3(work_wait &parameters) {
  double actual_remaining = 
	-0.0618 * parameters.wait_so_far 
	- 8097293.3323 * parameters.num_locks_so_far 
	- 2096257.1886 * parameters.total_wait_locks 
	+ 8.9949 * parameters.mean_wait_of_all 
	- 6480143.599 * parameters.cpu_usage 
	- 0.3477 * parameters.avg_work_of_same_past_second 
	- 0.4379 * parameters.avg_wait_of_same_past_second 
	+ 0.5681 * parameters.avg_latency_of_same_last_20 
	- 0.0014 * parameters.max_latency_of_same_last_50 
	+ 567771777.9785;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
delivery_estimate(work_wait &parameters){

  if (parameters.total_wait_locks <= 130.5) {
    return delivery_LM1(parameters);
  } else {

    if (parameters.avg_latency_of_same_last_20 <= 457659500) {
      return delivery_LM2(parameters);
    } else {
      return delivery_LM3(parameters);
    }
  }
}
static
double
stock_level_LM1(work_wait &parameters) {
  double actual_remaining = 
	-0.0494 * parameters.wait_so_far 
	- 129386.7627 * parameters.num_locks_so_far 
	+ 76560.2053 * parameters.total_wait_locks 
	- 0.1783 * parameters.mean_wait_of_all 
	+ 0.424 * parameters.avg_work_of_same_past_second 
	+ 21607379.3836;
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
	-0.0979 * parameters.work_so_far 
	- 0.1133 * parameters.wait_so_far 
	- 758298.1952 * parameters.num_locks_so_far 
	+ 227019.3571 * parameters.total_wait_locks 
	- 0.4611 * parameters.mean_wait_of_all 
	- 77984899.8759 * parameters.cpu_usage 
	+ 0.5598 * parameters.avg_work_of_same_past_second 
	- 0.1413 * parameters.avg_wait_of_same_past_second 
	+ 0.1753 * parameters.avg_latency_of_same_last_20 
	- 0.0092 * parameters.max_latency_of_same_last_50 
	+ 106397953.3334;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
tpcc_estimate(work_wait &parameters){
  return tpcc_LM1(parameters);
}