#include "my_global.h"
#include "m5p.h"
#include "trace_tool.h"

static
double
new_order_LM1(work_wait &parameters) {
  double actual_remaining = 
	3834.3559 * parameters.work_so_far 
	+ 9394.9285 * parameters.wait_so_far 
	- 95026.8963 * parameters.num_locks_so_far 
	+ 45859.5285 * parameters.total_wait_locks 
	- 0.005 * parameters.mean_wait_of_all 
	- 116177728.5964 * parameters.cpu_usage 
	+ 0.0105 * parameters.avg_work_of_same_past_second 
	- 0.0317 * parameters.avg_wait_of_same_past_second 
	+ 0.6144 * parameters.avg_latency_of_same_last_20 
	- 0.0269 * parameters.max_latency_of_same_last_50 
	+ 39772727.0128;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM2(work_wait &parameters) {
  double actual_remaining = 
	1229.9552 * parameters.work_so_far 
	+ 14009.6744 * parameters.wait_so_far 
	- 95026.8963 * parameters.num_locks_so_far 
	+ 168091.7274 * parameters.total_wait_locks 
	- 0.005 * parameters.mean_wait_of_all 
	- 15875977.226 * parameters.cpu_usage 
	+ 0.0105 * parameters.avg_work_of_same_past_second 
	- 0.1889 * parameters.avg_wait_of_same_past_second 
	+ 0.4213 * parameters.avg_latency_of_same_last_20 
	+ 0.0072 * parameters.max_latency_of_same_last_50 
	+ 37705643.9438;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM3(work_wait &parameters) {
  double actual_remaining = 
	1822.9047 * parameters.work_so_far 
	+ 14009.6744 * parameters.wait_so_far 
	- 95026.8963 * parameters.num_locks_so_far 
	+ 168091.7274 * parameters.total_wait_locks 
	- 0.005 * parameters.mean_wait_of_all 
	- 15875977.226 * parameters.cpu_usage 
	+ 0.0105 * parameters.avg_work_of_same_past_second 
	- 0.1889 * parameters.avg_wait_of_same_past_second 
	+ 0.6356 * parameters.avg_latency_of_same_last_20 
	- 0.076 * parameters.max_latency_of_same_last_50 
	+ 69716888.6064;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM4(work_wait &parameters) {
  double actual_remaining = 
	123.1163 * parameters.work_so_far 
	+ 14009.6744 * parameters.wait_so_far 
	- 95026.8963 * parameters.num_locks_so_far 
	+ 168091.7274 * parameters.total_wait_locks 
	- 0.005 * parameters.mean_wait_of_all 
	- 15875977.226 * parameters.cpu_usage 
	+ 0.0105 * parameters.avg_work_of_same_past_second 
	- 0.1889 * parameters.avg_wait_of_same_past_second 
	- 1.4082 * parameters.avg_latency_of_same_last_20 
	+ 0.0038 * parameters.max_latency_of_same_last_50 
	+ 328276132.2452;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM5(work_wait &parameters) {
  double actual_remaining = 
	123.1163 * parameters.work_so_far 
	+ 14009.6744 * parameters.wait_so_far 
	- 95026.8963 * parameters.num_locks_so_far 
	+ 168091.7274 * parameters.total_wait_locks 
	- 0.005 * parameters.mean_wait_of_all 
	- 15875977.226 * parameters.cpu_usage 
	+ 0.0105 * parameters.avg_work_of_same_past_second 
	- 0.1889 * parameters.avg_wait_of_same_past_second 
	- 0.9683 * parameters.avg_latency_of_same_last_20 
	+ 0.0038 * parameters.max_latency_of_same_last_50 
	+ 242577970.7973;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM6(work_wait &parameters) {
  double actual_remaining = 
	123.1163 * parameters.work_so_far 
	+ 52816.5428 * parameters.wait_so_far 
	- 95026.8963 * parameters.num_locks_so_far 
	+ 156979.7093 * parameters.total_wait_locks 
	- 0.005 * parameters.mean_wait_of_all 
	- 15875977.226 * parameters.cpu_usage 
	+ 0.0105 * parameters.avg_work_of_same_past_second 
	- 0.1746 * parameters.avg_wait_of_same_past_second 
	+ 0.0214 * parameters.avg_latency_of_same_last_20 
	+ 0.0038 * parameters.max_latency_of_same_last_50 
	- 16962615.2627;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM7(work_wait &parameters) {
  double actual_remaining = 
	222.5006 * parameters.work_so_far 
	- 0.1 * parameters.wait_so_far 
	- 95026.8963 * parameters.num_locks_so_far 
	+ 68490.5852 * parameters.total_wait_locks 
	- 0.005 * parameters.mean_wait_of_all 
	- 15875977.226 * parameters.cpu_usage 
	- 0.4178 * parameters.avg_work_of_same_past_second 
	+ 0.3157 * parameters.avg_wait_of_same_past_second 
	+ 0.0214 * parameters.avg_latency_of_same_last_20 
	+ 0.0648 * parameters.max_latency_of_same_last_50 
	+ 62981592.2064;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM8(work_wait &parameters) {
  double actual_remaining = 
	160.6343 * parameters.work_so_far 
	+ 0.0621 * parameters.wait_so_far 
	- 95026.8963 * parameters.num_locks_so_far 
	+ 97204.8639 * parameters.total_wait_locks 
	- 0.005 * parameters.mean_wait_of_all 
	- 15875977.226 * parameters.cpu_usage 
	+ 0.4653 * parameters.avg_work_of_same_past_second 
	- 0.0262 * parameters.avg_wait_of_same_past_second 
	+ 0.0214 * parameters.avg_latency_of_same_last_20 
	+ 0.0047 * parameters.max_latency_of_same_last_50 
	+ 40951906.5918;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM9(work_wait &parameters) {
  double actual_remaining = 
	-2028.7443 * parameters.work_so_far 
	+ 0.604 * parameters.wait_so_far 
	- 95026.8963 * parameters.num_locks_so_far 
	+ 97204.8639 * parameters.total_wait_locks 
	- 0.005 * parameters.mean_wait_of_all 
	- 359946536.7395 * parameters.cpu_usage 
	+ 0.0105 * parameters.avg_work_of_same_past_second 
	- 0.1148 * parameters.avg_wait_of_same_past_second 
	+ 0.0214 * parameters.avg_latency_of_same_last_20 
	+ 0.0047 * parameters.max_latency_of_same_last_50 
	+ 482105973.0677;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM10(work_wait &parameters) {
  double actual_remaining = 
	-610.7659 * parameters.work_so_far 
	+ 0.2992 * parameters.wait_so_far 
	- 95026.8963 * parameters.num_locks_so_far 
	+ 97204.8639 * parameters.total_wait_locks 
	- 0.005 * parameters.mean_wait_of_all 
	- 370698741.7243 * parameters.cpu_usage 
	+ 0.0105 * parameters.avg_work_of_same_past_second 
	- 0.1176 * parameters.avg_wait_of_same_past_second 
	+ 0.0214 * parameters.avg_latency_of_same_last_20 
	+ 0.0047 * parameters.max_latency_of_same_last_50 
	+ 435090381.9661;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM11(work_wait &parameters) {
  double actual_remaining = 
	160.6343 * parameters.work_so_far 
	- 0.0265 * parameters.wait_so_far 
	- 95026.8963 * parameters.num_locks_so_far 
	+ 97204.8639 * parameters.total_wait_locks 
	- 0.005 * parameters.mean_wait_of_all 
	- 15875977.226 * parameters.cpu_usage 
	+ 0.0105 * parameters.avg_work_of_same_past_second 
	- 0.0262 * parameters.avg_wait_of_same_past_second 
	- 0.1534 * parameters.avg_latency_of_same_last_20 
	+ 0.0047 * parameters.max_latency_of_same_last_50 
	+ 86589915.5398;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM12(work_wait &parameters) {
  double actual_remaining = 
	160.6343 * parameters.work_so_far 
	- 0.1627 * parameters.wait_so_far 
	- 95026.8963 * parameters.num_locks_so_far 
	+ 511611.3091 * parameters.total_wait_locks 
	- 1.5178 * parameters.mean_wait_of_all 
	- 648625240.2119 * parameters.cpu_usage 
	+ 1.7808 * parameters.avg_work_of_same_past_second 
	- 0.0262 * parameters.avg_wait_of_same_past_second 
	+ 0.0214 * parameters.avg_latency_of_same_last_20 
	+ 0.0047 * parameters.max_latency_of_same_last_50 
	+ 625899358.8063;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM13(work_wait &parameters) {
  double actual_remaining = 
	160.6343 * parameters.work_so_far 
	- 0.0663 * parameters.wait_so_far 
	- 95026.8963 * parameters.num_locks_so_far 
	+ 451926.0864 * parameters.total_wait_locks 
	- 1.3034 * parameters.mean_wait_of_all 
	- 86417782.5021 * parameters.cpu_usage 
	+ 0.0105 * parameters.avg_work_of_same_past_second 
	- 0.0262 * parameters.avg_wait_of_same_past_second 
	+ 0.0214 * parameters.avg_latency_of_same_last_20 
	+ 0.0047 * parameters.max_latency_of_same_last_50 
	+ 169338741.9531;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM14(work_wait &parameters) {
  double actual_remaining = 
	160.6343 * parameters.work_so_far 
	- 0.0855 * parameters.wait_so_far 
	- 95026.8963 * parameters.num_locks_so_far 
	+ 689625.7827 * parameters.total_wait_locks 
	- 2.7044 * parameters.mean_wait_of_all 
	- 15875977.226 * parameters.cpu_usage 
	+ 0.0789 * parameters.avg_work_of_same_past_second 
	- 0.0262 * parameters.avg_wait_of_same_past_second 
	+ 0.0214 * parameters.avg_latency_of_same_last_20 
	+ 0.0047 * parameters.max_latency_of_same_last_50 
	+ 154842294.1269;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM15(work_wait &parameters) {
  double actual_remaining = 
	160.6343 * parameters.work_so_far 
	- 0.0855 * parameters.wait_so_far 
	- 95026.8963 * parameters.num_locks_so_far 
	+ 689625.7827 * parameters.total_wait_locks 
	+ 4.5866 * parameters.mean_wait_of_all 
	- 15875977.226 * parameters.cpu_usage 
	+ 0.8239 * parameters.avg_work_of_same_past_second 
	- 0.0262 * parameters.avg_wait_of_same_past_second 
	+ 0.0214 * parameters.avg_latency_of_same_last_20 
	+ 0.0047 * parameters.max_latency_of_same_last_50 
	- 179453659.4624;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM16(work_wait &parameters) {
  double actual_remaining = 
	160.6343 * parameters.work_so_far 
	- 0.0855 * parameters.wait_so_far 
	- 95026.8963 * parameters.num_locks_so_far 
	+ 689625.7827 * parameters.total_wait_locks 
	+ 3.399 * parameters.mean_wait_of_all 
	- 15875977.226 * parameters.cpu_usage 
	+ 0.9489 * parameters.avg_work_of_same_past_second 
	- 0.0262 * parameters.avg_wait_of_same_past_second 
	+ 0.0214 * parameters.avg_latency_of_same_last_20 
	+ 0.0047 * parameters.max_latency_of_same_last_50 
	- 132850686.975;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM17(work_wait &parameters) {
  double actual_remaining = 
	160.6343 * parameters.work_so_far 
	- 0.0855 * parameters.wait_so_far 
	- 95026.8963 * parameters.num_locks_so_far 
	+ 689625.7827 * parameters.total_wait_locks 
	+ 3.399 * parameters.mean_wait_of_all 
	- 15875977.226 * parameters.cpu_usage 
	+ 0.9545 * parameters.avg_work_of_same_past_second 
	- 0.0262 * parameters.avg_wait_of_same_past_second 
	+ 0.0214 * parameters.avg_latency_of_same_last_20 
	+ 0.0047 * parameters.max_latency_of_same_last_50 
	- 132539614.7348;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM18(work_wait &parameters) {
  double actual_remaining = 
	160.6343 * parameters.work_so_far 
	- 0.0855 * parameters.wait_so_far 
	- 95026.8963 * parameters.num_locks_so_far 
	+ 689625.7827 * parameters.total_wait_locks 
	+ 3.399 * parameters.mean_wait_of_all 
	- 15875977.226 * parameters.cpu_usage 
	+ 0.8635 * parameters.avg_work_of_same_past_second 
	- 0.0262 * parameters.avg_wait_of_same_past_second 
	+ 0.0214 * parameters.avg_latency_of_same_last_20 
	+ 0.0047 * parameters.max_latency_of_same_last_50 
	- 122370311.6764;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM19(work_wait &parameters) {
  double actual_remaining = 
	1.0782 * parameters.work_so_far 
	- 0.0096 * parameters.wait_so_far 
	- 7683097.226 * parameters.num_locks_so_far 
	+ 102752.3466 * parameters.total_wait_locks 
	- 0.8494 * parameters.mean_wait_of_all 
	- 91352033.7474 * parameters.cpu_usage 
	+ 0.1511 * parameters.avg_work_of_same_past_second 
	- 0.1357 * parameters.avg_wait_of_same_past_second 
	+ 0.189 * parameters.avg_latency_of_same_last_20 
	- 0.0608 * parameters.max_latency_of_same_last_50 
	+ 282689437.5967;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM20(work_wait &parameters) {
  double actual_remaining = 
	1.4494 * parameters.work_so_far 
	- 0.0096 * parameters.wait_so_far 
	- 2595552.4424 * parameters.num_locks_so_far 
	+ 102752.3466 * parameters.total_wait_locks 
	- 0.005 * parameters.mean_wait_of_all 
	- 91352033.7474 * parameters.cpu_usage 
	+ 0.1511 * parameters.avg_work_of_same_past_second 
	- 0.1357 * parameters.avg_wait_of_same_past_second 
	+ 0.189 * parameters.avg_latency_of_same_last_20 
	- 0.2175 * parameters.max_latency_of_same_last_50 
	+ 344205108.6766;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM21(work_wait &parameters) {
  double actual_remaining = 
	1.4494 * parameters.work_so_far 
	- 0.0096 * parameters.wait_so_far 
	- 2595552.4424 * parameters.num_locks_so_far 
	+ 102752.3466 * parameters.total_wait_locks 
	- 0.005 * parameters.mean_wait_of_all 
	- 91352033.7474 * parameters.cpu_usage 
	+ 0.1511 * parameters.avg_work_of_same_past_second 
	- 0.1357 * parameters.avg_wait_of_same_past_second 
	+ 0.189 * parameters.avg_latency_of_same_last_20 
	- 0.1631 * parameters.max_latency_of_same_last_50 
	+ 289761833.8093;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM22(work_wait &parameters) {
  double actual_remaining = 
	0.7712 * parameters.work_so_far 
	- 0.0096 * parameters.wait_so_far 
	- 95026.8963 * parameters.num_locks_so_far 
	+ 88129.0881 * parameters.total_wait_locks 
	- 0.005 * parameters.mean_wait_of_all 
	- 76547847.199 * parameters.cpu_usage 
	- 0.525 * parameters.avg_work_of_same_past_second 
	- 0.265 * parameters.avg_wait_of_same_past_second 
	+ 0.1538 * parameters.avg_latency_of_same_last_20 
	- 0.1918 * parameters.max_latency_of_same_last_50 
	+ 415543717.3638;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM23(work_wait &parameters) {
  double actual_remaining = 
	1.8435 * parameters.work_so_far 
	- 0.0096 * parameters.wait_so_far 
	+ 4910513.2246 * parameters.num_locks_so_far 
	+ 2176468.7614 * parameters.total_wait_locks 
	- 11.9886 * parameters.mean_wait_of_all 
	- 76547847.199 * parameters.cpu_usage 
	+ 1.7884 * parameters.avg_work_of_same_past_second 
	- 0.265 * parameters.avg_wait_of_same_past_second 
	+ 0.1538 * parameters.avg_latency_of_same_last_20 
	- 0.4664 * parameters.max_latency_of_same_last_50 
	+ 685624058.0938;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM24(work_wait &parameters) {
  double actual_remaining = 
	0.7712 * parameters.work_so_far 
	- 0.0096 * parameters.wait_so_far 
	+ 16414813.4694 * parameters.num_locks_so_far 
	+ 88129.0881 * parameters.total_wait_locks 
	+ 3.9305 * parameters.mean_wait_of_all 
	- 76547847.199 * parameters.cpu_usage 
	+ 0.2828 * parameters.avg_work_of_same_past_second 
	- 0.265 * parameters.avg_wait_of_same_past_second 
	+ 0.1538 * parameters.avg_latency_of_same_last_20 
	- 0.3945 * parameters.max_latency_of_same_last_50 
	+ 160377331.8918;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM25(work_wait &parameters) {
  double actual_remaining = 
	2.6928 * parameters.work_so_far 
	- 0.0096 * parameters.wait_so_far 
	- 95026.8963 * parameters.num_locks_so_far 
	+ 88129.0881 * parameters.total_wait_locks 
	- 0.005 * parameters.mean_wait_of_all 
	- 76547847.199 * parameters.cpu_usage 
	+ 0.386 * parameters.avg_work_of_same_past_second 
	- 0.3624 * parameters.avg_wait_of_same_past_second 
	+ 0.1538 * parameters.avg_latency_of_same_last_20 
	- 0.1015 * parameters.max_latency_of_same_last_50 
	+ 213319588.2995;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM26(work_wait &parameters) {
  double actual_remaining = 
	2.3088 * parameters.work_so_far 
	+ 0.9016 * parameters.wait_so_far 
	- 1607703.5359 * parameters.num_locks_so_far 
	+ 273895.5278 * parameters.total_wait_locks 
	- 0.005 * parameters.mean_wait_of_all 
	- 336734715.3374 * parameters.cpu_usage 
	+ 0.4251 * parameters.avg_work_of_same_past_second 
	- 0.3724 * parameters.avg_wait_of_same_past_second 
	+ 0.0098 * parameters.avg_latency_of_same_last_20 
	+ 0.0228 * parameters.max_latency_of_same_last_50 
	+ 333324404.5656;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM27(work_wait &parameters) {
  double actual_remaining = 
	3750.3385 * parameters.work_so_far 
	- 0.1689 * parameters.wait_so_far 
	- 149015.6935 * parameters.num_locks_so_far 
	+ 54904.521 * parameters.total_wait_locks 
	- 0.0058 * parameters.mean_wait_of_all 
	- 1555506.3772 * parameters.cpu_usage 
	+ 0.0223 * parameters.avg_work_of_same_past_second 
	- 0.2815 * parameters.avg_wait_of_same_past_second 
	+ 0.0172 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 46699482.7484;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM28(work_wait &parameters) {
  double actual_remaining = 
	1.6448 * parameters.work_so_far 
	- 0.2197 * parameters.wait_so_far 
	- 3080602.5409 * parameters.num_locks_so_far 
	+ 1297908.2937 * parameters.total_wait_locks 
	- 0.0058 * parameters.mean_wait_of_all 
	- 1555506.3772 * parameters.cpu_usage 
	+ 0.029 * parameters.avg_work_of_same_past_second 
	- 0.0138 * parameters.avg_wait_of_same_past_second 
	+ 0.0263 * parameters.avg_latency_of_same_last_20 
	- 0.0047 * parameters.max_latency_of_same_last_50 
	+ 92102703.4718;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM29(work_wait &parameters) {
  double actual_remaining = 
	1.4849 * parameters.work_so_far 
	+ 0.0191 * parameters.wait_so_far 
	- 1673752.5544 * parameters.num_locks_so_far 
	- 1244584.8844 * parameters.total_wait_locks 
	- 0.0058 * parameters.mean_wait_of_all 
	+ 51163860.497 * parameters.cpu_usage 
	+ 0.0177 * parameters.avg_work_of_same_past_second 
	- 0.0138 * parameters.avg_wait_of_same_past_second 
	+ 0.1549 * parameters.avg_latency_of_same_last_20 
	- 0.0014 * parameters.max_latency_of_same_last_50 
	+ 353706531.1114;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM30(work_wait &parameters) {
  double actual_remaining = 
	4.409 * parameters.work_so_far 
	+ 0.0191 * parameters.wait_so_far 
	- 1673752.5544 * parameters.num_locks_so_far 
	- 477164.3014 * parameters.total_wait_locks 
	- 0.0058 * parameters.mean_wait_of_all 
	+ 51163860.497 * parameters.cpu_usage 
	+ 0.0177 * parameters.avg_work_of_same_past_second 
	- 0.0138 * parameters.avg_wait_of_same_past_second 
	+ 0.2074 * parameters.avg_latency_of_same_last_20 
	- 0.0925 * parameters.max_latency_of_same_last_50 
	+ 319060865.0693;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM31(work_wait &parameters) {
  double actual_remaining = 
	2.465 * parameters.work_so_far 
	+ 0.0191 * parameters.wait_so_far 
	- 1220291.3259 * parameters.num_locks_so_far 
	+ 161622.9166 * parameters.total_wait_locks 
	- 0.0058 * parameters.mean_wait_of_all 
	+ 31569051.5703 * parameters.cpu_usage 
	+ 0.0177 * parameters.avg_work_of_same_past_second 
	- 0.0138 * parameters.avg_wait_of_same_past_second 
	+ 0.0552 * parameters.avg_latency_of_same_last_20 
	- 0.0014 * parameters.max_latency_of_same_last_50 
	+ 59104460.4341;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM32(work_wait &parameters) {
  double actual_remaining = 
	4.0192 * parameters.work_so_far 
	- 0.2603 * parameters.wait_so_far 
	- 263412.295 * parameters.num_locks_so_far 
	+ 1512972.9561 * parameters.total_wait_locks 
	+ 0.011 * parameters.mean_wait_of_all 
	- 1555506.3772 * parameters.cpu_usage 
	+ 0.0177 * parameters.avg_work_of_same_past_second 
	- 0.0138 * parameters.avg_wait_of_same_past_second 
	+ 0.0156 * parameters.avg_latency_of_same_last_20 
	- 0.0043 * parameters.max_latency_of_same_last_50 
	+ 61928880.5072;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM33(work_wait &parameters) {
  double actual_remaining = 
	2.5313 * parameters.work_so_far 
	+ 0.6748 * parameters.wait_so_far 
	- 5991560.3739 * parameters.num_locks_so_far 
	+ 285908.2514 * parameters.total_wait_locks 
	+ 0.0252 * parameters.mean_wait_of_all 
	- 1555506.3772 * parameters.cpu_usage 
	+ 0.0177 * parameters.avg_work_of_same_past_second 
	- 0.0138 * parameters.avg_wait_of_same_past_second 
	+ 0.0156 * parameters.avg_latency_of_same_last_20 
	- 0.0973 * parameters.max_latency_of_same_last_50 
	+ 370549764.1379;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM34(work_wait &parameters) {
  double actual_remaining = 
	0.9432 * parameters.work_so_far 
	- 0.8408 * parameters.wait_so_far 
	- 7040884.3109 * parameters.num_locks_so_far 
	+ 87324.4303 * parameters.total_wait_locks 
	- 0.1348 * parameters.mean_wait_of_all 
	- 2057364.2264 * parameters.cpu_usage 
	+ 0.02 * parameters.avg_work_of_same_past_second 
	- 0.0665 * parameters.avg_wait_of_same_past_second 
	+ 0.4672 * parameters.avg_latency_of_same_last_20 
	- 0.0013 * parameters.max_latency_of_same_last_50 
	+ 351588581.6484;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM35(work_wait &parameters) {
  double actual_remaining = 
	0.3072 * parameters.work_so_far 
	+ 0.2409 * parameters.wait_so_far 
	- 148527.1319 * parameters.num_locks_so_far 
	+ 399001.2149 * parameters.total_wait_locks 
	- 2.8214 * parameters.mean_wait_of_all 
	- 14758582.4372 * parameters.cpu_usage 
	- 0.3854 * parameters.avg_work_of_same_past_second 
	+ 0.3512 * parameters.avg_wait_of_same_past_second 
	+ 0.5883 * parameters.avg_latency_of_same_last_20 
	- 0.0013 * parameters.max_latency_of_same_last_50 
	+ 213660708.2533;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM36(work_wait &parameters) {
  double actual_remaining = 
	0.2198 * parameters.work_so_far 
	+ 0.7503 * parameters.wait_so_far 
	- 148527.1319 * parameters.num_locks_so_far 
	+ 1209948.2387 * parameters.total_wait_locks 
	- 9.5632 * parameters.mean_wait_of_all 
	- 14758582.4372 * parameters.cpu_usage 
	- 1.3938 * parameters.avg_work_of_same_past_second 
	+ 1.2628 * parameters.avg_wait_of_same_past_second 
	+ 0.052 * parameters.avg_latency_of_same_last_20 
	- 0.0013 * parameters.max_latency_of_same_last_50 
	+ 598371975.0636;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM37(work_wait &parameters) {
  double actual_remaining = 
	1.1029 * parameters.work_so_far 
	+ 0.6785 * parameters.wait_so_far 
	+ 2051846.3948 * parameters.num_locks_so_far 
	+ 311911.561 * parameters.total_wait_locks 
	- 0.089 * parameters.mean_wait_of_all 
	- 10555633.8656 * parameters.cpu_usage 
	+ 0.0091 * parameters.avg_work_of_same_past_second 
	- 0.3541 * parameters.avg_wait_of_same_past_second 
	+ 0.3917 * parameters.avg_latency_of_same_last_20 
	- 0.0478 * parameters.max_latency_of_same_last_50 
	- 8688679.1547;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM38(work_wait &parameters) {
  double actual_remaining = 
	1.0438 * parameters.work_so_far 
	+ 0.0006 * parameters.wait_so_far 
	- 2105545.398 * parameters.num_locks_so_far 
	+ 50241.5644 * parameters.total_wait_locks 
	- 0.0745 * parameters.mean_wait_of_all 
	- 2057364.2264 * parameters.cpu_usage 
	+ 0.7538 * parameters.avg_work_of_same_past_second 
	- 0.0481 * parameters.avg_wait_of_same_past_second 
	+ 0.236 * parameters.avg_latency_of_same_last_20 
	- 0.1323 * parameters.max_latency_of_same_last_50 
	+ 209022766.3624;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM39(work_wait &parameters) {
  double actual_remaining = 
	0.0039 * parameters.work_so_far 
	- 0.1981 * parameters.wait_so_far 
	- 698.4849 * parameters.num_locks_so_far 
	+ 1540402.5762 * parameters.total_wait_locks 
	- 3.3944 * parameters.mean_wait_of_all 
	- 4219948.6235 * parameters.cpu_usage 
	- 0.4982 * parameters.avg_work_of_same_past_second 
	- 0.0005 * parameters.avg_wait_of_same_past_second 
	+ 0.1595 * parameters.avg_latency_of_same_last_20 
	- 0.0544 * parameters.max_latency_of_same_last_50 
	+ 210424867.6827;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM40(work_wait &parameters) {
  double actual_remaining = 
	0.0039 * parameters.work_so_far 
	- 0.0871 * parameters.wait_so_far 
	- 698.4849 * parameters.num_locks_so_far 
	+ 25861.4744 * parameters.total_wait_locks 
	- 0.0371 * parameters.mean_wait_of_all 
	- 470685508.5711 * parameters.cpu_usage 
	- 0.0058 * parameters.avg_work_of_same_past_second 
	- 0.0005 * parameters.avg_wait_of_same_past_second 
	+ 0.1281 * parameters.avg_latency_of_same_last_20 
	- 0.0014 * parameters.max_latency_of_same_last_50 
	+ 589567531.0949;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM41(work_wait &parameters) {
  double actual_remaining = 
	-1.6387 * parameters.work_so_far 
	+ 18206.6724 * parameters.wait_so_far 
	- 698.4849 * parameters.num_locks_so_far 
	- 1433384.3644 * parameters.total_wait_locks 
	+ 8.9333 * parameters.mean_wait_of_all 
	+ 655520840.4998 * parameters.cpu_usage 
	+ 0.7317 * parameters.avg_work_of_same_past_second 
	- 0.0341 * parameters.avg_wait_of_same_past_second 
	- 0.3104 * parameters.avg_latency_of_same_last_20 
	- 0.0021 * parameters.max_latency_of_same_last_50 
	- 710813496.1112;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM42(work_wait &parameters) {
  double actual_remaining = 
	361.5584 * parameters.work_so_far 
	+ 407.4059 * parameters.wait_so_far 
	- 698.4849 * parameters.num_locks_so_far 
	- 4746366.6753 * parameters.total_wait_locks 
	+ 27.7184 * parameters.mean_wait_of_all 
	- 130222989.5006 * parameters.cpu_usage 
	+ 0.082 * parameters.avg_work_of_same_past_second 
	- 0.0621 * parameters.avg_wait_of_same_past_second 
	- 0.3765 * parameters.avg_latency_of_same_last_20 
	- 0.0021 * parameters.max_latency_of_same_last_50 
	+ 160952772.74;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM43(work_wait &parameters) {
  double actual_remaining = 
	98.8893 * parameters.work_so_far 
	+ 695.5385 * parameters.wait_so_far 
	- 698.4849 * parameters.num_locks_so_far 
	- 1674183.2434 * parameters.total_wait_locks 
	+ 10.0935 * parameters.mean_wait_of_all 
	- 395775752.4036 * parameters.cpu_usage 
	+ 0.082 * parameters.avg_work_of_same_past_second 
	- 0.0621 * parameters.avg_wait_of_same_past_second 
	- 0.13 * parameters.avg_latency_of_same_last_20 
	- 0.0021 * parameters.max_latency_of_same_last_50 
	+ 901309112.7953;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM44(work_wait &parameters) {
  double actual_remaining = 
	-4.4784 * parameters.work_so_far 
	- 0.0136 * parameters.wait_so_far 
	- 698.4849 * parameters.num_locks_so_far 
	- 73244.4918 * parameters.total_wait_locks 
	+ 0.4425 * parameters.mean_wait_of_all 
	+ 0.0102 * parameters.avg_work_of_same_past_second 
	- 0.0065 * parameters.avg_wait_of_same_past_second 
	+ 0.0143 * parameters.avg_latency_of_same_last_20 
	- 0.0044 * parameters.max_latency_of_same_last_50 
	+ 334755208.9718;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM45(work_wait &parameters) {
  double actual_remaining = 
	-4.4784 * parameters.work_so_far 
	+ 11.8185 * parameters.wait_so_far 
	- 698.4849 * parameters.num_locks_so_far 
	- 73244.4918 * parameters.total_wait_locks 
	+ 0.4425 * parameters.mean_wait_of_all 
	+ 2568534814.5251 * parameters.cpu_usage 
	+ 0.0102 * parameters.avg_work_of_same_past_second 
	- 0.0065 * parameters.avg_wait_of_same_past_second 
	+ 0.0143 * parameters.avg_latency_of_same_last_20 
	- 0.0044 * parameters.max_latency_of_same_last_50 
	- 2117029261.8174;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM46(work_wait &parameters) {
  double actual_remaining = 
	-4.4784 * parameters.work_so_far 
	+ 3.0858 * parameters.wait_so_far 
	- 698.4849 * parameters.num_locks_so_far 
	- 73244.4918 * parameters.total_wait_locks 
	+ 0.4425 * parameters.mean_wait_of_all 
	+ 0.0102 * parameters.avg_work_of_same_past_second 
	- 0.0065 * parameters.avg_wait_of_same_past_second 
	+ 4.2258 * parameters.avg_latency_of_same_last_20 
	- 0.0044 * parameters.max_latency_of_same_last_50 
	- 1316422862.1104;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM47(work_wait &parameters) {
  double actual_remaining = 
	-4.4784 * parameters.work_so_far 
	- 0.0136 * parameters.wait_so_far 
	- 698.4849 * parameters.num_locks_so_far 
	- 117583.5428 * parameters.total_wait_locks 
	+ 0.7358 * parameters.mean_wait_of_all 
	+ 0.0753 * parameters.avg_work_of_same_past_second 
	- 0.0065 * parameters.avg_wait_of_same_past_second 
	+ 0.0143 * parameters.avg_latency_of_same_last_20 
	- 0.0044 * parameters.max_latency_of_same_last_50 
	+ 228559629.9473;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM48(work_wait &parameters) {
  double actual_remaining = 
	-4.4784 * parameters.work_so_far 
	- 0.0136 * parameters.wait_so_far 
	- 698.4849 * parameters.num_locks_so_far 
	- 208035.2068 * parameters.total_wait_locks 
	+ 1.3339 * parameters.mean_wait_of_all 
	+ 0.2081 * parameters.avg_work_of_same_past_second 
	- 0.0065 * parameters.avg_wait_of_same_past_second 
	+ 0.4666 * parameters.avg_latency_of_same_last_20 
	- 0.0044 * parameters.max_latency_of_same_last_50 
	- 13870613.6045;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM49(work_wait &parameters) {
  double actual_remaining = 
	-160.6666 * parameters.work_so_far 
	- 0.6638 * parameters.wait_so_far 
	- 698.4849 * parameters.num_locks_so_far 
	- 1681579.3748 * parameters.total_wait_locks 
	+ 10.1199 * parameters.mean_wait_of_all 
	+ 0.0102 * parameters.avg_work_of_same_past_second 
	- 0.0065 * parameters.avg_wait_of_same_past_second 
	+ 0.281 * parameters.avg_latency_of_same_last_20 
	- 0.0785 * parameters.max_latency_of_same_last_50 
	+ 195811624.1704;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM50(work_wait &parameters) {
  double actual_remaining = 
	114.4128 * parameters.work_so_far 
	- 0.1762 * parameters.wait_so_far 
	- 698.4849 * parameters.num_locks_so_far 
	- 1570686.5234 * parameters.total_wait_locks 
	+ 9.3213 * parameters.mean_wait_of_all 
	+ 0.0047 * parameters.avg_work_of_same_past_second 
	- 0.0026 * parameters.avg_wait_of_same_past_second 
	+ 0.3319 * parameters.avg_latency_of_same_last_20 
	- 0.052 * parameters.max_latency_of_same_last_50 
	+ 34236475.8512;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM51(work_wait &parameters) {
  double actual_remaining = 
	0.0559 * parameters.work_so_far 
	+ 0.4858 * parameters.wait_so_far 
	+ 94486.0548 * parameters.num_locks_so_far 
	- 953039.5893 * parameters.total_wait_locks 
	+ 5.7135 * parameters.mean_wait_of_all 
	+ 0.3683 * parameters.avg_work_of_same_past_second 
	- 0.0011 * parameters.avg_wait_of_same_past_second 
	+ 0.0922 * parameters.avg_latency_of_same_last_20 
	- 0.0349 * parameters.max_latency_of_same_last_50 
	+ 165326742.5581;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM52(work_wait &parameters) {
  double actual_remaining = 
	1.1044 * parameters.work_so_far 
	+ 0.0139 * parameters.wait_so_far 
	+ 951955.7096 * parameters.num_locks_so_far 
	+ 1257.5775 * parameters.total_wait_locks 
	+ 0.0291 * parameters.mean_wait_of_all 
	+ 0.0088 * parameters.avg_work_of_same_past_second 
	+ 0.3856 * parameters.avg_wait_of_same_past_second 
	+ 0.1812 * parameters.avg_latency_of_same_last_20 
	- 0.0017 * parameters.max_latency_of_same_last_50 
	+ 277475351.7467;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM53(work_wait &parameters) {
  double actual_remaining = 
	1.3075 * parameters.work_so_far 
	+ 0.911 * parameters.wait_so_far 
	+ 2109799.9831 * parameters.num_locks_so_far 
	+ 245571.853 * parameters.total_wait_locks 
	- 0.0296 * parameters.mean_wait_of_all 
	+ 0.0088 * parameters.avg_work_of_same_past_second 
	+ 0.0186 * parameters.avg_wait_of_same_past_second 
	+ 0.3263 * parameters.avg_latency_of_same_last_20 
	- 0.0033 * parameters.max_latency_of_same_last_50 
	+ 329912063.2798;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM54(work_wait &parameters) {
  double actual_remaining = 
	7.6178 * parameters.work_so_far 
	+ 1.6861 * parameters.wait_so_far 
	- 10008843.8209 * parameters.num_locks_so_far 
	- 135888.44 * parameters.total_wait_locks 
	+ 0.8757 * parameters.mean_wait_of_all 
	+ 0.0109 * parameters.avg_work_of_same_past_second 
	- 0.011 * parameters.avg_wait_of_same_past_second 
	+ 0.1013 * parameters.avg_latency_of_same_last_20 
	+ 0.0003 * parameters.max_latency_of_same_last_50 
	+ 196805465.475;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM55(work_wait &parameters) {
  double actual_remaining = 
	0.3807 * parameters.work_so_far 
	+ 0.2023 * parameters.wait_so_far 
	- 27435458.1622 * parameters.num_locks_so_far 
	- 67303.3078 * parameters.total_wait_locks 
	+ 0.0526 * parameters.mean_wait_of_all 
	+ 0.3862 * parameters.avg_work_of_same_past_second 
	- 0.8995 * parameters.avg_wait_of_same_past_second 
	+ 0.0072 * parameters.avg_latency_of_same_last_20 
	+ 0.0039 * parameters.max_latency_of_same_last_50 
	+ 899892239.3537;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM56(work_wait &parameters) {
  double actual_remaining = 
	0.3807 * parameters.work_so_far 
	+ 0.2023 * parameters.wait_so_far 
	- 4412382.0245 * parameters.num_locks_so_far 
	- 419503.2935 * parameters.total_wait_locks 
	+ 0.0526 * parameters.mean_wait_of_all 
	+ 0.2934 * parameters.avg_work_of_same_past_second 
	- 0.1992 * parameters.avg_wait_of_same_past_second 
	+ 0.0072 * parameters.avg_latency_of_same_last_20 
	+ 0.0039 * parameters.max_latency_of_same_last_50 
	+ 682307174.8568;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM57(work_wait &parameters) {
  double actual_remaining = 
	0.3664 * parameters.work_so_far 
	+ 0.1843 * parameters.wait_so_far 
	- 973569.8275 * parameters.num_locks_so_far 
	+ 168943.0933 * parameters.total_wait_locks 
	+ 0.0153 * parameters.mean_wait_of_all 
	+ 0.0291 * parameters.avg_work_of_same_past_second 
	- 0.4754 * parameters.avg_wait_of_same_past_second 
	+ 0.1308 * parameters.avg_latency_of_same_last_20 
	+ 0.0016 * parameters.max_latency_of_same_last_50 
	+ 204028996.4599;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM58(work_wait &parameters) {
  double actual_remaining = 
	0.3977 * parameters.work_so_far 
	+ 0.3351 * parameters.wait_so_far 
	- 1013027.4654 * parameters.num_locks_so_far 
	+ 9656.9269 * parameters.total_wait_locks 
	+ 0.005 * parameters.mean_wait_of_all 
	- 55657714.6581 * parameters.cpu_usage 
	+ 0.0291 * parameters.avg_work_of_same_past_second 
	- 0.0415 * parameters.avg_wait_of_same_past_second 
	+ 0.016 * parameters.avg_latency_of_same_last_20 
	+ 0.0104 * parameters.max_latency_of_same_last_50 
	+ 307552717.7939;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM59(work_wait &parameters) {
  double actual_remaining = 
	0.3977 * parameters.work_so_far 
	+ 0.5391 * parameters.wait_so_far 
	+ 15735241.3297 * parameters.num_locks_so_far 
	+ 9656.9269 * parameters.total_wait_locks 
	+ 0.005 * parameters.mean_wait_of_all 
	- 141674182.766 * parameters.cpu_usage 
	+ 0.0291 * parameters.avg_work_of_same_past_second 
	+ 0.3034 * parameters.avg_wait_of_same_past_second 
	+ 0.016 * parameters.avg_latency_of_same_last_20 
	+ 0.0242 * parameters.max_latency_of_same_last_50 
	+ 31233908.1828;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM60(work_wait &parameters) {
  double actual_remaining = 
	0.3977 * parameters.work_so_far 
	+ 0.5391 * parameters.wait_so_far 
	- 3626976.8385 * parameters.num_locks_so_far 
	+ 9656.9269 * parameters.total_wait_locks 
	+ 0.005 * parameters.mean_wait_of_all 
	- 141674182.766 * parameters.cpu_usage 
	+ 0.0291 * parameters.avg_work_of_same_past_second 
	+ 0.1623 * parameters.avg_wait_of_same_past_second 
	+ 0.016 * parameters.avg_latency_of_same_last_20 
	+ 0.0242 * parameters.max_latency_of_same_last_50 
	+ 450629557.8223;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM61(work_wait &parameters) {
  double actual_remaining = 
	2.6891 * parameters.work_so_far 
	+ 0.7016 * parameters.wait_so_far 
	- 6553443.6229 * parameters.num_locks_so_far 
	- 265889.5432 * parameters.total_wait_locks 
	+ 2.1006 * parameters.mean_wait_of_all 
	- 0.2336 * parameters.avg_work_of_same_past_second 
	- 0.0043 * parameters.avg_wait_of_same_past_second 
	+ 0.1196 * parameters.avg_latency_of_same_last_20 
	+ 0.0506 * parameters.max_latency_of_same_last_50 
	+ 232307886.1723;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM62(work_wait &parameters) {
  double actual_remaining = 
	0.1011 * parameters.work_so_far 
	+ 1.0252 * parameters.wait_so_far 
	- 1057077.7613 * parameters.num_locks_so_far 
	- 2394203.112 * parameters.total_wait_locks 
	+ 13.3384 * parameters.mean_wait_of_all 
	- 6275745.1645 * parameters.cpu_usage 
	+ 0.0022 * parameters.avg_work_of_same_past_second 
	- 0.0011 * parameters.avg_wait_of_same_past_second 
	+ 0.3301 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 278153928.048;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM63(work_wait &parameters) {
  double actual_remaining = 
	0.708 * parameters.work_so_far 
	+ 0.6895 * parameters.wait_so_far 
	+ 1130608.4329 * parameters.num_locks_so_far 
	+ 476536.5393 * parameters.total_wait_locks 
	- 1.8361 * parameters.mean_wait_of_all 
	- 275896074.9779 * parameters.cpu_usage 
	+ 0.0022 * parameters.avg_work_of_same_past_second 
	- 0.0011 * parameters.avg_wait_of_same_past_second 
	+ 0.1214 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 445575904.2071;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM64(work_wait &parameters) {
  double actual_remaining = 
	0.8598 * parameters.work_so_far 
	+ 0.6556 * parameters.wait_so_far 
	- 10336667.4232 * parameters.num_locks_so_far 
	- 670837.8759 * parameters.total_wait_locks 
	+ 4.5831 * parameters.mean_wait_of_all 
	- 384689963.9473 * parameters.cpu_usage 
	+ 0.0022 * parameters.avg_work_of_same_past_second 
	- 0.0011 * parameters.avg_wait_of_same_past_second 
	+ 0.0075 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 881636006.2496;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM65(work_wait &parameters) {
  double actual_remaining = 
	0.0439 * parameters.work_so_far 
	- 0.1433 * parameters.wait_so_far 
	+ 191903.8803 * parameters.num_locks_so_far 
	- 1074144.0603 * parameters.total_wait_locks 
	+ 6.4673 * parameters.mean_wait_of_all 
	+ 17364816.5193 * parameters.cpu_usage 
	+ 0.5768 * parameters.avg_work_of_same_past_second 
	- 0.5608 * parameters.avg_wait_of_same_past_second 
	+ 0.2237 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 101561256.1696;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM66(work_wait &parameters) {
  double actual_remaining = 
	1.652 * parameters.work_so_far 
	+ 0.7443 * parameters.wait_so_far 
	+ 40621477.3411 * parameters.num_locks_so_far 
	- 2091472.8533 * parameters.total_wait_locks 
	+ 12.1914 * parameters.mean_wait_of_all 
	+ 6440050.7546 * parameters.cpu_usage 
	+ 0.9785 * parameters.avg_work_of_same_past_second 
	- 0.5713 * parameters.avg_wait_of_same_past_second 
	+ 0.0156 * parameters.avg_latency_of_same_last_20 
	- 0.072 * parameters.max_latency_of_same_last_50 
	- 169016645.6561;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM67(work_wait &parameters) {
  double actual_remaining = 
	0.8789 * parameters.work_so_far 
	+ 0.673 * parameters.wait_so_far 
	- 300583.772 * parameters.num_locks_so_far 
	- 529563.0003 * parameters.total_wait_locks 
	+ 3.3785 * parameters.mean_wait_of_all 
	- 211131222.6857 * parameters.cpu_usage 
	+ 0.0376 * parameters.avg_work_of_same_past_second 
	- 0.2432 * parameters.avg_wait_of_same_past_second 
	+ 0.2312 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 347529365.983;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM68(work_wait &parameters) {
  double actual_remaining = 
	1.0437 * parameters.work_so_far 
	+ 0.9021 * parameters.wait_so_far 
	- 3922546.3972 * parameters.num_locks_so_far 
	- 640492.046 * parameters.total_wait_locks 
	+ 4.2011 * parameters.mean_wait_of_all 
	+ 6440050.7546 * parameters.cpu_usage 
	+ 1.4482 * parameters.avg_work_of_same_past_second 
	- 0.8001 * parameters.avg_wait_of_same_past_second 
	+ 0.0161 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 3056724.0531;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
new_order_estimate(work_wait &parameters){

  if (parameters.total_wait_locks <= 171.5) {

    if (parameters.work_so_far <= 79455395.5) {

      if (parameters.avg_latency_of_same_last_20 <= 158588500) {

        if (parameters.num_locks_so_far <= 17.5) {

          if (parameters.work_so_far <= 52684) {

            if (parameters.wait_so_far <= 6923.5) {

              if (parameters.wait_so_far <= 2229) {
                return new_order_LM1(parameters);
              } else {

                if (parameters.avg_work_of_same_past_second <= 61567350) {

                  if (parameters.mean_wait_of_all <= 41882850) {

                    if (parameters.wait_so_far <= 3000) {
                      return new_order_LM2(parameters);
                    } else {
                      return new_order_LM3(parameters);
                    }
                  } else {

                    if (parameters.avg_latency_of_same_last_20 <= 34492300) {
                      return new_order_LM4(parameters);
                    } else {
                      return new_order_LM5(parameters);
                    }
                  }
                } else {
                  return new_order_LM6(parameters);
                }
              }
            } else {

              if (parameters.work_so_far <= 27034) {
                return new_order_LM7(parameters);
              } else {

                if (parameters.total_wait_locks <= 90.5) {

                  if (parameters.wait_so_far <= 121766940) {

                    if (parameters.cpu_usage <= 0.929) {
                      return new_order_LM8(parameters);
                    } else {

                      if (parameters.cpu_usage <= 0.976) {
                        return new_order_LM9(parameters);
                      } else {
                        return new_order_LM10(parameters);
                      }
                    }
                  } else {
                    return new_order_LM11(parameters);
                  }
                } else {

                  if (parameters.work_so_far <= 42989) {

                    if (parameters.avg_wait_of_same_past_second <= 18350900) {
                      return new_order_LM12(parameters);
                    } else {
                      return new_order_LM13(parameters);
                    }
                  } else {

                    if (parameters.max_latency_of_same_last_50 <= 377611000) {
                      return new_order_LM14(parameters);
                    } else {

                      if (parameters.mean_wait_of_all <= 38076500) {
                        return new_order_LM15(parameters);
                      } else {

                        if (parameters.cpu_usage <= 0.95) {

                          if (parameters.avg_work_of_same_past_second <= 73053050) {
                            return new_order_LM16(parameters);
                          } else {
                            return new_order_LM17(parameters);
                          }
                        } else {
                          return new_order_LM18(parameters);
                        }
                      }
                    }
                  }
                }
              }
            }
          } else {

            if (parameters.avg_latency_of_same_last_20 <= 61656550) {

              if (parameters.work_so_far <= 17135175) {
                return new_order_LM19(parameters);
              } else {

                if (parameters.max_latency_of_same_last_50 <= 102414400) {
                  return new_order_LM20(parameters);
                } else {
                  return new_order_LM21(parameters);
                }
              }
            } else {

              if (parameters.max_latency_of_same_last_50 <= 586700000) {

                if (parameters.wait_so_far <= 6257.5) {
                  return new_order_LM22(parameters);
                } else {

                  if (parameters.max_latency_of_same_last_50 <= 360608500) {
                    return new_order_LM23(parameters);
                  } else {
                    return new_order_LM24(parameters);
                  }
                }
              } else {
                return new_order_LM25(parameters);
              }
            }
          }
        } else {
          return new_order_LM26(parameters);
        }
      } else {

        if (parameters.work_so_far <= 47106) {
          return new_order_LM27(parameters);
        } else {

          if (parameters.total_wait_locks <= 102.5) {
            return new_order_LM28(parameters);
          } else {

            if (parameters.wait_so_far <= 1269.5) {

              if (parameters.num_locks_so_far <= 17.5) {

                if (parameters.avg_latency_of_same_last_20 <= 355773000) {
                  return new_order_LM29(parameters);
                } else {
                  return new_order_LM30(parameters);
                }
              } else {
                return new_order_LM31(parameters);
              }
            } else {

              if (parameters.num_locks_so_far <= 5.5) {
                return new_order_LM32(parameters);
              } else {
                return new_order_LM33(parameters);
              }
            }
          }
        }
      }
    } else {

      if (parameters.work_so_far <= 224978008.5) {

        if (parameters.num_locks_so_far <= 24.5) {
          return new_order_LM34(parameters);
        } else {

          if (parameters.mean_wait_of_all <= 38470750) {

            if (parameters.work_so_far <= 98488434) {
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
    }
  } else {

    if (parameters.work_so_far <= 1118224) {

      if (parameters.total_wait_locks <= 296.5) {

        if (parameters.wait_so_far <= 226224087.5) {
          return new_order_LM39(parameters);
        } else {
          return new_order_LM40(parameters);
        }
      } else {

        if (parameters.wait_so_far <= 91473672.5) {

          if (parameters.wait_so_far <= 203902) {

            if (parameters.wait_so_far <= 12759) {
              return new_order_LM41(parameters);
            } else {

              if (parameters.wait_so_far <= 27366.5) {
                return new_order_LM42(parameters);
              } else {
                return new_order_LM43(parameters);
              }
            }
          } else {

            if (parameters.work_so_far <= 49440) {

              if (parameters.avg_latency_of_same_last_20 <= 404759000) {

                if (parameters.avg_latency_of_same_last_20 <= 358353500) {
                  return new_order_LM44(parameters);
                } else {

                  if (parameters.cpu_usage <= 0.967) {
                    return new_order_LM45(parameters);
                  } else {
                    return new_order_LM46(parameters);
                  }
                }
              } else {

                if (parameters.avg_wait_of_same_past_second <= 289553000) {
                  return new_order_LM47(parameters);
                } else {
                  return new_order_LM48(parameters);
                }
              }
            } else {
              return new_order_LM49(parameters);
            }
          }
        } else {
          return new_order_LM50(parameters);
        }
      }
    } else {

      if (parameters.wait_so_far <= 295979229.5) {

        if (parameters.work_so_far <= 105759962.5) {

          if (parameters.num_locks_so_far <= 10.5) {

            if (parameters.work_so_far <= 9946486.5) {
              return new_order_LM51(parameters);
            } else {

              if (parameters.num_locks_so_far <= 9.5) {
                return new_order_LM52(parameters);
              } else {
                return new_order_LM53(parameters);
              }
            }
          } else {

            if (parameters.wait_so_far <= 54941956) {

              if (parameters.work_so_far <= 31051193) {
                return new_order_LM54(parameters);
              } else {

                if (parameters.num_locks_so_far <= 21.5) {

                  if (parameters.avg_work_of_same_past_second <= 222797000) {
                    return new_order_LM55(parameters);
                  } else {
                    return new_order_LM56(parameters);
                  }
                } else {

                  if (parameters.work_so_far <= 64708875) {
                    return new_order_LM57(parameters);
                  } else {

                    if (parameters.max_latency_of_same_last_50 <= 1375830000) {
                      return new_order_LM58(parameters);
                    } else {

                      if (parameters.num_locks_so_far <= 27.5) {
                        return new_order_LM59(parameters);
                      } else {
                        return new_order_LM60(parameters);
                      }
                    }
                  }
                }
              }
            } else {
              return new_order_LM61(parameters);
            }
          }
        } else {

          if (parameters.work_so_far <= 326644376.5) {

            if (parameters.num_locks_so_far <= 20.5) {
              return new_order_LM62(parameters);
            } else {
              return new_order_LM63(parameters);
            }
          } else {
            return new_order_LM64(parameters);
          }
        }
      } else {

        if (parameters.num_locks_so_far <= 5.5) {
          return new_order_LM65(parameters);
        } else {

          if (parameters.wait_so_far <= 698785877.5) {

            if (parameters.num_locks_so_far <= 11.5) {
              return new_order_LM66(parameters);
            } else {
              return new_order_LM67(parameters);
            }
          } else {
            return new_order_LM68(parameters);
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
	19.9723 * parameters.work_so_far 
	+ 0.0155 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	- 21521.3151 * parameters.total_wait_locks 
	+ 0.115 * parameters.mean_wait_of_all 
	- 178509.7542 * parameters.cpu_usage 
	- 0.0016 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.0024 * parameters.avg_latency_of_same_last_20 
	+ 2531554.7641;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM2(work_wait &parameters) {
  double actual_remaining = 
	19.9723 * parameters.work_so_far 
	+ 0.0625 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	- 99842.3397 * parameters.total_wait_locks 
	+ 0.161 * parameters.mean_wait_of_all 
	- 178509.7542 * parameters.cpu_usage 
	- 0.0016 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.1082 * parameters.avg_latency_of_same_last_20 
	+ 11789812.1496;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM3(work_wait &parameters) {
  double actual_remaining = 
	-13716.4809 * parameters.work_so_far 
	+ 0.0618 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	- 511413.4236 * parameters.total_wait_locks 
	+ 0.161 * parameters.mean_wait_of_all 
	- 178509.7542 * parameters.cpu_usage 
	- 0.0016 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.1064 * parameters.avg_latency_of_same_last_20 
	+ 159385216.1452;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM4(work_wait &parameters) {
  double actual_remaining = 
	19.9723 * parameters.work_so_far 
	+ 0.0015 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 133.523 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 178509.7542 * parameters.cpu_usage 
	- 0.0016 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.0009 * parameters.avg_latency_of_same_last_20 
	+ 6250418.1891;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM5(work_wait &parameters) {
  double actual_remaining = 
	23.705 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	- 206952.8332 * parameters.total_wait_locks 
	+ 0.7443 * parameters.mean_wait_of_all 
	- 17390.146 * parameters.cpu_usage 
	- 0.0024 * parameters.avg_work_of_same_past_second 
	+ 1.6954 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 7318026.5304;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM6(work_wait &parameters) {
  double actual_remaining = 
	23.705 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	- 1188.4041 * parameters.total_wait_locks 
	+ 0.0078 * parameters.mean_wait_of_all 
	- 17390.146 * parameters.cpu_usage 
	- 0.0024 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 16148114.8435;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM7(work_wait &parameters) {
  double actual_remaining = 
	31.6767 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 24257.8835 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 54270461.1564 * parameters.cpu_usage 
	- 0.0009 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0357 * parameters.avg_latency_of_same_last_20 
	- 0.0074 * parameters.max_latency_of_same_last_50 
	+ 60726418.4098;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM8(work_wait &parameters) {
  double actual_remaining = 
	33.9352 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 133.523 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 17390.146 * parameters.cpu_usage 
	- 0.005 * parameters.avg_work_of_same_past_second 
	+ 0.0687 * parameters.avg_wait_of_same_past_second 
	- 0.0045 * parameters.avg_latency_of_same_last_20 
	+ 0.056 * parameters.max_latency_of_same_last_50 
	+ 3510578.5722;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM9(work_wait &parameters) {
  double actual_remaining = 
	33.9352 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 133.523 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 17390.146 * parameters.cpu_usage 
	- 0.005 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.0016 * parameters.avg_latency_of_same_last_20 
	+ 0.0059 * parameters.max_latency_of_same_last_50 
	+ 12427491.7044;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM10(work_wait &parameters) {
  double actual_remaining = 
	33.9352 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 133.523 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 17390.146 * parameters.cpu_usage 
	- 0.0134 * parameters.avg_work_of_same_past_second 
	+ 0.021 * parameters.avg_wait_of_same_past_second 
	- 0.0014 * parameters.avg_latency_of_same_last_20 
	+ 0.0004 * parameters.max_latency_of_same_last_50 
	+ 6768535.9834;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM11(work_wait &parameters) {
  double actual_remaining = 
	32.6429 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 90623.7668 * parameters.total_wait_locks 
	- 0.3662 * parameters.mean_wait_of_all 
	- 17390.146 * parameters.cpu_usage 
	- 0.0009 * parameters.avg_work_of_same_past_second 
	- 0.031 * parameters.avg_wait_of_same_past_second 
	- 0.0193 * parameters.avg_latency_of_same_last_20 
	+ 29546114.2133;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM12(work_wait &parameters) {
  double actual_remaining = 
	32.6429 * parameters.work_so_far 
	+ 1.6676 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 4081.3778 * parameters.total_wait_locks 
	- 0.0268 * parameters.mean_wait_of_all 
	- 17390.146 * parameters.cpu_usage 
	- 0.2382 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 39134258.1194;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM13(work_wait &parameters) {
  double actual_remaining = 
	32.6429 * parameters.work_so_far 
	+ 0.3114 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 4081.3778 * parameters.total_wait_locks 
	- 0.0268 * parameters.mean_wait_of_all 
	- 17390.146 * parameters.cpu_usage 
	- 0.398 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 35243718.8237;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM14(work_wait &parameters) {
  double actual_remaining = 
	32.6429 * parameters.work_so_far 
	- 0.0013 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 83244.7678 * parameters.total_wait_locks 
	- 0.5444 * parameters.mean_wait_of_all 
	- 17390.146 * parameters.cpu_usage 
	- 0.0116 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 36915444.8315;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM15(work_wait &parameters) {
  double actual_remaining = 
	32.6429 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 133.523 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 17390.146 * parameters.cpu_usage 
	- 0.0155 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 19817929.6183;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM16(work_wait &parameters) {
  double actual_remaining = 
	-9.6978 * parameters.work_so_far 
	+ 0.0036 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 1373.0615 * parameters.total_wait_locks 
	+ 0.002 * parameters.mean_wait_of_all 
	+ 51852.2152 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0015 * parameters.avg_wait_of_same_past_second 
	+ 0.1175 * parameters.avg_latency_of_same_last_20 
	- 0.0599 * parameters.max_latency_of_same_last_50 
	+ 33979945.6455;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM17(work_wait &parameters) {
  double actual_remaining = 
	-9.6978 * parameters.work_so_far 
	+ 0.0209 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 1373.0615 * parameters.total_wait_locks 
	+ 0.002 * parameters.mean_wait_of_all 
	+ 51852.2152 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0015 * parameters.avg_wait_of_same_past_second 
	+ 0.0027 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	+ 18235833.3332;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM18(work_wait &parameters) {
  double actual_remaining = 
	10274.4869 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 948.5619 * parameters.total_wait_locks 
	+ 0.2411 * parameters.mean_wait_of_all 
	+ 51852.2152 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.5708 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 177236369.0987;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM19(work_wait &parameters) {
  double actual_remaining = 
	16366.3494 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 948.5619 * parameters.total_wait_locks 
	+ 0.2411 * parameters.mean_wait_of_all 
	+ 51852.2152 * parameters.cpu_usage 
	- 0.2958 * parameters.avg_work_of_same_past_second 
	- 0.5708 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 317125636.1475;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM20(work_wait &parameters) {
  double actual_remaining = 
	16366.3494 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 948.5619 * parameters.total_wait_locks 
	+ 0.2411 * parameters.mean_wait_of_all 
	+ 51852.2152 * parameters.cpu_usage 
	- 0.2395 * parameters.avg_work_of_same_past_second 
	- 0.5708 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 318396634.2879;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM21(work_wait &parameters) {
  double actual_remaining = 
	16941.9257 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 948.5619 * parameters.total_wait_locks 
	+ 0.2411 * parameters.mean_wait_of_all 
	+ 51852.2152 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.5708 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 315636361.6373;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM22(work_wait &parameters) {
  double actual_remaining = 
	-4953.1412 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 948.5619 * parameters.total_wait_locks 
	+ 0.2411 * parameters.mean_wait_of_all 
	+ 51852.2152 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.4276 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	+ 195392551.6851;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM23(work_wait &parameters) {
  double actual_remaining = 
	-233.6904 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 948.5619 * parameters.total_wait_locks 
	+ 0.1966 * parameters.mean_wait_of_all 
	+ 51852.2152 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.1195 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	+ 0.0449 * parameters.max_latency_of_same_last_50 
	- 9177477.1249;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM24(work_wait &parameters) {
  double actual_remaining = 
	-18.036 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 948.5619 * parameters.total_wait_locks 
	+ 0.0093 * parameters.mean_wait_of_all 
	+ 51852.2152 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0026 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	+ 27832686.4912;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM25(work_wait &parameters) {
  double actual_remaining = 
	186.0216 * parameters.work_so_far 
	+ 0.1072 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	- 985.7511 * parameters.total_wait_locks 
	+ 0.0076 * parameters.mean_wait_of_all 
	+ 270900.0023 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 15122530.6478;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM26(work_wait &parameters) {
  double actual_remaining = 
	2.5157 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	- 120929.7635 * parameters.total_wait_locks 
	+ 0.5373 * parameters.mean_wait_of_all 
	+ 270900.0023 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.018 * parameters.avg_latency_of_same_last_20 
	+ 12995525.5579;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM27(work_wait &parameters) {
  double actual_remaining = 
	0.0748 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 55846.138 * parameters.total_wait_locks 
	- 0.3508 * parameters.mean_wait_of_all 
	+ 3065065.0395 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0322 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 0.0047 * parameters.max_latency_of_same_last_50 
	+ 35354780.7179;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM28(work_wait &parameters) {
  double actual_remaining = 
	0.0748 * parameters.work_so_far 
	+ 0.0247 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	- 5280.8858 * parameters.total_wait_locks 
	+ 0.0056 * parameters.mean_wait_of_all 
	+ 1486275.1319 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0005 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 31305181.1495;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM29(work_wait &parameters) {
  double actual_remaining = 
	0.0748 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 121382.5185 * parameters.total_wait_locks 
	- 1.4083 * parameters.mean_wait_of_all 
	+ 1486275.1319 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_work_of_same_past_second 
	+ 0.1312 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 0.0006 * parameters.max_latency_of_same_last_50 
	+ 54052338.4038;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM30(work_wait &parameters) {
  double actual_remaining = 
	0.0748 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	- 275842.0759 * parameters.total_wait_locks 
	+ 0.6963 * parameters.mean_wait_of_all 
	+ 1486275.1319 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_work_of_same_past_second 
	+ 0.0081 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 0.0019 * parameters.max_latency_of_same_last_50 
	+ 71304022.1605;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM31(work_wait &parameters) {
  double actual_remaining = 
	0.0748 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	- 497360.8894 * parameters.total_wait_locks 
	+ 1.2151 * parameters.mean_wait_of_all 
	+ 1486275.1319 * parameters.cpu_usage 
	- 2.6078 * parameters.avg_work_of_same_past_second 
	+ 0.0081 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 0.1212 * parameters.max_latency_of_same_last_50 
	+ 82408412.3918;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM32(work_wait &parameters) {
  double actual_remaining = 
	0.0748 * parameters.work_so_far 
	+ 0.0129 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	- 497360.8894 * parameters.total_wait_locks 
	+ 1.2151 * parameters.mean_wait_of_all 
	- 414211735.9826 * parameters.cpu_usage 
	- 3.5353 * parameters.avg_work_of_same_past_second 
	+ 0.0081 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 0.0866 * parameters.max_latency_of_same_last_50 
	+ 577601250.351;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM33(work_wait &parameters) {
  double actual_remaining = 
	0.0748 * parameters.work_so_far 
	+ 0.0123 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	- 497360.8894 * parameters.total_wait_locks 
	+ 1.2151 * parameters.mean_wait_of_all 
	- 225977319.512 * parameters.cpu_usage 
	- 3.5353 * parameters.avg_work_of_same_past_second 
	+ 0.0081 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 0.0866 * parameters.max_latency_of_same_last_50 
	+ 392412819.8523;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM34(work_wait &parameters) {
  double actual_remaining = 
	0.0748 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	- 497360.8894 * parameters.total_wait_locks 
	+ 1.2151 * parameters.mean_wait_of_all 
	- 294216397.9052 * parameters.cpu_usage 
	- 3.9351 * parameters.avg_work_of_same_past_second 
	+ 0.0081 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 0.0866 * parameters.max_latency_of_same_last_50 
	+ 467789669.1072;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM35(work_wait &parameters) {
  double actual_remaining = 
	0.0748 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	- 675005.7527 * parameters.total_wait_locks 
	+ 1.2151 * parameters.mean_wait_of_all 
	+ 1486275.1319 * parameters.cpu_usage 
	- 1.9189 * parameters.avg_work_of_same_past_second 
	+ 0.0081 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 0.0019 * parameters.max_latency_of_same_last_50 
	+ 296559991.3739;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM36(work_wait &parameters) {
  double actual_remaining = 
	0.0748 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 145605.6382 * parameters.total_wait_locks 
	- 1.1247 * parameters.mean_wait_of_all 
	+ 1486275.1319 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0005 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 68930012.4011;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM37(work_wait &parameters) {
  double actual_remaining = 
	0.0748 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	- 108245.0904 * parameters.total_wait_locks 
	+ 0.5408 * parameters.mean_wait_of_all 
	+ 354166.6509 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0034 * parameters.avg_wait_of_same_past_second 
	+ 0.0743 * parameters.avg_latency_of_same_last_20 
	- 0.0192 * parameters.max_latency_of_same_last_50 
	+ 13280928.6534;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM38(work_wait &parameters) {
  double actual_remaining = 
	-9.3229 * parameters.work_so_far 
	- 0.0081 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 11670.566 * parameters.total_wait_locks 
	- 0.0458 * parameters.mean_wait_of_all 
	+ 354166.6509 * parameters.cpu_usage 
	+ 0.0208 * parameters.avg_work_of_same_past_second 
	- 0.0019 * parameters.avg_wait_of_same_past_second 
	+ 0.0014 * parameters.avg_latency_of_same_last_20 
	+ 0.0005 * parameters.max_latency_of_same_last_50 
	+ 21606074.2035;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM39(work_wait &parameters) {
  double actual_remaining = 
	-27.0423 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 490417.4371 * parameters.total_wait_locks 
	- 2.3387 * parameters.mean_wait_of_all 
	- 3400969.3125 * parameters.cpu_usage 
	+ 0.0196 * parameters.avg_work_of_same_past_second 
	- 0.0019 * parameters.avg_wait_of_same_past_second 
	- 0.0299 * parameters.avg_latency_of_same_last_20 
	+ 0.0035 * parameters.max_latency_of_same_last_50 
	+ 64479939.7851;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM40(work_wait &parameters) {
  double actual_remaining = 
	-27.0423 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 181886.8688 * parameters.total_wait_locks 
	- 0.9593 * parameters.mean_wait_of_all 
	- 3400969.3125 * parameters.cpu_usage 
	+ 0.0196 * parameters.avg_work_of_same_past_second 
	- 0.0019 * parameters.avg_wait_of_same_past_second 
	- 0.0979 * parameters.avg_latency_of_same_last_20 
	+ 0.008 * parameters.max_latency_of_same_last_50 
	+ 134003305.9729;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM41(work_wait &parameters) {
  double actual_remaining = 
	-27.0423 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 181886.8688 * parameters.total_wait_locks 
	- 2.948 * parameters.mean_wait_of_all 
	- 3400969.3125 * parameters.cpu_usage 
	+ 0.0196 * parameters.avg_work_of_same_past_second 
	- 0.0019 * parameters.avg_wait_of_same_past_second 
	- 0.0979 * parameters.avg_latency_of_same_last_20 
	+ 0.008 * parameters.max_latency_of_same_last_50 
	+ 315667220.1845;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM42(work_wait &parameters) {
  double actual_remaining = 
	-27.0423 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 181886.8688 * parameters.total_wait_locks 
	- 0.9593 * parameters.mean_wait_of_all 
	- 3400969.3125 * parameters.cpu_usage 
	+ 0.0196 * parameters.avg_work_of_same_past_second 
	- 0.0019 * parameters.avg_wait_of_same_past_second 
	- 0.0979 * parameters.avg_latency_of_same_last_20 
	+ 0.008 * parameters.max_latency_of_same_last_50 
	+ 138744477.5055;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM43(work_wait &parameters) {
  double actual_remaining = 
	-432.186 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 181886.8688 * parameters.total_wait_locks 
	- 0.9593 * parameters.mean_wait_of_all 
	- 35733062.5349 * parameters.cpu_usage 
	+ 0.0196 * parameters.avg_work_of_same_past_second 
	- 0.0019 * parameters.avg_wait_of_same_past_second 
	- 0.0648 * parameters.avg_latency_of_same_last_20 
	+ 0.008 * parameters.max_latency_of_same_last_50 
	+ 134444957.1878;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM44(work_wait &parameters) {
  double actual_remaining = 
	-131.1596 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 181886.8688 * parameters.total_wait_locks 
	- 0.9593 * parameters.mean_wait_of_all 
	- 24260384.2947 * parameters.cpu_usage 
	+ 0.0196 * parameters.avg_work_of_same_past_second 
	- 0.1782 * parameters.avg_wait_of_same_past_second 
	- 0.0648 * parameters.avg_latency_of_same_last_20 
	+ 0.008 * parameters.max_latency_of_same_last_50 
	+ 193896196.4179;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM45(work_wait &parameters) {
  double actual_remaining = 
	-27.0423 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 175655.1283 * parameters.total_wait_locks 
	- 0.8612 * parameters.mean_wait_of_all 
	- 3400969.3125 * parameters.cpu_usage 
	+ 0.0196 * parameters.avg_work_of_same_past_second 
	- 0.0019 * parameters.avg_wait_of_same_past_second 
	+ 0.0286 * parameters.avg_latency_of_same_last_20 
	+ 0.0075 * parameters.max_latency_of_same_last_50 
	+ 2335942.2121;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM46(work_wait &parameters) {
  double actual_remaining = 
	-27.0423 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 184984.715 * parameters.total_wait_locks 
	- 0.8612 * parameters.mean_wait_of_all 
	- 3400969.3125 * parameters.cpu_usage 
	+ 0.0196 * parameters.avg_work_of_same_past_second 
	- 0.0019 * parameters.avg_wait_of_same_past_second 
	+ 0.0061 * parameters.avg_latency_of_same_last_20 
	+ 0.0075 * parameters.max_latency_of_same_last_50 
	+ 21887590.9119;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM47(work_wait &parameters) {
  double actual_remaining = 
	-27.0423 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 235619.8643 * parameters.total_wait_locks 
	- 1.2081 * parameters.mean_wait_of_all 
	- 3400969.3125 * parameters.cpu_usage 
	+ 0.0196 * parameters.avg_work_of_same_past_second 
	- 0.0019 * parameters.avg_wait_of_same_past_second 
	+ 0.013 * parameters.avg_latency_of_same_last_20 
	+ 0.0206 * parameters.max_latency_of_same_last_50 
	- 578181.8207;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM48(work_wait &parameters) {
  double actual_remaining = 
	654.5111 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 235619.8643 * parameters.total_wait_locks 
	- 1.2081 * parameters.mean_wait_of_all 
	- 3400969.3125 * parameters.cpu_usage 
	+ 0.0196 * parameters.avg_work_of_same_past_second 
	- 0.0019 * parameters.avg_wait_of_same_past_second 
	+ 0.013 * parameters.avg_latency_of_same_last_20 
	+ 0.0237 * parameters.max_latency_of_same_last_50 
	- 24839573.6663;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM49(work_wait &parameters) {
  double actual_remaining = 
	-68.8214 * parameters.work_so_far 
	- 0.0117 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 131870.1336 * parameters.total_wait_locks 
	- 0.4351 * parameters.mean_wait_of_all 
	- 12006489.2285 * parameters.cpu_usage 
	+ 0.0196 * parameters.avg_work_of_same_past_second 
	- 0.0019 * parameters.avg_wait_of_same_past_second 
	+ 0.0014 * parameters.avg_latency_of_same_last_20 
	+ 0.0039 * parameters.max_latency_of_same_last_50 
	+ 15873967.7505;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM50(work_wait &parameters) {
  double actual_remaining = 
	9.3682 * parameters.work_so_far 
	- 0.1091 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	- 5570.4415 * parameters.total_wait_locks 
	+ 39.6833 * parameters.mean_wait_of_all 
	+ 1783878.3488 * parameters.cpu_usage 
	- 1.0884 * parameters.avg_work_of_same_past_second 
	- 0.5494 * parameters.avg_wait_of_same_past_second 
	+ 0.0108 * parameters.avg_latency_of_same_last_20 
	- 0.0032 * parameters.max_latency_of_same_last_50 
	- 4108823569.4685;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM51(work_wait &parameters) {
  double actual_remaining = 
	9.3682 * parameters.work_so_far 
	- 0.0174 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 203328.7317 * parameters.total_wait_locks 
	+ 77.308 * parameters.mean_wait_of_all 
	+ 1783878.3488 * parameters.cpu_usage 
	- 1.4416 * parameters.avg_work_of_same_past_second 
	+ 0.3395 * parameters.avg_wait_of_same_past_second 
	+ 0.0108 * parameters.avg_latency_of_same_last_20 
	- 0.0032 * parameters.max_latency_of_same_last_50 
	- 8932644018.4698;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM52(work_wait &parameters) {
  double actual_remaining = 
	9.3682 * parameters.work_so_far 
	- 0.0174 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 114948.3122 * parameters.total_wait_locks 
	+ 54.047 * parameters.mean_wait_of_all 
	+ 1783878.3488 * parameters.cpu_usage 
	- 1.1296 * parameters.avg_work_of_same_past_second 
	+ 0.0643 * parameters.avg_wait_of_same_past_second 
	+ 0.0108 * parameters.avg_latency_of_same_last_20 
	- 0.0032 * parameters.max_latency_of_same_last_50 
	- 6158475056.8884;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM53(work_wait &parameters) {
  double actual_remaining = 
	9.3682 * parameters.work_so_far 
	- 0.0155 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	- 28364.8797 * parameters.total_wait_locks 
	- 5.2451 * parameters.mean_wait_of_all 
	- 67347850.3647 * parameters.cpu_usage 
	- 0.0421 * parameters.avg_work_of_same_past_second 
	+ 0.0059 * parameters.avg_wait_of_same_past_second 
	+ 0.0033 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	+ 712576689.5014;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM54(work_wait &parameters) {
  double actual_remaining = 
	9.3682 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	- 47622.2499 * parameters.total_wait_locks 
	- 23.4187 * parameters.mean_wait_of_all 
	+ 9359677.8228 * parameters.cpu_usage 
	+ 2.0338 * parameters.avg_work_of_same_past_second 
	+ 0.0059 * parameters.avg_wait_of_same_past_second 
	+ 0.0156 * parameters.avg_latency_of_same_last_20 
	- 0.0053 * parameters.max_latency_of_same_last_50 
	+ 2731146831.7591;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM55(work_wait &parameters) {
  double actual_remaining = 
	9.3682 * parameters.work_so_far 
	- 0.081 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	- 1997084.777 * parameters.total_wait_locks 
	+ 1.2603 * parameters.mean_wait_of_all 
	+ 9359677.8228 * parameters.cpu_usage 
	- 12.5838 * parameters.avg_work_of_same_past_second 
	+ 0.0059 * parameters.avg_wait_of_same_past_second 
	+ 0.1425 * parameters.avg_latency_of_same_last_20 
	- 0.0106 * parameters.max_latency_of_same_last_50 
	+ 1298445572.4377;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM56(work_wait &parameters) {
  double actual_remaining = 
	7.9073 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	- 2820.7511 * parameters.total_wait_locks 
	- 0.0163 * parameters.mean_wait_of_all 
	+ 1459254.2455 * parameters.cpu_usage 
	- 0.0069 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	+ 0.0001 * parameters.max_latency_of_same_last_50 
	+ 24274910.2327;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM57(work_wait &parameters) {
  double actual_remaining = 
	8.4579 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	- 2920.4013 * parameters.total_wait_locks 
	- 0.0167 * parameters.mean_wait_of_all 
	+ 1555237.1168 * parameters.cpu_usage 
	- 0.0069 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	- 0.0183 * parameters.avg_latency_of_same_last_20 
	+ 0.012 * parameters.max_latency_of_same_last_50 
	+ 19478491.5837;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM58(work_wait &parameters) {
  double actual_remaining = 
	-17.3182 * parameters.work_so_far 
	+ 0.0007 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 85.0675 * parameters.total_wait_locks 
	+ 0.0006 * parameters.mean_wait_of_all 
	+ 695837.5803 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	+ 32740883.307;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM59(work_wait &parameters) {
  double actual_remaining = 
	86.5829 * parameters.work_so_far 
	+ 0.0456 * parameters.wait_so_far 
	+ 30776.5131 * parameters.num_locks_so_far 
	+ 85.0675 * parameters.total_wait_locks 
	+ 0.0006 * parameters.mean_wait_of_all 
	+ 1962863.7552 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0938 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	+ 35439375.7549;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM60(work_wait &parameters) {
  double actual_remaining = 
	0.0032 * parameters.work_so_far 
	+ 0.7624 * parameters.wait_so_far 
	+ 11497712.4444 * parameters.num_locks_so_far 
	+ 42483.9605 * parameters.total_wait_locks 
	- 0.0156 * parameters.max_latency_of_same_last_50 
	- 33323733.0593;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
payment_estimate(work_wait &parameters){

  if (parameters.work_so_far <= 750596) {

    if (parameters.work_so_far <= 23600.5) {

      if (parameters.work_so_far <= 8177.5) {

        if (parameters.avg_wait_of_same_past_second <= 18152750) {

          if (parameters.mean_wait_of_all <= 39174000) {
            return payment_LM1(parameters);
          } else {

            if (parameters.wait_so_far <= 6849358.5) {
              return payment_LM2(parameters);
            } else {
              return payment_LM3(parameters);
            }
          }
        } else {
          return payment_LM4(parameters);
        }
      } else {

        if (parameters.cpu_usage <= 0.912) {

          if (parameters.avg_wait_of_same_past_second <= 15448700) {
            return payment_LM5(parameters);
          } else {
            return payment_LM6(parameters);
          }
        } else {

          if (parameters.work_so_far <= 12402) {
            return payment_LM7(parameters);
          } else {

            if (parameters.work_so_far <= 18414) {

              if (parameters.avg_work_of_same_past_second <= 21913750) {

                if (parameters.avg_latency_of_same_last_20 <= 66129250) {
                  return payment_LM8(parameters);
                } else {
                  return payment_LM9(parameters);
                }
              } else {
                return payment_LM10(parameters);
              }
            } else {

              if (parameters.avg_work_of_same_past_second <= 20225050) {
                return payment_LM11(parameters);
              } else {

                if (parameters.avg_work_of_same_past_second <= 29291350) {

                  if (parameters.wait_so_far <= 13312223.5) {

                    if (parameters.avg_work_of_same_past_second <= 25771050) {
                      return payment_LM12(parameters);
                    } else {
                      return payment_LM13(parameters);
                    }
                  } else {
                    return payment_LM14(parameters);
                  }
                } else {
                  return payment_LM15(parameters);
                }
              }
            }
          }
        }
      }
    } else {

      if (parameters.work_so_far <= 64028) {

        if (parameters.mean_wait_of_all <= 113582000) {

          if (parameters.avg_work_of_same_past_second <= 20684550) {

            if (parameters.max_latency_of_same_last_50 <= 837042500) {

              if (parameters.cpu_usage <= 0.904) {
                return payment_LM16(parameters);
              } else {
                return payment_LM17(parameters);
              }
            } else {

              if (parameters.avg_wait_of_same_past_second <= 95772950) {

                if (parameters.work_so_far <= 29773) {

                  if (parameters.avg_wait_of_same_past_second <= 50959250) {

                    if (parameters.wait_so_far <= 2130510.5) {
                      return payment_LM18(parameters);
                    } else {

                      if (parameters.work_so_far <= 25852.5) {

                        if (parameters.avg_work_of_same_past_second <= 10296200) {
                          return payment_LM19(parameters);
                        } else {
                          return payment_LM20(parameters);
                        }
                      } else {
                        return payment_LM21(parameters);
                      }
                    }
                  } else {
                    return payment_LM22(parameters);
                  }
                } else {
                  return payment_LM23(parameters);
                }
              } else {
                return payment_LM24(parameters);
              }
            }
          } else {

            if (parameters.avg_latency_of_same_last_20 <= 528994000) {

              if (parameters.mean_wait_of_all <= 81294450) {

                if (parameters.wait_so_far <= 80549475.5) {
                  return payment_LM25(parameters);
                } else {
                  return payment_LM26(parameters);
                }
              } else {

                if (parameters.cpu_usage <= 0.956) {
                  return payment_LM27(parameters);
                } else {

                  if (parameters.avg_wait_of_same_past_second <= 360495500) {
                    return payment_LM28(parameters);
                  } else {

                    if (parameters.max_latency_of_same_last_50 <= 1352885000) {

                      if (parameters.max_latency_of_same_last_50 <= 1218085000) {
                        return payment_LM29(parameters);
                      } else {

                        if (parameters.mean_wait_of_all <= 103522500) {
                          return payment_LM30(parameters);
                        } else {

                          if (parameters.total_wait_locks <= 517.5) {

                            if (parameters.max_latency_of_same_last_50 <= 1273610000) {
                              return payment_LM31(parameters);
                            } else {

                              if (parameters.avg_work_of_same_past_second <= 33574400) {

                                if (parameters.wait_so_far <= 17629665.5) {
                                  return payment_LM32(parameters);
                                } else {
                                  return payment_LM33(parameters);
                                }
                              } else {
                                return payment_LM34(parameters);
                              }
                            }
                          } else {
                            return payment_LM35(parameters);
                          }
                        }
                      }
                    } else {
                      return payment_LM36(parameters);
                    }
                  }
                }
              }
            } else {

              if (parameters.avg_wait_of_same_past_second <= 391714000) {
                return payment_LM37(parameters);
              } else {

                if (parameters.avg_latency_of_same_last_20 <= 653160500) {
                  return payment_LM38(parameters);
                } else {

                  if (parameters.work_so_far <= 54158.5) {

                    if (parameters.avg_wait_of_same_past_second <= 452201000) {
                      return payment_LM39(parameters);
                    } else {

                      if (parameters.avg_wait_of_same_past_second <= 479177000) {

                        if (parameters.avg_latency_of_same_last_20 <= 709622500) {

                          if (parameters.wait_so_far <= 18252.5) {
                            return payment_LM40(parameters);
                          } else {

                            if (parameters.cpu_usage <= 0.848) {
                              return payment_LM41(parameters);
                            } else {
                              return payment_LM42(parameters);
                            }
                          }
                        } else {

                          if (parameters.cpu_usage <= 0.837) {
                            return payment_LM43(parameters);
                          } else {
                            return payment_LM44(parameters);
                          }
                        }
                      } else {

                        if (parameters.avg_latency_of_same_last_20 <= 973138000) {

                          if (parameters.total_wait_locks <= 505.5) {
                            return payment_LM45(parameters);
                          } else {
                            return payment_LM46(parameters);
                          }
                        } else {

                          if (parameters.max_latency_of_same_last_50 <= 2574180000) {
                            return payment_LM47(parameters);
                          } else {
                            return payment_LM48(parameters);
                          }
                        }
                      }
                    }
                  } else {
                    return payment_LM49(parameters);
                  }
                }
              }
            }
          }
        } else {

          if (parameters.mean_wait_of_all <= 117810500) {

            if (parameters.mean_wait_of_all <= 114337000) {

              if (parameters.avg_wait_of_same_past_second <= 374945500) {
                return payment_LM50(parameters);
              } else {

                if (parameters.avg_work_of_same_past_second <= 27258800) {
                  return payment_LM51(parameters);
                } else {
                  return payment_LM52(parameters);
                }
              }
            } else {

              if (parameters.mean_wait_of_all <= 116436500) {
                return payment_LM53(parameters);
              } else {

                if (parameters.mean_wait_of_all <= 117470500) {
                  return payment_LM54(parameters);
                } else {
                  return payment_LM55(parameters);
                }
              }
            }
          } else {

            if (parameters.work_so_far <= 32410) {
              return payment_LM56(parameters);
            } else {
              return payment_LM57(parameters);
            }
          }
        }
      } else {

        if (parameters.wait_so_far <= 278406075.5) {
          return payment_LM58(parameters);
        } else {
          return payment_LM59(parameters);
        }
      }
    }
  } else {
    return payment_LM60(parameters);
  }
}
static
double
delivery_LM1(work_wait &parameters) {
  double actual_remaining = 
	1.217 * parameters.work_so_far 
	+ 0.3881 * parameters.wait_so_far 
	- 2360609.448 * parameters.num_locks_so_far 
	+ 461825.3446 * parameters.total_wait_locks 
	+ 1.2574 * parameters.mean_wait_of_all 
	- 7996075.726 * parameters.cpu_usage 
	+ 0.0058 * parameters.avg_work_of_same_past_second 
	+ 0.4427 * parameters.avg_latency_of_same_last_20 
	+ 166919600.3261;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM2(work_wait &parameters) {
  double actual_remaining = 
	22.8845 * parameters.work_so_far 
	- 0.0145 * parameters.wait_so_far 
	- 79804.7923 * parameters.num_locks_so_far 
	+ 133732.6407 * parameters.total_wait_locks 
	+ 0.1815 * parameters.mean_wait_of_all 
	- 13331080.4315 * parameters.cpu_usage 
	+ 0.0879 * parameters.avg_work_of_same_past_second 
	+ 0.0059 * parameters.avg_latency_of_same_last_20 
	+ 546545082.7131;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM3(work_wait &parameters) {
  double actual_remaining = 
	22.8845 * parameters.work_so_far 
	- 0.0145 * parameters.wait_so_far 
	- 79804.7923 * parameters.num_locks_so_far 
	+ 65766.6688 * parameters.total_wait_locks 
	+ 0.1815 * parameters.mean_wait_of_all 
	+ 205645373.9019 * parameters.cpu_usage 
	+ 0.1069 * parameters.avg_work_of_same_past_second 
	+ 0.0059 * parameters.avg_latency_of_same_last_20 
	+ 447468588.6101;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM4(work_wait &parameters) {
  double actual_remaining = 
	-689.2107 * parameters.work_so_far 
	- 0.0145 * parameters.wait_so_far 
	- 79804.7923 * parameters.num_locks_so_far 
	+ 65766.6688 * parameters.total_wait_locks 
	+ 0.1815 * parameters.mean_wait_of_all 
	+ 446090108.0718 * parameters.cpu_usage 
	+ 0.1661 * parameters.avg_work_of_same_past_second 
	+ 0.0059 * parameters.avg_latency_of_same_last_20 
	+ 472541608.3809;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM5(work_wait &parameters) {
  double actual_remaining = 
	399.5171 * parameters.work_so_far 
	- 0.1359 * parameters.wait_so_far 
	- 79804.7923 * parameters.num_locks_so_far 
	- 771071.8147 * parameters.total_wait_locks 
	+ 5.7941 * parameters.mean_wait_of_all 
	- 13331080.4315 * parameters.cpu_usage 
	+ 0.0169 * parameters.avg_work_of_same_past_second 
	+ 0.4402 * parameters.avg_wait_of_same_past_second 
	+ 0.0059 * parameters.avg_latency_of_same_last_20 
	+ 205275412.4175;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM6(work_wait &parameters) {
  double actual_remaining = 
	0.9018 * parameters.work_so_far 
	+ 0.1179 * parameters.wait_so_far 
	- 6748643.3675 * parameters.num_locks_so_far 
	+ 10641.4465 * parameters.total_wait_locks 
	+ 0.7252 * parameters.mean_wait_of_all 
	- 12562625.541 * parameters.cpu_usage 
	+ 0.1699 * parameters.avg_work_of_same_past_second 
	+ 0.1059 * parameters.avg_latency_of_same_last_20 
	+ 660963547.5506;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM7(work_wait &parameters) {
  double actual_remaining = 
	1.1216 * parameters.work_so_far 
	+ 0.5767 * parameters.wait_so_far 
	- 242809.3902 * parameters.num_locks_so_far 
	+ 1167326.5477 * parameters.total_wait_locks 
	- 2.6865 * parameters.mean_wait_of_all 
	- 1428210343.9847 * parameters.cpu_usage 
	+ 0.0112 * parameters.avg_work_of_same_past_second 
	+ 0.5033 * parameters.avg_wait_of_same_past_second 
	+ 0.0101 * parameters.avg_latency_of_same_last_20 
	+ 1714299059.7951;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
delivery_estimate(work_wait &parameters){

  if (parameters.total_wait_locks <= 140) {
    return delivery_LM1(parameters);
  } else {

    if (parameters.work_so_far <= 717002) {

      if (parameters.wait_so_far <= 93536) {

        if (parameters.total_wait_locks <= 282.5) {
          return delivery_LM2(parameters);
        } else {

          if (parameters.wait_so_far <= 1956.5) {
            return delivery_LM3(parameters);
          } else {
            return delivery_LM4(parameters);
          }
        }
      } else {
        return delivery_LM5(parameters);
      }
    } else {

      if (parameters.wait_so_far <= 558806457.5) {
        return delivery_LM6(parameters);
      } else {
        return delivery_LM7(parameters);
      }
    }
  }
}
static
double
stock_level_LM1(work_wait &parameters) {
  double actual_remaining = 
	0.6763 * parameters.work_so_far 
	- 0.0693 * parameters.wait_so_far 
	- 62880.8681 * parameters.num_locks_so_far 
	+ 11611404.8355;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
stock_level_LM2(work_wait &parameters) {
  double actual_remaining = 
	1.8746 * parameters.work_so_far 
	+ 0.5091 * parameters.wait_so_far 
	- 4.3234 * parameters.avg_work_of_same_past_second 
	+ 179086876.8595;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
stock_level_LM3(work_wait &parameters) {
  double actual_remaining = 
	1.5274 * parameters.work_so_far 
	- 0.2288 * parameters.wait_so_far 
	- 2.2025 * parameters.avg_work_of_same_past_second 
	+ 99407572.6229;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
stock_level_estimate(work_wait &parameters){

  if (parameters.work_so_far <= 5515289) {
    return stock_level_LM1(parameters);
  } else {

    if (parameters.wait_so_far <= 46113771) {
      return stock_level_LM2(parameters);
    } else {
      return stock_level_LM3(parameters);
    }
  }
}
static
double
tpcc_LM1(work_wait &parameters) {
  double actual_remaining = 
	0.1076 * parameters.work_so_far 
	- 0.1133 * parameters.wait_so_far 
	+ 180638.1584 * parameters.num_locks_so_far 
	+ 158908.4926 * parameters.total_wait_locks 
	+ 0.5025 * parameters.mean_wait_of_all 
	- 169044619.8953 * parameters.cpu_usage 
	+ 1.9306 * parameters.avg_work_of_same_past_second 
	- 1.3987 * parameters.avg_wait_of_same_past_second 
	+ 0.203 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 138640812.3502;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM2(work_wait &parameters) {
  double actual_remaining = 
	28.5928 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 371151.1434 * parameters.num_locks_so_far 
	+ 868.3556 * parameters.total_wait_locks 
	- 0.0005 * parameters.mean_wait_of_all 
	- 451258.5223 * parameters.cpu_usage 
	+ 0.007 * parameters.avg_work_of_same_past_second 
	- 0.0012 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 7882700.2341;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM3(work_wait &parameters) {
  double actual_remaining = 
	67.0269 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 371151.1434 * parameters.num_locks_so_far 
	+ 12460.7492 * parameters.total_wait_locks 
	- 0.0005 * parameters.mean_wait_of_all 
	- 22196514.0732 * parameters.cpu_usage 
	+ 0.0888 * parameters.avg_work_of_same_past_second 
	- 0.0022 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 32047497.3942;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM4(work_wait &parameters) {
  double actual_remaining = 
	67.0269 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 371151.1434 * parameters.num_locks_so_far 
	+ 7423.7332 * parameters.total_wait_locks 
	- 0.2939 * parameters.mean_wait_of_all 
	- 50912781.7039 * parameters.cpu_usage 
	+ 0.1823 * parameters.avg_work_of_same_past_second 
	- 0.0022 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 83980626.2548;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM5(work_wait &parameters) {
  double actual_remaining = 
	67.0269 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 371151.1434 * parameters.num_locks_so_far 
	+ 7423.7332 * parameters.total_wait_locks 
	- 0.0143 * parameters.mean_wait_of_all 
	- 50912781.7039 * parameters.cpu_usage 
	+ 0.1823 * parameters.avg_work_of_same_past_second 
	- 0.0022 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 62974195.9582;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM6(work_wait &parameters) {
  double actual_remaining = 
	67.0269 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 371151.1434 * parameters.num_locks_so_far 
	+ 7423.7332 * parameters.total_wait_locks 
	+ 0.4897 * parameters.mean_wait_of_all 
	- 50912781.7039 * parameters.cpu_usage 
	+ 0.1823 * parameters.avg_work_of_same_past_second 
	- 0.0022 * parameters.avg_wait_of_same_past_second 
	- 0.92 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 117758025.401;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM7(work_wait &parameters) {
  double actual_remaining = 
	67.0269 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 371151.1434 * parameters.num_locks_so_far 
	+ 7423.7332 * parameters.total_wait_locks 
	- 0.0005 * parameters.mean_wait_of_all 
	+ 20490922.4826 * parameters.cpu_usage 
	- 0.0167 * parameters.avg_work_of_same_past_second 
	- 0.0022 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 9877255.2776;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM8(work_wait &parameters) {
  double actual_remaining = 
	67.0269 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 371151.1434 * parameters.num_locks_so_far 
	+ 7423.7332 * parameters.total_wait_locks 
	- 0.0005 * parameters.mean_wait_of_all 
	- 6447791.2552 * parameters.cpu_usage 
	+ 0.0552 * parameters.avg_work_of_same_past_second 
	- 0.0022 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 22085349.558;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM9(work_wait &parameters) {
  double actual_remaining = 
	75.9445 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	+ 371151.1434 * parameters.num_locks_so_far 
	+ 933.2068 * parameters.total_wait_locks 
	- 0.0005 * parameters.mean_wait_of_all 
	- 203323.5417 * parameters.cpu_usage 
	+ 0.0076 * parameters.avg_work_of_same_past_second 
	- 0.0016 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 11397822.2952;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM10(work_wait &parameters) {
  double actual_remaining = 
	66.9067 * parameters.work_so_far 
	- 0.0098 * parameters.wait_so_far 
	+ 371151.1434 * parameters.num_locks_so_far 
	+ 933.2068 * parameters.total_wait_locks 
	- 0.0005 * parameters.mean_wait_of_all 
	- 203323.5417 * parameters.cpu_usage 
	+ 0.0076 * parameters.avg_work_of_same_past_second 
	- 0.0143 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 24778623.8656;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM11(work_wait &parameters) {
  double actual_remaining = 
	-383.3778 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 52780995.9226 * parameters.num_locks_so_far 
	+ 499.8483 * parameters.total_wait_locks 
	+ 0.0073 * parameters.mean_wait_of_all 
	+ 1312560.4162 * parameters.cpu_usage 
	- 0.425 * parameters.avg_work_of_same_past_second 
	- 0.0016 * parameters.avg_wait_of_same_past_second 
	+ 0.05 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 75369233.901;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM12(work_wait &parameters) {
  double actual_remaining = 
	0.7305 * parameters.work_so_far 
	- 0.0065 * parameters.wait_so_far 
	+ 825547.23 * parameters.num_locks_so_far 
	- 34182.9298 * parameters.total_wait_locks 
	+ 0.1701 * parameters.mean_wait_of_all 
	+ 879283.6969 * parameters.cpu_usage 
	+ 0.0035 * parameters.avg_work_of_same_past_second 
	- 0.0011 * parameters.avg_wait_of_same_past_second 
	+ 0.024 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 12421879.0048;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM13(work_wait &parameters) {
  double actual_remaining = 
	-27.2039 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 825547.23 * parameters.num_locks_so_far 
	- 4092.591 * parameters.total_wait_locks 
	+ 0.0363 * parameters.mean_wait_of_all 
	+ 1965139.9671 * parameters.cpu_usage 
	+ 0.0035 * parameters.avg_work_of_same_past_second 
	+ 0.0123 * parameters.avg_wait_of_same_past_second 
	+ 0.0041 * parameters.avg_latency_of_same_last_20 
	- 0.0115 * parameters.max_latency_of_same_last_50 
	+ 34919580.8777;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM14(work_wait &parameters) {
  double actual_remaining = 
	-407.0689 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 825547.23 * parameters.num_locks_so_far 
	- 13046.2386 * parameters.total_wait_locks 
	+ 0.0906 * parameters.mean_wait_of_all 
	+ 1965139.9671 * parameters.cpu_usage 
	+ 0.0035 * parameters.avg_work_of_same_past_second 
	+ 0.0427 * parameters.avg_wait_of_same_past_second 
	+ 0.0287 * parameters.avg_latency_of_same_last_20 
	- 0.0024 * parameters.max_latency_of_same_last_50 
	+ 19249876.0956;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM15(work_wait &parameters) {
  double actual_remaining = 
	-3513.1379 * parameters.work_so_far 
	- 0.0624 * parameters.wait_so_far 
	+ 825547.23 * parameters.num_locks_so_far 
	- 13046.2386 * parameters.total_wait_locks 
	+ 0.0906 * parameters.mean_wait_of_all 
	+ 1965139.9671 * parameters.cpu_usage 
	- 3.1723 * parameters.avg_work_of_same_past_second 
	+ 0.0427 * parameters.avg_wait_of_same_past_second 
	+ 0.0519 * parameters.avg_latency_of_same_last_20 
	- 0.0024 * parameters.max_latency_of_same_last_50 
	+ 246039380.9914;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM16(work_wait &parameters) {
  double actual_remaining = 
	0.7305 * parameters.work_so_far 
	- 0.0062 * parameters.wait_so_far 
	+ 513836.2812 * parameters.num_locks_so_far 
	+ 183.9691 * parameters.total_wait_locks 
	+ 0.0024 * parameters.mean_wait_of_all 
	+ 69530084.673 * parameters.cpu_usage 
	+ 0.0035 * parameters.avg_work_of_same_past_second 
	+ 0.0263 * parameters.avg_wait_of_same_past_second 
	+ 0.0005 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 56498229.6648;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM17(work_wait &parameters) {
  double actual_remaining = 
	0.7305 * parameters.work_so_far 
	+ 0.0006 * parameters.wait_so_far 
	+ 513836.2812 * parameters.num_locks_so_far 
	- 91504.2255 * parameters.total_wait_locks 
	+ 0.4656 * parameters.mean_wait_of_all 
	+ 223403.7392 * parameters.cpu_usage 
	+ 0.0035 * parameters.avg_work_of_same_past_second 
	- 0.0057 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.2276 * parameters.max_latency_of_same_last_50 
	+ 320841632.1084;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM18(work_wait &parameters) {
  double actual_remaining = 
	0.7305 * parameters.work_so_far 
	+ 0.0006 * parameters.wait_so_far 
	+ 513836.2812 * parameters.num_locks_so_far 
	- 159947.3694 * parameters.total_wait_locks 
	+ 0.7433 * parameters.mean_wait_of_all 
	+ 223403.7392 * parameters.cpu_usage 
	+ 0.0035 * parameters.avg_work_of_same_past_second 
	- 0.0057 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0918 * parameters.max_latency_of_same_last_50 
	+ 138776455.5703;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM19(work_wait &parameters) {
  double actual_remaining = 
	-1039.5618 * parameters.work_so_far 
	+ 0.0006 * parameters.wait_so_far 
	+ 513836.2812 * parameters.num_locks_so_far 
	- 15217.708 * parameters.total_wait_locks 
	+ 0.4404 * parameters.mean_wait_of_all 
	+ 223403.7392 * parameters.cpu_usage 
	+ 0.0035 * parameters.avg_work_of_same_past_second 
	- 0.1849 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 121369718.6892;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM20(work_wait &parameters) {
  double actual_remaining = 
	0.7305 * parameters.work_so_far 
	+ 0.0006 * parameters.wait_so_far 
	+ 513836.2812 * parameters.num_locks_so_far 
	+ 17077.8045 * parameters.total_wait_locks 
	+ 0.4404 * parameters.mean_wait_of_all 
	+ 223403.7392 * parameters.cpu_usage 
	+ 0.0035 * parameters.avg_work_of_same_past_second 
	- 0.6706 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 330938757.6426;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM21(work_wait &parameters) {
  double actual_remaining = 
	0.7305 * parameters.work_so_far 
	- 0.0074 * parameters.wait_so_far 
	+ 513836.2812 * parameters.num_locks_so_far 
	- 3654.7995 * parameters.total_wait_locks 
	+ 0.0264 * parameters.mean_wait_of_all 
	+ 223403.7392 * parameters.cpu_usage 
	+ 0.0035 * parameters.avg_work_of_same_past_second 
	- 0.0309 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 36127732.1544;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM22(work_wait &parameters) {
  double actual_remaining = 
	0.7305 * parameters.work_so_far 
	+ 0.0006 * parameters.wait_so_far 
	+ 513836.2812 * parameters.num_locks_so_far 
	- 2688.6293 * parameters.total_wait_locks 
	+ 0.0195 * parameters.mean_wait_of_all 
	+ 223403.7392 * parameters.cpu_usage 
	+ 0.2268 * parameters.avg_work_of_same_past_second 
	- 0.0019 * parameters.avg_wait_of_same_past_second 
	- 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 13314500.4779;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM23(work_wait &parameters) {
  double actual_remaining = 
	0.7305 * parameters.work_so_far 
	+ 0.0006 * parameters.wait_so_far 
	+ 513836.2812 * parameters.num_locks_so_far 
	- 40891.9199 * parameters.total_wait_locks 
	+ 0.0195 * parameters.mean_wait_of_all 
	+ 51376640.023 * parameters.cpu_usage 
	+ 0.0035 * parameters.avg_work_of_same_past_second 
	- 0.0019 * parameters.avg_wait_of_same_past_second 
	- 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 3482505.9076;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM24(work_wait &parameters) {
  double actual_remaining = 
	0.7305 * parameters.work_so_far 
	+ 0.1251 * parameters.wait_so_far 
	+ 513836.2812 * parameters.num_locks_so_far 
	- 40891.9199 * parameters.total_wait_locks 
	+ 0.0195 * parameters.mean_wait_of_all 
	+ 55311504.3525 * parameters.cpu_usage 
	+ 2.0417 * parameters.avg_work_of_same_past_second 
	- 0.0019 * parameters.avg_wait_of_same_past_second 
	- 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 54662701.4866;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM25(work_wait &parameters) {
  double actual_remaining = 
	0.7305 * parameters.work_so_far 
	+ 0.0006 * parameters.wait_so_far 
	+ 513836.2812 * parameters.num_locks_so_far 
	- 39624.0799 * parameters.total_wait_locks 
	+ 0.0195 * parameters.mean_wait_of_all 
	+ 223403.7392 * parameters.cpu_usage 
	+ 0.6261 * parameters.avg_work_of_same_past_second 
	- 0.0019 * parameters.avg_wait_of_same_past_second 
	- 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 22153625.0074;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM26(work_wait &parameters) {
  double actual_remaining = 
	0.7305 * parameters.work_so_far 
	+ 0.0006 * parameters.wait_so_far 
	+ 513836.2812 * parameters.num_locks_so_far 
	- 21149.4927 * parameters.total_wait_locks 
	+ 0.0195 * parameters.mean_wait_of_all 
	+ 223403.7392 * parameters.cpu_usage 
	+ 0.0035 * parameters.avg_work_of_same_past_second 
	- 0.0019 * parameters.avg_wait_of_same_past_second 
	- 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 27198945.2322;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM27(work_wait &parameters) {
  double actual_remaining = 
	0.7305 * parameters.work_so_far 
	+ 0.0006 * parameters.wait_so_far 
	+ 513836.2812 * parameters.num_locks_so_far 
	+ 242.138 * parameters.total_wait_locks 
	+ 0.002 * parameters.mean_wait_of_all 
	- 73788682.2366 * parameters.cpu_usage 
	+ 0.0035 * parameters.avg_work_of_same_past_second 
	- 0.0009 * parameters.avg_wait_of_same_past_second 
	- 0.0461 * parameters.avg_latency_of_same_last_20 
	+ 0.0103 * parameters.max_latency_of_same_last_50 
	+ 117360099.9285;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM28(work_wait &parameters) {
  double actual_remaining = 
	161.2593 * parameters.work_so_far 
	- 0.1256 * parameters.wait_so_far 
	+ 531774.8697 * parameters.num_locks_so_far 
	- 5043.7529 * parameters.total_wait_locks 
	- 1.732 * parameters.mean_wait_of_all 
	+ 1978730.2686 * parameters.cpu_usage 
	- 0.5864 * parameters.avg_work_of_same_past_second 
	- 0.7703 * parameters.avg_wait_of_same_past_second 
	+ 0.0098 * parameters.avg_latency_of_same_last_20 
	- 0.0035 * parameters.max_latency_of_same_last_50 
	+ 674618591.8033;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM29(work_wait &parameters) {
  double actual_remaining = 
	161.2593 * parameters.work_so_far 
	- 0.0183 * parameters.wait_so_far 
	+ 531774.8697 * parameters.num_locks_so_far 
	+ 440526.624 * parameters.total_wait_locks 
	- 1.732 * parameters.mean_wait_of_all 
	+ 1978730.2686 * parameters.cpu_usage 
	- 0.5242 * parameters.avg_work_of_same_past_second 
	- 0.4216 * parameters.avg_wait_of_same_past_second 
	+ 0.0098 * parameters.avg_latency_of_same_last_20 
	- 0.0035 * parameters.max_latency_of_same_last_50 
	+ 197323735.2481;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM30(work_wait &parameters) {
  double actual_remaining = 
	161.2593 * parameters.work_so_far 
	- 0.0183 * parameters.wait_so_far 
	+ 531774.8697 * parameters.num_locks_so_far 
	- 5043.7529 * parameters.total_wait_locks 
	- 1.732 * parameters.mean_wait_of_all 
	+ 1978730.2686 * parameters.cpu_usage 
	- 0.4812 * parameters.avg_work_of_same_past_second 
	- 0.4216 * parameters.avg_wait_of_same_past_second 
	+ 0.0098 * parameters.avg_latency_of_same_last_20 
	- 0.0035 * parameters.max_latency_of_same_last_50 
	+ 414535150.295;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM31(work_wait &parameters) {
  double actual_remaining = 
	62.074 * parameters.work_so_far 
	- 0.0126 * parameters.wait_so_far 
	+ 531774.8697 * parameters.num_locks_so_far 
	- 31113.824 * parameters.total_wait_locks 
	+ 0.2271 * parameters.mean_wait_of_all 
	+ 7913775.7445 * parameters.cpu_usage 
	- 0.0571 * parameters.avg_work_of_same_past_second 
	+ 0.0052 * parameters.avg_wait_of_same_past_second 
	+ 0.0031 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	+ 9183956.4198;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM32(work_wait &parameters) {
  double actual_remaining = 
	62.074 * parameters.work_so_far 
	+ 0.0006 * parameters.wait_so_far 
	+ 531774.8697 * parameters.num_locks_so_far 
	- 450513.2098 * parameters.total_wait_locks 
	+ 20.9734 * parameters.mean_wait_of_all 
	+ 130866969.6561 * parameters.cpu_usage 
	- 1.6224 * parameters.avg_work_of_same_past_second 
	- 0.304 * parameters.avg_wait_of_same_past_second 
	+ 0.0355 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	- 2145282145.4963;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM33(work_wait &parameters) {
  double actual_remaining = 
	62.074 * parameters.work_so_far 
	+ 0.0006 * parameters.wait_so_far 
	+ 531774.8697 * parameters.num_locks_so_far 
	- 54897.0467 * parameters.total_wait_locks 
	+ 23.3852 * parameters.mean_wait_of_all 
	+ 82441917.672 * parameters.cpu_usage 
	- 0.8047 * parameters.avg_work_of_same_past_second 
	+ 0.0052 * parameters.avg_wait_of_same_past_second 
	+ 0.0234 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	- 2726182544.1614;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM34(work_wait &parameters) {
  double actual_remaining = 
	62.074 * parameters.work_so_far 
	+ 0.0006 * parameters.wait_so_far 
	+ 531774.8697 * parameters.num_locks_so_far 
	- 54897.0467 * parameters.total_wait_locks 
	+ 34.8417 * parameters.mean_wait_of_all 
	+ 82441917.672 * parameters.cpu_usage 
	- 0.8047 * parameters.avg_work_of_same_past_second 
	+ 0.0052 * parameters.avg_wait_of_same_past_second 
	+ 0.0584 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	- 4060245420.2521;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM35(work_wait &parameters) {
  double actual_remaining = 
	62.074 * parameters.work_so_far 
	+ 0.0006 * parameters.wait_so_far 
	+ 531774.8697 * parameters.num_locks_so_far 
	- 54897.0467 * parameters.total_wait_locks 
	+ 11.4983 * parameters.mean_wait_of_all 
	+ 59695048.1649 * parameters.cpu_usage 
	- 0.0571 * parameters.avg_work_of_same_past_second 
	+ 0.0052 * parameters.avg_wait_of_same_past_second 
	+ 0.0202 * parameters.avg_latency_of_same_last_20 
	+ 0.0153 * parameters.max_latency_of_same_last_50 
	- 1369489122.7047;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM36(work_wait &parameters) {
  double actual_remaining = 
	359.7602 * parameters.work_so_far 
	- 0.0054 * parameters.wait_so_far 
	+ 531774.8697 * parameters.num_locks_so_far 
	- 60824.9178 * parameters.total_wait_locks 
	- 0.3828 * parameters.mean_wait_of_all 
	+ 27924864.4139 * parameters.cpu_usage 
	- 0.3271 * parameters.avg_work_of_same_past_second 
	- 0.0251 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.0052 * parameters.max_latency_of_same_last_50 
	+ 81110206.4809;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM37(work_wait &parameters) {
  double actual_remaining = 
	0.1718 * parameters.work_so_far 
	+ 0.0163 * parameters.wait_so_far 
	+ 92485.5564 * parameters.num_locks_so_far 
	+ 14779.9462 * parameters.total_wait_locks 
	- 0.0005 * parameters.mean_wait_of_all 
	+ 43700241.8123 * parameters.cpu_usage 
	+ 0.1932 * parameters.avg_work_of_same_past_second 
	- 0.0272 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 14794668.1132;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM38(work_wait &parameters) {
  double actual_remaining = 
	0.0444 * parameters.work_so_far 
	+ 1107.4442 * parameters.wait_so_far 
	- 5040.4543 * parameters.num_locks_so_far 
	+ 15482.9908 * parameters.total_wait_locks 
	- 0.0436 * parameters.mean_wait_of_all 
	- 2637946.9959 * parameters.cpu_usage 
	+ 0.2372 * parameters.avg_work_of_same_past_second 
	- 0.0459 * parameters.avg_wait_of_same_past_second 
	+ 0.0017 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 21459660.6158;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM39(work_wait &parameters) {
  double actual_remaining = 
	0.3028 * parameters.work_so_far 
	- 10773.9643 * parameters.wait_so_far 
	- 5040.4543 * parameters.num_locks_so_far 
	+ 387413.8008 * parameters.total_wait_locks 
	- 0.1384 * parameters.mean_wait_of_all 
	- 2637946.9959 * parameters.cpu_usage 
	+ 6.0371 * parameters.avg_work_of_same_past_second 
	- 0.6091 * parameters.avg_wait_of_same_past_second 
	+ 0.0017 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	- 12424085.4265;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM40(work_wait &parameters) {
  double actual_remaining = 
	0.0383 * parameters.work_so_far 
	+ 2372.3905 * parameters.wait_so_far 
	- 5040.4543 * parameters.num_locks_so_far 
	+ 27419.5944 * parameters.total_wait_locks 
	- 0.0686 * parameters.mean_wait_of_all 
	- 2637946.9959 * parameters.cpu_usage 
	+ 0.382 * parameters.avg_work_of_same_past_second 
	- 0.0323 * parameters.avg_wait_of_same_past_second 
	+ 0.0017 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 9169387.3985;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM41(work_wait &parameters) {
  double actual_remaining = 
	0.0294 * parameters.work_so_far 
	+ 0.0168 * parameters.wait_so_far 
	- 5040.4543 * parameters.num_locks_so_far 
	+ 5934.0012 * parameters.total_wait_locks 
	- 0.0209 * parameters.mean_wait_of_all 
	+ 786261.1102 * parameters.cpu_usage 
	+ 0.0545 * parameters.avg_work_of_same_past_second 
	- 0.0032 * parameters.avg_wait_of_same_past_second 
	+ 0.0038 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	+ 22216516.5588;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM42(work_wait &parameters) {
  double actual_remaining = 
	0.0272 * parameters.work_so_far 
	+ 0.0168 * parameters.wait_so_far 
	- 5040.4543 * parameters.num_locks_so_far 
	+ 5386.0754 * parameters.total_wait_locks 
	- 0.0182 * parameters.mean_wait_of_all 
	+ 64540390.9705 * parameters.cpu_usage 
	+ 0.0488 * parameters.avg_work_of_same_past_second 
	- 0.0032 * parameters.avg_wait_of_same_past_second 
	+ 0.048 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	- 46187915.6469;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM43(work_wait &parameters) {
  double actual_remaining = 
	0.0234 * parameters.work_so_far 
	+ 0.0176 * parameters.wait_so_far 
	- 5040.4543 * parameters.num_locks_so_far 
	+ 4430.3623 * parameters.total_wait_locks 
	- 0.0134 * parameters.mean_wait_of_all 
	- 2637946.9959 * parameters.cpu_usage 
	+ 0.0376 * parameters.avg_work_of_same_past_second 
	- 0.0031 * parameters.avg_wait_of_same_past_second 
	+ 0.0019 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 45425310.497;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM44(work_wait &parameters) {
  double actual_remaining = 
	0.0197 * parameters.work_so_far 
	+ 0.046 * parameters.wait_so_far 
	- 5040.4543 * parameters.num_locks_so_far 
	+ 70852.0434 * parameters.total_wait_locks 
	+ 0.0291 * parameters.mean_wait_of_all 
	- 2637946.9959 * parameters.cpu_usage 
	- 0.0546 * parameters.avg_work_of_same_past_second 
	- 0.0033 * parameters.avg_wait_of_same_past_second 
	+ 0.0012 * parameters.avg_latency_of_same_last_20 
	- 0.0024 * parameters.max_latency_of_same_last_50 
	+ 42574257.1472;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM45(work_wait &parameters) {
  double actual_remaining = 
	0.0197 * parameters.work_so_far 
	+ 0.1569 * parameters.wait_so_far 
	- 5040.4543 * parameters.num_locks_so_far 
	+ 3508.7065 * parameters.total_wait_locks 
	+ 0.066 * parameters.mean_wait_of_all 
	- 2637946.9959 * parameters.cpu_usage 
	+ 0.2778 * parameters.avg_work_of_same_past_second 
	- 0.0033 * parameters.avg_wait_of_same_past_second 
	+ 0.0012 * parameters.avg_latency_of_same_last_20 
	- 0.0073 * parameters.max_latency_of_same_last_50 
	+ 74771856.5234;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM46(work_wait &parameters) {
  double actual_remaining = 
	0.0197 * parameters.work_so_far 
	- 1.141 * parameters.wait_so_far 
	- 5040.4543 * parameters.num_locks_so_far 
	+ 3508.7065 * parameters.total_wait_locks 
	+ 0.066 * parameters.mean_wait_of_all 
	- 2637946.9959 * parameters.cpu_usage 
	+ 1.1333 * parameters.avg_work_of_same_past_second 
	- 0.0033 * parameters.avg_wait_of_same_past_second 
	+ 0.2191 * parameters.avg_latency_of_same_last_20 
	- 0.0073 * parameters.max_latency_of_same_last_50 
	+ 467112732.8738;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM47(work_wait &parameters) {
  double actual_remaining = 
	0.0197 * parameters.work_so_far 
	- 0.8879 * parameters.wait_so_far 
	- 5040.4543 * parameters.num_locks_so_far 
	+ 3508.7065 * parameters.total_wait_locks 
	+ 0.066 * parameters.mean_wait_of_all 
	- 2637946.9959 * parameters.cpu_usage 
	+ 1.1333 * parameters.avg_work_of_same_past_second 
	- 0.0033 * parameters.avg_wait_of_same_past_second 
	+ 0.2191 * parameters.avg_latency_of_same_last_20 
	- 0.0073 * parameters.max_latency_of_same_last_50 
	+ 362176399.967;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM48(work_wait &parameters) {
  double actual_remaining = 
	0.0197 * parameters.work_so_far 
	+ 0.3143 * parameters.wait_so_far 
	- 5040.4543 * parameters.num_locks_so_far 
	+ 3508.7065 * parameters.total_wait_locks 
	+ 0.066 * parameters.mean_wait_of_all 
	- 2637946.9959 * parameters.cpu_usage 
	+ 1.1333 * parameters.avg_work_of_same_past_second 
	- 0.0033 * parameters.avg_wait_of_same_past_second 
	+ 0.185 * parameters.avg_latency_of_same_last_20 
	- 0.0073 * parameters.max_latency_of_same_last_50 
	+ 34745035.6649;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM49(work_wait &parameters) {
  double actual_remaining = 
	0.0197 * parameters.work_so_far 
	+ 0.0936 * parameters.wait_so_far 
	- 5040.4543 * parameters.num_locks_so_far 
	- 47019.5792 * parameters.total_wait_locks 
	+ 0.3643 * parameters.mean_wait_of_all 
	+ 49740214.1014 * parameters.cpu_usage 
	- 0.2186 * parameters.avg_work_of_same_past_second 
	- 0.0033 * parameters.avg_wait_of_same_past_second 
	+ 0.0012 * parameters.avg_latency_of_same_last_20 
	- 0.0246 * parameters.max_latency_of_same_last_50 
	+ 51270011.6178;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM50(work_wait &parameters) {
  double actual_remaining = 
	0.0197 * parameters.work_so_far 
	+ 0.0936 * parameters.wait_so_far 
	- 5040.4543 * parameters.num_locks_so_far 
	- 49545.9934 * parameters.total_wait_locks 
	+ 0.3782 * parameters.mean_wait_of_all 
	+ 52359122.1562 * parameters.cpu_usage 
	- 0.2186 * parameters.avg_work_of_same_past_second 
	- 0.0033 * parameters.avg_wait_of_same_past_second 
	+ 0.0012 * parameters.avg_latency_of_same_last_20 
	- 0.0253 * parameters.max_latency_of_same_last_50 
	+ 9526541.4729;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM51(work_wait &parameters) {
  double actual_remaining = 
	2.5599 * parameters.work_so_far 
	+ 1.0231 * parameters.wait_so_far 
	- 5748727.2861 * parameters.num_locks_so_far 
	+ 601459.8953 * parameters.total_wait_locks 
	- 0.0498 * parameters.mean_wait_of_all 
	- 429171620.7919 * parameters.cpu_usage 
	+ 2.1157 * parameters.avg_work_of_same_past_second 
	- 4.1879 * parameters.avg_wait_of_same_past_second 
	+ 0.4646 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 446201022.2902;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM52(work_wait &parameters) {
  double actual_remaining = 
	1.8741 * parameters.work_so_far 
	+ 0.9138 * parameters.wait_so_far 
	- 1534969.9804 * parameters.num_locks_so_far 
	- 315.1232 * parameters.total_wait_locks 
	- 0.0497 * parameters.mean_wait_of_all 
	- 33810540.5733 * parameters.cpu_usage 
	+ 0.264 * parameters.avg_work_of_same_past_second 
	- 0.0364 * parameters.avg_wait_of_same_past_second 
	+ 0.0073 * parameters.avg_latency_of_same_last_20 
	+ 0.0127 * parameters.max_latency_of_same_last_50 
	+ 44206152.699;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM53(work_wait &parameters) {
  double actual_remaining = 
	1.9304 * parameters.work_so_far 
	+ 0.2622 * parameters.wait_so_far 
	- 882866.817 * parameters.num_locks_so_far 
	+ 85949.1519 * parameters.total_wait_locks 
	- 0.0794 * parameters.mean_wait_of_all 
	- 187501436.1187 * parameters.cpu_usage 
	+ 2.4115 * parameters.avg_work_of_same_past_second 
	- 0.0985 * parameters.avg_wait_of_same_past_second 
	+ 0.0073 * parameters.avg_latency_of_same_last_20 
	- 0.0151 * parameters.max_latency_of_same_last_50 
	+ 115280712.6456;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM54(work_wait &parameters) {
  double actual_remaining = 
	-6.4106 * parameters.work_so_far 
	+ 0.2622 * parameters.wait_so_far 
	- 882866.817 * parameters.num_locks_so_far 
	+ 156602.0277 * parameters.total_wait_locks 
	- 0.0794 * parameters.mean_wait_of_all 
	- 187501436.1187 * parameters.cpu_usage 
	+ 0.9926 * parameters.avg_work_of_same_past_second 
	- 0.1572 * parameters.avg_wait_of_same_past_second 
	+ 0.0073 * parameters.avg_latency_of_same_last_20 
	- 0.0324 * parameters.max_latency_of_same_last_50 
	+ 702495357.8756;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM55(work_wait &parameters) {
  double actual_remaining = 
	-3.2144 * parameters.work_so_far 
	+ 0.2622 * parameters.wait_so_far 
	- 882866.817 * parameters.num_locks_so_far 
	+ 156602.0277 * parameters.total_wait_locks 
	- 0.0794 * parameters.mean_wait_of_all 
	- 187501436.1187 * parameters.cpu_usage 
	+ 0.9926 * parameters.avg_work_of_same_past_second 
	- 0.1572 * parameters.avg_wait_of_same_past_second 
	+ 0.0073 * parameters.avg_latency_of_same_last_20 
	- 0.0324 * parameters.max_latency_of_same_last_50 
	+ 529535719.0625;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM56(work_wait &parameters) {
  double actual_remaining = 
	2.3084 * parameters.work_so_far 
	+ 0.2622 * parameters.wait_so_far 
	- 882866.817 * parameters.num_locks_so_far 
	+ 25041.5004 * parameters.total_wait_locks 
	- 0.0794 * parameters.mean_wait_of_all 
	- 363241062.5637 * parameters.cpu_usage 
	+ 1.6948 * parameters.avg_work_of_same_past_second 
	- 0.0478 * parameters.avg_wait_of_same_past_second 
	+ 0.0073 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 288202917.2428;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM57(work_wait &parameters) {
  double actual_remaining = 
	1.2864 * parameters.work_so_far 
	+ 0.9625 * parameters.wait_so_far 
	- 404983.9849 * parameters.num_locks_so_far 
	+ 16478.3301 * parameters.total_wait_locks 
	- 0.0373 * parameters.mean_wait_of_all 
	- 26732983.8411 * parameters.cpu_usage 
	+ 0.4215 * parameters.avg_work_of_same_past_second 
	- 0.0345 * parameters.avg_wait_of_same_past_second 
	+ 0.0073 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 33092220.2361;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM58(work_wait &parameters) {
  double actual_remaining = 
	1.9697 * parameters.work_so_far 
	+ 0.7702 * parameters.wait_so_far 
	- 801907.9937 * parameters.num_locks_so_far 
	+ 133202.0512 * parameters.total_wait_locks 
	- 0.4008 * parameters.mean_wait_of_all 
	- 384922893.4914 * parameters.cpu_usage 
	+ 1.1203 * parameters.avg_work_of_same_past_second 
	- 0.0155 * parameters.avg_wait_of_same_past_second 
	+ 0.0744 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 343637348.9184;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM59(work_wait &parameters) {
  double actual_remaining = 
	0.9836 * parameters.work_so_far 
	+ 0.0386 * parameters.wait_so_far 
	- 4195046.4445 * parameters.num_locks_so_far 
	+ 643822.0698 * parameters.total_wait_locks 
	- 0.0315 * parameters.mean_wait_of_all 
	- 249813589.3057 * parameters.cpu_usage 
	+ 0.0737 * parameters.avg_work_of_same_past_second 
	- 1.1114 * parameters.avg_wait_of_same_past_second 
	+ 0.0048 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 497015125.1439;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM60(work_wait &parameters) {
  double actual_remaining = 
	-0.185 * parameters.work_so_far 
	+ 0.759 * parameters.wait_so_far 
	+ 427693.0277 * parameters.num_locks_so_far 
	+ 16619.2114 * parameters.total_wait_locks 
	- 0.007 * parameters.mean_wait_of_all 
	- 2665407.3911 * parameters.cpu_usage 
	+ 0.0336 * parameters.avg_work_of_same_past_second 
	- 0.0033 * parameters.avg_wait_of_same_past_second 
	- 0.0023 * parameters.avg_latency_of_same_last_20 
	- 0.0059 * parameters.max_latency_of_same_last_50 
	- 45871938.2915;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM61(work_wait &parameters) {
  double actual_remaining = 
	-0.1629 * parameters.work_so_far 
	+ 0.2097 * parameters.wait_so_far 
	+ 427693.0277 * parameters.num_locks_so_far 
	+ 71700.8607 * parameters.total_wait_locks 
	- 0.007 * parameters.mean_wait_of_all 
	- 2665407.3911 * parameters.cpu_usage 
	+ 0.0336 * parameters.avg_work_of_same_past_second 
	- 0.3501 * parameters.avg_wait_of_same_past_second 
	- 0.0023 * parameters.avg_latency_of_same_last_20 
	- 0.0245 * parameters.max_latency_of_same_last_50 
	+ 111683952.9125;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM62(work_wait &parameters) {
  double actual_remaining = 
	-0.1629 * parameters.work_so_far 
	+ 0.6163 * parameters.wait_so_far 
	+ 427693.0277 * parameters.num_locks_so_far 
	+ 37419.2156 * parameters.total_wait_locks 
	- 0.007 * parameters.mean_wait_of_all 
	- 2665407.3911 * parameters.cpu_usage 
	+ 0.0336 * parameters.avg_work_of_same_past_second 
	- 0.0033 * parameters.avg_wait_of_same_past_second 
	- 0.0023 * parameters.avg_latency_of_same_last_20 
	- 0.1097 * parameters.max_latency_of_same_last_50 
	+ 30516932.4267;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM63(work_wait &parameters) {
  double actual_remaining = 
	-0.4264 * parameters.work_so_far 
	+ 0.9213 * parameters.wait_so_far 
	+ 123045.1023 * parameters.num_locks_so_far 
	+ 2980.3611 * parameters.total_wait_locks 
	- 0.007 * parameters.mean_wait_of_all 
	- 2665407.3911 * parameters.cpu_usage 
	- 0.1901 * parameters.avg_work_of_same_past_second 
	+ 0.0128 * parameters.avg_wait_of_same_past_second 
	- 0.0023 * parameters.avg_latency_of_same_last_20 
	- 0.0018 * parameters.max_latency_of_same_last_50 
	+ 36248638.0432;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM64(work_wait &parameters) {
  double actual_remaining = 
	-1.2816 * parameters.work_so_far 
	+ 0.6628 * parameters.wait_so_far 
	+ 123045.1023 * parameters.num_locks_so_far 
	+ 2980.3611 * parameters.total_wait_locks 
	- 0.007 * parameters.mean_wait_of_all 
	- 2665407.3911 * parameters.cpu_usage 
	- 0.1901 * parameters.avg_work_of_same_past_second 
	+ 0.0128 * parameters.avg_wait_of_same_past_second 
	- 0.0023 * parameters.avg_latency_of_same_last_20 
	- 0.0018 * parameters.max_latency_of_same_last_50 
	+ 157418905.4918;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM65(work_wait &parameters) {
  double actual_remaining = 
	-1.8018 * parameters.work_so_far 
	+ 0.475 * parameters.wait_so_far 
	+ 123045.1023 * parameters.num_locks_so_far 
	+ 2980.3611 * parameters.total_wait_locks 
	- 0.007 * parameters.mean_wait_of_all 
	- 2665407.3911 * parameters.cpu_usage 
	- 0.1901 * parameters.avg_work_of_same_past_second 
	+ 0.0128 * parameters.avg_wait_of_same_past_second 
	- 0.0023 * parameters.avg_latency_of_same_last_20 
	- 0.0018 * parameters.max_latency_of_same_last_50 
	+ 248552961.1601;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM66(work_wait &parameters) {
  double actual_remaining = 
	-1.8165 * parameters.work_so_far 
	+ 0.475 * parameters.wait_so_far 
	+ 123045.1023 * parameters.num_locks_so_far 
	+ 2980.3611 * parameters.total_wait_locks 
	- 0.007 * parameters.mean_wait_of_all 
	- 2665407.3911 * parameters.cpu_usage 
	- 0.1901 * parameters.avg_work_of_same_past_second 
	+ 0.0128 * parameters.avg_wait_of_same_past_second 
	- 0.0023 * parameters.avg_latency_of_same_last_20 
	- 0.0018 * parameters.max_latency_of_same_last_50 
	+ 242702138.11;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM67(work_wait &parameters) {
  double actual_remaining = 
	-1.4995 * parameters.work_so_far 
	+ 0.861 * parameters.wait_so_far 
	+ 119285.1247 * parameters.num_locks_so_far 
	+ 2980.3611 * parameters.total_wait_locks 
	- 0.007 * parameters.mean_wait_of_all 
	- 2665407.3911 * parameters.cpu_usage 
	- 0.1924 * parameters.avg_work_of_same_past_second 
	+ 0.0645 * parameters.avg_wait_of_same_past_second 
	- 0.0023 * parameters.avg_latency_of_same_last_20 
	- 0.0018 * parameters.max_latency_of_same_last_50 
	+ 68220319.3682;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM68(work_wait &parameters) {
  double actual_remaining = 
	0.7477 * parameters.work_so_far 
	+ 0.9929 * parameters.wait_so_far 
	+ 258713.5669 * parameters.num_locks_so_far 
	+ 2980.3611 * parameters.total_wait_locks 
	- 0.007 * parameters.mean_wait_of_all 
	- 2665407.3911 * parameters.cpu_usage 
	- 0.1241 * parameters.avg_work_of_same_past_second 
	+ 0.0082 * parameters.avg_wait_of_same_past_second 
	+ 0.0256 * parameters.avg_latency_of_same_last_20 
	- 0.0018 * parameters.max_latency_of_same_last_50 
	- 12298423.0432;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM69(work_wait &parameters) {
  double actual_remaining = 
	-0.042 * parameters.work_so_far 
	+ 0.8701 * parameters.wait_so_far 
	+ 22495112.0899 * parameters.num_locks_so_far 
	+ 2980.3611 * parameters.total_wait_locks 
	- 0.007 * parameters.mean_wait_of_all 
	+ 670132715.3797 * parameters.cpu_usage 
	+ 0.0336 * parameters.avg_work_of_same_past_second 
	- 0.0033 * parameters.avg_wait_of_same_past_second 
	- 0.0063 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	- 769016646.3811;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM70(work_wait &parameters) {
  double actual_remaining = 
	99.9608 * parameters.work_so_far 
	- 0.2468 * parameters.wait_so_far 
	- 29182549.0659 * parameters.num_locks_so_far 
	+ 691029.807 * parameters.total_wait_locks 
	- 0.0023 * parameters.mean_wait_of_all 
	+ 125107170.9418 * parameters.cpu_usage 
	+ 0.3943 * parameters.avg_work_of_same_past_second 
	- 0.5856 * parameters.avg_wait_of_same_past_second 
	+ 0.1225 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 75644784.4664;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM71(work_wait &parameters) {
  double actual_remaining = 
	0.0047 * parameters.work_so_far 
	- 0.2724 * parameters.wait_so_far 
	- 51535815.2331 * parameters.num_locks_so_far 
	- 1389689.9174 * parameters.total_wait_locks 
	+ 8.1486 * parameters.mean_wait_of_all 
	+ 614513.3832 * parameters.cpu_usage 
	- 0.3207 * parameters.avg_work_of_same_past_second 
	- 0.0029 * parameters.avg_wait_of_same_past_second 
	+ 0.2385 * parameters.avg_latency_of_same_last_20 
	- 0.0702 * parameters.max_latency_of_same_last_50 
	+ 491565741.3107;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM72(work_wait &parameters) {
  double actual_remaining = 
	3.3371 * parameters.work_so_far 
	+ 0.5376 * parameters.wait_so_far 
	- 4535123.7317 * parameters.num_locks_so_far 
	+ 367247.0602 * parameters.total_wait_locks 
	- 0.7985 * parameters.mean_wait_of_all 
	+ 712715.3778 * parameters.cpu_usage 
	+ 0.3342 * parameters.avg_work_of_same_past_second 
	- 0.0056 * parameters.avg_wait_of_same_past_second 
	+ 0.1705 * parameters.avg_latency_of_same_last_20 
	- 0.0442 * parameters.max_latency_of_same_last_50 
	+ 214470701.6421;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM73(work_wait &parameters) {
  double actual_remaining = 
	2.4589 * parameters.work_so_far 
	+ 1.1656 * parameters.wait_so_far 
	- 4611607.3931 * parameters.num_locks_so_far 
	+ 138176.1241 * parameters.total_wait_locks 
	- 0.2527 * parameters.mean_wait_of_all 
	+ 128059122.0595 * parameters.cpu_usage 
	+ 0.4608 * parameters.avg_work_of_same_past_second 
	- 0.4345 * parameters.avg_wait_of_same_past_second 
	+ 0.1664 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	+ 3574941.7091;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM74(work_wait &parameters) {
  double actual_remaining = 
	0.1119 * parameters.work_so_far 
	+ 0.0757 * parameters.wait_so_far 
	+ 2919587.9766 * parameters.num_locks_so_far 
	- 193776.0735 * parameters.total_wait_locks 
	+ 3.3697 * parameters.mean_wait_of_all 
	- 4649147.2628 * parameters.cpu_usage 
	- 0.1346 * parameters.avg_work_of_same_past_second 
	- 0.0967 * parameters.avg_wait_of_same_past_second 
	+ 0.1391 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 327777275.6025;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM75(work_wait &parameters) {
  double actual_remaining = 
	0.1119 * parameters.work_so_far 
	+ 0.0757 * parameters.wait_so_far 
	+ 2308665.1551 * parameters.num_locks_so_far 
	+ 64670.526 * parameters.total_wait_locks 
	+ 1.6807 * parameters.mean_wait_of_all 
	- 4649147.2628 * parameters.cpu_usage 
	- 1.2761 * parameters.avg_work_of_same_past_second 
	- 0.0967 * parameters.avg_wait_of_same_past_second 
	+ 0.2436 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 617636682.1741;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM76(work_wait &parameters) {
  double actual_remaining = 
	0.1119 * parameters.work_so_far 
	+ 4.4979 * parameters.wait_so_far 
	+ 2308665.1551 * parameters.num_locks_so_far 
	- 31429.0719 * parameters.total_wait_locks 
	+ 1.6807 * parameters.mean_wait_of_all 
	- 4649147.2628 * parameters.cpu_usage 
	- 0.6461 * parameters.avg_work_of_same_past_second 
	- 0.0967 * parameters.avg_wait_of_same_past_second 
	+ 0.3305 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 650924417.3209;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM77(work_wait &parameters) {
  double actual_remaining = 
	0.1119 * parameters.work_so_far 
	+ 4.4979 * parameters.wait_so_far 
	+ 2308665.1551 * parameters.num_locks_so_far 
	- 31429.0719 * parameters.total_wait_locks 
	+ 1.6807 * parameters.mean_wait_of_all 
	- 4649147.2628 * parameters.cpu_usage 
	- 0.6461 * parameters.avg_work_of_same_past_second 
	- 0.0967 * parameters.avg_wait_of_same_past_second 
	+ 0.3384 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 652453271.7784;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM78(work_wait &parameters) {
  double actual_remaining = 
	0.1119 * parameters.work_so_far 
	+ 2.7558 * parameters.wait_so_far 
	+ 2308665.1551 * parameters.num_locks_so_far 
	- 31429.0719 * parameters.total_wait_locks 
	+ 1.6807 * parameters.mean_wait_of_all 
	- 4649147.2628 * parameters.cpu_usage 
	- 0.6461 * parameters.avg_work_of_same_past_second 
	- 0.0967 * parameters.avg_wait_of_same_past_second 
	+ 0.1962 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 670536518.5266;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM79(work_wait &parameters) {
  double actual_remaining = 
	0.1119 * parameters.work_so_far 
	+ 2.7558 * parameters.wait_so_far 
	+ 2308665.1551 * parameters.num_locks_so_far 
	- 31429.0719 * parameters.total_wait_locks 
	+ 1.6807 * parameters.mean_wait_of_all 
	- 4649147.2628 * parameters.cpu_usage 
	- 0.6461 * parameters.avg_work_of_same_past_second 
	- 0.0967 * parameters.avg_wait_of_same_past_second 
	+ 0.2887 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 620873833.7629;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM80(work_wait &parameters) {
  double actual_remaining = 
	0.1119 * parameters.work_so_far 
	+ 0.5179 * parameters.wait_so_far 
	+ 2308665.1551 * parameters.num_locks_so_far 
	- 31429.0719 * parameters.total_wait_locks 
	+ 1.6807 * parameters.mean_wait_of_all 
	- 4649147.2628 * parameters.cpu_usage 
	- 0.4953 * parameters.avg_work_of_same_past_second 
	- 0.4945 * parameters.avg_wait_of_same_past_second 
	+ 0.1962 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 645219810.8022;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM81(work_wait &parameters) {
  double actual_remaining = 
	0.1119 * parameters.work_so_far 
	+ 0.0757 * parameters.wait_so_far 
	- 2475476.8425 * parameters.num_locks_so_far 
	- 35647.1169 * parameters.total_wait_locks 
	+ 0.4417 * parameters.mean_wait_of_all 
	+ 408139683.5625 * parameters.cpu_usage 
	+ 1.811 * parameters.avg_work_of_same_past_second 
	- 1.3267 * parameters.avg_wait_of_same_past_second 
	+ 0.0631 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	- 55266537.0069;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM82(work_wait &parameters) {
  double actual_remaining = 
	0.8951 * parameters.work_so_far 
	+ 0.8392 * parameters.wait_so_far 
	- 369728.1959 * parameters.num_locks_so_far 
	+ 402040.0574 * parameters.total_wait_locks 
	- 1.1302 * parameters.mean_wait_of_all 
	- 266347272.6632 * parameters.cpu_usage 
	+ 0.3661 * parameters.avg_work_of_same_past_second 
	- 0.3835 * parameters.avg_wait_of_same_past_second 
	+ 0.006 * parameters.avg_latency_of_same_last_20 
	+ 0.0325 * parameters.max_latency_of_same_last_50 
	+ 410340227.8878;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM83(work_wait &parameters) {
  double actual_remaining = 
	0.1875 * parameters.work_so_far 
	+ 0.1199 * parameters.wait_so_far 
	- 9587650.8753 * parameters.num_locks_so_far 
	+ 868680.0438 * parameters.total_wait_locks 
	- 3.5298 * parameters.mean_wait_of_all 
	- 16780649.6996 * parameters.cpu_usage 
	+ 1.5932 * parameters.avg_work_of_same_past_second 
	- 0.2696 * parameters.avg_wait_of_same_past_second 
	- 0.5684 * parameters.avg_latency_of_same_last_20 
	+ 0.2314 * parameters.max_latency_of_same_last_50 
	+ 901570996.0819;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM84(work_wait &parameters) {
  double actual_remaining = 
	1.8353 * parameters.work_so_far 
	+ 0.1622 * parameters.wait_so_far 
	+ 5159661.0076 * parameters.num_locks_so_far 
	- 67375.5436 * parameters.total_wait_locks 
	+ 0.4506 * parameters.mean_wait_of_all 
	- 16780649.6996 * parameters.cpu_usage 
	+ 0.6001 * parameters.avg_work_of_same_past_second 
	+ 0.0719 * parameters.avg_wait_of_same_past_second 
	- 0.3593 * parameters.avg_latency_of_same_last_20 
	+ 0.0445 * parameters.max_latency_of_same_last_50 
	+ 183568332.481;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM85(work_wait &parameters) {
  double actual_remaining = 
	1.8353 * parameters.work_so_far 
	+ 0.1622 * parameters.wait_so_far 
	+ 4248139.6158 * parameters.num_locks_so_far 
	- 67375.5436 * parameters.total_wait_locks 
	+ 0.4506 * parameters.mean_wait_of_all 
	- 16780649.6996 * parameters.cpu_usage 
	+ 0.5456 * parameters.avg_work_of_same_past_second 
	+ 0.0719 * parameters.avg_wait_of_same_past_second 
	- 0.3448 * parameters.avg_latency_of_same_last_20 
	+ 0.0445 * parameters.max_latency_of_same_last_50 
	+ 226158781.6935;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM86(work_wait &parameters) {
  double actual_remaining = 
	2.359 * parameters.work_so_far 
	+ 0.1622 * parameters.wait_so_far 
	+ 4170212.7164 * parameters.num_locks_so_far 
	- 67375.5436 * parameters.total_wait_locks 
	+ 0.4506 * parameters.mean_wait_of_all 
	- 16780649.6996 * parameters.cpu_usage 
	+ 0.2459 * parameters.avg_work_of_same_past_second 
	+ 0.0719 * parameters.avg_wait_of_same_past_second 
	- 0.3791 * parameters.avg_latency_of_same_last_20 
	+ 0.0746 * parameters.max_latency_of_same_last_50 
	+ 156764301.0038;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM87(work_wait &parameters) {
  double actual_remaining = 
	1.4022 * parameters.work_so_far 
	+ 0.1622 * parameters.wait_so_far 
	- 17197530.5968 * parameters.num_locks_so_far 
	- 516127.515 * parameters.total_wait_locks 
	+ 3.1386 * parameters.mean_wait_of_all 
	- 16780649.6996 * parameters.cpu_usage 
	+ 0.2459 * parameters.avg_work_of_same_past_second 
	+ 0.0065 * parameters.avg_wait_of_same_past_second 
	- 0.0475 * parameters.avg_latency_of_same_last_20 
	- 0.0082 * parameters.max_latency_of_same_last_50 
	+ 460831574.1393;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM88(work_wait &parameters) {
  double actual_remaining = 
	0.6736 * parameters.work_so_far 
	+ 0.8639 * parameters.wait_so_far 
	- 1412095.6285 * parameters.num_locks_so_far 
	- 375163.9628 * parameters.total_wait_locks 
	+ 2.4026 * parameters.mean_wait_of_all 
	- 16780649.6996 * parameters.cpu_usage 
	+ 0.1844 * parameters.avg_work_of_same_past_second 
	- 0.1435 * parameters.avg_wait_of_same_past_second 
	- 0.0027 * parameters.avg_latency_of_same_last_20 
	+ 0.0391 * parameters.max_latency_of_same_last_50 
	+ 264527359.4374;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM89(work_wait &parameters) {
  double actual_remaining = 
	0.5368 * parameters.work_so_far 
	+ 0.0771 * parameters.wait_so_far 
	- 6186680.6336 * parameters.num_locks_so_far 
	- 767763.3021 * parameters.total_wait_locks 
	+ 6.1824 * parameters.mean_wait_of_all 
	- 39596523.6295 * parameters.cpu_usage 
	+ 0.1775 * parameters.avg_work_of_same_past_second 
	- 1.3911 * parameters.avg_wait_of_same_past_second 
	+ 0.0027 * parameters.avg_latency_of_same_last_20 
	+ 0.1217 * parameters.max_latency_of_same_last_50 
	+ 633563473.4731;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM90(work_wait &parameters) {
  double actual_remaining = 
	0.0424 * parameters.work_so_far 
	- 0.1955 * parameters.wait_so_far 
	+ 103472.4994 * parameters.num_locks_so_far 
	+ 154232.9967 * parameters.total_wait_locks 
	+ 0.0512 * parameters.mean_wait_of_all 
	+ 9506677.5913 * parameters.cpu_usage 
	+ 0.6234 * parameters.avg_work_of_same_past_second 
	- 0.025 * parameters.avg_wait_of_same_past_second 
	+ 0.2237 * parameters.avg_latency_of_same_last_20 
	- 0.0019 * parameters.max_latency_of_same_last_50 
	+ 73523227.6104;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM91(work_wait &parameters) {
  double actual_remaining = 
	0.5906 * parameters.work_so_far 
	+ 0.7483 * parameters.wait_so_far 
	+ 59125773.6634 * parameters.num_locks_so_far 
	- 83542.7155 * parameters.total_wait_locks 
	+ 0.7947 * parameters.mean_wait_of_all 
	+ 3702355.0044 * parameters.cpu_usage 
	+ 0.0073 * parameters.avg_work_of_same_past_second 
	- 0.0185 * parameters.avg_wait_of_same_past_second 
	+ 0.0065 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	- 185590906.8074;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM92(work_wait &parameters) {
  double actual_remaining = 
	2.236 * parameters.work_so_far 
	- 0.4885 * parameters.wait_so_far 
	+ 3592214.3631 * parameters.num_locks_so_far 
	- 1769616.2306 * parameters.total_wait_locks 
	+ 4.7407 * parameters.mean_wait_of_all 
	+ 3702355.0044 * parameters.cpu_usage 
	- 1.2665 * parameters.avg_work_of_same_past_second 
	- 0.1795 * parameters.avg_wait_of_same_past_second 
	+ 0.0065 * parameters.avg_latency_of_same_last_20 
	- 0.0228 * parameters.max_latency_of_same_last_50 
	+ 1608743886.3875;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM93(work_wait &parameters) {
  double actual_remaining = 
	4.554 * parameters.work_so_far 
	- 0.3551 * parameters.wait_so_far 
	+ 3592214.3631 * parameters.num_locks_so_far 
	- 1692861.1266 * parameters.total_wait_locks 
	+ 4.7407 * parameters.mean_wait_of_all 
	+ 3702355.0044 * parameters.cpu_usage 
	- 1.2665 * parameters.avg_work_of_same_past_second 
	- 0.1795 * parameters.avg_wait_of_same_past_second 
	+ 0.0065 * parameters.avg_latency_of_same_last_20 
	- 0.0228 * parameters.max_latency_of_same_last_50 
	+ 1432358358.6615;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM94(work_wait &parameters) {
  double actual_remaining = 
	1.5724 * parameters.work_so_far 
	+ 0.2245 * parameters.wait_so_far 
	+ 3592214.3631 * parameters.num_locks_so_far 
	- 438666.6257 * parameters.total_wait_locks 
	+ 2.373 * parameters.mean_wait_of_all 
	+ 3702355.0044 * parameters.cpu_usage 
	- 0.5756 * parameters.avg_work_of_same_past_second 
	- 0.1795 * parameters.avg_wait_of_same_past_second 
	+ 0.0065 * parameters.avg_latency_of_same_last_20 
	- 0.0228 * parameters.max_latency_of_same_last_50 
	+ 739455046.5867;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM95(work_wait &parameters) {
  double actual_remaining = 
	2.5719 * parameters.work_so_far 
	+ 0.8781 * parameters.wait_so_far 
	+ 3592214.3631 * parameters.num_locks_so_far 
	- 28061.205 * parameters.total_wait_locks 
	+ 0.3754 * parameters.mean_wait_of_all 
	- 794251303.3998 * parameters.cpu_usage 
	+ 0.0073 * parameters.avg_work_of_same_past_second 
	- 0.0754 * parameters.avg_wait_of_same_past_second 
	+ 0.0065 * parameters.avg_latency_of_same_last_20 
	- 0.0862 * parameters.max_latency_of_same_last_50 
	+ 1138456580.3189;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM96(work_wait &parameters) {
  double actual_remaining = 
	0.6752 * parameters.work_so_far 
	+ 0.1338 * parameters.wait_so_far 
	- 86760322.6009 * parameters.num_locks_so_far 
	+ 48939.4217 * parameters.total_wait_locks 
	+ 0.2788 * parameters.mean_wait_of_all 
	+ 3702355.0044 * parameters.cpu_usage 
	+ 0.0073 * parameters.avg_work_of_same_past_second 
	- 0.0185 * parameters.avg_wait_of_same_past_second 
	- 0.2615 * parameters.avg_latency_of_same_last_20 
	+ 0.0882 * parameters.max_latency_of_same_last_50 
	+ 1551843495.6792;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM97(work_wait &parameters) {
  double actual_remaining = 
	0.6752 * parameters.work_so_far 
	+ 0.1338 * parameters.wait_so_far 
	- 179750060.767 * parameters.num_locks_so_far 
	+ 48939.4217 * parameters.total_wait_locks 
	+ 0.2788 * parameters.mean_wait_of_all 
	+ 3702355.0044 * parameters.cpu_usage 
	+ 0.0073 * parameters.avg_work_of_same_past_second 
	- 0.0185 * parameters.avg_wait_of_same_past_second 
	- 0.1533 * parameters.avg_latency_of_same_last_20 
	+ 0.0519 * parameters.max_latency_of_same_last_50 
	+ 2545967944.6411;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM98(work_wait &parameters) {
  double actual_remaining = 
	1.0977 * parameters.work_so_far 
	+ 0.1338 * parameters.wait_so_far 
	- 39630342.8525 * parameters.num_locks_so_far 
	+ 125953.3917 * parameters.total_wait_locks 
	+ 0.2788 * parameters.mean_wait_of_all 
	+ 3702355.0044 * parameters.cpu_usage 
	+ 0.0073 * parameters.avg_work_of_same_past_second 
	- 0.0185 * parameters.avg_wait_of_same_past_second 
	- 0.2184 * parameters.avg_latency_of_same_last_20 
	+ 0.0724 * parameters.max_latency_of_same_last_50 
	+ 1288816497.4642;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM99(work_wait &parameters) {
  double actual_remaining = 
	2.3971 * parameters.work_so_far 
	+ 0.4216 * parameters.wait_so_far 
	- 4409759.0225 * parameters.num_locks_so_far 
	+ 105790.7288 * parameters.total_wait_locks 
	+ 0.1022 * parameters.mean_wait_of_all 
	+ 3702355.0044 * parameters.cpu_usage 
	+ 0.0192 * parameters.avg_work_of_same_past_second 
	- 0.0325 * parameters.avg_wait_of_same_past_second 
	+ 0.2073 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	+ 270986082.4131;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM100(work_wait &parameters) {
  double actual_remaining = 
	0.6397 * parameters.work_so_far 
	+ 0.298 * parameters.wait_so_far 
	- 536255.5553 * parameters.num_locks_so_far 
	+ 12870.0241 * parameters.total_wait_locks 
	+ 0.1944 * parameters.mean_wait_of_all 
	+ 3702355.0044 * parameters.cpu_usage 
	+ 0.0192 * parameters.avg_work_of_same_past_second 
	- 0.0325 * parameters.avg_wait_of_same_past_second 
	+ 0.0827 * parameters.avg_latency_of_same_last_20 
	- 0.0083 * parameters.max_latency_of_same_last_50 
	+ 376813122.8424;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM101(work_wait &parameters) {
  double actual_remaining = 
	0.7185 * parameters.work_so_far 
	+ 0.3614 * parameters.wait_so_far 
	- 536255.5553 * parameters.num_locks_so_far 
	+ 12870.0241 * parameters.total_wait_locks 
	+ 0.1944 * parameters.mean_wait_of_all 
	+ 3702355.0044 * parameters.cpu_usage 
	+ 0.0192 * parameters.avg_work_of_same_past_second 
	- 0.0325 * parameters.avg_wait_of_same_past_second 
	+ 0.0827 * parameters.avg_latency_of_same_last_20 
	- 0.0083 * parameters.max_latency_of_same_last_50 
	+ 388912580.7944;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM102(work_wait &parameters) {
  double actual_remaining = 
	0.6719 * parameters.work_so_far 
	+ 0.244 * parameters.wait_so_far 
	- 536255.5553 * parameters.num_locks_so_far 
	+ 12870.0241 * parameters.total_wait_locks 
	+ 2.5301 * parameters.mean_wait_of_all 
	+ 3702355.0044 * parameters.cpu_usage 
	+ 0.0192 * parameters.avg_work_of_same_past_second 
	- 0.0325 * parameters.avg_wait_of_same_past_second 
	+ 0.129 * parameters.avg_latency_of_same_last_20 
	- 0.1925 * parameters.max_latency_of_same_last_50 
	+ 548266967.6447;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM103(work_wait &parameters) {
  double actual_remaining = 
	0.277 * parameters.work_so_far 
	+ 0.6557 * parameters.wait_so_far 
	+ 379031.2643 * parameters.num_locks_so_far 
	- 44703.8362 * parameters.total_wait_locks 
	+ 0.4808 * parameters.mean_wait_of_all 
	+ 3702355.0044 * parameters.cpu_usage 
	+ 0.5392 * parameters.avg_work_of_same_past_second 
	- 0.4615 * parameters.avg_wait_of_same_past_second 
	+ 0.2359 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	+ 195238588.808;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM104(work_wait &parameters) {
  double actual_remaining = 
	1.0472 * parameters.work_so_far 
	+ 0.6475 * parameters.wait_so_far 
	+ 1067124.3798 * parameters.num_locks_so_far 
	+ 73849.0328 * parameters.total_wait_locks 
	+ 1.3454 * parameters.mean_wait_of_all 
	+ 3702355.0044 * parameters.cpu_usage 
	+ 0.2022 * parameters.avg_work_of_same_past_second 
	- 0.6333 * parameters.avg_wait_of_same_past_second 
	+ 0.086 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	+ 101435564.027;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM105(work_wait &parameters) {
  double actual_remaining = 
	0.9126 * parameters.work_so_far 
	+ 0.9573 * parameters.wait_so_far 
	+ 1067124.3798 * parameters.num_locks_so_far 
	- 97820.7076 * parameters.total_wait_locks 
	+ 1.7793 * parameters.mean_wait_of_all 
	+ 3702355.0044 * parameters.cpu_usage 
	- 0.4586 * parameters.avg_work_of_same_past_second 
	- 0.9397 * parameters.avg_wait_of_same_past_second 
	+ 0.086 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	+ 388241683.3224;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM106(work_wait &parameters) {
  double actual_remaining = 
	1.0403 * parameters.work_so_far 
	- 2.1244 * parameters.wait_so_far 
	+ 15387725.5921 * parameters.num_locks_so_far 
	- 443026.6171 * parameters.total_wait_locks 
	+ 3.1345 * parameters.mean_wait_of_all 
	+ 532494793.7198 * parameters.cpu_usage 
	+ 0.0178 * parameters.avg_work_of_same_past_second 
	- 0.3519 * parameters.avg_wait_of_same_past_second 
	+ 0.1414 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	+ 1351323570.6955;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM107(work_wait &parameters) {
  double actual_remaining = 
	60.3963 * parameters.work_so_far 
	- 3.9002 * parameters.wait_so_far 
	+ 29449204.4896 * parameters.num_locks_so_far 
	- 483850.5204 * parameters.total_wait_locks 
	+ 2.2002 * parameters.mean_wait_of_all 
	+ 595155262.3842 * parameters.cpu_usage 
	+ 0.0178 * parameters.avg_work_of_same_past_second 
	- 0.3519 * parameters.avg_wait_of_same_past_second 
	- 0.031 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	+ 2463092933.5593;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM108(work_wait &parameters) {
  double actual_remaining = 
	1.1584 * parameters.work_so_far 
	- 3.5202 * parameters.wait_so_far 
	+ 29449204.4896 * parameters.num_locks_so_far 
	- 483850.5204 * parameters.total_wait_locks 
	+ 2.2002 * parameters.mean_wait_of_all 
	+ 1254375196.5474 * parameters.cpu_usage 
	+ 0.0178 * parameters.avg_work_of_same_past_second 
	- 0.3519 * parameters.avg_wait_of_same_past_second 
	- 0.3465 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	+ 1887847260.8859;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM109(work_wait &parameters) {
  double actual_remaining = 
	1.3676 * parameters.work_so_far 
	- 4.1101 * parameters.wait_so_far 
	+ 51875644.501 * parameters.num_locks_so_far 
	- 623789.6229 * parameters.total_wait_locks 
	+ 2.2002 * parameters.mean_wait_of_all 
	+ 777464759.1009 * parameters.cpu_usage 
	+ 0.0178 * parameters.avg_work_of_same_past_second 
	- 0.3519 * parameters.avg_wait_of_same_past_second 
	- 0.1563 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	+ 2420851226.3434;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM110(work_wait &parameters) {
  double actual_remaining = 
	1.3373 * parameters.work_so_far 
	+ 0.5153 * parameters.wait_so_far 
	- 1938573.6977 * parameters.num_locks_so_far 
	- 16673.0972 * parameters.total_wait_locks 
	+ 0.5068 * parameters.mean_wait_of_all 
	- 511869862.3973 * parameters.cpu_usage 
	- 0.4041 * parameters.avg_work_of_same_past_second 
	- 0.3357 * parameters.avg_wait_of_same_past_second 
	+ 0.1328 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	+ 1016416860.6869;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM111(work_wait &parameters) {
  double actual_remaining = 
	1.0151 * parameters.work_so_far 
	+ 0.1368 * parameters.wait_so_far 
	- 1938573.6977 * parameters.num_locks_so_far 
	- 16673.0972 * parameters.total_wait_locks 
	+ 0.5068 * parameters.mean_wait_of_all 
	- 731351597.8883 * parameters.cpu_usage 
	- 0.7775 * parameters.avg_work_of_same_past_second 
	- 0.6328 * parameters.avg_wait_of_same_past_second 
	+ 0.1328 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	+ 1677070069.5398;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM112(work_wait &parameters) {
  double actual_remaining = 
	1.0151 * parameters.work_so_far 
	+ 0.1368 * parameters.wait_so_far 
	- 1938573.6977 * parameters.num_locks_so_far 
	- 16673.0972 * parameters.total_wait_locks 
	+ 0.5068 * parameters.mean_wait_of_all 
	- 731351597.8883 * parameters.cpu_usage 
	- 0.7775 * parameters.avg_work_of_same_past_second 
	- 0.4194 * parameters.avg_wait_of_same_past_second 
	+ 0.1328 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	+ 1615816614.0034;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM113(work_wait &parameters) {
  double actual_remaining = 
	1.1368 * parameters.work_so_far 
	+ 0.1368 * parameters.wait_so_far 
	- 1938573.6977 * parameters.num_locks_so_far 
	- 16673.0972 * parameters.total_wait_locks 
	+ 0.5068 * parameters.mean_wait_of_all 
	- 513028847.5707 * parameters.cpu_usage 
	- 0.5064 * parameters.avg_work_of_same_past_second 
	- 0.3357 * parameters.avg_wait_of_same_past_second 
	+ 0.2486 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	+ 1233291968.5199;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM114(work_wait &parameters) {
  double actual_remaining = 
	1.0595 * parameters.work_so_far 
	+ 0.5545 * parameters.wait_so_far 
	- 558851.4546 * parameters.num_locks_so_far 
	- 224157.0949 * parameters.total_wait_locks 
	+ 2.2658 * parameters.mean_wait_of_all 
	+ 3702355.0044 * parameters.cpu_usage 
	+ 0.0178 * parameters.avg_work_of_same_past_second 
	- 0.1504 * parameters.avg_wait_of_same_past_second 
	+ 0.1527 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	+ 310397230.8271;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM115(work_wait &parameters) {
  double actual_remaining = 
	0.898 * parameters.work_so_far 
	+ 0.8374 * parameters.wait_so_far 
	- 564442.7711 * parameters.num_locks_so_far 
	+ 278035.2506 * parameters.total_wait_locks 
	+ 0.5959 * parameters.mean_wait_of_all 
	+ 3702355.0044 * parameters.cpu_usage 
	+ 0.0178 * parameters.avg_work_of_same_past_second 
	- 1.309 * parameters.avg_wait_of_same_past_second 
	+ 0.0414 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	+ 447009284.6849;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM116(work_wait &parameters) {
  double actual_remaining = 
	0.0289 * parameters.work_so_far 
	- 0.242 * parameters.wait_so_far 
	+ 66237444.1152 * parameters.num_locks_so_far 
	+ 13031.0753 * parameters.total_wait_locks 
	- 0.0539 * parameters.mean_wait_of_all 
	+ 45854.7319 * parameters.cpu_usage 
	+ 0.0088 * parameters.avg_work_of_same_past_second 
	- 0.6956 * parameters.avg_wait_of_same_past_second 
	+ 0.3467 * parameters.avg_latency_of_same_last_20 
	+ 0.0008 * parameters.max_latency_of_same_last_50 
	+ 224073384.4864;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM117(work_wait &parameters) {
  double actual_remaining = 
	0.3607 * parameters.work_so_far 
	+ 0.1502 * parameters.wait_so_far 
	+ 9994491.7247 * parameters.num_locks_so_far 
	+ 135226.2464 * parameters.total_wait_locks 
	- 0.949 * parameters.mean_wait_of_all 
	+ 45854.7319 * parameters.cpu_usage 
	+ 0.1166 * parameters.avg_work_of_same_past_second 
	+ 0.0337 * parameters.avg_wait_of_same_past_second 
	- 0.437 * parameters.avg_latency_of_same_last_20 
	+ 0.3108 * parameters.max_latency_of_same_last_50 
	+ 100924924.9057;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM118(work_wait &parameters) {
  double actual_remaining = 
	0.2797 * parameters.work_so_far 
	+ 0.5522 * parameters.wait_so_far 
	+ 64149848.5074 * parameters.num_locks_so_far 
	+ 101921.5541 * parameters.total_wait_locks 
	- 0.7009 * parameters.mean_wait_of_all 
	+ 45854.7319 * parameters.cpu_usage 
	+ 0.8341 * parameters.avg_work_of_same_past_second 
	- 0.0059 * parameters.avg_wait_of_same_past_second 
	+ 0.3166 * parameters.avg_latency_of_same_last_20 
	+ 0.0092 * parameters.max_latency_of_same_last_50 
	- 372928619.7203;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM119(work_wait &parameters) {
  double actual_remaining = 
	1.3975 * parameters.work_so_far 
	+ 0.6691 * parameters.wait_so_far 
	- 6870081.8245 * parameters.num_locks_so_far 
	+ 52087.3121 * parameters.total_wait_locks 
	- 0.325 * parameters.mean_wait_of_all 
	- 392337742.4886 * parameters.cpu_usage 
	+ 0.4981 * parameters.avg_work_of_same_past_second 
	- 0.873 * parameters.avg_wait_of_same_past_second 
	+ 0.0211 * parameters.avg_latency_of_same_last_20 
	+ 0.0722 * parameters.max_latency_of_same_last_50 
	+ 779926770.0789;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM120(work_wait &parameters) {
  double actual_remaining = 
	0.872 * parameters.work_so_far 
	+ 0.5125 * parameters.wait_so_far 
	- 8935292.0665 * parameters.num_locks_so_far 
	+ 59863.2383 * parameters.total_wait_locks 
	+ 0.4387 * parameters.mean_wait_of_all 
	- 888574453.9391 * parameters.cpu_usage 
	+ 0.9089 * parameters.avg_work_of_same_past_second 
	- 0.9155 * parameters.avg_wait_of_same_past_second 
	+ 0.2234 * parameters.avg_latency_of_same_last_20 
	- 0.0973 * parameters.max_latency_of_same_last_50 
	+ 1388024174.6731;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM121(work_wait &parameters) {
  double actual_remaining = 
	1.024 * parameters.work_so_far 
	+ 0.9632 * parameters.wait_so_far 
	- 285308.8571 * parameters.num_locks_so_far 
	+ 54798.7073 * parameters.total_wait_locks 
	- 0.2763 * parameters.mean_wait_of_all 
	+ 45854.7319 * parameters.cpu_usage 
	+ 0.0088 * parameters.avg_work_of_same_past_second 
	- 0.0589 * parameters.avg_wait_of_same_past_second 
	+ 0.3096 * parameters.avg_latency_of_same_last_20 
	+ 0.0073 * parameters.max_latency_of_same_last_50 
	+ 44704390.7516;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM122(work_wait &parameters) {
  double actual_remaining = 
	25.233 * parameters.work_so_far 
	- 0.0203 * parameters.wait_so_far 
	- 17048564.4004 * parameters.num_locks_so_far 
	+ 1130489.8177 * parameters.total_wait_locks 
	+ 0.0512 * parameters.mean_wait_of_all 
	+ 267608276.0704 * parameters.cpu_usage 
	+ 0.0474 * parameters.avg_work_of_same_past_second 
	+ 0.0048 * parameters.avg_wait_of_same_past_second 
	+ 0.0786 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 77373665.5197;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM123(work_wait &parameters) {
  double actual_remaining = 
	25.233 * parameters.work_so_far 
	- 0.0203 * parameters.wait_so_far 
	- 20049423.3708 * parameters.num_locks_so_far 
	+ 262193.0931 * parameters.total_wait_locks 
	+ 0.0512 * parameters.mean_wait_of_all 
	+ 315024401.3709 * parameters.cpu_usage 
	+ 0.0474 * parameters.avg_work_of_same_past_second 
	+ 0.0048 * parameters.avg_wait_of_same_past_second 
	+ 0.0909 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 539836067.4076;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM124(work_wait &parameters) {
  double actual_remaining = 
	41.9416 * parameters.work_so_far 
	- 0.2312 * parameters.wait_so_far 
	- 115145.9242 * parameters.num_locks_so_far 
	- 2124952.0298 * parameters.total_wait_locks 
	+ 13.3744 * parameters.mean_wait_of_all 
	+ 45854.7319 * parameters.cpu_usage 
	+ 0.0658 * parameters.avg_work_of_same_past_second 
	+ 0.0048 * parameters.avg_wait_of_same_past_second 
	- 0.0073 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 126848720.4066;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM125(work_wait &parameters) {
  double actual_remaining = 
	-399.8819 * parameters.work_so_far 
	- 0.0295 * parameters.wait_so_far 
	- 115145.9242 * parameters.num_locks_so_far 
	- 39701.6849 * parameters.total_wait_locks 
	+ 0.8053 * parameters.mean_wait_of_all 
	+ 45854.7319 * parameters.cpu_usage 
	+ 0.5712 * parameters.avg_work_of_same_past_second 
	+ 0.0048 * parameters.avg_wait_of_same_past_second 
	- 0.5847 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 556914931.0473;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM126(work_wait &parameters) {
  double actual_remaining = 
	0.8818 * parameters.work_so_far 
	+ 0.4062 * parameters.wait_so_far 
	- 3668016.6102 * parameters.num_locks_so_far 
	+ 522884.3107 * parameters.total_wait_locks 
	+ 0.0458 * parameters.mean_wait_of_all 
	+ 45854.7319 * parameters.cpu_usage 
	+ 0.019 * parameters.avg_work_of_same_past_second 
	+ 0.007 * parameters.avg_wait_of_same_past_second 
	+ 0.1747 * parameters.avg_latency_of_same_last_20 
	- 0.0016 * parameters.max_latency_of_same_last_50 
	+ 477883228.0464;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM127(work_wait &parameters) {
  double actual_remaining = 
	0.9077 * parameters.work_so_far 
	+ 0.0356 * parameters.wait_so_far 
	- 9275269.3675 * parameters.num_locks_so_far 
	- 335007.5811 * parameters.total_wait_locks 
	+ 0.3715 * parameters.mean_wait_of_all 
	+ 45854.7319 * parameters.cpu_usage 
	+ 0.277 * parameters.avg_work_of_same_past_second 
	+ 0.0186 * parameters.avg_wait_of_same_past_second 
	+ 0.0183 * parameters.avg_latency_of_same_last_20 
	- 0.0046 * parameters.max_latency_of_same_last_50 
	+ 944701679.6794;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM128(work_wait &parameters) {
  double actual_remaining = 
	0.842 * parameters.work_so_far 
	+ 0.457 * parameters.wait_so_far 
	- 836157.0896 * parameters.num_locks_so_far 
	- 1942854.2088 * parameters.total_wait_locks 
	+ 13.2739 * parameters.mean_wait_of_all 
	- 1325492089.4137 * parameters.cpu_usage 
	+ 0.446 * parameters.avg_work_of_same_past_second 
	+ 1.0341 * parameters.avg_wait_of_same_past_second 
	+ 0.5235 * parameters.avg_latency_of_same_last_20 
	- 0.3589 * parameters.max_latency_of_same_last_50 
	+ 1432367980.9829;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
tpcc_estimate(work_wait &parameters){

  if (parameters.avg_work_of_same_past_second <= 84842850) {

    if (parameters.work_so_far <= 750596) {

      if (parameters.avg_wait_of_same_past_second <= 44234850) {
        return tpcc_LM1(parameters);
      } else {

        if (parameters.work_so_far <= 51637) {

          if (parameters.work_so_far <= 22152.5) {

            if (parameters.work_so_far <= 11159.5) {
              return tpcc_LM2(parameters);
            } else {

              if (parameters.avg_latency_of_same_last_20 <= 110369500) {

                if (parameters.avg_wait_of_same_past_second <= 65073000) {
                  return tpcc_LM3(parameters);
                } else {

                  if (parameters.cpu_usage <= 0.946) {

                    if (parameters.mean_wait_of_all <= 57374200) {

                      if (parameters.mean_wait_of_all <= 38669750) {
                        return tpcc_LM4(parameters);
                      } else {
                        return tpcc_LM5(parameters);
                      }
                    } else {
                      return tpcc_LM6(parameters);
                    }
                  } else {

                    if (parameters.work_so_far <= 12823.5) {
                      return tpcc_LM7(parameters);
                    } else {
                      return tpcc_LM8(parameters);
                    }
                  }
                }
              } else {

                if (parameters.work_so_far <= 17480.5) {
                  return tpcc_LM9(parameters);
                } else {
                  return tpcc_LM10(parameters);
                }
              }
            }
          } else {

            if (parameters.mean_wait_of_all <= 113590000) {

              if (parameters.avg_wait_of_same_past_second <= 357448500) {

                if (parameters.avg_wait_of_same_past_second <= 135761000) {
                  return tpcc_LM11(parameters);
                } else {

                  if (parameters.mean_wait_of_all <= 70913950) {
                    return tpcc_LM12(parameters);
                  } else {

                    if (parameters.avg_wait_of_same_past_second <= 352854000) {
                      return tpcc_LM13(parameters);
                    } else {

                      if (parameters.avg_latency_of_same_last_20 <= 518045000) {
                        return tpcc_LM14(parameters);
                      } else {
                        return tpcc_LM15(parameters);
                      }
                    }
                  }
                }
              } else {

                if (parameters.max_latency_of_same_last_50 <= 1261640000) {
                  return tpcc_LM16(parameters);
                } else {

                  if (parameters.avg_latency_of_same_last_20 <= 647857500) {

                    if (parameters.avg_latency_of_same_last_20 <= 480521000) {

                      if (parameters.max_latency_of_same_last_50 <= 1340120000) {

                        if (parameters.avg_wait_of_same_past_second <= 449702000) {

                          if (parameters.mean_wait_of_all <= 98811300) {
                            return tpcc_LM17(parameters);
                          } else {
                            return tpcc_LM18(parameters);
                          }
                        } else {

                          if (parameters.mean_wait_of_all <= 103095500) {
                            return tpcc_LM19(parameters);
                          } else {
                            return tpcc_LM20(parameters);
                          }
                        }
                      } else {
                        return tpcc_LM21(parameters);
                      }
                    } else {

                      if (parameters.max_latency_of_same_last_50 <= 1897040000) {
                        return tpcc_LM22(parameters);
                      } else {

                        if (parameters.avg_work_of_same_past_second <= 32725050) {

                          if (parameters.mean_wait_of_all <= 93110950) {

                            if (parameters.cpu_usage <= 0.946) {
                              return tpcc_LM23(parameters);
                            } else {
                              return tpcc_LM24(parameters);
                            }
                          } else {
                            return tpcc_LM25(parameters);
                          }
                        } else {
                          return tpcc_LM26(parameters);
                        }
                      }
                    }
                  } else {
                    return tpcc_LM27(parameters);
                  }
                }
              }
            } else {

              if (parameters.mean_wait_of_all <= 117811000) {

                if (parameters.mean_wait_of_all <= 114309500) {

                  if (parameters.avg_wait_of_same_past_second <= 374945500) {
                    return tpcc_LM28(parameters);
                  } else {

                    if (parameters.avg_work_of_same_past_second <= 32826950) {
                      return tpcc_LM29(parameters);
                    } else {
                      return tpcc_LM30(parameters);
                    }
                  }
                } else {

                  if (parameters.mean_wait_of_all <= 116436500) {
                    return tpcc_LM31(parameters);
                  } else {

                    if (parameters.total_wait_locks <= 547.5) {

                      if (parameters.cpu_usage <= 0.836) {
                        return tpcc_LM32(parameters);
                      } else {

                        if (parameters.mean_wait_of_all <= 117598500) {
                          return tpcc_LM33(parameters);
                        } else {
                          return tpcc_LM34(parameters);
                        }
                      }
                    } else {
                      return tpcc_LM35(parameters);
                    }
                  }
                }
              } else {
                return tpcc_LM36(parameters);
              }
            }
          }
        } else {
          return tpcc_LM37(parameters);
        }
      }
    } else {

      if (parameters.wait_so_far <= 362426332) {

        if (parameters.num_locks_so_far <= 2.5) {

          if (parameters.wait_so_far <= 144420410.5) {

            if (parameters.wait_so_far <= 24165) {

              if (parameters.work_so_far <= 3040921.5) {
                return tpcc_LM38(parameters);
              } else {

                if (parameters.wait_so_far <= 7874) {
                  return tpcc_LM39(parameters);
                } else {
                  return tpcc_LM40(parameters);
                }
              }
            } else {

              if (parameters.wait_so_far <= 34609635.5) {

                if (parameters.work_so_far <= 2658163) {
                  return tpcc_LM41(parameters);
                } else {
                  return tpcc_LM42(parameters);
                }
              } else {
                return tpcc_LM43(parameters);
              }
            }
          } else {

            if (parameters.wait_so_far <= 228903358.5) {
              return tpcc_LM44(parameters);
            } else {

              if (parameters.avg_work_of_same_past_second <= 30133100) {

                if (parameters.wait_so_far <= 325719579) {
                  return tpcc_LM45(parameters);
                } else {

                  if (parameters.avg_latency_of_same_last_20 <= 381617000) {

                    if (parameters.wait_so_far <= 331041472) {
                      return tpcc_LM46(parameters);
                    } else {
                      return tpcc_LM47(parameters);
                    }
                  } else {
                    return tpcc_LM48(parameters);
                  }
                }
              } else {

                if (parameters.max_latency_of_same_last_50 <= 1325925000) {
                  return tpcc_LM49(parameters);
                } else {
                  return tpcc_LM50(parameters);
                }
              }
            }
          }
        } else {

          if (parameters.work_so_far <= 104161495.5) {

            if (parameters.num_locks_so_far <= 22.5) {

              if (parameters.avg_wait_of_same_past_second <= 27958050) {
                return tpcc_LM51(parameters);
              } else {

                if (parameters.wait_so_far <= 176616091.5) {

                  if (parameters.avg_work_of_same_past_second <= 46053350) {
                    return tpcc_LM52(parameters);
                  } else {

                    if (parameters.num_locks_so_far <= 17.5) {

                      if (parameters.work_so_far <= 31611479.5) {
                        return tpcc_LM53(parameters);
                      } else {

                        if (parameters.work_so_far <= 48060845) {
                          return tpcc_LM54(parameters);
                        } else {
                          return tpcc_LM55(parameters);
                        }
                      }
                    } else {
                      return tpcc_LM56(parameters);
                    }
                  }
                } else {
                  return tpcc_LM57(parameters);
                }
              }
            } else {
              return tpcc_LM58(parameters);
            }
          } else {
            return tpcc_LM59(parameters);
          }
        }
      } else {

        if (parameters.wait_so_far <= 742183500.5) {

          if (parameters.num_locks_so_far <= 2.5) {

            if (parameters.work_so_far <= 3599816) {
              return tpcc_LM60(parameters);
            } else {

              if (parameters.total_wait_locks <= 291) {
                return tpcc_LM61(parameters);
              } else {
                return tpcc_LM62(parameters);
              }
            }
          } else {

            if (parameters.wait_so_far <= 579926246) {

              if (parameters.wait_so_far <= 465846561) {

                if (parameters.work_so_far <= 7701309.5) {
                  return tpcc_LM63(parameters);
                } else {

                  if (parameters.work_so_far <= 36537881) {
                    return tpcc_LM64(parameters);
                  } else {

                    if (parameters.work_so_far <= 58977855.5) {
                      return tpcc_LM65(parameters);
                    } else {
                      return tpcc_LM66(parameters);
                    }
                  }
                }
              } else {
                return tpcc_LM67(parameters);
              }
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

    if (parameters.avg_work_of_same_past_second <= 336081500) {

      if (parameters.work_so_far <= 706291) {

        if (parameters.total_wait_locks <= 296.5) {
          return tpcc_LM70(parameters);
        } else {
          return tpcc_LM71(parameters);
        }
      } else {

        if (parameters.wait_so_far <= 218911528) {

          if (parameters.work_so_far <= 119635929.5) {

            if (parameters.num_locks_so_far <= 15.5) {
              return tpcc_LM72(parameters);
            } else {
              return tpcc_LM73(parameters);
            }
          } else {

            if (parameters.work_so_far <= 273562354) {

              if (parameters.num_locks_so_far <= 23.5) {

                if (parameters.num_locks_so_far <= 16.5) {

                  if (parameters.num_locks_so_far <= 7.5) {
                    return tpcc_LM74(parameters);
                  } else {

                    if (parameters.mean_wait_of_all <= 63150050) {
                      return tpcc_LM75(parameters);
                    } else {

                      if (parameters.wait_so_far <= 26593145.5) {

                        if (parameters.avg_work_of_same_past_second <= 221984000) {

                          if (parameters.avg_latency_of_same_last_20 <= 373972500) {
                            return tpcc_LM76(parameters);
                          } else {
                            return tpcc_LM77(parameters);
                          }
                        } else {

                          if (parameters.avg_work_of_same_past_second <= 282196500) {
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
                } else {
                  return tpcc_LM81(parameters);
                }
              } else {
                return tpcc_LM82(parameters);
              }
            } else {

              if (parameters.work_so_far <= 505059430.5) {

                if (parameters.avg_wait_of_same_past_second <= 21418550) {
                  return tpcc_LM83(parameters);
                } else {

                  if (parameters.num_locks_so_far <= 26.5) {

                    if (parameters.num_locks_so_far <= 12.5) {

                      if (parameters.work_so_far <= 369569748.5) {

                        if (parameters.num_locks_so_far <= 7.5) {
                          return tpcc_LM84(parameters);
                        } else {
                          return tpcc_LM85(parameters);
                        }
                      } else {
                        return tpcc_LM86(parameters);
                      }
                    } else {
                      return tpcc_LM87(parameters);
                    }
                  } else {
                    return tpcc_LM88(parameters);
                  }
                }
              } else {
                return tpcc_LM89(parameters);
              }
            }
          }
        } else {

          if (parameters.num_locks_so_far <= 4.5) {
            return tpcc_LM90(parameters);
          } else {

            if (parameters.wait_so_far <= 556440764.5) {

              if (parameters.num_locks_so_far <= 12.5) {

                if (parameters.num_locks_so_far <= 9.5) {

                  if (parameters.mean_wait_of_all <= 57839650) {
                    return tpcc_LM91(parameters);
                  } else {

                    if (parameters.max_latency_of_same_last_50 <= 969655500) {

                      if (parameters.avg_work_of_same_past_second <= 216234500) {

                        if (parameters.total_wait_locks <= 230.5) {
                          return tpcc_LM92(parameters);
                        } else {
                          return tpcc_LM93(parameters);
                        }
                      } else {
                        return tpcc_LM94(parameters);
                      }
                    } else {
                      return tpcc_LM95(parameters);
                    }
                  }
                } else {

                  if (parameters.work_so_far <= 58301874.5) {

                    if (parameters.avg_wait_of_same_past_second <= 190991500) {
                      return tpcc_LM96(parameters);
                    } else {
                      return tpcc_LM97(parameters);
                    }
                  } else {
                    return tpcc_LM98(parameters);
                  }
                }
              } else {

                if (parameters.work_so_far <= 72624500) {

                  if (parameters.wait_so_far <= 404370333) {
                    return tpcc_LM99(parameters);
                  } else {

                    if (parameters.avg_latency_of_same_last_20 <= 496074000) {

                      if (parameters.wait_so_far <= 496239911.5) {
                        return tpcc_LM100(parameters);
                      } else {
                        return tpcc_LM101(parameters);
                      }
                    } else {
                      return tpcc_LM102(parameters);
                    }
                  }
                } else {

                  if (parameters.work_so_far <= 251975083) {
                    return tpcc_LM103(parameters);
                  } else {

                    if (parameters.wait_so_far <= 421625168) {
                      return tpcc_LM104(parameters);
                    } else {
                      return tpcc_LM105(parameters);
                    }
                  }
                }
              }
            } else {

              if (parameters.wait_so_far <= 916621593) {

                if (parameters.wait_so_far <= 632610940.5) {

                  if (parameters.num_locks_so_far <= 10.5) {

                    if (parameters.mean_wait_of_all <= 59519800) {
                      return tpcc_LM106(parameters);
                    } else {

                      if (parameters.mean_wait_of_all <= 113152500) {

                        if (parameters.work_so_far <= 2011557.5) {
                          return tpcc_LM107(parameters);
                        } else {
                          return tpcc_LM108(parameters);
                        }
                      } else {
                        return tpcc_LM109(parameters);
                      }
                    }
                  } else {

                    if (parameters.num_locks_so_far <= 20.5) {
                      return tpcc_LM110(parameters);
                    } else {

                      if (parameters.cpu_usage <= 0.902) {

                        if (parameters.total_wait_locks <= 199.5) {
                          return tpcc_LM111(parameters);
                        } else {
                          return tpcc_LM112(parameters);
                        }
                      } else {
                        return tpcc_LM113(parameters);
                      }
                    }
                  }
                } else {
                  return tpcc_LM114(parameters);
                }
              } else {
                return tpcc_LM115(parameters);
              }
            }
          }
        }
      }
    } else {

      if (parameters.avg_work_of_same_past_second <= 636063000) {

        if (parameters.num_locks_so_far <= 4.5) {
          return tpcc_LM116(parameters);
        } else {

          if (parameters.wait_so_far <= 418895266.5) {

            if (parameters.work_so_far <= 327507630) {

              if (parameters.num_locks_so_far <= 11.5) {

                if (parameters.work_so_far <= 2400006.5) {
                  return tpcc_LM117(parameters);
                } else {
                  return tpcc_LM118(parameters);
                }
              } else {
                return tpcc_LM119(parameters);
              }
            } else {
              return tpcc_LM120(parameters);
            }
          } else {
            return tpcc_LM121(parameters);
          }
        }
      } else {

        if (parameters.work_so_far <= 716973) {

          if (parameters.wait_so_far <= 93536) {

            if (parameters.total_wait_locks <= 382.5) {
              return tpcc_LM122(parameters);
            } else {
              return tpcc_LM123(parameters);
            }
          } else {

            if (parameters.work_so_far <= 43918.5) {
              return tpcc_LM124(parameters);
            } else {
              return tpcc_LM125(parameters);
            }
          }
        } else {

          if (parameters.total_wait_locks <= 352.5) {
            return tpcc_LM126(parameters);
          } else {

            if (parameters.wait_so_far <= 563604714.5) {
              return tpcc_LM127(parameters);
            } else {
              return tpcc_LM128(parameters);
            }
          }
        }
      }
    }
  }
}