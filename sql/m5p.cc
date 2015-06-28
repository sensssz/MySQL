#include "my_global.h"
#include "m5p.h"
#include "trace_tool.h"

static
double
new_order_LM1(work_wait &parameters) {
  double actual_remaining = 
	3.1842 * parameters.work_so_far 
	+ 0.0009 * parameters.wait_so_far 
	- 2715615.4216 * parameters.num_locks_so_far 
	+ 854195.5661 * parameters.total_wait_locks 
	- 0.0007 * parameters.mean_wait_of_all 
	- 327467387.1225 * parameters.cpu_usage 
	+ 0.0031 * parameters.avg_work_of_same_past_second 
	- 0.0024 * parameters.avg_wait_of_same_past_second 
	+ 0.1479 * parameters.avg_latency_of_same_last_20 
	- 0.0376 * parameters.max_latency_of_same_last_50 
	+ 350019839.6161;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM2(work_wait &parameters) {
  double actual_remaining = 
	1.0258 * parameters.work_so_far 
	+ 0.7968 * parameters.wait_so_far 
	- 2134105.5355 * parameters.num_locks_so_far 
	+ 888537.2359 * parameters.total_wait_locks 
	- 0.0007 * parameters.mean_wait_of_all 
	- 10401772.2984 * parameters.cpu_usage 
	+ 0.0031 * parameters.avg_work_of_same_past_second 
	- 0.0024 * parameters.avg_wait_of_same_past_second 
	+ 0.0073 * parameters.avg_latency_of_same_last_20 
	- 0.0885 * parameters.max_latency_of_same_last_50 
	+ 189757260.6576;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM3(work_wait &parameters) {
  double actual_remaining = 
	0.6984 * parameters.work_so_far 
	- 0.2383 * parameters.wait_so_far 
	+ 66376.7754 * parameters.num_locks_so_far 
	+ 1920841.787 * parameters.total_wait_locks 
	- 0.3142 * parameters.mean_wait_of_all 
	- 21109842.4408 * parameters.cpu_usage 
	+ 0.0144 * parameters.avg_work_of_same_past_second 
	- 0.0183 * parameters.avg_wait_of_same_past_second 
	+ 0.1628 * parameters.avg_latency_of_same_last_20 
	- 0.0078 * parameters.max_latency_of_same_last_50 
	- 70601519.3183;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM4(work_wait &parameters) {
  double actual_remaining = 
	0.7588 * parameters.work_so_far 
	- 0.0415 * parameters.wait_so_far 
	+ 66376.7754 * parameters.num_locks_so_far 
	+ 171871.1343 * parameters.total_wait_locks 
	- 0.2157 * parameters.mean_wait_of_all 
	- 24393826.4386 * parameters.cpu_usage 
	+ 0.3902 * parameters.avg_work_of_same_past_second 
	+ 1.7402 * parameters.avg_wait_of_same_past_second 
	+ 0.0832 * parameters.avg_latency_of_same_last_20 
	- 0.0962 * parameters.max_latency_of_same_last_50 
	+ 290959378.7049;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM5(work_wait &parameters) {
  double actual_remaining = 
	2079.4746 * parameters.work_so_far 
	- 0.0415 * parameters.wait_so_far 
	+ 66376.7754 * parameters.num_locks_so_far 
	+ 171871.1343 * parameters.total_wait_locks 
	- 0.5002 * parameters.mean_wait_of_all 
	- 24393826.4386 * parameters.cpu_usage 
	+ 0.6486 * parameters.avg_work_of_same_past_second 
	+ 2.4334 * parameters.avg_wait_of_same_past_second 
	+ 0.0832 * parameters.avg_latency_of_same_last_20 
	- 0.0962 * parameters.max_latency_of_same_last_50 
	+ 237411303.4822;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM6(work_wait &parameters) {
  double actual_remaining = 
	0.7588 * parameters.work_so_far 
	- 0.0415 * parameters.wait_so_far 
	+ 66376.7754 * parameters.num_locks_so_far 
	+ 171871.1343 * parameters.total_wait_locks 
	+ 0.0056 * parameters.mean_wait_of_all 
	- 24393826.4386 * parameters.cpu_usage 
	+ 0.2836 * parameters.avg_work_of_same_past_second 
	+ 1.5722 * parameters.avg_wait_of_same_past_second 
	+ 0.0832 * parameters.avg_latency_of_same_last_20 
	- 0.2476 * parameters.max_latency_of_same_last_50 
	+ 370547835.1218;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM7(work_wait &parameters) {
  double actual_remaining = 
	28.0138 * parameters.work_so_far 
	- 0.0371 * parameters.wait_so_far 
	+ 66376.7754 * parameters.num_locks_so_far 
	+ 171871.1343 * parameters.total_wait_locks 
	+ 0.0056 * parameters.mean_wait_of_all 
	- 24393826.4386 * parameters.cpu_usage 
	+ 0.0144 * parameters.avg_work_of_same_past_second 
	+ 2.7934 * parameters.avg_wait_of_same_past_second 
	+ 0.6337 * parameters.avg_latency_of_same_last_20 
	- 0.3226 * parameters.max_latency_of_same_last_50 
	+ 170453405.0797;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM8(work_wait &parameters) {
  double actual_remaining = 
	8.6952 * parameters.work_so_far 
	- 0.0718 * parameters.wait_so_far 
	+ 66376.7754 * parameters.num_locks_so_far 
	+ 1592533.6047 * parameters.total_wait_locks 
	+ 0.0056 * parameters.mean_wait_of_all 
	- 19878547.4188 * parameters.cpu_usage 
	+ 0.0144 * parameters.avg_work_of_same_past_second 
	- 0.0183 * parameters.avg_wait_of_same_past_second 
	+ 0.0204 * parameters.avg_latency_of_same_last_20 
	- 0.0078 * parameters.max_latency_of_same_last_50 
	- 30579055.3197;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM9(work_wait &parameters) {
  double actual_remaining = 
	0.3217 * parameters.work_so_far 
	+ 0.0451 * parameters.wait_so_far 
	- 1220781.4569 * parameters.num_locks_so_far 
	+ 260813.4732 * parameters.total_wait_locks 
	+ 0.0063 * parameters.mean_wait_of_all 
	- 17409453.3839 * parameters.cpu_usage 
	+ 0.0064 * parameters.avg_work_of_same_past_second 
	- 0.02 * parameters.avg_wait_of_same_past_second 
	+ 0.4265 * parameters.avg_latency_of_same_last_20 
	- 0.0213 * parameters.max_latency_of_same_last_50 
	+ 268660916.0585;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM10(work_wait &parameters) {
  double actual_remaining = 
	1.8019 * parameters.work_so_far 
	+ 0.6094 * parameters.wait_so_far 
	- 849447.4193 * parameters.num_locks_so_far 
	+ 749024.4014 * parameters.total_wait_locks 
	+ 0.0063 * parameters.mean_wait_of_all 
	- 332545626.4392 * parameters.cpu_usage 
	+ 0.0064 * parameters.avg_work_of_same_past_second 
	- 0.02 * parameters.avg_wait_of_same_past_second 
	+ 0.027 * parameters.avg_latency_of_same_last_20 
	- 0.0871 * parameters.max_latency_of_same_last_50 
	+ 428096015.7783;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM11(work_wait &parameters) {
  double actual_remaining = 
	0.7604 * parameters.work_so_far 
	+ 0.0624 * parameters.wait_so_far 
	- 4980622.6435 * parameters.num_locks_so_far 
	+ 2130663.5497 * parameters.total_wait_locks 
	+ 0.0063 * parameters.mean_wait_of_all 
	- 287357069.919 * parameters.cpu_usage 
	- 0.7328 * parameters.avg_work_of_same_past_second 
	- 0.02 * parameters.avg_wait_of_same_past_second 
	+ 0.0137 * parameters.avg_latency_of_same_last_20 
	- 0.0114 * parameters.max_latency_of_same_last_50 
	+ 524961324.8317;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM12(work_wait &parameters) {
  double actual_remaining = 
	1.1357 * parameters.work_so_far 
	+ 0.1474 * parameters.wait_so_far 
	- 437387.7126 * parameters.num_locks_so_far 
	+ 151662.4989 * parameters.total_wait_locks 
	+ 0.0063 * parameters.mean_wait_of_all 
	- 22887153.0141 * parameters.cpu_usage 
	+ 0.0779 * parameters.avg_work_of_same_past_second 
	- 0.0913 * parameters.avg_wait_of_same_past_second 
	+ 0.026 * parameters.avg_latency_of_same_last_20 
	- 0.014 * parameters.max_latency_of_same_last_50 
	+ 404959544.9675;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM13(work_wait &parameters) {
  double actual_remaining = 
	0.4716 * parameters.work_so_far 
	+ 0.6259 * parameters.wait_so_far 
	- 437387.7126 * parameters.num_locks_so_far 
	+ 151662.4989 * parameters.total_wait_locks 
	- 1.1011 * parameters.mean_wait_of_all 
	- 1336688827.9532 * parameters.cpu_usage 
	+ 1.3978 * parameters.avg_work_of_same_past_second 
	- 0.2022 * parameters.avg_wait_of_same_past_second 
	+ 0.026 * parameters.avg_latency_of_same_last_20 
	- 0.014 * parameters.max_latency_of_same_last_50 
	+ 1368256972.8427;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM14(work_wait &parameters) {
  double actual_remaining = 
	-3.6808 * parameters.work_so_far 
	+ 11942.2835 * parameters.wait_so_far 
	+ 119561.5265 * parameters.num_locks_so_far 
	+ 59020.5507 * parameters.total_wait_locks 
	- 0.12 * parameters.mean_wait_of_all 
	- 9209184.3989 * parameters.cpu_usage 
	+ 0.0006 * parameters.avg_work_of_same_past_second 
	- 0.0159 * parameters.avg_wait_of_same_past_second 
	+ 0.0045 * parameters.avg_latency_of_same_last_20 
	- 0.0072 * parameters.max_latency_of_same_last_50 
	+ 198327032.6913;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM15(work_wait &parameters) {
  double actual_remaining = 
	-155.1702 * parameters.work_so_far 
	+ 187.7006 * parameters.wait_so_far 
	+ 119561.5265 * parameters.num_locks_so_far 
	+ 42767.8549 * parameters.total_wait_locks 
	- 0.081 * parameters.mean_wait_of_all 
	- 9209184.3989 * parameters.cpu_usage 
	- 0.8228 * parameters.avg_work_of_same_past_second 
	- 0.0159 * parameters.avg_wait_of_same_past_second 
	+ 0.2366 * parameters.avg_latency_of_same_last_20 
	- 0.1284 * parameters.max_latency_of_same_last_50 
	+ 701931465.9057;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM16(work_wait &parameters) {
  double actual_remaining = 
	-84.9173 * parameters.work_so_far 
	- 0.1606 * parameters.wait_so_far 
	+ 119561.5265 * parameters.num_locks_so_far 
	- 557946.865 * parameters.total_wait_locks 
	+ 1.4657 * parameters.mean_wait_of_all 
	- 405306950.9395 * parameters.cpu_usage 
	+ 0.0006 * parameters.avg_work_of_same_past_second 
	- 0.357 * parameters.avg_wait_of_same_past_second 
	+ 0.0026 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 841843323.0882;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM17(work_wait &parameters) {
  double actual_remaining = 
	-0.5973 * parameters.work_so_far 
	- 0.4883 * parameters.wait_so_far 
	+ 119561.5265 * parameters.num_locks_so_far 
	- 19565.8065 * parameters.total_wait_locks 
	- 23.867 * parameters.mean_wait_of_all 
	+ 487733781.3304 * parameters.cpu_usage 
	- 1.7669 * parameters.avg_work_of_same_past_second 
	- 0.0019 * parameters.avg_wait_of_same_past_second 
	+ 0.0019 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 3064672426.8023;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM18(work_wait &parameters) {
  double actual_remaining = 
	-0.5973 * parameters.work_so_far 
	- 0.2495 * parameters.wait_so_far 
	- 59573461.4247 * parameters.num_locks_so_far 
	- 770450.817 * parameters.total_wait_locks 
	+ 4.008 * parameters.mean_wait_of_all 
	- 384553394.2527 * parameters.cpu_usage 
	+ 0.0006 * parameters.avg_work_of_same_past_second 
	- 0.0019 * parameters.avg_wait_of_same_past_second 
	+ 0.0019 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 857271637.9808;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM19(work_wait &parameters) {
  double actual_remaining = 
	79.2152 * parameters.work_so_far 
	- 0.1294 * parameters.wait_so_far 
	+ 130271611.4592 * parameters.num_locks_so_far 
	- 787707.6701 * parameters.total_wait_locks 
	+ 3.4881 * parameters.mean_wait_of_all 
	- 203313572.7069 * parameters.cpu_usage 
	+ 0.1705 * parameters.avg_work_of_same_past_second 
	- 0.0011 * parameters.avg_wait_of_same_past_second 
	+ 0.2561 * parameters.avg_latency_of_same_last_20 
	- 0.0661 * parameters.max_latency_of_same_last_50 
	- 174612152.9771;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM20(work_wait &parameters) {
  double actual_remaining = 
	13.3883 * parameters.work_so_far 
	+ 0.2814 * parameters.wait_so_far 
	- 11222350.614 * parameters.num_locks_so_far 
	+ 1295.0661 * parameters.total_wait_locks 
	- 0.0019 * parameters.mean_wait_of_all 
	- 243661557.1574 * parameters.cpu_usage 
	+ 0.2452 * parameters.avg_work_of_same_past_second 
	+ 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.1548 * parameters.avg_latency_of_same_last_20 
	- 0.0849 * parameters.max_latency_of_same_last_50 
	+ 603263665.2846;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM21(work_wait &parameters) {
  double actual_remaining = 
	0.1933 * parameters.work_so_far 
	+ 0.4795 * parameters.wait_so_far 
	+ 122592.608 * parameters.num_locks_so_far 
	+ 159919.7858 * parameters.total_wait_locks 
	- 0.0057 * parameters.mean_wait_of_all 
	- 568724025.0165 * parameters.cpu_usage 
	+ 0.0025 * parameters.avg_work_of_same_past_second 
	+ 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0047 * parameters.avg_latency_of_same_last_20 
	- 0.0015 * parameters.max_latency_of_same_last_50 
	+ 920701938.0577;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM22(work_wait &parameters) {
  double actual_remaining = 
	0.0871 * parameters.work_so_far 
	+ 0.0334 * parameters.wait_so_far 
	+ 464226.5356 * parameters.num_locks_so_far 
	- 13834.7286 * parameters.total_wait_locks 
	- 0.6558 * parameters.mean_wait_of_all 
	- 13994440.3357 * parameters.cpu_usage 
	+ 0.0025 * parameters.avg_work_of_same_past_second 
	+ 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0047 * parameters.avg_latency_of_same_last_20 
	- 0.0015 * parameters.max_latency_of_same_last_50 
	+ 611157396.3822;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM23(work_wait &parameters) {
  double actual_remaining = 
	0.0417 * parameters.work_so_far 
	+ 0.5498 * parameters.wait_so_far 
	- 41316521.6457 * parameters.num_locks_so_far 
	- 1499989.8917 * parameters.total_wait_locks 
	+ 6.1897 * parameters.mean_wait_of_all 
	- 13994440.3357 * parameters.cpu_usage 
	+ 0.0025 * parameters.avg_work_of_same_past_second 
	- 1.2075 * parameters.avg_wait_of_same_past_second 
	+ 0.0047 * parameters.avg_latency_of_same_last_20 
	+ 0.0878 * parameters.max_latency_of_same_last_50 
	+ 1205895884.0768;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM24(work_wait &parameters) {
  double actual_remaining = 
	29.4569 * parameters.work_so_far 
	+ 1.6088 * parameters.wait_so_far 
	- 16878674.3444 * parameters.num_locks_so_far 
	- 363358.9036 * parameters.total_wait_locks 
	+ 1.6854 * parameters.mean_wait_of_all 
	- 23491970.8072 * parameters.cpu_usage 
	- 0.0094 * parameters.avg_work_of_same_past_second 
	- 0.4397 * parameters.avg_wait_of_same_past_second 
	+ 0.0147 * parameters.avg_latency_of_same_last_20 
	- 0.0043 * parameters.max_latency_of_same_last_50 
	+ 288923271.8004;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM25(work_wait &parameters) {
  double actual_remaining = 
	0.7864 * parameters.work_so_far 
	+ 1.3534 * parameters.wait_so_far 
	- 20099123.1445 * parameters.num_locks_so_far 
	- 704134.0857 * parameters.total_wait_locks 
	- 0.2615 * parameters.mean_wait_of_all 
	- 91132312.3236 * parameters.cpu_usage 
	- 0.1138 * parameters.avg_work_of_same_past_second 
	+ 0.1068 * parameters.avg_wait_of_same_past_second 
	+ 0.0597 * parameters.avg_latency_of_same_last_20 
	- 0.0221 * parameters.max_latency_of_same_last_50 
	+ 936164545.7232;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM26(work_wait &parameters) {
  double actual_remaining = 
	1.5474 * parameters.work_so_far 
	+ 0.3253 * parameters.wait_so_far 
	- 37336752.6207 * parameters.num_locks_so_far 
	+ 243928.863 * parameters.total_wait_locks 
	- 1.5416 * parameters.mean_wait_of_all 
	- 93990185.35 * parameters.cpu_usage 
	- 0.5284 * parameters.avg_work_of_same_past_second 
	+ 0.5164 * parameters.avg_wait_of_same_past_second 
	+ 0.1973 * parameters.avg_latency_of_same_last_20 
	- 0.0859 * parameters.max_latency_of_same_last_50 
	+ 1233723334.8042;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM27(work_wait &parameters) {
  double actual_remaining = 
	1.2676 * parameters.work_so_far 
	+ 1.4431 * parameters.wait_so_far 
	- 26223395.8149 * parameters.num_locks_so_far 
	+ 186578.6422 * parameters.total_wait_locks 
	- 1.0667 * parameters.mean_wait_of_all 
	- 93990185.35 * parameters.cpu_usage 
	- 1.9176 * parameters.avg_work_of_same_past_second 
	+ 2.369 * parameters.avg_wait_of_same_past_second 
	+ 0.3896 * parameters.avg_latency_of_same_last_20 
	- 0.2723 * parameters.max_latency_of_same_last_50 
	+ 1153176871.5222;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM28(work_wait &parameters) {
  double actual_remaining = 
	3.426 * parameters.work_so_far 
	+ 1.097 * parameters.wait_so_far 
	- 3454495.4088 * parameters.num_locks_so_far 
	- 148940.8102 * parameters.total_wait_locks 
	+ 0.6961 * parameters.mean_wait_of_all 
	- 350409090.0837 * parameters.cpu_usage 
	- 0.0097 * parameters.avg_work_of_same_past_second 
	- 0.2705 * parameters.avg_wait_of_same_past_second 
	+ 0.1521 * parameters.avg_latency_of_same_last_20 
	- 0.0577 * parameters.max_latency_of_same_last_50 
	+ 572405886.5297;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM29(work_wait &parameters) {
  double actual_remaining = 
	6.8815 * parameters.work_so_far 
	+ 0.8397 * parameters.wait_so_far 
	- 10050215.917 * parameters.num_locks_so_far 
	- 250.8977 * parameters.total_wait_locks 
	- 0.3416 * parameters.mean_wait_of_all 
	- 8912686.3861 * parameters.cpu_usage 
	+ 0.3022 * parameters.avg_work_of_same_past_second 
	+ 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.1547 * parameters.avg_latency_of_same_last_20 
	- 0.0017 * parameters.max_latency_of_same_last_50 
	+ 269322740.8678;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM30(work_wait &parameters) {
  double actual_remaining = 
	0.2142 * parameters.work_so_far 
	+ 0.043 * parameters.wait_so_far 
	+ 4473784.3783 * parameters.num_locks_so_far 
	- 92926.9668 * parameters.total_wait_locks 
	+ 0.4807 * parameters.mean_wait_of_all 
	- 6107620.0499 * parameters.cpu_usage 
	- 1.3905 * parameters.avg_work_of_same_past_second 
	+ 2.1989 * parameters.avg_wait_of_same_past_second 
	+ 0.0746 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 240751694.7864;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM31(work_wait &parameters) {
  double actual_remaining = 
	1.308 * parameters.work_so_far 
	+ 0.817 * parameters.wait_so_far 
	+ 1487016.9682 * parameters.num_locks_so_far 
	- 824929.6324 * parameters.total_wait_locks 
	+ 3.4524 * parameters.mean_wait_of_all 
	- 6107620.0499 * parameters.cpu_usage 
	- 0.0766 * parameters.avg_work_of_same_past_second 
	+ 0.0962 * parameters.avg_wait_of_same_past_second 
	+ 0.4767 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 281829715.9495;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM32(work_wait &parameters) {
  double actual_remaining = 
	0.8042 * parameters.work_so_far 
	+ 0.7203 * parameters.wait_so_far 
	- 4125484.1673 * parameters.num_locks_so_far 
	+ 70002.4348 * parameters.total_wait_locks 
	+ 0.0249 * parameters.mean_wait_of_all 
	- 254301604.4254 * parameters.cpu_usage 
	- 0.01 * parameters.avg_work_of_same_past_second 
	+ 0.0091 * parameters.avg_wait_of_same_past_second 
	+ 0.1527 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 589925934.1206;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM33(work_wait &parameters) {
  double actual_remaining = 
	0.151 * parameters.work_so_far 
	+ 0.1299 * parameters.wait_so_far 
	- 21038216.5915 * parameters.num_locks_so_far 
	- 2417506.1437 * parameters.total_wait_locks 
	+ 9.4589 * parameters.mean_wait_of_all 
	- 25262491.3802 * parameters.cpu_usage 
	- 1.2815 * parameters.avg_work_of_same_past_second 
	+ 0.013 * parameters.avg_wait_of_same_past_second 
	+ 0.6164 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 1247360712.0363;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM34(work_wait &parameters) {
  double actual_remaining = 
	0.4963 * parameters.work_so_far 
	+ 0.678 * parameters.wait_so_far 
	+ 8313389.5482 * parameters.num_locks_so_far 
	- 118308.0633 * parameters.total_wait_locks 
	+ 0.4343 * parameters.mean_wait_of_all 
	- 422384583.9027 * parameters.cpu_usage 
	- 0.3219 * parameters.avg_work_of_same_past_second 
	+ 0.013 * parameters.avg_wait_of_same_past_second 
	+ 0.1665 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 526350022.2514;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM35(work_wait &parameters) {
  double actual_remaining = 
	1.3744 * parameters.work_so_far 
	+ 0.2351 * parameters.wait_so_far 
	- 18898472.0178 * parameters.num_locks_so_far 
	- 169869.7086 * parameters.total_wait_locks 
	+ 0.6221 * parameters.mean_wait_of_all 
	- 57920248.6494 * parameters.cpu_usage 
	- 0.6682 * parameters.avg_work_of_same_past_second 
	+ 2.5275 * parameters.avg_wait_of_same_past_second 
	+ 0.0561 * parameters.avg_latency_of_same_last_20 
	+ 0.0209 * parameters.max_latency_of_same_last_50 
	+ 236220374.5166;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM36(work_wait &parameters) {
  double actual_remaining = 
	0.8041 * parameters.work_so_far 
	+ 0.5065 * parameters.wait_so_far 
	- 9393589.8966 * parameters.num_locks_so_far 
	- 263850.2073 * parameters.total_wait_locks 
	+ 0.6221 * parameters.mean_wait_of_all 
	- 57920248.6494 * parameters.cpu_usage 
	- 0.1052 * parameters.avg_work_of_same_past_second 
	+ 0.2966 * parameters.avg_wait_of_same_past_second 
	+ 0.0561 * parameters.avg_latency_of_same_last_20 
	+ 0.0209 * parameters.max_latency_of_same_last_50 
	+ 657475852.5834;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM37(work_wait &parameters) {
  double actual_remaining = 
	0.645 * parameters.work_so_far 
	+ 0.315 * parameters.wait_so_far 
	- 7456307.1934 * parameters.num_locks_so_far 
	- 169869.7086 * parameters.total_wait_locks 
	+ 0.6221 * parameters.mean_wait_of_all 
	- 57920248.6494 * parameters.cpu_usage 
	- 0.1052 * parameters.avg_work_of_same_past_second 
	+ 0.013 * parameters.avg_wait_of_same_past_second 
	+ 0.1718 * parameters.avg_latency_of_same_last_20 
	+ 0.0346 * parameters.max_latency_of_same_last_50 
	+ 596212954.95;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM38(work_wait &parameters) {
  double actual_remaining = 
	0.0496 * parameters.work_so_far 
	- 0.0796 * parameters.wait_so_far 
	+ 254599.0773 * parameters.num_locks_so_far 
	- 27651.0098 * parameters.total_wait_locks 
	+ 0.9641 * parameters.mean_wait_of_all 
	- 429694923.0802 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0128 * parameters.avg_wait_of_same_past_second 
	+ 0.2022 * parameters.avg_latency_of_same_last_20 
	- 0.1078 * parameters.max_latency_of_same_last_50 
	+ 707895037.0216;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM39(work_wait &parameters) {
  double actual_remaining = 
	0.1703 * parameters.work_so_far 
	+ 0.3802 * parameters.wait_so_far 
	+ 15790304.9309 * parameters.num_locks_so_far 
	- 272401.6846 * parameters.total_wait_locks 
	+ 1.2881 * parameters.mean_wait_of_all 
	- 934363042.3918 * parameters.cpu_usage 
	- 0.1017 * parameters.avg_work_of_same_past_second 
	- 0.0039 * parameters.avg_wait_of_same_past_second 
	+ 0.0214 * parameters.avg_latency_of_same_last_20 
	- 0.1158 * parameters.max_latency_of_same_last_50 
	+ 1371295256.0016;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM40(work_wait &parameters) {
  double actual_remaining = 
	0.1703 * parameters.work_so_far 
	+ 0.4472 * parameters.wait_so_far 
	+ 2077545.0822 * parameters.num_locks_so_far 
	- 2091233.6064 * parameters.total_wait_locks 
	+ 11.5915 * parameters.mean_wait_of_all 
	- 748415088.7049 * parameters.cpu_usage 
	- 0.7467 * parameters.avg_work_of_same_past_second 
	- 0.0039 * parameters.avg_wait_of_same_past_second 
	+ 0.0214 * parameters.avg_latency_of_same_last_20 
	- 0.0359 * parameters.max_latency_of_same_last_50 
	+ 995928399.1607;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM41(work_wait &parameters) {
  double actual_remaining = 
	0.1703 * parameters.work_so_far 
	+ 1.2811 * parameters.wait_so_far 
	+ 2077545.0822 * parameters.num_locks_so_far 
	- 3434974.925 * parameters.total_wait_locks 
	+ 19.2525 * parameters.mean_wait_of_all 
	- 1120682871.1697 * parameters.cpu_usage 
	- 1.1898 * parameters.avg_work_of_same_past_second 
	- 0.0039 * parameters.avg_wait_of_same_past_second 
	- 1.8294 * parameters.avg_latency_of_same_last_20 
	- 0.0359 * parameters.max_latency_of_same_last_50 
	+ 1996169803.7813;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM42(work_wait &parameters) {
  double actual_remaining = 
	0.8202 * parameters.work_so_far 
	+ 5.0618 * parameters.wait_so_far 
	+ 49948474.9969 * parameters.num_locks_so_far 
	- 322471.1145 * parameters.total_wait_locks 
	+ 1.4585 * parameters.mean_wait_of_all 
	- 94157632.4018 * parameters.cpu_usage 
	- 0.0961 * parameters.avg_work_of_same_past_second 
	- 0.0039 * parameters.avg_wait_of_same_past_second 
	+ 0.0214 * parameters.avg_latency_of_same_last_20 
	- 0.0042 * parameters.max_latency_of_same_last_50 
	- 1203508668.0824;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM43(work_wait &parameters) {
  double actual_remaining = 
	-0.7526 * parameters.work_so_far 
	+ 0.1105 * parameters.wait_so_far 
	+ 4430782.8077 * parameters.num_locks_so_far 
	- 322471.1145 * parameters.total_wait_locks 
	+ 1.4585 * parameters.mean_wait_of_all 
	- 94157632.4018 * parameters.cpu_usage 
	- 0.0961 * parameters.avg_work_of_same_past_second 
	- 0.0039 * parameters.avg_wait_of_same_past_second 
	+ 0.0214 * parameters.avg_latency_of_same_last_20 
	- 0.0042 * parameters.max_latency_of_same_last_50 
	+ 961364452.0577;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM44(work_wait &parameters) {
  double actual_remaining = 
	0.8671 * parameters.work_so_far 
	+ 0.6536 * parameters.wait_so_far 
	+ 1097810.6157 * parameters.num_locks_so_far 
	- 930590.1786 * parameters.total_wait_locks 
	+ 3.7246 * parameters.mean_wait_of_all 
	- 340043422.9451 * parameters.cpu_usage 
	- 0.1991 * parameters.avg_work_of_same_past_second 
	- 0.0039 * parameters.avg_wait_of_same_past_second 
	+ 0.3382 * parameters.avg_latency_of_same_last_20 
	- 0.0473 * parameters.max_latency_of_same_last_50 
	+ 548572173.5359;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM45(work_wait &parameters) {
  double actual_remaining = 
	1.4675 * parameters.work_so_far 
	+ 0.9004 * parameters.wait_so_far 
	- 5787948.4125 * parameters.num_locks_so_far 
	- 1685902.6176 * parameters.total_wait_locks 
	+ 7.5854 * parameters.mean_wait_of_all 
	- 372713852.3312 * parameters.cpu_usage 
	- 0.0117 * parameters.avg_work_of_same_past_second 
	- 0.0039 * parameters.avg_wait_of_same_past_second 
	+ 0.2913 * parameters.avg_latency_of_same_last_20 
	- 0.004 * parameters.max_latency_of_same_last_50 
	+ 461184976.1899;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
new_order_estimate(work_wait &parameters){

  if (parameters.total_wait_locks <= 184.5) {

    if (parameters.total_wait_locks <= 90.5) {

      if (parameters.work_so_far <= 61593254.5) {
        return new_order_LM1(parameters);
      } else {
        return new_order_LM2(parameters);
      }
    } else {

      if (parameters.work_so_far <= 8102958) {

        if (parameters.work_so_far <= 43522.5) {
          return new_order_LM3(parameters);
        } else {

          if (parameters.avg_wait_of_same_past_second <= 63502550) {

            if (parameters.wait_so_far <= 115776322.5) {

              if (parameters.work_so_far <= 96738) {

                if (parameters.avg_wait_of_same_past_second <= 33338800) {
                  return new_order_LM4(parameters);
                } else {
                  return new_order_LM5(parameters);
                }
              } else {
                return new_order_LM6(parameters);
              }
            } else {
              return new_order_LM7(parameters);
            }
          } else {
            return new_order_LM8(parameters);
          }
        }
      } else {

        if (parameters.wait_so_far <= 137290415.5) {

          if (parameters.work_so_far <= 100782767.5) {

            if (parameters.num_locks_so_far <= 21.5) {
              return new_order_LM9(parameters);
            } else {
              return new_order_LM10(parameters);
            }
          } else {
            return new_order_LM11(parameters);
          }
        } else {

          if (parameters.wait_so_far <= 463228488.5) {
            return new_order_LM12(parameters);
          } else {
            return new_order_LM13(parameters);
          }
        }
      }
    }
  } else {

    if (parameters.work_so_far <= 1128005) {

      if (parameters.wait_so_far <= 262085756.5) {

        if (parameters.mean_wait_of_all <= 99701850) {

          if (parameters.wait_so_far <= 135527.5) {

            if (parameters.wait_so_far <= 11738.5) {
              return new_order_LM14(parameters);
            } else {
              return new_order_LM15(parameters);
            }
          } else {
            return new_order_LM16(parameters);
          }
        } else {

          if (parameters.mean_wait_of_all <= 111285000) {
            return new_order_LM17(parameters);
          } else {
            return new_order_LM18(parameters);
          }
        }
      } else {
        return new_order_LM19(parameters);
      }
    } else {

      if (parameters.wait_so_far <= 317785097.5) {

        if (parameters.work_so_far <= 52511364.5) {

          if (parameters.num_locks_so_far <= 14.5) {

            if (parameters.work_so_far <= 9081891) {
              return new_order_LM20(parameters);
            } else {

              if (parameters.work_so_far <= 18726338.5) {
                return new_order_LM21(parameters);
              } else {

                if (parameters.num_locks_so_far <= 9.5) {
                  return new_order_LM22(parameters);
                } else {
                  return new_order_LM23(parameters);
                }
              }
            }
          } else {

            if (parameters.wait_so_far <= 92380396) {

              if (parameters.work_so_far <= 11852491) {
                return new_order_LM24(parameters);
              } else {

                if (parameters.num_locks_so_far <= 23.5) {

                  if (parameters.mean_wait_of_all <= 92844650) {
                    return new_order_LM25(parameters);
                  } else {

                    if (parameters.avg_latency_of_same_last_20 <= 330516500) {
                      return new_order_LM26(parameters);
                    } else {
                      return new_order_LM27(parameters);
                    }
                  }
                } else {
                  return new_order_LM28(parameters);
                }
              }
            } else {
              return new_order_LM29(parameters);
            }
          }
        } else {

          if (parameters.work_so_far <= 317343705.5) {

            if (parameters.num_locks_so_far <= 13.5) {

              if (parameters.num_locks_so_far <= 4.5) {
                return new_order_LM30(parameters);
              } else {
                return new_order_LM31(parameters);
              }
            } else {
              return new_order_LM32(parameters);
            }
          } else {

            if (parameters.work_so_far <= 607263794.5) {

              if (parameters.num_locks_so_far <= 29.5) {
                return new_order_LM33(parameters);
              } else {
                return new_order_LM34(parameters);
              }
            } else {

              if (parameters.cpu_usage <= 0.917) {

                if (parameters.work_so_far <= 706169951.5) {
                  return new_order_LM35(parameters);
                } else {
                  return new_order_LM36(parameters);
                }
              } else {
                return new_order_LM37(parameters);
              }
            }
          }
        }
      } else {

        if (parameters.num_locks_so_far <= 4.5) {
          return new_order_LM38(parameters);
        } else {

          if (parameters.wait_so_far <= 696456994.5) {

            if (parameters.num_locks_so_far <= 12.5) {

              if (parameters.work_so_far <= 10877838.5) {

                if (parameters.mean_wait_of_all <= 126687500) {
                  return new_order_LM39(parameters);
                } else {

                  if (parameters.avg_latency_of_same_last_20 <= 487650500) {
                    return new_order_LM40(parameters);
                  } else {
                    return new_order_LM41(parameters);
                  }
                }
              } else {

                if (parameters.wait_so_far <= 400602944.5) {
                  return new_order_LM42(parameters);
                } else {
                  return new_order_LM43(parameters);
                }
              }
            } else {
              return new_order_LM44(parameters);
            }
          } else {
            return new_order_LM45(parameters);
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
	80.9682 * parameters.work_so_far 
	+ 0.0007 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	+ 2477.9955 * parameters.total_wait_locks 
	- 199001.1269 * parameters.cpu_usage 
	- 0.0014 * parameters.avg_work_of_same_past_second 
	- 0.0007 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 5190796.7;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM2(work_wait &parameters) {
  double actual_remaining = 
	3122.8681 * parameters.work_so_far 
	+ 0.0006 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	+ 99922.6142 * parameters.total_wait_locks 
	- 199001.1269 * parameters.cpu_usage 
	- 0.0014 * parameters.avg_work_of_same_past_second 
	- 0.0416 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 16939251.1739;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM3(work_wait &parameters) {
  double actual_remaining = 
	0.1875 * parameters.work_so_far 
	- 0.0114 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	+ 36064.3146 * parameters.total_wait_locks 
	- 14260535.1459 * parameters.cpu_usage 
	- 0.1653 * parameters.avg_work_of_same_past_second 
	- 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0121 * parameters.avg_latency_of_same_last_20 
	+ 33853392.4281;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM4(work_wait &parameters) {
  double actual_remaining = 
	3.8122 * parameters.work_so_far 
	- 0.0216 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 204140.2077 * parameters.total_wait_locks 
	+ 1.1781 * parameters.mean_wait_of_all 
	+ 70605938.2914 * parameters.cpu_usage 
	- 0.1745 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.0018 * parameters.avg_latency_of_same_last_20 
	- 64778946.2408;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM5(work_wait &parameters) {
  double actual_remaining = 
	101.4108 * parameters.work_so_far 
	- 0.0018 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	+ 43313.8229 * parameters.total_wait_locks 
	- 0.263 * parameters.mean_wait_of_all 
	+ 7577852.1729 * parameters.cpu_usage 
	+ 0.0277 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.0748 * parameters.avg_latency_of_same_last_20 
	+ 51930397.7507;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM6(work_wait &parameters) {
  double actual_remaining = 
	599.2234 * parameters.work_so_far 
	- 0.0018 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 235057.4258 * parameters.total_wait_locks 
	- 0.3081 * parameters.mean_wait_of_all 
	+ 7577852.1729 * parameters.cpu_usage 
	+ 0.0277 * parameters.avg_work_of_same_past_second 
	+ 0.3366 * parameters.avg_wait_of_same_past_second 
	- 0.2589 * parameters.avg_latency_of_same_last_20 
	+ 151573255.401;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM7(work_wait &parameters) {
  double actual_remaining = 
	125.8605 * parameters.work_so_far 
	- 0.0018 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	+ 22943.8736 * parameters.total_wait_locks 
	- 0.3561 * parameters.mean_wait_of_all 
	+ 7577852.1729 * parameters.cpu_usage 
	+ 0.0277 * parameters.avg_work_of_same_past_second 
	- 0.0521 * parameters.avg_wait_of_same_past_second 
	- 0.0967 * parameters.avg_latency_of_same_last_20 
	+ 104256851.9557;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM8(work_wait &parameters) {
  double actual_remaining = 
	61.6768 * parameters.work_so_far 
	- 0.0018 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	+ 141089.3796 * parameters.total_wait_locks 
	- 0.5894 * parameters.mean_wait_of_all 
	+ 1281647696.7215 * parameters.cpu_usage 
	- 0.1762 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.0471 * parameters.avg_latency_of_same_last_20 
	- 1142335502.449;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM9(work_wait &parameters) {
  double actual_remaining = 
	61.6768 * parameters.work_so_far 
	- 0.0018 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	+ 145002.1466 * parameters.total_wait_locks 
	- 0.3694 * parameters.mean_wait_of_all 
	+ 571510406.3174 * parameters.cpu_usage 
	- 0.3867 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.0471 * parameters.avg_latency_of_same_last_20 
	- 499853370.8529;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM10(work_wait &parameters) {
  double actual_remaining = 
	31.6708 * parameters.work_so_far 
	- 0.0123 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 91109.2519 * parameters.total_wait_locks 
	+ 0.4779 * parameters.mean_wait_of_all 
	- 307515.555 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 12402842.2026;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM11(work_wait &parameters) {
  double actual_remaining = 
	-438.1914 * parameters.work_so_far 
	- 0.0109 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 199985.2783 * parameters.total_wait_locks 
	+ 0.9241 * parameters.mean_wait_of_all 
	- 74310518.7483 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_work_of_same_past_second 
	+ 0.0037 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 93180793.2936;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM12(work_wait &parameters) {
  double actual_remaining = 
	-380.3496 * parameters.work_so_far 
	- 0.0097 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 866465.8406 * parameters.total_wait_locks 
	+ 2.7566 * parameters.mean_wait_of_all 
	- 282748704.7425 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_work_of_same_past_second 
	+ 0.0037 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 375489427.4979;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM13(work_wait &parameters) {
  double actual_remaining = 
	-751.5732 * parameters.work_so_far 
	- 0.001 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 352613.577 * parameters.total_wait_locks 
	+ 1.3819 * parameters.mean_wait_of_all 
	- 2510335.4832 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_work_of_same_past_second 
	+ 0.0037 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 44754813.1732;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM14(work_wait &parameters) {
  double actual_remaining = 
	7.1903 * parameters.work_so_far 
	- 0.0014 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 50706.1197 * parameters.total_wait_locks 
	+ 0.1804 * parameters.mean_wait_of_all 
	+ 13736309.2076 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_work_of_same_past_second 
	+ 0.0037 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0046 * parameters.max_latency_of_same_last_50 
	+ 24112452.301;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM15(work_wait &parameters) {
  double actual_remaining = 
	-3221.0402 * parameters.work_so_far 
	- 0.0428 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 50706.1197 * parameters.total_wait_locks 
	+ 0.1804 * parameters.mean_wait_of_all 
	+ 39221242.0558 * parameters.cpu_usage 
	+ 1.5187 * parameters.avg_work_of_same_past_second 
	+ 0.0037 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0881 * parameters.max_latency_of_same_last_50 
	+ 218003292.355;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM16(work_wait &parameters) {
  double actual_remaining = 
	-727.0744 * parameters.work_so_far 
	- 0.0008 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	+ 181827.2862 * parameters.total_wait_locks 
	- 0.6223 * parameters.mean_wait_of_all 
	- 2014436512.9865 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_work_of_same_past_second 
	+ 0.0037 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0094 * parameters.max_latency_of_same_last_50 
	+ 2058596799.1958;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM17(work_wait &parameters) {
  double actual_remaining = 
	10.1338 * parameters.work_so_far 
	+ 0.0042 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 175029.5094 * parameters.total_wait_locks 
	+ 0.8295 * parameters.mean_wait_of_all 
	- 139577044.694 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_work_of_same_past_second 
	+ 0.0322 * parameters.avg_wait_of_same_past_second 
	- 0.0716 * parameters.avg_latency_of_same_last_20 
	+ 0.0223 * parameters.max_latency_of_same_last_50 
	+ 144526926.7801;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM18(work_wait &parameters) {
  double actual_remaining = 
	-144.4928 * parameters.work_so_far 
	+ 0.0342 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	+ 1110780.4139 * parameters.total_wait_locks 
	- 6.4503 * parameters.mean_wait_of_all 
	- 1765108.5018 * parameters.cpu_usage 
	+ 2.0056 * parameters.avg_work_of_same_past_second 
	- 1.8289 * parameters.avg_wait_of_same_past_second 
	+ 0.086 * parameters.avg_latency_of_same_last_20 
	+ 868870486.499;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM19(work_wait &parameters) {
  double actual_remaining = 
	1748.0777 * parameters.work_so_far 
	+ 0.3994 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	+ 720274.1665 * parameters.total_wait_locks 
	- 4.0412 * parameters.mean_wait_of_all 
	- 1765108.5018 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_work_of_same_past_second 
	+ 0.0665 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 134266556.6913;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM20(work_wait &parameters) {
  double actual_remaining = 
	6.0326 * parameters.work_so_far 
	+ 0.0636 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 7352.9725 * parameters.total_wait_locks 
	+ 0.8995 * parameters.mean_wait_of_all 
	+ 2556158.4873 * parameters.cpu_usage 
	- 0.0202 * parameters.avg_work_of_same_past_second 
	- 0.0009 * parameters.avg_wait_of_same_past_second 
	+ 0.0016 * parameters.avg_latency_of_same_last_20 
	- 0.0119 * parameters.max_latency_of_same_last_50 
	- 40365068.4534;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM21(work_wait &parameters) {
  double actual_remaining = 
	5.3194 * parameters.work_so_far 
	+ 0.0013 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 7352.9725 * parameters.total_wait_locks 
	+ 0.063 * parameters.mean_wait_of_all 
	+ 1879952.3067 * parameters.cpu_usage 
	- 0.0149 * parameters.avg_work_of_same_past_second 
	- 0.0009 * parameters.avg_wait_of_same_past_second 
	+ 0.0298 * parameters.avg_latency_of_same_last_20 
	+ 6003708.1152;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM22(work_wait &parameters) {
  double actual_remaining = 
	5.7826 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 45076.1886 * parameters.total_wait_locks 
	+ 0.246 * parameters.mean_wait_of_all 
	+ 1951622.9014 * parameters.cpu_usage 
	- 0.0158 * parameters.avg_work_of_same_past_second 
	- 0.0009 * parameters.avg_wait_of_same_past_second 
	+ 0.0032 * parameters.avg_latency_of_same_last_20 
	+ 6982532.2402;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM23(work_wait &parameters) {
  double actual_remaining = 
	5.7826 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 187514.6939 * parameters.total_wait_locks 
	+ 0.1803 * parameters.mean_wait_of_all 
	+ 1951622.9014 * parameters.cpu_usage 
	- 0.0158 * parameters.avg_work_of_same_past_second 
	- 0.0009 * parameters.avg_wait_of_same_past_second 
	+ 0.0024 * parameters.avg_latency_of_same_last_20 
	+ 77402645.6113;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM24(work_wait &parameters) {
  double actual_remaining = 
	3.2758 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 35031.3287 * parameters.total_wait_locks 
	+ 2.4065 * parameters.mean_wait_of_all 
	- 34768.0541 * parameters.cpu_usage 
	- 0.1458 * parameters.avg_work_of_same_past_second 
	+ 0.0116 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0.0015 * parameters.max_latency_of_same_last_50 
	- 235545570.5255;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM25(work_wait &parameters) {
  double actual_remaining = 
	3.2758 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	+ 655460.6767 * parameters.total_wait_locks 
	+ 30.5593 * parameters.mean_wait_of_all 
	- 34768.0541 * parameters.cpu_usage 
	- 4.0394 * parameters.avg_work_of_same_past_second 
	+ 0.0187 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0.0015 * parameters.max_latency_of_same_last_50 
	- 3667588063.6735;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM26(work_wait &parameters) {
  double actual_remaining = 
	629.2147 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	+ 1058035.447 * parameters.total_wait_locks 
	+ 46.9112 * parameters.mean_wait_of_all 
	- 34768.0541 * parameters.cpu_usage 
	- 6.0452 * parameters.avg_work_of_same_past_second 
	+ 0.0187 * parameters.avg_wait_of_same_past_second 
	+ 0.1368 * parameters.avg_latency_of_same_last_20 
	+ 0.0015 * parameters.max_latency_of_same_last_50 
	- 5759095771.4474;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM27(work_wait &parameters) {
  double actual_remaining = 
	3.2758 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 392504.3976 * parameters.total_wait_locks 
	+ 3.306 * parameters.mean_wait_of_all 
	- 34768.0541 * parameters.cpu_usage 
	- 0.6449 * parameters.avg_work_of_same_past_second 
	- 0.0405 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0.0108 * parameters.max_latency_of_same_last_50 
	- 140959471.8748;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM28(work_wait &parameters) {
  double actual_remaining = 
	-173.1683 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 417668.1914 * parameters.total_wait_locks 
	+ 3.306 * parameters.mean_wait_of_all 
	- 34768.0541 * parameters.cpu_usage 
	- 0.6449 * parameters.avg_work_of_same_past_second 
	- 0.0405 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0.0119 * parameters.max_latency_of_same_last_50 
	- 122822749.6366;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM29(work_wait &parameters) {
  double actual_remaining = 
	48.0811 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 173495.8146 * parameters.total_wait_locks 
	+ 3.306 * parameters.mean_wait_of_all 
	- 34768.0541 * parameters.cpu_usage 
	- 0.6449 * parameters.avg_work_of_same_past_second 
	- 0.0176 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0.004 * parameters.max_latency_of_same_last_50 
	- 244866239.1868;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM30(work_wait &parameters) {
  double actual_remaining = 
	3.2758 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	+ 63137.9858 * parameters.total_wait_locks 
	- 151.0701 * parameters.mean_wait_of_all 
	- 34768.0541 * parameters.cpu_usage 
	- 0.1445 * parameters.avg_work_of_same_past_second 
	+ 0.9139 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.1595 * parameters.max_latency_of_same_last_50 
	+ 17880810924.88;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM31(work_wait &parameters) {
  double actual_remaining = 
	3.2758 * parameters.work_so_far 
	+ 0.0082 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	+ 32855.8313 * parameters.total_wait_locks 
	- 151.0701 * parameters.mean_wait_of_all 
	- 34768.0541 * parameters.cpu_usage 
	- 0.1445 * parameters.avg_work_of_same_past_second 
	+ 0.9139 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.1595 * parameters.max_latency_of_same_last_50 
	+ 17897629537.2118;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM32(work_wait &parameters) {
  double actual_remaining = 
	3.2758 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	+ 579387.877 * parameters.total_wait_locks 
	- 97.1742 * parameters.mean_wait_of_all 
	- 34768.0541 * parameters.cpu_usage 
	- 0.1445 * parameters.avg_work_of_same_past_second 
	+ 1.9365 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.2325 * parameters.max_latency_of_same_last_50 
	+ 10960750702.402;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM33(work_wait &parameters) {
  double actual_remaining = 
	3.2758 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	+ 726571.0247 * parameters.total_wait_locks 
	- 97.1742 * parameters.mean_wait_of_all 
	- 34768.0541 * parameters.cpu_usage 
	- 0.1445 * parameters.avg_work_of_same_past_second 
	+ 0.6348 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.1841 * parameters.max_latency_of_same_last_50 
	+ 11333564292.6249;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM34(work_wait &parameters) {
  double actual_remaining = 
	3.2758 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	+ 619169.9312 * parameters.total_wait_locks 
	- 7.6491 * parameters.mean_wait_of_all 
	- 34768.0541 * parameters.cpu_usage 
	- 0.1445 * parameters.avg_work_of_same_past_second 
	+ 0.9053 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0.0046 * parameters.max_latency_of_same_last_50 
	+ 329288512.895;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM35(work_wait &parameters) {
  double actual_remaining = 
	3.2758 * parameters.work_so_far 
	- 0.0268 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 93348.5241 * parameters.total_wait_locks 
	- 5.9519 * parameters.mean_wait_of_all 
	- 34768.0541 * parameters.cpu_usage 
	- 0.1632 * parameters.avg_work_of_same_past_second 
	+ 0.0253 * parameters.avg_wait_of_same_past_second 
	+ 0.0078 * parameters.avg_latency_of_same_last_20 
	- 0.0176 * parameters.max_latency_of_same_last_50 
	+ 816265192.0828;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM36(work_wait &parameters) {
  double actual_remaining = 
	3.2758 * parameters.work_so_far 
	- 0.008 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	+ 343960.7163 * parameters.total_wait_locks 
	- 35.2341 * parameters.mean_wait_of_all 
	- 34768.0541 * parameters.cpu_usage 
	- 0.2275 * parameters.avg_work_of_same_past_second 
	+ 0.0253 * parameters.avg_wait_of_same_past_second 
	+ 0.1674 * parameters.avg_latency_of_same_last_20 
	+ 0.2515 * parameters.max_latency_of_same_last_50 
	+ 3590752576.2743;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM37(work_wait &parameters) {
  double actual_remaining = 
	404.7894 * parameters.work_so_far 
	- 0.0287 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 93348.5241 * parameters.total_wait_locks 
	- 38.9579 * parameters.mean_wait_of_all 
	- 34768.0541 * parameters.cpu_usage 
	- 0.2275 * parameters.avg_work_of_same_past_second 
	+ 0.0253 * parameters.avg_wait_of_same_past_second 
	+ 0.1797 * parameters.avg_latency_of_same_last_20 
	+ 0.1146 * parameters.max_latency_of_same_last_50 
	+ 4441314086.4689;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM38(work_wait &parameters) {
  double actual_remaining = 
	3.2758 * parameters.work_so_far 
	- 0.008 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 93348.5241 * parameters.total_wait_locks 
	- 1.7205 * parameters.mean_wait_of_all 
	- 34768.0541 * parameters.cpu_usage 
	- 0.2275 * parameters.avg_work_of_same_past_second 
	+ 0.0253 * parameters.avg_wait_of_same_past_second 
	+ 0.0778 * parameters.avg_latency_of_same_last_20 
	- 0.0296 * parameters.max_latency_of_same_last_50 
	+ 332754949.088;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM39(work_wait &parameters) {
  double actual_remaining = 
	1.8083 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 39242.9618 * parameters.total_wait_locks 
	+ 5.6527 * parameters.mean_wait_of_all 
	- 5024172.8574 * parameters.cpu_usage 
	+ 0.4963 * parameters.avg_work_of_same_past_second 
	- 0.0666 * parameters.avg_wait_of_same_past_second 
	+ 0.0939 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	- 671375107.9188;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM40(work_wait &parameters) {
  double actual_remaining = 
	1.8083 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 1210048.3381 * parameters.total_wait_locks 
	+ 4.6349 * parameters.mean_wait_of_all 
	- 5024172.8574 * parameters.cpu_usage 
	+ 0.3998 * parameters.avg_work_of_same_past_second 
	- 0.0539 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	+ 73029598.0553;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM41(work_wait &parameters) {
  double actual_remaining = 
	1.8083 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	+ 261117.9776 * parameters.total_wait_locks 
	+ 4.6349 * parameters.mean_wait_of_all 
	- 5024172.8574 * parameters.cpu_usage 
	+ 0.3998 * parameters.avg_work_of_same_past_second 
	- 0.0539 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	- 653177168.0185;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM42(work_wait &parameters) {
  double actual_remaining = 
	69.2558 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 39242.9618 * parameters.total_wait_locks 
	+ 6.5855 * parameters.mean_wait_of_all 
	- 5024172.8574 * parameters.cpu_usage 
	- 0.0055 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0262 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	- 779814494.5061;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM43(work_wait &parameters) {
  double actual_remaining = 
	2297.4102 * parameters.work_so_far 
	- 0.0063 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 59643.9343 * parameters.total_wait_locks 
	+ 0.2167 * parameters.mean_wait_of_all 
	- 11116393.4678 * parameters.cpu_usage 
	- 0.0055 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0017 * parameters.max_latency_of_same_last_50 
	+ 31544040.4152;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM44(work_wait &parameters) {
  double actual_remaining = 
	2176.589 * parameters.work_so_far 
	- 0.0063 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	+ 36613.8689 * parameters.total_wait_locks 
	+ 0.2167 * parameters.mean_wait_of_all 
	- 11116393.4678 * parameters.cpu_usage 
	- 0.0055 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0017 * parameters.max_latency_of_same_last_50 
	- 7640192.4901;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM45(work_wait &parameters) {
  double actual_remaining = 
	1.8083 * parameters.work_so_far 
	- 0.0063 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 59643.9343 * parameters.total_wait_locks 
	+ 0.2167 * parameters.mean_wait_of_all 
	- 11116393.4678 * parameters.cpu_usage 
	- 0.0055 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	- 0.0303 * parameters.avg_latency_of_same_last_20 
	- 0.0017 * parameters.max_latency_of_same_last_50 
	+ 98599605.711;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM46(work_wait &parameters) {
  double actual_remaining = 
	208.1551 * parameters.work_so_far 
	- 0.0063 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 59643.9343 * parameters.total_wait_locks 
	- 8.5337 * parameters.mean_wait_of_all 
	+ 65732420.8053 * parameters.cpu_usage 
	- 0.0055 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0114 * parameters.max_latency_of_same_last_50 
	+ 1102412755.04;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM47(work_wait &parameters) {
  double actual_remaining = 
	1.8083 * parameters.work_so_far 
	- 0.0063 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 59643.9343 * parameters.total_wait_locks 
	- 5.941 * parameters.mean_wait_of_all 
	+ 65732420.8053 * parameters.cpu_usage 
	- 0.0055 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0114 * parameters.max_latency_of_same_last_50 
	+ 780793245.8082;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM48(work_wait &parameters) {
  double actual_remaining = 
	72.3084 * parameters.work_so_far 
	- 0.0206 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 59643.9343 * parameters.total_wait_locks 
	+ 0.2167 * parameters.mean_wait_of_all 
	+ 24979261.7211 * parameters.cpu_usage 
	+ 0.4313 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	- 0.0233 * parameters.avg_latency_of_same_last_20 
	- 0.0122 * parameters.max_latency_of_same_last_50 
	+ 52154509.0351;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM49(work_wait &parameters) {
  double actual_remaining = 
	1.8083 * parameters.work_so_far 
	- 0.0063 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 59643.9343 * parameters.total_wait_locks 
	+ 0.2167 * parameters.mean_wait_of_all 
	+ 24979261.7211 * parameters.cpu_usage 
	+ 0.4313 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	- 0.0257 * parameters.avg_latency_of_same_last_20 
	- 0.0122 * parameters.max_latency_of_same_last_50 
	+ 51121602.8908;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM50(work_wait &parameters) {
  double actual_remaining = 
	1.8083 * parameters.work_so_far 
	- 0.0063 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 59643.9343 * parameters.total_wait_locks 
	+ 0.2167 * parameters.mean_wait_of_all 
	+ 24979261.7211 * parameters.cpu_usage 
	+ 0.6862 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	- 0.0193 * parameters.avg_latency_of_same_last_20 
	- 0.0122 * parameters.max_latency_of_same_last_50 
	+ 53905293.2773;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM51(work_wait &parameters) {
  double actual_remaining = 
	1.8083 * parameters.work_so_far 
	- 0.0063 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 59643.9343 * parameters.total_wait_locks 
	+ 0.2167 * parameters.mean_wait_of_all 
	+ 24979261.7211 * parameters.cpu_usage 
	+ 0.6862 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	- 0.0193 * parameters.avg_latency_of_same_last_20 
	- 0.0122 * parameters.max_latency_of_same_last_50 
	+ 51755724.9404;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM52(work_wait &parameters) {
  double actual_remaining = 
	1.8083 * parameters.work_so_far 
	- 0.0063 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 59643.9343 * parameters.total_wait_locks 
	+ 0.2167 * parameters.mean_wait_of_all 
	+ 24979261.7211 * parameters.cpu_usage 
	+ 0.6862 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	- 0.0193 * parameters.avg_latency_of_same_last_20 
	- 0.0122 * parameters.max_latency_of_same_last_50 
	+ 51372995.2664;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM53(work_wait &parameters) {
  double actual_remaining = 
	1.8083 * parameters.work_so_far 
	- 0.0063 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 59643.9343 * parameters.total_wait_locks 
	+ 0.2167 * parameters.mean_wait_of_all 
	+ 24979261.7211 * parameters.cpu_usage 
	- 0.0055 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0144 * parameters.max_latency_of_same_last_50 
	+ 50013894.0767;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM54(work_wait &parameters) {
  double actual_remaining = 
	1.8083 * parameters.work_so_far 
	- 0.0164 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 59643.9343 * parameters.total_wait_locks 
	+ 0.2167 * parameters.mean_wait_of_all 
	- 11116393.4678 * parameters.cpu_usage 
	- 0.0055 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0085 * parameters.avg_latency_of_same_last_20 
	- 0.0017 * parameters.max_latency_of_same_last_50 
	+ 42935315.2078;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM55(work_wait &parameters) {
  double actual_remaining = 
	1.8083 * parameters.work_so_far 
	- 0.0164 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 59643.9343 * parameters.total_wait_locks 
	+ 0.2167 * parameters.mean_wait_of_all 
	- 11116393.4678 * parameters.cpu_usage 
	- 0.0055 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0063 * parameters.avg_latency_of_same_last_20 
	- 0.0017 * parameters.max_latency_of_same_last_50 
	+ 46763035.0497;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM56(work_wait &parameters) {
  double actual_remaining = 
	9.3578 * parameters.work_so_far 
	+ 0.0017 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 506432.6349 * parameters.total_wait_locks 
	+ 4.1813 * parameters.mean_wait_of_all 
	+ 6696263.2314 * parameters.cpu_usage 
	- 0.1084 * parameters.avg_work_of_same_past_second 
	- 0.107 * parameters.avg_wait_of_same_past_second 
	+ 0.1225 * parameters.avg_latency_of_same_last_20 
	- 0.0611 * parameters.max_latency_of_same_last_50 
	- 181350418.143;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM57(work_wait &parameters) {
  double actual_remaining = 
	9.3578 * parameters.work_so_far 
	+ 0.0017 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 126885.1507 * parameters.total_wait_locks 
	- 1.9341 * parameters.mean_wait_of_all 
	+ 6696263.2314 * parameters.cpu_usage 
	- 0.1032 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0032 * parameters.max_latency_of_same_last_50 
	+ 338468736.341;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM58(work_wait &parameters) {
  double actual_remaining = 
	321.1128 * parameters.work_so_far 
	+ 0.0468 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 106709.2136 * parameters.total_wait_locks 
	- 8.4598 * parameters.mean_wait_of_all 
	+ 17859816.8612 * parameters.cpu_usage 
	+ 2.8106 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0025 * parameters.max_latency_of_same_last_50 
	+ 1026539683.6918;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM59(work_wait &parameters) {
  double actual_remaining = 
	618.6801 * parameters.work_so_far 
	+ 0.0295 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 1288036.1062 * parameters.total_wait_locks 
	- 4.1216 * parameters.mean_wait_of_all 
	+ 17859816.8612 * parameters.cpu_usage 
	+ 1.2158 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0025 * parameters.max_latency_of_same_last_50 
	+ 1149134855.7898;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM60(work_wait &parameters) {
  double actual_remaining = 
	655.8092 * parameters.work_so_far 
	+ 0.0305 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 1288036.1062 * parameters.total_wait_locks 
	- 4.1216 * parameters.mean_wait_of_all 
	+ 17859816.8612 * parameters.cpu_usage 
	+ 1.2158 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0025 * parameters.max_latency_of_same_last_50 
	+ 1143995638.2037;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM61(work_wait &parameters) {
  double actual_remaining = 
	600.0949 * parameters.work_so_far 
	+ 0.0305 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 1500641.5458 * parameters.total_wait_locks 
	- 4.1216 * parameters.mean_wait_of_all 
	+ 17859816.8612 * parameters.cpu_usage 
	+ 1.2158 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0025 * parameters.max_latency_of_same_last_50 
	+ 1249776400.1929;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM62(work_wait &parameters) {
  double actual_remaining = 
	322.3766 * parameters.work_so_far 
	+ 0.0305 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 567153.391 * parameters.total_wait_locks 
	- 4.1216 * parameters.mean_wait_of_all 
	+ 17859816.8612 * parameters.cpu_usage 
	+ 1.2158 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0279 * parameters.avg_latency_of_same_last_20 
	- 0.0025 * parameters.max_latency_of_same_last_50 
	+ 760639752.0079;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM63(work_wait &parameters) {
  double actual_remaining = 
	97.3831 * parameters.work_so_far 
	+ 0.0112 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 106709.2136 * parameters.total_wait_locks 
	+ 0.2167 * parameters.mean_wait_of_all 
	+ 17859816.8612 * parameters.cpu_usage 
	- 0.3038 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0025 * parameters.max_latency_of_same_last_50 
	+ 44220590.5442;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM64(work_wait &parameters) {
  double actual_remaining = 
	97.3831 * parameters.work_so_far 
	+ 0.0112 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 106709.2136 * parameters.total_wait_locks 
	+ 0.2167 * parameters.mean_wait_of_all 
	+ 17859816.8612 * parameters.cpu_usage 
	+ 0.3199 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0171 * parameters.max_latency_of_same_last_50 
	+ 46639753.464;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM65(work_wait &parameters) {
  double actual_remaining = 
	180.6136 * parameters.work_so_far 
	+ 0.0112 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 106709.2136 * parameters.total_wait_locks 
	+ 0.2167 * parameters.mean_wait_of_all 
	+ 17859816.8612 * parameters.cpu_usage 
	- 0.3038 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0204 * parameters.max_latency_of_same_last_50 
	+ 71726320.371;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM66(work_wait &parameters) {
  double actual_remaining = 
	97.3831 * parameters.work_so_far 
	+ 0.0112 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 106709.2136 * parameters.total_wait_locks 
	+ 0.2167 * parameters.mean_wait_of_all 
	+ 17859816.8612 * parameters.cpu_usage 
	- 0.3038 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0025 * parameters.max_latency_of_same_last_50 
	+ 48166431.9905;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM67(work_wait &parameters) {
  double actual_remaining = 
	1.8083 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 14083.7026 * parameters.total_wait_locks 
	+ 0.0755 * parameters.mean_wait_of_all 
	- 798191.8349 * parameters.cpu_usage 
	- 0.0051 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 28038992.9667;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM68(work_wait &parameters) {
  double actual_remaining = 
	193.5105 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 27440.9038 * parameters.num_locks_so_far 
	- 176939.391 * parameters.total_wait_locks 
	+ 0.1171 * parameters.mean_wait_of_all 
	- 34768.0541 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_work_of_same_past_second 
	+ 0.2109 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0.0121 * parameters.max_latency_of_same_last_50 
	+ 36197554.4697;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM69(work_wait &parameters) {
  double actual_remaining = 
	1.3039 * parameters.work_so_far 
	+ 0.3685 * parameters.wait_so_far 
	+ 261979.9657 * parameters.num_locks_so_far 
	+ 66293.7028 * parameters.total_wait_locks 
	- 0.18 * parameters.mean_wait_of_all 
	- 531084.983 * parameters.cpu_usage 
	+ 0 * parameters.avg_work_of_same_past_second 
	- 0.0258 * parameters.avg_wait_of_same_past_second 
	+ 0.0309 * parameters.avg_latency_of_same_last_20 
	+ 15113951.1663;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM70(work_wait &parameters) {
  double actual_remaining = 
	0.0672 * parameters.work_so_far 
	+ 0.3188 * parameters.wait_so_far 
	+ 3133890.8507 * parameters.num_locks_so_far 
	+ 285747.3055 * parameters.total_wait_locks 
	- 0.7089 * parameters.mean_wait_of_all 
	- 96110213.6059 * parameters.cpu_usage 
	+ 0 * parameters.avg_work_of_same_past_second 
	+ 0.0018 * parameters.avg_latency_of_same_last_20 
	+ 90759882.1385;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM71(work_wait &parameters) {
  double actual_remaining = 
	1.0906 * parameters.work_so_far 
	+ 0.1238 * parameters.wait_so_far 
	+ 772759.2153 * parameters.num_locks_so_far 
	- 24687.2333 * parameters.total_wait_locks 
	- 0.1432 * parameters.mean_wait_of_all 
	- 531084.983 * parameters.cpu_usage 
	+ 0 * parameters.avg_work_of_same_past_second 
	+ 0.0018 * parameters.avg_latency_of_same_last_20 
	+ 20838687.7757;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM72(work_wait &parameters) {
  double actual_remaining = 
	0.1161 * parameters.work_so_far 
	+ 0.1238 * parameters.wait_so_far 
	+ 772759.2153 * parameters.num_locks_so_far 
	- 55266.8119 * parameters.total_wait_locks 
	- 0.1432 * parameters.mean_wait_of_all 
	- 531084.983 * parameters.cpu_usage 
	+ 0 * parameters.avg_work_of_same_past_second 
	+ 0.0018 * parameters.avg_latency_of_same_last_20 
	+ 62714560.7648;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM73(work_wait &parameters) {
  double actual_remaining = 
	0.05 * parameters.work_so_far 
	- 17631.6137 * parameters.wait_so_far 
	+ 667034.6043 * parameters.num_locks_so_far 
	- 45257.0126 * parameters.total_wait_locks 
	+ 0.1745 * parameters.mean_wait_of_all 
	- 12910552.2476 * parameters.cpu_usage 
	+ 4.9604 * parameters.avg_work_of_same_past_second 
	- 0.0043 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	- 0.0267 * parameters.max_latency_of_same_last_50 
	+ 154035638.1496;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM74(work_wait &parameters) {
  double actual_remaining = 
	0.05 * parameters.work_so_far 
	- 3233.375 * parameters.wait_so_far 
	+ 667034.6043 * parameters.num_locks_so_far 
	- 45257.0126 * parameters.total_wait_locks 
	+ 0.1745 * parameters.mean_wait_of_all 
	- 12910552.2476 * parameters.cpu_usage 
	+ 0.0112 * parameters.avg_work_of_same_past_second 
	- 0.0043 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	- 0.0134 * parameters.max_latency_of_same_last_50 
	+ 101438240.5584;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM75(work_wait &parameters) {
  double actual_remaining = 
	0.5543 * parameters.work_so_far 
	+ 0.2737 * parameters.wait_so_far 
	+ 2459104.4803 * parameters.num_locks_so_far 
	- 10866.3551 * parameters.total_wait_locks 
	+ 0.0551 * parameters.mean_wait_of_all 
	- 114587475.9145 * parameters.cpu_usage 
	- 0.3734 * parameters.avg_work_of_same_past_second 
	- 0.0043 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	- 0.0143 * parameters.max_latency_of_same_last_50 
	+ 160899567.538;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM76(work_wait &parameters) {
  double actual_remaining = 
	0.0404 * parameters.work_so_far 
	+ 0.0248 * parameters.wait_so_far 
	+ 236464.4552 * parameters.num_locks_so_far 
	+ 285805.1929 * parameters.total_wait_locks 
	- 0.0069 * parameters.mean_wait_of_all 
	- 483496.7229 * parameters.cpu_usage 
	+ 0.0327 * parameters.avg_work_of_same_past_second 
	- 0.2332 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 34782080.5685;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM77(work_wait &parameters) {
  double actual_remaining = 
	0.0142 * parameters.work_so_far 
	+ 0.5253 * parameters.wait_so_far 
	+ 1691632.4769 * parameters.num_locks_so_far 
	+ 1572.5918 * parameters.total_wait_locks 
	- 0.1517 * parameters.mean_wait_of_all 
	- 483496.7229 * parameters.cpu_usage 
	+ 0 * parameters.avg_work_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 47224310.8136;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM78(work_wait &parameters) {
  double actual_remaining = 
	0.0104 * parameters.work_so_far 
	+ 0.164 * parameters.wait_so_far 
	+ 546620.6489 * parameters.num_locks_so_far 
	+ 56703.3606 * parameters.total_wait_locks 
	- 0.0051 * parameters.mean_wait_of_all 
	+ 1822667.4813 * parameters.cpu_usage 
	+ 0.0137 * parameters.avg_work_of_same_past_second 
	+ 0.0014 * parameters.avg_latency_of_same_last_20 
	+ 8032816.0586;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM79(work_wait &parameters) {
  double actual_remaining = 
	1.235 * parameters.work_so_far 
	+ 0.8097 * parameters.wait_so_far 
	+ 1031584.596 * parameters.num_locks_so_far 
	+ 5689.629 * parameters.total_wait_locks 
	- 0.0121 * parameters.mean_wait_of_all 
	+ 5031725.6532 * parameters.cpu_usage 
	+ 0.0328 * parameters.avg_work_of_same_past_second 
	+ 0.0635 * parameters.avg_latency_of_same_last_20 
	- 1756966.4111;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM80(work_wait &parameters) {
  double actual_remaining = 
	0.0035 * parameters.work_so_far 
	+ 0.5374 * parameters.wait_so_far 
	+ 1031934.5003 * parameters.num_locks_so_far 
	+ 190737.0185 * parameters.total_wait_locks 
	- 0.5289 * parameters.mean_wait_of_all 
	- 0.024 * parameters.avg_work_of_same_past_second 
	- 0.1058 * parameters.avg_latency_of_same_last_20 
	- 0.0408 * parameters.max_latency_of_same_last_50 
	+ 20747516.6219;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM81(work_wait &parameters) {
  double actual_remaining = 
	1.0312 * parameters.work_so_far 
	+ 0.8907 * parameters.wait_so_far 
	+ 1389928.3085 * parameters.num_locks_so_far 
	+ 31691.7338 * parameters.total_wait_locks 
	- 0.0018 * parameters.mean_wait_of_all 
	- 0.024 * parameters.avg_work_of_same_past_second 
	- 0.0022 * parameters.avg_latency_of_same_last_20 
	- 0.0073 * parameters.max_latency_of_same_last_50 
	+ 25544491.3555;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM82(work_wait &parameters) {
  double actual_remaining = 
	0.8101 * parameters.work_so_far 
	+ 0.6705 * parameters.wait_so_far 
	+ 1389928.3085 * parameters.num_locks_so_far 
	- 39760.6474 * parameters.total_wait_locks 
	+ 0.0747 * parameters.mean_wait_of_all 
	- 0.024 * parameters.avg_work_of_same_past_second 
	- 0.0022 * parameters.avg_latency_of_same_last_20 
	- 0.0018 * parameters.max_latency_of_same_last_50 
	+ 123399124.073;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM83(work_wait &parameters) {
  double actual_remaining = 
	0.8101 * parameters.work_so_far 
	+ 0.7929 * parameters.wait_so_far 
	+ 1389928.3085 * parameters.num_locks_so_far 
	- 26097.2193 * parameters.total_wait_locks 
	- 0.4142 * parameters.mean_wait_of_all 
	- 0.024 * parameters.avg_work_of_same_past_second 
	- 0.0022 * parameters.avg_latency_of_same_last_20 
	- 0.0018 * parameters.max_latency_of_same_last_50 
	+ 124482552.3782;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM84(work_wait &parameters) {
  double actual_remaining = 
	0.7637 * parameters.work_so_far 
	+ 0.4605 * parameters.wait_so_far 
	+ 1389928.3085 * parameters.num_locks_so_far 
	+ 3962.3224 * parameters.total_wait_locks 
	- 0.4039 * parameters.mean_wait_of_all 
	- 0.024 * parameters.avg_work_of_same_past_second 
	- 0.0022 * parameters.avg_latency_of_same_last_20 
	- 0.0495 * parameters.max_latency_of_same_last_50 
	+ 302507882.9194;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM85(work_wait &parameters) {
  double actual_remaining = 
	1.6325 * parameters.work_so_far 
	+ 0.4605 * parameters.wait_so_far 
	+ 1389928.3085 * parameters.num_locks_so_far 
	+ 3962.3224 * parameters.total_wait_locks 
	- 0.4039 * parameters.mean_wait_of_all 
	- 0.024 * parameters.avg_work_of_same_past_second 
	- 0.0022 * parameters.avg_latency_of_same_last_20 
	- 0.046 * parameters.max_latency_of_same_last_50 
	+ 281613001.1979;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM86(work_wait &parameters) {
  double actual_remaining = 
	0.8013 * parameters.work_so_far 
	+ 0.6336 * parameters.wait_so_far 
	+ 1389928.3085 * parameters.num_locks_so_far 
	+ 3962.3224 * parameters.total_wait_locks 
	- 0.4039 * parameters.mean_wait_of_all 
	- 0.024 * parameters.avg_work_of_same_past_second 
	+ 0.0053 * parameters.avg_latency_of_same_last_20 
	- 0.0285 * parameters.max_latency_of_same_last_50 
	+ 198309542.9679;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM87(work_wait &parameters) {
  double actual_remaining = 
	0.9744 * parameters.work_so_far 
	+ 0.7726 * parameters.wait_so_far 
	+ 1389928.3085 * parameters.num_locks_so_far 
	+ 3962.3224 * parameters.total_wait_locks 
	- 0.0995 * parameters.mean_wait_of_all 
	- 0.024 * parameters.avg_work_of_same_past_second 
	- 0.0022 * parameters.avg_latency_of_same_last_20 
	- 0.0018 * parameters.max_latency_of_same_last_50 
	+ 86364400.8429;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM88(work_wait &parameters) {
  double actual_remaining = 
	1.0355 * parameters.work_so_far 
	+ 0.8632 * parameters.wait_so_far 
	+ 1390503.7273 * parameters.num_locks_so_far 
	+ 3962.3224 * parameters.total_wait_locks 
	- 0.0018 * parameters.mean_wait_of_all 
	- 0.024 * parameters.avg_work_of_same_past_second 
	- 0.0022 * parameters.avg_latency_of_same_last_20 
	- 0.0018 * parameters.max_latency_of_same_last_50 
	+ 55514504.8743;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM89(work_wait &parameters) {
  double actual_remaining = 
	-0.149 * parameters.work_so_far 
	+ 0.1106 * parameters.wait_so_far 
	+ 2909202.2693 * parameters.num_locks_so_far 
	+ 634329.7569 * parameters.total_wait_locks 
	- 0.0018 * parameters.mean_wait_of_all 
	- 3.5082 * parameters.avg_work_of_same_past_second 
	- 0.041 * parameters.avg_wait_of_same_past_second 
	- 0.4219 * parameters.avg_latency_of_same_last_20 
	+ 0.1105 * parameters.max_latency_of_same_last_50 
	+ 244596606.8859;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM90(work_wait &parameters) {
  double actual_remaining = 
	-4.4529 * parameters.work_so_far 
	+ 0.1965 * parameters.wait_so_far 
	+ 2909202.2693 * parameters.num_locks_so_far 
	+ 116594.9712 * parameters.total_wait_locks 
	- 0.0018 * parameters.mean_wait_of_all 
	- 0.1463 * parameters.avg_work_of_same_past_second 
	- 0.1294 * parameters.avg_wait_of_same_past_second 
	- 0.1101 * parameters.avg_latency_of_same_last_20 
	+ 0.0266 * parameters.max_latency_of_same_last_50 
	+ 648683524.1243;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM91(work_wait &parameters) {
  double actual_remaining = 
	0.8717 * parameters.work_so_far 
	+ 0.9849 * parameters.wait_so_far 
	+ 5554355.0147 * parameters.num_locks_so_far 
	+ 27501.5391 * parameters.total_wait_locks 
	- 0.0018 * parameters.mean_wait_of_all 
	- 0.1759 * parameters.avg_work_of_same_past_second 
	- 0.0165 * parameters.avg_latency_of_same_last_20 
	- 20230420.0941;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
payment_estimate(work_wait &parameters){

  if (parameters.work_so_far <= 330986.5) {

    if (parameters.total_wait_locks <= 298.5) {

      if (parameters.work_so_far <= 11538.5) {

        if (parameters.work_so_far <= 7414) {
          return payment_LM1(parameters);
        } else {
          return payment_LM2(parameters);
        }
      } else {
        return payment_LM3(parameters);
      }
    } else {

      if (parameters.avg_latency_of_same_last_20 <= 347508500) {

        if (parameters.cpu_usage <= 0.931) {

          if (parameters.cpu_usage <= 0.919) {
            return payment_LM4(parameters);
          } else {

            if (parameters.wait_so_far <= 177894895) {

              if (parameters.avg_work_of_same_past_second <= 24752400) {
                return payment_LM5(parameters);
              } else {

                if (parameters.avg_wait_of_same_past_second <= 371807500) {
                  return payment_LM6(parameters);
                } else {
                  return payment_LM7(parameters);
                }
              }
            } else {

              if (parameters.cpu_usage <= 0.923) {
                return payment_LM8(parameters);
              } else {
                return payment_LM9(parameters);
              }
            }
          }
        } else {
          return payment_LM10(parameters);
        }
      } else {

        if (parameters.mean_wait_of_all <= 121619000) {

          if (parameters.mean_wait_of_all <= 114935500) {

            if (parameters.avg_wait_of_same_past_second <= 388004500) {

              if (parameters.work_so_far <= 35151) {

                if (parameters.cpu_usage <= 0.987) {

                  if (parameters.max_latency_of_same_last_50 <= 1056895000) {

                    if (parameters.mean_wait_of_all <= 92751200) {
                      return payment_LM11(parameters);
                    } else {
                      return payment_LM12(parameters);
                    }
                  } else {

                    if (parameters.max_latency_of_same_last_50 <= 1338180000) {
                      return payment_LM13(parameters);
                    } else {

                      if (parameters.cpu_usage <= 0.969) {
                        return payment_LM14(parameters);
                      } else {
                        return payment_LM15(parameters);
                      }
                    }
                  }
                } else {
                  return payment_LM16(parameters);
                }
              } else {

                if (parameters.avg_wait_of_same_past_second <= 369414000) {
                  return payment_LM17(parameters);
                } else {

                  if (parameters.wait_so_far <= 390184229.5) {
                    return payment_LM18(parameters);
                  } else {
                    return payment_LM19(parameters);
                  }
                }
              }
            } else {

              if (parameters.wait_so_far <= 263320532) {

                if (parameters.avg_work_of_same_past_second <= 32048400) {
                  return payment_LM20(parameters);
                } else {
                  return payment_LM21(parameters);
                }
              } else {

                if (parameters.mean_wait_of_all <= 101294000) {
                  return payment_LM22(parameters);
                } else {
                  return payment_LM23(parameters);
                }
              }
            }
          } else {

            if (parameters.mean_wait_of_all <= 117647500) {

              if (parameters.avg_wait_of_same_past_second <= 379701000) {
                return payment_LM24(parameters);
              } else {

                if (parameters.avg_work_of_same_past_second <= 38476800) {

                  if (parameters.total_wait_locks <= 460.5) {
                    return payment_LM25(parameters);
                  } else {
                    return payment_LM26(parameters);
                  }
                } else {

                  if (parameters.wait_so_far <= 2996238.5) {

                    if (parameters.max_latency_of_same_last_50 <= 1181165000) {
                      return payment_LM27(parameters);
                    } else {
                      return payment_LM28(parameters);
                    }
                  } else {
                    return payment_LM29(parameters);
                  }
                }
              }
            } else {

              if (parameters.avg_work_of_same_past_second <= 57755900) {

                if (parameters.mean_wait_of_all <= 118383500) {

                  if (parameters.avg_latency_of_same_last_20 <= 379473000) {

                    if (parameters.total_wait_locks <= 372.5) {
                      return payment_LM30(parameters);
                    } else {
                      return payment_LM31(parameters);
                    }
                  } else {

                    if (parameters.mean_wait_of_all <= 117680500) {
                      return payment_LM32(parameters);
                    } else {
                      return payment_LM33(parameters);
                    }
                  }
                } else {
                  return payment_LM34(parameters);
                }
              } else {

                if (parameters.max_latency_of_same_last_50 <= 1743300000) {
                  return payment_LM35(parameters);
                } else {

                  if (parameters.avg_work_of_same_past_second <= 114085500) {

                    if (parameters.total_wait_locks <= 468.5) {
                      return payment_LM36(parameters);
                    } else {
                      return payment_LM37(parameters);
                    }
                  } else {
                    return payment_LM38(parameters);
                  }
                }
              }
            }
          }
        } else {

          if (parameters.mean_wait_of_all <= 137250000) {

            if (parameters.mean_wait_of_all <= 128882000) {

              if (parameters.mean_wait_of_all <= 124071500) {

                if (parameters.avg_latency_of_same_last_20 <= 472740500) {

                  if (parameters.avg_work_of_same_past_second <= 39349700) {
                    return payment_LM39(parameters);
                  } else {

                    if (parameters.avg_wait_of_same_past_second <= 471005000) {
                      return payment_LM40(parameters);
                    } else {
                      return payment_LM41(parameters);
                    }
                  }
                } else {
                  return payment_LM42(parameters);
                }
              } else {

                if (parameters.cpu_usage <= 0.88) {

                  if (parameters.wait_so_far <= 489764221.5) {

                    if (parameters.wait_so_far <= 22727) {

                      if (parameters.wait_so_far <= 10885) {

                        if (parameters.work_so_far <= 28406.5) {
                          return payment_LM43(parameters);
                        } else {
                          return payment_LM44(parameters);
                        }
                      } else {
                        return payment_LM45(parameters);
                      }
                    } else {

                      if (parameters.cpu_usage <= 0.781) {

                        if (parameters.mean_wait_of_all <= 125614000) {
                          return payment_LM46(parameters);
                        } else {
                          return payment_LM47(parameters);
                        }
                      } else {

                        if (parameters.total_wait_locks <= 509.5) {

                          if (parameters.avg_work_of_same_past_second <= 36230750) {

                            if (parameters.avg_latency_of_same_last_20 <= 475764000) {
                              return payment_LM48(parameters);
                            } else {
                              return payment_LM49(parameters);
                            }
                          } else {

                            if (parameters.avg_work_of_same_past_second <= 48237200) {
                              return payment_LM50(parameters);
                            } else {

                              if (parameters.work_so_far <= 30123.5) {
                                return payment_LM51(parameters);
                              } else {
                                return payment_LM52(parameters);
                              }
                            }
                          }
                        } else {
                          return payment_LM53(parameters);
                        }
                      }
                    }
                  } else {

                    if (parameters.avg_latency_of_same_last_20 <= 544518500) {
                      return payment_LM54(parameters);
                    } else {
                      return payment_LM55(parameters);
                    }
                  }
                } else {

                  if (parameters.cpu_usage <= 0.948) {

                    if (parameters.max_latency_of_same_last_50 <= 1312680000) {
                      return payment_LM56(parameters);
                    } else {
                      return payment_LM57(parameters);
                    }
                  } else {

                    if (parameters.avg_work_of_same_past_second <= 44160250) {

                      if (parameters.avg_work_of_same_past_second <= 35747400) {
                        return payment_LM58(parameters);
                      } else {

                        if (parameters.avg_latency_of_same_last_20 <= 612053000) {

                          if (parameters.total_wait_locks <= 511.5) {

                            if (parameters.work_so_far <= 26112) {
                              return payment_LM59(parameters);
                            } else {
                              return payment_LM60(parameters);
                            }
                          } else {
                            return payment_LM61(parameters);
                          }
                        } else {
                          return payment_LM62(parameters);
                        }
                      }
                    } else {

                      if (parameters.wait_so_far <= 3408246) {
                        return payment_LM63(parameters);
                      } else {

                        if (parameters.total_wait_locks <= 521.5) {

                          if (parameters.work_so_far <= 28758.5) {
                            return payment_LM64(parameters);
                          } else {
                            return payment_LM65(parameters);
                          }
                        } else {
                          return payment_LM66(parameters);
                        }
                      }
                    }
                  }
                }
              }
            } else {
              return payment_LM67(parameters);
            }
          } else {
            return payment_LM68(parameters);
          }
        }
      }
    }
  } else {

    if (parameters.wait_so_far <= 224656599) {

      if (parameters.wait_so_far <= 65130147.5) {

        if (parameters.mean_wait_of_all <= 93703100) {

          if (parameters.work_so_far <= 8407797) {
            return payment_LM69(parameters);
          } else {

            if (parameters.work_so_far <= 38889344.5) {
              return payment_LM70(parameters);
            } else {

              if (parameters.mean_wait_of_all <= 70738200) {
                return payment_LM71(parameters);
              } else {
                return payment_LM72(parameters);
              }
            }
          }
        } else {

          if (parameters.mean_wait_of_all <= 125653500) {

            if (parameters.mean_wait_of_all <= 117708500) {

              if (parameters.wait_so_far <= 12329) {

                if (parameters.avg_wait_of_same_past_second <= 355102500) {
                  return payment_LM73(parameters);
                } else {
                  return payment_LM74(parameters);
                }
              } else {
                return payment_LM75(parameters);
              }
            } else {
              return payment_LM76(parameters);
            }
          } else {
            return payment_LM77(parameters);
          }
        }
      } else {

        if (parameters.num_locks_so_far <= 2.5) {
          return payment_LM78(parameters);
        } else {
          return payment_LM79(parameters);
        }
      }
    } else {

      if (parameters.wait_so_far <= 576359540) {

        if (parameters.num_locks_so_far <= 2.5) {
          return payment_LM80(parameters);
        } else {

          if (parameters.wait_so_far <= 404420345) {

            if (parameters.wait_so_far <= 337471499.5) {

              if (parameters.total_wait_locks <= 356) {
                return payment_LM81(parameters);
              } else {

                if (parameters.work_so_far <= 4003337) {

                  if (parameters.total_wait_locks <= 422) {
                    return payment_LM82(parameters);
                  } else {
                    return payment_LM83(parameters);
                  }
                } else {

                  if (parameters.avg_latency_of_same_last_20 <= 384996500) {

                    if (parameters.max_latency_of_same_last_50 <= 986609500) {
                      return payment_LM84(parameters);
                    } else {
                      return payment_LM85(parameters);
                    }
                  } else {
                    return payment_LM86(parameters);
                  }
                }
              }
            } else {
              return payment_LM87(parameters);
            }
          } else {
            return payment_LM88(parameters);
          }
        }
      } else {

        if (parameters.num_locks_so_far <= 2.5) {

          if (parameters.wait_so_far <= 947455310.5) {
            return payment_LM89(parameters);
          } else {
            return payment_LM90(parameters);
          }
        } else {
          return payment_LM91(parameters);
        }
      }
    }
  }
}
static
double
delivery_LM1(work_wait &parameters) {
  double actual_remaining = 
	3.8051 * parameters.work_so_far 
	+ 0.1946 * parameters.wait_so_far 
	- 6729763.2212 * parameters.num_locks_so_far 
	+ 410020.5611 * parameters.total_wait_locks 
	+ 0.1313 * parameters.mean_wait_of_all 
	+ 0.2213 * parameters.avg_work_of_same_past_second 
	+ 0.8286 * parameters.avg_wait_of_same_past_second 
	+ 0.0128 * parameters.avg_latency_of_same_last_20 
	- 0.1644 * parameters.max_latency_of_same_last_50 
	+ 259074150.4968;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM2(work_wait &parameters) {
  double actual_remaining = 
	5.4492 * parameters.work_so_far 
	+ 0.7495 * parameters.wait_so_far 
	- 1110997.9276 * parameters.num_locks_so_far 
	+ 63692.6576 * parameters.total_wait_locks 
	+ 4.6877 * parameters.mean_wait_of_all 
	+ 0.0435 * parameters.avg_work_of_same_past_second 
	+ 0.0223 * parameters.avg_wait_of_same_past_second 
	+ 0.0128 * parameters.avg_latency_of_same_last_20 
	- 0.0193 * parameters.max_latency_of_same_last_50 
	- 231329558.1916;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM3(work_wait &parameters) {
  double actual_remaining = 
	0.4148 * parameters.work_so_far 
	+ 0.3591 * parameters.wait_so_far 
	- 4893143.7116 * parameters.num_locks_so_far 
	- 77367.4355 * parameters.total_wait_locks 
	+ 2.5411 * parameters.mean_wait_of_all 
	- 0.1469 * parameters.avg_work_of_same_past_second 
	+ 0.0364 * parameters.avg_wait_of_same_past_second 
	+ 0.0449 * parameters.avg_latency_of_same_last_20 
	- 0.0132 * parameters.max_latency_of_same_last_50 
	+ 854600421.6875;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM4(work_wait &parameters) {
  double actual_remaining = 
	1.0118 * parameters.work_so_far 
	+ 0.9037 * parameters.wait_so_far 
	- 9372188.4032 * parameters.num_locks_so_far 
	- 77367.4355 * parameters.total_wait_locks 
	+ 0.9266 * parameters.mean_wait_of_all 
	- 0.0512 * parameters.avg_work_of_same_past_second 
	+ 0.0364 * parameters.avg_wait_of_same_past_second 
	+ 0.0449 * parameters.avg_latency_of_same_last_20 
	- 0.0132 * parameters.max_latency_of_same_last_50 
	+ 740678756.322;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM5(work_wait &parameters) {
  double actual_remaining = 
	0.9464 * parameters.work_so_far 
	+ 0.9557 * parameters.wait_so_far 
	- 10928571.4975 * parameters.num_locks_so_far 
	- 92591.3811 * parameters.total_wait_locks 
	+ 0.6494 * parameters.mean_wait_of_all 
	+ 0.0364 * parameters.avg_wait_of_same_past_second 
	+ 0.0449 * parameters.avg_latency_of_same_last_20 
	- 0.0132 * parameters.max_latency_of_same_last_50 
	+ 910732303.2384;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM6(work_wait &parameters) {
  double actual_remaining = 
	1.0296 * parameters.work_so_far 
	+ 0.9507 * parameters.wait_so_far 
	- 14382476.2392 * parameters.num_locks_so_far 
	- 84202.3705 * parameters.total_wait_locks 
	+ 0.5762 * parameters.mean_wait_of_all 
	- 402999425.8632 * parameters.cpu_usage 
	+ 0.0364 * parameters.avg_wait_of_same_past_second 
	+ 0.0753 * parameters.avg_latency_of_same_last_20 
	- 0.1793 * parameters.max_latency_of_same_last_50 
	+ 1676328870.0635;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
delivery_estimate(work_wait &parameters){

  if (parameters.work_so_far <= 178286799) {

    if (parameters.wait_so_far <= 672886899.5) {
      return delivery_LM1(parameters);
    } else {
      return delivery_LM2(parameters);
    }
  } else {

    if (parameters.avg_latency_of_same_last_20 <= 450000500) {

      if (parameters.work_so_far <= 473915433) {

        if (parameters.num_locks_so_far <= 46) {
          return delivery_LM3(parameters);
        } else {
          return delivery_LM4(parameters);
        }
      } else {
        return delivery_LM5(parameters);
      }
    } else {
      return delivery_LM6(parameters);
    }
  }
}
static
double
stock_level_LM1(work_wait &parameters) {
  double actual_remaining = 
	1.5837 * parameters.work_so_far 
	+ 5856002.6616;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
stock_level_LM2(work_wait &parameters) {
  double actual_remaining = 
	1.8337 * parameters.work_so_far 
	- 80524.913 * parameters.total_wait_locks 
	+ 52807908.4481;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
stock_level_estimate(work_wait &parameters){

  if (parameters.work_so_far <= 10103362) {
    return stock_level_LM1(parameters);
  } else {
    return stock_level_LM2(parameters);
  }
}
static
double
tpcc_LM1(work_wait &parameters) {
  double actual_remaining = 
	3.1553 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 1797.0452 * parameters.total_wait_locks 
	- 0.0002 * parameters.mean_wait_of_all 
	- 270686.8133 * parameters.cpu_usage 
	+ 0.0006 * parameters.avg_work_of_same_past_second 
	- 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 7576137.928;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM2(work_wait &parameters) {
  double actual_remaining = 
	2.4423 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 10472.6717 * parameters.total_wait_locks 
	- 0.0002 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	- 0.6365 * parameters.avg_work_of_same_past_second 
	- 0.0028 * parameters.avg_wait_of_same_past_second 
	- 0.004 * parameters.avg_latency_of_same_last_20 
	+ 0.0008 * parameters.max_latency_of_same_last_50 
	+ 22958176.8725;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM3(work_wait &parameters) {
  double actual_remaining = 
	-52.3125 * parameters.work_so_far 
	+ 0.0024 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 373604.7395 * parameters.total_wait_locks 
	+ 0.0213 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_work_of_same_past_second 
	+ 0.5929 * parameters.avg_wait_of_same_past_second 
	- 0.0766 * parameters.avg_latency_of_same_last_20 
	+ 0.0033 * parameters.max_latency_of_same_last_50 
	- 630887.1122;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM4(work_wait &parameters) {
  double actual_remaining = 
	-121.6656 * parameters.work_so_far 
	+ 0.0024 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 123756.9815 * parameters.total_wait_locks 
	+ 0.0213 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_work_of_same_past_second 
	- 0.0338 * parameters.avg_wait_of_same_past_second 
	- 0.0313 * parameters.avg_latency_of_same_last_20 
	+ 0.0033 * parameters.max_latency_of_same_last_50 
	+ 15000558.3175;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM5(work_wait &parameters) {
  double actual_remaining = 
	-45.226 * parameters.work_so_far 
	+ 0.0066 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 74465.8695 * parameters.total_wait_locks 
	+ 0.064 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_work_of_same_past_second 
	- 0.0953 * parameters.avg_wait_of_same_past_second 
	- 0.0268 * parameters.avg_latency_of_same_last_20 
	+ 0.0033 * parameters.max_latency_of_same_last_50 
	+ 12455206.6186;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM6(work_wait &parameters) {
  double actual_remaining = 
	2053.7784 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 15336.8398 * parameters.total_wait_locks 
	- 0.0002 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_work_of_same_past_second 
	- 0.0028 * parameters.avg_wait_of_same_past_second 
	- 0.0631 * parameters.avg_latency_of_same_last_20 
	+ 0.0028 * parameters.max_latency_of_same_last_50 
	+ 3045754.9337;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM7(work_wait &parameters) {
  double actual_remaining = 
	1141.7282 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 15336.8398 * parameters.total_wait_locks 
	- 0.0002 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_work_of_same_past_second 
	- 0.0028 * parameters.avg_wait_of_same_past_second 
	- 0.0631 * parameters.avg_latency_of_same_last_20 
	+ 0.0028 * parameters.max_latency_of_same_last_50 
	+ 22784485.9503;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM8(work_wait &parameters) {
  double actual_remaining = 
	1891.9965 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 15336.8398 * parameters.total_wait_locks 
	- 0.0002 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_work_of_same_past_second 
	- 0.0028 * parameters.avg_wait_of_same_past_second 
	- 0.0631 * parameters.avg_latency_of_same_last_20 
	+ 0.0028 * parameters.max_latency_of_same_last_50 
	+ 14994507.1054;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM9(work_wait &parameters) {
  double actual_remaining = 
	390.3894 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 15336.8398 * parameters.total_wait_locks 
	- 0.0002 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_work_of_same_past_second 
	- 0.0028 * parameters.avg_wait_of_same_past_second 
	- 0.0392 * parameters.avg_latency_of_same_last_20 
	+ 0.0028 * parameters.max_latency_of_same_last_50 
	+ 16670866.3131;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM10(work_wait &parameters) {
  double actual_remaining = 
	2.4423 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 15336.8398 * parameters.total_wait_locks 
	- 0.0002 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.8057 * parameters.avg_work_of_same_past_second 
	- 0.0028 * parameters.avg_wait_of_same_past_second 
	- 0.0096 * parameters.avg_latency_of_same_last_20 
	+ 0.0028 * parameters.max_latency_of_same_last_50 
	+ 20250346.0677;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM11(work_wait &parameters) {
  double actual_remaining = 
	2.4423 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 15336.8398 * parameters.total_wait_locks 
	+ 1.3883 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.8308 * parameters.avg_work_of_same_past_second 
	- 0.0028 * parameters.avg_wait_of_same_past_second 
	- 0.1219 * parameters.avg_latency_of_same_last_20 
	+ 0.0028 * parameters.max_latency_of_same_last_50 
	- 9573633.2984;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM12(work_wait &parameters) {
  double actual_remaining = 
	2.4423 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 15336.8398 * parameters.total_wait_locks 
	- 0.0002 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.8308 * parameters.avg_work_of_same_past_second 
	- 0.0028 * parameters.avg_wait_of_same_past_second 
	- 0.0096 * parameters.avg_latency_of_same_last_20 
	+ 0.0028 * parameters.max_latency_of_same_last_50 
	+ 25569741.9569;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM13(work_wait &parameters) {
  double actual_remaining = 
	2.4423 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 15336.8398 * parameters.total_wait_locks 
	- 0.0002 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_work_of_same_past_second 
	- 0.0028 * parameters.avg_wait_of_same_past_second 
	- 0.0096 * parameters.avg_latency_of_same_last_20 
	+ 0.0028 * parameters.max_latency_of_same_last_50 
	+ 24588987.6317;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM14(work_wait &parameters) {
  double actual_remaining = 
	2.4423 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 15336.8398 * parameters.total_wait_locks 
	- 0.1825 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	- 3.7194 * parameters.avg_work_of_same_past_second 
	+ 0.6738 * parameters.avg_wait_of_same_past_second 
	+ 0.0157 * parameters.avg_latency_of_same_last_20 
	- 0.0358 * parameters.max_latency_of_same_last_50 
	+ 94360250.4364;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM15(work_wait &parameters) {
  double actual_remaining = 
	2.4423 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 15336.8398 * parameters.total_wait_locks 
	- 0.1225 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_work_of_same_past_second 
	- 0.0028 * parameters.avg_wait_of_same_past_second 
	+ 0.0764 * parameters.avg_latency_of_same_last_20 
	- 0.1003 * parameters.max_latency_of_same_last_50 
	+ 62306773.6097;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM16(work_wait &parameters) {
  double actual_remaining = 
	2.4423 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	- 126571.5754 * parameters.total_wait_locks 
	+ 0.1142 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.6131 * parameters.avg_work_of_same_past_second 
	- 0.0028 * parameters.avg_wait_of_same_past_second 
	+ 0.2762 * parameters.avg_latency_of_same_last_20 
	+ 0.0028 * parameters.max_latency_of_same_last_50 
	+ 9923761.8464;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM17(work_wait &parameters) {
  double actual_remaining = 
	2.4423 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	- 1012018.0349 * parameters.total_wait_locks 
	+ 0.2205 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 1.1808 * parameters.avg_work_of_same_past_second 
	- 0.0028 * parameters.avg_wait_of_same_past_second 
	+ 0.1454 * parameters.avg_latency_of_same_last_20 
	+ 0.0028 * parameters.max_latency_of_same_last_50 
	+ 93559607.482;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM18(work_wait &parameters) {
  double actual_remaining = 
	2.4423 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	- 800989.2142 * parameters.total_wait_locks 
	+ 0.2205 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 1.1808 * parameters.avg_work_of_same_past_second 
	- 0.0028 * parameters.avg_wait_of_same_past_second 
	+ 0.1454 * parameters.avg_latency_of_same_last_20 
	+ 0.0028 * parameters.max_latency_of_same_last_50 
	+ 90565643.0875;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM19(work_wait &parameters) {
  double actual_remaining = 
	26.6389 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 24245.2505 * parameters.total_wait_locks 
	- 0.0002 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 3.3264 * parameters.avg_work_of_same_past_second 
	- 0.0103 * parameters.avg_wait_of_same_past_second 
	- 0.126 * parameters.avg_latency_of_same_last_20 
	+ 0.001 * parameters.max_latency_of_same_last_50 
	+ 7739807.6804;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM20(work_wait &parameters) {
  double actual_remaining = 
	26.6389 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 24245.2505 * parameters.total_wait_locks 
	+ 0.6231 * parameters.mean_wait_of_all 
	- 695513277.1875 * parameters.cpu_usage 
	+ 2.1362 * parameters.avg_work_of_same_past_second 
	- 0.0103 * parameters.avg_wait_of_same_past_second 
	- 0.3111 * parameters.avg_latency_of_same_last_20 
	+ 0.001 * parameters.max_latency_of_same_last_50 
	+ 695798291.0365;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM21(work_wait &parameters) {
  double actual_remaining = 
	26.6389 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 24245.2505 * parameters.total_wait_locks 
	+ 0.727 * parameters.mean_wait_of_all 
	- 695513277.1875 * parameters.cpu_usage 
	+ 2.1362 * parameters.avg_work_of_same_past_second 
	- 0.0103 * parameters.avg_wait_of_same_past_second 
	- 0.324 * parameters.avg_latency_of_same_last_20 
	+ 0.001 * parameters.max_latency_of_same_last_50 
	+ 689517011.6323;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM22(work_wait &parameters) {
  double actual_remaining = 
	26.6389 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 24245.2505 * parameters.total_wait_locks 
	- 0.0002 * parameters.mean_wait_of_all 
	- 725746263.9102 * parameters.cpu_usage 
	+ 2.1362 * parameters.avg_work_of_same_past_second 
	- 0.0103 * parameters.avg_wait_of_same_past_second 
	- 0.2396 * parameters.avg_latency_of_same_last_20 
	+ 0.001 * parameters.max_latency_of_same_last_50 
	+ 721955588.5144;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM23(work_wait &parameters) {
  double actual_remaining = 
	19.4597 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 18721.1027 * parameters.total_wait_locks 
	- 0.0002 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0333 * parameters.avg_work_of_same_past_second 
	- 0.008 * parameters.avg_wait_of_same_past_second 
	- 0.0068 * parameters.avg_latency_of_same_last_20 
	+ 0.001 * parameters.max_latency_of_same_last_50 
	+ 14254421.1278;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM24(work_wait &parameters) {
  double actual_remaining = 
	19.4597 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 18721.1027 * parameters.total_wait_locks 
	+ 1.7448 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0333 * parameters.avg_work_of_same_past_second 
	- 0.0596 * parameters.avg_wait_of_same_past_second 
	- 0.0068 * parameters.avg_latency_of_same_last_20 
	+ 0.001 * parameters.max_latency_of_same_last_50 
	- 26845946.9955;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM25(work_wait &parameters) {
  double actual_remaining = 
	19.4597 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 18721.1027 * parameters.total_wait_locks 
	+ 3.4898 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0333 * parameters.avg_work_of_same_past_second 
	- 0.0473 * parameters.avg_wait_of_same_past_second 
	- 0.0068 * parameters.avg_latency_of_same_last_20 
	+ 0.001 * parameters.max_latency_of_same_last_50 
	- 69942734.3843;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM26(work_wait &parameters) {
  double actual_remaining = 
	19.4597 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 18721.1027 * parameters.total_wait_locks 
	+ 3.4898 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0333 * parameters.avg_work_of_same_past_second 
	- 0.0813 * parameters.avg_wait_of_same_past_second 
	- 0.0068 * parameters.avg_latency_of_same_last_20 
	+ 0.001 * parameters.max_latency_of_same_last_50 
	- 60503262.688;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM27(work_wait &parameters) {
  double actual_remaining = 
	19.4597 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 18721.1027 * parameters.total_wait_locks 
	+ 3.4898 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0333 * parameters.avg_work_of_same_past_second 
	- 0.0833 * parameters.avg_wait_of_same_past_second 
	- 0.0068 * parameters.avg_latency_of_same_last_20 
	+ 0.001 * parameters.max_latency_of_same_last_50 
	- 60882054.491;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM28(work_wait &parameters) {
  double actual_remaining = 
	19.4597 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 18721.1027 * parameters.total_wait_locks 
	- 0.0002 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0333 * parameters.avg_work_of_same_past_second 
	- 0.008 * parameters.avg_wait_of_same_past_second 
	- 0.0068 * parameters.avg_latency_of_same_last_20 
	+ 0.001 * parameters.max_latency_of_same_last_50 
	+ 16096716.2494;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM29(work_wait &parameters) {
  double actual_remaining = 
	31.7208 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 24445.1308 * parameters.total_wait_locks 
	- 0.0002 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.5047 * parameters.avg_work_of_same_past_second 
	- 0.0221 * parameters.avg_wait_of_same_past_second 
	- 0.0459 * parameters.avg_latency_of_same_last_20 
	+ 0.001 * parameters.max_latency_of_same_last_50 
	+ 20376785.8085;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM30(work_wait &parameters) {
  double actual_remaining = 
	-231.8141 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 24445.1308 * parameters.total_wait_locks 
	- 0.0002 * parameters.mean_wait_of_all 
	+ 257584691.6282 * parameters.cpu_usage 
	+ 0.3388 * parameters.avg_work_of_same_past_second 
	- 0.0221 * parameters.avg_wait_of_same_past_second 
	- 0.0068 * parameters.avg_latency_of_same_last_20 
	+ 0.001 * parameters.max_latency_of_same_last_50 
	- 196048669.0602;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM31(work_wait &parameters) {
  double actual_remaining = 
	31.7208 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 24445.1308 * parameters.total_wait_locks 
	- 0.0002 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0719 * parameters.avg_work_of_same_past_second 
	- 0.0365 * parameters.avg_wait_of_same_past_second 
	- 0.0068 * parameters.avg_latency_of_same_last_20 
	+ 0.001 * parameters.max_latency_of_same_last_50 
	+ 17836892.5798;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM32(work_wait &parameters) {
  double actual_remaining = 
	4.1463 * parameters.work_so_far 
	+ 0.0009 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 5151.385 * parameters.total_wait_locks 
	- 0.0002 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.9756 * parameters.avg_work_of_same_past_second 
	- 0.0015 * parameters.avg_wait_of_same_past_second 
	+ 0.0007 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 6961538.3358;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM33(work_wait &parameters) {
  double actual_remaining = 
	4.1463 * parameters.work_so_far 
	+ 0.0007 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 4134.7019 * parameters.total_wait_locks 
	- 0.0002 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_work_of_same_past_second 
	- 0.0012 * parameters.avg_wait_of_same_past_second 
	+ 0.0007 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 15123734.1459;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM34(work_wait &parameters) {
  double actual_remaining = 
	4.1463 * parameters.work_so_far 
	- 0.0107 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 2572.8012 * parameters.total_wait_locks 
	- 0.0002 * parameters.mean_wait_of_all 
	+ 44893692.4005 * parameters.cpu_usage 
	- 1.0544 * parameters.avg_work_of_same_past_second 
	- 0.0006 * parameters.avg_wait_of_same_past_second 
	+ 0.0007 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 348853.2496;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM35(work_wait &parameters) {
  double actual_remaining = 
	129.0292 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 1512.2897 * parameters.total_wait_locks 
	- 0.0039 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_work_of_same_past_second 
	+ 0.0141 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	+ 11186939.61;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM36(work_wait &parameters) {
  double actual_remaining = 
	129.0292 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 1512.2897 * parameters.total_wait_locks 
	- 0.0039 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_work_of_same_past_second 
	+ 0.0141 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	+ 19779391.6692;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM37(work_wait &parameters) {
  double actual_remaining = 
	129.0292 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 1512.2897 * parameters.total_wait_locks 
	- 0.0039 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_work_of_same_past_second 
	+ 0.0141 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	+ 24248269.4287;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM38(work_wait &parameters) {
  double actual_remaining = 
	129.0292 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 1512.2897 * parameters.total_wait_locks 
	- 0.0039 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_work_of_same_past_second 
	+ 0.0141 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	+ 22354865.0789;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM39(work_wait &parameters) {
  double actual_remaining = 
	129.0292 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 1512.2897 * parameters.total_wait_locks 
	- 0.0039 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_work_of_same_past_second 
	+ 0.0141 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	+ 15724977.9851;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM40(work_wait &parameters) {
  double actual_remaining = 
	234.8929 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 1512.2897 * parameters.total_wait_locks 
	- 0.0039 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_work_of_same_past_second 
	+ 0.0194 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	+ 6326705.5529;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM41(work_wait &parameters) {
  double actual_remaining = 
	270.4914 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 1512.2897 * parameters.total_wait_locks 
	- 0.0039 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_work_of_same_past_second 
	+ 0.0235 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 0.0051 * parameters.max_latency_of_same_last_50 
	+ 11837388.8205;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM42(work_wait &parameters) {
  double actual_remaining = 
	190.3168 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 43922.3673 * parameters.total_wait_locks 
	- 0.0039 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_work_of_same_past_second 
	+ 0.0175 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 0.0084 * parameters.max_latency_of_same_last_50 
	+ 15834774.5183;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM43(work_wait &parameters) {
  double actual_remaining = 
	190.3168 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 39276.7611 * parameters.total_wait_locks 
	- 0.0039 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_work_of_same_past_second 
	+ 0.0175 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	+ 0.0016 * parameters.max_latency_of_same_last_50 
	+ 9734716.6831;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM44(work_wait &parameters) {
  double actual_remaining = 
	369.8437 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 39276.7611 * parameters.total_wait_locks 
	- 0.0039 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_work_of_same_past_second 
	- 0.0063 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 0.0033 * parameters.max_latency_of_same_last_50 
	+ 23116572.5512;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM45(work_wait &parameters) {
  double actual_remaining = 
	431.6901 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 39276.7611 * parameters.total_wait_locks 
	- 0.0039 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_work_of_same_past_second 
	- 0.0052 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	+ 0.0025 * parameters.max_latency_of_same_last_50 
	+ 11842639.1527;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM46(work_wait &parameters) {
  double actual_remaining = 
	431.6901 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 39276.7611 * parameters.total_wait_locks 
	- 0.0039 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_work_of_same_past_second 
	- 0.0136 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	+ 0.0028 * parameters.max_latency_of_same_last_50 
	+ 15033181.7466;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM47(work_wait &parameters) {
  double actual_remaining = 
	431.6901 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 39276.7611 * parameters.total_wait_locks 
	- 0.0039 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_work_of_same_past_second 
	- 0.0136 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	+ 0.0028 * parameters.max_latency_of_same_last_50 
	+ 14838965.3763;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM48(work_wait &parameters) {
  double actual_remaining = 
	511.3833 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 39276.7611 * parameters.total_wait_locks 
	- 0.0039 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_work_of_same_past_second 
	+ 0.0031 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 0.0033 * parameters.max_latency_of_same_last_50 
	+ 15275481.6333;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM49(work_wait &parameters) {
  double actual_remaining = 
	298.868 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 39276.7611 * parameters.total_wait_locks 
	- 0.0039 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_work_of_same_past_second 
	+ 0.0031 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 0.0033 * parameters.max_latency_of_same_last_50 
	+ 18484047.1243;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM50(work_wait &parameters) {
  double actual_remaining = 
	190.3168 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 62060.4121 * parameters.total_wait_locks 
	- 0.0039 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_work_of_same_past_second 
	+ 0.0175 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 0.0116 * parameters.max_latency_of_same_last_50 
	+ 19031859.0779;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM51(work_wait &parameters) {
  double actual_remaining = 
	327.2021 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 1512.2897 * parameters.total_wait_locks 
	- 0.0334 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_work_of_same_past_second 
	+ 0.0331 * parameters.avg_wait_of_same_past_second 
	- 0.0113 * parameters.avg_latency_of_same_last_20 
	- 0.0019 * parameters.max_latency_of_same_last_50 
	+ 10116665.927;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM52(work_wait &parameters) {
  double actual_remaining = 
	118.138 * parameters.work_so_far 
	- 0.0166 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 1512.2897 * parameters.total_wait_locks 
	- 0.0508 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 3.463 * parameters.avg_work_of_same_past_second 
	+ 0.0331 * parameters.avg_wait_of_same_past_second 
	- 0.0113 * parameters.avg_latency_of_same_last_20 
	- 0.0019 * parameters.max_latency_of_same_last_50 
	- 62522326.0588;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM53(work_wait &parameters) {
  double actual_remaining = 
	118.138 * parameters.work_so_far 
	- 0.0199 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 1512.2897 * parameters.total_wait_locks 
	- 0.0541 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 1.3073 * parameters.avg_work_of_same_past_second 
	+ 0.0331 * parameters.avg_wait_of_same_past_second 
	- 0.0113 * parameters.avg_latency_of_same_last_20 
	- 0.0019 * parameters.max_latency_of_same_last_50 
	- 7574022.3097;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM54(work_wait &parameters) {
  double actual_remaining = 
	148.2333 * parameters.work_so_far 
	- 0.0352 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 1512.2897 * parameters.total_wait_locks 
	- 0.0714 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_work_of_same_past_second 
	- 0.3237 * parameters.avg_wait_of_same_past_second 
	- 0.0293 * parameters.avg_latency_of_same_last_20 
	- 0.0019 * parameters.max_latency_of_same_last_50 
	+ 210372199.9985;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM55(work_wait &parameters) {
  double actual_remaining = 
	-1.7445 * parameters.work_so_far 
	- 0.0352 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 1512.2897 * parameters.total_wait_locks 
	- 0.0714 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_work_of_same_past_second 
	- 0.3237 * parameters.avg_wait_of_same_past_second 
	- 0.0293 * parameters.avg_latency_of_same_last_20 
	- 0.0019 * parameters.max_latency_of_same_last_50 
	+ 213210588.6855;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM56(work_wait &parameters) {
  double actual_remaining = 
	63.4266 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 1512.2897 * parameters.total_wait_locks 
	- 0.0714 * parameters.mean_wait_of_all 
	- 154582.5653 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_work_of_same_past_second 
	- 0.3076 * parameters.avg_wait_of_same_past_second 
	- 0.0079 * parameters.avg_latency_of_same_last_20 
	- 0.0019 * parameters.max_latency_of_same_last_50 
	+ 173202522.1063;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM57(work_wait &parameters) {
  double actual_remaining = 
	0.2226 * parameters.work_so_far 
	- 0.0156 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	- 64317.5822 * parameters.total_wait_locks 
	+ 0.0008 * parameters.mean_wait_of_all 
	- 176768.4285 * parameters.cpu_usage 
	+ 0.0025 * parameters.avg_work_of_same_past_second 
	- 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0226 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 40239834.4828;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM58(work_wait &parameters) {
  double actual_remaining = 
	0.2226 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	- 186667.4373 * parameters.total_wait_locks 
	+ 1.0323 * parameters.mean_wait_of_all 
	- 45977753.5428 * parameters.cpu_usage 
	+ 0.0025 * parameters.avg_work_of_same_past_second 
	- 0.0536 * parameters.avg_wait_of_same_past_second 
	+ 0.0006 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 60583559.274;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM59(work_wait &parameters) {
  double actual_remaining = 
	0.2226 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	- 2158.9728 * parameters.total_wait_locks 
	+ 0.0315 * parameters.mean_wait_of_all 
	- 176768.4285 * parameters.cpu_usage 
	- 0.1744 * parameters.avg_work_of_same_past_second 
	- 0.2489 * parameters.avg_wait_of_same_past_second 
	+ 0.2095 * parameters.avg_latency_of_same_last_20 
	- 0.0012 * parameters.max_latency_of_same_last_50 
	+ 43661840.6322;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM60(work_wait &parameters) {
  double actual_remaining = 
	0.2226 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	- 223968.2318 * parameters.total_wait_locks 
	+ 0.0315 * parameters.mean_wait_of_all 
	- 176768.4285 * parameters.cpu_usage 
	- 0.1157 * parameters.avg_work_of_same_past_second 
	+ 0.0022 * parameters.avg_wait_of_same_past_second 
	+ 0.0005 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 119677879.3202;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM61(work_wait &parameters) {
  double actual_remaining = 
	0.2226 * parameters.work_so_far 
	+ 0.5543 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	- 66291.165 * parameters.total_wait_locks 
	+ 0.0315 * parameters.mean_wait_of_all 
	- 176768.4285 * parameters.cpu_usage 
	- 0.1157 * parameters.avg_work_of_same_past_second 
	+ 0.0022 * parameters.avg_wait_of_same_past_second 
	+ 0.0517 * parameters.avg_latency_of_same_last_20 
	- 0.066 * parameters.max_latency_of_same_last_50 
	+ 86250255.0058;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM62(work_wait &parameters) {
  double actual_remaining = 
	0.2226 * parameters.work_so_far 
	+ 0.5543 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	- 66291.165 * parameters.total_wait_locks 
	+ 0.0315 * parameters.mean_wait_of_all 
	- 176768.4285 * parameters.cpu_usage 
	- 0.1157 * parameters.avg_work_of_same_past_second 
	+ 0.0022 * parameters.avg_wait_of_same_past_second 
	+ 0.0005 * parameters.avg_latency_of_same_last_20 
	- 0.066 * parameters.max_latency_of_same_last_50 
	+ 100127159.3807;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM63(work_wait &parameters) {
  double actual_remaining = 
	0.2226 * parameters.work_so_far 
	- 0.0453 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	- 66291.165 * parameters.total_wait_locks 
	+ 0.0315 * parameters.mean_wait_of_all 
	- 176768.4285 * parameters.cpu_usage 
	- 0.1157 * parameters.avg_work_of_same_past_second 
	+ 0.0022 * parameters.avg_wait_of_same_past_second 
	- 0.1696 * parameters.avg_latency_of_same_last_20 
	- 0.0171 * parameters.max_latency_of_same_last_50 
	+ 183171623.0527;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM64(work_wait &parameters) {
  double actual_remaining = 
	0.2226 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 109219.6345 * parameters.total_wait_locks 
	+ 0.0315 * parameters.mean_wait_of_all 
	- 176768.4285 * parameters.cpu_usage 
	- 0.1157 * parameters.avg_work_of_same_past_second 
	+ 0.0022 * parameters.avg_wait_of_same_past_second 
	+ 0.0005 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	- 10291702.709;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM65(work_wait &parameters) {
  double actual_remaining = 
	0.2226 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	- 2158.9728 * parameters.total_wait_locks 
	+ 0.0315 * parameters.mean_wait_of_all 
	- 176768.4285 * parameters.cpu_usage 
	- 0.1571 * parameters.avg_work_of_same_past_second 
	+ 0.0022 * parameters.avg_wait_of_same_past_second 
	+ 0.0198 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 14939790.5386;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM66(work_wait &parameters) {
  double actual_remaining = 
	409.4248 * parameters.work_so_far 
	+ 0.0366 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 5009.4579 * parameters.total_wait_locks 
	+ 6.3782 * parameters.mean_wait_of_all 
	- 176768.4285 * parameters.cpu_usage 
	- 2.9306 * parameters.avg_work_of_same_past_second 
	+ 0.7039 * parameters.avg_wait_of_same_past_second 
	+ 0.0005 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 904264855.311;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM67(work_wait &parameters) {
  double actual_remaining = 
	0.2226 * parameters.work_so_far 
	- 0.0096 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	- 415676.2035 * parameters.total_wait_locks 
	+ 3.915 * parameters.mean_wait_of_all 
	- 176768.4285 * parameters.cpu_usage 
	+ 0.9251 * parameters.avg_work_of_same_past_second 
	+ 0.051 * parameters.avg_wait_of_same_past_second 
	+ 0.0005 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 300201115.7201;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM68(work_wait &parameters) {
  double actual_remaining = 
	0.2226 * parameters.work_so_far 
	- 0.0103 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 9987.122 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 320193.8384 * parameters.cpu_usage 
	+ 0.0025 * parameters.avg_work_of_same_past_second 
	- 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0132 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 18993536.4736;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM69(work_wait &parameters) {
  double actual_remaining = 
	-74.519 * parameters.work_so_far 
	- 0.0127 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 63712.5633 * parameters.total_wait_locks 
	- 0.0418 * parameters.mean_wait_of_all 
	+ 0.0096 * parameters.avg_work_of_same_past_second 
	- 0.0367 * parameters.avg_wait_of_same_past_second 
	+ 0.0133 * parameters.avg_latency_of_same_last_20 
	+ 0.0067 * parameters.max_latency_of_same_last_50 
	+ 15064108.9631;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM70(work_wait &parameters) {
  double actual_remaining = 
	502.6938 * parameters.work_so_far 
	- 0.1032 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 788410.2867 * parameters.total_wait_locks 
	- 7.4759 * parameters.mean_wait_of_all 
	- 11.8172 * parameters.avg_work_of_same_past_second 
	- 0.0182 * parameters.avg_wait_of_same_past_second 
	- 0.0392 * parameters.avg_latency_of_same_last_20 
	+ 0.0153 * parameters.max_latency_of_same_last_50 
	+ 1395766931.1508;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM71(work_wait &parameters) {
  double actual_remaining = 
	430.9233 * parameters.work_so_far 
	- 0.1032 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 742787.0272 * parameters.total_wait_locks 
	- 7.4759 * parameters.mean_wait_of_all 
	- 11.8172 * parameters.avg_work_of_same_past_second 
	- 0.0182 * parameters.avg_wait_of_same_past_second 
	- 0.0392 * parameters.avg_latency_of_same_last_20 
	+ 0.0153 * parameters.max_latency_of_same_last_50 
	+ 1424343553.5156;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM72(work_wait &parameters) {
  double actual_remaining = 
	0.3005 * parameters.work_so_far 
	- 0.128 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 846858.9888 * parameters.total_wait_locks 
	- 7.4759 * parameters.mean_wait_of_all 
	- 7.8196 * parameters.avg_work_of_same_past_second 
	- 0.0182 * parameters.avg_wait_of_same_past_second 
	- 0.0392 * parameters.avg_latency_of_same_last_20 
	+ 0.0153 * parameters.max_latency_of_same_last_50 
	+ 1115118208.0236;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM73(work_wait &parameters) {
  double actual_remaining = 
	0.3005 * parameters.work_so_far 
	- 0.128 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 765403.7152 * parameters.total_wait_locks 
	- 7.4759 * parameters.mean_wait_of_all 
	- 7.8196 * parameters.avg_work_of_same_past_second 
	- 0.0182 * parameters.avg_wait_of_same_past_second 
	- 0.0392 * parameters.avg_latency_of_same_last_20 
	+ 0.0153 * parameters.max_latency_of_same_last_50 
	+ 1163612710.7156;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM74(work_wait &parameters) {
  double actual_remaining = 
	0.3005 * parameters.work_so_far 
	- 0.1383 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 556335.3083 * parameters.total_wait_locks 
	- 7.4759 * parameters.mean_wait_of_all 
	- 7.8196 * parameters.avg_work_of_same_past_second 
	- 0.0182 * parameters.avg_wait_of_same_past_second 
	- 0.0392 * parameters.avg_latency_of_same_last_20 
	+ 0.032 * parameters.max_latency_of_same_last_50 
	+ 1190856228.2599;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM75(work_wait &parameters) {
  double actual_remaining = 
	319.5371 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	- 113810.2306 * parameters.total_wait_locks 
	- 2.423 * parameters.mean_wait_of_all 
	- 0.5213 * parameters.avg_work_of_same_past_second 
	- 0.0182 * parameters.avg_wait_of_same_past_second 
	- 0.0149 * parameters.avg_latency_of_same_last_20 
	+ 0.0058 * parameters.max_latency_of_same_last_50 
	+ 403145113.6543;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM76(work_wait &parameters) {
  double actual_remaining = 
	0.3005 * parameters.work_so_far 
	- 0.0005 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 276387.9979 * parameters.total_wait_locks 
	+ 0.0511 * parameters.mean_wait_of_all 
	- 0.0118 * parameters.avg_work_of_same_past_second 
	- 0.0066 * parameters.avg_wait_of_same_past_second 
	+ 0.0427 * parameters.avg_latency_of_same_last_20 
	- 0.0202 * parameters.max_latency_of_same_last_50 
	- 95578466.4457;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM77(work_wait &parameters) {
  double actual_remaining = 
	0.3005 * parameters.work_so_far 
	- 0.0214 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	- 24106.3309 * parameters.total_wait_locks 
	+ 0.0511 * parameters.mean_wait_of_all 
	- 0.0118 * parameters.avg_work_of_same_past_second 
	- 0.0066 * parameters.avg_wait_of_same_past_second 
	+ 0.0196 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 30226366.3813;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM78(work_wait &parameters) {
  double actual_remaining = 
	0.3005 * parameters.work_so_far 
	- 0.0818 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	- 181120.5248 * parameters.total_wait_locks 
	+ 1.0296 * parameters.mean_wait_of_all 
	+ 0.6138 * parameters.avg_work_of_same_past_second 
	- 0.1305 * parameters.avg_wait_of_same_past_second 
	+ 0.0891 * parameters.avg_latency_of_same_last_20 
	- 0.0305 * parameters.max_latency_of_same_last_50 
	+ 15461939.9993;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM79(work_wait &parameters) {
  double actual_remaining = 
	0.0038 * parameters.work_so_far 
	+ 0.195 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 34352.096 * parameters.total_wait_locks 
	- 0.0002 * parameters.mean_wait_of_all 
	- 0.4132 * parameters.avg_work_of_same_past_second 
	- 0.0013 * parameters.avg_wait_of_same_past_second 
	+ 0.0163 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 25456491.1113;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM80(work_wait &parameters) {
  double actual_remaining = 
	0.0038 * parameters.work_so_far 
	+ 0.0693 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	- 89186.8536 * parameters.total_wait_locks 
	+ 0.3113 * parameters.mean_wait_of_all 
	+ 0.8897 * parameters.avg_work_of_same_past_second 
	- 0.0738 * parameters.avg_wait_of_same_past_second 
	- 0 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 31896174.2618;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM81(work_wait &parameters) {
  double actual_remaining = 
	0.0038 * parameters.work_so_far 
	+ 0.6455 * parameters.wait_so_far 
	+ 2435.0794 * parameters.num_locks_so_far 
	+ 243885.0073 * parameters.total_wait_locks 
	- 0.0002 * parameters.mean_wait_of_all 
	+ 0.0163 * parameters.avg_work_of_same_past_second 
	- 0.2299 * parameters.avg_wait_of_same_past_second 
	- 0.2884 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 17713402.5254;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM82(work_wait &parameters) {
  double actual_remaining = 
	0.3586 * parameters.work_so_far 
	+ 0.3627 * parameters.wait_so_far 
	- 234359.2984 * parameters.num_locks_so_far 
	+ 99301.367 * parameters.total_wait_locks 
	+ 0.0296 * parameters.mean_wait_of_all 
	- 44139440.9435 * parameters.cpu_usage 
	+ 0.0601 * parameters.avg_work_of_same_past_second 
	- 0.0542 * parameters.avg_wait_of_same_past_second 
	+ 0.0028 * parameters.avg_latency_of_same_last_20 
	- 0.0018 * parameters.max_latency_of_same_last_50 
	+ 67513321.4037;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM83(work_wait &parameters) {
  double actual_remaining = 
	3.4717 * parameters.work_so_far 
	+ 0.0341 * parameters.wait_so_far 
	- 3628281.2537 * parameters.num_locks_so_far 
	+ 148155.3262 * parameters.total_wait_locks 
	+ 0.0512 * parameters.mean_wait_of_all 
	- 471463113.5304 * parameters.cpu_usage 
	+ 1.5621 * parameters.avg_work_of_same_past_second 
	- 0.0898 * parameters.avg_wait_of_same_past_second 
	+ 0.0028 * parameters.avg_latency_of_same_last_20 
	- 0.0018 * parameters.max_latency_of_same_last_50 
	+ 445474105.0719;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM84(work_wait &parameters) {
  double actual_remaining = 
	2.8012 * parameters.work_so_far 
	+ 0.1711 * parameters.wait_so_far 
	- 2063913.9447 * parameters.num_locks_so_far 
	+ 1558072.8287 * parameters.total_wait_locks 
	+ 0.3619 * parameters.mean_wait_of_all 
	- 33366395.3194 * parameters.cpu_usage 
	+ 0.0477 * parameters.avg_work_of_same_past_second 
	- 0.4247 * parameters.avg_wait_of_same_past_second 
	- 0.1191 * parameters.avg_latency_of_same_last_20 
	- 0.0018 * parameters.max_latency_of_same_last_50 
	+ 48042980.4538;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM85(work_wait &parameters) {
  double actual_remaining = 
	2.5227 * parameters.work_so_far 
	+ 0.007 * parameters.wait_so_far 
	- 2271155.8138 * parameters.num_locks_so_far 
	+ 46538.6482 * parameters.total_wait_locks 
	+ 0.0047 * parameters.mean_wait_of_all 
	- 259980406.8806 * parameters.cpu_usage 
	+ 0.0269 * parameters.avg_work_of_same_past_second 
	- 0.0198 * parameters.avg_wait_of_same_past_second 
	+ 0.0061 * parameters.avg_latency_of_same_last_20 
	- 0.0031 * parameters.max_latency_of_same_last_50 
	+ 330531503.8564;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM86(work_wait &parameters) {
  double actual_remaining = 
	0.4478 * parameters.work_so_far 
	+ 10.0134 * parameters.wait_so_far 
	- 384611.1297 * parameters.num_locks_so_far 
	- 76906.8136 * parameters.total_wait_locks 
	+ 0.0047 * parameters.mean_wait_of_all 
	- 23286517.2571 * parameters.cpu_usage 
	+ 0.0906 * parameters.avg_work_of_same_past_second 
	- 0.0553 * parameters.avg_wait_of_same_past_second 
	+ 0.522 * parameters.avg_latency_of_same_last_20 
	- 0.0118 * parameters.max_latency_of_same_last_50 
	+ 62934385.1682;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM87(work_wait &parameters) {
  double actual_remaining = 
	0.4478 * parameters.work_so_far 
	+ 0.0027 * parameters.wait_so_far 
	- 384611.1297 * parameters.num_locks_so_far 
	- 76906.8136 * parameters.total_wait_locks 
	+ 0.0047 * parameters.mean_wait_of_all 
	- 23286517.2571 * parameters.cpu_usage 
	+ 0.0906 * parameters.avg_work_of_same_past_second 
	- 0.2325 * parameters.avg_wait_of_same_past_second 
	+ 0.0586 * parameters.avg_latency_of_same_last_20 
	- 0.0118 * parameters.max_latency_of_same_last_50 
	+ 113730742.0104;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM88(work_wait &parameters) {
  double actual_remaining = 
	2.8886 * parameters.work_so_far 
	+ 0.6201 * parameters.wait_so_far 
	- 5164375.1741 * parameters.num_locks_so_far 
	- 72445.0952 * parameters.total_wait_locks 
	+ 0.0047 * parameters.mean_wait_of_all 
	- 22959721.2876 * parameters.cpu_usage 
	+ 0.5401 * parameters.avg_work_of_same_past_second 
	- 0.3634 * parameters.avg_wait_of_same_past_second 
	+ 0.021 * parameters.avg_latency_of_same_last_20 
	- 0.1507 * parameters.max_latency_of_same_last_50 
	+ 248644771.4007;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM89(work_wait &parameters) {
  double actual_remaining = 
	0.2656 * parameters.work_so_far 
	+ 0.0372 * parameters.wait_so_far 
	- 458866.2287 * parameters.num_locks_so_far 
	+ 1647627.6009 * parameters.total_wait_locks 
	- 0.0658 * parameters.mean_wait_of_all 
	- 8433853.1802 * parameters.cpu_usage 
	+ 0.0287 * parameters.avg_work_of_same_past_second 
	- 0.0417 * parameters.avg_wait_of_same_past_second 
	- 0.1493 * parameters.avg_latency_of_same_last_20 
	+ 0.0548 * parameters.max_latency_of_same_last_50 
	+ 141887212.4229;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM90(work_wait &parameters) {
  double actual_remaining = 
	0.264 * parameters.work_so_far 
	+ 0.0372 * parameters.wait_so_far 
	- 1054053.5473 * parameters.num_locks_so_far 
	+ 1246372.1682 * parameters.total_wait_locks 
	- 0.0643 * parameters.mean_wait_of_all 
	- 8433853.1802 * parameters.cpu_usage 
	+ 3.1598 * parameters.avg_work_of_same_past_second 
	- 0.0417 * parameters.avg_wait_of_same_past_second 
	- 0.4367 * parameters.avg_latency_of_same_last_20 
	+ 0.6635 * parameters.max_latency_of_same_last_50 
	+ 42138490.4922;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM91(work_wait &parameters) {
  double actual_remaining = 
	0.264 * parameters.work_so_far 
	+ 0.0372 * parameters.wait_so_far 
	+ 4063481.7109 * parameters.num_locks_so_far 
	+ 2649493.8411 * parameters.total_wait_locks 
	- 0.0643 * parameters.mean_wait_of_all 
	- 8433853.1802 * parameters.cpu_usage 
	- 1.1976 * parameters.avg_work_of_same_past_second 
	- 0.0417 * parameters.avg_wait_of_same_past_second 
	- 0.4367 * parameters.avg_latency_of_same_last_20 
	+ 0.2451 * parameters.max_latency_of_same_last_50 
	+ 52107231.6973;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM92(work_wait &parameters) {
  double actual_remaining = 
	-0.3501 * parameters.work_so_far 
	+ 0.0372 * parameters.wait_so_far 
	- 4355374.2836 * parameters.num_locks_so_far 
	+ 111473.6574 * parameters.total_wait_locks 
	- 0.0643 * parameters.mean_wait_of_all 
	- 8433853.1802 * parameters.cpu_usage 
	+ 0.0287 * parameters.avg_work_of_same_past_second 
	- 0.0417 * parameters.avg_wait_of_same_past_second 
	- 0.5091 * parameters.avg_latency_of_same_last_20 
	+ 0.1821 * parameters.max_latency_of_same_last_50 
	+ 466376565.1978;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM93(work_wait &parameters) {
  double actual_remaining = 
	1.0747 * parameters.work_so_far 
	+ 0.0372 * parameters.wait_so_far 
	- 1076927.2085 * parameters.num_locks_so_far 
	+ 267930.9709 * parameters.total_wait_locks 
	+ 0.1192 * parameters.mean_wait_of_all 
	- 72559755.4071 * parameters.cpu_usage 
	+ 0.0287 * parameters.avg_work_of_same_past_second 
	- 0.0417 * parameters.avg_wait_of_same_past_second 
	+ 0.0666 * parameters.avg_latency_of_same_last_20 
	- 0.0124 * parameters.max_latency_of_same_last_50 
	+ 151899134.6011;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM94(work_wait &parameters) {
  double actual_remaining = 
	0.529 * parameters.work_so_far 
	+ 0.0372 * parameters.wait_so_far 
	- 2876134.8355 * parameters.num_locks_so_far 
	+ 235187.4393 * parameters.total_wait_locks 
	+ 0.2854 * parameters.mean_wait_of_all 
	- 117722293.2807 * parameters.cpu_usage 
	+ 0.0287 * parameters.avg_work_of_same_past_second 
	- 0.9829 * parameters.avg_wait_of_same_past_second 
	+ 0.051 * parameters.avg_latency_of_same_last_20 
	- 0.0124 * parameters.max_latency_of_same_last_50 
	+ 368966752.5206;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM95(work_wait &parameters) {
  double actual_remaining = 
	0.529 * parameters.work_so_far 
	+ 0.0372 * parameters.wait_so_far 
	- 2546487.8551 * parameters.num_locks_so_far 
	+ 235187.4393 * parameters.total_wait_locks 
	+ 0.4704 * parameters.mean_wait_of_all 
	- 117722293.2807 * parameters.cpu_usage 
	+ 0.0287 * parameters.avg_work_of_same_past_second 
	- 0.0417 * parameters.avg_wait_of_same_past_second 
	+ 0.051 * parameters.avg_latency_of_same_last_20 
	- 0.0124 * parameters.max_latency_of_same_last_50 
	+ 296065008.5856;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM96(work_wait &parameters) {
  double actual_remaining = 
	0.6611 * parameters.work_so_far 
	+ 0.0372 * parameters.wait_so_far 
	- 2107923.5753 * parameters.num_locks_so_far 
	+ 235187.4393 * parameters.total_wait_locks 
	+ 0.2267 * parameters.mean_wait_of_all 
	- 164151108.9155 * parameters.cpu_usage 
	+ 0.0287 * parameters.avg_work_of_same_past_second 
	- 0.0417 * parameters.avg_wait_of_same_past_second 
	+ 0.051 * parameters.avg_latency_of_same_last_20 
	- 0.0124 * parameters.max_latency_of_same_last_50 
	+ 386667585.7609;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM97(work_wait &parameters) {
  double actual_remaining = 
	0.97 * parameters.work_so_far 
	+ 0.2305 * parameters.wait_so_far 
	- 210986.1013 * parameters.num_locks_so_far 
	+ 1099146.1702 * parameters.total_wait_locks 
	+ 1.5093 * parameters.mean_wait_of_all 
	- 8433853.1802 * parameters.cpu_usage 
	+ 0.1025 * parameters.avg_work_of_same_past_second 
	- 0.2178 * parameters.avg_wait_of_same_past_second 
	+ 0.0028 * parameters.avg_latency_of_same_last_20 
	- 0.2086 * parameters.max_latency_of_same_last_50 
	+ 112459636.5225;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM98(work_wait &parameters) {
  double actual_remaining = 
	1.2788 * parameters.work_so_far 
	+ 0.2468 * parameters.wait_so_far 
	- 2115372.9197 * parameters.num_locks_so_far 
	+ 328032.0889 * parameters.total_wait_locks 
	+ 0.8461 * parameters.mean_wait_of_all 
	- 319817019.6524 * parameters.cpu_usage 
	+ 0.2884 * parameters.avg_work_of_same_past_second 
	- 0.6697 * parameters.avg_wait_of_same_past_second 
	+ 0.0028 * parameters.avg_latency_of_same_last_20 
	- 0.3865 * parameters.max_latency_of_same_last_50 
	+ 699666683.7656;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM99(work_wait &parameters) {
  double actual_remaining = 
	1.3636 * parameters.work_so_far 
	+ 0.2468 * parameters.wait_so_far 
	- 2115372.9197 * parameters.num_locks_so_far 
	+ 328032.0889 * parameters.total_wait_locks 
	+ 0.8461 * parameters.mean_wait_of_all 
	- 319817019.6524 * parameters.cpu_usage 
	+ 0.2884 * parameters.avg_work_of_same_past_second 
	- 0.6697 * parameters.avg_wait_of_same_past_second 
	+ 0.0028 * parameters.avg_latency_of_same_last_20 
	- 0.297 * parameters.max_latency_of_same_last_50 
	+ 567321879.9166;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM100(work_wait &parameters) {
  double actual_remaining = 
	1.7133 * parameters.work_so_far 
	+ 0.7002 * parameters.wait_so_far 
	- 3795246.6556 * parameters.num_locks_so_far 
	+ 1071298.0882 * parameters.total_wait_locks 
	+ 0.5815 * parameters.mean_wait_of_all 
	- 154967107.9906 * parameters.cpu_usage 
	+ 0.1931 * parameters.avg_work_of_same_past_second 
	- 0.4383 * parameters.avg_wait_of_same_past_second 
	+ 0.0028 * parameters.avg_latency_of_same_last_20 
	- 0.0413 * parameters.max_latency_of_same_last_50 
	+ 172743656.0852;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM101(work_wait &parameters) {
  double actual_remaining = 
	107.7826 * parameters.work_so_far 
	- 0.2385 * parameters.wait_so_far 
	+ 67108.9892 * parameters.num_locks_so_far 
	+ 1655527.5729 * parameters.total_wait_locks 
	+ 0.0046 * parameters.mean_wait_of_all 
	- 151821924.9194 * parameters.cpu_usage 
	+ 0.3153 * parameters.avg_work_of_same_past_second 
	- 0.4363 * parameters.avg_wait_of_same_past_second 
	+ 0.0094 * parameters.avg_latency_of_same_last_20 
	- 0.0027 * parameters.max_latency_of_same_last_50 
	+ 116685578.1866;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM102(work_wait &parameters) {
  double actual_remaining = 
	3.8831 * parameters.work_so_far 
	+ 0.0359 * parameters.wait_so_far 
	- 422015.7356 * parameters.num_locks_so_far 
	+ 1486014.1341 * parameters.total_wait_locks 
	+ 0.0033 * parameters.mean_wait_of_all 
	- 4667939.1793 * parameters.cpu_usage 
	+ 0.7245 * parameters.avg_work_of_same_past_second 
	- 0.8226 * parameters.avg_wait_of_same_past_second 
	+ 0.0188 * parameters.avg_latency_of_same_last_20 
	- 0.01 * parameters.max_latency_of_same_last_50 
	- 3830470.2391;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM103(work_wait &parameters) {
  double actual_remaining = 
	1.4996 * parameters.work_so_far 
	+ 0.0359 * parameters.wait_so_far 
	- 400920.5193 * parameters.num_locks_so_far 
	+ 1366037.4333 * parameters.total_wait_locks 
	+ 0.0033 * parameters.mean_wait_of_all 
	- 382517195.3828 * parameters.cpu_usage 
	+ 0.0612 * parameters.avg_work_of_same_past_second 
	- 0.0847 * parameters.avg_wait_of_same_past_second 
	- 0.2373 * parameters.avg_latency_of_same_last_20 
	- 0.0098 * parameters.max_latency_of_same_last_50 
	+ 400086146.1082;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM104(work_wait &parameters) {
  double actual_remaining = 
	2.1933 * parameters.work_so_far 
	+ 0.6318 * parameters.wait_so_far 
	- 174320.3826 * parameters.num_locks_so_far 
	+ 129481.4858 * parameters.total_wait_locks 
	+ 0.0033 * parameters.mean_wait_of_all 
	- 4667939.1793 * parameters.cpu_usage 
	+ 0.0363 * parameters.avg_work_of_same_past_second 
	- 0.49 * parameters.avg_wait_of_same_past_second 
	+ 0.2829 * parameters.avg_latency_of_same_last_20 
	- 0.0088 * parameters.max_latency_of_same_last_50 
	+ 139070473.1098;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM105(work_wait &parameters) {
  double actual_remaining = 
	0.9587 * parameters.work_so_far 
	+ 0.7531 * parameters.wait_so_far 
	- 8114296.1252 * parameters.num_locks_so_far 
	+ 116166.1576 * parameters.total_wait_locks 
	+ 0.0033 * parameters.mean_wait_of_all 
	- 4667939.1793 * parameters.cpu_usage 
	+ 0.7664 * parameters.avg_work_of_same_past_second 
	- 1.0864 * parameters.avg_wait_of_same_past_second 
	+ 0.023 * parameters.avg_latency_of_same_last_20 
	- 0.084 * parameters.max_latency_of_same_last_50 
	+ 538373991.4129;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM106(work_wait &parameters) {
  double actual_remaining = 
	-86.7703 * parameters.work_so_far 
	- 0.2811 * parameters.wait_so_far 
	+ 198616.813 * parameters.num_locks_so_far 
	- 287301.0008 * parameters.total_wait_locks 
	+ 1.5402 * parameters.mean_wait_of_all 
	- 246566187.2475 * parameters.cpu_usage 
	+ 0.1465 * parameters.avg_work_of_same_past_second 
	- 0.313 * parameters.avg_wait_of_same_past_second 
	+ 0.0014 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 596816444.6758;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM107(work_wait &parameters) {
  double actual_remaining = 
	2.031 * parameters.work_so_far 
	- 0.1161 * parameters.wait_so_far 
	+ 196525564.812 * parameters.num_locks_so_far 
	- 21763.1256 * parameters.total_wait_locks 
	+ 0.1018 * parameters.mean_wait_of_all 
	- 6413274.4434 * parameters.cpu_usage 
	+ 0.2809 * parameters.avg_work_of_same_past_second 
	- 0.0103 * parameters.avg_wait_of_same_past_second 
	+ 0.2407 * parameters.avg_latency_of_same_last_20 
	- 0.005 * parameters.max_latency_of_same_last_50 
	- 652909514.5706;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM108(work_wait &parameters) {
  double actual_remaining = 
	2.031 * parameters.work_so_far 
	- 0.0139 * parameters.wait_so_far 
	+ 18704958.3697 * parameters.num_locks_so_far 
	+ 2517902.2802 * parameters.total_wait_locks 
	- 19.743 * parameters.mean_wait_of_all 
	+ 443881765.9503 * parameters.cpu_usage 
	+ 0.1599 * parameters.avg_work_of_same_past_second 
	- 0.3727 * parameters.avg_wait_of_same_past_second 
	- 0.2837 * parameters.avg_latency_of_same_last_20 
	- 0.0943 * parameters.max_latency_of_same_last_50 
	+ 1361631306.9183;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM109(work_wait &parameters) {
  double actual_remaining = 
	2.031 * parameters.work_so_far 
	- 0.0139 * parameters.wait_so_far 
	+ 18704958.3697 * parameters.num_locks_so_far 
	+ 2351194.8979 * parameters.total_wait_locks 
	- 18.3547 * parameters.mean_wait_of_all 
	+ 443881765.9503 * parameters.cpu_usage 
	+ 0.1599 * parameters.avg_work_of_same_past_second 
	- 0.3727 * parameters.avg_wait_of_same_past_second 
	+ 0.139 * parameters.avg_latency_of_same_last_20 
	- 0.173 * parameters.max_latency_of_same_last_50 
	+ 1345238554.8733;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM110(work_wait &parameters) {
  double actual_remaining = 
	2.031 * parameters.work_so_far 
	- 0.0139 * parameters.wait_so_far 
	+ 18704958.3697 * parameters.num_locks_so_far 
	+ 2351194.8979 * parameters.total_wait_locks 
	- 18.3547 * parameters.mean_wait_of_all 
	+ 443881765.9503 * parameters.cpu_usage 
	+ 0.1599 * parameters.avg_work_of_same_past_second 
	- 0.3727 * parameters.avg_wait_of_same_past_second 
	+ 0.139 * parameters.avg_latency_of_same_last_20 
	- 0.15 * parameters.max_latency_of_same_last_50 
	+ 1205273040.7611;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM111(work_wait &parameters) {
  double actual_remaining = 
	241.421 * parameters.work_so_far 
	- 0.0139 * parameters.wait_so_far 
	+ 18704958.3697 * parameters.num_locks_so_far 
	+ 2430211.9379 * parameters.total_wait_locks 
	+ 32.4302 * parameters.mean_wait_of_all 
	+ 930687215.0246 * parameters.cpu_usage 
	+ 0.1599 * parameters.avg_work_of_same_past_second 
	- 0.7645 * parameters.avg_wait_of_same_past_second 
	+ 0.0267 * parameters.avg_latency_of_same_last_20 
	- 0.0403 * parameters.max_latency_of_same_last_50 
	- 5421648009.1018;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM112(work_wait &parameters) {
  double actual_remaining = 
	241.421 * parameters.work_so_far 
	+ 0.039 * parameters.wait_so_far 
	+ 18704958.3697 * parameters.num_locks_so_far 
	+ 2430211.9379 * parameters.total_wait_locks 
	+ 23.6943 * parameters.mean_wait_of_all 
	+ 930687215.0246 * parameters.cpu_usage 
	+ 0.1599 * parameters.avg_work_of_same_past_second 
	- 0.7645 * parameters.avg_wait_of_same_past_second 
	+ 0.0267 * parameters.avg_latency_of_same_last_20 
	- 0.0403 * parameters.max_latency_of_same_last_50 
	- 4312870363.6659;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM113(work_wait &parameters) {
  double actual_remaining = 
	223.6884 * parameters.work_so_far 
	- 0.0139 * parameters.wait_so_far 
	+ 18704958.3697 * parameters.num_locks_so_far 
	+ 2430211.9379 * parameters.total_wait_locks 
	- 15.6171 * parameters.mean_wait_of_all 
	+ 930687215.0246 * parameters.cpu_usage 
	+ 0.1599 * parameters.avg_work_of_same_past_second 
	- 0.7645 * parameters.avg_wait_of_same_past_second 
	+ 0.0267 * parameters.avg_latency_of_same_last_20 
	- 0.0403 * parameters.max_latency_of_same_last_50 
	+ 482878048.7527;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM114(work_wait &parameters) {
  double actual_remaining = 
	153.4108 * parameters.work_so_far 
	- 0.188 * parameters.wait_so_far 
	+ 18704958.3697 * parameters.num_locks_so_far 
	- 21763.1256 * parameters.total_wait_locks 
	+ 12.6884 * parameters.mean_wait_of_all 
	- 369698167.5895 * parameters.cpu_usage 
	+ 0.3915 * parameters.avg_work_of_same_past_second 
	- 0.0103 * parameters.avg_wait_of_same_past_second 
	+ 0.0267 * parameters.avg_latency_of_same_last_20 
	- 0.1796 * parameters.max_latency_of_same_last_50 
	- 1050294418.7379;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM115(work_wait &parameters) {
  double actual_remaining = 
	153.4108 * parameters.work_so_far 
	- 0.2943 * parameters.wait_so_far 
	+ 18704958.3697 * parameters.num_locks_so_far 
	- 2045859.2025 * parameters.total_wait_locks 
	+ 7.1619 * parameters.mean_wait_of_all 
	- 369698167.5895 * parameters.cpu_usage 
	+ 0.3915 * parameters.avg_work_of_same_past_second 
	- 0.0103 * parameters.avg_wait_of_same_past_second 
	+ 0.0267 * parameters.avg_latency_of_same_last_20 
	- 0.1426 * parameters.max_latency_of_same_last_50 
	+ 888089790.6351;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM116(work_wait &parameters) {
  double actual_remaining = 
	477.3651 * parameters.work_so_far 
	- 0.0358 * parameters.wait_so_far 
	+ 18704958.3697 * parameters.num_locks_so_far 
	- 21763.1256 * parameters.total_wait_locks 
	- 1.9175 * parameters.mean_wait_of_all 
	- 772961706.5335 * parameters.cpu_usage 
	+ 1.0888 * parameters.avg_work_of_same_past_second 
	- 0.0103 * parameters.avg_wait_of_same_past_second 
	+ 0.0873 * parameters.avg_latency_of_same_last_20 
	- 0.0723 * parameters.max_latency_of_same_last_50 
	+ 735618657.8589;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM117(work_wait &parameters) {
  double actual_remaining = 
	115.2055 * parameters.work_so_far 
	- 0.1333 * parameters.wait_so_far 
	+ 1338102.06 * parameters.num_locks_so_far 
	- 962946.7747 * parameters.total_wait_locks 
	+ 4.416 * parameters.mean_wait_of_all 
	- 3923193.1836 * parameters.cpu_usage 
	+ 0.4644 * parameters.avg_work_of_same_past_second 
	- 0.557 * parameters.avg_wait_of_same_past_second 
	+ 0.2311 * parameters.avg_latency_of_same_last_20 
	- 0.0549 * parameters.max_latency_of_same_last_50 
	+ 175631504.2532;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM118(work_wait &parameters) {
  double actual_remaining = 
	3.6905 * parameters.work_so_far 
	+ 0.8112 * parameters.wait_so_far 
	- 52419.1183 * parameters.num_locks_so_far 
	- 233602.9364 * parameters.total_wait_locks 
	+ 1.0801 * parameters.mean_wait_of_all 
	- 7125956.7497 * parameters.cpu_usage 
	+ 1.5095 * parameters.avg_work_of_same_past_second 
	- 0.2802 * parameters.avg_wait_of_same_past_second 
	+ 0.005 * parameters.avg_latency_of_same_last_20 
	- 0.0015 * parameters.max_latency_of_same_last_50 
	+ 74356632.7657;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM119(work_wait &parameters) {
  double actual_remaining = 
	2.7851 * parameters.work_so_far 
	+ 0.0324 * parameters.wait_so_far 
	- 1397553.1165 * parameters.num_locks_so_far 
	- 2214284.6718 * parameters.total_wait_locks 
	+ 3.8463 * parameters.mean_wait_of_all 
	- 57204352.4704 * parameters.cpu_usage 
	+ 2.4654 * parameters.avg_work_of_same_past_second 
	+ 2.1838 * parameters.avg_wait_of_same_past_second 
	+ 0.1215 * parameters.avg_latency_of_same_last_20 
	- 0.0527 * parameters.max_latency_of_same_last_50 
	+ 49740816.85;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM120(work_wait &parameters) {
  double actual_remaining = 
	2.7851 * parameters.work_so_far 
	+ 0.0324 * parameters.wait_so_far 
	- 1397553.1165 * parameters.num_locks_so_far 
	- 2214284.6718 * parameters.total_wait_locks 
	+ 3.8463 * parameters.mean_wait_of_all 
	- 57204352.4704 * parameters.cpu_usage 
	+ 2.4654 * parameters.avg_work_of_same_past_second 
	+ 2.1838 * parameters.avg_wait_of_same_past_second 
	+ 0.1215 * parameters.avg_latency_of_same_last_20 
	- 0.0527 * parameters.max_latency_of_same_last_50 
	- 57731333.4189;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM121(work_wait &parameters) {
  double actual_remaining = 
	2.7851 * parameters.work_so_far 
	+ 0.0324 * parameters.wait_so_far 
	- 1397553.1165 * parameters.num_locks_so_far 
	+ 1169097.63 * parameters.total_wait_locks 
	+ 0.1875 * parameters.mean_wait_of_all 
	- 57204352.4704 * parameters.cpu_usage 
	+ 0.0142 * parameters.avg_work_of_same_past_second 
	- 0.0107 * parameters.avg_wait_of_same_past_second 
	+ 0.0818 * parameters.avg_latency_of_same_last_20 
	- 0.0375 * parameters.max_latency_of_same_last_50 
	+ 90148025.1843;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM122(work_wait &parameters) {
  double actual_remaining = 
	22.8529 * parameters.work_so_far 
	+ 0.0226 * parameters.wait_so_far 
	- 10902589.404 * parameters.num_locks_so_far 
	- 42158.0395 * parameters.total_wait_locks 
	+ 0.1011 * parameters.mean_wait_of_all 
	- 32794456.2609 * parameters.cpu_usage 
	+ 0.0142 * parameters.avg_work_of_same_past_second 
	- 0.0107 * parameters.avg_wait_of_same_past_second 
	+ 0.2457 * parameters.avg_latency_of_same_last_20 
	- 0.0921 * parameters.max_latency_of_same_last_50 
	+ 393027690.4237;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM123(work_wait &parameters) {
  double actual_remaining = 
	1.7202 * parameters.work_so_far 
	+ 0.0236 * parameters.wait_so_far 
	- 707153.6137 * parameters.num_locks_so_far 
	- 386557.2966 * parameters.total_wait_locks 
	+ 1.0844 * parameters.mean_wait_of_all 
	- 226138838.3901 * parameters.cpu_usage 
	+ 0.0142 * parameters.avg_work_of_same_past_second 
	- 0.0107 * parameters.avg_wait_of_same_past_second 
	- 0.0614 * parameters.avg_latency_of_same_last_20 
	+ 0.2116 * parameters.max_latency_of_same_last_50 
	+ 597355236.5219;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM124(work_wait &parameters) {
  double actual_remaining = 
	1.7202 * parameters.work_so_far 
	+ 0.0236 * parameters.wait_so_far 
	- 707153.6137 * parameters.num_locks_so_far 
	- 392352.9706 * parameters.total_wait_locks 
	+ 1.1011 * parameters.mean_wait_of_all 
	- 231563161.0989 * parameters.cpu_usage 
	+ 0.0142 * parameters.avg_work_of_same_past_second 
	- 0.0107 * parameters.avg_wait_of_same_past_second 
	- 0.0636 * parameters.avg_latency_of_same_last_20 
	- 0.0256 * parameters.max_latency_of_same_last_50 
	+ 746927016.6781;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM125(work_wait &parameters) {
  double actual_remaining = 
	1.7202 * parameters.work_so_far 
	+ 0.0236 * parameters.wait_so_far 
	- 707153.6137 * parameters.num_locks_so_far 
	- 218914.2428 * parameters.total_wait_locks 
	+ 0.6007 * parameters.mean_wait_of_all 
	- 36287543.5835 * parameters.cpu_usage 
	+ 0.0142 * parameters.avg_work_of_same_past_second 
	- 0.0107 * parameters.avg_wait_of_same_past_second 
	+ 0.0159 * parameters.avg_latency_of_same_last_20 
	- 0.0296 * parameters.max_latency_of_same_last_50 
	+ 462223124.0075;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM126(work_wait &parameters) {
  double actual_remaining = 
	22.331 * parameters.work_so_far 
	+ 0.0294 * parameters.wait_so_far 
	- 613317.5518 * parameters.num_locks_so_far 
	+ 3822131.1768 * parameters.total_wait_locks 
	- 22.6738 * parameters.mean_wait_of_all 
	- 907025801.6603 * parameters.cpu_usage 
	+ 0.0279 * parameters.avg_work_of_same_past_second 
	- 0.0107 * parameters.avg_wait_of_same_past_second 
	+ 0.0174 * parameters.avg_latency_of_same_last_20 
	- 0.0064 * parameters.max_latency_of_same_last_50 
	+ 1999368297.6773;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM127(work_wait &parameters) {
  double actual_remaining = 
	13.1977 * parameters.work_so_far 
	+ 0.1454 * parameters.wait_so_far 
	- 11653308.1009 * parameters.num_locks_so_far 
	- 1560130.9617 * parameters.total_wait_locks 
	+ 7.4547 * parameters.mean_wait_of_all 
	- 137254035.6279 * parameters.cpu_usage 
	- 0.6784 * parameters.avg_work_of_same_past_second 
	+ 2.0474 * parameters.avg_wait_of_same_past_second 
	+ 0.4854 * parameters.avg_latency_of_same_last_20 
	- 0.0094 * parameters.max_latency_of_same_last_50 
	+ 38423432.3593;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM128(work_wait &parameters) {
  double actual_remaining = 
	13.1977 * parameters.work_so_far 
	+ 0.1454 * parameters.wait_so_far 
	- 11653308.1009 * parameters.num_locks_so_far 
	- 1694467.6712 * parameters.total_wait_locks 
	+ 8.2378 * parameters.mean_wait_of_all 
	- 137254035.6279 * parameters.cpu_usage 
	- 0.6784 * parameters.avg_work_of_same_past_second 
	+ 2.0474 * parameters.avg_wait_of_same_past_second 
	+ 0.5371 * parameters.avg_latency_of_same_last_20 
	- 0.0094 * parameters.max_latency_of_same_last_50 
	+ 135696321.8502;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM129(work_wait &parameters) {
  double actual_remaining = 
	13.4989 * parameters.work_so_far 
	+ 0.764 * parameters.wait_so_far 
	- 11963757.8454 * parameters.num_locks_so_far 
	- 821279.0595 * parameters.total_wait_locks 
	+ 3.1086 * parameters.mean_wait_of_all 
	- 555136288.383 * parameters.cpu_usage 
	- 1.7389 * parameters.avg_work_of_same_past_second 
	- 27.1637 * parameters.avg_wait_of_same_past_second 
	+ 0.2079 * parameters.avg_latency_of_same_last_20 
	+ 0.2551 * parameters.max_latency_of_same_last_50 
	+ 7501433737.3406;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM130(work_wait &parameters) {
  double actual_remaining = 
	-19.9331 * parameters.work_so_far 
	+ 0.4101 * parameters.wait_so_far 
	- 11963757.8454 * parameters.num_locks_so_far 
	- 821279.0595 * parameters.total_wait_locks 
	+ 3.1086 * parameters.mean_wait_of_all 
	- 1881557190.3458 * parameters.cpu_usage 
	- 2.3523 * parameters.avg_work_of_same_past_second 
	- 11.7219 * parameters.avg_wait_of_same_past_second 
	+ 0.2079 * parameters.avg_latency_of_same_last_20 
	+ 0.4119 * parameters.max_latency_of_same_last_50 
	+ 5337761552.4865;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM131(work_wait &parameters) {
  double actual_remaining = 
	27.034 * parameters.work_so_far 
	+ 0.6481 * parameters.wait_so_far 
	- 2218863.8433 * parameters.num_locks_so_far 
	- 2697533.4708 * parameters.total_wait_locks 
	+ 11.2571 * parameters.mean_wait_of_all 
	+ 686569273.2189 * parameters.cpu_usage 
	+ 0.0196 * parameters.avg_work_of_same_past_second 
	- 3.571 * parameters.avg_wait_of_same_past_second 
	+ 0.0253 * parameters.avg_latency_of_same_last_20 
	+ 0.1359 * parameters.max_latency_of_same_last_50 
	+ 175560777.7608;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM132(work_wait &parameters) {
  double actual_remaining = 
	0.5491 * parameters.work_so_far 
	+ 0.2327 * parameters.wait_so_far 
	- 11561270.4711 * parameters.num_locks_so_far 
	+ 1070667.1131 * parameters.total_wait_locks 
	- 6.4809 * parameters.mean_wait_of_all 
	- 10505627.3535 * parameters.cpu_usage 
	+ 0.0196 * parameters.avg_work_of_same_past_second 
	- 0.0274 * parameters.avg_wait_of_same_past_second 
	+ 0.317 * parameters.avg_latency_of_same_last_20 
	- 0.0717 * parameters.max_latency_of_same_last_50 
	+ 691020109.285;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM133(work_wait &parameters) {
  double actual_remaining = 
	1.553 * parameters.work_so_far 
	- 0.5283 * parameters.wait_so_far 
	+ 599873.2796 * parameters.num_locks_so_far 
	+ 1205905.198 * parameters.total_wait_locks 
	- 4.6347 * parameters.mean_wait_of_all 
	- 497556818.8695 * parameters.cpu_usage 
	+ 0.0167 * parameters.avg_work_of_same_past_second 
	- 0.0217 * parameters.avg_wait_of_same_past_second 
	+ 0.0158 * parameters.avg_latency_of_same_last_20 
	- 0.004 * parameters.max_latency_of_same_last_50 
	+ 932122224.8359;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM134(work_wait &parameters) {
  double actual_remaining = 
	0.4323 * parameters.work_so_far 
	+ 0.1099 * parameters.wait_so_far 
	- 4010682.8913 * parameters.num_locks_so_far 
	+ 136418.4849 * parameters.total_wait_locks 
	- 0.635 * parameters.mean_wait_of_all 
	- 26798310.7689 * parameters.cpu_usage 
	+ 0.0167 * parameters.avg_work_of_same_past_second 
	- 0.0217 * parameters.avg_wait_of_same_past_second 
	+ 0.0646 * parameters.avg_latency_of_same_last_20 
	- 0.1438 * parameters.max_latency_of_same_last_50 
	+ 648324789.4754;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM135(work_wait &parameters) {
  double actual_remaining = 
	0.2693 * parameters.work_so_far 
	+ 0.1337 * parameters.wait_so_far 
	- 4524759.858 * parameters.num_locks_so_far 
	+ 165343.5154 * parameters.total_wait_locks 
	- 1.5782 * parameters.mean_wait_of_all 
	- 26798310.7689 * parameters.cpu_usage 
	+ 0.0167 * parameters.avg_work_of_same_past_second 
	- 0.0217 * parameters.avg_wait_of_same_past_second 
	+ 0.0311 * parameters.avg_latency_of_same_last_20 
	- 0.0079 * parameters.max_latency_of_same_last_50 
	+ 602602408.7135;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM136(work_wait &parameters) {
  double actual_remaining = 
	0.2693 * parameters.work_so_far 
	+ 0.0817 * parameters.wait_so_far 
	- 26527791.1275 * parameters.num_locks_so_far 
	+ 115072.0124 * parameters.total_wait_locks 
	- 0.5085 * parameters.mean_wait_of_all 
	- 446579722.5865 * parameters.cpu_usage 
	+ 0.0167 * parameters.avg_work_of_same_past_second 
	- 1.2359 * parameters.avg_wait_of_same_past_second 
	+ 0.0311 * parameters.avg_latency_of_same_last_20 
	- 0.0079 * parameters.max_latency_of_same_last_50 
	+ 1478455560.6006;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM137(work_wait &parameters) {
  double actual_remaining = 
	3.1313 * parameters.work_so_far 
	+ 1.0859 * parameters.wait_so_far 
	- 36076866.5665 * parameters.num_locks_so_far 
	- 896792.7294 * parameters.total_wait_locks 
	+ 3.6364 * parameters.mean_wait_of_all 
	- 16190408.2211 * parameters.cpu_usage 
	+ 0.485 * parameters.avg_work_of_same_past_second 
	- 1.1997 * parameters.avg_wait_of_same_past_second 
	+ 0.0095 * parameters.avg_latency_of_same_last_20 
	+ 0.0588 * parameters.max_latency_of_same_last_50 
	+ 911368859.8161;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM138(work_wait &parameters) {
  double actual_remaining = 
	4.2299 * parameters.work_so_far 
	+ 1.0481 * parameters.wait_so_far 
	- 5606398.3223 * parameters.num_locks_so_far 
	- 250261.375 * parameters.total_wait_locks 
	+ 0.979 * parameters.mean_wait_of_all 
	- 286357684.5442 * parameters.cpu_usage 
	+ 0.2334 * parameters.avg_work_of_same_past_second 
	- 0.3347 * parameters.avg_wait_of_same_past_second 
	+ 0.1507 * parameters.avg_latency_of_same_last_20 
	- 0.0379 * parameters.max_latency_of_same_last_50 
	+ 520260468.699;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM139(work_wait &parameters) {
  double actual_remaining = 
	0.2047 * parameters.work_so_far 
	+ 0.0489 * parameters.wait_so_far 
	+ 45481483.2301 * parameters.num_locks_so_far 
	+ 679466.8876 * parameters.total_wait_locks 
	- 2.596 * parameters.mean_wait_of_all 
	- 565178560.5331 * parameters.cpu_usage 
	+ 0.1975 * parameters.avg_work_of_same_past_second 
	- 0.0421 * parameters.avg_wait_of_same_past_second 
	+ 0.0676 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 640033576.0567;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM140(work_wait &parameters) {
  double actual_remaining = 
	0.2047 * parameters.work_so_far 
	+ 0.0489 * parameters.wait_so_far 
	+ 81954048.0206 * parameters.num_locks_so_far 
	+ 290224.5969 * parameters.total_wait_locks 
	- 1.0599 * parameters.mean_wait_of_all 
	- 284219982.8952 * parameters.cpu_usage 
	+ 0.1975 * parameters.avg_work_of_same_past_second 
	+ 0.7672 * parameters.avg_wait_of_same_past_second 
	+ 0.0676 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 50993254.0179;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM141(work_wait &parameters) {
  double actual_remaining = 
	0.2047 * parameters.work_so_far 
	+ 0.3688 * parameters.wait_so_far 
	+ 1091512.841 * parameters.num_locks_so_far 
	- 99017.6938 * parameters.total_wait_locks 
	+ 0.4763 * parameters.mean_wait_of_all 
	- 3261405.2573 * parameters.cpu_usage 
	+ 0.5504 * parameters.avg_work_of_same_past_second 
	- 0.0421 * parameters.avg_wait_of_same_past_second 
	+ 0.0391 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 400662872.0552;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM142(work_wait &parameters) {
  double actual_remaining = 
	0.74 * parameters.work_so_far 
	+ 0.0489 * parameters.wait_so_far 
	+ 14353974.2509 * parameters.num_locks_so_far 
	- 1853772.1367 * parameters.total_wait_locks 
	+ 8.1869 * parameters.mean_wait_of_all 
	- 3261405.2573 * parameters.cpu_usage 
	+ 0.1583 * parameters.avg_work_of_same_past_second 
	- 0.0421 * parameters.avg_wait_of_same_past_second 
	- 0.1126 * parameters.avg_latency_of_same_last_20 
	- 0.021 * parameters.max_latency_of_same_last_50 
	+ 349010291.631;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM143(work_wait &parameters) {
  double actual_remaining = 
	0.8065 * parameters.work_so_far 
	+ 0.1657 * parameters.wait_so_far 
	+ 6472961.3261 * parameters.num_locks_so_far 
	- 3247381.1887 * parameters.total_wait_locks 
	+ 13.9311 * parameters.mean_wait_of_all 
	- 3261405.2573 * parameters.cpu_usage 
	+ 0.1583 * parameters.avg_work_of_same_past_second 
	- 0.0421 * parameters.avg_wait_of_same_past_second 
	- 0.0427 * parameters.avg_latency_of_same_last_20 
	- 0.021 * parameters.max_latency_of_same_last_50 
	+ 448603390.9471;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM144(work_wait &parameters) {
  double actual_remaining = 
	0.99 * parameters.work_so_far 
	+ 0.2631 * parameters.wait_so_far 
	+ 6472961.3261 * parameters.num_locks_so_far 
	- 1975900.4353 * parameters.total_wait_locks 
	+ 8.8121 * parameters.mean_wait_of_all 
	- 3261405.2573 * parameters.cpu_usage 
	+ 0.1583 * parameters.avg_work_of_same_past_second 
	- 0.0421 * parameters.avg_wait_of_same_past_second 
	- 0.0427 * parameters.avg_latency_of_same_last_20 
	- 0.021 * parameters.max_latency_of_same_last_50 
	+ 489691192.8081;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM145(work_wait &parameters) {
  double actual_remaining = 
	0.5728 * parameters.work_so_far 
	+ 0.0489 * parameters.wait_so_far 
	+ 208566.4372 * parameters.num_locks_so_far 
	- 1027366.9745 * parameters.total_wait_locks 
	+ 4.6289 * parameters.mean_wait_of_all 
	- 665093560.264 * parameters.cpu_usage 
	+ 0.1583 * parameters.avg_work_of_same_past_second 
	- 0.0421 * parameters.avg_wait_of_same_past_second 
	+ 0.013 * parameters.avg_latency_of_same_last_20 
	- 0.0388 * parameters.max_latency_of_same_last_50 
	+ 1115780636.5124;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM146(work_wait &parameters) {
  double actual_remaining = 
	0.5395 * parameters.work_so_far 
	+ 0.0489 * parameters.wait_so_far 
	+ 208566.4372 * parameters.num_locks_so_far 
	- 676870.6324 * parameters.total_wait_locks 
	+ 3.2446 * parameters.mean_wait_of_all 
	- 3261405.2573 * parameters.cpu_usage 
	+ 0.2696 * parameters.avg_work_of_same_past_second 
	- 0.0421 * parameters.avg_wait_of_same_past_second 
	+ 0.013 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 642531300.544;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM147(work_wait &parameters) {
  double actual_remaining = 
	0.8643 * parameters.work_so_far 
	+ 0.8636 * parameters.wait_so_far 
	- 4553079.8345 * parameters.num_locks_so_far 
	+ 116825.3723 * parameters.total_wait_locks 
	+ 0.0247 * parameters.mean_wait_of_all 
	- 3261405.2573 * parameters.cpu_usage 
	+ 0.3891 * parameters.avg_work_of_same_past_second 
	- 0.6126 * parameters.avg_wait_of_same_past_second 
	+ 0.1885 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 351476794.5685;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM148(work_wait &parameters) {
  double actual_remaining = 
	0.1894 * parameters.work_so_far 
	- 0.4964 * parameters.wait_so_far 
	- 16758334.6109 * parameters.num_locks_so_far 
	+ 30630.4255 * parameters.total_wait_locks 
	+ 0.5558 * parameters.mean_wait_of_all 
	- 3261405.2573 * parameters.cpu_usage 
	- 0.0628 * parameters.avg_work_of_same_past_second 
	- 0.2195 * parameters.avg_wait_of_same_past_second 
	+ 0.2031 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 1073434008.0161;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM149(work_wait &parameters) {
  double actual_remaining = 
	0.1249 * parameters.work_so_far 
	- 0.4964 * parameters.wait_so_far 
	- 16758334.6109 * parameters.num_locks_so_far 
	+ 28546.144 * parameters.total_wait_locks 
	+ 0.5558 * parameters.mean_wait_of_all 
	- 3261405.2573 * parameters.cpu_usage 
	- 0.0628 * parameters.avg_work_of_same_past_second 
	- 0.2195 * parameters.avg_wait_of_same_past_second 
	+ 0.2031 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 1100160677.6954;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM150(work_wait &parameters) {
  double actual_remaining = 
	0.1894 * parameters.work_so_far 
	- 0.4964 * parameters.wait_so_far 
	- 17612505.8938 * parameters.num_locks_so_far 
	+ 31746.6994 * parameters.total_wait_locks 
	+ 0.5558 * parameters.mean_wait_of_all 
	- 3261405.2573 * parameters.cpu_usage 
	- 0.0628 * parameters.avg_work_of_same_past_second 
	- 0.2195 * parameters.avg_wait_of_same_past_second 
	+ 0.2031 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 1075257228.8299;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM151(work_wait &parameters) {
  double actual_remaining = 
	0.1894 * parameters.work_so_far 
	- 0.7168 * parameters.wait_so_far 
	- 15700720.0869 * parameters.num_locks_so_far 
	- 147410.8447 * parameters.total_wait_locks 
	+ 0.5558 * parameters.mean_wait_of_all 
	- 3261405.2573 * parameters.cpu_usage 
	- 0.1515 * parameters.avg_work_of_same_past_second 
	- 0.2195 * parameters.avg_wait_of_same_past_second 
	+ 0.2031 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 1097669967.5108;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM152(work_wait &parameters) {
  double actual_remaining = 
	0.1894 * parameters.work_so_far 
	+ 0.145 * parameters.wait_so_far 
	- 6837194.4652 * parameters.num_locks_so_far 
	- 394269.9768 * parameters.total_wait_locks 
	+ 0.5558 * parameters.mean_wait_of_all 
	- 3261405.2573 * parameters.cpu_usage 
	+ 0.274 * parameters.avg_work_of_same_past_second 
	- 0.91 * parameters.avg_wait_of_same_past_second 
	+ 0.2031 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 1118736780.5364;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM153(work_wait &parameters) {
  double actual_remaining = 
	0.1894 * parameters.work_so_far 
	+ 0.145 * parameters.wait_so_far 
	- 6215084.7325 * parameters.num_locks_so_far 
	- 64654.3499 * parameters.total_wait_locks 
	+ 0.9517 * parameters.mean_wait_of_all 
	- 3261405.2573 * parameters.cpu_usage 
	+ 0.4933 * parameters.avg_work_of_same_past_second 
	- 0.421 * parameters.avg_wait_of_same_past_second 
	+ 0.3978 * parameters.avg_latency_of_same_last_20 
	- 0.0265 * parameters.max_latency_of_same_last_50 
	+ 493773896.7154;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM154(work_wait &parameters) {
  double actual_remaining = 
	0.1894 * parameters.work_so_far 
	+ 0.145 * parameters.wait_so_far 
	- 6215084.7325 * parameters.num_locks_so_far 
	+ 5957.1936 * parameters.total_wait_locks 
	+ 0.9517 * parameters.mean_wait_of_all 
	- 3261405.2573 * parameters.cpu_usage 
	- 0.0797 * parameters.avg_work_of_same_past_second 
	+ 0.212 * parameters.avg_wait_of_same_past_second 
	+ 0.3675 * parameters.avg_latency_of_same_last_20 
	- 0.074 * parameters.max_latency_of_same_last_50 
	+ 582696004.9897;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM155(work_wait &parameters) {
  double actual_remaining = 
	-0.3549 * parameters.work_so_far 
	+ 0.145 * parameters.wait_so_far 
	- 6215084.7325 * parameters.num_locks_so_far 
	- 147410.8447 * parameters.total_wait_locks 
	+ 1.2959 * parameters.mean_wait_of_all 
	- 3261405.2573 * parameters.cpu_usage 
	+ 0.6992 * parameters.avg_work_of_same_past_second 
	- 0.5962 * parameters.avg_wait_of_same_past_second 
	+ 0.418 * parameters.avg_latency_of_same_last_20 
	- 0.0491 * parameters.max_latency_of_same_last_50 
	+ 826848116.355;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM156(work_wait &parameters) {
  double actual_remaining = 
	-0.3549 * parameters.work_so_far 
	+ 0.145 * parameters.wait_so_far 
	- 6215084.7325 * parameters.num_locks_so_far 
	- 147410.8447 * parameters.total_wait_locks 
	+ 1.2959 * parameters.mean_wait_of_all 
	- 3261405.2573 * parameters.cpu_usage 
	+ 0.6992 * parameters.avg_work_of_same_past_second 
	- 0.5962 * parameters.avg_wait_of_same_past_second 
	+ 0.418 * parameters.avg_latency_of_same_last_20 
	- 0.0491 * parameters.max_latency_of_same_last_50 
	+ 799493938.5385;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM157(work_wait &parameters) {
  double actual_remaining = 
	0.689 * parameters.work_so_far 
	+ 0.6922 * parameters.wait_so_far 
	- 5920219.3683 * parameters.num_locks_so_far 
	+ 562931.8467 * parameters.total_wait_locks 
	- 2.5312 * parameters.mean_wait_of_all 
	- 345896344.702 * parameters.cpu_usage 
	+ 0.5535 * parameters.avg_work_of_same_past_second 
	- 0.446 * parameters.avg_wait_of_same_past_second 
	+ 0.0371 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 865770168.0971;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM158(work_wait &parameters) {
  double actual_remaining = 
	0.8613 * parameters.work_so_far 
	+ 0.9943 * parameters.wait_so_far 
	- 15695562.8019 * parameters.num_locks_so_far 
	- 79707.5348 * parameters.total_wait_locks 
	+ 0.3007 * parameters.mean_wait_of_all 
	- 3261405.2573 * parameters.cpu_usage 
	+ 0.7776 * parameters.avg_work_of_same_past_second 
	- 1.2059 * parameters.avg_wait_of_same_past_second 
	+ 0.0358 * parameters.avg_latency_of_same_last_20 
	+ 0.1169 * parameters.max_latency_of_same_last_50 
	+ 732916348.0947;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM159(work_wait &parameters) {
  double actual_remaining = 
	1.1336 * parameters.work_so_far 
	+ 0.9739 * parameters.wait_so_far 
	+ 1356937.3077 * parameters.num_locks_so_far 
	+ 43485.6194 * parameters.total_wait_locks 
	- 0.1105 * parameters.mean_wait_of_all 
	- 78412662.6236 * parameters.cpu_usage 
	+ 0.006 * parameters.avg_work_of_same_past_second 
	- 0.1361 * parameters.avg_wait_of_same_past_second 
	+ 0.0138 * parameters.avg_latency_of_same_last_20 
	- 0.0039 * parameters.max_latency_of_same_last_50 
	+ 126215073.6923;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM160(work_wait &parameters) {
  double actual_remaining = 
	0.0769 * parameters.work_so_far 
	+ 0.0513 * parameters.wait_so_far 
	+ 441078.0571 * parameters.num_locks_so_far 
	- 38623.1998 * parameters.total_wait_locks 
	+ 0.2428 * parameters.mean_wait_of_all 
	- 23078530.3124 * parameters.cpu_usage 
	+ 0.6911 * parameters.avg_work_of_same_past_second 
	- 0.0265 * parameters.avg_wait_of_same_past_second 
	+ 0.2142 * parameters.avg_latency_of_same_last_20 
	- 0.0064 * parameters.max_latency_of_same_last_50 
	+ 36135873.6246;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM161(work_wait &parameters) {
  double actual_remaining = 
	0.2005 * parameters.work_so_far 
	+ 0.6117 * parameters.wait_so_far 
	+ 1437093.5414 * parameters.num_locks_so_far 
	- 192100.2887 * parameters.total_wait_locks 
	+ 0.9306 * parameters.mean_wait_of_all 
	- 721306473.6903 * parameters.cpu_usage 
	+ 0.006 * parameters.avg_work_of_same_past_second 
	- 0.0334 * parameters.avg_wait_of_same_past_second 
	+ 0.0251 * parameters.avg_latency_of_same_last_20 
	- 0.1111 * parameters.max_latency_of_same_last_50 
	+ 1172557046.1763;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM162(work_wait &parameters) {
  double actual_remaining = 
	0.9272 * parameters.work_so_far 
	- 1.3637 * parameters.wait_so_far 
	+ 2868931.3185 * parameters.num_locks_so_far 
	- 1104229.5709 * parameters.total_wait_locks 
	+ 5.1121 * parameters.mean_wait_of_all 
	- 24458534.3215 * parameters.cpu_usage 
	+ 0.006 * parameters.avg_work_of_same_past_second 
	- 0.0334 * parameters.avg_wait_of_same_past_second 
	- 0.5318 * parameters.avg_latency_of_same_last_20 
	- 0.0061 * parameters.max_latency_of_same_last_50 
	+ 1719921102.1208;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM163(work_wait &parameters) {
  double actual_remaining = 
	1.1283 * parameters.work_so_far 
	+ 0.1516 * parameters.wait_so_far 
	+ 2868931.3185 * parameters.num_locks_so_far 
	- 1104229.5709 * parameters.total_wait_locks 
	+ 5.1121 * parameters.mean_wait_of_all 
	- 24458534.3215 * parameters.cpu_usage 
	+ 0.006 * parameters.avg_work_of_same_past_second 
	- 0.0334 * parameters.avg_wait_of_same_past_second 
	- 0.3528 * parameters.avg_latency_of_same_last_20 
	- 0.0061 * parameters.max_latency_of_same_last_50 
	+ 951465992.3728;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM164(work_wait &parameters) {
  double actual_remaining = 
	-0.0738 * parameters.work_so_far 
	+ 0.4497 * parameters.wait_so_far 
	+ 2868931.3185 * parameters.num_locks_so_far 
	- 1185760.4202 * parameters.total_wait_locks 
	+ 5.6416 * parameters.mean_wait_of_all 
	- 24458534.3215 * parameters.cpu_usage 
	- 0.2878 * parameters.avg_work_of_same_past_second 
	- 0.0334 * parameters.avg_wait_of_same_past_second 
	+ 0.0251 * parameters.avg_latency_of_same_last_20 
	+ 0.1152 * parameters.max_latency_of_same_last_50 
	+ 517725554.1146;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM165(work_wait &parameters) {
  double actual_remaining = 
	-1.554 * parameters.work_so_far 
	+ 1.1673 * parameters.wait_so_far 
	+ 2868931.3185 * parameters.num_locks_so_far 
	- 1033830.9442 * parameters.total_wait_locks 
	+ 4.9049 * parameters.mean_wait_of_all 
	- 24458534.3215 * parameters.cpu_usage 
	- 0.2062 * parameters.avg_work_of_same_past_second 
	- 0.0334 * parameters.avg_wait_of_same_past_second 
	+ 0.0251 * parameters.avg_latency_of_same_last_20 
	- 0.0061 * parameters.max_latency_of_same_last_50 
	+ 389292788.0318;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM166(work_wait &parameters) {
  double actual_remaining = 
	0.9476 * parameters.work_so_far 
	+ 0.7236 * parameters.wait_so_far 
	+ 105556.7087 * parameters.num_locks_so_far 
	- 630193.7231 * parameters.total_wait_locks 
	+ 2.3745 * parameters.mean_wait_of_all 
	- 268832450.6927 * parameters.cpu_usage 
	+ 0.1334 * parameters.avg_work_of_same_past_second 
	- 0.3564 * parameters.avg_wait_of_same_past_second 
	+ 0.3187 * parameters.avg_latency_of_same_last_20 
	- 0.0452 * parameters.max_latency_of_same_last_50 
	+ 492066831.5824;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM167(work_wait &parameters) {
  double actual_remaining = 
	0.7866 * parameters.work_so_far 
	+ 0.8905 * parameters.wait_so_far 
	+ 1320444.6063 * parameters.num_locks_so_far 
	+ 104879.6235 * parameters.total_wait_locks 
	- 0.2213 * parameters.mean_wait_of_all 
	- 2124440.5415 * parameters.cpu_usage 
	- 0.1792 * parameters.avg_work_of_same_past_second 
	+ 0.3047 * parameters.avg_wait_of_same_past_second 
	+ 0.0689 * parameters.avg_latency_of_same_last_20 
	- 0.0371 * parameters.max_latency_of_same_last_50 
	- 35934433.6398;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM168(work_wait &parameters) {
  double actual_remaining = 
	0.0935 * parameters.work_so_far 
	+ 0.1841 * parameters.wait_so_far 
	+ 1320444.6063 * parameters.num_locks_so_far 
	+ 91316.7693 * parameters.total_wait_locks 
	- 0.1858 * parameters.mean_wait_of_all 
	- 2124440.5415 * parameters.cpu_usage 
	+ 0.6546 * parameters.avg_work_of_same_past_second 
	- 0.6777 * parameters.avg_wait_of_same_past_second 
	+ 0.0468 * parameters.avg_latency_of_same_last_20 
	- 0.0344 * parameters.max_latency_of_same_last_50 
	+ 143028738.1856;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM169(work_wait &parameters) {
  double actual_remaining = 
	0.9981 * parameters.work_so_far 
	+ 0.8392 * parameters.wait_so_far 
	+ 828458.7185 * parameters.num_locks_so_far 
	- 1633747.5594 * parameters.total_wait_locks 
	+ 7.9891 * parameters.mean_wait_of_all 
	- 2124440.5415 * parameters.cpu_usage 
	+ 0.2175 * parameters.avg_work_of_same_past_second 
	+ 0.0388 * parameters.avg_wait_of_same_past_second 
	+ 0.3385 * parameters.avg_latency_of_same_last_20 
	- 0.0094 * parameters.max_latency_of_same_last_50 
	- 115197400.2922;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
tpcc_estimate(work_wait &parameters){

  if (parameters.num_locks_so_far <= 2.5) {

    if (parameters.work_so_far <= 154699.5) {

      if (parameters.avg_work_of_same_past_second <= 37178850) {

        if (parameters.total_wait_locks <= 191.5) {

          if (parameters.work_so_far <= 8996) {
            return tpcc_LM1(parameters);
          } else {

            if (parameters.max_latency_of_same_last_50 <= 564447000) {

              if (parameters.total_wait_locks <= 42.5) {
                return tpcc_LM2(parameters);
              } else {

                if (parameters.cpu_usage <= 0.892) {

                  if (parameters.cpu_usage <= 0.842) {

                    if (parameters.avg_wait_of_same_past_second <= 22752200) {

                      if (parameters.work_so_far <= 37718) {
                        return tpcc_LM3(parameters);
                      } else {
                        return tpcc_LM4(parameters);
                      }
                    } else {
                      return tpcc_LM5(parameters);
                    }
                  } else {

                    if (parameters.mean_wait_of_all <= 26803850) {

                      if (parameters.avg_latency_of_same_last_20 <= 51347600) {

                        if (parameters.max_latency_of_same_last_50 <= 161880500) {
                          return tpcc_LM6(parameters);
                        } else {

                          if (parameters.work_so_far <= 18192.5) {
                            return tpcc_LM7(parameters);
                          } else {
                            return tpcc_LM8(parameters);
                          }
                        }
                      } else {
                        return tpcc_LM9(parameters);
                      }
                    } else {

                      if (parameters.max_latency_of_same_last_50 <= 232749500) {

                        if (parameters.avg_work_of_same_past_second <= 12897250) {

                          if (parameters.avg_work_of_same_past_second <= 6903650) {
                            return tpcc_LM10(parameters);
                          } else {

                            if (parameters.mean_wait_of_all <= 39827450) {
                              return tpcc_LM11(parameters);
                            } else {
                              return tpcc_LM12(parameters);
                            }
                          }
                        } else {
                          return tpcc_LM13(parameters);
                        }
                      } else {

                        if (parameters.cpu_usage <= 0.876) {

                          if (parameters.mean_wait_of_all <= 30160800) {
                            return tpcc_LM14(parameters);
                          } else {
                            return tpcc_LM15(parameters);
                          }
                        } else {

                          if (parameters.avg_work_of_same_past_second <= 10850350) {
                            return tpcc_LM16(parameters);
                          } else {

                            if (parameters.mean_wait_of_all <= 31556250) {
                              return tpcc_LM17(parameters);
                            } else {
                              return tpcc_LM18(parameters);
                            }
                          }
                        }
                      }
                    }
                  }
                } else {

                  if (parameters.avg_work_of_same_past_second <= 9712315) {

                    if (parameters.cpu_usage <= 0.927) {
                      return tpcc_LM19(parameters);
                    } else {

                      if (parameters.cpu_usage <= 0.949) {

                        if (parameters.avg_latency_of_same_last_20 <= 99052250) {
                          return tpcc_LM20(parameters);
                        } else {
                          return tpcc_LM21(parameters);
                        }
                      } else {
                        return tpcc_LM22(parameters);
                      }
                    }
                  } else {

                    if (parameters.work_so_far <= 21766.5) {

                      if (parameters.avg_work_of_same_past_second <= 19180950) {
                        return tpcc_LM23(parameters);
                      } else {

                        if (parameters.mean_wait_of_all <= 30339400) {

                          if (parameters.mean_wait_of_all <= 29850150) {
                            return tpcc_LM24(parameters);
                          } else {

                            if (parameters.wait_so_far <= 4634) {
                              return tpcc_LM25(parameters);
                            } else {

                              if (parameters.avg_wait_of_same_past_second <= 221293500) {
                                return tpcc_LM26(parameters);
                              } else {
                                return tpcc_LM27(parameters);
                              }
                            }
                          }
                        } else {
                          return tpcc_LM28(parameters);
                        }
                      }
                    } else {

                      if (parameters.avg_wait_of_same_past_second <= 182815500) {

                        if (parameters.mean_wait_of_all <= 28985400) {
                          return tpcc_LM29(parameters);
                        } else {
                          return tpcc_LM30(parameters);
                        }
                      } else {
                        return tpcc_LM31(parameters);
                      }
                    }
                  }
                }
              }
            } else {

              if (parameters.avg_work_of_same_past_second <= 24227350) {

                if (parameters.avg_latency_of_same_last_20 <= 275269500) {

                  if (parameters.avg_wait_of_same_past_second <= 42764850) {
                    return tpcc_LM32(parameters);
                  } else {
                    return tpcc_LM33(parameters);
                  }
                } else {
                  return tpcc_LM34(parameters);
                }
              } else {

                if (parameters.work_so_far <= 32129) {

                  if (parameters.max_latency_of_same_last_50 <= 801941500) {

                    if (parameters.total_wait_locks <= 81.5) {
                      return tpcc_LM35(parameters);
                    } else {

                      if (parameters.max_latency_of_same_last_50 <= 685627000) {

                        if (parameters.wait_so_far <= 5627) {
                          return tpcc_LM36(parameters);
                        } else {

                          if (parameters.wait_so_far <= 4825384) {
                            return tpcc_LM37(parameters);
                          } else {
                            return tpcc_LM38(parameters);
                          }
                        }
                      } else {
                        return tpcc_LM39(parameters);
                      }
                    }
                  } else {

                    if (parameters.max_latency_of_same_last_50 <= 918019500) {
                      return tpcc_LM40(parameters);
                    } else {

                      if (parameters.avg_wait_of_same_past_second <= 225333000) {
                        return tpcc_LM41(parameters);
                      } else {

                        if (parameters.wait_so_far <= 12268) {
                          return tpcc_LM42(parameters);
                        } else {

                          if (parameters.max_latency_of_same_last_50 <= 1294270000) {

                            if (parameters.max_latency_of_same_last_50 <= 975031500) {
                              return tpcc_LM43(parameters);
                            } else {

                              if (parameters.mean_wait_of_all <= 38053200) {
                                return tpcc_LM44(parameters);
                              } else {

                                if (parameters.work_so_far <= 28933.5) {

                                  if (parameters.work_so_far <= 28137) {

                                    if (parameters.max_latency_of_same_last_50 <= 1103255000) {
                                      return tpcc_LM45(parameters);
                                    } else {

                                      if (parameters.avg_wait_of_same_past_second <= 318865000) {
                                        return tpcc_LM46(parameters);
                                      } else {
                                        return tpcc_LM47(parameters);
                                      }
                                    }
                                  } else {
                                    return tpcc_LM48(parameters);
                                  }
                                } else {
                                  return tpcc_LM49(parameters);
                                }
                              }
                            }
                          } else {
                            return tpcc_LM50(parameters);
                          }
                        }
                      }
                    }
                  }
                } else {

                  if (parameters.avg_wait_of_same_past_second <= 353214000) {

                    if (parameters.cpu_usage <= 0.964) {
                      return tpcc_LM51(parameters);
                    } else {

                      if (parameters.wait_so_far <= 90838836) {
                        return tpcc_LM52(parameters);
                      } else {
                        return tpcc_LM53(parameters);
                      }
                    }
                  } else {

                    if (parameters.avg_wait_of_same_past_second <= 367611500) {

                      if (parameters.wait_so_far <= 201004805) {
                        return tpcc_LM54(parameters);
                      } else {
                        return tpcc_LM55(parameters);
                      }
                    } else {
                      return tpcc_LM56(parameters);
                    }
                  }
                }
              }
            }
          }
        } else {

          if (parameters.cpu_usage <= 0.972) {

            if (parameters.mean_wait_of_all <= 91235750) {
              return tpcc_LM57(parameters);
            } else {

              if (parameters.avg_latency_of_same_last_20 <= 411492500) {
                return tpcc_LM58(parameters);
              } else {

                if (parameters.mean_wait_of_all <= 122054000) {

                  if (parameters.mean_wait_of_all <= 113068500) {

                    if (parameters.max_latency_of_same_last_50 <= 1135970000) {
                      return tpcc_LM59(parameters);
                    } else {

                      if (parameters.avg_work_of_same_past_second <= 32454450) {

                        if (parameters.avg_latency_of_same_last_20 <= 507295000) {

                          if (parameters.wait_so_far <= 169987873.5) {
                            return tpcc_LM60(parameters);
                          } else {

                            if (parameters.wait_so_far <= 222371471.5) {

                              if (parameters.max_latency_of_same_last_50 <= 1525655000) {
                                return tpcc_LM61(parameters);
                              } else {
                                return tpcc_LM62(parameters);
                              }
                            } else {
                              return tpcc_LM63(parameters);
                            }
                          }
                        } else {
                          return tpcc_LM64(parameters);
                        }
                      } else {
                        return tpcc_LM65(parameters);
                      }
                    }
                  } else {
                    return tpcc_LM66(parameters);
                  }
                } else {
                  return tpcc_LM67(parameters);
                }
              }
            }
          } else {
            return tpcc_LM68(parameters);
          }
        }
      } else {

        if (parameters.avg_work_of_same_past_second <= 61139950) {

          if (parameters.mean_wait_of_all <= 117647500) {
            return tpcc_LM69(parameters);
          } else {

            if (parameters.mean_wait_of_all <= 123610000) {

              if (parameters.mean_wait_of_all <= 118788500) {

                if (parameters.avg_work_of_same_past_second <= 52663000) {

                  if (parameters.total_wait_locks <= 372.5) {
                    return tpcc_LM70(parameters);
                  } else {
                    return tpcc_LM71(parameters);
                  }
                } else {

                  if (parameters.wait_so_far <= 29369173.5) {

                    if (parameters.total_wait_locks <= 437) {
                      return tpcc_LM72(parameters);
                    } else {
                      return tpcc_LM73(parameters);
                    }
                  } else {
                    return tpcc_LM74(parameters);
                  }
                }
              } else {
                return tpcc_LM75(parameters);
              }
            } else {

              if (parameters.total_wait_locks <= 524.5) {
                return tpcc_LM76(parameters);
              } else {
                return tpcc_LM77(parameters);
              }
            }
          }
        } else {
          return tpcc_LM78(parameters);
        }
      }
    } else {

      if (parameters.wait_so_far <= 346163874) {

        if (parameters.avg_work_of_same_past_second <= 39732600) {
          return tpcc_LM79(parameters);
        } else {
          return tpcc_LM80(parameters);
        }
      } else {
        return tpcc_LM81(parameters);
      }
    }
  } else {

    if (parameters.total_wait_locks <= 187.5) {

      if (parameters.total_wait_locks <= 90.5) {

        if (parameters.work_so_far <= 61726395.5) {

          if (parameters.total_wait_locks <= 39.5) {

            if (parameters.work_so_far <= 27466.5) {
              return tpcc_LM82(parameters);
            } else {

              if (parameters.avg_wait_of_same_past_second <= 5010170) {
                return tpcc_LM83(parameters);
              } else {
                return tpcc_LM84(parameters);
              }
            }
          } else {

            if (parameters.total_wait_locks <= 65.5) {
              return tpcc_LM85(parameters);
            } else {

              if (parameters.work_so_far <= 82501.5) {

                if (parameters.wait_so_far <= 11274094) {
                  return tpcc_LM86(parameters);
                } else {
                  return tpcc_LM87(parameters);
                }
              } else {
                return tpcc_LM88(parameters);
              }
            }
          }
        } else {

          if (parameters.work_so_far <= 181302653.5) {

            if (parameters.max_latency_of_same_last_50 <= 311868000) {

              if (parameters.work_so_far <= 93557032) {
                return tpcc_LM89(parameters);
              } else {

                if (parameters.total_wait_locks <= 53.5) {

                  if (parameters.num_locks_so_far <= 33) {
                    return tpcc_LM90(parameters);
                  } else {
                    return tpcc_LM91(parameters);
                  }
                } else {
                  return tpcc_LM92(parameters);
                }
              }
            } else {

              if (parameters.avg_latency_of_same_last_20 <= 97090400) {
                return tpcc_LM93(parameters);
              } else {

                if (parameters.work_so_far <= 131152149.5) {

                  if (parameters.num_locks_so_far <= 31) {
                    return tpcc_LM94(parameters);
                  } else {
                    return tpcc_LM95(parameters);
                  }
                } else {
                  return tpcc_LM96(parameters);
                }
              }
            }
          } else {

            if (parameters.avg_work_of_same_past_second <= 58190350) {
              return tpcc_LM97(parameters);
            } else {

              if (parameters.avg_wait_of_same_past_second <= 8137205) {

                if (parameters.max_latency_of_same_last_50 <= 274760500) {
                  return tpcc_LM98(parameters);
                } else {
                  return tpcc_LM99(parameters);
                }
              } else {
                return tpcc_LM100(parameters);
              }
            }
          }
        }
      } else {

        if (parameters.work_so_far <= 808039) {
          return tpcc_LM101(parameters);
        } else {

          if (parameters.work_so_far <= 124871663) {

            if (parameters.wait_so_far <= 123801365.5) {

              if (parameters.num_locks_so_far <= 21.5) {
                return tpcc_LM102(parameters);
              } else {
                return tpcc_LM103(parameters);
              }
            } else {
              return tpcc_LM104(parameters);
            }
          } else {
            return tpcc_LM105(parameters);
          }
        }
      }
    } else {

      if (parameters.work_so_far <= 849283) {

        if (parameters.wait_so_far <= 224780601.5) {
          return tpcc_LM106(parameters);
        } else {

          if (parameters.cpu_usage <= 0.889) {

            if (parameters.total_wait_locks <= 475.5) {
              return tpcc_LM107(parameters);
            } else {

              if (parameters.mean_wait_of_all <= 129338000) {

                if (parameters.cpu_usage <= 0.874) {

                  if (parameters.avg_latency_of_same_last_20 <= 579702500) {
                    return tpcc_LM108(parameters);
                  } else {

                    if (parameters.avg_wait_of_same_past_second <= 225403000) {
                      return tpcc_LM109(parameters);
                    } else {
                      return tpcc_LM110(parameters);
                    }
                  }
                } else {

                  if (parameters.mean_wait_of_all <= 126764000) {

                    if (parameters.mean_wait_of_all <= 123629500) {
                      return tpcc_LM111(parameters);
                    } else {
                      return tpcc_LM112(parameters);
                    }
                  } else {
                    return tpcc_LM113(parameters);
                  }
                }
              } else {

                if (parameters.max_latency_of_same_last_50 <= 1461265000) {

                  if (parameters.mean_wait_of_all <= 132150500) {
                    return tpcc_LM114(parameters);
                  } else {
                    return tpcc_LM115(parameters);
                  }
                } else {
                  return tpcc_LM116(parameters);
                }
              }
            }
          } else {
            return tpcc_LM117(parameters);
          }
        }
      } else {

        if (parameters.wait_so_far <= 369226837) {

          if (parameters.work_so_far <= 78380430.5) {

            if (parameters.num_locks_so_far <= 14.5) {

              if (parameters.avg_work_of_same_past_second <= 194265500) {
                return tpcc_LM118(parameters);
              } else {

                if (parameters.work_so_far <= 9147267.5) {

                  if (parameters.mean_wait_of_all <= 96775750) {

                    if (parameters.work_so_far <= 4861169) {

                      if (parameters.avg_work_of_same_past_second <= 220881500) {

                        if (parameters.avg_wait_of_same_past_second <= 196716500) {

                          if (parameters.total_wait_locks <= 281.5) {
                            return tpcc_LM119(parameters);
                          } else {
                            return tpcc_LM120(parameters);
                          }
                        } else {
                          return tpcc_LM121(parameters);
                        }
                      } else {
                        return tpcc_LM122(parameters);
                      }
                    } else {

                      if (parameters.max_latency_of_same_last_50 <= 1284955000) {

                        if (parameters.avg_latency_of_same_last_20 <= 351454000) {
                          return tpcc_LM123(parameters);
                        } else {
                          return tpcc_LM124(parameters);
                        }
                      } else {
                        return tpcc_LM125(parameters);
                      }
                    }
                  } else {

                    if (parameters.avg_work_of_same_past_second <= 235637500) {
                      return tpcc_LM126(parameters);
                    } else {

                      if (parameters.avg_wait_of_same_past_second <= 229274500) {

                        if (parameters.max_latency_of_same_last_50 <= 1007595000) {

                          if (parameters.avg_wait_of_same_past_second <= 213077500) {

                            if (parameters.avg_latency_of_same_last_20 <= 391747000) {
                              return tpcc_LM127(parameters);
                            } else {
                              return tpcc_LM128(parameters);
                            }
                          } else {

                            if (parameters.avg_work_of_same_past_second <= 279924500) {
                              return tpcc_LM129(parameters);
                            } else {
                              return tpcc_LM130(parameters);
                            }
                          }
                        } else {
                          return tpcc_LM131(parameters);
                        }
                      } else {
                        return tpcc_LM132(parameters);
                      }
                    }
                  }
                } else {

                  if (parameters.num_locks_so_far <= 9.5) {

                    if (parameters.num_locks_so_far <= 5.5) {
                      return tpcc_LM133(parameters);
                    } else {

                      if (parameters.avg_latency_of_same_last_20 <= 294521000) {
                        return tpcc_LM134(parameters);
                      } else {

                        if (parameters.wait_so_far <= 4930130) {
                          return tpcc_LM135(parameters);
                        } else {
                          return tpcc_LM136(parameters);
                        }
                      }
                    }
                  } else {
                    return tpcc_LM137(parameters);
                  }
                }
              }
            } else {
              return tpcc_LM138(parameters);
            }
          } else {

            if (parameters.work_so_far <= 357675829) {

              if (parameters.num_locks_so_far <= 20.5) {

                if (parameters.work_so_far <= 135882900.5) {

                  if (parameters.num_locks_so_far <= 7.5) {

                    if (parameters.avg_latency_of_same_last_20 <= 170870500) {
                      return tpcc_LM139(parameters);
                    } else {
                      return tpcc_LM140(parameters);
                    }
                  } else {
                    return tpcc_LM141(parameters);
                  }
                } else {

                  if (parameters.avg_work_of_same_past_second <= 306402000) {

                    if (parameters.num_locks_so_far <= 13.5) {

                      if (parameters.num_locks_so_far <= 5.5) {
                        return tpcc_LM142(parameters);
                      } else {

                        if (parameters.work_so_far <= 261881978) {
                          return tpcc_LM143(parameters);
                        } else {
                          return tpcc_LM144(parameters);
                        }
                      }
                    } else {
                      return tpcc_LM145(parameters);
                    }
                  } else {
                    return tpcc_LM146(parameters);
                  }
                }
              } else {
                return tpcc_LM147(parameters);
              }
            } else {

              if (parameters.work_so_far <= 634681264) {

                if (parameters.num_locks_so_far <= 30.5) {

                  if (parameters.num_locks_so_far <= 25.5) {

                    if (parameters.work_so_far <= 409819975) {

                      if (parameters.avg_work_of_same_past_second <= 293467500) {

                        if (parameters.num_locks_so_far <= 19.5) {

                          if (parameters.total_wait_locks <= 263) {
                            return tpcc_LM148(parameters);
                          } else {
                            return tpcc_LM149(parameters);
                          }
                        } else {
                          return tpcc_LM150(parameters);
                        }
                      } else {
                        return tpcc_LM151(parameters);
                      }
                    } else {
                      return tpcc_LM152(parameters);
                    }
                  } else {

                    if (parameters.avg_work_of_same_past_second <= 355636500) {

                      if (parameters.avg_latency_of_same_last_20 <= 416775500) {
                        return tpcc_LM153(parameters);
                      } else {
                        return tpcc_LM154(parameters);
                      }
                    } else {

                      if (parameters.work_so_far <= 421636462.5) {
                        return tpcc_LM155(parameters);
                      } else {
                        return tpcc_LM156(parameters);
                      }
                    }
                  }
                } else {
                  return tpcc_LM157(parameters);
                }
              } else {
                return tpcc_LM158(parameters);
              }
            }
          }
        } else {

          if (parameters.wait_so_far <= 744762502.5) {

            if (parameters.avg_work_of_same_past_second <= 170875500) {
              return tpcc_LM159(parameters);
            } else {

              if (parameters.num_locks_so_far <= 5.5) {
                return tpcc_LM160(parameters);
              } else {

                if (parameters.num_locks_so_far <= 12.5) {

                  if (parameters.work_so_far <= 11752373.5) {
                    return tpcc_LM161(parameters);
                  } else {

                    if (parameters.wait_so_far <= 416803852) {

                      if (parameters.avg_latency_of_same_last_20 <= 368589000) {
                        return tpcc_LM162(parameters);
                      } else {
                        return tpcc_LM163(parameters);
                      }
                    } else {

                      if (parameters.total_wait_locks <= 378.5) {
                        return tpcc_LM164(parameters);
                      } else {
                        return tpcc_LM165(parameters);
                      }
                    }
                  }
                } else {
                  return tpcc_LM166(parameters);
                }
              }
            }
          } else {

            if (parameters.num_locks_so_far <= 4.5) {

              if (parameters.avg_work_of_same_past_second <= 108725300) {
                return tpcc_LM167(parameters);
              } else {
                return tpcc_LM168(parameters);
              }
            } else {
              return tpcc_LM169(parameters);
            }
          }
        }
      }
    }
  }
}