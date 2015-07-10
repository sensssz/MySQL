#include "my_global.h"
#include "trace_tool.h"

static
double
new_order_LM1(work_wait &parameters) {
  double actual_remaining = 
	0.0008 * parameters.work_so_far 
	- 0.1958 * parameters.wait_so_far 
	+ 464250.0734 * parameters.total_wait_locks 
	- 0.501 * parameters.mean_wait_of_all 
	- 138605072.6616 * parameters.cpu_usage 
	+ 0.2496 * parameters.avg_work_of_same_past_second 
	- 0.1694 * parameters.avg_wait_of_same_past_second 
	+ 0.2215 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 219626773.6622;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM2(work_wait &parameters) {
  double actual_remaining = 
	0.9837 * parameters.work_so_far 
	- 0.2296 * parameters.wait_so_far 
	- 10.8747 * parameters.total_wait_locks 
	+ 0.0074 * parameters.mean_wait_of_all 
	- 443855238.3075 * parameters.cpu_usage 
	+ 0.002 * parameters.avg_work_of_same_past_second 
	- 0.0012 * parameters.avg_wait_of_same_past_second 
	+ 0.0017 * parameters.avg_latency_of_same_last_20 
	+ 0.0592 * parameters.max_latency_of_same_last_50 
	+ 739767288.1442;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM3(work_wait &parameters) {
  double actual_remaining = 
	0.0092 * parameters.work_so_far 
	- 0.0755 * parameters.wait_so_far 
	- 484841.5158 * parameters.total_wait_locks 
	+ 4.6038 * parameters.mean_wait_of_all 
	- 194398741.021 * parameters.cpu_usage 
	+ 0.1839 * parameters.avg_work_of_same_past_second 
	- 0.0023 * parameters.avg_wait_of_same_past_second 
	+ 0.2639 * parameters.avg_latency_of_same_last_20 
	+ 0.0006 * parameters.max_latency_of_same_last_50 
	- 81201299.8491;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
new_order_estimate(work_wait &parameters){

  if (parameters.total_wait_locks <= 446.5) {
    return new_order_LM1(parameters);
  } else {

    if (parameters.wait_so_far <= 411367475.5) {
      return new_order_LM2(parameters);
    } else {
      return new_order_LM3(parameters);
    }
  }
}
static
double
payment_LM1(work_wait &parameters) {
  double actual_remaining = 
	32.4224 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 645.5648 * parameters.total_wait_locks 
	- 0.0004 * parameters.mean_wait_of_all 
	- 474327.6516 * parameters.cpu_usage 
	+ 0.0117 * parameters.avg_work_of_same_past_second 
	- 0.001 * parameters.avg_wait_of_same_past_second 
	+ 0.0031 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 5005699.9698;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM2(work_wait &parameters) {
  double actual_remaining = 
	25.662 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 645.5648 * parameters.total_wait_locks 
	- 0.0179 * parameters.mean_wait_of_all 
	- 474327.6516 * parameters.cpu_usage 
	+ 0.1137 * parameters.avg_work_of_same_past_second 
	- 0.0111 * parameters.avg_wait_of_same_past_second 
	+ 0.0031 * parameters.avg_latency_of_same_last_20 
	+ 0.0046 * parameters.max_latency_of_same_last_50 
	+ 5581779.6983;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM3(work_wait &parameters) {
  double actual_remaining = 
	33.7162 * parameters.work_so_far 
	- 0.0019 * parameters.wait_so_far 
	+ 645.5648 * parameters.total_wait_locks 
	+ 0.0003 * parameters.mean_wait_of_all 
	- 14696573.8541 * parameters.cpu_usage 
	+ 0.1455 * parameters.avg_work_of_same_past_second 
	- 0.0074 * parameters.avg_wait_of_same_past_second 
	+ 0.0173 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 18305414.9065;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM4(work_wait &parameters) {
  double actual_remaining = 
	33.7162 * parameters.work_so_far 
	- 0.0013 * parameters.wait_so_far 
	+ 645.5648 * parameters.total_wait_locks 
	+ 0.0003 * parameters.mean_wait_of_all 
	- 101186788.7609 * parameters.cpu_usage 
	+ 1.3145 * parameters.avg_work_of_same_past_second 
	- 0.0676 * parameters.avg_wait_of_same_past_second 
	+ 0.0145 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 93216592.8324;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM5(work_wait &parameters) {
  double actual_remaining = 
	0.0051 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 1539.4344 * parameters.total_wait_locks 
	+ 0.0018 * parameters.mean_wait_of_all 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0034 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 11484022.9773;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM6(work_wait &parameters) {
  double actual_remaining = 
	0.0116 * parameters.work_so_far 
	+ 0.0131 * parameters.wait_so_far 
	+ 21329.9557 * parameters.total_wait_locks 
	+ 0.0595 * parameters.mean_wait_of_all 
	- 0.009 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.006 * parameters.avg_latency_of_same_last_20 
	+ 0.0176 * parameters.max_latency_of_same_last_50 
	+ 1443152.0499;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM7(work_wait &parameters) {
  double actual_remaining = 
	0.0116 * parameters.work_so_far 
	+ 0.4313 * parameters.wait_so_far 
	+ 40021.801 * parameters.total_wait_locks 
	+ 0.0595 * parameters.mean_wait_of_all 
	- 0.009 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.006 * parameters.avg_latency_of_same_last_20 
	+ 0.0176 * parameters.max_latency_of_same_last_50 
	- 252927.2384;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM8(work_wait &parameters) {
  double actual_remaining = 
	1.0348 * parameters.work_so_far 
	+ 0.0497 * parameters.wait_so_far 
	+ 2638.1105 * parameters.total_wait_locks 
	+ 0.2554 * parameters.mean_wait_of_all 
	- 0.009 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.006 * parameters.avg_latency_of_same_last_20 
	+ 0.0122 * parameters.max_latency_of_same_last_50 
	- 1448213.2732;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM9(work_wait &parameters) {
  double actual_remaining = 
	4107.694 * parameters.work_so_far 
	+ 0.0042 * parameters.wait_so_far 
	- 102450.8173 * parameters.total_wait_locks 
	- 0.5037 * parameters.mean_wait_of_all 
	- 163180586.7919 * parameters.cpu_usage 
	- 0.009 * parameters.avg_work_of_same_past_second 
	+ 0.4726 * parameters.avg_wait_of_same_past_second 
	+ 0.006 * parameters.avg_latency_of_same_last_20 
	- 0.1412 * parameters.max_latency_of_same_last_50 
	+ 187942872.2823;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM10(work_wait &parameters) {
  double actual_remaining = 
	4107.694 * parameters.work_so_far 
	+ 0.0042 * parameters.wait_so_far 
	- 102450.8173 * parameters.total_wait_locks 
	- 0.5037 * parameters.mean_wait_of_all 
	- 163180586.7919 * parameters.cpu_usage 
	- 0.009 * parameters.avg_work_of_same_past_second 
	+ 0.4796 * parameters.avg_wait_of_same_past_second 
	+ 0.006 * parameters.avg_latency_of_same_last_20 
	- 0.1412 * parameters.max_latency_of_same_last_50 
	+ 188242704.1945;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM11(work_wait &parameters) {
  double actual_remaining = 
	5313.8334 * parameters.work_so_far 
	+ 0.0042 * parameters.wait_so_far 
	- 102450.8173 * parameters.total_wait_locks 
	- 0.5037 * parameters.mean_wait_of_all 
	- 163180586.7919 * parameters.cpu_usage 
	- 0.009 * parameters.avg_work_of_same_past_second 
	+ 0.4331 * parameters.avg_wait_of_same_past_second 
	+ 0.006 * parameters.avg_latency_of_same_last_20 
	- 0.19 * parameters.max_latency_of_same_last_50 
	+ 189500799.066;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM12(work_wait &parameters) {
  double actual_remaining = 
	7.7464 * parameters.work_so_far 
	+ 0.0042 * parameters.wait_so_far 
	- 102450.8173 * parameters.total_wait_locks 
	- 0.4616 * parameters.mean_wait_of_all 
	- 106737320.7841 * parameters.cpu_usage 
	- 0.009 * parameters.avg_work_of_same_past_second 
	+ 0.395 * parameters.avg_wait_of_same_past_second 
	+ 0.006 * parameters.avg_latency_of_same_last_20 
	+ 0.0248 * parameters.max_latency_of_same_last_50 
	+ 142375361.2836;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM13(work_wait &parameters) {
  double actual_remaining = 
	8.4094 * parameters.work_so_far 
	+ 0.0042 * parameters.wait_so_far 
	- 102450.8173 * parameters.total_wait_locks 
	- 0.4616 * parameters.mean_wait_of_all 
	- 101767557.7428 * parameters.cpu_usage 
	- 0.009 * parameters.avg_work_of_same_past_second 
	+ 0.395 * parameters.avg_wait_of_same_past_second 
	+ 0.006 * parameters.avg_latency_of_same_last_20 
	+ 0.0248 * parameters.max_latency_of_same_last_50 
	+ 138768725.7073;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM14(work_wait &parameters) {
  double actual_remaining = 
	8.4354 * parameters.work_so_far 
	+ 0.0042 * parameters.wait_so_far 
	- 102450.8173 * parameters.total_wait_locks 
	- 0.4616 * parameters.mean_wait_of_all 
	- 101767557.7428 * parameters.cpu_usage 
	- 0.009 * parameters.avg_work_of_same_past_second 
	+ 0.395 * parameters.avg_wait_of_same_past_second 
	+ 0.006 * parameters.avg_latency_of_same_last_20 
	+ 0.0248 * parameters.max_latency_of_same_last_50 
	+ 139129562.1204;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM15(work_wait &parameters) {
  double actual_remaining = 
	2.9881 * parameters.work_so_far 
	+ 0.0042 * parameters.wait_so_far 
	- 174102.3589 * parameters.total_wait_locks 
	- 0.4136 * parameters.mean_wait_of_all 
	- 0.009 * parameters.avg_work_of_same_past_second 
	+ 0.2798 * parameters.avg_wait_of_same_past_second 
	+ 0.006 * parameters.avg_latency_of_same_last_20 
	+ 0.0546 * parameters.max_latency_of_same_last_50 
	+ 36866739.8043;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM16(work_wait &parameters) {
  double actual_remaining = 
	-12.1043 * parameters.work_so_far 
	- 0.0143 * parameters.wait_so_far 
	+ 2638.1105 * parameters.total_wait_locks 
	+ 0.2078 * parameters.mean_wait_of_all 
	+ 346554223.8404 * parameters.cpu_usage 
	- 0.009 * parameters.avg_work_of_same_past_second 
	- 0.0424 * parameters.avg_wait_of_same_past_second 
	- 0.0487 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	- 293683983.585;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM17(work_wait &parameters) {
  double actual_remaining = 
	0.0263 * parameters.work_so_far 
	- 0.0301 * parameters.wait_so_far 
	+ 2638.1105 * parameters.total_wait_locks 
	+ 0.1992 * parameters.mean_wait_of_all 
	+ 330999437.1363 * parameters.cpu_usage 
	- 0.7983 * parameters.avg_work_of_same_past_second 
	- 0.0424 * parameters.avg_wait_of_same_past_second 
	- 0.0487 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	- 268307635.7603;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM18(work_wait &parameters) {
  double actual_remaining = 
	0.0263 * parameters.work_so_far 
	- 0.0256 * parameters.wait_so_far 
	+ 2638.1105 * parameters.total_wait_locks 
	+ 0.1992 * parameters.mean_wait_of_all 
	+ 330999437.1363 * parameters.cpu_usage 
	- 1.1126 * parameters.avg_work_of_same_past_second 
	- 0.0424 * parameters.avg_wait_of_same_past_second 
	- 0.0487 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	- 257739361.6702;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM19(work_wait &parameters) {
  double actual_remaining = 
	0.0263 * parameters.work_so_far 
	- 0.0033 * parameters.wait_so_far 
	+ 2638.1105 * parameters.total_wait_locks 
	+ 0.1861 * parameters.mean_wait_of_all 
	+ 298753925.9103 * parameters.cpu_usage 
	- 0.009 * parameters.avg_work_of_same_past_second 
	- 0.0817 * parameters.avg_wait_of_same_past_second 
	- 0.0996 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	- 251777195.7814;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM20(work_wait &parameters) {
  double actual_remaining = 
	0.0294 * parameters.work_so_far 
	- 0.0014 * parameters.wait_so_far 
	+ 2638.1105 * parameters.total_wait_locks 
	+ 0.0103 * parameters.mean_wait_of_all 
	+ 6768519.2206 * parameters.cpu_usage 
	- 0.009 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.014 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 4216925.1439;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM21(work_wait &parameters) {
  double actual_remaining = 
	0.0722 * parameters.work_so_far 
	- 0.0014 * parameters.wait_so_far 
	+ 113320.6385 * parameters.total_wait_locks 
	+ 0.0103 * parameters.mean_wait_of_all 
	+ 109809288.8874 * parameters.cpu_usage 
	+ 4.0111 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0775 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	- 172124737.7322;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM22(work_wait &parameters) {
  double actual_remaining = 
	0.0722 * parameters.work_so_far 
	- 0.0014 * parameters.wait_so_far 
	+ 109157.2524 * parameters.total_wait_locks 
	+ 0.0103 * parameters.mean_wait_of_all 
	+ 109809288.8874 * parameters.cpu_usage 
	+ 3.8706 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0775 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	- 167619224.6128;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM23(work_wait &parameters) {
  double actual_remaining = 
	0.0722 * parameters.work_so_far 
	+ 0.0226 * parameters.wait_so_far 
	+ 124218.3401 * parameters.total_wait_locks 
	+ 0.0103 * parameters.mean_wait_of_all 
	+ 170726900.5395 * parameters.cpu_usage 
	+ 4.6442 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0775 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	- 241904585.1888;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM24(work_wait &parameters) {
  double actual_remaining = 
	0.0722 * parameters.work_so_far 
	+ 0.0213 * parameters.wait_so_far 
	+ 124218.3401 * parameters.total_wait_locks 
	+ 0.0103 * parameters.mean_wait_of_all 
	+ 170726900.5395 * parameters.cpu_usage 
	+ 4.6442 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0775 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	- 240542203.3019;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM25(work_wait &parameters) {
  double actual_remaining = 
	0.0507 * parameters.work_so_far 
	- 0.0014 * parameters.wait_so_far 
	+ 2638.1105 * parameters.total_wait_locks 
	+ 0.0103 * parameters.mean_wait_of_all 
	+ 8279936.1339 * parameters.cpu_usage 
	- 0.0808 * parameters.avg_work_of_same_past_second 
	- 0.0277 * parameters.avg_wait_of_same_past_second 
	+ 0.044 * parameters.avg_latency_of_same_last_20 
	+ 0.0102 * parameters.max_latency_of_same_last_50 
	+ 465436.1605;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM26(work_wait &parameters) {
  double actual_remaining = 
	11.0315 * parameters.work_so_far 
	- 0.0017 * parameters.wait_so_far 
	+ 122954.6432 * parameters.total_wait_locks 
	- 0.3648 * parameters.mean_wait_of_all 
	- 0.0319 * parameters.avg_work_of_same_past_second 
	- 0.0711 * parameters.avg_wait_of_same_past_second 
	+ 0.3304 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 8401300.0399;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM27(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.wait_so_far 
	+ 8828.9286 * parameters.total_wait_locks 
	- 0.0439 * parameters.mean_wait_of_all 
	- 30725975.9565 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 58242924.7411;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM28(work_wait &parameters) {
  double actual_remaining = 
	-180.5682 * parameters.work_so_far 
	+ 0.036 * parameters.wait_so_far 
	+ 76384.365 * parameters.total_wait_locks 
	- 0.3015 * parameters.mean_wait_of_all 
	- 90083.3816 * parameters.cpu_usage 
	- 3.1385 * parameters.avg_work_of_same_past_second 
	- 0.002 * parameters.avg_wait_of_same_past_second 
	+ 0.1162 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 30284823.1902;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM29(work_wait &parameters) {
  double actual_remaining = 
	-579.255 * parameters.work_so_far 
	+ 0.1052 * parameters.wait_so_far 
	+ 121537.1243 * parameters.total_wait_locks 
	- 0.4912 * parameters.mean_wait_of_all 
	- 90083.3816 * parameters.cpu_usage 
	- 0.4541 * parameters.avg_work_of_same_past_second 
	- 0.002 * parameters.avg_wait_of_same_past_second 
	+ 0.1687 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 7166724.5409;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM30(work_wait &parameters) {
  double actual_remaining = 
	-508.0061 * parameters.work_so_far 
	+ 0.0936 * parameters.wait_so_far 
	+ 121537.1243 * parameters.total_wait_locks 
	- 0.4912 * parameters.mean_wait_of_all 
	- 90083.3816 * parameters.cpu_usage 
	+ 2.3013 * parameters.avg_work_of_same_past_second 
	- 0.002 * parameters.avg_wait_of_same_past_second 
	+ 0.1687 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 18861820.9533;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM31(work_wait &parameters) {
  double actual_remaining = 
	-508.0061 * parameters.work_so_far 
	+ 0.0936 * parameters.wait_so_far 
	+ 121537.1243 * parameters.total_wait_locks 
	- 0.4912 * parameters.mean_wait_of_all 
	- 90083.3816 * parameters.cpu_usage 
	+ 2.1635 * parameters.avg_work_of_same_past_second 
	- 0.002 * parameters.avg_wait_of_same_past_second 
	+ 0.1687 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 15929290.8594;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM32(work_wait &parameters) {
  double actual_remaining = 
	-0.0001 * parameters.wait_so_far 
	+ 4671.1591 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 90083.3816 * parameters.cpu_usage 
	- 0.2865 * parameters.avg_work_of_same_past_second 
	- 0.002 * parameters.avg_wait_of_same_past_second 
	+ 0.0153 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 23453805.8648;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM33(work_wait &parameters) {
  double actual_remaining = 
	-0.0001 * parameters.wait_so_far 
	+ 17693.0786 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 76416446.301 * parameters.cpu_usage 
	- 0.2287 * parameters.avg_work_of_same_past_second 
	- 0.002 * parameters.avg_wait_of_same_past_second 
	- 0.2157 * parameters.avg_latency_of_same_last_20 
	- 0.0039 * parameters.max_latency_of_same_last_50 
	+ 141127591.6249;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM34(work_wait &parameters) {
  double actual_remaining = 
	-0.0001 * parameters.wait_so_far 
	+ 10356.7859 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 33415678.4591 * parameters.cpu_usage 
	- 0.2287 * parameters.avg_work_of_same_past_second 
	- 0.002 * parameters.avg_wait_of_same_past_second 
	- 0.0262 * parameters.avg_latency_of_same_last_20 
	- 0.0017 * parameters.max_latency_of_same_last_50 
	+ 58340670.2411;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM35(work_wait &parameters) {
  double actual_remaining = 
	-0.0001 * parameters.wait_so_far 
	- 3019.409 * parameters.total_wait_locks 
	- 0.1048 * parameters.mean_wait_of_all 
	- 90083.3816 * parameters.cpu_usage 
	+ 0.7351 * parameters.avg_work_of_same_past_second 
	- 0.002 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 33285159.2131;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM36(work_wait &parameters) {
  double actual_remaining = 
	0.043 * parameters.wait_so_far 
	- 231627.932 * parameters.total_wait_locks 
	- 0.2289 * parameters.mean_wait_of_all 
	- 90083.3816 * parameters.cpu_usage 
	+ 1.768 * parameters.avg_work_of_same_past_second 
	- 0.002 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 105127018.4076;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM37(work_wait &parameters) {
  double actual_remaining = 
	-0.0001 * parameters.wait_so_far 
	+ 16132.3151 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 90083.3816 * parameters.cpu_usage 
	- 0.0013 * parameters.avg_wait_of_same_past_second 
	- 0.0711 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 35231913.9101;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM38(work_wait &parameters) {
  double actual_remaining = 
	-0.0787 * parameters.work_so_far 
	- 0.0121 * parameters.wait_so_far 
	+ 18496.6918 * parameters.total_wait_locks 
	- 0.0792 * parameters.mean_wait_of_all 
	- 90083.3816 * parameters.cpu_usage 
	- 0.0495 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 40687194.0525;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM39(work_wait &parameters) {
  double actual_remaining = 
	-0.0001 * parameters.wait_so_far 
	+ 252.3791 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 90083.3816 * parameters.cpu_usage 
	- 0.1128 * parameters.avg_work_of_same_past_second 
	- 0.0189 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.0069 * parameters.max_latency_of_same_last_50 
	+ 23436545.7859;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM40(work_wait &parameters) {
  double actual_remaining = 
	0.3397 * parameters.work_so_far 
	- 0.0045 * parameters.wait_so_far 
	- 207718.4552 * parameters.total_wait_locks 
	+ 1.6853 * parameters.mean_wait_of_all 
	+ 135579935.3454 * parameters.cpu_usage 
	- 0.1196 * parameters.avg_work_of_same_past_second 
	- 0.0007 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.0084 * parameters.max_latency_of_same_last_50 
	- 217256872.5987;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM41(work_wait &parameters) {
  double actual_remaining = 
	-0.018 * parameters.wait_so_far 
	+ 252.3791 * parameters.total_wait_locks 
	+ 0.4789 * parameters.mean_wait_of_all 
	+ 210555472.0103 * parameters.cpu_usage 
	- 1.8449 * parameters.avg_work_of_same_past_second 
	- 0.0007 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.0129 * parameters.max_latency_of_same_last_50 
	- 154706325.885;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM42(work_wait &parameters) {
  double actual_remaining = 
	-0.018 * parameters.wait_so_far 
	+ 252.3791 * parameters.total_wait_locks 
	+ 0.4789 * parameters.mean_wait_of_all 
	+ 210555472.0103 * parameters.cpu_usage 
	- 1.8449 * parameters.avg_work_of_same_past_second 
	- 0.0007 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.0129 * parameters.max_latency_of_same_last_50 
	- 152291195.0702;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM43(work_wait &parameters) {
  double actual_remaining = 
	-0.018 * parameters.wait_so_far 
	+ 252.3791 * parameters.total_wait_locks 
	+ 0.4789 * parameters.mean_wait_of_all 
	+ 210555472.0103 * parameters.cpu_usage 
	- 1.8449 * parameters.avg_work_of_same_past_second 
	- 0.0007 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.0129 * parameters.max_latency_of_same_last_50 
	- 152004328.8455;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM44(work_wait &parameters) {
  double actual_remaining = 
	-0.0259 * parameters.wait_so_far 
	+ 252.3791 * parameters.total_wait_locks 
	+ 0.4789 * parameters.mean_wait_of_all 
	+ 210555472.0103 * parameters.cpu_usage 
	- 1.4423 * parameters.avg_work_of_same_past_second 
	- 0.2043 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.0129 * parameters.max_latency_of_same_last_50 
	- 108207571.2883;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM45(work_wait &parameters) {
  double actual_remaining = 
	-0.0001 * parameters.wait_so_far 
	- 273614.4125 * parameters.total_wait_locks 
	- 0.7083 * parameters.mean_wait_of_all 
	- 90083.3816 * parameters.cpu_usage 
	- 1.3931 * parameters.avg_work_of_same_past_second 
	+ 0.195 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 196450127.5248;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM46(work_wait &parameters) {
  double actual_remaining = 
	-0.0001 * parameters.wait_so_far 
	+ 252.3791 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 90083.3816 * parameters.cpu_usage 
	- 0.0045 * parameters.avg_work_of_same_past_second 
	+ 0.0814 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	- 0.0109 * parameters.max_latency_of_same_last_50 
	+ 8078375.6489;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM47(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.wait_so_far 
	- 383488.2635 * parameters.total_wait_locks 
	+ 1.2206 * parameters.mean_wait_of_all 
	- 90083.3816 * parameters.cpu_usage 
	- 0.0868 * parameters.avg_work_of_same_past_second 
	+ 0.5968 * parameters.avg_wait_of_same_past_second 
	+ 0.1379 * parameters.avg_latency_of_same_last_20 
	- 0.0153 * parameters.max_latency_of_same_last_50 
	- 208339839.0447;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM48(work_wait &parameters) {
  double actual_remaining = 
	-208.5758 * parameters.work_so_far 
	+ 0.0507 * parameters.wait_so_far 
	- 382647.7549 * parameters.total_wait_locks 
	+ 3.3851 * parameters.mean_wait_of_all 
	- 90083.3816 * parameters.cpu_usage 
	- 3.1216 * parameters.avg_work_of_same_past_second 
	+ 0.2129 * parameters.avg_wait_of_same_past_second 
	+ 0.0347 * parameters.avg_latency_of_same_last_20 
	+ 0.0001 * parameters.max_latency_of_same_last_50 
	- 216173616.8771;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM49(work_wait &parameters) {
  double actual_remaining = 
	-196.9882 * parameters.work_so_far 
	+ 0.0507 * parameters.wait_so_far 
	- 382647.7549 * parameters.total_wait_locks 
	+ 3.3851 * parameters.mean_wait_of_all 
	- 90083.3816 * parameters.cpu_usage 
	- 3.1216 * parameters.avg_work_of_same_past_second 
	+ 0.2129 * parameters.avg_wait_of_same_past_second 
	+ 0.0347 * parameters.avg_latency_of_same_last_20 
	+ 0.0001 * parameters.max_latency_of_same_last_50 
	- 217354121.4622;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM50(work_wait &parameters) {
  double actual_remaining = 
	0.049 * parameters.wait_so_far 
	- 382647.7549 * parameters.total_wait_locks 
	+ 3.3851 * parameters.mean_wait_of_all 
	- 90083.3816 * parameters.cpu_usage 
	- 3.1216 * parameters.avg_work_of_same_past_second 
	+ 0.2129 * parameters.avg_wait_of_same_past_second 
	+ 0.0347 * parameters.avg_latency_of_same_last_20 
	+ 0.0001 * parameters.max_latency_of_same_last_50 
	- 222372374.3597;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM51(work_wait &parameters) {
  double actual_remaining = 
	0.05 * parameters.wait_so_far 
	- 380672.7234 * parameters.total_wait_locks 
	+ 3.3851 * parameters.mean_wait_of_all 
	- 90083.3816 * parameters.cpu_usage 
	- 3.1216 * parameters.avg_work_of_same_past_second 
	+ 0.2129 * parameters.avg_wait_of_same_past_second 
	+ 0.0347 * parameters.avg_latency_of_same_last_20 
	+ 0.0001 * parameters.max_latency_of_same_last_50 
	- 235822621.3904;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM52(work_wait &parameters) {
  double actual_remaining = 
	0.0409 * parameters.wait_so_far 
	- 410183.2491 * parameters.total_wait_locks 
	+ 4.1359 * parameters.mean_wait_of_all 
	- 90083.3816 * parameters.cpu_usage 
	- 5.2054 * parameters.avg_work_of_same_past_second 
	+ 0.2129 * parameters.avg_wait_of_same_past_second 
	+ 0.0347 * parameters.avg_latency_of_same_last_20 
	+ 0.0001 * parameters.max_latency_of_same_last_50 
	- 230938195.7184;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM53(work_wait &parameters) {
  double actual_remaining = 
	0.0409 * parameters.wait_so_far 
	- 410183.2491 * parameters.total_wait_locks 
	+ 4.1359 * parameters.mean_wait_of_all 
	- 90083.3816 * parameters.cpu_usage 
	- 5.3613 * parameters.avg_work_of_same_past_second 
	+ 0.2129 * parameters.avg_wait_of_same_past_second 
	+ 0.0347 * parameters.avg_latency_of_same_last_20 
	+ 0.0001 * parameters.max_latency_of_same_last_50 
	- 235853302.76;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM54(work_wait &parameters) {
  double actual_remaining = 
	0.0409 * parameters.wait_so_far 
	- 410183.2491 * parameters.total_wait_locks 
	+ 4.1359 * parameters.mean_wait_of_all 
	- 90083.3816 * parameters.cpu_usage 
	- 5.3613 * parameters.avg_work_of_same_past_second 
	+ 0.2129 * parameters.avg_wait_of_same_past_second 
	+ 0.0347 * parameters.avg_latency_of_same_last_20 
	+ 0.0001 * parameters.max_latency_of_same_last_50 
	- 235166559.9087;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM55(work_wait &parameters) {
  double actual_remaining = 
	0.0129 * parameters.wait_so_far 
	- 99325.5009 * parameters.total_wait_locks 
	+ 1.1821 * parameters.mean_wait_of_all 
	- 90083.3816 * parameters.cpu_usage 
	- 2.1632 * parameters.avg_work_of_same_past_second 
	+ 0.2129 * parameters.avg_wait_of_same_past_second 
	+ 0.0347 * parameters.avg_latency_of_same_last_20 
	+ 0.0001 * parameters.max_latency_of_same_last_50 
	- 107394620.332;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM56(work_wait &parameters) {
  double actual_remaining = 
	0.0146 * parameters.wait_so_far 
	- 99325.5009 * parameters.total_wait_locks 
	+ 1.1821 * parameters.mean_wait_of_all 
	- 90083.3816 * parameters.cpu_usage 
	- 1.608 * parameters.avg_work_of_same_past_second 
	- 0.0664 * parameters.avg_wait_of_same_past_second 
	+ 0.0347 * parameters.avg_latency_of_same_last_20 
	+ 0.0001 * parameters.max_latency_of_same_last_50 
	- 18839042.5405;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM57(work_wait &parameters) {
  double actual_remaining = 
	0.0146 * parameters.wait_so_far 
	- 99325.5009 * parameters.total_wait_locks 
	+ 1.1821 * parameters.mean_wait_of_all 
	- 90083.3816 * parameters.cpu_usage 
	- 1.608 * parameters.avg_work_of_same_past_second 
	- 0.0059 * parameters.avg_wait_of_same_past_second 
	+ 0.0347 * parameters.avg_latency_of_same_last_20 
	+ 0.0001 * parameters.max_latency_of_same_last_50 
	- 42920533.1642;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM58(work_wait &parameters) {
  double actual_remaining = 
	0.3134 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 381.0419 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 90083.3816 * parameters.cpu_usage 
	- 0.0023 * parameters.avg_wait_of_same_past_second 
	+ 0.0019 * parameters.avg_latency_of_same_last_20 
	+ 0.0001 * parameters.max_latency_of_same_last_50 
	+ 23396841.8854;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM59(work_wait &parameters) {
  double actual_remaining = 
	-94.7564 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	+ 204221.0551 * parameters.total_wait_locks 
	+ 1.7544 * parameters.mean_wait_of_all 
	- 54774508.2606 * parameters.cpu_usage 
	+ 7.8392 * parameters.avg_work_of_same_past_second 
	+ 0.0045 * parameters.avg_wait_of_same_past_second 
	+ 0.0348 * parameters.avg_latency_of_same_last_20 
	+ 0.0921 * parameters.max_latency_of_same_last_50 
	- 177409880.1047;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM60(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.wait_so_far 
	+ 203468.3977 * parameters.total_wait_locks 
	+ 1.7544 * parameters.mean_wait_of_all 
	- 54774508.2606 * parameters.cpu_usage 
	+ 4.8163 * parameters.avg_work_of_same_past_second 
	+ 0.0045 * parameters.avg_wait_of_same_past_second 
	+ 0.0348 * parameters.avg_latency_of_same_last_20 
	+ 0.0921 * parameters.max_latency_of_same_last_50 
	- 144853889.689;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM61(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.wait_so_far 
	+ 260419.6467 * parameters.total_wait_locks 
	+ 1.7544 * parameters.mean_wait_of_all 
	- 54774508.2606 * parameters.cpu_usage 
	+ 4.8163 * parameters.avg_work_of_same_past_second 
	+ 0.0045 * parameters.avg_wait_of_same_past_second 
	+ 0.0348 * parameters.avg_latency_of_same_last_20 
	+ 0.0921 * parameters.max_latency_of_same_last_50 
	- 145683770.7664;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM62(work_wait &parameters) {
  double actual_remaining = 
	0.0041 * parameters.wait_so_far 
	+ 530226.1152 * parameters.total_wait_locks 
	+ 2.0706 * parameters.mean_wait_of_all 
	- 54774508.2606 * parameters.cpu_usage 
	- 0.2993 * parameters.avg_work_of_same_past_second 
	+ 0.0045 * parameters.avg_wait_of_same_past_second 
	+ 0.0348 * parameters.avg_latency_of_same_last_20 
	+ 0.1247 * parameters.max_latency_of_same_last_50 
	- 131174735.0223;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM63(work_wait &parameters) {
  double actual_remaining = 
	0.0035 * parameters.wait_so_far 
	+ 372077.1859 * parameters.total_wait_locks 
	+ 2.0706 * parameters.mean_wait_of_all 
	- 54774508.2606 * parameters.cpu_usage 
	- 0.2993 * parameters.avg_work_of_same_past_second 
	+ 0.0045 * parameters.avg_wait_of_same_past_second 
	+ 0.0348 * parameters.avg_latency_of_same_last_20 
	+ 0.1247 * parameters.max_latency_of_same_last_50 
	- 106751505.1277;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM64(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.wait_so_far 
	- 65163.1319 * parameters.total_wait_locks 
	+ 0.2723 * parameters.mean_wait_of_all 
	- 22387376.2018 * parameters.cpu_usage 
	- 0.1404 * parameters.avg_work_of_same_past_second 
	+ 0.0045 * parameters.avg_wait_of_same_past_second 
	+ 0.0153 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 39740795.8892;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM65(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.wait_so_far 
	+ 151.7305 * parameters.total_wait_locks 
	- 0.1084 * parameters.mean_wait_of_all 
	- 2525997.327 * parameters.cpu_usage 
	- 0.0187 * parameters.avg_work_of_same_past_second 
	+ 0.0031 * parameters.avg_wait_of_same_past_second 
	+ 0.0532 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 17537558.8374;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM66(work_wait &parameters) {
  double actual_remaining = 
	0.0165 * parameters.wait_so_far 
	- 7190.1007 * parameters.total_wait_locks 
	- 0.0652 * parameters.mean_wait_of_all 
	- 454544930.1162 * parameters.cpu_usage 
	+ 1.1693 * parameters.avg_work_of_same_past_second 
	+ 0.3964 * parameters.avg_wait_of_same_past_second 
	+ 0.0506 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 297468406.468;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM67(work_wait &parameters) {
  double actual_remaining = 
	0.0325 * parameters.wait_so_far 
	- 23602.9813 * parameters.total_wait_locks 
	- 0.0652 * parameters.mean_wait_of_all 
	- 454544930.1162 * parameters.cpu_usage 
	+ 4.6769 * parameters.avg_work_of_same_past_second 
	+ 0.2168 * parameters.avg_wait_of_same_past_second 
	+ 0.0045 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 296746345.1013;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM68(work_wait &parameters) {
  double actual_remaining = 
	1367.9994 * parameters.work_so_far 
	+ 0.0325 * parameters.wait_so_far 
	- 7190.1007 * parameters.total_wait_locks 
	- 0.0652 * parameters.mean_wait_of_all 
	- 454544930.1162 * parameters.cpu_usage 
	+ 4.6769 * parameters.avg_work_of_same_past_second 
	+ 0.2168 * parameters.avg_wait_of_same_past_second 
	+ 0.0045 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 257758510.0212;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM69(work_wait &parameters) {
  double actual_remaining = 
	1609.411 * parameters.work_so_far 
	+ 0.0325 * parameters.wait_so_far 
	- 7190.1007 * parameters.total_wait_locks 
	- 0.0652 * parameters.mean_wait_of_all 
	- 454544930.1162 * parameters.cpu_usage 
	+ 4.6769 * parameters.avg_work_of_same_past_second 
	+ 0.2168 * parameters.avg_wait_of_same_past_second 
	+ 0.0045 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 254325281.0657;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM70(work_wait &parameters) {
  double actual_remaining = 
	0.0606 * parameters.wait_so_far 
	+ 152798.9293 * parameters.total_wait_locks 
	- 0.0652 * parameters.mean_wait_of_all 
	- 454544930.1162 * parameters.cpu_usage 
	+ 6.6747 * parameters.avg_work_of_same_past_second 
	+ 0.2168 * parameters.avg_wait_of_same_past_second 
	+ 0.0045 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 189385741.2273;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM71(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.wait_so_far 
	+ 43356.6406 * parameters.total_wait_locks 
	- 0.0348 * parameters.mean_wait_of_all 
	- 168187386.3073 * parameters.cpu_usage 
	- 0.6114 * parameters.avg_work_of_same_past_second 
	+ 0.0237 * parameters.avg_wait_of_same_past_second 
	+ 0.0045 * parameters.avg_latency_of_same_last_20 
	- 0.0451 * parameters.max_latency_of_same_last_50 
	+ 235037078.2378;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM72(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.wait_so_far 
	+ 40694.3954 * parameters.total_wait_locks 
	- 0.162 * parameters.mean_wait_of_all 
	- 1796957.0784 * parameters.cpu_usage 
	+ 0.0824 * parameters.avg_work_of_same_past_second 
	+ 0.0162 * parameters.avg_wait_of_same_past_second 
	+ 0.1036 * parameters.avg_latency_of_same_last_20 
	+ 0.0056 * parameters.max_latency_of_same_last_50 
	- 37094085.8032;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM73(work_wait &parameters) {
  double actual_remaining = 
	0.0042 * parameters.wait_so_far 
	- 37953.6847 * parameters.total_wait_locks 
	+ 0.1372 * parameters.mean_wait_of_all 
	- 1796957.0784 * parameters.cpu_usage 
	+ 0.0624 * parameters.avg_work_of_same_past_second 
	+ 0.0473 * parameters.avg_wait_of_same_past_second 
	+ 0.0361 * parameters.avg_latency_of_same_last_20 
	+ 0.0154 * parameters.max_latency_of_same_last_50 
	- 22166100.4718;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM74(work_wait &parameters) {
  double actual_remaining = 
	0.0042 * parameters.wait_so_far 
	- 29641.9156 * parameters.total_wait_locks 
	+ 0.4518 * parameters.mean_wait_of_all 
	- 1796957.0784 * parameters.cpu_usage 
	+ 0.0624 * parameters.avg_work_of_same_past_second 
	+ 0.0362 * parameters.avg_wait_of_same_past_second 
	+ 0.1252 * parameters.avg_latency_of_same_last_20 
	- 0.227 * parameters.max_latency_of_same_last_50 
	+ 196409350.4658;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM75(work_wait &parameters) {
  double actual_remaining = 
	9.1017 * parameters.work_so_far 
	- 0.0275 * parameters.wait_so_far 
	- 101506.9231 * parameters.total_wait_locks 
	+ 1.7713 * parameters.mean_wait_of_all 
	- 1796957.0784 * parameters.cpu_usage 
	+ 0.0624 * parameters.avg_work_of_same_past_second 
	+ 0.0126 * parameters.avg_wait_of_same_past_second 
	+ 0.0032 * parameters.avg_latency_of_same_last_20 
	+ 0.0689 * parameters.max_latency_of_same_last_50 
	- 94119629.4555;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM76(work_wait &parameters) {
  double actual_remaining = 
	15.6028 * parameters.work_so_far 
	+ 0.004 * parameters.wait_so_far 
	- 101506.9231 * parameters.total_wait_locks 
	+ 3.0181 * parameters.mean_wait_of_all 
	- 1796957.0784 * parameters.cpu_usage 
	+ 0.0624 * parameters.avg_work_of_same_past_second 
	+ 0.0126 * parameters.avg_wait_of_same_past_second 
	+ 0.0032 * parameters.avg_latency_of_same_last_20 
	+ 0.0689 * parameters.max_latency_of_same_last_50 
	- 115115925.0368;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM77(work_wait &parameters) {
  double actual_remaining = 
	0.004 * parameters.wait_so_far 
	- 176045.4399 * parameters.total_wait_locks 
	+ 0.0257 * parameters.mean_wait_of_all 
	- 1796957.0784 * parameters.cpu_usage 
	+ 0.0624 * parameters.avg_work_of_same_past_second 
	+ 0.0126 * parameters.avg_wait_of_same_past_second 
	+ 0.0032 * parameters.avg_latency_of_same_last_20 
	+ 0.0365 * parameters.max_latency_of_same_last_50 
	+ 80826667.2042;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM78(work_wait &parameters) {
  double actual_remaining = 
	1.3835 * parameters.work_so_far 
	- 0.0573 * parameters.wait_so_far 
	- 2360.4085 * parameters.total_wait_locks 
	- 0.3166 * parameters.mean_wait_of_all 
	- 806300.1404 * parameters.cpu_usage 
	+ 0.3577 * parameters.avg_work_of_same_past_second 
	- 0.0012 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	+ 0.0009 * parameters.max_latency_of_same_last_50 
	+ 43839311.2052;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM79(work_wait &parameters) {
  double actual_remaining = 
	-0.0014 * parameters.wait_so_far 
	- 856.2019 * parameters.total_wait_locks 
	+ 0.009 * parameters.mean_wait_of_all 
	- 806300.1404 * parameters.cpu_usage 
	+ 0.0049 * parameters.avg_work_of_same_past_second 
	- 0.0012 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	+ 0.0005 * parameters.max_latency_of_same_last_50 
	+ 40869535.8996;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM80(work_wait &parameters) {
  double actual_remaining = 
	0.6082 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 3067.078 * parameters.total_wait_locks 
	- 0.0098 * parameters.mean_wait_of_all 
	- 91895924.8964 * parameters.cpu_usage 
	+ 0.0141 * parameters.avg_work_of_same_past_second 
	- 0.0026 * parameters.avg_wait_of_same_past_second 
	+ 0.0021 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 114660363.578;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM81(work_wait &parameters) {
  double actual_remaining = 
	-0.0001 * parameters.wait_so_far 
	+ 20306.6194 * parameters.total_wait_locks 
	+ 0.0009 * parameters.mean_wait_of_all 
	- 62732540.3348 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 79248354.9431;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM82(work_wait &parameters) {
  double actual_remaining = 
	-0.0001 * parameters.wait_so_far 
	- 31130.5302 * parameters.total_wait_locks 
	+ 0.1021 * parameters.mean_wait_of_all 
	- 17493991.3133 * parameters.cpu_usage 
	- 0.073 * parameters.avg_work_of_same_past_second 
	+ 0.0149 * parameters.avg_wait_of_same_past_second 
	- 0.043 * parameters.avg_latency_of_same_last_20 
	+ 0.0195 * parameters.max_latency_of_same_last_50 
	+ 48887529.8989;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM83(work_wait &parameters) {
  double actual_remaining = 
	10.6164 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 202688.2646 * parameters.total_wait_locks 
	+ 0.0648 * parameters.mean_wait_of_all 
	- 35308483.2781 * parameters.cpu_usage 
	- 0.2377 * parameters.avg_work_of_same_past_second 
	+ 0.1034 * parameters.avg_wait_of_same_past_second 
	+ 0.0016 * parameters.avg_latency_of_same_last_20 
	+ 0.0049 * parameters.max_latency_of_same_last_50 
	- 45835931.1709;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM84(work_wait &parameters) {
  double actual_remaining = 
	4.1446 * parameters.work_so_far 
	+ 0.0059 * parameters.wait_so_far 
	- 512105.1364 * parameters.total_wait_locks 
	+ 0.0648 * parameters.mean_wait_of_all 
	- 35308483.2781 * parameters.cpu_usage 
	- 1.1806 * parameters.avg_work_of_same_past_second 
	+ 0.1413 * parameters.avg_wait_of_same_past_second 
	+ 0.0016 * parameters.avg_latency_of_same_last_20 
	+ 0.0049 * parameters.max_latency_of_same_last_50 
	+ 267798192.1518;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM85(work_wait &parameters) {
  double actual_remaining = 
	4.1446 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 1000742.1659 * parameters.total_wait_locks 
	+ 0.0648 * parameters.mean_wait_of_all 
	- 35308483.2781 * parameters.cpu_usage 
	- 1.1443 * parameters.avg_work_of_same_past_second 
	+ 0.1413 * parameters.avg_wait_of_same_past_second 
	+ 0.0016 * parameters.avg_latency_of_same_last_20 
	+ 0.0049 * parameters.max_latency_of_same_last_50 
	+ 454097026.8208;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM86(work_wait &parameters) {
  double actual_remaining = 
	0.0134 * parameters.wait_so_far 
	- 86482.2614 * parameters.total_wait_locks 
	+ 0.0648 * parameters.mean_wait_of_all 
	- 132895918.3365 * parameters.cpu_usage 
	- 0.2719 * parameters.avg_work_of_same_past_second 
	+ 0.0649 * parameters.avg_wait_of_same_past_second 
	+ 0.0016 * parameters.avg_latency_of_same_last_20 
	+ 0.0303 * parameters.max_latency_of_same_last_50 
	+ 114644761.3666;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM87(work_wait &parameters) {
  double actual_remaining = 
	0.0127 * parameters.wait_so_far 
	+ 115777.2509 * parameters.total_wait_locks 
	- 0.1793 * parameters.mean_wait_of_all 
	- 54522768.5989 * parameters.cpu_usage 
	+ 0.0908 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0016 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 36188647.1646;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM88(work_wait &parameters) {
  double actual_remaining = 
	-0.0001 * parameters.wait_so_far 
	+ 32047.5726 * parameters.total_wait_locks 
	- 0.0841 * parameters.mean_wait_of_all 
	- 28036409.7262 * parameters.cpu_usage 
	+ 0.043 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0016 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 53854068.051;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM89(work_wait &parameters) {
  double actual_remaining = 
	2.2066 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 467736.9624 * parameters.total_wait_locks 
	- 5.4234 * parameters.mean_wait_of_all 
	- 39452066.9896 * parameters.cpu_usage 
	- 1.5339 * parameters.avg_work_of_same_past_second 
	- 0.0005 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0.0105 * parameters.max_latency_of_same_last_50 
	+ 661112246.0977;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM90(work_wait &parameters) {
  double actual_remaining = 
	0.5504 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 447887.4236 * parameters.total_wait_locks 
	- 2.5182 * parameters.mean_wait_of_all 
	- 39452066.9896 * parameters.cpu_usage 
	- 0.7954 * parameters.avg_work_of_same_past_second 
	- 0.0005 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0.0105 * parameters.max_latency_of_same_last_50 
	+ 232505651.7761;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM91(work_wait &parameters) {
  double actual_remaining = 
	0.021 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 24017.5805 * parameters.total_wait_locks 
	+ 5.8665 * parameters.mean_wait_of_all 
	- 21955986.8648 * parameters.cpu_usage 
	- 0.7111 * parameters.avg_work_of_same_past_second 
	- 0.0005 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0.0092 * parameters.max_latency_of_same_last_50 
	- 694287733.3788;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM92(work_wait &parameters) {
  double actual_remaining = 
	0.021 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 32650.0482 * parameters.total_wait_locks 
	+ 0.3061 * parameters.mean_wait_of_all 
	+ 173142752.2893 * parameters.cpu_usage 
	- 0.0764 * parameters.avg_work_of_same_past_second 
	- 0.0005 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0.0108 * parameters.max_latency_of_same_last_50 
	- 157888583.813;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM93(work_wait &parameters) {
  double actual_remaining = 
	0.004 * parameters.wait_so_far 
	- 120901.4752 * parameters.total_wait_locks 
	+ 14.8714 * parameters.mean_wait_of_all 
	- 17004586.728 * parameters.cpu_usage 
	- 0.0127 * parameters.avg_work_of_same_past_second 
	+ 0.1197 * parameters.avg_wait_of_same_past_second 
	- 0.0037 * parameters.avg_latency_of_same_last_20 
	- 0.003 * parameters.max_latency_of_same_last_50 
	- 1930896364.9841;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM94(work_wait &parameters) {
  double actual_remaining = 
	0.0038 * parameters.wait_so_far 
	- 198881.4312 * parameters.total_wait_locks 
	+ 14.3901 * parameters.mean_wait_of_all 
	- 17004586.728 * parameters.cpu_usage 
	- 0.0127 * parameters.avg_work_of_same_past_second 
	+ 0.1197 * parameters.avg_wait_of_same_past_second 
	- 0.0037 * parameters.avg_latency_of_same_last_20 
	+ 0.0105 * parameters.max_latency_of_same_last_50 
	- 1850828951.411;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM95(work_wait &parameters) {
  double actual_remaining = 
	-0.0025 * parameters.wait_so_far 
	- 37489.2145 * parameters.total_wait_locks 
	+ 1.8772 * parameters.mean_wait_of_all 
	- 17004586.728 * parameters.cpu_usage 
	- 0.0127 * parameters.avg_work_of_same_past_second 
	+ 0.1197 * parameters.avg_wait_of_same_past_second 
	- 0.0037 * parameters.avg_latency_of_same_last_20 
	- 0.0073 * parameters.max_latency_of_same_last_50 
	- 225122991.0696;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM96(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.wait_so_far 
	- 212083.8285 * parameters.total_wait_locks 
	+ 4.7328 * parameters.mean_wait_of_all 
	+ 268605484.4953 * parameters.cpu_usage 
	- 0.0127 * parameters.avg_work_of_same_past_second 
	+ 0.1197 * parameters.avg_wait_of_same_past_second 
	- 0.0105 * parameters.avg_latency_of_same_last_20 
	- 0.02 * parameters.max_latency_of_same_last_50 
	- 773543210.8889;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM97(work_wait &parameters) {
  double actual_remaining = 
	-0.013 * parameters.wait_so_far 
	- 212083.8285 * parameters.total_wait_locks 
	+ 5.2978 * parameters.mean_wait_of_all 
	+ 373830247.5776 * parameters.cpu_usage 
	- 0.0127 * parameters.avg_work_of_same_past_second 
	+ 0.1197 * parameters.avg_wait_of_same_past_second 
	- 0.0105 * parameters.avg_latency_of_same_last_20 
	- 0.0262 * parameters.max_latency_of_same_last_50 
	- 924390263.8332;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM98(work_wait &parameters) {
  double actual_remaining = 
	-0.0315 * parameters.wait_so_far 
	+ 327798.4838 * parameters.total_wait_locks 
	- 2.9796 * parameters.mean_wait_of_all 
	- 17004586.728 * parameters.cpu_usage 
	- 1.2926 * parameters.avg_work_of_same_past_second 
	+ 1.1442 * parameters.avg_wait_of_same_past_second 
	- 0.0593 * parameters.avg_latency_of_same_last_20 
	- 0.003 * parameters.max_latency_of_same_last_50 
	- 59066329.6771;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM99(work_wait &parameters) {
  double actual_remaining = 
	7.3234 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 537127.3326 * parameters.total_wait_locks 
	- 5.5081 * parameters.mean_wait_of_all 
	- 17004586.728 * parameters.cpu_usage 
	- 2.1103 * parameters.avg_work_of_same_past_second 
	+ 1.793 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0.003 * parameters.max_latency_of_same_last_50 
	- 56685103.5611;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM100(work_wait &parameters) {
  double actual_remaining = 
	8.6834 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 537127.3326 * parameters.total_wait_locks 
	- 5.5081 * parameters.mean_wait_of_all 
	- 17004586.728 * parameters.cpu_usage 
	- 2.1103 * parameters.avg_work_of_same_past_second 
	+ 1.793 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0.003 * parameters.max_latency_of_same_last_50 
	- 61462161.7586;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM101(work_wait &parameters) {
  double actual_remaining = 
	7.6721 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 667821.4613 * parameters.total_wait_locks 
	- 5.5081 * parameters.mean_wait_of_all 
	- 17004586.728 * parameters.cpu_usage 
	- 2.1103 * parameters.avg_work_of_same_past_second 
	+ 1.793 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0.003 * parameters.max_latency_of_same_last_50 
	- 134324450.2904;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM102(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.wait_so_far 
	+ 537127.3326 * parameters.total_wait_locks 
	- 5.5081 * parameters.mean_wait_of_all 
	- 17004586.728 * parameters.cpu_usage 
	- 2.1103 * parameters.avg_work_of_same_past_second 
	+ 1.793 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0.003 * parameters.max_latency_of_same_last_50 
	- 86760178.0114;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM103(work_wait &parameters) {
  double actual_remaining = 
	-0.0094 * parameters.wait_so_far 
	+ 206622.1135 * parameters.total_wait_locks 
	- 3.7473 * parameters.mean_wait_of_all 
	- 26613389.1969 * parameters.cpu_usage 
	+ 0.5692 * parameters.avg_work_of_same_past_second 
	+ 0.3038 * parameters.avg_wait_of_same_past_second 
	- 0.0422 * parameters.avg_latency_of_same_last_20 
	- 0.0039 * parameters.max_latency_of_same_last_50 
	+ 358293243.3023;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM104(work_wait &parameters) {
  double actual_remaining = 
	-0.0094 * parameters.wait_so_far 
	- 89887.5507 * parameters.total_wait_locks 
	- 2.417 * parameters.mean_wait_of_all 
	- 26613389.1969 * parameters.cpu_usage 
	+ 0.5692 * parameters.avg_work_of_same_past_second 
	+ 0.3256 * parameters.avg_wait_of_same_past_second 
	- 0.0122 * parameters.avg_latency_of_same_last_20 
	- 0.0039 * parameters.max_latency_of_same_last_50 
	+ 277954817.154;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM105(work_wait &parameters) {
  double actual_remaining = 
	-0.0412 * parameters.wait_so_far 
	- 224335.0664 * parameters.total_wait_locks 
	- 1.2053 * parameters.mean_wait_of_all 
	- 26613389.1969 * parameters.cpu_usage 
	+ 0.6195 * parameters.avg_work_of_same_past_second 
	+ 0.0992 * parameters.avg_wait_of_same_past_second 
	+ 0.0175 * parameters.avg_latency_of_same_last_20 
	- 0.0039 * parameters.max_latency_of_same_last_50 
	+ 331122426.7806;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM106(work_wait &parameters) {
  double actual_remaining = 
	-0.0012 * parameters.wait_so_far 
	+ 153.3292 * parameters.total_wait_locks 
	- 0.1424 * parameters.mean_wait_of_all 
	- 19985025.504 * parameters.cpu_usage 
	- 0.0672 * parameters.avg_work_of_same_past_second 
	- 0.0005 * parameters.avg_wait_of_same_past_second 
	+ 0.0404 * parameters.avg_latency_of_same_last_20 
	- 0.0269 * parameters.max_latency_of_same_last_50 
	+ 104565940.6248;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM107(work_wait &parameters) {
  double actual_remaining = 
	-27.1801 * parameters.work_so_far 
	- 0.014 * parameters.wait_so_far 
	- 58375.8802 * parameters.total_wait_locks 
	+ 0.0944 * parameters.mean_wait_of_all 
	+ 860611.5378 * parameters.cpu_usage 
	- 3.7219 * parameters.avg_work_of_same_past_second 
	+ 0.0486 * parameters.avg_wait_of_same_past_second 
	- 0.0841 * parameters.avg_latency_of_same_last_20 
	- 0.0047 * parameters.max_latency_of_same_last_50 
	+ 254914610.4519;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM108(work_wait &parameters) {
  double actual_remaining = 
	-22.0029 * parameters.work_so_far 
	- 0.014 * parameters.wait_so_far 
	- 58375.8802 * parameters.total_wait_locks 
	+ 0.0944 * parameters.mean_wait_of_all 
	+ 860611.5378 * parameters.cpu_usage 
	- 3.7219 * parameters.avg_work_of_same_past_second 
	+ 0.0486 * parameters.avg_wait_of_same_past_second 
	- 0.0672 * parameters.avg_latency_of_same_last_20 
	- 0.0047 * parameters.max_latency_of_same_last_50 
	+ 234297040.4784;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM109(work_wait &parameters) {
  double actual_remaining = 
	-0.0077 * parameters.wait_so_far 
	- 58375.8802 * parameters.total_wait_locks 
	+ 0.0944 * parameters.mean_wait_of_all 
	+ 860611.5378 * parameters.cpu_usage 
	- 3.7219 * parameters.avg_work_of_same_past_second 
	+ 0.0486 * parameters.avg_wait_of_same_past_second 
	+ 0.0045 * parameters.avg_latency_of_same_last_20 
	- 0.0047 * parameters.max_latency_of_same_last_50 
	+ 146426035.427;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM110(work_wait &parameters) {
  double actual_remaining = 
	0.1239 * parameters.work_so_far 
	+ 0.0142 * parameters.wait_so_far 
	- 150962.6931 * parameters.total_wait_locks 
	+ 0.0944 * parameters.mean_wait_of_all 
	+ 860611.5378 * parameters.cpu_usage 
	- 3.7456 * parameters.avg_work_of_same_past_second 
	+ 0.158 * parameters.avg_wait_of_same_past_second 
	+ 0.0045 * parameters.avg_latency_of_same_last_20 
	- 0.0229 * parameters.max_latency_of_same_last_50 
	+ 175502946.0079;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM111(work_wait &parameters) {
  double actual_remaining = 
	0.265 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 17015.1749 * parameters.total_wait_locks 
	+ 0.0944 * parameters.mean_wait_of_all 
	+ 860611.5378 * parameters.cpu_usage 
	- 5.8152 * parameters.avg_work_of_same_past_second 
	+ 0.0405 * parameters.avg_wait_of_same_past_second 
	+ 0.0045 * parameters.avg_latency_of_same_last_20 
	- 0.0085 * parameters.max_latency_of_same_last_50 
	+ 158682603.1619;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM112(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.wait_so_far 
	- 273364.6264 * parameters.total_wait_locks 
	+ 3.6255 * parameters.mean_wait_of_all 
	+ 3850770.6621 * parameters.cpu_usage 
	- 0.03 * parameters.avg_work_of_same_past_second 
	+ 0.0007 * parameters.avg_wait_of_same_past_second 
	+ 0.0255 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	- 363221760.8749;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM113(work_wait &parameters) {
  double actual_remaining = 
	0.6183 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 15633.9662 * parameters.total_wait_locks 
	+ 0.2503 * parameters.mean_wait_of_all 
	+ 7661757.7813 * parameters.cpu_usage 
	- 0.03 * parameters.avg_work_of_same_past_second 
	+ 0.0007 * parameters.avg_wait_of_same_past_second 
	+ 0.0043 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	- 4714877.1191;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM114(work_wait &parameters) {
  double actual_remaining = 
	-0.1158 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 123694.0237 * parameters.total_wait_locks 
	+ 0.7125 * parameters.mean_wait_of_all 
	+ 223686822.694 * parameters.cpu_usage 
	- 0.0809 * parameters.avg_work_of_same_past_second 
	- 0.0063 * parameters.avg_wait_of_same_past_second 
	+ 0.0078 * parameters.avg_latency_of_same_last_20 
	+ 0.0042 * parameters.max_latency_of_same_last_50 
	- 381847894.2434;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM115(work_wait &parameters) {
  double actual_remaining = 
	-0.3495 * parameters.work_so_far 
	+ 0.0103 * parameters.wait_so_far 
	+ 35763.0617 * parameters.total_wait_locks 
	- 5.0645 * parameters.mean_wait_of_all 
	+ 67330046.426 * parameters.cpu_usage 
	- 0.0809 * parameters.avg_work_of_same_past_second 
	- 0.0063 * parameters.avg_wait_of_same_past_second 
	+ 0.0175 * parameters.avg_latency_of_same_last_20 
	+ 0.0436 * parameters.max_latency_of_same_last_50 
	+ 708900443.1125;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM116(work_wait &parameters) {
  double actual_remaining = 
	-0.3495 * parameters.work_so_far 
	+ 0.0391 * parameters.wait_so_far 
	+ 35763.0617 * parameters.total_wait_locks 
	- 0.9552 * parameters.mean_wait_of_all 
	+ 67330046.426 * parameters.cpu_usage 
	- 0.0809 * parameters.avg_work_of_same_past_second 
	- 0.0063 * parameters.avg_wait_of_same_past_second 
	+ 0.0175 * parameters.avg_latency_of_same_last_20 
	+ 0.0436 * parameters.max_latency_of_same_last_50 
	+ 53853737.8608;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM117(work_wait &parameters) {
  double actual_remaining = 
	0.024 * parameters.work_so_far 
	+ 0.0044 * parameters.wait_so_far 
	+ 1073.0658 * parameters.total_wait_locks 
	+ 0.2665 * parameters.mean_wait_of_all 
	- 59929003.0707 * parameters.cpu_usage 
	- 0.0385 * parameters.avg_work_of_same_past_second 
	+ 0.0793 * parameters.avg_wait_of_same_past_second 
	- 0.0145 * parameters.avg_latency_of_same_last_20 
	+ 0.0112 * parameters.max_latency_of_same_last_50 
	- 8649859.4511;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM118(work_wait &parameters) {
  double actual_remaining = 
	0.024 * parameters.work_so_far 
	+ 0.0096 * parameters.wait_so_far 
	- 238026.3781 * parameters.total_wait_locks 
	+ 0.1407 * parameters.mean_wait_of_all 
	- 193529064.2534 * parameters.cpu_usage 
	+ 6.5572 * parameters.avg_work_of_same_past_second 
	- 0.1462 * parameters.avg_wait_of_same_past_second 
	- 0.0244 * parameters.avg_latency_of_same_last_20 
	+ 0.0077 * parameters.max_latency_of_same_last_50 
	+ 230488118.0082;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM119(work_wait &parameters) {
  double actual_remaining = 
	0.024 * parameters.work_so_far 
	+ 0.0108 * parameters.wait_so_far 
	+ 32090.7047 * parameters.total_wait_locks 
	+ 0.1407 * parameters.mean_wait_of_all 
	- 38568971.2516 * parameters.cpu_usage 
	- 0.5144 * parameters.avg_work_of_same_past_second 
	+ 0.2384 * parameters.avg_wait_of_same_past_second 
	- 0.0272 * parameters.avg_latency_of_same_last_20 
	+ 0.0077 * parameters.max_latency_of_same_last_50 
	- 61574758.6134;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM120(work_wait &parameters) {
  double actual_remaining = 
	0.024 * parameters.work_so_far 
	+ 0.0108 * parameters.wait_so_far 
	+ 36862.6492 * parameters.total_wait_locks 
	+ 0.1407 * parameters.mean_wait_of_all 
	- 38568971.2516 * parameters.cpu_usage 
	- 0.7438 * parameters.avg_work_of_same_past_second 
	+ 0.2384 * parameters.avg_wait_of_same_past_second 
	- 0.0272 * parameters.avg_latency_of_same_last_20 
	+ 0.0077 * parameters.max_latency_of_same_last_50 
	- 59974300.3438;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM121(work_wait &parameters) {
  double actual_remaining = 
	0.024 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	+ 189463.496 * parameters.total_wait_locks 
	- 2.0173 * parameters.mean_wait_of_all 
	- 10177695.7097 * parameters.cpu_usage 
	- 0.0385 * parameters.avg_work_of_same_past_second 
	+ 0.1261 * parameters.avg_wait_of_same_past_second 
	+ 0.0047 * parameters.avg_latency_of_same_last_20 
	+ 0.0026 * parameters.max_latency_of_same_last_50 
	+ 144820565.9806;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM122(work_wait &parameters) {
  double actual_remaining = 
	0.024 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	+ 1073.0658 * parameters.total_wait_locks 
	- 0.1862 * parameters.mean_wait_of_all 
	- 9586816.8813 * parameters.cpu_usage 
	- 0.0385 * parameters.avg_work_of_same_past_second 
	+ 0.0137 * parameters.avg_wait_of_same_past_second 
	+ 0.0045 * parameters.avg_latency_of_same_last_20 
	+ 0.0025 * parameters.max_latency_of_same_last_50 
	+ 54980634.2056;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM123(work_wait &parameters) {
  double actual_remaining = 
	0.0397 * parameters.work_so_far 
	- 0.0022 * parameters.wait_so_far 
	+ 1073.0658 * parameters.total_wait_locks 
	- 0.1399 * parameters.mean_wait_of_all 
	+ 497579.3904 * parameters.cpu_usage 
	+ 1.9007 * parameters.avg_work_of_same_past_second 
	- 0.1017 * parameters.avg_wait_of_same_past_second 
	+ 0.0019 * parameters.avg_latency_of_same_last_20 
	+ 0.0166 * parameters.max_latency_of_same_last_50 
	- 5466356.7203;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM124(work_wait &parameters) {
  double actual_remaining = 
	0.0397 * parameters.work_so_far 
	- 0.1846 * parameters.wait_so_far 
	+ 169930.1407 * parameters.total_wait_locks 
	- 2.1273 * parameters.mean_wait_of_all 
	+ 63710836.2972 * parameters.cpu_usage 
	- 1.9574 * parameters.avg_work_of_same_past_second 
	+ 0.0886 * parameters.avg_wait_of_same_past_second 
	- 0.0163 * parameters.avg_latency_of_same_last_20 
	- 0.0217 * parameters.max_latency_of_same_last_50 
	+ 333125572.6068;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM125(work_wait &parameters) {
  double actual_remaining = 
	0.0397 * parameters.work_so_far 
	- 0.1287 * parameters.wait_so_far 
	+ 169930.1407 * parameters.total_wait_locks 
	- 2.1273 * parameters.mean_wait_of_all 
	+ 63710836.2972 * parameters.cpu_usage 
	- 1.9574 * parameters.avg_work_of_same_past_second 
	+ 0.0886 * parameters.avg_wait_of_same_past_second 
	- 0.0163 * parameters.avg_latency_of_same_last_20 
	- 0.0217 * parameters.max_latency_of_same_last_50 
	+ 324019477.77;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM126(work_wait &parameters) {
  double actual_remaining = 
	0.0397 * parameters.work_so_far 
	- 0.1287 * parameters.wait_so_far 
	+ 169930.1407 * parameters.total_wait_locks 
	- 2.1273 * parameters.mean_wait_of_all 
	+ 63710836.2972 * parameters.cpu_usage 
	- 1.9574 * parameters.avg_work_of_same_past_second 
	+ 0.0886 * parameters.avg_wait_of_same_past_second 
	- 0.0163 * parameters.avg_latency_of_same_last_20 
	- 0.0217 * parameters.max_latency_of_same_last_50 
	+ 324101671.7635;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM127(work_wait &parameters) {
  double actual_remaining = 
	0.0397 * parameters.work_so_far 
	- 0.1188 * parameters.wait_so_far 
	+ 169930.1407 * parameters.total_wait_locks 
	- 2.1273 * parameters.mean_wait_of_all 
	+ 63710836.2972 * parameters.cpu_usage 
	- 1.9574 * parameters.avg_work_of_same_past_second 
	+ 0.0886 * parameters.avg_wait_of_same_past_second 
	- 0.0163 * parameters.avg_latency_of_same_last_20 
	- 0.0217 * parameters.max_latency_of_same_last_50 
	+ 324252283.7383;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM128(work_wait &parameters) {
  double actual_remaining = 
	0.0397 * parameters.work_so_far 
	- 0.1599 * parameters.wait_so_far 
	+ 123045.7331 * parameters.total_wait_locks 
	- 1.6285 * parameters.mean_wait_of_all 
	+ 63710836.2972 * parameters.cpu_usage 
	- 1.9574 * parameters.avg_work_of_same_past_second 
	+ 0.0886 * parameters.avg_wait_of_same_past_second 
	- 0.0163 * parameters.avg_latency_of_same_last_20 
	- 0.0186 * parameters.max_latency_of_same_last_50 
	+ 267926424.6723;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM129(work_wait &parameters) {
  double actual_remaining = 
	0.0397 * parameters.work_so_far 
	- 0.0082 * parameters.wait_so_far 
	- 102354.1234 * parameters.total_wait_locks 
	+ 0.8364 * parameters.mean_wait_of_all 
	+ 180674923.0345 * parameters.cpu_usage 
	- 4.5137 * parameters.avg_work_of_same_past_second 
	+ 0.1974 * parameters.avg_wait_of_same_past_second 
	- 0.0099 * parameters.avg_latency_of_same_last_20 
	+ 0.0003 * parameters.max_latency_of_same_last_50 
	- 68915224.7014;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM130(work_wait &parameters) {
  double actual_remaining = 
	0.0397 * parameters.work_so_far 
	- 0.0034 * parameters.wait_so_far 
	+ 113706.5031 * parameters.total_wait_locks 
	+ 2.4256 * parameters.mean_wait_of_all 
	- 1177234656.2611 * parameters.cpu_usage 
	- 0.1165 * parameters.avg_work_of_same_past_second 
	- 0.1938 * parameters.avg_wait_of_same_past_second 
	+ 0.156 * parameters.avg_latency_of_same_last_20 
	+ 0.0003 * parameters.max_latency_of_same_last_50 
	+ 758746129.4306;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM131(work_wait &parameters) {
  double actual_remaining = 
	0.0397 * parameters.work_so_far 
	- 0.0034 * parameters.wait_so_far 
	- 95777.7777 * parameters.total_wait_locks 
	+ 2.9757 * parameters.mean_wait_of_all 
	- 1874353661.1319 * parameters.cpu_usage 
	- 0.1165 * parameters.avg_work_of_same_past_second 
	- 0.1938 * parameters.avg_wait_of_same_past_second 
	+ 0.1022 * parameters.avg_latency_of_same_last_20 
	+ 0.0003 * parameters.max_latency_of_same_last_50 
	+ 1481892803.6803;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM132(work_wait &parameters) {
  double actual_remaining = 
	0.0397 * parameters.work_so_far 
	- 0.0034 * parameters.wait_so_far 
	+ 233093.7266 * parameters.total_wait_locks 
	- 1.3513 * parameters.mean_wait_of_all 
	- 692188683.9921 * parameters.cpu_usage 
	- 0.1165 * parameters.avg_work_of_same_past_second 
	- 0.4287 * parameters.avg_wait_of_same_past_second 
	+ 0.027 * parameters.avg_latency_of_same_last_20 
	+ 0.0003 * parameters.max_latency_of_same_last_50 
	+ 934484057.0129;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM133(work_wait &parameters) {
  double actual_remaining = 
	0.0591 * parameters.work_so_far 
	- 0.0016 * parameters.wait_so_far 
	- 36268.8289 * parameters.total_wait_locks 
	- 1.9079 * parameters.mean_wait_of_all 
	+ 497579.3904 * parameters.cpu_usage 
	- 0.1793 * parameters.avg_work_of_same_past_second 
	+ 0.0205 * parameters.avg_wait_of_same_past_second 
	+ 0.0158 * parameters.avg_latency_of_same_last_20 
	- 0.0059 * parameters.max_latency_of_same_last_50 
	+ 350963940.4172;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM134(work_wait &parameters) {
  double actual_remaining = 
	0.0591 * parameters.work_so_far 
	- 0.042 * parameters.wait_so_far 
	- 75767.4541 * parameters.total_wait_locks 
	- 1.7934 * parameters.mean_wait_of_all 
	+ 46692341.488 * parameters.cpu_usage 
	- 0.6157 * parameters.avg_work_of_same_past_second 
	+ 0.0752 * parameters.avg_wait_of_same_past_second 
	+ 0.0261 * parameters.avg_latency_of_same_last_20 
	- 0.0085 * parameters.max_latency_of_same_last_50 
	+ 332071979.8792;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM135(work_wait &parameters) {
  double actual_remaining = 
	0.0591 * parameters.work_so_far 
	- 0.0016 * parameters.wait_so_far 
	+ 258184.6741 * parameters.total_wait_locks 
	- 2.8171 * parameters.mean_wait_of_all 
	+ 46692341.488 * parameters.cpu_usage 
	- 0.6157 * parameters.avg_work_of_same_past_second 
	+ 0.118 * parameters.avg_wait_of_same_past_second 
	+ 0.0261 * parameters.avg_latency_of_same_last_20 
	- 0.0085 * parameters.max_latency_of_same_last_50 
	+ 230738538.3575;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM136(work_wait &parameters) {
  double actual_remaining = 
	0.0591 * parameters.work_so_far 
	- 0.0016 * parameters.wait_so_far 
	- 51963.0367 * parameters.total_wait_locks 
	- 0.0385 * parameters.mean_wait_of_all 
	+ 28332884.7569 * parameters.cpu_usage 
	- 0.4422 * parameters.avg_work_of_same_past_second 
	+ 0.0018 * parameters.avg_wait_of_same_past_second 
	+ 0.0189 * parameters.avg_latency_of_same_last_20 
	- 0.0097 * parameters.max_latency_of_same_last_50 
	+ 80661554.5687;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM137(work_wait &parameters) {
  double actual_remaining = 
	0.0591 * parameters.work_so_far 
	- 0.0016 * parameters.wait_so_far 
	- 54389.8358 * parameters.total_wait_locks 
	- 0.0385 * parameters.mean_wait_of_all 
	+ 28332884.7569 * parameters.cpu_usage 
	- 0.4422 * parameters.avg_work_of_same_past_second 
	+ 0.0018 * parameters.avg_wait_of_same_past_second 
	+ 0.0189 * parameters.avg_latency_of_same_last_20 
	- 0.0099 * parameters.max_latency_of_same_last_50 
	+ 74105007.2992;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM138(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.wait_so_far 
	+ 153.3292 * parameters.total_wait_locks 
	- 0.0003 * parameters.mean_wait_of_all 
	- 1078485.3374 * parameters.cpu_usage 
	- 0.0101 * parameters.avg_work_of_same_past_second 
	- 0.0013 * parameters.avg_wait_of_same_past_second 
	+ 0.001 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 29687127.4214;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
payment_estimate(work_wait &parameters){

  if (parameters.avg_latency_of_same_last_20 <= 403556000) {

    if (parameters.avg_latency_of_same_last_20 <= 130250000) {

      if (parameters.work_so_far <= 9295.5) {

        if (parameters.wait_so_far <= 65131649.5) {

          if (parameters.work_so_far <= 7178.5) {
            return payment_LM1(parameters);
          } else {
            return payment_LM2(parameters);
          }
        } else {

          if (parameters.total_wait_locks <= 47.5) {
            return payment_LM3(parameters);
          } else {
            return payment_LM4(parameters);
          }
        }
      } else {

        if (parameters.work_so_far <= 14351.5) {
          return payment_LM5(parameters);
        } else {

          if (parameters.total_wait_locks <= 185) {

            if (parameters.max_latency_of_same_last_50 <= 354001500) {

              if (parameters.wait_so_far <= 22354483) {

                if (parameters.total_wait_locks <= 124.5) {
                  return payment_LM6(parameters);
                } else {
                  return payment_LM7(parameters);
                }
              } else {

                if (parameters.max_latency_of_same_last_50 <= 303560500) {
                  return payment_LM8(parameters);
                } else {

                  if (parameters.avg_latency_of_same_last_20 <= 89633800) {

                    if (parameters.work_so_far <= 18465) {

                      if (parameters.work_so_far <= 17791.5) {

                        if (parameters.avg_wait_of_same_past_second <= 55849250) {
                          return payment_LM9(parameters);
                        } else {
                          return payment_LM10(parameters);
                        }
                      } else {
                        return payment_LM11(parameters);
                      }
                    } else {

                      if (parameters.cpu_usage <= 0.96) {
                        return payment_LM12(parameters);
                      } else {

                        if (parameters.work_so_far <= 21745) {
                          return payment_LM13(parameters);
                        } else {
                          return payment_LM14(parameters);
                        }
                      }
                    }
                  } else {
                    return payment_LM15(parameters);
                  }
                }
              }
            } else {

              if (parameters.cpu_usage <= 0.92) {

                if (parameters.max_latency_of_same_last_50 <= 643252000) {

                  if (parameters.cpu_usage <= 0.906) {
                    return payment_LM16(parameters);
                  } else {

                    if (parameters.avg_work_of_same_past_second <= 8216310) {
                      return payment_LM17(parameters);
                    } else {
                      return payment_LM18(parameters);
                    }
                  }
                } else {
                  return payment_LM19(parameters);
                }
              } else {

                if (parameters.avg_work_of_same_past_second <= 16264050) {
                  return payment_LM20(parameters);
                } else {

                  if (parameters.avg_work_of_same_past_second <= 18222600) {

                    if (parameters.cpu_usage <= 0.995) {

                      if (parameters.total_wait_locks <= 83.5) {
                        return payment_LM21(parameters);
                      } else {
                        return payment_LM22(parameters);
                      }
                    } else {

                      if (parameters.wait_so_far <= 67165958) {
                        return payment_LM23(parameters);
                      } else {
                        return payment_LM24(parameters);
                      }
                    }
                  } else {
                    return payment_LM25(parameters);
                  }
                }
              }
            }
          } else {
            return payment_LM26(parameters);
          }
        }
      }
    } else {

      if (parameters.wait_so_far <= 242274130.5) {
        return payment_LM27(parameters);
      } else {

        if (parameters.avg_wait_of_same_past_second <= 375486500) {

          if (parameters.avg_latency_of_same_last_20 <= 265890000) {

            if (parameters.avg_work_of_same_past_second <= 23348200) {

              if (parameters.mean_wait_of_all <= 87410150) {

                if (parameters.avg_wait_of_same_past_second <= 171192000) {

                  if (parameters.avg_work_of_same_past_second <= 9543310) {

                    if (parameters.avg_latency_of_same_last_20 <= 199338000) {
                      return payment_LM28(parameters);
                    } else {

                      if (parameters.work_so_far <= 14568.5) {
                        return payment_LM29(parameters);
                      } else {

                        if (parameters.avg_work_of_same_past_second <= 7569350) {
                          return payment_LM30(parameters);
                        } else {
                          return payment_LM31(parameters);
                        }
                      }
                    }
                  } else {
                    return payment_LM32(parameters);
                  }
                } else {

                  if (parameters.avg_latency_of_same_last_20 <= 202127500) {
                    return payment_LM33(parameters);
                  } else {
                    return payment_LM34(parameters);
                  }
                }
              } else {

                if (parameters.avg_work_of_same_past_second <= 23265150) {
                  return payment_LM35(parameters);
                } else {
                  return payment_LM36(parameters);
                }
              }
            } else {
              return payment_LM37(parameters);
            }
          } else {

            if (parameters.avg_latency_of_same_last_20 <= 295300500) {
              return payment_LM38(parameters);
            } else {

              if (parameters.mean_wait_of_all <= 109045500) {
                return payment_LM39(parameters);
              } else {

                if (parameters.total_wait_locks <= 420.5) {

                  if (parameters.cpu_usage <= 0.976) {

                    if (parameters.cpu_usage <= 0.967) {
                      return payment_LM40(parameters);
                    } else {

                      if (parameters.avg_work_of_same_past_second <= 29675600) {

                        if (parameters.avg_work_of_same_past_second <= 23890350) {
                          return payment_LM41(parameters);
                        } else {

                          if (parameters.wait_so_far <= 329646628.5) {
                            return payment_LM42(parameters);
                          } else {
                            return payment_LM43(parameters);
                          }
                        }
                      } else {
                        return payment_LM44(parameters);
                      }
                    }
                  } else {
                    return payment_LM45(parameters);
                  }
                } else {
                  return payment_LM46(parameters);
                }
              }
            }
          }
        } else {

          if (parameters.avg_wait_of_same_past_second <= 400734000) {

            if (parameters.mean_wait_of_all <= 131042500) {
              return payment_LM47(parameters);
            } else {

              if (parameters.avg_work_of_same_past_second <= 35918000) {

                if (parameters.mean_wait_of_all <= 156804500) {

                  if (parameters.total_wait_locks <= 568) {

                    if (parameters.wait_so_far <= 721782660.5) {

                      if (parameters.work_so_far <= 37567.5) {
                        return payment_LM48(parameters);
                      } else {
                        return payment_LM49(parameters);
                      }
                    } else {
                      return payment_LM50(parameters);
                    }
                  } else {
                    return payment_LM51(parameters);
                  }
                } else {

                  if (parameters.avg_work_of_same_past_second <= 30822150) {
                    return payment_LM52(parameters);
                  } else {

                    if (parameters.avg_work_of_same_past_second <= 35829550) {
                      return payment_LM53(parameters);
                    } else {
                      return payment_LM54(parameters);
                    }
                  }
                }
              } else {

                if (parameters.wait_so_far <= 756141209.5) {
                  return payment_LM55(parameters);
                } else {

                  if (parameters.wait_so_far <= 1141329287.5) {
                    return payment_LM56(parameters);
                  } else {
                    return payment_LM57(parameters);
                  }
                }
              }
            }
          } else {
            return payment_LM58(parameters);
          }
        }
      }
    }
  } else {

    if (parameters.max_latency_of_same_last_50 <= 1241395000) {

      if (parameters.cpu_usage <= 0.995) {

        if (parameters.mean_wait_of_all <= 64141600) {

          if (parameters.avg_work_of_same_past_second <= 11852000) {

            if (parameters.max_latency_of_same_last_50 <= 1062201500) {

              if (parameters.avg_work_of_same_past_second <= 7898500) {
                return payment_LM59(parameters);
              } else {

                if (parameters.total_wait_locks <= 173.5) {
                  return payment_LM60(parameters);
                } else {
                  return payment_LM61(parameters);
                }
              }
            } else {

              if (parameters.total_wait_locks <= 155.5) {
                return payment_LM62(parameters);
              } else {
                return payment_LM63(parameters);
              }
            }
          } else {
            return payment_LM64(parameters);
          }
        } else {

          if (parameters.cpu_usage <= 0.986) {
            return payment_LM65(parameters);
          } else {

            if (parameters.cpu_usage <= 0.989) {

              if (parameters.avg_work_of_same_past_second <= 27303400) {
                return payment_LM66(parameters);
              } else {

                if (parameters.avg_work_of_same_past_second <= 32528350) {

                  if (parameters.wait_so_far <= 412453728) {
                    return payment_LM67(parameters);
                  } else {

                    if (parameters.work_so_far <= 27518) {
                      return payment_LM68(parameters);
                    } else {
                      return payment_LM69(parameters);
                    }
                  }
                } else {
                  return payment_LM70(parameters);
                }
              }
            } else {
              return payment_LM71(parameters);
            }
          }
        }
      } else {

        if (parameters.avg_work_of_same_past_second <= 26759350) {
          return payment_LM72(parameters);
        } else {

          if (parameters.work_so_far <= 32889) {

            if (parameters.max_latency_of_same_last_50 <= 1042200000) {
              return payment_LM73(parameters);
            } else {
              return payment_LM74(parameters);
            }
          } else {

            if (parameters.mean_wait_of_all <= 79630350) {

              if (parameters.mean_wait_of_all <= 78435700) {
                return payment_LM75(parameters);
              } else {
                return payment_LM76(parameters);
              }
            } else {
              return payment_LM77(parameters);
            }
          }
        }
      }
    } else {

      if (parameters.mean_wait_of_all <= 131703000) {

        if (parameters.wait_so_far <= 243771773) {

          if (parameters.mean_wait_of_all <= 120255000) {

            if (parameters.mean_wait_of_all <= 86107850) {
              return payment_LM78(parameters);
            } else {
              return payment_LM79(parameters);
            }
          } else {
            return payment_LM80(parameters);
          }
        } else {

          if (parameters.avg_latency_of_same_last_20 <= 636031000) {
            return payment_LM81(parameters);
          } else {

            if (parameters.avg_wait_of_same_past_second <= 418493000) {

              if (parameters.mean_wait_of_all <= 94766700) {
                return payment_LM82(parameters);
              } else {

                if (parameters.total_wait_locks <= 415.5) {

                  if (parameters.avg_wait_of_same_past_second <= 375115500) {
                    return payment_LM83(parameters);
                  } else {

                    if (parameters.avg_work_of_same_past_second <= 30584800) {
                      return payment_LM84(parameters);
                    } else {
                      return payment_LM85(parameters);
                    }
                  }
                } else {
                  return payment_LM86(parameters);
                }
              }
            } else {

              if (parameters.work_so_far <= 33340) {
                return payment_LM87(parameters);
              } else {
                return payment_LM88(parameters);
              }
            }
          }
        }
      } else {

        if (parameters.avg_wait_of_same_past_second <= 557413000) {

          if (parameters.mean_wait_of_all <= 143892000) {

            if (parameters.max_latency_of_same_last_50 <= 1594815000) {

              if (parameters.cpu_usage <= 0.947) {

                if (parameters.max_latency_of_same_last_50 <= 1377860000) {
                  return payment_LM89(parameters);
                } else {
                  return payment_LM90(parameters);
                }
              } else {

                if (parameters.mean_wait_of_all <= 137503500) {
                  return payment_LM91(parameters);
                } else {
                  return payment_LM92(parameters);
                }
              }
            } else {

              if (parameters.avg_wait_of_same_past_second <= 437996000) {

                if (parameters.avg_wait_of_same_past_second <= 412050000) {

                  if (parameters.work_so_far <= 648064) {

                    if (parameters.mean_wait_of_all <= 134204500) {

                      if (parameters.mean_wait_of_all <= 133804000) {
                        return payment_LM93(parameters);
                      } else {
                        return payment_LM94(parameters);
                      }
                    } else {
                      return payment_LM95(parameters);
                    }
                  } else {

                    if (parameters.mean_wait_of_all <= 142227500) {
                      return payment_LM96(parameters);
                    } else {
                      return payment_LM97(parameters);
                    }
                  }
                } else {

                  if (parameters.avg_wait_of_same_past_second <= 435681500) {
                    return payment_LM98(parameters);
                  } else {

                    if (parameters.avg_work_of_same_past_second <= 43248150) {

                      if (parameters.mean_wait_of_all <= 143730500) {

                        if (parameters.mean_wait_of_all <= 134787500) {
                          return payment_LM99(parameters);
                        } else {
                          return payment_LM100(parameters);
                        }
                      } else {
                        return payment_LM101(parameters);
                      }
                    } else {
                      return payment_LM102(parameters);
                    }
                  }
                }
              } else {

                if (parameters.avg_work_of_same_past_second <= 36640100) {

                  if (parameters.avg_latency_of_same_last_20 <= 626020500) {

                    if (parameters.mean_wait_of_all <= 132359000) {
                      return payment_LM103(parameters);
                    } else {
                      return payment_LM104(parameters);
                    }
                  } else {
                    return payment_LM105(parameters);
                  }
                } else {
                  return payment_LM106(parameters);
                }
              }
            }
          } else {

            if (parameters.mean_wait_of_all <= 157009500) {

              if (parameters.avg_work_of_same_past_second <= 25820250) {

                if (parameters.avg_work_of_same_past_second <= 23739600) {

                  if (parameters.wait_so_far <= 183566682.5) {

                    if (parameters.work_so_far <= 43375) {
                      return payment_LM107(parameters);
                    } else {
                      return payment_LM108(parameters);
                    }
                  } else {
                    return payment_LM109(parameters);
                  }
                } else {

                  if (parameters.avg_work_of_same_past_second <= 25203400) {
                    return payment_LM110(parameters);
                  } else {
                    return payment_LM111(parameters);
                  }
                }
              } else {

                if (parameters.cpu_usage <= 0.959) {
                  return payment_LM112(parameters);
                } else {
                  return payment_LM113(parameters);
                }
              }
            } else {

              if (parameters.avg_work_of_same_past_second <= 31385250) {

                if (parameters.avg_latency_of_same_last_20 <= 791480000) {
                  return payment_LM114(parameters);
                } else {

                  if (parameters.max_latency_of_same_last_50 <= 2210195000) {
                    return payment_LM115(parameters);
                  } else {
                    return payment_LM116(parameters);
                  }
                }
              } else {

                if (parameters.avg_work_of_same_past_second <= 37854150) {

                  if (parameters.avg_wait_of_same_past_second <= 451389000) {

                    if (parameters.max_latency_of_same_last_50 <= 1478310000) {
                      return payment_LM117(parameters);
                    } else {

                      if (parameters.avg_work_of_same_past_second <= 35692450) {
                        return payment_LM118(parameters);
                      } else {

                        if (parameters.avg_work_of_same_past_second <= 36807450) {
                          return payment_LM119(parameters);
                        } else {
                          return payment_LM120(parameters);
                        }
                      }
                    }
                  } else {

                    if (parameters.max_latency_of_same_last_50 <= 1777860000) {
                      return payment_LM121(parameters);
                    } else {
                      return payment_LM122(parameters);
                    }
                  }
                } else {

                  if (parameters.avg_work_of_same_past_second <= 44447500) {

                    if (parameters.cpu_usage <= 0.932) {

                      if (parameters.work_so_far <= 51698.5) {
                        return payment_LM123(parameters);
                      } else {

                        if (parameters.wait_so_far <= 109746964.5) {

                          if (parameters.max_latency_of_same_last_50 <= 1643890000) {

                            if (parameters.wait_so_far <= 18589349.5) {
                              return payment_LM124(parameters);
                            } else {

                              if (parameters.wait_so_far <= 98050039) {

                                if (parameters.total_wait_locks <= 811) {
                                  return payment_LM125(parameters);
                                } else {
                                  return payment_LM126(parameters);
                                }
                              } else {
                                return payment_LM127(parameters);
                              }
                            }
                          } else {
                            return payment_LM128(parameters);
                          }
                        } else {
                          return payment_LM129(parameters);
                        }
                      }
                    } else {

                      if (parameters.avg_latency_of_same_last_20 <= 708833000) {

                        if (parameters.mean_wait_of_all <= 157258000) {
                          return payment_LM130(parameters);
                        } else {
                          return payment_LM131(parameters);
                        }
                      } else {
                        return payment_LM132(parameters);
                      }
                    }
                  } else {

                    if (parameters.mean_wait_of_all <= 161803500) {
                      return payment_LM133(parameters);
                    } else {

                      if (parameters.wait_so_far <= 219825965.5) {

                        if (parameters.avg_wait_of_same_past_second <= 542159500) {
                          return payment_LM134(parameters);
                        } else {
                          return payment_LM135(parameters);
                        }
                      } else {

                        if (parameters.max_latency_of_same_last_50 <= 1775665000) {
                          return payment_LM136(parameters);
                        } else {
                          return payment_LM137(parameters);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        } else {
          return payment_LM138(parameters);
        }
      }
    }
  }
}
static
double
stock_level_LM1(work_wait &parameters) {
  double actual_remaining = 
	-0.0899 * parameters.wait_so_far 
	+ 44696781.9432;
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
	-0.079 * parameters.wait_so_far 
	+ 120628.9092 * parameters.total_wait_locks 
	- 0.0938 * parameters.mean_wait_of_all 
	+ 1.0197 * parameters.avg_work_of_same_past_second 
	- 0.2415 * parameters.avg_wait_of_same_past_second 
	+ 0.1021 * parameters.avg_latency_of_same_last_20 
	+ 30129914.4394;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
tpcc_estimate(work_wait &parameters){
  return tpcc_LM1(parameters);
}