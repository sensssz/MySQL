#include "my_global.h"
#include "trace_tool.h"

static
double
new_order_LM1(work_wait &parameters) {
  double actual_remaining = 
	941.1193 * parameters.work_so_far 
	- 0.0331 * parameters.wait_so_far 
	- 168429.6838 * parameters.num_locks_so_far 
	+ 61035.0905 * parameters.total_wait_locks 
	- 0.0924 * parameters.mean_wait_of_all 
	- 75943756.2563 * parameters.cpu_usage 
	+ 0.1184 * parameters.avg_work_of_same_past_second 
	- 0.0299 * parameters.avg_wait_of_same_past_second 
	+ 0.0171 * parameters.avg_latency_of_same_last_20 
	+ 0.0033 * parameters.max_latency_of_same_last_50 
	+ 89731149.2677;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM2(work_wait &parameters) {
  double actual_remaining = 
	5180.1692 * parameters.work_so_far 
	- 0.1685 * parameters.wait_so_far 
	- 168429.6838 * parameters.num_locks_so_far 
	+ 61035.0905 * parameters.total_wait_locks 
	- 0.0924 * parameters.mean_wait_of_all 
	- 375353154.5901 * parameters.cpu_usage 
	+ 0.0328 * parameters.avg_work_of_same_past_second 
	- 0.0299 * parameters.avg_wait_of_same_past_second 
	+ 0.0171 * parameters.avg_latency_of_same_last_20 
	- 0.0012 * parameters.max_latency_of_same_last_50 
	+ 312991906.806;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM3(work_wait &parameters) {
  double actual_remaining = 
	-5.6071 * parameters.work_so_far 
	- 0.1578 * parameters.wait_so_far 
	- 207848.7763 * parameters.num_locks_so_far 
	+ 104974.3277 * parameters.total_wait_locks 
	- 1.7638 * parameters.mean_wait_of_all 
	- 187744629.516 * parameters.cpu_usage 
	+ 0.6973 * parameters.avg_work_of_same_past_second 
	- 0.5685 * parameters.avg_wait_of_same_past_second 
	+ 0.011 * parameters.avg_latency_of_same_last_20 
	- 0.003 * parameters.max_latency_of_same_last_50 
	+ 380187298.9174;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM4(work_wait &parameters) {
  double actual_remaining = 
	1.3435 * parameters.work_so_far 
	- 0.0117 * parameters.wait_so_far 
	- 207848.7763 * parameters.num_locks_so_far 
	+ 1752808.8189 * parameters.total_wait_locks 
	- 0.2758 * parameters.mean_wait_of_all 
	- 324312853.5693 * parameters.cpu_usage 
	+ 0.0942 * parameters.avg_work_of_same_past_second 
	- 0.4683 * parameters.avg_wait_of_same_past_second 
	+ 0.3284 * parameters.avg_latency_of_same_last_20 
	- 0.2083 * parameters.max_latency_of_same_last_50 
	+ 483543950.9571;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM5(work_wait &parameters) {
  double actual_remaining = 
	1.3435 * parameters.work_so_far 
	- 0.0117 * parameters.wait_so_far 
	- 207848.7763 * parameters.num_locks_so_far 
	+ 2239367.7194 * parameters.total_wait_locks 
	- 0.2758 * parameters.mean_wait_of_all 
	- 268803605.0342 * parameters.cpu_usage 
	+ 0.0942 * parameters.avg_work_of_same_past_second 
	- 0.4683 * parameters.avg_wait_of_same_past_second 
	+ 0.4758 * parameters.avg_latency_of_same_last_20 
	- 0.1498 * parameters.max_latency_of_same_last_50 
	+ 457951252.4212;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM6(work_wait &parameters) {
  double actual_remaining = 
	2.0234 * parameters.work_so_far 
	- 0.0117 * parameters.wait_so_far 
	- 207848.7763 * parameters.num_locks_so_far 
	+ 588798.9797 * parameters.total_wait_locks 
	- 0.2758 * parameters.mean_wait_of_all 
	- 121278015.2143 * parameters.cpu_usage 
	+ 0.0942 * parameters.avg_work_of_same_past_second 
	- 0.3936 * parameters.avg_wait_of_same_past_second 
	+ 0.011 * parameters.avg_latency_of_same_last_20 
	- 0.003 * parameters.max_latency_of_same_last_50 
	+ 215405956.471;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM7(work_wait &parameters) {
  double actual_remaining = 
	1.985 * parameters.work_so_far 
	- 0.0117 * parameters.wait_so_far 
	- 207848.7763 * parameters.num_locks_so_far 
	+ 588798.9797 * parameters.total_wait_locks 
	- 0.2758 * parameters.mean_wait_of_all 
	- 121278015.2143 * parameters.cpu_usage 
	+ 0.0942 * parameters.avg_work_of_same_past_second 
	- 0.3936 * parameters.avg_wait_of_same_past_second 
	+ 1.1641 * parameters.avg_latency_of_same_last_20 
	- 0.003 * parameters.max_latency_of_same_last_50 
	+ 227991951.9881;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM8(work_wait &parameters) {
  double actual_remaining = 
	1.985 * parameters.work_so_far 
	- 0.0117 * parameters.wait_so_far 
	- 207848.7763 * parameters.num_locks_so_far 
	+ 588798.9797 * parameters.total_wait_locks 
	- 0.2758 * parameters.mean_wait_of_all 
	- 767626945.3361 * parameters.cpu_usage 
	+ 0.0942 * parameters.avg_work_of_same_past_second 
	- 0.3936 * parameters.avg_wait_of_same_past_second 
	+ 0.011 * parameters.avg_latency_of_same_last_20 
	- 0.003 * parameters.max_latency_of_same_last_50 
	+ 893902051.9463;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM9(work_wait &parameters) {
  double actual_remaining = 
	3.9566 * parameters.work_so_far 
	+ 0.9104 * parameters.wait_so_far 
	- 3242832.7394 * parameters.num_locks_so_far 
	+ 106886.9322 * parameters.total_wait_locks 
	- 0.8814 * parameters.mean_wait_of_all 
	- 21468963.9247 * parameters.cpu_usage 
	+ 0.5377 * parameters.avg_work_of_same_past_second 
	- 0.4913 * parameters.avg_wait_of_same_past_second 
	+ 0.0366 * parameters.avg_latency_of_same_last_20 
	- 0.0094 * parameters.max_latency_of_same_last_50 
	+ 133828447.4643;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM10(work_wait &parameters) {
  double actual_remaining = 
	1.3531 * parameters.work_so_far 
	+ 0.1537 * parameters.wait_so_far 
	- 164292.0497 * parameters.num_locks_so_far 
	+ 179965.8493 * parameters.total_wait_locks 
	- 0.1056 * parameters.mean_wait_of_all 
	- 37193743.8928 * parameters.cpu_usage 
	+ 0.435 * parameters.avg_work_of_same_past_second 
	- 0.0977 * parameters.avg_wait_of_same_past_second 
	+ 0.0705 * parameters.avg_latency_of_same_last_20 
	- 0.0196 * parameters.max_latency_of_same_last_50 
	+ 48534965.0917;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM11(work_wait &parameters) {
  double actual_remaining = 
	0.5755 * parameters.work_so_far 
	+ 0.2724 * parameters.wait_so_far 
	- 164292.0497 * parameters.num_locks_so_far 
	+ 110297.6725 * parameters.total_wait_locks 
	- 0.9985 * parameters.mean_wait_of_all 
	- 40663303.0644 * parameters.cpu_usage 
	- 0.2069 * parameters.avg_work_of_same_past_second 
	+ 0.7223 * parameters.avg_wait_of_same_past_second 
	+ 0.2553 * parameters.avg_latency_of_same_last_20 
	- 0.1079 * parameters.max_latency_of_same_last_50 
	+ 315130188.6436;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM12(work_wait &parameters) {
  double actual_remaining = 
	4.6183 * parameters.work_so_far 
	+ 0.2724 * parameters.wait_so_far 
	- 164292.0497 * parameters.num_locks_so_far 
	+ 110297.6725 * parameters.total_wait_locks 
	- 0.9985 * parameters.mean_wait_of_all 
	+ 666214732.2685 * parameters.cpu_usage 
	- 0.2069 * parameters.avg_work_of_same_past_second 
	+ 0.7223 * parameters.avg_wait_of_same_past_second 
	+ 0.2553 * parameters.avg_latency_of_same_last_20 
	- 0.1079 * parameters.max_latency_of_same_last_50 
	- 476329957.3988;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM13(work_wait &parameters) {
  double actual_remaining = 
	0.5755 * parameters.work_so_far 
	+ 0.2724 * parameters.wait_so_far 
	- 164292.0497 * parameters.num_locks_so_far 
	+ 110297.6725 * parameters.total_wait_locks 
	- 0.9985 * parameters.mean_wait_of_all 
	- 40663303.0644 * parameters.cpu_usage 
	- 0.2069 * parameters.avg_work_of_same_past_second 
	+ 0.7223 * parameters.avg_wait_of_same_past_second 
	+ 0.2553 * parameters.avg_latency_of_same_last_20 
	- 0.1079 * parameters.max_latency_of_same_last_50 
	+ 263066988.8772;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM14(work_wait &parameters) {
  double actual_remaining = 
	0.9061 * parameters.work_so_far 
	+ 0.2724 * parameters.wait_so_far 
	- 164292.0497 * parameters.num_locks_so_far 
	+ 1246180.2265 * parameters.total_wait_locks 
	- 3.1219 * parameters.mean_wait_of_all 
	- 40663303.0644 * parameters.cpu_usage 
	- 0.2069 * parameters.avg_work_of_same_past_second 
	+ 0.7223 * parameters.avg_wait_of_same_past_second 
	+ 0.3434 * parameters.avg_latency_of_same_last_20 
	- 0.1516 * parameters.max_latency_of_same_last_50 
	+ 266032684.4126;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM15(work_wait &parameters) {
  double actual_remaining = 
	1.0792 * parameters.work_so_far 
	+ 0.2724 * parameters.wait_so_far 
	- 164292.0497 * parameters.num_locks_so_far 
	+ 745237.6442 * parameters.total_wait_locks 
	- 2.7287 * parameters.mean_wait_of_all 
	- 40663303.0644 * parameters.cpu_usage 
	- 0.2069 * parameters.avg_work_of_same_past_second 
	+ 0.7223 * parameters.avg_wait_of_same_past_second 
	+ 0.3434 * parameters.avg_latency_of_same_last_20 
	- 0.1516 * parameters.max_latency_of_same_last_50 
	+ 257964575.4716;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM16(work_wait &parameters) {
  double actual_remaining = 
	2.1353 * parameters.work_so_far 
	+ 0.2459 * parameters.wait_so_far 
	- 164292.0497 * parameters.num_locks_so_far 
	+ 110297.6725 * parameters.total_wait_locks 
	- 0.8313 * parameters.mean_wait_of_all 
	- 40663303.0644 * parameters.cpu_usage 
	- 0.1379 * parameters.avg_work_of_same_past_second 
	+ 0.5464 * parameters.avg_wait_of_same_past_second 
	+ 0.1212 * parameters.avg_latency_of_same_last_20 
	- 0.0422 * parameters.max_latency_of_same_last_50 
	+ 123700994.6471;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM17(work_wait &parameters) {
  double actual_remaining = 
	1.4948 * parameters.work_so_far 
	+ 0.1453 * parameters.wait_so_far 
	- 164292.0497 * parameters.num_locks_so_far 
	+ 110297.6725 * parameters.total_wait_locks 
	- 0.2071 * parameters.mean_wait_of_all 
	- 224802899.5127 * parameters.cpu_usage 
	+ 0.4593 * parameters.avg_work_of_same_past_second 
	- 0.1058 * parameters.avg_wait_of_same_past_second 
	+ 0.0672 * parameters.avg_latency_of_same_last_20 
	- 0.0187 * parameters.max_latency_of_same_last_50 
	+ 239313881.5816;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM18(work_wait &parameters) {
  double actual_remaining = 
	97.1666 * parameters.work_so_far 
	- 0.3044 * parameters.wait_so_far 
	- 203824.5519 * parameters.num_locks_so_far 
	+ 140050.9763 * parameters.total_wait_locks 
	- 4.2777 * parameters.mean_wait_of_all 
	+ 302215892.1843 * parameters.cpu_usage 
	- 0.0038 * parameters.avg_work_of_same_past_second 
	+ 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0165 * parameters.avg_latency_of_same_last_20 
	- 0.1272 * parameters.max_latency_of_same_last_50 
	+ 314331475.0834;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM19(work_wait &parameters) {
  double actual_remaining = 
	2.8994 * parameters.work_so_far 
	+ 0.7288 * parameters.wait_so_far 
	- 6772845.8393 * parameters.num_locks_so_far 
	+ 1560018.8602 * parameters.total_wait_locks 
	- 2.5311 * parameters.mean_wait_of_all 
	- 4657905.457 * parameters.cpu_usage 
	- 0.0038 * parameters.avg_work_of_same_past_second 
	+ 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0165 * parameters.avg_latency_of_same_last_20 
	- 0.1014 * parameters.max_latency_of_same_last_50 
	+ 326746112.0513;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM20(work_wait &parameters) {
  double actual_remaining = 
	2.0546 * parameters.work_so_far 
	- 0.165 * parameters.wait_so_far 
	- 2425108.4849 * parameters.num_locks_so_far 
	+ 1693538.4462 * parameters.total_wait_locks 
	- 3.7193 * parameters.mean_wait_of_all 
	- 16592365.0049 * parameters.cpu_usage 
	- 0.026 * parameters.avg_work_of_same_past_second 
	+ 0.0122 * parameters.avg_wait_of_same_past_second 
	+ 0.0316 * parameters.avg_latency_of_same_last_20 
	- 0.0024 * parameters.max_latency_of_same_last_50 
	+ 197330637.5531;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM21(work_wait &parameters) {
  double actual_remaining = 
	1.0231 * parameters.work_so_far 
	- 0.1645 * parameters.wait_so_far 
	- 1131572.238 * parameters.num_locks_so_far 
	+ 1087069.3624 * parameters.total_wait_locks 
	- 0.3691 * parameters.mean_wait_of_all 
	- 34603880.6417 * parameters.cpu_usage 
	- 0.2816 * parameters.avg_work_of_same_past_second 
	+ 0.0304 * parameters.avg_wait_of_same_past_second 
	+ 0.0539 * parameters.avg_latency_of_same_last_20 
	- 0.0024 * parameters.max_latency_of_same_last_50 
	+ 137183098.0029;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM22(work_wait &parameters) {
  double actual_remaining = 
	2.8923 * parameters.work_so_far 
	+ 0.0288 * parameters.wait_so_far 
	- 6631856.1114 * parameters.num_locks_so_far 
	+ 1443593.7073 * parameters.total_wait_locks 
	- 0.3691 * parameters.mean_wait_of_all 
	- 34603880.6417 * parameters.cpu_usage 
	- 0.6262 * parameters.avg_work_of_same_past_second 
	+ 0.0304 * parameters.avg_wait_of_same_past_second 
	+ 0.0539 * parameters.avg_latency_of_same_last_20 
	- 0.0024 * parameters.max_latency_of_same_last_50 
	+ 231291196.171;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM23(work_wait &parameters) {
  double actual_remaining = 
	1.7426 * parameters.work_so_far 
	+ 0.0502 * parameters.wait_so_far 
	- 2878459.4006 * parameters.num_locks_so_far 
	+ 143687.5858 * parameters.total_wait_locks 
	- 0.3691 * parameters.mean_wait_of_all 
	- 34603880.6417 * parameters.cpu_usage 
	- 2.0613 * parameters.avg_work_of_same_past_second 
	+ 0.0304 * parameters.avg_wait_of_same_past_second 
	- 0.9241 * parameters.avg_latency_of_same_last_20 
	+ 0.1481 * parameters.max_latency_of_same_last_50 
	+ 942782491.4659;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM24(work_wait &parameters) {
  double actual_remaining = 
	2.3563 * parameters.work_so_far 
	+ 0.0502 * parameters.wait_so_far 
	- 2878459.4006 * parameters.num_locks_so_far 
	+ 143687.5858 * parameters.total_wait_locks 
	- 0.3691 * parameters.mean_wait_of_all 
	- 34603880.6417 * parameters.cpu_usage 
	- 2.4504 * parameters.avg_work_of_same_past_second 
	+ 0.0304 * parameters.avg_wait_of_same_past_second 
	- 0.6029 * parameters.avg_latency_of_same_last_20 
	+ 0.1962 * parameters.max_latency_of_same_last_50 
	+ 722647790.1183;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM25(work_wait &parameters) {
  double actual_remaining = 
	0.1571 * parameters.work_so_far 
	+ 0.0278 * parameters.wait_so_far 
	- 97171.7359 * parameters.num_locks_so_far 
	+ 2550375.5656 * parameters.total_wait_locks 
	- 3.4195 * parameters.mean_wait_of_all 
	- 29306072.4275 * parameters.cpu_usage 
	+ 0.0021 * parameters.avg_work_of_same_past_second 
	+ 0.0366 * parameters.avg_wait_of_same_past_second 
	- 0.7463 * parameters.avg_latency_of_same_last_20 
	- 0.0104 * parameters.max_latency_of_same_last_50 
	+ 434191598.018;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM26(work_wait &parameters) {
  double actual_remaining = 
	0.5782 * parameters.work_so_far 
	+ 0.0278 * parameters.wait_so_far 
	- 97171.7359 * parameters.num_locks_so_far 
	+ 191466.9683 * parameters.total_wait_locks 
	- 0.3485 * parameters.mean_wait_of_all 
	- 21779634.4901 * parameters.cpu_usage 
	+ 0.0021 * parameters.avg_work_of_same_past_second 
	+ 0.0366 * parameters.avg_wait_of_same_past_second 
	- 0.0124 * parameters.avg_latency_of_same_last_20 
	- 0.0104 * parameters.max_latency_of_same_last_50 
	+ 230846309.1316;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM27(work_wait &parameters) {
  double actual_remaining = 
	0.3089 * parameters.work_so_far 
	- 1.8957 * parameters.wait_so_far 
	- 1030987.8803 * parameters.num_locks_so_far 
	+ 136371.5827 * parameters.total_wait_locks 
	+ 2.028 * parameters.mean_wait_of_all 
	+ 559493597.1086 * parameters.cpu_usage 
	- 0.8254 * parameters.avg_work_of_same_past_second 
	+ 0.8085 * parameters.avg_wait_of_same_past_second 
	+ 0.2613 * parameters.avg_latency_of_same_last_20 
	- 0.0993 * parameters.max_latency_of_same_last_50 
	- 134078348.4394;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM28(work_wait &parameters) {
  double actual_remaining = 
	0.3089 * parameters.work_so_far 
	- 1.9908 * parameters.wait_so_far 
	+ 547454.876 * parameters.num_locks_so_far 
	+ 136371.5827 * parameters.total_wait_locks 
	- 4.3336 * parameters.mean_wait_of_all 
	+ 487560991.5098 * parameters.cpu_usage 
	- 0.8582 * parameters.avg_work_of_same_past_second 
	+ 0.9545 * parameters.avg_wait_of_same_past_second 
	+ 0.1435 * parameters.avg_latency_of_same_last_20 
	- 0.0613 * parameters.max_latency_of_same_last_50 
	+ 214949543.3446;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM29(work_wait &parameters) {
  double actual_remaining = 
	0.3089 * parameters.work_so_far 
	- 1.2263 * parameters.wait_so_far 
	- 225659.9434 * parameters.num_locks_so_far 
	+ 136371.5827 * parameters.total_wait_locks 
	+ 0.6661 * parameters.mean_wait_of_all 
	+ 372639778.3495 * parameters.cpu_usage 
	- 0.6429 * parameters.avg_work_of_same_past_second 
	+ 0.986 * parameters.avg_wait_of_same_past_second 
	+ 0.1435 * parameters.avg_latency_of_same_last_20 
	- 0.0613 * parameters.max_latency_of_same_last_50 
	+ 23195366.761;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM30(work_wait &parameters) {
  double actual_remaining = 
	0.9745 * parameters.work_so_far 
	- 0.0319 * parameters.wait_so_far 
	- 631856.7863 * parameters.num_locks_so_far 
	+ 136371.5827 * parameters.total_wait_locks 
	- 1.743 * parameters.mean_wait_of_all 
	- 5732700.7744 * parameters.cpu_usage 
	- 0.0422 * parameters.avg_work_of_same_past_second 
	+ 0.1296 * parameters.avg_wait_of_same_past_second 
	+ 0.0202 * parameters.avg_latency_of_same_last_20 
	- 0.0237 * parameters.max_latency_of_same_last_50 
	+ 321850896.6637;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM31(work_wait &parameters) {
  double actual_remaining = 
	0.1951 * parameters.work_so_far 
	+ 0.3326 * parameters.wait_so_far 
	- 97171.7359 * parameters.num_locks_so_far 
	- 2319116.1026 * parameters.total_wait_locks 
	- 1.0024 * parameters.mean_wait_of_all 
	- 5732700.7744 * parameters.cpu_usage 
	+ 0.0021 * parameters.avg_work_of_same_past_second 
	+ 0.1622 * parameters.avg_wait_of_same_past_second 
	- 0.0571 * parameters.avg_latency_of_same_last_20 
	- 0.0267 * parameters.max_latency_of_same_last_50 
	+ 720214069.0836;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM32(work_wait &parameters) {
  double actual_remaining = 
	1.2531 * parameters.work_so_far 
	+ 0.3964 * parameters.wait_so_far 
	- 3351482.7977 * parameters.num_locks_so_far 
	- 2940077.6834 * parameters.total_wait_locks 
	- 1.0024 * parameters.mean_wait_of_all 
	- 799337947.0581 * parameters.cpu_usage 
	+ 1.6681 * parameters.avg_work_of_same_past_second 
	+ 0.1622 * parameters.avg_wait_of_same_past_second 
	- 0.0571 * parameters.avg_latency_of_same_last_20 
	- 0.0267 * parameters.max_latency_of_same_last_50 
	+ 1428016923.0154;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM33(work_wait &parameters) {
  double actual_remaining = 
	1.2531 * parameters.work_so_far 
	+ 0.3964 * parameters.wait_so_far 
	- 3351482.7977 * parameters.num_locks_so_far 
	- 2940077.6834 * parameters.total_wait_locks 
	- 1.0024 * parameters.mean_wait_of_all 
	- 799337947.0581 * parameters.cpu_usage 
	+ 1.73 * parameters.avg_work_of_same_past_second 
	+ 0.1622 * parameters.avg_wait_of_same_past_second 
	- 0.0571 * parameters.avg_latency_of_same_last_20 
	- 0.0267 * parameters.max_latency_of_same_last_50 
	+ 1444133122.7393;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM34(work_wait &parameters) {
  double actual_remaining = 
	0.7919 * parameters.work_so_far 
	+ 0.3964 * parameters.wait_so_far 
	- 1932936.9503 * parameters.num_locks_so_far 
	- 2204036.5634 * parameters.total_wait_locks 
	- 1.0024 * parameters.mean_wait_of_all 
	- 453407455.0883 * parameters.cpu_usage 
	+ 0.313 * parameters.avg_work_of_same_past_second 
	+ 0.1622 * parameters.avg_wait_of_same_past_second 
	- 0.0571 * parameters.avg_latency_of_same_last_20 
	- 0.0842 * parameters.max_latency_of_same_last_50 
	+ 1224281752.422;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM35(work_wait &parameters) {
  double actual_remaining = 
	1.4713 * parameters.work_so_far 
	- 0.5757 * parameters.wait_so_far 
	- 18738926.6765 * parameters.num_locks_so_far 
	+ 699095.9379 * parameters.total_wait_locks 
	+ 10.1714 * parameters.mean_wait_of_all 
	- 5732700.7744 * parameters.cpu_usage 
	+ 0.0021 * parameters.avg_work_of_same_past_second 
	+ 0.0336 * parameters.avg_wait_of_same_past_second 
	+ 1.1056 * parameters.avg_latency_of_same_last_20 
	- 0.0128 * parameters.max_latency_of_same_last_50 
	- 375687596.4008;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM36(work_wait &parameters) {
  double actual_remaining = 
	0.9033 * parameters.work_so_far 
	+ 0.6357 * parameters.wait_so_far 
	+ 1497363.3826 * parameters.num_locks_so_far 
	+ 1182337.9567 * parameters.total_wait_locks 
	- 0.2432 * parameters.mean_wait_of_all 
	- 5732700.7744 * parameters.cpu_usage 
	- 0.3502 * parameters.avg_work_of_same_past_second 
	+ 0.0336 * parameters.avg_wait_of_same_past_second 
	- 0.0349 * parameters.avg_latency_of_same_last_20 
	- 0.1152 * parameters.max_latency_of_same_last_50 
	+ 136227048.2199;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM37(work_wait &parameters) {
  double actual_remaining = 
	-111.1466 * parameters.work_so_far 
	- 0.0321 * parameters.wait_so_far 
	- 62812641.9738 * parameters.num_locks_so_far 
	+ 1069985.4789 * parameters.total_wait_locks 
	- 3.8466 * parameters.mean_wait_of_all 
	- 1352854427.9055 * parameters.cpu_usage 
	+ 0.4172 * parameters.avg_work_of_same_past_second 
	- 0.0016 * parameters.avg_wait_of_same_past_second 
	+ 0.0034 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	+ 1943294564.402;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM38(work_wait &parameters) {
  double actual_remaining = 
	0.1953 * parameters.work_so_far 
	- 0.0191 * parameters.wait_so_far 
	- 835325.5159 * parameters.num_locks_so_far 
	+ 1205999.1511 * parameters.total_wait_locks 
	- 4.2788 * parameters.mean_wait_of_all 
	- 606044461.0118 * parameters.cpu_usage 
	+ 0.4201 * parameters.avg_work_of_same_past_second 
	- 0.0016 * parameters.avg_wait_of_same_past_second 
	+ 0.0034 * parameters.avg_latency_of_same_last_20 
	- 0.0347 * parameters.max_latency_of_same_last_50 
	+ 887300469.8452;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM39(work_wait &parameters) {
  double actual_remaining = 
	0.1953 * parameters.work_so_far 
	- 0.0725 * parameters.wait_so_far 
	- 886593.0675 * parameters.num_locks_so_far 
	- 6410.1494 * parameters.total_wait_locks 
	- 0.0259 * parameters.mean_wait_of_all 
	+ 26304430.9326 * parameters.cpu_usage 
	+ 0.0148 * parameters.avg_work_of_same_past_second 
	- 0.0041 * parameters.avg_wait_of_same_past_second 
	+ 0.9006 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 177770333.9379;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM40(work_wait &parameters) {
  double actual_remaining = 
	0.1953 * parameters.work_so_far 
	- 0.0419 * parameters.wait_so_far 
	- 886593.0675 * parameters.num_locks_so_far 
	+ 2526.5262 * parameters.total_wait_locks 
	- 0.0259 * parameters.mean_wait_of_all 
	+ 775786974.8246 * parameters.cpu_usage 
	+ 0.4024 * parameters.avg_work_of_same_past_second 
	- 0.0041 * parameters.avg_wait_of_same_past_second 
	+ 0.0135 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 469744816.1757;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM41(work_wait &parameters) {
  double actual_remaining = 
	1.7397 * parameters.work_so_far 
	- 0.2069 * parameters.wait_so_far 
	+ 1720839.1078 * parameters.num_locks_so_far 
	+ 1014588.6882 * parameters.total_wait_locks 
	- 3.3446 * parameters.mean_wait_of_all 
	- 323229912.008 * parameters.cpu_usage 
	+ 0.0044 * parameters.avg_work_of_same_past_second 
	+ 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.175 * parameters.avg_latency_of_same_last_20 
	- 0.0389 * parameters.max_latency_of_same_last_50 
	+ 578036185.2719;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM42(work_wait &parameters) {
  double actual_remaining = 
	8.0064 * parameters.work_so_far 
	- 0.1403 * parameters.wait_so_far 
	+ 9784608.4233 * parameters.num_locks_so_far 
	+ 1009031.6667 * parameters.total_wait_locks 
	- 2.3994 * parameters.mean_wait_of_all 
	- 518304515.3969 * parameters.cpu_usage 
	- 0.0005 * parameters.avg_work_of_same_past_second 
	+ 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0101 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 640758601.4022;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM43(work_wait &parameters) {
  double actual_remaining = 
	16.8405 * parameters.work_so_far 
	+ 0.5627 * parameters.wait_so_far 
	+ 146897998.2111 * parameters.num_locks_so_far 
	+ 125326.8626 * parameters.total_wait_locks 
	- 0.1366 * parameters.mean_wait_of_all 
	- 22906504.5438 * parameters.cpu_usage 
	+ 1.3983 * parameters.avg_work_of_same_past_second 
	- 1.3726 * parameters.avg_wait_of_same_past_second 
	+ 0.0101 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 608812841.0054;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM44(work_wait &parameters) {
  double actual_remaining = 
	1.5826 * parameters.work_so_far 
	- 0.1589 * parameters.wait_so_far 
	+ 1839664.976 * parameters.num_locks_so_far 
	+ 9019.0291 * parameters.total_wait_locks 
	- 0.0204 * parameters.mean_wait_of_all 
	- 809224812.1649 * parameters.cpu_usage 
	+ 0.0089 * parameters.avg_work_of_same_past_second 
	+ 1.0255 * parameters.avg_wait_of_same_past_second 
	+ 0.0052 * parameters.avg_latency_of_same_last_20 
	- 0.0496 * parameters.max_latency_of_same_last_50 
	+ 928966457.0281;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM45(work_wait &parameters) {
  double actual_remaining = 
	5.7233 * parameters.work_so_far 
	+ 0.3009 * parameters.wait_so_far 
	+ 51149.5171 * parameters.num_locks_so_far 
	+ 83411.1494 * parameters.total_wait_locks 
	- 0.0031 * parameters.mean_wait_of_all 
	- 1936111.9681 * parameters.cpu_usage 
	+ 0.7154 * parameters.avg_work_of_same_past_second 
	- 0.4413 * parameters.avg_wait_of_same_past_second 
	+ 0.1625 * parameters.avg_latency_of_same_last_20 
	- 0.0569 * parameters.max_latency_of_same_last_50 
	+ 251365888.5166;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM46(work_wait &parameters) {
  double actual_remaining = 
	0.8553 * parameters.work_so_far 
	- 0.6127 * parameters.wait_so_far 
	+ 1742439.9329 * parameters.num_locks_so_far 
	+ 24016.7341 * parameters.total_wait_locks 
	- 0.1115 * parameters.mean_wait_of_all 
	- 1936111.9681 * parameters.cpu_usage 
	+ 0.3885 * parameters.avg_work_of_same_past_second 
	- 0.0486 * parameters.avg_wait_of_same_past_second 
	+ 0.4122 * parameters.avg_latency_of_same_last_20 
	+ 0.0031 * parameters.max_latency_of_same_last_50 
	+ 275545914.7978;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM47(work_wait &parameters) {
  double actual_remaining = 
	0.8741 * parameters.work_so_far 
	+ 0.7989 * parameters.wait_so_far 
	+ 2245529.3145 * parameters.num_locks_so_far 
	+ 507688.0809 * parameters.total_wait_locks 
	- 2.8694 * parameters.mean_wait_of_all 
	- 1936111.9681 * parameters.cpu_usage 
	+ 1.105 * parameters.avg_work_of_same_past_second 
	- 1.2422 * parameters.avg_wait_of_same_past_second 
	+ 0.029 * parameters.avg_latency_of_same_last_20 
	+ 0.1458 * parameters.max_latency_of_same_last_50 
	+ 518691822.5204;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM48(work_wait &parameters) {
  double actual_remaining = 
	3.537 * parameters.work_so_far 
	+ 0.993 * parameters.wait_so_far 
	- 7184013.9548 * parameters.num_locks_so_far 
	+ 1179.903 * parameters.total_wait_locks 
	+ 0.0067 * parameters.mean_wait_of_all 
	- 301624954.1681 * parameters.cpu_usage 
	+ 0.2035 * parameters.avg_work_of_same_past_second 
	- 0.0049 * parameters.avg_wait_of_same_past_second 
	+ 0.0032 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 537382469.8773;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM49(work_wait &parameters) {
  double actual_remaining = 
	0.7459 * parameters.work_so_far 
	+ 0.6567 * parameters.wait_so_far 
	- 118614.8101 * parameters.num_locks_so_far 
	+ 207548.9768 * parameters.total_wait_locks 
	+ 0.0106 * parameters.mean_wait_of_all 
	- 6377127.2764 * parameters.cpu_usage 
	+ 0.0081 * parameters.avg_work_of_same_past_second 
	- 0.2273 * parameters.avg_wait_of_same_past_second 
	+ 0.2533 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 178810168.7089;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM50(work_wait &parameters) {
  double actual_remaining = 
	0.0748 * parameters.work_so_far 
	+ 0.0185 * parameters.wait_so_far 
	+ 111881.3242 * parameters.num_locks_so_far 
	- 365563.0608 * parameters.total_wait_locks 
	+ 3.1252 * parameters.mean_wait_of_all 
	- 30482507.0083 * parameters.cpu_usage 
	+ 0.0065 * parameters.avg_work_of_same_past_second 
	+ 0.01 * parameters.avg_wait_of_same_past_second 
	+ 0.5881 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 130596018.493;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM51(work_wait &parameters) {
  double actual_remaining = 
	0.0748 * parameters.work_so_far 
	- 0.0201 * parameters.wait_so_far 
	+ 111881.3242 * parameters.num_locks_so_far 
	- 84492.9504 * parameters.total_wait_locks 
	+ 0.6995 * parameters.mean_wait_of_all 
	- 30482507.0083 * parameters.cpu_usage 
	+ 0.0065 * parameters.avg_work_of_same_past_second 
	+ 0.01 * parameters.avg_wait_of_same_past_second 
	+ 0.0902 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 127942164.2767;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM52(work_wait &parameters) {
  double actual_remaining = 
	1.2785 * parameters.work_so_far 
	+ 0.6828 * parameters.wait_so_far 
	+ 51892028.7191 * parameters.num_locks_so_far 
	+ 195148.4812 * parameters.total_wait_locks 
	+ 0.0429 * parameters.mean_wait_of_all 
	- 39216294.5141 * parameters.cpu_usage 
	+ 0.0065 * parameters.avg_work_of_same_past_second 
	+ 0.0005 * parameters.avg_wait_of_same_past_second 
	+ 0.0027 * parameters.avg_latency_of_same_last_20 
	+ 0.0006 * parameters.max_latency_of_same_last_50 
	- 30300620.6302;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM53(work_wait &parameters) {
  double actual_remaining = 
	1.0578 * parameters.work_so_far 
	+ 0.6774 * parameters.wait_so_far 
	+ 827692.5729 * parameters.num_locks_so_far 
	- 165400.3471 * parameters.total_wait_locks 
	+ 0.9576 * parameters.mean_wait_of_all 
	- 33746917.1279 * parameters.cpu_usage 
	+ 0.1849 * parameters.avg_work_of_same_past_second 
	+ 0.0005 * parameters.avg_wait_of_same_past_second 
	+ 0.0027 * parameters.avg_latency_of_same_last_20 
	+ 0.0006 * parameters.max_latency_of_same_last_50 
	+ 167454794.8311;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM54(work_wait &parameters) {
  double actual_remaining = 
	1.2298 * parameters.work_so_far 
	+ 0.9627 * parameters.wait_so_far 
	- 5263217.6336 * parameters.num_locks_so_far 
	- 2470.6159 * parameters.total_wait_locks 
	+ 1.2467 * parameters.mean_wait_of_all 
	- 36505516.3858 * parameters.cpu_usage 
	+ 0.0065 * parameters.avg_work_of_same_past_second 
	+ 0.0005 * parameters.avg_wait_of_same_past_second 
	+ 0.0027 * parameters.avg_latency_of_same_last_20 
	+ 0.002 * parameters.max_latency_of_same_last_50 
	+ 165844795.7775;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM55(work_wait &parameters) {
  double actual_remaining = 
	5.3944 * parameters.work_so_far 
	- 0.001 * parameters.wait_so_far 
	+ 25126.7058 * parameters.num_locks_so_far 
	+ 377123.5985 * parameters.total_wait_locks 
	+ 0.0749 * parameters.mean_wait_of_all 
	- 29949348.1925 * parameters.cpu_usage 
	- 0.2968 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0027 * parameters.avg_latency_of_same_last_20 
	+ 0.0003 * parameters.max_latency_of_same_last_50 
	+ 468812650.7197;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM56(work_wait &parameters) {
  double actual_remaining = 
	0.063 * parameters.work_so_far 
	- 0.001 * parameters.wait_so_far 
	+ 25126.7058 * parameters.num_locks_so_far 
	- 615653.9313 * parameters.total_wait_locks 
	+ 3.8593 * parameters.mean_wait_of_all 
	- 16073272.0989 * parameters.cpu_usage 
	+ 0.0199 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0087 * parameters.avg_latency_of_same_last_20 
	+ 0.0829 * parameters.max_latency_of_same_last_50 
	+ 25110938.7709;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM57(work_wait &parameters) {
  double actual_remaining = 
	0.0495 * parameters.work_so_far 
	- 0.001 * parameters.wait_so_far 
	+ 25126.7058 * parameters.num_locks_so_far 
	- 691722.7468 * parameters.total_wait_locks 
	+ 3.851 * parameters.mean_wait_of_all 
	- 16073272.0989 * parameters.cpu_usage 
	+ 0.4397 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0059 * parameters.avg_latency_of_same_last_20 
	+ 0.0003 * parameters.max_latency_of_same_last_50 
	+ 165647411.004;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM58(work_wait &parameters) {
  double actual_remaining = 
	0.0495 * parameters.work_so_far 
	- 0.001 * parameters.wait_so_far 
	+ 25126.7058 * parameters.num_locks_so_far 
	- 54152.6679 * parameters.total_wait_locks 
	+ 0.3142 * parameters.mean_wait_of_all 
	- 16073272.0989 * parameters.cpu_usage 
	+ 0.0372 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.312 * parameters.avg_latency_of_same_last_20 
	+ 0.0003 * parameters.max_latency_of_same_last_50 
	+ 341895713.7569;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM59(work_wait &parameters) {
  double actual_remaining = 
	-1931.3711 * parameters.work_so_far 
	- 0.2164 * parameters.wait_so_far 
	+ 2183125.0828 * parameters.num_locks_so_far 
	- 11973.4741 * parameters.total_wait_locks 
	+ 0.0767 * parameters.mean_wait_of_all 
	+ 19708532.3863 * parameters.cpu_usage 
	+ 0.039 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0248 * parameters.avg_latency_of_same_last_20 
	+ 0.0003 * parameters.max_latency_of_same_last_50 
	+ 383010222.1586;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM60(work_wait &parameters) {
  double actual_remaining = 
	1573.7237 * parameters.work_so_far 
	- 0.0134 * parameters.wait_so_far 
	+ 2183125.0828 * parameters.num_locks_so_far 
	+ 267631.8658 * parameters.total_wait_locks 
	- 2.02 * parameters.mean_wait_of_all 
	+ 27749159.4863 * parameters.cpu_usage 
	+ 0.0226 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0296 * parameters.avg_latency_of_same_last_20 
	+ 0.0779 * parameters.max_latency_of_same_last_50 
	+ 127825409.0283;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM61(work_wait &parameters) {
  double actual_remaining = 
	-5518.5843 * parameters.work_so_far 
	- 0.0273 * parameters.wait_so_far 
	+ 2183125.0828 * parameters.num_locks_so_far 
	- 66283.2748 * parameters.total_wait_locks 
	+ 0.4289 * parameters.mean_wait_of_all 
	- 8768958973.9951 * parameters.cpu_usage 
	+ 1.2764 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.1515 * parameters.avg_latency_of_same_last_20 
	- 0.0711 * parameters.max_latency_of_same_last_50 
	+ 8981740152.2172;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM62(work_wait &parameters) {
  double actual_remaining = 
	-193.9119 * parameters.work_so_far 
	- 0.0273 * parameters.wait_so_far 
	+ 2183125.0828 * parameters.num_locks_so_far 
	- 880421.1792 * parameters.total_wait_locks 
	+ 5.2942 * parameters.mean_wait_of_all 
	- 1310624244.8738 * parameters.cpu_usage 
	+ 0.1805 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.1393 * parameters.avg_latency_of_same_last_20 
	- 0.0572 * parameters.max_latency_of_same_last_50 
	+ 1236837352.2515;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM63(work_wait &parameters) {
  double actual_remaining = 
	-570.8495 * parameters.work_so_far 
	- 0.0493 * parameters.wait_so_far 
	+ 2183125.0828 * parameters.num_locks_so_far 
	+ 72571.1746 * parameters.total_wait_locks 
	- 0.6003 * parameters.mean_wait_of_all 
	- 1550522371.8137 * parameters.cpu_usage 
	+ 0.1646 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.3906 * parameters.avg_latency_of_same_last_20 
	- 0.2232 * parameters.max_latency_of_same_last_50 
	+ 2354911194.952;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM64(work_wait &parameters) {
  double actual_remaining = 
	-570.8495 * parameters.work_so_far 
	- 0.0493 * parameters.wait_so_far 
	+ 2183125.0828 * parameters.num_locks_so_far 
	+ 72571.1746 * parameters.total_wait_locks 
	- 0.6003 * parameters.mean_wait_of_all 
	- 1550522371.8137 * parameters.cpu_usage 
	+ 0.1646 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.4258 * parameters.avg_latency_of_same_last_20 
	- 0.2619 * parameters.max_latency_of_same_last_50 
	+ 2261934229.5717;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM65(work_wait &parameters) {
  double actual_remaining = 
	0.0492 * parameters.work_so_far 
	- 0.01 * parameters.wait_so_far 
	+ 2432124.8955 * parameters.num_locks_so_far 
	- 46114.2298 * parameters.total_wait_locks 
	+ 0.2638 * parameters.mean_wait_of_all 
	- 6745946.848 * parameters.cpu_usage 
	+ 0.0109 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0167 * parameters.avg_latency_of_same_last_20 
	+ 0.0003 * parameters.max_latency_of_same_last_50 
	+ 329210866.8645;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM66(work_wait &parameters) {
  double actual_remaining = 
	0.0492 * parameters.work_so_far 
	- 0.0415 * parameters.wait_so_far 
	+ 2432124.8955 * parameters.num_locks_so_far 
	- 388975.7108 * parameters.total_wait_locks 
	+ 2.009 * parameters.mean_wait_of_all 
	+ 610942200.5677 * parameters.cpu_usage 
	+ 0.0109 * parameters.avg_work_of_same_past_second 
	- 0.1544 * parameters.avg_wait_of_same_past_second 
	+ 0.0213 * parameters.avg_latency_of_same_last_20 
	- 0.0943 * parameters.max_latency_of_same_last_50 
	+ 94033042.397;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM67(work_wait &parameters) {
  double actual_remaining = 
	0.0492 * parameters.work_so_far 
	- 0.0415 * parameters.wait_so_far 
	+ 2432124.8955 * parameters.num_locks_so_far 
	- 254624.28 * parameters.total_wait_locks 
	+ 1.3764 * parameters.mean_wait_of_all 
	+ 843333097.4705 * parameters.cpu_usage 
	+ 0.0109 * parameters.avg_work_of_same_past_second 
	+ 3.4522 * parameters.avg_wait_of_same_past_second 
	+ 0.0213 * parameters.avg_latency_of_same_last_20 
	+ 2.1759 * parameters.max_latency_of_same_last_50 
	- 5237306495.2511;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM68(work_wait &parameters) {
  double actual_remaining = 
	2.8957 * parameters.work_so_far 
	- 0.0415 * parameters.wait_so_far 
	+ 2432124.8955 * parameters.num_locks_so_far 
	+ 562098.3204 * parameters.total_wait_locks 
	- 6.0283 * parameters.mean_wait_of_all 
	+ 350023807.8105 * parameters.cpu_usage 
	+ 0.0109 * parameters.avg_work_of_same_past_second 
	- 0.1544 * parameters.avg_wait_of_same_past_second 
	+ 0.0213 * parameters.avg_latency_of_same_last_20 
	+ 0.0003 * parameters.max_latency_of_same_last_50 
	+ 641040352.4437;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM69(work_wait &parameters) {
  double actual_remaining = 
	3.2119 * parameters.work_so_far 
	- 0.0415 * parameters.wait_so_far 
	+ 2432124.8955 * parameters.num_locks_so_far 
	+ 716396.3937 * parameters.total_wait_locks 
	- 7.144 * parameters.mean_wait_of_all 
	+ 350023807.8105 * parameters.cpu_usage 
	+ 0.0109 * parameters.avg_work_of_same_past_second 
	- 0.1544 * parameters.avg_wait_of_same_past_second 
	+ 0.0213 * parameters.avg_latency_of_same_last_20 
	+ 0.0003 * parameters.max_latency_of_same_last_50 
	+ 793713241.0332;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM70(work_wait &parameters) {
  double actual_remaining = 
	0.0492 * parameters.work_so_far 
	- 0.2454 * parameters.wait_so_far 
	+ 2432124.8955 * parameters.num_locks_so_far 
	- 1771712.3863 * parameters.total_wait_locks 
	+ 10.079 * parameters.mean_wait_of_all 
	- 6745946.848 * parameters.cpu_usage 
	+ 0.0109 * parameters.avg_work_of_same_past_second 
	- 0.0953 * parameters.avg_wait_of_same_past_second 
	+ 0.0213 * parameters.avg_latency_of_same_last_20 
	+ 0.1243 * parameters.max_latency_of_same_last_50 
	- 239011791.1667;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM71(work_wait &parameters) {
  double actual_remaining = 
	14.1656 * parameters.work_so_far 
	+ 1.3014 * parameters.wait_so_far 
	- 15151811.332 * parameters.num_locks_so_far 
	- 87272.4871 * parameters.total_wait_locks 
	+ 0.5288 * parameters.mean_wait_of_all 
	- 87868001.3184 * parameters.cpu_usage 
	+ 0.0494 * parameters.avg_work_of_same_past_second 
	- 0.0016 * parameters.avg_wait_of_same_past_second 
	+ 0.0146 * parameters.avg_latency_of_same_last_20 
	+ 378913053.5626;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM72(work_wait &parameters) {
  double actual_remaining = 
	1.3453 * parameters.work_so_far 
	+ 0.1528 * parameters.wait_so_far 
	+ 9855522.6632 * parameters.num_locks_so_far 
	- 153348.0746 * parameters.total_wait_locks 
	+ 2.3584 * parameters.mean_wait_of_all 
	- 282309235.054 * parameters.cpu_usage 
	+ 0.0391 * parameters.avg_work_of_same_past_second 
	- 0.0016 * parameters.avg_wait_of_same_past_second 
	+ 0.03 * parameters.avg_latency_of_same_last_20 
	+ 294727223.7668;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM73(work_wait &parameters) {
  double actual_remaining = 
	1.3453 * parameters.work_so_far 
	+ 0.1528 * parameters.wait_so_far 
	+ 1183328.5369 * parameters.num_locks_so_far 
	- 1275978.7287 * parameters.total_wait_locks 
	+ 5.9466 * parameters.mean_wait_of_all 
	- 139759759.5891 * parameters.cpu_usage 
	+ 0.0391 * parameters.avg_work_of_same_past_second 
	- 0.0016 * parameters.avg_wait_of_same_past_second 
	+ 0.03 * parameters.avg_latency_of_same_last_20 
	+ 463871981.6296;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM74(work_wait &parameters) {
  double actual_remaining = 
	14.9746 * parameters.work_so_far 
	+ 0.1528 * parameters.wait_so_far 
	- 5172031.3524 * parameters.num_locks_so_far 
	- 274420.3862 * parameters.total_wait_locks 
	+ 1.4711 * parameters.mean_wait_of_all 
	- 71638771.3138 * parameters.cpu_usage 
	+ 0.0391 * parameters.avg_work_of_same_past_second 
	- 0.0016 * parameters.avg_wait_of_same_past_second 
	+ 0.0619 * parameters.avg_latency_of_same_last_20 
	+ 0.0623 * parameters.max_latency_of_same_last_50 
	+ 104569482.669;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM75(work_wait &parameters) {
  double actual_remaining = 
	1.6175 * parameters.work_so_far 
	+ 0.13 * parameters.wait_so_far 
	+ 49429396.3369 * parameters.num_locks_so_far 
	- 1274538.1777 * parameters.total_wait_locks 
	+ 8.3177 * parameters.mean_wait_of_all 
	- 45472392.6828 * parameters.cpu_usage 
	+ 0.0224 * parameters.avg_work_of_same_past_second 
	- 0.0016 * parameters.avg_wait_of_same_past_second 
	+ 0.019 * parameters.avg_latency_of_same_last_20 
	- 238880454.4349;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM76(work_wait &parameters) {
  double actual_remaining = 
	0.4885 * parameters.work_so_far 
	+ 2.0083 * parameters.wait_so_far 
	- 2853394.8069 * parameters.num_locks_so_far 
	- 160457.6738 * parameters.total_wait_locks 
	+ 1.1155 * parameters.mean_wait_of_all 
	- 45472392.6828 * parameters.cpu_usage 
	+ 0.0224 * parameters.avg_work_of_same_past_second 
	+ 0.7865 * parameters.avg_wait_of_same_past_second 
	- 0.0315 * parameters.avg_latency_of_same_last_20 
	- 0.1061 * parameters.max_latency_of_same_last_50 
	+ 434618992.1103;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM77(work_wait &parameters) {
  double actual_remaining = 
	0.4885 * parameters.work_so_far 
	+ 0.6069 * parameters.wait_so_far 
	- 2853394.8069 * parameters.num_locks_so_far 
	- 160457.6738 * parameters.total_wait_locks 
	+ 1.1155 * parameters.mean_wait_of_all 
	- 45472392.6828 * parameters.cpu_usage 
	+ 0.0224 * parameters.avg_work_of_same_past_second 
	+ 0.3445 * parameters.avg_wait_of_same_past_second 
	- 0.0594 * parameters.avg_latency_of_same_last_20 
	+ 560918254.1217;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM78(work_wait &parameters) {
  double actual_remaining = 
	1.818 * parameters.work_so_far 
	+ 0.9682 * parameters.wait_so_far 
	- 3517900.751 * parameters.num_locks_so_far 
	- 293954.8067 * parameters.total_wait_locks 
	+ 2.0725 * parameters.mean_wait_of_all 
	- 29641085.9629 * parameters.cpu_usage 
	+ 0.0077 * parameters.avg_work_of_same_past_second 
	- 0.3157 * parameters.avg_wait_of_same_past_second 
	+ 0.2762 * parameters.avg_latency_of_same_last_20 
	+ 74936332.9591;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM79(work_wait &parameters) {
  double actual_remaining = 
	1.5082 * parameters.work_so_far 
	+ 0.5812 * parameters.wait_so_far 
	- 7348347.3341 * parameters.num_locks_so_far 
	- 43193.9797 * parameters.total_wait_locks 
	+ 0.3342 * parameters.mean_wait_of_all 
	- 17532565.4237 * parameters.cpu_usage 
	- 0.5196 * parameters.avg_work_of_same_past_second 
	- 0.0016 * parameters.avg_wait_of_same_past_second 
	+ 0.5083 * parameters.avg_latency_of_same_last_20 
	+ 326015523.6058;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM80(work_wait &parameters) {
  double actual_remaining = 
	0.2355 * parameters.work_so_far 
	+ 0.1095 * parameters.wait_so_far 
	+ 6167307.8785 * parameters.num_locks_so_far 
	- 213590.2234 * parameters.total_wait_locks 
	+ 1.5542 * parameters.mean_wait_of_all 
	- 17532565.4237 * parameters.cpu_usage 
	- 0.0236 * parameters.avg_work_of_same_past_second 
	- 0.0016 * parameters.avg_wait_of_same_past_second 
	+ 0.0069 * parameters.avg_latency_of_same_last_20 
	+ 0.0087 * parameters.max_latency_of_same_last_50 
	+ 529644400.2757;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM81(work_wait &parameters) {
  double actual_remaining = 
	0.2355 * parameters.work_so_far 
	+ 0.1593 * parameters.wait_so_far 
	+ 16164134.6961 * parameters.num_locks_so_far 
	- 357128.8 * parameters.total_wait_locks 
	+ 2.6431 * parameters.mean_wait_of_all 
	- 17532565.4237 * parameters.cpu_usage 
	- 0.0792 * parameters.avg_work_of_same_past_second 
	- 0.0016 * parameters.avg_wait_of_same_past_second 
	- 0.7538 * parameters.avg_latency_of_same_last_20 
	+ 0.217 * parameters.max_latency_of_same_last_50 
	+ 662805201.1964;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM82(work_wait &parameters) {
  double actual_remaining = 
	0.8644 * parameters.work_so_far 
	+ 0.0703 * parameters.wait_so_far 
	- 1065507.1549 * parameters.num_locks_so_far 
	- 1860844.3705 * parameters.total_wait_locks 
	+ 13.7868 * parameters.mean_wait_of_all 
	- 17532565.4237 * parameters.cpu_usage 
	+ 0.0171 * parameters.avg_work_of_same_past_second 
	- 0.0016 * parameters.avg_wait_of_same_past_second 
	+ 0.0069 * parameters.avg_latency_of_same_last_20 
	- 389688619.8576;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM83(work_wait &parameters) {
  double actual_remaining = 
	0.1642 * parameters.work_so_far 
	+ 0.1563 * parameters.wait_so_far 
	+ 69037804.26 * parameters.num_locks_so_far 
	- 116395.3988 * parameters.total_wait_locks 
	+ 1.0083 * parameters.mean_wait_of_all 
	- 34078480.3847 * parameters.cpu_usage 
	+ 0.6797 * parameters.avg_work_of_same_past_second 
	- 0.781 * parameters.avg_wait_of_same_past_second 
	+ 0.0063 * parameters.avg_latency_of_same_last_20 
	+ 0.0038 * parameters.max_latency_of_same_last_50 
	+ 388576772.5182;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM84(work_wait &parameters) {
  double actual_remaining = 
	0.1642 * parameters.work_so_far 
	+ 0.1563 * parameters.wait_so_far 
	- 19718603.1507 * parameters.num_locks_so_far 
	+ 145360.0732 * parameters.total_wait_locks 
	+ 1.0083 * parameters.mean_wait_of_all 
	- 34078480.3847 * parameters.cpu_usage 
	+ 0.5023 * parameters.avg_work_of_same_past_second 
	- 0.5956 * parameters.avg_wait_of_same_past_second 
	+ 0.0063 * parameters.avg_latency_of_same_last_20 
	+ 0.0038 * parameters.max_latency_of_same_last_50 
	+ 898119331.5707;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM85(work_wait &parameters) {
  double actual_remaining = 
	0.4704 * parameters.work_so_far 
	+ 0.5161 * parameters.wait_so_far 
	- 1464639.2271 * parameters.num_locks_so_far 
	- 408722.4119 * parameters.total_wait_locks 
	+ 3.341 * parameters.mean_wait_of_all 
	- 34078480.3847 * parameters.cpu_usage 
	+ 0.463 * parameters.avg_work_of_same_past_second 
	- 0.8414 * parameters.avg_wait_of_same_past_second 
	+ 0.0063 * parameters.avg_latency_of_same_last_20 
	+ 0.0038 * parameters.max_latency_of_same_last_50 
	+ 400169445.3415;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM86(work_wait &parameters) {
  double actual_remaining = 
	0.5903 * parameters.work_so_far 
	+ 0.657 * parameters.wait_so_far 
	- 1687969.8639 * parameters.num_locks_so_far 
	+ 526539.1583 * parameters.total_wait_locks 
	- 2.1341 * parameters.mean_wait_of_all 
	- 549532902.0296 * parameters.cpu_usage 
	+ 0.0774 * parameters.avg_work_of_same_past_second 
	- 0.1236 * parameters.avg_wait_of_same_past_second 
	+ 0.0063 * parameters.avg_latency_of_same_last_20 
	+ 0.0917 * parameters.max_latency_of_same_last_50 
	+ 988836575.6361;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM87(work_wait &parameters) {
  double actual_remaining = 
	1.1332 * parameters.work_so_far 
	+ 0.8418 * parameters.wait_so_far 
	- 5181905.1319 * parameters.num_locks_so_far 
	- 808491.4309 * parameters.total_wait_locks 
	+ 4.8959 * parameters.mean_wait_of_all 
	- 418981216.8961 * parameters.cpu_usage 
	+ 0.0064 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.2427 * parameters.avg_latency_of_same_last_20 
	+ 416337960.2502;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
new_order_estimate(work_wait &parameters){

  if (parameters.avg_latency_of_same_last_20 <= 479081500) {

    if (parameters.total_wait_locks <= 174.5) {

      if (parameters.work_so_far <= 81648039) {

        if (parameters.total_wait_locks <= 103.5) {

          if (parameters.work_so_far <= 31236) {

            if (parameters.max_latency_of_same_last_50 <= 156992500) {
              return new_order_LM1(parameters);
            } else {
              return new_order_LM2(parameters);
            }
          } else {

            if (parameters.num_locks_so_far <= 18.5) {

              if (parameters.work_so_far <= 8645813) {
                return new_order_LM3(parameters);
              } else {

                if (parameters.avg_wait_of_same_past_second <= 23568900) {

                  if (parameters.total_wait_locks <= 80) {
                    return new_order_LM4(parameters);
                  } else {
                    return new_order_LM5(parameters);
                  }
                } else {

                  if (parameters.work_so_far <= 19912444) {
                    return new_order_LM6(parameters);
                  } else {

                    if (parameters.avg_latency_of_same_last_20 <= 92128400) {
                      return new_order_LM7(parameters);
                    } else {
                      return new_order_LM8(parameters);
                    }
                  }
                }
              }
            } else {

              if (parameters.work_so_far <= 19042096.5) {
                return new_order_LM9(parameters);
              } else {

                if (parameters.total_wait_locks <= 37.5) {
                  return new_order_LM10(parameters);
                } else {

                  if (parameters.avg_wait_of_same_past_second <= 27609450) {

                    if (parameters.mean_wait_of_all <= 59333850) {

                      if (parameters.max_latency_of_same_last_50 <= 465530000) {

                        if (parameters.cpu_usage <= 0.906) {
                          return new_order_LM11(parameters);
                        } else {

                          if (parameters.work_so_far <= 29329951.5) {
                            return new_order_LM12(parameters);
                          } else {
                            return new_order_LM13(parameters);
                          }
                        }
                      } else {

                        if (parameters.mean_wait_of_all <= 44023150) {
                          return new_order_LM14(parameters);
                        } else {
                          return new_order_LM15(parameters);
                        }
                      }
                    } else {
                      return new_order_LM16(parameters);
                    }
                  } else {
                    return new_order_LM17(parameters);
                  }
                }
              }
            }
          }
        } else {

          if (parameters.mean_wait_of_all <= 60797900) {

            if (parameters.work_so_far <= 1247571) {
              return new_order_LM18(parameters);
            } else {
              return new_order_LM19(parameters);
            }
          } else {

            if (parameters.avg_latency_of_same_last_20 <= 275651500) {
              return new_order_LM20(parameters);
            } else {

              if (parameters.work_so_far <= 93372.5) {
                return new_order_LM21(parameters);
              } else {

                if (parameters.wait_so_far <= 111393234) {
                  return new_order_LM22(parameters);
                } else {

                  if (parameters.avg_work_of_same_past_second <= 173142000) {
                    return new_order_LM23(parameters);
                  } else {
                    return new_order_LM24(parameters);
                  }
                }
              }
            }
          }
        }
      } else {

        if (parameters.work_so_far <= 244018649) {

          if (parameters.total_wait_locks <= 113.5) {

            if (parameters.mean_wait_of_all <= 58389700) {
              return new_order_LM25(parameters);
            } else {
              return new_order_LM26(parameters);
            }
          } else {

            if (parameters.wait_so_far <= 68491403) {

              if (parameters.num_locks_so_far <= 23.5) {

                if (parameters.max_latency_of_same_last_50 <= 265111500) {
                  return new_order_LM27(parameters);
                } else {

                  if (parameters.num_locks_so_far <= 5.5) {
                    return new_order_LM28(parameters);
                  } else {
                    return new_order_LM29(parameters);
                  }
                }
              } else {
                return new_order_LM30(parameters);
              }
            } else {

              if (parameters.num_locks_so_far <= 5.5) {
                return new_order_LM31(parameters);
              } else {

                if (parameters.cpu_usage <= 0.928) {

                  if (parameters.avg_work_of_same_past_second <= 158149000) {
                    return new_order_LM32(parameters);
                  } else {
                    return new_order_LM33(parameters);
                  }
                } else {
                  return new_order_LM34(parameters);
                }
              }
            }
          }
        } else {

          if (parameters.num_locks_so_far <= 22.5) {
            return new_order_LM35(parameters);
          } else {
            return new_order_LM36(parameters);
          }
        }
      }
    } else {

      if (parameters.work_so_far <= 1183861) {

        if (parameters.wait_so_far <= 114076091) {

          if (parameters.mean_wait_of_all <= 133749500) {

            if (parameters.wait_so_far <= 1985348.5) {
              return new_order_LM37(parameters);
            } else {
              return new_order_LM38(parameters);
            }
          } else {

            if (parameters.wait_so_far <= 107072) {
              return new_order_LM39(parameters);
            } else {
              return new_order_LM40(parameters);
            }
          }
        } else {

          if (parameters.total_wait_locks <= 450.5) {

            if (parameters.work_so_far <= 98904) {
              return new_order_LM41(parameters);
            } else {

              if (parameters.work_so_far <= 801201.5) {
                return new_order_LM42(parameters);
              } else {
                return new_order_LM43(parameters);
              }
            }
          } else {
            return new_order_LM44(parameters);
          }
        }
      } else {

        if (parameters.wait_so_far <= 263233897) {

          if (parameters.num_locks_so_far <= 11.5) {

            if (parameters.work_so_far <= 27844193) {
              return new_order_LM45(parameters);
            } else {

              if (parameters.num_locks_so_far <= 9.5) {
                return new_order_LM46(parameters);
              } else {
                return new_order_LM47(parameters);
              }
            }
          } else {

            if (parameters.work_so_far <= 83693034) {
              return new_order_LM48(parameters);
            } else {
              return new_order_LM49(parameters);
            }
          }
        } else {

          if (parameters.num_locks_so_far <= 5.5) {

            if (parameters.wait_so_far <= 576841546.5) {
              return new_order_LM50(parameters);
            } else {
              return new_order_LM51(parameters);
            }
          } else {

            if (parameters.wait_so_far <= 536724707) {

              if (parameters.num_locks_so_far <= 12.5) {
                return new_order_LM52(parameters);
              } else {
                return new_order_LM53(parameters);
              }
            } else {
              return new_order_LM54(parameters);
            }
          }
        }
      }
    }
  } else {

    if (parameters.num_locks_so_far <= 5.5) {

      if (parameters.wait_so_far <= 197677511) {

        if (parameters.cpu_usage <= 0.934) {
          return new_order_LM55(parameters);
        } else {

          if (parameters.work_so_far <= 55539) {
            return new_order_LM56(parameters);
          } else {

            if (parameters.work_so_far <= 3424318) {
              return new_order_LM57(parameters);
            } else {
              return new_order_LM58(parameters);
            }
          }
        }
      } else {

        if (parameters.work_so_far <= 105858) {

          if (parameters.avg_work_of_same_past_second <= 247272000) {
            return new_order_LM59(parameters);
          } else {

            if (parameters.cpu_usage <= 0.975) {
              return new_order_LM60(parameters);
            } else {

              if (parameters.max_latency_of_same_last_50 <= 2033780000) {

                if (parameters.max_latency_of_same_last_50 <= 1488735000) {
                  return new_order_LM61(parameters);
                } else {
                  return new_order_LM62(parameters);
                }
              } else {

                if (parameters.max_latency_of_same_last_50 <= 2463685000) {
                  return new_order_LM63(parameters);
                } else {
                  return new_order_LM64(parameters);
                }
              }
            }
          }
        } else {

          if (parameters.max_latency_of_same_last_50 <= 1871005000) {
            return new_order_LM65(parameters);
          } else {

            if (parameters.avg_wait_of_same_past_second <= 272726000) {

              if (parameters.mean_wait_of_all <= 163633000) {

                if (parameters.cpu_usage <= 0.97) {
                  return new_order_LM66(parameters);
                } else {
                  return new_order_LM67(parameters);
                }
              } else {

                if (parameters.work_so_far <= 308291.5) {
                  return new_order_LM68(parameters);
                } else {
                  return new_order_LM69(parameters);
                }
              }
            } else {
              return new_order_LM70(parameters);
            }
          }
        }
      }
    } else {

      if (parameters.wait_so_far <= 494814092) {

        if (parameters.work_so_far <= 209227116) {

          if (parameters.wait_so_far <= 119240114) {

            if (parameters.num_locks_so_far <= 21.5) {

              if (parameters.work_so_far <= 22216675) {

                if (parameters.avg_work_of_same_past_second <= 262215000) {
                  return new_order_LM71(parameters);
                } else {

                  if (parameters.num_locks_so_far <= 10.5) {

                    if (parameters.work_so_far <= 1898380.5) {
                      return new_order_LM72(parameters);
                    } else {
                      return new_order_LM73(parameters);
                    }
                  } else {
                    return new_order_LM74(parameters);
                  }
                }
              } else {

                if (parameters.num_locks_so_far <= 10.5) {
                  return new_order_LM75(parameters);
                } else {

                  if (parameters.avg_wait_of_same_past_second <= 289084500) {
                    return new_order_LM76(parameters);
                  } else {
                    return new_order_LM77(parameters);
                  }
                }
              }
            } else {
              return new_order_LM78(parameters);
            }
          } else {

            if (parameters.total_wait_locks <= 401.5) {
              return new_order_LM79(parameters);
            } else {

              if (parameters.num_locks_so_far <= 10.5) {

                if (parameters.num_locks_so_far <= 9.5) {
                  return new_order_LM80(parameters);
                } else {
                  return new_order_LM81(parameters);
                }
              } else {
                return new_order_LM82(parameters);
              }
            }
          }
        } else {

          if (parameters.work_so_far <= 559807371.5) {

            if (parameters.num_locks_so_far <= 24.5) {

              if (parameters.num_locks_so_far <= 10.5) {
                return new_order_LM83(parameters);
              } else {
                return new_order_LM84(parameters);
              }
            } else {
              return new_order_LM85(parameters);
            }
          } else {
            return new_order_LM86(parameters);
          }
        }
      } else {
        return new_order_LM87(parameters);
      }
    }
  }
}
static
double
payment_LM1(work_wait &parameters) {
  double actual_remaining = 
	14.5456 * parameters.work_so_far 
	+ 0.0017 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 1517.662 * parameters.total_wait_locks 
	- 0.0024 * parameters.mean_wait_of_all 
	+ 769812.558 * parameters.cpu_usage 
	+ 0.0011 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	- 0.0005 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 5074681.907;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM2(work_wait &parameters) {
  double actual_remaining = 
	14.5456 * parameters.work_so_far 
	+ 0.0224 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 17147.37 * parameters.total_wait_locks 
	- 0.0024 * parameters.mean_wait_of_all 
	+ 479159382.4429 * parameters.cpu_usage 
	+ 0.0011 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	- 0.0402 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 430624826.4606;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM3(work_wait &parameters) {
  double actual_remaining = 
	14.5456 * parameters.work_so_far 
	+ 0.0167 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 14909.3475 * parameters.total_wait_locks 
	- 0.0196 * parameters.mean_wait_of_all 
	+ 9975049.9769 * parameters.cpu_usage 
	+ 0.0011 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	- 0.0199 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 2411120.6221;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM4(work_wait &parameters) {
  double actual_remaining = 
	14.5456 * parameters.work_so_far 
	+ 0.0346 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 79054.7469 * parameters.total_wait_locks 
	- 0.2194 * parameters.mean_wait_of_all 
	+ 9975049.9769 * parameters.cpu_usage 
	+ 0.0011 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	- 0.0532 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 11631086.5438;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM5(work_wait &parameters) {
  double actual_remaining = 
	14.5456 * parameters.work_so_far 
	+ 0.0521 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 41024.5816 * parameters.total_wait_locks 
	- 0.101 * parameters.mean_wait_of_all 
	+ 9975049.9769 * parameters.cpu_usage 
	+ 0.0011 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	- 0.0335 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 45769.8743;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM6(work_wait &parameters) {
  double actual_remaining = 
	337.4116 * parameters.work_so_far 
	+ 0.0482 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 57814.1575 * parameters.total_wait_locks 
	- 0.0163 * parameters.mean_wait_of_all 
	+ 1845901.6466 * parameters.cpu_usage 
	+ 0.0632 * parameters.avg_work_of_same_past_second 
	+ 0.0032 * parameters.avg_wait_of_same_past_second 
	+ 0.0294 * parameters.avg_latency_of_same_last_20 
	- 0.0045 * parameters.max_latency_of_same_last_50 
	+ 5427697.2576;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM7(work_wait &parameters) {
  double actual_remaining = 
	337.4116 * parameters.work_so_far 
	+ 0.0557 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 75441.0097 * parameters.total_wait_locks 
	- 0.0163 * parameters.mean_wait_of_all 
	+ 1845901.6466 * parameters.cpu_usage 
	+ 0.0632 * parameters.avg_work_of_same_past_second 
	+ 0.0032 * parameters.avg_wait_of_same_past_second 
	+ 0.0294 * parameters.avg_latency_of_same_last_20 
	- 0.0045 * parameters.max_latency_of_same_last_50 
	+ 6218196.385;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM8(work_wait &parameters) {
  double actual_remaining = 
	337.4116 * parameters.work_so_far 
	+ 0.0242 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 4933.6009 * parameters.total_wait_locks 
	- 0.0163 * parameters.mean_wait_of_all 
	+ 1845901.6466 * parameters.cpu_usage 
	+ 0.0632 * parameters.avg_work_of_same_past_second 
	+ 0.0032 * parameters.avg_wait_of_same_past_second 
	+ 0.0294 * parameters.avg_latency_of_same_last_20 
	- 0.0045 * parameters.max_latency_of_same_last_50 
	+ 5931769.4631;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM9(work_wait &parameters) {
  double actual_remaining = 
	562.0613 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 4933.6009 * parameters.total_wait_locks 
	- 0.0163 * parameters.mean_wait_of_all 
	+ 1845901.6466 * parameters.cpu_usage 
	+ 0.0632 * parameters.avg_work_of_same_past_second 
	+ 0.4544 * parameters.avg_wait_of_same_past_second 
	+ 0.0488 * parameters.avg_latency_of_same_last_20 
	- 0.0045 * parameters.max_latency_of_same_last_50 
	+ 230515.2459;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM10(work_wait &parameters) {
  double actual_remaining = 
	163.5062 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 4933.6009 * parameters.total_wait_locks 
	- 0.0163 * parameters.mean_wait_of_all 
	+ 1845901.6466 * parameters.cpu_usage 
	+ 0.0632 * parameters.avg_work_of_same_past_second 
	+ 0.0032 * parameters.avg_wait_of_same_past_second 
	+ 0.0077 * parameters.avg_latency_of_same_last_20 
	- 0.0045 * parameters.max_latency_of_same_last_50 
	+ 9265778.4029;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM11(work_wait &parameters) {
  double actual_remaining = 
	-977.5164 * parameters.work_so_far 
	+ 0.1231 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 4933.6009 * parameters.total_wait_locks 
	- 0.0163 * parameters.mean_wait_of_all 
	+ 1845901.6466 * parameters.cpu_usage 
	+ 0.0632 * parameters.avg_work_of_same_past_second 
	+ 0.0032 * parameters.avg_wait_of_same_past_second 
	+ 0.0077 * parameters.avg_latency_of_same_last_20 
	- 0.1208 * parameters.max_latency_of_same_last_50 
	+ 74149541.6958;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM12(work_wait &parameters) {
  double actual_remaining = 
	-549.3259 * parameters.work_so_far 
	+ 0.0297 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 16746.2906 * parameters.total_wait_locks 
	- 0.0163 * parameters.mean_wait_of_all 
	+ 1845901.6466 * parameters.cpu_usage 
	- 2.8648 * parameters.avg_work_of_same_past_second 
	+ 0.0032 * parameters.avg_wait_of_same_past_second 
	+ 0.0077 * parameters.avg_latency_of_same_last_20 
	- 0.1366 * parameters.max_latency_of_same_last_50 
	+ 89948649.8196;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM13(work_wait &parameters) {
  double actual_remaining = 
	-549.3259 * parameters.work_so_far 
	+ 0.0297 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 16746.2906 * parameters.total_wait_locks 
	- 0.0163 * parameters.mean_wait_of_all 
	+ 1845901.6466 * parameters.cpu_usage 
	+ 0.0632 * parameters.avg_work_of_same_past_second 
	+ 0.0032 * parameters.avg_wait_of_same_past_second 
	+ 0.0077 * parameters.avg_latency_of_same_last_20 
	- 0.1366 * parameters.max_latency_of_same_last_50 
	+ 69348751.9472;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM14(work_wait &parameters) {
  double actual_remaining = 
	-56.9068 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 46786.9189 * parameters.total_wait_locks 
	- 0.0163 * parameters.mean_wait_of_all 
	+ 1845901.6466 * parameters.cpu_usage 
	+ 0.0632 * parameters.avg_work_of_same_past_second 
	+ 0.0032 * parameters.avg_wait_of_same_past_second 
	+ 0.0103 * parameters.avg_latency_of_same_last_20 
	- 0.0061 * parameters.max_latency_of_same_last_50 
	+ 6369985.5479;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM15(work_wait &parameters) {
  double actual_remaining = 
	-56.9068 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 58569.7413 * parameters.total_wait_locks 
	- 0.0163 * parameters.mean_wait_of_all 
	+ 1845901.6466 * parameters.cpu_usage 
	+ 0.0632 * parameters.avg_work_of_same_past_second 
	+ 0.0032 * parameters.avg_wait_of_same_past_second 
	+ 0.0103 * parameters.avg_latency_of_same_last_20 
	- 0.0061 * parameters.max_latency_of_same_last_50 
	+ 8088152.5971;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM16(work_wait &parameters) {
  double actual_remaining = 
	-56.9068 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 23745.5221 * parameters.total_wait_locks 
	- 0.0163 * parameters.mean_wait_of_all 
	+ 1845901.6466 * parameters.cpu_usage 
	+ 0.0632 * parameters.avg_work_of_same_past_second 
	+ 0.0032 * parameters.avg_wait_of_same_past_second 
	+ 0.0103 * parameters.avg_latency_of_same_last_20 
	- 0.0061 * parameters.max_latency_of_same_last_50 
	+ 7326499.6806;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM17(work_wait &parameters) {
  double actual_remaining = 
	-517.6439 * parameters.work_so_far 
	- 0.02 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 7239.0264 * parameters.total_wait_locks 
	- 0.061 * parameters.mean_wait_of_all 
	+ 11839481.5623 * parameters.cpu_usage 
	+ 0.1848 * parameters.avg_work_of_same_past_second 
	+ 0.0032 * parameters.avg_wait_of_same_past_second 
	+ 0.0404 * parameters.avg_latency_of_same_last_20 
	- 0.0085 * parameters.max_latency_of_same_last_50 
	+ 17961473.3317;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM18(work_wait &parameters) {
  double actual_remaining = 
	-517.6439 * parameters.work_so_far 
	- 0.015 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 7239.0264 * parameters.total_wait_locks 
	- 0.061 * parameters.mean_wait_of_all 
	+ 11839481.5623 * parameters.cpu_usage 
	+ 0.1848 * parameters.avg_work_of_same_past_second 
	- 0.1709 * parameters.avg_wait_of_same_past_second 
	+ 0.0345 * parameters.avg_latency_of_same_last_20 
	- 0.0085 * parameters.max_latency_of_same_last_50 
	+ 46983479.4057;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM19(work_wait &parameters) {
  double actual_remaining = 
	-688.8832 * parameters.work_so_far 
	- 0.0023 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 21444.3157 * parameters.total_wait_locks 
	- 0.1163 * parameters.mean_wait_of_all 
	+ 3948758.5731 * parameters.cpu_usage 
	+ 0.1848 * parameters.avg_work_of_same_past_second 
	+ 0.0032 * parameters.avg_wait_of_same_past_second 
	+ 0.0164 * parameters.avg_latency_of_same_last_20 
	- 0.0067 * parameters.max_latency_of_same_last_50 
	+ 27823855.2032;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM20(work_wait &parameters) {
  double actual_remaining = 
	-526.0648 * parameters.work_so_far 
	- 0.0023 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 10741.2187 * parameters.total_wait_locks 
	- 0.0745 * parameters.mean_wait_of_all 
	+ 8355266.2164 * parameters.cpu_usage 
	+ 0.1848 * parameters.avg_work_of_same_past_second 
	+ 0.0032 * parameters.avg_wait_of_same_past_second 
	+ 0.0164 * parameters.avg_latency_of_same_last_20 
	- 0.0067 * parameters.max_latency_of_same_last_50 
	+ 24618291.8457;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM21(work_wait &parameters) {
  double actual_remaining = 
	-1965.2979 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 63870.584 * parameters.total_wait_locks 
	- 0.0163 * parameters.mean_wait_of_all 
	+ 18710067.7543 * parameters.cpu_usage 
	+ 1.1111 * parameters.avg_work_of_same_past_second 
	+ 0.0032 * parameters.avg_wait_of_same_past_second 
	+ 0.0444 * parameters.avg_latency_of_same_last_20 
	- 0.0059 * parameters.max_latency_of_same_last_50 
	+ 25834846.5348;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM22(work_wait &parameters) {
  double actual_remaining = 
	-3446.9475 * parameters.work_so_far 
	- 0.024 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 47039.038 * parameters.total_wait_locks 
	- 0.0163 * parameters.mean_wait_of_all 
	+ 18710067.7543 * parameters.cpu_usage 
	+ 1.7341 * parameters.avg_work_of_same_past_second 
	+ 0.0032 * parameters.avg_wait_of_same_past_second 
	+ 0.035 * parameters.avg_latency_of_same_last_20 
	- 0.0059 * parameters.max_latency_of_same_last_50 
	+ 51723089.4891;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM23(work_wait &parameters) {
  double actual_remaining = 
	-2735.0248 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 47039.038 * parameters.total_wait_locks 
	- 0.2471 * parameters.mean_wait_of_all 
	+ 18710067.7543 * parameters.cpu_usage 
	+ 1.7097 * parameters.avg_work_of_same_past_second 
	+ 0.0032 * parameters.avg_wait_of_same_past_second 
	+ 0.035 * parameters.avg_latency_of_same_last_20 
	- 0.0059 * parameters.max_latency_of_same_last_50 
	+ 78429361.1497;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM24(work_wait &parameters) {
  double actual_remaining = 
	-2735.0248 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 47039.038 * parameters.total_wait_locks 
	- 0.2471 * parameters.mean_wait_of_all 
	+ 18710067.7543 * parameters.cpu_usage 
	+ 1.7097 * parameters.avg_work_of_same_past_second 
	+ 0.0032 * parameters.avg_wait_of_same_past_second 
	+ 0.035 * parameters.avg_latency_of_same_last_20 
	- 0.0059 * parameters.max_latency_of_same_last_50 
	+ 79066823.2271;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM25(work_wait &parameters) {
  double actual_remaining = 
	-3818.5145 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 47039.038 * parameters.total_wait_locks 
	- 0.2471 * parameters.mean_wait_of_all 
	+ 18710067.7543 * parameters.cpu_usage 
	+ 1.7097 * parameters.avg_work_of_same_past_second 
	+ 0.0032 * parameters.avg_wait_of_same_past_second 
	+ 0.035 * parameters.avg_latency_of_same_last_20 
	- 0.0059 * parameters.max_latency_of_same_last_50 
	+ 87458966.7828;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM26(work_wait &parameters) {
  double actual_remaining = 
	-4090.6632 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 47039.038 * parameters.total_wait_locks 
	- 0.2471 * parameters.mean_wait_of_all 
	+ 18710067.7543 * parameters.cpu_usage 
	+ 1.7097 * parameters.avg_work_of_same_past_second 
	+ 0.0032 * parameters.avg_wait_of_same_past_second 
	+ 0.035 * parameters.avg_latency_of_same_last_20 
	- 0.0059 * parameters.max_latency_of_same_last_50 
	+ 93263801.5371;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM27(work_wait &parameters) {
  double actual_remaining = 
	-3392.3408 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 47039.038 * parameters.total_wait_locks 
	- 0.346 * parameters.mean_wait_of_all 
	+ 18710067.7543 * parameters.cpu_usage 
	+ 1.7097 * parameters.avg_work_of_same_past_second 
	+ 0.0032 * parameters.avg_wait_of_same_past_second 
	+ 0.035 * parameters.avg_latency_of_same_last_20 
	- 0.0059 * parameters.max_latency_of_same_last_50 
	+ 84838730.5009;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM28(work_wait &parameters) {
  double actual_remaining = 
	902.0058 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 82714.0784 * parameters.total_wait_locks 
	- 0.2245 * parameters.mean_wait_of_all 
	+ 0.0002 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 11862002.729;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM29(work_wait &parameters) {
  double actual_remaining = 
	20.6629 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 49054.8856 * parameters.total_wait_locks 
	- 0.0058 * parameters.mean_wait_of_all 
	- 144736263.4177 * parameters.cpu_usage 
	- 0.0027 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 147515516.8071;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM30(work_wait &parameters) {
  double actual_remaining = 
	20.6629 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 20546.4326 * parameters.total_wait_locks 
	- 0.0058 * parameters.mean_wait_of_all 
	- 2674101.2878 * parameters.cpu_usage 
	- 0.0027 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 10338660.6258;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM31(work_wait &parameters) {
  double actual_remaining = 
	18.1961 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 24738.1153 * parameters.total_wait_locks 
	- 0.4039 * parameters.mean_wait_of_all 
	+ 4367388.802 * parameters.cpu_usage 
	+ 1.0178 * parameters.avg_work_of_same_past_second 
	+ 0.0053 * parameters.avg_wait_of_same_past_second 
	- 0.0701 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 36753592.9469;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM32(work_wait &parameters) {
  double actual_remaining = 
	18.1961 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 417785.723 * parameters.total_wait_locks 
	- 1.7398 * parameters.mean_wait_of_all 
	- 228291578.5737 * parameters.cpu_usage 
	- 0.0181 * parameters.avg_work_of_same_past_second 
	+ 0.0513 * parameters.avg_wait_of_same_past_second 
	- 0.1081 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 341216628.9538;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM33(work_wait &parameters) {
  double actual_remaining = 
	18.1961 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 280125.0382 * parameters.total_wait_locks 
	- 1.7398 * parameters.mean_wait_of_all 
	- 228291578.5737 * parameters.cpu_usage 
	- 0.0181 * parameters.avg_work_of_same_past_second 
	+ 0.0513 * parameters.avg_wait_of_same_past_second 
	- 0.0838 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 371720669.6288;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM34(work_wait &parameters) {
  double actual_remaining = 
	18.1961 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 322942.7199 * parameters.total_wait_locks 
	- 2.0386 * parameters.mean_wait_of_all 
	- 228291578.5737 * parameters.cpu_usage 
	- 0.0181 * parameters.avg_work_of_same_past_second 
	+ 0.0851 * parameters.avg_wait_of_same_past_second 
	- 0.0418 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 382358186.6134;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM35(work_wait &parameters) {
  double actual_remaining = 
	18.1961 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 266928.2233 * parameters.total_wait_locks 
	- 1.7496 * parameters.mean_wait_of_all 
	- 321518582.7831 * parameters.cpu_usage 
	- 0.0181 * parameters.avg_work_of_same_past_second 
	+ 0.0691 * parameters.avg_wait_of_same_past_second 
	- 0.0418 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 451863178.5435;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM36(work_wait &parameters) {
  double actual_remaining = 
	18.1961 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 162729.0695 * parameters.total_wait_locks 
	- 0.6912 * parameters.mean_wait_of_all 
	- 175092065.4658 * parameters.cpu_usage 
	- 0.0181 * parameters.avg_work_of_same_past_second 
	+ 0.0392 * parameters.avg_wait_of_same_past_second 
	- 0.0556 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 229190409.8185;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM37(work_wait &parameters) {
  double actual_remaining = 
	-1017.7683 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 162729.0695 * parameters.total_wait_locks 
	- 0.6912 * parameters.mean_wait_of_all 
	- 175092065.4658 * parameters.cpu_usage 
	- 0.0181 * parameters.avg_work_of_same_past_second 
	+ 0.0392 * parameters.avg_wait_of_same_past_second 
	- 0.0556 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 250708014.8414;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM38(work_wait &parameters) {
  double actual_remaining = 
	18.1961 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 37687.9822 * parameters.total_wait_locks 
	- 0.1032 * parameters.mean_wait_of_all 
	+ 95271754.9123 * parameters.cpu_usage 
	- 0.0078 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	- 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	- 77679941.0333;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM39(work_wait &parameters) {
  double actual_remaining = 
	0.3771 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 62473.8678 * parameters.total_wait_locks 
	- 0.1977 * parameters.mean_wait_of_all 
	- 0.0031 * parameters.avg_work_of_same_past_second 
	- 0 * parameters.avg_wait_of_same_past_second 
	- 0.0201 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 29514931.1235;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM40(work_wait &parameters) {
  double actual_remaining = 
	0.3771 * parameters.work_so_far 
	- 1805.0259 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 1088.1262 * parameters.total_wait_locks 
	- 0.0021 * parameters.mean_wait_of_all 
	- 0.0462 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 34237993.3034;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM41(work_wait &parameters) {
  double actual_remaining = 
	0.3771 * parameters.work_so_far 
	+ 49.9145 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 1048.1972 * parameters.total_wait_locks 
	+ 0.0094 * parameters.mean_wait_of_all 
	- 3.2608 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 102252906.7044;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM42(work_wait &parameters) {
  double actual_remaining = 
	0.3771 * parameters.work_so_far 
	+ 1627.2623 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 991.9782 * parameters.total_wait_locks 
	+ 0.0091 * parameters.mean_wait_of_all 
	+ 27216870.566 * parameters.cpu_usage 
	- 0.2576 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0126 * parameters.max_latency_of_same_last_50 
	+ 11690160.2927;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM43(work_wait &parameters) {
  double actual_remaining = 
	0.3771 * parameters.work_so_far 
	+ 704.8476 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 991.9782 * parameters.total_wait_locks 
	+ 0.0091 * parameters.mean_wait_of_all 
	- 0.2576 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.0339 * parameters.avg_latency_of_same_last_20 
	- 0.0126 * parameters.max_latency_of_same_last_50 
	+ 71966779.7015;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM44(work_wait &parameters) {
  double actual_remaining = 
	0.3771 * parameters.work_so_far 
	+ 704.8476 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 991.9782 * parameters.total_wait_locks 
	+ 0.0091 * parameters.mean_wait_of_all 
	- 0.2576 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.0339 * parameters.avg_latency_of_same_last_20 
	- 0.0126 * parameters.max_latency_of_same_last_50 
	+ 71682985.1824;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM45(work_wait &parameters) {
  double actual_remaining = 
	0.3771 * parameters.work_so_far 
	+ 704.8476 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 991.9782 * parameters.total_wait_locks 
	+ 0.0091 * parameters.mean_wait_of_all 
	- 0.2576 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0126 * parameters.max_latency_of_same_last_50 
	+ 60294749.8806;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM46(work_wait &parameters) {
  double actual_remaining = 
	197.1861 * parameters.work_so_far 
	+ 704.8476 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 991.9782 * parameters.total_wait_locks 
	+ 0.0091 * parameters.mean_wait_of_all 
	- 0.2576 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0126 * parameters.max_latency_of_same_last_50 
	+ 48473588.6064;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM47(work_wait &parameters) {
  double actual_remaining = 
	-842.6423 * parameters.work_so_far 
	+ 704.8476 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 991.9782 * parameters.total_wait_locks 
	+ 0.0091 * parameters.mean_wait_of_all 
	- 0.2576 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.016 * parameters.max_latency_of_same_last_50 
	+ 72919161.4012;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM48(work_wait &parameters) {
  double actual_remaining = 
	0.3771 * parameters.work_so_far 
	+ 278.2793 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 991.9782 * parameters.total_wait_locks 
	+ 0.1288 * parameters.mean_wait_of_all 
	- 0.1242 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 9941575.0186;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM49(work_wait &parameters) {
  double actual_remaining = 
	0.3771 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 9925.6761 * parameters.total_wait_locks 
	- 0.0021 * parameters.mean_wait_of_all 
	- 0.0046 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0114 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 13780986.2371;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM50(work_wait &parameters) {
  double actual_remaining = 
	0.5901 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 740.0315 * parameters.total_wait_locks 
	- 0.002 * parameters.mean_wait_of_all 
	+ 800895.7561 * parameters.cpu_usage 
	- 0.0085 * parameters.avg_work_of_same_past_second 
	- 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0014 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 24973341.7632;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM51(work_wait &parameters) {
  double actual_remaining = 
	0.5901 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 493347.5056 * parameters.total_wait_locks 
	+ 2.022 * parameters.mean_wait_of_all 
	+ 1744559.8861 * parameters.cpu_usage 
	- 0.6129 * parameters.avg_work_of_same_past_second 
	- 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0025 * parameters.avg_latency_of_same_last_20 
	+ 0.0269 * parameters.max_latency_of_same_last_50 
	- 12836367.5837;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM52(work_wait &parameters) {
  double actual_remaining = 
	0.5901 * parameters.work_so_far 
	+ 0.1172 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 315084.3992 * parameters.total_wait_locks 
	+ 0.9978 * parameters.mean_wait_of_all 
	+ 1744559.8861 * parameters.cpu_usage 
	- 0.6129 * parameters.avg_work_of_same_past_second 
	- 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0025 * parameters.avg_latency_of_same_last_20 
	+ 0.0135 * parameters.max_latency_of_same_last_50 
	+ 42454771.4966;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM53(work_wait &parameters) {
  double actual_remaining = 
	0.5901 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 315084.3992 * parameters.total_wait_locks 
	+ 0.9978 * parameters.mean_wait_of_all 
	+ 1744559.8861 * parameters.cpu_usage 
	- 3.1804 * parameters.avg_work_of_same_past_second 
	- 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0025 * parameters.avg_latency_of_same_last_20 
	+ 0.0135 * parameters.max_latency_of_same_last_50 
	+ 143447504.4647;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM54(work_wait &parameters) {
  double actual_remaining = 
	0.5901 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 529571.6675 * parameters.total_wait_locks 
	+ 0.9978 * parameters.mean_wait_of_all 
	+ 1744559.8861 * parameters.cpu_usage 
	- 0.6129 * parameters.avg_work_of_same_past_second 
	- 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0025 * parameters.avg_latency_of_same_last_20 
	+ 0.0135 * parameters.max_latency_of_same_last_50 
	+ 94106180.8544;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM55(work_wait &parameters) {
  double actual_remaining = 
	0.5901 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 740.0315 * parameters.total_wait_locks 
	- 0.0709 * parameters.mean_wait_of_all 
	+ 1744559.8861 * parameters.cpu_usage 
	- 0.8293 * parameters.avg_work_of_same_past_second 
	- 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0025 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 58772213.2308;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM56(work_wait &parameters) {
  double actual_remaining = 
	0.5901 * parameters.work_so_far 
	- 0.0608 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 740.0315 * parameters.total_wait_locks 
	- 0.0319 * parameters.mean_wait_of_all 
	+ 1744559.8861 * parameters.cpu_usage 
	- 1.1091 * parameters.avg_work_of_same_past_second 
	- 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0025 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 62700383.0327;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM57(work_wait &parameters) {
  double actual_remaining = 
	0.5901 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 740.0315 * parameters.total_wait_locks 
	- 0.002 * parameters.mean_wait_of_all 
	- 0.5513 * parameters.avg_work_of_same_past_second 
	- 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0006 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 34916889.1969;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM58(work_wait &parameters) {
  double actual_remaining = 
	56.3711 * parameters.work_so_far 
	- 0.0044 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 452.592 * parameters.total_wait_locks 
	- 0.0013 * parameters.mean_wait_of_all 
	- 0.1335 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 20702104.63;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM59(work_wait &parameters) {
  double actual_remaining = 
	-8.4051 * parameters.work_so_far 
	- 0.0186 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 4081.1313 * parameters.total_wait_locks 
	+ 0.0164 * parameters.mean_wait_of_all 
	- 0.0018 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0317 * parameters.max_latency_of_same_last_50 
	+ 57090810.5168;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM60(work_wait &parameters) {
  double actual_remaining = 
	-1437.0075 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 4081.1313 * parameters.total_wait_locks 
	+ 0.0164 * parameters.mean_wait_of_all 
	- 0.0018 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	+ 1.9797 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 1017470535.9825;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM61(work_wait &parameters) {
  double actual_remaining = 
	-8.4051 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 4081.1313 * parameters.total_wait_locks 
	+ 0.0164 * parameters.mean_wait_of_all 
	- 0.0018 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	- 0.361 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 233452183.1962;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM62(work_wait &parameters) {
  double actual_remaining = 
	-11.2076 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 6385.5031 * parameters.total_wait_locks 
	- 0.0139 * parameters.mean_wait_of_all 
	- 0.9267 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 33536251.6614;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM63(work_wait &parameters) {
  double actual_remaining = 
	-89.7821 * parameters.work_so_far 
	- 0.0061 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 459.4585 * parameters.total_wait_locks 
	+ 0.0059 * parameters.mean_wait_of_all 
	- 0.0018 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 27985719.5334;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM64(work_wait &parameters) {
  double actual_remaining = 
	0.3495 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 108448.5249 * parameters.total_wait_locks 
	+ 0.6831 * parameters.mean_wait_of_all 
	- 0.0709 * parameters.avg_work_of_same_past_second 
	+ 0.0073 * parameters.avg_wait_of_same_past_second 
	- 0.042 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 7719282.9852;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM65(work_wait &parameters) {
  double actual_remaining = 
	0.3495 * parameters.work_so_far 
	- 0.0199 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 185506.9213 * parameters.total_wait_locks 
	+ 1.0479 * parameters.mean_wait_of_all 
	- 0.3673 * parameters.avg_work_of_same_past_second 
	+ 0.0375 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 25188690.6232;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM66(work_wait &parameters) {
  double actual_remaining = 
	0.3495 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 1762869.183 * parameters.total_wait_locks 
	- 6.2199 * parameters.mean_wait_of_all 
	- 4.5156 * parameters.avg_work_of_same_past_second 
	+ 0.5598 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0034 * parameters.max_latency_of_same_last_50 
	+ 92090765.0567;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM67(work_wait &parameters) {
  double actual_remaining = 
	0.3495 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 1003340.8621 * parameters.total_wait_locks 
	- 3.8168 * parameters.mean_wait_of_all 
	- 1.9777 * parameters.avg_work_of_same_past_second 
	+ 0.0391 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0034 * parameters.max_latency_of_same_last_50 
	+ 186842337.3198;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM68(work_wait &parameters) {
  double actual_remaining = 
	0.3495 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 1003340.8621 * parameters.total_wait_locks 
	- 3.6853 * parameters.mean_wait_of_all 
	- 1.9777 * parameters.avg_work_of_same_past_second 
	+ 0.0391 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0034 * parameters.max_latency_of_same_last_50 
	+ 175580876.5919;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM69(work_wait &parameters) {
  double actual_remaining = 
	0.3495 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 93432.4758 * parameters.total_wait_locks 
	- 0.7886 * parameters.mean_wait_of_all 
	- 2.0182 * parameters.avg_work_of_same_past_second 
	+ 0.0391 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0034 * parameters.max_latency_of_same_last_50 
	+ 134552712.7545;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM70(work_wait &parameters) {
  double actual_remaining = 
	-469.4012 * parameters.work_so_far 
	- 0.2002 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 460128.6388 * parameters.total_wait_locks 
	+ 9.733 * parameters.mean_wait_of_all 
	- 0.6501 * parameters.avg_work_of_same_past_second 
	+ 0.0576 * parameters.avg_wait_of_same_past_second 
	+ 1.1825 * parameters.avg_latency_of_same_last_20 
	- 0.0074 * parameters.max_latency_of_same_last_50 
	- 1370459964.4909;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM71(work_wait &parameters) {
  double actual_remaining = 
	0.3495 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 437202.3553 * parameters.total_wait_locks 
	+ 2.2426 * parameters.mean_wait_of_all 
	- 0.6501 * parameters.avg_work_of_same_past_second 
	+ 0.0576 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0074 * parameters.max_latency_of_same_last_50 
	- 54897228.2606;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM72(work_wait &parameters) {
  double actual_remaining = 
	0.3495 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 3098.1164 * parameters.total_wait_locks 
	+ 0.0067 * parameters.mean_wait_of_all 
	+ 42989601.9384 * parameters.cpu_usage 
	+ 0.0692 * parameters.avg_work_of_same_past_second 
	+ 0.0234 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 26154631.6659;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM73(work_wait &parameters) {
  double actual_remaining = 
	0.3495 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 3098.1164 * parameters.total_wait_locks 
	+ 0.0067 * parameters.mean_wait_of_all 
	- 0.165 * parameters.avg_work_of_same_past_second 
	+ 0.032 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 22038849.1723;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM74(work_wait &parameters) {
  double actual_remaining = 
	-68.6645 * parameters.work_so_far 
	- 0.0555 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 3098.1164 * parameters.total_wait_locks 
	+ 0.0067 * parameters.mean_wait_of_all 
	- 0.165 * parameters.avg_work_of_same_past_second 
	+ 0.032 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 41542276.715;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM75(work_wait &parameters) {
  double actual_remaining = 
	0.3495 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 3098.1164 * parameters.total_wait_locks 
	+ 0.0067 * parameters.mean_wait_of_all 
	- 0.165 * parameters.avg_work_of_same_past_second 
	+ 0.032 * parameters.avg_wait_of_same_past_second 
	+ 0.0032 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 22644642.1279;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM76(work_wait &parameters) {
  double actual_remaining = 
	0.3495 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 3098.1164 * parameters.total_wait_locks 
	+ 0.0067 * parameters.mean_wait_of_all 
	- 0.165 * parameters.avg_work_of_same_past_second 
	+ 0.032 * parameters.avg_wait_of_same_past_second 
	+ 0.0039 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 22700982.0085;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM77(work_wait &parameters) {
  double actual_remaining = 
	0.3495 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 12345.9275 * parameters.total_wait_locks 
	+ 0.0643 * parameters.mean_wait_of_all 
	- 0.0018 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	+ 0.0003 * parameters.max_latency_of_same_last_50 
	+ 15456723.2277;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM78(work_wait &parameters) {
  double actual_remaining = 
	0.3495 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 22863.3964 * parameters.total_wait_locks 
	+ 1.531 * parameters.mean_wait_of_all 
	- 0.0018 * parameters.avg_work_of_same_past_second 
	- 0.0026 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	- 155708055.9906;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM79(work_wait &parameters) {
  double actual_remaining = 
	0.3495 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 48692.1577 * parameters.total_wait_locks 
	+ 0.2473 * parameters.mean_wait_of_all 
	- 127350010.6509 * parameters.cpu_usage 
	- 0.0018 * parameters.avg_work_of_same_past_second 
	- 0.0083 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 136542116.6257;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM80(work_wait &parameters) {
  double actual_remaining = 
	0.1469 * parameters.work_so_far 
	- 0.0089 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	+ 23935.4224 * parameters.total_wait_locks 
	- 0.1933 * parameters.mean_wait_of_all 
	- 34589597.4038 * parameters.cpu_usage 
	+ 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0079 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 75219640.2937;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM81(work_wait &parameters) {
  double actual_remaining = 
	0.1469 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 255528.0904 * parameters.total_wait_locks 
	+ 2.2204 * parameters.mean_wait_of_all 
	+ 271984511.1388 * parameters.cpu_usage 
	- 0.2442 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0008 * parameters.max_latency_of_same_last_50 
	- 260274697.3886;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM82(work_wait &parameters) {
  double actual_remaining = 
	-147.3216 * parameters.work_so_far 
	- 0.0156 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 6626.4403 * parameters.total_wait_locks 
	- 10.6062 * parameters.mean_wait_of_all 
	+ 1048562.5483 * parameters.cpu_usage 
	+ 3.7721 * parameters.avg_work_of_same_past_second 
	- 0.5448 * parameters.avg_wait_of_same_past_second 
	+ 0.0264 * parameters.avg_latency_of_same_last_20 
	- 0.0359 * parameters.max_latency_of_same_last_50 
	+ 1828430084.4788;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM83(work_wait &parameters) {
  double actual_remaining = 
	-147.3216 * parameters.work_so_far 
	- 0.0268 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 1558376.0945 * parameters.total_wait_locks 
	- 499.8346 * parameters.mean_wait_of_all 
	+ 1048562.5483 * parameters.cpu_usage 
	+ 6.4265 * parameters.avg_work_of_same_past_second 
	- 0.8688 * parameters.avg_wait_of_same_past_second 
	+ 0.0448 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 72992848039.8926;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM84(work_wait &parameters) {
  double actual_remaining = 
	-147.3216 * parameters.work_so_far 
	- 0.0268 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 1642855.9606 * parameters.total_wait_locks 
	- 415.931 * parameters.mean_wait_of_all 
	+ 1048562.5483 * parameters.cpu_usage 
	+ 6.4265 * parameters.avg_work_of_same_past_second 
	- 0.8688 * parameters.avg_wait_of_same_past_second 
	+ 0.0448 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 60953972742.2052;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM85(work_wait &parameters) {
  double actual_remaining = 
	-237.4413 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 6626.4403 * parameters.total_wait_locks 
	- 0.9679 * parameters.mean_wait_of_all 
	+ 1048562.5483 * parameters.cpu_usage 
	- 0.0843 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 254805702.313;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM86(work_wait &parameters) {
  double actual_remaining = 
	0.1469 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 6626.4403 * parameters.total_wait_locks 
	- 0.9679 * parameters.mean_wait_of_all 
	- 124977126.6599 * parameters.cpu_usage 
	+ 0.8641 * parameters.avg_work_of_same_past_second 
	- 0.0854 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 304551737.7638;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM87(work_wait &parameters) {
  double actual_remaining = 
	0.1469 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 321230.8848 * parameters.total_wait_locks 
	+ 13.597 * parameters.mean_wait_of_all 
	- 120528598.5008 * parameters.cpu_usage 
	+ 0.0005 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	- 1663954050.1272;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM88(work_wait &parameters) {
  double actual_remaining = 
	0.1469 * parameters.work_so_far 
	- 0.0078 * parameters.wait_so_far 
	+ 31495.9023 * parameters.num_locks_so_far 
	- 127080.5188 * parameters.total_wait_locks 
	+ 0.9024 * parameters.mean_wait_of_all 
	+ 1048562.5483 * parameters.cpu_usage 
	+ 0.0005 * parameters.avg_wait_of_same_past_second 
	+ 0.0123 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	- 38099900.5569;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM89(work_wait &parameters) {
  double actual_remaining = 
	0.767 * parameters.work_so_far 
	+ 0.2153 * parameters.wait_so_far 
	- 777153.6421 * parameters.num_locks_so_far 
	+ 29992.1272 * parameters.total_wait_locks 
	- 0.127 * parameters.mean_wait_of_all 
	+ 0.2838 * parameters.avg_work_of_same_past_second 
	- 0.0196 * parameters.avg_wait_of_same_past_second 
	- 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 25340816.2954;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM90(work_wait &parameters) {
  double actual_remaining = 
	0.0069 * parameters.work_so_far 
	+ 0.0623 * parameters.wait_so_far 
	+ 691948.2534 * parameters.num_locks_so_far 
	+ 3817.2606 * parameters.total_wait_locks 
	- 0.0151 * parameters.mean_wait_of_all 
	+ 0.0003 * parameters.avg_wait_of_same_past_second 
	- 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 36877834.2353;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM91(work_wait &parameters) {
  double actual_remaining = 
	2.4764 * parameters.work_so_far 
	+ 0.7007 * parameters.wait_so_far 
	+ 1308389.9767 * parameters.num_locks_so_far 
	+ 3817.2606 * parameters.total_wait_locks 
	- 0.0151 * parameters.mean_wait_of_all 
	+ 0.0003 * parameters.avg_wait_of_same_past_second 
	- 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 15561073.075;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM92(work_wait &parameters) {
  double actual_remaining = 
	0.0069 * parameters.work_so_far 
	+ 0.0271 * parameters.wait_so_far 
	+ 345204.4172 * parameters.num_locks_so_far 
	+ 32563.0362 * parameters.total_wait_locks 
	- 0.0929 * parameters.mean_wait_of_all 
	+ 6233244.532 * parameters.cpu_usage 
	+ 0.0003 * parameters.avg_wait_of_same_past_second 
	- 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0362 * parameters.max_latency_of_same_last_50 
	+ 76857820.5114;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM93(work_wait &parameters) {
  double actual_remaining = 
	0.0069 * parameters.work_so_far 
	+ 0.0271 * parameters.wait_so_far 
	+ 345204.4172 * parameters.num_locks_so_far 
	+ 87777.9742 * parameters.total_wait_locks 
	- 0.2629 * parameters.mean_wait_of_all 
	+ 374444113.0295 * parameters.cpu_usage 
	+ 0.1665 * parameters.avg_wait_of_same_past_second 
	- 0.0591 * parameters.avg_latency_of_same_last_20 
	- 0.1046 * parameters.max_latency_of_same_last_50 
	- 217701839.6987;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM94(work_wait &parameters) {
  double actual_remaining = 
	0.0069 * parameters.work_so_far 
	+ 0.0271 * parameters.wait_so_far 
	+ 345204.4172 * parameters.num_locks_so_far 
	+ 87777.9742 * parameters.total_wait_locks 
	+ 0.1091 * parameters.mean_wait_of_all 
	+ 537169812.4093 * parameters.cpu_usage 
	- 0.6439 * parameters.avg_work_of_same_past_second 
	+ 0.1203 * parameters.avg_wait_of_same_past_second 
	- 0.1406 * parameters.avg_latency_of_same_last_20 
	- 0.1046 * parameters.max_latency_of_same_last_50 
	- 340803456.0585;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM95(work_wait &parameters) {
  double actual_remaining = 
	0.0069 * parameters.work_so_far 
	+ 0.0271 * parameters.wait_so_far 
	+ 345204.4172 * parameters.num_locks_so_far 
	+ 87777.9742 * parameters.total_wait_locks 
	+ 0.0737 * parameters.mean_wait_of_all 
	+ 537169812.4093 * parameters.cpu_usage 
	- 0.5825 * parameters.avg_work_of_same_past_second 
	+ 0.1203 * parameters.avg_wait_of_same_past_second 
	- 0.1406 * parameters.avg_latency_of_same_last_20 
	- 0.1046 * parameters.max_latency_of_same_last_50 
	- 338646190.5404;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM96(work_wait &parameters) {
  double actual_remaining = 
	0.0069 * parameters.work_so_far 
	+ 0.0271 * parameters.wait_so_far 
	+ 345204.4172 * parameters.num_locks_so_far 
	+ 87777.9742 * parameters.total_wait_locks 
	+ 0.0737 * parameters.mean_wait_of_all 
	+ 537169812.4093 * parameters.cpu_usage 
	- 0.5825 * parameters.avg_work_of_same_past_second 
	+ 0.1203 * parameters.avg_wait_of_same_past_second 
	- 0.1406 * parameters.avg_latency_of_same_last_20 
	- 0.1046 * parameters.max_latency_of_same_last_50 
	- 338383601.6384;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM97(work_wait &parameters) {
  double actual_remaining = 
	0.0069 * parameters.work_so_far 
	+ 0.0271 * parameters.wait_so_far 
	+ 345204.4172 * parameters.num_locks_so_far 
	- 16862.9094 * parameters.total_wait_locks 
	- 0.2629 * parameters.mean_wait_of_all 
	+ 526977254.8638 * parameters.cpu_usage 
	+ 0.1203 * parameters.avg_wait_of_same_past_second 
	- 0.1378 * parameters.avg_latency_of_same_last_20 
	- 0.1046 * parameters.max_latency_of_same_last_50 
	- 186512349.3024;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM98(work_wait &parameters) {
  double actual_remaining = 
	0.0069 * parameters.work_so_far 
	+ 0.0271 * parameters.wait_so_far 
	+ 345204.4172 * parameters.num_locks_so_far 
	+ 87777.9742 * parameters.total_wait_locks 
	- 0.2629 * parameters.mean_wait_of_all 
	+ 526977254.8638 * parameters.cpu_usage 
	+ 0.1789 * parameters.avg_wait_of_same_past_second 
	- 0.1378 * parameters.avg_latency_of_same_last_20 
	- 0.1046 * parameters.max_latency_of_same_last_50 
	- 293920925.1034;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM99(work_wait &parameters) {
  double actual_remaining = 
	0.0069 * parameters.work_so_far 
	+ 0.1676 * parameters.wait_so_far 
	+ 2010650.0344 * parameters.num_locks_so_far 
	- 59312.2711 * parameters.total_wait_locks 
	+ 0.4083 * parameters.mean_wait_of_all 
	+ 85395989.9857 * parameters.cpu_usage 
	- 0.2388 * parameters.avg_work_of_same_past_second 
	+ 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.017 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	- 80513172.1011;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM100(work_wait &parameters) {
  double actual_remaining = 
	0.0273 * parameters.work_so_far 
	+ 0.0521 * parameters.wait_so_far 
	+ 534589.8554 * parameters.num_locks_so_far 
	- 95990.3549 * parameters.total_wait_locks 
	+ 0.5214 * parameters.mean_wait_of_all 
	- 6449629.8716 * parameters.cpu_usage 
	+ 0.0003 * parameters.avg_wait_of_same_past_second 
	- 0.0011 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 28809602.0443;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM101(work_wait &parameters) {
  double actual_remaining = 
	0.0273 * parameters.work_so_far 
	+ 0.0739 * parameters.wait_so_far 
	+ 6428284.5443 * parameters.num_locks_so_far 
	- 6092.6683 * parameters.total_wait_locks 
	+ 0.0368 * parameters.mean_wait_of_all 
	- 6449629.8716 * parameters.cpu_usage 
	+ 0.0003 * parameters.avg_wait_of_same_past_second 
	- 0.0011 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 54049906.2074;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM102(work_wait &parameters) {
  double actual_remaining = 
	1.1306 * parameters.work_so_far 
	+ 0.0518 * parameters.wait_so_far 
	+ 4945479.0375 * parameters.num_locks_so_far 
	- 986722.3797 * parameters.total_wait_locks 
	+ 1.4817 * parameters.mean_wait_of_all 
	- 22855484.4963 * parameters.cpu_usage 
	+ 13.3527 * parameters.avg_work_of_same_past_second 
	- 0.0945 * parameters.avg_wait_of_same_past_second 
	- 0.0037 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 127794589.7139;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM103(work_wait &parameters) {
  double actual_remaining = 
	0.7623 * parameters.work_so_far 
	+ 7.6953 * parameters.wait_so_far 
	+ 4945479.0375 * parameters.num_locks_so_far 
	- 822206.084 * parameters.total_wait_locks 
	+ 1.4817 * parameters.mean_wait_of_all 
	- 22855484.4963 * parameters.cpu_usage 
	+ 10.5203 * parameters.avg_work_of_same_past_second 
	- 0.0945 * parameters.avg_wait_of_same_past_second 
	- 0.0037 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 114713433.2844;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM104(work_wait &parameters) {
  double actual_remaining = 
	0.1537 * parameters.work_so_far 
	+ 0.0518 * parameters.wait_so_far 
	+ 9698363.7874 * parameters.num_locks_so_far 
	- 128872.396 * parameters.total_wait_locks 
	+ 0.9036 * parameters.mean_wait_of_all 
	- 22855484.4963 * parameters.cpu_usage 
	- 0.0561 * parameters.avg_wait_of_same_past_second 
	- 0.0037 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 5507273.5221;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM105(work_wait &parameters) {
  double actual_remaining = 
	-0.0219 * parameters.work_so_far 
	+ 0.0209 * parameters.wait_so_far 
	+ 695884.6035 * parameters.num_locks_so_far 
	+ 2546.981 * parameters.total_wait_locks 
	- 0.0124 * parameters.mean_wait_of_all 
	+ 0.0107 * parameters.avg_wait_of_same_past_second 
	- 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0025 * parameters.max_latency_of_same_last_50 
	+ 42373679.4855;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM106(work_wait &parameters) {
  double actual_remaining = 
	-0.2599 * parameters.work_so_far 
	+ 0.0209 * parameters.wait_so_far 
	+ 695884.6035 * parameters.num_locks_so_far 
	+ 2546.981 * parameters.total_wait_locks 
	- 0.0124 * parameters.mean_wait_of_all 
	+ 0.0789 * parameters.avg_wait_of_same_past_second 
	- 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0214 * parameters.max_latency_of_same_last_50 
	+ 74747774.5701;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM107(work_wait &parameters) {
  double actual_remaining = 
	1.1548 * parameters.work_so_far 
	+ 0.8711 * parameters.wait_so_far 
	+ 1681049.1619 * parameters.num_locks_so_far 
	+ 5213.5264 * parameters.total_wait_locks 
	- 0.0283 * parameters.mean_wait_of_all 
	+ 0.0075 * parameters.avg_wait_of_same_past_second 
	- 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0017 * parameters.max_latency_of_same_last_50 
	+ 17956137.4418;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM108(work_wait &parameters) {
  double actual_remaining = 
	-0.8465 * parameters.work_so_far 
	+ 0.4367 * parameters.wait_so_far 
	+ 817780.1444 * parameters.num_locks_so_far 
	+ 2692.9623 * parameters.total_wait_locks 
	- 0.0107 * parameters.mean_wait_of_all 
	+ 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 4983001.0446;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM109(work_wait &parameters) {
  double actual_remaining = 
	1.2631 * parameters.work_so_far 
	+ 0.9813 * parameters.wait_so_far 
	+ 1086918.6575 * parameters.num_locks_so_far 
	+ 2692.9623 * parameters.total_wait_locks 
	- 0.0107 * parameters.mean_wait_of_all 
	+ 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0381 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 11824977.2536;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM110(work_wait &parameters) {
  double actual_remaining = 
	-0.0114 * parameters.work_so_far 
	+ 0.0968 * parameters.wait_so_far 
	+ 3128616.5141 * parameters.num_locks_so_far 
	+ 445942.9003 * parameters.total_wait_locks 
	- 1.9168 * parameters.mean_wait_of_all 
	+ 0.3135 * parameters.avg_wait_of_same_past_second 
	- 0.5581 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 511253287.5293;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM111(work_wait &parameters) {
  double actual_remaining = 
	0.8784 * parameters.work_so_far 
	+ 0.9689 * parameters.wait_so_far 
	+ 3352816.5484 * parameters.num_locks_so_far 
	+ 12275.8757 * parameters.total_wait_locks 
	- 0.0154 * parameters.mean_wait_of_all 
	+ 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.0235 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 4453002.5505;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM112(work_wait &parameters) {
  double actual_remaining = 
	-0.0114 * parameters.work_so_far 
	+ 0.9589 * parameters.wait_so_far 
	+ 39163321.461 * parameters.num_locks_so_far 
	+ 3880.7198 * parameters.total_wait_locks 
	- 0.0154 * parameters.mean_wait_of_all 
	+ 4.0501 * parameters.avg_work_of_same_past_second 
	- 0.546 * parameters.avg_wait_of_same_past_second 
	- 0.0227 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 142359088.6859;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
payment_estimate(work_wait &parameters){

  if (parameters.work_so_far <= 257541) {

    if (parameters.mean_wait_of_all <= 139356000) {

      if (parameters.work_so_far <= 21767) {

        if (parameters.work_so_far <= 9511.5) {

          if (parameters.wait_so_far <= 19913676.5) {
            return payment_LM1(parameters);
          } else {

            if (parameters.max_latency_of_same_last_50 <= 118412500) {
              return payment_LM2(parameters);
            } else {

              if (parameters.total_wait_locks <= 64.5) {
                return payment_LM3(parameters);
              } else {

                if (parameters.avg_latency_of_same_last_20 <= 39585950) {
                  return payment_LM4(parameters);
                } else {
                  return payment_LM5(parameters);
                }
              }
            }
          }
        } else {

          if (parameters.cpu_usage <= 0.924) {

            if (parameters.avg_wait_of_same_past_second <= 41967850) {

              if (parameters.max_latency_of_same_last_50 <= 404288500) {

                if (parameters.max_latency_of_same_last_50 <= 326252000) {

                  if (parameters.max_latency_of_same_last_50 <= 256527000) {

                    if (parameters.avg_latency_of_same_last_20 <= 55350200) {

                      if (parameters.total_wait_locks <= 59.5) {

                        if (parameters.total_wait_locks <= 41) {
                          return payment_LM6(parameters);
                        } else {
                          return payment_LM7(parameters);
                        }
                      } else {
                        return payment_LM8(parameters);
                      }
                    } else {
                      return payment_LM9(parameters);
                    }
                  } else {
                    return payment_LM10(parameters);
                  }
                } else {

                  if (parameters.work_so_far <= 11526.5) {
                    return payment_LM11(parameters);
                  } else {

                    if (parameters.max_latency_of_same_last_50 <= 362168000) {
                      return payment_LM12(parameters);
                    } else {
                      return payment_LM13(parameters);
                    }
                  }
                }
              } else {

                if (parameters.cpu_usage <= 0.898) {

                  if (parameters.total_wait_locks <= 242.5) {
                    return payment_LM14(parameters);
                  } else {
                    return payment_LM15(parameters);
                  }
                } else {
                  return payment_LM16(parameters);
                }
              }
            } else {

              if (parameters.cpu_usage <= 0.907) {

                if (parameters.mean_wait_of_all <= 63769500) {

                  if (parameters.avg_wait_of_same_past_second <= 56844450) {
                    return payment_LM17(parameters);
                  } else {
                    return payment_LM18(parameters);
                  }
                } else {

                  if (parameters.total_wait_locks <= 142) {
                    return payment_LM19(parameters);
                  } else {
                    return payment_LM20(parameters);
                  }
                }
              } else {

                if (parameters.wait_so_far <= 9458919.5) {
                  return payment_LM21(parameters);
                } else {

                  if (parameters.mean_wait_of_all <= 61589500) {
                    return payment_LM22(parameters);
                  } else {

                    if (parameters.mean_wait_of_all <= 106381000) {

                      if (parameters.mean_wait_of_all <= 64460000) {

                        if (parameters.work_so_far <= 13485.5) {
                          return payment_LM23(parameters);
                        } else {
                          return payment_LM24(parameters);
                        }
                      } else {

                        if (parameters.mean_wait_of_all <= 64561300) {
                          return payment_LM25(parameters);
                        } else {
                          return payment_LM26(parameters);
                        }
                      }
                    } else {
                      return payment_LM27(parameters);
                    }
                  }
                }
              }
            }
          } else {

            if (parameters.max_latency_of_same_last_50 <= 439262500) {
              return payment_LM28(parameters);
            } else {

              if (parameters.avg_latency_of_same_last_20 <= 174537500) {

                if (parameters.max_latency_of_same_last_50 <= 595619500) {
                  return payment_LM29(parameters);
                } else {
                  return payment_LM30(parameters);
                }
              } else {

                if (parameters.avg_work_of_same_past_second <= 17364950) {

                  if (parameters.total_wait_locks <= 207.5) {
                    return payment_LM31(parameters);
                  } else {

                    if (parameters.avg_latency_of_same_last_20 <= 312844000) {

                      if (parameters.cpu_usage <= 0.992) {

                        if (parameters.avg_latency_of_same_last_20 <= 263874500) {

                          if (parameters.avg_latency_of_same_last_20 <= 190672000) {
                            return payment_LM32(parameters);
                          } else {
                            return payment_LM33(parameters);
                          }
                        } else {
                          return payment_LM34(parameters);
                        }
                      } else {
                        return payment_LM35(parameters);
                      }
                    } else {

                      if (parameters.total_wait_locks <= 310.5) {
                        return payment_LM36(parameters);
                      } else {
                        return payment_LM37(parameters);
                      }
                    }
                  }
                } else {
                  return payment_LM38(parameters);
                }
              }
            }
          }
        }
      } else {

        if (parameters.avg_latency_of_same_last_20 <= 471427500) {

          if (parameters.wait_so_far <= 238506272) {

            if (parameters.work_so_far <= 37398.5) {

              if (parameters.avg_work_of_same_past_second <= 22960250) {
                return payment_LM39(parameters);
              } else {

                if (parameters.wait_so_far <= 23851) {

                  if (parameters.wait_so_far <= 9266.5) {
                    return payment_LM40(parameters);
                  } else {

                    if (parameters.avg_work_of_same_past_second <= 26197550) {
                      return payment_LM41(parameters);
                    } else {

                      if (parameters.avg_work_of_same_past_second <= 27195850) {

                        if (parameters.max_latency_of_same_last_50 <= 1084585000) {

                          if (parameters.avg_latency_of_same_last_20 <= 340358500) {
                            return payment_LM42(parameters);
                          } else {

                            if (parameters.work_so_far <= 31252.5) {

                              if (parameters.cpu_usage <= 0.995) {

                                if (parameters.avg_latency_of_same_last_20 <= 379108000) {
                                  return payment_LM43(parameters);
                                } else {
                                  return payment_LM44(parameters);
                                }
                              } else {
                                return payment_LM45(parameters);
                              }
                            } else {
                              return payment_LM46(parameters);
                            }
                          }
                        } else {
                          return payment_LM47(parameters);
                        }
                      } else {
                        return payment_LM48(parameters);
                      }
                    }
                  }
                } else {
                  return payment_LM49(parameters);
                }
              }
            } else {

              if (parameters.cpu_usage <= 0.984) {

                if (parameters.avg_work_of_same_past_second <= 24748400) {
                  return payment_LM50(parameters);
                } else {

                  if (parameters.mean_wait_of_all <= 85100300) {

                    if (parameters.avg_work_of_same_past_second <= 37519950) {

                      if (parameters.mean_wait_of_all <= 61291350) {
                        return payment_LM51(parameters);
                      } else {

                        if (parameters.avg_wait_of_same_past_second <= 328839500) {

                          if (parameters.avg_work_of_same_past_second <= 28381950) {
                            return payment_LM52(parameters);
                          } else {
                            return payment_LM53(parameters);
                          }
                        } else {
                          return payment_LM54(parameters);
                        }
                      }
                    } else {
                      return payment_LM55(parameters);
                    }
                  } else {
                    return payment_LM56(parameters);
                  }
                }
              } else {
                return payment_LM57(parameters);
              }
            }
          } else {
            return payment_LM58(parameters);
          }
        } else {

          if (parameters.mean_wait_of_all <= 92966800) {

            if (parameters.max_latency_of_same_last_50 <= 1173615000) {

              if (parameters.avg_latency_of_same_last_20 <= 553230500) {
                return payment_LM59(parameters);
              } else {

                if (parameters.avg_latency_of_same_last_20 <= 569752000) {
                  return payment_LM60(parameters);
                } else {
                  return payment_LM61(parameters);
                }
              }
            } else {

              if (parameters.avg_work_of_same_past_second <= 21016100) {
                return payment_LM62(parameters);
              } else {
                return payment_LM63(parameters);
              }
            }
          } else {

            if (parameters.mean_wait_of_all <= 121479000) {

              if (parameters.work_so_far <= 29894.5) {
                return payment_LM64(parameters);
              } else {

                if (parameters.avg_latency_of_same_last_20 <= 619224500) {

                  if (parameters.max_latency_of_same_last_50 <= 1208505000) {
                    return payment_LM65(parameters);
                  } else {

                    if (parameters.wait_so_far <= 214157016.5) {

                      if (parameters.mean_wait_of_all <= 101315000) {

                        if (parameters.avg_wait_of_same_past_second <= 487906000) {
                          return payment_LM66(parameters);
                        } else {

                          if (parameters.mean_wait_of_all <= 100357000) {
                            return payment_LM67(parameters);
                          } else {
                            return payment_LM68(parameters);
                          }
                        }
                      } else {
                        return payment_LM69(parameters);
                      }
                    } else {

                      if (parameters.max_latency_of_same_last_50 <= 1428535000) {
                        return payment_LM70(parameters);
                      } else {
                        return payment_LM71(parameters);
                      }
                    }
                  }
                } else {

                  if (parameters.work_so_far <= 67225.5) {
                    return payment_LM72(parameters);
                  } else {

                    if (parameters.avg_wait_of_same_past_second <= 333046500) {
                      return payment_LM73(parameters);
                    } else {

                      if (parameters.avg_work_of_same_past_second <= 25949500) {
                        return payment_LM74(parameters);
                      } else {

                        if (parameters.avg_latency_of_same_last_20 <= 1130305000) {
                          return payment_LM75(parameters);
                        } else {
                          return payment_LM76(parameters);
                        }
                      }
                    }
                  }
                }
              }
            } else {

              if (parameters.max_latency_of_same_last_50 <= 1538050000) {
                return payment_LM77(parameters);
              } else {

                if (parameters.mean_wait_of_all <= 136101000) {
                  return payment_LM78(parameters);
                } else {
                  return payment_LM79(parameters);
                }
              }
            }
          }
        }
      }
    } else {

      if (parameters.avg_wait_of_same_past_second <= 496532000) {
        return payment_LM80(parameters);
      } else {

        if (parameters.max_latency_of_same_last_50 <= 1451905000) {
          return payment_LM81(parameters);
        } else {

          if (parameters.mean_wait_of_all <= 145758000) {

            if (parameters.mean_wait_of_all <= 144387500) {

              if (parameters.avg_work_of_same_past_second <= 42843300) {

                if (parameters.work_so_far <= 54527) {

                  if (parameters.mean_wait_of_all <= 143609500) {
                    return payment_LM82(parameters);
                  } else {

                    if (parameters.mean_wait_of_all <= 143748000) {
                      return payment_LM83(parameters);
                    } else {
                      return payment_LM84(parameters);
                    }
                  }
                } else {
                  return payment_LM85(parameters);
                }
              } else {
                return payment_LM86(parameters);
              }
            } else {
              return payment_LM87(parameters);
            }
          } else {
            return payment_LM88(parameters);
          }
        }
      }
    }
  } else {

    if (parameters.wait_so_far <= 229531651.5) {

      if (parameters.wait_so_far <= 94143464) {

        if (parameters.work_so_far <= 11271119.5) {

          if (parameters.max_latency_of_same_last_50 <= 1269635000) {

            if (parameters.wait_so_far <= 31489464) {
              return payment_LM89(parameters);
            } else {

              if (parameters.num_locks_so_far <= 3) {
                return payment_LM90(parameters);
              } else {
                return payment_LM91(parameters);
              }
            }
          } else {

            if (parameters.max_latency_of_same_last_50 <= 1381170000) {

              if (parameters.total_wait_locks <= 640) {
                return payment_LM92(parameters);
              } else {

                if (parameters.work_so_far <= 979430) {
                  return payment_LM93(parameters);
                } else {

                  if (parameters.cpu_usage <= 0.991) {

                    if (parameters.avg_work_of_same_past_second <= 26479500) {
                      return payment_LM94(parameters);
                    } else {

                      if (parameters.total_wait_locks <= 756) {
                        return payment_LM95(parameters);
                      } else {
                        return payment_LM96(parameters);
                      }
                    }
                  } else {

                    if (parameters.avg_latency_of_same_last_20 <= 385934500) {
                      return payment_LM97(parameters);
                    } else {
                      return payment_LM98(parameters);
                    }
                  }
                }
              }
            } else {
              return payment_LM99(parameters);
            }
          }
        } else {

          if (parameters.work_so_far <= 72249291.5) {

            if (parameters.wait_so_far <= 26744091) {
              return payment_LM100(parameters);
            } else {
              return payment_LM101(parameters);
            }
          } else {

            if (parameters.avg_work_of_same_past_second <= 13487950) {

              if (parameters.wait_so_far <= 1980.5) {
                return payment_LM102(parameters);
              } else {
                return payment_LM103(parameters);
              }
            } else {
              return payment_LM104(parameters);
            }
          }
        }
      } else {

        if (parameters.num_locks_so_far <= 2.5) {

          if (parameters.work_so_far <= 889284.5) {
            return payment_LM105(parameters);
          } else {
            return payment_LM106(parameters);
          }
        } else {
          return payment_LM107(parameters);
        }
      }
    } else {

      if (parameters.wait_so_far <= 571613877.5) {

        if (parameters.num_locks_so_far <= 2.5) {
          return payment_LM108(parameters);
        } else {
          return payment_LM109(parameters);
        }
      } else {

        if (parameters.wait_so_far <= 947605267.5) {

          if (parameters.num_locks_so_far <= 2.5) {
            return payment_LM110(parameters);
          } else {
            return payment_LM111(parameters);
          }
        } else {
          return payment_LM112(parameters);
        }
      }
    }
  }
}
static
double
stock_level_LM1(work_wait &parameters) {
  double actual_remaining = 
	+ 61880880.7442;
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
	34.0432 * parameters.work_so_far 
	+ 0.001 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 2006.9319 * parameters.total_wait_locks 
	- 0.0043 * parameters.mean_wait_of_all 
	- 147134.1897 * parameters.cpu_usage 
	+ 0.013 * parameters.avg_work_of_same_past_second 
	- 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 7099776.5891;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM2(work_wait &parameters) {
  double actual_remaining = 
	24.6877 * parameters.work_so_far 
	+ 0.0008 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 1755.7042 * parameters.total_wait_locks 
	- 0.0037 * parameters.mean_wait_of_all 
	- 147134.1897 * parameters.cpu_usage 
	+ 0.0131 * parameters.avg_work_of_same_past_second 
	- 0.0006 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 11174363.4359;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM3(work_wait &parameters) {
  double actual_remaining = 
	189.5937 * parameters.work_so_far 
	+ 0.0008 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 44120.598 * parameters.total_wait_locks 
	- 0.012 * parameters.mean_wait_of_all 
	- 136449637.9475 * parameters.cpu_usage 
	+ 0.176 * parameters.avg_work_of_same_past_second 
	- 0.0035 * parameters.avg_wait_of_same_past_second 
	+ 0.1037 * parameters.avg_latency_of_same_last_20 
	- 0.0061 * parameters.max_latency_of_same_last_50 
	+ 132898339.8681;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM4(work_wait &parameters) {
  double actual_remaining = 
	6560.8786 * parameters.work_so_far 
	+ 0.0008 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 4330.0975 * parameters.total_wait_locks 
	- 0.012 * parameters.mean_wait_of_all 
	- 1543816.9197 * parameters.cpu_usage 
	+ 2.7936 * parameters.avg_work_of_same_past_second 
	- 0.2205 * parameters.avg_wait_of_same_past_second 
	+ 0.0187 * parameters.avg_latency_of_same_last_20 
	- 0.8631 * parameters.max_latency_of_same_last_50 
	+ 70230817.5867;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM5(work_wait &parameters) {
  double actual_remaining = 
	4295.3077 * parameters.work_so_far 
	+ 0.0008 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 4330.0975 * parameters.total_wait_locks 
	- 0.012 * parameters.mean_wait_of_all 
	- 1543816.9197 * parameters.cpu_usage 
	+ 0.8121 * parameters.avg_work_of_same_past_second 
	- 0.2928 * parameters.avg_wait_of_same_past_second 
	+ 0.0187 * parameters.avg_latency_of_same_last_20 
	- 0.588 * parameters.max_latency_of_same_last_50 
	+ 90224738.1811;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM6(work_wait &parameters) {
  double actual_remaining = 
	519.1513 * parameters.work_so_far 
	+ 0.0008 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 4330.0975 * parameters.total_wait_locks 
	- 0.012 * parameters.mean_wait_of_all 
	- 1543816.9197 * parameters.cpu_usage 
	+ 0.6564 * parameters.avg_work_of_same_past_second 
	- 0.0035 * parameters.avg_wait_of_same_past_second 
	+ 0.0187 * parameters.avg_latency_of_same_last_20 
	- 0.0069 * parameters.max_latency_of_same_last_50 
	- 3192983.4399;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM7(work_wait &parameters) {
  double actual_remaining = 
	519.1513 * parameters.work_so_far 
	+ 0.0008 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 4330.0975 * parameters.total_wait_locks 
	- 0.012 * parameters.mean_wait_of_all 
	- 1543816.9197 * parameters.cpu_usage 
	+ 5.1327 * parameters.avg_work_of_same_past_second 
	- 0.0035 * parameters.avg_wait_of_same_past_second 
	+ 0.0187 * parameters.avg_latency_of_same_last_20 
	+ 0.0066 * parameters.max_latency_of_same_last_50 
	- 92751327.7128;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM8(work_wait &parameters) {
  double actual_remaining = 
	236.6735 * parameters.work_so_far 
	+ 0.0008 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 4330.0975 * parameters.total_wait_locks 
	- 0.012 * parameters.mean_wait_of_all 
	- 1543816.9197 * parameters.cpu_usage 
	+ 0.2117 * parameters.avg_work_of_same_past_second 
	- 0.0095 * parameters.avg_wait_of_same_past_second 
	+ 0.0126 * parameters.avg_latency_of_same_last_20 
	- 0.0063 * parameters.max_latency_of_same_last_50 
	+ 8479729.2745;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM9(work_wait &parameters) {
  double actual_remaining = 
	68.2377 * parameters.work_so_far 
	+ 0.0008 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 5132.625 * parameters.total_wait_locks 
	- 0.0147 * parameters.mean_wait_of_all 
	- 2007846.3794 * parameters.cpu_usage 
	+ 0.0428 * parameters.avg_work_of_same_past_second 
	- 0.0007 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	+ 14356077.5936;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM10(work_wait &parameters) {
  double actual_remaining = 
	0.4952 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 48849.7844 * parameters.total_wait_locks 
	- 0.0077 * parameters.mean_wait_of_all 
	- 18384900.126 * parameters.cpu_usage 
	+ 0.002 * parameters.avg_work_of_same_past_second 
	- 0.0013 * parameters.avg_wait_of_same_past_second 
	+ 0.0196 * parameters.avg_latency_of_same_last_20 
	- 0.0084 * parameters.max_latency_of_same_last_50 
	+ 31698757.3995;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM11(work_wait &parameters) {
  double actual_remaining = 
	0.4952 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 6963.1496 * parameters.total_wait_locks 
	- 0.06 * parameters.mean_wait_of_all 
	- 118318.8744 * parameters.cpu_usage 
	- 0.0442 * parameters.avg_work_of_same_past_second 
	- 0.0031 * parameters.avg_wait_of_same_past_second 
	+ 0.0504 * parameters.avg_latency_of_same_last_20 
	- 0.0143 * parameters.max_latency_of_same_last_50 
	+ 23917995.9791;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM12(work_wait &parameters) {
  double actual_remaining = 
	0.4952 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 6963.1496 * parameters.total_wait_locks 
	- 0.06 * parameters.mean_wait_of_all 
	- 118318.8744 * parameters.cpu_usage 
	- 0.0442 * parameters.avg_work_of_same_past_second 
	- 0.0031 * parameters.avg_wait_of_same_past_second 
	+ 0.0504 * parameters.avg_latency_of_same_last_20 
	- 0.0143 * parameters.max_latency_of_same_last_50 
	+ 24315079.3408;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM13(work_wait &parameters) {
  double actual_remaining = 
	-4706.2074 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 6963.1496 * parameters.total_wait_locks 
	+ 0.5401 * parameters.mean_wait_of_all 
	- 118318.8744 * parameters.cpu_usage 
	- 0.0442 * parameters.avg_work_of_same_past_second 
	- 0.0031 * parameters.avg_wait_of_same_past_second 
	+ 0.0504 * parameters.avg_latency_of_same_last_20 
	- 0.0143 * parameters.max_latency_of_same_last_50 
	+ 96149431.6425;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM14(work_wait &parameters) {
  double actual_remaining = 
	-5886.4738 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 6963.1496 * parameters.total_wait_locks 
	+ 0.5401 * parameters.mean_wait_of_all 
	- 118318.8744 * parameters.cpu_usage 
	- 0.0442 * parameters.avg_work_of_same_past_second 
	- 0.0031 * parameters.avg_wait_of_same_past_second 
	+ 0.0504 * parameters.avg_latency_of_same_last_20 
	- 0.0143 * parameters.max_latency_of_same_last_50 
	+ 122712838.4678;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM15(work_wait &parameters) {
  double actual_remaining = 
	0.4952 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 6963.1496 * parameters.total_wait_locks 
	- 0.06 * parameters.mean_wait_of_all 
	- 118318.8744 * parameters.cpu_usage 
	- 0.0442 * parameters.avg_work_of_same_past_second 
	- 0.0031 * parameters.avg_wait_of_same_past_second 
	+ 0.0794 * parameters.avg_latency_of_same_last_20 
	- 0.0143 * parameters.max_latency_of_same_last_50 
	+ 25937890.7993;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM16(work_wait &parameters) {
  double actual_remaining = 
	0.4952 * parameters.work_so_far 
	+ 0.0656 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 6963.1496 * parameters.total_wait_locks 
	+ 0.7056 * parameters.mean_wait_of_all 
	- 118318.8744 * parameters.cpu_usage 
	- 0.0442 * parameters.avg_work_of_same_past_second 
	- 0.0031 * parameters.avg_wait_of_same_past_second 
	+ 0.0654 * parameters.avg_latency_of_same_last_20 
	- 0.0593 * parameters.max_latency_of_same_last_50 
	+ 40401777.9563;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM17(work_wait &parameters) {
  double actual_remaining = 
	0.4952 * parameters.work_so_far 
	+ 0.069 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 6963.1496 * parameters.total_wait_locks 
	+ 0.5078 * parameters.mean_wait_of_all 
	- 118318.8744 * parameters.cpu_usage 
	- 0.0442 * parameters.avg_work_of_same_past_second 
	- 0.0031 * parameters.avg_wait_of_same_past_second 
	+ 0.0654 * parameters.avg_latency_of_same_last_20 
	- 0.0593 * parameters.max_latency_of_same_last_50 
	+ 52264737.9978;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM18(work_wait &parameters) {
  double actual_remaining = 
	0.4952 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 6963.1496 * parameters.total_wait_locks 
	- 0.06 * parameters.mean_wait_of_all 
	- 118318.8744 * parameters.cpu_usage 
	- 0.0442 * parameters.avg_work_of_same_past_second 
	- 0.0031 * parameters.avg_wait_of_same_past_second 
	+ 0.1288 * parameters.avg_latency_of_same_last_20 
	- 0.0406 * parameters.max_latency_of_same_last_50 
	+ 30353140.3775;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM19(work_wait &parameters) {
  double actual_remaining = 
	0.4952 * parameters.work_so_far 
	+ 0.1331 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 6963.1496 * parameters.total_wait_locks 
	- 0.06 * parameters.mean_wait_of_all 
	- 118318.8744 * parameters.cpu_usage 
	- 0.0442 * parameters.avg_work_of_same_past_second 
	- 0.0031 * parameters.avg_wait_of_same_past_second 
	+ 0.1005 * parameters.avg_latency_of_same_last_20 
	- 0.0406 * parameters.max_latency_of_same_last_50 
	+ 43861689.0456;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM20(work_wait &parameters) {
  double actual_remaining = 
	0.4952 * parameters.work_so_far 
	+ 0.0806 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 6963.1496 * parameters.total_wait_locks 
	- 0.06 * parameters.mean_wait_of_all 
	- 118318.8744 * parameters.cpu_usage 
	- 0.0442 * parameters.avg_work_of_same_past_second 
	- 0.0031 * parameters.avg_wait_of_same_past_second 
	+ 0.1005 * parameters.avg_latency_of_same_last_20 
	- 0.0406 * parameters.max_latency_of_same_last_50 
	+ 46251792.1364;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM21(work_wait &parameters) {
  double actual_remaining = 
	0.4952 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 6963.1496 * parameters.total_wait_locks 
	- 0.06 * parameters.mean_wait_of_all 
	- 118318.8744 * parameters.cpu_usage 
	- 0.0442 * parameters.avg_work_of_same_past_second 
	- 0.0031 * parameters.avg_wait_of_same_past_second 
	+ 0.1005 * parameters.avg_latency_of_same_last_20 
	- 0.0406 * parameters.max_latency_of_same_last_50 
	+ 43268513.2217;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM22(work_wait &parameters) {
  double actual_remaining = 
	0.4952 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 6963.1496 * parameters.total_wait_locks 
	- 0.0901 * parameters.mean_wait_of_all 
	- 118318.8744 * parameters.cpu_usage 
	- 0.0442 * parameters.avg_work_of_same_past_second 
	- 0.0031 * parameters.avg_wait_of_same_past_second 
	+ 0.0334 * parameters.avg_latency_of_same_last_20 
	- 0.01 * parameters.max_latency_of_same_last_50 
	+ 22947628.8661;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM23(work_wait &parameters) {
  double actual_remaining = 
	0.4952 * parameters.work_so_far 
	- 0.5057 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 6963.1496 * parameters.total_wait_locks 
	- 2.8976 * parameters.mean_wait_of_all 
	- 118318.8744 * parameters.cpu_usage 
	- 0.0442 * parameters.avg_work_of_same_past_second 
	- 0.0031 * parameters.avg_wait_of_same_past_second 
	+ 0.0261 * parameters.avg_latency_of_same_last_20 
	- 0.0085 * parameters.max_latency_of_same_last_50 
	+ 240730571.4699;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM24(work_wait &parameters) {
  double actual_remaining = 
	0.4952 * parameters.work_so_far 
	+ 0.0432 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 6963.1496 * parameters.total_wait_locks 
	- 0.4824 * parameters.mean_wait_of_all 
	- 118318.8744 * parameters.cpu_usage 
	- 0.0442 * parameters.avg_work_of_same_past_second 
	- 0.0031 * parameters.avg_wait_of_same_past_second 
	+ 0.0261 * parameters.avg_latency_of_same_last_20 
	- 0.0085 * parameters.max_latency_of_same_last_50 
	+ 54905965.6558;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM25(work_wait &parameters) {
  double actual_remaining = 
	0.4952 * parameters.work_so_far 
	+ 0.2139 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 6963.1496 * parameters.total_wait_locks 
	- 0.0048 * parameters.mean_wait_of_all 
	- 118318.8744 * parameters.cpu_usage 
	- 0.0442 * parameters.avg_work_of_same_past_second 
	- 0.0031 * parameters.avg_wait_of_same_past_second 
	+ 0.0261 * parameters.avg_latency_of_same_last_20 
	- 0.0085 * parameters.max_latency_of_same_last_50 
	+ 30698731.1859;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM26(work_wait &parameters) {
  double actual_remaining = 
	0.4952 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 62351.2441 * parameters.total_wait_locks 
	- 0.0048 * parameters.mean_wait_of_all 
	- 118318.8744 * parameters.cpu_usage 
	- 0.0169 * parameters.avg_work_of_same_past_second 
	- 0.0017 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 9785410.1914;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM27(work_wait &parameters) {
  double actual_remaining = 
	1.9662 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 2968.842 * parameters.total_wait_locks 
	- 0.0048 * parameters.mean_wait_of_all 
	- 118318.8744 * parameters.cpu_usage 
	- 0.0132 * parameters.avg_work_of_same_past_second 
	- 0.0013 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 19562046.4391;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM28(work_wait &parameters) {
  double actual_remaining = 
	2.7874 * parameters.work_so_far 
	+ 0.5479 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 2968.842 * parameters.total_wait_locks 
	- 0.0048 * parameters.mean_wait_of_all 
	- 118318.8744 * parameters.cpu_usage 
	- 0.0132 * parameters.avg_work_of_same_past_second 
	- 0.0013 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 21832763.3261;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM29(work_wait &parameters) {
  double actual_remaining = 
	2.7874 * parameters.work_so_far 
	+ 4.7338 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 2968.842 * parameters.total_wait_locks 
	+ 0.4924 * parameters.mean_wait_of_all 
	- 118318.8744 * parameters.cpu_usage 
	- 8.4588 * parameters.avg_work_of_same_past_second 
	+ 0.1603 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 153657004.6978;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM30(work_wait &parameters) {
  double actual_remaining = 
	2.7874 * parameters.work_so_far 
	+ 3.0313 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 41442.8638 * parameters.total_wait_locks 
	+ 0.1935 * parameters.mean_wait_of_all 
	- 118318.8744 * parameters.cpu_usage 
	- 9.8617 * parameters.avg_work_of_same_past_second 
	- 0.0469 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 261164529.0339;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM31(work_wait &parameters) {
  double actual_remaining = 
	2.7874 * parameters.work_so_far 
	+ 2.1015 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 2968.842 * parameters.total_wait_locks 
	- 0.0048 * parameters.mean_wait_of_all 
	- 118318.8744 * parameters.cpu_usage 
	- 7.0514 * parameters.avg_work_of_same_past_second 
	- 0.0013 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 196928189.7546;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM32(work_wait &parameters) {
  double actual_remaining = 
	2.7874 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 2968.842 * parameters.total_wait_locks 
	- 0.0667 * parameters.mean_wait_of_all 
	- 118318.8744 * parameters.cpu_usage 
	- 5.8259 * parameters.avg_work_of_same_past_second 
	- 0.0013 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 169097209.6353;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM33(work_wait &parameters) {
  double actual_remaining = 
	2.7874 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 2968.842 * parameters.total_wait_locks 
	- 0.0667 * parameters.mean_wait_of_all 
	- 118318.8744 * parameters.cpu_usage 
	- 12.7386 * parameters.avg_work_of_same_past_second 
	- 0.0013 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 344484176.2679;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM34(work_wait &parameters) {
  double actual_remaining = 
	2.7874 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 2968.842 * parameters.total_wait_locks 
	- 0.028 * parameters.mean_wait_of_all 
	- 118318.8744 * parameters.cpu_usage 
	- 0.0132 * parameters.avg_work_of_same_past_second 
	- 0.0013 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 19522022.0706;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM35(work_wait &parameters) {
  double actual_remaining = 
	0.4952 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 1954.3188 * parameters.total_wait_locks 
	- 0.0057 * parameters.mean_wait_of_all 
	- 118318.8744 * parameters.cpu_usage 
	+ 0.002 * parameters.avg_work_of_same_past_second 
	- 0.0204 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 25244194.9383;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM36(work_wait &parameters) {
  double actual_remaining = 
	0.4952 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 5057.7913 * parameters.total_wait_locks 
	- 0.0189 * parameters.mean_wait_of_all 
	- 118318.8744 * parameters.cpu_usage 
	+ 0.002 * parameters.avg_work_of_same_past_second 
	- 0.0007 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 41911734.1594;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM37(work_wait &parameters) {
  double actual_remaining = 
	0.4952 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 5057.7913 * parameters.total_wait_locks 
	- 0.0189 * parameters.mean_wait_of_all 
	- 118318.8744 * parameters.cpu_usage 
	+ 0.002 * parameters.avg_work_of_same_past_second 
	- 0.0007 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	+ 0.0405 * parameters.max_latency_of_same_last_50 
	+ 16851472.9247;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM38(work_wait &parameters) {
  double actual_remaining = 
	0.4952 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 5057.7913 * parameters.total_wait_locks 
	+ 0.1032 * parameters.mean_wait_of_all 
	- 73555631.9818 * parameters.cpu_usage 
	+ 0.002 * parameters.avg_work_of_same_past_second 
	- 0.0007 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 84180111.3866;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM39(work_wait &parameters) {
  double actual_remaining = 
	0.4952 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 5057.7913 * parameters.total_wait_locks 
	+ 0.1004 * parameters.mean_wait_of_all 
	- 405103226.6276 * parameters.cpu_usage 
	+ 0.002 * parameters.avg_work_of_same_past_second 
	- 0.0007 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 419220302.6497;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM40(work_wait &parameters) {
  double actual_remaining = 
	1543.6354 * parameters.work_so_far 
	+ 0.0208 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	- 36190.6475 * parameters.total_wait_locks 
	+ 0.2704 * parameters.mean_wait_of_all 
	- 118318.8744 * parameters.cpu_usage 
	+ 0.002 * parameters.avg_work_of_same_past_second 
	- 0.0007 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	- 37128091.1409;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM41(work_wait &parameters) {
  double actual_remaining = 
	1348.0261 * parameters.work_so_far 
	+ 0.0182 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	- 290386.4039 * parameters.total_wait_locks 
	+ 2.0039 * parameters.mean_wait_of_all 
	- 118318.8744 * parameters.cpu_usage 
	+ 0.002 * parameters.avg_work_of_same_past_second 
	- 0.0007 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	- 133136984.1282;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM42(work_wait &parameters) {
  double actual_remaining = 
	0.4952 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 5057.7913 * parameters.total_wait_locks 
	- 0.0189 * parameters.mean_wait_of_all 
	- 118318.8744 * parameters.cpu_usage 
	+ 0.002 * parameters.avg_work_of_same_past_second 
	- 0.0007 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 27083219.2423;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM43(work_wait &parameters) {
  double actual_remaining = 
	66.8721 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 75420.2791 * parameters.total_wait_locks 
	- 0.3513 * parameters.mean_wait_of_all 
	- 118318.8744 * parameters.cpu_usage 
	+ 0.002 * parameters.avg_work_of_same_past_second 
	- 0.0007 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 32315510.8119;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM44(work_wait &parameters) {
  double actual_remaining = 
	-376.7902 * parameters.work_so_far 
	+ 0.0335 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 22499.2831 * parameters.total_wait_locks 
	- 0.1168 * parameters.mean_wait_of_all 
	+ 20781546.1541 * parameters.cpu_usage 
	- 0.0493 * parameters.avg_work_of_same_past_second 
	+ 0.0193 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0083 * parameters.max_latency_of_same_last_50 
	+ 23190241.729;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM45(work_wait &parameters) {
  double actual_remaining = 
	-124.4782 * parameters.work_so_far 
	+ 0.0335 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 16194.0082 * parameters.total_wait_locks 
	- 0.1168 * parameters.mean_wait_of_all 
	+ 82185852.7592 * parameters.cpu_usage 
	- 0.0493 * parameters.avg_work_of_same_past_second 
	+ 0.0183 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0054 * parameters.max_latency_of_same_last_50 
	- 41177056.1557;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM46(work_wait &parameters) {
  double actual_remaining = 
	-124.4782 * parameters.work_so_far 
	+ 0.0335 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 13607.2288 * parameters.total_wait_locks 
	- 0.1168 * parameters.mean_wait_of_all 
	+ 114867985.5819 * parameters.cpu_usage 
	- 0.0493 * parameters.avg_work_of_same_past_second 
	+ 0.0221 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0054 * parameters.max_latency_of_same_last_50 
	- 62726275.9521;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM47(work_wait &parameters) {
  double actual_remaining = 
	-124.4782 * parameters.work_so_far 
	+ 0.0565 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 22499.2831 * parameters.total_wait_locks 
	- 0.1168 * parameters.mean_wait_of_all 
	+ 2523154.0036 * parameters.cpu_usage 
	- 0.0493 * parameters.avg_work_of_same_past_second 
	+ 0.0091 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0054 * parameters.max_latency_of_same_last_50 
	+ 41644580.6599;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM48(work_wait &parameters) {
  double actual_remaining = 
	-1328.0061 * parameters.work_so_far 
	+ 0.0565 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 22499.2831 * parameters.total_wait_locks 
	- 0.1168 * parameters.mean_wait_of_all 
	+ 2523154.0036 * parameters.cpu_usage 
	- 3.167 * parameters.avg_work_of_same_past_second 
	+ 0.0091 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0054 * parameters.max_latency_of_same_last_50 
	+ 179631432.2664;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM49(work_wait &parameters) {
  double actual_remaining = 
	-1094.0339 * parameters.work_so_far 
	+ 0.0565 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 22499.2831 * parameters.total_wait_locks 
	- 0.1168 * parameters.mean_wait_of_all 
	+ 2523154.0036 * parameters.cpu_usage 
	- 3.167 * parameters.avg_work_of_same_past_second 
	+ 0.0091 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0054 * parameters.max_latency_of_same_last_50 
	+ 174222183.9787;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM50(work_wait &parameters) {
  double actual_remaining = 
	-1142.5117 * parameters.work_so_far 
	+ 0.0565 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 22499.2831 * parameters.total_wait_locks 
	- 0.1168 * parameters.mean_wait_of_all 
	+ 2523154.0036 * parameters.cpu_usage 
	- 3.3229 * parameters.avg_work_of_same_past_second 
	+ 0.0091 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0054 * parameters.max_latency_of_same_last_50 
	+ 175323805.0074;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM51(work_wait &parameters) {
  double actual_remaining = 
	58.6652 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 188794.4371 * parameters.total_wait_locks 
	- 0.9909 * parameters.mean_wait_of_all 
	- 8961963.6394 * parameters.cpu_usage 
	- 0.0493 * parameters.avg_work_of_same_past_second 
	+ 0.0026 * parameters.avg_wait_of_same_past_second 
	- 0.103 * parameters.avg_latency_of_same_last_20 
	- 0.0064 * parameters.max_latency_of_same_last_50 
	+ 162951038.1163;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM52(work_wait &parameters) {
  double actual_remaining = 
	58.6652 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 243926.4293 * parameters.total_wait_locks 
	- 0.9909 * parameters.mean_wait_of_all 
	- 8961963.6394 * parameters.cpu_usage 
	- 0.0493 * parameters.avg_work_of_same_past_second 
	+ 0.0026 * parameters.avg_wait_of_same_past_second 
	- 0.103 * parameters.avg_latency_of_same_last_20 
	- 0.0064 * parameters.max_latency_of_same_last_50 
	+ 145546960.3902;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM53(work_wait &parameters) {
  double actual_remaining = 
	58.6652 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 250412.546 * parameters.total_wait_locks 
	- 0.9909 * parameters.mean_wait_of_all 
	- 8961963.6394 * parameters.cpu_usage 
	- 0.0493 * parameters.avg_work_of_same_past_second 
	+ 0.0026 * parameters.avg_wait_of_same_past_second 
	- 0.103 * parameters.avg_latency_of_same_last_20 
	- 0.0064 * parameters.max_latency_of_same_last_50 
	+ 145610068.9998;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM54(work_wait &parameters) {
  double actual_remaining = 
	58.6652 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 222542.7637 * parameters.total_wait_locks 
	- 0.9909 * parameters.mean_wait_of_all 
	- 8961963.6394 * parameters.cpu_usage 
	- 0.0493 * parameters.avg_work_of_same_past_second 
	+ 0.0026 * parameters.avg_wait_of_same_past_second 
	- 0.103 * parameters.avg_latency_of_same_last_20 
	- 0.0064 * parameters.max_latency_of_same_last_50 
	+ 121183569.2988;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM55(work_wait &parameters) {
  double actual_remaining = 
	58.6652 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 230642.3621 * parameters.total_wait_locks 
	- 0.9909 * parameters.mean_wait_of_all 
	- 661923835.9635 * parameters.cpu_usage 
	- 0.0493 * parameters.avg_work_of_same_past_second 
	+ 0.0026 * parameters.avg_wait_of_same_past_second 
	- 0.103 * parameters.avg_latency_of_same_last_20 
	- 0.0064 * parameters.max_latency_of_same_last_50 
	+ 728721903.0438;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM56(work_wait &parameters) {
  double actual_remaining = 
	58.6652 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 230642.3621 * parameters.total_wait_locks 
	- 0.9909 * parameters.mean_wait_of_all 
	- 543203495.5409 * parameters.cpu_usage 
	- 0.0493 * parameters.avg_work_of_same_past_second 
	+ 0.0026 * parameters.avg_wait_of_same_past_second 
	- 0.103 * parameters.avg_latency_of_same_last_20 
	- 0.0064 * parameters.max_latency_of_same_last_50 
	+ 615718239.7742;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM57(work_wait &parameters) {
  double actual_remaining = 
	58.6652 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 335684.7854 * parameters.total_wait_locks 
	- 1.7736 * parameters.mean_wait_of_all 
	- 8961963.6394 * parameters.cpu_usage 
	- 0.0493 * parameters.avg_work_of_same_past_second 
	+ 0.0026 * parameters.avg_wait_of_same_past_second 
	- 0.2022 * parameters.avg_latency_of_same_last_20 
	- 0.0064 * parameters.max_latency_of_same_last_50 
	+ 197588699.7766;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM58(work_wait &parameters) {
  double actual_remaining = 
	14.5815 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 22701.6714 * parameters.total_wait_locks 
	- 0.1063 * parameters.mean_wait_of_all 
	- 10515219.48 * parameters.cpu_usage 
	- 0.5122 * parameters.avg_work_of_same_past_second 
	+ 0.0034 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0014 * parameters.max_latency_of_same_last_50 
	+ 45947768.994;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM59(work_wait &parameters) {
  double actual_remaining = 
	14.5815 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 21689.4861 * parameters.total_wait_locks 
	- 0.1035 * parameters.mean_wait_of_all 
	- 10515219.48 * parameters.cpu_usage 
	- 0.466 * parameters.avg_work_of_same_past_second 
	+ 0.0034 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0014 * parameters.max_latency_of_same_last_50 
	+ 51881614.6562;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM60(work_wait &parameters) {
  double actual_remaining = 
	1.3012 * parameters.work_so_far 
	- 0.0012 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	- 36443.0141 * parameters.total_wait_locks 
	+ 0.0019 * parameters.mean_wait_of_all 
	- 712166.8237 * parameters.cpu_usage 
	- 1.7071 * parameters.avg_work_of_same_past_second 
	- 0.0005 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 75316896.3094;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM61(work_wait &parameters) {
  double actual_remaining = 
	1.3012 * parameters.work_so_far 
	- 0.0014 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 115553.3691 * parameters.total_wait_locks 
	- 0.8515 * parameters.mean_wait_of_all 
	+ 3412970.9886 * parameters.cpu_usage 
	- 0.1167 * parameters.avg_work_of_same_past_second 
	+ 0.0005 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	+ 0.0062 * parameters.max_latency_of_same_last_50 
	+ 78488175.2878;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM62(work_wait &parameters) {
  double actual_remaining = 
	1.3012 * parameters.work_so_far 
	+ 5.1403 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 92780.2568 * parameters.total_wait_locks 
	- 6.5008 * parameters.mean_wait_of_all 
	+ 125066131.0075 * parameters.cpu_usage 
	+ 9.3017 * parameters.avg_work_of_same_past_second 
	+ 0.0031 * parameters.avg_wait_of_same_past_second 
	- 0.0144 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 739463284.8353;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM63(work_wait &parameters) {
  double actual_remaining = 
	1.3012 * parameters.work_so_far 
	+ 3.115 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 92780.2568 * parameters.total_wait_locks 
	- 43.5587 * parameters.mean_wait_of_all 
	+ 125066131.0075 * parameters.cpu_usage 
	- 3.0252 * parameters.avg_work_of_same_past_second 
	- 0.2919 * parameters.avg_wait_of_same_past_second 
	- 0.0144 * parameters.avg_latency_of_same_last_20 
	+ 0.0141 * parameters.max_latency_of_same_last_50 
	+ 7471418071.5059;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM64(work_wait &parameters) {
  double actual_remaining = 
	1.3012 * parameters.work_so_far 
	+ 3.115 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 92780.2568 * parameters.total_wait_locks 
	- 19.7181 * parameters.mean_wait_of_all 
	+ 125066131.0075 * parameters.cpu_usage 
	- 3.0252 * parameters.avg_work_of_same_past_second 
	- 0.2125 * parameters.avg_wait_of_same_past_second 
	- 0.0144 * parameters.avg_latency_of_same_last_20 
	+ 0.0103 * parameters.max_latency_of_same_last_50 
	+ 3374447350.2406;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM65(work_wait &parameters) {
  double actual_remaining = 
	1.3012 * parameters.work_so_far 
	- 0.3623 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 92780.2568 * parameters.total_wait_locks 
	- 6.1624 * parameters.mean_wait_of_all 
	+ 125066131.0075 * parameters.cpu_usage 
	- 3.0252 * parameters.avg_work_of_same_past_second 
	+ 0.0031 * parameters.avg_wait_of_same_past_second 
	- 0.0144 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 993959926.5496;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM66(work_wait &parameters) {
  double actual_remaining = 
	1.3012 * parameters.work_so_far 
	- 0.3623 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 92780.2568 * parameters.total_wait_locks 
	- 6.1624 * parameters.mean_wait_of_all 
	+ 125066131.0075 * parameters.cpu_usage 
	- 3.0252 * parameters.avg_work_of_same_past_second 
	+ 0.0031 * parameters.avg_wait_of_same_past_second 
	- 0.0144 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 999407970.1832;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM67(work_wait &parameters) {
  double actual_remaining = 
	4.3773 * parameters.work_so_far 
	- 0.3623 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 92780.2568 * parameters.total_wait_locks 
	- 6.1624 * parameters.mean_wait_of_all 
	+ 125066131.0075 * parameters.cpu_usage 
	- 3.0252 * parameters.avg_work_of_same_past_second 
	+ 0.0031 * parameters.avg_wait_of_same_past_second 
	- 0.0144 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 997968659.2542;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM68(work_wait &parameters) {
  double actual_remaining = 
	4.5583 * parameters.work_so_far 
	- 0.3623 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 92780.2568 * parameters.total_wait_locks 
	- 6.1624 * parameters.mean_wait_of_all 
	+ 125066131.0075 * parameters.cpu_usage 
	- 3.0252 * parameters.avg_work_of_same_past_second 
	+ 0.0031 * parameters.avg_wait_of_same_past_second 
	- 0.0144 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 998052557.7104;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM69(work_wait &parameters) {
  double actual_remaining = 
	1.3012 * parameters.work_so_far 
	- 0.3623 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 92780.2568 * parameters.total_wait_locks 
	- 6.1624 * parameters.mean_wait_of_all 
	+ 125066131.0075 * parameters.cpu_usage 
	- 3.0252 * parameters.avg_work_of_same_past_second 
	+ 0.0031 * parameters.avg_wait_of_same_past_second 
	- 0.0144 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 997401893.1188;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM70(work_wait &parameters) {
  double actual_remaining = 
	1.3012 * parameters.work_so_far 
	- 0.267 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 92780.2568 * parameters.total_wait_locks 
	- 4.7004 * parameters.mean_wait_of_all 
	+ 125066131.0075 * parameters.cpu_usage 
	- 4.4031 * parameters.avg_work_of_same_past_second 
	+ 0.0031 * parameters.avg_wait_of_same_past_second 
	- 0.0144 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 776666569.5674;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM71(work_wait &parameters) {
  double actual_remaining = 
	1.3012 * parameters.work_so_far 
	- 0.0631 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 282101.053 * parameters.total_wait_locks 
	- 3.7494 * parameters.mean_wait_of_all 
	+ 275308447.008 * parameters.cpu_usage 
	- 4.1959 * parameters.avg_work_of_same_past_second 
	+ 0.0031 * parameters.avg_wait_of_same_past_second 
	- 0.0132 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 320167553.6867;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM72(work_wait &parameters) {
  double actual_remaining = 
	1.3012 * parameters.work_so_far 
	- 0.0631 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 282101.053 * parameters.total_wait_locks 
	- 3.7494 * parameters.mean_wait_of_all 
	+ 275308447.008 * parameters.cpu_usage 
	- 4.0592 * parameters.avg_work_of_same_past_second 
	+ 0.0031 * parameters.avg_wait_of_same_past_second 
	- 0.0132 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 309164506.7123;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM73(work_wait &parameters) {
  double actual_remaining = 
	1.3012 * parameters.work_so_far 
	- 0.0631 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 174107.3637 * parameters.total_wait_locks 
	- 2.3619 * parameters.mean_wait_of_all 
	+ 255235713.6755 * parameters.cpu_usage 
	- 1.0539 * parameters.avg_work_of_same_past_second 
	+ 0.0031 * parameters.avg_wait_of_same_past_second 
	+ 0.004 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 74695080.9817;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM74(work_wait &parameters) {
  double actual_remaining = 
	-88.613 * parameters.work_so_far 
	- 0.0631 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 174107.3637 * parameters.total_wait_locks 
	- 2.3619 * parameters.mean_wait_of_all 
	+ 629964032.2786 * parameters.cpu_usage 
	- 1.0539 * parameters.avg_work_of_same_past_second 
	+ 0.0031 * parameters.avg_wait_of_same_past_second 
	+ 0.0137 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 285296770.9048;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM75(work_wait &parameters) {
  double actual_remaining = 
	-88.9632 * parameters.work_so_far 
	- 0.0044 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 8556.6009 * parameters.total_wait_locks 
	- 0.0486 * parameters.mean_wait_of_all 
	- 712166.8237 * parameters.cpu_usage 
	- 0.1459 * parameters.avg_work_of_same_past_second 
	- 0.0005 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 32755299.0028;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM76(work_wait &parameters) {
  double actual_remaining = 
	1.7533 * parameters.work_so_far 
	- 0.0037 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 18081.5407 * parameters.total_wait_locks 
	+ 0.006 * parameters.mean_wait_of_all 
	- 5703886.0111 * parameters.cpu_usage 
	- 0.0895 * parameters.avg_work_of_same_past_second 
	+ 0.0006 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 20105800.4045;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM77(work_wait &parameters) {
  double actual_remaining = 
	1.7533 * parameters.work_so_far 
	- 0.0059 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	- 22716.8626 * parameters.total_wait_locks 
	+ 0.006 * parameters.mean_wait_of_all 
	- 5703886.0111 * parameters.cpu_usage 
	- 1.0481 * parameters.avg_work_of_same_past_second 
	+ 0.0006 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 58446773.9269;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM78(work_wait &parameters) {
  double actual_remaining = 
	1.7533 * parameters.work_so_far 
	- 0.0059 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	- 22716.8626 * parameters.total_wait_locks 
	+ 0.006 * parameters.mean_wait_of_all 
	- 5703886.0111 * parameters.cpu_usage 
	- 1.0481 * parameters.avg_work_of_same_past_second 
	+ 0.0006 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 58119024.9048;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM79(work_wait &parameters) {
  double actual_remaining = 
	1.7533 * parameters.work_so_far 
	- 0.0059 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 5146.985 * parameters.total_wait_locks 
	+ 0.006 * parameters.mean_wait_of_all 
	- 5703886.0111 * parameters.cpu_usage 
	- 0.79 * parameters.avg_work_of_same_past_second 
	+ 0.0006 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 45073558.0516;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM80(work_wait &parameters) {
  double actual_remaining = 
	1.7533 * parameters.work_so_far 
	- 0.0059 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	- 91034.2019 * parameters.total_wait_locks 
	+ 0.006 * parameters.mean_wait_of_all 
	+ 28024524.1709 * parameters.cpu_usage 
	- 0.0895 * parameters.avg_work_of_same_past_second 
	+ 0.0006 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 52360828.5385;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM81(work_wait &parameters) {
  double actual_remaining = 
	1.7533 * parameters.work_so_far 
	- 0.0059 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	- 91034.2019 * parameters.total_wait_locks 
	+ 0.006 * parameters.mean_wait_of_all 
	+ 28856710.3087 * parameters.cpu_usage 
	- 0.0895 * parameters.avg_work_of_same_past_second 
	+ 0.0006 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 51856077.201;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM82(work_wait &parameters) {
  double actual_remaining = 
	1.7533 * parameters.work_so_far 
	- 0.0059 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	- 110564.0413 * parameters.total_wait_locks 
	+ 0.006 * parameters.mean_wait_of_all 
	+ 25393413.3351 * parameters.cpu_usage 
	- 0.0895 * parameters.avg_work_of_same_past_second 
	+ 0.0006 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 60614922.6221;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM83(work_wait &parameters) {
  double actual_remaining = 
	1.7533 * parameters.work_so_far 
	- 0.0059 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 26144.8348 * parameters.total_wait_locks 
	+ 0.006 * parameters.mean_wait_of_all 
	- 5703886.0111 * parameters.cpu_usage 
	- 0.0895 * parameters.avg_work_of_same_past_second 
	+ 0.0006 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 26571131.5937;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM84(work_wait &parameters) {
  double actual_remaining = 
	1.7533 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 1967.3408 * parameters.total_wait_locks 
	+ 0.006 * parameters.mean_wait_of_all 
	- 5703886.0111 * parameters.cpu_usage 
	- 0.0662 * parameters.avg_work_of_same_past_second 
	+ 0.0006 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 21322211.8456;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM85(work_wait &parameters) {
  double actual_remaining = 
	1.7533 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 706.3555 * parameters.total_wait_locks 
	+ 0.0242 * parameters.mean_wait_of_all 
	- 106378811.2014 * parameters.cpu_usage 
	- 2.6637 * parameters.avg_work_of_same_past_second 
	+ 0.1103 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0163 * parameters.max_latency_of_same_last_50 
	+ 170830664.5451;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM86(work_wait &parameters) {
  double actual_remaining = 
	1.7533 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 706.3555 * parameters.total_wait_locks 
	- 0.0017 * parameters.mean_wait_of_all 
	- 1800856.9517 * parameters.cpu_usage 
	- 0.0078 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 19231659.4902;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM87(work_wait &parameters) {
  double actual_remaining = 
	81.8687 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 706.3555 * parameters.total_wait_locks 
	- 0.0017 * parameters.mean_wait_of_all 
	- 1560163.4349 * parameters.cpu_usage 
	- 0.0108 * parameters.avg_work_of_same_past_second 
	+ 0.0006 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 18364957.5338;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM88(work_wait &parameters) {
  double actual_remaining = 
	401.0791 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 706.3555 * parameters.total_wait_locks 
	- 0.0017 * parameters.mean_wait_of_all 
	- 1560163.4349 * parameters.cpu_usage 
	- 0.0108 * parameters.avg_work_of_same_past_second 
	+ 0.0006 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 17345554.6964;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM89(work_wait &parameters) {
  double actual_remaining = 
	497.5661 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 706.3555 * parameters.total_wait_locks 
	- 0.0017 * parameters.mean_wait_of_all 
	+ 2482205959.2226 * parameters.cpu_usage 
	- 0.0108 * parameters.avg_work_of_same_past_second 
	+ 0.0006 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 2493624889.558;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM90(work_wait &parameters) {
  double actual_remaining = 
	10.2655 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 706.3555 * parameters.total_wait_locks 
	- 0.0017 * parameters.mean_wait_of_all 
	- 1560163.4349 * parameters.cpu_usage 
	- 0.0108 * parameters.avg_work_of_same_past_second 
	+ 0.0006 * parameters.avg_wait_of_same_past_second 
	+ 0.0545 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 488972.7599;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM91(work_wait &parameters) {
  double actual_remaining = 
	49.9058 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 90765.1097 * parameters.num_locks_so_far 
	+ 466.5211 * parameters.total_wait_locks 
	+ 0.0693 * parameters.mean_wait_of_all 
	- 82989.6308 * parameters.cpu_usage 
	+ 0.002 * parameters.avg_work_of_same_past_second 
	+ 0.0146 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0047 * parameters.max_latency_of_same_last_50 
	+ 17609345.136;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM92(work_wait &parameters) {
  double actual_remaining = 
	229.7383 * parameters.work_so_far 
	- 0.0181 * parameters.wait_so_far 
	+ 3489318.1059 * parameters.num_locks_so_far 
	+ 159857.6896 * parameters.total_wait_locks 
	- 0.2379 * parameters.mean_wait_of_all 
	- 94715.6947 * parameters.cpu_usage 
	+ 0.002 * parameters.avg_work_of_same_past_second 
	- 0.0408 * parameters.avg_wait_of_same_past_second 
	+ 0.2545 * parameters.avg_latency_of_same_last_20 
	- 0.0019 * parameters.max_latency_of_same_last_50 
	+ 35828085.6323;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM93(work_wait &parameters) {
  double actual_remaining = 
	137.978 * parameters.work_so_far 
	- 0.0181 * parameters.wait_so_far 
	+ 3489318.1059 * parameters.num_locks_so_far 
	+ 159857.6896 * parameters.total_wait_locks 
	- 0.2379 * parameters.mean_wait_of_all 
	- 94715.6947 * parameters.cpu_usage 
	+ 0.002 * parameters.avg_work_of_same_past_second 
	- 0.0408 * parameters.avg_wait_of_same_past_second 
	+ 0.021 * parameters.avg_latency_of_same_last_20 
	- 0.0019 * parameters.max_latency_of_same_last_50 
	+ 95671910.7544;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM94(work_wait &parameters) {
  double actual_remaining = 
	-8278.2771 * parameters.work_so_far 
	- 0.1498 * parameters.wait_so_far 
	+ 3489318.1059 * parameters.num_locks_so_far 
	+ 3715922.6339 * parameters.total_wait_locks 
	- 10.1302 * parameters.mean_wait_of_all 
	- 227543389.9547 * parameters.cpu_usage 
	+ 0.002 * parameters.avg_work_of_same_past_second 
	- 0.0408 * parameters.avg_wait_of_same_past_second 
	+ 0.0058 * parameters.avg_latency_of_same_last_20 
	- 0.0019 * parameters.max_latency_of_same_last_50 
	+ 789157935.4125;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM95(work_wait &parameters) {
  double actual_remaining = 
	88.5143 * parameters.work_so_far 
	- 0.2221 * parameters.wait_so_far 
	+ 3489318.1059 * parameters.num_locks_so_far 
	+ 893456.2648 * parameters.total_wait_locks 
	- 2.2033 * parameters.mean_wait_of_all 
	- 359880084.3467 * parameters.cpu_usage 
	- 0.7352 * parameters.avg_work_of_same_past_second 
	+ 1.2846 * parameters.avg_wait_of_same_past_second 
	+ 0.0058 * parameters.avg_latency_of_same_last_20 
	- 0.0019 * parameters.max_latency_of_same_last_50 
	+ 751810789.0847;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM96(work_wait &parameters) {
  double actual_remaining = 
	88.5143 * parameters.work_so_far 
	- 0.2221 * parameters.wait_so_far 
	+ 3489318.1059 * parameters.num_locks_so_far 
	+ 893456.2648 * parameters.total_wait_locks 
	- 2.2033 * parameters.mean_wait_of_all 
	- 359880084.3467 * parameters.cpu_usage 
	- 0.7352 * parameters.avg_work_of_same_past_second 
	+ 1.2846 * parameters.avg_wait_of_same_past_second 
	+ 0.0058 * parameters.avg_latency_of_same_last_20 
	- 0.0019 * parameters.max_latency_of_same_last_50 
	+ 746534546.8739;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM97(work_wait &parameters) {
  double actual_remaining = 
	88.5143 * parameters.work_so_far 
	- 0.2221 * parameters.wait_so_far 
	+ 3489318.1059 * parameters.num_locks_so_far 
	+ 893456.2648 * parameters.total_wait_locks 
	- 2.2033 * parameters.mean_wait_of_all 
	- 359880084.3467 * parameters.cpu_usage 
	- 0.7352 * parameters.avg_work_of_same_past_second 
	+ 1.2846 * parameters.avg_wait_of_same_past_second 
	+ 0.0058 * parameters.avg_latency_of_same_last_20 
	- 0.0019 * parameters.max_latency_of_same_last_50 
	+ 749987067.2416;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM98(work_wait &parameters) {
  double actual_remaining = 
	88.5143 * parameters.work_so_far 
	- 0.2221 * parameters.wait_so_far 
	+ 3489318.1059 * parameters.num_locks_so_far 
	+ 893456.2648 * parameters.total_wait_locks 
	- 2.2033 * parameters.mean_wait_of_all 
	- 359880084.3467 * parameters.cpu_usage 
	- 0.7352 * parameters.avg_work_of_same_past_second 
	+ 1.2846 * parameters.avg_wait_of_same_past_second 
	+ 0.0058 * parameters.avg_latency_of_same_last_20 
	- 0.0019 * parameters.max_latency_of_same_last_50 
	+ 717366860.3748;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM99(work_wait &parameters) {
  double actual_remaining = 
	88.5143 * parameters.work_so_far 
	- 0.2221 * parameters.wait_so_far 
	+ 3489318.1059 * parameters.num_locks_so_far 
	+ 893456.2648 * parameters.total_wait_locks 
	- 2.2033 * parameters.mean_wait_of_all 
	- 359880084.3467 * parameters.cpu_usage 
	- 0.7352 * parameters.avg_work_of_same_past_second 
	+ 1.2846 * parameters.avg_wait_of_same_past_second 
	+ 0.193 * parameters.avg_latency_of_same_last_20 
	- 0.0019 * parameters.max_latency_of_same_last_50 
	+ 685556574.3686;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM100(work_wait &parameters) {
  double actual_remaining = 
	-781.4667 * parameters.work_so_far 
	- 0.1481 * parameters.wait_so_far 
	+ 3489318.1059 * parameters.num_locks_so_far 
	+ 1395217.3487 * parameters.total_wait_locks 
	- 3.3611 * parameters.mean_wait_of_all 
	- 500877198.2595 * parameters.cpu_usage 
	- 0.3737 * parameters.avg_work_of_same_past_second 
	+ 7.288 * parameters.avg_wait_of_same_past_second 
	+ 0.0058 * parameters.avg_latency_of_same_last_20 
	- 0.08 * parameters.max_latency_of_same_last_50 
	+ 787750664.4718;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM101(work_wait &parameters) {
  double actual_remaining = 
	88.5143 * parameters.work_so_far 
	- 0.1481 * parameters.wait_so_far 
	+ 3489318.1059 * parameters.num_locks_so_far 
	+ 2130439.5779 * parameters.total_wait_locks 
	- 5.5143 * parameters.mean_wait_of_all 
	+ 661628925.1265 * parameters.cpu_usage 
	- 2.9173 * parameters.avg_work_of_same_past_second 
	+ 0.6347 * parameters.avg_wait_of_same_past_second 
	+ 0.0058 * parameters.avg_latency_of_same_last_20 
	- 0.0319 * parameters.max_latency_of_same_last_50 
	- 192021597.3108;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM102(work_wait &parameters) {
  double actual_remaining = 
	178.4316 * parameters.work_so_far 
	- 0.0206 * parameters.wait_so_far 
	+ 22649303.9145 * parameters.num_locks_so_far 
	+ 82111.1541 * parameters.total_wait_locks 
	- 0.1048 * parameters.mean_wait_of_all 
	- 94715.6947 * parameters.cpu_usage 
	- 0.4297 * parameters.avg_work_of_same_past_second 
	- 0.0855 * parameters.avg_wait_of_same_past_second 
	+ 0.0631 * parameters.avg_latency_of_same_last_20 
	- 0.0034 * parameters.max_latency_of_same_last_50 
	- 18860748.3492;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM103(work_wait &parameters) {
  double actual_remaining = 
	177.9702 * parameters.work_so_far 
	- 0.0136 * parameters.wait_so_far 
	+ 14794169.4041 * parameters.num_locks_so_far 
	+ 47797.3824 * parameters.total_wait_locks 
	+ 0.005 * parameters.mean_wait_of_all 
	- 94715.6947 * parameters.cpu_usage 
	- 1.9748 * parameters.avg_work_of_same_past_second 
	- 0.3099 * parameters.avg_wait_of_same_past_second 
	+ 0.0368 * parameters.avg_latency_of_same_last_20 
	- 0.0034 * parameters.max_latency_of_same_last_50 
	+ 156412023.6084;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM104(work_wait &parameters) {
  double actual_remaining = 
	295.0801 * parameters.work_so_far 
	- 0.0136 * parameters.wait_so_far 
	+ 14794169.4041 * parameters.num_locks_so_far 
	+ 216198.604 * parameters.total_wait_locks 
	- 0.0309 * parameters.mean_wait_of_all 
	- 94715.6947 * parameters.cpu_usage 
	- 0.3746 * parameters.avg_work_of_same_past_second 
	- 0.2365 * parameters.avg_wait_of_same_past_second 
	+ 0.0368 * parameters.avg_latency_of_same_last_20 
	- 0.0034 * parameters.max_latency_of_same_last_50 
	- 17155741.0617;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM105(work_wait &parameters) {
  double actual_remaining = 
	100.1922 * parameters.work_so_far 
	- 0.0075 * parameters.wait_so_far 
	+ 7088718.5442 * parameters.num_locks_so_far 
	+ 82111.1541 * parameters.total_wait_locks 
	- 0.1048 * parameters.mean_wait_of_all 
	- 94715.6947 * parameters.cpu_usage 
	- 0.0709 * parameters.avg_work_of_same_past_second 
	- 0.0823 * parameters.avg_wait_of_same_past_second 
	+ 0.0127 * parameters.avg_latency_of_same_last_20 
	- 0.0034 * parameters.max_latency_of_same_last_50 
	+ 17298186.9456;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM106(work_wait &parameters) {
  double actual_remaining = 
	185.4191 * parameters.work_so_far 
	- 0.0075 * parameters.wait_so_far 
	+ 7088718.5442 * parameters.num_locks_so_far 
	+ 82111.1541 * parameters.total_wait_locks 
	- 0.1048 * parameters.mean_wait_of_all 
	- 94715.6947 * parameters.cpu_usage 
	- 0.0709 * parameters.avg_work_of_same_past_second 
	- 0.0823 * parameters.avg_wait_of_same_past_second 
	+ 0.0127 * parameters.avg_latency_of_same_last_20 
	- 0.0034 * parameters.max_latency_of_same_last_50 
	+ 16697389.1012;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM107(work_wait &parameters) {
  double actual_remaining = 
	58.0716 * parameters.work_so_far 
	- 0.0075 * parameters.wait_so_far 
	+ 7088718.5442 * parameters.num_locks_so_far 
	+ 82111.1541 * parameters.total_wait_locks 
	- 0.1048 * parameters.mean_wait_of_all 
	- 94715.6947 * parameters.cpu_usage 
	- 0.0709 * parameters.avg_work_of_same_past_second 
	- 0.0823 * parameters.avg_wait_of_same_past_second 
	+ 0.0127 * parameters.avg_latency_of_same_last_20 
	- 0.0034 * parameters.max_latency_of_same_last_50 
	+ 15277956.2482;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM108(work_wait &parameters) {
  double actual_remaining = 
	58.0716 * parameters.work_so_far 
	- 0.0075 * parameters.wait_so_far 
	+ 7088718.5442 * parameters.num_locks_so_far 
	+ 82111.1541 * parameters.total_wait_locks 
	- 0.1048 * parameters.mean_wait_of_all 
	- 94715.6947 * parameters.cpu_usage 
	- 0.0709 * parameters.avg_work_of_same_past_second 
	- 0.0823 * parameters.avg_wait_of_same_past_second 
	+ 0.0127 * parameters.avg_latency_of_same_last_20 
	- 0.0034 * parameters.max_latency_of_same_last_50 
	+ 11392852.8431;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM109(work_wait &parameters) {
  double actual_remaining = 
	58.0716 * parameters.work_so_far 
	- 0.0075 * parameters.wait_so_far 
	+ 7088718.5442 * parameters.num_locks_so_far 
	+ 82111.1541 * parameters.total_wait_locks 
	- 0.1048 * parameters.mean_wait_of_all 
	- 94715.6947 * parameters.cpu_usage 
	- 0.0709 * parameters.avg_work_of_same_past_second 
	- 0.0823 * parameters.avg_wait_of_same_past_second 
	+ 0.0127 * parameters.avg_latency_of_same_last_20 
	- 0.0034 * parameters.max_latency_of_same_last_50 
	+ 7478056.3866;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM110(work_wait &parameters) {
  double actual_remaining = 
	1.5777 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 809833.1381 * parameters.num_locks_so_far 
	+ 274.741 * parameters.total_wait_locks 
	+ 0.0035 * parameters.mean_wait_of_all 
	- 94715.6947 * parameters.cpu_usage 
	- 0.0032 * parameters.avg_work_of_same_past_second 
	+ 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0012 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 12681604.1814;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM111(work_wait &parameters) {
  double actual_remaining = 
	-15.7102 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 809833.1381 * parameters.num_locks_so_far 
	- 99020.1289 * parameters.total_wait_locks 
	+ 0.105 * parameters.mean_wait_of_all 
	- 94715.6947 * parameters.cpu_usage 
	- 0.0533 * parameters.avg_work_of_same_past_second 
	+ 0.0737 * parameters.avg_wait_of_same_past_second 
	+ 0.0015 * parameters.avg_latency_of_same_last_20 
	+ 0.0001 * parameters.max_latency_of_same_last_50 
	+ 23012402.5116;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM112(work_wait &parameters) {
  double actual_remaining = 
	-15.7102 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 809833.1381 * parameters.num_locks_so_far 
	- 73036.7911 * parameters.total_wait_locks 
	- 0.0627 * parameters.mean_wait_of_all 
	- 94715.6947 * parameters.cpu_usage 
	- 0.0533 * parameters.avg_work_of_same_past_second 
	+ 0.0486 * parameters.avg_wait_of_same_past_second 
	+ 0.0015 * parameters.avg_latency_of_same_last_20 
	+ 0.0093 * parameters.max_latency_of_same_last_50 
	+ 37065655.1596;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM113(work_wait &parameters) {
  double actual_remaining = 
	-15.7102 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 809833.1381 * parameters.num_locks_so_far 
	- 73036.7911 * parameters.total_wait_locks 
	- 0.1085 * parameters.mean_wait_of_all 
	- 94715.6947 * parameters.cpu_usage 
	- 0.0533 * parameters.avg_work_of_same_past_second 
	+ 0.0486 * parameters.avg_wait_of_same_past_second 
	+ 0.0015 * parameters.avg_latency_of_same_last_20 
	+ 0.0057 * parameters.max_latency_of_same_last_50 
	+ 44043656.8935;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM114(work_wait &parameters) {
  double actual_remaining = 
	-15.7102 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 809833.1381 * parameters.num_locks_so_far 
	- 23235.3938 * parameters.total_wait_locks 
	+ 0.105 * parameters.mean_wait_of_all 
	- 94715.6947 * parameters.cpu_usage 
	- 0.0533 * parameters.avg_work_of_same_past_second 
	+ 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0015 * parameters.avg_latency_of_same_last_20 
	+ 0.0001 * parameters.max_latency_of_same_last_50 
	+ 20406610.9279;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM115(work_wait &parameters) {
  double actual_remaining = 
	-23.4207 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 809833.1381 * parameters.num_locks_so_far 
	- 27376.7753 * parameters.total_wait_locks 
	+ 0.1236 * parameters.mean_wait_of_all 
	- 94715.6947 * parameters.cpu_usage 
	- 0.0533 * parameters.avg_work_of_same_past_second 
	+ 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0015 * parameters.avg_latency_of_same_last_20 
	+ 0.0001 * parameters.max_latency_of_same_last_50 
	+ 14574420.5512;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM116(work_wait &parameters) {
  double actual_remaining = 
	7.4214 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 809833.1381 * parameters.num_locks_so_far 
	- 9137.892 * parameters.total_wait_locks 
	+ 0.0422 * parameters.mean_wait_of_all 
	- 94715.6947 * parameters.cpu_usage 
	- 0.0457 * parameters.avg_work_of_same_past_second 
	+ 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0015 * parameters.avg_latency_of_same_last_20 
	+ 0.0001 * parameters.max_latency_of_same_last_50 
	+ 13998323.1638;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM117(work_wait &parameters) {
  double actual_remaining = 
	165.4047 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 809833.1381 * parameters.num_locks_so_far 
	+ 274.741 * parameters.total_wait_locks 
	+ 0.0035 * parameters.mean_wait_of_all 
	- 94715.6947 * parameters.cpu_usage 
	- 0.0032 * parameters.avg_work_of_same_past_second 
	+ 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0015 * parameters.avg_latency_of_same_last_20 
	+ 0.0001 * parameters.max_latency_of_same_last_50 
	+ 14426743.66;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM118(work_wait &parameters) {
  double actual_remaining = 
	1.5777 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 809833.1381 * parameters.num_locks_so_far 
	- 46789.916 * parameters.total_wait_locks 
	+ 1.0829 * parameters.mean_wait_of_all 
	+ 55484914.2974 * parameters.cpu_usage 
	- 0.0944 * parameters.avg_work_of_same_past_second 
	+ 0.0223 * parameters.avg_wait_of_same_past_second 
	+ 0.0682 * parameters.avg_latency_of_same_last_20 
	- 0.0037 * parameters.max_latency_of_same_last_50 
	- 179029805.8692;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM119(work_wait &parameters) {
  double actual_remaining = 
	1.5777 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 809833.1381 * parameters.num_locks_so_far 
	- 771283.139 * parameters.total_wait_locks 
	+ 23.3396 * parameters.mean_wait_of_all 
	+ 161480844.4655 * parameters.cpu_usage 
	- 0.0944 * parameters.avg_work_of_same_past_second 
	+ 0.0642 * parameters.avg_wait_of_same_past_second 
	+ 0.0334 * parameters.avg_latency_of_same_last_20 
	- 0.0106 * parameters.max_latency_of_same_last_50 
	- 3341368665.1153;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM120(work_wait &parameters) {
  double actual_remaining = 
	1.5777 * parameters.work_so_far 
	- 0.1327 * parameters.wait_so_far 
	+ 809833.1381 * parameters.num_locks_so_far 
	- 1498327.4656 * parameters.total_wait_locks 
	+ 20.8908 * parameters.mean_wait_of_all 
	+ 161480844.4655 * parameters.cpu_usage 
	- 0.0944 * parameters.avg_work_of_same_past_second 
	+ 0.0642 * parameters.avg_wait_of_same_past_second 
	+ 0.0334 * parameters.avg_latency_of_same_last_20 
	- 0.0106 * parameters.max_latency_of_same_last_50 
	- 2363554889.9481;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM121(work_wait &parameters) {
  double actual_remaining = 
	1.5777 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 809833.1381 * parameters.num_locks_so_far 
	- 2599.5161 * parameters.total_wait_locks 
	- 1.5554 * parameters.mean_wait_of_all 
	+ 739763.5513 * parameters.cpu_usage 
	- 0.0326 * parameters.avg_work_of_same_past_second 
	+ 0.0006 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 268402928.2865;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM122(work_wait &parameters) {
  double actual_remaining = 
	1.5777 * parameters.work_so_far 
	- 0.0089 * parameters.wait_so_far 
	+ 809833.1381 * parameters.num_locks_so_far 
	- 270566.9136 * parameters.total_wait_locks 
	+ 3.2798 * parameters.mean_wait_of_all 
	+ 763856.128 * parameters.cpu_usage 
	- 0.01 * parameters.avg_work_of_same_past_second 
	+ 0.0006 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	- 328442641.9777;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM123(work_wait &parameters) {
  double actual_remaining = 
	0.096 * parameters.work_so_far 
	+ 0.2971 * parameters.wait_so_far 
	+ 9505.3651 * parameters.num_locks_so_far 
	+ 1404.6084 * parameters.total_wait_locks 
	- 0.0056 * parameters.mean_wait_of_all 
	- 1173416.9259 * parameters.cpu_usage 
	- 0.2623 * parameters.avg_work_of_same_past_second 
	+ 0.0407 * parameters.avg_wait_of_same_past_second 
	+ 0 * parameters.avg_latency_of_same_last_20 
	- 0.0063 * parameters.max_latency_of_same_last_50 
	+ 30482700.5828;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM124(work_wait &parameters) {
  double actual_remaining = 
	2.2637 * parameters.work_so_far 
	+ 0.0664 * parameters.wait_so_far 
	- 4847071.614 * parameters.num_locks_so_far 
	+ 607954.5058 * parameters.total_wait_locks 
	- 2.2703 * parameters.mean_wait_of_all 
	- 11571551.7752 * parameters.cpu_usage 
	+ 1.3546 * parameters.avg_work_of_same_past_second 
	- 1.5397 * parameters.avg_wait_of_same_past_second 
	+ 0.1827 * parameters.avg_latency_of_same_last_20 
	- 0.109 * parameters.max_latency_of_same_last_50 
	+ 253584241.3716;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM125(work_wait &parameters) {
  double actual_remaining = 
	1.6258 * parameters.work_so_far 
	+ 0.0977 * parameters.wait_so_far 
	- 3427316.8304 * parameters.num_locks_so_far 
	+ 1821370.9114 * parameters.total_wait_locks 
	- 4.7238 * parameters.mean_wait_of_all 
	- 11571551.7752 * parameters.cpu_usage 
	+ 3.7724 * parameters.avg_work_of_same_past_second 
	- 0.193 * parameters.avg_wait_of_same_past_second 
	- 0.2033 * parameters.avg_latency_of_same_last_20 
	- 0.0093 * parameters.max_latency_of_same_last_50 
	+ 217031841.6801;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM126(work_wait &parameters) {
  double actual_remaining = 
	2.1624 * parameters.work_so_far 
	+ 0.9323 * parameters.wait_so_far 
	- 150772.8734 * parameters.num_locks_so_far 
	+ 21876.2005 * parameters.total_wait_locks 
	- 0.0684 * parameters.mean_wait_of_all 
	- 11776837.9122 * parameters.cpu_usage 
	+ 0.4281 * parameters.avg_work_of_same_past_second 
	- 0.0277 * parameters.avg_wait_of_same_past_second 
	+ 0.0094 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 18625680.317;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM127(work_wait &parameters) {
  double actual_remaining = 
	1.2371 * parameters.work_so_far 
	+ 0.617 * parameters.wait_so_far 
	+ 4657559.5015 * parameters.num_locks_so_far 
	+ 22957.8118 * parameters.total_wait_locks 
	- 0.0739 * parameters.mean_wait_of_all 
	- 11776837.9122 * parameters.cpu_usage 
	+ 0.1457 * parameters.avg_work_of_same_past_second 
	- 0.3017 * parameters.avg_wait_of_same_past_second 
	+ 0.078 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 76539093.4907;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM128(work_wait &parameters) {
  double actual_remaining = 
	1.2371 * parameters.work_so_far 
	+ 0.7291 * parameters.wait_so_far 
	+ 2309506.9128 * parameters.num_locks_so_far 
	+ 22957.8118 * parameters.total_wait_locks 
	- 0.0739 * parameters.mean_wait_of_all 
	- 11776837.9122 * parameters.cpu_usage 
	+ 0.1457 * parameters.avg_work_of_same_past_second 
	- 0.1083 * parameters.avg_wait_of_same_past_second 
	+ 0.078 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 64243838.6069;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM129(work_wait &parameters) {
  double actual_remaining = 
	1.3623 * parameters.work_so_far 
	+ 1.065 * parameters.wait_so_far 
	+ 803969.0446 * parameters.num_locks_so_far 
	+ 22957.8118 * parameters.total_wait_locks 
	- 0.0739 * parameters.mean_wait_of_all 
	- 11776837.9122 * parameters.cpu_usage 
	+ 0.1457 * parameters.avg_work_of_same_past_second 
	- 0.1354 * parameters.avg_wait_of_same_past_second 
	+ 0.0527 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 55788999.9043;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM130(work_wait &parameters) {
  double actual_remaining = 
	1.344 * parameters.work_so_far 
	+ 0.2501 * parameters.wait_so_far 
	- 226529.8906 * parameters.num_locks_so_far 
	+ 22957.8118 * parameters.total_wait_locks 
	- 0.0739 * parameters.mean_wait_of_all 
	- 11776837.9122 * parameters.cpu_usage 
	+ 0.1457 * parameters.avg_work_of_same_past_second 
	- 0.0456 * parameters.avg_wait_of_same_past_second 
	+ 0.0244 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 44717522.5504;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM131(work_wait &parameters) {
  double actual_remaining = 
	0.7778 * parameters.work_so_far 
	+ 0.6983 * parameters.wait_so_far 
	- 612739.0237 * parameters.num_locks_so_far 
	+ 24018.6731 * parameters.total_wait_locks 
	- 0.0805 * parameters.mean_wait_of_all 
	- 11776837.9122 * parameters.cpu_usage 
	- 0.5693 * parameters.avg_work_of_same_past_second 
	+ 0.0102 * parameters.avg_wait_of_same_past_second 
	+ 0.0072 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 71259526.9332;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM132(work_wait &parameters) {
  double actual_remaining = 
	0.9988 * parameters.work_so_far 
	+ 0.4097 * parameters.wait_so_far 
	- 5563040.9274 * parameters.num_locks_so_far 
	+ 24018.6731 * parameters.total_wait_locks 
	- 0.0805 * parameters.mean_wait_of_all 
	- 11776837.9122 * parameters.cpu_usage 
	+ 0.1175 * parameters.avg_work_of_same_past_second 
	- 0.0189 * parameters.avg_wait_of_same_past_second 
	+ 0.0072 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 149632072.0505;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM133(work_wait &parameters) {
  double actual_remaining = 
	0.9988 * parameters.work_so_far 
	+ 0.4097 * parameters.wait_so_far 
	- 1942717.3271 * parameters.num_locks_so_far 
	+ 24018.6731 * parameters.total_wait_locks 
	- 0.0805 * parameters.mean_wait_of_all 
	- 11776837.9122 * parameters.cpu_usage 
	+ 0.1175 * parameters.avg_work_of_same_past_second 
	- 0.0189 * parameters.avg_wait_of_same_past_second 
	+ 0.0072 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 127938383.7994;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM134(work_wait &parameters) {
  double actual_remaining = 
	1.0874 * parameters.work_so_far 
	+ 0.5611 * parameters.wait_so_far 
	- 1874283.4858 * parameters.num_locks_so_far 
	+ 24018.6731 * parameters.total_wait_locks 
	- 0.0805 * parameters.mean_wait_of_all 
	- 11776837.9122 * parameters.cpu_usage 
	+ 0.5313 * parameters.avg_work_of_same_past_second 
	- 0.043 * parameters.avg_wait_of_same_past_second 
	+ 0.0072 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 105995222.2668;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM135(work_wait &parameters) {
  double actual_remaining = 
	1.1101 * parameters.work_so_far 
	+ 0.3668 * parameters.wait_so_far 
	- 2651581.3592 * parameters.num_locks_so_far 
	+ 24018.6731 * parameters.total_wait_locks 
	- 0.0805 * parameters.mean_wait_of_all 
	- 11776837.9122 * parameters.cpu_usage 
	+ 0.5313 * parameters.avg_work_of_same_past_second 
	- 0.043 * parameters.avg_wait_of_same_past_second 
	+ 0.0072 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 156524405.976;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM136(work_wait &parameters) {
  double actual_remaining = 
	4.7192 * parameters.work_so_far 
	+ 0.9217 * parameters.wait_so_far 
	- 1548827.3953 * parameters.num_locks_so_far 
	+ 17193.2795 * parameters.total_wait_locks 
	- 0.0457 * parameters.mean_wait_of_all 
	- 13652309.0475 * parameters.cpu_usage 
	+ 0.1234 * parameters.avg_work_of_same_past_second 
	- 0.2051 * parameters.avg_wait_of_same_past_second 
	+ 0.1287 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 57113544.3444;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM137(work_wait &parameters) {
  double actual_remaining = 
	0.9778 * parameters.work_so_far 
	+ 0.041 * parameters.wait_so_far 
	- 2232265.4467 * parameters.num_locks_so_far 
	+ 353964.9269 * parameters.total_wait_locks 
	- 0.0339 * parameters.mean_wait_of_all 
	- 9099969.7641 * parameters.cpu_usage 
	+ 0.0787 * parameters.avg_work_of_same_past_second 
	- 0.4259 * parameters.avg_wait_of_same_past_second 
	+ 0.004 * parameters.avg_latency_of_same_last_20 
	- 0.0725 * parameters.max_latency_of_same_last_50 
	+ 277320988.8772;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM138(work_wait &parameters) {
  double actual_remaining = 
	0.016 * parameters.work_so_far 
	+ 0.6907 * parameters.wait_so_far 
	+ 864461.0996 * parameters.num_locks_so_far 
	+ 7479.6906 * parameters.total_wait_locks 
	- 0.0371 * parameters.mean_wait_of_all 
	- 1705197.2244 * parameters.cpu_usage 
	+ 0.0292 * parameters.avg_work_of_same_past_second 
	+ 0.2547 * parameters.avg_wait_of_same_past_second 
	- 0.273 * parameters.avg_latency_of_same_last_20 
	- 0.0016 * parameters.max_latency_of_same_last_50 
	- 77429482.2333;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM139(work_wait &parameters) {
  double actual_remaining = 
	1.2189 * parameters.work_so_far 
	+ 0.9651 * parameters.wait_so_far 
	- 1917463.7728 * parameters.num_locks_so_far 
	+ 9420.209 * parameters.total_wait_locks 
	- 0.0473 * parameters.mean_wait_of_all 
	- 1705197.2244 * parameters.cpu_usage 
	+ 0.5174 * parameters.avg_work_of_same_past_second 
	+ 0.0064 * parameters.avg_wait_of_same_past_second 
	- 0.0111 * parameters.avg_latency_of_same_last_20 
	- 0.0022 * parameters.max_latency_of_same_last_50 
	+ 23489522.7322;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM140(work_wait &parameters) {
  double actual_remaining = 
	1.1212 * parameters.work_so_far 
	+ 0.9801 * parameters.wait_so_far 
	+ 879661.9752 * parameters.num_locks_so_far 
	+ 9420.209 * parameters.total_wait_locks 
	- 0.0473 * parameters.mean_wait_of_all 
	- 1705197.2244 * parameters.cpu_usage 
	+ 0.0606 * parameters.avg_work_of_same_past_second 
	+ 0.0064 * parameters.avg_wait_of_same_past_second 
	- 0.0111 * parameters.avg_latency_of_same_last_20 
	- 0.0022 * parameters.max_latency_of_same_last_50 
	+ 12633349.0771;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM141(work_wait &parameters) {
  double actual_remaining = 
	-0.0468 * parameters.work_so_far 
	+ 1.0734 * parameters.wait_so_far 
	+ 4405703.9336 * parameters.num_locks_so_far 
	+ 2269.3224 * parameters.total_wait_locks 
	- 0.0097 * parameters.mean_wait_of_all 
	- 1705197.2244 * parameters.cpu_usage 
	+ 0.0292 * parameters.avg_work_of_same_past_second 
	- 0.0026 * parameters.avg_wait_of_same_past_second 
	- 0.3796 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 239692521.4606;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM142(work_wait &parameters) {
  double actual_remaining = 
	1.5816 * parameters.work_so_far 
	+ 1.0099 * parameters.wait_so_far 
	+ 4131515.8695 * parameters.num_locks_so_far 
	+ 2269.3224 * parameters.total_wait_locks 
	- 0.0097 * parameters.mean_wait_of_all 
	- 1705197.2244 * parameters.cpu_usage 
	+ 0.0292 * parameters.avg_work_of_same_past_second 
	+ 0.0887 * parameters.avg_wait_of_same_past_second 
	- 0.064 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 40956074.9085;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM143(work_wait &parameters) {
  double actual_remaining = 
	0.3425 * parameters.work_so_far 
	- 4.4195 * parameters.wait_so_far 
	+ 183525.5913 * parameters.num_locks_so_far 
	+ 519969.3583 * parameters.total_wait_locks 
	- 1.2765 * parameters.mean_wait_of_all 
	- 1129623062.339 * parameters.cpu_usage 
	+ 1.1922 * parameters.avg_work_of_same_past_second 
	- 0.7639 * parameters.avg_wait_of_same_past_second 
	+ 0.0061 * parameters.avg_latency_of_same_last_20 
	+ 0.0937 * parameters.max_latency_of_same_last_50 
	+ 1178591367.4048;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM144(work_wait &parameters) {
  double actual_remaining = 
	0.3425 * parameters.work_so_far 
	- 3.9785 * parameters.wait_so_far 
	+ 183525.5913 * parameters.num_locks_so_far 
	+ 735181.5193 * parameters.total_wait_locks 
	- 2.3124 * parameters.mean_wait_of_all 
	- 555529798.1251 * parameters.cpu_usage 
	+ 0.4728 * parameters.avg_work_of_same_past_second 
	- 0.007 * parameters.avg_wait_of_same_past_second 
	+ 0.0034 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 825824571.9596;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM145(work_wait &parameters) {
  double actual_remaining = 
	-34.4859 * parameters.work_so_far 
	- 15.5951 * parameters.wait_so_far 
	+ 183525.5913 * parameters.num_locks_so_far 
	+ 2569064.5915 * parameters.total_wait_locks 
	- 20.3836 * parameters.mean_wait_of_all 
	- 297063420.2553 * parameters.cpu_usage 
	+ 0.0232 * parameters.avg_work_of_same_past_second 
	- 3.2806 * parameters.avg_wait_of_same_past_second 
	+ 0.0034 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 3490425340.2992;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM146(work_wait &parameters) {
  double actual_remaining = 
	-9.9991 * parameters.work_so_far 
	- 0.5479 * parameters.wait_so_far 
	+ 183525.5913 * parameters.num_locks_so_far 
	+ 133855.856 * parameters.total_wait_locks 
	+ 7.0034 * parameters.mean_wait_of_all 
	+ 2431901348.6104 * parameters.cpu_usage 
	- 0.7191 * parameters.avg_work_of_same_past_second 
	- 0.0678 * parameters.avg_wait_of_same_past_second 
	+ 0.0034 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 2791690819.668;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM147(work_wait &parameters) {
  double actual_remaining = 
	310.7104 * parameters.work_so_far 
	- 0.3109 * parameters.wait_so_far 
	+ 183525.5913 * parameters.num_locks_so_far 
	+ 29830.1372 * parameters.total_wait_locks 
	- 0.2629 * parameters.mean_wait_of_all 
	- 47784388.9502 * parameters.cpu_usage 
	+ 0.0232 * parameters.avg_work_of_same_past_second 
	- 0.007 * parameters.avg_wait_of_same_past_second 
	+ 0.0034 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 419790940.0244;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM148(work_wait &parameters) {
  double actual_remaining = 
	60.4921 * parameters.work_so_far 
	- 0.3109 * parameters.wait_so_far 
	+ 183525.5913 * parameters.num_locks_so_far 
	+ 29830.1372 * parameters.total_wait_locks 
	- 120.4362 * parameters.mean_wait_of_all 
	- 47784388.9502 * parameters.cpu_usage 
	+ 0.0232 * parameters.avg_work_of_same_past_second 
	- 3.6397 * parameters.avg_wait_of_same_past_second 
	+ 0.0034 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 22232085616.6886;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM149(work_wait &parameters) {
  double actual_remaining = 
	77.8345 * parameters.work_so_far 
	- 0.1962 * parameters.wait_so_far 
	+ 44477909.68 * parameters.num_locks_so_far 
	+ 210767.8466 * parameters.total_wait_locks 
	- 0.4796 * parameters.mean_wait_of_all 
	- 267865728.3598 * parameters.cpu_usage 
	+ 0.6056 * parameters.avg_work_of_same_past_second 
	- 0.1233 * parameters.avg_wait_of_same_past_second 
	+ 0.2482 * parameters.avg_latency_of_same_last_20 
	- 0.0196 * parameters.max_latency_of_same_last_50 
	+ 166367846.7687;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM150(work_wait &parameters) {
  double actual_remaining = 
	8.01 * parameters.work_so_far 
	+ 0.3884 * parameters.wait_so_far 
	+ 189085.8758 * parameters.num_locks_so_far 
	+ 174367.5119 * parameters.total_wait_locks 
	- 0.0222 * parameters.mean_wait_of_all 
	- 3824323.0662 * parameters.cpu_usage 
	+ 1.0547 * parameters.avg_work_of_same_past_second 
	- 0.5331 * parameters.avg_wait_of_same_past_second 
	+ 0.1789 * parameters.avg_latency_of_same_last_20 
	- 0.0521 * parameters.max_latency_of_same_last_50 
	+ 121858910.8341;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM151(work_wait &parameters) {
  double actual_remaining = 
	1.6052 * parameters.work_so_far 
	+ 0.3961 * parameters.wait_so_far 
	+ 23255966.7375 * parameters.num_locks_so_far 
	+ 682254.9002 * parameters.total_wait_locks 
	- 2.6175 * parameters.mean_wait_of_all 
	- 360024857.757 * parameters.cpu_usage 
	+ 1.5521 * parameters.avg_work_of_same_past_second 
	- 0.74 * parameters.avg_wait_of_same_past_second 
	+ 0.3026 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	+ 371967372.0815;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM152(work_wait &parameters) {
  double actual_remaining = 
	0.1092 * parameters.work_so_far 
	+ 0.0412 * parameters.wait_so_far 
	- 29901139.731 * parameters.num_locks_so_far 
	+ 1233.5326 * parameters.total_wait_locks 
	+ 0.0064 * parameters.mean_wait_of_all 
	- 31197166.7527 * parameters.cpu_usage 
	+ 2.0168 * parameters.avg_work_of_same_past_second 
	- 1.1592 * parameters.avg_wait_of_same_past_second 
	+ 0.0158 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 198111548.3641;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM153(work_wait &parameters) {
  double actual_remaining = 
	0.1092 * parameters.work_so_far 
	+ 0.0193 * parameters.wait_so_far 
	+ 459298.4265 * parameters.num_locks_so_far 
	+ 1233.5326 * parameters.total_wait_locks 
	+ 0.0064 * parameters.mean_wait_of_all 
	- 31197166.7527 * parameters.cpu_usage 
	+ 0.0552 * parameters.avg_work_of_same_past_second 
	- 0.0105 * parameters.avg_wait_of_same_past_second 
	+ 0.2744 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 363058123.6235;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM154(work_wait &parameters) {
  double actual_remaining = 
	7.275 * parameters.work_so_far 
	+ 0.0087 * parameters.wait_so_far 
	+ 459298.4265 * parameters.num_locks_so_far 
	- 117408.2424 * parameters.total_wait_locks 
	+ 0.7914 * parameters.mean_wait_of_all 
	+ 1804926630.6422 * parameters.cpu_usage 
	+ 2.7301 * parameters.avg_work_of_same_past_second 
	- 0.0105 * parameters.avg_wait_of_same_past_second 
	+ 0.0223 * parameters.avg_latency_of_same_last_20 
	+ 0.022 * parameters.max_latency_of_same_last_50 
	- 1892463266.8712;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM155(work_wait &parameters) {
  double actual_remaining = 
	53.8248 * parameters.work_so_far 
	+ 0.0087 * parameters.wait_so_far 
	+ 459298.4265 * parameters.num_locks_so_far 
	- 50940.26 * parameters.total_wait_locks 
	+ 0.3516 * parameters.mean_wait_of_all 
	- 152729659.9589 * parameters.cpu_usage 
	+ 0.0814 * parameters.avg_work_of_same_past_second 
	+ 0.7679 * parameters.avg_wait_of_same_past_second 
	+ 0.0223 * parameters.avg_latency_of_same_last_20 
	+ 0.0097 * parameters.max_latency_of_same_last_50 
	+ 192904978.387;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM156(work_wait &parameters) {
  double actual_remaining = 
	0.1503 * parameters.work_so_far 
	- 0.2709 * parameters.wait_so_far 
	+ 1184962.5857 * parameters.num_locks_so_far 
	+ 1117.6178 * parameters.total_wait_locks 
	+ 0.007 * parameters.mean_wait_of_all 
	- 12453956.2992 * parameters.cpu_usage 
	+ 0.0319 * parameters.avg_work_of_same_past_second 
	- 0.0105 * parameters.avg_wait_of_same_past_second 
	+ 0.2516 * parameters.avg_latency_of_same_last_20 
	+ 0.002 * parameters.max_latency_of_same_last_50 
	+ 414763061.6473;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM157(work_wait &parameters) {
  double actual_remaining = 
	0.2163 * parameters.work_so_far 
	+ 0.0087 * parameters.wait_so_far 
	- 27900256.2359 * parameters.num_locks_so_far 
	- 55676.8745 * parameters.total_wait_locks 
	+ 0.5254 * parameters.mean_wait_of_all 
	- 12453956.2992 * parameters.cpu_usage 
	+ 0.0319 * parameters.avg_work_of_same_past_second 
	+ 0.1522 * parameters.avg_wait_of_same_past_second 
	+ 0.0249 * parameters.avg_latency_of_same_last_20 
	+ 0.0295 * parameters.max_latency_of_same_last_50 
	+ 773385430.1776;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM158(work_wait &parameters) {
  double actual_remaining = 
	0.2163 * parameters.work_so_far 
	+ 0.0087 * parameters.wait_so_far 
	- 36003003.222 * parameters.num_locks_so_far 
	+ 2019513.7973 * parameters.total_wait_locks 
	- 27.8652 * parameters.mean_wait_of_all 
	- 12453956.2992 * parameters.cpu_usage 
	+ 0.0319 * parameters.avg_work_of_same_past_second 
	+ 0.1958 * parameters.avg_wait_of_same_past_second 
	+ 0.0249 * parameters.avg_latency_of_same_last_20 
	+ 0.3546 * parameters.max_latency_of_same_last_50 
	+ 3710390819.4867;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM159(work_wait &parameters) {
  double actual_remaining = 
	16.9584 * parameters.work_so_far 
	+ 0.082 * parameters.wait_so_far 
	- 17167216.31 * parameters.num_locks_so_far 
	+ 7877.7397 * parameters.total_wait_locks 
	+ 0.4639 * parameters.mean_wait_of_all 
	- 3016701.8751 * parameters.cpu_usage 
	+ 0.558 * parameters.avg_work_of_same_past_second 
	- 0.601 * parameters.avg_wait_of_same_past_second 
	+ 0.0197 * parameters.avg_latency_of_same_last_20 
	- 0.0007 * parameters.max_latency_of_same_last_50 
	+ 247059800.3453;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM160(work_wait &parameters) {
  double actual_remaining = 
	1.0743 * parameters.work_so_far 
	+ 0.082 * parameters.wait_so_far 
	- 12742213.685 * parameters.num_locks_so_far 
	+ 7877.7397 * parameters.total_wait_locks 
	+ 0.6478 * parameters.mean_wait_of_all 
	- 3016701.8751 * parameters.cpu_usage 
	+ 0.068 * parameters.avg_work_of_same_past_second 
	- 0.0733 * parameters.avg_wait_of_same_past_second 
	+ 0.1751 * parameters.avg_latency_of_same_last_20 
	- 0.0007 * parameters.max_latency_of_same_last_50 
	+ 368828472.0295;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM161(work_wait &parameters) {
  double actual_remaining = 
	3.9995 * parameters.work_so_far 
	+ 1.3438 * parameters.wait_so_far 
	- 2673623.4123 * parameters.num_locks_so_far 
	+ 80817.1487 * parameters.total_wait_locks 
	+ 0.0019 * parameters.mean_wait_of_all 
	- 3016701.8751 * parameters.cpu_usage 
	+ 0.0294 * parameters.avg_work_of_same_past_second 
	- 0.2034 * parameters.avg_wait_of_same_past_second 
	+ 0.1178 * parameters.avg_latency_of_same_last_20 
	- 0.0007 * parameters.max_latency_of_same_last_50 
	+ 90510522.3544;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM162(work_wait &parameters) {
  double actual_remaining = 
	1.8504 * parameters.work_so_far 
	+ 1.0868 * parameters.wait_so_far 
	- 5797231.5045 * parameters.num_locks_so_far 
	+ 920827.4726 * parameters.total_wait_locks 
	- 0.6247 * parameters.mean_wait_of_all 
	- 3016701.8751 * parameters.cpu_usage 
	+ 0.0536 * parameters.avg_work_of_same_past_second 
	- 0.6893 * parameters.avg_wait_of_same_past_second 
	+ 0.0415 * parameters.avg_latency_of_same_last_20 
	- 0.0109 * parameters.max_latency_of_same_last_50 
	+ 354093497.4398;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM163(work_wait &parameters) {
  double actual_remaining = 
	3.2966 * parameters.work_so_far 
	+ 1.0868 * parameters.wait_so_far 
	- 3611132.99 * parameters.num_locks_so_far 
	+ 590850.7374 * parameters.total_wait_locks 
	- 1.8443 * parameters.mean_wait_of_all 
	- 3016701.8751 * parameters.cpu_usage 
	+ 0.0536 * parameters.avg_work_of_same_past_second 
	- 0.4362 * parameters.avg_wait_of_same_past_second 
	+ 0.0415 * parameters.avg_latency_of_same_last_20 
	- 0.0109 * parameters.max_latency_of_same_last_50 
	+ 274952038.9851;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM164(work_wait &parameters) {
  double actual_remaining = 
	0.9854 * parameters.work_so_far 
	- 1.3865 * parameters.wait_so_far 
	- 2011548.711 * parameters.num_locks_so_far 
	+ 104996.3969 * parameters.total_wait_locks 
	- 0.0862 * parameters.mean_wait_of_all 
	- 3016701.8751 * parameters.cpu_usage 
	+ 0.0536 * parameters.avg_work_of_same_past_second 
	- 0.3116 * parameters.avg_wait_of_same_past_second 
	+ 0.0415 * parameters.avg_latency_of_same_last_20 
	- 0.0109 * parameters.max_latency_of_same_last_50 
	+ 536534527.2427;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM165(work_wait &parameters) {
  double actual_remaining = 
	1.953 * parameters.work_so_far 
	+ 2.8025 * parameters.wait_so_far 
	+ 15989835.4833 * parameters.num_locks_so_far 
	+ 241864.1275 * parameters.total_wait_locks 
	- 0.0723 * parameters.mean_wait_of_all 
	- 3016701.8751 * parameters.cpu_usage 
	+ 0.0536 * parameters.avg_work_of_same_past_second 
	- 0.6182 * parameters.avg_wait_of_same_past_second 
	+ 0.3594 * parameters.avg_latency_of_same_last_20 
	- 0.1259 * parameters.max_latency_of_same_last_50 
	- 195997664.1762;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM166(work_wait &parameters) {
  double actual_remaining = 
	1.6579 * parameters.work_so_far 
	+ 0.1252 * parameters.wait_so_far 
	- 416595.7341 * parameters.num_locks_so_far 
	+ 10365.9229 * parameters.total_wait_locks 
	+ 0.6393 * parameters.mean_wait_of_all 
	- 3016701.8751 * parameters.cpu_usage 
	+ 0.318 * parameters.avg_work_of_same_past_second 
	- 0.3815 * parameters.avg_wait_of_same_past_second 
	+ 0.2143 * parameters.avg_latency_of_same_last_20 
	- 0.0024 * parameters.max_latency_of_same_last_50 
	+ 21681204.752;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM167(work_wait &parameters) {
  double actual_remaining = 
	2.5207 * parameters.work_so_far 
	+ 0.8444 * parameters.wait_so_far 
	- 6203469.8869 * parameters.num_locks_so_far 
	+ 2162.9375 * parameters.total_wait_locks 
	+ 0.2757 * parameters.mean_wait_of_all 
	- 3569215.3209 * parameters.cpu_usage 
	+ 0.0154 * parameters.avg_work_of_same_past_second 
	+ 0.1981 * parameters.avg_wait_of_same_past_second 
	+ 0.2865 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 153800189.3356;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM168(work_wait &parameters) {
  double actual_remaining = 
	1.2508 * parameters.work_so_far 
	+ 0.0512 * parameters.wait_so_far 
	- 495479.0348 * parameters.num_locks_so_far 
	- 581701.1533 * parameters.total_wait_locks 
	+ 3.6181 * parameters.mean_wait_of_all 
	- 1356034022.7879 * parameters.cpu_usage 
	+ 0.0709 * parameters.avg_work_of_same_past_second 
	- 0.0764 * parameters.avg_wait_of_same_past_second 
	+ 0.5173 * parameters.avg_latency_of_same_last_20 
	- 0.0031 * parameters.max_latency_of_same_last_50 
	+ 1390608207.5237;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM169(work_wait &parameters) {
  double actual_remaining = 
	1.0873 * parameters.work_so_far 
	+ 0.7769 * parameters.wait_so_far 
	- 231584.4587 * parameters.num_locks_so_far 
	+ 326175.7745 * parameters.total_wait_locks 
	- 0.8155 * parameters.mean_wait_of_all 
	- 165027658.2416 * parameters.cpu_usage 
	+ 0.4441 * parameters.avg_work_of_same_past_second 
	- 0.6039 * parameters.avg_wait_of_same_past_second 
	+ 0.3081 * parameters.avg_latency_of_same_last_20 
	- 0.0328 * parameters.max_latency_of_same_last_50 
	+ 294751895.8827;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM170(work_wait &parameters) {
  double actual_remaining = 
	0.8382 * parameters.work_so_far 
	+ 0.8754 * parameters.wait_so_far 
	- 4229469.6226 * parameters.num_locks_so_far 
	+ 191128.03 * parameters.total_wait_locks 
	- 0.001 * parameters.mean_wait_of_all 
	- 370511280.6235 * parameters.cpu_usage 
	+ 0.6563 * parameters.avg_work_of_same_past_second 
	- 1.1133 * parameters.avg_wait_of_same_past_second 
	+ 0.164 * parameters.avg_latency_of_same_last_20 
	- 0.0011 * parameters.max_latency_of_same_last_50 
	+ 722500796.4316;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM171(work_wait &parameters) {
  double actual_remaining = 
	0.0428 * parameters.work_so_far 
	+ 0.0237 * parameters.wait_so_far 
	+ 4077617.5617 * parameters.num_locks_so_far 
	- 15387.9033 * parameters.total_wait_locks 
	+ 0.9474 * parameters.mean_wait_of_all 
	- 1761871.056 * parameters.cpu_usage 
	+ 0.0936 * parameters.avg_work_of_same_past_second 
	- 0.0048 * parameters.avg_wait_of_same_past_second 
	+ 0.025 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 100576382.0098;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM172(work_wait &parameters) {
  double actual_remaining = 
	0.0428 * parameters.work_so_far 
	+ 0.0237 * parameters.wait_so_far 
	+ 4077617.5617 * parameters.num_locks_so_far 
	- 15387.9033 * parameters.total_wait_locks 
	+ 0.0949 * parameters.mean_wait_of_all 
	- 1962054688.3312 * parameters.cpu_usage 
	+ 0.2013 * parameters.avg_work_of_same_past_second 
	- 0.741 * parameters.avg_wait_of_same_past_second 
	+ 0.025 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 2362075110.8749;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM173(work_wait &parameters) {
  double actual_remaining = 
	0.0428 * parameters.work_so_far 
	+ 0.0237 * parameters.wait_so_far 
	+ 12397568.8674 * parameters.num_locks_so_far 
	- 34052.5512 * parameters.total_wait_locks 
	+ 0.1874 * parameters.mean_wait_of_all 
	- 1761871.056 * parameters.cpu_usage 
	+ 0.0935 * parameters.avg_work_of_same_past_second 
	- 0.0048 * parameters.avg_wait_of_same_past_second 
	+ 0.0595 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 378988024.9477;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM174(work_wait &parameters) {
  double actual_remaining = 
	0.7729 * parameters.work_so_far 
	+ 0.6575 * parameters.wait_so_far 
	+ 2057465.9823 * parameters.num_locks_so_far 
	- 917.5578 * parameters.total_wait_locks 
	+ 1.181 * parameters.mean_wait_of_all 
	- 5423942.7754 * parameters.cpu_usage 
	+ 0.3797 * parameters.avg_work_of_same_past_second 
	- 0.3937 * parameters.avg_wait_of_same_past_second 
	+ 0.2296 * parameters.avg_latency_of_same_last_20 
	+ 0.0048 * parameters.max_latency_of_same_last_50 
	+ 129297384.5182;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM175(work_wait &parameters) {
  double actual_remaining = 
	6.1886 * parameters.work_so_far 
	+ 0.4086 * parameters.wait_so_far 
	+ 5231542.7197 * parameters.num_locks_so_far 
	+ 11230.1028 * parameters.total_wait_locks 
	+ 0.0781 * parameters.mean_wait_of_all 
	- 5423942.7754 * parameters.cpu_usage 
	+ 0.2845 * parameters.avg_work_of_same_past_second 
	+ 0.1871 * parameters.avg_wait_of_same_past_second 
	+ 0.0092 * parameters.avg_latency_of_same_last_20 
	+ 0.0457 * parameters.max_latency_of_same_last_50 
	+ 300761131.0416;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM176(work_wait &parameters) {
  double actual_remaining = 
	0.6286 * parameters.work_so_far 
	+ 0.3855 * parameters.wait_so_far 
	+ 5231542.7197 * parameters.num_locks_so_far 
	+ 11230.1028 * parameters.total_wait_locks 
	+ 0.0781 * parameters.mean_wait_of_all 
	- 5423942.7754 * parameters.cpu_usage 
	+ 0.2564 * parameters.avg_work_of_same_past_second 
	+ 0.1871 * parameters.avg_wait_of_same_past_second 
	+ 0.0092 * parameters.avg_latency_of_same_last_20 
	+ 0.0457 * parameters.max_latency_of_same_last_50 
	+ 489656349.6137;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM177(work_wait &parameters) {
  double actual_remaining = 
	0.7925 * parameters.work_so_far 
	+ 0.1958 * parameters.wait_so_far 
	+ 5231542.7197 * parameters.num_locks_so_far 
	+ 11230.1028 * parameters.total_wait_locks 
	+ 0.0781 * parameters.mean_wait_of_all 
	- 5423942.7754 * parameters.cpu_usage 
	+ 0.0261 * parameters.avg_work_of_same_past_second 
	+ 0.1871 * parameters.avg_wait_of_same_past_second 
	+ 0.0092 * parameters.avg_latency_of_same_last_20 
	+ 0.2737 * parameters.max_latency_of_same_last_50 
	+ 447576890.5755;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM178(work_wait &parameters) {
  double actual_remaining = 
	1.0833 * parameters.work_so_far 
	+ 0.2431 * parameters.wait_so_far 
	+ 5231542.7197 * parameters.num_locks_so_far 
	- 1106235.947 * parameters.total_wait_locks 
	+ 3.1647 * parameters.mean_wait_of_all 
	- 5423942.7754 * parameters.cpu_usage 
	+ 0.0261 * parameters.avg_work_of_same_past_second 
	+ 8.925 * parameters.avg_wait_of_same_past_second 
	+ 0.3318 * parameters.avg_latency_of_same_last_20 
	+ 0.009 * parameters.max_latency_of_same_last_50 
	- 1438789652.3334;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM179(work_wait &parameters) {
  double actual_remaining = 
	1.0833 * parameters.work_so_far 
	+ 0.2431 * parameters.wait_so_far 
	+ 5231542.7197 * parameters.num_locks_so_far 
	- 1106235.947 * parameters.total_wait_locks 
	+ 3.1647 * parameters.mean_wait_of_all 
	- 5423942.7754 * parameters.cpu_usage 
	+ 0.0261 * parameters.avg_work_of_same_past_second 
	+ 9.8836 * parameters.avg_wait_of_same_past_second 
	+ 0.3318 * parameters.avg_latency_of_same_last_20 
	+ 0.009 * parameters.max_latency_of_same_last_50 
	- 1643297705.1768;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM180(work_wait &parameters) {
  double actual_remaining = 
	1.0833 * parameters.work_so_far 
	+ 0.2431 * parameters.wait_so_far 
	+ 5231542.7197 * parameters.num_locks_so_far 
	- 767609.8713 * parameters.total_wait_locks 
	+ 2.2294 * parameters.mean_wait_of_all 
	- 5423942.7754 * parameters.cpu_usage 
	+ 0.0261 * parameters.avg_work_of_same_past_second 
	+ 0.2972 * parameters.avg_wait_of_same_past_second 
	+ 0.5308 * parameters.avg_latency_of_same_last_20 
	+ 0.009 * parameters.max_latency_of_same_last_50 
	+ 466089130.0337;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM181(work_wait &parameters) {
  double actual_remaining = 
	1.1724 * parameters.work_so_far 
	+ 0.2431 * parameters.wait_so_far 
	+ 5231542.7197 * parameters.num_locks_so_far 
	- 1214498.7314 * parameters.total_wait_locks 
	+ 0.0781 * parameters.mean_wait_of_all 
	- 5423942.7754 * parameters.cpu_usage 
	+ 0.0261 * parameters.avg_work_of_same_past_second 
	+ 0.2972 * parameters.avg_wait_of_same_past_second 
	- 0.6497 * parameters.avg_latency_of_same_last_20 
	+ 0.009 * parameters.max_latency_of_same_last_50 
	+ 1916120137.6821;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM182(work_wait &parameters) {
  double actual_remaining = 
	1.0798 * parameters.work_so_far 
	+ 0.7427 * parameters.wait_so_far 
	- 167125.1295 * parameters.num_locks_so_far 
	- 276620.9965 * parameters.total_wait_locks 
	+ 1.5328 * parameters.mean_wait_of_all 
	- 5423942.7754 * parameters.cpu_usage 
	+ 0.3025 * parameters.avg_work_of_same_past_second 
	- 0.0048 * parameters.avg_wait_of_same_past_second 
	+ 0.1613 * parameters.avg_latency_of_same_last_20 
	+ 0.0371 * parameters.max_latency_of_same_last_50 
	- 2558012.2597;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM183(work_wait &parameters) {
  double actual_remaining = 
	0.5883 * parameters.work_so_far 
	+ 0.8329 * parameters.wait_so_far 
	- 3326526.2184 * parameters.num_locks_so_far 
	- 1014671.5406 * parameters.total_wait_locks 
	+ 5.7621 * parameters.mean_wait_of_all 
	- 675689942.8448 * parameters.cpu_usage 
	+ 0.485 * parameters.avg_work_of_same_past_second 
	- 0.0048 * parameters.avg_wait_of_same_past_second 
	+ 0.0097 * parameters.avg_latency_of_same_last_20 
	+ 0.0015 * parameters.max_latency_of_same_last_50 
	+ 657527854.1184;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM184(work_wait &parameters) {
  double actual_remaining = 
	0.015 * parameters.work_so_far 
	- 0.0522 * parameters.wait_so_far 
	+ 971887.2661 * parameters.num_locks_so_far 
	+ 15640.236 * parameters.total_wait_locks 
	- 0.0636 * parameters.mean_wait_of_all 
	- 1057604519.9735 * parameters.cpu_usage 
	- 2.2218 * parameters.avg_work_of_same_past_second 
	- 0.9906 * parameters.avg_wait_of_same_past_second 
	+ 0.2807 * parameters.avg_latency_of_same_last_20 
	- 0.0108 * parameters.max_latency_of_same_last_50 
	+ 2541972017.5916;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM185(work_wait &parameters) {
  double actual_remaining = 
	0.015 * parameters.work_so_far 
	- 0.0432 * parameters.wait_so_far 
	+ 971887.2661 * parameters.num_locks_so_far 
	+ 15640.236 * parameters.total_wait_locks 
	- 0.0636 * parameters.mean_wait_of_all 
	- 31233895.6479 * parameters.cpu_usage 
	- 0.0726 * parameters.avg_work_of_same_past_second 
	+ 0.0725 * parameters.avg_wait_of_same_past_second 
	+ 0.0329 * parameters.avg_latency_of_same_last_20 
	- 0.0261 * parameters.max_latency_of_same_last_50 
	+ 376018250.5488;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM186(work_wait &parameters) {
  double actual_remaining = 
	0.015 * parameters.work_so_far 
	- 0.0432 * parameters.wait_so_far 
	+ 971887.2661 * parameters.num_locks_so_far 
	+ 15640.236 * parameters.total_wait_locks 
	- 0.0636 * parameters.mean_wait_of_all 
	- 31233895.6479 * parameters.cpu_usage 
	- 0.0726 * parameters.avg_work_of_same_past_second 
	+ 0.0198 * parameters.avg_wait_of_same_past_second 
	+ 0.0329 * parameters.avg_latency_of_same_last_20 
	- 0.0173 * parameters.max_latency_of_same_last_50 
	+ 485522208.4405;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM187(work_wait &parameters) {
  double actual_remaining = 
	2.1653 * parameters.work_so_far 
	+ 0.8094 * parameters.wait_so_far 
	+ 971887.2661 * parameters.num_locks_so_far 
	- 96051.987 * parameters.total_wait_locks 
	+ 1.9404 * parameters.mean_wait_of_all 
	+ 194014870.9022 * parameters.cpu_usage 
	- 0.0426 * parameters.avg_work_of_same_past_second 
	- 0.1413 * parameters.avg_wait_of_same_past_second 
	+ 0.0817 * parameters.avg_latency_of_same_last_20 
	- 0.0141 * parameters.max_latency_of_same_last_50 
	+ 20493475.4768;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM188(work_wait &parameters) {
  double actual_remaining = 
	1.5245 * parameters.work_so_far 
	- 0.0054 * parameters.wait_so_far 
	+ 971887.2661 * parameters.num_locks_so_far 
	- 1446519.5555 * parameters.total_wait_locks 
	+ 3.5059 * parameters.mean_wait_of_all 
	- 5640132357.1379 * parameters.cpu_usage 
	- 0.0426 * parameters.avg_work_of_same_past_second 
	- 0.1413 * parameters.avg_wait_of_same_past_second 
	+ 0.302 * parameters.avg_latency_of_same_last_20 
	- 0.0141 * parameters.max_latency_of_same_last_50 
	+ 6202206095.5687;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM189(work_wait &parameters) {
  double actual_remaining = 
	2.0308 * parameters.work_so_far 
	- 0.0054 * parameters.wait_so_far 
	+ 971887.2661 * parameters.num_locks_so_far 
	+ 464795.9076 * parameters.total_wait_locks 
	+ 0.4842 * parameters.mean_wait_of_all 
	- 808694388.1841 * parameters.cpu_usage 
	- 0.0426 * parameters.avg_work_of_same_past_second 
	- 0.5127 * parameters.avg_wait_of_same_past_second 
	+ 0.0217 * parameters.avg_latency_of_same_last_20 
	- 0.0765 * parameters.max_latency_of_same_last_50 
	+ 1379297760.5229;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM190(work_wait &parameters) {
  double actual_remaining = 
	2.0308 * parameters.work_so_far 
	- 0.0054 * parameters.wait_so_far 
	+ 971887.2661 * parameters.num_locks_so_far 
	+ 464795.9076 * parameters.total_wait_locks 
	+ 3.9293 * parameters.mean_wait_of_all 
	- 696720198.6283 * parameters.cpu_usage 
	- 0.0426 * parameters.avg_work_of_same_past_second 
	- 0.1425 * parameters.avg_wait_of_same_past_second 
	+ 0.0217 * parameters.avg_latency_of_same_last_20 
	- 0.1058 * parameters.max_latency_of_same_last_50 
	+ 582765551.1079;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM191(work_wait &parameters) {
  double actual_remaining = 
	2.0308 * parameters.work_so_far 
	- 0.0054 * parameters.wait_so_far 
	+ 971887.2661 * parameters.num_locks_so_far 
	+ 464795.9076 * parameters.total_wait_locks 
	+ 4.8225 * parameters.mean_wait_of_all 
	- 696720198.6283 * parameters.cpu_usage 
	- 0.0426 * parameters.avg_work_of_same_past_second 
	- 0.0465 * parameters.avg_wait_of_same_past_second 
	+ 0.0217 * parameters.avg_latency_of_same_last_20 
	- 0.1172 * parameters.max_latency_of_same_last_50 
	+ 383093546.7914;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM192(work_wait &parameters) {
  double actual_remaining = 
	2.7767 * parameters.work_so_far 
	- 0.0054 * parameters.wait_so_far 
	+ 971887.2661 * parameters.num_locks_so_far 
	+ 464795.9076 * parameters.total_wait_locks 
	+ 2.475 * parameters.mean_wait_of_all 
	- 1923614046.7444 * parameters.cpu_usage 
	- 0.0426 * parameters.avg_work_of_same_past_second 
	- 0.7938 * parameters.avg_wait_of_same_past_second 
	- 0.2162 * parameters.avg_latency_of_same_last_20 
	- 0.0197 * parameters.max_latency_of_same_last_50 
	+ 2404863646.9659;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM193(work_wait &parameters) {
  double actual_remaining = 
	2.7767 * parameters.work_so_far 
	- 0.0054 * parameters.wait_so_far 
	+ 971887.2661 * parameters.num_locks_so_far 
	- 7154733.0198 * parameters.total_wait_locks 
	+ 2.475 * parameters.mean_wait_of_all 
	- 1828156434.8117 * parameters.cpu_usage 
	- 0.0426 * parameters.avg_work_of_same_past_second 
	- 0.7938 * parameters.avg_wait_of_same_past_second 
	+ 0.0217 * parameters.avg_latency_of_same_last_20 
	- 0.0197 * parameters.max_latency_of_same_last_50 
	+ 8021568878.1313;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM194(work_wait &parameters) {
  double actual_remaining = 
	2.7767 * parameters.work_so_far 
	- 0.0054 * parameters.wait_so_far 
	+ 971887.2661 * parameters.num_locks_so_far 
	+ 1009354.7932 * parameters.total_wait_locks 
	+ 2.475 * parameters.mean_wait_of_all 
	- 1828156434.8117 * parameters.cpu_usage 
	- 0.0426 * parameters.avg_work_of_same_past_second 
	- 0.7938 * parameters.avg_wait_of_same_past_second 
	+ 0.0217 * parameters.avg_latency_of_same_last_20 
	- 0.0197 * parameters.max_latency_of_same_last_50 
	+ 1573877798.4411;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM195(work_wait &parameters) {
  double actual_remaining = 
	0.015 * parameters.work_so_far 
	- 0.0054 * parameters.wait_so_far 
	+ 971887.2661 * parameters.num_locks_so_far 
	+ 270509.1601 * parameters.total_wait_locks 
	+ 1.8281 * parameters.mean_wait_of_all 
	- 41866324.9461 * parameters.cpu_usage 
	- 0.0426 * parameters.avg_work_of_same_past_second 
	- 0.3073 * parameters.avg_wait_of_same_past_second 
	+ 0.2746 * parameters.avg_latency_of_same_last_20 
	+ 0.0003 * parameters.max_latency_of_same_last_50 
	- 14552345.5798;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM196(work_wait &parameters) {
  double actual_remaining = 
	0.015 * parameters.work_so_far 
	- 0.1428 * parameters.wait_so_far 
	+ 971887.2661 * parameters.num_locks_so_far 
	- 260892.4308 * parameters.total_wait_locks 
	+ 2.5128 * parameters.mean_wait_of_all 
	- 16299532.7303 * parameters.cpu_usage 
	- 0.0033 * parameters.avg_work_of_same_past_second 
	- 0.9577 * parameters.avg_wait_of_same_past_second 
	+ 0.1684 * parameters.avg_latency_of_same_last_20 
	+ 0.0003 * parameters.max_latency_of_same_last_50 
	+ 372505004.8404;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM197(work_wait &parameters) {
  double actual_remaining = 
	2.8207 * parameters.work_so_far 
	- 0.1632 * parameters.wait_so_far 
	+ 109359208.1229 * parameters.num_locks_so_far 
	+ 328634.8909 * parameters.total_wait_locks 
	+ 0.0018 * parameters.mean_wait_of_all 
	+ 669094937.71 * parameters.cpu_usage 
	+ 1.194 * parameters.avg_work_of_same_past_second 
	- 0.4698 * parameters.avg_wait_of_same_past_second 
	+ 0.0097 * parameters.avg_latency_of_same_last_20 
	+ 0.0003 * parameters.max_latency_of_same_last_50 
	- 1149834567.1201;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM198(work_wait &parameters) {
  double actual_remaining = 
	0.5932 * parameters.work_so_far 
	+ 0.646 * parameters.wait_so_far 
	- 856273.1682 * parameters.num_locks_so_far 
	- 868662.6143 * parameters.total_wait_locks 
	+ 5.6189 * parameters.mean_wait_of_all 
	- 11266012.3551 * parameters.cpu_usage 
	+ 0.0508 * parameters.avg_work_of_same_past_second 
	- 0.085 * parameters.avg_wait_of_same_past_second 
	+ 0.2505 * parameters.avg_latency_of_same_last_20 
	+ 0.0009 * parameters.max_latency_of_same_last_50 
	- 27765824.4987;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM199(work_wait &parameters) {
  double actual_remaining = 
	0.5932 * parameters.work_so_far 
	+ 0.6873 * parameters.wait_so_far 
	+ 169516563.468 * parameters.num_locks_so_far 
	- 1285687.9069 * parameters.total_wait_locks 
	+ 4.1768 * parameters.mean_wait_of_all 
	- 11266012.3551 * parameters.cpu_usage 
	+ 0.0508 * parameters.avg_work_of_same_past_second 
	- 0.085 * parameters.avg_wait_of_same_past_second 
	+ 0.8066 * parameters.avg_latency_of_same_last_20 
	- 0.0765 * parameters.max_latency_of_same_last_50 
	- 958431867.2073;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM200(work_wait &parameters) {
  double actual_remaining = 
	0.5932 * parameters.work_so_far 
	+ 0.6873 * parameters.wait_so_far 
	+ 181551410.2017 * parameters.num_locks_so_far 
	- 1285687.9069 * parameters.total_wait_locks 
	+ 4.1768 * parameters.mean_wait_of_all 
	- 11266012.3551 * parameters.cpu_usage 
	+ 0.0508 * parameters.avg_work_of_same_past_second 
	- 0.085 * parameters.avg_wait_of_same_past_second 
	+ 0.7326 * parameters.avg_latency_of_same_last_20 
	- 0.0765 * parameters.max_latency_of_same_last_50 
	- 952363277.5862;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM201(work_wait &parameters) {
  double actual_remaining = 
	0.5932 * parameters.work_so_far 
	+ 0.8713 * parameters.wait_so_far 
	+ 140471795.3033 * parameters.num_locks_so_far 
	- 1501331.5325 * parameters.total_wait_locks 
	+ 4.1768 * parameters.mean_wait_of_all 
	- 11266012.3551 * parameters.cpu_usage 
	+ 0.0508 * parameters.avg_work_of_same_past_second 
	- 0.085 * parameters.avg_wait_of_same_past_second 
	+ 0.686 * parameters.avg_latency_of_same_last_20 
	- 0.0765 * parameters.max_latency_of_same_last_50 
	- 594122322.1428;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM202(work_wait &parameters) {
  double actual_remaining = 
	0.5932 * parameters.work_so_far 
	+ 0.2502 * parameters.wait_so_far 
	- 8788347.1633 * parameters.num_locks_so_far 
	- 1116757.2642 * parameters.total_wait_locks 
	+ 6.1963 * parameters.mean_wait_of_all 
	- 11266012.3551 * parameters.cpu_usage 
	- 0.4099 * parameters.avg_work_of_same_past_second 
	- 0.085 * parameters.avg_wait_of_same_past_second 
	+ 0.4072 * parameters.avg_latency_of_same_last_20 
	- 0.0491 * parameters.max_latency_of_same_last_50 
	+ 383162957.7709;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM203(work_wait &parameters) {
  double actual_remaining = 
	0.5932 * parameters.work_so_far 
	+ 0.2502 * parameters.wait_so_far 
	- 5112507.9949 * parameters.num_locks_so_far 
	- 881452.2162 * parameters.total_wait_locks 
	+ 4.8848 * parameters.mean_wait_of_all 
	- 11266012.3551 * parameters.cpu_usage 
	- 0.1964 * parameters.avg_work_of_same_past_second 
	- 0.085 * parameters.avg_wait_of_same_past_second 
	+ 0.2619 * parameters.avg_latency_of_same_last_20 
	- 0.0491 * parameters.max_latency_of_same_last_50 
	+ 378949881.2059;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM204(work_wait &parameters) {
  double actual_remaining = 
	1.2501 * parameters.work_so_far 
	+ 0.3085 * parameters.wait_so_far 
	- 856273.1682 * parameters.num_locks_so_far 
	- 131334.3287 * parameters.total_wait_locks 
	+ 0.8417 * parameters.mean_wait_of_all 
	- 107238556.8432 * parameters.cpu_usage 
	+ 0.1304 * parameters.avg_work_of_same_past_second 
	+ 0.0154 * parameters.avg_wait_of_same_past_second 
	+ 0.0132 * parameters.avg_latency_of_same_last_20 
	+ 0.0134 * parameters.max_latency_of_same_last_50 
	+ 498844529.8949;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM205(work_wait &parameters) {
  double actual_remaining = 
	1.2501 * parameters.work_so_far 
	+ 0.3085 * parameters.wait_so_far 
	- 856273.1682 * parameters.num_locks_so_far 
	- 223276.8239 * parameters.total_wait_locks 
	+ 1.4623 * parameters.mean_wait_of_all 
	- 107238556.8432 * parameters.cpu_usage 
	+ 0.1304 * parameters.avg_work_of_same_past_second 
	+ 0.1778 * parameters.avg_wait_of_same_past_second 
	+ 0.0132 * parameters.avg_latency_of_same_last_20 
	+ 0.0134 * parameters.max_latency_of_same_last_50 
	+ 493419884.7128;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM206(work_wait &parameters) {
  double actual_remaining = 
	1.8256 * parameters.work_so_far 
	+ 0.5302 * parameters.wait_so_far 
	+ 32014080.4749 * parameters.num_locks_so_far 
	- 74497.1499 * parameters.total_wait_locks 
	+ 0.4581 * parameters.mean_wait_of_all 
	- 258052555.3245 * parameters.cpu_usage 
	+ 0.2554 * parameters.avg_work_of_same_past_second 
	- 0.085 * parameters.avg_wait_of_same_past_second 
	- 1.2174 * parameters.avg_latency_of_same_last_20 
	+ 0.3268 * parameters.max_latency_of_same_last_50 
	+ 635045498.9512;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM207(work_wait &parameters) {
  double actual_remaining = 
	2.7026 * parameters.work_so_far 
	+ 0.9698 * parameters.wait_so_far 
	- 7672677.9474 * parameters.num_locks_so_far 
	- 608094.589 * parameters.total_wait_locks 
	+ 4.7953 * parameters.mean_wait_of_all 
	- 11266012.3551 * parameters.cpu_usage 
	+ 0.9131 * parameters.avg_work_of_same_past_second 
	- 0.7123 * parameters.avg_wait_of_same_past_second 
	+ 0.0314 * parameters.avg_latency_of_same_last_20 
	+ 0.0554 * parameters.max_latency_of_same_last_50 
	- 241413957.9598;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM208(work_wait &parameters) {
  double actual_remaining = 
	0.9258 * parameters.work_so_far 
	+ 0.8899 * parameters.wait_so_far 
	- 11158625.2145 * parameters.num_locks_so_far 
	+ 937.4478 * parameters.total_wait_locks 
	+ 0.0422 * parameters.mean_wait_of_all 
	- 11266012.3551 * parameters.cpu_usage 
	+ 0.5755 * parameters.avg_work_of_same_past_second 
	- 1.0577 * parameters.avg_wait_of_same_past_second 
	+ 0.0208 * parameters.avg_latency_of_same_last_20 
	+ 0.0009 * parameters.max_latency_of_same_last_50 
	+ 772623918.6903;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM209(work_wait &parameters) {
  double actual_remaining = 
	0.6399 * parameters.work_so_far 
	+ 0.0524 * parameters.wait_so_far 
	- 6311887.7568 * parameters.num_locks_so_far 
	- 4044.7363 * parameters.total_wait_locks 
	+ 0.0913 * parameters.mean_wait_of_all 
	- 622891802.3329 * parameters.cpu_usage 
	+ 0.4771 * parameters.avg_work_of_same_past_second 
	- 1.5 * parameters.avg_wait_of_same_past_second 
	+ 0.197 * parameters.avg_latency_of_same_last_20 
	+ 0.1361 * parameters.max_latency_of_same_last_50 
	+ 1203298927.3671;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM210(work_wait &parameters) {
  double actual_remaining = 
	0.9695 * parameters.work_so_far 
	+ 0.9114 * parameters.wait_so_far 
	- 265291.549 * parameters.num_locks_so_far 
	+ 3485.5877 * parameters.total_wait_locks 
	+ 2.4092 * parameters.mean_wait_of_all 
	- 19285468.0026 * parameters.cpu_usage 
	+ 0.0294 * parameters.avg_work_of_same_past_second 
	- 0.5161 * parameters.avg_wait_of_same_past_second 
	+ 0.2499 * parameters.avg_latency_of_same_last_20 
	+ 0.0003 * parameters.max_latency_of_same_last_50 
	- 30570309.2273;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM211(work_wait &parameters) {
  double actual_remaining = 
	0.4931 * parameters.work_so_far 
	+ 0.0218 * parameters.wait_so_far 
	- 5715153.4325 * parameters.num_locks_so_far 
	+ 1208729.4044 * parameters.total_wait_locks 
	- 2.1362 * parameters.mean_wait_of_all 
	+ 135061481.7288 * parameters.cpu_usage 
	- 0.0009 * parameters.avg_work_of_same_past_second 
	- 0.0103 * parameters.avg_wait_of_same_past_second 
	+ 0.0064 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 482957693.5491;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM212(work_wait &parameters) {
  double actual_remaining = 
	0.3623 * parameters.work_so_far 
	+ 0.0611 * parameters.wait_so_far 
	+ 82077842.5681 * parameters.num_locks_so_far 
	+ 3051060.4762 * parameters.total_wait_locks 
	- 11.3092 * parameters.mean_wait_of_all 
	+ 67265823.4675 * parameters.cpu_usage 
	- 0.0009 * parameters.avg_work_of_same_past_second 
	+ 0.3827 * parameters.avg_wait_of_same_past_second 
	+ 0.3696 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 194051023.5128;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM213(work_wait &parameters) {
  double actual_remaining = 
	-2.5217 * parameters.work_so_far 
	+ 0.0685 * parameters.wait_so_far 
	- 829510.1839 * parameters.num_locks_so_far 
	+ 738609.1455 * parameters.total_wait_locks 
	- 2.5438 * parameters.mean_wait_of_all 
	+ 67265823.4675 * parameters.cpu_usage 
	- 0.0009 * parameters.avg_work_of_same_past_second 
	- 0.0103 * parameters.avg_wait_of_same_past_second 
	+ 0.0064 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 627671686.4612;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM214(work_wait &parameters) {
  double actual_remaining = 
	0.3471 * parameters.work_so_far 
	- 0.398 * parameters.wait_so_far 
	- 8000923.9752 * parameters.num_locks_so_far 
	+ 252178.2879 * parameters.total_wait_locks 
	- 0.8741 * parameters.mean_wait_of_all 
	- 10598496.9119 * parameters.cpu_usage 
	- 0.4724 * parameters.avg_work_of_same_past_second 
	- 0.0103 * parameters.avg_wait_of_same_past_second 
	+ 0.0064 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 1373172877.9234;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM215(work_wait &parameters) {
  double actual_remaining = 
	0.2015 * parameters.work_so_far 
	+ 0.5692 * parameters.wait_so_far 
	- 514270.6947 * parameters.num_locks_so_far 
	+ 134361.6763 * parameters.total_wait_locks 
	- 0.5106 * parameters.mean_wait_of_all 
	- 10598496.9119 * parameters.cpu_usage 
	+ 0.0094 * parameters.avg_work_of_same_past_second 
	- 0.0103 * parameters.avg_wait_of_same_past_second 
	+ 0.0064 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 520419934.8166;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM216(work_wait &parameters) {
  double actual_remaining = 
	0.8685 * parameters.work_so_far 
	+ 0.8735 * parameters.wait_so_far 
	- 11484560.9637 * parameters.num_locks_so_far 
	+ 554994.0496 * parameters.total_wait_locks 
	- 1.0075 * parameters.mean_wait_of_all 
	- 10598496.9119 * parameters.cpu_usage 
	+ 0.0094 * parameters.avg_work_of_same_past_second 
	- 0.2369 * parameters.avg_wait_of_same_past_second 
	+ 0.0064 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 1043958929.4826;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM217(work_wait &parameters) {
  double actual_remaining = 
	-89.4113 * parameters.work_so_far 
	- 0.0016 * parameters.wait_so_far 
	- 167254430.3701 * parameters.num_locks_so_far 
	+ 162364.4457 * parameters.total_wait_locks 
	+ 2.4694 * parameters.mean_wait_of_all 
	- 285478136.4425 * parameters.cpu_usage 
	+ 0.4962 * parameters.avg_work_of_same_past_second 
	- 0.0398 * parameters.avg_wait_of_same_past_second 
	+ 0.0082 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 682206762.5236;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM218(work_wait &parameters) {
  double actual_remaining = 
	-78.4351 * parameters.work_so_far 
	+ 0.0059 * parameters.wait_so_far 
	- 300311.6725 * parameters.num_locks_so_far 
	+ 149351.2475 * parameters.total_wait_locks 
	- 0.3393 * parameters.mean_wait_of_all 
	- 1490522117.0576 * parameters.cpu_usage 
	+ 0.0737 * parameters.avg_work_of_same_past_second 
	- 0.0398 * parameters.avg_wait_of_same_past_second 
	+ 0.0082 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 1956360530.7213;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM219(work_wait &parameters) {
  double actual_remaining = 
	0.8043 * parameters.work_so_far 
	+ 0.2829 * parameters.wait_so_far 
	- 7662771.0268 * parameters.num_locks_so_far 
	+ 686803.4031 * parameters.total_wait_locks 
	- 1.9479 * parameters.mean_wait_of_all 
	- 895601323.3746 * parameters.cpu_usage 
	+ 0.1707 * parameters.avg_work_of_same_past_second 
	- 0.0298 * parameters.avg_wait_of_same_past_second 
	+ 0.0082 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 1688040011.3525;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM220(work_wait &parameters) {
  double actual_remaining = 
	1.1333 * parameters.work_so_far 
	+ 1.0267 * parameters.wait_so_far 
	- 3353228.515 * parameters.num_locks_so_far 
	+ 63710.932 * parameters.total_wait_locks 
	- 0.0667 * parameters.mean_wait_of_all 
	- 113229871.286 * parameters.cpu_usage 
	+ 0.3233 * parameters.avg_work_of_same_past_second 
	- 0.8074 * parameters.avg_wait_of_same_past_second 
	+ 0.0082 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 385982493.5318;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
tpcc_estimate(work_wait &parameters){

  if (parameters.avg_work_of_same_past_second <= 82979500) {

    if (parameters.work_so_far <= 265849.5) {

      if (parameters.avg_work_of_same_past_second <= 33119300) {

        if (parameters.avg_latency_of_same_last_20 <= 439617000) {

          if (parameters.work_so_far <= 18356.5) {

            if (parameters.wait_so_far <= 3662.5) {
              return tpcc_LM1(parameters);
            } else {

              if (parameters.avg_wait_of_same_past_second <= 74906400) {
                return tpcc_LM2(parameters);
              } else {

                if (parameters.max_latency_of_same_last_50 <= 655359000) {

                  if (parameters.cpu_usage <= 0.995) {

                    if (parameters.avg_work_of_same_past_second <= 17114650) {
                      return tpcc_LM3(parameters);
                    } else {

                      if (parameters.max_latency_of_same_last_50 <= 185939000) {

                        if (parameters.avg_wait_of_same_past_second <= 169270500) {
                          return tpcc_LM4(parameters);
                        } else {
                          return tpcc_LM5(parameters);
                        }
                      } else {

                        if (parameters.max_latency_of_same_last_50 <= 590900500) {
                          return tpcc_LM6(parameters);
                        } else {
                          return tpcc_LM7(parameters);
                        }
                      }
                    }
                  } else {
                    return tpcc_LM8(parameters);
                  }
                } else {
                  return tpcc_LM9(parameters);
                }
              }
            }
          } else {

            if (parameters.wait_so_far <= 213550718) {

              if (parameters.avg_work_of_same_past_second <= 26239100) {

                if (parameters.total_wait_locks <= 360.5) {

                  if (parameters.mean_wait_of_all <= 103721000) {

                    if (parameters.cpu_usage <= 0.942) {
                      return tpcc_LM10(parameters);
                    } else {

                      if (parameters.avg_work_of_same_past_second <= 22947950) {

                        if (parameters.avg_wait_of_same_past_second <= 96279750) {

                          if (parameters.cpu_usage <= 0.976) {

                            if (parameters.mean_wait_of_all <= 58892350) {

                              if (parameters.avg_latency_of_same_last_20 <= 209186000) {

                                if (parameters.avg_wait_of_same_past_second <= 21179850) {
                                  return tpcc_LM11(parameters);
                                } else {

                                  if (parameters.work_so_far <= 20112) {
                                    return tpcc_LM12(parameters);
                                  } else {

                                    if (parameters.work_so_far <= 22689) {

                                      if (parameters.mean_wait_of_all <= 57783750) {
                                        return tpcc_LM13(parameters);
                                      } else {
                                        return tpcc_LM14(parameters);
                                      }
                                    } else {
                                      return tpcc_LM15(parameters);
                                    }
                                  }
                                }
                              } else {

                                if (parameters.max_latency_of_same_last_50 <= 632389000) {

                                  if (parameters.wait_so_far <= 14085443.5) {
                                    return tpcc_LM16(parameters);
                                  } else {
                                    return tpcc_LM17(parameters);
                                  }
                                } else {

                                  if (parameters.avg_latency_of_same_last_20 <= 310215000) {
                                    return tpcc_LM18(parameters);
                                  } else {

                                    if (parameters.wait_so_far <= 74630935.5) {

                                      if (parameters.avg_work_of_same_past_second <= 13184950) {
                                        return tpcc_LM19(parameters);
                                      } else {
                                        return tpcc_LM20(parameters);
                                      }
                                    } else {
                                      return tpcc_LM21(parameters);
                                    }
                                  }
                                }
                              }
                            } else {
                              return tpcc_LM22(parameters);
                            }
                          } else {

                            if (parameters.avg_wait_of_same_past_second <= 23157700) {
                              return tpcc_LM23(parameters);
                            } else {

                              if (parameters.mean_wait_of_all <= 60950450) {
                                return tpcc_LM24(parameters);
                              } else {
                                return tpcc_LM25(parameters);
                              }
                            }
                          }
                        } else {
                          return tpcc_LM26(parameters);
                        }
                      } else {

                        if (parameters.work_so_far <= 31459.5) {
                          return tpcc_LM27(parameters);
                        } else {

                          if (parameters.wait_so_far <= 7630854) {

                            if (parameters.avg_work_of_same_past_second <= 23951900) {
                              return tpcc_LM28(parameters);
                            } else {

                              if (parameters.mean_wait_of_all <= 98477550) {

                                if (parameters.avg_work_of_same_past_second <= 25015850) {
                                  return tpcc_LM29(parameters);
                                } else {
                                  return tpcc_LM30(parameters);
                                }
                              } else {
                                return tpcc_LM31(parameters);
                              }
                            }
                          } else {

                            if (parameters.mean_wait_of_all <= 72900100) {

                              if (parameters.wait_so_far <= 17892820.5) {
                                return tpcc_LM32(parameters);
                              } else {
                                return tpcc_LM33(parameters);
                              }
                            } else {
                              return tpcc_LM34(parameters);
                            }
                          }
                        }
                      }
                    }
                  } else {
                    return tpcc_LM35(parameters);
                  }
                } else {

                  if (parameters.work_so_far <= 27667.5) {

                    if (parameters.avg_latency_of_same_last_20 <= 380674000) {

                      if (parameters.work_so_far <= 24951) {

                        if (parameters.avg_latency_of_same_last_20 <= 280599500) {

                          if (parameters.work_so_far <= 23935) {
                            return tpcc_LM36(parameters);
                          } else {
                            return tpcc_LM37(parameters);
                          }
                        } else {

                          if (parameters.mean_wait_of_all <= 131010500) {
                            return tpcc_LM38(parameters);
                          } else {
                            return tpcc_LM39(parameters);
                          }
                        }
                      } else {

                        if (parameters.work_so_far <= 26441.5) {
                          return tpcc_LM40(parameters);
                        } else {
                          return tpcc_LM41(parameters);
                        }
                      }
                    } else {
                      return tpcc_LM42(parameters);
                    }
                  } else {
                    return tpcc_LM43(parameters);
                  }
                }
              } else {

                if (parameters.cpu_usage <= 0.954) {

                  if (parameters.cpu_usage <= 0.944) {

                    if (parameters.work_so_far <= 35679) {

                      if (parameters.cpu_usage <= 0.905) {
                        return tpcc_LM44(parameters);
                      } else {

                        if (parameters.wait_so_far <= 51073493.5) {

                          if (parameters.cpu_usage <= 0.934) {
                            return tpcc_LM45(parameters);
                          } else {
                            return tpcc_LM46(parameters);
                          }
                        } else {

                          if (parameters.avg_latency_of_same_last_20 <= 316380000) {
                            return tpcc_LM47(parameters);
                          } else {

                            if (parameters.avg_work_of_same_past_second <= 30053150) {

                              if (parameters.work_so_far <= 31408.5) {
                                return tpcc_LM48(parameters);
                              } else {
                                return tpcc_LM49(parameters);
                              }
                            } else {
                              return tpcc_LM50(parameters);
                            }
                          }
                        }
                      }
                    } else {

                      if (parameters.avg_latency_of_same_last_20 <= 413818000) {

                        if (parameters.mean_wait_of_all <= 85111100) {

                          if (parameters.work_so_far <= 42151.5) {
                            return tpcc_LM51(parameters);
                          } else {

                            if (parameters.total_wait_locks <= 236.5) {
                              return tpcc_LM52(parameters);
                            } else {
                              return tpcc_LM53(parameters);
                            }
                          }
                        } else {

                          if (parameters.total_wait_locks <= 517) {
                            return tpcc_LM54(parameters);
                          } else {

                            if (parameters.cpu_usage <= 0.917) {
                              return tpcc_LM55(parameters);
                            } else {
                              return tpcc_LM56(parameters);
                            }
                          }
                        }
                      } else {
                        return tpcc_LM57(parameters);
                      }
                    }
                  } else {

                    if (parameters.avg_wait_of_same_past_second <= 415436000) {
                      return tpcc_LM58(parameters);
                    } else {
                      return tpcc_LM59(parameters);
                    }
                  }
                } else {

                  if (parameters.total_wait_locks <= 298.5) {
                    return tpcc_LM60(parameters);
                  } else {

                    if (parameters.wait_so_far <= 67749946.5) {

                      if (parameters.total_wait_locks <= 711.5) {
                        return tpcc_LM61(parameters);
                      } else {

                        if (parameters.avg_wait_of_same_past_second <= 372053500) {

                          if (parameters.avg_work_of_same_past_second <= 29497500) {

                            if (parameters.wait_so_far <= 4636345.5) {

                              if (parameters.avg_work_of_same_past_second <= 26981000) {
                                return tpcc_LM62(parameters);
                              } else {

                                if (parameters.avg_wait_of_same_past_second <= 320950500) {
                                  return tpcc_LM63(parameters);
                                } else {
                                  return tpcc_LM64(parameters);
                                }
                              }
                            } else {

                              if (parameters.mean_wait_of_all <= 170831000) {
                                return tpcc_LM65(parameters);
                              } else {

                                if (parameters.avg_wait_of_same_past_second <= 345099500) {

                                  if (parameters.work_so_far <= 35253.5) {
                                    return tpcc_LM66(parameters);
                                  } else {

                                    if (parameters.work_so_far <= 114951.5) {
                                      return tpcc_LM67(parameters);
                                    } else {
                                      return tpcc_LM68(parameters);
                                    }
                                  }
                                } else {
                                  return tpcc_LM69(parameters);
                                }
                              }
                            }
                          } else {
                            return tpcc_LM70(parameters);
                          }
                        } else {

                          if (parameters.avg_latency_of_same_last_20 <= 252759500) {

                            if (parameters.avg_work_of_same_past_second <= 28136900) {
                              return tpcc_LM71(parameters);
                            } else {
                              return tpcc_LM72(parameters);
                            }
                          } else {

                            if (parameters.avg_latency_of_same_last_20 <= 395660000) {
                              return tpcc_LM73(parameters);
                            } else {
                              return tpcc_LM74(parameters);
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

              if (parameters.work_so_far <= 40759.5) {

                if (parameters.cpu_usage <= 0.969) {

                  if (parameters.mean_wait_of_all <= 130001000) {

                    if (parameters.avg_work_of_same_past_second <= 18055000) {

                      if (parameters.total_wait_locks <= 194.5) {
                        return tpcc_LM76(parameters);
                      } else {

                        if (parameters.wait_so_far <= 434625188.5) {

                          if (parameters.total_wait_locks <= 350.5) {

                            if (parameters.avg_work_of_same_past_second <= 12476850) {

                              if (parameters.total_wait_locks <= 299.5) {
                                return tpcc_LM77(parameters);
                              } else {
                                return tpcc_LM78(parameters);
                              }
                            } else {
                              return tpcc_LM79(parameters);
                            }
                          } else {

                            if (parameters.total_wait_locks <= 371.5) {

                              if (parameters.cpu_usage <= 0.956) {
                                return tpcc_LM80(parameters);
                              } else {
                                return tpcc_LM81(parameters);
                              }
                            } else {
                              return tpcc_LM82(parameters);
                            }
                          }
                        } else {
                          return tpcc_LM83(parameters);
                        }
                      }
                    } else {
                      return tpcc_LM84(parameters);
                    }
                  } else {
                    return tpcc_LM85(parameters);
                  }
                } else {
                  return tpcc_LM86(parameters);
                }
              } else {

                if (parameters.avg_latency_of_same_last_20 <= 292829500) {

                  if (parameters.work_so_far <= 115169.5) {
                    return tpcc_LM87(parameters);
                  } else {

                    if (parameters.work_so_far <= 201500) {
                      return tpcc_LM88(parameters);
                    } else {
                      return tpcc_LM89(parameters);
                    }
                  }
                } else {
                  return tpcc_LM90(parameters);
                }
              }
            }
          }
        } else {
          return tpcc_LM91(parameters);
        }
      } else {

        if (parameters.avg_wait_of_same_past_second <= 150638500) {

          if (parameters.avg_wait_of_same_past_second <= 27479950) {

            if (parameters.total_wait_locks <= 101.5) {

              if (parameters.wait_so_far <= 2455.5) {
                return tpcc_LM92(parameters);
              } else {
                return tpcc_LM93(parameters);
              }
            } else {

              if (parameters.work_so_far <= 30905.5) {
                return tpcc_LM94(parameters);
              } else {

                if (parameters.wait_so_far <= 23707975) {

                  if (parameters.avg_wait_of_same_past_second <= 7780780) {

                    if (parameters.cpu_usage <= 0.955) {

                      if (parameters.avg_latency_of_same_last_20 <= 116734000) {

                        if (parameters.mean_wait_of_all <= 75664300) {
                          return tpcc_LM95(parameters);
                        } else {
                          return tpcc_LM96(parameters);
                        }
                      } else {
                        return tpcc_LM97(parameters);
                      }
                    } else {
                      return tpcc_LM98(parameters);
                    }
                  } else {
                    return tpcc_LM99(parameters);
                  }
                } else {

                  if (parameters.cpu_usage <= 0.884) {
                    return tpcc_LM100(parameters);
                  } else {
                    return tpcc_LM101(parameters);
                  }
                }
              }
            }
          } else {

            if (parameters.avg_wait_of_same_past_second <= 95215900) {

              if (parameters.avg_latency_of_same_last_20 <= 83407600) {
                return tpcc_LM102(parameters);
              } else {

                if (parameters.total_wait_locks <= 109.5) {
                  return tpcc_LM103(parameters);
                } else {
                  return tpcc_LM104(parameters);
                }
              }
            } else {

              if (parameters.wait_so_far <= 13248.5) {

                if (parameters.total_wait_locks <= 164.5) {

                  if (parameters.avg_work_of_same_past_second <= 36356650) {

                    if (parameters.work_so_far <= 37426) {
                      return tpcc_LM105(parameters);
                    } else {
                      return tpcc_LM106(parameters);
                    }
                  } else {
                    return tpcc_LM107(parameters);
                  }
                } else {
                  return tpcc_LM108(parameters);
                }
              } else {
                return tpcc_LM109(parameters);
              }
            }
          }
        } else {

          if (parameters.mean_wait_of_all <= 142157000) {

            if (parameters.avg_latency_of_same_last_20 <= 464956500) {
              return tpcc_LM110(parameters);
            } else {

              if (parameters.max_latency_of_same_last_50 <= 1854915000) {

                if (parameters.avg_work_of_same_past_second <= 36408500) {

                  if (parameters.work_so_far <= 45831) {

                    if (parameters.avg_wait_of_same_past_second <= 473288500) {

                      if (parameters.avg_wait_of_same_past_second <= 331589000) {
                        return tpcc_LM111(parameters);
                      } else {

                        if (parameters.total_wait_locks <= 427.5) {
                          return tpcc_LM112(parameters);
                        } else {
                          return tpcc_LM113(parameters);
                        }
                      }
                    } else {
                      return tpcc_LM114(parameters);
                    }
                  } else {
                    return tpcc_LM115(parameters);
                  }
                } else {
                  return tpcc_LM116(parameters);
                }
              } else {
                return tpcc_LM117(parameters);
              }
            }
          } else {

            if (parameters.mean_wait_of_all <= 162289500) {

              if (parameters.avg_work_of_same_past_second <= 35853550) {

                if (parameters.mean_wait_of_all <= 157835500) {
                  return tpcc_LM118(parameters);
                } else {

                  if (parameters.mean_wait_of_all <= 162233500) {
                    return tpcc_LM119(parameters);
                  } else {
                    return tpcc_LM120(parameters);
                  }
                }
              } else {
                return tpcc_LM121(parameters);
              }
            } else {
              return tpcc_LM122(parameters);
            }
          }
        }
      }
    } else {

      if (parameters.wait_so_far <= 395880599) {

        if (parameters.num_locks_so_far <= 2.5) {
          return tpcc_LM123(parameters);
        } else {

          if (parameters.work_so_far <= 81648039) {

            if (parameters.wait_so_far <= 184233652) {

              if (parameters.avg_wait_of_same_past_second <= 27448150) {

                if (parameters.total_wait_locks <= 128.5) {
                  return tpcc_LM124(parameters);
                } else {
                  return tpcc_LM125(parameters);
                }
              } else {

                if (parameters.wait_so_far <= 86513485) {

                  if (parameters.work_so_far <= 12059231) {
                    return tpcc_LM126(parameters);
                  } else {

                    if (parameters.num_locks_so_far <= 20.5) {

                      if (parameters.cpu_usage <= 0.936) {

                        if (parameters.total_wait_locks <= 104.5) {
                          return tpcc_LM127(parameters);
                        } else {
                          return tpcc_LM128(parameters);
                        }
                      } else {
                        return tpcc_LM129(parameters);
                      }
                    } else {
                      return tpcc_LM130(parameters);
                    }
                  }
                } else {

                  if (parameters.work_so_far <= 13058445) {

                    if (parameters.wait_so_far <= 146107469) {
                      return tpcc_LM131(parameters);
                    } else {

                      if (parameters.total_wait_locks <= 230) {
                        return tpcc_LM132(parameters);
                      } else {
                        return tpcc_LM133(parameters);
                      }
                    }
                  } else {

                    if (parameters.work_so_far <= 21216195) {
                      return tpcc_LM134(parameters);
                    } else {
                      return tpcc_LM135(parameters);
                    }
                  }
                }
              }
            } else {
              return tpcc_LM136(parameters);
            }
          } else {
            return tpcc_LM137(parameters);
          }
        }
      } else {

        if (parameters.wait_so_far <= 756791564) {

          if (parameters.num_locks_so_far <= 2.5) {
            return tpcc_LM138(parameters);
          } else {

            if (parameters.wait_so_far <= 543391114.5) {
              return tpcc_LM139(parameters);
            } else {
              return tpcc_LM140(parameters);
            }
          }
        } else {

          if (parameters.num_locks_so_far <= 2.5) {
            return tpcc_LM141(parameters);
          } else {
            return tpcc_LM142(parameters);
          }
        }
      }
    }
  } else {

    if (parameters.avg_work_of_same_past_second <= 368399500) {

      if (parameters.work_so_far <= 938195) {

        if (parameters.wait_so_far <= 25132923.5) {

          if (parameters.avg_work_of_same_past_second <= 183683000) {
            return tpcc_LM143(parameters);
          } else {

            if (parameters.mean_wait_of_all <= 133694000) {
              return tpcc_LM144(parameters);
            } else {

              if (parameters.total_wait_locks <= 693) {

                if (parameters.cpu_usage <= 0.938) {
                  return tpcc_LM145(parameters);
                } else {
                  return tpcc_LM146(parameters);
                }
              } else {

                if (parameters.mean_wait_of_all <= 171363000) {
                  return tpcc_LM147(parameters);
                } else {
                  return tpcc_LM148(parameters);
                }
              }
            }
          }
        } else {
          return tpcc_LM149(parameters);
        }
      } else {

        if (parameters.wait_so_far <= 292877698) {

          if (parameters.work_so_far <= 108232503.5) {

            if (parameters.num_locks_so_far <= 11.5) {

              if (parameters.avg_work_of_same_past_second <= 244573500) {

                if (parameters.work_so_far <= 12277514) {
                  return tpcc_LM150(parameters);
                } else {
                  return tpcc_LM151(parameters);
                }
              } else {

                if (parameters.work_so_far <= 6136191) {

                  if (parameters.avg_latency_of_same_last_20 <= 490112000) {

                    if (parameters.wait_so_far <= 7177960.5) {
                      return tpcc_LM152(parameters);
                    } else {
                      return tpcc_LM153(parameters);
                    }
                  } else {

                    if (parameters.cpu_usage <= 0.923) {
                      return tpcc_LM154(parameters);
                    } else {
                      return tpcc_LM155(parameters);
                    }
                  }
                } else {

                  if (parameters.num_locks_so_far <= 9.5) {
                    return tpcc_LM156(parameters);
                  } else {

                    if (parameters.mean_wait_of_all <= 139392500) {
                      return tpcc_LM157(parameters);
                    } else {
                      return tpcc_LM158(parameters);
                    }
                  }
                }
              }
            } else {

              if (parameters.wait_so_far <= 47142359.5) {

                if (parameters.work_so_far <= 32519939.5) {

                  if (parameters.num_locks_so_far <= 22.5) {

                    if (parameters.work_so_far <= 12559351.5) {
                      return tpcc_LM159(parameters);
                    } else {
                      return tpcc_LM160(parameters);
                    }
                  } else {
                    return tpcc_LM161(parameters);
                  }
                } else {

                  if (parameters.num_locks_so_far <= 27.5) {

                    if (parameters.num_locks_so_far <= 21.5) {

                      if (parameters.wait_so_far <= 8420218) {

                        if (parameters.avg_wait_of_same_past_second <= 123741500) {
                          return tpcc_LM162(parameters);
                        } else {
                          return tpcc_LM163(parameters);
                        }
                      } else {
                        return tpcc_LM164(parameters);
                      }
                    } else {
                      return tpcc_LM165(parameters);
                    }
                  } else {
                    return tpcc_LM166(parameters);
                  }
                }
              } else {
                return tpcc_LM167(parameters);
              }
            }
          } else {

            if (parameters.work_so_far <= 343972550.5) {

              if (parameters.num_locks_so_far <= 21.5) {
                return tpcc_LM168(parameters);
              } else {
                return tpcc_LM169(parameters);
              }
            } else {
              return tpcc_LM170(parameters);
            }
          }
        } else {

          if (parameters.num_locks_so_far <= 5.5) {

            if (parameters.avg_latency_of_same_last_20 <= 560925000) {

              if (parameters.avg_work_of_same_past_second <= 284680500) {
                return tpcc_LM171(parameters);
              } else {
                return tpcc_LM172(parameters);
              }
            } else {
              return tpcc_LM173(parameters);
            }
          } else {

            if (parameters.wait_so_far <= 660472983.5) {

              if (parameters.num_locks_so_far <= 11.5) {

                if (parameters.num_locks_so_far <= 9.5) {
                  return tpcc_LM174(parameters);
                } else {

                  if (parameters.avg_wait_of_same_past_second <= 232881000) {

                    if (parameters.work_so_far <= 39502637) {

                      if (parameters.wait_so_far <= 411982394) {
                        return tpcc_LM175(parameters);
                      } else {
                        return tpcc_LM176(parameters);
                      }
                    } else {
                      return tpcc_LM177(parameters);
                    }
                  } else {

                    if (parameters.mean_wait_of_all <= 140678000) {

                      if (parameters.avg_wait_of_same_past_second <= 243144000) {

                        if (parameters.avg_wait_of_same_past_second <= 241026000) {
                          return tpcc_LM178(parameters);
                        } else {
                          return tpcc_LM179(parameters);
                        }
                      } else {
                        return tpcc_LM180(parameters);
                      }
                    } else {
                      return tpcc_LM181(parameters);
                    }
                  }
                }
              } else {
                return tpcc_LM182(parameters);
              }
            } else {
              return tpcc_LM183(parameters);
            }
          }
        }
      }
    } else {

      if (parameters.avg_work_of_same_past_second <= 650908000) {

        if (parameters.num_locks_so_far <= 5.5) {

          if (parameters.avg_work_of_same_past_second <= 499469500) {

            if (parameters.wait_so_far <= 191995019.5) {

              if (parameters.max_latency_of_same_last_50 <= 1823730000) {

                if (parameters.wait_so_far <= 12880143) {
                  return tpcc_LM184(parameters);
                } else {

                  if (parameters.work_so_far <= 51252) {
                    return tpcc_LM185(parameters);
                  } else {
                    return tpcc_LM186(parameters);
                  }
                }
              } else {

                if (parameters.avg_wait_of_same_past_second <= 353304000) {

                  if (parameters.mean_wait_of_all <= 153195000) {

                    if (parameters.cpu_usage <= 0.941) {
                      return tpcc_LM187(parameters);
                    } else {
                      return tpcc_LM188(parameters);
                    }
                  } else {

                    if (parameters.mean_wait_of_all <= 162859500) {

                      if (parameters.mean_wait_of_all <= 154042000) {
                        return tpcc_LM189(parameters);
                      } else {

                        if (parameters.max_latency_of_same_last_50 <= 2147655000) {
                          return tpcc_LM190(parameters);
                        } else {
                          return tpcc_LM191(parameters);
                        }
                      }
                    } else {

                      if (parameters.max_latency_of_same_last_50 <= 2148095000) {
                        return tpcc_LM192(parameters);
                      } else {

                        if (parameters.cpu_usage <= 0.965) {
                          return tpcc_LM193(parameters);
                        } else {
                          return tpcc_LM194(parameters);
                        }
                      }
                    }
                  }
                } else {
                  return tpcc_LM195(parameters);
                }
              }
            } else {
              return tpcc_LM196(parameters);
            }
          } else {
            return tpcc_LM197(parameters);
          }
        } else {

          if (parameters.wait_so_far <= 426443714.5) {

            if (parameters.work_so_far <= 330808476) {

              if (parameters.work_so_far <= 65824630.5) {

                if (parameters.num_locks_so_far <= 19.5) {

                  if (parameters.work_so_far <= 14014604) {

                    if (parameters.avg_latency_of_same_last_20 <= 706996000) {
                      return tpcc_LM198(parameters);
                    } else {

                      if (parameters.work_so_far <= 2862347.5) {

                        if (parameters.total_wait_locks <= 729) {

                          if (parameters.cpu_usage <= 0.83) {
                            return tpcc_LM199(parameters);
                          } else {
                            return tpcc_LM200(parameters);
                          }
                        } else {
                          return tpcc_LM201(parameters);
                        }
                      } else {

                        if (parameters.max_latency_of_same_last_50 <= 1845970000) {
                          return tpcc_LM202(parameters);
                        } else {
                          return tpcc_LM203(parameters);
                        }
                      }
                    }
                  } else {

                    if (parameters.wait_so_far <= 172736164) {

                      if (parameters.work_so_far <= 45426781) {
                        return tpcc_LM204(parameters);
                      } else {
                        return tpcc_LM205(parameters);
                      }
                    } else {
                      return tpcc_LM206(parameters);
                    }
                  }
                } else {
                  return tpcc_LM207(parameters);
                }
              } else {
                return tpcc_LM208(parameters);
              }
            } else {
              return tpcc_LM209(parameters);
            }
          } else {
            return tpcc_LM210(parameters);
          }
        }
      } else {

        if (parameters.avg_latency_of_same_last_20 <= 439687000) {

          if (parameters.work_so_far <= 100752204.5) {

            if (parameters.wait_so_far <= 523137417.5) {

              if (parameters.total_wait_locks <= 484.5) {

                if (parameters.wait_so_far <= 162072.5) {
                  return tpcc_LM211(parameters);
                } else {

                  if (parameters.num_locks_so_far <= 3.5) {
                    return tpcc_LM212(parameters);
                  } else {
                    return tpcc_LM213(parameters);
                  }
                }
              } else {
                return tpcc_LM214(parameters);
              }
            } else {
              return tpcc_LM215(parameters);
            }
          } else {
            return tpcc_LM216(parameters);
          }
        } else {

          if (parameters.work_so_far <= 566889) {

            if (parameters.wait_so_far <= 69504.5) {
              return tpcc_LM217(parameters);
            } else {
              return tpcc_LM218(parameters);
            }
          } else {

            if (parameters.wait_so_far <= 713868271.5) {
              return tpcc_LM219(parameters);
            } else {
              return tpcc_LM220(parameters);
            }
          }
        }
      }
    }
  }
}