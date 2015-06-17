#include "my_global.h"
#include "m5p.h"

static
double
new_order_LM1(work_wait &parameters) {
  double actual_remaining = 
	1739.6794 * parameters.work_so_far 
	- 53947.9994 * parameters.num_locks_so_far 
	+ 4132964.2055 * parameters.num_of_wait_locks 
	+ 208710.3876 * parameters.total_wait_locks 
	- 0.0137 * parameters.mean_wait_of_all 
	+ 43692516.5562 * parameters.cpu_usage 
	- 0.044 * parameters.avg_latency_of_same_past_second 
	- 45775117.2954;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM2(work_wait &parameters) {
  double actual_remaining = 
	3.6668 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	- 4182849.6653 * parameters.num_locks_so_far 
	+ 329570.919 * parameters.num_of_wait_locks 
	+ 315601.8101 * parameters.total_wait_locks 
	- 0.3886 * parameters.mean_wait_of_all 
	- 93377610.6288 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_latency_of_same_past_second 
	+ 164668357.0916;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM3(work_wait &parameters) {
  double actual_remaining = 
	0.3287 * parameters.work_so_far 
	- 0.007 * parameters.wait_so_far 
	- 244764.4246 * parameters.num_locks_so_far 
	- 1499259.743 * parameters.num_of_wait_locks 
	+ 95365.8979 * parameters.total_wait_locks 
	- 0.0134 * parameters.mean_wait_of_all 
	- 16506960.6615 * parameters.cpu_usage 
	- 0.005 * parameters.avg_latency_of_same_past_second 
	+ 77389873.8942;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM4(work_wait &parameters) {
  double actual_remaining = 
	0.3287 * parameters.work_so_far 
	- 0.3594 * parameters.wait_so_far 
	- 244764.4246 * parameters.num_locks_so_far 
	- 1543706.0083 * parameters.num_of_wait_locks 
	+ 2160281.2935 * parameters.total_wait_locks 
	- 0.0134 * parameters.mean_wait_of_all 
	- 16506960.6615 * parameters.cpu_usage 
	- 0.0298 * parameters.avg_latency_of_same_past_second 
	+ 22111516.4229;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM5(work_wait &parameters) {
  double actual_remaining = 
	0.3287 * parameters.work_so_far 
	- 0.027 * parameters.wait_so_far 
	- 244764.4246 * parameters.num_locks_so_far 
	- 1543706.0083 * parameters.num_of_wait_locks 
	+ 210460.3477 * parameters.total_wait_locks 
	- 0.0134 * parameters.mean_wait_of_all 
	- 16506960.6615 * parameters.cpu_usage 
	+ 0.0508 * parameters.avg_latency_of_same_past_second 
	+ 68147761.9039;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM6(work_wait &parameters) {
  double actual_remaining = 
	4.6102 * parameters.work_so_far 
	- 0.0019 * parameters.wait_so_far 
	- 5808207.8553 * parameters.num_locks_so_far 
	- 32921066.5059 * parameters.num_of_wait_locks 
	+ 36254.8725 * parameters.total_wait_locks 
	- 0.0134 * parameters.mean_wait_of_all 
	- 370578412.7165 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_latency_of_same_past_second 
	+ 569565234.0495;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM7(work_wait &parameters) {
  double actual_remaining = 
	2.6551 * parameters.work_so_far 
	+ 0.9404 * parameters.wait_so_far 
	- 1525880.2968 * parameters.num_locks_so_far 
	- 405786.7038 * parameters.num_of_wait_locks 
	+ 307484.6395 * parameters.total_wait_locks 
	- 0.0134 * parameters.mean_wait_of_all 
	- 9032489.054 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_latency_of_same_past_second 
	+ 44918617.6529;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM8(work_wait &parameters) {
  double actual_remaining = 
	2.8956 * parameters.work_so_far 
	- 2954567.3128 * parameters.num_locks_so_far 
	+ 318443.2702 * parameters.num_of_wait_locks 
	+ 2008470.6245 * parameters.total_wait_locks 
	- 9.3601 * parameters.mean_wait_of_all 
	- 29083943.0121 * parameters.cpu_usage 
	+ 0.0106 * parameters.avg_latency_of_same_past_second 
	+ 310244902.3662;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM9(work_wait &parameters) {
  double actual_remaining = 
	0.3115 * parameters.work_so_far 
	+ 0.376 * parameters.wait_so_far 
	- 60640.6495 * parameters.num_locks_so_far 
	+ 318443.2702 * parameters.num_of_wait_locks 
	+ 117639.7842 * parameters.total_wait_locks 
	- 0.1682 * parameters.mean_wait_of_all 
	- 23687421.5011 * parameters.cpu_usage 
	+ 0.0074 * parameters.avg_latency_of_same_past_second 
	+ 95626688.382;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM10(work_wait &parameters) {
  double actual_remaining = 
	1.5135 * parameters.work_so_far 
	- 60640.6495 * parameters.num_locks_so_far 
	+ 318443.2702 * parameters.num_of_wait_locks 
	+ 145705.5978 * parameters.total_wait_locks 
	+ 5.154 * parameters.mean_wait_of_all 
	- 43278686.6965 * parameters.cpu_usage 
	+ 0.0074 * parameters.avg_latency_of_same_past_second 
	- 76148597.9858;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM11(work_wait &parameters) {
  double actual_remaining = 
	0.2486 * parameters.work_so_far 
	- 60640.6495 * parameters.num_locks_so_far 
	+ 318443.2702 * parameters.num_of_wait_locks 
	- 5527324.1894 * parameters.total_wait_locks 
	+ 0.7569 * parameters.mean_wait_of_all 
	- 536282901.4234 * parameters.cpu_usage 
	+ 0.0074 * parameters.avg_latency_of_same_past_second 
	+ 1088068822.3106;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM12(work_wait &parameters) {
  double actual_remaining = 
	0.7764 * parameters.work_so_far 
	- 0.1944 * parameters.wait_so_far 
	- 1504.0767 * parameters.num_locks_so_far 
	+ 318443.2702 * parameters.num_of_wait_locks 
	+ 1425574.9946 * parameters.total_wait_locks 
	- 2.2398 * parameters.mean_wait_of_all 
	- 324217258.384 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_latency_of_same_past_second 
	+ 479962348.8065;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM13(work_wait &parameters) {
  double actual_remaining = 
	0.6776 * parameters.work_so_far 
	- 0.1266 * parameters.wait_so_far 
	- 6024494.0954 * parameters.num_locks_so_far 
	- 247549.8214 * parameters.num_of_wait_locks 
	+ 1132369.2841 * parameters.total_wait_locks 
	- 3.1976 * parameters.mean_wait_of_all 
	- 394865480.6515 * parameters.cpu_usage 
	+ 0 * parameters.avg_latency_of_same_past_second 
	+ 518326889.285;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM14(work_wait &parameters) {
  double actual_remaining = 
	0.8725 * parameters.work_so_far 
	- 0.0045 * parameters.wait_so_far 
	- 1198822.5806 * parameters.num_locks_so_far 
	- 22342775.6896 * parameters.num_of_wait_locks 
	+ 1589057.3436 * parameters.total_wait_locks 
	- 4.1309 * parameters.mean_wait_of_all 
	- 7860651.6601 * parameters.cpu_usage 
	- 0.0125 * parameters.avg_latency_of_same_past_second 
	+ 145459454.6689;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM15(work_wait &parameters) {
  double actual_remaining = 
	26.4263 * parameters.work_so_far 
	+ 1.4819 * parameters.wait_so_far 
	- 4057515.7844 * parameters.num_locks_so_far 
	- 12487783.4978 * parameters.num_of_wait_locks 
	+ 1182571.1131 * parameters.total_wait_locks 
	- 1.9701 * parameters.mean_wait_of_all 
	- 7860651.6601 * parameters.cpu_usage 
	- 2.1902 * parameters.avg_latency_of_same_past_second 
	+ 476196537.525;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM16(work_wait &parameters) {
  double actual_remaining = 
	0.8725 * parameters.work_so_far 
	- 0.0045 * parameters.wait_so_far 
	- 4057515.7844 * parameters.num_locks_so_far 
	- 11897565.8721 * parameters.num_of_wait_locks 
	+ 1113924.7411 * parameters.total_wait_locks 
	- 6.7167 * parameters.mean_wait_of_all 
	- 7860651.6601 * parameters.cpu_usage 
	- 0.0436 * parameters.avg_latency_of_same_past_second 
	+ 569154479.7723;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM17(work_wait &parameters) {
  double actual_remaining = 
	0.8725 * parameters.work_so_far 
	- 0.0045 * parameters.wait_so_far 
	- 4057515.7844 * parameters.num_locks_so_far 
	- 44393535.5255 * parameters.num_of_wait_locks 
	+ 5247227.6613 * parameters.total_wait_locks 
	- 4.3632 * parameters.mean_wait_of_all 
	- 7860651.6601 * parameters.cpu_usage 
	- 0.0436 * parameters.avg_latency_of_same_past_second 
	- 356291328.6977;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM18(work_wait &parameters) {
  double actual_remaining = 
	0.8725 * parameters.work_so_far 
	- 0.0045 * parameters.wait_so_far 
	- 33041571.6313 * parameters.num_locks_so_far 
	- 24316172.0023 * parameters.num_of_wait_locks 
	+ 131371.9912 * parameters.total_wait_locks 
	+ 4.1129 * parameters.mean_wait_of_all 
	- 7860651.6601 * parameters.cpu_usage 
	- 0.0186 * parameters.avg_latency_of_same_past_second 
	+ 339784115.429;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM19(work_wait &parameters) {
  double actual_remaining = 
	1.8039 * parameters.work_so_far 
	- 0.1541 * parameters.wait_so_far 
	- 808486.7611 * parameters.num_locks_so_far 
	- 318981.3919 * parameters.num_of_wait_locks 
	+ 27171.3577 * parameters.total_wait_locks 
	- 0.1379 * parameters.mean_wait_of_all 
	- 352828698.0295 * parameters.cpu_usage 
	+ 0.1687 * parameters.avg_latency_of_same_past_second 
	+ 489744424.4425;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM20(work_wait &parameters) {
  double actual_remaining = 
	-13.098 * parameters.work_so_far 
	- 0.0071 * parameters.wait_so_far 
	- 1934746.6298 * parameters.num_locks_so_far 
	+ 1769001.7222 * parameters.num_of_wait_locks 
	- 89407.6043 * parameters.total_wait_locks 
	- 0.4811 * parameters.mean_wait_of_all 
	- 109286447.2152 * parameters.cpu_usage 
	+ 0.0297 * parameters.avg_latency_of_same_past_second 
	+ 256194405.2831;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM21(work_wait &parameters) {
  double actual_remaining = 
	6.1505 * parameters.work_so_far 
	- 0.0071 * parameters.wait_so_far 
	- 1934746.6298 * parameters.num_locks_so_far 
	+ 1769001.7222 * parameters.num_of_wait_locks 
	- 171816.8705 * parameters.total_wait_locks 
	- 0.4811 * parameters.mean_wait_of_all 
	- 133455540.6076 * parameters.cpu_usage 
	+ 0.0462 * parameters.avg_latency_of_same_past_second 
	+ 271866469.7023;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM22(work_wait &parameters) {
  double actual_remaining = 
	10.9504 * parameters.work_so_far 
	+ 0.0029 * parameters.wait_so_far 
	+ 656989.5978 * parameters.num_locks_so_far 
	- 8097162.3623 * parameters.num_of_wait_locks 
	- 339423.9565 * parameters.total_wait_locks 
	- 0.5806 * parameters.mean_wait_of_all 
	- 775549965.3665 * parameters.cpu_usage 
	+ 4.2125 * parameters.avg_latency_of_same_past_second 
	+ 634422239.5309;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM23(work_wait &parameters) {
  double actual_remaining = 
	10.9504 * parameters.work_so_far 
	+ 0.0029 * parameters.wait_so_far 
	+ 656989.5978 * parameters.num_locks_so_far 
	- 8097162.3623 * parameters.num_of_wait_locks 
	- 339423.9565 * parameters.total_wait_locks 
	- 0.5806 * parameters.mean_wait_of_all 
	- 504840604.1716 * parameters.cpu_usage 
	+ 0.0065 * parameters.avg_latency_of_same_past_second 
	+ 787796368.6438;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM24(work_wait &parameters) {
  double actual_remaining = 
	23.7291 * parameters.work_so_far 
	+ 0.0029 * parameters.wait_so_far 
	+ 656989.5978 * parameters.num_locks_so_far 
	- 29524295.7158 * parameters.num_of_wait_locks 
	- 94351.9509 * parameters.total_wait_locks 
	- 0.5806 * parameters.mean_wait_of_all 
	- 133731069.0032 * parameters.cpu_usage 
	+ 0.0065 * parameters.avg_latency_of_same_past_second 
	+ 423088003.7913;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM25(work_wait &parameters) {
  double actual_remaining = 
	54.759 * parameters.work_so_far 
	+ 0.6693 * parameters.wait_so_far 
	+ 4979851.2215 * parameters.num_locks_so_far 
	- 45960480.9065 * parameters.num_of_wait_locks 
	+ 27171.3577 * parameters.total_wait_locks 
	- 1.1056 * parameters.mean_wait_of_all 
	- 154785214.5914 * parameters.cpu_usage 
	+ 0.1784 * parameters.avg_latency_of_same_past_second 
	+ 254048390.4736;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM26(work_wait &parameters) {
  double actual_remaining = 
	1819.6317 * parameters.work_so_far 
	+ 13.8873 * parameters.wait_so_far 
	- 855756.6791 * parameters.num_locks_so_far 
	+ 1836373.6968 * parameters.num_of_wait_locks 
	+ 361666.6557 * parameters.total_wait_locks 
	- 0.901 * parameters.mean_wait_of_all 
	- 309714.9685 * parameters.cpu_usage 
	- 0.0005 * parameters.avg_latency_of_same_past_second 
	+ 159563494.739;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM27(work_wait &parameters) {
  double actual_remaining = 
	3716.1459 * parameters.work_so_far 
	+ 127114.99 * parameters.wait_so_far 
	- 855756.6791 * parameters.num_locks_so_far 
	+ 1836373.6968 * parameters.num_of_wait_locks 
	+ 361666.6557 * parameters.total_wait_locks 
	- 10.8045 * parameters.mean_wait_of_all 
	- 309714.9685 * parameters.cpu_usage 
	- 0.0005 * parameters.avg_latency_of_same_past_second 
	- 482509675.1245;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM28(work_wait &parameters) {
  double actual_remaining = 
	3716.1459 * parameters.work_so_far 
	+ 142627.2939 * parameters.wait_so_far 
	- 855756.6791 * parameters.num_locks_so_far 
	+ 1836373.6968 * parameters.num_of_wait_locks 
	+ 361666.6557 * parameters.total_wait_locks 
	- 9.8142 * parameters.mean_wait_of_all 
	- 309714.9685 * parameters.cpu_usage 
	- 0.0005 * parameters.avg_latency_of_same_past_second 
	- 735818732.0009;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM29(work_wait &parameters) {
  double actual_remaining = 
	3716.1459 * parameters.work_so_far 
	- 135.5826 * parameters.wait_so_far 
	- 855756.6791 * parameters.num_locks_so_far 
	+ 1836373.6968 * parameters.num_of_wait_locks 
	+ 361666.6557 * parameters.total_wait_locks 
	- 5.6961 * parameters.mean_wait_of_all 
	- 309714.9685 * parameters.cpu_usage 
	- 0.0005 * parameters.avg_latency_of_same_past_second 
	+ 360960054.0124;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM30(work_wait &parameters) {
  double actual_remaining = 
	0.5263 * parameters.work_so_far 
	+ 5154.887 * parameters.wait_so_far 
	- 3461221.5764 * parameters.num_locks_so_far 
	+ 715650.4769 * parameters.num_of_wait_locks 
	+ 487818.0817 * parameters.total_wait_locks 
	- 1.3639 * parameters.mean_wait_of_all 
	- 309714.9685 * parameters.cpu_usage 
	- 0.0005 * parameters.avg_latency_of_same_past_second 
	+ 123577860.0106;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM31(work_wait &parameters) {
  double actual_remaining = 
	58.0791 * parameters.work_so_far 
	+ 24.3061 * parameters.wait_so_far 
	- 2761767.9127 * parameters.num_locks_so_far 
	+ 715650.4769 * parameters.num_of_wait_locks 
	+ 431373.6918 * parameters.total_wait_locks 
	- 1.1608 * parameters.mean_wait_of_all 
	- 309714.9685 * parameters.cpu_usage 
	- 0.4766 * parameters.avg_latency_of_same_past_second 
	+ 422828621.0723;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM32(work_wait &parameters) {
  double actual_remaining = 
	0.5263 * parameters.work_so_far 
	- 281.4919 * parameters.wait_so_far 
	- 855756.6791 * parameters.num_locks_so_far 
	- 98427624.1825 * parameters.num_of_wait_locks 
	+ 8764164.2869 * parameters.total_wait_locks 
	- 0.2803 * parameters.mean_wait_of_all 
	- 309714.9685 * parameters.cpu_usage 
	- 0.0005 * parameters.avg_latency_of_same_past_second 
	- 1787763977.2163;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM33(work_wait &parameters) {
  double actual_remaining = 
	-42.9266 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	- 855756.6791 * parameters.num_locks_so_far 
	- 36297006.6971 * parameters.num_of_wait_locks 
	+ 194188.2526 * parameters.total_wait_locks 
	+ 11.5542 * parameters.mean_wait_of_all 
	- 309714.9685 * parameters.cpu_usage 
	- 0.0005 * parameters.avg_latency_of_same_past_second 
	- 513132170.4427;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM34(work_wait &parameters) {
  double actual_remaining = 
	0.9167 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	- 1353807.1568 * parameters.num_locks_so_far 
	- 14824260.7384 * parameters.num_of_wait_locks 
	+ 31545.7686 * parameters.total_wait_locks 
	- 0.1104 * parameters.mean_wait_of_all 
	- 309714.9685 * parameters.cpu_usage 
	- 0.0049 * parameters.avg_latency_of_same_past_second 
	+ 290523045.4113;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM35(work_wait &parameters) {
  double actual_remaining = 
	14.0782 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	- 28562600.3471 * parameters.num_locks_so_far 
	- 10466036.1593 * parameters.num_of_wait_locks 
	+ 20190.1076 * parameters.total_wait_locks 
	- 0.0601 * parameters.mean_wait_of_all 
	- 309714.9685 * parameters.cpu_usage 
	- 0.2572 * parameters.avg_latency_of_same_past_second 
	+ 541196419.7133;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM36(work_wait &parameters) {
  double actual_remaining = 
	0.1876 * parameters.work_so_far 
	+ 0.0132 * parameters.wait_so_far 
	- 383860.5432 * parameters.num_locks_so_far 
	- 29368283.3356 * parameters.num_of_wait_locks 
	+ 3482530.7301 * parameters.total_wait_locks 
	- 15.9482 * parameters.mean_wait_of_all 
	+ 1339023.1899 * parameters.cpu_usage 
	+ 0.0494 * parameters.avg_latency_of_same_past_second 
	+ 551542479.8468;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM37(work_wait &parameters) {
  double actual_remaining = 
	0.1876 * parameters.work_so_far 
	+ 0.0132 * parameters.wait_so_far 
	- 383860.5432 * parameters.num_locks_so_far 
	- 2133781.845 * parameters.num_of_wait_locks 
	+ 207102.2368 * parameters.total_wait_locks 
	- 0.8618 * parameters.mean_wait_of_all 
	+ 1339023.1899 * parameters.cpu_usage 
	+ 0.1037 * parameters.avg_latency_of_same_past_second 
	+ 477140259.0926;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM38(work_wait &parameters) {
  double actual_remaining = 
	-3162.289 * parameters.work_so_far 
	+ 0.0132 * parameters.wait_so_far 
	- 383860.5432 * parameters.num_locks_so_far 
	- 2133781.845 * parameters.num_of_wait_locks 
	+ 207102.2368 * parameters.total_wait_locks 
	- 0.8618 * parameters.mean_wait_of_all 
	+ 1339023.1899 * parameters.cpu_usage 
	+ 3.9637 * parameters.avg_latency_of_same_past_second 
	- 1189353932.4621;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM39(work_wait &parameters) {
  double actual_remaining = 
	0.1876 * parameters.work_so_far 
	+ 0.5768 * parameters.wait_so_far 
	- 383860.5432 * parameters.num_locks_so_far 
	- 523569.1064 * parameters.num_of_wait_locks 
	+ 22071.3536 * parameters.total_wait_locks 
	- 0.0704 * parameters.mean_wait_of_all 
	+ 1339023.1899 * parameters.cpu_usage 
	- 0.0036 * parameters.avg_latency_of_same_past_second 
	+ 243817951.9997;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM40(work_wait &parameters) {
  double actual_remaining = 
	-1.1488 * parameters.work_so_far 
	+ 0.0367 * parameters.wait_so_far 
	- 1675113.3843 * parameters.num_locks_so_far 
	- 1983349.2137 * parameters.num_of_wait_locks 
	- 5022930.6417 * parameters.total_wait_locks 
	+ 19.0092 * parameters.mean_wait_of_all 
	+ 499921450.0139 * parameters.cpu_usage 
	- 0.0006 * parameters.avg_latency_of_same_past_second 
	+ 85656957.9349;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM41(work_wait &parameters) {
  double actual_remaining = 
	1.1974 * parameters.work_so_far 
	+ 0.0172 * parameters.wait_so_far 
	- 2504639.0323 * parameters.num_locks_so_far 
	- 3085274.129 * parameters.num_of_wait_locks 
	+ 661456.3706 * parameters.total_wait_locks 
	- 3.1835 * parameters.mean_wait_of_all 
	- 89874615.8214 * parameters.cpu_usage 
	- 0.6644 * parameters.avg_latency_of_same_past_second 
	+ 796819868.9699;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM42(work_wait &parameters) {
  double actual_remaining = 
	-628.0691 * parameters.work_so_far 
	+ 3.1576 * parameters.wait_so_far 
	- 2504639.0323 * parameters.num_locks_so_far 
	- 3085274.129 * parameters.num_of_wait_locks 
	+ 661456.3706 * parameters.total_wait_locks 
	- 3.1835 * parameters.mean_wait_of_all 
	- 89874615.8214 * parameters.cpu_usage 
	- 0.0758 * parameters.avg_latency_of_same_past_second 
	+ 839101781.456;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM43(work_wait &parameters) {
  double actual_remaining = 
	1.1974 * parameters.work_so_far 
	+ 1.6702 * parameters.wait_so_far 
	- 2504639.0323 * parameters.num_locks_so_far 
	- 3085274.129 * parameters.num_of_wait_locks 
	+ 661456.3706 * parameters.total_wait_locks 
	- 3.1835 * parameters.mean_wait_of_all 
	- 89874615.8214 * parameters.cpu_usage 
	- 1.5429 * parameters.avg_latency_of_same_past_second 
	+ 1415747619.0906;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM44(work_wait &parameters) {
  double actual_remaining = 
	1.1974 * parameters.work_so_far 
	+ 1.6702 * parameters.wait_so_far 
	- 2504639.0323 * parameters.num_locks_so_far 
	- 3085274.129 * parameters.num_of_wait_locks 
	+ 661456.3706 * parameters.total_wait_locks 
	- 3.1835 * parameters.mean_wait_of_all 
	- 89874615.8214 * parameters.cpu_usage 
	- 1.5429 * parameters.avg_latency_of_same_past_second 
	+ 1386118299.8998;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM45(work_wait &parameters) {
  double actual_remaining = 
	-316.6033 * parameters.work_so_far 
	+ 0.0172 * parameters.wait_so_far 
	- 2504639.0323 * parameters.num_locks_so_far 
	- 3085274.129 * parameters.num_of_wait_locks 
	+ 559662.6317 * parameters.total_wait_locks 
	- 2.65 * parameters.mean_wait_of_all 
	- 66672325.5585 * parameters.cpu_usage 
	- 0.0579 * parameters.avg_latency_of_same_past_second 
	+ 562693892.9192;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM46(work_wait &parameters) {
  double actual_remaining = 
	44.0328 * parameters.work_so_far 
	+ 0.0172 * parameters.wait_so_far 
	- 22176562.4896 * parameters.num_locks_so_far 
	- 29055843.4888 * parameters.num_of_wait_locks 
	+ 2403045.8524 * parameters.total_wait_locks 
	- 8.8423 * parameters.mean_wait_of_all 
	+ 380898305.2116 * parameters.cpu_usage 
	+ 0.1874 * parameters.avg_latency_of_same_past_second 
	- 118590519.4337;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM47(work_wait &parameters) {
  double actual_remaining = 
	0.4876 * parameters.work_so_far 
	- 0.1048 * parameters.wait_so_far 
	- 195705.1669 * parameters.num_locks_so_far 
	- 15704720.9299 * parameters.num_of_wait_locks 
	+ 4520.5127 * parameters.total_wait_locks 
	+ 0.0011 * parameters.mean_wait_of_all 
	- 309714.9685 * parameters.cpu_usage 
	+ 0 * parameters.avg_latency_of_same_past_second 
	+ 286292154.1306;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM48(work_wait &parameters) {
  double actual_remaining = 
	1.4377 * parameters.work_so_far 
	- 0.001 * parameters.wait_so_far 
	- 29221067.9554 * parameters.num_locks_so_far 
	+ 658213.718 * parameters.num_of_wait_locks 
	- 165715.1727 * parameters.total_wait_locks 
	+ 0.0869 * parameters.mean_wait_of_all 
	- 309714.9685 * parameters.cpu_usage 
	+ 0 * parameters.avg_latency_of_same_past_second 
	+ 420238825.865;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM49(work_wait &parameters) {
  double actual_remaining = 
	1.0716 * parameters.work_so_far 
	+ 0.0014 * parameters.wait_so_far 
	+ 199857.1697 * parameters.num_locks_so_far 
	- 50524266.622 * parameters.num_of_wait_locks 
	+ 413154.5165 * parameters.total_wait_locks 
	- 0.0143 * parameters.mean_wait_of_all 
	- 309714.9685 * parameters.cpu_usage 
	+ 0 * parameters.avg_latency_of_same_past_second 
	+ 299606779.176;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM50(work_wait &parameters) {
  double actual_remaining = 
	1.6253 * parameters.work_so_far 
	+ 0.7989 * parameters.wait_so_far 
	- 8685672.2475 * parameters.num_locks_so_far 
	- 2646168.2885 * parameters.num_of_wait_locks 
	+ 80023.5952 * parameters.total_wait_locks 
	+ 0.911 * parameters.mean_wait_of_all 
	- 309714.9685 * parameters.cpu_usage 
	+ 0 * parameters.avg_latency_of_same_past_second 
	+ 171855655.5512;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM51(work_wait &parameters) {
  double actual_remaining = 
	0.2448 * parameters.work_so_far 
	+ 0.6086 * parameters.wait_so_far 
	+ 1721179.4689 * parameters.num_locks_so_far 
	- 22433162.1702 * parameters.num_of_wait_locks 
	+ 206484.7923 * parameters.total_wait_locks 
	- 0.6078 * parameters.mean_wait_of_all 
	- 62384832.4226 * parameters.cpu_usage 
	+ 0.0141 * parameters.avg_latency_of_same_past_second 
	+ 428866311.1051;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM52(work_wait &parameters) {
  double actual_remaining = 
	0.2448 * parameters.work_so_far 
	- 0.0495 * parameters.wait_so_far 
	+ 18356280.5358 * parameters.num_locks_so_far 
	+ 123451.8949 * parameters.num_of_wait_locks 
	+ 291572.8086 * parameters.total_wait_locks 
	- 0.9334 * parameters.mean_wait_of_all 
	- 95386581.1768 * parameters.cpu_usage 
	+ 0.0141 * parameters.avg_latency_of_same_past_second 
	+ 243239868.7715;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM53(work_wait &parameters) {
  double actual_remaining = 
	0.2448 * parameters.work_so_far 
	- 0.4545 * parameters.wait_so_far 
	+ 4711035.7488 * parameters.num_locks_so_far 
	+ 14389146.0075 * parameters.num_of_wait_locks 
	+ 428372.7097 * parameters.total_wait_locks 
	- 1.8541 * parameters.mean_wait_of_all 
	- 295763756.3609 * parameters.cpu_usage 
	+ 0.0141 * parameters.avg_latency_of_same_past_second 
	+ 462873088.1919;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM54(work_wait &parameters) {
  double actual_remaining = 
	0.2448 * parameters.work_so_far 
	- 0.0792 * parameters.wait_so_far 
	+ 37443506.2832 * parameters.num_locks_so_far 
	+ 9983564.0021 * parameters.num_of_wait_locks 
	+ 349932.0706 * parameters.total_wait_locks 
	- 0.4651 * parameters.mean_wait_of_all 
	- 49372911.2452 * parameters.cpu_usage 
	+ 0.0141 * parameters.avg_latency_of_same_past_second 
	+ 60083986.324;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM55(work_wait &parameters) {
  double actual_remaining = 
	0.2448 * parameters.work_so_far 
	+ 0.0452 * parameters.wait_so_far 
	+ 1538939.2599 * parameters.num_locks_so_far 
	+ 20091467.1639 * parameters.num_of_wait_locks 
	+ 768086.9226 * parameters.total_wait_locks 
	- 0.3627 * parameters.mean_wait_of_all 
	+ 137907074.4805 * parameters.cpu_usage 
	- 0.3137 * parameters.avg_latency_of_same_past_second 
	+ 39203732.3111;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM56(work_wait &parameters) {
  double actual_remaining = 
	0.2448 * parameters.work_so_far 
	+ 0.0989 * parameters.wait_so_far 
	+ 1538939.2599 * parameters.num_locks_so_far 
	+ 94788487.4063 * parameters.num_of_wait_locks 
	+ 390499.8693 * parameters.total_wait_locks 
	- 0.7279 * parameters.mean_wait_of_all 
	+ 1144082466.5254 * parameters.cpu_usage 
	- 0.7122 * parameters.avg_latency_of_same_past_second 
	- 776979126.724;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM57(work_wait &parameters) {
  double actual_remaining = 
	0.2448 * parameters.work_so_far 
	- 0.3128 * parameters.wait_so_far 
	+ 15814112.1752 * parameters.num_locks_so_far 
	+ 76022828.2746 * parameters.num_of_wait_locks 
	+ 390499.8693 * parameters.total_wait_locks 
	- 0.7279 * parameters.mean_wait_of_all 
	+ 903820544.3235 * parameters.cpu_usage 
	- 0.7122 * parameters.avg_latency_of_same_past_second 
	- 391591364.1036;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM58(work_wait &parameters) {
  double actual_remaining = 
	0.2448 * parameters.work_so_far 
	- 0.2212 * parameters.wait_so_far 
	+ 1609411.0043 * parameters.num_locks_so_far 
	- 41437871.4447 * parameters.num_of_wait_locks 
	+ 2548725.6928 * parameters.total_wait_locks 
	- 5.2642 * parameters.mean_wait_of_all 
	+ 5148550.6894 * parameters.cpu_usage 
	+ 0.0345 * parameters.avg_latency_of_same_past_second 
	+ 135107341.7745;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM59(work_wait &parameters) {
  double actual_remaining = 
	0.2448 * parameters.work_so_far 
	- 0.0351 * parameters.wait_so_far 
	+ 2244318.554 * parameters.num_locks_so_far 
	+ 318635686.2271 * parameters.num_of_wait_locks 
	+ 30826.053 * parameters.total_wait_locks 
	- 0.0194 * parameters.mean_wait_of_all 
	+ 5148550.6894 * parameters.cpu_usage 
	+ 0.0345 * parameters.avg_latency_of_same_past_second 
	- 163706461.5238;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM60(work_wait &parameters) {
  double actual_remaining = 
	0.2448 * parameters.work_so_far 
	- 0.011 * parameters.wait_so_far 
	+ 27654340.0735 * parameters.num_locks_so_far 
	+ 123451.8949 * parameters.num_of_wait_locks 
	+ 1629744.1192 * parameters.total_wait_locks 
	- 3.1332 * parameters.mean_wait_of_all 
	+ 11577625.1547 * parameters.cpu_usage 
	+ 0.0339 * parameters.avg_latency_of_same_past_second 
	- 123908791.5852;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM61(work_wait &parameters) {
  double actual_remaining = 
	17.9486 * parameters.work_so_far 
	+ 0.6683 * parameters.wait_so_far 
	- 300158.4627 * parameters.num_locks_so_far 
	+ 36523964.031 * parameters.num_of_wait_locks 
	- 575826.5356 * parameters.total_wait_locks 
	+ 2.1869 * parameters.mean_wait_of_all 
	- 738312.6765 * parameters.cpu_usage 
	+ 0.0075 * parameters.avg_latency_of_same_past_second 
	+ 816142.5083;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM62(work_wait &parameters) {
  double actual_remaining = 
	5.4406 * parameters.work_so_far 
	- 0.4379 * parameters.wait_so_far 
	+ 368663.421 * parameters.num_locks_so_far 
	- 71744696.8051 * parameters.num_of_wait_locks 
	+ 2623055.9862 * parameters.total_wait_locks 
	- 7.8496 * parameters.mean_wait_of_all 
	- 16278082.6589 * parameters.cpu_usage 
	+ 0.0027 * parameters.avg_latency_of_same_past_second 
	+ 317065577.7631;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM63(work_wait &parameters) {
  double actual_remaining = 
	0.2301 * parameters.work_so_far 
	+ 0.0312 * parameters.wait_so_far 
	- 12413500.1196 * parameters.num_locks_so_far 
	+ 13009388.0988 * parameters.num_of_wait_locks 
	+ 1311959.5023 * parameters.total_wait_locks 
	- 2.8605 * parameters.mean_wait_of_all 
	- 9984041.7442 * parameters.cpu_usage 
	- 0.4838 * parameters.avg_latency_of_same_past_second 
	+ 557132114.2698;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM64(work_wait &parameters) {
  double actual_remaining = 
	0.2301 * parameters.work_so_far 
	- 0.5472 * parameters.wait_so_far 
	- 155206.941 * parameters.num_locks_so_far 
	+ 30295137.7976 * parameters.num_of_wait_locks 
	+ 1749495.651 * parameters.total_wait_locks 
	- 4.553 * parameters.mean_wait_of_all 
	- 9984041.7442 * parameters.cpu_usage 
	+ 0.0027 * parameters.avg_latency_of_same_past_second 
	+ 169140757.4769;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM65(work_wait &parameters) {
  double actual_remaining = 
	0.2301 * parameters.work_so_far 
	+ 0.4779 * parameters.wait_so_far 
	- 6823797.3806 * parameters.num_locks_so_far 
	+ 14597702.0294 * parameters.num_of_wait_locks 
	+ 1709604.7228 * parameters.total_wait_locks 
	- 4.3707 * parameters.mean_wait_of_all 
	- 9984041.7442 * parameters.cpu_usage 
	+ 0.0027 * parameters.avg_latency_of_same_past_second 
	+ 354414308.5098;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM66(work_wait &parameters) {
  double actual_remaining = 
	7.5062 * parameters.work_so_far 
	+ 0.911 * parameters.wait_so_far 
	- 7807369.5755 * parameters.num_locks_so_far 
	+ 15372362.067 * parameters.num_of_wait_locks 
	+ 11182.5991 * parameters.total_wait_locks 
	- 0.0099 * parameters.mean_wait_of_all 
	- 738312.6765 * parameters.cpu_usage 
	+ 0 * parameters.avg_latency_of_same_past_second 
	+ 178764640.9459;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM67(work_wait &parameters) {
  double actual_remaining = 
	0.019 * parameters.work_so_far 
	- 0.0107 * parameters.wait_so_far 
	- 86964.2283 * parameters.num_locks_so_far 
	- 28594554.7725 * parameters.num_of_wait_locks 
	+ 1674067.786 * parameters.total_wait_locks 
	- 3.2486 * parameters.mean_wait_of_all 
	- 193807702.3254 * parameters.cpu_usage 
	- 0.2171 * parameters.avg_latency_of_same_past_second 
	+ 587914917.6839;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM68(work_wait &parameters) {
  double actual_remaining = 
	0.019 * parameters.work_so_far 
	- 0.0495 * parameters.wait_so_far 
	+ 3481345.7888 * parameters.num_locks_so_far 
	+ 5007220.4977 * parameters.num_of_wait_locks 
	- 531648.9519 * parameters.total_wait_locks 
	+ 2.6083 * parameters.mean_wait_of_all 
	- 26087939.4973 * parameters.cpu_usage 
	- 0.023 * parameters.avg_latency_of_same_past_second 
	+ 273152133.7906;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM69(work_wait &parameters) {
  double actual_remaining = 
	0.019 * parameters.work_so_far 
	- 0.5894 * parameters.wait_so_far 
	+ 4388856.5866 * parameters.num_locks_so_far 
	- 12475394.9046 * parameters.num_of_wait_locks 
	- 263471.6552 * parameters.total_wait_locks 
	+ 2.1966 * parameters.mean_wait_of_all 
	- 1228486656.7478 * parameters.cpu_usage 
	+ 0.2898 * parameters.avg_latency_of_same_past_second 
	+ 1439311656.737;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM70(work_wait &parameters) {
  double actual_remaining = 
	0.019 * parameters.work_so_far 
	+ 0.7594 * parameters.wait_so_far 
	+ 4779161.8351 * parameters.num_locks_so_far 
	- 14926076.3712 * parameters.num_of_wait_locks 
	- 263471.6552 * parameters.total_wait_locks 
	+ 5.0043 * parameters.mean_wait_of_all 
	- 199745356.2277 * parameters.cpu_usage 
	- 0.023 * parameters.avg_latency_of_same_past_second 
	+ 281534230.2172;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM71(work_wait &parameters) {
  double actual_remaining = 
	0.9253 * parameters.work_so_far 
	+ 0.7309 * parameters.wait_so_far 
	- 1903780.8847 * parameters.num_locks_so_far 
	+ 24027656.8522 * parameters.num_of_wait_locks 
	+ 346159.8975 * parameters.total_wait_locks 
	- 0.0121 * parameters.mean_wait_of_all 
	- 5271758.9973 * parameters.cpu_usage 
	- 0.155 * parameters.avg_latency_of_same_past_second 
	+ 223307946.2818;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM72(work_wait &parameters) {
  double actual_remaining = 
	-0.501 * parameters.work_so_far 
	+ 0.0072 * parameters.wait_so_far 
	- 86568.1981 * parameters.num_locks_so_far 
	+ 123451.8949 * parameters.num_of_wait_locks 
	+ 29034.0738 * parameters.total_wait_locks 
	+ 3.9953 * parameters.mean_wait_of_all 
	- 6514824.0647 * parameters.cpu_usage 
	- 0.0053 * parameters.avg_latency_of_same_past_second 
	+ 528575643.4864;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM73(work_wait &parameters) {
  double actual_remaining = 
	0.6686 * parameters.work_so_far 
	+ 0.4072 * parameters.wait_so_far 
	- 86568.1981 * parameters.num_locks_so_far 
	+ 123451.8949 * parameters.num_of_wait_locks 
	+ 29034.0738 * parameters.total_wait_locks 
	+ 1.2145 * parameters.mean_wait_of_all 
	- 6514824.0647 * parameters.cpu_usage 
	- 0.0053 * parameters.avg_latency_of_same_past_second 
	+ 276543168.0182;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM74(work_wait &parameters) {
  double actual_remaining = 
	0.0105 * parameters.work_so_far 
	- 0.0221 * parameters.wait_so_far 
	+ 715518.9945 * parameters.num_locks_so_far 
	+ 4659812.9083 * parameters.num_of_wait_locks 
	- 38104.0191 * parameters.total_wait_locks 
	+ 1.3593 * parameters.mean_wait_of_all 
	+ 6592769.4259 * parameters.cpu_usage 
	+ 0.0103 * parameters.avg_latency_of_same_past_second 
	+ 21760781.0138;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM75(work_wait &parameters) {
  double actual_remaining = 
	0.0442 * parameters.work_so_far 
	+ 0.0525 * parameters.wait_so_far 
	+ 1009968.925 * parameters.num_locks_so_far 
	- 32810051.4447 * parameters.num_of_wait_locks 
	- 802334.4461 * parameters.total_wait_locks 
	+ 4.1612 * parameters.mean_wait_of_all 
	+ 3000964.2343 * parameters.cpu_usage 
	+ 0.0049 * parameters.avg_latency_of_same_past_second 
	+ 285888849.9575;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM76(work_wait &parameters) {
  double actual_remaining = 
	1.374 * parameters.work_so_far 
	+ 0.1501 * parameters.wait_so_far 
	- 478891.7354 * parameters.num_locks_so_far 
	+ 249923.9485 * parameters.num_of_wait_locks 
	- 1918088.6059 * parameters.total_wait_locks 
	+ 7.3929 * parameters.mean_wait_of_all 
	- 37896530.5452 * parameters.cpu_usage 
	+ 0.0049 * parameters.avg_latency_of_same_past_second 
	+ 850363491.0071;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM77(work_wait &parameters) {
  double actual_remaining = 
	1.9248 * parameters.work_so_far 
	+ 0.9101 * parameters.wait_so_far 
	+ 1621352.3533 * parameters.num_locks_so_far 
	+ 12634515.3967 * parameters.num_of_wait_locks 
	- 1464884.7895 * parameters.total_wait_locks 
	+ 4.947 * parameters.mean_wait_of_all 
	- 170233037.1986 * parameters.cpu_usage 
	+ 0.107 * parameters.avg_latency_of_same_past_second 
	+ 251812916.5084;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM78(work_wait &parameters) {
  double actual_remaining = 
	1.4365 * parameters.work_so_far 
	+ 0.8259 * parameters.wait_so_far 
	- 6408330.1587 * parameters.num_locks_so_far 
	- 26295810.8099 * parameters.num_of_wait_locks 
	- 1968853.2442 * parameters.total_wait_locks 
	+ 7.1615 * parameters.mean_wait_of_all 
	- 15483299.3553 * parameters.cpu_usage 
	+ 0.2786 * parameters.avg_latency_of_same_past_second 
	+ 479426915.4123;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
static
double
new_order_estimate(work_wait &parameters){

  if (parameters.total_wait_locks <= 94.5) {

    if (parameters.work_so_far <= 28374913.5) {

      if (parameters.work_so_far <= 23465.5) {
        return new_order_LM1(parameters);
      } else if (parameters.work_so_far >  23465.5) {

        if (parameters.num_of_wait_locks <= 1.5) {
          return new_order_LM2(parameters);
        } else if (parameters.num_of_wait_locks >  1.5) {

          if (parameters.num_locks_so_far <= 23.5) {

            if (parameters.work_so_far <= 36651.5) {

              if (parameters.total_wait_locks <= 47.5) {
                return new_order_LM3(parameters);
              } else if (parameters.total_wait_locks >  47.5) {

                if (parameters.avg_latency_of_same_past_second <= 78297850) {
                  return new_order_LM4(parameters);
                } else if (parameters.avg_latency_of_same_past_second >  78297850) {
                  return new_order_LM5(parameters);
                }
              }
            } else if (parameters.work_so_far >  36651.5) {
              return new_order_LM6(parameters);
            }
          } else if (parameters.num_locks_so_far >  23.5) {
            return new_order_LM7(parameters);
          }
        }
      }
    } else if (parameters.work_so_far >  28374913.5) {

      if (parameters.work_so_far <= 85944195.5) {

        if (parameters.mean_wait_of_all <= 27427500) {
          return new_order_LM8(parameters);
        } else if (parameters.mean_wait_of_all >  27427500) {

          if (parameters.work_so_far <= 39877780) {
            return new_order_LM9(parameters);
          } else if (parameters.work_so_far >  39877780) {

            if (parameters.total_wait_locks <= 74.5) {
              return new_order_LM10(parameters);
            } else if (parameters.total_wait_locks >  74.5) {
              return new_order_LM11(parameters);
            }
          }
        }
      } else if (parameters.work_so_far >  85944195.5) {
        return new_order_LM12(parameters);
      }
    }
  } else if (parameters.total_wait_locks >  94.5) {

    if (parameters.work_so_far <= 4559141.5) {

      if (parameters.total_wait_locks <= 223.5) {

        if (parameters.total_wait_locks <= 146.5) {
          return new_order_LM13(parameters);
        } else if (parameters.total_wait_locks >  146.5) {

          if (parameters.wait_so_far <= 100907872.5) {

            if (parameters.work_so_far <= 51193.5) {
              return new_order_LM14(parameters);
            } else if (parameters.work_so_far >  51193.5) {

              if (parameters.avg_latency_of_same_past_second <= 203300500) {

                if (parameters.total_wait_locks <= 172.5) {
                  return new_order_LM15(parameters);
                } else if (parameters.total_wait_locks >  172.5) {

                  if (parameters.mean_wait_of_all <= 28758500) {
                    return new_order_LM16(parameters);
                  } else if (parameters.mean_wait_of_all >  28758500) {
                    return new_order_LM17(parameters);
                  }
                }
              } else if (parameters.avg_latency_of_same_past_second >  203300500) {
                return new_order_LM18(parameters);
              }
            }
          } else if (parameters.wait_so_far >  100907872.5) {

            if (parameters.work_so_far <= 102363.5) {
              return new_order_LM19(parameters);
            } else if (parameters.work_so_far >  102363.5) {

              if (parameters.num_of_wait_locks <= 1.5) {

                if (parameters.work_so_far <= 2726024) {
                  return new_order_LM20(parameters);
                } else if (parameters.work_so_far >  2726024) {
                  return new_order_LM21(parameters);
                }
              } else if (parameters.num_of_wait_locks >  1.5) {

                if (parameters.num_locks_so_far <= 4.5) {

                  if (parameters.total_wait_locks <= 170.5) {

                    if (parameters.avg_latency_of_same_past_second <= 143684000) {
                      return new_order_LM22(parameters);
                    } else if (parameters.avg_latency_of_same_past_second >  143684000) {
                      return new_order_LM23(parameters);
                    }
                  } else if (parameters.total_wait_locks >  170.5) {
                    return new_order_LM24(parameters);
                  }
                } else if (parameters.num_locks_so_far >  4.5) {
                  return new_order_LM25(parameters);
                }
              }
            }
          }
        }
      } else if (parameters.total_wait_locks >  223.5) {

        if (parameters.wait_so_far <= 153778519) {

          if (parameters.mean_wait_of_all <= 75469900) {

            if (parameters.wait_so_far <= 1683907) {

              if (parameters.mean_wait_of_all <= 67463300) {

                if (parameters.mean_wait_of_all <= 62393150) {

                  if (parameters.work_so_far <= 51047.5) {

                    if (parameters.work_so_far <= 49029) {
                      return new_order_LM26(parameters);
                    } else if (parameters.work_so_far >  49029) {

                      if (parameters.wait_so_far <= 10778) {

                        if (parameters.mean_wait_of_all <= 56548650) {
                          return new_order_LM27(parameters);
                        } else if (parameters.mean_wait_of_all >  56548650) {
                          return new_order_LM28(parameters);
                        }
                      } else if (parameters.wait_so_far >  10778) {
                        return new_order_LM29(parameters);
                      }
                    }
                  } else if (parameters.work_so_far >  51047.5) {

                    if (parameters.wait_so_far <= 11566) {
                      return new_order_LM30(parameters);
                    } else if (parameters.wait_so_far >  11566) {
                      return new_order_LM31(parameters);
                    }
                  }
                } else if (parameters.mean_wait_of_all >  62393150) {
                  return new_order_LM32(parameters);
                }
              } else if (parameters.mean_wait_of_all >  67463300) {
                return new_order_LM33(parameters);
              }
            } else if (parameters.wait_so_far >  1683907) {

              if (parameters.work_so_far <= 48330) {
                return new_order_LM34(parameters);
              } else if (parameters.work_so_far >  48330) {
                return new_order_LM35(parameters);
              }
            }
          } else if (parameters.mean_wait_of_all >  75469900) {

            if (parameters.work_so_far <= 100394) {

              if (parameters.avg_latency_of_same_past_second <= 449432500) {

                if (parameters.avg_latency_of_same_past_second <= 404048000) {
                  return new_order_LM36(parameters);
                } else if (parameters.avg_latency_of_same_past_second >  404048000) {

                  if (parameters.avg_latency_of_same_past_second <= 408707000) {
                    return new_order_LM37(parameters);
                  } else if (parameters.avg_latency_of_same_past_second >  408707000) {
                    return new_order_LM38(parameters);
                  }
                }
              } else if (parameters.avg_latency_of_same_past_second >  449432500) {
                return new_order_LM39(parameters);
              }
            } else if (parameters.work_so_far >  100394) {

              if (parameters.work_so_far <= 223628.5) {
                return new_order_LM40(parameters);
              } else if (parameters.work_so_far >  223628.5) {

                if (parameters.work_so_far <= 679122.5) {

                  if (parameters.mean_wait_of_all <= 86084550) {

                    if (parameters.work_so_far <= 479866) {
                      return new_order_LM41(parameters);
                    } else if (parameters.work_so_far >  479866) {

                      if (parameters.avg_latency_of_same_past_second <= 505609000) {
                        return new_order_LM42(parameters);
                      } else if (parameters.avg_latency_of_same_past_second >  505609000) {

                        if (parameters.avg_latency_of_same_past_second <= 544915000) {
                          return new_order_LM43(parameters);
                        } else if (parameters.avg_latency_of_same_past_second >  544915000) {
                          return new_order_LM44(parameters);
                        }
                      }
                    }
                  } else if (parameters.mean_wait_of_all >  86084550) {
                    return new_order_LM45(parameters);
                  }
                } else if (parameters.work_so_far >  679122.5) {
                  return new_order_LM46(parameters);
                }
              }
            }
          }
        } else if (parameters.wait_so_far >  153778519) {

          if (parameters.work_so_far <= 89711) {
            return new_order_LM47(parameters);
          } else if (parameters.work_so_far >  89711) {

            if (parameters.num_of_wait_locks <= 1.5) {
              return new_order_LM48(parameters);
            } else if (parameters.num_of_wait_locks >  1.5) {

              if (parameters.num_locks_so_far <= 5.5) {
                return new_order_LM49(parameters);
              } else if (parameters.num_locks_so_far >  5.5) {
                return new_order_LM50(parameters);
              }
            }
          }
        }
      }
    } else if (parameters.work_so_far >  4559141.5) {

      if (parameters.wait_so_far <= 398279629.5) {

        if (parameters.work_so_far <= 36584086.5) {

          if (parameters.num_locks_so_far <= 18.5) {

            if (parameters.work_so_far <= 16696386) {

              if (parameters.num_locks_so_far <= 12.5) {

                if (parameters.total_wait_locks <= 249.5) {

                  if (parameters.wait_so_far <= 133233226.5) {

                    if (parameters.cpu_usage <= 0.977) {
                      return new_order_LM51(parameters);
                    } else if (parameters.cpu_usage >  0.977) {
                      return new_order_LM52(parameters);
                    }
                  } else if (parameters.wait_so_far >  133233226.5) {

                    if (parameters.num_of_wait_locks <= 1.5) {
                      return new_order_LM53(parameters);
                    } else if (parameters.num_of_wait_locks >  1.5) {
                      return new_order_LM54(parameters);
                    }
                  }
                } else if (parameters.total_wait_locks >  249.5) {

                  if (parameters.num_of_wait_locks <= 3.5) {

                    if (parameters.avg_latency_of_same_past_second <= 392658000) {

                      if (parameters.wait_so_far <= 161499545) {
                        return new_order_LM55(parameters);
                      } else if (parameters.wait_so_far >  161499545) {

                        if (parameters.num_of_wait_locks <= 1.5) {
                          return new_order_LM56(parameters);
                        } else if (parameters.num_of_wait_locks >  1.5) {
                          return new_order_LM57(parameters);
                        }
                      }
                    } else if (parameters.avg_latency_of_same_past_second >  392658000) {

                      if (parameters.num_locks_so_far <= 9.5) {
                        return new_order_LM58(parameters);
                      } else if (parameters.num_locks_so_far >  9.5) {
                        return new_order_LM59(parameters);
                      }
                    }
                  } else if (parameters.num_of_wait_locks >  3.5) {
                    return new_order_LM60(parameters);
                  }
                }
              } else if (parameters.num_locks_so_far >  12.5) {
                return new_order_LM61(parameters);
              }
            } else if (parameters.work_so_far >  16696386) {

              if (parameters.num_locks_so_far <= 5.5) {
                return new_order_LM62(parameters);
              } else if (parameters.num_locks_so_far >  5.5) {

                if (parameters.wait_so_far <= 14080366) {
                  return new_order_LM63(parameters);
                } else if (parameters.wait_so_far >  14080366) {

                  if (parameters.num_of_wait_locks <= 1.5) {
                    return new_order_LM64(parameters);
                  } else if (parameters.num_of_wait_locks >  1.5) {
                    return new_order_LM65(parameters);
                  }
                }
              }
            }
          } else if (parameters.num_locks_so_far >  18.5) {
            return new_order_LM66(parameters);
          }
        } else if (parameters.work_so_far >  36584086.5) {

          if (parameters.work_so_far <= 203601915) {

            if (parameters.num_locks_so_far <= 21.5) {

              if (parameters.wait_so_far <= 168541934.5) {
                return new_order_LM67(parameters);
              } else if (parameters.wait_so_far >  168541934.5) {

                if (parameters.num_of_wait_locks <= 1.5) {
                  return new_order_LM68(parameters);
                } else if (parameters.num_of_wait_locks >  1.5) {

                  if (parameters.num_locks_so_far <= 5.5) {
                    return new_order_LM69(parameters);
                  } else if (parameters.num_locks_so_far >  5.5) {
                    return new_order_LM70(parameters);
                  }
                }
              }
            } else if (parameters.num_locks_so_far >  21.5) {
              return new_order_LM71(parameters);
            }
          } else if (parameters.work_so_far >  203601915) {

            if (parameters.num_locks_so_far <= 23.5) {
              return new_order_LM72(parameters);
            } else if (parameters.num_locks_so_far >  23.5) {
              return new_order_LM73(parameters);
            }
          }
        }
      } else if (parameters.wait_so_far >  398279629.5) {

        if (parameters.num_of_wait_locks <= 1.5) {
          return new_order_LM74(parameters);
        } else if (parameters.num_of_wait_locks >  1.5) {

          if (parameters.num_locks_so_far <= 5.5) {
            return new_order_LM75(parameters);
          } else if (parameters.num_locks_so_far >  5.5) {

            if (parameters.wait_so_far <= 760319347.5) {

              if (parameters.num_locks_so_far <= 13.5) {
                return new_order_LM76(parameters);
              } else if (parameters.num_locks_so_far >  13.5) {
                return new_order_LM77(parameters);
              }
            } else if (parameters.wait_so_far >  760319347.5) {
              return new_order_LM78(parameters);
            }
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
	47.5547 * parameters.work_so_far 
	+ 0.0009 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	+ 15071.3078 * parameters.num_of_wait_locks 
	+ 1736.3617 * parameters.total_wait_locks 
	- 0.0017 * parameters.mean_wait_of_all 
	- 107446.0622 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_latency_of_same_past_second 
	+ 4517690.9591;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM2(work_wait &parameters) {
  double actual_remaining = 
	35.4034 * parameters.work_so_far 
	+ 0.0007 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	+ 15071.3078 * parameters.num_of_wait_locks 
	+ 27732.5684 * parameters.total_wait_locks 
	- 0.0017 * parameters.mean_wait_of_all 
	- 107446.0622 * parameters.cpu_usage 
	+ 0.0087 * parameters.avg_latency_of_same_past_second 
	+ 4543897.3446;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM3(work_wait &parameters) {
  double actual_remaining = 
	1293.0171 * parameters.work_so_far 
	+ 0.0227 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	- 2235827.9441 * parameters.num_of_wait_locks 
	+ 2412.1408 * parameters.total_wait_locks 
	- 0.0017 * parameters.mean_wait_of_all 
	- 107446.0622 * parameters.cpu_usage 
	- 0.0003 * parameters.avg_latency_of_same_past_second 
	+ 4687198.3756;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM4(work_wait &parameters) {
  double actual_remaining = 
	818.099 * parameters.work_so_far 
	+ 0.0091 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	- 80479.7099 * parameters.num_of_wait_locks 
	+ 3984.4942 * parameters.total_wait_locks 
	- 15.0823 * parameters.mean_wait_of_all 
	- 107446.0622 * parameters.cpu_usage 
	- 0.0007 * parameters.avg_latency_of_same_past_second 
	+ 435290630.9782;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM5(work_wait &parameters) {
  double actual_remaining = 
	4260.1494 * parameters.work_so_far 
	+ 0.004 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	- 80479.7099 * parameters.num_of_wait_locks 
	+ 3984.4942 * parameters.total_wait_locks 
	- 0.0017 * parameters.mean_wait_of_all 
	- 107446.0622 * parameters.cpu_usage 
	- 0.0007 * parameters.avg_latency_of_same_past_second 
	- 15684062.5125;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM6(work_wait &parameters) {
  double actual_remaining = 
	1483.8093 * parameters.work_so_far 
	+ 0.002 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	+ 45622.4143 * parameters.num_of_wait_locks 
	+ 1636.2765 * parameters.total_wait_locks 
	+ 0.3835 * parameters.mean_wait_of_all 
	+ 1430278.0068 * parameters.cpu_usage 
	- 0.0374 * parameters.avg_latency_of_same_past_second 
	- 15407425.7246;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM7(work_wait &parameters) {
  double actual_remaining = 
	281.7093 * parameters.work_so_far 
	+ 0.0016 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	+ 45622.4143 * parameters.num_of_wait_locks 
	+ 212221.4048 * parameters.total_wait_locks 
	- 1.0089 * parameters.mean_wait_of_all 
	+ 7469672.7027 * parameters.cpu_usage 
	- 0.0074 * parameters.avg_latency_of_same_past_second 
	+ 23092641.4966;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM8(work_wait &parameters) {
  double actual_remaining = 
	899.9727 * parameters.work_so_far 
	+ 0.0016 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	+ 45622.4143 * parameters.num_of_wait_locks 
	- 77939.6251 * parameters.total_wait_locks 
	+ 0.0108 * parameters.mean_wait_of_all 
	+ 7079402.2535 * parameters.cpu_usage 
	- 0.0071 * parameters.avg_latency_of_same_past_second 
	- 923240.8699;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM9(work_wait &parameters) {
  double actual_remaining = 
	681.3401 * parameters.work_so_far 
	+ 0.0016 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	+ 45622.4143 * parameters.num_of_wait_locks 
	- 175891.5215 * parameters.total_wait_locks 
	+ 0.0108 * parameters.mean_wait_of_all 
	+ 7079402.2535 * parameters.cpu_usage 
	- 0.0071 * parameters.avg_latency_of_same_past_second 
	+ 7124651.3438;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM10(work_wait &parameters) {
  double actual_remaining = 
	4057.1601 * parameters.work_so_far 
	+ 0.0016 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	+ 45622.4143 * parameters.num_of_wait_locks 
	+ 1636.2765 * parameters.total_wait_locks 
	+ 0.0108 * parameters.mean_wait_of_all 
	+ 7079402.2535 * parameters.cpu_usage 
	- 0.0247 * parameters.avg_latency_of_same_past_second 
	- 20857550.2738;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM11(work_wait &parameters) {
  double actual_remaining = 
	1823.5033 * parameters.work_so_far 
	+ 0.1648 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	+ 45622.4143 * parameters.num_of_wait_locks 
	+ 556032.4117 * parameters.total_wait_locks 
	+ 0.0108 * parameters.mean_wait_of_all 
	+ 7079402.2535 * parameters.cpu_usage 
	- 0.0247 * parameters.avg_latency_of_same_past_second 
	- 8278197.6366;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM12(work_wait &parameters) {
  double actual_remaining = 
	2213.6251 * parameters.work_so_far 
	+ 0.2231 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	+ 45622.4143 * parameters.num_of_wait_locks 
	+ 620212.323 * parameters.total_wait_locks 
	+ 0.0108 * parameters.mean_wait_of_all 
	+ 7079402.2535 * parameters.cpu_usage 
	- 0.0247 * parameters.avg_latency_of_same_past_second 
	- 14194079.728;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM13(work_wait &parameters) {
  double actual_remaining = 
	1823.5033 * parameters.work_so_far 
	+ 0.2172 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	+ 45622.4143 * parameters.num_of_wait_locks 
	+ 673059.119 * parameters.total_wait_locks 
	+ 0.0108 * parameters.mean_wait_of_all 
	+ 7079402.2535 * parameters.cpu_usage 
	- 0.0247 * parameters.avg_latency_of_same_past_second 
	- 9415842.437;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM14(work_wait &parameters) {
  double actual_remaining = 
	1823.5033 * parameters.work_so_far 
	+ 0.0016 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	+ 45622.4143 * parameters.num_of_wait_locks 
	+ 1636.2765 * parameters.total_wait_locks 
	+ 0.0108 * parameters.mean_wait_of_all 
	+ 7079402.2535 * parameters.cpu_usage 
	- 0.0247 * parameters.avg_latency_of_same_past_second 
	+ 2441633.8634;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM15(work_wait &parameters) {
  double actual_remaining = 
	273.226 * parameters.work_so_far 
	+ 0.0016 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	+ 45622.4143 * parameters.num_of_wait_locks 
	+ 1636.2765 * parameters.total_wait_locks 
	+ 0.0108 * parameters.mean_wait_of_all 
	- 757696416.425 * parameters.cpu_usage 
	- 0.0193 * parameters.avg_latency_of_same_past_second 
	+ 683777138.3899;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM16(work_wait &parameters) {
  double actual_remaining = 
	273.226 * parameters.work_so_far 
	+ 0.0016 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	+ 45622.4143 * parameters.num_of_wait_locks 
	+ 19558.4108 * parameters.total_wait_locks 
	+ 0.0108 * parameters.mean_wait_of_all 
	- 54016132.9241 * parameters.cpu_usage 
	- 0.0268 * parameters.avg_latency_of_same_past_second 
	+ 57647020.4058;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM17(work_wait &parameters) {
  double actual_remaining = 
	273.226 * parameters.work_so_far 
	+ 0.0016 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	+ 45622.4143 * parameters.num_of_wait_locks 
	+ 25383.1045 * parameters.total_wait_locks 
	+ 0.0108 * parameters.mean_wait_of_all 
	- 54016132.9241 * parameters.cpu_usage 
	- 0.0292 * parameters.avg_latency_of_same_past_second 
	+ 60293173.0186;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM18(work_wait &parameters) {
  double actual_remaining = 
	127.0388 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	+ 45622.4143 * parameters.num_of_wait_locks 
	+ 3312.3869 * parameters.total_wait_locks 
	- 0.0017 * parameters.mean_wait_of_all 
	- 1543580.9499 * parameters.cpu_usage 
	+ 7957098.9123;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM19(work_wait &parameters) {
  double actual_remaining = 
	197.2038 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	+ 45622.4143 * parameters.num_of_wait_locks 
	+ 208877.3794 * parameters.total_wait_locks 
	- 0.8238 * parameters.mean_wait_of_all 
	- 1543580.9499 * parameters.cpu_usage 
	+ 23270543.7407;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM20(work_wait &parameters) {
  double actual_remaining = 
	3046.1215 * parameters.work_so_far 
	+ 0.0034 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	- 95940.834 * parameters.num_of_wait_locks 
	+ 861.0841 * parameters.total_wait_locks 
	- 0.0017 * parameters.mean_wait_of_all 
	- 77263213.3802 * parameters.cpu_usage 
	+ 63161358.8399;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM21(work_wait &parameters) {
  double actual_remaining = 
	27.8525 * parameters.work_so_far 
	+ 0.3547 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	- 95940.834 * parameters.num_of_wait_locks 
	+ 861.0841 * parameters.total_wait_locks 
	- 0.0017 * parameters.mean_wait_of_all 
	- 2398157.7828 * parameters.cpu_usage 
	+ 25956383.3869;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM22(work_wait &parameters) {
  double actual_remaining = 
	27.8525 * parameters.work_so_far 
	+ 0.0075 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	- 95940.834 * parameters.num_of_wait_locks 
	- 21926.2082 * parameters.total_wait_locks 
	- 0.0017 * parameters.mean_wait_of_all 
	- 2398157.7828 * parameters.cpu_usage 
	+ 0.2496 * parameters.avg_latency_of_same_past_second 
	+ 18635964.2632;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM23(work_wait &parameters) {
  double actual_remaining = 
	2084.01 * parameters.work_so_far 
	+ 0.0075 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	- 95940.834 * parameters.num_of_wait_locks 
	- 21926.2082 * parameters.total_wait_locks 
	- 0.0017 * parameters.mean_wait_of_all 
	- 2398157.7828 * parameters.cpu_usage 
	+ 0.1296 * parameters.avg_latency_of_same_past_second 
	+ 18689960.9035;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM24(work_wait &parameters) {
  double actual_remaining = 
	21085.3685 * parameters.work_so_far 
	+ 0.0075 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	- 95940.834 * parameters.num_of_wait_locks 
	+ 998864.2842 * parameters.total_wait_locks 
	- 0.0017 * parameters.mean_wait_of_all 
	- 2398157.7828 * parameters.cpu_usage 
	+ 0.1987 * parameters.avg_latency_of_same_past_second 
	- 233418686.6933;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM25(work_wait &parameters) {
  double actual_remaining = 
	4327.0909 * parameters.work_so_far 
	+ 0.0075 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	- 95940.834 * parameters.num_of_wait_locks 
	- 3495627.5263 * parameters.total_wait_locks 
	- 0.0017 * parameters.mean_wait_of_all 
	- 2398157.7828 * parameters.cpu_usage 
	+ 0.1987 * parameters.avg_latency_of_same_past_second 
	+ 104899391.1285;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM26(work_wait &parameters) {
  double actual_remaining = 
	4327.0909 * parameters.work_so_far 
	+ 0.0075 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	- 95940.834 * parameters.num_of_wait_locks 
	- 3495627.5263 * parameters.total_wait_locks 
	- 0.0017 * parameters.mean_wait_of_all 
	- 2398157.7828 * parameters.cpu_usage 
	+ 0.1987 * parameters.avg_latency_of_same_past_second 
	+ 100545619.2326;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM27(work_wait &parameters) {
  double actual_remaining = 
	27.8525 * parameters.work_so_far 
	+ 0.0075 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	- 95940.834 * parameters.num_of_wait_locks 
	- 6600.2417 * parameters.total_wait_locks 
	- 0.0017 * parameters.mean_wait_of_all 
	- 2398157.7828 * parameters.cpu_usage 
	- 0.0698 * parameters.avg_latency_of_same_past_second 
	+ 37688793.7992;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM28(work_wait &parameters) {
  double actual_remaining = 
	1745.2834 * parameters.work_so_far 
	+ 0.0724 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	- 4378691.5315 * parameters.num_of_wait_locks 
	- 80620.3641 * parameters.total_wait_locks 
	- 0.2073 * parameters.mean_wait_of_all 
	- 2236109.7373 * parameters.cpu_usage 
	+ 15233012.5881;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM29(work_wait &parameters) {
  double actual_remaining = 
	1091.024 * parameters.work_so_far 
	+ 0.058 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	- 2161836.301 * parameters.num_of_wait_locks 
	+ 33772.3532 * parameters.total_wait_locks 
	- 0.2073 * parameters.mean_wait_of_all 
	- 2236109.7373 * parameters.cpu_usage 
	+ 22770937.9897;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM30(work_wait &parameters) {
  double actual_remaining = 
	6859.9517 * parameters.work_so_far 
	+ 0.0597 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	- 25468116.1686 * parameters.num_of_wait_locks 
	- 392565.5772 * parameters.total_wait_locks 
	- 0.2073 * parameters.mean_wait_of_all 
	- 2236109.7373 * parameters.cpu_usage 
	+ 80014694.5487;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM31(work_wait &parameters) {
  double actual_remaining = 
	27.8525 * parameters.work_so_far 
	+ 0.0066 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	- 420132.2452 * parameters.num_of_wait_locks 
	+ 249923.8365 * parameters.total_wait_locks 
	- 1.2429 * parameters.mean_wait_of_all 
	- 2236109.7373 * parameters.cpu_usage 
	+ 42877847.0917;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM32(work_wait &parameters) {
  double actual_remaining = 
	27.8525 * parameters.work_so_far 
	+ 0.0073 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	+ 640803.4839 * parameters.num_of_wait_locks 
	+ 10998.7725 * parameters.total_wait_locks 
	- 0.0633 * parameters.mean_wait_of_all 
	- 2236109.7373 * parameters.cpu_usage 
	+ 10041370.7281;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM33(work_wait &parameters) {
  double actual_remaining = 
	27.8525 * parameters.work_so_far 
	+ 0.0073 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	+ 11096271.646 * parameters.num_of_wait_locks 
	+ 10998.7725 * parameters.total_wait_locks 
	- 0.0633 * parameters.mean_wait_of_all 
	- 290739704.3159 * parameters.cpu_usage 
	+ 270150492.4438;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM34(work_wait &parameters) {
  double actual_remaining = 
	27.8525 * parameters.work_so_far 
	+ 0.0073 * parameters.wait_so_far 
	+ 48320.1755 * parameters.num_locks_so_far 
	+ 416662.1327 * parameters.num_of_wait_locks 
	+ 10998.7725 * parameters.total_wait_locks 
	- 0.0633 * parameters.mean_wait_of_all 
	- 209958697.8339 * parameters.cpu_usage 
	+ 220691440.3392;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM35(work_wait &parameters) {
  double actual_remaining = 
	0.0927 * parameters.work_so_far 
	- 0.0547 * parameters.wait_so_far 
	+ 34711.7597 * parameters.num_locks_so_far 
	- 44395.142 * parameters.num_of_wait_locks 
	+ 256879.3216 * parameters.total_wait_locks 
	- 0.0025 * parameters.mean_wait_of_all 
	- 0.0669 * parameters.avg_latency_of_same_past_second 
	+ 33542236.6167;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM36(work_wait &parameters) {
  double actual_remaining = 
	0.2015 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 34711.7597 * parameters.num_locks_so_far 
	+ 7122996.2309 * parameters.num_of_wait_locks 
	- 1669.8472 * parameters.total_wait_locks 
	+ 0.0094 * parameters.mean_wait_of_all 
	- 0.083 * parameters.avg_latency_of_same_past_second 
	+ 92759719.3787;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM37(work_wait &parameters) {
  double actual_remaining = 
	0.2015 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 34711.7597 * parameters.num_locks_so_far 
	- 83392.8658 * parameters.num_of_wait_locks 
	- 996.2586 * parameters.total_wait_locks 
	- 1.7872 * parameters.mean_wait_of_all 
	- 0.0011 * parameters.avg_latency_of_same_past_second 
	+ 249312511.9335;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM38(work_wait &parameters) {
  double actual_remaining = 
	38.3165 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 34711.7597 * parameters.num_locks_so_far 
	- 8154738.1963 * parameters.num_of_wait_locks 
	+ 902.3946 * parameters.total_wait_locks 
	+ 0.1453 * parameters.mean_wait_of_all 
	- 0.0278 * parameters.avg_latency_of_same_past_second 
	+ 83332447.9218;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM39(work_wait &parameters) {
  double actual_remaining = 
	0.4979 * parameters.work_so_far 
	+ 0.0043 * parameters.wait_so_far 
	+ 237396.7524 * parameters.num_locks_so_far 
	- 10195317.3529 * parameters.num_of_wait_locks 
	+ 154487.8978 * parameters.total_wait_locks 
	- 0.023 * parameters.mean_wait_of_all 
	- 0.0004 * parameters.avg_latency_of_same_past_second 
	+ 66351474.8873;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM40(work_wait &parameters) {
  double actual_remaining = 
	0.2664 * parameters.work_so_far 
	+ 0.0065 * parameters.wait_so_far 
	+ 424690.155 * parameters.num_locks_so_far 
	- 16735194.8061 * parameters.num_of_wait_locks 
	+ 513391.2827 * parameters.total_wait_locks 
	- 1.3798 * parameters.mean_wait_of_all 
	- 0.0004 * parameters.avg_latency_of_same_past_second 
	+ 97338972.9167;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM41(work_wait &parameters) {
  double actual_remaining = 
	1.0332 * parameters.work_so_far 
	+ 0.9452 * parameters.wait_so_far 
	+ 841240.1164 * parameters.num_locks_so_far 
	- 906736.3294 * parameters.num_of_wait_locks 
	+ 30377.5615 * parameters.total_wait_locks 
	- 0.0794 * parameters.mean_wait_of_all 
	- 0.0004 * parameters.avg_latency_of_same_past_second 
	+ 17976410.4057;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM42(work_wait &parameters) {
  double actual_remaining = 
	-0.3774 * parameters.work_so_far 
	+ 0.0092 * parameters.wait_so_far 
	+ 1064828.4059 * parameters.num_locks_so_far 
	- 41734374.5134 * parameters.num_of_wait_locks 
	+ 1252569.1915 * parameters.total_wait_locks 
	- 3.4952 * parameters.mean_wait_of_all 
	- 225010812.6591 * parameters.cpu_usage 
	- 0.0061 * parameters.avg_latency_of_same_past_second 
	+ 387248437.0146;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM43(work_wait &parameters) {
  double actual_remaining = 
	1.1065 * parameters.work_so_far 
	+ 0.9333 * parameters.wait_so_far 
	+ 2398653.6681 * parameters.num_locks_so_far 
	+ 3475114.2213 * parameters.num_of_wait_locks 
	- 391909.8947 * parameters.total_wait_locks 
	+ 1.1382 * parameters.mean_wait_of_all 
	- 58426476.0773 * parameters.cpu_usage 
	+ 0.0202 * parameters.avg_latency_of_same_past_second 
	+ 91874542.1785;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM44(work_wait &parameters) {
  double actual_remaining = 
	8.9373 * parameters.work_so_far 
	+ 0.8291 * parameters.wait_so_far 
	+ 2398653.6681 * parameters.num_locks_so_far 
	+ 25248183.1302 * parameters.num_of_wait_locks 
	- 20059.751 * parameters.total_wait_locks 
	+ 0.118 * parameters.mean_wait_of_all 
	- 141576604.4724 * parameters.cpu_usage 
	- 0.0149 * parameters.avg_latency_of_same_past_second 
	+ 112385051.0368;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM45(work_wait &parameters) {
  double actual_remaining = 
	1.3387 * parameters.work_so_far 
	+ 0.7774 * parameters.wait_so_far 
	+ 3048948.9745 * parameters.num_locks_so_far 
	+ 50330090.9128 * parameters.num_of_wait_locks 
	- 20059.751 * parameters.total_wait_locks 
	+ 0.118 * parameters.mean_wait_of_all 
	- 70712807.575 * parameters.cpu_usage 
	+ 0.2106 * parameters.avg_latency_of_same_past_second 
	- 80432181.2449;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM46(work_wait &parameters) {
  double actual_remaining = 
	1.7887 * parameters.work_so_far 
	+ 0.7913 * parameters.wait_so_far 
	+ 2398653.6681 * parameters.num_locks_so_far 
	+ 73238322.4916 * parameters.num_of_wait_locks 
	- 20059.751 * parameters.total_wait_locks 
	+ 0.118 * parameters.mean_wait_of_all 
	- 109765383.6974 * parameters.cpu_usage 
	+ 0.1817 * parameters.avg_latency_of_same_past_second 
	- 142517475.4851;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM47(work_wait &parameters) {
  double actual_remaining = 
	0.9909 * parameters.work_so_far 
	+ 0.8067 * parameters.wait_so_far 
	+ 2398653.6681 * parameters.num_locks_so_far 
	+ 115069536.4916 * parameters.num_of_wait_locks 
	- 20059.751 * parameters.total_wait_locks 
	+ 0.118 * parameters.mean_wait_of_all 
	- 109765383.6974 * parameters.cpu_usage 
	+ 0.1817 * parameters.avg_latency_of_same_past_second 
	- 357609558.6362;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM48(work_wait &parameters) {
  double actual_remaining = 
	0.9909 * parameters.work_so_far 
	+ 0.8174 * parameters.wait_so_far 
	+ 2398653.6681 * parameters.num_locks_so_far 
	+ 110635528.6345 * parameters.num_of_wait_locks 
	- 20059.751 * parameters.total_wait_locks 
	+ 0.118 * parameters.mean_wait_of_all 
	- 109765383.6974 * parameters.cpu_usage 
	+ 0.1817 * parameters.avg_latency_of_same_past_second 
	- 335278149.6774;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
static
double
payment_estimate(work_wait &parameters){

  if (parameters.work_so_far <= 13713.5) {

    if (parameters.work_so_far <= 7693.5) {

      if (parameters.num_of_wait_locks <= 1.5) {

        if (parameters.work_so_far <= 6229.5) {
          return payment_LM1(parameters);
        } else if (parameters.work_so_far >  6229.5) {
          return payment_LM2(parameters);
        }
      } else if (parameters.num_of_wait_locks >  1.5) {

        if (parameters.total_wait_locks <= 48.5) {
          return payment_LM3(parameters);
        } else if (parameters.total_wait_locks >  48.5) {

          if (parameters.mean_wait_of_all <= 28683000) {
            return payment_LM4(parameters);
          } else if (parameters.mean_wait_of_all >  28683000) {
            return payment_LM5(parameters);
          }
        }
      }
    } else if (parameters.work_so_far >  7693.5) {

      if (parameters.num_of_wait_locks <= 1.5) {

        if (parameters.cpu_usage <= 0.898) {

          if (parameters.wait_so_far <= 15595772) {
            return payment_LM6(parameters);
          } else if (parameters.wait_so_far >  15595772) {

            if (parameters.cpu_usage <= 0.848) {
              return payment_LM7(parameters);
            } else if (parameters.cpu_usage >  0.848) {

              if (parameters.mean_wait_of_all <= 26748750) {

                if (parameters.work_so_far <= 8631) {
                  return payment_LM8(parameters);
                } else if (parameters.work_so_far >  8631) {
                  return payment_LM9(parameters);
                }
              } else if (parameters.mean_wait_of_all >  26748750) {

                if (parameters.avg_latency_of_same_past_second <= 25347900) {

                  if (parameters.avg_latency_of_same_past_second <= 20253550) {
                    return payment_LM10(parameters);
                  } else if (parameters.avg_latency_of_same_past_second >  20253550) {

                    if (parameters.total_wait_locks <= 56) {

                      if (parameters.total_wait_locks <= 11) {
                        return payment_LM11(parameters);
                      } else if (parameters.total_wait_locks >  11) {

                        if (parameters.total_wait_locks <= 41.5) {
                          return payment_LM12(parameters);
                        } else if (parameters.total_wait_locks >  41.5) {
                          return payment_LM13(parameters);
                        }
                      }
                    } else if (parameters.total_wait_locks >  56) {
                      return payment_LM14(parameters);
                    }
                  }
                } else if (parameters.avg_latency_of_same_past_second >  25347900) {

                  if (parameters.wait_so_far <= 28782159.5) {
                    return payment_LM15(parameters);
                  } else if (parameters.wait_so_far >  28782159.5) {

                    if (parameters.total_wait_locks <= 63) {
                      return payment_LM16(parameters);
                    } else if (parameters.total_wait_locks >  63) {
                      return payment_LM17(parameters);
                    }
                  }
                }
              }
            }
          }
        } else if (parameters.cpu_usage >  0.898) {

          if (parameters.work_so_far <= 10978) {
            return payment_LM18(parameters);
          } else if (parameters.work_so_far >  10978) {
            return payment_LM19(parameters);
          }
        }
      } else if (parameters.num_of_wait_locks >  1.5) {

        if (parameters.num_of_wait_locks <= 2.5) {

          if (parameters.wait_so_far <= 26199530) {
            return payment_LM20(parameters);
          } else if (parameters.wait_so_far >  26199530) {

            if (parameters.work_so_far <= 8517) {
              return payment_LM21(parameters);
            } else if (parameters.work_so_far >  8517) {

              if (parameters.total_wait_locks <= 30.5) {

                if (parameters.cpu_usage <= 0.859) {
                  return payment_LM22(parameters);
                } else if (parameters.cpu_usage >  0.859) {

                  if (parameters.work_so_far <= 11347.5) {
                    return payment_LM23(parameters);
                  } else if (parameters.work_so_far >  11347.5) {

                    if (parameters.mean_wait_of_all <= 32221100) {
                      return payment_LM24(parameters);
                    } else if (parameters.mean_wait_of_all >  32221100) {

                      if (parameters.mean_wait_of_all <= 34002050) {
                        return payment_LM25(parameters);
                      } else if (parameters.mean_wait_of_all >  34002050) {
                        return payment_LM26(parameters);
                      }
                    }
                  }
                }
              } else if (parameters.total_wait_locks >  30.5) {
                return payment_LM27(parameters);
              }
            }
          }
        } else if (parameters.num_of_wait_locks >  2.5) {

          if (parameters.cpu_usage <= 0.94) {

            if (parameters.mean_wait_of_all <= 26997600) {

              if (parameters.avg_latency_of_same_past_second <= 23730800) {
                return payment_LM28(parameters);
              } else if (parameters.avg_latency_of_same_past_second >  23730800) {

                if (parameters.wait_so_far <= 163322405.5) {
                  return payment_LM29(parameters);
                } else if (parameters.wait_so_far >  163322405.5) {
                  return payment_LM30(parameters);
                }
              }
            } else if (parameters.mean_wait_of_all >  26997600) {
              return payment_LM31(parameters);
            }
          } else if (parameters.cpu_usage >  0.94) {

            if (parameters.cpu_usage <= 0.969) {
              return payment_LM32(parameters);
            } else if (parameters.cpu_usage >  0.969) {

              if (parameters.cpu_usage <= 0.99) {
                return payment_LM33(parameters);
              } else if (parameters.cpu_usage >  0.99) {
                return payment_LM34(parameters);
              }
            }
          }
        }
      }
    }
  } else if (parameters.work_so_far >  13713.5) {

    if (parameters.work_so_far <= 954932) {

      if (parameters.total_wait_locks <= 177.5) {
        return payment_LM35(parameters);
      } else if (parameters.total_wait_locks >  177.5) {

        if (parameters.wait_so_far <= 7842896.5) {

          if (parameters.mean_wait_of_all <= 63929000) {
            return payment_LM36(parameters);
          } else if (parameters.mean_wait_of_all >  63929000) {
            return payment_LM37(parameters);
          }
        } else if (parameters.wait_so_far >  7842896.5) {
          return payment_LM38(parameters);
        }
      }
    } else if (parameters.work_so_far >  954932) {

      if (parameters.wait_so_far <= 447654301) {

        if (parameters.wait_so_far <= 72355461.5) {
          return payment_LM39(parameters);
        } else if (parameters.wait_so_far >  72355461.5) {

          if (parameters.num_locks_so_far <= 2.5) {
            return payment_LM40(parameters);
          } else if (parameters.num_locks_so_far >  2.5) {
            return payment_LM41(parameters);
          }
        }
      } else if (parameters.wait_so_far >  447654301) {

        if (parameters.num_locks_so_far <= 2.5) {
          return payment_LM42(parameters);
        } else if (parameters.num_locks_so_far >  2.5) {

          if (parameters.wait_so_far <= 698744921.5) {
            return payment_LM43(parameters);
          } else if (parameters.wait_so_far >  698744921.5) {

            if (parameters.wait_so_far <= 817423926) {
              return payment_LM44(parameters);
            } else if (parameters.wait_so_far >  817423926) {

              if (parameters.wait_so_far <= 1000163492) {
                return payment_LM45(parameters);
              } else if (parameters.wait_so_far >  1000163492) {

                if (parameters.num_locks_so_far <= 5) {
                  return payment_LM46(parameters);
                } else if (parameters.num_locks_so_far >  5) {

                  if (parameters.num_of_wait_locks <= 2.5) {
                    return payment_LM47(parameters);
                  } else if (parameters.num_of_wait_locks >  2.5) {
                    return payment_LM48(parameters);
                  }
                }
              }
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
	0.1041 * parameters.work_so_far 
	- 0.0042 * parameters.wait_so_far 
	- 252415.1802 * parameters.num_locks_so_far 
	+ 9660742.993 * parameters.num_of_wait_locks 
	+ 111528.8809 * parameters.total_wait_locks 
	- 0.1032 * parameters.mean_wait_of_all 
	- 3046991.7721 * parameters.cpu_usage 
	+ 74608991.1769;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM2(work_wait &parameters) {
  double actual_remaining = 
	0.1184 * parameters.work_so_far 
	- 0.1252 * parameters.wait_so_far 
	- 2131192.6115 * parameters.num_locks_so_far 
	+ 7687790.393 * parameters.num_of_wait_locks 
	+ 2540367.9922 * parameters.total_wait_locks 
	- 0.1666 * parameters.mean_wait_of_all 
	- 15942884.9117 * parameters.cpu_usage 
	- 0.1448 * parameters.avg_latency_of_same_past_second 
	+ 121208202.2936;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM3(work_wait &parameters) {
  double actual_remaining = 
	1.1658 * parameters.work_so_far 
	- 0.0061 * parameters.wait_so_far 
	- 2699922.327 * parameters.num_locks_so_far 
	+ 7687790.393 * parameters.num_of_wait_locks 
	+ 532864.8249 * parameters.total_wait_locks 
	- 0.138 * parameters.mean_wait_of_all 
	- 151116506.1083 * parameters.cpu_usage 
	+ 232102993.7839;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM4(work_wait &parameters) {
  double actual_remaining = 
	0.3543 * parameters.work_so_far 
	- 0.1344 * parameters.wait_so_far 
	- 686660.6062 * parameters.num_locks_so_far 
	+ 12724098.4984 * parameters.num_of_wait_locks 
	+ 1981237.2104 * parameters.total_wait_locks 
	- 0.1512 * parameters.mean_wait_of_all 
	- 3046991.7721 * parameters.cpu_usage 
	+ 90149232.4226;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM5(work_wait &parameters) {
  double actual_remaining = 
	1.1461 * parameters.work_so_far 
	+ 0.0802 * parameters.wait_so_far 
	- 2055053.4056 * parameters.num_locks_so_far 
	+ 12724098.4984 * parameters.num_of_wait_locks 
	+ 1532912.6952 * parameters.total_wait_locks 
	- 11.8687 * parameters.mean_wait_of_all 
	- 3046991.7721 * parameters.cpu_usage 
	+ 0.0898 * parameters.avg_latency_of_same_past_second 
	+ 424978441.0418;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM6(work_wait &parameters) {
  double actual_remaining = 
	0.5356 * parameters.work_so_far 
	+ 0.1221 * parameters.wait_so_far 
	- 990475.1366 * parameters.num_locks_so_far 
	+ 12724098.4984 * parameters.num_of_wait_locks 
	+ 1953307.8869 * parameters.total_wait_locks 
	- 7.4894 * parameters.mean_wait_of_all 
	+ 592989699.1677 * parameters.cpu_usage 
	+ 0.1428 * parameters.avg_latency_of_same_past_second 
	- 241922463.2685;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM7(work_wait &parameters) {
  double actual_remaining = 
	0.7655 * parameters.work_so_far 
	+ 0.0988 * parameters.wait_so_far 
	- 4505127.3435 * parameters.num_locks_so_far 
	+ 12724098.4984 * parameters.num_of_wait_locks 
	+ 1700655.8238 * parameters.total_wait_locks 
	- 5.9399 * parameters.mean_wait_of_all 
	- 3046991.7721 * parameters.cpu_usage 
	+ 0.0829 * parameters.avg_latency_of_same_past_second 
	+ 547993655.855;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM8(work_wait &parameters) {
  double actual_remaining = 
	0.1838 * parameters.work_so_far 
	- 0.2822 * parameters.wait_so_far 
	- 7388102.5456 * parameters.num_locks_so_far 
	+ 5108321.6899 * parameters.num_of_wait_locks 
	+ 1078812.2048 * parameters.total_wait_locks 
	- 0.0345 * parameters.mean_wait_of_all 
	- 4827841.9579 * parameters.cpu_usage 
	+ 271302487.3562;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM9(work_wait &parameters) {
  double actual_remaining = 
	0.5242 * parameters.work_so_far 
	- 0.2877 * parameters.wait_so_far 
	- 453702.8126 * parameters.num_locks_so_far 
	+ 8215635.4125 * parameters.num_of_wait_locks 
	+ 3151413.3015 * parameters.total_wait_locks 
	- 9.6451 * parameters.mean_wait_of_all 
	- 549280676.2802 * parameters.cpu_usage 
	+ 1003219824.5661;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM10(work_wait &parameters) {
  double actual_remaining = 
	0.5242 * parameters.work_so_far 
	+ 3.1961 * parameters.wait_so_far 
	- 453702.8126 * parameters.num_locks_so_far 
	+ 8215635.4125 * parameters.num_of_wait_locks 
	+ 3291643.2549 * parameters.total_wait_locks 
	- 14.1966 * parameters.mean_wait_of_all 
	- 835359041.0797 * parameters.cpu_usage 
	+ 1633354054.2571;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM11(work_wait &parameters) {
  double actual_remaining = 
	0.5242 * parameters.work_so_far 
	+ 2.3251 * parameters.wait_so_far 
	- 453702.8126 * parameters.num_locks_so_far 
	+ 8215635.4125 * parameters.num_of_wait_locks 
	+ 3291643.2549 * parameters.total_wait_locks 
	- 13.1694 * parameters.mean_wait_of_all 
	- 898462872.9934 * parameters.cpu_usage 
	+ 1565061970.5247;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM12(work_wait &parameters) {
  double actual_remaining = 
	0.5242 * parameters.work_so_far 
	- 0.1693 * parameters.wait_so_far 
	- 453702.8126 * parameters.num_locks_so_far 
	+ 8215635.4125 * parameters.num_of_wait_locks 
	+ 849723.8264 * parameters.total_wait_locks 
	- 2.3585 * parameters.mean_wait_of_all 
	- 150019458.0032 * parameters.cpu_usage 
	+ 672902252.0651;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM13(work_wait &parameters) {
  double actual_remaining = 
	1.2078 * parameters.work_so_far 
	- 0.0552 * parameters.wait_so_far 
	- 453702.8126 * parameters.num_locks_so_far 
	+ 8215635.4125 * parameters.num_of_wait_locks 
	+ 628911.1318 * parameters.total_wait_locks 
	- 1.0199 * parameters.mean_wait_of_all 
	- 290673480.6113 * parameters.cpu_usage 
	- 0.051 * parameters.avg_latency_of_same_past_second 
	+ 520961982.4566;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM14(work_wait &parameters) {
  double actual_remaining = 
	2.3199 * parameters.work_so_far 
	- 0.0552 * parameters.wait_so_far 
	- 453702.8126 * parameters.num_locks_so_far 
	+ 8215635.4125 * parameters.num_of_wait_locks 
	+ 1139325.1996 * parameters.total_wait_locks 
	- 1.0199 * parameters.mean_wait_of_all 
	- 681916795.7608 * parameters.cpu_usage 
	- 0.3958 * parameters.avg_latency_of_same_past_second 
	+ 1212067648.3438;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM15(work_wait &parameters) {
  double actual_remaining = 
	1.663 * parameters.work_so_far 
	- 0.0552 * parameters.wait_so_far 
	- 453702.8126 * parameters.num_locks_so_far 
	+ 8215635.4125 * parameters.num_of_wait_locks 
	+ 2124021.3827 * parameters.total_wait_locks 
	- 1.0199 * parameters.mean_wait_of_all 
	- 459354991.0593 * parameters.cpu_usage 
	- 0.3224 * parameters.avg_latency_of_same_past_second 
	+ 526273080.5186;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM16(work_wait &parameters) {
  double actual_remaining = 
	1.0333 * parameters.work_so_far 
	+ 0.2456 * parameters.wait_so_far 
	- 6451009.6724 * parameters.num_locks_so_far 
	+ 8215635.4125 * parameters.num_of_wait_locks 
	+ 683419.4723 * parameters.total_wait_locks 
	- 0.2933 * parameters.mean_wait_of_all 
	- 852956116.8221 * parameters.cpu_usage 
	+ 1322289603.858;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
static
double
delivery_estimate(work_wait &parameters){

  if (parameters.total_wait_locks <= 91.5) {

    if (parameters.work_so_far <= 9391.5) {
      return delivery_LM1(parameters);
    } else if (parameters.work_so_far >  9391.5) {

      if (parameters.num_of_wait_locks <= 1.5) {

        if (parameters.mean_wait_of_all <= 27100700) {
          return delivery_LM2(parameters);
        } else if (parameters.mean_wait_of_all >  27100700) {
          return delivery_LM3(parameters);
        }
      } else if (parameters.num_of_wait_locks >  1.5) {

        if (parameters.work_so_far <= 188138.5) {
          return delivery_LM4(parameters);
        } else if (parameters.work_so_far >  188138.5) {

          if (parameters.work_so_far <= 239156762.5) {

            if (parameters.total_wait_locks <= 74.5) {
              return delivery_LM5(parameters);
            } else if (parameters.total_wait_locks >  74.5) {
              return delivery_LM6(parameters);
            }
          } else if (parameters.work_so_far >  239156762.5) {
            return delivery_LM7(parameters);
          }
        }
      }
    }
  } else if (parameters.total_wait_locks >  91.5) {

    if (parameters.num_of_wait_locks <= 1.5) {
      return delivery_LM8(parameters);
    } else if (parameters.num_of_wait_locks >  1.5) {

      if (parameters.num_locks_so_far <= 3.5) {

        if (parameters.wait_so_far <= 369181490.5) {

          if (parameters.wait_so_far <= 34224879) {

            if (parameters.mean_wait_of_all <= 63129500) {
              return delivery_LM9(parameters);
            } else if (parameters.mean_wait_of_all >  63129500) {

              if (parameters.mean_wait_of_all <= 69368650) {
                return delivery_LM10(parameters);
              } else if (parameters.mean_wait_of_all >  69368650) {
                return delivery_LM11(parameters);
              }
            }
          } else if (parameters.wait_so_far >  34224879) {
            return delivery_LM12(parameters);
          }
        } else if (parameters.wait_so_far >  369181490.5) {

          if (parameters.work_so_far <= 16960.5) {
            return delivery_LM13(parameters);
          } else if (parameters.work_so_far >  16960.5) {

            if (parameters.cpu_usage <= 0.822) {
              return delivery_LM14(parameters);
            } else if (parameters.cpu_usage >  0.822) {
              return delivery_LM15(parameters);
            }
          }
        }
      } else if (parameters.num_locks_so_far >  3.5) {
        return delivery_LM16(parameters);
      }
    }
  }
}
static
double
stock_level_LM1(work_wait &parameters) {
  double actual_remaining = 
	-0.0562 * parameters.wait_so_far 
	- 222946.3766 * parameters.num_locks_so_far 
	+ 197440.0084 * parameters.total_wait_locks 
	- 0.5799 * parameters.mean_wait_of_all 
	- 67725847.4701 * parameters.cpu_usage 
	+ 0.2253 * parameters.avg_latency_of_same_past_second 
	+ 94398197.6413;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
static
double
stock_level_estimate(work_wait &parameters){
  return stock_level_LM1(parameters);
}
static
double
tpcc_LM1(work_wait &parameters) {
  double actual_remaining = 
	22.7293 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	- 21284.2095 * parameters.num_of_wait_locks 
	+ 1568.6225 * parameters.total_wait_locks 
	- 0.0048 * parameters.mean_wait_of_all 
	- 590317.4067 * parameters.cpu_usage 
	+ 0.0014 * parameters.avg_latency_of_same_past_second 
	+ 6951084.9169;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM2(work_wait &parameters) {
  double actual_remaining = 
	557.2608 * parameters.work_so_far 
	+ 0.0011 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	+ 489822.1243 * parameters.num_of_wait_locks 
	- 477.6945 * parameters.total_wait_locks 
	- 0.0504 * parameters.mean_wait_of_all 
	- 911601.3165 * parameters.cpu_usage 
	+ 0.0159 * parameters.avg_latency_of_same_past_second 
	+ 3264157.8206;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM3(work_wait &parameters) {
  double actual_remaining = 
	323.0995 * parameters.work_so_far 
	+ 0.0011 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	+ 5303661.9484 * parameters.num_of_wait_locks 
	- 477.6945 * parameters.total_wait_locks 
	- 0.0504 * parameters.mean_wait_of_all 
	- 911601.3165 * parameters.cpu_usage 
	+ 0.0684 * parameters.avg_latency_of_same_past_second 
	- 609812.6794;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM4(work_wait &parameters) {
  double actual_remaining = 
	110.3881 * parameters.work_so_far 
	+ 0.0011 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	+ 32269.0679 * parameters.num_of_wait_locks 
	- 269675.1721 * parameters.total_wait_locks 
	- 0.1133 * parameters.mean_wait_of_all 
	- 911601.3165 * parameters.cpu_usage 
	+ 0.2363 * parameters.avg_latency_of_same_past_second 
	+ 15161865.8933;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM5(work_wait &parameters) {
  double actual_remaining = 
	88.6997 * parameters.work_so_far 
	+ 0.0011 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	+ 24963.0146 * parameters.num_of_wait_locks 
	+ 6.1136 * parameters.total_wait_locks 
	- 0.0103 * parameters.mean_wait_of_all 
	- 911601.3165 * parameters.cpu_usage 
	+ 0.0033 * parameters.avg_latency_of_same_past_second 
	+ 7977481.92;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM6(work_wait &parameters) {
  double actual_remaining = 
	20.1642 * parameters.work_so_far 
	+ 0.0683 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	+ 4379768.7915 * parameters.num_of_wait_locks 
	+ 1534.947 * parameters.total_wait_locks 
	- 0.0076 * parameters.mean_wait_of_all 
	- 44035336.3841 * parameters.cpu_usage 
	+ 0.0418 * parameters.avg_latency_of_same_past_second 
	+ 40107942.9021;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM7(work_wait &parameters) {
  double actual_remaining = 
	2829.3439 * parameters.work_so_far 
	+ 0.001 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	+ 8244136.3822 * parameters.num_of_wait_locks 
	+ 81331.5255 * parameters.total_wait_locks 
	- 0.013 * parameters.mean_wait_of_all 
	- 52979633.0084 * parameters.cpu_usage 
	+ 0.0772 * parameters.avg_latency_of_same_past_second 
	+ 18931036.4505;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM8(work_wait &parameters) {
  double actual_remaining = 
	5875.5639 * parameters.work_so_far 
	+ 0.001 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	+ 217097.4131 * parameters.num_of_wait_locks 
	- 328068.5932 * parameters.total_wait_locks 
	- 0.0208 * parameters.mean_wait_of_all 
	- 308439780.4158 * parameters.cpu_usage 
	+ 0.112 * parameters.avg_latency_of_same_past_second 
	+ 264513326.4099;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM9(work_wait &parameters) {
  double actual_remaining = 
	-293.7089 * parameters.work_so_far 
	+ 0.0074 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	+ 636896.2033 * parameters.num_of_wait_locks 
	+ 1483.8564 * parameters.total_wait_locks 
	- 0.0426 * parameters.mean_wait_of_all 
	- 22390818.5724 * parameters.cpu_usage 
	+ 0.0243 * parameters.avg_latency_of_same_past_second 
	+ 37165684.7353;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM10(work_wait &parameters) {
  double actual_remaining = 
	-293.7089 * parameters.work_so_far 
	+ 0.0095 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	+ 636896.2033 * parameters.num_of_wait_locks 
	+ 1483.8564 * parameters.total_wait_locks 
	- 0.0426 * parameters.mean_wait_of_all 
	- 375460764.4338 * parameters.cpu_usage 
	+ 0.0313 * parameters.avg_latency_of_same_past_second 
	+ 399827647.1458;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM11(work_wait &parameters) {
  double actual_remaining = 
	-1285.8954 * parameters.work_so_far 
	+ 0.0164 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	+ 709213.611 * parameters.num_of_wait_locks 
	+ 1483.8564 * parameters.total_wait_locks 
	- 0.0448 * parameters.mean_wait_of_all 
	- 12176143.2556 * parameters.cpu_usage 
	+ 0.0274 * parameters.avg_latency_of_same_past_second 
	+ 49234428.1463;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM12(work_wait &parameters) {
  double actual_remaining = 
	-2388.5204 * parameters.work_so_far 
	+ 0.0126 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	+ 709213.611 * parameters.num_of_wait_locks 
	+ 1483.8564 * parameters.total_wait_locks 
	- 0.6047 * parameters.mean_wait_of_all 
	- 12176143.2556 * parameters.cpu_usage 
	+ 0.0666 * parameters.avg_latency_of_same_past_second 
	+ 94960585.7356;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM13(work_wait &parameters) {
  double actual_remaining = 
	-2388.5204 * parameters.work_so_far 
	+ 0.2428 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	+ 709213.611 * parameters.num_of_wait_locks 
	+ 1483.8564 * parameters.total_wait_locks 
	- 3.9668 * parameters.mean_wait_of_all 
	- 12176143.2556 * parameters.cpu_usage 
	+ 0.3409 * parameters.avg_latency_of_same_past_second 
	+ 197116472.1063;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM14(work_wait &parameters) {
  double actual_remaining = 
	-2388.5204 * parameters.work_so_far 
	+ 0.2428 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	+ 709213.611 * parameters.num_of_wait_locks 
	+ 1483.8564 * parameters.total_wait_locks 
	- 3.9668 * parameters.mean_wait_of_all 
	- 12176143.2556 * parameters.cpu_usage 
	+ 0.3409 * parameters.avg_latency_of_same_past_second 
	+ 225961150.0682;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM15(work_wait &parameters) {
  double actual_remaining = 
	-2388.5204 * parameters.work_so_far 
	+ 0.0126 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	+ 709213.611 * parameters.num_of_wait_locks 
	+ 1483.8564 * parameters.total_wait_locks 
	- 2.6322 * parameters.mean_wait_of_all 
	- 12176143.2556 * parameters.cpu_usage 
	+ 0.1452 * parameters.avg_latency_of_same_past_second 
	+ 165457746.8568;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM16(work_wait &parameters) {
  double actual_remaining = 
	-4631.1303 * parameters.work_so_far 
	+ 0.0126 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	+ 709213.611 * parameters.num_of_wait_locks 
	+ 1483.8564 * parameters.total_wait_locks 
	- 0.5706 * parameters.mean_wait_of_all 
	- 12176143.2556 * parameters.cpu_usage 
	+ 0.0693 * parameters.avg_latency_of_same_past_second 
	+ 101543892.6875;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM17(work_wait &parameters) {
  double actual_remaining = 
	-314.4415 * parameters.work_so_far 
	+ 0.0013 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	- 55005.4818 * parameters.num_of_wait_locks 
	+ 1483.8564 * parameters.total_wait_locks 
	- 0.0503 * parameters.mean_wait_of_all 
	- 12994513.3629 * parameters.cpu_usage 
	+ 0.0169 * parameters.avg_latency_of_same_past_second 
	+ 34614482.6843;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM18(work_wait &parameters) {
  double actual_remaining = 
	0.3342 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	+ 24818591.4442 * parameters.num_of_wait_locks 
	+ 160412.8176 * parameters.total_wait_locks 
	- 0.66 * parameters.mean_wait_of_all 
	- 1740136.0766 * parameters.cpu_usage 
	- 0.1628 * parameters.avg_latency_of_same_past_second 
	+ 13805038.0151;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM19(work_wait &parameters) {
  double actual_remaining = 
	0.0124 * parameters.work_so_far 
	+ 0.0044 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	+ 247959.5083 * parameters.num_of_wait_locks 
	- 26244.3442 * parameters.total_wait_locks 
	- 1.497 * parameters.mean_wait_of_all 
	- 24018013.2094 * parameters.cpu_usage 
	+ 0.6675 * parameters.avg_latency_of_same_past_second 
	+ 105075452.4017;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM20(work_wait &parameters) {
  double actual_remaining = 
	0.0124 * parameters.work_so_far 
	+ 0.0596 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	+ 12900674.8466 * parameters.num_of_wait_locks 
	- 182947.9705 * parameters.total_wait_locks 
	- 0.032 * parameters.mean_wait_of_all 
	- 8848390.9806 * parameters.cpu_usage 
	+ 0.13 * parameters.avg_latency_of_same_past_second 
	+ 11510879.9144;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM21(work_wait &parameters) {
  double actual_remaining = 
	0.0212 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	- 240530.5924 * parameters.num_of_wait_locks 
	+ 4548.8618 * parameters.total_wait_locks 
	- 0.1611 * parameters.mean_wait_of_all 
	- 30059300.1372 * parameters.cpu_usage 
	+ 0.0036 * parameters.avg_latency_of_same_past_second 
	+ 56961792.4401;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM22(work_wait &parameters) {
  double actual_remaining = 
	0.0469 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	- 13157570.7401 * parameters.num_of_wait_locks 
	+ 13349.4003 * parameters.total_wait_locks 
	- 0.0279 * parameters.mean_wait_of_all 
	- 2286401.4375 * parameters.cpu_usage 
	+ 0.0036 * parameters.avg_latency_of_same_past_second 
	+ 92819449.4885;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM23(work_wait &parameters) {
  double actual_remaining = 
	0.009 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	+ 14429662.8333 * parameters.num_of_wait_locks 
	+ 165417.6797 * parameters.total_wait_locks 
	- 0.3808 * parameters.mean_wait_of_all 
	- 670030.4956 * parameters.cpu_usage 
	+ 0.0032 * parameters.avg_latency_of_same_past_second 
	+ 28266299.377;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM24(work_wait &parameters) {
  double actual_remaining = 
	0.5265 * parameters.work_so_far 
	+ 0.0794 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	+ 68698835.5624 * parameters.num_of_wait_locks 
	+ 485401.179 * parameters.total_wait_locks 
	- 1.2891 * parameters.mean_wait_of_all 
	- 1121364.1387 * parameters.cpu_usage 
	+ 0.0032 * parameters.avg_latency_of_same_past_second 
	- 88973988.8906;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM25(work_wait &parameters) {
  double actual_remaining = 
	0.0122 * parameters.work_so_far 
	- 0.003 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	- 3300231.4433 * parameters.num_of_wait_locks 
	+ 24464.5856 * parameters.total_wait_locks 
	- 0.126 * parameters.mean_wait_of_all 
	+ 5434158.4396 * parameters.cpu_usage 
	+ 0.0322 * parameters.avg_latency_of_same_past_second 
	+ 92118522.8097;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM26(work_wait &parameters) {
  double actual_remaining = 
	0.0122 * parameters.work_so_far 
	- 0.2798 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	- 8356440.6192 * parameters.num_of_wait_locks 
	+ 121173.1556 * parameters.total_wait_locks 
	- 0.4482 * parameters.mean_wait_of_all 
	+ 46506059.8153 * parameters.cpu_usage 
	+ 0.2745 * parameters.avg_latency_of_same_past_second 
	+ 359798423.8106;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM27(work_wait &parameters) {
  double actual_remaining = 
	2.5257 * parameters.work_so_far 
	- 0.029 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	- 111273385.3839 * parameters.num_of_wait_locks 
	+ 3680479.8671 * parameters.total_wait_locks 
	- 10.1829 * parameters.mean_wait_of_all 
	+ 574683652.3393 * parameters.cpu_usage 
	+ 0.0927 * parameters.avg_latency_of_same_past_second 
	- 489221216.2435;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM28(work_wait &parameters) {
  double actual_remaining = 
	0.0021 * parameters.work_so_far 
	- 0.0139 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	- 9957788.0369 * parameters.num_of_wait_locks 
	+ 45055.749 * parameters.total_wait_locks 
	- 0.0027 * parameters.mean_wait_of_all 
	- 57439.7012 * parameters.cpu_usage 
	+ 0.0007 * parameters.avg_latency_of_same_past_second 
	+ 87877488.5102;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM29(work_wait &parameters) {
  double actual_remaining = 
	0.0036 * parameters.work_so_far 
	+ 0.0482 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	- 17691193.4324 * parameters.num_of_wait_locks 
	+ 917.0191 * parameters.total_wait_locks 
	- 0.0027 * parameters.mean_wait_of_all 
	- 57439.7012 * parameters.cpu_usage 
	+ 0.0007 * parameters.avg_latency_of_same_past_second 
	+ 147649068.2575;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM30(work_wait &parameters) {
  double actual_remaining = 
	1.1939 * parameters.work_so_far 
	+ 0.0016 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	- 14174545.5176 * parameters.num_of_wait_locks 
	+ 368217.8166 * parameters.total_wait_locks 
	- 0.904 * parameters.mean_wait_of_all 
	- 26302720.6359 * parameters.cpu_usage 
	- 0.0245 * parameters.avg_latency_of_same_past_second 
	+ 145783541.8143;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM31(work_wait &parameters) {
  double actual_remaining = 
	1.1939 * parameters.work_so_far 
	+ 0.0016 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	- 9503178.0358 * parameters.num_of_wait_locks 
	+ 228306.8072 * parameters.total_wait_locks 
	- 0.5665 * parameters.mean_wait_of_all 
	- 26302720.6359 * parameters.cpu_usage 
	- 0.0245 * parameters.avg_latency_of_same_past_second 
	+ 216584160.7258;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM32(work_wait &parameters) {
  double actual_remaining = 
	3.6866 * parameters.work_so_far 
	+ 0.0016 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	- 92010208.7484 * parameters.num_of_wait_locks 
	+ 305601.7605 * parameters.total_wait_locks 
	- 5.6936 * parameters.mean_wait_of_all 
	- 61366336.6926 * parameters.cpu_usage 
	- 0.0624 * parameters.avg_latency_of_same_past_second 
	+ 1011704917.5587;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM33(work_wait &parameters) {
  double actual_remaining = 
	0.3038 * parameters.work_so_far 
	- 0.0965 * parameters.wait_so_far 
	+ 143.5024 * parameters.num_locks_so_far 
	- 30287231.501 * parameters.num_of_wait_locks 
	- 272696.1469 * parameters.total_wait_locks 
	+ 1.5063 * parameters.mean_wait_of_all 
	- 10782770.6789 * parameters.cpu_usage 
	- 0.0074 * parameters.avg_latency_of_same_past_second 
	+ 262951115.0759;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM34(work_wait &parameters) {
  double actual_remaining = 
	0.0114 * parameters.work_so_far 
	- 0.113 * parameters.wait_so_far 
	+ 1850859.8547 * parameters.num_locks_so_far 
	+ 131116.2119 * parameters.num_of_wait_locks 
	+ 12598.8904 * parameters.total_wait_locks 
	- 0.0259 * parameters.mean_wait_of_all 
	- 174975366.0783 * parameters.cpu_usage 
	+ 1.6877 * parameters.avg_latency_of_same_past_second 
	+ 122904376.3975;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM35(work_wait &parameters) {
  double actual_remaining = 
	0.0114 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	- 17557.6884 * parameters.num_locks_so_far 
	+ 131116.2119 * parameters.num_of_wait_locks 
	+ 12598.8904 * parameters.total_wait_locks 
	- 0.0259 * parameters.mean_wait_of_all 
	- 4919631.7811 * parameters.cpu_usage 
	+ 0.0358 * parameters.avg_latency_of_same_past_second 
	+ 8972863.4354;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM36(work_wait &parameters) {
  double actual_remaining = 
	21.3919 * parameters.work_so_far 
	+ 0.0034 * parameters.wait_so_far 
	- 30371947.6586 * parameters.num_locks_so_far 
	+ 131116.2119 * parameters.num_of_wait_locks 
	+ 333037.8271 * parameters.total_wait_locks 
	- 0.0303 * parameters.mean_wait_of_all 
	- 6839563.2826 * parameters.cpu_usage 
	+ 0.0045 * parameters.avg_latency_of_same_past_second 
	+ 156971506.3605;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM37(work_wait &parameters) {
  double actual_remaining = 
	57.672 * parameters.work_so_far 
	+ 0.0059 * parameters.wait_so_far 
	- 44311526.8801 * parameters.num_locks_so_far 
	+ 131116.2119 * parameters.num_of_wait_locks 
	+ 38615.2512 * parameters.total_wait_locks 
	- 0.0303 * parameters.mean_wait_of_all 
	- 6839563.2826 * parameters.cpu_usage 
	+ 0.0045 * parameters.avg_latency_of_same_past_second 
	+ 250528280.0662;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM38(work_wait &parameters) {
  double actual_remaining = 
	52.4715 * parameters.work_so_far 
	+ 0.0061 * parameters.wait_so_far 
	- 1700531.6202 * parameters.num_locks_so_far 
	+ 131116.2119 * parameters.num_of_wait_locks 
	+ 879861.5926 * parameters.total_wait_locks 
	- 0.0479 * parameters.mean_wait_of_all 
	- 316891462.5832 * parameters.cpu_usage 
	+ 0.3284 * parameters.avg_latency_of_same_past_second 
	+ 334057810.0137;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM39(work_wait &parameters) {
  double actual_remaining = 
	0.5092 * parameters.work_so_far 
	+ 0.0061 * parameters.wait_so_far 
	- 1700531.6202 * parameters.num_locks_so_far 
	+ 131116.2119 * parameters.num_of_wait_locks 
	+ 103304.2234 * parameters.total_wait_locks 
	- 0.0479 * parameters.mean_wait_of_all 
	- 37304930.65 * parameters.cpu_usage 
	- 0.1242 * parameters.avg_latency_of_same_past_second 
	+ 131459906.8722;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM40(work_wait &parameters) {
  double actual_remaining = 
	1.9242 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	- 20630.702 * parameters.num_locks_so_far 
	+ 131116.2119 * parameters.num_of_wait_locks 
	+ 217311.5467 * parameters.total_wait_locks 
	- 0.0327 * parameters.mean_wait_of_all 
	- 37667793.7864 * parameters.cpu_usage 
	+ 0.006 * parameters.avg_latency_of_same_past_second 
	+ 62823992.4499;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM41(work_wait &parameters) {
  double actual_remaining = 
	4.4694 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	- 91216.2255 * parameters.num_locks_so_far 
	+ 131116.2119 * parameters.num_of_wait_locks 
	+ 91071.2118 * parameters.total_wait_locks 
	- 0.2409 * parameters.mean_wait_of_all 
	- 35388149.7013 * parameters.cpu_usage 
	+ 0.0219 * parameters.avg_latency_of_same_past_second 
	+ 84804311.5336;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM42(work_wait &parameters) {
  double actual_remaining = 
	0.1466 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 1057878.6695 * parameters.num_locks_so_far 
	+ 131116.2119 * parameters.num_of_wait_locks 
	+ 483814.1191 * parameters.total_wait_locks 
	- 0.3392 * parameters.mean_wait_of_all 
	- 251436895.9418 * parameters.cpu_usage 
	+ 0.019 * parameters.avg_latency_of_same_past_second 
	+ 215658496.5463;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM43(work_wait &parameters) {
  double actual_remaining = 
	0.1466 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	- 78523.2875 * parameters.num_locks_so_far 
	+ 131116.2119 * parameters.num_of_wait_locks 
	+ 77814.6991 * parameters.total_wait_locks 
	- 0.4676 * parameters.mean_wait_of_all 
	- 80161775.0543 * parameters.cpu_usage 
	+ 0.019 * parameters.avg_latency_of_same_past_second 
	+ 102844540.7955;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM44(work_wait &parameters) {
  double actual_remaining = 
	3.8677 * parameters.work_so_far 
	+ 0.1473 * parameters.wait_so_far 
	- 3039185.2266 * parameters.num_locks_so_far 
	- 28338128.52 * parameters.num_of_wait_locks 
	+ 625980.556 * parameters.total_wait_locks 
	- 0.5216 * parameters.mean_wait_of_all 
	- 228170639.577 * parameters.cpu_usage 
	+ 0.0939 * parameters.avg_latency_of_same_past_second 
	+ 337555574.7068;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM45(work_wait &parameters) {
  double actual_remaining = 
	1.2321 * parameters.work_so_far 
	+ 0.1366 * parameters.wait_so_far 
	- 1190883.762 * parameters.num_locks_so_far 
	+ 116023021.5095 * parameters.num_of_wait_locks 
	+ 950702.4199 * parameters.total_wait_locks 
	- 2.4049 * parameters.mean_wait_of_all 
	- 270465306.218 * parameters.cpu_usage 
	+ 0.0021 * parameters.avg_latency_of_same_past_second 
	+ 165692244.9372;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM46(work_wait &parameters) {
  double actual_remaining = 
	0.6097 * parameters.work_so_far 
	- 0.0777 * parameters.wait_so_far 
	- 47816304.8894 * parameters.num_locks_so_far 
	+ 324958.2212 * parameters.num_of_wait_locks 
	+ 1023636.6103 * parameters.total_wait_locks 
	- 2.0121 * parameters.mean_wait_of_all 
	- 24487368.3088 * parameters.cpu_usage 
	+ 0.4219 * parameters.avg_latency_of_same_past_second 
	+ 290989213.7654;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM47(work_wait &parameters) {
  double actual_remaining = 
	0.6097 * parameters.work_so_far 
	- 0.2423 * parameters.wait_so_far 
	- 47816304.8894 * parameters.num_locks_so_far 
	+ 324958.2212 * parameters.num_of_wait_locks 
	+ 921103.5369 * parameters.total_wait_locks 
	- 2.0121 * parameters.mean_wait_of_all 
	- 24487368.3088 * parameters.cpu_usage 
	- 0.1151 * parameters.avg_latency_of_same_past_second 
	+ 423723352.2374;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM48(work_wait &parameters) {
  double actual_remaining = 
	0.6097 * parameters.work_so_far 
	- 0.1553 * parameters.wait_so_far 
	- 47816304.8894 * parameters.num_locks_so_far 
	+ 324958.2212 * parameters.num_of_wait_locks 
	+ 4182282.0484 * parameters.total_wait_locks 
	- 8.0527 * parameters.mean_wait_of_all 
	- 24487368.3088 * parameters.cpu_usage 
	- 1.3077 * parameters.avg_latency_of_same_past_second 
	+ 388217245.1259;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM49(work_wait &parameters) {
  double actual_remaining = 
	0.6097 * parameters.work_so_far 
	- 0.1553 * parameters.wait_so_far 
	- 47816304.8894 * parameters.num_locks_so_far 
	+ 324958.2212 * parameters.num_of_wait_locks 
	+ 1573722.3311 * parameters.total_wait_locks 
	- 3.0807 * parameters.mean_wait_of_all 
	- 24487368.3088 * parameters.cpu_usage 
	- 0.3788 * parameters.avg_latency_of_same_past_second 
	+ 389306581.5573;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM50(work_wait &parameters) {
  double actual_remaining = 
	0.6097 * parameters.work_so_far 
	- 0.1553 * parameters.wait_so_far 
	- 47816304.8894 * parameters.num_locks_so_far 
	+ 324958.2212 * parameters.num_of_wait_locks 
	+ 1573722.3311 * parameters.total_wait_locks 
	- 1.4937 * parameters.mean_wait_of_all 
	- 24487368.3088 * parameters.cpu_usage 
	- 0.3788 * parameters.avg_latency_of_same_past_second 
	+ 366711356.1364;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM51(work_wait &parameters) {
  double actual_remaining = 
	0.6097 * parameters.work_so_far 
	- 0.1278 * parameters.wait_so_far 
	- 159159869.2754 * parameters.num_locks_so_far 
	+ 324958.2212 * parameters.num_of_wait_locks 
	- 62046.8199 * parameters.total_wait_locks 
	- 3.4242 * parameters.mean_wait_of_all 
	- 24487368.3088 * parameters.cpu_usage 
	- 1.6528 * parameters.avg_latency_of_same_past_second 
	+ 1400987062.6419;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM52(work_wait &parameters) {
  double actual_remaining = 
	0.6097 * parameters.work_so_far 
	- 0.0638 * parameters.wait_so_far 
	- 37148746.2945 * parameters.num_locks_so_far 
	+ 324958.2212 * parameters.num_of_wait_locks 
	+ 589841.8097 * parameters.total_wait_locks 
	- 1.3695 * parameters.mean_wait_of_all 
	- 24487368.3088 * parameters.cpu_usage 
	- 0.0618 * parameters.avg_latency_of_same_past_second 
	+ 261787358.387;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM53(work_wait &parameters) {
  double actual_remaining = 
	0.6097 * parameters.work_so_far 
	- 0.0638 * parameters.wait_so_far 
	- 37148746.2945 * parameters.num_locks_so_far 
	+ 324958.2212 * parameters.num_of_wait_locks 
	+ 768474.965 * parameters.total_wait_locks 
	- 1.3695 * parameters.mean_wait_of_all 
	- 24487368.3088 * parameters.cpu_usage 
	- 0.0618 * parameters.avg_latency_of_same_past_second 
	+ 287068811.0871;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM54(work_wait &parameters) {
  double actual_remaining = 
	11.2561 * parameters.work_so_far 
	- 0.0057 * parameters.wait_so_far 
	- 919249.1952 * parameters.num_locks_so_far 
	+ 324958.2212 * parameters.num_of_wait_locks 
	+ 64659.9659 * parameters.total_wait_locks 
	- 0.2732 * parameters.mean_wait_of_all 
	- 19007188.2169 * parameters.cpu_usage 
	+ 0.0084 * parameters.avg_latency_of_same_past_second 
	+ 64929984.5154;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM55(work_wait &parameters) {
  double actual_remaining = 
	0.1269 * parameters.work_so_far 
	- 0.001 * parameters.wait_so_far 
	- 311856.0637 * parameters.num_locks_so_far 
	+ 324958.2212 * parameters.num_of_wait_locks 
	+ 102627.83 * parameters.total_wait_locks 
	- 0.0778 * parameters.mean_wait_of_all 
	- 7122120.063 * parameters.cpu_usage 
	+ 0.0065 * parameters.avg_latency_of_same_past_second 
	+ 48341820.9785;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM56(work_wait &parameters) {
  double actual_remaining = 
	0.3707 * parameters.work_so_far 
	- 0.076 * parameters.wait_so_far 
	- 100320.9929 * parameters.num_locks_so_far 
	- 15211737.2401 * parameters.num_of_wait_locks 
	+ 1261594.1783 * parameters.total_wait_locks 
	- 3.4899 * parameters.mean_wait_of_all 
	- 431391224.3656 * parameters.cpu_usage 
	- 0.0031 * parameters.avg_latency_of_same_past_second 
	+ 565414499.6924;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM57(work_wait &parameters) {
  double actual_remaining = 
	13.8246 * parameters.work_so_far 
	+ 0.0053 * parameters.wait_so_far 
	- 5647158.8843 * parameters.num_locks_so_far 
	- 89265.0801 * parameters.num_of_wait_locks 
	+ 1136478.0106 * parameters.total_wait_locks 
	- 0.2315 * parameters.mean_wait_of_all 
	- 13779317.741 * parameters.cpu_usage 
	- 0.031 * parameters.avg_latency_of_same_past_second 
	+ 140556576.6735;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM58(work_wait &parameters) {
  double actual_remaining = 
	0.4798 * parameters.work_so_far 
	+ 0.0053 * parameters.wait_so_far 
	- 166472.0857 * parameters.num_locks_so_far 
	- 89265.0801 * parameters.num_of_wait_locks 
	+ 1392733.8069 * parameters.total_wait_locks 
	- 3.8957 * parameters.mean_wait_of_all 
	- 8155792.7156 * parameters.cpu_usage 
	- 0.0139 * parameters.avg_latency_of_same_past_second 
	+ 94568122.4451;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM59(work_wait &parameters) {
  double actual_remaining = 
	4.7909 * parameters.work_so_far 
	- 0.0634 * parameters.wait_so_far 
	- 220638.8019 * parameters.num_locks_so_far 
	- 37570864.4008 * parameters.num_of_wait_locks 
	+ 293745.3892 * parameters.total_wait_locks 
	- 0.0579 * parameters.mean_wait_of_all 
	- 5197147.0865 * parameters.cpu_usage 
	- 0.018 * parameters.avg_latency_of_same_past_second 
	+ 255931632.668;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM60(work_wait &parameters) {
  double actual_remaining = 
	4.7909 * parameters.work_so_far 
	- 0.0297 * parameters.wait_so_far 
	- 220638.8019 * parameters.num_locks_so_far 
	- 10015509.7974 * parameters.num_of_wait_locks 
	- 471217.9705 * parameters.total_wait_locks 
	+ 0.6978 * parameters.mean_wait_of_all 
	+ 306722414.6241 * parameters.cpu_usage 
	+ 0.4917 * parameters.avg_latency_of_same_past_second 
	- 4615802.5262;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM61(work_wait &parameters) {
  double actual_remaining = 
	4.7909 * parameters.work_so_far 
	- 0.0297 * parameters.wait_so_far 
	- 220638.8019 * parameters.num_locks_so_far 
	- 10015509.7974 * parameters.num_of_wait_locks 
	- 471217.9705 * parameters.total_wait_locks 
	+ 0.2803 * parameters.mean_wait_of_all 
	+ 306722414.6241 * parameters.cpu_usage 
	+ 0.258 * parameters.avg_latency_of_same_past_second 
	+ 41936971.3325;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM62(work_wait &parameters) {
  double actual_remaining = 
	-1154.5035 * parameters.work_so_far 
	- 0.3228 * parameters.wait_so_far 
	- 220638.8019 * parameters.num_locks_so_far 
	- 52918010.4 * parameters.num_of_wait_locks 
	- 641209.8282 * parameters.total_wait_locks 
	+ 1.7035 * parameters.mean_wait_of_all 
	+ 1509524686.097 * parameters.cpu_usage 
	- 0.018 * parameters.avg_latency_of_same_past_second 
	- 492845748.914;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM63(work_wait &parameters) {
  double actual_remaining = 
	-1213.6294 * parameters.work_so_far 
	- 0.3287 * parameters.wait_so_far 
	- 220638.8019 * parameters.num_locks_so_far 
	- 40047260.2192 * parameters.num_of_wait_locks 
	- 641209.8282 * parameters.total_wait_locks 
	+ 1.7035 * parameters.mean_wait_of_all 
	+ 1169478642.1025 * parameters.cpu_usage 
	- 0.018 * parameters.avg_latency_of_same_past_second 
	- 147904650.304;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM64(work_wait &parameters) {
  double actual_remaining = 
	-1161.4534 * parameters.work_so_far 
	- 0.3546 * parameters.wait_so_far 
	- 220638.8019 * parameters.num_locks_so_far 
	- 40047260.2192 * parameters.num_of_wait_locks 
	- 641209.8282 * parameters.total_wait_locks 
	+ 1.7035 * parameters.mean_wait_of_all 
	+ 1169478642.1025 * parameters.cpu_usage 
	- 0.018 * parameters.avg_latency_of_same_past_second 
	- 149731809.8243;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM65(work_wait &parameters) {
  double actual_remaining = 
	-806.7152 * parameters.work_so_far 
	- 0.2406 * parameters.wait_so_far 
	- 220638.8019 * parameters.num_locks_so_far 
	- 40047260.2192 * parameters.num_of_wait_locks 
	- 641209.8282 * parameters.total_wait_locks 
	+ 1.7035 * parameters.mean_wait_of_all 
	+ 1169478642.1025 * parameters.cpu_usage 
	- 0.018 * parameters.avg_latency_of_same_past_second 
	- 287647780.1972;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM66(work_wait &parameters) {
  double actual_remaining = 
	4.9192 * parameters.work_so_far 
	+ 0.7267 * parameters.wait_so_far 
	+ 4039169.7312 * parameters.num_locks_so_far 
	- 3457121.1512 * parameters.num_of_wait_locks 
	+ 1515119.1841 * parameters.total_wait_locks 
	- 3.4534 * parameters.mean_wait_of_all 
	- 509235416.8619 * parameters.cpu_usage 
	- 0.018 * parameters.avg_latency_of_same_past_second 
	+ 364733674.1726;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM67(work_wait &parameters) {
  double actual_remaining = 
	-2.0947 * parameters.work_so_far 
	- 0.0006 * parameters.wait_so_far 
	- 62324913.2927 * parameters.num_locks_so_far 
	- 27650038.352 * parameters.num_of_wait_locks 
	+ 1564014.965 * parameters.total_wait_locks 
	- 3.9135 * parameters.mean_wait_of_all 
	+ 85183.1765 * parameters.cpu_usage 
	+ 0.2041 * parameters.avg_latency_of_same_past_second 
	+ 330748796.9955;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM68(work_wait &parameters) {
  double actual_remaining = 
	-1385.6546 * parameters.work_so_far 
	- 0.0725 * parameters.wait_so_far 
	- 286858.6113 * parameters.num_locks_so_far 
	- 18043335.0901 * parameters.num_of_wait_locks 
	+ 647855.0478 * parameters.total_wait_locks 
	- 1.3964 * parameters.mean_wait_of_all 
	+ 85183.1765 * parameters.cpu_usage 
	+ 0.1609 * parameters.avg_latency_of_same_past_second 
	+ 179993643.2453;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM69(work_wait &parameters) {
  double actual_remaining = 
	1.5952 * parameters.work_so_far 
	+ 0.0205 * parameters.wait_so_far 
	- 35808533.8439 * parameters.num_locks_so_far 
	- 4982576.539 * parameters.num_of_wait_locks 
	+ 184770.0405 * parameters.total_wait_locks 
	- 0.5859 * parameters.mean_wait_of_all 
	+ 2244932.4625 * parameters.cpu_usage 
	+ 0.4059 * parameters.avg_latency_of_same_past_second 
	+ 201924905.3834;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM70(work_wait &parameters) {
  double actual_remaining = 
	21.3391 * parameters.work_so_far 
	+ 0.0157 * parameters.wait_so_far 
	- 1698073.89 * parameters.num_locks_so_far 
	- 97521914.2015 * parameters.num_of_wait_locks 
	+ 2358940.4723 * parameters.total_wait_locks 
	- 6.2737 * parameters.mean_wait_of_all 
	+ 2244932.4625 * parameters.cpu_usage 
	+ 0.0372 * parameters.avg_latency_of_same_past_second 
	+ 240475699.0537;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM71(work_wait &parameters) {
  double actual_remaining = 
	3.6048 * parameters.work_so_far 
	+ 0.0147 * parameters.wait_so_far 
	- 3973341.5366 * parameters.num_locks_so_far 
	+ 175101597.8463 * parameters.num_of_wait_locks 
	+ 128481.9143 * parameters.total_wait_locks 
	- 0.3903 * parameters.mean_wait_of_all 
	+ 2244932.4625 * parameters.cpu_usage 
	+ 0.0526 * parameters.avg_latency_of_same_past_second 
	- 94800073.1378;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM72(work_wait &parameters) {
  double actual_remaining = 
	0.969 * parameters.work_so_far 
	- 0.1644 * parameters.wait_so_far 
	- 1021855.8556 * parameters.num_locks_so_far 
	- 47696721.1284 * parameters.num_of_wait_locks 
	+ 1199070.8077 * parameters.total_wait_locks 
	- 4.2843 * parameters.mean_wait_of_all 
	+ 2244932.4625 * parameters.cpu_usage 
	+ 0.0172 * parameters.avg_latency_of_same_past_second 
	+ 353847273.9378;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM73(work_wait &parameters) {
  double actual_remaining = 
	8.555 * parameters.work_so_far 
	+ 0.0112 * parameters.wait_so_far 
	- 7881230.0702 * parameters.num_locks_so_far 
	+ 146410688.2585 * parameters.num_of_wait_locks 
	+ 1955303.0783 * parameters.total_wait_locks 
	- 5.7383 * parameters.mean_wait_of_all 
	+ 25000890.6045 * parameters.cpu_usage 
	+ 0.6116 * parameters.avg_latency_of_same_past_second 
	- 403159973.5754;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM74(work_wait &parameters) {
  double actual_remaining = 
	1.3852 * parameters.work_so_far 
	+ 0.0112 * parameters.wait_so_far 
	+ 5961003.0176 * parameters.num_locks_so_far 
	- 1334806.3348 * parameters.num_of_wait_locks 
	- 1981712.4974 * parameters.total_wait_locks 
	+ 5.793 * parameters.mean_wait_of_all 
	+ 26553210.7652 * parameters.cpu_usage 
	+ 0.0685 * parameters.avg_latency_of_same_past_second 
	+ 401750383.7826;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM75(work_wait &parameters) {
  double actual_remaining = 
	1.4128 * parameters.work_so_far 
	+ 0.0112 * parameters.wait_so_far 
	+ 17990310.8984 * parameters.num_locks_so_far 
	+ 42028886.4467 * parameters.num_of_wait_locks 
	+ 642771.7112 * parameters.total_wait_locks 
	- 0.1037 * parameters.mean_wait_of_all 
	+ 8497276.2643 * parameters.cpu_usage 
	+ 0.064 * parameters.avg_latency_of_same_past_second 
	- 191691986.1389;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM76(work_wait &parameters) {
  double actual_remaining = 
	1.4128 * parameters.work_so_far 
	+ 0.0112 * parameters.wait_so_far 
	+ 50247408.5574 * parameters.num_locks_so_far 
	+ 22990026.1637 * parameters.num_of_wait_locks 
	+ 347719.5824 * parameters.total_wait_locks 
	- 0.1037 * parameters.mean_wait_of_all 
	+ 8497276.2643 * parameters.cpu_usage 
	+ 0.064 * parameters.avg_latency_of_same_past_second 
	- 127856077.004;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM77(work_wait &parameters) {
  double actual_remaining = 
	1.4128 * parameters.work_so_far 
	+ 0.0112 * parameters.wait_so_far 
	- 11998564.0729 * parameters.num_locks_so_far 
	+ 25757016.036 * parameters.num_of_wait_locks 
	+ 137904.7353 * parameters.total_wait_locks 
	- 0.1037 * parameters.mean_wait_of_all 
	+ 8497276.2643 * parameters.cpu_usage 
	+ 0.064 * parameters.avg_latency_of_same_past_second 
	+ 541716958.036;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM78(work_wait &parameters) {
  double actual_remaining = 
	11.4012 * parameters.work_so_far 
	+ 0.7489 * parameters.wait_so_far 
	- 7969278.9 * parameters.num_locks_so_far 
	+ 1955243.7511 * parameters.num_of_wait_locks 
	+ 923081.2438 * parameters.total_wait_locks 
	- 3.0411 * parameters.mean_wait_of_all 
	+ 303487248.9113 * parameters.cpu_usage 
	+ 0.2834 * parameters.avg_latency_of_same_past_second 
	- 306157144.2833;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM79(work_wait &parameters) {
  double actual_remaining = 
	2.7006 * parameters.work_so_far 
	+ 0.1567 * parameters.wait_so_far 
	- 7986611.5816 * parameters.num_locks_so_far 
	+ 67676959.5225 * parameters.num_of_wait_locks 
	+ 282104.622 * parameters.total_wait_locks 
	- 2.4295 * parameters.mean_wait_of_all 
	+ 18584820.6457 * parameters.cpu_usage 
	+ 0.109 * parameters.avg_latency_of_same_past_second 
	+ 230740227.172;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM80(work_wait &parameters) {
  double actual_remaining = 
	2.7006 * parameters.work_so_far 
	+ 0.1567 * parameters.wait_so_far 
	- 7321977.0523 * parameters.num_locks_so_far 
	+ 59404742.1116 * parameters.num_of_wait_locks 
	+ 282104.622 * parameters.total_wait_locks 
	- 2.0847 * parameters.mean_wait_of_all 
	+ 18584820.6457 * parameters.cpu_usage 
	+ 0.0331 * parameters.avg_latency_of_same_past_second 
	+ 323518168.9842;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM81(work_wait &parameters) {
  double actual_remaining = 
	2.7006 * parameters.work_so_far 
	+ 0.5633 * parameters.wait_so_far 
	- 4039478.7257 * parameters.num_locks_so_far 
	+ 20633875.8451 * parameters.num_of_wait_locks 
	- 2914846.1864 * parameters.total_wait_locks 
	+ 7.014 * parameters.mean_wait_of_all 
	+ 18584820.6457 * parameters.cpu_usage 
	+ 0.0331 * parameters.avg_latency_of_same_past_second 
	+ 582514470.9993;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM82(work_wait &parameters) {
  double actual_remaining = 
	-131.388 * parameters.work_so_far 
	- 0.3199 * parameters.wait_so_far 
	- 181419.8 * parameters.num_locks_so_far 
	- 25990308.3116 * parameters.num_of_wait_locks 
	+ 4895.9381 * parameters.total_wait_locks 
	+ 1.6318 * parameters.mean_wait_of_all 
	+ 5144975.6424 * parameters.cpu_usage 
	+ 0.008 * parameters.avg_latency_of_same_past_second 
	+ 364232209.2317;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM83(work_wait &parameters) {
  double actual_remaining = 
	0.5298 * parameters.work_so_far 
	+ 0.2074 * parameters.wait_so_far 
	- 21055745.9805 * parameters.num_locks_so_far 
	- 11755948.4267 * parameters.num_of_wait_locks 
	+ 1410780.2305 * parameters.total_wait_locks 
	- 4.3212 * parameters.mean_wait_of_all 
	+ 309691477.7506 * parameters.cpu_usage 
	+ 0.3572 * parameters.avg_latency_of_same_past_second 
	- 199782599.0058;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM84(work_wait &parameters) {
  double actual_remaining = 
	1.3323 * parameters.work_so_far 
	- 0.1658 * parameters.wait_so_far 
	+ 1129800.1455 * parameters.num_locks_so_far 
	+ 43799685.6951 * parameters.num_of_wait_locks 
	+ 599719.0253 * parameters.total_wait_locks 
	- 1.4587 * parameters.mean_wait_of_all 
	+ 463320610.7761 * parameters.cpu_usage 
	- 1.2369 * parameters.avg_latency_of_same_past_second 
	+ 137462897.4021;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM85(work_wait &parameters) {
  double actual_remaining = 
	1.3323 * parameters.work_so_far 
	+ 0.5506 * parameters.wait_so_far 
	+ 21965979.5829 * parameters.num_locks_so_far 
	+ 24588357.4415 * parameters.num_of_wait_locks 
	+ 862418.141 * parameters.total_wait_locks 
	- 2.1271 * parameters.mean_wait_of_all 
	+ 438333668.7638 * parameters.cpu_usage 
	- 1.218 * parameters.avg_latency_of_same_past_second 
	- 35204443.7784;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM86(work_wait &parameters) {
  double actual_remaining = 
	1.3323 * parameters.work_so_far 
	+ 0.1353 * parameters.wait_so_far 
	+ 1129800.1455 * parameters.num_locks_so_far 
	+ 24588357.4415 * parameters.num_of_wait_locks 
	+ 1045960.2229 * parameters.total_wait_locks 
	- 2.5674 * parameters.mean_wait_of_all 
	+ 523443965.7724 * parameters.cpu_usage 
	- 1.4876 * parameters.avg_latency_of_same_past_second 
	+ 231256509.7094;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM87(work_wait &parameters) {
  double actual_remaining = 
	8.6135 * parameters.work_so_far 
	+ 0.0015 * parameters.wait_so_far 
	+ 875715.3775 * parameters.num_locks_so_far 
	+ 10014665.0745 * parameters.num_of_wait_locks 
	+ 708709.4102 * parameters.total_wait_locks 
	- 0.2655 * parameters.mean_wait_of_all 
	+ 14973541.0859 * parameters.cpu_usage 
	+ 0.3665 * parameters.avg_latency_of_same_past_second 
	- 79685495.6676;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM88(work_wait &parameters) {
  double actual_remaining = 
	1.7881 * parameters.work_so_far 
	+ 0.0015 * parameters.wait_so_far 
	+ 1653173.3371 * parameters.num_locks_so_far 
	+ 344483682.6378 * parameters.num_of_wait_locks 
	+ 89309.5347 * parameters.total_wait_locks 
	- 0.2655 * parameters.mean_wait_of_all 
	+ 491100240.0054 * parameters.cpu_usage 
	+ 0.099 * parameters.avg_latency_of_same_past_second 
	- 691110856.0341;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM89(work_wait &parameters) {
  double actual_remaining = 
	0.5937 * parameters.work_so_far 
	- 0.0016 * parameters.wait_so_far 
	+ 107847.706 * parameters.num_locks_so_far 
	+ 12066.5516 * parameters.num_of_wait_locks 
	+ 3283624.9753 * parameters.total_wait_locks 
	- 9.2299 * parameters.mean_wait_of_all 
	+ 20056557.6345 * parameters.cpu_usage 
	+ 0.0413 * parameters.avg_latency_of_same_past_second 
	- 92780272.3736;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM90(work_wait &parameters) {
  double actual_remaining = 
	18.516 * parameters.work_so_far 
	+ 0.7304 * parameters.wait_so_far 
	- 11561768.9846 * parameters.num_locks_so_far 
	+ 16314536.3724 * parameters.num_of_wait_locks 
	+ 26131.8862 * parameters.total_wait_locks 
	- 0.0626 * parameters.mean_wait_of_all 
	+ 8659019.1845 * parameters.cpu_usage 
	+ 0.0134 * parameters.avg_latency_of_same_past_second 
	+ 162917629.9612;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM91(work_wait &parameters) {
  double actual_remaining = 
	0.696 * parameters.work_so_far 
	+ 0.0058 * parameters.wait_so_far 
	+ 222035.5258 * parameters.num_locks_so_far 
	+ 3546433.6877 * parameters.num_of_wait_locks 
	- 524733.0499 * parameters.total_wait_locks 
	+ 1.542 * parameters.mean_wait_of_all 
	+ 22047780.5623 * parameters.cpu_usage 
	- 0.1218 * parameters.avg_latency_of_same_past_second 
	+ 152594780.3889;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM92(work_wait &parameters) {
  double actual_remaining = 
	0.696 * parameters.work_so_far 
	+ 0.0024 * parameters.wait_so_far 
	- 5630801.9956 * parameters.num_locks_so_far 
	+ 3546433.6877 * parameters.num_of_wait_locks 
	- 4116369.307 * parameters.total_wait_locks 
	+ 11.8973 * parameters.mean_wait_of_all 
	+ 582694115.6763 * parameters.cpu_usage 
	+ 0.0584 * parameters.avg_latency_of_same_past_second 
	+ 107325875.9102;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM93(work_wait &parameters) {
  double actual_remaining = 
	2.1163 * parameters.work_so_far 
	+ 0.0518 * parameters.wait_so_far 
	+ 666579.9742 * parameters.num_locks_so_far 
	- 4198566.2139 * parameters.num_of_wait_locks 
	+ 259795.7435 * parameters.total_wait_locks 
	- 0.5663 * parameters.mean_wait_of_all 
	+ 52593003.6102 * parameters.cpu_usage 
	+ 0.3548 * parameters.avg_latency_of_same_past_second 
	- 96724471.6614;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM94(work_wait &parameters) {
  double actual_remaining = 
	1.7865 * parameters.work_so_far 
	+ 0.6604 * parameters.wait_so_far 
	+ 666579.9742 * parameters.num_locks_so_far 
	- 36773595.9771 * parameters.num_of_wait_locks 
	+ 1264018.2377 * parameters.total_wait_locks 
	- 0.8313 * parameters.mean_wait_of_all 
	+ 452357157.3557 * parameters.cpu_usage 
	+ 0.0714 * parameters.avg_latency_of_same_past_second 
	- 705776705.3371;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM95(work_wait &parameters) {
  double actual_remaining = 
	1.7865 * parameters.work_so_far 
	+ 0.1287 * parameters.wait_so_far 
	+ 666579.9742 * parameters.num_locks_so_far 
	- 191545909.8678 * parameters.num_of_wait_locks 
	+ 766184.9936 * parameters.total_wait_locks 
	- 1.4566 * parameters.mean_wait_of_all 
	+ 126784952.4129 * parameters.cpu_usage 
	+ 0.1197 * parameters.avg_latency_of_same_past_second 
	+ 879402642.9661;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM96(work_wait &parameters) {
  double actual_remaining = 
	12.73 * parameters.work_so_far 
	+ 0.8257 * parameters.wait_so_far 
	- 6014045.2707 * parameters.num_locks_so_far 
	- 19006761.7063 * parameters.num_of_wait_locks 
	+ 898477.9153 * parameters.total_wait_locks 
	- 2.4649 * parameters.mean_wait_of_all 
	- 5977772.6077 * parameters.cpu_usage 
	+ 0.0116 * parameters.avg_latency_of_same_past_second 
	+ 145015631.8434;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM97(work_wait &parameters) {
  double actual_remaining = 
	10.4614 * parameters.work_so_far 
	+ 0.8453 * parameters.wait_so_far 
	- 4852923.1576 * parameters.num_locks_so_far 
	- 27764806.1774 * parameters.num_of_wait_locks 
	+ 805903.3401 * parameters.total_wait_locks 
	- 2.8221 * parameters.mean_wait_of_all 
	- 143683473.9145 * parameters.cpu_usage 
	- 0.0606 * parameters.avg_latency_of_same_past_second 
	+ 396208208.0157;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM98(work_wait &parameters) {
  double actual_remaining = 
	2.7627 * parameters.work_so_far 
	+ 0.7031 * parameters.wait_so_far 
	+ 1534.6103 * parameters.num_locks_so_far 
	- 3693035.3835 * parameters.num_of_wait_locks 
	+ 141266.6308 * parameters.total_wait_locks 
	+ 1.5566 * parameters.mean_wait_of_all 
	- 869728130.4793 * parameters.cpu_usage 
	- 0.1414 * parameters.avg_latency_of_same_past_second 
	+ 1000562624.7988;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM99(work_wait &parameters) {
  double actual_remaining = 
	2.7627 * parameters.work_so_far 
	+ 0.8197 * parameters.wait_so_far 
	+ 1534.6103 * parameters.num_locks_so_far 
	- 3693035.3835 * parameters.num_of_wait_locks 
	+ 141266.6308 * parameters.total_wait_locks 
	- 0.3388 * parameters.mean_wait_of_all 
	- 889477946.1183 * parameters.cpu_usage 
	- 0.1414 * parameters.avg_latency_of_same_past_second 
	+ 888198430.5903;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM100(work_wait &parameters) {
  double actual_remaining = 
	2.7627 * parameters.work_so_far 
	+ 0.904 * parameters.wait_so_far 
	+ 1534.6103 * parameters.num_locks_so_far 
	- 3693035.3835 * parameters.num_of_wait_locks 
	+ 141266.6308 * parameters.total_wait_locks 
	- 0.3388 * parameters.mean_wait_of_all 
	- 889477946.1183 * parameters.cpu_usage 
	- 0.1414 * parameters.avg_latency_of_same_past_second 
	+ 867239439.8081;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM101(work_wait &parameters) {
  double actual_remaining = 
	0.0159 * parameters.work_so_far 
	- 0.2181 * parameters.wait_so_far 
	- 3168310.9174 * parameters.num_locks_so_far 
	+ 819074.9481 * parameters.num_of_wait_locks 
	- 6347.0899 * parameters.total_wait_locks 
	+ 0.0263 * parameters.mean_wait_of_all 
	- 283072.9631 * parameters.cpu_usage 
	+ 0.2998 * parameters.avg_latency_of_same_past_second 
	+ 199378959.188;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM102(work_wait &parameters) {
  double actual_remaining = 
	0.0159 * parameters.work_so_far 
	- 0.0411 * parameters.wait_so_far 
	- 96165.4349 * parameters.num_locks_so_far 
	+ 819074.9481 * parameters.num_of_wait_locks 
	+ 170748.6031 * parameters.total_wait_locks 
	- 0.3262 * parameters.mean_wait_of_all 
	- 53460396.3055 * parameters.cpu_usage 
	+ 0.023 * parameters.avg_latency_of_same_past_second 
	+ 61238002.6181;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM103(work_wait &parameters) {
  double actual_remaining = 
	1.4568 * parameters.work_so_far 
	+ 0.1724 * parameters.wait_so_far 
	- 169535.6796 * parameters.num_locks_so_far 
	- 77226542.9907 * parameters.num_of_wait_locks 
	+ 2052305.0513 * parameters.total_wait_locks 
	- 5.5519 * parameters.mean_wait_of_all 
	- 201015745.5821 * parameters.cpu_usage 
	+ 0.004 * parameters.avg_latency_of_same_past_second 
	+ 570480222.6491;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM104(work_wait &parameters) {
  double actual_remaining = 
	2.7137 * parameters.work_so_far 
	+ 0.9736 * parameters.wait_so_far 
	- 3910343.1276 * parameters.num_locks_so_far 
	- 1693867.47 * parameters.num_of_wait_locks 
	+ 121434.2951 * parameters.total_wait_locks 
	- 0.047 * parameters.mean_wait_of_all 
	- 4562196.4784 * parameters.cpu_usage 
	+ 0.004 * parameters.avg_latency_of_same_past_second 
	+ 200046648.1105;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM105(work_wait &parameters) {
  double actual_remaining = 
	0.2177 * parameters.work_so_far 
	+ 0.1131 * parameters.wait_so_far 
	+ 13550475.5395 * parameters.num_locks_so_far 
	- 16058249.4159 * parameters.num_of_wait_locks 
	+ 224589.2226 * parameters.total_wait_locks 
	- 0.6199 * parameters.mean_wait_of_all 
	- 80739660.6813 * parameters.cpu_usage 
	+ 0.0171 * parameters.avg_latency_of_same_past_second 
	+ 452504461.1727;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM106(work_wait &parameters) {
  double actual_remaining = 
	0.692 * parameters.work_so_far 
	+ 0.6701 * parameters.wait_so_far 
	- 507411.7612 * parameters.num_locks_so_far 
	- 10329017.1273 * parameters.num_of_wait_locks 
	+ 1239053.8164 * parameters.total_wait_locks 
	- 3.2955 * parameters.mean_wait_of_all 
	- 48079425.4883 * parameters.cpu_usage 
	- 0.181 * parameters.avg_latency_of_same_past_second 
	+ 327579896.4393;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM107(work_wait &parameters) {
  double actual_remaining = 
	0.3051 * parameters.work_so_far 
	+ 0.2201 * parameters.wait_so_far 
	- 7338332.2175 * parameters.num_locks_so_far 
	- 136003187.7475 * parameters.num_of_wait_locks 
	- 76667.6324 * parameters.total_wait_locks 
	+ 0.3967 * parameters.mean_wait_of_all 
	- 39503881.691 * parameters.cpu_usage 
	+ 0.0171 * parameters.avg_latency_of_same_past_second 
	+ 1081073240.9567;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM108(work_wait &parameters) {
  double actual_remaining = 
	0.7309 * parameters.work_so_far 
	+ 0.877 * parameters.wait_so_far 
	- 783180.9316 * parameters.num_locks_so_far 
	- 14890999.4293 * parameters.num_of_wait_locks 
	+ 14417.921 * parameters.total_wait_locks 
	+ 0.0479 * parameters.mean_wait_of_all 
	- 260952157.1062 * parameters.cpu_usage 
	+ 0.0171 * parameters.avg_latency_of_same_past_second 
	+ 607732260.2588;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM109(work_wait &parameters) {
  double actual_remaining = 
	0.366 * parameters.work_so_far 
	+ 0.0445 * parameters.wait_so_far 
	+ 10757043.439 * parameters.num_locks_so_far 
	- 50759012.0169 * parameters.num_of_wait_locks 
	+ 3269903.2885 * parameters.total_wait_locks 
	- 6.7914 * parameters.mean_wait_of_all 
	- 30237152.2814 * parameters.cpu_usage 
	+ 0.131 * parameters.avg_latency_of_same_past_second 
	- 25952911.7697;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM110(work_wait &parameters) {
  double actual_remaining = 
	0.6484 * parameters.work_so_far 
	+ 0.0445 * parameters.wait_so_far 
	+ 7572411.902 * parameters.num_locks_so_far 
	- 50759012.0169 * parameters.num_of_wait_locks 
	+ 2241135.7964 * parameters.total_wait_locks 
	- 5.3184 * parameters.mean_wait_of_all 
	- 30237152.2814 * parameters.cpu_usage 
	+ 0.131 * parameters.avg_latency_of_same_past_second 
	+ 368365412.194;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM111(work_wait &parameters) {
  double actual_remaining = 
	0.6591 * parameters.work_so_far 
	+ 0.0445 * parameters.wait_so_far 
	+ 7572411.902 * parameters.num_locks_so_far 
	- 50759012.0169 * parameters.num_of_wait_locks 
	+ 2241135.7964 * parameters.total_wait_locks 
	- 5.3184 * parameters.mean_wait_of_all 
	- 30237152.2814 * parameters.cpu_usage 
	+ 0.131 * parameters.avg_latency_of_same_past_second 
	+ 372313394.9767;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM112(work_wait &parameters) {
  double actual_remaining = 
	0.581 * parameters.work_so_far 
	+ 0.0803 * parameters.wait_so_far 
	+ 7572411.902 * parameters.num_locks_so_far 
	- 50759012.0169 * parameters.num_of_wait_locks 
	+ 2185576.1272 * parameters.total_wait_locks 
	- 5.3184 * parameters.mean_wait_of_all 
	- 30237152.2814 * parameters.cpu_usage 
	+ 0.131 * parameters.avg_latency_of_same_past_second 
	+ 374368363.097;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM113(work_wait &parameters) {
  double actual_remaining = 
	0.581 * parameters.work_so_far 
	+ 0.0845 * parameters.wait_so_far 
	+ 7572411.902 * parameters.num_locks_so_far 
	- 50759012.0169 * parameters.num_of_wait_locks 
	+ 2185576.1272 * parameters.total_wait_locks 
	- 5.3184 * parameters.mean_wait_of_all 
	- 30237152.2814 * parameters.cpu_usage 
	+ 0.131 * parameters.avg_latency_of_same_past_second 
	+ 376193460.8323;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM114(work_wait &parameters) {
  double actual_remaining = 
	0.5263 * parameters.work_so_far 
	+ 0.0445 * parameters.wait_so_far 
	+ 7572411.902 * parameters.num_locks_so_far 
	- 50759012.0169 * parameters.num_of_wait_locks 
	+ 2532824.0597 * parameters.total_wait_locks 
	- 49.7056 * parameters.mean_wait_of_all 
	- 30237152.2814 * parameters.cpu_usage 
	+ 0.131 * parameters.avg_latency_of_same_past_second 
	+ 4814922404.6695;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM115(work_wait &parameters) {
  double actual_remaining = 
	0.8215 * parameters.work_so_far 
	+ 0.5246 * parameters.wait_so_far 
	- 4902215.4542 * parameters.num_locks_so_far 
	- 31164105.3337 * parameters.num_of_wait_locks 
	+ 105030.25 * parameters.total_wait_locks 
	- 1.5879 * parameters.mean_wait_of_all 
	- 30237152.2814 * parameters.cpu_usage 
	+ 0.3776 * parameters.avg_latency_of_same_past_second 
	+ 530749521.4046;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM116(work_wait &parameters) {
  double actual_remaining = 
	0.8937 * parameters.work_so_far 
	+ 0.0445 * parameters.wait_so_far 
	- 4280486.5098 * parameters.num_locks_so_far 
	- 65831874.9796 * parameters.num_of_wait_locks 
	+ 16439.1767 * parameters.total_wait_locks 
	- 0.0428 * parameters.mean_wait_of_all 
	- 30237152.2814 * parameters.cpu_usage 
	+ 0.3049 * parameters.avg_latency_of_same_past_second 
	+ 538650560.6485;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM117(work_wait &parameters) {
  double actual_remaining = 
	1.0543 * parameters.work_so_far 
	+ 0.0445 * parameters.wait_so_far 
	- 10695274.679 * parameters.num_locks_so_far 
	- 64345546.8864 * parameters.num_of_wait_locks 
	+ 16439.1767 * parameters.total_wait_locks 
	- 0.0428 * parameters.mean_wait_of_all 
	- 30237152.2814 * parameters.cpu_usage 
	+ 0.2948 * parameters.avg_latency_of_same_past_second 
	+ 847362661.6454;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM118(work_wait &parameters) {
  double actual_remaining = 
	0.0912 * parameters.work_so_far 
	+ 0.0795 * parameters.wait_so_far 
	+ 440615.8484 * parameters.num_locks_so_far 
	- 9247526.942 * parameters.num_of_wait_locks 
	- 206083.1708 * parameters.total_wait_locks 
	+ 0.7603 * parameters.mean_wait_of_all 
	- 3481184.2113 * parameters.cpu_usage 
	+ 0.0053 * parameters.avg_latency_of_same_past_second 
	+ 276868447.9856;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM119(work_wait &parameters) {
  double actual_remaining = 
	1.3685 * parameters.work_so_far 
	+ 0.9162 * parameters.wait_so_far 
	- 6049251.684 * parameters.num_locks_so_far 
	- 3949508.2556 * parameters.num_of_wait_locks 
	- 1502497.9391 * parameters.total_wait_locks 
	+ 5.3322 * parameters.mean_wait_of_all 
	- 3481184.2113 * parameters.cpu_usage 
	+ 0.2 * parameters.avg_latency_of_same_past_second 
	+ 369295699.0216;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
static
double
tpcc_estimate(work_wait &parameters){

  if (parameters.num_locks_so_far <= 2.5) {

    if (parameters.total_wait_locks <= 116.5) {

      if (parameters.work_so_far <= 7693.5) {

        if (parameters.work_so_far <= 6615.5) {
          return tpcc_LM1(parameters);
        } else if (parameters.work_so_far >  6615.5) {

          if (parameters.total_wait_locks <= 45.5) {

            if (parameters.mean_wait_of_all <= 26742500) {

              if (parameters.wait_so_far <= 28584438.5) {

                if (parameters.work_so_far <= 6948) {
                  return tpcc_LM2(parameters);
                } else if (parameters.work_so_far >  6948) {
                  return tpcc_LM3(parameters);
                }
              } else if (parameters.wait_so_far >  28584438.5) {
                return tpcc_LM4(parameters);
              }
            } else if (parameters.mean_wait_of_all >  26742500) {
              return tpcc_LM5(parameters);
            }
          } else if (parameters.total_wait_locks >  45.5) {
            return tpcc_LM6(parameters);
          }
        }
      } else if (parameters.work_so_far >  7693.5) {

        if (parameters.work_so_far <= 11087) {

          if (parameters.wait_so_far <= 28297652.5) {

            if (parameters.avg_latency_of_same_past_second <= 94954150) {
              return tpcc_LM7(parameters);
            } else if (parameters.avg_latency_of_same_past_second >  94954150) {
              return tpcc_LM8(parameters);
            }
          } else if (parameters.wait_so_far >  28297652.5) {

            if (parameters.num_of_wait_locks <= 2.5) {

              if (parameters.num_of_wait_locks <= 1.5) {

                if (parameters.avg_latency_of_same_past_second <= 77750500) {
                  return tpcc_LM9(parameters);
                } else if (parameters.avg_latency_of_same_past_second >  77750500) {
                  return tpcc_LM10(parameters);
                }
              } else if (parameters.num_of_wait_locks >  1.5) {

                if (parameters.wait_so_far <= 57649416.5) {
                  return tpcc_LM11(parameters);
                } else if (parameters.wait_so_far >  57649416.5) {

                  if (parameters.work_so_far <= 9845.5) {

                    if (parameters.total_wait_locks <= 54.5) {
                      return tpcc_LM12(parameters);
                    } else if (parameters.total_wait_locks >  54.5) {

                      if (parameters.total_wait_locks <= 63.5) {

                        if (parameters.avg_latency_of_same_past_second <= 17731650) {
                          return tpcc_LM13(parameters);
                        } else if (parameters.avg_latency_of_same_past_second >  17731650) {
                          return tpcc_LM14(parameters);
                        }
                      } else if (parameters.total_wait_locks >  63.5) {
                        return tpcc_LM15(parameters);
                      }
                    }
                  } else if (parameters.work_so_far >  9845.5) {
                    return tpcc_LM16(parameters);
                  }
                }
              }
            } else if (parameters.num_of_wait_locks >  2.5) {
              return tpcc_LM17(parameters);
            }
          }
        } else if (parameters.work_so_far >  11087) {

          if (parameters.num_of_wait_locks <= 2.5) {

            if (parameters.avg_latency_of_same_past_second <= 81378550) {
              return tpcc_LM18(parameters);
            } else if (parameters.avg_latency_of_same_past_second >  81378550) {

              if (parameters.cpu_usage <= 0.89) {
                return tpcc_LM19(parameters);
              } else if (parameters.cpu_usage >  0.89) {
                return tpcc_LM20(parameters);
              }
            }
          } else if (parameters.num_of_wait_locks >  2.5) {

            if (parameters.work_so_far <= 29949) {
              return tpcc_LM21(parameters);
            } else if (parameters.work_so_far >  29949) {
              return tpcc_LM22(parameters);
            }
          }
        }
      }
    } else if (parameters.total_wait_locks >  116.5) {

      if (parameters.num_of_wait_locks <= 2.5) {

        if (parameters.avg_latency_of_same_past_second <= 474400500) {

          if (parameters.work_so_far <= 60340) {
            return tpcc_LM23(parameters);
          } else if (parameters.work_so_far >  60340) {
            return tpcc_LM24(parameters);
          }
        } else if (parameters.avg_latency_of_same_past_second >  474400500) {

          if (parameters.avg_latency_of_same_past_second <= 646035500) {
            return tpcc_LM25(parameters);
          } else if (parameters.avg_latency_of_same_past_second >  646035500) {

            if (parameters.work_so_far <= 36357.5) {
              return tpcc_LM26(parameters);
            } else if (parameters.work_so_far >  36357.5) {
              return tpcc_LM27(parameters);
            }
          }
        }
      } else if (parameters.num_of_wait_locks >  2.5) {

        if (parameters.work_so_far <= 507949) {
          return tpcc_LM28(parameters);
        } else if (parameters.work_so_far >  507949) {

          if (parameters.wait_so_far <= 491324462) {
            return tpcc_LM29(parameters);
          } else if (parameters.wait_so_far >  491324462) {

            if (parameters.work_so_far <= 4631505.5) {

              if (parameters.wait_so_far <= 844007903) {

                if (parameters.work_so_far <= 975438) {
                  return tpcc_LM30(parameters);
                } else if (parameters.work_so_far >  975438) {
                  return tpcc_LM31(parameters);
                }
              } else if (parameters.wait_so_far >  844007903) {
                return tpcc_LM32(parameters);
              }
            } else if (parameters.work_so_far >  4631505.5) {
              return tpcc_LM33(parameters);
            }
          }
        }
      }
    }
  } else if (parameters.num_locks_so_far >  2.5) {

    if (parameters.total_wait_locks <= 94.5) {

      if (parameters.work_so_far <= 22085843.5) {

        if (parameters.num_of_wait_locks <= 1.5) {

          if (parameters.avg_latency_of_same_past_second <= 33273400) {

            if (parameters.num_locks_so_far <= 32.5) {
              return tpcc_LM34(parameters);
            } else if (parameters.num_locks_so_far >  32.5) {
              return tpcc_LM35(parameters);
            }
          } else if (parameters.avg_latency_of_same_past_second >  33273400) {

            if (parameters.num_locks_so_far <= 6) {

              if (parameters.work_so_far <= 30820) {

                if (parameters.wait_so_far <= 34775360.5) {
                  return tpcc_LM36(parameters);
                } else if (parameters.wait_so_far >  34775360.5) {
                  return tpcc_LM37(parameters);
                }
              } else if (parameters.work_so_far >  30820) {

                if (parameters.mean_wait_of_all <= 27829700) {
                  return tpcc_LM38(parameters);
                } else if (parameters.mean_wait_of_all >  27829700) {
                  return tpcc_LM39(parameters);
                }
              }
            } else if (parameters.num_locks_so_far >  6) {

              if (parameters.num_locks_so_far <= 12.5) {
                return tpcc_LM40(parameters);
              } else if (parameters.num_locks_so_far >  12.5) {

                if (parameters.num_locks_so_far <= 23.5) {
                  return tpcc_LM41(parameters);
                } else if (parameters.num_locks_so_far >  23.5) {

                  if (parameters.num_locks_so_far <= 90.5) {
                    return tpcc_LM42(parameters);
                  } else if (parameters.num_locks_so_far >  90.5) {
                    return tpcc_LM43(parameters);
                  }
                }
              }
            }
          }
        } else if (parameters.num_of_wait_locks >  1.5) {
          return tpcc_LM44(parameters);
        }
      } else if (parameters.work_so_far >  22085843.5) {
        return tpcc_LM45(parameters);
      }
    } else if (parameters.total_wait_locks >  94.5) {

      if (parameters.work_so_far <= 14581279.5) {

        if (parameters.avg_latency_of_same_past_second <= 364785000) {

          if (parameters.num_of_wait_locks <= 1.5) {

            if (parameters.num_locks_so_far <= 14.5) {

              if (parameters.num_locks_so_far <= 4.5) {

                if (parameters.mean_wait_of_all <= 38189500) {

                  if (parameters.avg_latency_of_same_past_second <= 254484000) {

                    if (parameters.total_wait_locks <= 113.5) {
                      return tpcc_LM46(parameters);
                    } else if (parameters.total_wait_locks >  113.5) {

                      if (parameters.mean_wait_of_all <= 27052100) {
                        return tpcc_LM47(parameters);
                      } else if (parameters.mean_wait_of_all >  27052100) {

                        if (parameters.mean_wait_of_all <= 28661350) {
                          return tpcc_LM48(parameters);
                        } else if (parameters.mean_wait_of_all >  28661350) {

                          if (parameters.mean_wait_of_all <= 37950550) {
                            return tpcc_LM49(parameters);
                          } else if (parameters.mean_wait_of_all >  37950550) {
                            return tpcc_LM50(parameters);
                          }
                        }
                      }
                    }
                  } else if (parameters.avg_latency_of_same_past_second >  254484000) {
                    return tpcc_LM51(parameters);
                  }
                } else if (parameters.mean_wait_of_all >  38189500) {

                  if (parameters.total_wait_locks <= 170.5) {
                    return tpcc_LM52(parameters);
                  } else if (parameters.total_wait_locks >  170.5) {
                    return tpcc_LM53(parameters);
                  }
                }
              } else if (parameters.num_locks_so_far >  4.5) {
                return tpcc_LM54(parameters);
              }
            } else if (parameters.num_locks_so_far >  14.5) {
              return tpcc_LM55(parameters);
            }
          } else if (parameters.num_of_wait_locks >  1.5) {

            if (parameters.total_wait_locks <= 146.5) {
              return tpcc_LM56(parameters);
            } else if (parameters.total_wait_locks >  146.5) {

              if (parameters.wait_so_far <= 396559456.5) {

                if (parameters.avg_latency_of_same_past_second <= 176480500) {
                  return tpcc_LM57(parameters);
                } else if (parameters.avg_latency_of_same_past_second >  176480500) {
                  return tpcc_LM58(parameters);
                }
              } else if (parameters.wait_so_far >  396559456.5) {

                if (parameters.work_so_far <= 675485) {

                  if (parameters.total_wait_locks <= 203.5) {
                    return tpcc_LM59(parameters);
                  } else if (parameters.total_wait_locks >  203.5) {

                    if (parameters.work_so_far <= 78213.5) {

                      if (parameters.mean_wait_of_all <= 61467200) {
                        return tpcc_LM60(parameters);
                      } else if (parameters.mean_wait_of_all >  61467200) {
                        return tpcc_LM61(parameters);
                      }
                    } else if (parameters.work_so_far >  78213.5) {

                      if (parameters.cpu_usage <= 0.893) {
                        return tpcc_LM62(parameters);
                      } else if (parameters.cpu_usage >  0.893) {

                        if (parameters.num_of_wait_locks <= 4.5) {

                          if (parameters.wait_so_far <= 780298217.5) {
                            return tpcc_LM63(parameters);
                          } else if (parameters.wait_so_far >  780298217.5) {
                            return tpcc_LM64(parameters);
                          }
                        } else if (parameters.num_of_wait_locks >  4.5) {
                          return tpcc_LM65(parameters);
                        }
                      }
                    }
                  }
                } else if (parameters.work_so_far >  675485) {
                  return tpcc_LM66(parameters);
                }
              }
            }
          }
        } else if (parameters.avg_latency_of_same_past_second >  364785000) {

          if (parameters.work_so_far <= 89524) {

            if (parameters.wait_so_far <= 211519583.5) {
              return tpcc_LM67(parameters);
            } else if (parameters.wait_so_far >  211519583.5) {
              return tpcc_LM68(parameters);
            }
          } else if (parameters.work_so_far >  89524) {

            if (parameters.wait_so_far <= 514664675) {

              if (parameters.mean_wait_of_all <= 61980550) {

                if (parameters.work_so_far <= 3513739) {

                  if (parameters.num_of_wait_locks <= 3.5) {

                    if (parameters.num_locks_so_far <= 9.5) {

                      if (parameters.wait_so_far <= 36369222) {
                        return tpcc_LM69(parameters);
                      } else if (parameters.wait_so_far >  36369222) {
                        return tpcc_LM70(parameters);
                      }
                    } else if (parameters.num_locks_so_far >  9.5) {
                      return tpcc_LM71(parameters);
                    }
                  } else if (parameters.num_of_wait_locks >  3.5) {
                    return tpcc_LM72(parameters);
                  }
                } else if (parameters.work_so_far >  3513739) {

                  if (parameters.num_locks_so_far <= 16.5) {

                    if (parameters.wait_so_far <= 348358645.5) {

                      if (parameters.num_of_wait_locks <= 2.5) {
                        return tpcc_LM73(parameters);
                      } else if (parameters.num_of_wait_locks >  2.5) {
                        return tpcc_LM74(parameters);
                      }
                    } else if (parameters.wait_so_far >  348358645.5) {

                      if (parameters.num_locks_so_far <= 11.5) {

                        if (parameters.num_of_wait_locks <= 1.5) {
                          return tpcc_LM75(parameters);
                        } else if (parameters.num_of_wait_locks >  1.5) {
                          return tpcc_LM76(parameters);
                        }
                      } else if (parameters.num_locks_so_far >  11.5) {
                        return tpcc_LM77(parameters);
                      }
                    }
                  } else if (parameters.num_locks_so_far >  16.5) {

                    if (parameters.wait_so_far <= 195374585) {
                      return tpcc_LM78(parameters);
                    } else if (parameters.wait_so_far >  195374585) {

                      if (parameters.total_wait_locks <= 248.5) {

                        if (parameters.num_of_wait_locks <= 1.5) {
                          return tpcc_LM79(parameters);
                        } else if (parameters.num_of_wait_locks >  1.5) {
                          return tpcc_LM80(parameters);
                        }
                      } else if (parameters.total_wait_locks >  248.5) {
                        return tpcc_LM81(parameters);
                      }
                    }
                  }
                }
              } else if (parameters.mean_wait_of_all >  61980550) {

                if (parameters.work_so_far <= 678681) {
                  return tpcc_LM82(parameters);
                } else if (parameters.work_so_far >  678681) {

                  if (parameters.num_locks_so_far <= 10.5) {

                    if (parameters.work_so_far <= 3575803.5) {
                      return tpcc_LM83(parameters);
                    } else if (parameters.work_so_far >  3575803.5) {

                      if (parameters.num_of_wait_locks <= 3.5) {

                        if (parameters.avg_latency_of_same_past_second <= 394609000) {

                          if (parameters.num_of_wait_locks <= 1.5) {
                            return tpcc_LM84(parameters);
                          } else if (parameters.num_of_wait_locks >  1.5) {

                            if (parameters.cpu_usage <= 0.997) {
                              return tpcc_LM85(parameters);
                            } else if (parameters.cpu_usage >  0.997) {
                              return tpcc_LM86(parameters);
                            }
                          }
                        } else if (parameters.avg_latency_of_same_past_second >  394609000) {

                          if (parameters.num_locks_so_far <= 9.5) {
                            return tpcc_LM87(parameters);
                          } else if (parameters.num_locks_so_far >  9.5) {
                            return tpcc_LM88(parameters);
                          }
                        }
                      } else if (parameters.num_of_wait_locks >  3.5) {
                        return tpcc_LM89(parameters);
                      }
                    }
                  } else if (parameters.num_locks_so_far >  10.5) {
                    return tpcc_LM90(parameters);
                  }
                }
              }
            } else if (parameters.wait_so_far >  514664675) {

              if (parameters.num_of_wait_locks <= 1.5) {

                if (parameters.avg_latency_of_same_past_second <= 560023000) {
                  return tpcc_LM91(parameters);
                } else if (parameters.avg_latency_of_same_past_second >  560023000) {
                  return tpcc_LM92(parameters);
                }
              } else if (parameters.num_of_wait_locks >  1.5) {

                if (parameters.num_locks_so_far <= 5.5) {

                  if (parameters.work_so_far <= 639610.5) {
                    return tpcc_LM93(parameters);
                  } else if (parameters.work_so_far >  639610.5) {

                    if (parameters.wait_so_far <= 896368537.5) {
                      return tpcc_LM94(parameters);
                    } else if (parameters.wait_so_far >  896368537.5) {
                      return tpcc_LM95(parameters);
                    }
                  }
                } else if (parameters.num_locks_so_far >  5.5) {

                  if (parameters.wait_so_far <= 743121054) {
                    return tpcc_LM96(parameters);
                  } else if (parameters.wait_so_far >  743121054) {

                    if (parameters.avg_latency_of_same_past_second <= 565044500) {
                      return tpcc_LM97(parameters);
                    } else if (parameters.avg_latency_of_same_past_second >  565044500) {

                      if (parameters.cpu_usage <= 0.867) {
                        return tpcc_LM98(parameters);
                      } else if (parameters.cpu_usage >  0.867) {

                        if (parameters.work_so_far <= 1347655.5) {
                          return tpcc_LM99(parameters);
                        } else if (parameters.work_so_far >  1347655.5) {
                          return tpcc_LM100(parameters);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      } else if (parameters.work_so_far >  14581279.5) {

        if (parameters.num_of_wait_locks <= 1.5) {

          if (parameters.num_locks_so_far <= 64.5) {
            return tpcc_LM101(parameters);
          } else if (parameters.num_locks_so_far >  64.5) {
            return tpcc_LM102(parameters);
          }
        } else if (parameters.num_of_wait_locks >  1.5) {

          if (parameters.wait_so_far <= 307928329) {

            if (parameters.work_so_far <= 123723393.5) {

              if (parameters.num_locks_so_far <= 21.5) {
                return tpcc_LM103(parameters);
              } else if (parameters.num_locks_so_far >  21.5) {
                return tpcc_LM104(parameters);
              }
            } else if (parameters.work_so_far >  123723393.5) {

              if (parameters.avg_latency_of_same_past_second <= 478397000) {

                if (parameters.work_so_far <= 256318560) {

                  if (parameters.num_locks_so_far <= 19.5) {
                    return tpcc_LM105(parameters);
                  } else if (parameters.num_locks_so_far >  19.5) {
                    return tpcc_LM106(parameters);
                  }
                } else if (parameters.work_so_far >  256318560) {

                  if (parameters.num_locks_so_far <= 29.5) {
                    return tpcc_LM107(parameters);
                  } else if (parameters.num_locks_so_far >  29.5) {
                    return tpcc_LM108(parameters);
                  }
                }
              } else if (parameters.avg_latency_of_same_past_second >  478397000) {

                if (parameters.work_so_far <= 570640938) {

                  if (parameters.num_locks_so_far <= 21) {

                    if (parameters.num_locks_so_far <= 7) {
                      return tpcc_LM109(parameters);
                    } else if (parameters.num_locks_so_far >  7) {

                      if (parameters.mean_wait_of_all <= 98833050) {

                        if (parameters.total_wait_locks <= 313.5) {

                          if (parameters.work_so_far <= 235057945) {
                            return tpcc_LM110(parameters);
                          } else if (parameters.work_so_far >  235057945) {
                            return tpcc_LM111(parameters);
                          }
                        } else if (parameters.total_wait_locks >  313.5) {

                          if (parameters.wait_so_far <= 61261203.5) {
                            return tpcc_LM112(parameters);
                          } else if (parameters.wait_so_far >  61261203.5) {
                            return tpcc_LM113(parameters);
                          }
                        }
                      } else if (parameters.mean_wait_of_all >  98833050) {
                        return tpcc_LM114(parameters);
                      }
                    }
                  } else if (parameters.num_locks_so_far >  21) {
                    return tpcc_LM115(parameters);
                  }
                } else if (parameters.work_so_far >  570640938) {

                  if (parameters.avg_latency_of_same_past_second <= 756370500) {
                    return tpcc_LM116(parameters);
                  } else if (parameters.avg_latency_of_same_past_second >  756370500) {
                    return tpcc_LM117(parameters);
                  }
                }
              }
            }
          } else if (parameters.wait_so_far >  307928329) {

            if (parameters.num_locks_so_far <= 5.5) {
              return tpcc_LM118(parameters);
            } else if (parameters.num_locks_so_far >  5.5) {
              return tpcc_LM119(parameters);
            }
          }
        }
      }
    }
  }
}