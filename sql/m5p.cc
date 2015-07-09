#include "my_global.h"
#include "m5p.h"
#include "trace_tool.h"

static
double
new_order_LM1(work_wait &parameters) {
  double actual_remaining = 
	2.7795 * parameters.work_so_far 
	- 0.0005 * parameters.wait_so_far 
	- 2806992.7955 * parameters.num_locks_so_far 
	+ 572243.2746 * parameters.total_wait_locks 
	- 2.6367 * parameters.mean_wait_of_all 
	- 572629216.1579 * parameters.cpu_usage 
	- 1.257 * parameters.avg_work_of_same_past_second 
	- 0.004 * parameters.avg_wait_of_same_past_second 
	+ 1.254 * parameters.avg_latency_of_same_last_20 
	- 0.1556 * parameters.max_latency_of_same_last_50 
	+ 761171378.077;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM2(work_wait &parameters) {
  double actual_remaining = 
	1.2145 * parameters.work_so_far 
	- 0.0005 * parameters.wait_so_far 
	- 1265032.9244 * parameters.num_locks_so_far 
	+ 36154.532 * parameters.total_wait_locks 
	- 0.11 * parameters.mean_wait_of_all 
	- 1815872.4948 * parameters.cpu_usage 
	+ 0.0208 * parameters.avg_work_of_same_past_second 
	- 0.0211 * parameters.avg_wait_of_same_past_second 
	+ 1.1274 * parameters.avg_latency_of_same_last_20 
	- 0.0026 * parameters.max_latency_of_same_last_50 
	+ 35755253.1983;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM3(work_wait &parameters) {
  double actual_remaining = 
	0.8955 * parameters.work_so_far 
	- 0.0005 * parameters.wait_so_far 
	- 694057.7515 * parameters.num_locks_so_far 
	+ 164719.7435 * parameters.total_wait_locks 
	- 0.543 * parameters.mean_wait_of_all 
	- 146793927.2456 * parameters.cpu_usage 
	+ 0.1901 * parameters.avg_work_of_same_past_second 
	- 0.1901 * parameters.avg_wait_of_same_past_second 
	+ 0.0333 * parameters.avg_latency_of_same_last_20 
	+ 0.0226 * parameters.max_latency_of_same_last_50 
	+ 193724294.4078;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM4(work_wait &parameters) {
  double actual_remaining = 
	0.3088 * parameters.work_so_far 
	- 0.0005 * parameters.wait_so_far 
	- 2008355.6308 * parameters.num_locks_so_far 
	+ 2552465.5033 * parameters.total_wait_locks 
	- 13.9912 * parameters.mean_wait_of_all 
	+ 4798173.6174 * parameters.cpu_usage 
	+ 0.129 * parameters.avg_work_of_same_past_second 
	- 0.128 * parameters.avg_wait_of_same_past_second 
	+ 0.0333 * parameters.avg_latency_of_same_last_20 
	+ 0.0126 * parameters.max_latency_of_same_last_50 
	+ 634394483.6567;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM5(work_wait &parameters) {
  double actual_remaining = 
	1.1475 * parameters.work_so_far 
	- 0.0601 * parameters.wait_so_far 
	- 628398.9871 * parameters.num_locks_so_far 
	+ 203182.749 * parameters.total_wait_locks 
	- 0.6447 * parameters.mean_wait_of_all 
	+ 578255371.1435 * parameters.cpu_usage 
	- 0.6704 * parameters.avg_work_of_same_past_second 
	+ 0.068 * parameters.avg_wait_of_same_past_second 
	+ 0.0916 * parameters.avg_latency_of_same_last_20 
	- 0.0039 * parameters.max_latency_of_same_last_50 
	- 392882116.6614;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM6(work_wait &parameters) {
  double actual_remaining = 
	2.2084 * parameters.work_so_far 
	+ 20.1512 * parameters.wait_so_far 
	+ 5100915.1691 * parameters.num_locks_so_far 
	+ 955156.6746 * parameters.total_wait_locks 
	- 3.3852 * parameters.mean_wait_of_all 
	+ 605075037.1531 * parameters.cpu_usage 
	- 0.9644 * parameters.avg_work_of_same_past_second 
	+ 0.6936 * parameters.avg_wait_of_same_past_second 
	+ 0.0916 * parameters.avg_latency_of_same_last_20 
	- 0.0819 * parameters.max_latency_of_same_last_50 
	- 324125300.9491;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM7(work_wait &parameters) {
  double actual_remaining = 
	3.9889 * parameters.work_so_far 
	+ 55.8336 * parameters.wait_so_far 
	- 7175859.7077 * parameters.num_locks_so_far 
	+ 1466486.6477 * parameters.total_wait_locks 
	- 8.296 * parameters.mean_wait_of_all 
	+ 1292213340.4418 * parameters.cpu_usage 
	- 0.6604 * parameters.avg_work_of_same_past_second 
	+ 0.481 * parameters.avg_wait_of_same_past_second 
	+ 0.0916 * parameters.avg_latency_of_same_last_20 
	- 0.0819 * parameters.max_latency_of_same_last_50 
	- 652256256.3853;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM8(work_wait &parameters) {
  double actual_remaining = 
	5.3545 * parameters.work_so_far 
	- 0.0492 * parameters.wait_so_far 
	- 628398.9871 * parameters.num_locks_so_far 
	+ 739643.9926 * parameters.total_wait_locks 
	- 3.0171 * parameters.mean_wait_of_all 
	+ 417041500.6672 * parameters.cpu_usage 
	- 0.5611 * parameters.avg_work_of_same_past_second 
	+ 0.4577 * parameters.avg_wait_of_same_past_second 
	+ 0.0916 * parameters.avg_latency_of_same_last_20 
	- 0.1756 * parameters.max_latency_of_same_last_50 
	- 132634804.7286;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM9(work_wait &parameters) {
  double actual_remaining = 
	2.1492 * parameters.work_so_far 
	+ 0.6271 * parameters.wait_so_far 
	- 538553.5114 * parameters.num_locks_so_far 
	+ 667202.6269 * parameters.total_wait_locks 
	- 3.1757 * parameters.mean_wait_of_all 
	- 8753683.102 * parameters.cpu_usage 
	+ 0.0041 * parameters.avg_work_of_same_past_second 
	- 0.0107 * parameters.avg_wait_of_same_past_second 
	+ 0.8754 * parameters.avg_latency_of_same_last_20 
	- 0.0039 * parameters.max_latency_of_same_last_50 
	+ 109171980.7135;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM10(work_wait &parameters) {
  double actual_remaining = 
	1.9729 * parameters.work_so_far 
	- 0.0005 * parameters.wait_so_far 
	- 1922865.9938 * parameters.num_locks_so_far 
	+ 45394.4758 * parameters.total_wait_locks 
	- 0.0848 * parameters.mean_wait_of_all 
	- 8753683.102 * parameters.cpu_usage 
	+ 0.0041 * parameters.avg_work_of_same_past_second 
	- 0.2045 * parameters.avg_wait_of_same_past_second 
	+ 0.4789 * parameters.avg_latency_of_same_last_20 
	- 0.0442 * parameters.max_latency_of_same_last_50 
	+ 85213144.0871;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM11(work_wait &parameters) {
  double actual_remaining = 
	2.8639 * parameters.work_so_far 
	+ 173.9583 * parameters.wait_so_far 
	- 4633731.5233 * parameters.num_locks_so_far 
	+ 3657659.2259 * parameters.total_wait_locks 
	- 24.2431 * parameters.mean_wait_of_all 
	- 8753683.102 * parameters.cpu_usage 
	+ 0.0041 * parameters.avg_work_of_same_past_second 
	- 0.0297 * parameters.avg_wait_of_same_past_second 
	+ 0.0677 * parameters.avg_latency_of_same_last_20 
	- 0.0031 * parameters.max_latency_of_same_last_50 
	+ 1063844036.327;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM12(work_wait &parameters) {
  double actual_remaining = 
	1.8685 * parameters.work_so_far 
	+ 0.0197 * parameters.wait_so_far 
	- 1124862.6609 * parameters.num_locks_so_far 
	+ 332082.2383 * parameters.total_wait_locks 
	- 6.8436 * parameters.mean_wait_of_all 
	- 8753683.102 * parameters.cpu_usage 
	+ 0.0041 * parameters.avg_work_of_same_past_second 
	- 0.0297 * parameters.avg_wait_of_same_past_second 
	+ 0.0677 * parameters.avg_latency_of_same_last_20 
	+ 0.0143 * parameters.max_latency_of_same_last_50 
	+ 433431979.0758;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM13(work_wait &parameters) {
  double actual_remaining = 
	4.2391 * parameters.work_so_far 
	+ 0.0846 * parameters.wait_so_far 
	- 1124862.6609 * parameters.num_locks_so_far 
	+ 332082.2383 * parameters.total_wait_locks 
	- 4.2338 * parameters.mean_wait_of_all 
	- 8753683.102 * parameters.cpu_usage 
	+ 0.4002 * parameters.avg_work_of_same_past_second 
	- 0.0297 * parameters.avg_wait_of_same_past_second 
	+ 0.0677 * parameters.avg_latency_of_same_last_20 
	- 0.0031 * parameters.max_latency_of_same_last_50 
	+ 229995065.8032;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM14(work_wait &parameters) {
  double actual_remaining = 
	4.2391 * parameters.work_so_far 
	+ 0.0846 * parameters.wait_so_far 
	- 1124862.6609 * parameters.num_locks_so_far 
	+ 332082.2383 * parameters.total_wait_locks 
	- 4.2338 * parameters.mean_wait_of_all 
	- 8753683.102 * parameters.cpu_usage 
	+ 0.3979 * parameters.avg_work_of_same_past_second 
	- 0.0297 * parameters.avg_wait_of_same_past_second 
	+ 0.0677 * parameters.avg_latency_of_same_last_20 
	- 0.0031 * parameters.max_latency_of_same_last_50 
	+ 230967732.2498;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM15(work_wait &parameters) {
  double actual_remaining = 
	4.0224 * parameters.work_so_far 
	+ 0.0964 * parameters.wait_so_far 
	- 1124862.6609 * parameters.num_locks_so_far 
	+ 332082.2383 * parameters.total_wait_locks 
	- 4.2338 * parameters.mean_wait_of_all 
	- 8753683.102 * parameters.cpu_usage 
	+ 0.5151 * parameters.avg_work_of_same_past_second 
	- 0.0297 * parameters.avg_wait_of_same_past_second 
	+ 0.0677 * parameters.avg_latency_of_same_last_20 
	- 0.0031 * parameters.max_latency_of_same_last_50 
	+ 229389769.9831;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM16(work_wait &parameters) {
  double actual_remaining = 
	1994.0769 * parameters.work_so_far 
	- 0.2436 * parameters.wait_so_far 
	- 93784.5874 * parameters.num_locks_so_far 
	+ 367239.6795 * parameters.total_wait_locks 
	- 0.7179 * parameters.mean_wait_of_all 
	- 3594196.241 * parameters.cpu_usage 
	+ 0.0145 * parameters.avg_work_of_same_past_second 
	- 0.0153 * parameters.avg_wait_of_same_past_second 
	+ 0.1522 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 59787805.3339;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM17(work_wait &parameters) {
  double actual_remaining = 
	9.7197 * parameters.work_so_far 
	+ 0.0018 * parameters.wait_so_far 
	- 81034.3277 * parameters.num_locks_so_far 
	+ 752229.4186 * parameters.total_wait_locks 
	- 2.4653 * parameters.mean_wait_of_all 
	- 3594196.241 * parameters.cpu_usage 
	+ 1.0591 * parameters.avg_work_of_same_past_second 
	- 1.0775 * parameters.avg_wait_of_same_past_second 
	+ 0.1658 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 124404344.3824;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM18(work_wait &parameters) {
  double actual_remaining = 
	0.4682 * parameters.work_so_far 
	+ 0.0319 * parameters.wait_so_far 
	+ 8432638.4282 * parameters.num_locks_so_far 
	+ 734793.1882 * parameters.total_wait_locks 
	- 7.3653 * parameters.mean_wait_of_all 
	- 1538112281.6305 * parameters.cpu_usage 
	+ 0.0905 * parameters.avg_work_of_same_past_second 
	+ 11.1453 * parameters.avg_wait_of_same_past_second 
	- 0.531 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 2090379724.2861;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM19(work_wait &parameters) {
  double actual_remaining = 
	0.4682 * parameters.work_so_far 
	+ 0.0319 * parameters.wait_so_far 
	+ 8432638.4282 * parameters.num_locks_so_far 
	+ 734793.1882 * parameters.total_wait_locks 
	- 7.5487 * parameters.mean_wait_of_all 
	- 1538112281.6305 * parameters.cpu_usage 
	+ 0.0905 * parameters.avg_work_of_same_past_second 
	+ 11.1453 * parameters.avg_wait_of_same_past_second 
	- 0.3943 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 2019187750.3222;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM20(work_wait &parameters) {
  double actual_remaining = 
	0.4682 * parameters.work_so_far 
	+ 0.0319 * parameters.wait_so_far 
	+ 8432638.4282 * parameters.num_locks_so_far 
	+ 734793.1882 * parameters.total_wait_locks 
	- 8.7912 * parameters.mean_wait_of_all 
	- 6061145144.6031 * parameters.cpu_usage 
	+ 0.0905 * parameters.avg_work_of_same_past_second 
	+ 19.7167 * parameters.avg_wait_of_same_past_second 
	- 1.9416 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 6780529198.7818;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM21(work_wait &parameters) {
  double actual_remaining = 
	0.4682 * parameters.work_so_far 
	+ 0.2216 * parameters.wait_so_far 
	+ 37870141.1678 * parameters.num_locks_so_far 
	+ 1828957.7207 * parameters.total_wait_locks 
	- 0.1928 * parameters.mean_wait_of_all 
	- 188975341.8607 * parameters.cpu_usage 
	+ 0.9913 * parameters.avg_work_of_same_past_second 
	- 0.8584 * parameters.avg_wait_of_same_past_second 
	+ 0.3013 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 188040954.849;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM22(work_wait &parameters) {
  double actual_remaining = 
	0.8138 * parameters.work_so_far 
	+ 0.1495 * parameters.wait_so_far 
	+ 74476.9955 * parameters.num_locks_so_far 
	+ 422507.4453 * parameters.total_wait_locks 
	- 0.1928 * parameters.mean_wait_of_all 
	- 103499293.214 * parameters.cpu_usage 
	+ 0.0905 * parameters.avg_work_of_same_past_second 
	- 0.2544 * parameters.avg_wait_of_same_past_second 
	+ 0.7251 * parameters.avg_latency_of_same_last_20 
	- 0.173 * parameters.max_latency_of_same_last_50 
	+ 340697879.2787;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM23(work_wait &parameters) {
  double actual_remaining = 
	1.0346 * parameters.work_so_far 
	+ 0.2105 * parameters.wait_so_far 
	+ 74476.9955 * parameters.num_locks_so_far 
	+ 523188.8137 * parameters.total_wait_locks 
	- 0.1928 * parameters.mean_wait_of_all 
	- 103499293.214 * parameters.cpu_usage 
	+ 0.0905 * parameters.avg_work_of_same_past_second 
	- 0.35 * parameters.avg_wait_of_same_past_second 
	+ 0.1377 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 405911924.7809;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM24(work_wait &parameters) {
  double actual_remaining = 
	2.0058 * parameters.work_so_far 
	+ 0.7761 * parameters.wait_so_far 
	- 1669232.194 * parameters.num_locks_so_far 
	+ 490119.0889 * parameters.total_wait_locks 
	- 0.8956 * parameters.mean_wait_of_all 
	- 3594196.241 * parameters.cpu_usage 
	+ 0.4701 * parameters.avg_work_of_same_past_second 
	- 0.5831 * parameters.avg_wait_of_same_past_second 
	+ 0.0129 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 100747087.5418;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM25(work_wait &parameters) {
  double actual_remaining = 
	0.7978 * parameters.work_so_far 
	+ 0.0686 * parameters.wait_so_far 
	- 10110322.5993 * parameters.num_locks_so_far 
	+ 1192328.9125 * parameters.total_wait_locks 
	- 3.2265 * parameters.mean_wait_of_all 
	- 4550974.5496 * parameters.cpu_usage 
	- 0.0302 * parameters.avg_work_of_same_past_second 
	- 0.8036 * parameters.avg_wait_of_same_past_second 
	+ 0.319 * parameters.avg_latency_of_same_last_20 
	- 0.0096 * parameters.max_latency_of_same_last_50 
	+ 491314259.8488;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM26(work_wait &parameters) {
  double actual_remaining = 
	0.9092 * parameters.work_so_far 
	+ 0.789 * parameters.wait_so_far 
	+ 1400333.1923 * parameters.num_locks_so_far 
	+ 681972.0162 * parameters.total_wait_locks 
	- 2.5866 * parameters.mean_wait_of_all 
	- 4550974.5496 * parameters.cpu_usage 
	- 0.2697 * parameters.avg_work_of_same_past_second 
	+ 0.145 * parameters.avg_wait_of_same_past_second 
	+ 0.2388 * parameters.avg_latency_of_same_last_20 
	- 0.1036 * parameters.max_latency_of_same_last_50 
	+ 203350165.2931;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM27(work_wait &parameters) {
  double actual_remaining = 
	0.9239 * parameters.work_so_far 
	+ 0.3515 * parameters.wait_so_far 
	- 4552581.1047 * parameters.num_locks_so_far 
	+ 64129.1057 * parameters.total_wait_locks 
	- 0.1943 * parameters.mean_wait_of_all 
	- 4550974.5496 * parameters.cpu_usage 
	- 0.0155 * parameters.avg_work_of_same_past_second 
	- 0.0046 * parameters.avg_wait_of_same_past_second 
	+ 0.1336 * parameters.avg_latency_of_same_last_20 
	- 0.1326 * parameters.max_latency_of_same_last_50 
	+ 425009968.6452;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM28(work_wait &parameters) {
  double actual_remaining = 
	1.3842 * parameters.work_so_far 
	+ 0.7489 * parameters.wait_so_far 
	+ 23008730.0626 * parameters.num_locks_so_far 
	+ 64129.1057 * parameters.total_wait_locks 
	- 2.597 * parameters.mean_wait_of_all 
	- 4550974.5496 * parameters.cpu_usage 
	- 0.0155 * parameters.avg_work_of_same_past_second 
	- 1.6856 * parameters.avg_wait_of_same_past_second 
	+ 0.1336 * parameters.avg_latency_of_same_last_20 
	- 0.1208 * parameters.max_latency_of_same_last_50 
	+ 318802034.7573;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM29(work_wait &parameters) {
  double actual_remaining = 
	1.2271 * parameters.work_so_far 
	+ 0.6217 * parameters.wait_so_far 
	- 6387509.0387 * parameters.num_locks_so_far 
	+ 64129.1057 * parameters.total_wait_locks 
	- 0.1943 * parameters.mean_wait_of_all 
	- 4550974.5496 * parameters.cpu_usage 
	- 0.0155 * parameters.avg_work_of_same_past_second 
	- 1.1975 * parameters.avg_wait_of_same_past_second 
	+ 0.1336 * parameters.avg_latency_of_same_last_20 
	- 0.1208 * parameters.max_latency_of_same_last_50 
	+ 458940304.4653;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM30(work_wait &parameters) {
  double actual_remaining = 
	0.482 * parameters.work_so_far 
	+ 0.0407 * parameters.wait_so_far 
	- 923041.1243 * parameters.num_locks_so_far 
	+ 749026.2269 * parameters.total_wait_locks 
	- 0.1943 * parameters.mean_wait_of_all 
	- 4550974.5496 * parameters.cpu_usage 
	- 0.0155 * parameters.avg_work_of_same_past_second 
	- 0.0046 * parameters.avg_wait_of_same_past_second 
	+ 0.3757 * parameters.avg_latency_of_same_last_20 
	- 0.1128 * parameters.max_latency_of_same_last_50 
	+ 284583872.2154;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM31(work_wait &parameters) {
  double actual_remaining = 
	2.4976 * parameters.work_so_far 
	- 0.0159 * parameters.wait_so_far 
	- 1745565.6185 * parameters.total_wait_locks 
	+ 5.8244 * parameters.mean_wait_of_all 
	- 363789385.7359 * parameters.cpu_usage 
	- 0.3335 * parameters.avg_work_of_same_past_second 
	+ 0.3009 * parameters.avg_wait_of_same_past_second 
	- 0.1527 * parameters.avg_latency_of_same_last_20 
	- 0.0013 * parameters.max_latency_of_same_last_50 
	+ 903031725.792;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM32(work_wait &parameters) {
  double actual_remaining = 
	0.0402 * parameters.work_so_far 
	- 0.0168 * parameters.wait_so_far 
	+ 307504.7073 * parameters.total_wait_locks 
	+ 0.1827 * parameters.mean_wait_of_all 
	- 7897618.6195 * parameters.cpu_usage 
	+ 0.0016 * parameters.avg_work_of_same_past_second 
	- 0.0021 * parameters.avg_wait_of_same_past_second 
	+ 0.318 * parameters.avg_latency_of_same_last_20 
	- 0.1008 * parameters.max_latency_of_same_last_50 
	+ 190759919.2516;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM33(work_wait &parameters) {
  double actual_remaining = 
	0.0402 * parameters.work_so_far 
	- 0.0168 * parameters.wait_so_far 
	- 3661.3247 * parameters.total_wait_locks 
	+ 0.1827 * parameters.mean_wait_of_all 
	- 7897618.6195 * parameters.cpu_usage 
	+ 0.0016 * parameters.avg_work_of_same_past_second 
	- 0.0021 * parameters.avg_wait_of_same_past_second 
	+ 0.0283 * parameters.avg_latency_of_same_last_20 
	- 0.0092 * parameters.max_latency_of_same_last_50 
	+ 373378606.1619;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM34(work_wait &parameters) {
  double actual_remaining = 
	1.3828 * parameters.work_so_far 
	+ 252.3657 * parameters.wait_so_far 
	+ 2162202.4684 * parameters.total_wait_locks 
	- 15.1885 * parameters.mean_wait_of_all 
	- 2941166.7919 * parameters.cpu_usage 
	+ 0.0012 * parameters.avg_work_of_same_past_second 
	- 0.0138 * parameters.avg_wait_of_same_past_second 
	- 0.154 * parameters.avg_latency_of_same_last_20 
	- 0.002 * parameters.max_latency_of_same_last_50 
	+ 1194204873.4283;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM35(work_wait &parameters) {
  double actual_remaining = 
	0.237 * parameters.work_so_far 
	+ 789.6961 * parameters.wait_so_far 
	+ 228361.8293 * parameters.total_wait_locks 
	- 1.4319 * parameters.mean_wait_of_all 
	- 2941166.7919 * parameters.cpu_usage 
	+ 0.0012 * parameters.avg_work_of_same_past_second 
	- 0.0138 * parameters.avg_wait_of_same_past_second 
	+ 0.0091 * parameters.avg_latency_of_same_last_20 
	- 0.002 * parameters.max_latency_of_same_last_50 
	+ 711364043.2038;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM36(work_wait &parameters) {
  double actual_remaining = 
	0.0795 * parameters.work_so_far 
	- 0.0079 * parameters.wait_so_far 
	- 1568268.5108 * parameters.total_wait_locks 
	+ 9.2179 * parameters.mean_wait_of_all 
	- 2941166.7919 * parameters.cpu_usage 
	+ 0.0012 * parameters.avg_work_of_same_past_second 
	- 0.013 * parameters.avg_wait_of_same_past_second 
	+ 0.009 * parameters.avg_latency_of_same_last_20 
	- 0.0474 * parameters.max_latency_of_same_last_50 
	+ 184956758.58;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM37(work_wait &parameters) {
  double actual_remaining = 
	1.5557 * parameters.work_so_far 
	- 0.0079 * parameters.wait_so_far 
	- 877688.5667 * parameters.total_wait_locks 
	+ 5.801 * parameters.mean_wait_of_all 
	- 2941166.7919 * parameters.cpu_usage 
	+ 0.0012 * parameters.avg_work_of_same_past_second 
	- 0.7433 * parameters.avg_wait_of_same_past_second 
	+ 0.1809 * parameters.avg_latency_of_same_last_20 
	- 0.0018 * parameters.max_latency_of_same_last_50 
	+ 359419866.6786;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM38(work_wait &parameters) {
  double actual_remaining = 
	0.6441 * parameters.work_so_far 
	- 0.1436 * parameters.wait_so_far 
	- 1209890.4797 * parameters.total_wait_locks 
	+ 7.7955 * parameters.mean_wait_of_all 
	- 2141477.6611 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.1258 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 32389334.4528;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM39(work_wait &parameters) {
  double actual_remaining = 
	14.9856 * parameters.work_so_far 
	+ 1.1085 * parameters.wait_so_far 
	- 59919136.0185 * parameters.num_locks_so_far 
	- 1922093.9789 * parameters.total_wait_locks 
	+ 11.422 * parameters.mean_wait_of_all 
	- 736176488.5778 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0031 * parameters.avg_latency_of_same_last_20 
	- 0.0956 * parameters.max_latency_of_same_last_50 
	+ 1208167854.3562;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM40(work_wait &parameters) {
  double actual_remaining = 
	3.2437 * parameters.work_so_far 
	+ 0.0905 * parameters.wait_so_far 
	- 1437833.2642 * parameters.num_locks_so_far 
	- 84945.2449 * parameters.total_wait_locks 
	+ 0.5432 * parameters.mean_wait_of_all 
	- 33734105.1299 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.2404 * parameters.avg_latency_of_same_last_20 
	- 0.1238 * parameters.max_latency_of_same_last_50 
	+ 504415368.1845;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM41(work_wait &parameters) {
  double actual_remaining = 
	0.3836 * parameters.work_so_far 
	+ 0.0888 * parameters.wait_so_far 
	- 1437833.2642 * parameters.num_locks_so_far 
	- 84945.2449 * parameters.total_wait_locks 
	+ 0.5432 * parameters.mean_wait_of_all 
	- 33734105.1299 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.3378 * parameters.avg_latency_of_same_last_20 
	- 0.0123 * parameters.max_latency_of_same_last_50 
	+ 375349984.6155;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM42(work_wait &parameters) {
  double actual_remaining = 
	4.0412 * parameters.work_so_far 
	+ 0.6439 * parameters.wait_so_far 
	- 245170800.176 * parameters.num_locks_so_far 
	- 1668929.1789 * parameters.total_wait_locks 
	+ 13.5687 * parameters.mean_wait_of_all 
	- 26685038.3924 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_work_of_same_past_second 
	- 0.7078 * parameters.avg_wait_of_same_past_second 
	- 0.2236 * parameters.avg_latency_of_same_last_20 
	- 0.0045 * parameters.max_latency_of_same_last_50 
	+ 2708792883.6986;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM43(work_wait &parameters) {
  double actual_remaining = 
	2.8729 * parameters.work_so_far 
	+ 1.0557 * parameters.wait_so_far 
	- 7428840.7407 * parameters.num_locks_so_far 
	- 737145.0176 * parameters.total_wait_locks 
	+ 4.7592 * parameters.mean_wait_of_all 
	- 6594900.2349 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_work_of_same_past_second 
	- 0.1673 * parameters.avg_wait_of_same_past_second 
	+ 0.0756 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	+ 198744820.4281;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM44(work_wait &parameters) {
  double actual_remaining = 
	1.054 * parameters.work_so_far 
	+ 0.0934 * parameters.wait_so_far 
	- 11032253.8721 * parameters.num_locks_so_far 
	+ 1913344.3513 * parameters.total_wait_locks 
	- 4.8952 * parameters.mean_wait_of_all 
	- 18325269.1028 * parameters.cpu_usage 
	- 0.0019 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0034 * parameters.avg_latency_of_same_last_20 
	- 0.002 * parameters.max_latency_of_same_last_50 
	+ 392097254.5296;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM45(work_wait &parameters) {
  double actual_remaining = 
	0.7821 * parameters.work_so_far 
	+ 0.6084 * parameters.wait_so_far 
	- 693179.5319 * parameters.num_locks_so_far 
	- 722997.794 * parameters.total_wait_locks 
	+ 5.1635 * parameters.mean_wait_of_all 
	- 18325269.1028 * parameters.cpu_usage 
	- 0.0019 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.1551 * parameters.avg_latency_of_same_last_20 
	- 0.0464 * parameters.max_latency_of_same_last_50 
	+ 154633906.7833;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM46(work_wait &parameters) {
  double actual_remaining = 
	0.8785 * parameters.work_so_far 
	+ 0.7068 * parameters.wait_so_far 
	- 8122647.2296 * parameters.num_locks_so_far 
	- 41012.8531 * parameters.total_wait_locks 
	+ 0.394 * parameters.mean_wait_of_all 
	- 626439384.4663 * parameters.cpu_usage 
	+ 0.4397 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0082 * parameters.avg_latency_of_same_last_20 
	- 0.004 * parameters.max_latency_of_same_last_50 
	+ 1047781904.5888;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM47(work_wait &parameters) {
  double actual_remaining = 
	2.1324 * parameters.work_so_far 
	+ 0.281 * parameters.wait_so_far 
	+ 63002077.9284 * parameters.num_locks_so_far 
	- 1588658.3066 * parameters.total_wait_locks 
	+ 10.5025 * parameters.mean_wait_of_all 
	- 952329672.1899 * parameters.cpu_usage 
	+ 0.0114 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0035 * parameters.avg_latency_of_same_last_20 
	- 0.0007 * parameters.max_latency_of_same_last_50 
	+ 766407866.2568;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM48(work_wait &parameters) {
  double actual_remaining = 
	1.0056 * parameters.work_so_far 
	+ 0.6399 * parameters.wait_so_far 
	- 466949.0157 * parameters.num_locks_so_far 
	- 288992.9145 * parameters.total_wait_locks 
	+ 2.1773 * parameters.mean_wait_of_all 
	+ 478915773.5888 * parameters.cpu_usage 
	+ 0.2174 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.2508 * parameters.avg_latency_of_same_last_20 
	- 0.0007 * parameters.max_latency_of_same_last_50 
	- 401667740.4365;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM49(work_wait &parameters) {
  double actual_remaining = 
	0.1446 * parameters.work_so_far 
	+ 0.717 * parameters.wait_so_far 
	- 2993152.5439 * parameters.num_locks_so_far 
	- 2014429.5232 * parameters.total_wait_locks 
	+ 11.9441 * parameters.mean_wait_of_all 
	- 4689778.2691 * parameters.cpu_usage 
	- 0.3358 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.1789 * parameters.avg_latency_of_same_last_20 
	- 0.0007 * parameters.max_latency_of_same_last_50 
	+ 175415941.9413;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM50(work_wait &parameters) {
  double actual_remaining = 
	-0.6745 * parameters.work_so_far 
	+ 0.3124 * parameters.wait_so_far 
	- 12681015.287 * parameters.num_locks_so_far 
	- 501048.7644 * parameters.total_wait_locks 
	+ 3.4574 * parameters.mean_wait_of_all 
	- 4689778.2691 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0087 * parameters.avg_latency_of_same_last_20 
	- 0.0007 * parameters.max_latency_of_same_last_50 
	+ 1256059114.551;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM51(work_wait &parameters) {
  double actual_remaining = 
	0.3148 * parameters.work_so_far 
	+ 0.625 * parameters.wait_so_far 
	- 2505573.2319 * parameters.num_locks_so_far 
	- 501048.7644 * parameters.total_wait_locks 
	+ 3.4574 * parameters.mean_wait_of_all 
	- 4689778.2691 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0087 * parameters.avg_latency_of_same_last_20 
	+ 0.045 * parameters.max_latency_of_same_last_50 
	+ 461805749.6654;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM52(work_wait &parameters) {
  double actual_remaining = 
	0.4664 * parameters.work_so_far 
	+ 0.8796 * parameters.wait_so_far 
	- 523979.125 * parameters.num_locks_so_far 
	- 348451.0941 * parameters.total_wait_locks 
	+ 2.5082 * parameters.mean_wait_of_all 
	- 4689778.2691 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.343 * parameters.avg_wait_of_same_past_second 
	+ 0.1199 * parameters.avg_latency_of_same_last_20 
	- 0.0007 * parameters.max_latency_of_same_last_50 
	+ 269650060.0268;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM53(work_wait &parameters) {
  double actual_remaining = 
	0.5553 * parameters.work_so_far 
	+ 0.8149 * parameters.wait_so_far 
	- 523979.125 * parameters.num_locks_so_far 
	- 348451.0941 * parameters.total_wait_locks 
	+ 2.5082 * parameters.mean_wait_of_all 
	- 4689778.2691 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.5926 * parameters.avg_wait_of_same_past_second 
	+ 0.1199 * parameters.avg_latency_of_same_last_20 
	- 0.0007 * parameters.max_latency_of_same_last_50 
	+ 460104090.771;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM54(work_wait &parameters) {
  double actual_remaining = 
	0.4316 * parameters.work_so_far 
	+ 0.7975 * parameters.wait_so_far 
	- 523979.125 * parameters.num_locks_so_far 
	- 348451.0941 * parameters.total_wait_locks 
	+ 2.5082 * parameters.mean_wait_of_all 
	- 4689778.2691 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.1812 * parameters.avg_latency_of_same_last_20 
	- 0.0007 * parameters.max_latency_of_same_last_50 
	+ 371696650.4164;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM55(work_wait &parameters) {
  double actual_remaining = 
	0.4316 * parameters.work_so_far 
	+ 0.6824 * parameters.wait_so_far 
	- 2613954.1284 * parameters.num_locks_so_far 
	- 348451.0941 * parameters.total_wait_locks 
	+ 2.5082 * parameters.mean_wait_of_all 
	- 4689778.2691 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.1812 * parameters.avg_latency_of_same_last_20 
	- 0.0007 * parameters.max_latency_of_same_last_50 
	+ 697412379.8456;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM56(work_wait &parameters) {
  double actual_remaining = 
	0.4316 * parameters.work_so_far 
	+ 0.6824 * parameters.wait_so_far 
	- 2393956.7596 * parameters.num_locks_so_far 
	- 348451.0941 * parameters.total_wait_locks 
	+ 2.5082 * parameters.mean_wait_of_all 
	- 4689778.2691 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.129 * parameters.avg_latency_of_same_last_20 
	- 0.0007 * parameters.max_latency_of_same_last_50 
	+ 720566158.1291;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
new_order_estimate(work_wait &parameters){

  if (parameters.total_wait_locks <= 213.5) {

    if (parameters.work_so_far <= 74365541.5) {

      if (parameters.avg_latency_of_same_last_20 <= 137930000) {

        if (parameters.cpu_usage <= 0.892) {
          return new_order_LM1(parameters);
        } else {

          if (parameters.avg_latency_of_same_last_20 <= 31072800) {

            if (parameters.work_so_far <= 26082342.5) {
              return new_order_LM2(parameters);
            } else {

              if (parameters.total_wait_locks <= 53.5) {
                return new_order_LM3(parameters);
              } else {
                return new_order_LM4(parameters);
              }
            }
          } else {

            if (parameters.max_latency_of_same_last_50 <= 311341000) {

              if (parameters.num_locks_so_far <= 19) {

                if (parameters.work_so_far <= 27384) {
                  return new_order_LM5(parameters);
                } else {

                  if (parameters.wait_so_far <= 6163690) {

                    if (parameters.total_wait_locks <= 56) {
                      return new_order_LM6(parameters);
                    } else {
                      return new_order_LM7(parameters);
                    }
                  } else {
                    return new_order_LM8(parameters);
                  }
                }
              } else {
                return new_order_LM9(parameters);
              }
            } else {

              if (parameters.total_wait_locks <= 142.5) {
                return new_order_LM10(parameters);
              } else {

                if (parameters.wait_so_far <= 1729925.5) {
                  return new_order_LM11(parameters);
                } else {

                  if (parameters.work_so_far <= 73255) {
                    return new_order_LM12(parameters);
                  } else {

                    if (parameters.work_so_far <= 3210128.5) {

                      if (parameters.avg_work_of_same_past_second <= 149491000) {
                        return new_order_LM13(parameters);
                      } else {
                        return new_order_LM14(parameters);
                      }
                    } else {
                      return new_order_LM15(parameters);
                    }
                  }
                }
              }
            }
          }
        }
      } else {

        if (parameters.work_so_far <= 80890.5) {
          return new_order_LM16(parameters);
        } else {

          if (parameters.num_locks_so_far <= 20.5) {

            if (parameters.work_so_far <= 14096881.5) {
              return new_order_LM17(parameters);
            } else {

              if (parameters.num_locks_so_far <= 10.5) {

                if (parameters.avg_wait_of_same_past_second <= 23671050) {

                  if (parameters.avg_wait_of_same_past_second <= 18376550) {

                    if (parameters.mean_wait_of_all <= 47090750) {
                      return new_order_LM18(parameters);
                    } else {
                      return new_order_LM19(parameters);
                    }
                  } else {
                    return new_order_LM20(parameters);
                  }
                } else {
                  return new_order_LM21(parameters);
                }
              } else {

                if (parameters.wait_so_far <= 51870802.5) {
                  return new_order_LM22(parameters);
                } else {
                  return new_order_LM23(parameters);
                }
              }
            }
          } else {
            return new_order_LM24(parameters);
          }
        }
      }
    } else {

      if (parameters.work_so_far <= 231707862.5) {

        if (parameters.num_locks_so_far <= 25.5) {
          return new_order_LM25(parameters);
        } else {
          return new_order_LM26(parameters);
        }
      } else {

        if (parameters.mean_wait_of_all <= 43204950) {

          if (parameters.work_so_far <= 308324633.5) {
            return new_order_LM27(parameters);
          } else {

            if (parameters.num_locks_so_far <= 16.5) {
              return new_order_LM28(parameters);
            } else {
              return new_order_LM29(parameters);
            }
          }
        } else {
          return new_order_LM30(parameters);
        }
      }
    }
  } else {

    if (parameters.num_locks_so_far <= 5.5) {

      if (parameters.wait_so_far <= 194288090) {

        if (parameters.mean_wait_of_all <= 83797100) {

          if (parameters.wait_so_far <= 23219814.5) {
            return new_order_LM31(parameters);
          } else {

            if (parameters.work_so_far <= 1231779) {
              return new_order_LM32(parameters);
            } else {
              return new_order_LM33(parameters);
            }
          }
        } else {

          if (parameters.wait_so_far <= 123248) {

            if (parameters.wait_so_far <= 15647.5) {
              return new_order_LM34(parameters);
            } else {
              return new_order_LM35(parameters);
            }
          } else {

            if (parameters.work_so_far <= 67903.5) {
              return new_order_LM36(parameters);
            } else {
              return new_order_LM37(parameters);
            }
          }
        }
      } else {
        return new_order_LM38(parameters);
      }
    } else {

      if (parameters.wait_so_far <= 291794511) {

        if (parameters.work_so_far <= 113785936.5) {

          if (parameters.num_locks_so_far <= 11.5) {

            if (parameters.num_locks_so_far <= 9.5) {

              if (parameters.work_so_far <= 10536093.5) {
                return new_order_LM39(parameters);
              } else {

                if (parameters.cpu_usage <= 0.974) {
                  return new_order_LM40(parameters);
                } else {
                  return new_order_LM41(parameters);
                }
              }
            } else {
              return new_order_LM42(parameters);
            }
          } else {
            return new_order_LM43(parameters);
          }
        } else {

          if (parameters.work_so_far <= 412099212.5) {

            if (parameters.num_locks_so_far <= 21.5) {
              return new_order_LM44(parameters);
            } else {
              return new_order_LM45(parameters);
            }
          } else {
            return new_order_LM46(parameters);
          }
        }
      } else {

        if (parameters.wait_so_far <= 696990655) {

          if (parameters.num_locks_so_far <= 11.5) {
            return new_order_LM47(parameters);
          } else {
            return new_order_LM48(parameters);
          }
        } else {

          if (parameters.wait_so_far <= 1052909745.5) {

            if (parameters.work_so_far <= 59808797.5) {
              return new_order_LM49(parameters);
            } else {

              if (parameters.avg_latency_of_same_last_20 <= 470175500) {
                return new_order_LM50(parameters);
              } else {
                return new_order_LM51(parameters);
              }
            }
          } else {

            if (parameters.wait_so_far <= 1449307250.5) {

              if (parameters.work_so_far <= 64898093.5) {
                return new_order_LM52(parameters);
              } else {
                return new_order_LM53(parameters);
              }
            } else {

              if (parameters.max_latency_of_same_last_50 <= 2126815000) {
                return new_order_LM54(parameters);
              } else {

                if (parameters.num_locks_so_far <= 14.5) {
                  return new_order_LM55(parameters);
                } else {
                  return new_order_LM56(parameters);
                }
              }
            }
          }
        }
      }
    }
  }
}