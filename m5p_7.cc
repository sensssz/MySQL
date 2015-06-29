#include "my_global.h"
#include "m5p.h"
#include "trace_tool.h"

static
double
new_order_LM1(work_wait &parameters) {
  double actual_remaining = 
	3.5022 * parameters.work_so_far 
	- 0.1197 * parameters.wait_so_far 
	- 3607235.4869 * parameters.num_locks_so_far 
	+ 1017200.8604 * parameters.total_wait_locks 
	- 0.2485 * parameters.mean_wait_of_all 
	- 323764238.1049 * parameters.cpu_usage 
	+ 0.0039 * parameters.avg_work_of_same_past_second 
	- 0.0034 * parameters.avg_wait_of_same_past_second 
	+ 0.1121 * parameters.avg_latency_of_same_last_20 
	- 0.0228 * parameters.max_latency_of_same_last_50 
	+ 386059601.5382;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM2(work_wait &parameters) {
  double actual_remaining = 
	7134.1922 * parameters.work_so_far 
	- 0.0447 * parameters.wait_so_far 
	- 144355.8031 * parameters.num_locks_so_far 
	+ 1906819.412 * parameters.total_wait_locks 
	- 0.0864 * parameters.mean_wait_of_all 
	- 15920788.0085 * parameters.cpu_usage 
	+ 0.059 * parameters.avg_work_of_same_past_second 
	- 0.0992 * parameters.avg_wait_of_same_past_second 
	- 0.3334 * parameters.avg_latency_of_same_last_20 
	- 0.0035 * parameters.max_latency_of_same_last_50 
	- 187284308.021;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM3(work_wait &parameters) {
  double actual_remaining = 
	38.2225 * parameters.work_so_far 
	- 0.1418 * parameters.wait_so_far 
	- 144355.8031 * parameters.num_locks_so_far 
	+ 1139633.3623 * parameters.total_wait_locks 
	- 0.0458 * parameters.mean_wait_of_all 
	- 15920788.0085 * parameters.cpu_usage 
	+ 0.0282 * parameters.avg_work_of_same_past_second 
	- 0.3873 * parameters.avg_wait_of_same_past_second 
	+ 0.014 * parameters.avg_latency_of_same_last_20 
	- 0.0035 * parameters.max_latency_of_same_last_50 
	+ 84098879.4764;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM4(work_wait &parameters) {
  double actual_remaining = 
	4.1564 * parameters.work_so_far 
	+ 0.0941 * parameters.wait_so_far 
	- 3238514.7271 * parameters.num_locks_so_far 
	+ 2078702.8635 * parameters.total_wait_locks 
	- 0.6802 * parameters.mean_wait_of_all 
	- 507371741.9509 * parameters.cpu_usage 
	+ 0.0142 * parameters.avg_work_of_same_past_second 
	- 0.0185 * parameters.avg_wait_of_same_past_second 
	+ 0.1904 * parameters.avg_latency_of_same_last_20 
	- 0.0032 * parameters.max_latency_of_same_last_50 
	+ 437783665.4364;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM5(work_wait &parameters) {
  double actual_remaining = 
	1.0678 * parameters.work_so_far 
	+ 0.7645 * parameters.wait_so_far 
	- 3091142.3817 * parameters.num_locks_so_far 
	+ 1015756.1425 * parameters.total_wait_locks 
	- 0.0102 * parameters.mean_wait_of_all 
	- 131180014.2883 * parameters.cpu_usage 
	+ 0.0019 * parameters.avg_work_of_same_past_second 
	- 0.0021 * parameters.avg_wait_of_same_past_second 
	+ 0.2729 * parameters.avg_latency_of_same_last_20 
	- 0.1372 * parameters.max_latency_of_same_last_50 
	+ 348444166.5225;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM6(work_wait &parameters) {
  double actual_remaining = 
	2.663 * parameters.work_so_far 
	+ 0.1679 * parameters.wait_so_far 
	- 1894045.8041 * parameters.num_locks_so_far 
	+ 110222.1684 * parameters.total_wait_locks 
	+ 2.5955 * parameters.mean_wait_of_all 
	- 94544984.8918 * parameters.cpu_usage 
	+ 0.0019 * parameters.avg_work_of_same_past_second 
	- 0.0021 * parameters.avg_wait_of_same_past_second 
	+ 0.0187 * parameters.avg_latency_of_same_last_20 
	- 0.0075 * parameters.max_latency_of_same_last_50 
	+ 278016380.8881;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM7(work_wait &parameters) {
  double actual_remaining = 
	0.823 * parameters.work_so_far 
	+ 0.6669 * parameters.wait_so_far 
	+ 1916620.4465 * parameters.num_locks_so_far 
	+ 1537854.9786 * parameters.total_wait_locks 
	- 0.0102 * parameters.mean_wait_of_all 
	- 215250533.1963 * parameters.cpu_usage 
	+ 0.4114 * parameters.avg_work_of_same_past_second 
	- 0.682 * parameters.avg_wait_of_same_past_second 
	+ 0.1989 * parameters.avg_latency_of_same_last_20 
	- 0.0075 * parameters.max_latency_of_same_last_50 
	+ 151526767.978;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM8(work_wait &parameters) {
  double actual_remaining = 
	0.003 * parameters.work_so_far 
	- 0.2516 * parameters.wait_so_far 
	- 53181793.6773 * parameters.num_locks_so_far 
	- 234997.8468 * parameters.total_wait_locks 
	+ 2.1661 * parameters.mean_wait_of_all 
	+ 0.5905 * parameters.avg_work_of_same_past_second 
	- 0.4433 * parameters.avg_wait_of_same_past_second 
	+ 0.1315 * parameters.avg_latency_of_same_last_20 
	- 0.092 * parameters.max_latency_of_same_last_50 
	+ 489868932.5159;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM9(work_wait &parameters) {
  double actual_remaining = 
	63.8261 * parameters.work_so_far 
	- 0.1614 * parameters.wait_so_far 
	+ 125055817.0183 * parameters.num_locks_so_far 
	- 541324.5885 * parameters.total_wait_locks 
	+ 3.4385 * parameters.mean_wait_of_all 
	+ 0.3066 * parameters.avg_work_of_same_past_second 
	- 0.3283 * parameters.avg_wait_of_same_past_second 
	+ 0.2792 * parameters.avg_latency_of_same_last_20 
	- 0.0498 * parameters.max_latency_of_same_last_50 
	- 385545076.6669;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM10(work_wait &parameters) {
  double actual_remaining = 
	23.2578 * parameters.work_so_far 
	+ 0.3243 * parameters.wait_so_far 
	- 12314447.6318 * parameters.num_locks_so_far 
	- 8501.5475 * parameters.total_wait_locks 
	+ 0.7601 * parameters.mean_wait_of_all 
	- 3002843.067 * parameters.cpu_usage 
	+ 0.0217 * parameters.avg_work_of_same_past_second 
	- 0.0162 * parameters.avg_wait_of_same_past_second 
	+ 0.0022 * parameters.avg_latency_of_same_last_20 
	- 0.106 * parameters.max_latency_of_same_last_50 
	+ 406950959.4385;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM11(work_wait &parameters) {
  double actual_remaining = 
	0.6463 * parameters.work_so_far 
	+ 0.0408 * parameters.wait_so_far 
	- 2346664.2064 * parameters.num_locks_so_far 
	- 164086.5574 * parameters.total_wait_locks 
	+ 0.9517 * parameters.mean_wait_of_all 
	- 3002843.067 * parameters.cpu_usage 
	- 0.1333 * parameters.avg_work_of_same_past_second 
	- 2.4673 * parameters.avg_wait_of_same_past_second 
	+ 0.0451 * parameters.avg_latency_of_same_last_20 
	+ 0.1565 * parameters.max_latency_of_same_last_50 
	+ 1006600039.7833;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM12(work_wait &parameters) {
  double actual_remaining = 
	0.6463 * parameters.work_so_far 
	+ 0.0408 * parameters.wait_so_far 
	- 16699271.93 * parameters.num_locks_so_far 
	- 109703.8567 * parameters.total_wait_locks 
	+ 0.6475 * parameters.mean_wait_of_all 
	- 465613385.114 * parameters.cpu_usage 
	- 0.6509 * parameters.avg_work_of_same_past_second 
	- 0.0222 * parameters.avg_wait_of_same_past_second 
	+ 0.4085 * parameters.avg_latency_of_same_last_20 
	- 0.0155 * parameters.max_latency_of_same_last_50 
	+ 927050845.4826;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM13(work_wait &parameters) {
  double actual_remaining = 
	0.6463 * parameters.work_so_far 
	+ 0.8024 * parameters.wait_so_far 
	+ 32241270.0556 * parameters.num_locks_so_far 
	+ 373397.4248 * parameters.total_wait_locks 
	- 1.7148 * parameters.mean_wait_of_all 
	- 3002843.067 * parameters.cpu_usage 
	- 0.0921 * parameters.avg_work_of_same_past_second 
	- 0.0222 * parameters.avg_wait_of_same_past_second 
	+ 0.0321 * parameters.avg_latency_of_same_last_20 
	- 0.0165 * parameters.max_latency_of_same_last_50 
	+ 166038902.1846;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM14(work_wait &parameters) {
  double actual_remaining = 
	0.6463 * parameters.work_so_far 
	+ 0.5441 * parameters.wait_so_far 
	+ 35900346.6233 * parameters.num_locks_so_far 
	- 110629.5501 * parameters.total_wait_locks 
	+ 0.018 * parameters.mean_wait_of_all 
	- 3002843.067 * parameters.cpu_usage 
	- 0.0921 * parameters.avg_work_of_same_past_second 
	- 0.0222 * parameters.avg_wait_of_same_past_second 
	+ 0.0321 * parameters.avg_latency_of_same_last_20 
	- 0.0165 * parameters.max_latency_of_same_last_50 
	+ 197329709.6145;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM15(work_wait &parameters) {
  double actual_remaining = 
	0.6463 * parameters.work_so_far 
	+ 0.5441 * parameters.wait_so_far 
	+ 45754010.1729 * parameters.num_locks_so_far 
	- 110629.5501 * parameters.total_wait_locks 
	+ 0.1723 * parameters.mean_wait_of_all 
	- 3002843.067 * parameters.cpu_usage 
	- 0.0921 * parameters.avg_work_of_same_past_second 
	- 0.0222 * parameters.avg_wait_of_same_past_second 
	+ 0.0321 * parameters.avg_latency_of_same_last_20 
	- 0.0165 * parameters.max_latency_of_same_last_50 
	+ 87961107.522;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM16(work_wait &parameters) {
  double actual_remaining = 
	-54.7072 * parameters.work_so_far 
	+ 0.0872 * parameters.wait_so_far 
	+ 41877349.6422 * parameters.num_locks_so_far 
	- 653347.847 * parameters.total_wait_locks 
	+ 3.7093 * parameters.mean_wait_of_all 
	- 3002843.067 * parameters.cpu_usage 
	- 1.1478 * parameters.avg_work_of_same_past_second 
	- 0.0222 * parameters.avg_wait_of_same_past_second 
	+ 0.0321 * parameters.avg_latency_of_same_last_20 
	- 0.0165 * parameters.max_latency_of_same_last_50 
	+ 728238552.0199;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM17(work_wait &parameters) {
  double actual_remaining = 
	-22.6637 * parameters.work_so_far 
	+ 0.0872 * parameters.wait_so_far 
	+ 26094463.5778 * parameters.num_locks_so_far 
	- 388817.3429 * parameters.total_wait_locks 
	+ 3.7093 * parameters.mean_wait_of_all 
	- 3002843.067 * parameters.cpu_usage 
	+ 1.9653 * parameters.avg_work_of_same_past_second 
	- 0.0222 * parameters.avg_wait_of_same_past_second 
	+ 0.0321 * parameters.avg_latency_of_same_last_20 
	- 0.1484 * parameters.max_latency_of_same_last_50 
	+ 21116071.8382;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM18(work_wait &parameters) {
  double actual_remaining = 
	-22.6637 * parameters.work_so_far 
	+ 0.0872 * parameters.wait_so_far 
	+ 26094463.5778 * parameters.num_locks_so_far 
	- 377795.2386 * parameters.total_wait_locks 
	+ 3.7093 * parameters.mean_wait_of_all 
	- 3002843.067 * parameters.cpu_usage 
	+ 1.428 * parameters.avg_work_of_same_past_second 
	- 0.0222 * parameters.avg_wait_of_same_past_second 
	+ 0.0321 * parameters.avg_latency_of_same_last_20 
	- 0.1539 * parameters.max_latency_of_same_last_50 
	+ 97741564.251;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM19(work_wait &parameters) {
  double actual_remaining = 
	0.2103 * parameters.work_so_far 
	- 0.3553 * parameters.wait_so_far 
	+ 17184276.2872 * parameters.num_locks_so_far 
	+ 263705.342 * parameters.total_wait_locks 
	- 1.0145 * parameters.mean_wait_of_all 
	- 329804629.6287 * parameters.cpu_usage 
	+ 0.0178 * parameters.avg_work_of_same_past_second 
	- 0.0175 * parameters.avg_wait_of_same_past_second 
	+ 0.1611 * parameters.avg_latency_of_same_last_20 
	- 0.1007 * parameters.max_latency_of_same_last_50 
	+ 807561825.8017;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM20(work_wait &parameters) {
  double actual_remaining = 
	7.0562 * parameters.work_so_far 
	+ 0.9137 * parameters.wait_so_far 
	- 56987407.5855 * parameters.num_locks_so_far 
	+ 928910.9286 * parameters.total_wait_locks 
	- 3.6128 * parameters.mean_wait_of_all 
	- 3180117.6583 * parameters.cpu_usage 
	+ 0.024 * parameters.avg_work_of_same_past_second 
	- 0.0245 * parameters.avg_wait_of_same_past_second 
	+ 0.0071 * parameters.avg_latency_of_same_last_20 
	- 0.0041 * parameters.max_latency_of_same_last_50 
	+ 1030048450.7026;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM21(work_wait &parameters) {
  double actual_remaining = 
	6.8137 * parameters.work_so_far 
	+ 1.0569 * parameters.wait_so_far 
	- 9361622.5017 * parameters.num_locks_so_far 
	- 577559.565 * parameters.total_wait_locks 
	+ 3.156 * parameters.mean_wait_of_all 
	- 1627326.3532 * parameters.cpu_usage 
	+ 0.0064 * parameters.avg_work_of_same_past_second 
	- 0.1822 * parameters.avg_wait_of_same_past_second 
	+ 0.1112 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	+ 235270596.8281;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM22(work_wait &parameters) {
  double actual_remaining = 
	0.1597 * parameters.work_so_far 
	- 0.0474 * parameters.wait_so_far 
	+ 3153294.6326 * parameters.num_locks_so_far 
	+ 546938.6761 * parameters.total_wait_locks 
	- 2.6959 * parameters.mean_wait_of_all 
	+ 68068653.7071 * parameters.cpu_usage 
	+ 0.0863 * parameters.avg_work_of_same_past_second 
	+ 0.2532 * parameters.avg_wait_of_same_past_second 
	+ 0.0089 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 379023343.5316;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM23(work_wait &parameters) {
  double actual_remaining = 
	0.7211 * parameters.work_so_far 
	- 0.0714 * parameters.wait_so_far 
	+ 3153294.6326 * parameters.num_locks_so_far 
	+ 676747.377 * parameters.total_wait_locks 
	- 1.9474 * parameters.mean_wait_of_all 
	+ 68068653.7071 * parameters.cpu_usage 
	+ 0.0863 * parameters.avg_work_of_same_past_second 
	+ 0.3176 * parameters.avg_wait_of_same_past_second 
	+ 0.0089 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 222540191.353;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM24(work_wait &parameters) {
  double actual_remaining = 
	0.7997 * parameters.work_so_far 
	- 0.0714 * parameters.wait_so_far 
	+ 3153294.6326 * parameters.num_locks_so_far 
	+ 676747.377 * parameters.total_wait_locks 
	- 2.514 * parameters.mean_wait_of_all 
	+ 68068653.7071 * parameters.cpu_usage 
	+ 0.0863 * parameters.avg_work_of_same_past_second 
	+ 0.3176 * parameters.avg_wait_of_same_past_second 
	+ 0.0089 * parameters.avg_latency_of_same_last_20 
	- 0.0817 * parameters.max_latency_of_same_last_50 
	+ 500652452.7188;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM25(work_wait &parameters) {
  double actual_remaining = 
	0.9558 * parameters.work_so_far 
	- 0.0714 * parameters.wait_so_far 
	+ 3153294.6326 * parameters.num_locks_so_far 
	+ 676747.377 * parameters.total_wait_locks 
	- 2.514 * parameters.mean_wait_of_all 
	+ 68068653.7071 * parameters.cpu_usage 
	+ 0.0863 * parameters.avg_work_of_same_past_second 
	+ 0.3176 * parameters.avg_wait_of_same_past_second 
	+ 0.0089 * parameters.avg_latency_of_same_last_20 
	- 0.0479 * parameters.max_latency_of_same_last_50 
	+ 392032837.0239;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM26(work_wait &parameters) {
  double actual_remaining = 
	0.1803 * parameters.work_so_far 
	+ 0.1291 * parameters.wait_so_far 
	+ 1392170.3879 * parameters.num_locks_so_far 
	+ 230399.1343 * parameters.total_wait_locks 
	+ 0.3611 * parameters.mean_wait_of_all 
	+ 35348425.4404 * parameters.cpu_usage 
	+ 0.1162 * parameters.avg_work_of_same_past_second 
	- 0.7335 * parameters.avg_wait_of_same_past_second 
	+ 0.0089 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 640684130.0084;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM27(work_wait &parameters) {
  double actual_remaining = 
	2.2587 * parameters.work_so_far 
	+ 0.2482 * parameters.wait_so_far 
	+ 1392170.3879 * parameters.num_locks_so_far 
	- 143999.8746 * parameters.total_wait_locks 
	+ 0.8644 * parameters.mean_wait_of_all 
	+ 35348425.4404 * parameters.cpu_usage 
	+ 1.748 * parameters.avg_work_of_same_past_second 
	- 2.0532 * parameters.avg_wait_of_same_past_second 
	+ 0.0089 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 548578740.5281;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM28(work_wait &parameters) {
  double actual_remaining = 
	0.7354 * parameters.work_so_far 
	+ 0.7608 * parameters.wait_so_far 
	- 4932414.0062 * parameters.num_locks_so_far 
	- 14487.1213 * parameters.total_wait_locks 
	+ 0.768 * parameters.mean_wait_of_all 
	- 928349.3771 * parameters.cpu_usage 
	+ 0.0044 * parameters.avg_work_of_same_past_second 
	- 0.0044 * parameters.avg_wait_of_same_past_second 
	+ 0.1252 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 351527030.3929;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM29(work_wait &parameters) {
  double actual_remaining = 
	0.7452 * parameters.work_so_far 
	+ 0.6677 * parameters.wait_so_far 
	- 338029.016 * parameters.num_locks_so_far 
	- 1710962.2632 * parameters.total_wait_locks 
	+ 8.6345 * parameters.mean_wait_of_all 
	- 928349.3771 * parameters.cpu_usage 
	+ 0.0044 * parameters.avg_work_of_same_past_second 
	- 0.0044 * parameters.avg_wait_of_same_past_second 
	+ 0.1841 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 158774493.512;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM30(work_wait &parameters) {
  double actual_remaining = 
	0.0482 * parameters.work_so_far 
	- 0.1191 * parameters.wait_so_far 
	+ 290091.9435 * parameters.num_locks_so_far 
	- 15097.1354 * parameters.total_wait_locks 
	+ 0.1014 * parameters.mean_wait_of_all 
	+ 0.0038 * parameters.avg_work_of_same_past_second 
	+ 0.4771 * parameters.avg_wait_of_same_past_second 
	+ 0.36 * parameters.avg_latency_of_same_last_20 
	- 0.165 * parameters.max_latency_of_same_last_50 
	+ 293983964.313;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM31(work_wait &parameters) {
  double actual_remaining = 
	3.2388 * parameters.work_so_far 
	+ 0.3393 * parameters.wait_so_far 
	+ 36107177.3221 * parameters.num_locks_so_far 
	- 2420718.779 * parameters.total_wait_locks 
	+ 12.7104 * parameters.mean_wait_of_all 
	+ 0.0299 * parameters.avg_work_of_same_past_second 
	- 0.0032 * parameters.avg_wait_of_same_past_second 
	+ 0.0262 * parameters.avg_latency_of_same_last_20 
	- 0.007 * parameters.max_latency_of_same_last_50 
	+ 58620526.2186;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM32(work_wait &parameters) {
  double actual_remaining = 
	1.106 * parameters.work_so_far 
	+ 0.8467 * parameters.wait_so_far 
	+ 1857427.1505 * parameters.num_locks_so_far 
	- 759474.6309 * parameters.total_wait_locks 
	+ 3.2973 * parameters.mean_wait_of_all 
	+ 0.4027 * parameters.avg_work_of_same_past_second 
	- 0.0032 * parameters.avg_wait_of_same_past_second 
	+ 0.3638 * parameters.avg_latency_of_same_last_20 
	- 0.0713 * parameters.max_latency_of_same_last_50 
	- 28428493.8866;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM33(work_wait &parameters) {
  double actual_remaining = 
	1.5827 * parameters.work_so_far 
	+ 0.9171 * parameters.wait_so_far 
	- 3809319.58 * parameters.num_locks_so_far 
	- 619570.2158 * parameters.total_wait_locks 
	+ 3.9289 * parameters.mean_wait_of_all 
	+ 433465652.1564 * parameters.cpu_usage 
	+ 0.0184 * parameters.avg_work_of_same_past_second 
	- 0.0032 * parameters.avg_wait_of_same_past_second 
	+ 0.0187 * parameters.avg_latency_of_same_last_20 
	- 0.0048 * parameters.max_latency_of_same_last_50 
	- 237525714.6439;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
new_order_estimate(work_wait &parameters){

  if (parameters.total_wait_locks <= 160.5) {

    if (parameters.work_so_far <= 53750900.5) {

      if (parameters.total_wait_locks <= 87.5) {
        return new_order_LM1(parameters);
      } else {

        if (parameters.work_so_far <= 91127) {

          if (parameters.wait_so_far <= 10204203) {
            return new_order_LM2(parameters);
          } else {
            return new_order_LM3(parameters);
          }
        } else {
          return new_order_LM4(parameters);
        }
      }
    } else {

      if (parameters.total_wait_locks <= 106.5) {
        return new_order_LM5(parameters);
      } else {

        if (parameters.num_locks_so_far <= 20.5) {
          return new_order_LM6(parameters);
        } else {
          return new_order_LM7(parameters);
        }
      }
    }
  } else {

    if (parameters.work_so_far <= 1223146) {

      if (parameters.wait_so_far <= 246262715) {
        return new_order_LM8(parameters);
      } else {
        return new_order_LM9(parameters);
      }
    } else {

      if (parameters.wait_so_far <= 329562141) {

        if (parameters.work_so_far <= 46143188) {

          if (parameters.num_locks_so_far <= 14.5) {

            if (parameters.work_so_far <= 6250836.5) {

              if (parameters.avg_work_of_same_past_second <= 283619500) {
                return new_order_LM10(parameters);
              } else {

                if (parameters.wait_so_far <= 182400805) {

                  if (parameters.max_latency_of_same_last_50 <= 1260270000) {
                    return new_order_LM11(parameters);
                  } else {
                    return new_order_LM12(parameters);
                  }
                } else {

                  if (parameters.cpu_usage <= 0.847) {

                    if (parameters.cpu_usage <= 0.795) {
                      return new_order_LM13(parameters);
                    } else {

                      if (parameters.total_wait_locks <= 375) {
                        return new_order_LM14(parameters);
                      } else {
                        return new_order_LM15(parameters);
                      }
                    }
                  } else {

                    if (parameters.max_latency_of_same_last_50 <= 1432545000) {
                      return new_order_LM16(parameters);
                    } else {

                      if (parameters.max_latency_of_same_last_50 <= 1696240000) {
                        return new_order_LM17(parameters);
                      } else {
                        return new_order_LM18(parameters);
                      }
                    }
                  }
                }
              }
            } else {

              if (parameters.num_locks_so_far <= 9.5) {
                return new_order_LM19(parameters);
              } else {
                return new_order_LM20(parameters);
              }
            }
          } else {
            return new_order_LM21(parameters);
          }
        } else {

          if (parameters.work_so_far <= 331748795.5) {

            if (parameters.num_locks_so_far <= 11.5) {

              if (parameters.num_locks_so_far <= 4.5) {

                if (parameters.avg_wait_of_same_past_second <= 250118500) {
                  return new_order_LM22(parameters);
                } else {

                  if (parameters.avg_work_of_same_past_second <= 240975500) {
                    return new_order_LM23(parameters);
                  } else {

                    if (parameters.max_latency_of_same_last_50 <= 1029030000) {
                      return new_order_LM24(parameters);
                    } else {
                      return new_order_LM25(parameters);
                    }
                  }
                }
              } else {

                if (parameters.wait_so_far <= 65705786.5) {
                  return new_order_LM26(parameters);
                } else {
                  return new_order_LM27(parameters);
                }
              }
            } else {
              return new_order_LM28(parameters);
            }
          } else {
            return new_order_LM29(parameters);
          }
        }
      } else {

        if (parameters.num_locks_so_far <= 5.5) {
          return new_order_LM30(parameters);
        } else {

          if (parameters.wait_so_far <= 700470515.5) {

            if (parameters.num_locks_so_far <= 11.5) {
              return new_order_LM31(parameters);
            } else {
              return new_order_LM32(parameters);
            }
          } else {
            return new_order_LM33(parameters);
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
	9.0272 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 7494.6801 * parameters.total_wait_locks 
	- 0.0008 * parameters.mean_wait_of_all 
	- 964691.6012 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 5910418.1531;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM2(work_wait &parameters) {
  double actual_remaining = 
	9.0272 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 7494.6801 * parameters.total_wait_locks 
	- 0.0008 * parameters.mean_wait_of_all 
	- 964691.6012 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 6757763.0131;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM3(work_wait &parameters) {
  double actual_remaining = 
	9.0272 * parameters.work_so_far 
	- 0.0222 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 7494.6801 * parameters.total_wait_locks 
	- 0.0008 * parameters.mean_wait_of_all 
	- 26247710.1198 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	+ 0.0139 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 30769260.4459;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM4(work_wait &parameters) {
  double actual_remaining = 
	-13574.0381 * parameters.work_so_far 
	- 0.1229 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 7494.6801 * parameters.total_wait_locks 
	- 0.0008 * parameters.mean_wait_of_all 
	- 1412493689.969 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	+ 0.0048 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 1386327827.0384;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM5(work_wait &parameters) {
  double actual_remaining = 
	-13574.0381 * parameters.work_so_far 
	- 0.1165 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 7494.6801 * parameters.total_wait_locks 
	- 0.0008 * parameters.mean_wait_of_all 
	- 1412493689.969 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	+ 0.0048 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 1385659448.5264;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM6(work_wait &parameters) {
  double actual_remaining = 
	-13298.695 * parameters.work_so_far 
	- 0.0076 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 7494.6801 * parameters.total_wait_locks 
	- 0.0008 * parameters.mean_wait_of_all 
	- 1412493689.969 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	+ 0.0048 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 1378461051.4522;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM7(work_wait &parameters) {
  double actual_remaining = 
	-7502.9129 * parameters.work_so_far 
	- 0.0076 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 7494.6801 * parameters.total_wait_locks 
	- 0.0008 * parameters.mean_wait_of_all 
	- 1361902849.1747 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	+ 0.0048 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 1285352210.1047;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM8(work_wait &parameters) {
  double actual_remaining = 
	9.0272 * parameters.work_so_far 
	- 0.0076 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 7494.6801 * parameters.total_wait_locks 
	- 0.0008 * parameters.mean_wait_of_all 
	- 25163314.8445 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	+ 0.0048 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 31529121.608;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM9(work_wait &parameters) {
  double actual_remaining = 
	152.9404 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 9030.2693 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 22005700.3231 * parameters.cpu_usage 
	+ 2.2177 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.0055 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 17583017.035;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM10(work_wait &parameters) {
  double actual_remaining = 
	122.4693 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 406949.1436 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	+ 134960848.6863 * parameters.cpu_usage 
	+ 1.74 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.0055 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 104281969.506;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM11(work_wait &parameters) {
  double actual_remaining = 
	122.4693 * parameters.work_so_far 
	- 0.0649 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 9030.2693 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	+ 439881680.3436 * parameters.cpu_usage 
	+ 1.74 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.0055 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 337971356.2926;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM12(work_wait &parameters) {
  double actual_remaining = 
	122.4693 * parameters.work_so_far 
	- 0.0649 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 9030.2693 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	+ 449011938.2011 * parameters.cpu_usage 
	+ 1.74 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.0055 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 345076476.6189;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM13(work_wait &parameters) {
  double actual_remaining = 
	122.4693 * parameters.work_so_far 
	- 0.0619 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 9030.2693 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	+ 400171074.1427 * parameters.cpu_usage 
	+ 1.74 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.0055 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 308121138.0733;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM14(work_wait &parameters) {
  double actual_remaining = 
	122.4693 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 9030.2693 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 78663071.5645 * parameters.cpu_usage 
	+ 1.74 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.0055 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 75253399.5819;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM15(work_wait &parameters) {
  double actual_remaining = 
	11.4673 * parameters.work_so_far 
	+ 0.0227 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 9030.2693 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 17068357.963 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.0048 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 26965987.4074;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM16(work_wait &parameters) {
  double actual_remaining = 
	7804.0499 * parameters.work_so_far 
	+ 0.0146 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 9030.2693 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 13161406.5154 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	+ 0.2917 * parameters.avg_wait_of_same_past_second 
	- 0.0048 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 50799206.2143;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM17(work_wait &parameters) {
  double actual_remaining = 
	12376.5516 * parameters.work_so_far 
	+ 0.0146 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 9030.2693 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 13161406.5154 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	+ 0.2334 * parameters.avg_wait_of_same_past_second 
	- 0.0048 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 86965784.5455;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM18(work_wait &parameters) {
  double actual_remaining = 
	10725.8929 * parameters.work_so_far 
	+ 0.0146 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 9030.2693 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 13161406.5154 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	+ 0.2334 * parameters.avg_wait_of_same_past_second 
	- 0.0048 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 70550197.1252;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM19(work_wait &parameters) {
  double actual_remaining = 
	10725.8929 * parameters.work_so_far 
	+ 0.0146 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 9030.2693 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 13161406.5154 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	+ 0.2334 * parameters.avg_wait_of_same_past_second 
	- 0.0048 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 70866677.9982;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM20(work_wait &parameters) {
  double actual_remaining = 
	10725.8929 * parameters.work_so_far 
	+ 0.0146 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 9030.2693 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 13161406.5154 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	+ 0.2334 * parameters.avg_wait_of_same_past_second 
	- 0.0048 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 69413102.3902;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM21(work_wait &parameters) {
  double actual_remaining = 
	11.4673 * parameters.work_so_far 
	+ 0.0146 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 9030.2693 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 13161406.5154 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.0048 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 26882906.8466;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM22(work_wait &parameters) {
  double actual_remaining = 
	11.4673 * parameters.work_so_far 
	+ 0.0149 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 191648.3721 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 14969732.0442 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.0048 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 20454966.337;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM23(work_wait &parameters) {
  double actual_remaining = 
	387.2815 * parameters.work_so_far 
	- 0.0133 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 9030.2693 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 5615874.1917 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.0054 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 11047170.6652;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM24(work_wait &parameters) {
  double actual_remaining = 
	-3.4921 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 133584.4054 * parameters.total_wait_locks 
	+ 3.5875 * parameters.mean_wait_of_all 
	- 77703105.3081 * parameters.cpu_usage 
	+ 0.0093 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 20797026.1739;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM25(work_wait &parameters) {
  double actual_remaining = 
	-17.6252 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 5600.9803 * parameters.total_wait_locks 
	- 0.9062 * parameters.mean_wait_of_all 
	- 1902179.388 * parameters.cpu_usage 
	+ 0.0171 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 48310474.3443;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM26(work_wait &parameters) {
  double actual_remaining = 
	-27.1993 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 103663.7792 * parameters.total_wait_locks 
	+ 426.9086 * parameters.mean_wait_of_all 
	- 1902179.388 * parameters.cpu_usage 
	+ 0.0171 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 11937265905.379;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM27(work_wait &parameters) {
  double actual_remaining = 
	-27.1993 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 103663.7792 * parameters.total_wait_locks 
	+ 621.2797 * parameters.mean_wait_of_all 
	- 1902179.388 * parameters.cpu_usage 
	+ 0.0171 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 17399154807.1706;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM28(work_wait &parameters) {
  double actual_remaining = 
	-27.1993 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 103663.7792 * parameters.total_wait_locks 
	+ 612.0239 * parameters.mean_wait_of_all 
	- 1902179.388 * parameters.cpu_usage 
	+ 0.0171 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 17137599877.1238;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM29(work_wait &parameters) {
  double actual_remaining = 
	-27.1993 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 22926.8309 * parameters.total_wait_locks 
	+ 442.837 * parameters.mean_wait_of_all 
	- 1902179.388 * parameters.cpu_usage 
	+ 0.0171 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 12400504971.1066;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM30(work_wait &parameters) {
  double actual_remaining = 
	-78.0108 * parameters.work_so_far 
	- 0.0154 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 5600.9803 * parameters.total_wait_locks 
	- 46.7145 * parameters.mean_wait_of_all 
	- 1902179.388 * parameters.cpu_usage 
	+ 0.0171 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 1342255920.57;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM31(work_wait &parameters) {
  double actual_remaining = 
	-27.1993 * parameters.work_so_far 
	- 0.01 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 5600.9803 * parameters.total_wait_locks 
	- 46.7145 * parameters.mean_wait_of_all 
	- 1902179.388 * parameters.cpu_usage 
	+ 0.0171 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 1338500972.8204;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM32(work_wait &parameters) {
  double actual_remaining = 
	688.8443 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 163455.2456 * parameters.total_wait_locks 
	+ 4.9524 * parameters.mean_wait_of_all 
	- 1016074.9153 * parameters.cpu_usage 
	- 1.4556 * parameters.avg_work_of_same_past_second 
	+ 0.1492 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 113631165.3816;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM33(work_wait &parameters) {
  double actual_remaining = 
	-212.6669 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 1071781.5093 * parameters.total_wait_locks 
	+ 5.6116 * parameters.mean_wait_of_all 
	- 1016074.9153 * parameters.cpu_usage 
	- 0.6794 * parameters.avg_work_of_same_past_second 
	- 0.1575 * parameters.avg_wait_of_same_past_second 
	- 0.0227 * parameters.avg_latency_of_same_last_20 
	+ 0.0212 * parameters.max_latency_of_same_last_50 
	- 159654964.5112;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM34(work_wait &parameters) {
  double actual_remaining = 
	-677.5542 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 3402923.1902 * parameters.total_wait_locks 
	+ 5.6116 * parameters.mean_wait_of_all 
	- 1016074.9153 * parameters.cpu_usage 
	- 0.6794 * parameters.avg_work_of_same_past_second 
	+ 0.0642 * parameters.avg_wait_of_same_past_second 
	- 0.0227 * parameters.avg_latency_of_same_last_20 
	+ 0.0212 * parameters.max_latency_of_same_last_50 
	+ 121315.892;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM35(work_wait &parameters) {
  double actual_remaining = 
	-677.5542 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 1525641.3461 * parameters.total_wait_locks 
	+ 5.6116 * parameters.mean_wait_of_all 
	- 1016074.9153 * parameters.cpu_usage 
	- 0.6794 * parameters.avg_work_of_same_past_second 
	+ 0.0642 * parameters.avg_wait_of_same_past_second 
	- 0.0227 * parameters.avg_latency_of_same_last_20 
	+ 0.0212 * parameters.max_latency_of_same_last_50 
	- 62809831.0372;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM36(work_wait &parameters) {
  double actual_remaining = 
	-677.5542 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 12139.0306 * parameters.total_wait_locks 
	+ 7.8682 * parameters.mean_wait_of_all 
	+ 167332661.4329 * parameters.cpu_usage 
	- 0.6794 * parameters.avg_work_of_same_past_second 
	+ 0.0642 * parameters.avg_wait_of_same_past_second 
	- 0.0227 * parameters.avg_latency_of_same_last_20 
	+ 0.0212 * parameters.max_latency_of_same_last_50 
	- 314794856.0252;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM37(work_wait &parameters) {
  double actual_remaining = 
	-927.8781 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 12139.0306 * parameters.total_wait_locks 
	+ 5.6116 * parameters.mean_wait_of_all 
	- 1016074.9153 * parameters.cpu_usage 
	- 0.6794 * parameters.avg_work_of_same_past_second 
	+ 0.0642 * parameters.avg_wait_of_same_past_second 
	- 0.0227 * parameters.avg_latency_of_same_last_20 
	+ 0.0212 * parameters.max_latency_of_same_last_50 
	- 111584383.3231;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM38(work_wait &parameters) {
  double actual_remaining = 
	-534.9233 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 12139.0306 * parameters.total_wait_locks 
	+ 4.7383 * parameters.mean_wait_of_all 
	- 1016074.9153 * parameters.cpu_usage 
	- 6.9328 * parameters.avg_work_of_same_past_second 
	+ 0.0642 * parameters.avg_wait_of_same_past_second 
	- 0.0169 * parameters.avg_latency_of_same_last_20 
	+ 0.0926 * parameters.max_latency_of_same_last_50 
	- 77251474.0562;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM39(work_wait &parameters) {
  double actual_remaining = 
	873.7606 * parameters.work_so_far 
	+ 0.0525 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 13895.3497 * parameters.total_wait_locks 
	+ 0.0446 * parameters.mean_wait_of_all 
	- 1016074.9153 * parameters.cpu_usage 
	- 0.1707 * parameters.avg_work_of_same_past_second 
	+ 0.14 * parameters.avg_wait_of_same_past_second 
	- 0.0037 * parameters.avg_latency_of_same_last_20 
	- 0.0166 * parameters.max_latency_of_same_last_50 
	+ 10373914.1886;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM40(work_wait &parameters) {
  double actual_remaining = 
	55.7915 * parameters.work_so_far 
	+ 0.0016 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 69576.0609 * parameters.total_wait_locks 
	+ 0.0446 * parameters.mean_wait_of_all 
	- 1016074.9153 * parameters.cpu_usage 
	- 0.1372 * parameters.avg_work_of_same_past_second 
	+ 0.0037 * parameters.avg_wait_of_same_past_second 
	- 0.0026 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 9812899.0648;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM41(work_wait &parameters) {
  double actual_remaining = 
	-151.538 * parameters.work_so_far 
	- 0.0226 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 18379.4851 * parameters.total_wait_locks 
	+ 0.0446 * parameters.mean_wait_of_all 
	- 1016074.9153 * parameters.cpu_usage 
	- 0.0683 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 37712913.3048;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM42(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 61748.0744 * parameters.total_wait_locks 
	- 0.0035 * parameters.mean_wait_of_all 
	- 49935.1999 * parameters.cpu_usage 
	- 0.0013 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 11534478.135;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM43(work_wait &parameters) {
  double actual_remaining = 
	0.3858 * parameters.work_so_far 
	- 0.0118 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 11.2822 * parameters.total_wait_locks 
	+ 0.0004 * parameters.mean_wait_of_all 
	+ 127355.042 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0276 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 34183385.5404;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM44(work_wait &parameters) {
  double actual_remaining = 
	0.72 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 47112.3392 * parameters.total_wait_locks 
	- 0.1169 * parameters.mean_wait_of_all 
	+ 1928867.5171 * parameters.cpu_usage 
	+ 0.1935 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 9344029.3109;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM45(work_wait &parameters) {
  double actual_remaining = 
	0.72 * parameters.work_so_far 
	- 0.0009 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 149631.2681 * parameters.total_wait_locks 
	+ 0.8541 * parameters.mean_wait_of_all 
	+ 1618648.5639 * parameters.cpu_usage 
	+ 0.6553 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.001 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 5160721.0714;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM46(work_wait &parameters) {
  double actual_remaining = 
	0.72 * parameters.work_so_far 
	- 0.0252 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 186627.2296 * parameters.total_wait_locks 
	+ 1.1768 * parameters.mean_wait_of_all 
	+ 1618648.5639 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.001 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 6477123.6897;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM47(work_wait &parameters) {
  double actual_remaining = 
	0.72 * parameters.work_so_far 
	- 0.0226 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 167447.5675 * parameters.total_wait_locks 
	+ 0.8719 * parameters.mean_wait_of_all 
	+ 1618648.5639 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.1436 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 101020798.9867;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM48(work_wait &parameters) {
  double actual_remaining = 
	0.72 * parameters.work_so_far 
	- 0.0334 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 167447.5675 * parameters.total_wait_locks 
	+ 0.8719 * parameters.mean_wait_of_all 
	+ 1618648.5639 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.3259 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 190317944.7807;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM49(work_wait &parameters) {
  double actual_remaining = 
	0.72 * parameters.work_so_far 
	- 0.0334 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 167447.5675 * parameters.total_wait_locks 
	+ 0.8719 * parameters.mean_wait_of_all 
	+ 1618648.5639 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.3259 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 189399217.7165;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM50(work_wait &parameters) {
  double actual_remaining = 
	0.72 * parameters.work_so_far 
	- 0.0226 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 167447.5675 * parameters.total_wait_locks 
	+ 0.8719 * parameters.mean_wait_of_all 
	+ 1618648.5639 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.301 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 171188181.6283;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM51(work_wait &parameters) {
  double actual_remaining = 
	0.72 * parameters.work_so_far 
	- 0.028 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 167447.5675 * parameters.total_wait_locks 
	+ 0.8719 * parameters.mean_wait_of_all 
	+ 53103563.884 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.1586 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 49112884.1505;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM52(work_wait &parameters) {
  double actual_remaining = 
	0.72 * parameters.work_so_far 
	- 0.0285 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 167447.5675 * parameters.total_wait_locks 
	+ 0.8719 * parameters.mean_wait_of_all 
	+ 40747184.2072 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.1586 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 62345079.7369;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM53(work_wait &parameters) {
  double actual_remaining = 
	0.72 * parameters.work_so_far 
	- 0.0287 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 167447.5675 * parameters.total_wait_locks 
	+ 0.8719 * parameters.mean_wait_of_all 
	+ 40747184.2072 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.1586 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 62087783.9143;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM54(work_wait &parameters) {
  double actual_remaining = 
	-81.5738 * parameters.work_so_far 
	- 0.0027 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 31292.182 * parameters.total_wait_locks 
	- 0.0449 * parameters.mean_wait_of_all 
	+ 1618648.5639 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	+ 0.2416 * parameters.avg_wait_of_same_past_second 
	+ 0.0513 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 72592190.0687;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM55(work_wait &parameters) {
  double actual_remaining = 
	-81.5738 * parameters.work_so_far 
	- 0.0027 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 31292.182 * parameters.total_wait_locks 
	- 0.0449 * parameters.mean_wait_of_all 
	+ 1618648.5639 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	+ 0.2416 * parameters.avg_wait_of_same_past_second 
	+ 0.0513 * parameters.avg_latency_of_same_last_20 
	- 0.0115 * parameters.max_latency_of_same_last_50 
	- 57496873.2644;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM56(work_wait &parameters) {
  double actual_remaining = 
	-81.5738 * parameters.work_so_far 
	- 0.0027 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 31292.182 * parameters.total_wait_locks 
	- 0.0449 * parameters.mean_wait_of_all 
	+ 1618648.5639 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	+ 0.2416 * parameters.avg_wait_of_same_past_second 
	+ 0.0513 * parameters.avg_latency_of_same_last_20 
	- 0.0093 * parameters.max_latency_of_same_last_50 
	- 60874094.107;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM57(work_wait &parameters) {
  double actual_remaining = 
	-174.314 * parameters.work_so_far 
	+ 0.0623 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 31292.182 * parameters.total_wait_locks 
	- 0.0449 * parameters.mean_wait_of_all 
	+ 1618648.5639 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	+ 0.1757 * parameters.avg_wait_of_same_past_second 
	+ 0.0429 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 34798003.7029;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM58(work_wait &parameters) {
  double actual_remaining = 
	-120.6408 * parameters.work_so_far 
	+ 0.0419 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 31292.182 * parameters.total_wait_locks 
	- 0.0449 * parameters.mean_wait_of_all 
	+ 1618648.5639 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	+ 0.1757 * parameters.avg_wait_of_same_past_second 
	+ 0.0429 * parameters.avg_latency_of_same_last_20 
	- 0.0175 * parameters.max_latency_of_same_last_50 
	- 11076933.8605;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM59(work_wait &parameters) {
  double actual_remaining = 
	-120.6408 * parameters.work_so_far 
	+ 0.0419 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 31292.182 * parameters.total_wait_locks 
	- 0.0449 * parameters.mean_wait_of_all 
	+ 1618648.5639 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	+ 0.1757 * parameters.avg_wait_of_same_past_second 
	+ 0.0429 * parameters.avg_latency_of_same_last_20 
	- 0.0175 * parameters.max_latency_of_same_last_50 
	- 13057136.1484;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM60(work_wait &parameters) {
  double actual_remaining = 
	-120.6408 * parameters.work_so_far 
	+ 0.0419 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 31292.182 * parameters.total_wait_locks 
	- 0.0449 * parameters.mean_wait_of_all 
	+ 1618648.5639 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	+ 0.1757 * parameters.avg_wait_of_same_past_second 
	+ 0.0429 * parameters.avg_latency_of_same_last_20 
	- 0.0175 * parameters.max_latency_of_same_last_50 
	- 13251368.1547;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM61(work_wait &parameters) {
  double actual_remaining = 
	-120.6408 * parameters.work_so_far 
	+ 0.0419 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 31292.182 * parameters.total_wait_locks 
	- 0.0449 * parameters.mean_wait_of_all 
	+ 1618648.5639 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	+ 0.1757 * parameters.avg_wait_of_same_past_second 
	+ 0.0429 * parameters.avg_latency_of_same_last_20 
	- 0.0175 * parameters.max_latency_of_same_last_50 
	- 12515840.8656;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM62(work_wait &parameters) {
  double actual_remaining = 
	-120.6408 * parameters.work_so_far 
	+ 0.0419 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 31292.182 * parameters.total_wait_locks 
	- 0.0449 * parameters.mean_wait_of_all 
	+ 1618648.5639 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	+ 0.1757 * parameters.avg_wait_of_same_past_second 
	+ 0.0429 * parameters.avg_latency_of_same_last_20 
	- 0.0262 * parameters.max_latency_of_same_last_50 
	- 6771769.8696;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM63(work_wait &parameters) {
  double actual_remaining = 
	-15.6014 * parameters.work_so_far 
	- 0.0027 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 31292.182 * parameters.total_wait_locks 
	- 0.0449 * parameters.mean_wait_of_all 
	+ 1618648.5639 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0454 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 259632.1718;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM64(work_wait &parameters) {
  double actual_remaining = 
	151.5493 * parameters.work_so_far 
	- 0.0037 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 66118.116 * parameters.total_wait_locks 
	- 0.1208 * parameters.mean_wait_of_all 
	+ 1618648.5639 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0089 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 8089771.9031;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM65(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	- 0.0179 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 69662.3334 * parameters.total_wait_locks 
	+ 0.2515 * parameters.mean_wait_of_all 
	+ 494401.8846 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0045 * parameters.avg_wait_of_same_past_second 
	+ 0.1031 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 21893543.6631;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM66(work_wait &parameters) {
  double actual_remaining = 
	-119.316 * parameters.work_so_far 
	+ 0.1623 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 155744.8656 * parameters.total_wait_locks 
	+ 0.5685 * parameters.mean_wait_of_all 
	+ 494401.8846 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0045 * parameters.avg_wait_of_same_past_second 
	+ 0.0227 * parameters.avg_latency_of_same_last_20 
	+ 0.0028 * parameters.max_latency_of_same_last_50 
	+ 26380042.4582;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM67(work_wait &parameters) {
  double actual_remaining = 
	-79.5437 * parameters.work_so_far 
	+ 0.1082 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 155744.8656 * parameters.total_wait_locks 
	+ 0.5685 * parameters.mean_wait_of_all 
	+ 494401.8846 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0045 * parameters.avg_wait_of_same_past_second 
	+ 0.0227 * parameters.avg_latency_of_same_last_20 
	+ 0.0019 * parameters.max_latency_of_same_last_50 
	+ 28420011.9323;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM68(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	- 0.0236 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 155744.8656 * parameters.total_wait_locks 
	+ 0.5685 * parameters.mean_wait_of_all 
	+ 494401.8846 * parameters.cpu_usage 
	+ 8.2097 * parameters.avg_work_of_same_past_second 
	- 0.0045 * parameters.avg_wait_of_same_past_second 
	+ 0.0227 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 98657369.1264;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM69(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	- 0.0208 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 155744.8656 * parameters.total_wait_locks 
	+ 0.5685 * parameters.mean_wait_of_all 
	+ 494401.8846 * parameters.cpu_usage 
	+ 9.3414 * parameters.avg_work_of_same_past_second 
	- 0.0045 * parameters.avg_wait_of_same_past_second 
	+ 0.0227 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 128752396.911;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM70(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 155744.8656 * parameters.total_wait_locks 
	+ 0.5685 * parameters.mean_wait_of_all 
	+ 494401.8846 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0045 * parameters.avg_wait_of_same_past_second 
	+ 0.0227 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 58721883.011;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM71(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 155744.8656 * parameters.total_wait_locks 
	+ 0.5685 * parameters.mean_wait_of_all 
	+ 494401.8846 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	+ 0.0119 * parameters.avg_wait_of_same_past_second 
	+ 0.0227 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 40300214.7372;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM72(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 155744.8656 * parameters.total_wait_locks 
	+ 0.5685 * parameters.mean_wait_of_all 
	+ 494401.8846 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_work_of_same_past_second 
	+ 0.0128 * parameters.avg_wait_of_same_past_second 
	+ 0.0227 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 40368431.3312;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM73(work_wait &parameters) {
  double actual_remaining = 
	-29.5873 * parameters.work_so_far 
	- 0.003 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 107815.1196 * parameters.total_wait_locks 
	- 0.2023 * parameters.mean_wait_of_all 
	+ 494401.8846 * parameters.cpu_usage 
	+ 0.6087 * parameters.avg_work_of_same_past_second 
	- 0.0161 * parameters.avg_wait_of_same_past_second 
	+ 0.0108 * parameters.avg_latency_of_same_last_20 
	+ 0.0021 * parameters.max_latency_of_same_last_50 
	- 9531432.8119;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM74(work_wait &parameters) {
  double actual_remaining = 
	-182.5346 * parameters.work_so_far 
	- 0.0045 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 800180.974 * parameters.total_wait_locks 
	- 1.9416 * parameters.mean_wait_of_all 
	+ 494401.8846 * parameters.cpu_usage 
	+ 0.6692 * parameters.avg_work_of_same_past_second 
	- 0.1247 * parameters.avg_wait_of_same_past_second 
	+ 0.0149 * parameters.avg_latency_of_same_last_20 
	+ 0.0035 * parameters.max_latency_of_same_last_50 
	- 12116711.8284;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM75(work_wait &parameters) {
  double actual_remaining = 
	-128.3234 * parameters.work_so_far 
	- 0.0045 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 551428.6322 * parameters.total_wait_locks 
	- 1.301 * parameters.mean_wait_of_all 
	- 147612080.235 * parameters.cpu_usage 
	+ 1.7277 * parameters.avg_work_of_same_past_second 
	- 0.0836 * parameters.avg_wait_of_same_past_second 
	+ 0.0149 * parameters.avg_latency_of_same_last_20 
	+ 0.0035 * parameters.max_latency_of_same_last_50 
	+ 99318702.4121;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM76(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 18443.4231 * parameters.total_wait_locks 
	+ 0.0913 * parameters.mean_wait_of_all 
	+ 494401.8846 * parameters.cpu_usage 
	- 0.0118 * parameters.avg_work_of_same_past_second 
	- 0.0037 * parameters.avg_wait_of_same_past_second 
	+ 0.0223 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 7604184.2059;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM77(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 24449.9432 * parameters.total_wait_locks 
	+ 0.1334 * parameters.mean_wait_of_all 
	+ 494401.8846 * parameters.cpu_usage 
	- 0.9882 * parameters.avg_work_of_same_past_second 
	- 0.0037 * parameters.avg_wait_of_same_past_second 
	+ 0.0033 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 61039290.4023;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM78(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	+ 0.0097 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 109.3628 * parameters.total_wait_locks 
	+ 0.1701 * parameters.mean_wait_of_all 
	+ 24777357.8833 * parameters.cpu_usage 
	- 0.9779 * parameters.avg_work_of_same_past_second 
	+ 0.0495 * parameters.avg_wait_of_same_past_second 
	+ 0.088 * parameters.avg_latency_of_same_last_20 
	+ 0.0008 * parameters.max_latency_of_same_last_50 
	- 29205394.7103;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM79(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	+ 0.0166 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 455342.9705 * parameters.total_wait_locks 
	- 6.9359 * parameters.mean_wait_of_all 
	+ 41431314.7587 * parameters.cpu_usage 
	+ 21.8161 * parameters.avg_work_of_same_past_second 
	+ 0.0849 * parameters.avg_wait_of_same_past_second 
	- 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0.0008 * parameters.max_latency_of_same_last_50 
	+ 959057718.7824;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM80(work_wait &parameters) {
  double actual_remaining = 
	2949.9371 * parameters.work_so_far 
	- 0.2831 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 6383742.3675 * parameters.total_wait_locks 
	- 6.9359 * parameters.mean_wait_of_all 
	+ 41431314.7587 * parameters.cpu_usage 
	+ 14.3098 * parameters.avg_work_of_same_past_second 
	+ 0.0849 * parameters.avg_wait_of_same_past_second 
	- 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0.0008 * parameters.max_latency_of_same_last_50 
	- 3279543598.0015;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM81(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	+ 0.0507 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 115335.627 * parameters.total_wait_locks 
	- 5.0341 * parameters.mean_wait_of_all 
	+ 41431314.7587 * parameters.cpu_usage 
	+ 10.0911 * parameters.avg_work_of_same_past_second 
	+ 0.0849 * parameters.avg_wait_of_same_past_second 
	- 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0.009 * parameters.max_latency_of_same_last_50 
	+ 531565571.8385;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM82(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	+ 0.0292 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 115335.627 * parameters.total_wait_locks 
	- 1.1364 * parameters.mean_wait_of_all 
	+ 41431314.7587 * parameters.cpu_usage 
	+ 10.0911 * parameters.avg_work_of_same_past_second 
	+ 0.0849 * parameters.avg_wait_of_same_past_second 
	- 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0.0086 * parameters.max_latency_of_same_last_50 
	- 3138727.6219;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM83(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	+ 0.0292 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 115335.627 * parameters.total_wait_locks 
	- 1.4148 * parameters.mean_wait_of_all 
	+ 41431314.7587 * parameters.cpu_usage 
	+ 10.0911 * parameters.avg_work_of_same_past_second 
	+ 0.0849 * parameters.avg_wait_of_same_past_second 
	- 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0.0086 * parameters.max_latency_of_same_last_50 
	+ 51679222.244;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM84(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	- 0.0005 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 1794.8715 * parameters.total_wait_locks 
	- 0.013 * parameters.mean_wait_of_all 
	- 55535196.1006 * parameters.cpu_usage 
	- 0.011 * parameters.avg_work_of_same_past_second 
	+ 0.0064 * parameters.avg_wait_of_same_past_second 
	+ 0.0519 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 64125272.843;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM85(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	- 0.0185 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 386320.6364 * parameters.total_wait_locks 
	+ 1.6687 * parameters.mean_wait_of_all 
	+ 1556584.0607 * parameters.cpu_usage 
	- 0.011 * parameters.avg_work_of_same_past_second 
	+ 0.0038 * parameters.avg_wait_of_same_past_second 
	+ 0.1006 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 14692165.4882;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM86(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	- 0.0126 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 4101.9965 * parameters.total_wait_locks 
	- 0.0032 * parameters.mean_wait_of_all 
	+ 95064.4884 * parameters.cpu_usage 
	- 0.0058 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 34940108.297;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM87(work_wait &parameters) {
  double actual_remaining = 
	-1414.4876 * parameters.work_so_far 
	- 0.019 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 269859.4075 * parameters.total_wait_locks 
	+ 40.934 * parameters.mean_wait_of_all 
	+ 53043268.7012 * parameters.cpu_usage 
	- 14.8783 * parameters.avg_work_of_same_past_second 
	- 0.2152 * parameters.avg_wait_of_same_past_second 
	- 0.0145 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 3967885817.7848;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM88(work_wait &parameters) {
  double actual_remaining = 
	-225.3686 * parameters.work_so_far 
	- 0.0405 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 283211.6763 * parameters.total_wait_locks 
	+ 13.3129 * parameters.mean_wait_of_all 
	+ 53043268.7012 * parameters.cpu_usage 
	- 0.9741 * parameters.avg_work_of_same_past_second 
	- 0.2241 * parameters.avg_wait_of_same_past_second 
	- 0.0145 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 1435631584.035;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM89(work_wait &parameters) {
  double actual_remaining = 
	-165.2101 * parameters.work_so_far 
	- 0.0152 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 1163501.9708 * parameters.total_wait_locks 
	+ 9.3502 * parameters.mean_wait_of_all 
	+ 78879914.065 * parameters.cpu_usage 
	+ 0.846 * parameters.avg_work_of_same_past_second 
	- 0.2466 * parameters.avg_wait_of_same_past_second 
	- 0.0256 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 1444544151.7125;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM90(work_wait &parameters) {
  double actual_remaining = 
	-43.5875 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 72867.2275 * parameters.total_wait_locks 
	+ 22.3196 * parameters.mean_wait_of_all 
	+ 25842620.3229 * parameters.cpu_usage 
	- 0.2227 * parameters.avg_work_of_same_past_second 
	- 0.3582 * parameters.avg_wait_of_same_past_second 
	- 0 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 2330462237.6367;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM91(work_wait &parameters) {
  double actual_remaining = 
	2.1599 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 66528.9366 * parameters.total_wait_locks 
	- 0.0014 * parameters.mean_wait_of_all 
	+ 95064.4884 * parameters.cpu_usage 
	- 0.0007 * parameters.avg_work_of_same_past_second 
	- 0.0938 * parameters.avg_wait_of_same_past_second 
	+ 0 * parameters.avg_latency_of_same_last_20 
	+ 0.0005 * parameters.max_latency_of_same_last_50 
	+ 38671213.5887;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM92(work_wait &parameters) {
  double actual_remaining = 
	2.1599 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 109.3628 * parameters.total_wait_locks 
	- 0.0014 * parameters.mean_wait_of_all 
	+ 5998634.067 * parameters.cpu_usage 
	- 0.0007 * parameters.avg_work_of_same_past_second 
	+ 0.1554 * parameters.avg_wait_of_same_past_second 
	+ 0 * parameters.avg_latency_of_same_last_20 
	+ 0.0023 * parameters.max_latency_of_same_last_50 
	- 35725546.696;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM93(work_wait &parameters) {
  double actual_remaining = 
	2.1599 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 109.3628 * parameters.total_wait_locks 
	+ 0.9611 * parameters.mean_wait_of_all 
	+ 5998634.067 * parameters.cpu_usage 
	- 0.0007 * parameters.avg_work_of_same_past_second 
	- 0.0047 * parameters.avg_wait_of_same_past_second 
	+ 0 * parameters.avg_latency_of_same_last_20 
	+ 0.0035 * parameters.max_latency_of_same_last_50 
	- 90151679.6407;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM94(work_wait &parameters) {
  double actual_remaining = 
	2.1599 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 109.3628 * parameters.total_wait_locks 
	+ 0.7605 * parameters.mean_wait_of_all 
	+ 5998634.067 * parameters.cpu_usage 
	- 1.2602 * parameters.avg_work_of_same_past_second 
	- 0.0047 * parameters.avg_wait_of_same_past_second 
	+ 0 * parameters.avg_latency_of_same_last_20 
	+ 0.0035 * parameters.max_latency_of_same_last_50 
	- 5522526.4686;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM95(work_wait &parameters) {
  double actual_remaining = 
	2.1599 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 119755.5546 * parameters.total_wait_locks 
	- 0.0014 * parameters.mean_wait_of_all 
	+ 5998634.067 * parameters.cpu_usage 
	- 0.0007 * parameters.avg_work_of_same_past_second 
	- 0.0047 * parameters.avg_wait_of_same_past_second 
	+ 0 * parameters.avg_latency_of_same_last_20 
	+ 0.0175 * parameters.max_latency_of_same_last_50 
	+ 68235440.7117;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM96(work_wait &parameters) {
  double actual_remaining = 
	2.1599 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 109.3628 * parameters.total_wait_locks 
	- 0.0014 * parameters.mean_wait_of_all 
	+ 61075677.5335 * parameters.cpu_usage 
	- 0.0007 * parameters.avg_work_of_same_past_second 
	- 0.0033 * parameters.avg_wait_of_same_past_second 
	+ 0 * parameters.avg_latency_of_same_last_20 
	+ 0.0005 * parameters.max_latency_of_same_last_50 
	- 33638659.7707;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM97(work_wait &parameters) {
  double actual_remaining = 
	1.7093 * parameters.work_so_far 
	+ 0.0017 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 109.3628 * parameters.total_wait_locks 
	- 0.301 * parameters.mean_wait_of_all 
	+ 95064.4884 * parameters.cpu_usage 
	- 0.0007 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 69352151.0369;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM98(work_wait &parameters) {
  double actual_remaining = 
	1.7093 * parameters.work_so_far 
	+ 0.1859 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 257327.1459 * parameters.total_wait_locks 
	- 0.0014 * parameters.mean_wait_of_all 
	- 150562081.241 * parameters.cpu_usage 
	+ 0.239 * parameters.avg_work_of_same_past_second 
	+ 0.1658 * parameters.avg_wait_of_same_past_second 
	+ 0.0363 * parameters.avg_latency_of_same_last_20 
	- 0.0187 * parameters.max_latency_of_same_last_50 
	- 92416202.6266;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM99(work_wait &parameters) {
  double actual_remaining = 
	334.6797 * parameters.work_so_far 
	+ 0.0038 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 477754.1196 * parameters.total_wait_locks 
	- 1.2342 * parameters.mean_wait_of_all 
	+ 95064.4884 * parameters.cpu_usage 
	- 0.0007 * parameters.avg_work_of_same_past_second 
	+ 0.311 * parameters.avg_wait_of_same_past_second 
	+ 0 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 404544944.2971;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM100(work_wait &parameters) {
  double actual_remaining = 
	334.6797 * parameters.work_so_far 
	+ 0.0038 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 477754.1196 * parameters.total_wait_locks 
	- 1.2342 * parameters.mean_wait_of_all 
	+ 95064.4884 * parameters.cpu_usage 
	- 0.0007 * parameters.avg_work_of_same_past_second 
	+ 0.311 * parameters.avg_wait_of_same_past_second 
	+ 0 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 407202137.1571;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM101(work_wait &parameters) {
  double actual_remaining = 
	334.6797 * parameters.work_so_far 
	+ 0.0038 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 414905.2578 * parameters.total_wait_locks 
	- 1.2342 * parameters.mean_wait_of_all 
	+ 95064.4884 * parameters.cpu_usage 
	- 0.0007 * parameters.avg_work_of_same_past_second 
	+ 0.2814 * parameters.avg_wait_of_same_past_second 
	+ 0 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 364745314.1549;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM102(work_wait &parameters) {
  double actual_remaining = 
	168.1945 * parameters.work_so_far 
	+ 0.0038 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 313354.9949 * parameters.total_wait_locks 
	- 1.2342 * parameters.mean_wait_of_all 
	+ 95064.4884 * parameters.cpu_usage 
	- 0.0007 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0 * parameters.avg_latency_of_same_last_20 
	+ 0.0338 * parameters.max_latency_of_same_last_50 
	- 29939159.1588;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM103(work_wait &parameters) {
  double actual_remaining = 
	168.1945 * parameters.work_so_far 
	+ 0.0038 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 421734.3535 * parameters.total_wait_locks 
	- 1.2342 * parameters.mean_wait_of_all 
	+ 95064.4884 * parameters.cpu_usage 
	- 0.0007 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0 * parameters.avg_latency_of_same_last_20 
	+ 0.0617 * parameters.max_latency_of_same_last_50 
	- 119814902.8301;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM104(work_wait &parameters) {
  double actual_remaining = 
	168.1945 * parameters.work_so_far 
	+ 0.0038 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 421734.3535 * parameters.total_wait_locks 
	- 1.2342 * parameters.mean_wait_of_all 
	+ 95064.4884 * parameters.cpu_usage 
	- 0.1452 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0628 * parameters.avg_latency_of_same_last_20 
	+ 0.0617 * parameters.max_latency_of_same_last_50 
	- 134991640.0237;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM105(work_wait &parameters) {
  double actual_remaining = 
	168.1945 * parameters.work_so_far 
	+ 0.0038 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 421734.3535 * parameters.total_wait_locks 
	- 1.2342 * parameters.mean_wait_of_all 
	+ 95064.4884 * parameters.cpu_usage 
	- 0.1622 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.057 * parameters.avg_latency_of_same_last_20 
	+ 0.0617 * parameters.max_latency_of_same_last_50 
	- 132639500.2826;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM106(work_wait &parameters) {
  double actual_remaining = 
	1.7093 * parameters.work_so_far 
	+ 0.0038 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	+ 824744.7616 * parameters.total_wait_locks 
	- 4.3963 * parameters.mean_wait_of_all 
	- 220395961.7783 * parameters.cpu_usage 
	- 0.4734 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 349652079.5557;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM107(work_wait &parameters) {
  double actual_remaining = 
	0.7658 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 46912.4561 * parameters.total_wait_locks 
	- 0.0014 * parameters.mean_wait_of_all 
	+ 95064.4884 * parameters.cpu_usage 
	+ 0.0059 * parameters.avg_work_of_same_past_second 
	+ 0.0011 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 50066200.2972;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM108(work_wait &parameters) {
  double actual_remaining = 
	0.7658 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 362973.8574 * parameters.total_wait_locks 
	+ 1.9902 * parameters.mean_wait_of_all 
	+ 95064.4884 * parameters.cpu_usage 
	+ 0.2191 * parameters.avg_work_of_same_past_second 
	+ 0.0026 * parameters.avg_wait_of_same_past_second 
	- 0.0414 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 5855650.7824;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM109(work_wait &parameters) {
  double actual_remaining = 
	0.7658 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 32039.0805 * parameters.num_locks_so_far 
	- 1806.1782 * parameters.total_wait_locks 
	- 0.0014 * parameters.mean_wait_of_all 
	+ 95064.4884 * parameters.cpu_usage 
	+ 0.0041 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 22239277.5029;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM110(work_wait &parameters) {
  double actual_remaining = 
	0.2161 * parameters.work_so_far 
	+ 0.2847 * parameters.wait_so_far 
	+ 3213932.1641 * parameters.num_locks_so_far 
	+ 689.1076 * parameters.total_wait_locks 
	- 0.0017 * parameters.mean_wait_of_all 
	- 24174491.614 * parameters.cpu_usage 
	+ 0.0366 * parameters.avg_wait_of_same_past_second 
	+ 0.0285 * parameters.avg_latency_of_same_last_20 
	- 0.0058 * parameters.max_latency_of_same_last_50 
	+ 26505474.2466;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM111(work_wait &parameters) {
  double actual_remaining = 
	0.01 * parameters.work_so_far 
	+ 0.0315 * parameters.wait_so_far 
	+ 821376.9254 * parameters.num_locks_so_far 
	- 25629.406 * parameters.total_wait_locks 
	+ 0.1555 * parameters.mean_wait_of_all 
	+ 5425956.694 * parameters.cpu_usage 
	- 0.0511 * parameters.avg_work_of_same_past_second 
	+ 0.0025 * parameters.avg_wait_of_same_past_second 
	+ 0.0036 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 27618681.8664;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM112(work_wait &parameters) {
  double actual_remaining = 
	0.01 * parameters.work_so_far 
	+ 0.233 * parameters.wait_so_far 
	+ 3126473.8092 * parameters.num_locks_so_far 
	+ 232844.8259 * parameters.total_wait_locks 
	- 1.0343 * parameters.mean_wait_of_all 
	+ 5425956.694 * parameters.cpu_usage 
	- 0.0511 * parameters.avg_work_of_same_past_second 
	+ 0.0025 * parameters.avg_wait_of_same_past_second 
	+ 0.0033 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 41948719.3035;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM113(work_wait &parameters) {
  double actual_remaining = 
	0.01 * parameters.work_so_far 
	+ 0.016 * parameters.wait_so_far 
	+ 899095.3426 * parameters.num_locks_so_far 
	+ 53072.3448 * parameters.total_wait_locks 
	+ 0.2039 * parameters.mean_wait_of_all 
	+ 696778502.655 * parameters.cpu_usage 
	- 0.1796 * parameters.avg_work_of_same_past_second 
	+ 0.0025 * parameters.avg_wait_of_same_past_second 
	+ 0.9152 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	- 807958084.2122;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM114(work_wait &parameters) {
  double actual_remaining = 
	0.01 * parameters.work_so_far 
	+ 5.8924 * parameters.wait_so_far 
	+ 899095.3426 * parameters.num_locks_so_far 
	+ 53072.3448 * parameters.total_wait_locks 
	+ 0.2039 * parameters.mean_wait_of_all 
	+ 696778502.655 * parameters.cpu_usage 
	- 0.1796 * parameters.avg_work_of_same_past_second 
	+ 0.0025 * parameters.avg_wait_of_same_past_second 
	+ 0.8671 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	- 784970704.6057;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM115(work_wait &parameters) {
  double actual_remaining = 
	0.01 * parameters.work_so_far 
	+ 0.111 * parameters.wait_so_far 
	+ 899095.3426 * parameters.num_locks_so_far 
	+ 53072.3448 * parameters.total_wait_locks 
	+ 0.2039 * parameters.mean_wait_of_all 
	+ 696778502.655 * parameters.cpu_usage 
	- 0.1796 * parameters.avg_work_of_same_past_second 
	+ 0.0025 * parameters.avg_wait_of_same_past_second 
	+ 0.0012 * parameters.avg_latency_of_same_last_20 
	+ 0.0111 * parameters.max_latency_of_same_last_50 
	- 648373260.73;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM116(work_wait &parameters) {
  double actual_remaining = 
	0.01 * parameters.work_so_far 
	+ 0.016 * parameters.wait_so_far 
	+ 899095.3426 * parameters.num_locks_so_far 
	- 131528.7718 * parameters.total_wait_locks 
	+ 0.2039 * parameters.mean_wait_of_all 
	+ 290156254.0474 * parameters.cpu_usage 
	- 0.1796 * parameters.avg_work_of_same_past_second 
	+ 0.0025 * parameters.avg_wait_of_same_past_second 
	+ 0.1034 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	- 231498523.4761;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM117(work_wait &parameters) {
  double actual_remaining = 
	0.006 * parameters.work_so_far 
	+ 0.3847 * parameters.wait_so_far 
	+ 976902.379 * parameters.num_locks_so_far 
	+ 689.1076 * parameters.total_wait_locks 
	- 0.0017 * parameters.mean_wait_of_all 
	- 0.5739 * parameters.avg_work_of_same_past_second 
	+ 0.1465 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	- 35314818.4894;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM118(work_wait &parameters) {
  double actual_remaining = 
	1.3522 * parameters.work_so_far 
	+ 0.9257 * parameters.wait_so_far 
	+ 2180393.9291 * parameters.num_locks_so_far 
	+ 38128.307 * parameters.total_wait_locks 
	- 0.0017 * parameters.mean_wait_of_all 
	+ 0.012 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	- 15571132.9143;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM119(work_wait &parameters) {
  double actual_remaining = 
	0.0027 * parameters.work_so_far 
	+ 0.0539 * parameters.wait_so_far 
	+ 1148334.6666 * parameters.num_locks_so_far 
	+ 5411.9637 * parameters.total_wait_locks 
	+ 0.014 * parameters.mean_wait_of_all 
	+ 0.1763 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	- 0.0545 * parameters.max_latency_of_same_last_50 
	+ 108959620.8035;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM120(work_wait &parameters) {
  double actual_remaining = 
	0.0027 * parameters.work_so_far 
	+ 0.0693 * parameters.wait_so_far 
	+ 1148334.6666 * parameters.num_locks_so_far 
	+ 5411.9637 * parameters.total_wait_locks 
	+ 0.2787 * parameters.mean_wait_of_all 
	+ 3.4163 * parameters.avg_work_of_same_past_second 
	+ 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0493 * parameters.avg_latency_of_same_last_20 
	- 35757344.4967;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM121(work_wait &parameters) {
  double actual_remaining = 
	0.0027 * parameters.work_so_far 
	+ 0.6617 * parameters.wait_so_far 
	+ 1148334.6666 * parameters.num_locks_so_far 
	+ 5411.9637 * parameters.total_wait_locks 
	+ 0.1106 * parameters.mean_wait_of_all 
	+ 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.4815 * parameters.avg_latency_of_same_last_20 
	- 212874366.5204;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM122(work_wait &parameters) {
  double actual_remaining = 
	0.0027 * parameters.work_so_far 
	+ 0.0693 * parameters.wait_so_far 
	+ 1148334.6666 * parameters.num_locks_so_far 
	+ 5411.9637 * parameters.total_wait_locks 
	+ 0.1106 * parameters.mean_wait_of_all 
	+ 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0459 * parameters.avg_latency_of_same_last_20 
	+ 163780883.2609;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM123(work_wait &parameters) {
  double actual_remaining = 
	1.0417 * parameters.work_so_far 
	+ 0.9654 * parameters.wait_so_far 
	+ 1459389.3279 * parameters.num_locks_so_far 
	+ 29384.5138 * parameters.total_wait_locks 
	- 0.0031 * parameters.mean_wait_of_all 
	+ 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	- 3258386.4711;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM124(work_wait &parameters) {
  double actual_remaining = 
	0.0027 * parameters.work_so_far 
	+ 0.1419 * parameters.wait_so_far 
	+ 3480796.2665 * parameters.num_locks_so_far 
	+ 381643.843 * parameters.total_wait_locks 
	- 1.8249 * parameters.mean_wait_of_all 
	+ 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 269288279.2303;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM125(work_wait &parameters) {
  double actual_remaining = 
	0.0027 * parameters.work_so_far 
	+ 1.0273 * parameters.wait_so_far 
	+ 3480796.2665 * parameters.num_locks_so_far 
	+ 874173.3358 * parameters.total_wait_locks 
	- 4.2155 * parameters.mean_wait_of_all 
	- 2098439794.883 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 1360133288.5668;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM126(work_wait &parameters) {
  double actual_remaining = 
	1.0552 * parameters.work_so_far 
	+ 0.9764 * parameters.wait_so_far 
	+ 3895445.8183 * parameters.num_locks_so_far 
	+ 92576.1094 * parameters.total_wait_locks 
	- 0.4201 * parameters.mean_wait_of_all 
	+ 61230015.164 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	- 73082070.0849;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
payment_estimate(work_wait &parameters){

  if (parameters.work_so_far <= 213677) {

    if (parameters.mean_wait_of_all <= 94963800) {

      if (parameters.total_wait_locks <= 200.5) {

        if (parameters.total_wait_locks <= 27.5) {

          if (parameters.work_so_far <= 8455.5) {

            if (parameters.cpu_usage <= 0.855) {
              return payment_LM1(parameters);
            } else {

              if (parameters.wait_so_far <= 9237613.5) {
                return payment_LM2(parameters);
              } else {

                if (parameters.cpu_usage <= 0.886) {
                  return payment_LM3(parameters);
                } else {

                  if (parameters.cpu_usage <= 0.902) {

                    if (parameters.cpu_usage <= 0.891) {

                      if (parameters.work_so_far <= 7926.5) {

                        if (parameters.wait_so_far <= 18923139) {
                          return payment_LM4(parameters);
                        } else {
                          return payment_LM5(parameters);
                        }
                      } else {
                        return payment_LM6(parameters);
                      }
                    } else {
                      return payment_LM7(parameters);
                    }
                  } else {
                    return payment_LM8(parameters);
                  }
                }
              }
            }
          } else {

            if (parameters.avg_work_of_same_past_second <= 6719370) {

              if (parameters.avg_latency_of_same_last_20 <= 31467450) {
                return payment_LM9(parameters);
              } else {

                if (parameters.cpu_usage <= 0.872) {

                  if (parameters.wait_so_far <= 10489647.5) {
                    return payment_LM10(parameters);
                  } else {

                    if (parameters.wait_so_far <= 46538647) {

                      if (parameters.cpu_usage <= 0.865) {
                        return payment_LM11(parameters);
                      } else {
                        return payment_LM12(parameters);
                      }
                    } else {
                      return payment_LM13(parameters);
                    }
                  }
                } else {
                  return payment_LM14(parameters);
                }
              }
            } else {

              if (parameters.avg_latency_of_same_last_20 <= 60539800) {

                if (parameters.cpu_usage <= 0.938) {

                  if (parameters.max_latency_of_same_last_50 <= 102313000) {
                    return payment_LM15(parameters);
                  } else {

                    if (parameters.work_so_far <= 10027) {

                      if (parameters.avg_wait_of_same_past_second <= 14853200) {
                        return payment_LM16(parameters);
                      } else {

                        if (parameters.mean_wait_of_all <= 28865800) {
                          return payment_LM17(parameters);
                        } else {

                          if (parameters.work_so_far <= 9445) {

                            if (parameters.wait_so_far <= 2799) {
                              return payment_LM18(parameters);
                            } else {
                              return payment_LM19(parameters);
                            }
                          } else {
                            return payment_LM20(parameters);
                          }
                        }
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
            }
          }
        } else {

          if (parameters.mean_wait_of_all <= 31213250) {

            if (parameters.mean_wait_of_all <= 28309450) {

              if (parameters.avg_work_of_same_past_second <= 12032000) {
                return payment_LM24(parameters);
              } else {

                if (parameters.mean_wait_of_all <= 28064150) {
                  return payment_LM25(parameters);
                } else {

                  if (parameters.mean_wait_of_all <= 28091900) {

                    if (parameters.work_so_far <= 23421) {

                      if (parameters.avg_work_of_same_past_second <= 16295050) {
                        return payment_LM26(parameters);
                      } else {

                        if (parameters.mean_wait_of_all <= 28087750) {
                          return payment_LM27(parameters);
                        } else {
                          return payment_LM28(parameters);
                        }
                      }
                    } else {
                      return payment_LM29(parameters);
                    }
                  } else {

                    if (parameters.wait_so_far <= 2179417) {
                      return payment_LM30(parameters);
                    } else {
                      return payment_LM31(parameters);
                    }
                  }
                }
              }
            } else {

              if (parameters.avg_work_of_same_past_second <= 10408350) {

                if (parameters.mean_wait_of_all <= 28661650) {
                  return payment_LM32(parameters);
                } else {

                  if (parameters.total_wait_locks <= 40.5) {

                    if (parameters.avg_latency_of_same_last_20 <= 29040400) {
                      return payment_LM33(parameters);
                    } else {

                      if (parameters.work_so_far <= 16080.5) {

                        if (parameters.total_wait_locks <= 36.5) {

                          if (parameters.cpu_usage <= 0.829) {
                            return payment_LM34(parameters);
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
                  } else {
                    return payment_LM38(parameters);
                  }
                }
              } else {

                if (parameters.work_so_far <= 25506) {

                  if (parameters.avg_work_of_same_past_second <= 15763100) {
                    return payment_LM39(parameters);
                  } else {
                    return payment_LM40(parameters);
                  }
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

        if (parameters.avg_latency_of_same_last_20 <= 525368000) {

          if (parameters.work_so_far <= 34070) {
            return payment_LM43(parameters);
          } else {

            if (parameters.cpu_usage <= 0.947) {
              return payment_LM44(parameters);
            } else {

              if (parameters.total_wait_locks <= 334) {

                if (parameters.wait_so_far <= 223097953) {
                  return payment_LM45(parameters);
                } else {

                  if (parameters.avg_latency_of_same_last_20 <= 348316000) {
                    return payment_LM46(parameters);
                  } else {

                    if (parameters.max_latency_of_same_last_50 <= 1158405000) {

                      if (parameters.cpu_usage <= 0.964) {
                        return payment_LM47(parameters);
                      } else {

                        if (parameters.avg_latency_of_same_last_20 <= 383439000) {

                          if (parameters.wait_so_far <= 363267332) {
                            return payment_LM48(parameters);
                          } else {
                            return payment_LM49(parameters);
                          }
                        } else {
                          return payment_LM50(parameters);
                        }
                      }
                    } else {

                      if (parameters.cpu_usage <= 0.961) {
                        return payment_LM51(parameters);
                      } else {

                        if (parameters.wait_so_far <= 539860651.5) {
                          return payment_LM52(parameters);
                        } else {
                          return payment_LM53(parameters);
                        }
                      }
                    }
                  }
                }
              } else {

                if (parameters.wait_so_far <= 177996853) {

                  if (parameters.avg_wait_of_same_past_second <= 348201000) {

                    if (parameters.avg_wait_of_same_past_second <= 308546500) {

                      if (parameters.wait_so_far <= 628872.5) {
                        return payment_LM54(parameters);
                      } else {

                        if (parameters.max_latency_of_same_last_50 <= 960051500) {
                          return payment_LM55(parameters);
                        } else {
                          return payment_LM56(parameters);
                        }
                      }
                    } else {

                      if (parameters.max_latency_of_same_last_50 <= 877990000) {
                        return payment_LM57(parameters);
                      } else {

                        if (parameters.max_latency_of_same_last_50 <= 1148695000) {

                          if (parameters.max_latency_of_same_last_50 <= 930239000) {
                            return payment_LM58(parameters);
                          } else {

                            if (parameters.avg_wait_of_same_past_second <= 339769500) {

                              if (parameters.work_so_far <= 35779) {
                                return payment_LM59(parameters);
                              } else {
                                return payment_LM60(parameters);
                              }
                            } else {
                              return payment_LM61(parameters);
                            }
                          }
                        } else {
                          return payment_LM62(parameters);
                        }
                      }
                    }
                  } else {
                    return payment_LM63(parameters);
                  }
                } else {
                  return payment_LM64(parameters);
                }
              }
            }
          }
        } else {

          if (parameters.avg_work_of_same_past_second <= 25906550) {

            if (parameters.cpu_usage <= 0.969) {
              return payment_LM65(parameters);
            } else {

              if (parameters.wait_so_far <= 105330848.5) {

                if (parameters.wait_so_far <= 124690.5) {
                  return payment_LM66(parameters);
                } else {
                  return payment_LM67(parameters);
                }
              } else {

                if (parameters.avg_work_of_same_past_second <= 23068900) {

                  if (parameters.work_so_far <= 35519.5) {

                    if (parameters.wait_so_far <= 319974048.5) {
                      return payment_LM68(parameters);
                    } else {
                      return payment_LM69(parameters);
                    }
                  } else {
                    return payment_LM70(parameters);
                  }
                } else {

                  if (parameters.avg_wait_of_same_past_second <= 408094000) {
                    return payment_LM71(parameters);
                  } else {
                    return payment_LM72(parameters);
                  }
                }
              }
            }
          } else {

            if (parameters.mean_wait_of_all <= 64241600) {

              if (parameters.max_latency_of_same_last_50 <= 1661230000) {
                return payment_LM73(parameters);
              } else {

                if (parameters.total_wait_locks <= 217.5) {
                  return payment_LM74(parameters);
                } else {
                  return payment_LM75(parameters);
                }
              }
            } else {

              if (parameters.mean_wait_of_all <= 85900100) {
                return payment_LM76(parameters);
              } else {
                return payment_LM77(parameters);
              }
            }
          }
        }
      }
    } else {

      if (parameters.avg_latency_of_same_last_20 <= 331534000) {

        if (parameters.avg_work_of_same_past_second <= 25125400) {

          if (parameters.mean_wait_of_all <= 133969000) {
            return payment_LM78(parameters);
          } else {

            if (parameters.mean_wait_of_all <= 137705500) {

              if (parameters.total_wait_locks <= 622.5) {
                return payment_LM79(parameters);
              } else {
                return payment_LM80(parameters);
              }
            } else {

              if (parameters.max_latency_of_same_last_50 <= 1069805000) {
                return payment_LM81(parameters);
              } else {

                if (parameters.mean_wait_of_all <= 142309500) {
                  return payment_LM82(parameters);
                } else {
                  return payment_LM83(parameters);
                }
              }
            }
          }
        } else {

          if (parameters.avg_wait_of_same_past_second <= 368003500) {
            return payment_LM84(parameters);
          } else {
            return payment_LM85(parameters);
          }
        }
      } else {

        if (parameters.mean_wait_of_all <= 111482500) {

          if (parameters.mean_wait_of_all <= 108398000) {
            return payment_LM86(parameters);
          } else {

            if (parameters.avg_work_of_same_past_second <= 49862000) {

              if (parameters.avg_work_of_same_past_second <= 36976650) {

                if (parameters.wait_so_far <= 96100897) {
                  return payment_LM87(parameters);
                } else {
                  return payment_LM88(parameters);
                }
              } else {
                return payment_LM89(parameters);
              }
            } else {
              return payment_LM90(parameters);
            }
          }
        } else {

          if (parameters.wait_so_far <= 139970164.5) {

            if (parameters.work_so_far <= 31802.5) {

              if (parameters.cpu_usage <= 0.838) {
                return payment_LM91(parameters);
              } else {

                if (parameters.avg_wait_of_same_past_second <= 395656000) {

                  if (parameters.max_latency_of_same_last_50 <= 1338105000) {
                    return payment_LM92(parameters);
                  } else {

                    if (parameters.wait_so_far <= 11034) {

                      if (parameters.mean_wait_of_all <= 128092000) {
                        return payment_LM93(parameters);
                      } else {
                        return payment_LM94(parameters);
                      }
                    } else {
                      return payment_LM95(parameters);
                    }
                  }
                } else {
                  return payment_LM96(parameters);
                }
              }
            } else {

              if (parameters.total_wait_locks <= 611.5) {
                return payment_LM97(parameters);
              } else {

                if (parameters.cpu_usage <= 0.882) {
                  return payment_LM98(parameters);
                } else {

                  if (parameters.max_latency_of_same_last_50 <= 1149835000) {

                    if (parameters.max_latency_of_same_last_50 <= 892645000) {

                      if (parameters.total_wait_locks <= 622) {

                        if (parameters.avg_wait_of_same_past_second <= 358468500) {
                          return payment_LM99(parameters);
                        } else {
                          return payment_LM100(parameters);
                        }
                      } else {
                        return payment_LM101(parameters);
                      }
                    } else {

                      if (parameters.total_wait_locks <= 652.5) {
                        return payment_LM102(parameters);
                      } else {

                        if (parameters.max_latency_of_same_last_50 <= 970024500) {
                          return payment_LM103(parameters);
                        } else {

                          if (parameters.avg_work_of_same_past_second <= 50657250) {
                            return payment_LM104(parameters);
                          } else {
                            return payment_LM105(parameters);
                          }
                        }
                      }
                    }
                  } else {
                    return payment_LM106(parameters);
                  }
                }
              }
            }
          } else {

            if (parameters.max_latency_of_same_last_50 <= 1647690000) {

              if (parameters.avg_latency_of_same_last_20 <= 606499500) {
                return payment_LM107(parameters);
              } else {
                return payment_LM108(parameters);
              }
            } else {
              return payment_LM109(parameters);
            }
          }
        }
      }
    }
  } else {

    if (parameters.wait_so_far <= 273868240) {

      if (parameters.wait_so_far <= 130032426) {

        if (parameters.avg_wait_of_same_past_second <= 447445500) {
          return payment_LM110(parameters);
        } else {

          if (parameters.cpu_usage <= 0.95) {

            if (parameters.work_so_far <= 2582626.5) {
              return payment_LM111(parameters);
            } else {
              return payment_LM112(parameters);
            }
          } else {

            if (parameters.avg_work_of_same_past_second <= 26571400) {

              if (parameters.avg_latency_of_same_last_20 <= 268021500) {

                if (parameters.avg_latency_of_same_last_20 <= 219279000) {
                  return payment_LM113(parameters);
                } else {
                  return payment_LM114(parameters);
                }
              } else {
                return payment_LM115(parameters);
              }
            } else {
              return payment_LM116(parameters);
            }
          }
        }
      } else {

        if (parameters.num_locks_so_far <= 3) {
          return payment_LM117(parameters);
        } else {
          return payment_LM118(parameters);
        }
      }
    } else {

      if (parameters.wait_so_far <= 650882796.5) {

        if (parameters.num_locks_so_far <= 2.5) {

          if (parameters.wait_so_far <= 486762577.5) {
            return payment_LM119(parameters);
          } else {

            if (parameters.work_so_far <= 807007) {
              return payment_LM120(parameters);
            } else {

              if (parameters.work_so_far <= 1717852) {
                return payment_LM121(parameters);
              } else {
                return payment_LM122(parameters);
              }
            }
          }
        } else {
          return payment_LM123(parameters);
        }
      } else {

        if (parameters.num_locks_so_far <= 2.5) {

          if (parameters.wait_so_far <= 1127977614.5) {
            return payment_LM124(parameters);
          } else {
            return payment_LM125(parameters);
          }
        } else {
          return payment_LM126(parameters);
        }
      }
    }
  }
}
static
double
delivery_LM1(work_wait &parameters) {
  double actual_remaining = 
	1.3407 * parameters.work_so_far 
	+ 0.2515 * parameters.wait_so_far 
	- 1778960.7816 * parameters.num_locks_so_far 
	+ 232036.1223 * parameters.total_wait_locks 
	- 0.3944 * parameters.mean_wait_of_all 
	- 1098572654.0934 * parameters.cpu_usage 
	+ 0.3522 * parameters.avg_work_of_same_past_second 
	- 0.4647 * parameters.avg_wait_of_same_past_second 
	+ 0.2683 * parameters.avg_latency_of_same_last_20 
	- 0.008 * parameters.max_latency_of_same_last_50 
	+ 1109775938.3674;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM2(work_wait &parameters) {
  double actual_remaining = 
	1.3407 * parameters.work_so_far 
	+ 0.12 * parameters.wait_so_far 
	- 1778960.7816 * parameters.num_locks_so_far 
	+ 232036.1223 * parameters.total_wait_locks 
	- 0.3944 * parameters.mean_wait_of_all 
	- 834074838.5645 * parameters.cpu_usage 
	+ 0.2867 * parameters.avg_work_of_same_past_second 
	- 0.4647 * parameters.avg_wait_of_same_past_second 
	+ 0.1919 * parameters.avg_latency_of_same_last_20 
	- 0.008 * parameters.max_latency_of_same_last_50 
	+ 931977930.0014;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM3(work_wait &parameters) {
  double actual_remaining = 
	151.3276 * parameters.work_so_far 
	+ 0.1718 * parameters.wait_so_far 
	- 1778960.7816 * parameters.num_locks_so_far 
	+ 232036.1223 * parameters.total_wait_locks 
	- 0.3944 * parameters.mean_wait_of_all 
	- 935994228.0566 * parameters.cpu_usage 
	+ 0.3778 * parameters.avg_work_of_same_past_second 
	- 1.8719 * parameters.avg_wait_of_same_past_second 
	+ 0.1078 * parameters.avg_latency_of_same_last_20 
	- 0.008 * parameters.max_latency_of_same_last_50 
	+ 992278150.5483;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM4(work_wait &parameters) {
  double actual_remaining = 
	1.5524 * parameters.work_so_far 
	+ 0.0563 * parameters.wait_so_far 
	- 2147363.9915 * parameters.num_locks_so_far 
	+ 16775.2672 * parameters.total_wait_locks 
	+ 0.5534 * parameters.mean_wait_of_all 
	- 1339657971.7886 * parameters.cpu_usage 
	- 0.084 * parameters.avg_work_of_same_past_second 
	+ 0.062 * parameters.avg_latency_of_same_last_20 
	- 0.3746 * parameters.max_latency_of_same_last_50 
	+ 2411080542.5697;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM5(work_wait &parameters) {
  double actual_remaining = 
	1.0694 * parameters.work_so_far 
	+ 0.0563 * parameters.wait_so_far 
	- 1439090.5834 * parameters.num_locks_so_far 
	+ 184573.339 * parameters.total_wait_locks 
	- 0.3333 * parameters.mean_wait_of_all 
	- 125747220.4251 * parameters.cpu_usage 
	- 0.0297 * parameters.avg_work_of_same_past_second 
	+ 0.125 * parameters.avg_latency_of_same_last_20 
	- 0.1455 * parameters.max_latency_of_same_last_50 
	+ 730686662.7527;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM6(work_wait &parameters) {
  double actual_remaining = 
	2.3048 * parameters.work_so_far 
	- 0.3261 * parameters.wait_so_far 
	- 1439090.5834 * parameters.num_locks_so_far 
	+ 257777.4249 * parameters.total_wait_locks 
	- 0.6374 * parameters.mean_wait_of_all 
	- 125747220.4251 * parameters.cpu_usage 
	- 0.0297 * parameters.avg_work_of_same_past_second 
	+ 0.1643 * parameters.avg_latency_of_same_last_20 
	- 0.008 * parameters.max_latency_of_same_last_50 
	+ 733708531.636;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM7(work_wait &parameters) {
  double actual_remaining = 
	2.124 * parameters.work_so_far 
	- 0.0588 * parameters.wait_so_far 
	- 1439090.5834 * parameters.num_locks_so_far 
	+ 257777.4249 * parameters.total_wait_locks 
	- 0.6374 * parameters.mean_wait_of_all 
	- 125747220.4251 * parameters.cpu_usage 
	- 0.8475 * parameters.avg_work_of_same_past_second 
	+ 0.1643 * parameters.avg_latency_of_same_last_20 
	- 0.008 * parameters.max_latency_of_same_last_50 
	+ 1511568221.6727;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM8(work_wait &parameters) {
  double actual_remaining = 
	1.1457 * parameters.work_so_far 
	+ 0.6157 * parameters.wait_so_far 
	+ 3216781.7552 * parameters.num_locks_so_far 
	- 217778.5221 * parameters.total_wait_locks 
	+ 2.4437 * parameters.mean_wait_of_all 
	- 160046929.89 * parameters.cpu_usage 
	+ 0.0486 * parameters.avg_work_of_same_past_second 
	+ 0.1022 * parameters.avg_latency_of_same_last_20 
	- 0.1461 * parameters.max_latency_of_same_last_50 
	+ 370467007.1376;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM9(work_wait &parameters) {
  double actual_remaining = 
	1.1457 * parameters.work_so_far 
	+ 0.4838 * parameters.wait_so_far 
	+ 9259407.202 * parameters.num_locks_so_far 
	- 146825.6093 * parameters.total_wait_locks 
	+ 1.8802 * parameters.mean_wait_of_all 
	- 160046929.89 * parameters.cpu_usage 
	+ 0.0486 * parameters.avg_work_of_same_past_second 
	+ 0.1022 * parameters.avg_latency_of_same_last_20 
	- 0.3194 * parameters.max_latency_of_same_last_50 
	+ 902619850.3557;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM10(work_wait &parameters) {
  double actual_remaining = 
	1.1457 * parameters.work_so_far 
	+ 1.0378 * parameters.wait_so_far 
	+ 6731519.2297 * parameters.num_locks_so_far 
	- 146825.6093 * parameters.total_wait_locks 
	+ 1.8802 * parameters.mean_wait_of_all 
	- 160046929.89 * parameters.cpu_usage 
	+ 0.0486 * parameters.avg_work_of_same_past_second 
	+ 0.1022 * parameters.avg_latency_of_same_last_20 
	- 0.2476 * parameters.max_latency_of_same_last_50 
	+ 392295970.8308;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM11(work_wait &parameters) {
  double actual_remaining = 
	0.8282 * parameters.work_so_far 
	+ 0.7109 * parameters.wait_so_far 
	- 11735018.8489 * parameters.num_locks_so_far 
	+ 734781.2743 * parameters.total_wait_locks 
	- 2.0379 * parameters.mean_wait_of_all 
	- 18889772.0879 * parameters.cpu_usage 
	+ 0.0151 * parameters.avg_latency_of_same_last_20 
	+ 1023801844.5728;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
delivery_estimate(work_wait &parameters){

  if (parameters.work_so_far <= 82854844.5) {

    if (parameters.wait_so_far <= 732629557.5) {

      if (parameters.total_wait_locks <= 148.5) {

        if (parameters.wait_so_far <= 371142789) {

          if (parameters.total_wait_locks <= 17.5) {
            return delivery_LM1(parameters);
          } else {
            return delivery_LM2(parameters);
          }
        } else {
          return delivery_LM3(parameters);
        }
      } else {

        if (parameters.avg_wait_of_same_past_second <= 132998500) {
          return delivery_LM4(parameters);
        } else {

          if (parameters.avg_latency_of_same_last_20 <= 395959500) {
            return delivery_LM5(parameters);
          } else {

            if (parameters.avg_work_of_same_past_second <= 798313500) {
              return delivery_LM6(parameters);
            } else {
              return delivery_LM7(parameters);
            }
          }
        }
      }
    } else {

      if (parameters.wait_so_far <= 894590957) {
        return delivery_LM8(parameters);
      } else {

        if (parameters.work_so_far <= 818644) {
          return delivery_LM9(parameters);
        } else {
          return delivery_LM10(parameters);
        }
      }
    }
  } else {
    return delivery_LM11(parameters);
  }
}
static
double
stock_level_LM1(work_wait &parameters) {
  double actual_remaining = 
	+ 47748542.2727;
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
	9.113 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 6015.7452 * parameters.total_wait_locks 
	- 0.0007 * parameters.mean_wait_of_all 
	- 922500.1759 * parameters.cpu_usage 
	+ 0.0014 * parameters.avg_work_of_same_past_second 
	- 0.0006 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 7332173.2382;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM2(work_wait &parameters) {
  double actual_remaining = 
	11.6858 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 7293.6961 * parameters.total_wait_locks 
	- 0.0007 * parameters.mean_wait_of_all 
	- 6454634.6433 * parameters.cpu_usage 
	+ 0.0014 * parameters.avg_work_of_same_past_second 
	- 0.0006 * parameters.avg_wait_of_same_past_second 
	- 0.0053 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 19650179.8456;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM3(work_wait &parameters) {
  double actual_remaining = 
	11.6858 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 404710.9328 * parameters.total_wait_locks 
	- 0.0007 * parameters.mean_wait_of_all 
	+ 135089761.0129 * parameters.cpu_usage 
	+ 0.0014 * parameters.avg_work_of_same_past_second 
	- 0.0006 * parameters.avg_wait_of_same_past_second 
	- 0.0053 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 92494437.9245;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM4(work_wait &parameters) {
  double actual_remaining = 
	11.6858 * parameters.work_so_far 
	- 0.0648 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 7293.6961 * parameters.total_wait_locks 
	- 0.0007 * parameters.mean_wait_of_all 
	+ 439626193.2906 * parameters.cpu_usage 
	+ 0.0014 * parameters.avg_work_of_same_past_second 
	- 0.0006 * parameters.avg_wait_of_same_past_second 
	- 0.0053 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 325889223.4705;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM5(work_wait &parameters) {
  double actual_remaining = 
	11.6858 * parameters.work_so_far 
	- 0.0648 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 7293.6961 * parameters.total_wait_locks 
	- 0.0007 * parameters.mean_wait_of_all 
	+ 448744941.0606 * parameters.cpu_usage 
	+ 0.0014 * parameters.avg_work_of_same_past_second 
	- 0.0006 * parameters.avg_wait_of_same_past_second 
	- 0.0053 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 332985386.7051;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM6(work_wait &parameters) {
  double actual_remaining = 
	11.6858 * parameters.work_so_far 
	- 0.0618 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 7293.6961 * parameters.total_wait_locks 
	- 0.0007 * parameters.mean_wait_of_all 
	+ 399965648.387 * parameters.cpu_usage 
	+ 0.0014 * parameters.avg_work_of_same_past_second 
	- 0.0006 * parameters.avg_wait_of_same_past_second 
	- 0.0053 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 296076636.0202;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM7(work_wait &parameters) {
  double actual_remaining = 
	11.6858 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 7293.6961 * parameters.total_wait_locks 
	- 0.0007 * parameters.mean_wait_of_all 
	- 78264853.5892 * parameters.cpu_usage 
	+ 0.0014 * parameters.avg_work_of_same_past_second 
	- 0.0006 * parameters.avg_wait_of_same_past_second 
	- 0.0053 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 86814599.3511;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM8(work_wait &parameters) {
  double actual_remaining = 
	11.6858 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 7293.6961 * parameters.total_wait_locks 
	- 0.0007 * parameters.mean_wait_of_all 
	- 2707738.7551 * parameters.cpu_usage 
	+ 0.0014 * parameters.avg_work_of_same_past_second 
	- 0.0006 * parameters.avg_wait_of_same_past_second 
	- 0.0014 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 14252041.6842;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM9(work_wait &parameters) {
  double actual_remaining = 
	-3.5378 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 19884.0069 * parameters.total_wait_locks 
	+ 0.4993 * parameters.mean_wait_of_all 
	- 10812462.4819 * parameters.cpu_usage 
	+ 0.0226 * parameters.avg_work_of_same_past_second 
	- 0.0513 * parameters.avg_wait_of_same_past_second 
	+ 0.0142 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 8896701.3091;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM10(work_wait &parameters) {
  double actual_remaining = 
	-3.5378 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 19884.0069 * parameters.total_wait_locks 
	+ 0.4993 * parameters.mean_wait_of_all 
	- 10812462.4819 * parameters.cpu_usage 
	+ 0.0226 * parameters.avg_work_of_same_past_second 
	- 0.0218 * parameters.avg_wait_of_same_past_second 
	+ 0.0062 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 15148733.4438;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM11(work_wait &parameters) {
  double actual_remaining = 
	-3.5378 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 27156.3285 * parameters.total_wait_locks 
	+ 0.698 * parameters.mean_wait_of_all 
	- 15119650.7861 * parameters.cpu_usage 
	+ 0.0226 * parameters.avg_work_of_same_past_second 
	- 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 5175959.681;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM12(work_wait &parameters) {
  double actual_remaining = 
	-19.8719 * parameters.work_so_far 
	+ 0.0047 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 5170.2399 * parameters.total_wait_locks 
	- 0.8072 * parameters.mean_wait_of_all 
	- 2097918.7037 * parameters.cpu_usage 
	+ 0.0377 * parameters.avg_work_of_same_past_second 
	- 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 46324682.6187;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM13(work_wait &parameters) {
  double actual_remaining = 
	-97.4873 * parameters.work_so_far 
	+ 0.0076 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 110645.7861 * parameters.total_wait_locks 
	+ 690.8507 * parameters.mean_wait_of_all 
	- 539313600.1031 * parameters.cpu_usage 
	+ 1.2448 * parameters.avg_work_of_same_past_second 
	- 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 18875864892.3485;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM14(work_wait &parameters) {
  double actual_remaining = 
	-97.4873 * parameters.work_so_far 
	+ 0.0076 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 110645.7861 * parameters.total_wait_locks 
	+ 824.3898 * parameters.mean_wait_of_all 
	- 539313600.1031 * parameters.cpu_usage 
	+ 1.2448 * parameters.avg_work_of_same_past_second 
	- 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 22627214164.4788;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM15(work_wait &parameters) {
  double actual_remaining = 
	-97.4873 * parameters.work_so_far 
	+ 0.0076 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 110645.7861 * parameters.total_wait_locks 
	+ 827.1508 * parameters.mean_wait_of_all 
	- 645341488.8016 * parameters.cpu_usage 
	+ 1.4311 * parameters.avg_work_of_same_past_second 
	- 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 22611971280.5913;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM16(work_wait &parameters) {
  double actual_remaining = 
	-106.7418 * parameters.work_so_far 
	+ 0.0076 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 41723.1135 * parameters.total_wait_locks 
	+ 495.6487 * parameters.mean_wait_of_all 
	- 384172707.1444 * parameters.cpu_usage 
	+ 1.0085 * parameters.avg_work_of_same_past_second 
	- 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 13548676316.2931;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM17(work_wait &parameters) {
  double actual_remaining = 
	-30.3922 * parameters.work_so_far 
	+ 0.0076 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 5170.2399 * parameters.total_wait_locks 
	- 53.0593 * parameters.mean_wait_of_all 
	- 2097918.7037 * parameters.cpu_usage 
	+ 0.0377 * parameters.avg_work_of_same_past_second 
	- 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 1517626454.1345;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM18(work_wait &parameters) {
  double actual_remaining = 
	-145.2616 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 11577.036 * parameters.total_wait_locks 
	+ 4.8113 * parameters.mean_wait_of_all 
	- 1164235.6769 * parameters.cpu_usage 
	- 0.0909 * parameters.avg_work_of_same_past_second 
	- 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.0069 * parameters.max_latency_of_same_last_50 
	- 114609164.9032;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM19(work_wait &parameters) {
  double actual_remaining = 
	-273.9262 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 11577.036 * parameters.total_wait_locks 
	+ 5.5456 * parameters.mean_wait_of_all 
	- 1164235.6769 * parameters.cpu_usage 
	- 0.0909 * parameters.avg_work_of_same_past_second 
	- 0.0004 * parameters.avg_wait_of_same_past_second 
	- 0.0223 * parameters.avg_latency_of_same_last_20 
	+ 0.0241 * parameters.max_latency_of_same_last_50 
	- 130424930.0949;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM20(work_wait &parameters) {
  double actual_remaining = 
	-737.7844 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 3395925.4984 * parameters.total_wait_locks 
	+ 5.5456 * parameters.mean_wait_of_all 
	- 1164235.6769 * parameters.cpu_usage 
	- 0.0909 * parameters.avg_work_of_same_past_second 
	- 0.0004 * parameters.avg_wait_of_same_past_second 
	- 0.0223 * parameters.avg_latency_of_same_last_20 
	+ 0.0241 * parameters.max_latency_of_same_last_50 
	- 1487654.0318;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM21(work_wait &parameters) {
  double actual_remaining = 
	-737.7844 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 1522799.2629 * parameters.total_wait_locks 
	+ 5.5456 * parameters.mean_wait_of_all 
	- 1164235.6769 * parameters.cpu_usage 
	- 0.0909 * parameters.avg_work_of_same_past_second 
	- 0.0004 * parameters.avg_wait_of_same_past_second 
	- 0.0223 * parameters.avg_latency_of_same_last_20 
	+ 0.0241 * parameters.max_latency_of_same_last_50 
	- 64279494.6445;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM22(work_wait &parameters) {
  double actual_remaining = 
	-737.7844 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 11577.036 * parameters.total_wait_locks 
	+ 7.7972 * parameters.mean_wait_of_all 
	+ 166811838.7466 * parameters.cpu_usage 
	- 0.0909 * parameters.avg_work_of_same_past_second 
	- 0.0004 * parameters.avg_wait_of_same_past_second 
	- 0.0223 * parameters.avg_latency_of_same_last_20 
	+ 0.0241 * parameters.max_latency_of_same_last_50 
	- 315706717.8548;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM23(work_wait &parameters) {
  double actual_remaining = 
	-987.5542 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 11577.036 * parameters.total_wait_locks 
	+ 5.5456 * parameters.mean_wait_of_all 
	- 1164235.6769 * parameters.cpu_usage 
	- 0.0909 * parameters.avg_work_of_same_past_second 
	- 0.0004 * parameters.avg_wait_of_same_past_second 
	- 0.0223 * parameters.avg_latency_of_same_last_20 
	+ 0.0241 * parameters.max_latency_of_same_last_50 
	- 112946078.0859;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM24(work_wait &parameters) {
  double actual_remaining = 
	-595.4693 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 11577.036 * parameters.total_wait_locks 
	+ 4.6743 * parameters.mean_wait_of_all 
	- 1164235.6769 * parameters.cpu_usage 
	- 6.3304 * parameters.avg_work_of_same_past_second 
	- 0.0004 * parameters.avg_wait_of_same_past_second 
	- 0.0166 * parameters.avg_latency_of_same_last_20 
	+ 0.0953 * parameters.max_latency_of_same_last_50 
	- 78689169.1997;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM25(work_wait &parameters) {
  double actual_remaining = 
	871.906 * parameters.work_so_far 
	+ 0.0524 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 13329.4673 * parameters.total_wait_locks 
	+ 0.0489 * parameters.mean_wait_of_all 
	- 1164235.6769 * parameters.cpu_usage 
	- 0.1692 * parameters.avg_work_of_same_past_second 
	+ 0.1393 * parameters.avg_wait_of_same_past_second 
	- 0.0034 * parameters.avg_latency_of_same_last_20 
	- 0.0166 * parameters.max_latency_of_same_last_50 
	+ 10468232.8439;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM26(work_wait &parameters) {
  double actual_remaining = 
	55.7475 * parameters.work_so_far 
	+ 0.0016 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 13329.4673 * parameters.total_wait_locks 
	+ 0.0489 * parameters.mean_wait_of_all 
	- 1164235.6769 * parameters.cpu_usage 
	- 0.1358 * parameters.avg_work_of_same_past_second 
	+ 0.0034 * parameters.avg_wait_of_same_past_second 
	- 0.0023 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 13677794.7913;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM27(work_wait &parameters) {
  double actual_remaining = 
	-151.123 * parameters.work_so_far 
	- 0.0225 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 17803.6765 * parameters.total_wait_locks 
	+ 0.0489 * parameters.mean_wait_of_all 
	- 1164235.6769 * parameters.cpu_usage 
	- 0.067 * parameters.avg_work_of_same_past_second 
	- 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 37746713.5133;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM28(work_wait &parameters) {
  double actual_remaining = 
	132.8075 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 47428.2322 * parameters.total_wait_locks 
	- 0.1362 * parameters.mean_wait_of_all 
	- 117433.8206 * parameters.cpu_usage 
	- 1.7353 * parameters.avg_work_of_same_past_second 
	- 0.0129 * parameters.avg_wait_of_same_past_second 
	+ 0.0005 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 35312160.1977;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM29(work_wait &parameters) {
  double actual_remaining = 
	165.7049 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 469604.7575 * parameters.total_wait_locks 
	- 1.3878 * parameters.mean_wait_of_all 
	- 117433.8206 * parameters.cpu_usage 
	+ 1.8284 * parameters.avg_work_of_same_past_second 
	- 0.0129 * parameters.avg_wait_of_same_past_second 
	+ 0.0005 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 22774804.4289;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM30(work_wait &parameters) {
  double actual_remaining = 
	165.7049 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 526731.0589 * parameters.total_wait_locks 
	- 1.686 * parameters.mean_wait_of_all 
	- 117433.8206 * parameters.cpu_usage 
	+ 1.099 * parameters.avg_work_of_same_past_second 
	- 0.0129 * parameters.avg_wait_of_same_past_second 
	+ 0.0005 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 48427198.1091;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM31(work_wait &parameters) {
  double actual_remaining = 
	165.7049 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 526731.0589 * parameters.total_wait_locks 
	- 1.686 * parameters.mean_wait_of_all 
	- 117433.8206 * parameters.cpu_usage 
	+ 1.099 * parameters.avg_work_of_same_past_second 
	- 0.0129 * parameters.avg_wait_of_same_past_second 
	+ 0.0005 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 46469333.0202;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM32(work_wait &parameters) {
  double actual_remaining = 
	248.8691 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 488149.1744 * parameters.total_wait_locks 
	- 1.5494 * parameters.mean_wait_of_all 
	- 117433.8206 * parameters.cpu_usage 
	+ 1.099 * parameters.avg_work_of_same_past_second 
	- 0.0129 * parameters.avg_wait_of_same_past_second 
	+ 0.0005 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 35284103.0701;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM33(work_wait &parameters) {
  double actual_remaining = 
	95.2201 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 55736.8347 * parameters.total_wait_locks 
	- 0.1623 * parameters.mean_wait_of_all 
	- 117433.8206 * parameters.cpu_usage 
	- 0.0195 * parameters.avg_work_of_same_past_second 
	- 0.0153 * parameters.avg_wait_of_same_past_second 
	+ 0.0005 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 16163296.5647;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM34(work_wait &parameters) {
  double actual_remaining = 
	89.9011 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 45151.3438 * parameters.total_wait_locks 
	- 0.1217 * parameters.mean_wait_of_all 
	- 117433.8206 * parameters.cpu_usage 
	- 0.0195 * parameters.avg_work_of_same_past_second 
	- 0.0116 * parameters.avg_wait_of_same_past_second 
	+ 0.0005 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 12127711.2855;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM35(work_wait &parameters) {
  double actual_remaining = 
	3.2224 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 2281.1587 * parameters.total_wait_locks 
	+ 0.0005 * parameters.mean_wait_of_all 
	- 117433.8206 * parameters.cpu_usage 
	- 0.0128 * parameters.avg_work_of_same_past_second 
	- 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0005 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 12929839.8263;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM36(work_wait &parameters) {
  double actual_remaining = 
	0.1078 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 3582.4847 * parameters.total_wait_locks 
	+ 0.0039 * parameters.mean_wait_of_all 
	- 117433.8206 * parameters.cpu_usage 
	- 0.0197 * parameters.avg_work_of_same_past_second 
	+ 0.0174 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.0003 * parameters.max_latency_of_same_last_50 
	+ 13211617.723;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM37(work_wait &parameters) {
  double actual_remaining = 
	630.5892 * parameters.work_so_far 
	- 0.0021 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 20129.1495 * parameters.total_wait_locks 
	+ 0.0306 * parameters.mean_wait_of_all 
	+ 71882759.3269 * parameters.cpu_usage 
	- 0.5944 * parameters.avg_work_of_same_past_second 
	- 0.0067 * parameters.avg_wait_of_same_past_second 
	- 0.0026 * parameters.avg_latency_of_same_last_20 
	+ 0.0007 * parameters.max_latency_of_same_last_50 
	- 46959627.5677;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM38(work_wait &parameters) {
  double actual_remaining = 
	169.6187 * parameters.work_so_far 
	- 0.0044 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 20129.1495 * parameters.total_wait_locks 
	+ 0.0306 * parameters.mean_wait_of_all 
	+ 17084152.1539 * parameters.cpu_usage 
	- 0.1777 * parameters.avg_work_of_same_past_second 
	- 0.0136 * parameters.avg_wait_of_same_past_second 
	- 0.0026 * parameters.avg_latency_of_same_last_20 
	+ 0.0007 * parameters.max_latency_of_same_last_50 
	+ 31767.1251;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM39(work_wait &parameters) {
  double actual_remaining = 
	0.1078 * parameters.work_so_far 
	+ 0.0565 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 342691.805 * parameters.total_wait_locks 
	+ 0.0306 * parameters.mean_wait_of_all 
	- 193426608.1624 * parameters.cpu_usage 
	- 0.1629 * parameters.avg_work_of_same_past_second 
	- 0.0028 * parameters.avg_wait_of_same_past_second 
	- 0.0491 * parameters.avg_latency_of_same_last_20 
	+ 0.0007 * parameters.max_latency_of_same_last_50 
	+ 181315465.6497;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM40(work_wait &parameters) {
  double actual_remaining = 
	0.1078 * parameters.work_so_far 
	+ 0.1038 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 299216.6401 * parameters.total_wait_locks 
	+ 0.0306 * parameters.mean_wait_of_all 
	- 81350474.0014 * parameters.cpu_usage 
	- 0.1629 * parameters.avg_work_of_same_past_second 
	- 0.0028 * parameters.avg_wait_of_same_past_second 
	- 0.0491 * parameters.avg_latency_of_same_last_20 
	+ 0.0007 * parameters.max_latency_of_same_last_50 
	+ 92065486.4918;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM41(work_wait &parameters) {
  double actual_remaining = 
	0.1078 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 257023.3838 * parameters.total_wait_locks 
	+ 0.0306 * parameters.mean_wait_of_all 
	- 117433.8206 * parameters.cpu_usage 
	- 0.1629 * parameters.avg_work_of_same_past_second 
	- 0.0028 * parameters.avg_wait_of_same_past_second 
	- 0.0739 * parameters.avg_latency_of_same_last_20 
	+ 0.0007 * parameters.max_latency_of_same_last_50 
	+ 10868158.5121;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM42(work_wait &parameters) {
  double actual_remaining = 
	0.1078 * parameters.work_so_far 
	- 0.0013 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 4089.5207 * parameters.total_wait_locks 
	+ 0.027 * parameters.mean_wait_of_all 
	- 117433.8206 * parameters.cpu_usage 
	- 0.0184 * parameters.avg_work_of_same_past_second 
	- 0.0025 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.0014 * parameters.max_latency_of_same_last_50 
	+ 18262003.7278;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM43(work_wait &parameters) {
  double actual_remaining = 
	0.1078 * parameters.work_so_far 
	- 0.0013 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 190725.7545 * parameters.total_wait_locks 
	+ 0.5206 * parameters.mean_wait_of_all 
	- 117433.8206 * parameters.cpu_usage 
	- 0.0184 * parameters.avg_work_of_same_past_second 
	- 0.0025 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.0131 * parameters.max_latency_of_same_last_50 
	+ 20803435.5642;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM44(work_wait &parameters) {
  double actual_remaining = 
	0.1078 * parameters.work_so_far 
	- 0.0013 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 204539.3553 * parameters.total_wait_locks 
	+ 0.5462 * parameters.mean_wait_of_all 
	- 117433.8206 * parameters.cpu_usage 
	- 0.0184 * parameters.avg_work_of_same_past_second 
	- 0.0025 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.007 * parameters.max_latency_of_same_last_50 
	+ 32087430.5255;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM45(work_wait &parameters) {
  double actual_remaining = 
	0.1078 * parameters.work_so_far 
	- 0.0013 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 550637.5778 * parameters.total_wait_locks 
	+ 0.657 * parameters.mean_wait_of_all 
	- 117433.8206 * parameters.cpu_usage 
	- 0.0184 * parameters.avg_work_of_same_past_second 
	- 0.0025 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.007 * parameters.max_latency_of_same_last_50 
	+ 93972396.9767;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM46(work_wait &parameters) {
  double actual_remaining = 
	560.3421 * parameters.work_so_far 
	- 0.003 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 239143.0255 * parameters.total_wait_locks 
	- 0.9678 * parameters.mean_wait_of_all 
	- 117433.8206 * parameters.cpu_usage 
	- 0.0184 * parameters.avg_work_of_same_past_second 
	- 0.0512 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.0031 * parameters.max_latency_of_same_last_50 
	+ 20007540.4725;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM47(work_wait &parameters) {
  double actual_remaining = 
	560.3421 * parameters.work_so_far 
	- 0.003 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 239143.0255 * parameters.total_wait_locks 
	+ 27.1936 * parameters.mean_wait_of_all 
	- 117433.8206 * parameters.cpu_usage 
	- 0.0184 * parameters.avg_work_of_same_past_second 
	- 0.0512 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.0031 * parameters.max_latency_of_same_last_50 
	- 990821436.4021;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM48(work_wait &parameters) {
  double actual_remaining = 
	560.3421 * parameters.work_so_far 
	- 0.003 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 239143.0255 * parameters.total_wait_locks 
	+ 33.8198 * parameters.mean_wait_of_all 
	- 117433.8206 * parameters.cpu_usage 
	- 0.0184 * parameters.avg_work_of_same_past_second 
	- 0.0512 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.0031 * parameters.max_latency_of_same_last_50 
	- 1227590190.7727;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM49(work_wait &parameters) {
  double actual_remaining = 
	18277.1385 * parameters.work_so_far 
	- 0.003 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 454608.7383 * parameters.total_wait_locks 
	- 1.8797 * parameters.mean_wait_of_all 
	- 117433.8206 * parameters.cpu_usage 
	+ 1.7053 * parameters.avg_work_of_same_past_second 
	- 0.0957 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.0031 * parameters.max_latency_of_same_last_50 
	- 562782277.6979;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM50(work_wait &parameters) {
  double actual_remaining = 
	22325.1954 * parameters.work_so_far 
	- 0.003 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 454608.7383 * parameters.total_wait_locks 
	- 1.8797 * parameters.mean_wait_of_all 
	- 117433.8206 * parameters.cpu_usage 
	+ 1.796 * parameters.avg_work_of_same_past_second 
	- 0.0957 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.0031 * parameters.max_latency_of_same_last_50 
	- 686992177.1505;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM51(work_wait &parameters) {
  double actual_remaining = 
	0.1078 * parameters.work_so_far 
	- 0.003 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 4089.5207 * parameters.total_wait_locks 
	+ 0.027 * parameters.mean_wait_of_all 
	- 117433.8206 * parameters.cpu_usage 
	- 0.0184 * parameters.avg_work_of_same_past_second 
	- 0.0025 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.0031 * parameters.max_latency_of_same_last_50 
	+ 18459379.004;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM52(work_wait &parameters) {
  double actual_remaining = 
	0.1078 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 162599.9004 * parameters.total_wait_locks 
	+ 0.0123 * parameters.mean_wait_of_all 
	- 117433.8206 * parameters.cpu_usage 
	- 0.0471 * parameters.avg_work_of_same_past_second 
	- 0.036 * parameters.avg_wait_of_same_past_second 
	+ 0.0016 * parameters.avg_latency_of_same_last_20 
	+ 0.0003 * parameters.max_latency_of_same_last_50 
	- 255995.8408;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM53(work_wait &parameters) {
  double actual_remaining = 
	0.1078 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 7482.4762 * parameters.total_wait_locks 
	+ 0.0874 * parameters.mean_wait_of_all 
	- 117433.8206 * parameters.cpu_usage 
	- 0.0939 * parameters.avg_work_of_same_past_second 
	- 0.0009 * parameters.avg_wait_of_same_past_second 
	- 0.0219 * parameters.avg_latency_of_same_last_20 
	+ 0.0003 * parameters.max_latency_of_same_last_50 
	+ 22608496.9783;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM54(work_wait &parameters) {
  double actual_remaining = 
	0.1078 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 7482.4762 * parameters.total_wait_locks 
	+ 0.0282 * parameters.mean_wait_of_all 
	- 117433.8206 * parameters.cpu_usage 
	- 1.8775 * parameters.avg_work_of_same_past_second 
	- 0.0009 * parameters.avg_wait_of_same_past_second 
	+ 0.0056 * parameters.avg_latency_of_same_last_20 
	+ 0.0003 * parameters.max_latency_of_same_last_50 
	+ 72484155.1817;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM55(work_wait &parameters) {
  double actual_remaining = 
	2.0286 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 2599.6945 * parameters.total_wait_locks 
	+ 0.0018 * parameters.mean_wait_of_all 
	- 117433.8206 * parameters.cpu_usage 
	- 0.0081 * parameters.avg_work_of_same_past_second 
	- 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.0001 * parameters.max_latency_of_same_last_50 
	+ 18818887.534;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM56(work_wait &parameters) {
  double actual_remaining = 
	80.6912 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 2599.6945 * parameters.total_wait_locks 
	+ 1.0944 * parameters.mean_wait_of_all 
	- 117433.8206 * parameters.cpu_usage 
	- 0.0081 * parameters.avg_work_of_same_past_second 
	- 0.0571 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.0001 * parameters.max_latency_of_same_last_50 
	- 10170518.7596;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM57(work_wait &parameters) {
  double actual_remaining = 
	329.2038 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 2599.6945 * parameters.total_wait_locks 
	+ 1.3319 * parameters.mean_wait_of_all 
	- 117433.8206 * parameters.cpu_usage 
	- 0.0081 * parameters.avg_work_of_same_past_second 
	- 0.0571 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.0358 * parameters.max_latency_of_same_last_50 
	- 67448319.5854;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM58(work_wait &parameters) {
  double actual_remaining = 
	5.3857 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 2599.6945 * parameters.total_wait_locks 
	+ 0.0018 * parameters.mean_wait_of_all 
	- 117433.8206 * parameters.cpu_usage 
	- 0.0081 * parameters.avg_work_of_same_past_second 
	- 0.0477 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.0001 * parameters.max_latency_of_same_last_50 
	+ 40231126.6238;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM59(work_wait &parameters) {
  double actual_remaining = 
	5.3857 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 2599.6945 * parameters.total_wait_locks 
	+ 0.0018 * parameters.mean_wait_of_all 
	- 117433.8206 * parameters.cpu_usage 
	- 0.0081 * parameters.avg_work_of_same_past_second 
	- 0.0629 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.0001 * parameters.max_latency_of_same_last_50 
	+ 39716533.3492;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM60(work_wait &parameters) {
  double actual_remaining = 
	0.2018 * parameters.work_so_far 
	- 0.0018 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 416224.2928 * parameters.total_wait_locks 
	- 1.7354 * parameters.mean_wait_of_all 
	+ 4444858.5646 * parameters.cpu_usage 
	- 2.1084 * parameters.avg_work_of_same_past_second 
	+ 0.4682 * parameters.avg_wait_of_same_past_second 
	+ 0.0041 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 61843217.4121;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM61(work_wait &parameters) {
  double actual_remaining = 
	0.2018 * parameters.work_so_far 
	- 0.0018 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 543156.7626 * parameters.total_wait_locks 
	- 2.1633 * parameters.mean_wait_of_all 
	+ 4444858.5646 * parameters.cpu_usage 
	- 6.8384 * parameters.avg_work_of_same_past_second 
	+ 1.0045 * parameters.avg_wait_of_same_past_second 
	+ 0.0041 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 137507846.5884;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM62(work_wait &parameters) {
  double actual_remaining = 
	0.2018 * parameters.work_so_far 
	- 0.3302 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 483730.6239 * parameters.total_wait_locks 
	- 2.1411 * parameters.mean_wait_of_all 
	+ 4444858.5646 * parameters.cpu_usage 
	+ 4.7997 * parameters.avg_work_of_same_past_second 
	- 0.0475 * parameters.avg_wait_of_same_past_second 
	+ 0.0041 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 17549806.477;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM63(work_wait &parameters) {
  double actual_remaining = 
	0.2018 * parameters.work_so_far 
	- 0.2731 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 483730.6239 * parameters.total_wait_locks 
	- 2.1411 * parameters.mean_wait_of_all 
	+ 4444858.5646 * parameters.cpu_usage 
	+ 21.2812 * parameters.avg_work_of_same_past_second 
	- 0.0475 * parameters.avg_wait_of_same_past_second 
	+ 0.0041 * parameters.avg_latency_of_same_last_20 
	+ 0.0138 * parameters.max_latency_of_same_last_50 
	- 414488200.7692;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM64(work_wait &parameters) {
  double actual_remaining = 
	0.2018 * parameters.work_so_far 
	- 0.0018 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 483730.6239 * parameters.total_wait_locks 
	- 2.1411 * parameters.mean_wait_of_all 
	+ 4444858.5646 * parameters.cpu_usage 
	+ 4.7997 * parameters.avg_work_of_same_past_second 
	- 0.0475 * parameters.avg_wait_of_same_past_second 
	+ 0.0041 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 32393697.9553;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM65(work_wait &parameters) {
  double actual_remaining = 
	0.2018 * parameters.work_so_far 
	+ 0.4113 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 57445.5886 * parameters.total_wait_locks 
	- 0.4505 * parameters.mean_wait_of_all 
	+ 4444858.5646 * parameters.cpu_usage 
	+ 0.001 * parameters.avg_work_of_same_past_second 
	- 0.4459 * parameters.avg_wait_of_same_past_second 
	+ 0.0041 * parameters.avg_latency_of_same_last_20 
	+ 0.0234 * parameters.max_latency_of_same_last_50 
	+ 164742234.9611;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM66(work_wait &parameters) {
  double actual_remaining = 
	0.2018 * parameters.work_so_far 
	+ 0.6773 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 57445.5886 * parameters.total_wait_locks 
	- 1.5483 * parameters.mean_wait_of_all 
	+ 4444858.5646 * parameters.cpu_usage 
	+ 0.001 * parameters.avg_work_of_same_past_second 
	- 0.4174 * parameters.avg_wait_of_same_past_second 
	+ 0.0041 * parameters.avg_latency_of_same_last_20 
	+ 0.0218 * parameters.max_latency_of_same_last_50 
	+ 234481086.1018;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM67(work_wait &parameters) {
  double actual_remaining = 
	0.2018 * parameters.work_so_far 
	+ 0.0317 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 57445.5886 * parameters.total_wait_locks 
	- 0.3453 * parameters.mean_wait_of_all 
	+ 4444858.5646 * parameters.cpu_usage 
	+ 0.001 * parameters.avg_work_of_same_past_second 
	- 0.0317 * parameters.avg_wait_of_same_past_second 
	+ 0.0041 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 35750882.8296;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM68(work_wait &parameters) {
  double actual_remaining = 
	0.2018 * parameters.work_so_far 
	- 0.0022 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 12480.0692 * parameters.total_wait_locks 
	- 0.0785 * parameters.mean_wait_of_all 
	+ 4444858.5646 * parameters.cpu_usage 
	+ 0.001 * parameters.avg_work_of_same_past_second 
	- 0.0147 * parameters.avg_wait_of_same_past_second 
	+ 0.0041 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 21156593.1137;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM69(work_wait &parameters) {
  double actual_remaining = 
	0.2018 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 114084.8721 * parameters.total_wait_locks 
	+ 0.2917 * parameters.mean_wait_of_all 
	+ 32149650.3364 * parameters.cpu_usage 
	+ 0.001 * parameters.avg_work_of_same_past_second 
	- 0.0108 * parameters.avg_wait_of_same_past_second 
	+ 0.0191 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 8598782.3037;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM70(work_wait &parameters) {
  double actual_remaining = 
	22.0942 * parameters.work_so_far 
	- 0.055 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 185969.7824 * parameters.total_wait_locks 
	+ 0.4902 * parameters.mean_wait_of_all 
	+ 47629037.9612 * parameters.cpu_usage 
	+ 0.001 * parameters.avg_work_of_same_past_second 
	- 0.0108 * parameters.avg_wait_of_same_past_second 
	+ 0.0888 * parameters.avg_latency_of_same_last_20 
	+ 0.0096 * parameters.max_latency_of_same_last_50 
	- 14263770.9057;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM71(work_wait &parameters) {
  double actual_remaining = 
	22.0942 * parameters.work_so_far 
	- 0.055 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 185969.7824 * parameters.total_wait_locks 
	+ 0.4902 * parameters.mean_wait_of_all 
	+ 47629037.9612 * parameters.cpu_usage 
	+ 0.001 * parameters.avg_work_of_same_past_second 
	- 0.0108 * parameters.avg_wait_of_same_past_second 
	+ 0.0888 * parameters.avg_latency_of_same_last_20 
	+ 0.0096 * parameters.max_latency_of_same_last_50 
	- 16672872.3347;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM72(work_wait &parameters) {
  double actual_remaining = 
	-182.7347 * parameters.work_so_far 
	- 0.0533 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 185969.7824 * parameters.total_wait_locks 
	+ 0.4902 * parameters.mean_wait_of_all 
	+ 47629037.9612 * parameters.cpu_usage 
	+ 0.001 * parameters.avg_work_of_same_past_second 
	- 0.0108 * parameters.avg_wait_of_same_past_second 
	+ 0.1035 * parameters.avg_latency_of_same_last_20 
	+ 0.04 * parameters.max_latency_of_same_last_50 
	- 55388228.9918;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM73(work_wait &parameters) {
  double actual_remaining = 
	0.2018 * parameters.work_so_far 
	- 0.0533 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 185969.7824 * parameters.total_wait_locks 
	+ 0.4902 * parameters.mean_wait_of_all 
	+ 47629037.9612 * parameters.cpu_usage 
	+ 0.001 * parameters.avg_work_of_same_past_second 
	- 0.0108 * parameters.avg_wait_of_same_past_second 
	+ 0.1035 * parameters.avg_latency_of_same_last_20 
	+ 0.0458 * parameters.max_latency_of_same_last_50 
	- 69161453.8115;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM74(work_wait &parameters) {
  double actual_remaining = 
	0.2018 * parameters.work_so_far 
	- 0.0517 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 185969.7824 * parameters.total_wait_locks 
	+ 0.4902 * parameters.mean_wait_of_all 
	+ 47629037.9612 * parameters.cpu_usage 
	+ 0.001 * parameters.avg_work_of_same_past_second 
	- 0.0108 * parameters.avg_wait_of_same_past_second 
	+ 0.0835 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 30105822.7925;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM75(work_wait &parameters) {
  double actual_remaining = 
	0.2018 * parameters.work_so_far 
	- 0.0517 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 185969.7824 * parameters.total_wait_locks 
	+ 0.4902 * parameters.mean_wait_of_all 
	+ 47629037.9612 * parameters.cpu_usage 
	+ 0.001 * parameters.avg_work_of_same_past_second 
	- 0.0108 * parameters.avg_wait_of_same_past_second 
	+ 0.0835 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 51351230.8309;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM76(work_wait &parameters) {
  double actual_remaining = 
	0.2018 * parameters.work_so_far 
	- 0.0502 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 185969.7824 * parameters.total_wait_locks 
	+ 0.4902 * parameters.mean_wait_of_all 
	+ 47629037.9612 * parameters.cpu_usage 
	+ 0.001 * parameters.avg_work_of_same_past_second 
	- 0.0108 * parameters.avg_wait_of_same_past_second 
	+ 0.0835 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 48000935.1153;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM77(work_wait &parameters) {
  double actual_remaining = 
	0.2018 * parameters.work_so_far 
	- 0.0517 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 185969.7824 * parameters.total_wait_locks 
	+ 0.4902 * parameters.mean_wait_of_all 
	+ 47629037.9612 * parameters.cpu_usage 
	+ 0.001 * parameters.avg_work_of_same_past_second 
	- 0.0108 * parameters.avg_wait_of_same_past_second 
	+ 0.0835 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 43567741.4122;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM78(work_wait &parameters) {
  double actual_remaining = 
	0.9725 * parameters.work_so_far 
	- 0.0064 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 135437.3359 * parameters.total_wait_locks 
	+ 0.5402 * parameters.mean_wait_of_all 
	+ 192377.9897 * parameters.cpu_usage 
	+ 0.001 * parameters.avg_work_of_same_past_second 
	- 0.001 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 25223068.9959;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM79(work_wait &parameters) {
  double actual_remaining = 
	1.8637 * parameters.work_so_far 
	- 0.0085 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 7424.2359 * parameters.total_wait_locks 
	+ 0.303 * parameters.mean_wait_of_all 
	+ 1704102.5953 * parameters.cpu_usage 
	+ 0.001 * parameters.avg_work_of_same_past_second 
	- 0.0013 * parameters.avg_wait_of_same_past_second 
	+ 0.0395 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 14376432.5715;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM80(work_wait &parameters) {
  double actual_remaining = 
	1.8637 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 14170.1952 * parameters.total_wait_locks 
	+ 0.0596 * parameters.mean_wait_of_all 
	- 898434417.5038 * parameters.cpu_usage 
	+ 0.001 * parameters.avg_work_of_same_past_second 
	- 0.0013 * parameters.avg_wait_of_same_past_second 
	+ 0.0044 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 923097551.9808;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM81(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	+ 0.0013 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 11415.7867 * parameters.total_wait_locks 
	+ 0.0813 * parameters.mean_wait_of_all 
	+ 2949.971 * parameters.cpu_usage 
	- 0.0306 * parameters.avg_work_of_same_past_second 
	- 0.0497 * parameters.avg_wait_of_same_past_second 
	- 0.0053 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 49909708.3486;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM82(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	+ 0.1069 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 465844.2915 * parameters.total_wait_locks 
	- 46.7835 * parameters.mean_wait_of_all 
	+ 2949.971 * parameters.cpu_usage 
	- 68.8868 * parameters.avg_work_of_same_past_second 
	+ 0.011 * parameters.avg_wait_of_same_past_second 
	- 0.0408 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 8353517501.8236;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM83(work_wait &parameters) {
  double actual_remaining = 
	46.9391 * parameters.work_so_far 
	+ 0.1069 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 465844.2915 * parameters.total_wait_locks 
	- 46.7835 * parameters.mean_wait_of_all 
	+ 2949.971 * parameters.cpu_usage 
	- 68.8868 * parameters.avg_work_of_same_past_second 
	+ 0.011 * parameters.avg_wait_of_same_past_second 
	- 0.0408 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 8347710044.6873;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM84(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	+ 0.0607 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 271517.517 * parameters.total_wait_locks 
	- 62.0792 * parameters.mean_wait_of_all 
	+ 2949.971 * parameters.cpu_usage 
	- 68.0906 * parameters.avg_work_of_same_past_second 
	+ 0.011 * parameters.avg_wait_of_same_past_second 
	- 0.0408 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 10386903521.9708;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM85(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	+ 0.0607 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 5911008.6029 * parameters.total_wait_locks 
	- 77.362 * parameters.mean_wait_of_all 
	+ 2949.971 * parameters.cpu_usage 
	- 80.5652 * parameters.avg_work_of_same_past_second 
	+ 0.011 * parameters.avg_wait_of_same_past_second 
	- 0.0408 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 8840959483.2879;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM86(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	+ 0.0607 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 5911008.6029 * parameters.total_wait_locks 
	- 77.362 * parameters.mean_wait_of_all 
	+ 2949.971 * parameters.cpu_usage 
	- 80.2595 * parameters.avg_work_of_same_past_second 
	+ 0.011 * parameters.avg_wait_of_same_past_second 
	- 0.0408 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 8835191989.7263;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM87(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	+ 0.0607 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 6980219.8312 * parameters.total_wait_locks 
	- 77.362 * parameters.mean_wait_of_all 
	+ 2949.971 * parameters.cpu_usage 
	- 85.7632 * parameters.avg_work_of_same_past_second 
	+ 0.011 * parameters.avg_wait_of_same_past_second 
	- 0.0408 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 8293882538.2556;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM88(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.0226 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 465844.2915 * parameters.total_wait_locks 
	- 31.9812 * parameters.mean_wait_of_all 
	+ 2949.971 * parameters.cpu_usage 
	- 39.1784 * parameters.avg_work_of_same_past_second 
	+ 0.011 * parameters.avg_wait_of_same_past_second 
	- 0.0408 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 5645619604.3103;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM89(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.1554 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 1144829.1484 * parameters.total_wait_locks 
	- 32.0592 * parameters.mean_wait_of_all 
	+ 2949.971 * parameters.cpu_usage 
	- 39.1784 * parameters.avg_work_of_same_past_second 
	+ 0.011 * parameters.avg_wait_of_same_past_second 
	- 0.0408 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 6087978093.3002;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM90(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.158 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 1144829.1484 * parameters.total_wait_locks 
	- 31.9812 * parameters.mean_wait_of_all 
	+ 2949.971 * parameters.cpu_usage 
	- 39.1784 * parameters.avg_work_of_same_past_second 
	+ 0.011 * parameters.avg_wait_of_same_past_second 
	- 0.0408 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 6077025215.7792;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM91(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.1594 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 1304590.2912 * parameters.total_wait_locks 
	- 31.9812 * parameters.mean_wait_of_all 
	+ 2949.971 * parameters.cpu_usage 
	- 39.1784 * parameters.avg_work_of_same_past_second 
	+ 0.011 * parameters.avg_wait_of_same_past_second 
	- 0.0408 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 6175031631.9343;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM92(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.0226 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 465844.2915 * parameters.total_wait_locks 
	- 31.9812 * parameters.mean_wait_of_all 
	+ 2949.971 * parameters.cpu_usage 
	- 39.1784 * parameters.avg_work_of_same_past_second 
	+ 0.011 * parameters.avg_wait_of_same_past_second 
	- 0.0408 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 5637702462.2144;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM93(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.0273 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 465844.2915 * parameters.total_wait_locks 
	- 31.9812 * parameters.mean_wait_of_all 
	+ 2949.971 * parameters.cpu_usage 
	- 39.1784 * parameters.avg_work_of_same_past_second 
	+ 0.011 * parameters.avg_wait_of_same_past_second 
	- 0.0408 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 5626646899.3456;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM94(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	+ 0.0025 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 402223.8435 * parameters.total_wait_locks 
	+ 1.3947 * parameters.mean_wait_of_all 
	+ 2949.971 * parameters.cpu_usage 
	+ 0.9753 * parameters.avg_work_of_same_past_second 
	+ 0.011 * parameters.avg_wait_of_same_past_second 
	- 0.0293 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 77668264.4943;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM95(work_wait &parameters) {
  double actual_remaining = 
	-552.5621 * parameters.work_so_far 
	+ 0.0025 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 985800.7802 * parameters.total_wait_locks 
	+ 3.2272 * parameters.mean_wait_of_all 
	+ 2949.971 * parameters.cpu_usage 
	+ 0.9753 * parameters.avg_work_of_same_past_second 
	+ 0.011 * parameters.avg_wait_of_same_past_second 
	- 0.0587 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 272371454.4855;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM96(work_wait &parameters) {
  double actual_remaining = 
	415.2021 * parameters.work_so_far 
	+ 0.0025 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 992324.3294 * parameters.total_wait_locks 
	+ 3.2272 * parameters.mean_wait_of_all 
	+ 2949.971 * parameters.cpu_usage 
	+ 0.9753 * parameters.avg_work_of_same_past_second 
	+ 0.011 * parameters.avg_wait_of_same_past_second 
	- 0.0587 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 239752908.3099;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM97(work_wait &parameters) {
  double actual_remaining = 
	642.9113 * parameters.work_so_far 
	+ 0.0025 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 992324.3294 * parameters.total_wait_locks 
	+ 3.2272 * parameters.mean_wait_of_all 
	+ 2949.971 * parameters.cpu_usage 
	+ 0.9753 * parameters.avg_work_of_same_past_second 
	+ 0.011 * parameters.avg_wait_of_same_past_second 
	- 0.0587 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 235081948.0919;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM98(work_wait &parameters) {
  double actual_remaining = 
	-680.0767 * parameters.work_so_far 
	+ 0.0025 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 900043.8122 * parameters.total_wait_locks 
	+ 3.2272 * parameters.mean_wait_of_all 
	+ 2949.971 * parameters.cpu_usage 
	+ 0.9753 * parameters.avg_work_of_same_past_second 
	+ 0.011 * parameters.avg_wait_of_same_past_second 
	- 0.0655 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 197841287.5933;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM99(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.0251 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 4823.2095 * parameters.total_wait_locks 
	+ 0.0202 * parameters.mean_wait_of_all 
	+ 2949.971 * parameters.cpu_usage 
	- 1.6297 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 97693874.6564;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM100(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.0109 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 3808.5427 * parameters.total_wait_locks 
	+ 0.0202 * parameters.mean_wait_of_all 
	+ 2949.971 * parameters.cpu_usage 
	- 0.0074 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0148 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 23536071.0459;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM101(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.0103 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 82995.6437 * parameters.total_wait_locks 
	+ 0.4352 * parameters.mean_wait_of_all 
	- 39228965.5546 * parameters.cpu_usage 
	+ 0.0026 * parameters.avg_work_of_same_past_second 
	- 0.0823 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.0068 * parameters.max_latency_of_same_last_50 
	+ 76390735.7087;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM102(work_wait &parameters) {
  double actual_remaining = 
	2.8764 * parameters.work_so_far 
	- 0.0087 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 131938.1882 * parameters.total_wait_locks 
	- 0.6838 * parameters.mean_wait_of_all 
	+ 1905043.0276 * parameters.cpu_usage 
	- 0.021 * parameters.avg_work_of_same_past_second 
	- 0.0029 * parameters.avg_wait_of_same_past_second 
	+ 0.0229 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 27202756.5347;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM103(work_wait &parameters) {
  double actual_remaining = 
	1.3435 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 145.7199 * parameters.total_wait_locks 
	+ 0.0803 * parameters.mean_wait_of_all 
	+ 1065081.7597 * parameters.cpu_usage 
	- 0.4224 * parameters.avg_work_of_same_past_second 
	- 0.0321 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.0029 * parameters.max_latency_of_same_last_50 
	+ 48940104.5323;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM104(work_wait &parameters) {
  double actual_remaining = 
	161.6445 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 27844.5023 * parameters.total_wait_locks 
	+ 0.395 * parameters.mean_wait_of_all 
	+ 1065081.7597 * parameters.cpu_usage 
	- 0.4554 * parameters.avg_work_of_same_past_second 
	- 0.0917 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.06 * parameters.max_latency_of_same_last_50 
	- 22645791.1276;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM105(work_wait &parameters) {
  double actual_remaining = 
	1166.1402 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 47037.4867 * parameters.total_wait_locks 
	+ 0.2708 * parameters.mean_wait_of_all 
	+ 1065081.7597 * parameters.cpu_usage 
	- 0.4554 * parameters.avg_work_of_same_past_second 
	- 0.0718 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.0086 * parameters.max_latency_of_same_last_50 
	+ 53065784.612;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM106(work_wait &parameters) {
  double actual_remaining = 
	1.3435 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 8401.7506 * parameters.total_wait_locks 
	+ 0.0803 * parameters.mean_wait_of_all 
	+ 1065081.7597 * parameters.cpu_usage 
	- 0.6102 * parameters.avg_work_of_same_past_second 
	- 0.0576 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.0054 * parameters.max_latency_of_same_last_50 
	+ 75358784.9594;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM107(work_wait &parameters) {
  double actual_remaining = 
	1.3435 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 34705.699 * parameters.total_wait_locks 
	- 0.395 * parameters.mean_wait_of_all 
	+ 1065081.7597 * parameters.cpu_usage 
	+ 2.9865 * parameters.avg_work_of_same_past_second 
	- 0.0238 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 8182973.5967;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM108(work_wait &parameters) {
  double actual_remaining = 
	1.3435 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 34705.699 * parameters.total_wait_locks 
	- 0.6011 * parameters.mean_wait_of_all 
	+ 1065081.7597 * parameters.cpu_usage 
	+ 0.4934 * parameters.avg_work_of_same_past_second 
	- 0.0238 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 114766361.8754;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM109(work_wait &parameters) {
  double actual_remaining = 
	474.9754 * parameters.work_so_far 
	- 0.001 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 200709.5458 * parameters.total_wait_locks 
	+ 0.9739 * parameters.mean_wait_of_all 
	+ 1065081.7597 * parameters.cpu_usage 
	- 0.0404 * parameters.avg_work_of_same_past_second 
	- 0.0659 * parameters.avg_wait_of_same_past_second 
	+ 0.2773 * parameters.avg_latency_of_same_last_20 
	- 0.0058 * parameters.max_latency_of_same_last_50 
	- 74273292.7239;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM110(work_wait &parameters) {
  double actual_remaining = 
	474.9754 * parameters.work_so_far 
	- 0.001 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 200709.5458 * parameters.total_wait_locks 
	+ 0.9739 * parameters.mean_wait_of_all 
	+ 1065081.7597 * parameters.cpu_usage 
	- 0.0404 * parameters.avg_work_of_same_past_second 
	- 0.0659 * parameters.avg_wait_of_same_past_second 
	+ 0.2824 * parameters.avg_latency_of_same_last_20 
	- 0.0058 * parameters.max_latency_of_same_last_50 
	- 71512991.284;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM111(work_wait &parameters) {
  double actual_remaining = 
	474.9754 * parameters.work_so_far 
	- 0.001 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 200709.5458 * parameters.total_wait_locks 
	+ 0.9739 * parameters.mean_wait_of_all 
	+ 1065081.7597 * parameters.cpu_usage 
	- 0.0404 * parameters.avg_work_of_same_past_second 
	- 0.0659 * parameters.avg_wait_of_same_past_second 
	+ 0.2824 * parameters.avg_latency_of_same_last_20 
	- 0.0058 * parameters.max_latency_of_same_last_50 
	- 70340433.8839;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM112(work_wait &parameters) {
  double actual_remaining = 
	474.9754 * parameters.work_so_far 
	- 0.001 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 200709.5458 * parameters.total_wait_locks 
	+ 0.9739 * parameters.mean_wait_of_all 
	+ 1065081.7597 * parameters.cpu_usage 
	- 0.0404 * parameters.avg_work_of_same_past_second 
	- 0.0659 * parameters.avg_wait_of_same_past_second 
	+ 0.2363 * parameters.avg_latency_of_same_last_20 
	- 0.0058 * parameters.max_latency_of_same_last_50 
	- 58377051.94;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM113(work_wait &parameters) {
  double actual_remaining = 
	380.249 * parameters.work_so_far 
	- 0.001 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 174043.9149 * parameters.total_wait_locks 
	+ 0.569 * parameters.mean_wait_of_all 
	+ 1065081.7597 * parameters.cpu_usage 
	+ 1.4912 * parameters.avg_work_of_same_past_second 
	- 0.0659 * parameters.avg_wait_of_same_past_second 
	+ 0.027 * parameters.avg_latency_of_same_last_20 
	- 0.0058 * parameters.max_latency_of_same_last_50 
	+ 1640794.7755;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM114(work_wait &parameters) {
  double actual_remaining = 
	1.3435 * parameters.work_so_far 
	- 0.001 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 75845.3679 * parameters.total_wait_locks 
	+ 0.3227 * parameters.mean_wait_of_all 
	+ 1065081.7597 * parameters.cpu_usage 
	- 0.0404 * parameters.avg_work_of_same_past_second 
	- 0.0744 * parameters.avg_wait_of_same_past_second 
	+ 0.0307 * parameters.avg_latency_of_same_last_20 
	- 0.0066 * parameters.max_latency_of_same_last_50 
	+ 56738199.9619;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM115(work_wait &parameters) {
  double actual_remaining = 
	1.3435 * parameters.work_so_far 
	- 0.001 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 6924.4177 * parameters.total_wait_locks 
	+ 0.037 * parameters.mean_wait_of_all 
	+ 1065081.7597 * parameters.cpu_usage 
	- 0.0404 * parameters.avg_work_of_same_past_second 
	- 0.0048 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 35356149.3264;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM116(work_wait &parameters) {
  double actual_remaining = 
	1.3435 * parameters.work_so_far 
	- 0.0024 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 6924.4177 * parameters.total_wait_locks 
	+ 0.037 * parameters.mean_wait_of_all 
	+ 1065081.7597 * parameters.cpu_usage 
	- 0.0404 * parameters.avg_work_of_same_past_second 
	- 0.0048 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 25524836.2964;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM117(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.1249 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 83354.8954 * parameters.total_wait_locks 
	- 0.0756 * parameters.mean_wait_of_all 
	- 258893703.4405 * parameters.cpu_usage 
	+ 0.3756 * parameters.avg_work_of_same_past_second 
	+ 1.8762 * parameters.avg_wait_of_same_past_second 
	+ 0.7903 * parameters.avg_latency_of_same_last_20 
	- 0.1097 * parameters.max_latency_of_same_last_50 
	+ 271997421.8018;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM118(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.0865 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 1871397.3646 * parameters.total_wait_locks 
	+ 8.4488 * parameters.mean_wait_of_all 
	- 169142863.5912 * parameters.cpu_usage 
	+ 0.7516 * parameters.avg_work_of_same_past_second 
	- 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.7136 * parameters.avg_latency_of_same_last_20 
	- 0.2617 * parameters.max_latency_of_same_last_50 
	+ 38936593.8287;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM119(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.0044 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 137208.8375 * parameters.total_wait_locks 
	+ 0.5204 * parameters.mean_wait_of_all 
	+ 2949.971 * parameters.cpu_usage 
	+ 0.5017 * parameters.avg_work_of_same_past_second 
	+ 0.1338 * parameters.avg_wait_of_same_past_second 
	+ 0.0081 * parameters.avg_latency_of_same_last_20 
	- 0.0106 * parameters.max_latency_of_same_last_50 
	- 39481781.3112;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM120(work_wait &parameters) {
  double actual_remaining = 
	0.1157 * parameters.work_so_far 
	+ 0.1733 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 947.3117 * parameters.total_wait_locks 
	- 0.0012 * parameters.mean_wait_of_all 
	- 568861.1736 * parameters.cpu_usage 
	- 0.0021 * parameters.avg_work_of_same_past_second 
	+ 0.0364 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 16003080.8711;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM121(work_wait &parameters) {
  double actual_remaining = 
	-9.4256 * parameters.work_so_far 
	+ 0.0307 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 102021.1536 * parameters.total_wait_locks 
	+ 0.3217 * parameters.mean_wait_of_all 
	- 78289173.0853 * parameters.cpu_usage 
	- 0.2379 * parameters.avg_work_of_same_past_second 
	- 0.2136 * parameters.avg_wait_of_same_past_second 
	+ 0.0274 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 224636799.7139;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM122(work_wait &parameters) {
  double actual_remaining = 
	-0.0548 * parameters.work_so_far 
	+ 0.0317 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 56898.1993 * parameters.total_wait_locks 
	+ 0.6154 * parameters.mean_wait_of_all 
	+ 12121872.765 * parameters.cpu_usage 
	- 0.7856 * parameters.avg_work_of_same_past_second 
	+ 0.0041 * parameters.avg_wait_of_same_past_second 
	+ 0.0105 * parameters.avg_latency_of_same_last_20 
	- 0.0052 * parameters.max_latency_of_same_last_50 
	+ 31054102.0091;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM123(work_wait &parameters) {
  double actual_remaining = 
	-0.0542 * parameters.work_so_far 
	+ 0.0317 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 56898.1993 * parameters.total_wait_locks 
	+ 0.3385 * parameters.mean_wait_of_all 
	+ 12121872.765 * parameters.cpu_usage 
	- 0.7756 * parameters.avg_work_of_same_past_second 
	+ 0.0041 * parameters.avg_wait_of_same_past_second 
	+ 0.0103 * parameters.avg_latency_of_same_last_20 
	- 0.0051 * parameters.max_latency_of_same_last_50 
	+ 44899874.4603;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM124(work_wait &parameters) {
  double actual_remaining = 
	-0.0582 * parameters.work_so_far 
	+ 0.22 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 56898.1993 * parameters.total_wait_locks 
	+ 0.3385 * parameters.mean_wait_of_all 
	+ 12121872.765 * parameters.cpu_usage 
	- 0.2379 * parameters.avg_work_of_same_past_second 
	+ 0.0041 * parameters.avg_wait_of_same_past_second 
	- 0.0242 * parameters.avg_latency_of_same_last_20 
	+ 0.0222 * parameters.max_latency_of_same_last_50 
	+ 12878304.089;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM125(work_wait &parameters) {
  double actual_remaining = 
	-0.6658 * parameters.work_so_far 
	+ 0.2513 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 56898.1993 * parameters.total_wait_locks 
	+ 0.3385 * parameters.mean_wait_of_all 
	+ 12121872.765 * parameters.cpu_usage 
	- 0.2379 * parameters.avg_work_of_same_past_second 
	+ 0.0041 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	+ 0.0259 * parameters.max_latency_of_same_last_50 
	+ 29366156.2998;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM126(work_wait &parameters) {
  double actual_remaining = 
	0.0067 * parameters.work_so_far 
	+ 0.0146 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 1881.0228 * parameters.total_wait_locks 
	+ 0.1232 * parameters.mean_wait_of_all 
	+ 34965193.8544 * parameters.cpu_usage 
	- 4.3622 * parameters.avg_work_of_same_past_second 
	+ 0.0041 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 235293569.5779;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM127(work_wait &parameters) {
  double actual_remaining = 
	0.0067 * parameters.work_so_far 
	+ 0.0146 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 1881.0228 * parameters.total_wait_locks 
	+ 0.1232 * parameters.mean_wait_of_all 
	+ 34965193.8544 * parameters.cpu_usage 
	- 4.3622 * parameters.avg_work_of_same_past_second 
	+ 0.0041 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 186049946.0885;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM128(work_wait &parameters) {
  double actual_remaining = 
	0.0067 * parameters.work_so_far 
	+ 0.0146 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 1881.0228 * parameters.total_wait_locks 
	+ 0.1232 * parameters.mean_wait_of_all 
	+ 34965193.8544 * parameters.cpu_usage 
	- 7.4155 * parameters.avg_work_of_same_past_second 
	+ 0.0041 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 262374034.0812;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM129(work_wait &parameters) {
  double actual_remaining = 
	0.0029 * parameters.work_so_far 
	+ 0.2695 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 617.8337 * parameters.total_wait_locks 
	+ 0.0015 * parameters.mean_wait_of_all 
	- 568861.1736 * parameters.cpu_usage 
	- 0.012 * parameters.avg_work_of_same_past_second 
	+ 0.2053 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.026 * parameters.max_latency_of_same_last_50 
	- 16111636.9947;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM130(work_wait &parameters) {
  double actual_remaining = 
	0.0029 * parameters.work_so_far 
	+ 0.038 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 59827.3611 * parameters.total_wait_locks 
	- 0.3164 * parameters.mean_wait_of_all 
	- 568861.1736 * parameters.cpu_usage 
	+ 0.5963 * parameters.avg_work_of_same_past_second 
	- 0.3522 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 151431436.5365;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM131(work_wait &parameters) {
  double actual_remaining = 
	17.1879 * parameters.work_so_far 
	+ 0.038 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 59827.3611 * parameters.total_wait_locks 
	- 0.3164 * parameters.mean_wait_of_all 
	- 568861.1736 * parameters.cpu_usage 
	+ 0.6842 * parameters.avg_work_of_same_past_second 
	- 0.3522 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 159430351.8215;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM132(work_wait &parameters) {
  double actual_remaining = 
	18.1988 * parameters.work_so_far 
	+ 0.038 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 59827.3611 * parameters.total_wait_locks 
	- 0.3164 * parameters.mean_wait_of_all 
	- 568861.1736 * parameters.cpu_usage 
	+ 0.6842 * parameters.avg_work_of_same_past_second 
	- 0.3522 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 177099030.7429;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM133(work_wait &parameters) {
  double actual_remaining = 
	0.635 * parameters.work_so_far 
	+ 0.0823 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 59827.3611 * parameters.total_wait_locks 
	- 0.3164 * parameters.mean_wait_of_all 
	- 568861.1736 * parameters.cpu_usage 
	+ 0.2615 * parameters.avg_work_of_same_past_second 
	- 0.1436 * parameters.avg_wait_of_same_past_second 
	+ 0.2526 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 9046967.785;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM134(work_wait &parameters) {
  double actual_remaining = 
	1.154 * parameters.work_so_far 
	+ 0.0823 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 59827.3611 * parameters.total_wait_locks 
	- 0.3164 * parameters.mean_wait_of_all 
	- 568861.1736 * parameters.cpu_usage 
	+ 0.2615 * parameters.avg_work_of_same_past_second 
	- 0.1436 * parameters.avg_wait_of_same_past_second 
	+ 0.264 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 7042066.7403;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM135(work_wait &parameters) {
  double actual_remaining = 
	0.0029 * parameters.work_so_far 
	+ 0.0823 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 59827.3611 * parameters.total_wait_locks 
	- 0.3164 * parameters.mean_wait_of_all 
	- 568861.1736 * parameters.cpu_usage 
	+ 0.2615 * parameters.avg_work_of_same_past_second 
	- 0.1436 * parameters.avg_wait_of_same_past_second 
	+ 0.025 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 57092608.3078;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM136(work_wait &parameters) {
  double actual_remaining = 
	0.0029 * parameters.work_so_far 
	+ 0.4029 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 59827.3611 * parameters.total_wait_locks 
	- 0.3164 * parameters.mean_wait_of_all 
	- 568861.1736 * parameters.cpu_usage 
	- 0.6022 * parameters.avg_work_of_same_past_second 
	- 0.1436 * parameters.avg_wait_of_same_past_second 
	+ 0.0492 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 100455621.815;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM137(work_wait &parameters) {
  double actual_remaining = 
	0.2662 * parameters.work_so_far 
	+ 0.4086 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 59827.3611 * parameters.total_wait_locks 
	- 0.3164 * parameters.mean_wait_of_all 
	- 568861.1736 * parameters.cpu_usage 
	- 0.9138 * parameters.avg_work_of_same_past_second 
	- 0.1436 * parameters.avg_wait_of_same_past_second 
	+ 0.0492 * parameters.avg_latency_of_same_last_20 
	- 0.0066 * parameters.max_latency_of_same_last_50 
	+ 136565536.0881;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM138(work_wait &parameters) {
  double actual_remaining = 
	0.0029 * parameters.work_so_far 
	+ 0.4086 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 59827.3611 * parameters.total_wait_locks 
	- 0.3164 * parameters.mean_wait_of_all 
	- 568861.1736 * parameters.cpu_usage 
	- 0.9321 * parameters.avg_work_of_same_past_second 
	- 0.1436 * parameters.avg_wait_of_same_past_second 
	+ 0.0492 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 127743333.5671;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM139(work_wait &parameters) {
  double actual_remaining = 
	0.0029 * parameters.work_so_far 
	+ 0.4417 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 59827.3611 * parameters.total_wait_locks 
	- 0.3164 * parameters.mean_wait_of_all 
	- 568861.1736 * parameters.cpu_usage 
	- 0.89 * parameters.avg_work_of_same_past_second 
	- 0.1436 * parameters.avg_wait_of_same_past_second 
	+ 0.0492 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 131245481.557;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM140(work_wait &parameters) {
  double actual_remaining = 
	0.0029 * parameters.work_so_far 
	+ 0.1889 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	- 74104.966 * parameters.total_wait_locks 
	+ 0.2297 * parameters.mean_wait_of_all 
	- 568861.1736 * parameters.cpu_usage 
	+ 0.0717 * parameters.avg_work_of_same_past_second 
	+ 0.0011 * parameters.avg_wait_of_same_past_second 
	+ 0.0342 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 31596592.5536;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM141(work_wait &parameters) {
  double actual_remaining = 
	0.0029 * parameters.work_so_far 
	+ 0.0442 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 304.4139 * parameters.total_wait_locks 
	+ 0.0172 * parameters.mean_wait_of_all 
	- 1444771.8883 * parameters.cpu_usage 
	+ 0.0155 * parameters.avg_work_of_same_past_second 
	+ 0.1662 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0565 * parameters.max_latency_of_same_last_50 
	+ 123323854.1167;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM142(work_wait &parameters) {
  double actual_remaining = 
	0.0029 * parameters.work_so_far 
	+ 0.055 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 304.4139 * parameters.total_wait_locks 
	+ 0.0278 * parameters.mean_wait_of_all 
	- 1444771.8883 * parameters.cpu_usage 
	+ 0.0155 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 220924870.5766;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM143(work_wait &parameters) {
  double actual_remaining = 
	0.0029 * parameters.work_so_far 
	+ 0.1133 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 304.4139 * parameters.total_wait_locks 
	- 0.0007 * parameters.mean_wait_of_all 
	- 1444771.8883 * parameters.cpu_usage 
	+ 0.0155 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 276743505.4957;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM144(work_wait &parameters) {
  double actual_remaining = 
	0.0029 * parameters.work_so_far 
	+ 1.0096 * parameters.wait_so_far 
	+ 2742.2112 * parameters.num_locks_so_far 
	+ 304.4139 * parameters.total_wait_locks 
	- 0.0007 * parameters.mean_wait_of_all 
	- 2139356617.6254 * parameters.cpu_usage 
	+ 0.0155 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 1357527133.9069;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM145(work_wait &parameters) {
  double actual_remaining = 
	2.8172 * parameters.work_so_far 
	+ 0.0011 * parameters.wait_so_far 
	- 2852670.3148 * parameters.num_locks_so_far 
	+ 953979.5581 * parameters.total_wait_locks 
	- 0.0109 * parameters.mean_wait_of_all 
	- 333825898.3942 * parameters.cpu_usage 
	+ 0.4884 * parameters.avg_work_of_same_past_second 
	- 0.5591 * parameters.avg_wait_of_same_past_second 
	+ 0.004 * parameters.avg_latency_of_same_last_20 
	- 0.0013 * parameters.max_latency_of_same_last_50 
	+ 362974130.9574;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM146(work_wait &parameters) {
  double actual_remaining = 
	1175.2631 * parameters.work_so_far 
	- 0.0387 * parameters.wait_so_far 
	- 115137.7101 * parameters.num_locks_so_far 
	+ 3605096.9124 * parameters.total_wait_locks 
	- 0.097 * parameters.mean_wait_of_all 
	- 12362205.3355 * parameters.cpu_usage 
	- 1.1217 * parameters.avg_work_of_same_past_second 
	- 0.2284 * parameters.avg_wait_of_same_past_second 
	- 0.0845 * parameters.avg_latency_of_same_last_20 
	- 0.004 * parameters.max_latency_of_same_last_50 
	- 6639765.7813;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM147(work_wait &parameters) {
  double actual_remaining = 
	5728.5117 * parameters.work_so_far 
	- 0.0387 * parameters.wait_so_far 
	- 115137.7101 * parameters.num_locks_so_far 
	+ 146462.8135 * parameters.total_wait_locks 
	+ 0.9085 * parameters.mean_wait_of_all 
	- 12362205.3355 * parameters.cpu_usage 
	+ 0.7134 * parameters.avg_work_of_same_past_second 
	- 0.2924 * parameters.avg_wait_of_same_past_second 
	- 0.4664 * parameters.avg_latency_of_same_last_20 
	- 0.004 * parameters.max_latency_of_same_last_50 
	+ 95357509.3187;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM148(work_wait &parameters) {
  double actual_remaining = 
	5728.5117 * parameters.work_so_far 
	- 0.0387 * parameters.wait_so_far 
	- 115137.7101 * parameters.num_locks_so_far 
	+ 209400.5271 * parameters.total_wait_locks 
	+ 0.8583 * parameters.mean_wait_of_all 
	- 12362205.3355 * parameters.cpu_usage 
	+ 0.7134 * parameters.avg_work_of_same_past_second 
	- 0.2924 * parameters.avg_wait_of_same_past_second 
	- 0.4664 * parameters.avg_latency_of_same_last_20 
	- 0.004 * parameters.max_latency_of_same_last_50 
	+ 81807702.8061;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM149(work_wait &parameters) {
  double actual_remaining = 
	6662.8557 * parameters.work_so_far 
	- 0.0387 * parameters.wait_so_far 
	- 115137.7101 * parameters.num_locks_so_far 
	+ 1405217.0864 * parameters.total_wait_locks 
	- 0.097 * parameters.mean_wait_of_all 
	- 12362205.3355 * parameters.cpu_usage 
	+ 0.7813 * parameters.avg_work_of_same_past_second 
	- 0.2924 * parameters.avg_wait_of_same_past_second 
	- 0.3534 * parameters.avg_latency_of_same_last_20 
	- 0.004 * parameters.max_latency_of_same_last_50 
	- 193449779.9758;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM150(work_wait &parameters) {
  double actual_remaining = 
	4389.0058 * parameters.work_so_far 
	- 0.0387 * parameters.wait_so_far 
	- 115137.7101 * parameters.num_locks_so_far 
	+ 1405217.0864 * parameters.total_wait_locks 
	- 0.097 * parameters.mean_wait_of_all 
	- 12362205.3355 * parameters.cpu_usage 
	+ 0.8851 * parameters.avg_work_of_same_past_second 
	- 0.2924 * parameters.avg_wait_of_same_past_second 
	- 0.3534 * parameters.avg_latency_of_same_last_20 
	- 0.004 * parameters.max_latency_of_same_last_50 
	- 15530371.0956;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM151(work_wait &parameters) {
  double actual_remaining = 
	-789.4868 * parameters.work_so_far 
	- 0.1427 * parameters.wait_so_far 
	- 115137.7101 * parameters.num_locks_so_far 
	+ 1173286.5432 * parameters.total_wait_locks 
	- 0.046 * parameters.mean_wait_of_all 
	- 12362205.3355 * parameters.cpu_usage 
	+ 0.3011 * parameters.avg_work_of_same_past_second 
	- 0.5926 * parameters.avg_wait_of_same_past_second 
	+ 0.1329 * parameters.avg_latency_of_same_last_20 
	- 0.004 * parameters.max_latency_of_same_last_50 
	+ 68137458.0013;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM152(work_wait &parameters) {
  double actual_remaining = 
	0.9295 * parameters.work_so_far 
	- 0.1601 * parameters.wait_so_far 
	- 3830971.2039 * parameters.num_locks_so_far 
	+ 254077.0315 * parameters.total_wait_locks 
	- 0.0636 * parameters.mean_wait_of_all 
	- 35595077.8879 * parameters.cpu_usage 
	+ 1.0922 * parameters.avg_work_of_same_past_second 
	- 1.0595 * parameters.avg_wait_of_same_past_second 
	+ 0.0238 * parameters.avg_latency_of_same_last_20 
	- 0.0118 * parameters.max_latency_of_same_last_50 
	+ 190631615.5165;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM153(work_wait &parameters) {
  double actual_remaining = 
	1.2659 * parameters.work_so_far 
	+ 0.4813 * parameters.wait_so_far 
	- 1159961.8815 * parameters.num_locks_so_far 
	+ 254077.0315 * parameters.total_wait_locks 
	- 0.0636 * parameters.mean_wait_of_all 
	- 35595077.8879 * parameters.cpu_usage 
	+ 0.2445 * parameters.avg_work_of_same_past_second 
	- 0.2711 * parameters.avg_wait_of_same_past_second 
	+ 0.0238 * parameters.avg_latency_of_same_last_20 
	- 0.0118 * parameters.max_latency_of_same_last_50 
	+ 258400160.0295;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM154(work_wait &parameters) {
  double actual_remaining = 
	4.3814 * parameters.work_so_far 
	+ 0.0182 * parameters.wait_so_far 
	- 655274.7328 * parameters.num_locks_so_far 
	+ 1837882.5182 * parameters.total_wait_locks 
	- 1.3922 * parameters.mean_wait_of_all 
	- 431556798.7252 * parameters.cpu_usage 
	+ 0.8692 * parameters.avg_work_of_same_past_second 
	- 0.7308 * parameters.avg_wait_of_same_past_second 
	+ 0.0194 * parameters.avg_latency_of_same_last_20 
	- 0.0148 * parameters.max_latency_of_same_last_50 
	+ 447716895.4998;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM155(work_wait &parameters) {
  double actual_remaining = 
	3.6775 * parameters.work_so_far 
	+ 0.8896 * parameters.wait_so_far 
	- 2643065.527 * parameters.num_locks_so_far 
	+ 324818.129 * parameters.total_wait_locks 
	- 0.123 * parameters.mean_wait_of_all 
	- 52547274.5056 * parameters.cpu_usage 
	+ 0.3316 * parameters.avg_work_of_same_past_second 
	- 0.0969 * parameters.avg_wait_of_same_past_second 
	+ 0.0194 * parameters.avg_latency_of_same_last_20 
	- 0.099 * parameters.max_latency_of_same_last_50 
	+ 206661801.6847;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM156(work_wait &parameters) {
  double actual_remaining = 
	-1.731 * parameters.work_so_far 
	+ 0.1318 * parameters.wait_so_far 
	+ 1348254.4596 * parameters.num_locks_so_far 
	+ 326586.1599 * parameters.total_wait_locks 
	- 0.0348 * parameters.mean_wait_of_all 
	- 173054027.058 * parameters.cpu_usage 
	- 0.6148 * parameters.avg_work_of_same_past_second 
	- 0.0778 * parameters.avg_wait_of_same_past_second 
	+ 0.53 * parameters.avg_latency_of_same_last_20 
	- 0.0172 * parameters.max_latency_of_same_last_50 
	+ 202736417.9673;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM157(work_wait &parameters) {
  double actual_remaining = 
	2.8636 * parameters.work_so_far 
	+ 0.3314 * parameters.wait_so_far 
	- 1081787.5168 * parameters.num_locks_so_far 
	+ 989046.2218 * parameters.total_wait_locks 
	+ 0.1937 * parameters.mean_wait_of_all 
	- 666947639.8941 * parameters.cpu_usage 
	+ 0.3931 * parameters.avg_work_of_same_past_second 
	- 0.0778 * parameters.avg_wait_of_same_past_second 
	+ 0.1014 * parameters.avg_latency_of_same_last_20 
	- 0.0172 * parameters.max_latency_of_same_last_50 
	+ 770378320.8921;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM158(work_wait &parameters) {
  double actual_remaining = 
	1.0096 * parameters.work_so_far 
	+ 0.6183 * parameters.wait_so_far 
	- 608457.3466 * parameters.num_locks_so_far 
	+ 989046.2218 * parameters.total_wait_locks 
	+ 0.1937 * parameters.mean_wait_of_all 
	- 332274726.1128 * parameters.cpu_usage 
	+ 0.3553 * parameters.avg_work_of_same_past_second 
	- 0.0778 * parameters.avg_wait_of_same_past_second 
	+ 0.1014 * parameters.avg_latency_of_same_last_20 
	- 0.0172 * parameters.max_latency_of_same_last_50 
	+ 312107064.3729;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM159(work_wait &parameters) {
  double actual_remaining = 
	0.6572 * parameters.work_so_far 
	+ 0.3147 * parameters.wait_so_far 
	+ 73382.0813 * parameters.num_locks_so_far 
	+ 1834253.8869 * parameters.total_wait_locks 
	+ 0.4853 * parameters.mean_wait_of_all 
	- 338333284.847 * parameters.cpu_usage 
	+ 0.339 * parameters.avg_work_of_same_past_second 
	+ 0.5078 * parameters.avg_wait_of_same_past_second 
	+ 0.1014 * parameters.avg_latency_of_same_last_20 
	- 0.0172 * parameters.max_latency_of_same_last_50 
	+ 358067038.5605;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM160(work_wait &parameters) {
  double actual_remaining = 
	0.9201 * parameters.work_so_far 
	+ 0.4252 * parameters.wait_so_far 
	- 3376444.843 * parameters.num_locks_so_far 
	+ 1393827.5928 * parameters.total_wait_locks 
	- 0.5555 * parameters.mean_wait_of_all 
	- 160210653.8463 * parameters.cpu_usage 
	+ 0.6035 * parameters.avg_work_of_same_past_second 
	- 0.5571 * parameters.avg_wait_of_same_past_second 
	+ 0.1471 * parameters.avg_latency_of_same_last_20 
	- 0.1027 * parameters.max_latency_of_same_last_50 
	+ 395046992.9381;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM161(work_wait &parameters) {
  double actual_remaining = 
	-93.4301 * parameters.work_so_far 
	- 0.3019 * parameters.wait_so_far 
	+ 7180.3735 * parameters.num_locks_so_far 
	- 503679.158 * parameters.total_wait_locks 
	+ 2.0461 * parameters.mean_wait_of_all 
	- 361021943.7479 * parameters.cpu_usage 
	+ 0.4892 * parameters.avg_work_of_same_past_second 
	- 0.0043 * parameters.avg_wait_of_same_past_second 
	+ 0.1417 * parameters.avg_latency_of_same_last_20 
	- 0.0564 * parameters.max_latency_of_same_last_50 
	+ 586349615.2337;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM162(work_wait &parameters) {
  double actual_remaining = 
	-3.5382 * parameters.work_so_far 
	- 0.3072 * parameters.wait_so_far 
	+ 7180.3735 * parameters.num_locks_so_far 
	- 4108.1811 * parameters.total_wait_locks 
	+ 0.0328 * parameters.mean_wait_of_all 
	- 319393269.5466 * parameters.cpu_usage 
	+ 0.007 * parameters.avg_work_of_same_past_second 
	- 0.0036 * parameters.avg_wait_of_same_past_second 
	+ 0.0077 * parameters.avg_latency_of_same_last_20 
	- 0.0811 * parameters.max_latency_of_same_last_50 
	+ 731867803.5593;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM163(work_wait &parameters) {
  double actual_remaining = 
	-766.1549 * parameters.work_so_far 
	- 0.0128 * parameters.wait_so_far 
	+ 7180.3735 * parameters.num_locks_so_far 
	- 169897.4639 * parameters.total_wait_locks 
	+ 0.744 * parameters.mean_wait_of_all 
	- 1160440.2551 * parameters.cpu_usage 
	+ 0.17 * parameters.avg_work_of_same_past_second 
	- 1.1866 * parameters.avg_wait_of_same_past_second 
	+ 0.0779 * parameters.avg_latency_of_same_last_20 
	+ 0.285 * parameters.max_latency_of_same_last_50 
	+ 780087192.0336;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM164(work_wait &parameters) {
  double actual_remaining = 
	-7.9731 * parameters.work_so_far 
	+ 12515.4236 * parameters.wait_so_far 
	+ 7180.3735 * parameters.num_locks_so_far 
	- 169897.4639 * parameters.total_wait_locks 
	+ 0.744 * parameters.mean_wait_of_all 
	- 1160440.2551 * parameters.cpu_usage 
	+ 0.17 * parameters.avg_work_of_same_past_second 
	- 0.5653 * parameters.avg_wait_of_same_past_second 
	+ 0.0779 * parameters.avg_latency_of_same_last_20 
	+ 0.1077 * parameters.max_latency_of_same_last_50 
	+ 348627373.9668;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM165(work_wait &parameters) {
  double actual_remaining = 
	-7.9731 * parameters.work_so_far 
	- 0.0128 * parameters.wait_so_far 
	+ 7180.3735 * parameters.num_locks_so_far 
	- 267749.8878 * parameters.total_wait_locks 
	+ 1.2677 * parameters.mean_wait_of_all 
	- 1160440.2551 * parameters.cpu_usage 
	+ 0.1467 * parameters.avg_work_of_same_past_second 
	- 0.0592 * parameters.avg_wait_of_same_past_second 
	+ 0.0791 * parameters.avg_latency_of_same_last_20 
	- 0.0365 * parameters.max_latency_of_same_last_50 
	+ 372164883.4173;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM166(work_wait &parameters) {
  double actual_remaining = 
	-7.9731 * parameters.work_so_far 
	+ 21.5972 * parameters.wait_so_far 
	+ 7180.3735 * parameters.num_locks_so_far 
	- 1232235.2765 * parameters.total_wait_locks 
	+ 5.8793 * parameters.mean_wait_of_all 
	- 1160440.2551 * parameters.cpu_usage 
	+ 0.203 * parameters.avg_work_of_same_past_second 
	- 2.3981 * parameters.avg_wait_of_same_past_second 
	+ 0.3286 * parameters.avg_latency_of_same_last_20 
	- 0.7527 * parameters.max_latency_of_same_last_50 
	+ 1423353358.2078;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM167(work_wait &parameters) {
  double actual_remaining = 
	-7.9731 * parameters.work_so_far 
	+ 15.5904 * parameters.wait_so_far 
	+ 7180.3735 * parameters.num_locks_so_far 
	- 1232235.2765 * parameters.total_wait_locks 
	+ 5.8793 * parameters.mean_wait_of_all 
	- 1160440.2551 * parameters.cpu_usage 
	+ 0.203 * parameters.avg_work_of_same_past_second 
	- 2.611 * parameters.avg_wait_of_same_past_second 
	+ 0.3286 * parameters.avg_latency_of_same_last_20 
	- 0.7527 * parameters.max_latency_of_same_last_50 
	+ 1478881930.435;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM168(work_wait &parameters) {
  double actual_remaining = 
	-7.9731 * parameters.work_so_far 
	- 0.0128 * parameters.wait_so_far 
	+ 7180.3735 * parameters.num_locks_so_far 
	- 1232235.2765 * parameters.total_wait_locks 
	+ 5.8793 * parameters.mean_wait_of_all 
	- 1160440.2551 * parameters.cpu_usage 
	+ 0.203 * parameters.avg_work_of_same_past_second 
	- 0.767 * parameters.avg_wait_of_same_past_second 
	+ 0.3286 * parameters.avg_latency_of_same_last_20 
	- 0.5809 * parameters.max_latency_of_same_last_50 
	+ 896254439.0883;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM169(work_wait &parameters) {
  double actual_remaining = 
	-7.9731 * parameters.work_so_far 
	- 0.0128 * parameters.wait_so_far 
	+ 7180.3735 * parameters.num_locks_so_far 
	- 835537.4506 * parameters.total_wait_locks 
	+ 3.98 * parameters.mean_wait_of_all 
	+ 551111392.9435 * parameters.cpu_usage 
	+ 0.203 * parameters.avg_work_of_same_past_second 
	- 0.0592 * parameters.avg_wait_of_same_past_second 
	+ 0.7732 * parameters.avg_latency_of_same_last_20 
	- 0.1522 * parameters.max_latency_of_same_last_50 
	- 111432621.5175;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM170(work_wait &parameters) {
  double actual_remaining = 
	-154.366 * parameters.work_so_far 
	- 0.2275 * parameters.wait_so_far 
	+ 7180.3735 * parameters.num_locks_so_far 
	- 906020.7527 * parameters.total_wait_locks 
	+ 5.1485 * parameters.mean_wait_of_all 
	- 1160440.2551 * parameters.cpu_usage 
	+ 0.007 * parameters.avg_work_of_same_past_second 
	- 0.0036 * parameters.avg_wait_of_same_past_second 
	+ 0.1445 * parameters.avg_latency_of_same_last_20 
	- 0.0557 * parameters.max_latency_of_same_last_50 
	+ 294781925.7456;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM171(work_wait &parameters) {
  double actual_remaining = 
	98.9594 * parameters.work_so_far 
	- 0.1702 * parameters.wait_so_far 
	+ 49542570.5664 * parameters.num_locks_so_far 
	- 451626.1231 * parameters.total_wait_locks 
	+ 3.1156 * parameters.mean_wait_of_all 
	+ 133498646.2005 * parameters.cpu_usage 
	+ 0.6862 * parameters.avg_work_of_same_past_second 
	- 0.5573 * parameters.avg_wait_of_same_past_second 
	+ 0.2516 * parameters.avg_latency_of_same_last_20 
	- 0.0539 * parameters.max_latency_of_same_last_50 
	- 233865651.2254;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM172(work_wait &parameters) {
  double actual_remaining = 
	4.517 * parameters.work_so_far 
	+ 0.7209 * parameters.wait_so_far 
	+ 6939122.8783 * parameters.num_locks_so_far 
	- 394573.9453 * parameters.total_wait_locks 
	+ 1.9034 * parameters.mean_wait_of_all 
	- 229863311.0897 * parameters.cpu_usage 
	+ 1.251 * parameters.avg_work_of_same_past_second 
	- 0.4642 * parameters.avg_wait_of_same_past_second 
	- 0.096 * parameters.avg_latency_of_same_last_20 
	- 0.002 * parameters.max_latency_of_same_last_50 
	+ 368994331.6945;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM173(work_wait &parameters) {
  double actual_remaining = 
	12.4011 * parameters.work_so_far 
	+ 0.2584 * parameters.wait_so_far 
	+ 171866.3072 * parameters.num_locks_so_far 
	- 282795.9718 * parameters.total_wait_locks 
	+ 2.2843 * parameters.mean_wait_of_all 
	- 46222.1359 * parameters.cpu_usage 
	+ 0.5098 * parameters.avg_work_of_same_past_second 
	- 0.4088 * parameters.avg_wait_of_same_past_second 
	+ 0.1178 * parameters.avg_latency_of_same_last_20 
	- 0.114 * parameters.max_latency_of_same_last_50 
	+ 296931727.9602;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM174(work_wait &parameters) {
  double actual_remaining = 
	1.8094 * parameters.work_so_far 
	- 0.2166 * parameters.wait_so_far 
	+ 19982071.3078 * parameters.num_locks_so_far 
	+ 778456.2363 * parameters.total_wait_locks 
	- 3.2074 * parameters.mean_wait_of_all 
	- 46222.1359 * parameters.cpu_usage 
	+ 0.014 * parameters.avg_work_of_same_past_second 
	- 0.4662 * parameters.avg_wait_of_same_past_second 
	+ 0.1695 * parameters.avg_latency_of_same_last_20 
	- 0.0729 * parameters.max_latency_of_same_last_50 
	+ 529247740.3712;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM175(work_wait &parameters) {
  double actual_remaining = 
	3.0619 * parameters.work_so_far 
	+ 0.8947 * parameters.wait_so_far 
	- 77541507.3059 * parameters.num_locks_so_far 
	+ 255623.9592 * parameters.total_wait_locks 
	- 0.0847 * parameters.mean_wait_of_all 
	- 46222.1359 * parameters.cpu_usage 
	+ 0.014 * parameters.avg_work_of_same_past_second 
	- 0.0301 * parameters.avg_wait_of_same_past_second 
	+ 0.0093 * parameters.avg_latency_of_same_last_20 
	- 0.0034 * parameters.max_latency_of_same_last_50 
	+ 1253492727.7652;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM176(work_wait &parameters) {
  double actual_remaining = 
	20.3656 * parameters.work_so_far 
	+ 1.0418 * parameters.wait_so_far 
	- 21938944.496 * parameters.num_locks_so_far 
	- 50361.7239 * parameters.total_wait_locks 
	+ 0.2953 * parameters.mean_wait_of_all 
	- 46222.1359 * parameters.cpu_usage 
	+ 0.3338 * parameters.avg_work_of_same_past_second 
	- 0.4875 * parameters.avg_wait_of_same_past_second 
	+ 0.0067 * parameters.avg_latency_of_same_last_20 
	- 0.0007 * parameters.max_latency_of_same_last_50 
	+ 418631401.3423;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM177(work_wait &parameters) {
  double actual_remaining = 
	0.9373 * parameters.work_so_far 
	+ 0.9862 * parameters.wait_so_far 
	- 21076686.4505 * parameters.num_locks_so_far 
	- 1129710.5174 * parameters.total_wait_locks 
	+ 6.0136 * parameters.mean_wait_of_all 
	- 46222.1359 * parameters.cpu_usage 
	+ 0.6586 * parameters.avg_work_of_same_past_second 
	- 0.058 * parameters.avg_wait_of_same_past_second 
	- 0.1351 * parameters.avg_latency_of_same_last_20 
	- 0.0007 * parameters.max_latency_of_same_last_50 
	+ 504261575.7584;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM178(work_wait &parameters) {
  double actual_remaining = 
	3.7901 * parameters.work_so_far 
	+ 1.1009 * parameters.wait_so_far 
	- 1508020.2259 * parameters.num_locks_so_far 
	- 656873.4524 * parameters.total_wait_locks 
	+ 3.6667 * parameters.mean_wait_of_all 
	- 46222.1359 * parameters.cpu_usage 
	+ 0.3683 * parameters.avg_work_of_same_past_second 
	- 0.6679 * parameters.avg_wait_of_same_past_second 
	+ 0.1109 * parameters.avg_latency_of_same_last_20 
	- 0.0007 * parameters.max_latency_of_same_last_50 
	+ 54587250.7273;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM179(work_wait &parameters) {
  double actual_remaining = 
	1.3304 * parameters.work_so_far 
	+ 0.9857 * parameters.wait_so_far 
	- 7706882.8413 * parameters.num_locks_so_far 
	- 25496.4332 * parameters.total_wait_locks 
	+ 0.158 * parameters.mean_wait_of_all 
	- 291611847.6417 * parameters.cpu_usage 
	+ 0.3282 * parameters.avg_work_of_same_past_second 
	- 0.5777 * parameters.avg_wait_of_same_past_second 
	+ 0.118 * parameters.avg_latency_of_same_last_20 
	- 0.0007 * parameters.max_latency_of_same_last_50 
	+ 744189906.4766;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM180(work_wait &parameters) {
  double actual_remaining = 
	2.88 * parameters.work_so_far 
	+ 0.4504 * parameters.wait_so_far 
	- 4491651.1965 * parameters.num_locks_so_far 
	- 394702.8114 * parameters.total_wait_locks 
	+ 2.1983 * parameters.mean_wait_of_all 
	- 46222.1359 * parameters.cpu_usage 
	+ 0.5079 * parameters.avg_work_of_same_past_second 
	- 0.4222 * parameters.avg_wait_of_same_past_second 
	+ 0.2479 * parameters.avg_latency_of_same_last_20 
	- 0.0462 * parameters.max_latency_of_same_last_50 
	+ 282623965.2107;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM181(work_wait &parameters) {
  double actual_remaining = 
	0.258 * parameters.work_so_far 
	+ 0.1907 * parameters.wait_so_far 
	+ 1327765.4432 * parameters.num_locks_so_far 
	- 2362502.2794 * parameters.total_wait_locks 
	+ 12.1753 * parameters.mean_wait_of_all 
	- 46222.1359 * parameters.cpu_usage 
	+ 0.1293 * parameters.avg_work_of_same_past_second 
	- 0.0169 * parameters.avg_wait_of_same_past_second 
	+ 0.0042 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 318068172.8799;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM182(work_wait &parameters) {
  double actual_remaining = 
	0.258 * parameters.work_so_far 
	- 0.1149 * parameters.wait_so_far 
	+ 18472126.1367 * parameters.num_locks_so_far 
	- 922098.966 * parameters.total_wait_locks 
	+ 5.9214 * parameters.mean_wait_of_all 
	- 46222.1359 * parameters.cpu_usage 
	+ 0.1293 * parameters.avg_work_of_same_past_second 
	+ 0.278 * parameters.avg_wait_of_same_past_second 
	- 0.233 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 237617349.9958;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM183(work_wait &parameters) {
  double actual_remaining = 
	0.258 * parameters.work_so_far 
	- 0.2693 * parameters.wait_so_far 
	+ 18472126.1367 * parameters.num_locks_so_far 
	- 825631.2432 * parameters.total_wait_locks 
	+ 5.9214 * parameters.mean_wait_of_all 
	- 46222.1359 * parameters.cpu_usage 
	+ 0.1293 * parameters.avg_work_of_same_past_second 
	+ 0.4022 * parameters.avg_wait_of_same_past_second 
	- 0.3329 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 268694623.7679;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM184(work_wait &parameters) {
  double actual_remaining = 
	0.258 * parameters.work_so_far 
	+ 0.2518 * parameters.wait_so_far 
	+ 17078723.9229 * parameters.num_locks_so_far 
	- 1151209.8077 * parameters.total_wait_locks 
	+ 5.9214 * parameters.mean_wait_of_all 
	- 46222.1359 * parameters.cpu_usage 
	+ 0.1293 * parameters.avg_work_of_same_past_second 
	- 0.0169 * parameters.avg_wait_of_same_past_second 
	+ 0.0042 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 442303453.4717;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM185(work_wait &parameters) {
  double actual_remaining = 
	0.5077 * parameters.work_so_far 
	+ 0.8658 * parameters.wait_so_far 
	+ 1744609.2864 * parameters.num_locks_so_far 
	- 723258.03 * parameters.total_wait_locks 
	+ 3.6612 * parameters.mean_wait_of_all 
	- 72260338.6257 * parameters.cpu_usage 
	+ 1.6618 * parameters.avg_work_of_same_past_second 
	- 0.0169 * parameters.avg_wait_of_same_past_second 
	- 0.1353 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 309210079.171;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM186(work_wait &parameters) {
  double actual_remaining = 
	0.5077 * parameters.work_so_far 
	+ 0.9543 * parameters.wait_so_far 
	+ 1744609.2864 * parameters.num_locks_so_far 
	- 723258.03 * parameters.total_wait_locks 
	+ 3.6612 * parameters.mean_wait_of_all 
	+ 1000502919.2462 * parameters.cpu_usage 
	+ 1.5902 * parameters.avg_work_of_same_past_second 
	- 0.0169 * parameters.avg_wait_of_same_past_second 
	- 0.1353 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	- 644589150.6156;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM187(work_wait &parameters) {
  double actual_remaining = 
	0.5077 * parameters.work_so_far 
	+ 1.0612 * parameters.wait_so_far 
	+ 1744609.2864 * parameters.num_locks_so_far 
	- 723258.03 * parameters.total_wait_locks 
	+ 3.6612 * parameters.mean_wait_of_all 
	- 1236671711.3998 * parameters.cpu_usage 
	+ 0.9235 * parameters.avg_work_of_same_past_second 
	- 0.0169 * parameters.avg_wait_of_same_past_second 
	- 0.3645 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 1717875318.7826;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM188(work_wait &parameters) {
  double actual_remaining = 
	0.7552 * parameters.work_so_far 
	+ 0.7596 * parameters.wait_so_far 
	- 370858.5916 * parameters.num_locks_so_far 
	- 315198.9585 * parameters.total_wait_locks 
	+ 1.9626 * parameters.mean_wait_of_all 
	- 46222.1359 * parameters.cpu_usage 
	+ 0.0241 * parameters.avg_work_of_same_past_second 
	- 0.0169 * parameters.avg_wait_of_same_past_second 
	+ 0.0825 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 228762990.8677;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM189(work_wait &parameters) {
  double actual_remaining = 
	0.79 * parameters.work_so_far 
	+ 0.7069 * parameters.wait_so_far 
	- 429381.1604 * parameters.num_locks_so_far 
	- 1130138.782 * parameters.total_wait_locks 
	+ 6.0618 * parameters.mean_wait_of_all 
	- 46222.1359 * parameters.cpu_usage 
	+ 0.0172 * parameters.avg_work_of_same_past_second 
	- 0.0169 * parameters.avg_wait_of_same_past_second 
	+ 0.1933 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 135554716.9182;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM190(work_wait &parameters) {
  double actual_remaining = 
	0.8201 * parameters.work_so_far 
	+ 0.7935 * parameters.wait_so_far 
	- 10583305.145 * parameters.num_locks_so_far 
	- 37007.8703 * parameters.total_wait_locks 
	+ 0.2175 * parameters.mean_wait_of_all 
	+ 448527815.8251 * parameters.cpu_usage 
	+ 0.514 * parameters.avg_work_of_same_past_second 
	- 0.9121 * parameters.avg_wait_of_same_past_second 
	+ 0.0024 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 396923939.3985;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM191(work_wait &parameters) {
  double actual_remaining = 
	0.0508 * parameters.work_so_far 
	+ 0.5011 * parameters.wait_so_far 
	+ 300144.1177 * parameters.num_locks_so_far 
	+ 423264.9371 * parameters.total_wait_locks 
	- 2.4308 * parameters.mean_wait_of_all 
	- 46222.1359 * parameters.cpu_usage 
	- 0.3386 * parameters.avg_work_of_same_past_second 
	+ 0.8595 * parameters.avg_wait_of_same_past_second 
	+ 0.3026 * parameters.avg_latency_of_same_last_20 
	- 0.1532 * parameters.max_latency_of_same_last_50 
	+ 51536744.1612;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM192(work_wait &parameters) {
  double actual_remaining = 
	2.6608 * parameters.work_so_far 
	+ 0.8939 * parameters.wait_so_far 
	- 393343.5275 * parameters.num_locks_so_far 
	- 110250.8423 * parameters.total_wait_locks 
	+ 0.6031 * parameters.mean_wait_of_all 
	- 46222.1359 * parameters.cpu_usage 
	+ 0.0247 * parameters.avg_work_of_same_past_second 
	- 0.1035 * parameters.avg_wait_of_same_past_second 
	+ 0.0458 * parameters.avg_latency_of_same_last_20 
	- 0.0103 * parameters.max_latency_of_same_last_50 
	+ 87989192.7581;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM193(work_wait &parameters) {
  double actual_remaining = 
	6.3662 * parameters.work_so_far 
	+ 0.1398 * parameters.wait_so_far 
	+ 4200720.4713 * parameters.num_locks_so_far 
	- 313803.304 * parameters.total_wait_locks 
	+ 1.5573 * parameters.mean_wait_of_all 
	- 46222.1359 * parameters.cpu_usage 
	+ 0.0168 * parameters.avg_work_of_same_past_second 
	- 0.0327 * parameters.avg_wait_of_same_past_second 
	+ 0.1016 * parameters.avg_latency_of_same_last_20 
	- 0.024 * parameters.max_latency_of_same_last_50 
	+ 499522155.1236;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM194(work_wait &parameters) {
  double actual_remaining = 
	1.7823 * parameters.work_so_far 
	+ 0.6618 * parameters.wait_so_far 
	+ 7512406.5788 * parameters.num_locks_so_far 
	- 385553.3289 * parameters.total_wait_locks 
	+ 1.9691 * parameters.mean_wait_of_all 
	+ 627400693.6672 * parameters.cpu_usage 
	+ 0.0168 * parameters.avg_work_of_same_past_second 
	- 0.0327 * parameters.avg_wait_of_same_past_second 
	+ 0.4566 * parameters.avg_latency_of_same_last_20 
	- 0.1333 * parameters.max_latency_of_same_last_50 
	- 328155452.6707;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM195(work_wait &parameters) {
  double actual_remaining = 
	2.0735 * parameters.work_so_far 
	+ 0.2045 * parameters.wait_so_far 
	+ 9486062.1467 * parameters.num_locks_so_far 
	- 443752.4005 * parameters.total_wait_locks 
	+ 2.2749 * parameters.mean_wait_of_all 
	- 46222.1359 * parameters.cpu_usage 
	+ 0.0168 * parameters.avg_work_of_same_past_second 
	- 0.0327 * parameters.avg_wait_of_same_past_second 
	+ 0.0817 * parameters.avg_latency_of_same_last_20 
	- 0.2078 * parameters.max_latency_of_same_last_50 
	+ 970090792.8887;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM196(work_wait &parameters) {
  double actual_remaining = 
	4.5051 * parameters.work_so_far 
	+ 0.8888 * parameters.wait_so_far 
	- 3880614.376 * parameters.num_locks_so_far 
	- 837511.3803 * parameters.total_wait_locks 
	+ 4.1547 * parameters.mean_wait_of_all 
	- 204405229.8679 * parameters.cpu_usage 
	+ 0.1408 * parameters.avg_work_of_same_past_second 
	- 0.4842 * parameters.avg_wait_of_same_past_second 
	+ 0.2723 * parameters.avg_latency_of_same_last_20 
	- 0.0702 * parameters.max_latency_of_same_last_50 
	+ 383772956.1057;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM197(work_wait &parameters) {
  double actual_remaining = 
	0.9923 * parameters.work_so_far 
	+ 0.8644 * parameters.wait_so_far 
	- 3039250.1286 * parameters.num_locks_so_far 
	- 2118671.8574 * parameters.total_wait_locks 
	+ 11.283 * parameters.mean_wait_of_all 
	- 46222.1359 * parameters.cpu_usage 
	+ 0.3798 * parameters.avg_work_of_same_past_second 
	- 0.025 * parameters.avg_wait_of_same_past_second 
	+ 0.2599 * parameters.avg_latency_of_same_last_20 
	- 0.1116 * parameters.max_latency_of_same_last_50 
	+ 80729132.8561;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM198(work_wait &parameters) {
  double actual_remaining = 
	1.0849 * parameters.work_so_far 
	+ 0.9185 * parameters.wait_so_far 
	+ 1657215.5779 * parameters.num_locks_so_far 
	+ 602753.5933 * parameters.total_wait_locks 
	- 3.2235 * parameters.mean_wait_of_all 
	+ 58510378.2886 * parameters.cpu_usage 
	- 0.1558 * parameters.avg_work_of_same_past_second 
	+ 0.4376 * parameters.avg_wait_of_same_past_second 
	+ 0.011 * parameters.avg_latency_of_same_last_20 
	- 0.0514 * parameters.max_latency_of_same_last_50 
	- 37869627.6348;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM199(work_wait &parameters) {
  double actual_remaining = 
	0.179 * parameters.work_so_far 
	+ 0.2609 * parameters.wait_so_far 
	+ 1657215.5779 * parameters.num_locks_so_far 
	+ 2020112.8507 * parameters.total_wait_locks 
	- 11.4956 * parameters.mean_wait_of_all 
	+ 58510378.2886 * parameters.cpu_usage 
	+ 0.756 * parameters.avg_work_of_same_past_second 
	+ 0.5315 * parameters.avg_wait_of_same_past_second 
	+ 0.011 * parameters.avg_latency_of_same_last_20 
	- 0.2425 * parameters.max_latency_of_same_last_50 
	+ 288541495.8041;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM200(work_wait &parameters) {
  double actual_remaining = 
	1.531 * parameters.work_so_far 
	+ 0.8796 * parameters.wait_so_far 
	+ 1105340.4031 * parameters.num_locks_so_far 
	+ 144231.252 * parameters.total_wait_locks 
	- 0.7791 * parameters.mean_wait_of_all 
	+ 34544174.7393 * parameters.cpu_usage 
	+ 0.3759 * parameters.avg_work_of_same_past_second 
	+ 0.1049 * parameters.avg_wait_of_same_past_second 
	+ 0.011 * parameters.avg_latency_of_same_last_20 
	- 0.0135 * parameters.max_latency_of_same_last_50 
	+ 76447360.5688;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
tpcc_estimate(work_wait &parameters){

  if (parameters.num_locks_so_far <= 2.5) {

    if (parameters.work_so_far <= 202812) {

      if (parameters.avg_work_of_same_past_second <= 37509900) {

        if (parameters.total_wait_locks <= 387.5) {

          if (parameters.total_wait_locks <= 224.5) {

            if (parameters.total_wait_locks <= 27.5) {

              if (parameters.work_so_far <= 8455.5) {
                return tpcc_LM1(parameters);
              } else {

                if (parameters.avg_work_of_same_past_second <= 6719370) {

                  if (parameters.avg_latency_of_same_last_20 <= 31467450) {
                    return tpcc_LM2(parameters);
                  } else {

                    if (parameters.cpu_usage <= 0.872) {

                      if (parameters.wait_so_far <= 10489647.5) {
                        return tpcc_LM3(parameters);
                      } else {

                        if (parameters.wait_so_far <= 46538647) {

                          if (parameters.cpu_usage <= 0.865) {
                            return tpcc_LM4(parameters);
                          } else {
                            return tpcc_LM5(parameters);
                          }
                        } else {
                          return tpcc_LM6(parameters);
                        }
                      }
                    } else {
                      return tpcc_LM7(parameters);
                    }
                  }
                } else {
                  return tpcc_LM8(parameters);
                }
              }
            } else {

              if (parameters.mean_wait_of_all <= 31213250) {

                if (parameters.mean_wait_of_all <= 28309450) {

                  if (parameters.avg_work_of_same_past_second <= 12032000) {

                    if (parameters.cpu_usage <= 0.905) {

                      if (parameters.work_so_far <= 12452) {
                        return tpcc_LM9(parameters);
                      } else {
                        return tpcc_LM10(parameters);
                      }
                    } else {
                      return tpcc_LM11(parameters);
                    }
                  } else {

                    if (parameters.mean_wait_of_all <= 28064150) {
                      return tpcc_LM12(parameters);
                    } else {

                      if (parameters.mean_wait_of_all <= 28119000) {

                        if (parameters.work_so_far <= 23421) {

                          if (parameters.cpu_usage <= 0.956) {

                            if (parameters.avg_work_of_same_past_second <= 16295050) {
                              return tpcc_LM13(parameters);
                            } else {
                              return tpcc_LM14(parameters);
                            }
                          } else {
                            return tpcc_LM15(parameters);
                          }
                        } else {
                          return tpcc_LM16(parameters);
                        }
                      } else {
                        return tpcc_LM17(parameters);
                      }
                    }
                  }
                } else {

                  if (parameters.avg_work_of_same_past_second <= 10408350) {

                    if (parameters.mean_wait_of_all <= 28661650) {
                      return tpcc_LM18(parameters);
                    } else {

                      if (parameters.total_wait_locks <= 40.5) {

                        if (parameters.avg_latency_of_same_last_20 <= 29040400) {
                          return tpcc_LM19(parameters);
                        } else {

                          if (parameters.work_so_far <= 16080.5) {

                            if (parameters.total_wait_locks <= 36.5) {

                              if (parameters.cpu_usage <= 0.829) {
                                return tpcc_LM20(parameters);
                              } else {
                                return tpcc_LM21(parameters);
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
                    }
                  } else {

                    if (parameters.work_so_far <= 25506) {

                      if (parameters.avg_work_of_same_past_second <= 15763100) {
                        return tpcc_LM25(parameters);
                      } else {
                        return tpcc_LM26(parameters);
                      }
                    } else {
                      return tpcc_LM27(parameters);
                    }
                  }
                }
              } else {

                if (parameters.total_wait_locks <= 78.5) {

                  if (parameters.max_latency_of_same_last_50 <= 299144000) {

                    if (parameters.cpu_usage <= 0.952) {

                      if (parameters.avg_wait_of_same_past_second <= 44815550) {

                        if (parameters.avg_wait_of_same_past_second <= 29964400) {
                          return tpcc_LM28(parameters);
                        } else {

                          if (parameters.avg_work_of_same_past_second <= 8937315) {
                            return tpcc_LM29(parameters);
                          } else {

                            if (parameters.mean_wait_of_all <= 33586650) {

                              if (parameters.work_so_far <= 13025.5) {
                                return tpcc_LM30(parameters);
                              } else {
                                return tpcc_LM31(parameters);
                              }
                            } else {
                              return tpcc_LM32(parameters);
                            }
                          }
                        }
                      } else {
                        return tpcc_LM33(parameters);
                      }
                    } else {
                      return tpcc_LM34(parameters);
                    }
                  } else {
                    return tpcc_LM35(parameters);
                  }
                } else {

                  if (parameters.work_so_far <= 39144.5) {

                    if (parameters.wait_so_far <= 195852) {
                      return tpcc_LM36(parameters);
                    } else {

                      if (parameters.mean_wait_of_all <= 46554100) {

                        if (parameters.avg_wait_of_same_past_second <= 295101000) {

                          if (parameters.mean_wait_of_all <= 41022300) {

                            if (parameters.avg_wait_of_same_past_second <= 218716000) {
                              return tpcc_LM37(parameters);
                            } else {
                              return tpcc_LM38(parameters);
                            }
                          } else {

                            if (parameters.avg_latency_of_same_last_20 <= 385616000) {

                              if (parameters.wait_so_far <= 76721043.5) {
                                return tpcc_LM39(parameters);
                              } else {
                                return tpcc_LM40(parameters);
                              }
                            } else {
                              return tpcc_LM41(parameters);
                            }
                          }
                        } else {

                          if (parameters.max_latency_of_same_last_50 <= 1312725000) {

                            if (parameters.work_so_far <= 32355) {
                              return tpcc_LM42(parameters);
                            } else {

                              if (parameters.avg_latency_of_same_last_20 <= 250952000) {
                                return tpcc_LM43(parameters);
                              } else {

                                if (parameters.max_latency_of_same_last_50 <= 1105345000) {
                                  return tpcc_LM44(parameters);
                                } else {
                                  return tpcc_LM45(parameters);
                                }
                              }
                            }
                          } else {

                            if (parameters.work_so_far <= 31931.5) {

                              if (parameters.work_so_far <= 30812) {

                                if (parameters.avg_wait_of_same_past_second <= 399050500) {
                                  return tpcc_LM46(parameters);
                                } else {

                                  if (parameters.mean_wait_of_all <= 36022850) {
                                    return tpcc_LM47(parameters);
                                  } else {
                                    return tpcc_LM48(parameters);
                                  }
                                }
                              } else {

                                if (parameters.avg_work_of_same_past_second <= 24907550) {
                                  return tpcc_LM49(parameters);
                                } else {
                                  return tpcc_LM50(parameters);
                                }
                              }
                            } else {
                              return tpcc_LM51(parameters);
                            }
                          }
                        }
                      } else {

                        if (parameters.avg_wait_of_same_past_second <= 253672000) {
                          return tpcc_LM52(parameters);
                        } else {

                          if (parameters.avg_latency_of_same_last_20 <= 415905000) {
                            return tpcc_LM53(parameters);
                          } else {
                            return tpcc_LM54(parameters);
                          }
                        }
                      }
                    }
                  } else {

                    if (parameters.avg_wait_of_same_past_second <= 355681500) {
                      return tpcc_LM55(parameters);
                    } else {

                      if (parameters.avg_work_of_same_past_second <= 24069450) {

                        if (parameters.mean_wait_of_all <= 48480450) {
                          return tpcc_LM56(parameters);
                        } else {
                          return tpcc_LM57(parameters);
                        }
                      } else {

                        if (parameters.avg_wait_of_same_past_second <= 389564500) {
                          return tpcc_LM58(parameters);
                        } else {
                          return tpcc_LM59(parameters);
                        }
                      }
                    }
                  }
                }
              }
            }
          } else {

            if (parameters.avg_work_of_same_past_second <= 23190550) {

              if (parameters.max_latency_of_same_last_50 <= 1155120000) {

                if (parameters.wait_so_far <= 53263864) {

                  if (parameters.avg_wait_of_same_past_second <= 317938500) {

                    if (parameters.avg_work_of_same_past_second <= 22563050) {

                      if (parameters.avg_work_of_same_past_second <= 22339550) {
                        return tpcc_LM60(parameters);
                      } else {
                        return tpcc_LM61(parameters);
                      }
                    } else {

                      if (parameters.max_latency_of_same_last_50 <= 1023687000) {

                        if (parameters.wait_so_far <= 850874) {
                          return tpcc_LM62(parameters);
                        } else {
                          return tpcc_LM63(parameters);
                        }
                      } else {
                        return tpcc_LM64(parameters);
                      }
                    }
                  } else {

                    if (parameters.mean_wait_of_all <= 68239650) {

                      if (parameters.max_latency_of_same_last_50 <= 832726000) {
                        return tpcc_LM65(parameters);
                      } else {
                        return tpcc_LM66(parameters);
                      }
                    } else {
                      return tpcc_LM67(parameters);
                    }
                  }
                } else {
                  return tpcc_LM68(parameters);
                }
              } else {

                if (parameters.wait_so_far <= 189438184) {
                  return tpcc_LM69(parameters);
                } else {

                  if (parameters.cpu_usage <= 0.969) {

                    if (parameters.avg_latency_of_same_last_20 <= 633133500) {

                      if (parameters.wait_so_far <= 461558217) {
                        return tpcc_LM70(parameters);
                      } else {
                        return tpcc_LM71(parameters);
                      }
                    } else {

                      if (parameters.max_latency_of_same_last_50 <= 1583525000) {
                        return tpcc_LM72(parameters);
                      } else {
                        return tpcc_LM73(parameters);
                      }
                    }
                  } else {

                    if (parameters.avg_work_of_same_past_second <= 21967600) {
                      return tpcc_LM74(parameters);
                    } else {

                      if (parameters.work_so_far <= 38843.5) {

                        if (parameters.wait_so_far <= 319974048.5) {
                          return tpcc_LM75(parameters);
                        } else {
                          return tpcc_LM76(parameters);
                        }
                      } else {
                        return tpcc_LM77(parameters);
                      }
                    }
                  }
                }
              }
            } else {

              if (parameters.work_so_far <= 37359) {
                return tpcc_LM78(parameters);
              } else {

                if (parameters.cpu_usage <= 0.972) {
                  return tpcc_LM79(parameters);
                } else {
                  return tpcc_LM80(parameters);
                }
              }
            }
          }
        } else {

          if (parameters.avg_work_of_same_past_second <= 25035150) {

            if (parameters.mean_wait_of_all <= 133887000) {
              return tpcc_LM81(parameters);
            } else {

              if (parameters.mean_wait_of_all <= 137705500) {

                if (parameters.avg_latency_of_same_last_20 <= 300975000) {

                  if (parameters.mean_wait_of_all <= 133969000) {

                    if (parameters.wait_so_far <= 12342) {
                      return tpcc_LM82(parameters);
                    } else {
                      return tpcc_LM83(parameters);
                    }
                  } else {

                    if (parameters.total_wait_locks <= 622.5) {
                      return tpcc_LM84(parameters);
                    } else {

                      if (parameters.total_wait_locks <= 626.5) {

                        if (parameters.avg_work_of_same_past_second <= 22583500) {
                          return tpcc_LM85(parameters);
                        } else {
                          return tpcc_LM86(parameters);
                        }
                      } else {
                        return tpcc_LM87(parameters);
                      }
                    }
                  }
                } else {

                  if (parameters.wait_so_far <= 166849997.5) {

                    if (parameters.max_latency_of_same_last_50 <= 1779225000) {

                      if (parameters.total_wait_locks <= 610.5) {
                        return tpcc_LM88(parameters);
                      } else {

                        if (parameters.total_wait_locks <= 627.5) {

                          if (parameters.wait_so_far <= 76639235.5) {
                            return tpcc_LM89(parameters);
                          } else {
                            return tpcc_LM90(parameters);
                          }
                        } else {
                          return tpcc_LM91(parameters);
                        }
                      }
                    } else {
                      return tpcc_LM92(parameters);
                    }
                  } else {
                    return tpcc_LM93(parameters);
                  }
                }
              } else {

                if (parameters.mean_wait_of_all <= 142309500) {
                  return tpcc_LM94(parameters);
                } else {

                  if (parameters.work_so_far <= 32824) {

                    if (parameters.total_wait_locks <= 661.5) {
                      return tpcc_LM95(parameters);
                    } else {

                      if (parameters.work_so_far <= 31716.5) {
                        return tpcc_LM96(parameters);
                      } else {
                        return tpcc_LM97(parameters);
                      }
                    }
                  } else {
                    return tpcc_LM98(parameters);
                  }
                }
              }
            }
          } else {

            if (parameters.total_wait_locks <= 501.5) {
              return tpcc_LM99(parameters);
            } else {
              return tpcc_LM100(parameters);
            }
          }
        }
      } else {

        if (parameters.avg_work_of_same_past_second <= 54718650) {

          if (parameters.avg_wait_of_same_past_second <= 380159000) {
            return tpcc_LM101(parameters);
          } else {

            if (parameters.cpu_usage <= 0.883) {
              return tpcc_LM102(parameters);
            } else {

              if (parameters.avg_latency_of_same_last_20 <= 439947000) {

                if (parameters.total_wait_locks <= 613.5) {

                  if (parameters.mean_wait_of_all <= 94953350) {
                    return tpcc_LM103(parameters);
                  } else {

                    if (parameters.avg_work_of_same_past_second <= 42688300) {

                      if (parameters.avg_latency_of_same_last_20 <= 304007000) {
                        return tpcc_LM104(parameters);
                      } else {
                        return tpcc_LM105(parameters);
                      }
                    } else {
                      return tpcc_LM106(parameters);
                    }
                  }
                } else {

                  if (parameters.mean_wait_of_all <= 143006500) {
                    return tpcc_LM107(parameters);
                  } else {
                    return tpcc_LM108(parameters);
                  }
                }
              } else {

                if (parameters.wait_so_far <= 219840496.5) {

                  if (parameters.wait_so_far <= 20849.5) {

                    if (parameters.avg_wait_of_same_past_second <= 449104500) {

                      if (parameters.max_latency_of_same_last_50 <= 1362690000) {

                        if (parameters.wait_so_far <= 12781.5) {

                          if (parameters.avg_latency_of_same_last_20 <= 487270500) {
                            return tpcc_LM109(parameters);
                          } else {

                            if (parameters.cpu_usage <= 0.902) {
                              return tpcc_LM110(parameters);
                            } else {
                              return tpcc_LM111(parameters);
                            }
                          }
                        } else {
                          return tpcc_LM112(parameters);
                        }
                      } else {
                        return tpcc_LM113(parameters);
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
              }
            }
          }
        } else {

          if (parameters.avg_wait_of_same_past_second <= 297178500) {

            if (parameters.wait_so_far <= 622496) {
              return tpcc_LM117(parameters);
            } else {
              return tpcc_LM118(parameters);
            }
          } else {
            return tpcc_LM119(parameters);
          }
        }
      }
    } else {

      if (parameters.wait_so_far <= 298731194.5) {

        if (parameters.avg_work_of_same_past_second <= 39581750) {

          if (parameters.wait_so_far <= 130032426) {

            if (parameters.avg_wait_of_same_past_second <= 444309500) {
              return tpcc_LM120(parameters);
            } else {

              if (parameters.mean_wait_of_all <= 133889000) {

                if (parameters.work_so_far <= 2319538) {
                  return tpcc_LM121(parameters);
                } else {

                  if (parameters.avg_work_of_same_past_second <= 35628750) {

                    if (parameters.avg_work_of_same_past_second <= 30277800) {
                      return tpcc_LM122(parameters);
                    } else {
                      return tpcc_LM123(parameters);
                    }
                  } else {

                    if (parameters.max_latency_of_same_last_50 <= 1425890000) {
                      return tpcc_LM124(parameters);
                    } else {
                      return tpcc_LM125(parameters);
                    }
                  }
                }
              } else {

                if (parameters.avg_work_of_same_past_second <= 31674500) {

                  if (parameters.avg_latency_of_same_last_20 <= 280989000) {
                    return tpcc_LM126(parameters);
                  } else {
                    return tpcc_LM127(parameters);
                  }
                } else {
                  return tpcc_LM128(parameters);
                }
              }
            }
          } else {
            return tpcc_LM129(parameters);
          }
        } else {

          if (parameters.avg_wait_of_same_past_second <= 364717000) {

            if (parameters.avg_wait_of_same_past_second <= 310139500) {

              if (parameters.avg_work_of_same_past_second <= 679713500) {
                return tpcc_LM130(parameters);
              } else {

                if (parameters.work_so_far <= 5074150) {
                  return tpcc_LM131(parameters);
                } else {
                  return tpcc_LM132(parameters);
                }
              }
            } else {

              if (parameters.avg_latency_of_same_last_20 <= 452559000) {

                if (parameters.avg_latency_of_same_last_20 <= 249647500) {

                  if (parameters.avg_latency_of_same_last_20 <= 217085500) {
                    return tpcc_LM133(parameters);
                  } else {
                    return tpcc_LM134(parameters);
                  }
                } else {
                  return tpcc_LM135(parameters);
                }
              } else {

                if (parameters.wait_so_far <= 2033046) {
                  return tpcc_LM136(parameters);
                } else {

                  if (parameters.wait_so_far <= 124312467) {

                    if (parameters.avg_work_of_same_past_second <= 50639000) {
                      return tpcc_LM137(parameters);
                    } else {
                      return tpcc_LM138(parameters);
                    }
                  } else {
                    return tpcc_LM139(parameters);
                  }
                }
              }
            }
          } else {
            return tpcc_LM140(parameters);
          }
        }
      } else {

        if (parameters.wait_so_far <= 686599344.5) {

          if (parameters.wait_so_far <= 486762577.5) {
            return tpcc_LM141(parameters);
          } else {
            return tpcc_LM142(parameters);
          }
        } else {

          if (parameters.wait_so_far <= 1127977614.5) {
            return tpcc_LM143(parameters);
          } else {
            return tpcc_LM144(parameters);
          }
        }
      }
    }
  } else {

    if (parameters.total_wait_locks <= 164.5) {

      if (parameters.work_so_far <= 74432318) {

        if (parameters.total_wait_locks <= 86.5) {
          return tpcc_LM145(parameters);
        } else {

          if (parameters.work_so_far <= 91127) {

            if (parameters.wait_so_far <= 8453975) {

              if (parameters.work_so_far <= 48962) {
                return tpcc_LM146(parameters);
              } else {

                if (parameters.avg_latency_of_same_last_20 <= 148952000) {

                  if (parameters.total_wait_locks <= 98.5) {
                    return tpcc_LM147(parameters);
                  } else {
                    return tpcc_LM148(parameters);
                  }
                } else {

                  if (parameters.avg_work_of_same_past_second <= 191114000) {
                    return tpcc_LM149(parameters);
                  } else {
                    return tpcc_LM150(parameters);
                  }
                }
              }
            } else {
              return tpcc_LM151(parameters);
            }
          } else {

            if (parameters.total_wait_locks <= 108.5) {

              if (parameters.work_so_far <= 30985026) {
                return tpcc_LM152(parameters);
              } else {
                return tpcc_LM153(parameters);
              }
            } else {

              if (parameters.wait_so_far <= 289926132) {

                if (parameters.num_locks_so_far <= 16.5) {
                  return tpcc_LM154(parameters);
                } else {
                  return tpcc_LM155(parameters);
                }
              } else {

                if (parameters.num_locks_so_far <= 4.5) {
                  return tpcc_LM156(parameters);
                } else {

                  if (parameters.wait_so_far <= 658999683) {

                    if (parameters.num_locks_so_far <= 10.5) {
                      return tpcc_LM157(parameters);
                    } else {
                      return tpcc_LM158(parameters);
                    }
                  } else {
                    return tpcc_LM159(parameters);
                  }
                }
              }
            }
          }
        }
      } else {
        return tpcc_LM160(parameters);
      }
    } else {

      if (parameters.work_so_far <= 802376.5) {

        if (parameters.wait_so_far <= 246262715) {

          if (parameters.mean_wait_of_all <= 92415100) {
            return tpcc_LM161(parameters);
          } else {

            if (parameters.work_so_far <= 47294.5) {
              return tpcc_LM162(parameters);
            } else {

              if (parameters.max_latency_of_same_last_50 <= 1008270000) {

                if (parameters.wait_so_far <= 290164.5) {

                  if (parameters.avg_wait_of_same_past_second <= 202852500) {
                    return tpcc_LM163(parameters);
                  } else {
                    return tpcc_LM164(parameters);
                  }
                } else {

                  if (parameters.avg_work_of_same_past_second <= 267895000) {
                    return tpcc_LM165(parameters);
                  } else {

                    if (parameters.wait_so_far <= 10650115) {

                      if (parameters.max_latency_of_same_last_50 <= 779229000) {

                        if (parameters.avg_wait_of_same_past_second <= 253326500) {
                          return tpcc_LM166(parameters);
                        } else {
                          return tpcc_LM167(parameters);
                        }
                      } else {
                        return tpcc_LM168(parameters);
                      }
                    } else {
                      return tpcc_LM169(parameters);
                    }
                  }
                }
              } else {
                return tpcc_LM170(parameters);
              }
            }
          }
        } else {
          return tpcc_LM171(parameters);
        }
      } else {

        if (parameters.wait_so_far <= 395841223.5) {

          if (parameters.work_so_far <= 91598567) {

            if (parameters.num_locks_so_far <= 13.5) {

              if (parameters.avg_work_of_same_past_second <= 188875000) {
                return tpcc_LM172(parameters);
              } else {

                if (parameters.work_so_far <= 6008535.5) {
                  return tpcc_LM173(parameters);
                } else {

                  if (parameters.num_locks_so_far <= 9.5) {
                    return tpcc_LM174(parameters);
                  } else {
                    return tpcc_LM175(parameters);
                  }
                }
              }
            } else {

              if (parameters.wait_so_far <= 136368731) {

                if (parameters.work_so_far <= 35758735) {

                  if (parameters.num_locks_so_far <= 23.5) {

                    if (parameters.work_so_far <= 11124003) {
                      return tpcc_LM176(parameters);
                    } else {
                      return tpcc_LM177(parameters);
                    }
                  } else {
                    return tpcc_LM178(parameters);
                  }
                } else {
                  return tpcc_LM179(parameters);
                }
              } else {
                return tpcc_LM180(parameters);
              }
            }
          } else {

            if (parameters.avg_work_of_same_past_second <= 352387000) {

              if (parameters.work_so_far <= 392055884) {

                if (parameters.num_locks_so_far <= 17.5) {

                  if (parameters.work_so_far <= 210327559) {

                    if (parameters.wait_so_far <= 77447080) {
                      return tpcc_LM181(parameters);
                    } else {

                      if (parameters.num_locks_so_far <= 4.5) {

                        if (parameters.avg_wait_of_same_past_second <= 262192500) {
                          return tpcc_LM182(parameters);
                        } else {
                          return tpcc_LM183(parameters);
                        }
                      } else {
                        return tpcc_LM184(parameters);
                      }
                    }
                  } else {

                    if (parameters.avg_work_of_same_past_second <= 242571000) {

                      if (parameters.cpu_usage <= 0.931) {
                        return tpcc_LM185(parameters);
                      } else {
                        return tpcc_LM186(parameters);
                      }
                    } else {
                      return tpcc_LM187(parameters);
                    }
                  }
                } else {
                  return tpcc_LM188(parameters);
                }
              } else {
                return tpcc_LM189(parameters);
              }
            } else {
              return tpcc_LM190(parameters);
            }
          }
        } else {

          if (parameters.wait_so_far <= 830865571.5) {

            if (parameters.num_locks_so_far <= 4.5) {
              return tpcc_LM191(parameters);
            } else {

              if (parameters.work_so_far <= 42850065.5) {

                if (parameters.avg_work_of_same_past_second <= 177374500) {
                  return tpcc_LM192(parameters);
                } else {

                  if (parameters.num_locks_so_far <= 11.5) {

                    if (parameters.avg_latency_of_same_last_20 <= 411641000) {
                      return tpcc_LM193(parameters);
                    } else {

                      if (parameters.num_locks_so_far <= 9.5) {
                        return tpcc_LM194(parameters);
                      } else {
                        return tpcc_LM195(parameters);
                      }
                    }
                  } else {
                    return tpcc_LM196(parameters);
                  }
                }
              } else {
                return tpcc_LM197(parameters);
              }
            }
          } else {

            if (parameters.num_locks_so_far <= 4.5) {

              if (parameters.avg_work_of_same_past_second <= 133032850) {
                return tpcc_LM198(parameters);
              } else {
                return tpcc_LM199(parameters);
              }
            } else {
              return tpcc_LM200(parameters);
            }
          }
        }
      }
    }
  }
}