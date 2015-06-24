#include "my_global.h"
#include "m5p.h"
#include "trace_tool.h"

static
double
new_order_LM1(work_wait &parameters) {
  double actual_remaining = 
	3.5601 * parameters.work_so_far 
	+ 0.8113 * parameters.wait_so_far 
	- 3938847.341 * parameters.num_locks_so_far 
	+ 936667.1636 * parameters.total_wait_locks 
	- 1.7047 * parameters.mean_wait_of_all 
	- 238878398.2045 * parameters.cpu_usage 
	- 0.0069 * parameters.avg_work_of_same_past_second 
	+ 0.0008 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0.0011 * parameters.max_latency_of_same_last_50 
	+ 326155795.1574;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM2(work_wait &parameters) {
  double actual_remaining = 
	1.1513 * parameters.work_so_far 
	+ 0.0359 * parameters.wait_so_far 
	- 4259191.3365 * parameters.num_locks_so_far 
	+ 1697786.3524 * parameters.total_wait_locks 
	- 2.4058 * parameters.mean_wait_of_all 
	- 6694121.1168 * parameters.cpu_usage 
	- 0.012 * parameters.avg_work_of_same_past_second 
	+ 0.0008 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0.1352 * parameters.max_latency_of_same_last_50 
	+ 283420406.5508;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM3(work_wait &parameters) {
  double actual_remaining = 
	5.8405 * parameters.work_so_far 
	- 0.1812 * parameters.wait_so_far 
	- 16260462.3404 * parameters.num_locks_so_far 
	+ 4849975.3648 * parameters.total_wait_locks 
	- 12.8985 * parameters.mean_wait_of_all 
	+ 79516320.6925 * parameters.cpu_usage 
	- 0.0528 * parameters.avg_work_of_same_past_second 
	+ 6.4604 * parameters.avg_wait_of_same_past_second 
	- 2.8505 * parameters.avg_latency_of_same_last_20 
	- 0.232 * parameters.max_latency_of_same_last_50 
	+ 745154838.4486;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM4(work_wait &parameters) {
  double actual_remaining = 
	0.6964 * parameters.work_so_far 
	- 0.2103 * parameters.wait_so_far 
	- 5233132.2058 * parameters.num_locks_so_far 
	+ 379363.7928 * parameters.total_wait_locks 
	- 2.239 * parameters.mean_wait_of_all 
	+ 91236230.7321 * parameters.cpu_usage 
	- 0.0528 * parameters.avg_work_of_same_past_second 
	+ 7.0689 * parameters.avg_wait_of_same_past_second 
	+ 0.1854 * parameters.avg_latency_of_same_last_20 
	+ 0.0185 * parameters.max_latency_of_same_last_50 
	+ 404806064.0624;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM5(work_wait &parameters) {
  double actual_remaining = 
	0.6881 * parameters.work_so_far 
	+ 0.0868 * parameters.wait_so_far 
	- 941233.0685 * parameters.num_locks_so_far 
	+ 591520.2714 * parameters.total_wait_locks 
	- 4.861 * parameters.mean_wait_of_all 
	- 11312982.1145 * parameters.cpu_usage 
	- 0.0528 * parameters.avg_work_of_same_past_second 
	+ 1.3662 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0.0504 * parameters.max_latency_of_same_last_50 
	+ 369605304.9207;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM6(work_wait &parameters) {
  double actual_remaining = 
	1.1887 * parameters.work_so_far 
	+ 0.7407 * parameters.wait_so_far 
	- 1173354.337 * parameters.num_locks_so_far 
	+ 814900.5127 * parameters.total_wait_locks 
	- 1.7344 * parameters.mean_wait_of_all 
	- 11312982.1145 * parameters.cpu_usage 
	+ 3.4827 * parameters.avg_work_of_same_past_second 
	+ 1.3662 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0.0504 * parameters.max_latency_of_same_last_50 
	+ 61518224.1163;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM7(work_wait &parameters) {
  double actual_remaining = 
	1.1774 * parameters.work_so_far 
	+ 0.626 * parameters.wait_so_far 
	- 2903698.006 * parameters.num_locks_so_far 
	+ 258156.5781 * parameters.total_wait_locks 
	- 11.2265 * parameters.mean_wait_of_all 
	- 10327716.9244 * parameters.cpu_usage 
	- 1.5319 * parameters.avg_work_of_same_past_second 
	+ 1.5789 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0.0024 * parameters.max_latency_of_same_last_50 
	+ 524337443.8682;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM8(work_wait &parameters) {
  double actual_remaining = 
	8.2922 * parameters.work_so_far 
	- 1.2527 * parameters.wait_so_far 
	- 8535415.6574 * parameters.num_locks_so_far 
	+ 1235908.1043 * parameters.total_wait_locks 
	- 0.539 * parameters.mean_wait_of_all 
	+ 340257333.1986 * parameters.cpu_usage 
	- 0.328 * parameters.avg_work_of_same_past_second 
	+ 0.1187 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0.0024 * parameters.max_latency_of_same_last_50 
	- 162421303.4888;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM9(work_wait &parameters) {
  double actual_remaining = 
	2.862 * parameters.work_so_far 
	- 0.0124 * parameters.wait_so_far 
	- 3340562.1525 * parameters.num_locks_so_far 
	+ 37740082.8096 * parameters.total_wait_locks 
	- 0.539 * parameters.mean_wait_of_all 
	- 10327716.9244 * parameters.cpu_usage 
	- 1.2156 * parameters.avg_work_of_same_past_second 
	+ 0.1187 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0.0024 * parameters.max_latency_of_same_last_50 
	- 5474919051.9715;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM10(work_wait &parameters) {
  double actual_remaining = 
	2.862 * parameters.work_so_far 
	- 0.0124 * parameters.wait_so_far 
	- 3340562.1525 * parameters.num_locks_so_far 
	+ 11349398.7823 * parameters.total_wait_locks 
	- 0.539 * parameters.mean_wait_of_all 
	- 10327716.9244 * parameters.cpu_usage 
	- 1.136 * parameters.avg_work_of_same_past_second 
	+ 0.1187 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0.0024 * parameters.max_latency_of_same_last_50 
	- 1323811324.304;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM11(work_wait &parameters) {
  double actual_remaining = 
	1.0583 * parameters.work_so_far 
	- 0.0671 * parameters.wait_so_far 
	- 7658315.4155 * parameters.num_locks_so_far 
	+ 853393.4124 * parameters.total_wait_locks 
	- 0.539 * parameters.mean_wait_of_all 
	- 10327716.9244 * parameters.cpu_usage 
	- 0.2779 * parameters.avg_work_of_same_past_second 
	+ 0.1187 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0.0024 * parameters.max_latency_of_same_last_50 
	+ 376195734.8318;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM12(work_wait &parameters) {
  double actual_remaining = 
	0.8018 * parameters.work_so_far 
	+ 0.3796 * parameters.wait_so_far 
	- 533711.8634 * parameters.num_locks_so_far 
	+ 427440.3435 * parameters.total_wait_locks 
	- 4.0169 * parameters.mean_wait_of_all 
	- 10327716.9244 * parameters.cpu_usage 
	- 1.7755 * parameters.avg_work_of_same_past_second 
	+ 1.4322 * parameters.avg_wait_of_same_past_second 
	+ 0.2122 * parameters.avg_latency_of_same_last_20 
	- 0.0652 * parameters.max_latency_of_same_last_50 
	+ 499838001.8321;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM13(work_wait &parameters) {
  double actual_remaining = 
	1.1914 * parameters.work_so_far 
	+ 0.522 * parameters.wait_so_far 
	- 2417477.4233 * parameters.num_locks_so_far 
	+ 214929.8748 * parameters.total_wait_locks 
	- 0.4923 * parameters.mean_wait_of_all 
	- 18339232.9448 * parameters.cpu_usage 
	- 0.0563 * parameters.avg_work_of_same_past_second 
	+ 0.0398 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0.0024 * parameters.max_latency_of_same_last_50 
	+ 178104174.437;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM14(work_wait &parameters) {
  double actual_remaining = 
	0.0929 * parameters.work_so_far 
	- 4.7565 * parameters.wait_so_far 
	- 56132804.1497 * parameters.num_locks_so_far 
	+ 676950.6968 * parameters.total_wait_locks 
	- 2.1332 * parameters.mean_wait_of_all 
	- 328651700.6913 * parameters.cpu_usage 
	- 0.0008 * parameters.avg_work_of_same_past_second 
	- 0.0028 * parameters.avg_wait_of_same_past_second 
	+ 0.0034 * parameters.avg_latency_of_same_last_20 
	- 0.0704 * parameters.max_latency_of_same_last_50 
	+ 895194782.3449;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM15(work_wait &parameters) {
  double actual_remaining = 
	0.0929 * parameters.work_so_far 
	+ 0.0442 * parameters.wait_so_far 
	- 2253019.5719 * parameters.num_locks_so_far 
	+ 3071968.5783 * parameters.total_wait_locks 
	- 10.7815 * parameters.mean_wait_of_all 
	- 376883566.6874 * parameters.cpu_usage 
	- 0.0008 * parameters.avg_work_of_same_past_second 
	- 0.0028 * parameters.avg_wait_of_same_past_second 
	+ 0.0034 * parameters.avg_latency_of_same_last_20 
	- 0.0031 * parameters.max_latency_of_same_last_50 
	+ 514675123.7525;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM16(work_wait &parameters) {
  double actual_remaining = 
	0.0929 * parameters.work_so_far 
	- 2.1387 * parameters.wait_so_far 
	- 1923582.2751 * parameters.num_locks_so_far 
	- 169943.85 * parameters.total_wait_locks 
	+ 1.4567 * parameters.mean_wait_of_all 
	- 371225371.2999 * parameters.cpu_usage 
	- 0.0448 * parameters.avg_work_of_same_past_second 
	- 0.0082 * parameters.avg_wait_of_same_past_second 
	- 0.1332 * parameters.avg_latency_of_same_last_20 
	- 0.0007 * parameters.max_latency_of_same_last_50 
	+ 854789085.4395;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM17(work_wait &parameters) {
  double actual_remaining = 
	284.3886 * parameters.work_so_far 
	- 0.3532 * parameters.wait_so_far 
	- 1923582.2751 * parameters.num_locks_so_far 
	+ 1958146.6935 * parameters.total_wait_locks 
	- 16.1907 * parameters.mean_wait_of_all 
	- 376450844.3286 * parameters.cpu_usage 
	- 0.0448 * parameters.avg_work_of_same_past_second 
	- 0.0082 * parameters.avg_wait_of_same_past_second 
	+ 1.1776 * parameters.avg_latency_of_same_last_20 
	- 0.132 * parameters.max_latency_of_same_last_50 
	+ 1575748578.1173;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM18(work_wait &parameters) {
  double actual_remaining = 
	0.0929 * parameters.work_so_far 
	- 0.3532 * parameters.wait_so_far 
	- 1923582.2751 * parameters.num_locks_so_far 
	+ 743835.1579 * parameters.total_wait_locks 
	- 6.1064 * parameters.mean_wait_of_all 
	- 376450844.3286 * parameters.cpu_usage 
	- 0.0448 * parameters.avg_work_of_same_past_second 
	- 6.453 * parameters.avg_wait_of_same_past_second 
	- 0.1354 * parameters.avg_latency_of_same_last_20 
	- 0.057 * parameters.max_latency_of_same_last_50 
	+ 2622069433.2008;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM19(work_wait &parameters) {
  double actual_remaining = 
	0.0929 * parameters.work_so_far 
	+ 1.7067 * parameters.wait_so_far 
	- 1923582.2751 * parameters.num_locks_so_far 
	- 2141088.2597 * parameters.total_wait_locks 
	+ 28.6786 * parameters.mean_wait_of_all 
	- 177777484.9668 * parameters.cpu_usage 
	- 0.0448 * parameters.avg_work_of_same_past_second 
	- 0.0082 * parameters.avg_wait_of_same_past_second 
	- 0.0523 * parameters.avg_latency_of_same_last_20 
	- 0.0007 * parameters.max_latency_of_same_last_50 
	- 1695089246.7239;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM20(work_wait &parameters) {
  double actual_remaining = 
	30.6789 * parameters.work_so_far 
	+ 0.0189 * parameters.wait_so_far 
	- 1687294.9173 * parameters.num_locks_so_far 
	+ 1556655.2527 * parameters.total_wait_locks 
	- 8.535 * parameters.mean_wait_of_all 
	- 8246713.2246 * parameters.cpu_usage 
	- 0.0162 * parameters.avg_work_of_same_past_second 
	+ 1.9243 * parameters.avg_wait_of_same_past_second 
	+ 0.0075 * parameters.avg_latency_of_same_last_20 
	- 0.0007 * parameters.max_latency_of_same_last_50 
	+ 128230959.7019;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM21(work_wait &parameters) {
  double actual_remaining = 
	87.8975 * parameters.work_so_far 
	+ 0.0189 * parameters.wait_so_far 
	- 1687294.9173 * parameters.num_locks_so_far 
	- 363421.4529 * parameters.total_wait_locks 
	- 0.491 * parameters.mean_wait_of_all 
	- 8246713.2246 * parameters.cpu_usage 
	- 0.0162 * parameters.avg_work_of_same_past_second 
	+ 0.1243 * parameters.avg_wait_of_same_past_second 
	+ 0.0075 * parameters.avg_latency_of_same_last_20 
	+ 0.1124 * parameters.max_latency_of_same_last_50 
	+ 594293262.026;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM22(work_wait &parameters) {
  double actual_remaining = 
	49.6523 * parameters.work_so_far 
	+ 0.0189 * parameters.wait_so_far 
	- 24749403.6775 * parameters.num_locks_so_far 
	+ 20561.6663 * parameters.total_wait_locks 
	- 0.1624 * parameters.mean_wait_of_all 
	- 504169819.6024 * parameters.cpu_usage 
	- 0.0162 * parameters.avg_work_of_same_past_second 
	- 0.0082 * parameters.avg_wait_of_same_past_second 
	+ 0.0122 * parameters.avg_latency_of_same_last_20 
	- 0.0973 * parameters.max_latency_of_same_last_50 
	+ 948168856.5025;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM23(work_wait &parameters) {
  double actual_remaining = 
	38.2694 * parameters.work_so_far 
	+ 328.3734 * parameters.wait_so_far 
	- 48338088.2944 * parameters.num_locks_so_far 
	+ 1323476.0602 * parameters.total_wait_locks 
	- 6.931 * parameters.mean_wait_of_all 
	- 3432132.2194 * parameters.cpu_usage 
	+ 0.0245 * parameters.avg_work_of_same_past_second 
	- 0.0067 * parameters.avg_wait_of_same_past_second 
	+ 0.0081 * parameters.avg_latency_of_same_last_20 
	- 0.0007 * parameters.max_latency_of_same_last_50 
	+ 600755335.4625;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM24(work_wait &parameters) {
  double actual_remaining = 
	96.1187 * parameters.work_so_far 
	+ 744.6001 * parameters.wait_so_far 
	- 6356020.3572 * parameters.num_locks_so_far 
	+ 176807.0539 * parameters.total_wait_locks 
	- 1.0012 * parameters.mean_wait_of_all 
	- 3432132.2194 * parameters.cpu_usage 
	+ 0.0565 * parameters.avg_work_of_same_past_second 
	- 0.0067 * parameters.avg_wait_of_same_past_second 
	+ 0.0081 * parameters.avg_latency_of_same_last_20 
	- 0.0007 * parameters.max_latency_of_same_last_50 
	+ 493584477.8236;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM25(work_wait &parameters) {
  double actual_remaining = 
	0.3282 * parameters.work_so_far 
	+ 1.6108 * parameters.wait_so_far 
	- 24391409.8033 * parameters.num_locks_so_far 
	- 689100.834 * parameters.total_wait_locks 
	+ 2.6653 * parameters.mean_wait_of_all 
	- 3432132.2194 * parameters.cpu_usage 
	- 0.0008 * parameters.avg_work_of_same_past_second 
	- 0.0067 * parameters.avg_wait_of_same_past_second 
	+ 0.1382 * parameters.avg_latency_of_same_last_20 
	- 0.0007 * parameters.max_latency_of_same_last_50 
	+ 404642300.7395;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM26(work_wait &parameters) {
  double actual_remaining = 
	4.2437 * parameters.work_so_far 
	+ 0.6791 * parameters.wait_so_far 
	- 165904.0616 * parameters.num_locks_so_far 
	+ 1914.9586 * parameters.total_wait_locks 
	+ 1.0099 * parameters.mean_wait_of_all 
	- 4483751.5628 * parameters.cpu_usage 
	- 0.3353 * parameters.avg_work_of_same_past_second 
	+ 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0027 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	+ 426111760.8354;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM27(work_wait &parameters) {
  double actual_remaining = 
	1.7776 * parameters.work_so_far 
	+ 0.4697 * parameters.wait_so_far 
	+ 30598095.6038 * parameters.num_locks_so_far 
	+ 115576.9396 * parameters.total_wait_locks 
	- 0.001 * parameters.mean_wait_of_all 
	- 185239080.5235 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.2404 * parameters.avg_latency_of_same_last_20 
	- 0.0501 * parameters.max_latency_of_same_last_50 
	+ 348236452.7066;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM28(work_wait &parameters) {
  double actual_remaining = 
	9.8011 * parameters.work_so_far 
	+ 1.0534 * parameters.wait_so_far 
	- 11603090.4117 * parameters.num_locks_so_far 
	+ 2654.6715 * parameters.total_wait_locks 
	+ 0.3224 * parameters.mean_wait_of_all 
	- 204008709.8455 * parameters.cpu_usage 
	- 0.1503 * parameters.avg_work_of_same_past_second 
	+ 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0967 * parameters.avg_latency_of_same_last_20 
	- 0.0283 * parameters.max_latency_of_same_last_50 
	+ 492033972.9206;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM29(work_wait &parameters) {
  double actual_remaining = 
	1.3414 * parameters.work_so_far 
	+ 0.5296 * parameters.wait_so_far 
	+ 9210193.566 * parameters.num_locks_so_far 
	+ 863336.1206 * parameters.total_wait_locks 
	- 3.0304 * parameters.mean_wait_of_all 
	- 7258293.5453 * parameters.cpu_usage 
	- 0.0006 * parameters.avg_wait_of_same_past_second 
	+ 0.2938 * parameters.avg_latency_of_same_last_20 
	- 0.0781 * parameters.max_latency_of_same_last_50 
	+ 342030121.4409;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM30(work_wait &parameters) {
  double actual_remaining = 
	0.8624 * parameters.work_so_far 
	+ 0.7892 * parameters.wait_so_far 
	- 4797308.3366 * parameters.num_locks_so_far 
	+ 389861.4411 * parameters.total_wait_locks 
	- 1.3246 * parameters.mean_wait_of_all 
	- 210428389.2256 * parameters.cpu_usage 
	- 0.1933 * parameters.avg_wait_of_same_past_second 
	+ 0.1575 * parameters.avg_latency_of_same_last_20 
	- 0.0234 * parameters.max_latency_of_same_last_50 
	+ 586560810.6097;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM31(work_wait &parameters) {
  double actual_remaining = 
	0.9409 * parameters.work_so_far 
	+ 0.3091 * parameters.wait_so_far 
	- 685643.3822 * parameters.num_locks_so_far 
	- 348398.264 * parameters.total_wait_locks 
	+ 1.8741 * parameters.mean_wait_of_all 
	- 311883176.8667 * parameters.cpu_usage 
	- 0.8449 * parameters.avg_work_of_same_past_second 
	+ 0.78 * parameters.avg_wait_of_same_past_second 
	+ 0.1751 * parameters.avg_latency_of_same_last_20 
	- 0.0689 * parameters.max_latency_of_same_last_50 
	+ 768786492.2569;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM32(work_wait &parameters) {
  double actual_remaining = 
	1.5485 * parameters.work_so_far 
	+ 0.4125 * parameters.wait_so_far 
	- 685643.3822 * parameters.num_locks_so_far 
	- 489798.4447 * parameters.total_wait_locks 
	+ 2.6089 * parameters.mean_wait_of_all 
	- 5235127153.4921 * parameters.cpu_usage 
	- 1.2005 * parameters.avg_work_of_same_past_second 
	+ 1.12 * parameters.avg_wait_of_same_past_second 
	+ 0.2441 * parameters.avg_latency_of_same_last_20 
	- 0.0978 * parameters.max_latency_of_same_last_50 
	+ 4812394416.8216;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM33(work_wait &parameters) {
  double actual_remaining = 
	1.1276 * parameters.work_so_far 
	+ 0.6156 * parameters.wait_so_far 
	- 3387151.5719 * parameters.num_locks_so_far 
	- 603561.9642 * parameters.total_wait_locks 
	+ 2.7109 * parameters.mean_wait_of_all 
	- 25237159.8823 * parameters.cpu_usage 
	- 0.5212 * parameters.avg_work_of_same_past_second 
	+ 0.0562 * parameters.avg_wait_of_same_past_second 
	+ 0.1519 * parameters.avg_latency_of_same_last_20 
	- 0.0058 * parameters.max_latency_of_same_last_50 
	+ 513490564.4689;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM34(work_wait &parameters) {
  double actual_remaining = 
	-1041.558 * parameters.work_so_far 
	+ 0.3663 * parameters.wait_so_far 
	+ 233918.89 * parameters.num_locks_so_far 
	+ 63846.3437 * parameters.total_wait_locks 
	- 0.2316 * parameters.mean_wait_of_all 
	- 760947.6711 * parameters.cpu_usage 
	+ 0.0318 * parameters.avg_work_of_same_past_second 
	+ 0.1042 * parameters.avg_wait_of_same_past_second 
	+ 0.0802 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 307716716.2406;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM35(work_wait &parameters) {
  double actual_remaining = 
	-4587.8309 * parameters.work_so_far 
	+ 0.0654 * parameters.wait_so_far 
	+ 233918.89 * parameters.num_locks_so_far 
	+ 43885.2839 * parameters.total_wait_locks 
	- 0.1331 * parameters.mean_wait_of_all 
	- 760947.6711 * parameters.cpu_usage 
	+ 0.0318 * parameters.avg_work_of_same_past_second 
	+ 0.0632 * parameters.avg_wait_of_same_past_second 
	+ 0.2337 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 558284536.5595;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM36(work_wait &parameters) {
  double actual_remaining = 
	-1.9202 * parameters.work_so_far 
	+ 0.3069 * parameters.wait_so_far 
	+ 233918.89 * parameters.num_locks_so_far 
	+ 5225.8192 * parameters.total_wait_locks 
	+ 0.0062 * parameters.mean_wait_of_all 
	- 760947.6711 * parameters.cpu_usage 
	+ 0.2508 * parameters.avg_work_of_same_past_second 
	+ 0.0053 * parameters.avg_wait_of_same_past_second 
	- 0.0515 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 390505105.8535;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM37(work_wait &parameters) {
  double actual_remaining = 
	-1.9202 * parameters.work_so_far 
	+ 1.8761 * parameters.wait_so_far 
	+ 233918.89 * parameters.num_locks_so_far 
	+ 5225.8192 * parameters.total_wait_locks 
	+ 0.0062 * parameters.mean_wait_of_all 
	- 760947.6711 * parameters.cpu_usage 
	+ 0.2508 * parameters.avg_work_of_same_past_second 
	+ 0.0053 * parameters.avg_wait_of_same_past_second 
	- 0.0515 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	- 142368153.1568;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM38(work_wait &parameters) {
  double actual_remaining = 
	-1.9202 * parameters.work_so_far 
	- 1.7616 * parameters.wait_so_far 
	+ 233918.89 * parameters.num_locks_so_far 
	+ 5225.8192 * parameters.total_wait_locks 
	+ 0.0062 * parameters.mean_wait_of_all 
	- 760947.6711 * parameters.cpu_usage 
	+ 0.5929 * parameters.avg_work_of_same_past_second 
	+ 0.0053 * parameters.avg_wait_of_same_past_second 
	- 0.1674 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 1249692349.726;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM39(work_wait &parameters) {
  double actual_remaining = 
	-1.9202 * parameters.work_so_far 
	- 1.1744 * parameters.wait_so_far 
	+ 233918.89 * parameters.num_locks_so_far 
	+ 5225.8192 * parameters.total_wait_locks 
	+ 0.0062 * parameters.mean_wait_of_all 
	- 760947.6711 * parameters.cpu_usage 
	+ 0.5929 * parameters.avg_work_of_same_past_second 
	+ 0.0053 * parameters.avg_wait_of_same_past_second 
	- 0.1674 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 947901065.052;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM40(work_wait &parameters) {
  double actual_remaining = 
	-1.9202 * parameters.work_so_far 
	+ 0.5781 * parameters.wait_so_far 
	+ 233918.89 * parameters.num_locks_so_far 
	+ 5225.8192 * parameters.total_wait_locks 
	+ 0.0062 * parameters.mean_wait_of_all 
	- 760947.6711 * parameters.cpu_usage 
	+ 0.0318 * parameters.avg_work_of_same_past_second 
	+ 0.0053 * parameters.avg_wait_of_same_past_second 
	+ 0.1682 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 231798485.4545;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM41(work_wait &parameters) {
  double actual_remaining = 
	-78.7887 * parameters.work_so_far 
	+ 0.0802 * parameters.wait_so_far 
	+ 233918.89 * parameters.num_locks_so_far 
	- 104.5584 * parameters.total_wait_locks 
	+ 0.0062 * parameters.mean_wait_of_all 
	- 760947.6711 * parameters.cpu_usage 
	+ 0.0432 * parameters.avg_work_of_same_past_second 
	+ 0.0053 * parameters.avg_wait_of_same_past_second 
	+ 0.3671 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 424776957.9395;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM42(work_wait &parameters) {
  double actual_remaining = 
	-0.5312 * parameters.work_so_far 
	+ 0.52 * parameters.wait_so_far 
	+ 233918.89 * parameters.num_locks_so_far 
	+ 435745.9145 * parameters.total_wait_locks 
	- 1.1214 * parameters.mean_wait_of_all 
	- 760947.6711 * parameters.cpu_usage 
	+ 0.0488 * parameters.avg_work_of_same_past_second 
	+ 0.0053 * parameters.avg_wait_of_same_past_second 
	+ 0.0287 * parameters.avg_latency_of_same_last_20 
	- 0.0048 * parameters.max_latency_of_same_last_50 
	+ 276783067.8877;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM43(work_wait &parameters) {
  double actual_remaining = 
	-0.5312 * parameters.work_so_far 
	+ 0.6597 * parameters.wait_so_far 
	+ 233918.89 * parameters.num_locks_so_far 
	- 72798.7511 * parameters.total_wait_locks 
	+ 0.1986 * parameters.mean_wait_of_all 
	- 760947.6711 * parameters.cpu_usage 
	+ 0.2674 * parameters.avg_work_of_same_past_second 
	+ 0.0053 * parameters.avg_wait_of_same_past_second 
	+ 0.0903 * parameters.avg_latency_of_same_last_20 
	+ 0.1197 * parameters.max_latency_of_same_last_50 
	+ 121588078.6501;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM44(work_wait &parameters) {
  double actual_remaining = 
	-0.5312 * parameters.work_so_far 
	+ 0.1851 * parameters.wait_so_far 
	+ 233918.89 * parameters.num_locks_so_far 
	- 181840.0402 * parameters.total_wait_locks 
	+ 5.9624 * parameters.mean_wait_of_all 
	+ 1620906172.7779 * parameters.cpu_usage 
	+ 0.6102 * parameters.avg_work_of_same_past_second 
	+ 0.0053 * parameters.avg_wait_of_same_past_second 
	- 0.9326 * parameters.avg_latency_of_same_last_20 
	- 0.01 * parameters.max_latency_of_same_last_50 
	- 1259707475.7878;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM45(work_wait &parameters) {
  double actual_remaining = 
	-160.2104 * parameters.work_so_far 
	+ 0.3357 * parameters.wait_so_far 
	+ 233918.89 * parameters.num_locks_so_far 
	- 815720.8362 * parameters.total_wait_locks 
	- 0.2869 * parameters.mean_wait_of_all 
	- 760947.6711 * parameters.cpu_usage 
	- 0.7685 * parameters.avg_work_of_same_past_second 
	+ 0.0053 * parameters.avg_wait_of_same_past_second 
	+ 0.1683 * parameters.avg_latency_of_same_last_20 
	- 0.01 * parameters.max_latency_of_same_last_50 
	+ 1189103150.4656;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM46(work_wait &parameters) {
  double actual_remaining = 
	-160.2104 * parameters.work_so_far 
	+ 0.3357 * parameters.wait_so_far 
	+ 233918.89 * parameters.num_locks_so_far 
	- 888490.8023 * parameters.total_wait_locks 
	- 0.2869 * parameters.mean_wait_of_all 
	- 760947.6711 * parameters.cpu_usage 
	- 0.7685 * parameters.avg_work_of_same_past_second 
	+ 0.0053 * parameters.avg_wait_of_same_past_second 
	+ 0.1683 * parameters.avg_latency_of_same_last_20 
	- 0.01 * parameters.max_latency_of_same_last_50 
	+ 1247054129.697;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM47(work_wait &parameters) {
  double actual_remaining = 
	-176.6002 * parameters.work_so_far 
	+ 0.3357 * parameters.wait_so_far 
	+ 233918.89 * parameters.num_locks_so_far 
	- 653832.7843 * parameters.total_wait_locks 
	- 0.2869 * parameters.mean_wait_of_all 
	- 760947.6711 * parameters.cpu_usage 
	- 0.7685 * parameters.avg_work_of_same_past_second 
	+ 0.0053 * parameters.avg_wait_of_same_past_second 
	+ 0.1683 * parameters.avg_latency_of_same_last_20 
	- 0.01 * parameters.max_latency_of_same_last_50 
	+ 1088493703.4211;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM48(work_wait &parameters) {
  double actual_remaining = 
	-104.3508 * parameters.work_so_far 
	+ 0.3357 * parameters.wait_so_far 
	+ 233918.89 * parameters.num_locks_so_far 
	- 398931.2428 * parameters.total_wait_locks 
	- 0.2869 * parameters.mean_wait_of_all 
	- 760947.6711 * parameters.cpu_usage 
	- 0.8838 * parameters.avg_work_of_same_past_second 
	+ 0.0053 * parameters.avg_wait_of_same_past_second 
	+ 0.1683 * parameters.avg_latency_of_same_last_20 
	- 0.01 * parameters.max_latency_of_same_last_50 
	+ 930440521.6383;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM49(work_wait &parameters) {
  double actual_remaining = 
	-0.5312 * parameters.work_so_far 
	+ 0.1032 * parameters.wait_so_far 
	+ 233918.89 * parameters.num_locks_so_far 
	- 104.5584 * parameters.total_wait_locks 
	+ 0.0062 * parameters.mean_wait_of_all 
	- 760947.6711 * parameters.cpu_usage 
	+ 0.0389 * parameters.avg_work_of_same_past_second 
	+ 0.0053 * parameters.avg_wait_of_same_past_second 
	+ 0.2946 * parameters.avg_latency_of_same_last_20 
	- 0.0093 * parameters.max_latency_of_same_last_50 
	+ 468695400.3042;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM50(work_wait &parameters) {
  double actual_remaining = 
	0.214 * parameters.work_so_far 
	+ 0.5984 * parameters.wait_so_far 
	- 1322402.602 * parameters.num_locks_so_far 
	- 160587.0919 * parameters.total_wait_locks 
	+ 0.9881 * parameters.mean_wait_of_all 
	+ 8543082.0177 * parameters.cpu_usage 
	+ 0.0229 * parameters.avg_work_of_same_past_second 
	+ 0.0614 * parameters.avg_wait_of_same_past_second 
	+ 0.0133 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 287902058.2022;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM51(work_wait &parameters) {
  double actual_remaining = 
	0.214 * parameters.work_so_far 
	+ 0.117 * parameters.wait_so_far 
	- 21459427.0748 * parameters.num_locks_so_far 
	- 104627.8424 * parameters.total_wait_locks 
	+ 0.6201 * parameters.mean_wait_of_all 
	+ 8543082.0177 * parameters.cpu_usage 
	+ 0.114 * parameters.avg_work_of_same_past_second 
	+ 0.0614 * parameters.avg_wait_of_same_past_second 
	+ 0.0133 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 644449832.9113;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM52(work_wait &parameters) {
  double actual_remaining = 
	0.214 * parameters.work_so_far 
	+ 0.94 * parameters.wait_so_far 
	- 7869462.7779 * parameters.num_locks_so_far 
	- 2045674.07 * parameters.total_wait_locks 
	+ 8.7737 * parameters.mean_wait_of_all 
	+ 8543082.0177 * parameters.cpu_usage 
	- 0.9469 * parameters.avg_work_of_same_past_second 
	+ 0.0614 * parameters.avg_wait_of_same_past_second 
	+ 0.0133 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 711872704.1927;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM53(work_wait &parameters) {
  double actual_remaining = 
	0.214 * parameters.work_so_far 
	+ 1.4512 * parameters.wait_so_far 
	- 7869462.7779 * parameters.num_locks_so_far 
	- 3325246.1534 * parameters.total_wait_locks 
	+ 6.7353 * parameters.mean_wait_of_all 
	- 7828088114.4117 * parameters.cpu_usage 
	- 0.6466 * parameters.avg_work_of_same_past_second 
	+ 0.0614 * parameters.avg_wait_of_same_past_second 
	+ 0.0133 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 8831406412.6987;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM54(work_wait &parameters) {
  double actual_remaining = 
	2.6225 * parameters.work_so_far 
	+ 0.1122 * parameters.wait_so_far 
	+ 4547254.5841 * parameters.num_locks_so_far 
	- 296083.2974 * parameters.total_wait_locks 
	+ 1.0874 * parameters.mean_wait_of_all 
	+ 1829831260.5709 * parameters.cpu_usage 
	+ 0.0229 * parameters.avg_work_of_same_past_second 
	+ 0.3722 * parameters.avg_wait_of_same_past_second 
	+ 0.108 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	- 1219853516.5097;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM55(work_wait &parameters) {
  double actual_remaining = 
	1.7505 * parameters.work_so_far 
	+ 0.1122 * parameters.wait_so_far 
	+ 4547254.5841 * parameters.num_locks_so_far 
	- 411512.5256 * parameters.total_wait_locks 
	+ 1.467 * parameters.mean_wait_of_all 
	+ 476525992.5628 * parameters.cpu_usage 
	+ 0.0229 * parameters.avg_work_of_same_past_second 
	+ 0.5017 * parameters.avg_wait_of_same_past_second 
	+ 0.7426 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	- 22464855.5604;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM56(work_wait &parameters) {
  double actual_remaining = 
	0.9947 * parameters.work_so_far 
	+ 0.7094 * parameters.wait_so_far 
	+ 1210673.5036 * parameters.num_locks_so_far 
	- 504139.5539 * parameters.total_wait_locks 
	+ 2.4068 * parameters.mean_wait_of_all 
	- 4541868.1025 * parameters.cpu_usage 
	+ 0.0138 * parameters.avg_work_of_same_past_second 
	+ 0.0053 * parameters.avg_wait_of_same_past_second 
	+ 0.2069 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 104105072.8451;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM57(work_wait &parameters) {
  double actual_remaining = 
	1.2281 * parameters.work_so_far 
	+ 0.911 * parameters.wait_so_far 
	- 2902637.0541 * parameters.num_locks_so_far 
	- 699501.7078 * parameters.total_wait_locks 
	+ 3.2452 * parameters.mean_wait_of_all 
	- 424826294.0756 * parameters.cpu_usage 
	+ 0.0046 * parameters.avg_wait_of_same_past_second 
	+ 0.1283 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	+ 570966171.5036;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
new_order_estimate(work_wait &parameters){

  if (parameters.wait_so_far <= 313296800.5) {

    if (parameters.total_wait_locks <= 163.5) {

      if (parameters.total_wait_locks <= 82.5) {

        if (parameters.work_so_far <= 47349415) {
          return new_order_LM1(parameters);
        } else {
          return new_order_LM2(parameters);
        }
      } else {

        if (parameters.avg_wait_of_same_past_second <= 13819500) {

          if (parameters.max_latency_of_same_last_50 <= 463933000) {

            if (parameters.work_so_far <= 83899932) {
              return new_order_LM3(parameters);
            } else {
              return new_order_LM4(parameters);
            }
          } else {

            if (parameters.total_wait_locks <= 143.5) {
              return new_order_LM5(parameters);
            } else {
              return new_order_LM6(parameters);
            }
          }
        } else {

          if (parameters.mean_wait_of_all <= 34977150) {

            if (parameters.total_wait_locks <= 129.5) {
              return new_order_LM7(parameters);
            } else {

              if (parameters.wait_so_far <= 64162952) {

                if (parameters.work_so_far <= 30424926) {

                  if (parameters.total_wait_locks <= 157.5) {
                    return new_order_LM8(parameters);
                  } else {

                    if (parameters.avg_work_of_same_past_second <= 187921000) {
                      return new_order_LM9(parameters);
                    } else {
                      return new_order_LM10(parameters);
                    }
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
        }
      }
    } else {

      if (parameters.work_so_far <= 34665053) {

        if (parameters.num_locks_so_far <= 10.5) {

          if (parameters.wait_so_far <= 89690602) {

            if (parameters.work_so_far <= 4432139) {

              if (parameters.total_wait_locks <= 321.5) {

                if (parameters.wait_so_far <= 23771600.5) {
                  return new_order_LM14(parameters);
                } else {
                  return new_order_LM15(parameters);
                }
              } else {

                if (parameters.avg_wait_of_same_past_second <= 222887500) {

                  if (parameters.avg_work_of_same_past_second <= 197026500) {

                    if (parameters.total_wait_locks <= 551.5) {

                      if (parameters.mean_wait_of_all <= 95766100) {
                        return new_order_LM16(parameters);
                      } else {

                        if (parameters.total_wait_locks <= 460) {
                          return new_order_LM17(parameters);
                        } else {
                          return new_order_LM18(parameters);
                        }
                      }
                    } else {
                      return new_order_LM19(parameters);
                    }
                  } else {

                    if (parameters.work_so_far <= 327623) {

                      if (parameters.work_so_far <= 70935) {
                        return new_order_LM20(parameters);
                      } else {
                        return new_order_LM21(parameters);
                      }
                    } else {
                      return new_order_LM22(parameters);
                    }
                  }
                } else {

                  if (parameters.wait_so_far <= 107660) {

                    if (parameters.wait_so_far <= 11953) {
                      return new_order_LM23(parameters);
                    } else {
                      return new_order_LM24(parameters);
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
            return new_order_LM27(parameters);
          }
        } else {
          return new_order_LM28(parameters);
        }
      } else {

        if (parameters.num_locks_so_far <= 12.5) {
          return new_order_LM29(parameters);
        } else {
          return new_order_LM30(parameters);
        }
      }
    }
  } else {

    if (parameters.wait_so_far <= 577738141) {

      if (parameters.cpu_usage <= 0.856) {

        if (parameters.avg_work_of_same_past_second <= 197741000) {

          if (parameters.avg_wait_of_same_past_second <= 112567000) {
            return new_order_LM31(parameters);
          } else {
            return new_order_LM32(parameters);
          }
        } else {
          return new_order_LM33(parameters);
        }
      } else {

        if (parameters.num_locks_so_far <= 11.5) {

          if (parameters.work_so_far <= 2331067) {

            if (parameters.wait_so_far <= 427375060.5) {

              if (parameters.avg_work_of_same_past_second <= 237290000) {

                if (parameters.work_so_far <= 46014.5) {

                  if (parameters.total_wait_locks <= 150.5) {
                    return new_order_LM34(parameters);
                  } else {
                    return new_order_LM35(parameters);
                  }
                } else {

                  if (parameters.avg_work_of_same_past_second <= 191405000) {

                    if (parameters.avg_wait_of_same_past_second <= 197629000) {

                      if (parameters.avg_work_of_same_past_second <= 184599500) {
                        return new_order_LM36(parameters);
                      } else {
                        return new_order_LM37(parameters);
                      }
                    } else {

                      if (parameters.wait_so_far <= 328790607.5) {
                        return new_order_LM38(parameters);
                      } else {
                        return new_order_LM39(parameters);
                      }
                    }
                  } else {
                    return new_order_LM40(parameters);
                  }
                }
              } else {
                return new_order_LM41(parameters);
              }
            } else {

              if (parameters.avg_work_of_same_past_second <= 209804500) {
                return new_order_LM42(parameters);
              } else {

                if (parameters.max_latency_of_same_last_50 <= 1066845000) {

                  if (parameters.avg_latency_of_same_last_20 <= 388023000) {

                    if (parameters.avg_work_of_same_past_second <= 264838000) {
                      return new_order_LM43(parameters);
                    } else {
                      return new_order_LM44(parameters);
                    }
                  } else {

                    if (parameters.avg_work_of_same_past_second <= 260924000) {

                      if (parameters.work_so_far <= 161163.5) {

                        if (parameters.work_so_far <= 55512) {
                          return new_order_LM45(parameters);
                        } else {
                          return new_order_LM46(parameters);
                        }
                      } else {
                        return new_order_LM47(parameters);
                      }
                    } else {
                      return new_order_LM48(parameters);
                    }
                  }
                } else {
                  return new_order_LM49(parameters);
                }
              }
            }
          } else {

            if (parameters.num_locks_so_far <= 9.5) {

              if (parameters.mean_wait_of_all <= 61602500) {
                return new_order_LM50(parameters);
              } else {

                if (parameters.avg_work_of_same_past_second <= 275727500) {
                  return new_order_LM51(parameters);
                } else {

                  if (parameters.cpu_usage <= 0.952) {
                    return new_order_LM52(parameters);
                  } else {
                    return new_order_LM53(parameters);
                  }
                }
              }
            } else {

              if (parameters.avg_wait_of_same_past_second <= 224625500) {
                return new_order_LM54(parameters);
              } else {
                return new_order_LM55(parameters);
              }
            }
          }
        } else {
          return new_order_LM56(parameters);
        }
      }
    } else {
      return new_order_LM57(parameters);
    }
  }
}
static
double
payment_LM1(work_wait &parameters) {
  double actual_remaining = 
	13387.8288 * parameters.work_so_far 
	+ 0.9705 * parameters.wait_so_far 
	- 135193.8017 * parameters.num_locks_so_far 
	+ 321339.9559 * parameters.total_wait_locks 
	- 0.05 * parameters.mean_wait_of_all 
	- 4404269.5735 * parameters.cpu_usage 
	- 0.9112 * parameters.avg_work_of_same_past_second 
	+ 0.0009 * parameters.avg_wait_of_same_past_second 
	+ 0.001 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	- 50437974.2217;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM2(work_wait &parameters) {
  double actual_remaining = 
	0.0086 * parameters.work_so_far 
	+ 0.7708 * parameters.wait_so_far 
	- 135193.8017 * parameters.num_locks_so_far 
	+ 1483753.065 * parameters.total_wait_locks 
	- 0.1016 * parameters.mean_wait_of_all 
	- 257897454.4557 * parameters.cpu_usage 
	- 0.0774 * parameters.avg_work_of_same_past_second 
	+ 0.0009 * parameters.avg_wait_of_same_past_second 
	- 0.0037 * parameters.avg_latency_of_same_last_20 
	- 0.0969 * parameters.max_latency_of_same_last_50 
	+ 319800631.1425;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM3(work_wait &parameters) {
  double actual_remaining = 
	0.0086 * parameters.work_so_far 
	+ 0.53 * parameters.wait_so_far 
	- 135193.8017 * parameters.num_locks_so_far 
	+ 4459129.0336 * parameters.total_wait_locks 
	- 8.5322 * parameters.mean_wait_of_all 
	+ 186190704.802 * parameters.cpu_usage 
	- 0.1274 * parameters.avg_work_of_same_past_second 
	+ 0.0009 * parameters.avg_wait_of_same_past_second 
	- 0.6822 * parameters.avg_latency_of_same_last_20 
	- 0.1972 * parameters.max_latency_of_same_last_50 
	+ 91932536.2758;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM4(work_wait &parameters) {
  double actual_remaining = 
	0.0086 * parameters.work_so_far 
	+ 0.4255 * parameters.wait_so_far 
	- 135193.8017 * parameters.num_locks_so_far 
	+ 1343877.1399 * parameters.total_wait_locks 
	- 2.2495 * parameters.mean_wait_of_all 
	- 284476050.5721 * parameters.cpu_usage 
	- 0.0736 * parameters.avg_work_of_same_past_second 
	+ 0.0009 * parameters.avg_wait_of_same_past_second 
	- 0.1066 * parameters.avg_latency_of_same_last_20 
	- 0.0018 * parameters.max_latency_of_same_last_50 
	+ 392785997.2031;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM5(work_wait &parameters) {
  double actual_remaining = 
	1.0819 * parameters.work_so_far 
	+ 0.1606 * parameters.wait_so_far 
	- 22235254.6776 * parameters.num_locks_so_far 
	+ 994811.1244 * parameters.total_wait_locks 
	- 2.8273 * parameters.mean_wait_of_all 
	- 254516651.2569 * parameters.cpu_usage 
	+ 0.0015 * parameters.avg_work_of_same_past_second 
	+ 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0007 * parameters.avg_latency_of_same_last_20 
	- 0.0576 * parameters.max_latency_of_same_last_50 
	+ 522096367.4936;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM6(work_wait &parameters) {
  double actual_remaining = 
	0.9696 * parameters.work_so_far 
	- 0.0982 * parameters.wait_so_far 
	- 27413187.9265 * parameters.num_locks_so_far 
	+ 287175.6031 * parameters.total_wait_locks 
	- 2.1783 * parameters.mean_wait_of_all 
	- 204789994.3595 * parameters.cpu_usage 
	+ 0.0015 * parameters.avg_work_of_same_past_second 
	- 0.1461 * parameters.avg_wait_of_same_past_second 
	+ 0.069 * parameters.avg_latency_of_same_last_20 
	- 0.0298 * parameters.max_latency_of_same_last_50 
	+ 745734742.017;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM7(work_wait &parameters) {
  double actual_remaining = 
	1.3253 * parameters.work_so_far 
	+ 0.5144 * parameters.wait_so_far 
	- 10027738.3521 * parameters.num_locks_so_far 
	+ 5321.2455 * parameters.total_wait_locks 
	- 0.4598 * parameters.mean_wait_of_all 
	- 6991933.8453 * parameters.cpu_usage 
	+ 0.0024 * parameters.avg_work_of_same_past_second 
	- 0.006 * parameters.avg_wait_of_same_past_second 
	+ 0.0678 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 287194161.1525;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM8(work_wait &parameters) {
  double actual_remaining = 
	14.4791 * parameters.work_so_far 
	+ 0.7197 * parameters.wait_so_far 
	- 1677724.9008 * parameters.num_locks_so_far 
	- 1398125.5063 * parameters.total_wait_locks 
	+ 12.1025 * parameters.mean_wait_of_all 
	- 6991933.8453 * parameters.cpu_usage 
	- 1.5542 * parameters.avg_work_of_same_past_second 
	- 0.4053 * parameters.avg_wait_of_same_past_second 
	- 0.1502 * parameters.avg_latency_of_same_last_20 
	- 0.0538 * parameters.max_latency_of_same_last_50 
	- 93165666.3936;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM9(work_wait &parameters) {
  double actual_remaining = 
	0.1965 * parameters.work_so_far 
	+ 0.7197 * parameters.wait_so_far 
	- 1677724.9008 * parameters.num_locks_so_far 
	- 1398125.5063 * parameters.total_wait_locks 
	+ 12.1025 * parameters.mean_wait_of_all 
	- 6991933.8453 * parameters.cpu_usage 
	- 1.9067 * parameters.avg_work_of_same_past_second 
	- 0.4972 * parameters.avg_wait_of_same_past_second 
	+ 0.1128 * parameters.avg_latency_of_same_last_20 
	- 0.0538 * parameters.max_latency_of_same_last_50 
	- 47168848.6712;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM10(work_wait &parameters) {
  double actual_remaining = 
	-0.5943 * parameters.work_so_far 
	- 4.9063 * parameters.wait_so_far 
	- 1677724.9008 * parameters.num_locks_so_far 
	- 2584043.0665 * parameters.total_wait_locks 
	+ 26.4171 * parameters.mean_wait_of_all 
	- 6991933.8453 * parameters.cpu_usage 
	- 0.6144 * parameters.avg_work_of_same_past_second 
	- 0.1602 * parameters.avg_wait_of_same_past_second 
	+ 0.232 * parameters.avg_latency_of_same_last_20 
	- 0.117 * parameters.max_latency_of_same_last_50 
	+ 1260588711.4319;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM11(work_wait &parameters) {
  double actual_remaining = 
	0.9623 * parameters.work_so_far 
	- 3.6351 * parameters.wait_so_far 
	- 1677724.9008 * parameters.num_locks_so_far 
	- 2584043.0665 * parameters.total_wait_locks 
	+ 24.9936 * parameters.mean_wait_of_all 
	- 6991933.8453 * parameters.cpu_usage 
	- 0.6144 * parameters.avg_work_of_same_past_second 
	- 0.1602 * parameters.avg_wait_of_same_past_second 
	+ 0.232 * parameters.avg_latency_of_same_last_20 
	- 0.117 * parameters.max_latency_of_same_last_50 
	+ 805573634.3606;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM12(work_wait &parameters) {
  double actual_remaining = 
	0.7519 * parameters.work_so_far 
	- 3.6351 * parameters.wait_so_far 
	- 1677724.9008 * parameters.num_locks_so_far 
	- 2584043.0665 * parameters.total_wait_locks 
	+ 25.0648 * parameters.mean_wait_of_all 
	- 6991933.8453 * parameters.cpu_usage 
	- 0.6144 * parameters.avg_work_of_same_past_second 
	- 0.1602 * parameters.avg_wait_of_same_past_second 
	+ 0.232 * parameters.avg_latency_of_same_last_20 
	- 0.117 * parameters.max_latency_of_same_last_50 
	+ 796410924.2302;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM13(work_wait &parameters) {
  double actual_remaining = 
	0.1965 * parameters.work_so_far 
	+ 0.7995 * parameters.wait_so_far 
	- 1677724.9008 * parameters.num_locks_so_far 
	- 381015.24 * parameters.total_wait_locks 
	- 0.0433 * parameters.mean_wait_of_all 
	- 6991933.8453 * parameters.cpu_usage 
	- 0.5982 * parameters.avg_work_of_same_past_second 
	- 0.5191 * parameters.avg_wait_of_same_past_second 
	+ 0.0116 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 602044708.9029;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM14(work_wait &parameters) {
  double actual_remaining = 
	1.1191 * parameters.work_so_far 
	+ 0.7395 * parameters.wait_so_far 
	- 4414052.9833 * parameters.num_locks_so_far 
	- 482500.3815 * parameters.total_wait_locks 
	+ 2.5244 * parameters.mean_wait_of_all 
	- 5875038.6544 * parameters.cpu_usage 
	+ 0.0024 * parameters.avg_work_of_same_past_second 
	- 0.0011 * parameters.avg_wait_of_same_past_second 
	+ 0.0029 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 146295729.6223;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM15(work_wait &parameters) {
  double actual_remaining = 
	1.8084 * parameters.work_so_far 
	+ 0.899 * parameters.wait_so_far 
	- 8197000.5234 * parameters.num_locks_so_far 
	- 345033.6128 * parameters.total_wait_locks 
	+ 1.4101 * parameters.mean_wait_of_all 
	- 131479900.2426 * parameters.cpu_usage 
	+ 0.0024 * parameters.avg_work_of_same_past_second 
	+ 0.0883 * parameters.avg_wait_of_same_past_second 
	+ 0.0919 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 203013667.6005;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM16(work_wait &parameters) {
  double actual_remaining = 
	1.2731 * parameters.work_so_far 
	+ 0.9992 * parameters.wait_so_far 
	- 4104188.351 * parameters.num_locks_so_far 
	- 486330.9449 * parameters.total_wait_locks 
	+ 1.9916 * parameters.mean_wait_of_all 
	- 3433150.8043 * parameters.cpu_usage 
	+ 0.0024 * parameters.avg_work_of_same_past_second 
	+ 0.0005 * parameters.avg_wait_of_same_past_second 
	+ 0.0689 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 46437024.4053;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
payment_estimate(work_wait &parameters){

  if (parameters.wait_so_far <= 277681923) {

    if (parameters.total_wait_locks <= 129.5) {

      if (parameters.work_so_far <= 10081) {
        return payment_LM1(parameters);
      } else {

        if (parameters.total_wait_locks <= 38.5) {
          return payment_LM2(parameters);
        } else {

          if (parameters.avg_wait_of_same_past_second <= 20149250) {
            return payment_LM3(parameters);
          } else {
            return payment_LM4(parameters);
          }
        }
      }
    } else {

      if (parameters.mean_wait_of_all <= 69751200) {
        return payment_LM5(parameters);
      } else {
        return payment_LM6(parameters);
      }
    }
  } else {

    if (parameters.wait_so_far <= 659157392) {

      if (parameters.wait_so_far <= 438338511.5) {

        if (parameters.cpu_usage <= 0.953) {

          if (parameters.total_wait_locks <= 522) {
            return payment_LM7(parameters);
          } else {

            if (parameters.mean_wait_of_all <= 121753000) {

              if (parameters.wait_so_far <= 396040580) {

                if (parameters.avg_latency_of_same_last_20 <= 487065000) {
                  return payment_LM8(parameters);
                } else {
                  return payment_LM9(parameters);
                }
              } else {

                if (parameters.wait_so_far <= 412246920.5) {
                  return payment_LM10(parameters);
                } else {

                  if (parameters.mean_wait_of_all <= 114767000) {
                    return payment_LM11(parameters);
                  } else {
                    return payment_LM12(parameters);
                  }
                }
              }
            } else {
              return payment_LM13(parameters);
            }
          }
        } else {
          return payment_LM14(parameters);
        }
      } else {
        return payment_LM15(parameters);
      }
    } else {
      return payment_LM16(parameters);
    }
  }
}
static
double
delivery_LM1(work_wait &parameters) {
  double actual_remaining = 
	1.1346 * parameters.work_so_far 
	+ 0.734 * parameters.wait_so_far 
	- 4393353.0367 * parameters.num_locks_so_far 
	+ 1604253.2384 * parameters.total_wait_locks 
	- 0.2546 * parameters.mean_wait_of_all 
	- 38203167.8327 * parameters.cpu_usage 
	+ 0.0191 * parameters.avg_work_of_same_past_second 
	- 0.6062 * parameters.avg_wait_of_same_past_second 
	+ 0.0532 * parameters.avg_latency_of_same_last_20 
	+ 319045990.0639;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM2(work_wait &parameters) {
  double actual_remaining = 
	0.8996 * parameters.work_so_far 
	+ 0.4579 * parameters.wait_so_far 
	- 8518062.5275 * parameters.num_locks_so_far 
	+ 34626.5052 * parameters.total_wait_locks 
	+ 1.8007 * parameters.mean_wait_of_all 
	- 418706223.5902 * parameters.cpu_usage 
	+ 0.0057 * parameters.avg_work_of_same_past_second 
	- 0.8627 * parameters.avg_wait_of_same_past_second 
	+ 0.3358 * parameters.avg_latency_of_same_last_20 
	+ 1131880917.692;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
delivery_estimate(work_wait &parameters){

  if (parameters.total_wait_locks <= 190.5) {
    return delivery_LM1(parameters);
  } else {
    return delivery_LM2(parameters);
  }
}
static
double
stock_level_LM1(work_wait &parameters) {
  double actual_remaining = 
	0.913 * parameters.wait_so_far 
	- 3015407.0514 * parameters.num_locks_so_far 
	+ 396657041.1925;
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
	5243.429 * parameters.work_so_far 
	+ 0.9408 * parameters.wait_so_far 
	- 78710.0623 * parameters.num_locks_so_far 
	+ 69934.9091 * parameters.total_wait_locks 
	- 0.0258 * parameters.mean_wait_of_all 
	- 8814060.0339 * parameters.cpu_usage 
	+ 0.0114 * parameters.avg_work_of_same_past_second 
	- 0.0119 * parameters.avg_wait_of_same_past_second 
	+ 0.0076 * parameters.avg_latency_of_same_last_20 
	- 0.0028 * parameters.max_latency_of_same_last_50 
	- 336482.4681;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM2(work_wait &parameters) {
  double actual_remaining = 
	3.6514 * parameters.work_so_far 
	+ 0.8511 * parameters.wait_so_far 
	- 3966142.3271 * parameters.num_locks_so_far 
	+ 1239312.7518 * parameters.total_wait_locks 
	- 0.5149 * parameters.mean_wait_of_all 
	- 235790410.9364 * parameters.cpu_usage 
	+ 0.3221 * parameters.avg_work_of_same_past_second 
	- 0.2281 * parameters.avg_wait_of_same_past_second 
	+ 0.106 * parameters.avg_latency_of_same_last_20 
	- 0.0658 * parameters.max_latency_of_same_last_50 
	+ 292162273.8562;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM3(work_wait &parameters) {
  double actual_remaining = 
	1.3037 * parameters.work_so_far 
	+ 0.8332 * parameters.wait_so_far 
	- 2276269.072 * parameters.num_locks_so_far 
	+ 2742278.7013 * parameters.total_wait_locks 
	- 0.0258 * parameters.mean_wait_of_all 
	- 12731659.218 * parameters.cpu_usage 
	+ 0.0128 * parameters.avg_work_of_same_past_second 
	- 0.947 * parameters.avg_wait_of_same_past_second 
	+ 0.0089 * parameters.avg_latency_of_same_last_20 
	- 0.1253 * parameters.max_latency_of_same_last_50 
	+ 135600365.3789;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM4(work_wait &parameters) {
  double actual_remaining = 
	3.8915 * parameters.work_so_far 
	+ 12775.4391 * parameters.wait_so_far 
	- 1762942.3718 * parameters.num_locks_so_far 
	+ 1290225.5897 * parameters.total_wait_locks 
	- 0.3688 * parameters.mean_wait_of_all 
	- 163221352.3818 * parameters.cpu_usage 
	+ 0.0058 * parameters.avg_work_of_same_past_second 
	- 0.0041 * parameters.avg_wait_of_same_past_second 
	+ 0.0133 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 167935508.5551;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM5(work_wait &parameters) {
  double actual_remaining = 
	1.7913 * parameters.work_so_far 
	+ 554.9282 * parameters.wait_so_far 
	- 1182502.4781 * parameters.num_locks_so_far 
	+ 760913.3915 * parameters.total_wait_locks 
	- 0.3046 * parameters.mean_wait_of_all 
	- 20415963.5001 * parameters.cpu_usage 
	+ 0.0058 * parameters.avg_work_of_same_past_second 
	- 0.0041 * parameters.avg_wait_of_same_past_second 
	+ 0.008 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 26087854.6254;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM6(work_wait &parameters) {
  double actual_remaining = 
	0.0877 * parameters.work_so_far 
	+ 0.8479 * parameters.wait_so_far 
	- 143741.4213 * parameters.num_locks_so_far 
	+ 4681686.0827 * parameters.total_wait_locks 
	- 11.2089 * parameters.mean_wait_of_all 
	- 28078814.1252 * parameters.cpu_usage 
	- 0.0188 * parameters.avg_work_of_same_past_second 
	- 0.0041 * parameters.avg_wait_of_same_past_second 
	- 0.4232 * parameters.avg_latency_of_same_last_20 
	- 0.0014 * parameters.max_latency_of_same_last_50 
	+ 158559788.7668;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM7(work_wait &parameters) {
  double actual_remaining = 
	0.0877 * parameters.work_so_far 
	+ 0.048 * parameters.wait_so_far 
	- 143741.4213 * parameters.num_locks_so_far 
	+ 5077712.5121 * parameters.total_wait_locks 
	- 13.1888 * parameters.mean_wait_of_all 
	+ 35077225.8897 * parameters.cpu_usage 
	- 0.3199 * parameters.avg_work_of_same_past_second 
	+ 0.0367 * parameters.avg_wait_of_same_past_second 
	- 0.0018 * parameters.avg_latency_of_same_last_20 
	- 0.2937 * parameters.max_latency_of_same_last_50 
	+ 236585025.0316;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM8(work_wait &parameters) {
  double actual_remaining = 
	0.0877 * parameters.work_so_far 
	+ 0.048 * parameters.wait_so_far 
	- 143741.4213 * parameters.num_locks_so_far 
	+ 13629877.2635 * parameters.total_wait_locks 
	- 36.2688 * parameters.mean_wait_of_all 
	+ 60542698.9168 * parameters.cpu_usage 
	- 1.5874 * parameters.avg_work_of_same_past_second 
	+ 0.0367 * parameters.avg_wait_of_same_past_second 
	- 0.0018 * parameters.avg_latency_of_same_last_20 
	- 2.6551 * parameters.max_latency_of_same_last_50 
	+ 734955370.0083;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM9(work_wait &parameters) {
  double actual_remaining = 
	0.0877 * parameters.work_so_far 
	+ 0.048 * parameters.wait_so_far 
	- 143741.4213 * parameters.num_locks_so_far 
	+ 205756.2117 * parameters.total_wait_locks 
	- 0.3633 * parameters.mean_wait_of_all 
	- 32465504.1681 * parameters.cpu_usage 
	- 0.5063 * parameters.avg_work_of_same_past_second 
	+ 0.009 * parameters.avg_wait_of_same_past_second 
	- 0.0018 * parameters.avg_latency_of_same_last_20 
	- 0.0501 * parameters.max_latency_of_same_last_50 
	+ 201246620.4997;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM10(work_wait &parameters) {
  double actual_remaining = 
	0.0877 * parameters.work_so_far 
	+ 0.048 * parameters.wait_so_far 
	- 143741.4213 * parameters.num_locks_so_far 
	- 8808586.0711 * parameters.total_wait_locks 
	- 0.3633 * parameters.mean_wait_of_all 
	- 172743116.3495 * parameters.cpu_usage 
	- 0.0997 * parameters.avg_work_of_same_past_second 
	+ 0.009 * parameters.avg_wait_of_same_past_second 
	- 0.0018 * parameters.avg_latency_of_same_last_20 
	- 0.0066 * parameters.max_latency_of_same_last_50 
	+ 957320272.6233;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM11(work_wait &parameters) {
  double actual_remaining = 
	0.0877 * parameters.work_so_far 
	+ 0.8155 * parameters.wait_so_far 
	- 143741.4213 * parameters.num_locks_so_far 
	+ 48995.7288 * parameters.total_wait_locks 
	- 0.2504 * parameters.mean_wait_of_all 
	- 19440211.3136 * parameters.cpu_usage 
	+ 0.0058 * parameters.avg_work_of_same_past_second 
	- 0.4034 * parameters.avg_wait_of_same_past_second 
	- 0.2572 * parameters.avg_latency_of_same_last_20 
	- 0.0023 * parameters.max_latency_of_same_last_50 
	+ 194286397.9106;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM12(work_wait &parameters) {
  double actual_remaining = 
	0.2097 * parameters.work_so_far 
	+ 0.0262 * parameters.wait_so_far 
	- 3358352.1004 * parameters.num_locks_so_far 
	- 8894079.1745 * parameters.total_wait_locks 
	- 5.9527 * parameters.mean_wait_of_all 
	- 10907221.4711 * parameters.cpu_usage 
	+ 0.0771 * parameters.avg_work_of_same_past_second 
	- 0.0088 * parameters.avg_wait_of_same_past_second 
	- 0.2403 * parameters.avg_latency_of_same_last_20 
	- 0.1281 * parameters.max_latency_of_same_last_50 
	+ 1389097577.6622;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM13(work_wait &parameters) {
  double actual_remaining = 
	0.2097 * parameters.work_so_far 
	+ 0.488 * parameters.wait_so_far 
	- 2766085.8473 * parameters.num_locks_so_far 
	+ 1214803.2516 * parameters.total_wait_locks 
	- 3.953 * parameters.mean_wait_of_all 
	- 10907221.4711 * parameters.cpu_usage 
	+ 0.0771 * parameters.avg_work_of_same_past_second 
	- 0.0088 * parameters.avg_wait_of_same_past_second 
	- 0.2403 * parameters.avg_latency_of_same_last_20 
	- 0.0718 * parameters.max_latency_of_same_last_50 
	+ 281969881.3199;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM14(work_wait &parameters) {
  double actual_remaining = 
	-2.5403 * parameters.work_so_far 
	+ 0.0262 * parameters.wait_so_far 
	- 4739024.6138 * parameters.num_locks_so_far 
	+ 1322253.6517 * parameters.total_wait_locks 
	- 2.8943 * parameters.mean_wait_of_all 
	- 10907221.4711 * parameters.cpu_usage 
	+ 0.0771 * parameters.avg_work_of_same_past_second 
	- 0.0088 * parameters.avg_wait_of_same_past_second 
	- 0.2642 * parameters.avg_latency_of_same_last_20 
	- 0.014 * parameters.max_latency_of_same_last_50 
	+ 459164813.0784;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM15(work_wait &parameters) {
  double actual_remaining = 
	-2.5403 * parameters.work_so_far 
	+ 0.0262 * parameters.wait_so_far 
	- 4739024.6138 * parameters.num_locks_so_far 
	+ 1322253.6517 * parameters.total_wait_locks 
	- 4.7046 * parameters.mean_wait_of_all 
	- 10907221.4711 * parameters.cpu_usage 
	+ 0.0771 * parameters.avg_work_of_same_past_second 
	- 0.0088 * parameters.avg_wait_of_same_past_second 
	- 0.2642 * parameters.avg_latency_of_same_last_20 
	- 0.014 * parameters.max_latency_of_same_last_50 
	+ 452661908.0151;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM16(work_wait &parameters) {
  double actual_remaining = 
	-13.7343 * parameters.work_so_far 
	+ 0.0262 * parameters.wait_so_far 
	- 4739024.6138 * parameters.num_locks_so_far 
	+ 1322253.6517 * parameters.total_wait_locks 
	- 0.9195 * parameters.mean_wait_of_all 
	- 10907221.4711 * parameters.cpu_usage 
	+ 0.0771 * parameters.avg_work_of_same_past_second 
	- 0.0088 * parameters.avg_wait_of_same_past_second 
	- 0.2642 * parameters.avg_latency_of_same_last_20 
	- 0.014 * parameters.max_latency_of_same_last_50 
	+ 516677880.1929;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM17(work_wait &parameters) {
  double actual_remaining = 
	0.2097 * parameters.work_so_far 
	+ 0.0262 * parameters.wait_so_far 
	- 10905253.3842 * parameters.num_locks_so_far 
	+ 1322253.6517 * parameters.total_wait_locks 
	+ 0.5319 * parameters.mean_wait_of_all 
	- 10907221.4711 * parameters.cpu_usage 
	+ 0.0771 * parameters.avg_work_of_same_past_second 
	- 0.0088 * parameters.avg_wait_of_same_past_second 
	- 0.2642 * parameters.avg_latency_of_same_last_20 
	- 0.014 * parameters.max_latency_of_same_last_50 
	+ 286205871.0449;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM18(work_wait &parameters) {
  double actual_remaining = 
	2.3927 * parameters.work_so_far 
	+ 0.04 * parameters.wait_so_far 
	- 3668696.6132 * parameters.num_locks_so_far 
	- 1406361.5086 * parameters.total_wait_locks 
	- 0.7694 * parameters.mean_wait_of_all 
	- 102084811.0369 * parameters.cpu_usage 
	+ 12.6094 * parameters.avg_work_of_same_past_second 
	- 0.0088 * parameters.avg_wait_of_same_past_second 
	+ 0.3343 * parameters.avg_latency_of_same_last_20 
	+ 0.0293 * parameters.max_latency_of_same_last_50 
	+ 354373283.7167;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM19(work_wait &parameters) {
  double actual_remaining = 
	16.3236 * parameters.work_so_far 
	+ 0.04 * parameters.wait_so_far 
	- 3668696.6132 * parameters.num_locks_so_far 
	- 503125.2013 * parameters.total_wait_locks 
	- 0.7694 * parameters.mean_wait_of_all 
	- 102084811.0369 * parameters.cpu_usage 
	+ 6.0598 * parameters.avg_work_of_same_past_second 
	- 0.0088 * parameters.avg_wait_of_same_past_second 
	+ 0.1413 * parameters.avg_latency_of_same_last_20 
	+ 0.0293 * parameters.max_latency_of_same_last_50 
	+ 406605709.4872;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM20(work_wait &parameters) {
  double actual_remaining = 
	24.3045 * parameters.work_so_far 
	- 0.0089 * parameters.wait_so_far 
	- 3668696.6132 * parameters.num_locks_so_far 
	- 503125.2013 * parameters.total_wait_locks 
	+ 1.8043 * parameters.mean_wait_of_all 
	- 102084811.0369 * parameters.cpu_usage 
	+ 6.0598 * parameters.avg_work_of_same_past_second 
	- 0.0088 * parameters.avg_wait_of_same_past_second 
	+ 0.0538 * parameters.avg_latency_of_same_last_20 
	+ 0.0293 * parameters.max_latency_of_same_last_50 
	+ 408872068.0323;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM21(work_wait &parameters) {
  double actual_remaining = 
	25.6347 * parameters.work_so_far 
	+ 0.04 * parameters.wait_so_far 
	- 3668696.6132 * parameters.num_locks_so_far 
	- 503125.2013 * parameters.total_wait_locks 
	+ 0.5346 * parameters.mean_wait_of_all 
	- 102084811.0369 * parameters.cpu_usage 
	+ 6.0598 * parameters.avg_work_of_same_past_second 
	- 0.0088 * parameters.avg_wait_of_same_past_second 
	+ 0.1816 * parameters.avg_latency_of_same_last_20 
	+ 0.0293 * parameters.max_latency_of_same_last_50 
	+ 413547834.0426;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM22(work_wait &parameters) {
  double actual_remaining = 
	29.6488 * parameters.work_so_far 
	+ 0.04 * parameters.wait_so_far 
	- 3668696.6132 * parameters.num_locks_so_far 
	- 503125.2013 * parameters.total_wait_locks 
	- 0.7694 * parameters.mean_wait_of_all 
	- 102084811.0369 * parameters.cpu_usage 
	+ 6.0598 * parameters.avg_work_of_same_past_second 
	- 0.0088 * parameters.avg_wait_of_same_past_second 
	+ 0.1413 * parameters.avg_latency_of_same_last_20 
	+ 0.0293 * parameters.max_latency_of_same_last_50 
	+ 388543816.8355;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM23(work_wait &parameters) {
  double actual_remaining = 
	7.7391 * parameters.work_so_far 
	+ 0.2378 * parameters.wait_so_far 
	- 9062339.3105 * parameters.num_locks_so_far 
	+ 1782792.7105 * parameters.total_wait_locks 
	- 5.5189 * parameters.mean_wait_of_all 
	- 45720482.9417 * parameters.cpu_usage 
	+ 1.02 * parameters.avg_work_of_same_past_second 
	- 0.0088 * parameters.avg_wait_of_same_past_second 
	- 0.2305 * parameters.avg_latency_of_same_last_20 
	+ 0.0104 * parameters.max_latency_of_same_last_50 
	+ 223079064.6129;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM24(work_wait &parameters) {
  double actual_remaining = 
	1.3479 * parameters.work_so_far 
	+ 0.4914 * parameters.wait_so_far 
	- 2283094.599 * parameters.num_locks_so_far 
	+ 382477.3568 * parameters.total_wait_locks 
	- 1.1597 * parameters.mean_wait_of_all 
	- 10907221.4711 * parameters.cpu_usage 
	+ 0.1257 * parameters.avg_work_of_same_past_second 
	- 0.0088 * parameters.avg_wait_of_same_past_second 
	- 0.0309 * parameters.avg_latency_of_same_last_20 
	+ 0.0115 * parameters.max_latency_of_same_last_50 
	+ 161201223.2351;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM25(work_wait &parameters) {
  double actual_remaining = 
	6.9136 * parameters.work_so_far 
	+ 0.4577 * parameters.wait_so_far 
	- 7854802.8524 * parameters.num_locks_so_far 
	+ 1433729.4988 * parameters.total_wait_locks 
	- 4.5872 * parameters.mean_wait_of_all 
	- 155660403.6416 * parameters.cpu_usage 
	+ 0.3898 * parameters.avg_work_of_same_past_second 
	+ 0.1141 * parameters.avg_wait_of_same_past_second 
	- 0.1319 * parameters.avg_latency_of_same_last_20 
	- 0.0018 * parameters.max_latency_of_same_last_50 
	+ 301304904.924;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM26(work_wait &parameters) {
  double actual_remaining = 
	1.3682 * parameters.work_so_far 
	+ 0.4944 * parameters.wait_so_far 
	- 4299181.1638 * parameters.num_locks_so_far 
	+ 238468.4777 * parameters.total_wait_locks 
	- 2.2304 * parameters.mean_wait_of_all 
	- 4786445.8118 * parameters.cpu_usage 
	+ 0.4146 * parameters.avg_work_of_same_past_second 
	- 0.6941 * parameters.avg_wait_of_same_past_second 
	- 0.2177 * parameters.avg_latency_of_same_last_20 
	- 0.0112 * parameters.max_latency_of_same_last_50 
	+ 305568021.0344;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM27(work_wait &parameters) {
  double actual_remaining = 
	0.1638 * parameters.work_so_far 
	+ 0.4322 * parameters.wait_so_far 
	- 2661810.0179 * parameters.num_locks_so_far 
	+ 314108.7869 * parameters.total_wait_locks 
	- 0.358 * parameters.mean_wait_of_all 
	+ 180754885.2962 * parameters.cpu_usage 
	+ 0.8726 * parameters.avg_work_of_same_past_second 
	- 0.5147 * parameters.avg_wait_of_same_past_second 
	- 0.1263 * parameters.avg_latency_of_same_last_20 
	- 0.1811 * parameters.max_latency_of_same_last_50 
	+ 353648956.6976;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM28(work_wait &parameters) {
  double actual_remaining = 
	0.1638 * parameters.work_so_far 
	+ 0.4322 * parameters.wait_so_far 
	- 2661810.0179 * parameters.num_locks_so_far 
	+ 314108.7869 * parameters.total_wait_locks 
	- 0.358 * parameters.mean_wait_of_all 
	+ 180754885.2962 * parameters.cpu_usage 
	+ 0.8658 * parameters.avg_work_of_same_past_second 
	- 0.3934 * parameters.avg_wait_of_same_past_second 
	- 0.1231 * parameters.avg_latency_of_same_last_20 
	- 0.1811 * parameters.max_latency_of_same_last_50 
	+ 307083480.8228;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM29(work_wait &parameters) {
  double actual_remaining = 
	0.1638 * parameters.work_so_far 
	+ 0.6207 * parameters.wait_so_far 
	- 4057548.3912 * parameters.num_locks_so_far 
	+ 314108.7869 * parameters.total_wait_locks 
	+ 6.81 * parameters.mean_wait_of_all 
	+ 421271425.6213 * parameters.cpu_usage 
	+ 1.0842 * parameters.avg_work_of_same_past_second 
	+ 10.0772 * parameters.avg_wait_of_same_past_second 
	- 0.0018 * parameters.avg_latency_of_same_last_20 
	- 0.344 * parameters.max_latency_of_same_last_50 
	+ 56304850.1304;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM30(work_wait &parameters) {
  double actual_remaining = 
	0.1638 * parameters.work_so_far 
	+ 0.9728 * parameters.wait_so_far 
	- 1204053.8763 * parameters.num_locks_so_far 
	+ 314108.7869 * parameters.total_wait_locks 
	- 0.358 * parameters.mean_wait_of_all 
	- 4786445.8118 * parameters.cpu_usage 
	+ 0.1749 * parameters.avg_work_of_same_past_second 
	- 0.2271 * parameters.avg_wait_of_same_past_second 
	+ 0.3177 * parameters.avg_latency_of_same_last_20 
	- 0.1258 * parameters.max_latency_of_same_last_50 
	+ 288775647.3802;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM31(work_wait &parameters) {
  double actual_remaining = 
	1.1381 * parameters.work_so_far 
	+ 0.0829 * parameters.wait_so_far 
	- 418142.6735 * parameters.num_locks_so_far 
	+ 2132937.7327 * parameters.total_wait_locks 
	- 5.8611 * parameters.mean_wait_of_all 
	- 4786445.8118 * parameters.cpu_usage 
	+ 0.0423 * parameters.avg_work_of_same_past_second 
	+ 0.2747 * parameters.avg_wait_of_same_past_second 
	- 0.316 * parameters.avg_latency_of_same_last_20 
	- 0.1328 * parameters.max_latency_of_same_last_50 
	+ 210481799.3283;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM32(work_wait &parameters) {
  double actual_remaining = 
	2.8313 * parameters.work_so_far 
	+ 0.4214 * parameters.wait_so_far 
	- 7307191.3865 * parameters.num_locks_so_far 
	+ 1067773.0452 * parameters.total_wait_locks 
	- 3.0889 * parameters.mean_wait_of_all 
	- 244636228.6306 * parameters.cpu_usage 
	+ 0.4086 * parameters.avg_work_of_same_past_second 
	- 0.1465 * parameters.avg_wait_of_same_past_second 
	+ 0.0519 * parameters.avg_latency_of_same_last_20 
	- 0.0499 * parameters.max_latency_of_same_last_50 
	+ 464003369.1354;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM33(work_wait &parameters) {
  double actual_remaining = 
	13.7602 * parameters.work_so_far 
	+ 0.0136 * parameters.wait_so_far 
	- 3493387.7018 * parameters.num_locks_so_far 
	- 1246451.1676 * parameters.total_wait_locks 
	+ 7.1826 * parameters.mean_wait_of_all 
	- 831956166.0244 * parameters.cpu_usage 
	- 2.5699 * parameters.avg_work_of_same_past_second 
	- 0.3175 * parameters.avg_wait_of_same_past_second 
	+ 0.0017 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	+ 1679683810.721;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM34(work_wait &parameters) {
  double actual_remaining = 
	24.6217 * parameters.work_so_far 
	+ 0.0136 * parameters.wait_so_far 
	- 3493387.7018 * parameters.num_locks_so_far 
	+ 937522.8457 * parameters.total_wait_locks 
	- 10.9717 * parameters.mean_wait_of_all 
	- 754678245.3406 * parameters.cpu_usage 
	+ 0.3268 * parameters.avg_work_of_same_past_second 
	- 2.2427 * parameters.avg_wait_of_same_past_second 
	+ 0.0017 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	+ 2124535020.9701;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM35(work_wait &parameters) {
  double actual_remaining = 
	6.3164 * parameters.work_so_far 
	+ 0.0136 * parameters.wait_so_far 
	- 3493387.7018 * parameters.num_locks_so_far 
	+ 937522.8457 * parameters.total_wait_locks 
	- 6.0485 * parameters.mean_wait_of_all 
	- 694935027.9106 * parameters.cpu_usage 
	+ 0.3268 * parameters.avg_work_of_same_past_second 
	- 2.2427 * parameters.avg_wait_of_same_past_second 
	+ 0.0017 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	+ 1446102878.0188;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM36(work_wait &parameters) {
  double actual_remaining = 
	0.7687 * parameters.work_so_far 
	+ 0.0136 * parameters.wait_so_far 
	- 3493387.7018 * parameters.num_locks_so_far 
	+ 893348.8218 * parameters.total_wait_locks 
	- 5.7672 * parameters.mean_wait_of_all 
	- 97502853.6097 * parameters.cpu_usage 
	- 0.1165 * parameters.avg_work_of_same_past_second 
	- 3.4148 * parameters.avg_wait_of_same_past_second 
	+ 0.0017 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	+ 1968192115.23;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM37(work_wait &parameters) {
  double actual_remaining = 
	0.7687 * parameters.work_so_far 
	+ 0.0136 * parameters.wait_so_far 
	- 3493387.7018 * parameters.num_locks_so_far 
	+ 893348.8218 * parameters.total_wait_locks 
	- 5.7672 * parameters.mean_wait_of_all 
	- 97502853.6097 * parameters.cpu_usage 
	+ 0.0163 * parameters.avg_work_of_same_past_second 
	- 4.6606 * parameters.avg_wait_of_same_past_second 
	+ 0.0017 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	+ 1835744580.4569;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM38(work_wait &parameters) {
  double actual_remaining = 
	15.836 * parameters.work_so_far 
	+ 0.0136 * parameters.wait_so_far 
	- 1129242.1353 * parameters.num_locks_so_far 
	- 170030.3702 * parameters.total_wait_locks 
	- 0.0506 * parameters.mean_wait_of_all 
	- 1161054.7493 * parameters.cpu_usage 
	+ 0.0163 * parameters.avg_work_of_same_past_second 
	- 1.1786 * parameters.avg_wait_of_same_past_second 
	+ 0.0017 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	+ 744839663.0208;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM39(work_wait &parameters) {
  double actual_remaining = 
	14.1623 * parameters.work_so_far 
	+ 1.5998 * parameters.wait_so_far 
	- 12645521.0375 * parameters.num_locks_so_far 
	+ 5168.7661 * parameters.total_wait_locks 
	- 1.3911 * parameters.mean_wait_of_all 
	- 1161054.7493 * parameters.cpu_usage 
	+ 0.0188 * parameters.avg_work_of_same_past_second 
	- 2.2373 * parameters.avg_wait_of_same_past_second 
	+ 0.0017 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	+ 939993753.0066;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM40(work_wait &parameters) {
  double actual_remaining = 
	8.9729 * parameters.work_so_far 
	+ 0.452 * parameters.wait_so_far 
	- 11472244.6276 * parameters.num_locks_so_far 
	+ 429803.0961 * parameters.total_wait_locks 
	- 3.1455 * parameters.mean_wait_of_all 
	- 1161054.7493 * parameters.cpu_usage 
	+ 0.4589 * parameters.avg_work_of_same_past_second 
	- 0.0206 * parameters.avg_wait_of_same_past_second 
	+ 0.2618 * parameters.avg_latency_of_same_last_20 
	- 0.0699 * parameters.max_latency_of_same_last_50 
	+ 465020957.6623;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM41(work_wait &parameters) {
  double actual_remaining = 
	0.0545 * parameters.work_so_far 
	- 1.2449 * parameters.wait_so_far 
	- 54701124.0273 * parameters.num_locks_so_far 
	+ 212456.9669 * parameters.total_wait_locks 
	- 1.7376 * parameters.mean_wait_of_all 
	- 513460614.0715 * parameters.cpu_usage 
	+ 0.0044 * parameters.avg_work_of_same_past_second 
	- 0.3638 * parameters.avg_wait_of_same_past_second 
	- 0.1425 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 1249927647.8331;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM42(work_wait &parameters) {
  double actual_remaining = 
	9.5406 * parameters.work_so_far 
	+ 14151.7795 * parameters.wait_so_far 
	- 12105692.1298 * parameters.num_locks_so_far 
	+ 20179.2659 * parameters.total_wait_locks 
	- 0.135 * parameters.mean_wait_of_all 
	- 5118851.2796 * parameters.cpu_usage 
	+ 0.4054 * parameters.avg_work_of_same_past_second 
	- 0.0027 * parameters.avg_wait_of_same_past_second 
	+ 0.0023 * parameters.avg_latency_of_same_last_20 
	- 0.0008 * parameters.max_latency_of_same_last_50 
	+ 169497388.762;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM43(work_wait &parameters) {
  double actual_remaining = 
	10.0251 * parameters.work_so_far 
	- 0.0548 * parameters.wait_so_far 
	- 729638.9462 * parameters.num_locks_so_far 
	+ 764307.825 * parameters.total_wait_locks 
	- 5.968 * parameters.mean_wait_of_all 
	- 3150698.6003 * parameters.cpu_usage 
	+ 0.2678 * parameters.avg_work_of_same_past_second 
	- 0.0027 * parameters.avg_wait_of_same_past_second 
	+ 0.0032 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 646330469.0642;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM44(work_wait &parameters) {
  double actual_remaining = 
	7.1323 * parameters.work_so_far 
	- 0.0284 * parameters.wait_so_far 
	- 15573821.6911 * parameters.num_locks_so_far 
	+ 13903.7193 * parameters.total_wait_locks 
	- 1.2765 * parameters.mean_wait_of_all 
	- 3150698.6003 * parameters.cpu_usage 
	+ 0.0081 * parameters.avg_work_of_same_past_second 
	- 0.3151 * parameters.avg_wait_of_same_past_second 
	+ 0.122 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 554992481.4161;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM45(work_wait &parameters) {
  double actual_remaining = 
	0.0191 * parameters.work_so_far 
	+ 0.311 * parameters.wait_so_far 
	- 8561365.3154 * parameters.num_locks_so_far 
	- 113633.0631 * parameters.total_wait_locks 
	- 0.0257 * parameters.mean_wait_of_all 
	- 176122662.4897 * parameters.cpu_usage 
	+ 0.4938 * parameters.avg_work_of_same_past_second 
	- 0.152 * parameters.avg_wait_of_same_past_second 
	+ 0.1223 * parameters.avg_latency_of_same_last_20 
	- 0.0303 * parameters.max_latency_of_same_last_50 
	+ 544153875.3461;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM46(work_wait &parameters) {
  double actual_remaining = 
	1.022 * parameters.work_so_far 
	+ 0.7473 * parameters.wait_so_far 
	- 9449344.7938 * parameters.num_locks_so_far 
	+ 413740.9562 * parameters.total_wait_locks 
	- 1.163 * parameters.mean_wait_of_all 
	- 112772539.5326 * parameters.cpu_usage 
	+ 0.6542 * parameters.avg_work_of_same_past_second 
	- 0.6467 * parameters.avg_wait_of_same_past_second 
	+ 0.1473 * parameters.avg_latency_of_same_last_20 
	- 0.0354 * parameters.max_latency_of_same_last_50 
	+ 538904699.4833;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM47(work_wait &parameters) {
  double actual_remaining = 
	1.3558 * parameters.work_so_far 
	+ 0.8934 * parameters.wait_so_far 
	- 2850346.6585 * parameters.num_locks_so_far 
	- 63641.1153 * parameters.total_wait_locks 
	+ 0.3582 * parameters.mean_wait_of_all 
	- 156186833.3247 * parameters.cpu_usage 
	+ 0.385 * parameters.avg_work_of_same_past_second 
	- 0.0546 * parameters.avg_wait_of_same_past_second 
	+ 0.086 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 231489904.514;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM48(work_wait &parameters) {
  double actual_remaining = 
	-0.8562 * parameters.work_so_far 
	+ 0.8826 * parameters.wait_so_far 
	+ 276774.8682 * parameters.num_locks_so_far 
	+ 7430.2381 * parameters.total_wait_locks 
	- 0.001 * parameters.mean_wait_of_all 
	- 4227688.2662 * parameters.cpu_usage 
	+ 0.0033 * parameters.avg_work_of_same_past_second 
	- 0.001 * parameters.avg_wait_of_same_past_second 
	+ 0.0177 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 178487315.5667;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM49(work_wait &parameters) {
  double actual_remaining = 
	-0.8776 * parameters.work_so_far 
	- 1.0553 * parameters.wait_so_far 
	+ 276774.8682 * parameters.num_locks_so_far 
	+ 7430.2381 * parameters.total_wait_locks 
	- 0.4053 * parameters.mean_wait_of_all 
	- 846749050.753 * parameters.cpu_usage 
	- 0.243 * parameters.avg_work_of_same_past_second 
	+ 8.8401 * parameters.avg_wait_of_same_past_second 
	- 0.3894 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 286711864.1772;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM50(work_wait &parameters) {
  double actual_remaining = 
	-0.8776 * parameters.work_so_far 
	- 2.1112 * parameters.wait_so_far 
	+ 276774.8682 * parameters.num_locks_so_far 
	+ 702741.336 * parameters.total_wait_locks 
	- 0.4053 * parameters.mean_wait_of_all 
	- 846749050.753 * parameters.cpu_usage 
	- 0.243 * parameters.avg_work_of_same_past_second 
	+ 8.8401 * parameters.avg_wait_of_same_past_second 
	- 0.3894 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 393284617.4091;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM51(work_wait &parameters) {
  double actual_remaining = 
	-75.5356 * parameters.work_so_far 
	+ 0.8724 * parameters.wait_so_far 
	+ 276774.8682 * parameters.num_locks_so_far 
	+ 7430.2381 * parameters.total_wait_locks 
	- 0.4053 * parameters.mean_wait_of_all 
	- 1502052160.8752 * parameters.cpu_usage 
	- 0.243 * parameters.avg_work_of_same_past_second 
	- 0.001 * parameters.avg_wait_of_same_past_second 
	+ 0.4937 * parameters.avg_latency_of_same_last_20 
	- 0.1339 * parameters.max_latency_of_same_last_50 
	+ 1743667979.0676;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM52(work_wait &parameters) {
  double actual_remaining = 
	-42.291 * parameters.work_so_far 
	+ 0.4549 * parameters.wait_so_far 
	+ 276774.8682 * parameters.num_locks_so_far 
	+ 7430.2381 * parameters.total_wait_locks 
	- 1.3378 * parameters.mean_wait_of_all 
	- 39921458.0138 * parameters.cpu_usage 
	- 0.073 * parameters.avg_work_of_same_past_second 
	- 0.001 * parameters.avg_wait_of_same_past_second 
	+ 0.3189 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 475529421.9587;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM53(work_wait &parameters) {
  double actual_remaining = 
	1.7176 * parameters.work_so_far 
	+ 0.0889 * parameters.wait_so_far 
	+ 18135242.8925 * parameters.num_locks_so_far 
	+ 7430.2381 * parameters.total_wait_locks 
	+ 0.0301 * parameters.mean_wait_of_all 
	- 4227688.2662 * parameters.cpu_usage 
	- 0.0311 * parameters.avg_work_of_same_past_second 
	- 0.001 * parameters.avg_wait_of_same_past_second 
	+ 0.0097 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 476500426.2093;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM54(work_wait &parameters) {
  double actual_remaining = 
	0.9885 * parameters.work_so_far 
	+ 0.6913 * parameters.wait_so_far 
	- 343947.1484 * parameters.num_locks_so_far 
	+ 10793.366 * parameters.total_wait_locks 
	- 0.0126 * parameters.mean_wait_of_all 
	- 4227688.2662 * parameters.cpu_usage 
	+ 0.002 * parameters.avg_work_of_same_past_second 
	- 0.001 * parameters.avg_wait_of_same_past_second 
	+ 0.2255 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 159035773.3382;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM55(work_wait &parameters) {
  double actual_remaining = 
	0.3649 * parameters.work_so_far 
	+ 0.5997 * parameters.wait_so_far 
	- 1475262.6923 * parameters.num_locks_so_far 
	+ 161554.1688 * parameters.total_wait_locks 
	- 0.7006 * parameters.mean_wait_of_all 
	+ 74719901.4295 * parameters.cpu_usage 
	+ 0.6036 * parameters.avg_work_of_same_past_second 
	- 1.0497 * parameters.avg_wait_of_same_past_second 
	+ 0.0066 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 375028946.3963;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM56(work_wait &parameters) {
  double actual_remaining = 
	0.329 * parameters.work_so_far 
	+ 0.0515 * parameters.wait_so_far 
	+ 11617946.9278 * parameters.num_locks_so_far 
	+ 536795.8711 * parameters.total_wait_locks 
	- 2.4574 * parameters.mean_wait_of_all 
	+ 24705983.35 * parameters.cpu_usage 
	+ 0.6063 * parameters.avg_work_of_same_past_second 
	+ 0.336 * parameters.avg_wait_of_same_past_second 
	+ 0.0066 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 239646698.1847;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM57(work_wait &parameters) {
  double actual_remaining = 
	0.329 * parameters.work_so_far 
	- 0.9134 * parameters.wait_so_far 
	+ 40888246.5014 * parameters.num_locks_so_far 
	+ 446669.9779 * parameters.total_wait_locks 
	- 2.4574 * parameters.mean_wait_of_all 
	+ 24705983.35 * parameters.cpu_usage 
	+ 0.4871 * parameters.avg_work_of_same_past_second 
	+ 0.694 * parameters.avg_wait_of_same_past_second 
	+ 0.0066 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 532447409.1363;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM58(work_wait &parameters) {
  double actual_remaining = 
	0.329 * parameters.work_so_far 
	+ 0.0515 * parameters.wait_so_far 
	+ 9463067.4297 * parameters.num_locks_so_far 
	+ 859598.5401 * parameters.total_wait_locks 
	- 3.3539 * parameters.mean_wait_of_all 
	+ 24705983.35 * parameters.cpu_usage 
	+ 0.3227 * parameters.avg_work_of_same_past_second 
	- 1.2116 * parameters.avg_wait_of_same_past_second 
	+ 0.0066 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 813099413.7497;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM59(work_wait &parameters) {
  double actual_remaining = 
	0.329 * parameters.work_so_far 
	+ 0.0515 * parameters.wait_so_far 
	+ 7465644.4376 * parameters.num_locks_so_far 
	+ 294275.7483 * parameters.total_wait_locks 
	- 2.419 * parameters.mean_wait_of_all 
	+ 24705983.35 * parameters.cpu_usage 
	+ 0.2832 * parameters.avg_work_of_same_past_second 
	- 0.001 * parameters.avg_wait_of_same_past_second 
	+ 0.0066 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 535918986.2131;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM60(work_wait &parameters) {
  double actual_remaining = 
	0.5802 * parameters.work_so_far 
	+ 0.0515 * parameters.wait_so_far 
	- 1237424.181 * parameters.num_locks_so_far 
	+ 348081.0226 * parameters.total_wait_locks 
	- 1.4533 * parameters.mean_wait_of_all 
	+ 24705983.35 * parameters.cpu_usage 
	+ 0.2388 * parameters.avg_work_of_same_past_second 
	- 0.001 * parameters.avg_wait_of_same_past_second 
	+ 0.0066 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 403662807.3657;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM61(work_wait &parameters) {
  double actual_remaining = 
	0.7078 * parameters.work_so_far 
	+ 0.0515 * parameters.wait_so_far 
	- 406065.1039 * parameters.num_locks_so_far 
	+ 348081.0226 * parameters.total_wait_locks 
	- 1.4533 * parameters.mean_wait_of_all 
	+ 24705983.35 * parameters.cpu_usage 
	+ 0.5202 * parameters.avg_work_of_same_past_second 
	- 0.001 * parameters.avg_wait_of_same_past_second 
	+ 0.0066 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 326273769.2952;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM62(work_wait &parameters) {
  double actual_remaining = 
	1.3891 * parameters.work_so_far 
	+ 0.76 * parameters.wait_so_far 
	- 5112288.0366 * parameters.num_locks_so_far 
	- 702670.2579 * parameters.total_wait_locks 
	+ 3.7622 * parameters.mean_wait_of_all 
	- 197514697.3843 * parameters.cpu_usage 
	+ 0.2823 * parameters.avg_work_of_same_past_second 
	- 0.001 * parameters.avg_wait_of_same_past_second 
	+ 0.0103 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 448035278.1193;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM63(work_wait &parameters) {
  double actual_remaining = 
	0.9647 * parameters.work_so_far 
	+ 0.2767 * parameters.wait_so_far 
	- 4019058.9661 * parameters.num_locks_so_far 
	+ 269274.4829 * parameters.total_wait_locks 
	+ 0.4178 * parameters.mean_wait_of_all 
	- 39054774.4221 * parameters.cpu_usage 
	+ 0.0472 * parameters.avg_work_of_same_past_second 
	+ 0.6302 * parameters.avg_wait_of_same_past_second 
	+ 0.0906 * parameters.avg_latency_of_same_last_20 
	- 0.0228 * parameters.max_latency_of_same_last_50 
	+ 537433372.1139;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM64(work_wait &parameters) {
  double actual_remaining = 
	1.173 * parameters.work_so_far 
	+ 0.2767 * parameters.wait_so_far 
	+ 16027502.1171 * parameters.num_locks_so_far 
	+ 357201.2021 * parameters.total_wait_locks 
	+ 0.4178 * parameters.mean_wait_of_all 
	- 39054774.4221 * parameters.cpu_usage 
	+ 0.0472 * parameters.avg_work_of_same_past_second 
	+ 0.1795 * parameters.avg_wait_of_same_past_second 
	+ 0.0906 * parameters.avg_latency_of_same_last_20 
	- 0.0228 * parameters.max_latency_of_same_last_50 
	+ 611581079.768;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM65(work_wait &parameters) {
  double actual_remaining = 
	1.173 * parameters.work_so_far 
	+ 0.2767 * parameters.wait_so_far 
	+ 17281460.4741 * parameters.num_locks_so_far 
	+ 357201.2021 * parameters.total_wait_locks 
	+ 0.4178 * parameters.mean_wait_of_all 
	- 39054774.4221 * parameters.cpu_usage 
	+ 0.0472 * parameters.avg_work_of_same_past_second 
	+ 0.1795 * parameters.avg_wait_of_same_past_second 
	+ 0.0906 * parameters.avg_latency_of_same_last_20 
	- 0.0228 * parameters.max_latency_of_same_last_50 
	+ 673716310.9298;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM66(work_wait &parameters) {
  double actual_remaining = 
	0.8811 * parameters.work_so_far 
	+ 0.6683 * parameters.wait_so_far 
	- 3750555.2303 * parameters.num_locks_so_far 
	+ 225374.3852 * parameters.total_wait_locks 
	+ 0.4178 * parameters.mean_wait_of_all 
	- 39054774.4221 * parameters.cpu_usage 
	+ 0.4418 * parameters.avg_work_of_same_past_second 
	+ 0.9484 * parameters.avg_wait_of_same_past_second 
	+ 0.0906 * parameters.avg_latency_of_same_last_20 
	- 0.0228 * parameters.max_latency_of_same_last_50 
	+ 215613359.6274;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM67(work_wait &parameters) {
  double actual_remaining = 
	0.8811 * parameters.work_so_far 
	- 0.7474 * parameters.wait_so_far 
	- 3750555.2303 * parameters.num_locks_so_far 
	+ 225374.3852 * parameters.total_wait_locks 
	+ 0.4178 * parameters.mean_wait_of_all 
	- 39054774.4221 * parameters.cpu_usage 
	+ 0.2428 * parameters.avg_work_of_same_past_second 
	+ 1.1534 * parameters.avg_wait_of_same_past_second 
	+ 0.0906 * parameters.avg_latency_of_same_last_20 
	- 0.0228 * parameters.max_latency_of_same_last_50 
	+ 1203931785.306;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM68(work_wait &parameters) {
  double actual_remaining = 
	2104.4711 * parameters.work_so_far 
	+ 0.4306 * parameters.wait_so_far 
	- 1635156.7736 * parameters.num_locks_so_far 
	- 124583.6531 * parameters.total_wait_locks 
	+ 0.7917 * parameters.mean_wait_of_all 
	- 39054774.4221 * parameters.cpu_usage 
	- 0.0496 * parameters.avg_work_of_same_past_second 
	- 0.1011 * parameters.avg_wait_of_same_past_second 
	- 0.4754 * parameters.avg_latency_of_same_last_20 
	- 0.0335 * parameters.max_latency_of_same_last_50 
	+ 689532786.0561;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM69(work_wait &parameters) {
  double actual_remaining = 
	0.4269 * parameters.work_so_far 
	+ 0.4306 * parameters.wait_so_far 
	- 1635156.7736 * parameters.num_locks_so_far 
	- 124583.6531 * parameters.total_wait_locks 
	+ 0.7917 * parameters.mean_wait_of_all 
	- 39054774.4221 * parameters.cpu_usage 
	- 0.0496 * parameters.avg_work_of_same_past_second 
	- 0.1011 * parameters.avg_wait_of_same_past_second 
	+ 0.304 * parameters.avg_latency_of_same_last_20 
	- 0.0079 * parameters.max_latency_of_same_last_50 
	+ 433221204.0262;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM70(work_wait &parameters) {
  double actual_remaining = 
	0.7955 * parameters.work_so_far 
	+ 0.597 * parameters.wait_so_far 
	- 8647790.0716 * parameters.num_locks_so_far 
	+ 1785387.4187 * parameters.total_wait_locks 
	- 5.5471 * parameters.mean_wait_of_all 
	- 39054774.4221 * parameters.cpu_usage 
	- 0.7413 * parameters.avg_work_of_same_past_second 
	- 0.1011 * parameters.avg_wait_of_same_past_second 
	+ 0.0918 * parameters.avg_latency_of_same_last_20 
	- 0.084 * parameters.max_latency_of_same_last_50 
	+ 635535608.7012;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM71(work_wait &parameters) {
  double actual_remaining = 
	1.0864 * parameters.work_so_far 
	+ 0.597 * parameters.wait_so_far 
	- 2384831.6584 * parameters.num_locks_so_far 
	+ 374095.4467 * parameters.total_wait_locks 
	- 2.6714 * parameters.mean_wait_of_all 
	- 39054774.4221 * parameters.cpu_usage 
	- 0.0074 * parameters.avg_work_of_same_past_second 
	- 0.1011 * parameters.avg_wait_of_same_past_second 
	+ 0.0918 * parameters.avg_latency_of_same_last_20 
	- 0.0709 * parameters.max_latency_of_same_last_50 
	+ 641818163.5975;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM72(work_wait &parameters) {
  double actual_remaining = 
	0.4933 * parameters.work_so_far 
	+ 0.6303 * parameters.wait_so_far 
	- 1236272.2381 * parameters.num_locks_so_far 
	- 224410.8488 * parameters.total_wait_locks 
	- 0.6704 * parameters.mean_wait_of_all 
	- 39054774.4221 * parameters.cpu_usage 
	- 1.1584 * parameters.avg_work_of_same_past_second 
	+ 1.2817 * parameters.avg_wait_of_same_past_second 
	+ 0.0918 * parameters.avg_latency_of_same_last_20 
	- 0.0443 * parameters.max_latency_of_same_last_50 
	+ 786647491.1355;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM73(work_wait &parameters) {
  double actual_remaining = 
	1.3759 * parameters.work_so_far 
	+ 0.7376 * parameters.wait_so_far 
	- 2855948.929 * parameters.num_locks_so_far 
	- 465686.227 * parameters.total_wait_locks 
	+ 2.4266 * parameters.mean_wait_of_all 
	- 14692612.7867 * parameters.cpu_usage 
	+ 0.0376 * parameters.avg_work_of_same_past_second 
	- 0.0078 * parameters.avg_wait_of_same_past_second 
	+ 0.0077 * parameters.avg_latency_of_same_last_20 
	- 0.0018 * parameters.max_latency_of_same_last_50 
	+ 279447818.078;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM74(work_wait &parameters) {
  double actual_remaining = 
	0.3158 * parameters.work_so_far 
	+ 0.069 * parameters.wait_so_far 
	- 926929.3395 * parameters.num_locks_so_far 
	- 586625.6169 * parameters.total_wait_locks 
	+ 1.2048 * parameters.mean_wait_of_all 
	- 14692612.7867 * parameters.cpu_usage 
	+ 0.1948 * parameters.avg_work_of_same_past_second 
	- 0.0078 * parameters.avg_wait_of_same_past_second 
	+ 0.0077 * parameters.avg_latency_of_same_last_20 
	- 0.0061 * parameters.max_latency_of_same_last_50 
	+ 811404770.9388;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM75(work_wait &parameters) {
  double actual_remaining = 
	0.3158 * parameters.work_so_far 
	+ 0.069 * parameters.wait_so_far 
	- 926929.3395 * parameters.num_locks_so_far 
	+ 210060.4228 * parameters.total_wait_locks 
	+ 1.7201 * parameters.mean_wait_of_all 
	- 14692612.7867 * parameters.cpu_usage 
	+ 0.2417 * parameters.avg_work_of_same_past_second 
	- 0.0078 * parameters.avg_wait_of_same_past_second 
	+ 0.0077 * parameters.avg_latency_of_same_last_20 
	- 0.0061 * parameters.max_latency_of_same_last_50 
	+ 524803515.6408;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM76(work_wait &parameters) {
  double actual_remaining = 
	0.7051 * parameters.work_so_far 
	+ 0.069 * parameters.wait_so_far 
	- 7021452.8526 * parameters.num_locks_so_far 
	- 573921.6783 * parameters.total_wait_locks 
	+ 1.1703 * parameters.mean_wait_of_all 
	- 14692612.7867 * parameters.cpu_usage 
	+ 0.9377 * parameters.avg_work_of_same_past_second 
	- 0.0078 * parameters.avg_wait_of_same_past_second 
	+ 0.0077 * parameters.avg_latency_of_same_last_20 
	- 0.0061 * parameters.max_latency_of_same_last_50 
	+ 886140001.4604;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM77(work_wait &parameters) {
  double actual_remaining = 
	0.7051 * parameters.work_so_far 
	+ 0.069 * parameters.wait_so_far 
	- 7021452.8526 * parameters.num_locks_so_far 
	- 573921.6783 * parameters.total_wait_locks 
	+ 1.1703 * parameters.mean_wait_of_all 
	+ 889328940.7724 * parameters.cpu_usage 
	+ 0.8846 * parameters.avg_work_of_same_past_second 
	- 0.0078 * parameters.avg_wait_of_same_past_second 
	+ 0.0077 * parameters.avg_latency_of_same_last_20 
	- 0.0061 * parameters.max_latency_of_same_last_50 
	+ 133071596.9306;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM78(work_wait &parameters) {
  double actual_remaining = 
	0.958 * parameters.work_so_far 
	+ 0.069 * parameters.wait_so_far 
	- 6137966.8676 * parameters.num_locks_so_far 
	- 523520.0879 * parameters.total_wait_locks 
	+ 1.1703 * parameters.mean_wait_of_all 
	- 14692612.7867 * parameters.cpu_usage 
	+ 0.6976 * parameters.avg_work_of_same_past_second 
	- 0.0078 * parameters.avg_wait_of_same_past_second 
	+ 0.0077 * parameters.avg_latency_of_same_last_20 
	- 0.0061 * parameters.max_latency_of_same_last_50 
	+ 756697657.6914;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM79(work_wait &parameters) {
  double actual_remaining = 
	0.8237 * parameters.work_so_far 
	+ 0.069 * parameters.wait_so_far 
	- 6137966.8676 * parameters.num_locks_so_far 
	- 523520.0879 * parameters.total_wait_locks 
	+ 1.1703 * parameters.mean_wait_of_all 
	- 1178594548.8792 * parameters.cpu_usage 
	+ 0.7014 * parameters.avg_work_of_same_past_second 
	- 0.0078 * parameters.avg_wait_of_same_past_second 
	+ 0.0077 * parameters.avg_latency_of_same_last_20 
	- 0.0061 * parameters.max_latency_of_same_last_50 
	+ 1949553388.5318;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM80(work_wait &parameters) {
  double actual_remaining = 
	0.3427 * parameters.work_so_far 
	+ 0.9933 * parameters.wait_so_far 
	+ 1631642.8426 * parameters.num_locks_so_far 
	- 200579.8096 * parameters.total_wait_locks 
	+ 0.9034 * parameters.mean_wait_of_all 
	- 14692612.7867 * parameters.cpu_usage 
	+ 0.4791 * parameters.avg_work_of_same_past_second 
	- 0.0078 * parameters.avg_wait_of_same_past_second 
	+ 0.1197 * parameters.avg_latency_of_same_last_20 
	- 0.0123 * parameters.max_latency_of_same_last_50 
	- 38866751.6537;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM81(work_wait &parameters) {
  double actual_remaining = 
	1.1459 * parameters.work_so_far 
	+ 0.9757 * parameters.wait_so_far 
	- 1903065.8495 * parameters.num_locks_so_far 
	- 793355.7281 * parameters.total_wait_locks 
	+ 3.5591 * parameters.mean_wait_of_all 
	- 208115728.8892 * parameters.cpu_usage 
	+ 0.3265 * parameters.avg_work_of_same_past_second 
	- 0.1985 * parameters.avg_wait_of_same_past_second 
	+ 0.1002 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 284507727.4909;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
tpcc_estimate(work_wait &parameters){

  if (parameters.wait_so_far <= 301664470.5) {

    if (parameters.total_wait_locks <= 147.5) {

      if (parameters.total_wait_locks <= 38.5) {

        if (parameters.work_so_far <= 7678.5) {
          return tpcc_LM1(parameters);
        } else {

          if (parameters.work_so_far <= 33451244.5) {
            return tpcc_LM2(parameters);
          } else {
            return tpcc_LM3(parameters);
          }
        }
      } else {

        if (parameters.work_so_far <= 32966084.5) {

          if (parameters.total_wait_locks <= 79.5) {

            if (parameters.wait_so_far <= 3306.5) {

              if (parameters.mean_wait_of_all <= 24347500) {
                return tpcc_LM4(parameters);
              } else {
                return tpcc_LM5(parameters);
              }
            } else {

              if (parameters.wait_so_far <= 67585738) {

                if (parameters.work_so_far <= 10391) {
                  return tpcc_LM6(parameters);
                } else {

                  if (parameters.max_latency_of_same_last_50 <= 212510000) {

                    if (parameters.cpu_usage <= 0.918) {
                      return tpcc_LM7(parameters);
                    } else {
                      return tpcc_LM8(parameters);
                    }
                  } else {

                    if (parameters.total_wait_locks <= 63.5) {
                      return tpcc_LM9(parameters);
                    } else {
                      return tpcc_LM10(parameters);
                    }
                  }
                }
              } else {
                return tpcc_LM11(parameters);
              }
            }
          } else {

            if (parameters.avg_wait_of_same_past_second <= 38662900) {

              if (parameters.max_latency_of_same_last_50 <= 462507000) {

                if (parameters.total_wait_locks <= 95.5) {

                  if (parameters.mean_wait_of_all <= 34023750) {
                    return tpcc_LM12(parameters);
                  } else {
                    return tpcc_LM13(parameters);
                  }
                } else {

                  if (parameters.cpu_usage <= 0.92) {

                    if (parameters.mean_wait_of_all <= 34712350) {

                      if (parameters.mean_wait_of_all <= 34203250) {
                        return tpcc_LM14(parameters);
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
              } else {

                if (parameters.mean_wait_of_all <= 34699250) {

                  if (parameters.avg_work_of_same_past_second <= 14004950) {

                    if (parameters.avg_work_of_same_past_second <= 7213300) {
                      return tpcc_LM18(parameters);
                    } else {

                      if (parameters.total_wait_locks <= 132.5) {

                        if (parameters.avg_latency_of_same_last_20 <= 151303000) {
                          return tpcc_LM19(parameters);
                        } else {

                          if (parameters.avg_work_of_same_past_second <= 10391100) {
                            return tpcc_LM20(parameters);
                          } else {
                            return tpcc_LM21(parameters);
                          }
                        }
                      } else {
                        return tpcc_LM22(parameters);
                      }
                    }
                  } else {
                    return tpcc_LM23(parameters);
                  }
                } else {
                  return tpcc_LM24(parameters);
                }
              }
            } else {
              return tpcc_LM25(parameters);
            }
          }
        } else {

          if (parameters.work_so_far <= 189196310) {

            if (parameters.total_wait_locks <= 90.5) {
              return tpcc_LM26(parameters);
            } else {

              if (parameters.avg_wait_of_same_past_second <= 15015500) {

                if (parameters.avg_wait_of_same_past_second <= 11215900) {

                  if (parameters.avg_wait_of_same_past_second <= 5158435) {
                    return tpcc_LM27(parameters);
                  } else {
                    return tpcc_LM28(parameters);
                  }
                } else {
                  return tpcc_LM29(parameters);
                }
              } else {
                return tpcc_LM30(parameters);
              }
            }
          } else {
            return tpcc_LM31(parameters);
          }
        }
      }
    } else {

      if (parameters.work_so_far <= 16085796) {

        if (parameters.mean_wait_of_all <= 69745200) {
          return tpcc_LM32(parameters);
        } else {

          if (parameters.avg_wait_of_same_past_second <= 257042500) {

            if (parameters.wait_so_far <= 88923982) {

              if (parameters.num_locks_so_far <= 5.5) {

                if (parameters.avg_wait_of_same_past_second <= 195709500) {

                  if (parameters.avg_work_of_same_past_second <= 268967500) {
                    return tpcc_LM33(parameters);
                  } else {

                    if (parameters.avg_work_of_same_past_second <= 442692000) {

                      if (parameters.cpu_usage <= 0.893) {
                        return tpcc_LM34(parameters);
                      } else {
                        return tpcc_LM35(parameters);
                      }
                    } else {

                      if (parameters.work_so_far <= 18438.5) {
                        return tpcc_LM36(parameters);
                      } else {
                        return tpcc_LM37(parameters);
                      }
                    }
                  }
                } else {
                  return tpcc_LM38(parameters);
                }
              } else {
                return tpcc_LM39(parameters);
              }
            } else {
              return tpcc_LM40(parameters);
            }
          } else {

            if (parameters.wait_so_far <= 45390982.5) {

              if (parameters.avg_work_of_same_past_second <= 31661050) {
                return tpcc_LM41(parameters);
              } else {

                if (parameters.wait_so_far <= 11616.5) {
                  return tpcc_LM42(parameters);
                } else {

                  if (parameters.wait_so_far <= 1084333.5) {
                    return tpcc_LM43(parameters);
                  } else {
                    return tpcc_LM44(parameters);
                  }
                }
              }
            } else {
              return tpcc_LM45(parameters);
            }
          }
        }
      } else {
        return tpcc_LM46(parameters);
      }
    }
  } else {

    if (parameters.wait_so_far <= 677958255) {

      if (parameters.avg_work_of_same_past_second <= 164752500) {
        return tpcc_LM47(parameters);
      } else {

        if (parameters.wait_so_far <= 479823270.5) {

          if (parameters.avg_latency_of_same_last_20 <= 443374500) {

            if (parameters.avg_work_of_same_past_second <= 266003500) {

              if (parameters.num_locks_so_far <= 11.5) {

                if (parameters.work_so_far <= 2938601.5) {

                  if (parameters.total_wait_locks <= 373) {
                    return tpcc_LM48(parameters);
                  } else {

                    if (parameters.avg_work_of_same_past_second <= 193673000) {

                      if (parameters.avg_latency_of_same_last_20 <= 267668500) {

                        if (parameters.avg_wait_of_same_past_second <= 199639500) {
                          return tpcc_LM49(parameters);
                        } else {
                          return tpcc_LM50(parameters);
                        }
                      } else {
                        return tpcc_LM51(parameters);
                      }
                    } else {
                      return tpcc_LM52(parameters);
                    }
                  }
                } else {
                  return tpcc_LM53(parameters);
                }
              } else {
                return tpcc_LM54(parameters);
              }
            } else {

              if (parameters.cpu_usage <= 0.898) {
                return tpcc_LM55(parameters);
              } else {

                if (parameters.num_locks_so_far <= 10.5) {

                  if (parameters.avg_latency_of_same_last_20 <= 374931000) {

                    if (parameters.total_wait_locks <= 452) {

                      if (parameters.avg_wait_of_same_past_second <= 243751500) {
                        return tpcc_LM56(parameters);
                      } else {
                        return tpcc_LM57(parameters);
                      }
                    } else {
                      return tpcc_LM58(parameters);
                    }
                  } else {
                    return tpcc_LM59(parameters);
                  }
                } else {

                  if (parameters.num_locks_so_far <= 37.5) {
                    return tpcc_LM60(parameters);
                  } else {
                    return tpcc_LM61(parameters);
                  }
                }
              }
            }
          } else {
            return tpcc_LM62(parameters);
          }
        } else {

          if (parameters.cpu_usage <= 0.837) {

            if (parameters.avg_wait_of_same_past_second <= 196576000) {

              if (parameters.avg_wait_of_same_past_second <= 113421000) {
                return tpcc_LM63(parameters);
              } else {

                if (parameters.avg_work_of_same_past_second <= 202374500) {

                  if (parameters.work_so_far <= 10264544.5) {
                    return tpcc_LM64(parameters);
                  } else {
                    return tpcc_LM65(parameters);
                  }
                } else {

                  if (parameters.wait_so_far <= 600439529.5) {
                    return tpcc_LM66(parameters);
                  } else {
                    return tpcc_LM67(parameters);
                  }
                }
              }
            } else {

              if (parameters.avg_latency_of_same_last_20 <= 492111500) {

                if (parameters.work_so_far <= 102299) {
                  return tpcc_LM68(parameters);
                } else {
                  return tpcc_LM69(parameters);
                }
              } else {

                if (parameters.wait_so_far <= 577738141) {

                  if (parameters.max_latency_of_same_last_50 <= 1310110000) {
                    return tpcc_LM70(parameters);
                  } else {
                    return tpcc_LM71(parameters);
                  }
                } else {
                  return tpcc_LM72(parameters);
                }
              }
            }
          } else {

            if (parameters.avg_work_of_same_past_second <= 260542000) {
              return tpcc_LM73(parameters);
            } else {

              if (parameters.max_latency_of_same_last_50 <= 1612705000) {

                if (parameters.work_so_far <= 17127369) {

                  if (parameters.avg_work_of_same_past_second <= 297844000) {
                    return tpcc_LM74(parameters);
                  } else {
                    return tpcc_LM75(parameters);
                  }
                } else {

                  if (parameters.num_locks_so_far <= 15) {

                    if (parameters.avg_work_of_same_past_second <= 266933000) {
                      return tpcc_LM76(parameters);
                    } else {
                      return tpcc_LM77(parameters);
                    }
                  } else {

                    if (parameters.avg_work_of_same_past_second <= 319527500) {
                      return tpcc_LM78(parameters);
                    } else {
                      return tpcc_LM79(parameters);
                    }
                  }
                }
              } else {
                return tpcc_LM80(parameters);
              }
            }
          }
        }
      }
    } else {
      return tpcc_LM81(parameters);
    }
  }
}