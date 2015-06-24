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