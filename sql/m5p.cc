#include "my_global.h"
#include "m5p.h"
#include "trace_tool.h"

static
double
new_order_LM1(work_wait &parameters) {
  double actual_remaining = 
	0.6132 * parameters.work_so_far 
	- 0.1711 * parameters.wait_so_far 
	+ 614435.3079 * parameters.total_wait_locks 
	- 1.6152 * parameters.mean_wait_of_all 
	+ 180118466.0835 * parameters.cpu_usage 
	+ 0.2252 * parameters.avg_work_of_same_past_second 
	+ 0.2187 * parameters.avg_latency_of_same_last_20 
	- 0.0218 * parameters.max_latency_of_same_last_50 
	- 57655865.6475;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
new_order_estimate(work_wait &parameters){
  return new_order_LM1(parameters);
}
static
double
payment_LM1(work_wait &parameters) {
  double actual_remaining = 
	0.007 * parameters.work_so_far 
	+ 0.0414 * parameters.wait_so_far 
	+ 3980.3857 * parameters.total_wait_locks 
	+ 0.1473 * parameters.mean_wait_of_all 
	- 41814768.5171 * parameters.cpu_usage 
	- 0.1401 * parameters.avg_work_of_same_past_second 
	- 0.0017 * parameters.avg_wait_of_same_past_second 
	+ 0.1031 * parameters.avg_latency_of_same_last_20 
	- 0.0093 * parameters.max_latency_of_same_last_50 
	+ 41011955.8308;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM2(work_wait &parameters) {
  double actual_remaining = 
	1264.9993 * parameters.work_so_far 
	+ 0.0038 * parameters.wait_so_far 
	+ 17426.2251 * parameters.total_wait_locks 
	- 0.0395 * parameters.mean_wait_of_all 
	+ 43583573.2564 * parameters.cpu_usage 
	+ 0.964 * parameters.avg_work_of_same_past_second 
	- 0.1575 * parameters.avg_wait_of_same_past_second 
	+ 0.1276 * parameters.avg_latency_of_same_last_20 
	- 0.0266 * parameters.max_latency_of_same_last_50 
	- 41363582.3359;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM3(work_wait &parameters) {
  double actual_remaining = 
	361.9191 * parameters.work_so_far 
	+ 0.0037 * parameters.wait_so_far 
	+ 375479.1289 * parameters.total_wait_locks 
	- 1.4264 * parameters.mean_wait_of_all 
	+ 270756566.9678 * parameters.cpu_usage 
	+ 0.0441 * parameters.avg_work_of_same_past_second 
	+ 2.2364 * parameters.avg_wait_of_same_past_second 
	- 0.0776 * parameters.avg_latency_of_same_last_20 
	- 0.0081 * parameters.max_latency_of_same_last_50 
	- 177033364.4394;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM4(work_wait &parameters) {
  double actual_remaining = 
	361.9191 * parameters.work_so_far 
	+ 0.0037 * parameters.wait_so_far 
	- 1296832.1138 * parameters.total_wait_locks 
	- 1.4264 * parameters.mean_wait_of_all 
	+ 383383828.3886 * parameters.cpu_usage 
	+ 0.0441 * parameters.avg_work_of_same_past_second 
	+ 8.2734 * parameters.avg_wait_of_same_past_second 
	- 0.0776 * parameters.avg_latency_of_same_last_20 
	- 0.0081 * parameters.max_latency_of_same_last_50 
	- 195676150.8334;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM5(work_wait &parameters) {
  double actual_remaining = 
	2096.7132 * parameters.work_so_far 
	+ 0.0037 * parameters.wait_so_far 
	+ 454509.8946 * parameters.total_wait_locks 
	- 0.7819 * parameters.mean_wait_of_all 
	- 38968401.9394 * parameters.cpu_usage 
	+ 0.0441 * parameters.avg_work_of_same_past_second 
	+ 2.7628 * parameters.avg_wait_of_same_past_second 
	- 0.0342 * parameters.avg_latency_of_same_last_20 
	- 0.0081 * parameters.max_latency_of_same_last_50 
	+ 17403287.1604;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM6(work_wait &parameters) {
  double actual_remaining = 
	432.2586 * parameters.work_so_far 
	+ 0.0087 * parameters.wait_so_far 
	+ 38467.1596 * parameters.total_wait_locks 
	- 0.5989 * parameters.mean_wait_of_all 
	- 34161171.1181 * parameters.cpu_usage 
	+ 0.1405 * parameters.avg_work_of_same_past_second 
	- 0.0259 * parameters.avg_wait_of_same_past_second 
	+ 0.1713 * parameters.avg_latency_of_same_last_20 
	- 0.0411 * parameters.max_latency_of_same_last_50 
	+ 64628755.3106;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM7(work_wait &parameters) {
  double actual_remaining = 
	597.8542 * parameters.work_so_far 
	+ 0.0958 * parameters.wait_so_far 
	+ 38467.1596 * parameters.total_wait_locks 
	- 0.1078 * parameters.mean_wait_of_all 
	- 177145965.1802 * parameters.cpu_usage 
	+ 0.2166 * parameters.avg_work_of_same_past_second 
	- 0.0387 * parameters.avg_wait_of_same_past_second 
	+ 0.006 * parameters.avg_latency_of_same_last_20 
	- 0.0097 * parameters.max_latency_of_same_last_50 
	+ 164055041.3248;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM8(work_wait &parameters) {
  double actual_remaining = 
	255.8249 * parameters.work_so_far 
	+ 0.0066 * parameters.wait_so_far 
	- 7496.0248 * parameters.total_wait_locks 
	+ 0.0406 * parameters.mean_wait_of_all 
	+ 4885687.3412 * parameters.cpu_usage 
	+ 0.0646 * parameters.avg_work_of_same_past_second 
	- 0.0144 * parameters.avg_wait_of_same_past_second 
	- 0.0104 * parameters.avg_latency_of_same_last_20 
	+ 0.0045 * parameters.max_latency_of_same_last_50 
	- 2033699.5048;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM9(work_wait &parameters) {
  double actual_remaining = 
	317.4325 * parameters.work_so_far 
	+ 0.0066 * parameters.wait_so_far 
	- 25236.4244 * parameters.total_wait_locks 
	+ 0.0995 * parameters.mean_wait_of_all 
	+ 4885687.3412 * parameters.cpu_usage 
	+ 0.1179 * parameters.avg_work_of_same_past_second 
	- 0.0236 * parameters.avg_wait_of_same_past_second 
	- 0.0104 * parameters.avg_latency_of_same_last_20 
	+ 0.0045 * parameters.max_latency_of_same_last_50 
	- 3428605.6361;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM10(work_wait &parameters) {
  double actual_remaining = 
	253.6042 * parameters.work_so_far 
	+ 0.0066 * parameters.wait_so_far 
	- 14789.3002 * parameters.total_wait_locks 
	+ 0.0648 * parameters.mean_wait_of_all 
	+ 4885687.3412 * parameters.cpu_usage 
	+ 0.3534 * parameters.avg_work_of_same_past_second 
	- 0.0482 * parameters.avg_wait_of_same_past_second 
	- 0.0104 * parameters.avg_latency_of_same_last_20 
	+ 0.0045 * parameters.max_latency_of_same_last_50 
	- 2174991.9289;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM11(work_wait &parameters) {
  double actual_remaining = 
	253.6042 * parameters.work_so_far 
	+ 0.0066 * parameters.wait_so_far 
	- 14789.3002 * parameters.total_wait_locks 
	+ 0.0648 * parameters.mean_wait_of_all 
	+ 4885687.3412 * parameters.cpu_usage 
	+ 0.2199 * parameters.avg_work_of_same_past_second 
	- 0.0521 * parameters.avg_wait_of_same_past_second 
	- 0.0104 * parameters.avg_latency_of_same_last_20 
	+ 0.0045 * parameters.max_latency_of_same_last_50 
	- 526700.5123;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM12(work_wait &parameters) {
  double actual_remaining = 
	253.6042 * parameters.work_so_far 
	+ 0.0066 * parameters.wait_so_far 
	- 14789.3002 * parameters.total_wait_locks 
	+ 0.1135 * parameters.mean_wait_of_all 
	+ 4885687.3412 * parameters.cpu_usage 
	+ 0.1026 * parameters.avg_work_of_same_past_second 
	- 0.021 * parameters.avg_wait_of_same_past_second 
	- 0.0104 * parameters.avg_latency_of_same_last_20 
	+ 0.0045 * parameters.max_latency_of_same_last_50 
	- 2966050.4815;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM13(work_wait &parameters) {
  double actual_remaining = 
	1683.9383 * parameters.work_so_far 
	+ 0.0167 * parameters.wait_so_far 
	- 49907.6348 * parameters.total_wait_locks 
	+ 0.1771 * parameters.mean_wait_of_all 
	- 112871627.5569 * parameters.cpu_usage 
	+ 0.0305 * parameters.avg_work_of_same_past_second 
	- 0.0081 * parameters.avg_wait_of_same_past_second 
	- 0.2965 * parameters.avg_latency_of_same_last_20 
	+ 0.0147 * parameters.max_latency_of_same_last_50 
	+ 117873142.6026;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM14(work_wait &parameters) {
  double actual_remaining = 
	698.6553 * parameters.work_so_far 
	+ 0.0167 * parameters.wait_so_far 
	- 111927.0809 * parameters.total_wait_locks 
	+ 0.1771 * parameters.mean_wait_of_all 
	- 112871627.5569 * parameters.cpu_usage 
	+ 0.0305 * parameters.avg_work_of_same_past_second 
	- 0.0081 * parameters.avg_wait_of_same_past_second 
	- 0.2422 * parameters.avg_latency_of_same_last_20 
	+ 0.0147 * parameters.max_latency_of_same_last_50 
	+ 129591827.9276;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM15(work_wait &parameters) {
  double actual_remaining = 
	643.87 * parameters.work_so_far 
	+ 0.0167 * parameters.wait_so_far 
	- 110297.7662 * parameters.total_wait_locks 
	+ 0.1771 * parameters.mean_wait_of_all 
	- 112871627.5569 * parameters.cpu_usage 
	+ 0.0305 * parameters.avg_work_of_same_past_second 
	- 0.0081 * parameters.avg_wait_of_same_past_second 
	- 0.2422 * parameters.avg_latency_of_same_last_20 
	+ 0.0147 * parameters.max_latency_of_same_last_50 
	+ 129634338.5012;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM16(work_wait &parameters) {
  double actual_remaining = 
	812.7287 * parameters.work_so_far 
	+ 0.0167 * parameters.wait_so_far 
	- 49907.6348 * parameters.total_wait_locks 
	+ 0.1771 * parameters.mean_wait_of_all 
	- 86703335.3573 * parameters.cpu_usage 
	+ 0.0305 * parameters.avg_work_of_same_past_second 
	- 0.0081 * parameters.avg_wait_of_same_past_second 
	- 0.0361 * parameters.avg_latency_of_same_last_20 
	+ 0.0325 * parameters.max_latency_of_same_last_50 
	+ 78770013.1859;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM17(work_wait &parameters) {
  double actual_remaining = 
	-243.7944 * parameters.work_so_far 
	+ 0.001 * parameters.wait_so_far 
	+ 241117.1787 * parameters.total_wait_locks 
	- 3.3844 * parameters.mean_wait_of_all 
	+ 60151261.166 * parameters.cpu_usage 
	+ 0.0183 * parameters.avg_work_of_same_past_second 
	- 0.0096 * parameters.avg_wait_of_same_past_second 
	+ 0.0053 * parameters.avg_latency_of_same_last_20 
	- 0.0016 * parameters.max_latency_of_same_last_50 
	+ 53764362.5479;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM18(work_wait &parameters) {
  double actual_remaining = 
	-1138.6587 * parameters.work_so_far 
	+ 0.001 * parameters.wait_so_far 
	+ 194560.4276 * parameters.total_wait_locks 
	- 1.9672 * parameters.mean_wait_of_all 
	- 44500764.4363 * parameters.cpu_usage 
	+ 0.0183 * parameters.avg_work_of_same_past_second 
	- 0.0096 * parameters.avg_wait_of_same_past_second 
	+ 0.0053 * parameters.avg_latency_of_same_last_20 
	- 0.0016 * parameters.max_latency_of_same_last_50 
	+ 129638020.2319;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM19(work_wait &parameters) {
  double actual_remaining = 
	-4528.1202 * parameters.work_so_far 
	+ 0.001 * parameters.wait_so_far 
	+ 194560.4276 * parameters.total_wait_locks 
	- 2.232 * parameters.mean_wait_of_all 
	+ 138029903.6191 * parameters.cpu_usage 
	+ 0.0183 * parameters.avg_work_of_same_past_second 
	- 0.0096 * parameters.avg_wait_of_same_past_second 
	+ 0.3299 * parameters.avg_latency_of_same_last_20 
	- 0.0016 * parameters.max_latency_of_same_last_50 
	+ 22202442.3501;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM20(work_wait &parameters) {
  double actual_remaining = 
	-4641.0194 * parameters.work_so_far 
	+ 0.001 * parameters.wait_so_far 
	+ 194560.4276 * parameters.total_wait_locks 
	- 2.232 * parameters.mean_wait_of_all 
	+ 138029903.6191 * parameters.cpu_usage 
	+ 0.0183 * parameters.avg_work_of_same_past_second 
	- 0.0096 * parameters.avg_wait_of_same_past_second 
	+ 0.3299 * parameters.avg_latency_of_same_last_20 
	- 0.0016 * parameters.max_latency_of_same_last_50 
	+ 23973179.6055;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM21(work_wait &parameters) {
  double actual_remaining = 
	-4673.4793 * parameters.work_so_far 
	+ 0.001 * parameters.wait_so_far 
	+ 194560.4276 * parameters.total_wait_locks 
	- 2.1257 * parameters.mean_wait_of_all 
	+ 138029903.6191 * parameters.cpu_usage 
	+ 0.0183 * parameters.avg_work_of_same_past_second 
	- 0.0096 * parameters.avg_wait_of_same_past_second 
	+ 0.3299 * parameters.avg_latency_of_same_last_20 
	- 0.0016 * parameters.max_latency_of_same_last_50 
	+ 22313101.2948;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM22(work_wait &parameters) {
  double actual_remaining = 
	-4659.2991 * parameters.work_so_far 
	+ 0.001 * parameters.wait_so_far 
	+ 194560.4276 * parameters.total_wait_locks 
	- 2.9052 * parameters.mean_wait_of_all 
	+ 138029903.6191 * parameters.cpu_usage 
	+ 0.0183 * parameters.avg_work_of_same_past_second 
	- 0.0096 * parameters.avg_wait_of_same_past_second 
	+ 0.3569 * parameters.avg_latency_of_same_last_20 
	- 0.0016 * parameters.max_latency_of_same_last_50 
	+ 51976041.7168;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM23(work_wait &parameters) {
  double actual_remaining = 
	-4501.3404 * parameters.work_so_far 
	+ 0.001 * parameters.wait_so_far 
	+ 301662.7219 * parameters.total_wait_locks 
	- 2.9052 * parameters.mean_wait_of_all 
	+ 138029903.6191 * parameters.cpu_usage 
	+ 0.0183 * parameters.avg_work_of_same_past_second 
	- 0.0096 * parameters.avg_wait_of_same_past_second 
	+ 0.3569 * parameters.avg_latency_of_same_last_20 
	- 0.0016 * parameters.max_latency_of_same_last_50 
	+ 40563376.1362;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM24(work_wait &parameters) {
  double actual_remaining = 
	-2841.495 * parameters.work_so_far 
	+ 0.001 * parameters.wait_so_far 
	+ 524695.8135 * parameters.total_wait_locks 
	- 2.8329 * parameters.mean_wait_of_all 
	+ 138029903.6191 * parameters.cpu_usage 
	+ 0.0183 * parameters.avg_work_of_same_past_second 
	- 0.0096 * parameters.avg_wait_of_same_past_second 
	+ 0.0053 * parameters.avg_latency_of_same_last_20 
	- 0.0016 * parameters.max_latency_of_same_last_50 
	- 4401075.9253;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM25(work_wait &parameters) {
  double actual_remaining = 
	-2841.495 * parameters.work_so_far 
	+ 0.001 * parameters.wait_so_far 
	+ 2480880.3503 * parameters.total_wait_locks 
	- 2.8329 * parameters.mean_wait_of_all 
	+ 138029903.6191 * parameters.cpu_usage 
	+ 0.0183 * parameters.avg_work_of_same_past_second 
	- 0.0096 * parameters.avg_wait_of_same_past_second 
	+ 0.0053 * parameters.avg_latency_of_same_last_20 
	- 0.0016 * parameters.max_latency_of_same_last_50 
	- 194533457.0234;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM26(work_wait &parameters) {
  double actual_remaining = 
	-2841.495 * parameters.work_so_far 
	+ 0.001 * parameters.wait_so_far 
	+ 2504508.3057 * parameters.total_wait_locks 
	- 2.8329 * parameters.mean_wait_of_all 
	+ 138029903.6191 * parameters.cpu_usage 
	+ 0.0183 * parameters.avg_work_of_same_past_second 
	- 0.0096 * parameters.avg_wait_of_same_past_second 
	+ 0.0053 * parameters.avg_latency_of_same_last_20 
	- 0.0016 * parameters.max_latency_of_same_last_50 
	- 196956361.3718;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM27(work_wait &parameters) {
  double actual_remaining = 
	-2841.495 * parameters.work_so_far 
	+ 0.001 * parameters.wait_so_far 
	+ 3194798.6621 * parameters.total_wait_locks 
	- 2.8329 * parameters.mean_wait_of_all 
	+ 138029903.6191 * parameters.cpu_usage 
	+ 0.0183 * parameters.avg_work_of_same_past_second 
	- 0.0096 * parameters.avg_wait_of_same_past_second 
	+ 0.0053 * parameters.avg_latency_of_same_last_20 
	- 0.0016 * parameters.max_latency_of_same_last_50 
	- 263232074.1666;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM28(work_wait &parameters) {
  double actual_remaining = 
	-2408.617 * parameters.work_so_far 
	+ 0.0165 * parameters.wait_so_far 
	+ 194560.4276 * parameters.total_wait_locks 
	- 2.6824 * parameters.mean_wait_of_all 
	+ 138029903.6191 * parameters.cpu_usage 
	+ 0.0183 * parameters.avg_work_of_same_past_second 
	- 0.0096 * parameters.avg_wait_of_same_past_second 
	+ 0.0053 * parameters.avg_latency_of_same_last_20 
	- 0.0016 * parameters.max_latency_of_same_last_50 
	+ 12093525.0155;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM29(work_wait &parameters) {
  double actual_remaining = 
	356.6573 * parameters.work_so_far 
	+ 0.0398 * parameters.wait_so_far 
	+ 9721.3374 * parameters.total_wait_locks 
	- 0.1009 * parameters.mean_wait_of_all 
	+ 11200270.5342 * parameters.cpu_usage 
	+ 0.1657 * parameters.avg_work_of_same_past_second 
	- 0.03 * parameters.avg_wait_of_same_past_second 
	+ 0.0078 * parameters.avg_latency_of_same_last_20 
	- 0.0008 * parameters.max_latency_of_same_last_50 
	- 5440724.8133;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM30(work_wait &parameters) {
  double actual_remaining = 
	1313.9537 * parameters.work_so_far 
	+ 0.0081 * parameters.wait_so_far 
	+ 9721.3374 * parameters.total_wait_locks 
	+ 0.6539 * parameters.mean_wait_of_all 
	+ 11200270.5342 * parameters.cpu_usage 
	+ 0.4346 * parameters.avg_work_of_same_past_second 
	- 0.144 * parameters.avg_wait_of_same_past_second 
	+ 0.0078 * parameters.avg_latency_of_same_last_20 
	- 0.0008 * parameters.max_latency_of_same_last_50 
	- 34247948.2937;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM31(work_wait &parameters) {
  double actual_remaining = 
	818.904 * parameters.work_so_far 
	+ 0.0081 * parameters.wait_so_far 
	+ 9721.3374 * parameters.total_wait_locks 
	+ 1.5203 * parameters.mean_wait_of_all 
	+ 11200270.5342 * parameters.cpu_usage 
	+ 1.8277 * parameters.avg_work_of_same_past_second 
	- 0.1354 * parameters.avg_wait_of_same_past_second 
	+ 0.0078 * parameters.avg_latency_of_same_last_20 
	- 0.0008 * parameters.max_latency_of_same_last_50 
	- 87337771.9518;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM32(work_wait &parameters) {
  double actual_remaining = 
	796.9953 * parameters.work_so_far 
	+ 0.031 * parameters.wait_so_far 
	+ 9721.3374 * parameters.total_wait_locks 
	- 0.1102 * parameters.mean_wait_of_all 
	+ 11200270.5342 * parameters.cpu_usage 
	+ 0.2113 * parameters.avg_work_of_same_past_second 
	- 0.0364 * parameters.avg_wait_of_same_past_second 
	+ 0.0078 * parameters.avg_latency_of_same_last_20 
	- 0.0008 * parameters.max_latency_of_same_last_50 
	- 11220924.8608;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM33(work_wait &parameters) {
  double actual_remaining = 
	-741.4978 * parameters.work_so_far 
	- 0.0137 * parameters.wait_so_far 
	+ 20144.3569 * parameters.total_wait_locks 
	- 2.8754 * parameters.mean_wait_of_all 
	+ 126119619.6705 * parameters.cpu_usage 
	- 0.0006 * parameters.avg_work_of_same_past_second 
	+ 0.0188 * parameters.avg_wait_of_same_past_second 
	- 0.0627 * parameters.avg_latency_of_same_last_20 
	+ 0.0274 * parameters.max_latency_of_same_last_50 
	- 754148.2293;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM34(work_wait &parameters) {
  double actual_remaining = 
	-741.4978 * parameters.work_so_far 
	- 0.0137 * parameters.wait_so_far 
	+ 20144.3569 * parameters.total_wait_locks 
	- 2.8754 * parameters.mean_wait_of_all 
	+ 326435793.3304 * parameters.cpu_usage 
	- 0.0006 * parameters.avg_work_of_same_past_second 
	+ 0.0188 * parameters.avg_wait_of_same_past_second 
	- 0.0299 * parameters.avg_latency_of_same_last_20 
	+ 0.011 * parameters.max_latency_of_same_last_50 
	- 177220165.5639;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM35(work_wait &parameters) {
  double actual_remaining = 
	-1130.228 * parameters.work_so_far 
	- 0.0195 * parameters.wait_so_far 
	+ 20144.3569 * parameters.total_wait_locks 
	- 3.6221 * parameters.mean_wait_of_all 
	+ 90810003.8204 * parameters.cpu_usage 
	- 0.0006 * parameters.avg_work_of_same_past_second 
	+ 0.0188 * parameters.avg_wait_of_same_past_second 
	+ 0.0044 * parameters.avg_latency_of_same_last_20 
	- 0.0061 * parameters.max_latency_of_same_last_50 
	+ 64433259.9316;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM36(work_wait &parameters) {
  double actual_remaining = 
	-517.5934 * parameters.work_so_far 
	- 0.0134 * parameters.wait_so_far 
	+ 20144.3569 * parameters.total_wait_locks 
	+ 12.4986 * parameters.mean_wait_of_all 
	+ 22700861.7834 * parameters.cpu_usage 
	- 0.0006 * parameters.avg_work_of_same_past_second 
	+ 0.0475 * parameters.avg_wait_of_same_past_second 
	+ 0.0044 * parameters.avg_latency_of_same_last_20 
	- 0.0112 * parameters.max_latency_of_same_last_50 
	- 358457383.4053;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM37(work_wait &parameters) {
  double actual_remaining = 
	28.4661 * parameters.work_so_far 
	+ 0.001 * parameters.wait_so_far 
	+ 174982.9733 * parameters.total_wait_locks 
	- 0.0271 * parameters.mean_wait_of_all 
	+ 86496577.2684 * parameters.cpu_usage 
	+ 0.0129 * parameters.avg_work_of_same_past_second 
	- 0.0453 * parameters.avg_wait_of_same_past_second 
	+ 0.0044 * parameters.avg_latency_of_same_last_20 
	- 0.0008 * parameters.max_latency_of_same_last_50 
	- 71892794.1832;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM38(work_wait &parameters) {
  double actual_remaining = 
	0.0173 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 1217381.4505 * parameters.total_wait_locks 
	- 2.4106 * parameters.mean_wait_of_all 
	- 264574917.1095 * parameters.cpu_usage 
	+ 0.1553 * parameters.avg_work_of_same_past_second 
	+ 8.765 * parameters.avg_wait_of_same_past_second 
	+ 0.0196 * parameters.avg_latency_of_same_last_20 
	- 0.1478 * parameters.max_latency_of_same_last_50 
	+ 248415697.7156;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM39(work_wait &parameters) {
  double actual_remaining = 
	0.0173 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 856031.495 * parameters.total_wait_locks 
	- 4.4819 * parameters.mean_wait_of_all 
	- 462507025.1855 * parameters.cpu_usage 
	+ 0.1553 * parameters.avg_work_of_same_past_second 
	+ 4.2376 * parameters.avg_wait_of_same_past_second 
	+ 0.0196 * parameters.avg_latency_of_same_last_20 
	- 0.096 * parameters.max_latency_of_same_last_50 
	+ 503962608.1399;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM40(work_wait &parameters) {
  double actual_remaining = 
	0.0173 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 55931.8107 * parameters.total_wait_locks 
	- 0.1678 * parameters.mean_wait_of_all 
	- 135743990.9582 * parameters.cpu_usage 
	+ 0.1553 * parameters.avg_work_of_same_past_second 
	- 0.023 * parameters.avg_wait_of_same_past_second 
	+ 0.0196 * parameters.avg_latency_of_same_last_20 
	- 0.0126 * parameters.max_latency_of_same_last_50 
	+ 148401242.4532;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM41(work_wait &parameters) {
  double actual_remaining = 
	0.0173 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 233450.0443 * parameters.total_wait_locks 
	- 0.0353 * parameters.mean_wait_of_all 
	- 1940658.393 * parameters.cpu_usage 
	+ 0.8503 * parameters.avg_work_of_same_past_second 
	- 0.162 * parameters.avg_wait_of_same_past_second 
	+ 0.2015 * parameters.avg_latency_of_same_last_20 
	- 0.0739 * parameters.max_latency_of_same_last_50 
	+ 32651606.9289;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM42(work_wait &parameters) {
  double actual_remaining = 
	0.0202 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	- 123222.7638 * parameters.total_wait_locks 
	- 0.0234 * parameters.mean_wait_of_all 
	- 2329647.74 * parameters.cpu_usage 
	- 0.3995 * parameters.avg_work_of_same_past_second 
	- 0.0095 * parameters.avg_wait_of_same_past_second 
	+ 0.0094 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 54532119.6027;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM43(work_wait &parameters) {
  double actual_remaining = 
	0.0202 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 13755.3708 * parameters.total_wait_locks 
	- 0.0234 * parameters.mean_wait_of_all 
	- 2329647.74 * parameters.cpu_usage 
	+ 0.0279 * parameters.avg_work_of_same_past_second 
	- 0.0095 * parameters.avg_wait_of_same_past_second 
	+ 0.0178 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 28587028.571;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM44(work_wait &parameters) {
  double actual_remaining = 
	0.0202 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 13755.3708 * parameters.total_wait_locks 
	- 2.2637 * parameters.mean_wait_of_all 
	- 2329647.74 * parameters.cpu_usage 
	+ 0.0279 * parameters.avg_work_of_same_past_second 
	- 0.0095 * parameters.avg_wait_of_same_past_second 
	- 0.0465 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 136470390.8656;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM45(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	+ 0.0058 * parameters.wait_so_far 
	+ 22865.6805 * parameters.total_wait_locks 
	+ 0.7502 * parameters.mean_wait_of_all 
	- 172757855.1608 * parameters.cpu_usage 
	+ 0.0268 * parameters.avg_work_of_same_past_second 
	- 0.0029 * parameters.avg_wait_of_same_past_second 
	+ 0.0941 * parameters.avg_latency_of_same_last_20 
	- 0.0079 * parameters.max_latency_of_same_last_50 
	+ 163252404.1862;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM46(work_wait &parameters) {
  double actual_remaining = 
	-1.5585 * parameters.work_so_far 
	+ 0.0746 * parameters.wait_so_far 
	- 572626.6284 * parameters.total_wait_locks 
	+ 0.6371 * parameters.mean_wait_of_all 
	- 20027149.5823 * parameters.cpu_usage 
	- 1.0241 * parameters.avg_work_of_same_past_second 
	+ 0.0271 * parameters.avg_wait_of_same_past_second 
	+ 0.1369 * parameters.avg_latency_of_same_last_20 
	- 0.0105 * parameters.max_latency_of_same_last_50 
	+ 154856549.8411;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM47(work_wait &parameters) {
  double actual_remaining = 
	-2.9075 * parameters.work_so_far 
	+ 0.0639 * parameters.wait_so_far 
	- 572626.6284 * parameters.total_wait_locks 
	+ 1.0556 * parameters.mean_wait_of_all 
	- 20027149.5823 * parameters.cpu_usage 
	- 1.4074 * parameters.avg_work_of_same_past_second 
	+ 0.0271 * parameters.avg_wait_of_same_past_second 
	+ 0.1369 * parameters.avg_latency_of_same_last_20 
	- 0.0105 * parameters.max_latency_of_same_last_50 
	+ 154745176.7186;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM48(work_wait &parameters) {
  double actual_remaining = 
	-1011.4905 * parameters.work_so_far 
	+ 0.0621 * parameters.wait_so_far 
	- 572626.6284 * parameters.total_wait_locks 
	+ 0.0707 * parameters.mean_wait_of_all 
	- 20027149.5823 * parameters.cpu_usage 
	- 1.2327 * parameters.avg_work_of_same_past_second 
	+ 0.0271 * parameters.avg_wait_of_same_past_second 
	+ 0.1797 * parameters.avg_latency_of_same_last_20 
	- 0.0105 * parameters.max_latency_of_same_last_50 
	+ 244044289.2403;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM49(work_wait &parameters) {
  double actual_remaining = 
	0.6471 * parameters.work_so_far 
	+ 0.0208 * parameters.wait_so_far 
	- 1169913.6258 * parameters.total_wait_locks 
	- 0.8169 * parameters.mean_wait_of_all 
	- 20027149.5823 * parameters.cpu_usage 
	+ 0.222 * parameters.avg_work_of_same_past_second 
	+ 0.0646 * parameters.avg_wait_of_same_past_second 
	+ 0.1261 * parameters.avg_latency_of_same_last_20 
	- 0.0105 * parameters.max_latency_of_same_last_50 
	+ 381716783.7936;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM50(work_wait &parameters) {
  double actual_remaining = 
	0.9421 * parameters.work_so_far 
	+ 0.0208 * parameters.wait_so_far 
	- 1965117.9099 * parameters.total_wait_locks 
	- 0.9944 * parameters.mean_wait_of_all 
	- 20027149.5823 * parameters.cpu_usage 
	+ 0.222 * parameters.avg_work_of_same_past_second 
	+ 0.0646 * parameters.avg_wait_of_same_past_second 
	+ 0.1261 * parameters.avg_latency_of_same_last_20 
	- 0.0105 * parameters.max_latency_of_same_last_50 
	+ 524662505.4025;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM51(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	+ 0.02 * parameters.wait_so_far 
	- 128626.3153 * parameters.total_wait_locks 
	+ 0.0707 * parameters.mean_wait_of_all 
	- 168525811.6445 * parameters.cpu_usage 
	+ 0.2107 * parameters.avg_work_of_same_past_second 
	- 0.0578 * parameters.avg_wait_of_same_past_second 
	+ 0.0186 * parameters.avg_latency_of_same_last_20 
	+ 0.3368 * parameters.max_latency_of_same_last_50 
	+ 15776630.772;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM52(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	+ 0.0071 * parameters.wait_so_far 
	+ 20026.309 * parameters.total_wait_locks 
	- 0.0084 * parameters.mean_wait_of_all 
	- 92008253.2168 * parameters.cpu_usage 
	+ 0.7728 * parameters.avg_work_of_same_past_second 
	- 0.056 * parameters.avg_wait_of_same_past_second 
	+ 0.1007 * parameters.avg_latency_of_same_last_20 
	- 0.0105 * parameters.max_latency_of_same_last_50 
	+ 82073216.0593;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM53(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	- 0.0656 * parameters.wait_so_far 
	- 621.4219 * parameters.total_wait_locks 
	- 16.9261 * parameters.mean_wait_of_all 
	- 632177514.095 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_work_of_same_past_second 
	+ 0.0111 * parameters.avg_wait_of_same_past_second 
	+ 0.2024 * parameters.avg_latency_of_same_last_20 
	- 0.0022 * parameters.max_latency_of_same_last_50 
	+ 1074001520.4502;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM54(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	- 0.0008 * parameters.wait_so_far 
	+ 223662.3644 * parameters.total_wait_locks 
	- 0.3311 * parameters.mean_wait_of_all 
	- 12767888.9116 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_work_of_same_past_second 
	+ 0.0111 * parameters.avg_wait_of_same_past_second 
	+ 0.007 * parameters.avg_latency_of_same_last_20 
	- 0.0022 * parameters.max_latency_of_same_last_50 
	+ 28387408.7339;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM55(work_wait &parameters) {
  double actual_remaining = 
	482.2733 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	- 259779.5322 * parameters.total_wait_locks 
	- 4.7536 * parameters.mean_wait_of_all 
	+ 127046454.5453 * parameters.cpu_usage 
	- 2.0906 * parameters.avg_work_of_same_past_second 
	+ 0.2351 * parameters.avg_wait_of_same_past_second 
	+ 0.0088 * parameters.avg_latency_of_same_last_20 
	- 0.0136 * parameters.max_latency_of_same_last_50 
	+ 244870709.8108;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM56(work_wait &parameters) {
  double actual_remaining = 
	482.2733 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	- 259779.5322 * parameters.total_wait_locks 
	- 4.7536 * parameters.mean_wait_of_all 
	+ 127046454.5453 * parameters.cpu_usage 
	- 2.0906 * parameters.avg_work_of_same_past_second 
	+ 0.2351 * parameters.avg_wait_of_same_past_second 
	+ 0.0088 * parameters.avg_latency_of_same_last_20 
	- 0.0136 * parameters.max_latency_of_same_last_50 
	+ 243977660.465;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM57(work_wait &parameters) {
  double actual_remaining = 
	822.2689 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	- 259779.5322 * parameters.total_wait_locks 
	- 4.7536 * parameters.mean_wait_of_all 
	+ 127046454.5453 * parameters.cpu_usage 
	- 1.9804 * parameters.avg_work_of_same_past_second 
	+ 0.2351 * parameters.avg_wait_of_same_past_second 
	+ 0.0088 * parameters.avg_latency_of_same_last_20 
	- 0.0136 * parameters.max_latency_of_same_last_50 
	+ 222069820.443;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM58(work_wait &parameters) {
  double actual_remaining = 
	-1.025 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	- 442759.9691 * parameters.total_wait_locks 
	- 4.9262 * parameters.mean_wait_of_all 
	+ 127046454.5453 * parameters.cpu_usage 
	- 1.386 * parameters.avg_work_of_same_past_second 
	+ 0.2351 * parameters.avg_wait_of_same_past_second 
	+ 0.0088 * parameters.avg_latency_of_same_last_20 
	- 0.0136 * parameters.max_latency_of_same_last_50 
	+ 233743125.6273;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM59(work_wait &parameters) {
  double actual_remaining = 
	-0.7728 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	- 269099.5664 * parameters.total_wait_locks 
	- 10.2783 * parameters.mean_wait_of_all 
	+ 127046454.5453 * parameters.cpu_usage 
	- 0.5086 * parameters.avg_work_of_same_past_second 
	+ 0.2377 * parameters.avg_wait_of_same_past_second 
	+ 0.0088 * parameters.avg_latency_of_same_last_20 
	- 0.0136 * parameters.max_latency_of_same_last_50 
	+ 330553801.9214;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM60(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	+ 0.0302 * parameters.wait_so_far 
	- 740539.9082 * parameters.total_wait_locks 
	- 9.6515 * parameters.mean_wait_of_all 
	+ 223805190.531 * parameters.cpu_usage 
	- 1.0719 * parameters.avg_work_of_same_past_second 
	+ 0.3039 * parameters.avg_wait_of_same_past_second 
	- 0.0276 * parameters.avg_latency_of_same_last_20 
	- 0.0184 * parameters.max_latency_of_same_last_50 
	+ 362644390.655;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM61(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	+ 0.0302 * parameters.wait_so_far 
	- 740539.9082 * parameters.total_wait_locks 
	- 6.5308 * parameters.mean_wait_of_all 
	+ 223805190.531 * parameters.cpu_usage 
	- 1.0719 * parameters.avg_work_of_same_past_second 
	+ 0.3039 * parameters.avg_wait_of_same_past_second 
	- 0.0276 * parameters.avg_latency_of_same_last_20 
	- 0.0184 * parameters.max_latency_of_same_last_50 
	+ 254014509.3866;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM62(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	+ 0.0265 * parameters.wait_so_far 
	- 1104909.392 * parameters.total_wait_locks 
	- 16.6731 * parameters.mean_wait_of_all 
	+ 223805190.531 * parameters.cpu_usage 
	- 1.0719 * parameters.avg_work_of_same_past_second 
	+ 0.3039 * parameters.avg_wait_of_same_past_second 
	- 0.0232 * parameters.avg_latency_of_same_last_20 
	- 0.0184 * parameters.max_latency_of_same_last_50 
	+ 721024971.0526;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM63(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	- 621.4219 * parameters.total_wait_locks 
	- 10.4369 * parameters.mean_wait_of_all 
	- 289847122.236 * parameters.cpu_usage 
	- 2.3669 * parameters.avg_work_of_same_past_second 
	+ 0.4788 * parameters.avg_wait_of_same_past_second 
	+ 0.0478 * parameters.avg_latency_of_same_last_20 
	- 0.0017 * parameters.max_latency_of_same_last_50 
	+ 743532149.008;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM64(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	- 0.0177 * parameters.wait_so_far 
	- 241638.6316 * parameters.total_wait_locks 
	+ 22.423 * parameters.mean_wait_of_all 
	- 952326.8915 * parameters.cpu_usage 
	- 1.0002 * parameters.avg_work_of_same_past_second 
	+ 0.001 * parameters.avg_wait_of_same_past_second 
	+ 0.0474 * parameters.avg_latency_of_same_last_20 
	- 0.0034 * parameters.max_latency_of_same_last_50 
	- 781200423.6832;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM65(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	- 0.0185 * parameters.wait_so_far 
	- 194191.117 * parameters.total_wait_locks 
	+ 31.358 * parameters.mean_wait_of_all 
	- 952326.8915 * parameters.cpu_usage 
	- 0.4005 * parameters.avg_work_of_same_past_second 
	- 0.1504 * parameters.avg_wait_of_same_past_second 
	+ 0.0277 * parameters.avg_latency_of_same_last_20 
	- 0.0034 * parameters.max_latency_of_same_last_50 
	- 1202452882.047;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM66(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	- 0.0185 * parameters.wait_so_far 
	- 137536.5721 * parameters.total_wait_locks 
	+ 13.0292 * parameters.mean_wait_of_all 
	- 952326.8915 * parameters.cpu_usage 
	- 0.4005 * parameters.avg_work_of_same_past_second 
	- 0.0657 * parameters.avg_wait_of_same_past_second 
	+ 0.0277 * parameters.avg_latency_of_same_last_20 
	- 0.0034 * parameters.max_latency_of_same_last_50 
	- 450914985.6005;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM67(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	- 0.0185 * parameters.wait_so_far 
	- 137536.5721 * parameters.total_wait_locks 
	+ 13.0292 * parameters.mean_wait_of_all 
	- 952326.8915 * parameters.cpu_usage 
	- 0.4005 * parameters.avg_work_of_same_past_second 
	- 0.0657 * parameters.avg_wait_of_same_past_second 
	+ 0.0277 * parameters.avg_latency_of_same_last_20 
	- 0.0034 * parameters.max_latency_of_same_last_50 
	- 453913656.6344;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM68(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	- 0.0505 * parameters.wait_so_far 
	+ 335573.4532 * parameters.total_wait_locks 
	+ 38.1938 * parameters.mean_wait_of_all 
	- 952326.8915 * parameters.cpu_usage 
	- 0.4005 * parameters.avg_work_of_same_past_second 
	- 1.2409 * parameters.avg_wait_of_same_past_second 
	+ 0.0277 * parameters.avg_latency_of_same_last_20 
	- 0.0645 * parameters.max_latency_of_same_last_50 
	- 1201806080.5319;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM69(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	- 0.0505 * parameters.wait_so_far 
	+ 335573.4532 * parameters.total_wait_locks 
	+ 38.1938 * parameters.mean_wait_of_all 
	- 952326.8915 * parameters.cpu_usage 
	- 0.4005 * parameters.avg_work_of_same_past_second 
	- 1.2409 * parameters.avg_wait_of_same_past_second 
	+ 0.0277 * parameters.avg_latency_of_same_last_20 
	- 0.0645 * parameters.max_latency_of_same_last_50 
	- 1204235635.9433;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM70(work_wait &parameters) {
  double actual_remaining = 
	0.5579 * parameters.work_so_far 
	- 0.04 * parameters.wait_so_far 
	+ 210701.0711 * parameters.total_wait_locks 
	+ 38.1938 * parameters.mean_wait_of_all 
	- 952326.8915 * parameters.cpu_usage 
	- 0.4005 * parameters.avg_work_of_same_past_second 
	- 1.3387 * parameters.avg_wait_of_same_past_second 
	+ 0.0667 * parameters.avg_latency_of_same_last_20 
	- 0.0261 * parameters.max_latency_of_same_last_50 
	- 1221594345.0334;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM71(work_wait &parameters) {
  double actual_remaining = 
	0.5579 * parameters.work_so_far 
	- 0.04 * parameters.wait_so_far 
	+ 244237.4432 * parameters.total_wait_locks 
	+ 38.1938 * parameters.mean_wait_of_all 
	- 952326.8915 * parameters.cpu_usage 
	- 0.4005 * parameters.avg_work_of_same_past_second 
	- 1.3387 * parameters.avg_wait_of_same_past_second 
	+ 0.0667 * parameters.avg_latency_of_same_last_20 
	- 0.0261 * parameters.max_latency_of_same_last_50 
	- 1226914101.5738;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM72(work_wait &parameters) {
  double actual_remaining = 
	0.4754 * parameters.work_so_far 
	- 0.04 * parameters.wait_so_far 
	+ 210701.0711 * parameters.total_wait_locks 
	+ 38.1938 * parameters.mean_wait_of_all 
	- 952326.8915 * parameters.cpu_usage 
	- 0.4005 * parameters.avg_work_of_same_past_second 
	- 1.2639 * parameters.avg_wait_of_same_past_second 
	+ 0.0679 * parameters.avg_latency_of_same_last_20 
	- 0.0418 * parameters.max_latency_of_same_last_50 
	- 1224532014.5426;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM73(work_wait &parameters) {
  double actual_remaining = 
	0.4754 * parameters.work_so_far 
	- 0.04 * parameters.wait_so_far 
	+ 210701.0711 * parameters.total_wait_locks 
	+ 38.1938 * parameters.mean_wait_of_all 
	- 952326.8915 * parameters.cpu_usage 
	- 0.4005 * parameters.avg_work_of_same_past_second 
	- 1.2805 * parameters.avg_wait_of_same_past_second 
	+ 0.0679 * parameters.avg_latency_of_same_last_20 
	- 0.0418 * parameters.max_latency_of_same_last_50 
	- 1219597877.4787;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM74(work_wait &parameters) {
  double actual_remaining = 
	0.4754 * parameters.work_so_far 
	- 0.04 * parameters.wait_so_far 
	+ 210701.0711 * parameters.total_wait_locks 
	+ 38.1938 * parameters.mean_wait_of_all 
	- 952326.8915 * parameters.cpu_usage 
	- 0.4005 * parameters.avg_work_of_same_past_second 
	- 1.2639 * parameters.avg_wait_of_same_past_second 
	+ 0.0702 * parameters.avg_latency_of_same_last_20 
	- 0.0418 * parameters.max_latency_of_same_last_50 
	- 1224838892.8669;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM75(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	- 621.4219 * parameters.total_wait_locks 
	- 0.0318 * parameters.mean_wait_of_all 
	- 952326.8915 * parameters.cpu_usage 
	+ 0.195 * parameters.avg_work_of_same_past_second 
	+ 0.001 * parameters.avg_wait_of_same_past_second 
	+ 0.0027 * parameters.avg_latency_of_same_last_20 
	- 0.0007 * parameters.max_latency_of_same_last_50 
	+ 32389186.5077;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM76(work_wait &parameters) {
  double actual_remaining = 
	-0.085 * parameters.work_so_far 
	+ 0.0281 * parameters.wait_so_far 
	+ 94114.5815 * parameters.total_wait_locks 
	- 1.6987 * parameters.mean_wait_of_all 
	- 952326.8915 * parameters.cpu_usage 
	- 0.2384 * parameters.avg_work_of_same_past_second 
	+ 0.038 * parameters.avg_wait_of_same_past_second 
	- 0.0218 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 115419031.3797;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM77(work_wait &parameters) {
  double actual_remaining = 
	-0.088 * parameters.work_so_far 
	+ 0.0103 * parameters.wait_so_far 
	+ 97262.3118 * parameters.total_wait_locks 
	- 1.751 * parameters.mean_wait_of_all 
	- 952326.8915 * parameters.cpu_usage 
	- 0.2463 * parameters.avg_work_of_same_past_second 
	+ 0.0392 * parameters.avg_wait_of_same_past_second 
	- 0.0226 * parameters.avg_latency_of_same_last_20 
	- 0.1164 * parameters.max_latency_of_same_last_50 
	+ 232282077.9479;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM78(work_wait &parameters) {
  double actual_remaining = 
	3.2285 * parameters.work_so_far 
	+ 0.0011 * parameters.wait_so_far 
	+ 2830.4022 * parameters.total_wait_locks 
	+ 49.6425 * parameters.mean_wait_of_all 
	- 952326.8915 * parameters.cpu_usage 
	- 0.0083 * parameters.avg_work_of_same_past_second 
	- 0.7319 * parameters.avg_wait_of_same_past_second 
	+ 0.0016 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	- 2248659003.8123;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM79(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	+ 0.0011 * parameters.wait_so_far 
	+ 2830.4022 * parameters.total_wait_locks 
	+ 3.7949 * parameters.mean_wait_of_all 
	- 952326.8915 * parameters.cpu_usage 
	- 0.0083 * parameters.avg_work_of_same_past_second 
	- 0.0321 * parameters.avg_wait_of_same_past_second 
	+ 0.087 * parameters.avg_latency_of_same_last_20 
	- 0.0045 * parameters.max_latency_of_same_last_50 
	- 171678125.2777;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM80(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	+ 0.0011 * parameters.wait_so_far 
	+ 219763.1795 * parameters.total_wait_locks 
	+ 8.4468 * parameters.mean_wait_of_all 
	- 952326.8915 * parameters.cpu_usage 
	- 0.0083 * parameters.avg_work_of_same_past_second 
	- 0.0932 * parameters.avg_wait_of_same_past_second 
	+ 0.017 * parameters.avg_latency_of_same_last_20 
	- 0.0078 * parameters.max_latency_of_same_last_50 
	- 380570705.2899;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM81(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	+ 0.0011 * parameters.wait_so_far 
	- 204887.0763 * parameters.total_wait_locks 
	+ 8.4468 * parameters.mean_wait_of_all 
	- 952326.8915 * parameters.cpu_usage 
	- 0.0083 * parameters.avg_work_of_same_past_second 
	- 0.0932 * parameters.avg_wait_of_same_past_second 
	+ 0.017 * parameters.avg_latency_of_same_last_20 
	- 0.0078 * parameters.max_latency_of_same_last_50 
	- 307893589.1601;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM82(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	+ 0.0011 * parameters.wait_so_far 
	+ 2830.4022 * parameters.total_wait_locks 
	+ 3.652 * parameters.mean_wait_of_all 
	- 952326.8915 * parameters.cpu_usage 
	- 1.7232 * parameters.avg_work_of_same_past_second 
	+ 0.0986 * parameters.avg_wait_of_same_past_second 
	+ 0.0429 * parameters.avg_latency_of_same_last_20 
	- 0.0039 * parameters.max_latency_of_same_last_50 
	- 87471546.9032;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM83(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	- 0.1846 * parameters.wait_so_far 
	+ 93397.5491 * parameters.total_wait_locks 
	- 3.8544 * parameters.mean_wait_of_all 
	+ 181562099.4111 * parameters.cpu_usage 
	- 0.1559 * parameters.avg_work_of_same_past_second 
	+ 0.0119 * parameters.avg_wait_of_same_past_second 
	+ 0.0016 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 57473825.935;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM84(work_wait &parameters) {
  double actual_remaining = 
	-0.1341 * parameters.work_so_far 
	+ 0.0035 * parameters.wait_so_far 
	+ 373994.2439 * parameters.total_wait_locks 
	- 2.0034 * parameters.mean_wait_of_all 
	+ 536203223.1274 * parameters.cpu_usage 
	- 0.0867 * parameters.avg_work_of_same_past_second 
	+ 0.0119 * parameters.avg_wait_of_same_past_second 
	+ 0.0518 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	- 451248729.1573;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM85(work_wait &parameters) {
  double actual_remaining = 
	0.9471 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	- 17190.4842 * parameters.total_wait_locks 
	+ 2.2544 * parameters.mean_wait_of_all 
	- 447164251.9904 * parameters.cpu_usage 
	- 0.0066 * parameters.avg_work_of_same_past_second 
	- 0.4136 * parameters.avg_wait_of_same_past_second 
	+ 0.0016 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 448323786.3047;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM86(work_wait &parameters) {
  double actual_remaining = 
	0.001 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	- 11109.4374 * parameters.total_wait_locks 
	- 5.1152 * parameters.mean_wait_of_all 
	+ 1929186.8013 * parameters.cpu_usage 
	- 5.5486 * parameters.avg_work_of_same_past_second 
	+ 0.206 * parameters.avg_wait_of_same_past_second 
	- 0.0245 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 854192134.5962;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM87(work_wait &parameters) {
  double actual_remaining = 
	-0.3504 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	- 11109.4374 * parameters.total_wait_locks 
	+ 3.515 * parameters.mean_wait_of_all 
	+ 562384688.1555 * parameters.cpu_usage 
	- 2.2457 * parameters.avg_work_of_same_past_second 
	- 0.251 * parameters.avg_wait_of_same_past_second 
	+ 0.0016 * parameters.avg_latency_of_same_last_20 
	+ 0.016 * parameters.max_latency_of_same_last_50 
	- 583826403.5044;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM88(work_wait &parameters) {
  double actual_remaining = 
	0.001 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 188985.1462 * parameters.total_wait_locks 
	- 0.7435 * parameters.mean_wait_of_all 
	+ 2631648.3253 * parameters.cpu_usage 
	- 0.0039 * parameters.avg_work_of_same_past_second 
	- 0.085 * parameters.avg_wait_of_same_past_second 
	+ 0.025 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 70973809.3441;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM89(work_wait &parameters) {
  double actual_remaining = 
	0.001 * parameters.work_so_far 
	+ 0.001 * parameters.wait_so_far 
	- 447619.3639 * parameters.total_wait_locks 
	+ 1.8752 * parameters.mean_wait_of_all 
	+ 29774342.7242 * parameters.cpu_usage 
	- 0.0229 * parameters.avg_work_of_same_past_second 
	- 0.0262 * parameters.avg_wait_of_same_past_second 
	+ 0.0036 * parameters.avg_latency_of_same_last_20 
	+ 0.0032 * parameters.max_latency_of_same_last_50 
	+ 24380617.4383;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM90(work_wait &parameters) {
  double actual_remaining = 
	0.001 * parameters.work_so_far 
	+ 0.001 * parameters.wait_so_far 
	- 13758.7509 * parameters.total_wait_locks 
	+ 0.0019 * parameters.mean_wait_of_all 
	- 201968357.7408 * parameters.cpu_usage 
	- 0.0229 * parameters.avg_work_of_same_past_second 
	- 0.0088 * parameters.avg_wait_of_same_past_second 
	- 0.0585 * parameters.avg_latency_of_same_last_20 
	+ 0.033 * parameters.max_latency_of_same_last_50 
	+ 235688280.5449;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM91(work_wait &parameters) {
  double actual_remaining = 
	0.001 * parameters.work_so_far 
	+ 0.0122 * parameters.wait_so_far 
	+ 987805.1141 * parameters.total_wait_locks 
	- 0.5771 * parameters.mean_wait_of_all 
	+ 15399842.2408 * parameters.cpu_usage 
	- 0.0316 * parameters.avg_work_of_same_past_second 
	- 0.0457 * parameters.avg_wait_of_same_past_second 
	+ 0.0036 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 81013757.2768;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM92(work_wait &parameters) {
  double actual_remaining = 
	-0.033 * parameters.work_so_far 
	+ 0.0088 * parameters.wait_so_far 
	+ 97259.8521 * parameters.total_wait_locks 
	- 0.3411 * parameters.mean_wait_of_all 
	+ 79836332.0277 * parameters.cpu_usage 
	- 0.0316 * parameters.avg_work_of_same_past_second 
	- 0.0356 * parameters.avg_wait_of_same_past_second 
	+ 0.0156 * parameters.avg_latency_of_same_last_20 
	- 0.0122 * parameters.max_latency_of_same_last_50 
	+ 45643059.1393;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM93(work_wait &parameters) {
  double actual_remaining = 
	-0.0188 * parameters.work_so_far 
	+ 0.0032 * parameters.wait_so_far 
	+ 18751.747 * parameters.total_wait_locks 
	- 0.6556 * parameters.mean_wait_of_all 
	+ 79836332.0277 * parameters.cpu_usage 
	- 0.0316 * parameters.avg_work_of_same_past_second 
	+ 0.0212 * parameters.avg_wait_of_same_past_second 
	+ 0.0686 * parameters.avg_latency_of_same_last_20 
	- 0.0175 * parameters.max_latency_of_same_last_50 
	+ 16028725.6408;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM94(work_wait &parameters) {
  double actual_remaining = 
	-0.0188 * parameters.work_so_far 
	+ 0.0152 * parameters.wait_so_far 
	+ 548964.2406 * parameters.total_wait_locks 
	+ 8.2677 * parameters.mean_wait_of_all 
	+ 79836332.0277 * parameters.cpu_usage 
	- 0.0316 * parameters.avg_work_of_same_past_second 
	+ 0.048 * parameters.avg_wait_of_same_past_second 
	+ 0.0491 * parameters.avg_latency_of_same_last_20 
	- 0.0225 * parameters.max_latency_of_same_last_50 
	- 1130403531.2581;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM95(work_wait &parameters) {
  double actual_remaining = 
	-0.0188 * parameters.work_so_far 
	+ 0.0124 * parameters.wait_so_far 
	+ 548964.2406 * parameters.total_wait_locks 
	+ 6.1615 * parameters.mean_wait_of_all 
	+ 79836332.0277 * parameters.cpu_usage 
	- 0.0316 * parameters.avg_work_of_same_past_second 
	+ 0.048 * parameters.avg_wait_of_same_past_second 
	+ 0.0491 * parameters.avg_latency_of_same_last_20 
	- 0.0225 * parameters.max_latency_of_same_last_50 
	- 902129485.344;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM96(work_wait &parameters) {
  double actual_remaining = 
	-0.0188 * parameters.work_so_far 
	+ 0.0088 * parameters.wait_so_far 
	+ 761620.4473 * parameters.total_wait_locks 
	- 19.0205 * parameters.mean_wait_of_all 
	+ 79836332.0277 * parameters.cpu_usage 
	- 0.0316 * parameters.avg_work_of_same_past_second 
	+ 0.048 * parameters.avg_wait_of_same_past_second 
	+ 0.0491 * parameters.avg_latency_of_same_last_20 
	- 0.0225 * parameters.max_latency_of_same_last_50 
	+ 1705682889.1211;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM97(work_wait &parameters) {
  double actual_remaining = 
	3.2399 * parameters.work_so_far 
	+ 0.0134 * parameters.wait_so_far 
	+ 390108.5003 * parameters.total_wait_locks 
	- 0.6346 * parameters.mean_wait_of_all 
	+ 161455885.7577 * parameters.cpu_usage 
	- 0.6385 * parameters.avg_work_of_same_past_second 
	- 0.0696 * parameters.avg_wait_of_same_past_second 
	+ 0.1104 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 121222247.2936;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM98(work_wait &parameters) {
  double actual_remaining = 
	1.7362 * parameters.work_so_far 
	+ 0.0134 * parameters.wait_so_far 
	+ 390108.5003 * parameters.total_wait_locks 
	- 0.6346 * parameters.mean_wait_of_all 
	+ 161455885.7577 * parameters.cpu_usage 
	- 0.6385 * parameters.avg_work_of_same_past_second 
	- 0.0696 * parameters.avg_wait_of_same_past_second 
	+ 0.1203 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 125193903.9397;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM99(work_wait &parameters) {
  double actual_remaining = 
	0.001 * parameters.work_so_far 
	+ 0.0134 * parameters.wait_so_far 
	+ 427942.9059 * parameters.total_wait_locks 
	- 0.6346 * parameters.mean_wait_of_all 
	+ 161455885.7577 * parameters.cpu_usage 
	- 0.6385 * parameters.avg_work_of_same_past_second 
	- 0.0696 * parameters.avg_wait_of_same_past_second 
	+ 0.1178 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 121268925.1671;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM100(work_wait &parameters) {
  double actual_remaining = 
	0.001 * parameters.work_so_far 
	+ 0.0134 * parameters.wait_so_far 
	+ 440286.1668 * parameters.total_wait_locks 
	- 1.1142 * parameters.mean_wait_of_all 
	+ 161455885.7577 * parameters.cpu_usage 
	- 1.008 * parameters.avg_work_of_same_past_second 
	- 0.0696 * parameters.avg_wait_of_same_past_second 
	+ 0.1262 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 79032019.3775;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM101(work_wait &parameters) {
  double actual_remaining = 
	0.001 * parameters.work_so_far 
	- 0.0058 * parameters.wait_so_far 
	- 1527.3446 * parameters.total_wait_locks 
	+ 0.0034 * parameters.mean_wait_of_all 
	+ 610117.4668 * parameters.cpu_usage 
	- 0.1652 * parameters.avg_work_of_same_past_second 
	- 0.0565 * parameters.avg_wait_of_same_past_second 
	+ 0.0142 * parameters.avg_latency_of_same_last_20 
	+ 0.0082 * parameters.max_latency_of_same_last_50 
	+ 68016196.0516;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM102(work_wait &parameters) {
  double actual_remaining = 
	0.2076 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	- 134777.568 * parameters.total_wait_locks 
	+ 0.0334 * parameters.mean_wait_of_all 
	- 998432.9896 * parameters.cpu_usage 
	- 0.1423 * parameters.avg_work_of_same_past_second 
	+ 0.0007 * parameters.avg_wait_of_same_past_second 
	+ 0.0626 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 91340012.6584;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM103(work_wait &parameters) {
  double actual_remaining = 
	2.2614 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	- 762901.5288 * parameters.total_wait_locks 
	+ 6.8961 * parameters.mean_wait_of_all 
	- 1504603.1341 * parameters.cpu_usage 
	+ 0.7054 * parameters.avg_work_of_same_past_second 
	+ 0.001 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	- 409112098.6556;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM104(work_wait &parameters) {
  double actual_remaining = 
	0.8347 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 933142.3139 * parameters.total_wait_locks 
	- 8.4215 * parameters.mean_wait_of_all 
	- 1504603.1341 * parameters.cpu_usage 
	- 0.0023 * parameters.avg_work_of_same_past_second 
	+ 0.001 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 703942821.0507;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM105(work_wait &parameters) {
  double actual_remaining = 
	0.028 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	- 78795.6765 * parameters.total_wait_locks 
	- 0.8144 * parameters.mean_wait_of_all 
	- 287892687.4968 * parameters.cpu_usage 
	- 0.6498 * parameters.avg_work_of_same_past_second 
	- 0.7791 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	- 0.0103 * parameters.max_latency_of_same_last_50 
	+ 822308071.9127;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM106(work_wait &parameters) {
  double actual_remaining = 
	0.028 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 623388.7539 * parameters.total_wait_locks 
	- 0.4531 * parameters.mean_wait_of_all 
	- 664935920.2322 * parameters.cpu_usage 
	- 0.4577 * parameters.avg_work_of_same_past_second 
	+ 2.6611 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	- 0.0052 * parameters.max_latency_of_same_last_50 
	- 361857004.4569;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM107(work_wait &parameters) {
  double actual_remaining = 
	0.028 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	- 78795.6765 * parameters.total_wait_locks 
	- 0.3728 * parameters.mean_wait_of_all 
	- 200228265.2353 * parameters.cpu_usage 
	+ 0.9161 * parameters.avg_work_of_same_past_second 
	- 0.5197 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	- 0.0264 * parameters.max_latency_of_same_last_50 
	+ 427948115.0492;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM108(work_wait &parameters) {
  double actual_remaining = 
	0.028 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	- 579809.7464 * parameters.total_wait_locks 
	+ 2.2481 * parameters.mean_wait_of_all 
	+ 235071820.0291 * parameters.cpu_usage 
	- 0.0023 * parameters.avg_work_of_same_past_second 
	+ 0.2442 * parameters.avg_wait_of_same_past_second 
	+ 0.1585 * parameters.avg_latency_of_same_last_20 
	+ 0.0194 * parameters.max_latency_of_same_last_50 
	- 319381332.3142;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM109(work_wait &parameters) {
  double actual_remaining = 
	0.0149 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	- 29329.0164 * parameters.total_wait_locks 
	+ 2.0804 * parameters.mean_wait_of_all 
	- 1504603.1341 * parameters.cpu_usage 
	- 0.5962 * parameters.avg_work_of_same_past_second 
	+ 0.1 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	- 0.0104 * parameters.max_latency_of_same_last_50 
	- 198401863.5089;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM110(work_wait &parameters) {
  double actual_remaining = 
	2.3659 * parameters.work_so_far 
	+ 0.0494 * parameters.wait_so_far 
	- 849629.765 * parameters.total_wait_locks 
	+ 1.88 * parameters.mean_wait_of_all 
	+ 236002.3628 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0431 * parameters.avg_wait_of_same_past_second 
	+ 5.0225 * parameters.avg_latency_of_same_last_20 
	+ 0.034 * parameters.max_latency_of_same_last_50 
	- 1514072251.9499;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM111(work_wait &parameters) {
  double actual_remaining = 
	1.6365 * parameters.work_so_far 
	+ 0.0332 * parameters.wait_so_far 
	- 830268.0853 * parameters.total_wait_locks 
	+ 1.88 * parameters.mean_wait_of_all 
	+ 236002.3628 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0431 * parameters.avg_wait_of_same_past_second 
	+ 2.9642 * parameters.avg_latency_of_same_last_20 
	+ 0.034 * parameters.max_latency_of_same_last_50 
	- 873030482.9708;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM112(work_wait &parameters) {
  double actual_remaining = 
	1.6365 * parameters.work_so_far 
	+ 0.0379 * parameters.wait_so_far 
	- 733360.2948 * parameters.total_wait_locks 
	+ 1.88 * parameters.mean_wait_of_all 
	+ 236002.3628 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0431 * parameters.avg_wait_of_same_past_second 
	+ 2.9642 * parameters.avg_latency_of_same_last_20 
	+ 0.034 * parameters.max_latency_of_same_last_50 
	- 900473751.0715;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM113(work_wait &parameters) {
  double actual_remaining = 
	1.6365 * parameters.work_so_far 
	+ 0.0372 * parameters.wait_so_far 
	- 730963.2048 * parameters.total_wait_locks 
	+ 1.88 * parameters.mean_wait_of_all 
	+ 236002.3628 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0431 * parameters.avg_wait_of_same_past_second 
	+ 2.9642 * parameters.avg_latency_of_same_last_20 
	+ 0.034 * parameters.max_latency_of_same_last_50 
	- 900492564.3198;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM114(work_wait &parameters) {
  double actual_remaining = 
	1.5309 * parameters.work_so_far 
	+ 0.0332 * parameters.wait_so_far 
	- 759843.1484 * parameters.total_wait_locks 
	+ 1.88 * parameters.mean_wait_of_all 
	+ 236002.3628 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0431 * parameters.avg_wait_of_same_past_second 
	+ 2.9642 * parameters.avg_latency_of_same_last_20 
	+ 0.034 * parameters.max_latency_of_same_last_50 
	- 892708436.1437;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM115(work_wait &parameters) {
  double actual_remaining = 
	1.6365 * parameters.work_so_far 
	+ 0.0281 * parameters.wait_so_far 
	- 830268.0853 * parameters.total_wait_locks 
	+ 1.88 * parameters.mean_wait_of_all 
	+ 236002.3628 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0431 * parameters.avg_wait_of_same_past_second 
	+ 2.9642 * parameters.avg_latency_of_same_last_20 
	+ 0.034 * parameters.max_latency_of_same_last_50 
	- 860116070.7434;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM116(work_wait &parameters) {
  double actual_remaining = 
	0.2439 * parameters.work_so_far 
	+ 0.0069 * parameters.wait_so_far 
	- 405230.5274 * parameters.total_wait_locks 
	+ 0.3296 * parameters.mean_wait_of_all 
	+ 236002.3628 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0431 * parameters.avg_wait_of_same_past_second 
	- 0.1706 * parameters.avg_latency_of_same_last_20 
	+ 0.0144 * parameters.max_latency_of_same_last_50 
	+ 223902894.1497;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM117(work_wait &parameters) {
  double actual_remaining = 
	0.087 * parameters.work_so_far 
	- 0.0293 * parameters.wait_so_far 
	- 2477084.2642 * parameters.total_wait_locks 
	- 1.9906 * parameters.mean_wait_of_all 
	+ 236002.3628 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0431 * parameters.avg_wait_of_same_past_second 
	- 0.0116 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 1227836501.345;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM118(work_wait &parameters) {
  double actual_remaining = 
	0.087 * parameters.work_so_far 
	- 0.0248 * parameters.wait_so_far 
	- 2032750.5418 * parameters.total_wait_locks 
	- 4.0627 * parameters.mean_wait_of_all 
	+ 236002.3628 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0431 * parameters.avg_wait_of_same_past_second 
	- 0.0116 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 1212795612.0328;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM119(work_wait &parameters) {
  double actual_remaining = 
	-4.3646 * parameters.work_so_far 
	+ 0.0069 * parameters.wait_so_far 
	- 2030430.599 * parameters.total_wait_locks 
	+ 17.7199 * parameters.mean_wait_of_all 
	+ 236002.3628 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0431 * parameters.avg_wait_of_same_past_second 
	- 0.0116 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	- 578302228.8582;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM120(work_wait &parameters) {
  double actual_remaining = 
	0.3279 * parameters.work_so_far 
	+ 0.0073 * parameters.wait_so_far 
	- 103584.5538 * parameters.total_wait_locks 
	+ 0.2501 * parameters.mean_wait_of_all 
	+ 236002.3628 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0452 * parameters.avg_wait_of_same_past_second 
	- 0.0116 * parameters.avg_latency_of_same_last_20 
	+ 0.0892 * parameters.max_latency_of_same_last_50 
	+ 23913252.7871;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM121(work_wait &parameters) {
  double actual_remaining = 
	0.3279 * parameters.work_so_far 
	+ 0.0073 * parameters.wait_so_far 
	- 103584.5538 * parameters.total_wait_locks 
	+ 0.2279 * parameters.mean_wait_of_all 
	+ 236002.3628 * parameters.cpu_usage 
	- 0.4059 * parameters.avg_work_of_same_past_second 
	- 0.0452 * parameters.avg_wait_of_same_past_second 
	- 0.0116 * parameters.avg_latency_of_same_last_20 
	+ 0.0892 * parameters.max_latency_of_same_last_50 
	+ 65716315.2167;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM122(work_wait &parameters) {
  double actual_remaining = 
	0.2451 * parameters.work_so_far 
	+ 0.0073 * parameters.wait_so_far 
	- 103584.5538 * parameters.total_wait_locks 
	+ 0.5392 * parameters.mean_wait_of_all 
	+ 236002.3628 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.186 * parameters.avg_wait_of_same_past_second 
	+ 1.0318 * parameters.avg_latency_of_same_last_20 
	+ 0.1256 * parameters.max_latency_of_same_last_50 
	- 314810178.2128;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM123(work_wait &parameters) {
  double actual_remaining = 
	4909.6619 * parameters.work_so_far 
	+ 0.0073 * parameters.wait_so_far 
	- 50177.4192 * parameters.total_wait_locks 
	+ 0.5392 * parameters.mean_wait_of_all 
	+ 236002.3628 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.12 * parameters.avg_wait_of_same_past_second 
	+ 0.1844 * parameters.avg_latency_of_same_last_20 
	+ 0.0832 * parameters.max_latency_of_same_last_50 
	- 166329166.5875;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM124(work_wait &parameters) {
  double actual_remaining = 
	6976.7849 * parameters.work_so_far 
	+ 0.0073 * parameters.wait_so_far 
	- 103584.5538 * parameters.total_wait_locks 
	+ 0.5392 * parameters.mean_wait_of_all 
	+ 236002.3628 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.12 * parameters.avg_wait_of_same_past_second 
	+ 0.1844 * parameters.avg_latency_of_same_last_20 
	+ 0.0832 * parameters.max_latency_of_same_last_50 
	- 175566460.8037;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM125(work_wait &parameters) {
  double actual_remaining = 
	0.2451 * parameters.work_so_far 
	+ 0.0073 * parameters.wait_so_far 
	- 103584.5538 * parameters.total_wait_locks 
	+ 0.5392 * parameters.mean_wait_of_all 
	+ 236002.3628 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.12 * parameters.avg_wait_of_same_past_second 
	+ 0.1844 * parameters.avg_latency_of_same_last_20 
	+ 0.2313 * parameters.max_latency_of_same_last_50 
	- 147300617.6546;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM126(work_wait &parameters) {
  double actual_remaining = 
	-0.5523 * parameters.work_so_far 
	+ 0.0073 * parameters.wait_so_far 
	- 112367.8692 * parameters.total_wait_locks 
	+ 0.5867 * parameters.mean_wait_of_all 
	- 197758293.7303 * parameters.cpu_usage 
	+ 0.1815 * parameters.avg_work_of_same_past_second 
	- 0.0932 * parameters.avg_wait_of_same_past_second 
	- 0.0116 * parameters.avg_latency_of_same_last_20 
	+ 0.0927 * parameters.max_latency_of_same_last_50 
	+ 160048170.8997;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM127(work_wait &parameters) {
  double actual_remaining = 
	-0.0096 * parameters.work_so_far 
	+ 0.0073 * parameters.wait_so_far 
	- 112367.8692 * parameters.total_wait_locks 
	+ 0.5867 * parameters.mean_wait_of_all 
	- 58773136.9467 * parameters.cpu_usage 
	+ 0.1752 * parameters.avg_work_of_same_past_second 
	- 1.8927 * parameters.avg_wait_of_same_past_second 
	- 0.0116 * parameters.avg_latency_of_same_last_20 
	- 0.3203 * parameters.max_latency_of_same_last_50 
	+ 1010148256.1798;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM128(work_wait &parameters) {
  double actual_remaining = 
	-0.0096 * parameters.work_so_far 
	+ 0.0073 * parameters.wait_so_far 
	- 112367.8692 * parameters.total_wait_locks 
	+ 0.5867 * parameters.mean_wait_of_all 
	- 58773136.9467 * parameters.cpu_usage 
	+ 0.1752 * parameters.avg_work_of_same_past_second 
	- 0.1804 * parameters.avg_wait_of_same_past_second 
	- 0.0116 * parameters.avg_latency_of_same_last_20 
	- 0.1157 * parameters.max_latency_of_same_last_50 
	+ 276426511.1342;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM129(work_wait &parameters) {
  double actual_remaining = 
	0.0261 * parameters.work_so_far 
	+ 0.0015 * parameters.wait_so_far 
	- 361806.6295 * parameters.total_wait_locks 
	+ 1.7035 * parameters.mean_wait_of_all 
	- 467669828.3809 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0142 * parameters.avg_wait_of_same_past_second 
	- 0.0137 * parameters.avg_latency_of_same_last_20 
	+ 0.0644 * parameters.max_latency_of_same_last_50 
	+ 443566395.9931;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM130(work_wait &parameters) {
  double actual_remaining = 
	0.1955 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	- 231039.6976 * parameters.total_wait_locks 
	+ 1.007 * parameters.mean_wait_of_all 
	+ 236002.3628 * parameters.cpu_usage 
	+ 0.1045 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0283 * parameters.avg_latency_of_same_last_20 
	- 0.0145 * parameters.max_latency_of_same_last_50 
	+ 57408832.6371;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
payment_estimate(work_wait &parameters){

  if (parameters.total_wait_locks <= 124.5) {

    if (parameters.total_wait_locks <= 37.5) {
      return payment_LM1(parameters);
    } else {

      if (parameters.work_so_far <= 19588.5) {

        if (parameters.cpu_usage <= 0.907) {

          if (parameters.wait_so_far <= 71699686.5) {
            return payment_LM2(parameters);
          } else {

            if (parameters.avg_wait_of_same_past_second <= 12280000) {

              if (parameters.avg_work_of_same_past_second <= 5674495) {

                if (parameters.avg_wait_of_same_past_second <= 7942975) {
                  return payment_LM3(parameters);
                } else {
                  return payment_LM4(parameters);
                }
              } else {
                return payment_LM5(parameters);
              }
            } else {

              if (parameters.work_so_far <= 14214) {
                return payment_LM6(parameters);
              } else {
                return payment_LM7(parameters);
              }
            }
          }
        } else {

          if (parameters.max_latency_of_same_last_50 <= 228380500) {

            if (parameters.wait_so_far <= 79723751) {

              if (parameters.work_so_far <= 6813.5) {
                return payment_LM8(parameters);
              } else {

                if (parameters.wait_so_far <= 9622233) {
                  return payment_LM9(parameters);
                } else {

                  if (parameters.avg_latency_of_same_last_20 <= 21045800) {

                    if (parameters.avg_wait_of_same_past_second <= 101643100) {
                      return payment_LM10(parameters);
                    } else {
                      return payment_LM11(parameters);
                    }
                  } else {
                    return payment_LM12(parameters);
                  }
                }
              }
            } else {

              if (parameters.cpu_usage <= 0.94) {

                if (parameters.avg_latency_of_same_last_20 <= 31874550) {
                  return payment_LM13(parameters);
                } else {

                  if (parameters.total_wait_locks <= 45.5) {
                    return payment_LM14(parameters);
                  } else {
                    return payment_LM15(parameters);
                  }
                }
              } else {
                return payment_LM16(parameters);
              }
            }
          } else {

            if (parameters.avg_latency_of_same_last_20 <= 75007250) {

              if (parameters.total_wait_locks <= 62.5) {
                return payment_LM17(parameters);
              } else {

                if (parameters.cpu_usage <= 0.928) {
                  return payment_LM18(parameters);
                } else {

                  if (parameters.total_wait_locks <= 103.5) {

                    if (parameters.mean_wait_of_all <= 38209150) {

                      if (parameters.avg_latency_of_same_last_20 <= 63508450) {

                        if (parameters.mean_wait_of_all <= 34651500) {

                          if (parameters.work_so_far <= 11651.5) {
                            return payment_LM19(parameters);
                          } else {
                            return payment_LM20(parameters);
                          }
                        } else {
                          return payment_LM21(parameters);
                        }
                      } else {

                        if (parameters.total_wait_locks <= 69.5) {
                          return payment_LM22(parameters);
                        } else {
                          return payment_LM23(parameters);
                        }
                      }
                    } else {

                      if (parameters.total_wait_locks <= 96.5) {
                        return payment_LM24(parameters);
                      } else {

                        if (parameters.total_wait_locks <= 101) {

                          if (parameters.total_wait_locks <= 98.5) {
                            return payment_LM25(parameters);
                          } else {
                            return payment_LM26(parameters);
                          }
                        } else {
                          return payment_LM27(parameters);
                        }
                      }
                    }
                  } else {
                    return payment_LM28(parameters);
                  }
                }
              }
            } else {

              if (parameters.avg_latency_of_same_last_20 <= 103345500) {

                if (parameters.work_so_far <= 9589) {
                  return payment_LM29(parameters);
                } else {

                  if (parameters.mean_wait_of_all <= 30660050) {

                    if (parameters.avg_work_of_same_past_second <= 23627650) {
                      return payment_LM30(parameters);
                    } else {
                      return payment_LM31(parameters);
                    }
                  } else {
                    return payment_LM32(parameters);
                  }
                }
              } else {

                if (parameters.mean_wait_of_all <= 29329500) {

                  if (parameters.mean_wait_of_all <= 29055250) {

                    if (parameters.max_latency_of_same_last_50 <= 830425500) {

                      if (parameters.max_latency_of_same_last_50 <= 497740000) {
                        return payment_LM33(parameters);
                      } else {
                        return payment_LM34(parameters);
                      }
                    } else {
                      return payment_LM35(parameters);
                    }
                  } else {
                    return payment_LM36(parameters);
                  }
                } else {
                  return payment_LM37(parameters);
                }
              }
            }
          }
        }
      } else {

        if (parameters.max_latency_of_same_last_50 <= 696979500) {

          if (parameters.avg_work_of_same_past_second <= 12412900) {

            if (parameters.avg_wait_of_same_past_second <= 10683600) {

              if (parameters.cpu_usage <= 0.88) {
                return payment_LM38(parameters);
              } else {
                return payment_LM39(parameters);
              }
            } else {
              return payment_LM40(parameters);
            }
          } else {
            return payment_LM41(parameters);
          }
        } else {

          if (parameters.max_latency_of_same_last_50 <= 916041000) {
            return payment_LM42(parameters);
          } else {

            if (parameters.avg_latency_of_same_last_20 <= 289793000) {
              return payment_LM43(parameters);
            } else {
              return payment_LM44(parameters);
            }
          }
        }
      }
    }
  } else {

    if (parameters.mean_wait_of_all <= 55686950) {

      if (parameters.max_latency_of_same_last_50 <= 706642500) {

        if (parameters.mean_wait_of_all <= 51284450) {

          if (parameters.total_wait_locks <= 172) {
            return payment_LM45(parameters);
          } else {

            if (parameters.max_latency_of_same_last_50 <= 593723000) {

              if (parameters.avg_wait_of_same_past_second <= 92095850) {

                if (parameters.avg_latency_of_same_last_20 <= 311454000) {

                  if (parameters.mean_wait_of_all <= 51187300) {
                    return payment_LM46(parameters);
                  } else {
                    return payment_LM47(parameters);
                  }
                } else {
                  return payment_LM48(parameters);
                }
              } else {

                if (parameters.mean_wait_of_all <= 42831950) {
                  return payment_LM49(parameters);
                } else {
                  return payment_LM50(parameters);
                }
              }
            } else {
              return payment_LM51(parameters);
            }
          }
        } else {
          return payment_LM52(parameters);
        }
      } else {

        if (parameters.mean_wait_of_all <= 37934050) {

          if (parameters.mean_wait_of_all <= 35665550) {

            if (parameters.mean_wait_of_all <= 29143250) {
              return payment_LM53(parameters);
            } else {
              return payment_LM54(parameters);
            }
          } else {

            if (parameters.cpu_usage <= 0.941) {

              if (parameters.total_wait_locks <= 195.5) {

                if (parameters.work_so_far <= 43002) {

                  if (parameters.avg_work_of_same_past_second <= 69259400) {

                    if (parameters.avg_work_of_same_past_second <= 57632400) {
                      return payment_LM55(parameters);
                    } else {
                      return payment_LM56(parameters);
                    }
                  } else {
                    return payment_LM57(parameters);
                  }
                } else {
                  return payment_LM58(parameters);
                }
              } else {
                return payment_LM59(parameters);
              }
            } else {

              if (parameters.wait_so_far <= 429166207) {

                if (parameters.mean_wait_of_all <= 37921100) {
                  return payment_LM60(parameters);
                } else {
                  return payment_LM61(parameters);
                }
              } else {
                return payment_LM62(parameters);
              }
            }
          }
        } else {

          if (parameters.mean_wait_of_all <= 49135800) {

            if (parameters.mean_wait_of_all <= 43973000) {

              if (parameters.mean_wait_of_all <= 42364900) {
                return payment_LM63(parameters);
              } else {

                if (parameters.avg_work_of_same_past_second <= 60363350) {
                  return payment_LM64(parameters);
                } else {

                  if (parameters.mean_wait_of_all <= 43511700) {

                    if (parameters.mean_wait_of_all <= 42830000) {
                      return payment_LM65(parameters);
                    } else {

                      if (parameters.total_wait_locks <= 207.5) {
                        return payment_LM66(parameters);
                      } else {
                        return payment_LM67(parameters);
                      }
                    }
                  } else {

                    if (parameters.wait_so_far <= 88636992) {

                      if (parameters.work_so_far <= 36389) {
                        return payment_LM68(parameters);
                      } else {
                        return payment_LM69(parameters);
                      }
                    } else {

                      if (parameters.work_so_far <= 31226.5) {

                        if (parameters.max_latency_of_same_last_50 <= 1010170000) {
                          return payment_LM70(parameters);
                        } else {
                          return payment_LM71(parameters);
                        }
                      } else {

                        if (parameters.avg_latency_of_same_last_20 <= 437606000) {

                          if (parameters.work_so_far <= 98607) {
                            return payment_LM72(parameters);
                          } else {
                            return payment_LM73(parameters);
                          }
                        } else {
                          return payment_LM74(parameters);
                        }
                      }
                    }
                  }
                }
              }
            } else {
              return payment_LM75(parameters);
            }
          } else {

            if (parameters.mean_wait_of_all <= 54226750) {

              if (parameters.max_latency_of_same_last_50 <= 904490500) {

                if (parameters.mean_wait_of_all <= 51267800) {
                  return payment_LM76(parameters);
                } else {
                  return payment_LM77(parameters);
                }
              } else {

                if (parameters.mean_wait_of_all <= 50493500) {
                  return payment_LM78(parameters);
                } else {

                  if (parameters.mean_wait_of_all <= 51798600) {
                    return payment_LM79(parameters);
                  } else {

                    if (parameters.max_latency_of_same_last_50 <= 1022790000) {

                      if (parameters.avg_wait_of_same_past_second <= 299544500) {
                        return payment_LM80(parameters);
                      } else {
                        return payment_LM81(parameters);
                      }
                    } else {
                      return payment_LM82(parameters);
                    }
                  }
                }
              }
            } else {

              if (parameters.wait_so_far <= 57775167) {
                return payment_LM83(parameters);
              } else {
                return payment_LM84(parameters);
              }
            }
          }
        }
      }
    } else {

      if (parameters.cpu_usage <= 0.918) {

        if (parameters.mean_wait_of_all <= 111824500) {

          if (parameters.avg_work_of_same_past_second <= 63576950) {

            if (parameters.mean_wait_of_all <= 88109150) {
              return payment_LM85(parameters);
            } else {

              if (parameters.cpu_usage <= 0.856) {
                return payment_LM86(parameters);
              } else {
                return payment_LM87(parameters);
              }
            }
          } else {

            if (parameters.avg_latency_of_same_last_20 <= 564530500) {
              return payment_LM88(parameters);
            } else {

              if (parameters.avg_wait_of_same_past_second <= 409483500) {

                if (parameters.cpu_usage <= 0.785) {
                  return payment_LM89(parameters);
                } else {
                  return payment_LM90(parameters);
                }
              } else {

                if (parameters.mean_wait_of_all <= 73657600) {
                  return payment_LM91(parameters);
                } else {

                  if (parameters.max_latency_of_same_last_50 <= 2075280000) {

                    if (parameters.avg_latency_of_same_last_20 <= 640045000) {
                      return payment_LM92(parameters);
                    } else {

                      if (parameters.avg_wait_of_same_past_second <= 525130500) {
                        return payment_LM93(parameters);
                      } else {

                        if (parameters.total_wait_locks <= 409.5) {

                          if (parameters.work_so_far <= 41717.5) {
                            return payment_LM94(parameters);
                          } else {
                            return payment_LM95(parameters);
                          }
                        } else {
                          return payment_LM96(parameters);
                        }
                      }
                    }
                  } else {

                    if (parameters.max_latency_of_same_last_50 <= 2521695000) {

                      if (parameters.total_wait_locks <= 394.5) {

                        if (parameters.avg_work_of_same_past_second <= 88654600) {
                          return payment_LM97(parameters);
                        } else {
                          return payment_LM98(parameters);
                        }
                      } else {
                        return payment_LM99(parameters);
                      }
                    } else {
                      return payment_LM100(parameters);
                    }
                  }
                }
              }
            }
          }
        } else {
          return payment_LM101(parameters);
        }
      } else {

        if (parameters.avg_latency_of_same_last_20 <= 348725000) {

          if (parameters.mean_wait_of_all <= 98338450) {
            return payment_LM102(parameters);
          } else {

            if (parameters.total_wait_locks <= 509.5) {

              if (parameters.avg_latency_of_same_last_20 <= 244365000) {

                if (parameters.avg_latency_of_same_last_20 <= 242645500) {
                  return payment_LM103(parameters);
                } else {
                  return payment_LM104(parameters);
                }
              } else {

                if (parameters.avg_wait_of_same_past_second <= 341037500) {

                  if (parameters.avg_work_of_same_past_second <= 83277150) {

                    if (parameters.avg_wait_of_same_past_second <= 314528000) {
                      return payment_LM105(parameters);
                    } else {
                      return payment_LM106(parameters);
                    }
                  } else {
                    return payment_LM107(parameters);
                  }
                } else {
                  return payment_LM108(parameters);
                }
              }
            } else {
              return payment_LM109(parameters);
            }
          }
        } else {

          if (parameters.max_latency_of_same_last_50 <= 1013655000) {

            if (parameters.avg_latency_of_same_last_20 <= 404008500) {

              if (parameters.mean_wait_of_all <= 91646800) {

                if (parameters.mean_wait_of_all <= 86822150) {

                  if (parameters.avg_latency_of_same_last_20 <= 356332500) {

                    if (parameters.total_wait_locks <= 244) {
                      return payment_LM110(parameters);
                    } else {

                      if (parameters.avg_latency_of_same_last_20 <= 356065500) {

                        if (parameters.work_so_far <= 30636.5) {
                          return payment_LM111(parameters);
                        } else {

                          if (parameters.avg_work_of_same_past_second <= 67082400) {

                            if (parameters.wait_so_far <= 49701868) {
                              return payment_LM112(parameters);
                            } else {
                              return payment_LM113(parameters);
                            }
                          } else {
                            return payment_LM114(parameters);
                          }
                        }
                      } else {
                        return payment_LM115(parameters);
                      }
                    }
                  } else {
                    return payment_LM116(parameters);
                  }
                } else {

                  if (parameters.mean_wait_of_all <= 90825550) {

                    if (parameters.mean_wait_of_all <= 88188650) {
                      return payment_LM117(parameters);
                    } else {
                      return payment_LM118(parameters);
                    }
                  } else {
                    return payment_LM119(parameters);
                  }
                }
              } else {

                if (parameters.max_latency_of_same_last_50 <= 926318000) {

                  if (parameters.avg_wait_of_same_past_second <= 339058500) {

                    if (parameters.avg_work_of_same_past_second <= 56088100) {
                      return payment_LM120(parameters);
                    } else {
                      return payment_LM121(parameters);
                    }
                  } else {

                    if (parameters.avg_wait_of_same_past_second <= 344914500) {
                      return payment_LM122(parameters);
                    } else {

                      if (parameters.work_so_far <= 29748) {

                        if (parameters.work_so_far <= 27869) {
                          return payment_LM123(parameters);
                        } else {
                          return payment_LM124(parameters);
                        }
                      } else {
                        return payment_LM125(parameters);
                      }
                    }
                  }
                } else {

                  if (parameters.max_latency_of_same_last_50 <= 968303000) {
                    return payment_LM126(parameters);
                  } else {

                    if (parameters.avg_wait_of_same_past_second <= 314305500) {
                      return payment_LM127(parameters);
                    } else {
                      return payment_LM128(parameters);
                    }
                  }
                }
              }
            } else {
              return payment_LM129(parameters);
            }
          } else {
            return payment_LM130(parameters);
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
	+ 373210364.5;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
delivery_estimate(work_wait &parameters){
  return delivery_LM1(parameters);
}
static
double
stock_level_LM1(work_wait &parameters) {
  double actual_remaining = 
	8169.7816 * parameters.total_wait_locks 
	- 1269095.7353;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
stock_level_LM2(work_wait &parameters) {
  double actual_remaining = 
	8765.1607 * parameters.total_wait_locks 
	- 957426.2019;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
stock_level_estimate(work_wait &parameters){

  if (parameters.total_wait_locks <= 531) {
    return stock_level_LM1(parameters);
  } else {
    return stock_level_LM2(parameters);
  }
}
static
double
tpcc_LM1(work_wait &parameters) {
  double actual_remaining = 
	0.2889 * parameters.work_so_far 
	- 0.0662 * parameters.wait_so_far 
	+ 295582.4525 * parameters.total_wait_locks 
	- 0.6254 * parameters.mean_wait_of_all 
	+ 99810360.9551 * parameters.cpu_usage 
	+ 0.9182 * parameters.avg_work_of_same_past_second 
	- 0.2762 * parameters.avg_wait_of_same_past_second 
	+ 0.1014 * parameters.avg_latency_of_same_last_20 
	- 0.0108 * parameters.max_latency_of_same_last_50 
	- 54657454.6761;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
tpcc_estimate(work_wait &parameters){
  return tpcc_LM1(parameters);
}