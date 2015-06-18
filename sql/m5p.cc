#include "my_global.h"
#include "m5p.h"
#include "trace_tool.h"

static
double
new_order_LM1(work_wait &parameters) {
  double actual_remaining = 
	474.2668 * parameters.work_so_far 
	+ 0.0576 * parameters.wait_so_far 
	- 613157.6487 * parameters.num_locks_so_far 
	- 3128024.8837 * parameters.num_of_wait_locks 
	+ 114535.2334 * parameters.total_wait_locks 
	+ 0.5428 * parameters.mean_wait_of_all 
	- 54173323.8666 * parameters.cpu_usage 
	- 0.0382 * parameters.avg_latency_of_same_past_second 
	+ 72264864.1476;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM2(work_wait &parameters) {
  double actual_remaining = 
	8041.8844 * parameters.work_so_far 
	- 0.069 * parameters.wait_so_far 
	- 613157.6487 * parameters.num_locks_so_far 
	- 3128024.8837 * parameters.num_of_wait_locks 
	+ 268163.6735 * parameters.total_wait_locks 
	- 0.5255 * parameters.mean_wait_of_all 
	- 54173323.8666 * parameters.cpu_usage 
	- 2.3257 * parameters.avg_latency_of_same_past_second 
	+ 166837295.9152;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM3(work_wait &parameters) {
  double actual_remaining = 
	7590.6967 * parameters.work_so_far 
	+ 6.9589 * parameters.wait_so_far 
	- 613157.6487 * parameters.num_locks_so_far 
	- 3128024.8837 * parameters.num_of_wait_locks 
	+ 268163.6735 * parameters.total_wait_locks 
	- 0.5255 * parameters.mean_wait_of_all 
	- 283792459.0917 * parameters.cpu_usage 
	- 0.6159 * parameters.avg_latency_of_same_past_second 
	+ 254107738.3213;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM4(work_wait &parameters) {
  double actual_remaining = 
	-4067.705 * parameters.work_so_far 
	- 3.8806 * parameters.wait_so_far 
	- 613157.6487 * parameters.num_locks_so_far 
	- 3128024.8837 * parameters.num_of_wait_locks 
	+ 268163.6735 * parameters.total_wait_locks 
	- 0.591 * parameters.mean_wait_of_all 
	- 223650764.8874 * parameters.cpu_usage 
	- 0.1633 * parameters.avg_latency_of_same_past_second 
	+ 445871581.3533;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM5(work_wait &parameters) {
  double actual_remaining = 
	-4067.705 * parameters.work_so_far 
	- 7.9669 * parameters.wait_so_far 
	- 613157.6487 * parameters.num_locks_so_far 
	- 3128024.8837 * parameters.num_of_wait_locks 
	+ 268163.6735 * parameters.total_wait_locks 
	- 0.591 * parameters.mean_wait_of_all 
	- 210429835.6772 * parameters.cpu_usage 
	- 0.1633 * parameters.avg_latency_of_same_past_second 
	+ 443552831.4655;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM6(work_wait &parameters) {
  double actual_remaining = 
	-153.1695 * parameters.work_so_far 
	- 0.0482 * parameters.wait_so_far 
	- 613157.6487 * parameters.num_locks_so_far 
	- 3128024.8837 * parameters.num_of_wait_locks 
	+ 190631.5635 * parameters.total_wait_locks 
	- 0.0015 * parameters.mean_wait_of_all 
	- 54173323.8666 * parameters.cpu_usage 
	- 0.3095 * parameters.avg_latency_of_same_past_second 
	+ 145905297.484;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM7(work_wait &parameters) {
  double actual_remaining = 
	7.4287 * parameters.work_so_far 
	- 0.095 * parameters.wait_so_far 
	- 8649187.8747 * parameters.num_locks_so_far 
	- 2999298.564 * parameters.num_of_wait_locks 
	+ 272118.771 * parameters.total_wait_locks 
	- 0.0015 * parameters.mean_wait_of_all 
	- 443736064.1669 * parameters.cpu_usage 
	- 1.1744 * parameters.avg_latency_of_same_past_second 
	+ 675189520.1413;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM8(work_wait &parameters) {
  double actual_remaining = 
	1627.0456 * parameters.work_so_far 
	- 0.0641 * parameters.wait_so_far 
	- 3129323.3987 * parameters.num_locks_so_far 
	- 2999298.564 * parameters.num_of_wait_locks 
	+ 158294.7686 * parameters.total_wait_locks 
	- 1.4689 * parameters.mean_wait_of_all 
	- 79592764.3009 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_latency_of_same_past_second 
	+ 284511121.3811;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM9(work_wait &parameters) {
  double actual_remaining = 
	3906.7926 * parameters.work_so_far 
	- 0.0641 * parameters.wait_so_far 
	- 3129323.3987 * parameters.num_locks_so_far 
	- 2999298.564 * parameters.num_of_wait_locks 
	+ 158294.7686 * parameters.total_wait_locks 
	- 1.8882 * parameters.mean_wait_of_all 
	- 79592764.3009 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_latency_of_same_past_second 
	+ 163671935.6932;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM10(work_wait &parameters) {
  double actual_remaining = 
	2.3781 * parameters.work_so_far 
	- 0.0641 * parameters.wait_so_far 
	- 3129323.3987 * parameters.num_locks_so_far 
	- 2999298.564 * parameters.num_of_wait_locks 
	+ 506293.6818 * parameters.total_wait_locks 
	- 0.0015 * parameters.mean_wait_of_all 
	- 79592764.3009 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_latency_of_same_past_second 
	+ 215146772.9728;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM11(work_wait &parameters) {
  double actual_remaining = 
	7.7928 * parameters.work_so_far 
	- 0.0641 * parameters.wait_so_far 
	- 3129323.3987 * parameters.num_locks_so_far 
	- 2999298.564 * parameters.num_of_wait_locks 
	+ 808901.4324 * parameters.total_wait_locks 
	- 0.0015 * parameters.mean_wait_of_all 
	- 79592764.3009 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_latency_of_same_past_second 
	+ 61952777.7129;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM12(work_wait &parameters) {
  double actual_remaining = 
	5.2426 * parameters.work_so_far 
	- 0.0641 * parameters.wait_so_far 
	- 2618538.203 * parameters.num_locks_so_far 
	- 2999298.564 * parameters.num_of_wait_locks 
	+ 158294.7686 * parameters.total_wait_locks 
	- 0.0015 * parameters.mean_wait_of_all 
	- 79592764.3009 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_latency_of_same_past_second 
	+ 138220729.8753;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM13(work_wait &parameters) {
  double actual_remaining = 
	1.5699 * parameters.work_so_far 
	- 0.0944 * parameters.wait_so_far 
	- 2279107.7521 * parameters.num_locks_so_far 
	- 2999298.564 * parameters.num_of_wait_locks 
	+ 158294.7686 * parameters.total_wait_locks 
	- 0.0015 * parameters.mean_wait_of_all 
	- 79592764.3009 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_latency_of_same_past_second 
	+ 169835275.7525;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM14(work_wait &parameters) {
  double actual_remaining = 
	4.1733 * parameters.work_so_far 
	+ 0.9862 * parameters.wait_so_far 
	- 2223233.526 * parameters.num_locks_so_far 
	- 2308910.7709 * parameters.num_of_wait_locks 
	+ 69008.0125 * parameters.total_wait_locks 
	- 0.0015 * parameters.mean_wait_of_all 
	- 262298059.9785 * parameters.cpu_usage 
	+ 0.3635 * parameters.avg_latency_of_same_past_second 
	+ 252719226.9734;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM15(work_wait &parameters) {
  double actual_remaining = 
	2.5144 * parameters.work_so_far 
	- 0.0046 * parameters.wait_so_far 
	- 1800235.3314 * parameters.num_locks_so_far 
	- 2098511.5113 * parameters.num_of_wait_locks 
	+ 324560.5663 * parameters.total_wait_locks 
	- 0.0015 * parameters.mean_wait_of_all 
	- 25380524.5353 * parameters.cpu_usage 
	+ 0.0018 * parameters.avg_latency_of_same_past_second 
	+ 74698127.9314;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM16(work_wait &parameters) {
  double actual_remaining = 
	7.4263 * parameters.work_so_far 
	- 0.0066 * parameters.wait_so_far 
	- 7540321.7285 * parameters.num_locks_so_far 
	- 3409523.3598 * parameters.num_of_wait_locks 
	+ 967639.6081 * parameters.total_wait_locks 
	- 10.2218 * parameters.mean_wait_of_all 
	- 317644892.2344 * parameters.cpu_usage 
	- 0.0009 * parameters.avg_latency_of_same_past_second 
	+ 724934991.6866;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM17(work_wait &parameters) {
  double actual_remaining = 
	0.9145 * parameters.work_so_far 
	- 0.0754 * parameters.wait_so_far 
	- 869218.9548 * parameters.num_locks_so_far 
	- 4597682.3869 * parameters.num_of_wait_locks 
	+ 1702797.5443 * parameters.total_wait_locks 
	- 0.612 * parameters.mean_wait_of_all 
	- 33663373.6548 * parameters.cpu_usage 
	- 0.0009 * parameters.avg_latency_of_same_past_second 
	+ 5682019.4923;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM18(work_wait &parameters) {
  double actual_remaining = 
	1.2625 * parameters.work_so_far 
	- 0.2171 * parameters.wait_so_far 
	- 917427.383 * parameters.num_locks_so_far 
	- 4776079.2577 * parameters.num_of_wait_locks 
	+ 229648.4445 * parameters.total_wait_locks 
	- 0.3299 * parameters.mean_wait_of_all 
	- 170748476.0205 * parameters.cpu_usage 
	- 0.0153 * parameters.avg_latency_of_same_past_second 
	+ 374603846.3608;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM19(work_wait &parameters) {
  double actual_remaining = 
	2.7203 * parameters.work_so_far 
	+ 0.0582 * parameters.wait_so_far 
	- 3056284.2485 * parameters.num_locks_so_far 
	- 139240914.6708 * parameters.num_of_wait_locks 
	+ 312817.1914 * parameters.total_wait_locks 
	+ 0.0184 * parameters.mean_wait_of_all 
	- 260321591.3648 * parameters.cpu_usage 
	- 0.3631 * parameters.avg_latency_of_same_past_second 
	+ 990651869.3007;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM20(work_wait &parameters) {
  double actual_remaining = 
	6.4651 * parameters.work_so_far 
	+ 0.5044 * parameters.wait_so_far 
	- 3447112.3386 * parameters.num_locks_so_far 
	- 43373867.6455 * parameters.num_of_wait_locks 
	+ 312817.1914 * parameters.total_wait_locks 
	+ 0.0184 * parameters.mean_wait_of_all 
	- 87169227.9012 * parameters.cpu_usage 
	- 0.1012 * parameters.avg_latency_of_same_past_second 
	+ 328825981.6532;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM21(work_wait &parameters) {
  double actual_remaining = 
	0.9487 * parameters.work_so_far 
	+ 0.8848 * parameters.wait_so_far 
	- 5068856.8354 * parameters.num_locks_so_far 
	- 1065765.6672 * parameters.num_of_wait_locks 
	+ 1029471.8544 * parameters.total_wait_locks 
	+ 0.4818 * parameters.mean_wait_of_all 
	- 157181751.3605 * parameters.cpu_usage 
	- 0.1208 * parameters.avg_latency_of_same_past_second 
	+ 401571196.2931;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM22(work_wait &parameters) {
  double actual_remaining = 
	1.4543 * parameters.work_so_far 
	- 0.2137 * parameters.wait_so_far 
	+ 30186869.9704 * parameters.num_locks_so_far 
	- 35289309.2952 * parameters.num_of_wait_locks 
	+ 169265.2751 * parameters.total_wait_locks 
	- 0.8374 * parameters.mean_wait_of_all 
	- 216919784.6921 * parameters.cpu_usage 
	+ 0.0844 * parameters.avg_latency_of_same_past_second 
	+ 515266409.0525;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM23(work_wait &parameters) {
  double actual_remaining = 
	0.0086 * parameters.work_so_far 
	- 0.1731 * parameters.wait_so_far 
	- 3701.5287 * parameters.num_locks_so_far 
	- 43549470.4531 * parameters.num_of_wait_locks 
	- 274911.4009 * parameters.total_wait_locks 
	+ 1.5661 * parameters.mean_wait_of_all 
	- 358060853.8428 * parameters.cpu_usage 
	+ 0.105 * parameters.avg_latency_of_same_past_second 
	+ 702302599.07;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM24(work_wait &parameters) {
  double actual_remaining = 
	7.1093 * parameters.work_so_far 
	+ 0.7369 * parameters.wait_so_far 
	- 245916.9363 * parameters.num_locks_so_far 
	- 502731.1438 * parameters.num_of_wait_locks 
	+ 5395.4805 * parameters.total_wait_locks 
	- 0.0268 * parameters.mean_wait_of_all 
	- 275576396.9822 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_latency_of_same_past_second 
	+ 519387979.9214;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM25(work_wait &parameters) {
  double actual_remaining = 
	4.5318 * parameters.work_so_far 
	+ 0.8917 * parameters.wait_so_far 
	- 6428357.5649 * parameters.num_locks_so_far 
	- 502731.1438 * parameters.num_of_wait_locks 
	+ 155062.8309 * parameters.total_wait_locks 
	- 0.9122 * parameters.mean_wait_of_all 
	- 294957038.4506 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_latency_of_same_past_second 
	+ 519075203.4906;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM26(work_wait &parameters) {
  double actual_remaining = 
	0.6539 * parameters.work_so_far 
	+ 0.5964 * parameters.wait_so_far 
	- 6020086.6661 * parameters.num_locks_so_far 
	- 642281.9986 * parameters.num_of_wait_locks 
	+ 740048.2604 * parameters.total_wait_locks 
	- 4.3015 * parameters.mean_wait_of_all 
	- 363623224.059 * parameters.cpu_usage 
	- 0.0009 * parameters.avg_latency_of_same_past_second 
	+ 847440290.0172;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM27(work_wait &parameters) {
  double actual_remaining = 
	0.2748 * parameters.work_so_far 
	+ 0.0436 * parameters.wait_so_far 
	+ 1908671.4726 * parameters.num_locks_so_far 
	- 1839263.454 * parameters.num_of_wait_locks 
	- 279231.2235 * parameters.total_wait_locks 
	+ 1.3325 * parameters.mean_wait_of_all 
	- 33729906.2594 * parameters.cpu_usage 
	- 0.6606 * parameters.avg_latency_of_same_past_second 
	+ 772842653.4001;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM28(work_wait &parameters) {
  double actual_remaining = 
	1.0728 * parameters.work_so_far 
	+ 0.0436 * parameters.wait_so_far 
	+ 1424684.2122 * parameters.num_locks_so_far 
	- 1839263.454 * parameters.num_of_wait_locks 
	- 1894877.5979 * parameters.total_wait_locks 
	+ 8.9655 * parameters.mean_wait_of_all 
	- 33729906.2594 * parameters.cpu_usage 
	- 0.6394 * parameters.avg_latency_of_same_past_second 
	+ 955956857.4886;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM29(work_wait &parameters) {
  double actual_remaining = 
	1.1385 * parameters.work_so_far 
	+ 0.4126 * parameters.wait_so_far 
	- 262901.2177 * parameters.num_locks_so_far 
	- 1164881.049 * parameters.num_of_wait_locks 
	+ 149480.5856 * parameters.total_wait_locks 
	- 1.5096 * parameters.mean_wait_of_all 
	- 355065428.0453 * parameters.cpu_usage 
	- 0.2241 * parameters.avg_latency_of_same_past_second 
	+ 778315921.1866;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM30(work_wait &parameters) {
  double actual_remaining = 
	1.7367 * parameters.work_so_far 
	+ 0.1028 * parameters.wait_so_far 
	+ 63679089.2704 * parameters.num_locks_so_far 
	+ 2532860.4969 * parameters.num_of_wait_locks 
	+ 81833.8104 * parameters.total_wait_locks 
	- 0.0149 * parameters.mean_wait_of_all 
	- 107869854.9915 * parameters.cpu_usage 
	- 0.0546 * parameters.avg_latency_of_same_past_second 
	+ 261941803.0637;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM31(work_wait &parameters) {
  double actual_remaining = 
	-0.3528 * parameters.work_so_far 
	+ 0.1028 * parameters.wait_so_far 
	+ 3626146.1664 * parameters.num_locks_so_far 
	+ 2532860.4969 * parameters.num_of_wait_locks 
	+ 57608.6036 * parameters.total_wait_locks 
	- 0.0149 * parameters.mean_wait_of_all 
	- 332853088.0963 * parameters.cpu_usage 
	- 0.0546 * parameters.avg_latency_of_same_past_second 
	+ 815815214.8983;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM32(work_wait &parameters) {
  double actual_remaining = 
	0.8452 * parameters.work_so_far 
	+ 0.6923 * parameters.wait_so_far 
	- 250290.8791 * parameters.num_locks_so_far 
	+ 9244026.3132 * parameters.num_of_wait_locks 
	+ 1579081.8195 * parameters.total_wait_locks 
	- 0.0149 * parameters.mean_wait_of_all 
	- 23924032.3996 * parameters.cpu_usage 
	- 0.1207 * parameters.avg_latency_of_same_past_second 
	- 355537190.7645;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM33(work_wait &parameters) {
  double actual_remaining = 
	1.632 * parameters.work_so_far 
	+ 1.0117 * parameters.wait_so_far 
	- 250290.8791 * parameters.num_locks_so_far 
	+ 9244026.3132 * parameters.num_of_wait_locks 
	+ 260427.7651 * parameters.total_wait_locks 
	- 0.0149 * parameters.mean_wait_of_all 
	- 23924032.3996 * parameters.cpu_usage 
	- 0.1207 * parameters.avg_latency_of_same_past_second 
	- 181729670.8623;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
new_order_estimate(work_wait &parameters){

  if (parameters.total_wait_locks <= 142.5) {

    if (parameters.work_so_far <= 39770718.5) {

      if (parameters.total_wait_locks <= 72.5) {

        if (parameters.cpu_usage <= 0.943) {

          if (parameters.num_locks_so_far <= 25.5) {

            if (parameters.work_so_far <= 35605.5) {

              if (parameters.work_so_far <= 23589.5) {
                return new_order_LM1(parameters);
              } else {

                if (parameters.wait_so_far <= 4546197.5) {

                  if (parameters.work_so_far <= 27211) {

                    if (parameters.mean_wait_of_all <= 31910300) {
                      return new_order_LM2(parameters);
                    } else {
                      return new_order_LM3(parameters);
                    }
                  } else {

                    if (parameters.wait_so_far <= 3373.5) {
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

              if (parameters.mean_wait_of_all <= 30623500) {
                return new_order_LM7(parameters);
              } else {

                if (parameters.wait_so_far <= 24504011) {

                  if (parameters.num_locks_so_far <= 12) {

                    if (parameters.work_so_far <= 69699) {

                      if (parameters.mean_wait_of_all <= 45281200) {
                        return new_order_LM8(parameters);
                      } else {
                        return new_order_LM9(parameters);
                      }
                    } else {

                      if (parameters.work_so_far <= 29023932.5) {
                        return new_order_LM10(parameters);
                      } else {
                        return new_order_LM11(parameters);
                      }
                    }
                  } else {
                    return new_order_LM12(parameters);
                  }
                } else {
                  return new_order_LM13(parameters);
                }
              }
            }
          } else {
            return new_order_LM14(parameters);
          }
        } else {
          return new_order_LM15(parameters);
        }
      } else {

        if (parameters.mean_wait_of_all <= 34527600) {

          if (parameters.num_of_wait_locks <= 2.5) {
            return new_order_LM16(parameters);
          } else {
            return new_order_LM17(parameters);
          }
        } else {

          if (parameters.work_so_far <= 1073404) {
            return new_order_LM18(parameters);
          } else {

            if (parameters.num_locks_so_far <= 17.5) {
              return new_order_LM19(parameters);
            } else {
              return new_order_LM20(parameters);
            }
          }
        }
      }
    } else {
      return new_order_LM21(parameters);
    }
  } else {

    if (parameters.num_locks_so_far <= 5.5) {

      if (parameters.wait_so_far <= 207527059) {
        return new_order_LM22(parameters);
      } else {
        return new_order_LM23(parameters);
      }
    } else {

      if (parameters.wait_so_far <= 288275528.5) {

        if (parameters.work_so_far <= 52259801) {

          if (parameters.num_locks_so_far <= 14.5) {
            return new_order_LM24(parameters);
          } else {
            return new_order_LM25(parameters);
          }
        } else {
          return new_order_LM26(parameters);
        }
      } else {

        if (parameters.wait_so_far <= 605874805) {

          if (parameters.num_locks_so_far <= 11.5) {

            if (parameters.work_so_far <= 3603008.5) {
              return new_order_LM27(parameters);
            } else {
              return new_order_LM28(parameters);
            }
          } else {
            return new_order_LM29(parameters);
          }
        } else {

          if (parameters.wait_so_far <= 906962960) {

            if (parameters.num_locks_so_far <= 10.5) {
              return new_order_LM30(parameters);
            } else {
              return new_order_LM31(parameters);
            }
          } else {

            if (parameters.wait_so_far <= 953637455) {
              return new_order_LM32(parameters);
            } else {
              return new_order_LM33(parameters);
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
	108.0644 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 10233.9153 * parameters.num_of_wait_locks 
	+ 2830.3711 * parameters.total_wait_locks 
	+ 0.0002 * parameters.mean_wait_of_all 
	- 1250642.0623 * parameters.cpu_usage 
	- 0 * parameters.avg_latency_of_same_past_second 
	+ 5510856.4608;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM2(work_wait &parameters) {
  double actual_remaining = 
	245.294 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 10233.9153 * parameters.num_of_wait_locks 
	+ 1594.3759 * parameters.total_wait_locks 
	+ 0.0002 * parameters.mean_wait_of_all 
	- 1657831.2848 * parameters.cpu_usage 
	- 0.0015 * parameters.avg_latency_of_same_past_second 
	+ 5635920.4855;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM3(work_wait &parameters) {
  double actual_remaining = 
	288.1614 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 10233.9153 * parameters.num_of_wait_locks 
	+ 1594.3759 * parameters.total_wait_locks 
	+ 5.309 * parameters.mean_wait_of_all 
	- 11946993.5237 * parameters.cpu_usage 
	- 0.0021 * parameters.avg_latency_of_same_past_second 
	- 139944821.3022;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM4(work_wait &parameters) {
  double actual_remaining = 
	288.1614 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 10233.9153 * parameters.num_of_wait_locks 
	+ 1594.3759 * parameters.total_wait_locks 
	+ 0.0002 * parameters.mean_wait_of_all 
	- 5289300.3103 * parameters.cpu_usage 
	- 0.0021 * parameters.avg_latency_of_same_past_second 
	+ 10490363.7852;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM5(work_wait &parameters) {
  double actual_remaining = 
	174.7949 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 10233.9153 * parameters.num_of_wait_locks 
	+ 1594.3759 * parameters.total_wait_locks 
	+ 0.2147 * parameters.mean_wait_of_all 
	- 2453640.672 * parameters.cpu_usage 
	- 0 * parameters.avg_latency_of_same_past_second 
	+ 1722252.0347;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM6(work_wait &parameters) {
  double actual_remaining = 
	-18685.9985 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 10233.9153 * parameters.num_of_wait_locks 
	- 148031.3583 * parameters.total_wait_locks 
	+ 0.0002 * parameters.mean_wait_of_all 
	- 32233093.181 * parameters.cpu_usage 
	+ 0.9009 * parameters.avg_latency_of_same_past_second 
	+ 204751206.4559;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM7(work_wait &parameters) {
  double actual_remaining = 
	-47849.8731 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 10233.9153 * parameters.num_of_wait_locks 
	- 383383.367 * parameters.total_wait_locks 
	+ 0.0002 * parameters.mean_wait_of_all 
	- 32233093.181 * parameters.cpu_usage 
	+ 0.6372 * parameters.avg_latency_of_same_past_second 
	+ 498932328.2534;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM8(work_wait &parameters) {
  double actual_remaining = 
	-48105.0786 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 10233.9153 * parameters.num_of_wait_locks 
	- 497032.719 * parameters.total_wait_locks 
	+ 0.0002 * parameters.mean_wait_of_all 
	- 32233093.181 * parameters.cpu_usage 
	+ 0.6372 * parameters.avg_latency_of_same_past_second 
	+ 514046295.3345;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM9(work_wait &parameters) {
  double actual_remaining = 
	-49632.4578 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 10233.9153 * parameters.num_of_wait_locks 
	- 468615.8733 * parameters.total_wait_locks 
	+ 0.0002 * parameters.mean_wait_of_all 
	- 32233093.181 * parameters.cpu_usage 
	+ 0.6372 * parameters.avg_latency_of_same_past_second 
	+ 522256101.5839;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM10(work_wait &parameters) {
  double actual_remaining = 
	-37094.0071 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 10233.9153 * parameters.num_of_wait_locks 
	- 268198.1158 * parameters.total_wait_locks 
	+ 0.0002 * parameters.mean_wait_of_all 
	- 32233093.181 * parameters.cpu_usage 
	+ 0.6372 * parameters.avg_latency_of_same_past_second 
	+ 391791210.1158;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM11(work_wait &parameters) {
  double actual_remaining = 
	-724.6763 * parameters.work_so_far 
	+ 0.0152 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 10233.9153 * parameters.num_of_wait_locks 
	+ 1594.3759 * parameters.total_wait_locks 
	+ 0.0002 * parameters.mean_wait_of_all 
	- 25482058.8224 * parameters.cpu_usage 
	- 0 * parameters.avg_latency_of_same_past_second 
	+ 37818051.9941;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM12(work_wait &parameters) {
  double actual_remaining = 
	-3201.9497 * parameters.work_so_far 
	+ 0.028 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 10233.9153 * parameters.num_of_wait_locks 
	+ 1594.3759 * parameters.total_wait_locks 
	+ 0.0002 * parameters.mean_wait_of_all 
	- 34186064.1438 * parameters.cpu_usage 
	- 0 * parameters.avg_latency_of_same_past_second 
	+ 70363734.6377;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM13(work_wait &parameters) {
  double actual_remaining = 
	-7174.9782 * parameters.work_so_far 
	+ 0.0946 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 10233.9153 * parameters.num_of_wait_locks 
	+ 1594.3759 * parameters.total_wait_locks 
	- 0.2017 * parameters.mean_wait_of_all 
	- 153482033.7444 * parameters.cpu_usage 
	- 0 * parameters.avg_latency_of_same_past_second 
	+ 227524993.2835;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM14(work_wait &parameters) {
  double actual_remaining = 
	-5147.763 * parameters.work_so_far 
	+ 0.0381 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 10233.9153 * parameters.num_of_wait_locks 
	+ 1594.3759 * parameters.total_wait_locks 
	+ 0.0558 * parameters.mean_wait_of_all 
	- 49410900.1971 * parameters.cpu_usage 
	- 0 * parameters.avg_latency_of_same_past_second 
	+ 100803723.9181;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM15(work_wait &parameters) {
  double actual_remaining = 
	-5147.763 * parameters.work_so_far 
	+ 0.0381 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 10233.9153 * parameters.num_of_wait_locks 
	+ 1594.3759 * parameters.total_wait_locks 
	+ 0.0968 * parameters.mean_wait_of_all 
	- 49410900.1971 * parameters.cpu_usage 
	- 0 * parameters.avg_latency_of_same_past_second 
	+ 101428135.1078;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM16(work_wait &parameters) {
  double actual_remaining = 
	0.2454 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 3868.6297 * parameters.num_of_wait_locks 
	+ 44633.8825 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 28221046.3946 * parameters.cpu_usage 
	- 0.0072 * parameters.avg_latency_of_same_past_second 
	+ 40842456.1773;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM17(work_wait &parameters) {
  double actual_remaining = 
	0.5069 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 1577540.0514 * parameters.num_of_wait_locks 
	+ 34575.7045 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 645157.3866 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_latency_of_same_past_second 
	+ 15794651.3394;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM18(work_wait &parameters) {
  double actual_remaining = 
	0.0431 * parameters.work_so_far 
	+ 0.1463 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 1768008.7544 * parameters.num_of_wait_locks 
	+ 96864.9702 * parameters.total_wait_locks 
	- 0.5778 * parameters.mean_wait_of_all 
	- 104532.1871 * parameters.cpu_usage 
	+ 0.0319 * parameters.avg_latency_of_same_past_second 
	+ 20957850.7128;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM19(work_wait &parameters) {
  double actual_remaining = 
	0.0431 * parameters.work_so_far 
	- 0.0101 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 17957.4324 * parameters.num_of_wait_locks 
	- 329140.9163 * parameters.total_wait_locks 
	+ 0.6315 * parameters.mean_wait_of_all 
	- 104532.1871 * parameters.cpu_usage 
	+ 0.0005 * parameters.avg_latency_of_same_past_second 
	+ 92488889.8705;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM20(work_wait &parameters) {
  double actual_remaining = 
	0.0431 * parameters.work_so_far 
	- 0.0028 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 5428774.7799 * parameters.num_of_wait_locks 
	- 107348.0455 * parameters.total_wait_locks 
	+ 0.4113 * parameters.mean_wait_of_all 
	- 104532.1871 * parameters.cpu_usage 
	+ 0.0005 * parameters.avg_latency_of_same_past_second 
	+ 34280841.2588;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM21(work_wait &parameters) {
  double actual_remaining = 
	0.0431 * parameters.work_so_far 
	- 0.0028 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 5428774.7799 * parameters.num_of_wait_locks 
	- 295919.3996 * parameters.total_wait_locks 
	+ 0.4113 * parameters.mean_wait_of_all 
	- 104532.1871 * parameters.cpu_usage 
	+ 0.0005 * parameters.avg_latency_of_same_past_second 
	+ 101517843.1786;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM22(work_wait &parameters) {
  double actual_remaining = 
	0.0431 * parameters.work_so_far 
	- 0.0028 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 5428774.7799 * parameters.num_of_wait_locks 
	- 107348.0455 * parameters.total_wait_locks 
	+ 0.4113 * parameters.mean_wait_of_all 
	- 104532.1871 * parameters.cpu_usage 
	+ 0.0005 * parameters.avg_latency_of_same_past_second 
	+ 39404391.4217;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM23(work_wait &parameters) {
  double actual_remaining = 
	0.0431 * parameters.work_so_far 
	- 0.0028 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 2575798.3603 * parameters.num_of_wait_locks 
	- 107348.0455 * parameters.total_wait_locks 
	+ 0.4113 * parameters.mean_wait_of_all 
	- 104532.1871 * parameters.cpu_usage 
	+ 0.0005 * parameters.avg_latency_of_same_past_second 
	+ 34048518.8141;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM24(work_wait &parameters) {
  double actual_remaining = 
	0.0431 * parameters.work_so_far 
	- 0.0069 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 17957.4324 * parameters.num_of_wait_locks 
	- 210266.5358 * parameters.total_wait_locks 
	+ 1.7195 * parameters.mean_wait_of_all 
	- 104532.1871 * parameters.cpu_usage 
	+ 0.0005 * parameters.avg_latency_of_same_past_second 
	- 43520654.8736;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM25(work_wait &parameters) {
  double actual_remaining = 
	0.0431 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 676827.2656 * parameters.num_of_wait_locks 
	- 412411.9664 * parameters.total_wait_locks 
	+ 0.9408 * parameters.mean_wait_of_all 
	- 16033226.0802 * parameters.cpu_usage 
	- 0.1053 * parameters.avg_latency_of_same_past_second 
	+ 168397454.9215;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM26(work_wait &parameters) {
  double actual_remaining = 
	0.0431 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 13614952.4936 * parameters.num_of_wait_locks 
	- 260038.142 * parameters.total_wait_locks 
	+ 0.3868 * parameters.mean_wait_of_all 
	- 362703267.7983 * parameters.cpu_usage 
	+ 0.0005 * parameters.avg_latency_of_same_past_second 
	+ 385562933.8984;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM27(work_wait &parameters) {
  double actual_remaining = 
	0.0431 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 1228294.1927 * parameters.num_of_wait_locks 
	- 260038.142 * parameters.total_wait_locks 
	+ 0.3868 * parameters.mean_wait_of_all 
	- 508228922.0053 * parameters.cpu_usage 
	+ 0.0005 * parameters.avg_latency_of_same_past_second 
	+ 537824702.698;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM28(work_wait &parameters) {
  double actual_remaining = 
	0.0431 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 1228294.1927 * parameters.num_of_wait_locks 
	- 330096.8298 * parameters.total_wait_locks 
	+ 0.3868 * parameters.mean_wait_of_all 
	- 222200873.5293 * parameters.cpu_usage 
	- 0.0544 * parameters.avg_latency_of_same_past_second 
	+ 349820080.7351;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM29(work_wait &parameters) {
  double actual_remaining = 
	0.0431 * parameters.work_so_far 
	- 0.0066 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 137307.6485 * parameters.num_of_wait_locks 
	- 258711.9095 * parameters.total_wait_locks 
	+ 1.1604 * parameters.mean_wait_of_all 
	- 1839795.3772 * parameters.cpu_usage 
	+ 0.0005 * parameters.avg_latency_of_same_past_second 
	+ 31909808.3901;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM30(work_wait &parameters) {
  double actual_remaining = 
	0.0431 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 162944.4454 * parameters.num_of_wait_locks 
	- 345458.2996 * parameters.total_wait_locks 
	+ 16.926 * parameters.mean_wait_of_all 
	+ 112525291.73 * parameters.cpu_usage 
	- 0.5189 * parameters.avg_latency_of_same_past_second 
	- 1372352510.3924;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM31(work_wait &parameters) {
  double actual_remaining = 
	0.0431 * parameters.work_so_far 
	+ 0.0211 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 162944.4454 * parameters.num_of_wait_locks 
	- 266061.2161 * parameters.total_wait_locks 
	+ 7.1452 * parameters.mean_wait_of_all 
	+ 75258595.1961 * parameters.cpu_usage 
	- 0.6532 * parameters.avg_latency_of_same_past_second 
	- 310611173.8518;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM32(work_wait &parameters) {
  double actual_remaining = 
	0.0431 * parameters.work_so_far 
	+ 0.0164 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 162944.4454 * parameters.num_of_wait_locks 
	- 293011.235 * parameters.total_wait_locks 
	+ 8.6352 * parameters.mean_wait_of_all 
	+ 75258595.1961 * parameters.cpu_usage 
	- 0.6532 * parameters.avg_latency_of_same_past_second 
	- 458595402.6738;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM33(work_wait &parameters) {
  double actual_remaining = 
	0.0431 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 162944.4454 * parameters.num_of_wait_locks 
	- 385411.2997 * parameters.total_wait_locks 
	+ 15.4682 * parameters.mean_wait_of_all 
	+ 75258595.1961 * parameters.cpu_usage 
	- 0.6532 * parameters.avg_latency_of_same_past_second 
	- 1060654169.3262;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM34(work_wait &parameters) {
  double actual_remaining = 
	0.0431 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 162944.4454 * parameters.num_of_wait_locks 
	- 446140.692 * parameters.total_wait_locks 
	+ 14.1963 * parameters.mean_wait_of_all 
	+ 75258595.1961 * parameters.cpu_usage 
	- 0.8472 * parameters.avg_latency_of_same_past_second 
	- 865003555.5828;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM35(work_wait &parameters) {
  double actual_remaining = 
	0.0431 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 162944.4454 * parameters.num_of_wait_locks 
	- 456793.6029 * parameters.total_wait_locks 
	+ 5.7734 * parameters.mean_wait_of_all 
	+ 10011733.2672 * parameters.cpu_usage 
	+ 0.0005 * parameters.avg_latency_of_same_past_second 
	- 352862906.7488;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM36(work_wait &parameters) {
  double actual_remaining = 
	0.0431 * parameters.work_so_far 
	- 0.0218 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 14321.0189 * parameters.num_of_wait_locks 
	- 5030.0421 * parameters.total_wait_locks 
	+ 10.8957 * parameters.mean_wait_of_all 
	+ 21171516.121 * parameters.cpu_usage 
	+ 0.2159 * parameters.avg_latency_of_same_past_second 
	- 1270949186.7711;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM37(work_wait &parameters) {
  double actual_remaining = 
	0.0431 * parameters.work_so_far 
	- 0.0071 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 14321.0189 * parameters.num_of_wait_locks 
	+ 54754.4889 * parameters.total_wait_locks 
	+ 0.362 * parameters.mean_wait_of_all 
	+ 42915626.1251 * parameters.cpu_usage 
	- 0.7675 * parameters.avg_latency_of_same_past_second 
	+ 227392978.3712;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM38(work_wait &parameters) {
  double actual_remaining = 
	0.0431 * parameters.work_so_far 
	- 0.0005 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 14321.0189 * parameters.num_of_wait_locks 
	- 894168.4585 * parameters.total_wait_locks 
	+ 9.367 * parameters.mean_wait_of_all 
	+ 11094405.492 * parameters.cpu_usage 
	+ 1.5623 * parameters.avg_latency_of_same_past_second 
	- 1154719446.8726;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM39(work_wait &parameters) {
  double actual_remaining = 
	0.0431 * parameters.work_so_far 
	- 0.0005 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 14321.0189 * parameters.num_of_wait_locks 
	- 775564.4233 * parameters.total_wait_locks 
	+ 6.2876 * parameters.mean_wait_of_all 
	+ 11094405.492 * parameters.cpu_usage 
	+ 2.1731 * parameters.avg_latency_of_same_past_second 
	- 1080662691.0765;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM40(work_wait &parameters) {
  double actual_remaining = 
	0.0431 * parameters.work_so_far 
	- 0.0005 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 14321.0189 * parameters.num_of_wait_locks 
	- 831266.0652 * parameters.total_wait_locks 
	+ 12.9748 * parameters.mean_wait_of_all 
	+ 11094405.492 * parameters.cpu_usage 
	+ 1.6794 * parameters.avg_latency_of_same_past_second 
	- 1633281412.1061;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM41(work_wait &parameters) {
  double actual_remaining = 
	0.0431 * parameters.work_so_far 
	- 0.0005 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 14321.0189 * parameters.num_of_wait_locks 
	- 892743.627 * parameters.total_wait_locks 
	+ 15.3821 * parameters.mean_wait_of_all 
	+ 11094405.492 * parameters.cpu_usage 
	+ 1.6794 * parameters.avg_latency_of_same_past_second 
	- 1839297036.4281;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM42(work_wait &parameters) {
  double actual_remaining = 
	0.0431 * parameters.work_so_far 
	- 0.0005 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 14321.0189 * parameters.num_of_wait_locks 
	- 140695.4111 * parameters.total_wait_locks 
	+ 1.2104 * parameters.mean_wait_of_all 
	+ 11094405.492 * parameters.cpu_usage 
	- 0.0334 * parameters.avg_latency_of_same_past_second 
	- 9149535.7939;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM43(work_wait &parameters) {
  double actual_remaining = 
	0.0431 * parameters.work_so_far 
	- 0.019 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	+ 2377120.3359 * parameters.num_of_wait_locks 
	- 335.7269 * parameters.total_wait_locks 
	- 0.0307 * parameters.mean_wait_of_all 
	+ 1042699.5887 * parameters.cpu_usage 
	- 0.1093 * parameters.avg_latency_of_same_past_second 
	+ 66433773.886;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM44(work_wait &parameters) {
  double actual_remaining = 
	-2.7766 * parameters.work_so_far 
	- 0.0115 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	- 77091.9545 * parameters.num_of_wait_locks 
	- 541.0223 * parameters.total_wait_locks 
	+ 0.1407 * parameters.mean_wait_of_all 
	- 1415992.4183 * parameters.cpu_usage 
	+ 0.0265 * parameters.avg_latency_of_same_past_second 
	+ 10197078.1686;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM45(work_wait &parameters) {
  double actual_remaining = 
	-35.072 * parameters.work_so_far 
	+ 0.4542 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	- 77091.9545 * parameters.num_of_wait_locks 
	+ 52746.3413 * parameters.total_wait_locks 
	- 0.1916 * parameters.mean_wait_of_all 
	- 1415992.4183 * parameters.cpu_usage 
	+ 0.0441 * parameters.avg_latency_of_same_past_second 
	+ 45246314.9922;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM46(work_wait &parameters) {
  double actual_remaining = 
	-35.072 * parameters.work_so_far 
	- 0.0891 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	- 77091.9545 * parameters.num_of_wait_locks 
	+ 52746.3413 * parameters.total_wait_locks 
	- 0.1916 * parameters.mean_wait_of_all 
	- 1415992.4183 * parameters.cpu_usage 
	+ 0.0441 * parameters.avg_latency_of_same_past_second 
	+ 33403173.7052;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM47(work_wait &parameters) {
  double actual_remaining = 
	-15.7815 * parameters.work_so_far 
	- 0.0131 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	- 77091.9545 * parameters.num_of_wait_locks 
	+ 12496.5752 * parameters.total_wait_locks 
	+ 1.986 * parameters.mean_wait_of_all 
	- 1415992.4183 * parameters.cpu_usage 
	+ 0.1738 * parameters.avg_latency_of_same_past_second 
	- 209005382.2212;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM48(work_wait &parameters) {
  double actual_remaining = 
	-5.9122 * parameters.work_so_far 
	- 0.0053 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	- 77091.9545 * parameters.num_of_wait_locks 
	- 39168.3939 * parameters.total_wait_locks 
	+ 0.2099 * parameters.mean_wait_of_all 
	- 1415992.4183 * parameters.cpu_usage 
	+ 0.0155 * parameters.avg_latency_of_same_past_second 
	+ 22864770.3407;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM49(work_wait &parameters) {
  double actual_remaining = 
	215.6994 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	- 17789501.2774 * parameters.num_of_wait_locks 
	- 32329.7292 * parameters.total_wait_locks 
	+ 0.1906 * parameters.mean_wait_of_all 
	- 1415992.4183 * parameters.cpu_usage 
	+ 0.0124 * parameters.avg_latency_of_same_past_second 
	+ 81689231.451;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM50(work_wait &parameters) {
  double actual_remaining = 
	0.0431 * parameters.work_so_far 
	- 0.0107 * parameters.wait_so_far 
	+ 24914.1292 * parameters.num_locks_so_far 
	- 2127622.3851 * parameters.num_of_wait_locks 
	- 110262.6683 * parameters.total_wait_locks 
	+ 0.6364 * parameters.mean_wait_of_all 
	+ 50108472.0932 * parameters.cpu_usage 
	+ 0.0004 * parameters.avg_latency_of_same_past_second 
	- 18323771.3037;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM51(work_wait &parameters) {
  double actual_remaining = 
	0.8892 * parameters.work_so_far 
	+ 0.0898 * parameters.wait_so_far 
	+ 1969325.2993 * parameters.num_locks_so_far 
	+ 61802.159 * parameters.num_of_wait_locks 
	+ 44850.9327 * parameters.total_wait_locks 
	- 0.1883 * parameters.mean_wait_of_all 
	- 33275029.9361 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_latency_of_same_past_second 
	+ 49368541.3984;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM52(work_wait &parameters) {
  double actual_remaining = 
	0.0098 * parameters.work_so_far 
	+ 0.0087 * parameters.wait_so_far 
	+ 4843358.6891 * parameters.num_locks_so_far 
	+ 9919714.5082 * parameters.num_of_wait_locks 
	+ 2952.1829 * parameters.total_wait_locks 
	- 0.0117 * parameters.mean_wait_of_all 
	- 75631072.5488 * parameters.cpu_usage 
	- 0.0407 * parameters.avg_latency_of_same_past_second 
	+ 86320307.3822;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM53(work_wait &parameters) {
  double actual_remaining = 
	0.0066 * parameters.work_so_far 
	+ 0.027 * parameters.wait_so_far 
	+ 9631497.2686 * parameters.num_locks_so_far 
	+ 100370.6957 * parameters.num_of_wait_locks 
	- 172833.2607 * parameters.total_wait_locks 
	+ 0.9489 * parameters.mean_wait_of_all 
	- 2432432.2363 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_latency_of_same_past_second 
	+ 13106729.6613;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM54(work_wait &parameters) {
  double actual_remaining = 
	0.0066 * parameters.work_so_far 
	+ 0.0171 * parameters.wait_so_far 
	+ 2433581.6537 * parameters.num_locks_so_far 
	+ 100370.6957 * parameters.num_of_wait_locks 
	- 2153.0262 * parameters.total_wait_locks 
	+ 0.0127 * parameters.mean_wait_of_all 
	- 2432432.2363 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_latency_of_same_past_second 
	+ 42630092.0819;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM55(work_wait &parameters) {
  double actual_remaining = 
	0.7932 * parameters.work_so_far 
	+ 0.0171 * parameters.wait_so_far 
	+ 5149344.1739 * parameters.num_locks_so_far 
	+ 100370.6957 * parameters.num_of_wait_locks 
	- 2153.0262 * parameters.total_wait_locks 
	+ 0.0127 * parameters.mean_wait_of_all 
	- 2432432.2363 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_latency_of_same_past_second 
	+ 137525845.6835;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM56(work_wait &parameters) {
  double actual_remaining = 
	0.0025 * parameters.work_so_far 
	+ 0.3924 * parameters.wait_so_far 
	+ 1012109.1245 * parameters.num_locks_so_far 
	+ 476442.2415 * parameters.num_of_wait_locks 
	+ 201955.3264 * parameters.total_wait_locks 
	- 1.2769 * parameters.mean_wait_of_all 
	- 1960071.2714 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_latency_of_same_past_second 
	- 34449074.2893;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM57(work_wait &parameters) {
  double actual_remaining = 
	0.9124 * parameters.work_so_far 
	+ 0.2942 * parameters.wait_so_far 
	+ 801617.9267 * parameters.num_locks_so_far 
	+ 11346764.8129 * parameters.num_of_wait_locks 
	- 160862.2481 * parameters.total_wait_locks 
	+ 0.5117 * parameters.mean_wait_of_all 
	+ 215121377.0141 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_latency_of_same_past_second 
	- 35603469.5641;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM58(work_wait &parameters) {
  double actual_remaining = 
	0.6607 * parameters.work_so_far 
	+ 0.4264 * parameters.wait_so_far 
	+ 801617.9267 * parameters.num_locks_so_far 
	+ 8340079.8463 * parameters.num_of_wait_locks 
	- 119484.1153 * parameters.total_wait_locks 
	+ 0.3675 * parameters.mean_wait_of_all 
	+ 126938091.8111 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_latency_of_same_past_second 
	+ 33411561.7241;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM59(work_wait &parameters) {
  double actual_remaining = 
	0.0025 * parameters.work_so_far 
	+ 0.7224 * parameters.wait_so_far 
	+ 1180636.1806 * parameters.num_locks_so_far 
	+ 476442.2415 * parameters.num_of_wait_locks 
	+ 7811.4258 * parameters.total_wait_locks 
	- 0.0864 * parameters.mean_wait_of_all 
	- 51697204.0753 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_latency_of_same_past_second 
	- 16142974.5279;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM60(work_wait &parameters) {
  double actual_remaining = 
	0.0025 * parameters.work_so_far 
	+ 0.0963 * parameters.wait_so_far 
	+ 1917897.3286 * parameters.num_locks_so_far 
	+ 2225654.3771 * parameters.num_of_wait_locks 
	+ 290150.5753 * parameters.total_wait_locks 
	- 0.3508 * parameters.mean_wait_of_all 
	- 29236475.4161 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_latency_of_same_past_second 
	+ 118972683.0374;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM61(work_wait &parameters) {
  double actual_remaining = 
	0.0025 * parameters.work_so_far 
	+ 0.168 * parameters.wait_so_far 
	+ 2099032.1704 * parameters.num_locks_so_far 
	+ 2225654.3771 * parameters.num_of_wait_locks 
	+ 60331.8226 * parameters.total_wait_locks 
	- 0.5459 * parameters.mean_wait_of_all 
	- 358360807.291 * parameters.cpu_usage 
	- 0.0421 * parameters.avg_latency_of_same_past_second 
	+ 663039844.6582;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM62(work_wait &parameters) {
  double actual_remaining = 
	1.1801 * parameters.work_so_far 
	+ 0.2296 * parameters.wait_so_far 
	+ 2099032.1704 * parameters.num_locks_so_far 
	+ 2225654.3771 * parameters.num_of_wait_locks 
	- 307495.1048 * parameters.total_wait_locks 
	- 0.6961 * parameters.mean_wait_of_all 
	- 121626005.0385 * parameters.cpu_usage 
	- 0.5596 * parameters.avg_latency_of_same_past_second 
	+ 835218841.5185;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM63(work_wait &parameters) {
  double actual_remaining = 
	0.0025 * parameters.work_so_far 
	+ 0.8574 * parameters.wait_so_far 
	+ 2087650.2425 * parameters.num_locks_so_far 
	+ 127763821.8894 * parameters.num_of_wait_locks 
	+ 71536.0833 * parameters.total_wait_locks 
	- 0.4445 * parameters.mean_wait_of_all 
	- 1960071.2714 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_latency_of_same_past_second 
	- 824946643.8375;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
payment_estimate(work_wait &parameters){

  if (parameters.work_so_far <= 450754) {

    if (parameters.total_wait_locks <= 291.5) {

      if (parameters.work_so_far <= 9664.5) {

        if (parameters.total_wait_locks <= 18.5) {
          return payment_LM1(parameters);
        } else {

          if (parameters.mean_wait_of_all <= 31184000) {

            if (parameters.work_so_far <= 7800) {
              return payment_LM2(parameters);
            } else {

              if (parameters.avg_latency_of_same_past_second <= 19837050) {
                return payment_LM3(parameters);
              } else {
                return payment_LM4(parameters);
              }
            }
          } else {

            if (parameters.work_so_far <= 8495) {
              return payment_LM5(parameters);
            } else {

              if (parameters.avg_latency_of_same_past_second <= 29448250) {

                if (parameters.avg_latency_of_same_past_second <= 17604250) {
                  return payment_LM6(parameters);
                } else {

                  if (parameters.work_so_far <= 9395) {

                    if (parameters.total_wait_locks <= 27.5) {
                      return payment_LM7(parameters);
                    } else {

                      if (parameters.total_wait_locks <= 41) {
                        return payment_LM8(parameters);
                      } else {
                        return payment_LM9(parameters);
                      }
                    }
                  } else {
                    return payment_LM10(parameters);
                  }
                }
              } else {

                if (parameters.work_so_far <= 8904) {
                  return payment_LM11(parameters);
                } else {

                  if (parameters.total_wait_locks <= 32.5) {
                    return payment_LM12(parameters);
                  } else {

                    if (parameters.work_so_far <= 9105) {
                      return payment_LM13(parameters);
                    } else {

                      if (parameters.mean_wait_of_all <= 32862850) {
                        return payment_LM14(parameters);
                      } else {
                        return payment_LM15(parameters);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      } else {

        if (parameters.work_so_far <= 39045) {
          return payment_LM16(parameters);
        } else {
          return payment_LM17(parameters);
        }
      }
    } else {

      if (parameters.work_so_far <= 43881) {

        if (parameters.mean_wait_of_all <= 109032000) {

          if (parameters.wait_so_far <= 48111897) {
            return payment_LM18(parameters);
          } else {

            if (parameters.avg_latency_of_same_past_second <= 401914000) {

              if (parameters.mean_wait_of_all <= 84239100) {

                if (parameters.mean_wait_of_all <= 76230450) {
                  return payment_LM19(parameters);
                } else {

                  if (parameters.total_wait_locks <= 351) {

                    if (parameters.total_wait_locks <= 329.5) {
                      return payment_LM20(parameters);
                    } else {

                      if (parameters.total_wait_locks <= 349.5) {
                        return payment_LM21(parameters);
                      } else {
                        return payment_LM22(parameters);
                      }
                    }
                  } else {
                    return payment_LM23(parameters);
                  }
                }
              } else {
                return payment_LM24(parameters);
              }
            } else {

              if (parameters.mean_wait_of_all <= 99024700) {

                if (parameters.cpu_usage <= 0.89) {

                  if (parameters.mean_wait_of_all <= 91631350) {
                    return payment_LM25(parameters);
                  } else {

                    if (parameters.total_wait_locks <= 466) {

                      if (parameters.wait_so_far <= 223197406.5) {
                        return payment_LM26(parameters);
                      } else {
                        return payment_LM27(parameters);
                      }
                    } else {
                      return payment_LM28(parameters);
                    }
                  }
                } else {
                  return payment_LM29(parameters);
                }
              } else {

                if (parameters.mean_wait_of_all <= 102095500) {

                  if (parameters.cpu_usage <= 0.926) {
                    return payment_LM30(parameters);
                  } else {

                    if (parameters.avg_latency_of_same_past_second <= 440249000) {

                      if (parameters.mean_wait_of_all <= 101922000) {

                        if (parameters.mean_wait_of_all <= 99118950) {
                          return payment_LM31(parameters);
                        } else {
                          return payment_LM32(parameters);
                        }
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
          }
        } else {

          if (parameters.mean_wait_of_all <= 112935500) {

            if (parameters.avg_latency_of_same_past_second <= 416017500) {

              if (parameters.cpu_usage <= 0.977) {
                return payment_LM36(parameters);
              } else {
                return payment_LM37(parameters);
              }
            } else {

              if (parameters.avg_latency_of_same_past_second <= 437535500) {

                if (parameters.mean_wait_of_all <= 109915500) {
                  return payment_LM38(parameters);
                } else {

                  if (parameters.mean_wait_of_all <= 110348000) {
                    return payment_LM39(parameters);
                  } else {

                    if (parameters.mean_wait_of_all <= 112805500) {
                      return payment_LM40(parameters);
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
            return payment_LM43(parameters);
          }
        }
      } else {

        if (parameters.cpu_usage <= 0.869) {

          if (parameters.wait_so_far <= 341587150.5) {

            if (parameters.mean_wait_of_all <= 96508900) {

              if (parameters.total_wait_locks <= 341) {
                return payment_LM44(parameters);
              } else {

                if (parameters.total_wait_locks <= 359.5) {

                  if (parameters.wait_so_far <= 101882727) {
                    return payment_LM45(parameters);
                  } else {
                    return payment_LM46(parameters);
                  }
                } else {
                  return payment_LM47(parameters);
                }
              }
            } else {
              return payment_LM48(parameters);
            }
          } else {
            return payment_LM49(parameters);
          }
        } else {
          return payment_LM50(parameters);
        }
      }
    }
  } else {

    if (parameters.wait_so_far <= 305362742.5) {

      if (parameters.wait_so_far <= 138999266) {

        if (parameters.work_so_far <= 15055424) {
          return payment_LM51(parameters);
        } else {
          return payment_LM52(parameters);
        }
      } else {

        if (parameters.wait_so_far <= 182842077.5) {
          return payment_LM53(parameters);
        } else {

          if (parameters.num_locks_so_far <= 2.5) {
            return payment_LM54(parameters);
          } else {
            return payment_LM55(parameters);
          }
        }
      }
    } else {

      if (parameters.wait_so_far <= 564939090.5) {

        if (parameters.num_locks_so_far <= 2.5) {
          return payment_LM56(parameters);
        } else {

          if (parameters.cpu_usage <= 0.908) {

            if (parameters.num_of_wait_locks <= 3.5) {
              return payment_LM57(parameters);
            } else {
              return payment_LM58(parameters);
            }
          } else {
            return payment_LM59(parameters);
          }
        }
      } else {

        if (parameters.wait_so_far <= 890023224) {

          if (parameters.num_locks_so_far <= 2.5) {
            return payment_LM60(parameters);
          } else {

            if (parameters.wait_so_far <= 739243393) {
              return payment_LM61(parameters);
            } else {
              return payment_LM62(parameters);
            }
          }
        } else {
          return payment_LM63(parameters);
        }
      }
    }
  }
}
static
double
delivery_LM1(work_wait &parameters) {
  double actual_remaining = 
	0.7905 * parameters.work_so_far 
	+ 0.4253 * parameters.wait_so_far 
	- 331549.8744 * parameters.num_locks_so_far 
	+ 3632782.5838 * parameters.total_wait_locks 
	- 0.8906 * parameters.mean_wait_of_all 
	+ 640811732.0006 * parameters.cpu_usage 
	- 0.4423 * parameters.avg_latency_of_same_past_second 
	- 414579365.0108;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM2(work_wait &parameters) {
  double actual_remaining = 
	0.0896 * parameters.work_so_far 
	+ 0.2114 * parameters.wait_so_far 
	- 344497.788 * parameters.num_locks_so_far 
	- 173299.9761 * parameters.total_wait_locks 
	+ 0.6915 * parameters.mean_wait_of_all 
	- 82278028.1693 * parameters.cpu_usage 
	- 0.0116 * parameters.avg_latency_of_same_past_second 
	+ 660537823.7723;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM3(work_wait &parameters) {
  double actual_remaining = 
	0.6394 * parameters.work_so_far 
	+ 0.4236 * parameters.wait_so_far 
	- 6919098.5836 * parameters.num_locks_so_far 
	- 958254.5329 * parameters.total_wait_locks 
	+ 3.3669 * parameters.mean_wait_of_all 
	- 796341510.7398 * parameters.cpu_usage 
	- 0.2488 * parameters.avg_latency_of_same_past_second 
	+ 1963443399.0361;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
delivery_estimate(work_wait &parameters){

  if (parameters.total_wait_locks <= 173) {
    return delivery_LM1(parameters);
  } else {

    if (parameters.work_so_far <= 4438699) {
      return delivery_LM2(parameters);
    } else {
      return delivery_LM3(parameters);
    }
  }
}
static
double
stock_level_LM1(work_wait &parameters) {
  double actual_remaining = 
	+ 97376145.1;
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
	7.5347 * parameters.work_so_far 
	+ 43.8828 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 40623.241 * parameters.num_of_wait_locks 
	+ 1298.5168 * parameters.total_wait_locks 
	- 0.0068 * parameters.mean_wait_of_all 
	- 2093625.227 * parameters.cpu_usage 
	+ 0.0025 * parameters.avg_latency_of_same_past_second 
	+ 7923325.5132;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM2(work_wait &parameters) {
  double actual_remaining = 
	7.5347 * parameters.work_so_far 
	+ 1254.4538 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 40623.241 * parameters.num_of_wait_locks 
	- 79352.1247 * parameters.total_wait_locks 
	- 0.1544 * parameters.mean_wait_of_all 
	- 2093625.227 * parameters.cpu_usage 
	+ 0.0025 * parameters.avg_latency_of_same_past_second 
	+ 23025887.408;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM3(work_wait &parameters) {
  double actual_remaining = 
	35415.3524 * parameters.work_so_far 
	- 212896.7859 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	+ 18283062.4761 * parameters.num_of_wait_locks 
	+ 1691549.9341 * parameters.total_wait_locks 
	- 0.7025 * parameters.mean_wait_of_all 
	- 379575985.6517 * parameters.cpu_usage 
	- 0.4763 * parameters.avg_latency_of_same_past_second 
	+ 535452817.562;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM4(work_wait &parameters) {
  double actual_remaining = 
	4485.2881 * parameters.work_so_far 
	- 23150.5221 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	+ 21560396.6077 * parameters.num_of_wait_locks 
	+ 224435.7196 * parameters.total_wait_locks 
	- 0.5266 * parameters.mean_wait_of_all 
	- 281430177.5809 * parameters.cpu_usage 
	+ 0.002 * parameters.avg_latency_of_same_past_second 
	+ 273579996.6603;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM5(work_wait &parameters) {
  double actual_remaining = 
	4485.2881 * parameters.work_so_far 
	- 24168.3031 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	+ 50981048.4485 * parameters.num_of_wait_locks 
	+ 224435.7196 * parameters.total_wait_locks 
	- 0.5266 * parameters.mean_wait_of_all 
	- 255938514.9519 * parameters.cpu_usage 
	+ 0.002 * parameters.avg_latency_of_same_past_second 
	+ 197480780.5545;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM6(work_wait &parameters) {
  double actual_remaining = 
	1195.7402 * parameters.work_so_far 
	- 3851.1081 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 40623.241 * parameters.num_of_wait_locks 
	+ 29607.3162 * parameters.total_wait_locks 
	- 0.03 * parameters.mean_wait_of_all 
	- 73243083.1256 * parameters.cpu_usage 
	+ 0.0418 * parameters.avg_latency_of_same_past_second 
	+ 73423624.0181;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM7(work_wait &parameters) {
  double actual_remaining = 
	352.8206 * parameters.work_so_far 
	- 54.4942 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	+ 3471383.1854 * parameters.num_of_wait_locks 
	+ 2460.9838 * parameters.total_wait_locks 
	- 0.0082 * parameters.mean_wait_of_all 
	- 3771987.5246 * parameters.cpu_usage 
	+ 0.0033 * parameters.avg_latency_of_same_past_second 
	+ 6985631.2555;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM8(work_wait &parameters) {
  double actual_remaining = 
	18.9013 * parameters.work_so_far 
	+ 3193.2531 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	+ 59330.3839 * parameters.num_of_wait_locks 
	+ 2460.9838 * parameters.total_wait_locks 
	- 0.0078 * parameters.mean_wait_of_all 
	- 3771987.5246 * parameters.cpu_usage 
	+ 0.2191 * parameters.avg_latency_of_same_past_second 
	- 81986105.9684;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM9(work_wait &parameters) {
  double actual_remaining = 
	125.509 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 40623.241 * parameters.num_of_wait_locks 
	+ 4740.3439 * parameters.total_wait_locks 
	- 0.0015 * parameters.mean_wait_of_all 
	- 952942.678 * parameters.cpu_usage 
	+ 0.0009 * parameters.avg_latency_of_same_past_second 
	+ 5543013.2013;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM10(work_wait &parameters) {
  double actual_remaining = 
	148.8897 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 40623.241 * parameters.num_of_wait_locks 
	+ 2505.9563 * parameters.total_wait_locks 
	- 0.0015 * parameters.mean_wait_of_all 
	- 952942.678 * parameters.cpu_usage 
	+ 0.0009 * parameters.avg_latency_of_same_past_second 
	+ 7282093.4579;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM11(work_wait &parameters) {
  double actual_remaining = 
	109.8 * parameters.work_so_far 
	+ 0.0052 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 40623.241 * parameters.num_of_wait_locks 
	+ 2505.9563 * parameters.total_wait_locks 
	- 0.0015 * parameters.mean_wait_of_all 
	- 952942.678 * parameters.cpu_usage 
	+ 0.0009 * parameters.avg_latency_of_same_past_second 
	+ 6769971.4357;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM12(work_wait &parameters) {
  double actual_remaining = 
	3185.5006 * parameters.work_so_far 
	+ 0.0021 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 40623.241 * parameters.num_of_wait_locks 
	- 162837.953 * parameters.total_wait_locks 
	- 0.0015 * parameters.mean_wait_of_all 
	- 952942.678 * parameters.cpu_usage 
	+ 0.0009 * parameters.avg_latency_of_same_past_second 
	- 2123621.606;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM13(work_wait &parameters) {
  double actual_remaining = 
	2570.3605 * parameters.work_so_far 
	+ 0.0021 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 40623.241 * parameters.num_of_wait_locks 
	- 400140.6425 * parameters.total_wait_locks 
	+ 77.0358 * parameters.mean_wait_of_all 
	- 952942.678 * parameters.cpu_usage 
	+ 0.0009 * parameters.avg_latency_of_same_past_second 
	- 2386484740.5263;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM14(work_wait &parameters) {
  double actual_remaining = 
	2570.3605 * parameters.work_so_far 
	+ 0.0021 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 40623.241 * parameters.num_of_wait_locks 
	- 400140.6425 * parameters.total_wait_locks 
	+ 81.3156 * parameters.mean_wait_of_all 
	- 952942.678 * parameters.cpu_usage 
	+ 0.0009 * parameters.avg_latency_of_same_past_second 
	- 2517242027.5157;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM15(work_wait &parameters) {
  double actual_remaining = 
	2570.3605 * parameters.work_so_far 
	+ 0.0021 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 40623.241 * parameters.num_of_wait_locks 
	- 286300.023 * parameters.total_wait_locks 
	- 29.8676 * parameters.mean_wait_of_all 
	- 952942.678 * parameters.cpu_usage 
	+ 0.0009 * parameters.avg_latency_of_same_past_second 
	+ 953522234.5223;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM16(work_wait &parameters) {
  double actual_remaining = 
	2570.3605 * parameters.work_so_far 
	+ 0.0021 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 40623.241 * parameters.num_of_wait_locks 
	- 286300.023 * parameters.total_wait_locks 
	- 19.6011 * parameters.mean_wait_of_all 
	- 952942.678 * parameters.cpu_usage 
	+ 0.0009 * parameters.avg_latency_of_same_past_second 
	+ 628162256.4817;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM17(work_wait &parameters) {
  double actual_remaining = 
	109.8 * parameters.work_so_far 
	+ 0.0021 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 40623.241 * parameters.num_of_wait_locks 
	+ 2505.9563 * parameters.total_wait_locks 
	- 0.0015 * parameters.mean_wait_of_all 
	- 952942.678 * parameters.cpu_usage 
	+ 0.0009 * parameters.avg_latency_of_same_past_second 
	+ 8155150.3185;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM18(work_wait &parameters) {
  double actual_remaining = 
	-6130.2602 * parameters.work_so_far 
	+ 0.0021 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 40623.241 * parameters.num_of_wait_locks 
	+ 842447.6827 * parameters.total_wait_locks 
	- 0.0015 * parameters.mean_wait_of_all 
	- 952942.678 * parameters.cpu_usage 
	+ 0.0009 * parameters.avg_latency_of_same_past_second 
	+ 48966059.6875;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM19(work_wait &parameters) {
  double actual_remaining = 
	-2890.2289 * parameters.work_so_far 
	+ 0.0021 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 40623.241 * parameters.num_of_wait_locks 
	+ 262638.08 * parameters.total_wait_locks 
	- 0.0015 * parameters.mean_wait_of_all 
	- 952942.678 * parameters.cpu_usage 
	+ 0.0009 * parameters.avg_latency_of_same_past_second 
	+ 28777347.7392;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM20(work_wait &parameters) {
  double actual_remaining = 
	1.2154 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 40623.241 * parameters.num_of_wait_locks 
	+ 36813.2927 * parameters.total_wait_locks 
	- 0.0015 * parameters.mean_wait_of_all 
	- 19376927.704 * parameters.cpu_usage 
	+ 0.0009 * parameters.avg_latency_of_same_past_second 
	+ 35069334.9607;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM21(work_wait &parameters) {
  double actual_remaining = 
	2.054 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 40623.241 * parameters.num_of_wait_locks 
	+ 30550.4246 * parameters.total_wait_locks 
	- 0.0015 * parameters.mean_wait_of_all 
	- 867754.595 * parameters.cpu_usage 
	- 0.0099 * parameters.avg_latency_of_same_past_second 
	+ 15270836.681;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM22(work_wait &parameters) {
  double actual_remaining = 
	5.392 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 40623.241 * parameters.num_of_wait_locks 
	- 215110.6276 * parameters.total_wait_locks 
	+ 0.5935 * parameters.mean_wait_of_all 
	- 867754.595 * parameters.cpu_usage 
	+ 0.002 * parameters.avg_latency_of_same_past_second 
	+ 46583530.7752;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM23(work_wait &parameters) {
  double actual_remaining = 
	5.392 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 40623.241 * parameters.num_of_wait_locks 
	+ 242100.6236 * parameters.total_wait_locks 
	+ 3.9614 * parameters.mean_wait_of_all 
	- 867754.595 * parameters.cpu_usage 
	+ 0.002 * parameters.avg_latency_of_same_past_second 
	- 233018017.3273;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM24(work_wait &parameters) {
  double actual_remaining = 
	33.2092 * parameters.work_so_far 
	+ 0.1671 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 40623.241 * parameters.num_of_wait_locks 
	- 56144.7266 * parameters.total_wait_locks 
	+ 0.0499 * parameters.mean_wait_of_all 
	- 181790096.3832 * parameters.cpu_usage 
	- 0.2078 * parameters.avg_latency_of_same_past_second 
	+ 303972348.6739;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM25(work_wait &parameters) {
  double actual_remaining = 
	281.9387 * parameters.work_so_far 
	- 0.0073 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 40623.241 * parameters.num_of_wait_locks 
	- 56144.7266 * parameters.total_wait_locks 
	+ 0.0499 * parameters.mean_wait_of_all 
	- 116497662.3591 * parameters.cpu_usage 
	- 0.1428 * parameters.avg_latency_of_same_past_second 
	+ 200528382.4945;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM26(work_wait &parameters) {
  double actual_remaining = 
	33.2092 * parameters.work_so_far 
	- 0.0113 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 40623.241 * parameters.num_of_wait_locks 
	- 56144.7266 * parameters.total_wait_locks 
	+ 0.0499 * parameters.mean_wait_of_all 
	- 95749068.5846 * parameters.cpu_usage 
	- 0.1255 * parameters.avg_latency_of_same_past_second 
	+ 177749519.6025;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM27(work_wait &parameters) {
  double actual_remaining = 
	55.4233 * parameters.work_so_far 
	- 0.0053 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 40623.241 * parameters.num_of_wait_locks 
	- 90095.0088 * parameters.total_wait_locks 
	+ 0.0499 * parameters.mean_wait_of_all 
	- 867754.595 * parameters.cpu_usage 
	- 0.0511 * parameters.avg_latency_of_same_past_second 
	+ 57940477.7754;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM28(work_wait &parameters) {
  double actual_remaining = 
	0.1243 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	+ 7464437.986 * parameters.num_of_wait_locks 
	+ 13074.6312 * parameters.total_wait_locks 
	- 0.0531 * parameters.mean_wait_of_all 
	- 4506957.5806 * parameters.cpu_usage 
	+ 0.0011 * parameters.avg_latency_of_same_past_second 
	+ 21078396.2128;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM29(work_wait &parameters) {
  double actual_remaining = 
	-11.6637 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 40623.241 * parameters.num_of_wait_locks 
	+ 29765.2103 * parameters.total_wait_locks 
	- 0.1115 * parameters.mean_wait_of_all 
	+ 7192310.864 * parameters.cpu_usage 
	+ 0.0011 * parameters.avg_latency_of_same_past_second 
	+ 16743991.8645;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM30(work_wait &parameters) {
  double actual_remaining = 
	-27.381 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 40623.241 * parameters.num_of_wait_locks 
	+ 39045.132 * parameters.total_wait_locks 
	- 0.1468 * parameters.mean_wait_of_all 
	+ 7192310.864 * parameters.cpu_usage 
	+ 0.0011 * parameters.avg_latency_of_same_past_second 
	+ 11271230.9615;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM31(work_wait &parameters) {
  double actual_remaining = 
	0.1243 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 191726.8916 * parameters.num_of_wait_locks 
	+ 23039.1399 * parameters.total_wait_locks 
	- 0.278 * parameters.mean_wait_of_all 
	+ 6761753.7537 * parameters.cpu_usage 
	+ 0.0011 * parameters.avg_latency_of_same_past_second 
	+ 36628762.8258;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM32(work_wait &parameters) {
  double actual_remaining = 
	0.1243 * parameters.work_so_far 
	- 0.052 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 916205.311 * parameters.num_of_wait_locks 
	+ 20971.4228 * parameters.total_wait_locks 
	- 0.1306 * parameters.mean_wait_of_all 
	- 79510776.8265 * parameters.cpu_usage 
	- 0.043 * parameters.avg_latency_of_same_past_second 
	+ 152342559.1376;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM33(work_wait &parameters) {
  double actual_remaining = 
	0.1243 * parameters.work_so_far 
	- 0.0736 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 916205.311 * parameters.num_of_wait_locks 
	- 31887.0546 * parameters.total_wait_locks 
	+ 0.0115 * parameters.mean_wait_of_all 
	+ 288217607.0987 * parameters.cpu_usage 
	- 0.043 * parameters.avg_latency_of_same_past_second 
	- 202382088.5492;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM34(work_wait &parameters) {
  double actual_remaining = 
	0.1243 * parameters.work_so_far 
	- 0.0491 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 614058.6289 * parameters.num_of_wait_locks 
	+ 175553.0634 * parameters.total_wait_locks 
	- 0.5413 * parameters.mean_wait_of_all 
	- 41788907.5206 * parameters.cpu_usage 
	- 0.024 * parameters.avg_latency_of_same_past_second 
	+ 60582720.0563;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM35(work_wait &parameters) {
  double actual_remaining = 
	0.1243 * parameters.work_so_far 
	+ 0.0644 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 614058.6289 * parameters.num_of_wait_locks 
	+ 293555.3175 * parameters.total_wait_locks 
	+ 0.1378 * parameters.mean_wait_of_all 
	- 41788907.5206 * parameters.cpu_usage 
	- 0.4075 * parameters.avg_latency_of_same_past_second 
	+ 104734713.6779;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM36(work_wait &parameters) {
  double actual_remaining = 
	0.1243 * parameters.work_so_far 
	+ 0.2487 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 614058.6289 * parameters.num_of_wait_locks 
	+ 293555.3175 * parameters.total_wait_locks 
	+ 0.972 * parameters.mean_wait_of_all 
	- 41788907.5206 * parameters.cpu_usage 
	- 0.4307 * parameters.avg_latency_of_same_past_second 
	+ 38511408.9655;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM37(work_wait &parameters) {
  double actual_remaining = 
	0.1243 * parameters.work_so_far 
	- 0.0329 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 40623.241 * parameters.num_of_wait_locks 
	- 188.0264 * parameters.total_wait_locks 
	- 0.0016 * parameters.mean_wait_of_all 
	- 987805.2293 * parameters.cpu_usage 
	+ 0.0011 * parameters.avg_latency_of_same_past_second 
	+ 29796280.9342;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM38(work_wait &parameters) {
  double actual_remaining = 
	0.1243 * parameters.work_so_far 
	- 0.0364 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 40623.241 * parameters.num_of_wait_locks 
	+ 3178.7548 * parameters.total_wait_locks 
	- 0.14 * parameters.mean_wait_of_all 
	- 470679.0889 * parameters.cpu_usage 
	+ 0.0011 * parameters.avg_latency_of_same_past_second 
	+ 42152967.6555;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM39(work_wait &parameters) {
  double actual_remaining = 
	0.1243 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 40623.241 * parameters.num_of_wait_locks 
	+ 1140505.4436 * parameters.total_wait_locks 
	- 0.5437 * parameters.mean_wait_of_all 
	+ 1476662762.6303 * parameters.cpu_usage 
	- 0.3243 * parameters.avg_latency_of_same_past_second 
	- 1877505704.8733;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM40(work_wait &parameters) {
  double actual_remaining = 
	0.1243 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 40623.241 * parameters.num_of_wait_locks 
	+ 1265535.4837 * parameters.total_wait_locks 
	- 0.5437 * parameters.mean_wait_of_all 
	+ 3372517003.7332 * parameters.cpu_usage 
	- 0.5979 * parameters.avg_latency_of_same_past_second 
	- 3711169632.8741;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM41(work_wait &parameters) {
  double actual_remaining = 
	0.1243 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 40623.241 * parameters.num_of_wait_locks 
	+ 1341649.6517 * parameters.total_wait_locks 
	- 0.5437 * parameters.mean_wait_of_all 
	+ 2854456520.9765 * parameters.cpu_usage 
	- 0.5993 * parameters.avg_latency_of_same_past_second 
	- 3225754499.0211;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM42(work_wait &parameters) {
  double actual_remaining = 
	0.1243 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 40623.241 * parameters.num_of_wait_locks 
	+ 1364036.1717 * parameters.total_wait_locks 
	- 0.5437 * parameters.mean_wait_of_all 
	+ 2854456520.9765 * parameters.cpu_usage 
	- 0.5993 * parameters.avg_latency_of_same_past_second 
	- 3238288520.1005;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM43(work_wait &parameters) {
  double actual_remaining = 
	0.1243 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 40623.241 * parameters.num_of_wait_locks 
	+ 1265535.4837 * parameters.total_wait_locks 
	- 0.5437 * parameters.mean_wait_of_all 
	+ 2854456520.9765 * parameters.cpu_usage 
	- 0.6233 * parameters.avg_latency_of_same_past_second 
	- 3177484399.1084;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM44(work_wait &parameters) {
  double actual_remaining = 
	0.1243 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 40623.241 * parameters.num_of_wait_locks 
	+ 896140.8348 * parameters.total_wait_locks 
	- 0.5437 * parameters.mean_wait_of_all 
	+ 1307288233.443 * parameters.cpu_usage 
	- 0.2595 * parameters.avg_latency_of_same_past_second 
	- 1603566011.6807;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM45(work_wait &parameters) {
  double actual_remaining = 
	0.1243 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	+ 5276008.0277 * parameters.num_of_wait_locks 
	+ 9221.3183 * parameters.total_wait_locks 
	- 0.232 * parameters.mean_wait_of_all 
	- 470679.0889 * parameters.cpu_usage 
	+ 0.0011 * parameters.avg_latency_of_same_past_second 
	+ 43217488.1079;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM46(work_wait &parameters) {
  double actual_remaining = 
	-3.2947 * parameters.work_so_far 
	- 0.0013 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 61847.2914 * parameters.num_of_wait_locks 
	- 11050.3158 * parameters.total_wait_locks 
	- 0.0449 * parameters.mean_wait_of_all 
	- 470679.0889 * parameters.cpu_usage 
	+ 0.0334 * parameters.avg_latency_of_same_past_second 
	+ 21154370.2917;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM47(work_wait &parameters) {
  double actual_remaining = 
	-3.2947 * parameters.work_so_far 
	- 0.003 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 61847.2914 * parameters.num_of_wait_locks 
	- 11050.3158 * parameters.total_wait_locks 
	+ 0.0298 * parameters.mean_wait_of_all 
	- 470679.0889 * parameters.cpu_usage 
	+ 0.0908 * parameters.avg_latency_of_same_past_second 
	+ 8014197.8257;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM48(work_wait &parameters) {
  double actual_remaining = 
	-86.6498 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 2507778.941 * parameters.num_of_wait_locks 
	- 7782.8189 * parameters.total_wait_locks 
	+ 0.0385 * parameters.mean_wait_of_all 
	- 470679.0889 * parameters.cpu_usage 
	- 0.0003 * parameters.avg_latency_of_same_past_second 
	+ 34424650.1724;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM49(work_wait &parameters) {
  double actual_remaining = 
	0.1243 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 97455.1109 * parameters.num_of_wait_locks 
	- 118455.5157 * parameters.total_wait_locks 
	+ 0.2768 * parameters.mean_wait_of_all 
	- 15367372.849 * parameters.cpu_usage 
	+ 0.8405 * parameters.avg_latency_of_same_past_second 
	- 274380831.5648;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM50(work_wait &parameters) {
  double actual_remaining = 
	-62.0401 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 97455.1109 * parameters.num_of_wait_locks 
	- 118455.5157 * parameters.total_wait_locks 
	+ 0.2768 * parameters.mean_wait_of_all 
	- 15367372.849 * parameters.cpu_usage 
	+ 0.8405 * parameters.avg_latency_of_same_past_second 
	- 268940290.0393;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM51(work_wait &parameters) {
  double actual_remaining = 
	-26.6588 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 97455.1109 * parameters.num_of_wait_locks 
	- 118455.5157 * parameters.total_wait_locks 
	+ 0.2768 * parameters.mean_wait_of_all 
	- 15367372.849 * parameters.cpu_usage 
	+ 0.9098 * parameters.avg_latency_of_same_past_second 
	- 298829547.0528;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM52(work_wait &parameters) {
  double actual_remaining = 
	-25.1708 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 97455.1109 * parameters.num_of_wait_locks 
	- 118455.5157 * parameters.total_wait_locks 
	+ 0.2768 * parameters.mean_wait_of_all 
	- 15367372.849 * parameters.cpu_usage 
	+ 0.9098 * parameters.avg_latency_of_same_past_second 
	- 299178875.8779;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM53(work_wait &parameters) {
  double actual_remaining = 
	0.1243 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 97455.1109 * parameters.num_of_wait_locks 
	- 118455.5157 * parameters.total_wait_locks 
	+ 0.2768 * parameters.mean_wait_of_all 
	- 15367372.849 * parameters.cpu_usage 
	+ 0.7533 * parameters.avg_latency_of_same_past_second 
	- 239330801.4811;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM54(work_wait &parameters) {
  double actual_remaining = 
	0.1243 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 97455.1109 * parameters.num_of_wait_locks 
	- 118455.5157 * parameters.total_wait_locks 
	+ 0.2768 * parameters.mean_wait_of_all 
	- 15367372.849 * parameters.cpu_usage 
	+ 0.0011 * parameters.avg_latency_of_same_past_second 
	+ 65217167.4939;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM55(work_wait &parameters) {
  double actual_remaining = 
	0.1243 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 97455.1109 * parameters.num_of_wait_locks 
	- 118455.5157 * parameters.total_wait_locks 
	+ 0.196 * parameters.mean_wait_of_all 
	- 15367372.849 * parameters.cpu_usage 
	+ 0.0011 * parameters.avg_latency_of_same_past_second 
	+ 66718516.4303;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM56(work_wait &parameters) {
  double actual_remaining = 
	79.0647 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 97455.1109 * parameters.num_of_wait_locks 
	- 72055.5034 * parameters.total_wait_locks 
	+ 0.6234 * parameters.mean_wait_of_all 
	- 5811003.267 * parameters.cpu_usage 
	+ 0.0011 * parameters.avg_latency_of_same_past_second 
	+ 4508340.5949;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM57(work_wait &parameters) {
  double actual_remaining = 
	174.4834 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 97455.1109 * parameters.num_of_wait_locks 
	- 72055.5034 * parameters.total_wait_locks 
	+ 0.5139 * parameters.mean_wait_of_all 
	- 5811003.267 * parameters.cpu_usage 
	+ 0.9386 * parameters.avg_latency_of_same_past_second 
	- 368478996.6182;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM58(work_wait &parameters) {
  double actual_remaining = 
	155.9378 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 97455.1109 * parameters.num_of_wait_locks 
	- 72055.5034 * parameters.total_wait_locks 
	+ 0.5139 * parameters.mean_wait_of_all 
	- 5811003.267 * parameters.cpu_usage 
	+ 0.7997 * parameters.avg_latency_of_same_past_second 
	- 305923881.1651;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM59(work_wait &parameters) {
  double actual_remaining = 
	49.3003 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 97455.1109 * parameters.num_of_wait_locks 
	- 159677.5198 * parameters.total_wait_locks 
	+ 0.5139 * parameters.mean_wait_of_all 
	- 5811003.267 * parameters.cpu_usage 
	+ 0.0011 * parameters.avg_latency_of_same_past_second 
	+ 45322537.7955;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM60(work_wait &parameters) {
  double actual_remaining = 
	49.3003 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 97455.1109 * parameters.num_of_wait_locks 
	- 128752.1022 * parameters.total_wait_locks 
	+ 0.5139 * parameters.mean_wait_of_all 
	- 5811003.267 * parameters.cpu_usage 
	+ 0.0011 * parameters.avg_latency_of_same_past_second 
	+ 33047391.0935;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM61(work_wait &parameters) {
  double actual_remaining = 
	0.1243 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 97455.1109 * parameters.num_of_wait_locks 
	- 72055.5034 * parameters.total_wait_locks 
	+ 0.333 * parameters.mean_wait_of_all 
	- 5811003.267 * parameters.cpu_usage 
	+ 0.0011 * parameters.avg_latency_of_same_past_second 
	+ 23110473.4009;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM62(work_wait &parameters) {
  double actual_remaining = 
	0.1243 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 97455.1109 * parameters.num_of_wait_locks 
	- 1124035.6431 * parameters.total_wait_locks 
	+ 3.6176 * parameters.mean_wait_of_all 
	- 470679.0889 * parameters.cpu_usage 
	- 1.5256 * parameters.avg_latency_of_same_past_second 
	+ 861020833.5224;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM63(work_wait &parameters) {
  double actual_remaining = 
	0.1243 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 97455.1109 * parameters.num_of_wait_locks 
	- 658440.6497 * parameters.total_wait_locks 
	+ 6.5472 * parameters.mean_wait_of_all 
	- 470679.0889 * parameters.cpu_usage 
	- 0.5833 * parameters.avg_latency_of_same_past_second 
	- 46144380.1731;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM64(work_wait &parameters) {
  double actual_remaining = 
	0.1243 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 97455.1109 * parameters.num_of_wait_locks 
	- 580742.0949 * parameters.total_wait_locks 
	+ 6.4278 * parameters.mean_wait_of_all 
	- 470679.0889 * parameters.cpu_usage 
	- 0.5833 * parameters.avg_latency_of_same_past_second 
	- 57797220.5097;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM65(work_wait &parameters) {
  double actual_remaining = 
	0.1243 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 97455.1109 * parameters.num_of_wait_locks 
	- 706217.6781 * parameters.total_wait_locks 
	+ 7.8154 * parameters.mean_wait_of_all 
	- 470679.0889 * parameters.cpu_usage 
	- 0.5833 * parameters.avg_latency_of_same_past_second 
	- 149319914.0596;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM66(work_wait &parameters) {
  double actual_remaining = 
	0.1243 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 2010439.9324 * parameters.num_of_wait_locks 
	- 195767.6294 * parameters.total_wait_locks 
	+ 1.0866 * parameters.mean_wait_of_all 
	- 9678135.6623 * parameters.cpu_usage 
	+ 0.1959 * parameters.avg_latency_of_same_past_second 
	- 49323412.92;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM67(work_wait &parameters) {
  double actual_remaining = 
	0.1243 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 2010439.9324 * parameters.num_of_wait_locks 
	- 195767.6294 * parameters.total_wait_locks 
	+ 1.0866 * parameters.mean_wait_of_all 
	- 7942806.6335 * parameters.cpu_usage 
	+ 0.1959 * parameters.avg_latency_of_same_past_second 
	- 50595090.0342;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM68(work_wait &parameters) {
  double actual_remaining = 
	0.1243 * parameters.work_so_far 
	- 0.0136 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 2010439.9324 * parameters.num_of_wait_locks 
	- 195767.6294 * parameters.total_wait_locks 
	+ 1.0866 * parameters.mean_wait_of_all 
	- 19511666.8253 * parameters.cpu_usage 
	+ 0.1959 * parameters.avg_latency_of_same_past_second 
	- 31225654.2911;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM69(work_wait &parameters) {
  double actual_remaining = 
	0.1243 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 2010439.9324 * parameters.num_of_wait_locks 
	- 195767.6294 * parameters.total_wait_locks 
	+ 1.0866 * parameters.mean_wait_of_all 
	- 19511666.8253 * parameters.cpu_usage 
	+ 0.1959 * parameters.avg_latency_of_same_past_second 
	- 42372046.3868;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM70(work_wait &parameters) {
  double actual_remaining = 
	0.1243 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 862649.0395 * parameters.num_of_wait_locks 
	- 259821.5658 * parameters.total_wait_locks 
	+ 1.0866 * parameters.mean_wait_of_all 
	- 8087074.1835 * parameters.cpu_usage 
	+ 0.4074 * parameters.avg_latency_of_same_past_second 
	- 111800006.6665;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM71(work_wait &parameters) {
  double actual_remaining = 
	0.1003 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 83484.0521 * parameters.num_of_wait_locks 
	- 7104.9632 * parameters.total_wait_locks 
	+ 0.0322 * parameters.mean_wait_of_all 
	+ 553237.7454 * parameters.cpu_usage 
	+ 0.0069 * parameters.avg_latency_of_same_past_second 
	+ 19265588.8428;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM72(work_wait &parameters) {
  double actual_remaining = 
	2.2194 * parameters.work_so_far 
	+ 0.0083 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 361278.954 * parameters.num_of_wait_locks 
	- 734129.9609 * parameters.total_wait_locks 
	+ 5.9021 * parameters.mean_wait_of_all 
	- 102110485.9802 * parameters.cpu_usage 
	- 0.3727 * parameters.avg_latency_of_same_past_second 
	+ 131922358.4457;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM73(work_wait &parameters) {
  double actual_remaining = 
	2.2194 * parameters.work_so_far 
	+ 0.0043 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 239389.3542 * parameters.num_of_wait_locks 
	- 9183.3867 * parameters.total_wait_locks 
	+ 1.2604 * parameters.mean_wait_of_all 
	+ 553237.7454 * parameters.cpu_usage 
	+ 0.0069 * parameters.avg_latency_of_same_past_second 
	- 72643618.9527;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM74(work_wait &parameters) {
  double actual_remaining = 
	2.2194 * parameters.work_so_far 
	- 0.0014 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 83484.0521 * parameters.num_of_wait_locks 
	- 9183.3867 * parameters.total_wait_locks 
	+ 0.5761 * parameters.mean_wait_of_all 
	+ 553237.7454 * parameters.cpu_usage 
	+ 0.0069 * parameters.avg_latency_of_same_past_second 
	- 22137427.283;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM75(work_wait &parameters) {
  double actual_remaining = 
	118.2969 * parameters.work_so_far 
	- 0.0006 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 83484.0521 * parameters.num_of_wait_locks 
	+ 89192.6889 * parameters.total_wait_locks 
	+ 0.0652 * parameters.mean_wait_of_all 
	+ 553237.7454 * parameters.cpu_usage 
	+ 0.0069 * parameters.avg_latency_of_same_past_second 
	- 36401721.7271;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM76(work_wait &parameters) {
  double actual_remaining = 
	-2.2584 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 83484.0521 * parameters.num_of_wait_locks 
	- 2721.2923 * parameters.total_wait_locks 
	- 0.1476 * parameters.mean_wait_of_all 
	+ 553237.7454 * parameters.cpu_usage 
	+ 0.1263 * parameters.avg_latency_of_same_past_second 
	- 14825515.7263;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM77(work_wait &parameters) {
  double actual_remaining = 
	-2.2584 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 83484.0521 * parameters.num_of_wait_locks 
	- 100702.4695 * parameters.total_wait_locks 
	- 0.3686 * parameters.mean_wait_of_all 
	- 247009744.8468 * parameters.cpu_usage 
	- 0.0788 * parameters.avg_latency_of_same_past_second 
	+ 402010635.7547;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM78(work_wait &parameters) {
  double actual_remaining = 
	-2.2584 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 15424598.993 * parameters.num_of_wait_locks 
	- 54044.766 * parameters.total_wait_locks 
	- 3.2337 * parameters.mean_wait_of_all 
	- 452331508.1071 * parameters.cpu_usage 
	- 8.787 * parameters.avg_latency_of_same_past_second 
	+ 4829549727.5671;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM79(work_wait &parameters) {
  double actual_remaining = 
	-2.2584 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 29837856.6028 * parameters.num_of_wait_locks 
	- 54044.766 * parameters.total_wait_locks 
	- 3.2337 * parameters.mean_wait_of_all 
	- 452331508.1071 * parameters.cpu_usage 
	- 8.282 * parameters.avg_latency_of_same_past_second 
	+ 4630449740.7561;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM80(work_wait &parameters) {
  double actual_remaining = 
	-2.2584 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 2415566.2836 * parameters.num_of_wait_locks 
	- 54044.766 * parameters.total_wait_locks 
	- 2.7486 * parameters.mean_wait_of_all 
	+ 52607699.2353 * parameters.cpu_usage 
	- 2.6247 * parameters.avg_latency_of_same_past_second 
	+ 1474195076.5332;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM81(work_wait &parameters) {
  double actual_remaining = 
	-600.7878 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 2415566.2836 * parameters.num_of_wait_locks 
	+ 161079.6993 * parameters.total_wait_locks 
	- 8.6882 * parameters.mean_wait_of_all 
	+ 359871504.994 * parameters.cpu_usage 
	- 3.3194 * parameters.avg_latency_of_same_past_second 
	+ 2071595107.2223;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM82(work_wait &parameters) {
  double actual_remaining = 
	-604.8969 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 83484.0521 * parameters.num_of_wait_locks 
	+ 149081.4541 * parameters.total_wait_locks 
	- 1.9924 * parameters.mean_wait_of_all 
	- 78437719.8168 * parameters.cpu_usage 
	- 0.0959 * parameters.avg_latency_of_same_past_second 
	+ 300072117.5666;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM83(work_wait &parameters) {
  double actual_remaining = 
	-604.8969 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 83484.0521 * parameters.num_of_wait_locks 
	+ 149081.4541 * parameters.total_wait_locks 
	- 1.9924 * parameters.mean_wait_of_all 
	- 78437719.8168 * parameters.cpu_usage 
	- 0.0959 * parameters.avg_latency_of_same_past_second 
	+ 295300077.3108;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM84(work_wait &parameters) {
  double actual_remaining = 
	-2.2584 * parameters.work_so_far 
	- 0.0143 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 83484.0521 * parameters.num_of_wait_locks 
	- 273038.9697 * parameters.total_wait_locks 
	- 0.9303 * parameters.mean_wait_of_all 
	- 78437719.8168 * parameters.cpu_usage 
	- 0.0959 * parameters.avg_latency_of_same_past_second 
	+ 413523550.0878;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM85(work_wait &parameters) {
  double actual_remaining = 
	-2.2584 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 83484.0521 * parameters.num_of_wait_locks 
	+ 34829.4678 * parameters.total_wait_locks 
	- 0.9303 * parameters.mean_wait_of_all 
	- 78437719.8168 * parameters.cpu_usage 
	- 0.0959 * parameters.avg_latency_of_same_past_second 
	+ 236448398.768;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM86(work_wait &parameters) {
  double actual_remaining = 
	-2.2584 * parameters.work_so_far 
	+ 0.0529 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 83484.0521 * parameters.num_of_wait_locks 
	+ 34829.4678 * parameters.total_wait_locks 
	- 4.255 * parameters.mean_wait_of_all 
	- 78437719.8168 * parameters.cpu_usage 
	- 0.0959 * parameters.avg_latency_of_same_past_second 
	+ 619250436.6732;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM87(work_wait &parameters) {
  double actual_remaining = 
	-2.2584 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 83484.0521 * parameters.num_of_wait_locks 
	+ 34829.4678 * parameters.total_wait_locks 
	- 0.9303 * parameters.mean_wait_of_all 
	- 78437719.8168 * parameters.cpu_usage 
	- 0.0959 * parameters.avg_latency_of_same_past_second 
	+ 230701126.8144;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM88(work_wait &parameters) {
  double actual_remaining = 
	-5.5325 * parameters.work_so_far 
	- 0.0023 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 150474.7931 * parameters.num_of_wait_locks 
	- 158968.5727 * parameters.total_wait_locks 
	+ 0.9266 * parameters.mean_wait_of_all 
	- 44412689.3506 * parameters.cpu_usage 
	+ 0.0728 * parameters.avg_latency_of_same_past_second 
	+ 24019225.6122;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM89(work_wait &parameters) {
  double actual_remaining = 
	620.0346 * parameters.work_so_far 
	- 0.158 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 150474.7931 * parameters.num_of_wait_locks 
	+ 207480.9083 * parameters.total_wait_locks 
	- 1.7732 * parameters.mean_wait_of_all 
	+ 3870416.9581 * parameters.cpu_usage 
	+ 1.3934 * parameters.avg_latency_of_same_past_second 
	- 699942965.2441;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM90(work_wait &parameters) {
  double actual_remaining = 
	-5.5325 * parameters.work_so_far 
	- 0.0512 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 150474.7931 * parameters.num_of_wait_locks 
	- 1037958.8533 * parameters.total_wait_locks 
	+ 3.5209 * parameters.mean_wait_of_all 
	+ 3870416.9581 * parameters.cpu_usage 
	+ 0.3706 * parameters.avg_latency_of_same_past_second 
	+ 381505515.885;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM91(work_wait &parameters) {
  double actual_remaining = 
	-5.5325 * parameters.work_so_far 
	- 0.0512 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 150474.7931 * parameters.num_of_wait_locks 
	- 722868.3825 * parameters.total_wait_locks 
	+ 0.6698 * parameters.mean_wait_of_all 
	+ 3870416.9581 * parameters.cpu_usage 
	+ 0.3706 * parameters.avg_latency_of_same_past_second 
	+ 339683836.2515;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM92(work_wait &parameters) {
  double actual_remaining = 
	0.0045 * parameters.work_so_far 
	+ 0.0705 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	+ 1865899.6997 * parameters.num_of_wait_locks 
	- 566.5089 * parameters.total_wait_locks 
	+ 0.0007 * parameters.mean_wait_of_all 
	- 23659711.3488 * parameters.cpu_usage 
	+ 0.0341 * parameters.avg_latency_of_same_past_second 
	+ 34904021.6628;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM93(work_wait &parameters) {
  double actual_remaining = 
	0.0349 * parameters.work_so_far 
	+ 0.0124 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 340045.8532 * parameters.num_of_wait_locks 
	- 115898.9396 * parameters.total_wait_locks 
	+ 0.6264 * parameters.mean_wait_of_all 
	+ 9838135.5754 * parameters.cpu_usage 
	+ 0.0523 * parameters.avg_latency_of_same_past_second 
	- 10421590.1657;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM94(work_wait &parameters) {
  double actual_remaining = 
	0.7201 * parameters.work_so_far 
	+ 0.0193 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 340045.8532 * parameters.num_of_wait_locks 
	- 12963.3174 * parameters.total_wait_locks 
	+ 0.0604 * parameters.mean_wait_of_all 
	+ 9838135.5754 * parameters.cpu_usage 
	+ 0.0523 * parameters.avg_latency_of_same_past_second 
	+ 979393.8982;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM95(work_wait &parameters) {
  double actual_remaining = 
	1.1499 * parameters.work_so_far 
	+ 0.0179 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 969599.8022 * parameters.num_of_wait_locks 
	+ 519332.2675 * parameters.total_wait_locks 
	- 2.0912 * parameters.mean_wait_of_all 
	+ 35566110.4373 * parameters.cpu_usage 
	+ 1.9352 * parameters.avg_latency_of_same_past_second 
	- 1089738364.7139;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM96(work_wait &parameters) {
  double actual_remaining = 
	0.0034 * parameters.work_so_far 
	+ 0.5581 * parameters.wait_so_far 
	+ 5788.5443 * parameters.num_locks_so_far 
	- 187563.3192 * parameters.num_of_wait_locks 
	+ 122844.6487 * parameters.total_wait_locks 
	- 0.0008 * parameters.mean_wait_of_all 
	- 392279.6255 * parameters.cpu_usage 
	+ 0.0037 * parameters.avg_latency_of_same_past_second 
	- 198214127.5992;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM97(work_wait &parameters) {
  double actual_remaining = 
	2.1541 * parameters.work_so_far 
	+ 0.0024 * parameters.wait_so_far 
	- 2446247.6152 * parameters.num_locks_so_far 
	- 16039202.4789 * parameters.num_of_wait_locks 
	+ 35304.0385 * parameters.total_wait_locks 
	- 0.3113 * parameters.mean_wait_of_all 
	- 390047735.1983 * parameters.cpu_usage 
	+ 0.1698 * parameters.avg_latency_of_same_past_second 
	+ 472941346.0189;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM98(work_wait &parameters) {
  double actual_remaining = 
	0.8845 * parameters.work_so_far 
	+ 0.0024 * parameters.wait_so_far 
	- 2591884.3595 * parameters.num_locks_so_far 
	- 2232310.3167 * parameters.num_of_wait_locks 
	+ 3982246.2019 * parameters.total_wait_locks 
	+ 0.919 * parameters.mean_wait_of_all 
	- 23929810.8262 * parameters.cpu_usage 
	+ 0.0083 * parameters.avg_latency_of_same_past_second 
	+ 65000403.8889;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM99(work_wait &parameters) {
  double actual_remaining = 
	0.8845 * parameters.work_so_far 
	+ 0.0024 * parameters.wait_so_far 
	- 3320053.675 * parameters.num_locks_so_far 
	- 2232310.3167 * parameters.num_of_wait_locks 
	+ 1254325.3282 * parameters.total_wait_locks 
	+ 5.129 * parameters.mean_wait_of_all 
	- 23929810.8262 * parameters.cpu_usage 
	+ 0.0083 * parameters.avg_latency_of_same_past_second 
	- 12595768.4246;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM100(work_wait &parameters) {
  double actual_remaining = 
	3.3025 * parameters.work_so_far 
	+ 0.0024 * parameters.wait_so_far 
	- 2983198.0884 * parameters.num_locks_so_far 
	- 2232310.3167 * parameters.num_of_wait_locks 
	+ 92000.8503 * parameters.total_wait_locks 
	- 0.0068 * parameters.mean_wait_of_all 
	- 23929810.8262 * parameters.cpu_usage 
	+ 0.0083 * parameters.avg_latency_of_same_past_second 
	+ 115257212.4112;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM101(work_wait &parameters) {
  double actual_remaining = 
	2660.5401 * parameters.work_so_far 
	- 0.0194 * parameters.wait_so_far 
	- 201098.789 * parameters.num_locks_so_far 
	- 2676229.0669 * parameters.num_of_wait_locks 
	+ 153452.2754 * parameters.total_wait_locks 
	- 0.0068 * parameters.mean_wait_of_all 
	- 21633504.5153 * parameters.cpu_usage 
	+ 0.0069 * parameters.avg_latency_of_same_past_second 
	+ 93193303.1416;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM102(work_wait &parameters) {
  double actual_remaining = 
	1284.8413 * parameters.work_so_far 
	- 0.1323 * parameters.wait_so_far 
	- 201098.789 * parameters.num_locks_so_far 
	- 2676229.0669 * parameters.num_of_wait_locks 
	+ 819605.4545 * parameters.total_wait_locks 
	- 0.0068 * parameters.mean_wait_of_all 
	- 15955875.3209 * parameters.cpu_usage 
	+ 0.0069 * parameters.avg_latency_of_same_past_second 
	+ 16118219.8518;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM103(work_wait &parameters) {
  double actual_remaining = 
	4.0481 * parameters.work_so_far 
	+ 0.5599 * parameters.wait_so_far 
	- 366128.113 * parameters.num_locks_so_far 
	- 9913771.4397 * parameters.num_of_wait_locks 
	+ 365217.9498 * parameters.total_wait_locks 
	+ 0.0549 * parameters.mean_wait_of_all 
	- 393507050.7797 * parameters.cpu_usage 
	+ 0.197 * parameters.avg_latency_of_same_past_second 
	+ 457655234.0103;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM104(work_wait &parameters) {
  double actual_remaining = 
	3.2538 * parameters.work_so_far 
	- 0.0497 * parameters.wait_so_far 
	- 366128.113 * parameters.num_locks_so_far 
	- 9913771.4397 * parameters.num_of_wait_locks 
	+ 1150167.45 * parameters.total_wait_locks 
	+ 0.1067 * parameters.mean_wait_of_all 
	- 66765248.1251 * parameters.cpu_usage 
	+ 0.0495 * parameters.avg_latency_of_same_past_second 
	+ 200068161.4724;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM105(work_wait &parameters) {
  double actual_remaining = 
	2.4248 * parameters.work_so_far 
	+ 0.2633 * parameters.wait_so_far 
	- 366128.113 * parameters.num_locks_so_far 
	- 9913771.4397 * parameters.num_of_wait_locks 
	+ 872762.3379 * parameters.total_wait_locks 
	+ 0.1067 * parameters.mean_wait_of_all 
	- 66765248.1251 * parameters.cpu_usage 
	+ 0.0495 * parameters.avg_latency_of_same_past_second 
	+ 339880383.9372;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM106(work_wait &parameters) {
  double actual_remaining = 
	0.7698 * parameters.work_so_far 
	+ 0.0274 * parameters.wait_so_far 
	- 366128.113 * parameters.num_locks_so_far 
	- 13671541.0195 * parameters.num_of_wait_locks 
	+ 306848.15 * parameters.total_wait_locks 
	- 0.0068 * parameters.mean_wait_of_all 
	- 283269402.9168 * parameters.cpu_usage 
	+ 0.0361 * parameters.avg_latency_of_same_past_second 
	+ 408692590.283;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM107(work_wait &parameters) {
  double actual_remaining = 
	4.0492 * parameters.work_so_far 
	+ 0.8154 * parameters.wait_so_far 
	- 4069464.7774 * parameters.num_locks_so_far 
	- 5341602.4677 * parameters.num_of_wait_locks 
	+ 821366.3604 * parameters.total_wait_locks 
	- 0.0068 * parameters.mean_wait_of_all 
	- 19562742.221 * parameters.cpu_usage 
	+ 0.0137 * parameters.avg_latency_of_same_past_second 
	+ 103210840.0338;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM108(work_wait &parameters) {
  double actual_remaining = 
	0.9059 * parameters.work_so_far 
	+ 0.9158 * parameters.wait_so_far 
	- 2839548.2193 * parameters.num_locks_so_far 
	- 1342810.6107 * parameters.num_of_wait_locks 
	+ 736037.9494 * parameters.total_wait_locks 
	- 0.0041 * parameters.mean_wait_of_all 
	- 5002390.2804 * parameters.cpu_usage 
	+ 0.0024 * parameters.avg_latency_of_same_past_second 
	+ 230867300.6734;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM109(work_wait &parameters) {
  double actual_remaining = 
	5.0409 * parameters.work_so_far 
	+ 0.4057 * parameters.wait_so_far 
	- 8509342.3233 * parameters.num_locks_so_far 
	- 280972.6597 * parameters.num_of_wait_locks 
	+ 555941.6964 * parameters.total_wait_locks 
	- 3.1623 * parameters.mean_wait_of_all 
	- 342644294.34 * parameters.cpu_usage 
	+ 0.3017 * parameters.avg_latency_of_same_past_second 
	+ 603838994.4626;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM110(work_wait &parameters) {
  double actual_remaining = 
	3.7422 * parameters.work_so_far 
	+ 1.0051 * parameters.wait_so_far 
	- 4035896.9766 * parameters.num_locks_so_far 
	- 280972.6597 * parameters.num_of_wait_locks 
	+ 195271.2718 * parameters.total_wait_locks 
	- 0.7916 * parameters.mean_wait_of_all 
	- 348541942.1511 * parameters.cpu_usage 
	- 0.1963 * parameters.avg_latency_of_same_past_second 
	+ 582299281.572;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM111(work_wait &parameters) {
  double actual_remaining = 
	0.7518 * parameters.work_so_far 
	+ 0.6213 * parameters.wait_so_far 
	- 6183494.366 * parameters.num_locks_so_far 
	- 280972.6597 * parameters.num_of_wait_locks 
	+ 788492.0102 * parameters.total_wait_locks 
	- 4.7826 * parameters.mean_wait_of_all 
	- 406265229.3532 * parameters.cpu_usage 
	+ 0.0033 * parameters.avg_latency_of_same_past_second 
	+ 898507551.9899;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM112(work_wait &parameters) {
  double actual_remaining = 
	3.5541 * parameters.work_so_far 
	+ 0.0308 * parameters.wait_so_far 
	- 45368.1125 * parameters.num_locks_so_far 
	- 280972.6597 * parameters.num_of_wait_locks 
	+ 1569305.8765 * parameters.total_wait_locks 
	- 6.1205 * parameters.mean_wait_of_all 
	- 54063719.1043 * parameters.cpu_usage 
	+ 0.0033 * parameters.avg_latency_of_same_past_second 
	+ 220548512.2095;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM113(work_wait &parameters) {
  double actual_remaining = 
	3.9133 * parameters.work_so_far 
	+ 0.0477 * parameters.wait_so_far 
	+ 36862640.7017 * parameters.num_locks_so_far 
	- 280972.6597 * parameters.num_of_wait_locks 
	+ 27064.8305 * parameters.total_wait_locks 
	- 0.2456 * parameters.mean_wait_of_all 
	- 820102508.9209 * parameters.cpu_usage 
	- 0.0258 * parameters.avg_latency_of_same_past_second 
	+ 1033931213.1865;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM114(work_wait &parameters) {
  double actual_remaining = 
	0.9228 * parameters.work_so_far 
	+ 0.5078 * parameters.wait_so_far 
	- 187261.8017 * parameters.num_locks_so_far 
	- 280972.6597 * parameters.num_of_wait_locks 
	+ 557663.68 * parameters.total_wait_locks 
	- 3.9321 * parameters.mean_wait_of_all 
	- 390961392.1835 * parameters.cpu_usage 
	- 0.2673 * parameters.avg_latency_of_same_past_second 
	+ 815399860.6163;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM115(work_wait &parameters) {
  double actual_remaining = 
	0.0751 * parameters.work_so_far 
	+ 0.7959 * parameters.wait_so_far 
	+ 4551673.1715 * parameters.num_locks_so_far 
	- 280972.6597 * parameters.num_of_wait_locks 
	+ 352970.6085 * parameters.total_wait_locks 
	- 0.1661 * parameters.mean_wait_of_all 
	- 32599132.3844 * parameters.cpu_usage 
	+ 0.0033 * parameters.avg_latency_of_same_past_second 
	- 100105226.9202;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM116(work_wait &parameters) {
  double actual_remaining = 
	0.7396 * parameters.work_so_far 
	+ 0.4469 * parameters.wait_so_far 
	- 3752146.9563 * parameters.num_locks_so_far 
	- 280972.6597 * parameters.num_of_wait_locks 
	+ 8127.1235 * parameters.total_wait_locks 
	+ 0.9218 * parameters.mean_wait_of_all 
	- 458356467.7573 * parameters.cpu_usage 
	- 0.4021 * parameters.avg_latency_of_same_past_second 
	+ 948798498.3526;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM117(work_wait &parameters) {
  double actual_remaining = 
	0.1393 * parameters.work_so_far 
	+ 0.2831 * parameters.wait_so_far 
	- 751967.5069 * parameters.num_locks_so_far 
	- 280972.6597 * parameters.num_of_wait_locks 
	- 263467.1459 * parameters.total_wait_locks 
	+ 1.0861 * parameters.mean_wait_of_all 
	- 144920646.6215 * parameters.cpu_usage 
	+ 0.0361 * parameters.avg_latency_of_same_past_second 
	+ 704724199.6962;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM118(work_wait &parameters) {
  double actual_remaining = 
	0.6247 * parameters.work_so_far 
	+ 0.3877 * parameters.wait_so_far 
	- 6460190.4222 * parameters.num_locks_so_far 
	- 280972.6597 * parameters.num_of_wait_locks 
	- 416221.3339 * parameters.total_wait_locks 
	+ 0.3964 * parameters.mean_wait_of_all 
	- 640509613.6853 * parameters.cpu_usage 
	+ 0.0361 * parameters.avg_latency_of_same_past_second 
	+ 1573053641.8476;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM119(work_wait &parameters) {
  double actual_remaining = 
	-11.3837 * parameters.work_so_far 
	- 0.0008 * parameters.wait_so_far 
	- 10337547.3946 * parameters.num_locks_so_far 
	- 39650255.4033 * parameters.num_of_wait_locks 
	- 176927.6336 * parameters.total_wait_locks 
	+ 1.0868 * parameters.mean_wait_of_all 
	- 175590121.7255 * parameters.cpu_usage 
	+ 0.0016 * parameters.avg_latency_of_same_past_second 
	+ 671416788.0288;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM120(work_wait &parameters) {
  double actual_remaining = 
	1194.741 * parameters.work_so_far 
	- 0.3127 * parameters.wait_so_far 
	+ 237650.231 * parameters.num_locks_so_far 
	- 887103.9161 * parameters.num_of_wait_locks 
	- 504685.1461 * parameters.total_wait_locks 
	+ 2.7026 * parameters.mean_wait_of_all 
	- 14510998.2579 * parameters.cpu_usage 
	+ 0.0035 * parameters.avg_latency_of_same_past_second 
	+ 240152204.1145;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM121(work_wait &parameters) {
  double actual_remaining = 
	-672.6001 * parameters.work_so_far 
	- 0.0515 * parameters.wait_so_far 
	+ 237650.231 * parameters.num_locks_so_far 
	- 2192507.409 * parameters.num_of_wait_locks 
	- 796891.414 * parameters.total_wait_locks 
	+ 1.2534 * parameters.mean_wait_of_all 
	- 190129318.1434 * parameters.cpu_usage 
	+ 0.5286 * parameters.avg_latency_of_same_past_second 
	+ 492805300.0072;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM122(work_wait &parameters) {
  double actual_remaining = 
	-213.9496 * parameters.work_so_far 
	- 0.0235 * parameters.wait_so_far 
	+ 237650.231 * parameters.num_locks_so_far 
	- 2192507.409 * parameters.num_of_wait_locks 
	- 102078.7772 * parameters.total_wait_locks 
	+ 0.4529 * parameters.mean_wait_of_all 
	- 87744413.7929 * parameters.cpu_usage 
	+ 0.0029 * parameters.avg_latency_of_same_past_second 
	+ 285637527.5502;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM123(work_wait &parameters) {
  double actual_remaining = 
	0.3379 * parameters.work_so_far 
	- 0.0938 * parameters.wait_so_far 
	+ 237650.231 * parameters.num_locks_so_far 
	- 24363234.0075 * parameters.num_of_wait_locks 
	- 9722.7101 * parameters.total_wait_locks 
	+ 0.046 * parameters.mean_wait_of_all 
	- 19571001.3665 * parameters.cpu_usage 
	+ 0.0029 * parameters.avg_latency_of_same_past_second 
	+ 290687281.2902;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM124(work_wait &parameters) {
  double actual_remaining = 
	0.803 * parameters.work_so_far 
	- 0.2512 * parameters.wait_so_far 
	+ 13701619.9896 * parameters.num_locks_so_far 
	- 22349877.893 * parameters.num_of_wait_locks 
	- 717248.7175 * parameters.total_wait_locks 
	+ 3.705 * parameters.mean_wait_of_all 
	- 413392427.7268 * parameters.cpu_usage 
	+ 0.0016 * parameters.avg_latency_of_same_past_second 
	+ 719872824.443;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM125(work_wait &parameters) {
  double actual_remaining = 
	7.9292 * parameters.work_so_far 
	+ 0.0058 * parameters.wait_so_far 
	+ 3012085.5417 * parameters.num_locks_so_far 
	- 604726.6912 * parameters.num_of_wait_locks 
	- 99904.3928 * parameters.total_wait_locks 
	+ 0.4229 * parameters.mean_wait_of_all 
	- 102866640.5834 * parameters.cpu_usage 
	- 0.042 * parameters.avg_latency_of_same_past_second 
	+ 296496033.4367;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM126(work_wait &parameters) {
  double actual_remaining = 
	7.9292 * parameters.work_so_far 
	- 0.0159 * parameters.wait_so_far 
	+ 3012085.5417 * parameters.num_locks_so_far 
	- 604726.6912 * parameters.num_of_wait_locks 
	- 191385.9157 * parameters.total_wait_locks 
	+ 1.2438 * parameters.mean_wait_of_all 
	- 102866640.5834 * parameters.cpu_usage 
	- 0.042 * parameters.avg_latency_of_same_past_second 
	+ 207653666.3229;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM127(work_wait &parameters) {
  double actual_remaining = 
	-33.3876 * parameters.work_so_far 
	+ 0.0724 * parameters.wait_so_far 
	+ 4673844.4087 * parameters.num_locks_so_far 
	- 4098115.7133 * parameters.num_of_wait_locks 
	+ 1809889.3362 * parameters.total_wait_locks 
	- 8.9078 * parameters.mean_wait_of_all 
	- 114984218.1128 * parameters.cpu_usage 
	- 0.0248 * parameters.avg_latency_of_same_past_second 
	+ 471295572.0751;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM128(work_wait &parameters) {
  double actual_remaining = 
	-3.9398 * parameters.work_so_far 
	+ 0.848 * parameters.wait_so_far 
	+ 6092848.6771 * parameters.num_locks_so_far 
	- 4098115.7133 * parameters.num_of_wait_locks 
	+ 526403.8193 * parameters.total_wait_locks 
	- 2.5983 * parameters.mean_wait_of_all 
	- 114984218.1128 * parameters.cpu_usage 
	- 0.0248 * parameters.avg_latency_of_same_past_second 
	+ 10718789.5493;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM129(work_wait &parameters) {
  double actual_remaining = 
	5.2992 * parameters.work_so_far 
	+ 0.1313 * parameters.wait_so_far 
	+ 44631576.5968 * parameters.num_locks_so_far 
	- 8654710.0898 * parameters.num_of_wait_locks 
	+ 2671682.0611 * parameters.total_wait_locks 
	- 13.6286 * parameters.mean_wait_of_all 
	- 1200836257.4092 * parameters.cpu_usage 
	- 0.0248 * parameters.avg_latency_of_same_past_second 
	+ 1367243179.8924;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM130(work_wait &parameters) {
  double actual_remaining = 
	3.4994 * parameters.work_so_far 
	- 0.5092 * parameters.wait_so_far 
	+ 15096430.594 * parameters.num_locks_so_far 
	- 29210878.6182 * parameters.num_of_wait_locks 
	+ 583189.4753 * parameters.total_wait_locks 
	- 2.5978 * parameters.mean_wait_of_all 
	- 11413944.6423 * parameters.cpu_usage 
	+ 0.0016 * parameters.avg_latency_of_same_past_second 
	+ 408699273.0093;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM131(work_wait &parameters) {
  double actual_remaining = 
	4.8452 * parameters.work_so_far 
	+ 0.564 * parameters.wait_so_far 
	- 5655161.2635 * parameters.num_locks_so_far 
	- 3822722.9922 * parameters.num_of_wait_locks 
	+ 384798.0009 * parameters.total_wait_locks 
	- 2.3629 * parameters.mean_wait_of_all 
	- 11413944.6423 * parameters.cpu_usage 
	+ 0.0016 * parameters.avg_latency_of_same_past_second 
	+ 301598190.9751;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM132(work_wait &parameters) {
  double actual_remaining = 
	0.0681 * parameters.work_so_far 
	- 0.4704 * parameters.wait_so_far 
	+ 35446970.8633 * parameters.num_locks_so_far 
	- 66052339.2729 * parameters.num_of_wait_locks 
	- 822861.4985 * parameters.total_wait_locks 
	+ 3.7962 * parameters.mean_wait_of_all 
	- 35295144.3952 * parameters.cpu_usage 
	+ 0.0016 * parameters.avg_latency_of_same_past_second 
	+ 633380460.6586;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM133(work_wait &parameters) {
  double actual_remaining = 
	0.5649 * parameters.work_so_far 
	+ 0.5196 * parameters.wait_so_far 
	- 228989.5139 * parameters.num_locks_so_far 
	- 3876666.2451 * parameters.num_of_wait_locks 
	+ 926366.0869 * parameters.total_wait_locks 
	- 4.7549 * parameters.mean_wait_of_all 
	- 434723051.5262 * parameters.cpu_usage 
	+ 0.0016 * parameters.avg_latency_of_same_past_second 
	+ 709795078.4879;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM134(work_wait &parameters) {
  double actual_remaining = 
	-0.3198 * parameters.work_so_far 
	+ 0.2318 * parameters.wait_so_far 
	+ 1064976.2088 * parameters.num_locks_so_far 
	- 6947887.1618 * parameters.num_of_wait_locks 
	+ 422336.465 * parameters.total_wait_locks 
	- 0.8656 * parameters.mean_wait_of_all 
	- 180824044.8332 * parameters.cpu_usage 
	- 0.136 * parameters.avg_latency_of_same_past_second 
	+ 262490462.5246;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM135(work_wait &parameters) {
  double actual_remaining = 
	-1.0495 * parameters.work_so_far 
	+ 0.5584 * parameters.wait_so_far 
	+ 1064976.2088 * parameters.num_locks_so_far 
	- 6947887.1618 * parameters.num_of_wait_locks 
	+ 333470.4986 * parameters.total_wait_locks 
	- 1.4393 * parameters.mean_wait_of_all 
	- 297315585.6373 * parameters.cpu_usage 
	- 0.136 * parameters.avg_latency_of_same_past_second 
	+ 302781658.5108;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM136(work_wait &parameters) {
  double actual_remaining = 
	-1.3479 * parameters.work_so_far 
	+ 0.6854 * parameters.wait_so_far 
	+ 1064976.2088 * parameters.num_locks_so_far 
	- 6947887.1618 * parameters.num_of_wait_locks 
	+ 333470.4986 * parameters.total_wait_locks 
	- 1.4393 * parameters.mean_wait_of_all 
	- 297315585.6373 * parameters.cpu_usage 
	- 2.1837 * parameters.avg_latency_of_same_past_second 
	+ 1159425366.2022;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM137(work_wait &parameters) {
  double actual_remaining = 
	-0.219 * parameters.work_so_far 
	+ 0.1918 * parameters.wait_so_far 
	+ 1064976.2088 * parameters.num_locks_so_far 
	- 6947887.1618 * parameters.num_of_wait_locks 
	+ 149050.0135 * parameters.total_wait_locks 
	- 0.4774 * parameters.mean_wait_of_all 
	- 64332504.029 * parameters.cpu_usage 
	- 0.2051 * parameters.avg_latency_of_same_past_second 
	+ 217784581.3497;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM138(work_wait &parameters) {
  double actual_remaining = 
	5.4122 * parameters.work_so_far 
	+ 0.8542 * parameters.wait_so_far 
	+ 1058313.3542 * parameters.num_locks_so_far 
	- 56952098.0918 * parameters.num_of_wait_locks 
	- 215077.3378 * parameters.total_wait_locks 
	+ 0.9689 * parameters.mean_wait_of_all 
	- 64033233.2581 * parameters.cpu_usage 
	- 0.0494 * parameters.avg_latency_of_same_past_second 
	+ 223980252.9101;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM139(work_wait &parameters) {
  double actual_remaining = 
	0.8186 * parameters.work_so_far 
	+ 0.5075 * parameters.wait_so_far 
	- 2818196.7509 * parameters.num_locks_so_far 
	- 33480104.3108 * parameters.num_of_wait_locks 
	- 404092.1829 * parameters.total_wait_locks 
	+ 1.864 * parameters.mean_wait_of_all 
	- 64033233.2581 * parameters.cpu_usage 
	- 0.0494 * parameters.avg_latency_of_same_past_second 
	+ 575094274.164;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM140(work_wait &parameters) {
  double actual_remaining = 
	0.278 * parameters.work_so_far 
	+ 0.3841 * parameters.wait_so_far 
	+ 1058313.3542 * parameters.num_locks_so_far 
	- 23783344.0862 * parameters.num_of_wait_locks 
	- 135539.1023 * parameters.total_wait_locks 
	+ 0.5633 * parameters.mean_wait_of_all 
	- 732018241.2355 * parameters.cpu_usage 
	- 0.0494 * parameters.avg_latency_of_same_past_second 
	+ 1128321606.6709;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM141(work_wait &parameters) {
  double actual_remaining = 
	0.278 * parameters.work_so_far 
	+ 0.5054 * parameters.wait_so_far 
	+ 1058313.3542 * parameters.num_locks_so_far 
	- 23783344.0862 * parameters.num_of_wait_locks 
	- 135539.1023 * parameters.total_wait_locks 
	+ 0.5633 * parameters.mean_wait_of_all 
	- 64033233.2581 * parameters.cpu_usage 
	- 0.0494 * parameters.avg_latency_of_same_past_second 
	+ 571414563.5388;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM142(work_wait &parameters) {
  double actual_remaining = 
	0.278 * parameters.work_so_far 
	+ 0.5054 * parameters.wait_so_far 
	+ 1058313.3542 * parameters.num_locks_so_far 
	- 23783344.0862 * parameters.num_of_wait_locks 
	- 135539.1023 * parameters.total_wait_locks 
	+ 0.5633 * parameters.mean_wait_of_all 
	- 2579247440.3579 * parameters.cpu_usage 
	- 0.0494 * parameters.avg_latency_of_same_past_second 
	+ 3127456559.7909;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
tpcc_estimate(work_wait &parameters){

  if (parameters.num_locks_so_far <= 2.5) {

    if (parameters.work_so_far <= 159389.5) {

      if (parameters.avg_latency_of_same_past_second <= 426809500) {

        if (parameters.wait_so_far <= 21897.5) {

          if (parameters.avg_latency_of_same_past_second <= 104556000) {

            if (parameters.work_so_far <= 8607) {
              return tpcc_LM1(parameters);
            } else {
              return tpcc_LM2(parameters);
            }
          } else {

            if (parameters.wait_so_far <= 10041.5) {

              if (parameters.cpu_usage <= 0.962) {

                if (parameters.wait_so_far <= 3737) {
                  return tpcc_LM3(parameters);
                } else {

                  if (parameters.total_wait_locks <= 383) {
                    return tpcc_LM4(parameters);
                  } else {
                    return tpcc_LM5(parameters);
                  }
                }
              } else {
                return tpcc_LM6(parameters);
              }
            } else {

              if (parameters.mean_wait_of_all <= 88872250) {
                return tpcc_LM7(parameters);
              } else {
                return tpcc_LM8(parameters);
              }
            }
          }
        } else {

          if (parameters.total_wait_locks <= 265.5) {

            if (parameters.work_so_far <= 9352) {

              if (parameters.total_wait_locks <= 18.5) {
                return tpcc_LM9(parameters);
              } else {

                if (parameters.mean_wait_of_all <= 31184000) {
                  return tpcc_LM10(parameters);
                } else {

                  if (parameters.wait_so_far <= 4289488.5) {
                    return tpcc_LM11(parameters);
                  } else {

                    if (parameters.mean_wait_of_all <= 31466350) {

                      if (parameters.work_so_far <= 7365) {
                        return tpcc_LM12(parameters);
                      } else {

                        if (parameters.total_wait_locks <= 48) {

                          if (parameters.mean_wait_of_all <= 31322500) {
                            return tpcc_LM13(parameters);
                          } else {
                            return tpcc_LM14(parameters);
                          }
                        } else {

                          if (parameters.mean_wait_of_all <= 31229300) {
                            return tpcc_LM15(parameters);
                          } else {
                            return tpcc_LM16(parameters);
                          }
                        }
                      }
                    } else {

                      if (parameters.mean_wait_of_all <= 34524250) {
                        return tpcc_LM17(parameters);
                      } else {

                        if (parameters.work_so_far <= 7690) {
                          return tpcc_LM18(parameters);
                        } else {
                          return tpcc_LM19(parameters);
                        }
                      }
                    }
                  }
                }
              }
            } else {

              if (parameters.cpu_usage <= 0.918) {
                return tpcc_LM20(parameters);
              } else {

                if (parameters.total_wait_locks <= 171.5) {
                  return tpcc_LM21(parameters);
                } else {

                  if (parameters.avg_latency_of_same_past_second <= 363853000) {

                    if (parameters.mean_wait_of_all <= 48498150) {
                      return tpcc_LM22(parameters);
                    } else {
                      return tpcc_LM23(parameters);
                    }
                  } else {

                    if (parameters.total_wait_locks <= 242.5) {

                      if (parameters.wait_so_far <= 230117532.5) {

                        if (parameters.avg_latency_of_same_past_second <= 372487500) {
                          return tpcc_LM24(parameters);
                        } else {
                          return tpcc_LM25(parameters);
                        }
                      } else {
                        return tpcc_LM26(parameters);
                      }
                    } else {
                      return tpcc_LM27(parameters);
                    }
                  }
                }
              }
            }
          } else {

            if (parameters.wait_so_far <= 203606183.5) {

              if (parameters.cpu_usage <= 0.974) {

                if (parameters.mean_wait_of_all <= 99122900) {

                  if (parameters.cpu_usage <= 0.839) {
                    return tpcc_LM28(parameters);
                  } else {

                    if (parameters.wait_so_far <= 6079240) {

                      if (parameters.work_so_far <= 42778.5) {
                        return tpcc_LM29(parameters);
                      } else {
                        return tpcc_LM30(parameters);
                      }
                    } else {

                      if (parameters.cpu_usage <= 0.923) {
                        return tpcc_LM31(parameters);
                      } else {

                        if (parameters.cpu_usage <= 0.954) {

                          if (parameters.wait_so_far <= 42275454) {
                            return tpcc_LM32(parameters);
                          } else {
                            return tpcc_LM33(parameters);
                          }
                        } else {

                          if (parameters.total_wait_locks <= 384.5) {
                            return tpcc_LM34(parameters);
                          } else {

                            if (parameters.mean_wait_of_all <= 98991950) {
                              return tpcc_LM35(parameters);
                            } else {
                              return tpcc_LM36(parameters);
                            }
                          }
                        }
                      }
                    }
                  }
                } else {
                  return tpcc_LM37(parameters);
                }
              } else {

                if (parameters.mean_wait_of_all <= 107951000) {
                  return tpcc_LM38(parameters);
                } else {

                  if (parameters.mean_wait_of_all <= 113924500) {

                    if (parameters.work_so_far <= 33732) {

                      if (parameters.total_wait_locks <= 568.5) {
                        return tpcc_LM39(parameters);
                      } else {

                        if (parameters.cpu_usage <= 0.995) {
                          return tpcc_LM40(parameters);
                        } else {

                          if (parameters.avg_latency_of_same_past_second <= 417101000) {

                            if (parameters.total_wait_locks <= 584.5) {
                              return tpcc_LM41(parameters);
                            } else {
                              return tpcc_LM42(parameters);
                            }
                          } else {
                            return tpcc_LM43(parameters);
                          }
                        }
                      }
                    } else {
                      return tpcc_LM44(parameters);
                    }
                  } else {
                    return tpcc_LM45(parameters);
                  }
                }
              }
            } else {

              if (parameters.avg_latency_of_same_past_second <= 401929500) {

                if (parameters.avg_latency_of_same_past_second <= 353542500) {

                  if (parameters.avg_latency_of_same_past_second <= 347754000) {
                    return tpcc_LM46(parameters);
                  } else {
                    return tpcc_LM47(parameters);
                  }
                } else {
                  return tpcc_LM48(parameters);
                }
              } else {

                if (parameters.mean_wait_of_all <= 96115200) {

                  if (parameters.cpu_usage <= 0.868) {

                    if (parameters.mean_wait_of_all <= 86587700) {

                      if (parameters.avg_latency_of_same_past_second <= 419485000) {

                        if (parameters.wait_so_far <= 855204632.5) {

                          if (parameters.avg_latency_of_same_past_second <= 416353000) {

                            if (parameters.work_so_far <= 72569.5) {
                              return tpcc_LM49(parameters);
                            } else {
                              return tpcc_LM50(parameters);
                            }
                          } else {

                            if (parameters.work_so_far <= 33992) {
                              return tpcc_LM51(parameters);
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
                      return tpcc_LM55(parameters);
                    }
                  } else {

                    if (parameters.total_wait_locks <= 342.5) {

                      if (parameters.mean_wait_of_all <= 56968450) {
                        return tpcc_LM56(parameters);
                      } else {

                        if (parameters.avg_latency_of_same_past_second <= 414736500) {

                          if (parameters.avg_latency_of_same_past_second <= 406763000) {
                            return tpcc_LM57(parameters);
                          } else {
                            return tpcc_LM58(parameters);
                          }
                        } else {

                          if (parameters.total_wait_locks <= 314) {
                            return tpcc_LM59(parameters);
                          } else {
                            return tpcc_LM60(parameters);
                          }
                        }
                      }
                    } else {
                      return tpcc_LM61(parameters);
                    }
                  }
                } else {

                  if (parameters.total_wait_locks <= 518) {

                    if (parameters.cpu_usage <= 0.954) {
                      return tpcc_LM62(parameters);
                    } else {

                      if (parameters.mean_wait_of_all <= 99028200) {
                        return tpcc_LM63(parameters);
                      } else {

                        if (parameters.mean_wait_of_all <= 99105550) {
                          return tpcc_LM64(parameters);
                        } else {
                          return tpcc_LM65(parameters);
                        }
                      }
                    }
                  } else {

                    if (parameters.num_of_wait_locks <= 3.5) {

                      if (parameters.cpu_usage <= 0.982) {

                        if (parameters.wait_so_far <= 358038033.5) {

                          if (parameters.cpu_usage <= 0.905) {
                            return tpcc_LM66(parameters);
                          } else {
                            return tpcc_LM67(parameters);
                          }
                        } else {
                          return tpcc_LM68(parameters);
                        }
                      } else {
                        return tpcc_LM69(parameters);
                      }
                    } else {
                      return tpcc_LM70(parameters);
                    }
                  }
                }
              }
            }
          }
        }
      } else {

        if (parameters.avg_latency_of_same_past_second <= 502170500) {

          if (parameters.mean_wait_of_all <= 101938500) {

            if (parameters.mean_wait_of_all <= 68121300) {
              return tpcc_LM71(parameters);
            } else {

              if (parameters.mean_wait_of_all <= 93003100) {

                if (parameters.wait_so_far <= 161157144.5) {

                  if (parameters.mean_wait_of_all <= 78681750) {
                    return tpcc_LM72(parameters);
                  } else {
                    return tpcc_LM73(parameters);
                  }
                } else {
                  return tpcc_LM74(parameters);
                }
              } else {
                return tpcc_LM75(parameters);
              }
            }
          } else {

            if (parameters.cpu_usage <= 0.918) {
              return tpcc_LM76(parameters);
            } else {

              if (parameters.avg_latency_of_same_past_second <= 443598000) {

                if (parameters.avg_latency_of_same_past_second <= 434265000) {
                  return tpcc_LM77(parameters);
                } else {

                  if (parameters.cpu_usage <= 0.945) {

                    if (parameters.avg_latency_of_same_past_second <= 436185000) {
                      return tpcc_LM78(parameters);
                    } else {
                      return tpcc_LM79(parameters);
                    }
                  } else {

                    if (parameters.cpu_usage <= 0.997) {
                      return tpcc_LM80(parameters);
                    } else {
                      return tpcc_LM81(parameters);
                    }
                  }
                }
              } else {

                if (parameters.work_so_far <= 30688) {

                  if (parameters.work_so_far <= 27603.5) {
                    return tpcc_LM82(parameters);
                  } else {
                    return tpcc_LM83(parameters);
                  }
                } else {

                  if (parameters.work_so_far <= 49490.5) {

                    if (parameters.total_wait_locks <= 587.5) {

                      if (parameters.work_so_far <= 31857.5) {
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
                }
              }
            }
          }
        } else {

          if (parameters.avg_latency_of_same_past_second <= 601294000) {
            return tpcc_LM88(parameters);
          } else {

            if (parameters.avg_latency_of_same_past_second <= 721140000) {
              return tpcc_LM89(parameters);
            } else {

              if (parameters.wait_so_far <= 5748.5) {
                return tpcc_LM90(parameters);
              } else {
                return tpcc_LM91(parameters);
              }
            }
          }
        }
      }
    } else {

      if (parameters.wait_so_far <= 355805595) {

        if (parameters.avg_latency_of_same_past_second <= 438222500) {
          return tpcc_LM92(parameters);
        } else {

          if (parameters.avg_latency_of_same_past_second <= 512295000) {

            if (parameters.wait_so_far <= 134901472.5) {
              return tpcc_LM93(parameters);
            } else {
              return tpcc_LM94(parameters);
            }
          } else {
            return tpcc_LM95(parameters);
          }
        }
      } else {
        return tpcc_LM96(parameters);
      }
    }
  } else {

    if (parameters.total_wait_locks <= 146.5) {

      if (parameters.work_so_far <= 59501621) {

        if (parameters.total_wait_locks <= 65.5) {

          if (parameters.work_so_far <= 26222476.5) {
            return tpcc_LM97(parameters);
          } else {

            if (parameters.num_locks_so_far <= 28.5) {

              if (parameters.num_locks_so_far <= 25.5) {
                return tpcc_LM98(parameters);
              } else {
                return tpcc_LM99(parameters);
              }
            } else {
              return tpcc_LM100(parameters);
            }
          }
        } else {

          if (parameters.work_so_far <= 67583) {

            if (parameters.wait_so_far <= 15939873) {
              return tpcc_LM101(parameters);
            } else {
              return tpcc_LM102(parameters);
            }
          } else {

            if (parameters.num_locks_so_far <= 17.5) {

              if (parameters.num_of_wait_locks <= 2.5) {

                if (parameters.mean_wait_of_all <= 40587950) {
                  return tpcc_LM103(parameters);
                } else {

                  if (parameters.work_so_far <= 1081920) {
                    return tpcc_LM104(parameters);
                  } else {
                    return tpcc_LM105(parameters);
                  }
                }
              } else {
                return tpcc_LM106(parameters);
              }
            } else {
              return tpcc_LM107(parameters);
            }
          }
        }
      } else {
        return tpcc_LM108(parameters);
      }
    } else {

      if (parameters.num_of_wait_locks <= 2.5) {

        if (parameters.avg_latency_of_same_past_second <= 510532500) {

          if (parameters.wait_so_far <= 222507242.5) {

            if (parameters.work_so_far <= 53030785) {

              if (parameters.num_locks_so_far <= 13.5) {
                return tpcc_LM109(parameters);
              } else {
                return tpcc_LM110(parameters);
              }
            } else {
              return tpcc_LM111(parameters);
            }
          } else {

            if (parameters.wait_so_far <= 606240261.5) {

              if (parameters.num_locks_so_far <= 5.5) {
                return tpcc_LM112(parameters);
              } else {

                if (parameters.num_locks_so_far <= 10.5) {
                  return tpcc_LM113(parameters);
                } else {
                  return tpcc_LM114(parameters);
                }
              }
            } else {
              return tpcc_LM115(parameters);
            }
          }
        } else {

          if (parameters.avg_latency_of_same_past_second <= 710657000) {
            return tpcc_LM116(parameters);
          } else {

            if (parameters.work_so_far <= 4612773.5) {
              return tpcc_LM117(parameters);
            } else {
              return tpcc_LM118(parameters);
            }
          }
        }
      } else {

        if (parameters.work_so_far <= 5097657.5) {

          if (parameters.wait_so_far <= 158446295) {
            return tpcc_LM119(parameters);
          } else {

            if (parameters.work_so_far <= 94612) {

              if (parameters.wait_so_far <= 325983834.5) {
                return tpcc_LM120(parameters);
              } else {

                if (parameters.cpu_usage <= 0.869) {

                  if (parameters.wait_so_far <= 461989825) {
                    return tpcc_LM121(parameters);
                  } else {
                    return tpcc_LM122(parameters);
                  }
                } else {
                  return tpcc_LM123(parameters);
                }
              }
            } else {

              if (parameters.wait_so_far <= 554937241) {
                return tpcc_LM124(parameters);
              } else {

                if (parameters.work_so_far <= 711648.5) {

                  if (parameters.wait_so_far <= 774513698) {
                    return tpcc_LM125(parameters);
                  } else {
                    return tpcc_LM126(parameters);
                  }
                } else {

                  if (parameters.wait_so_far <= 868879923) {

                    if (parameters.num_locks_so_far <= 5.5) {
                      return tpcc_LM127(parameters);
                    } else {
                      return tpcc_LM128(parameters);
                    }
                  } else {
                    return tpcc_LM129(parameters);
                  }
                }
              }
            }
          }
        } else {

          if (parameters.wait_so_far <= 408896258.5) {

            if (parameters.work_so_far <= 25968634) {

              if (parameters.num_locks_so_far <= 10.5) {
                return tpcc_LM130(parameters);
              } else {
                return tpcc_LM131(parameters);
              }
            } else {

              if (parameters.num_locks_so_far <= 12.5) {
                return tpcc_LM132(parameters);
              } else {
                return tpcc_LM133(parameters);
              }
            }
          } else {

            if (parameters.num_locks_so_far <= 5.5) {

              if (parameters.avg_latency_of_same_past_second <= 480601000) {

                if (parameters.wait_so_far <= 685338819.5) {
                  return tpcc_LM134(parameters);
                } else {

                  if (parameters.wait_so_far <= 930707651.5) {
                    return tpcc_LM135(parameters);
                  } else {
                    return tpcc_LM136(parameters);
                  }
                }
              } else {
                return tpcc_LM137(parameters);
              }
            } else {

              if (parameters.wait_so_far <= 639033558.5) {

                if (parameters.work_so_far <= 22988540) {
                  return tpcc_LM138(parameters);
                } else {
                  return tpcc_LM139(parameters);
                }
              } else {

                if (parameters.wait_so_far <= 931652916.5) {
                  return tpcc_LM140(parameters);
                } else {

                  if (parameters.cpu_usage <= 0.954) {
                    return tpcc_LM141(parameters);
                  } else {
                    return tpcc_LM142(parameters);
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