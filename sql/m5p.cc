#include "my_global.h"
#include "m5p.h"
#include "trace_tool.h"

static
double
new_order_LM1(work_wait &parameters) {
  double actual_remaining = 
	3.2773 * parameters.work_so_far 
	+ 0.0007 * parameters.wait_so_far 
	- 3750711.9273 * parameters.num_locks_so_far 
	- 37881321.9144 * parameters.num_of_wait_locks 
	+ 1342888.0406 * parameters.total_wait_locks 
	+ 0.3396 * parameters.mean_wait_of_all 
	- 138430907.1384 * parameters.cpu_usage 
	- 0.1422 * parameters.avg_latency_of_same_past_second 
	+ 247108193.7456;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM2(work_wait &parameters) {
  double actual_remaining = 
	0.9792 * parameters.work_so_far 
	+ 0.7918 * parameters.wait_so_far 
	- 6104800.3746 * parameters.num_locks_so_far 
	- 1337864.2135 * parameters.num_of_wait_locks 
	+ 1287705.1702 * parameters.total_wait_locks 
	+ 0.6117 * parameters.mean_wait_of_all 
	+ 171862284.9398 * parameters.cpu_usage 
	- 0.4869 * parameters.avg_latency_of_same_past_second 
	+ 135535094.9907;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM3(work_wait &parameters) {
  double actual_remaining = 
	0.0032 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	- 16475219.2955 * parameters.num_locks_so_far 
	- 28343463.5697 * parameters.num_of_wait_locks 
	+ 242846.9078 * parameters.total_wait_locks 
	- 0.001 * parameters.mean_wait_of_all 
	- 109923295.008 * parameters.cpu_usage 
	+ 0.0005 * parameters.avg_latency_of_same_past_second 
	+ 499684462.427;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM4(work_wait &parameters) {
  double actual_remaining = 
	0.164 * parameters.work_so_far 
	- 0.111 * parameters.wait_so_far 
	+ 382708.8984 * parameters.num_locks_so_far 
	- 43919882.8635 * parameters.num_of_wait_locks 
	+ 3604.4988 * parameters.total_wait_locks 
	+ 0.4775 * parameters.mean_wait_of_all 
	- 227799008.873 * parameters.cpu_usage 
	+ 0.0008 * parameters.avg_latency_of_same_past_second 
	+ 569444066.4151;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM5(work_wait &parameters) {
  double actual_remaining = 
	-1.1143 * parameters.work_so_far 
	+ 0.3989 * parameters.wait_so_far 
	+ 3558514.7944 * parameters.num_locks_so_far 
	- 199095040.9283 * parameters.num_of_wait_locks 
	+ 585520.3243 * parameters.total_wait_locks 
	+ 0.1804 * parameters.mean_wait_of_all 
	- 36533244.6177 * parameters.cpu_usage 
	+ 0.0333 * parameters.avg_latency_of_same_past_second 
	+ 431693789.2101;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM6(work_wait &parameters) {
  double actual_remaining = 
	-1.1143 * parameters.work_so_far 
	- 0.0796 * parameters.wait_so_far 
	+ 3558514.7944 * parameters.num_locks_so_far 
	- 70614476.0505 * parameters.num_of_wait_locks 
	+ 6793.4636 * parameters.total_wait_locks 
	+ 0.1406 * parameters.mean_wait_of_all 
	- 36533244.6177 * parameters.cpu_usage 
	+ 0.2236 * parameters.avg_latency_of_same_past_second 
	+ 393353299.7694;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM7(work_wait &parameters) {
  double actual_remaining = 
	39.8232 * parameters.work_so_far 
	+ 0.6183 * parameters.wait_so_far 
	- 9246521.6677 * parameters.num_locks_so_far 
	- 8165606.3728 * parameters.num_of_wait_locks 
	+ 6793.4636 * parameters.total_wait_locks 
	- 0.001 * parameters.mean_wait_of_all 
	- 541683628.0756 * parameters.cpu_usage 
	+ 0.0008 * parameters.avg_latency_of_same_past_second 
	+ 687445531.7744;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM8(work_wait &parameters) {
  double actual_remaining = 
	0.8389 * parameters.work_so_far 
	+ 0.3743 * parameters.wait_so_far 
	- 126360.0902 * parameters.num_locks_so_far 
	- 39512656.5986 * parameters.num_of_wait_locks 
	+ 1294.0138 * parameters.total_wait_locks 
	- 0.001 * parameters.mean_wait_of_all 
	- 154498965.7106 * parameters.cpu_usage 
	- 0.1153 * parameters.avg_latency_of_same_past_second 
	+ 697691683.2924;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM9(work_wait &parameters) {
  double actual_remaining = 
	2.3751 * parameters.work_so_far 
	+ 0.8856 * parameters.wait_so_far 
	- 5014555.4573 * parameters.num_locks_so_far 
	- 15231622.6449 * parameters.num_of_wait_locks 
	+ 1294.0138 * parameters.total_wait_locks 
	- 0.001 * parameters.mean_wait_of_all 
	- 120715175.4908 * parameters.cpu_usage 
	- 0.1255 * parameters.avg_latency_of_same_past_second 
	+ 450844287.817;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM10(work_wait &parameters) {
  double actual_remaining = 
	0.6127 * parameters.work_so_far 
	+ 0.4506 * parameters.wait_so_far 
	- 3344417.8057 * parameters.num_locks_so_far 
	- 784375.6948 * parameters.num_of_wait_locks 
	+ 917834.1009 * parameters.total_wait_locks 
	- 3.6321 * parameters.mean_wait_of_all 
	- 297006564.7485 * parameters.cpu_usage 
	- 0.288 * parameters.avg_latency_of_same_past_second 
	+ 710112108.3664;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM11(work_wait &parameters) {
  double actual_remaining = 
	0.0871 * parameters.work_so_far 
	+ 0.0463 * parameters.wait_so_far 
	+ 67789.2848 * parameters.num_locks_so_far 
	- 38091538.6578 * parameters.num_of_wait_locks 
	- 1867283.2553 * parameters.total_wait_locks 
	+ 8.9824 * parameters.mean_wait_of_all 
	- 3712406.8885 * parameters.cpu_usage 
	- 0.0018 * parameters.avg_latency_of_same_past_second 
	+ 341484719.4625;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM12(work_wait &parameters) {
  double actual_remaining = 
	0.3945 * parameters.work_so_far 
	+ 0.3864 * parameters.wait_so_far 
	+ 2188627.6427 * parameters.num_locks_so_far 
	- 7629423.4973 * parameters.num_of_wait_locks 
	+ 159581.9086 * parameters.total_wait_locks 
	- 0.6099 * parameters.mean_wait_of_all 
	- 38533705.1071 * parameters.cpu_usage 
	- 0.1316 * parameters.avg_latency_of_same_past_second 
	+ 441337888.2594;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM13(work_wait &parameters) {
  double actual_remaining = 
	0.3945 * parameters.work_so_far 
	+ 0.5117 * parameters.wait_so_far 
	+ 41613204.1422 * parameters.num_locks_so_far 
	- 7629423.4973 * parameters.num_of_wait_locks 
	+ 789349.6391 * parameters.total_wait_locks 
	- 0.9159 * parameters.mean_wait_of_all 
	- 38533705.1071 * parameters.cpu_usage 
	- 0.6271 * parameters.avg_latency_of_same_past_second 
	+ 183888057.4;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM14(work_wait &parameters) {
  double actual_remaining = 
	0.6415 * parameters.work_so_far 
	+ 0.3132 * parameters.wait_so_far 
	+ 62130950.0647 * parameters.num_locks_so_far 
	- 7629423.4973 * parameters.num_of_wait_locks 
	+ 167389.6994 * parameters.total_wait_locks 
	- 0.582 * parameters.mean_wait_of_all 
	- 38533705.1071 * parameters.cpu_usage 
	- 0.1458 * parameters.avg_latency_of_same_past_second 
	+ 147124468.5314;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM15(work_wait &parameters) {
  double actual_remaining = 
	1.001 * parameters.work_so_far 
	+ 0.0572 * parameters.wait_so_far 
	- 527827.0802 * parameters.num_locks_so_far 
	- 5919715.1425 * parameters.num_of_wait_locks 
	- 1127912.4292 * parameters.total_wait_locks 
	+ 3.5377 * parameters.mean_wait_of_all 
	- 486108207.6716 * parameters.cpu_usage 
	- 0.0018 * parameters.avg_latency_of_same_past_second 
	+ 1039277514.9315;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM16(work_wait &parameters) {
  double actual_remaining = 
	0.3987 * parameters.work_so_far 
	+ 0.2929 * parameters.wait_so_far 
	+ 61028878.6469 * parameters.num_locks_so_far 
	- 155812411.3124 * parameters.num_of_wait_locks 
	- 653204.8134 * parameters.total_wait_locks 
	+ 2.5128 * parameters.mean_wait_of_all 
	- 20785385.2528 * parameters.cpu_usage 
	- 0.0018 * parameters.avg_latency_of_same_past_second 
	+ 718078802.4429;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM17(work_wait &parameters) {
  double actual_remaining = 
	0.9765 * parameters.work_so_far 
	+ 0.7408 * parameters.wait_so_far 
	- 5181657.1384 * parameters.num_locks_so_far 
	- 5931894.5201 * parameters.num_of_wait_locks 
	- 276450.2566 * parameters.total_wait_locks 
	+ 1.0109 * parameters.mean_wait_of_all 
	- 20785385.2528 * parameters.cpu_usage 
	- 0.3011 * parameters.avg_latency_of_same_past_second 
	+ 496331562.9941;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
new_order_estimate(work_wait &parameters){

  if (parameters.total_wait_locks <= 152.5) {

    if (parameters.work_so_far <= 59816216.5) {
      return new_order_LM1(parameters);
    } else {
      return new_order_LM2(parameters);
    }
  } else {

    if (parameters.work_so_far <= 4647810) {

      if (parameters.wait_so_far <= 223295359.5) {
        return new_order_LM3(parameters);
      } else {

        if (parameters.work_so_far <= 783477.5) {
          return new_order_LM4(parameters);
        } else {

          if (parameters.num_locks_so_far <= 4.5) {

            if (parameters.num_of_wait_locks <= 3.5) {
              return new_order_LM5(parameters);
            } else {
              return new_order_LM6(parameters);
            }
          } else {
            return new_order_LM7(parameters);
          }
        }
      }
    } else {

      if (parameters.wait_so_far <= 306151158.5) {

        if (parameters.num_locks_so_far <= 14.5) {
          return new_order_LM8(parameters);
        } else {

          if (parameters.work_so_far <= 105710990.5) {
            return new_order_LM9(parameters);
          } else {
            return new_order_LM10(parameters);
          }
        }
      } else {

        if (parameters.num_locks_so_far <= 4.5) {
          return new_order_LM11(parameters);
        } else {

          if (parameters.wait_so_far <= 589870921) {

            if (parameters.num_locks_so_far <= 13.5) {

              if (parameters.work_so_far <= 33158195.5) {

                if (parameters.wait_so_far <= 461079382.5) {
                  return new_order_LM12(parameters);
                } else {
                  return new_order_LM13(parameters);
                }
              } else {
                return new_order_LM14(parameters);
              }
            } else {
              return new_order_LM15(parameters);
            }
          } else {

            if (parameters.num_locks_so_far <= 10.5) {
              return new_order_LM16(parameters);
            } else {
              return new_order_LM17(parameters);
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
	0.4729 * parameters.work_so_far 
	+ 0.0006 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 34630.0321 * parameters.num_of_wait_locks 
	+ 1715.126 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 13466652.3449 * parameters.cpu_usage 
	+ 0.0088 * parameters.avg_latency_of_same_past_second 
	+ 17693573.6952;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM2(work_wait &parameters) {
  double actual_remaining = 
	0.4729 * parameters.work_so_far 
	+ 0.0087 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 34630.0321 * parameters.num_of_wait_locks 
	+ 5929.6875 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 0.0029 * parameters.avg_latency_of_same_past_second 
	+ 5448153.6384;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM3(work_wait &parameters) {
  double actual_remaining = 
	0.4729 * parameters.work_so_far 
	+ 0.0206 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 34630.0321 * parameters.num_of_wait_locks 
	+ 6253.8846 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	+ 10644969.1567 * parameters.cpu_usage 
	- 0.015 * parameters.avg_latency_of_same_past_second 
	+ 5507977.371;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM4(work_wait &parameters) {
  double actual_remaining = 
	0.4729 * parameters.work_so_far 
	+ 0.0239 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 34630.0321 * parameters.num_of_wait_locks 
	+ 6253.8846 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	+ 13730467.4631 * parameters.cpu_usage 
	- 0.0184 * parameters.avg_latency_of_same_past_second 
	- 4312679.0933;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM5(work_wait &parameters) {
  double actual_remaining = 
	345.4636 * parameters.work_so_far 
	- 0.002 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 376892.0316 * parameters.num_of_wait_locks 
	- 220298.8595 * parameters.total_wait_locks 
	- 0.6661 * parameters.mean_wait_of_all 
	+ 18282305.7106 * parameters.cpu_usage 
	+ 0.8951 * parameters.avg_latency_of_same_past_second 
	+ 21737963.8073;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM6(work_wait &parameters) {
  double actual_remaining = 
	618.6172 * parameters.work_so_far 
	- 0.002 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 376892.0316 * parameters.num_of_wait_locks 
	- 3092793.7679 * parameters.total_wait_locks 
	+ 0.2489 * parameters.mean_wait_of_all 
	+ 18282305.7106 * parameters.cpu_usage 
	+ 1.7939 * parameters.avg_latency_of_same_past_second 
	+ 182386044.6447;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM7(work_wait &parameters) {
  double actual_remaining = 
	248.9384 * parameters.work_so_far 
	- 0.002 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 376892.0316 * parameters.num_of_wait_locks 
	+ 93873.3694 * parameters.total_wait_locks 
	- 0.4318 * parameters.mean_wait_of_all 
	+ 9332308.5473 * parameters.cpu_usage 
	- 0.0037 * parameters.avg_latency_of_same_past_second 
	+ 9003032.5732;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM8(work_wait &parameters) {
  double actual_remaining = 
	0.2017 * parameters.work_so_far 
	- 0.0206 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 299514.2687 * parameters.num_of_wait_locks 
	+ 223995.1585 * parameters.total_wait_locks 
	- 0.0621 * parameters.mean_wait_of_all 
	+ 2123809.253 * parameters.cpu_usage 
	- 0.0844 * parameters.avg_latency_of_same_past_second 
	+ 2408622.9499;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM9(work_wait &parameters) {
  double actual_remaining = 
	0.2017 * parameters.work_so_far 
	- 0.0362 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 7610982.9227 * parameters.num_of_wait_locks 
	+ 18283.6729 * parameters.total_wait_locks 
	- 0.0621 * parameters.mean_wait_of_all 
	+ 4854486.1949 * parameters.cpu_usage 
	- 0.0064 * parameters.avg_latency_of_same_past_second 
	+ 692127.3377;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM10(work_wait &parameters) {
  double actual_remaining = 
	12.7944 * parameters.work_so_far 
	+ 0.0007 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	- 78054.509 * parameters.num_of_wait_locks 
	+ 206699.547 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 0.0367 * parameters.avg_latency_of_same_past_second 
	+ 6509305.1364;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM11(work_wait &parameters) {
  double actual_remaining = 
	401.6934 * parameters.work_so_far 
	- 0.0075 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	- 14028.1273 * parameters.num_of_wait_locks 
	+ 2574.8774 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	+ 11539079.3792 * parameters.cpu_usage 
	- 0.0003 * parameters.avg_latency_of_same_past_second 
	- 5676127.9957;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM12(work_wait &parameters) {
  double actual_remaining = 
	3931.8708 * parameters.work_so_far 
	- 0.0037 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	- 14028.1273 * parameters.num_of_wait_locks 
	+ 2574.8774 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	+ 5922713.3097 * parameters.cpu_usage 
	- 0.0003 * parameters.avg_latency_of_same_past_second 
	- 36118989.6843;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM13(work_wait &parameters) {
  double actual_remaining = 
	440.9934 * parameters.work_so_far 
	- 0.0037 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	- 14028.1273 * parameters.num_of_wait_locks 
	+ 2574.8774 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	+ 5922713.3097 * parameters.cpu_usage 
	+ 0.0121 * parameters.avg_latency_of_same_past_second 
	- 874711.7512;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM14(work_wait &parameters) {
  double actual_remaining = 
	440.9934 * parameters.work_so_far 
	+ 0.0808 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	- 14028.1273 * parameters.num_of_wait_locks 
	+ 2574.8774 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	+ 18016649.4192 * parameters.cpu_usage 
	+ 0.0062 * parameters.avg_latency_of_same_past_second 
	- 8751283.0234;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM15(work_wait &parameters) {
  double actual_remaining = 
	440.9934 * parameters.work_so_far 
	+ 0.1418 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	- 14028.1273 * parameters.num_of_wait_locks 
	+ 2574.8774 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	+ 67841022.5227 * parameters.cpu_usage 
	+ 0.0062 * parameters.avg_latency_of_same_past_second 
	- 53090158.9501;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM16(work_wait &parameters) {
  double actual_remaining = 
	440.9934 * parameters.work_so_far 
	- 0.0118 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	- 14028.1273 * parameters.num_of_wait_locks 
	+ 2574.8774 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	+ 5922713.3097 * parameters.cpu_usage 
	+ 0.0062 * parameters.avg_latency_of_same_past_second 
	+ 2222628.03;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM17(work_wait &parameters) {
  double actual_remaining = 
	-3452.052 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	- 14028.1273 * parameters.num_of_wait_locks 
	+ 2574.8774 * parameters.total_wait_locks 
	+ 0.0523 * parameters.mean_wait_of_all 
	+ 0.0158 * parameters.avg_latency_of_same_past_second 
	+ 47962416.608;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM18(work_wait &parameters) {
  double actual_remaining = 
	55.0342 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	- 14028.1273 * parameters.num_of_wait_locks 
	+ 2574.8774 * parameters.total_wait_locks 
	+ 0.7587 * parameters.mean_wait_of_all 
	+ 0.2346 * parameters.avg_latency_of_same_past_second 
	- 16145863.3825;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM19(work_wait &parameters) {
  double actual_remaining = 
	-17539.8426 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	- 14028.1273 * parameters.num_of_wait_locks 
	+ 2574.8774 * parameters.total_wait_locks 
	+ 1.2748 * parameters.mean_wait_of_all 
	+ 0.1918 * parameters.avg_latency_of_same_past_second 
	+ 193000910.66;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM20(work_wait &parameters) {
  double actual_remaining = 
	-9128.8322 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	- 14028.1273 * parameters.num_of_wait_locks 
	+ 2574.8774 * parameters.total_wait_locks 
	+ 1.5947 * parameters.mean_wait_of_all 
	+ 0.1918 * parameters.avg_latency_of_same_past_second 
	+ 71979803.0579;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM21(work_wait &parameters) {
  double actual_remaining = 
	55.0342 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	- 14028.1273 * parameters.num_of_wait_locks 
	+ 2574.8774 * parameters.total_wait_locks 
	+ 0.0756 * parameters.mean_wait_of_all 
	+ 134327349.6153 * parameters.cpu_usage 
	+ 0.0324 * parameters.avg_latency_of_same_past_second 
	- 102272222.6702;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM22(work_wait &parameters) {
  double actual_remaining = 
	224.9559 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	- 14028.1273 * parameters.num_of_wait_locks 
	+ 52210.5487 * parameters.total_wait_locks 
	+ 0.0157 * parameters.mean_wait_of_all 
	+ 26828706.4176 * parameters.cpu_usage 
	- 0.0088 * parameters.avg_latency_of_same_past_second 
	- 21716428.8545;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM23(work_wait &parameters) {
  double actual_remaining = 
	1318.6603 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	- 14028.1273 * parameters.num_of_wait_locks 
	+ 52210.5487 * parameters.total_wait_locks 
	+ 0.0229 * parameters.mean_wait_of_all 
	+ 26828706.4176 * parameters.cpu_usage 
	- 0.0088 * parameters.avg_latency_of_same_past_second 
	- 38963405.4769;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM24(work_wait &parameters) {
  double actual_remaining = 
	1561.7058 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	- 14028.1273 * parameters.num_of_wait_locks 
	+ 52210.5487 * parameters.total_wait_locks 
	+ 0.0229 * parameters.mean_wait_of_all 
	+ 26828706.4176 * parameters.cpu_usage 
	- 0.0088 * parameters.avg_latency_of_same_past_second 
	- 41659747.5262;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM25(work_wait &parameters) {
  double actual_remaining = 
	176.1278 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	- 14028.1273 * parameters.num_of_wait_locks 
	+ 37947.4247 * parameters.total_wait_locks 
	+ 0.0065 * parameters.mean_wait_of_all 
	- 914440368.615 * parameters.cpu_usage 
	- 0.0064 * parameters.avg_latency_of_same_past_second 
	+ 922529124.5418;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM26(work_wait &parameters) {
  double actual_remaining = 
	19.9954 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	- 14028.1273 * parameters.num_of_wait_locks 
	+ 6501.0297 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 0.0003 * parameters.avg_latency_of_same_past_second 
	+ 13205786.2445;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM27(work_wait &parameters) {
  double actual_remaining = 
	19.9954 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	- 14028.1273 * parameters.num_of_wait_locks 
	+ 16098.2908 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	+ 0.0467 * parameters.avg_latency_of_same_past_second 
	+ 7547149.7262;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM28(work_wait &parameters) {
  double actual_remaining = 
	0.2017 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 28292.3409 * parameters.num_of_wait_locks 
	+ 8189.983 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 0.1435 * parameters.avg_latency_of_same_past_second 
	+ 26205922.4392;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM29(work_wait &parameters) {
  double actual_remaining = 
	0.2017 * parameters.work_so_far 
	+ 0.3918 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 28292.3409 * parameters.num_of_wait_locks 
	- 98909.0885 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	+ 1.1518 * parameters.avg_latency_of_same_past_second 
	+ 10586059.0141;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM30(work_wait &parameters) {
  double actual_remaining = 
	0.2017 * parameters.work_so_far 
	- 0.0231 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 28292.3409 * parameters.num_of_wait_locks 
	- 314340.208 * parameters.total_wait_locks 
	- 0.4325 * parameters.mean_wait_of_all 
	+ 0.9744 * parameters.avg_latency_of_same_past_second 
	+ 70876653.488;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM31(work_wait &parameters) {
  double actual_remaining = 
	0.2017 * parameters.work_so_far 
	- 0.0398 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 28292.3409 * parameters.num_of_wait_locks 
	- 98909.0885 * parameters.total_wait_locks 
	+ 0.2029 * parameters.mean_wait_of_all 
	+ 0.918 * parameters.avg_latency_of_same_past_second 
	+ 7701376.9936;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM32(work_wait &parameters) {
  double actual_remaining = 
	0.2017 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 28292.3409 * parameters.num_of_wait_locks 
	- 63306.968 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	+ 0.171 * parameters.avg_latency_of_same_past_second 
	+ 31408540.367;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM33(work_wait &parameters) {
  double actual_remaining = 
	0.2017 * parameters.work_so_far 
	- 0.0073 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 28292.3409 * parameters.num_of_wait_locks 
	+ 37221.3413 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 0.0007 * parameters.avg_latency_of_same_past_second 
	+ 15681159.7007;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM34(work_wait &parameters) {
  double actual_remaining = 
	0.0548 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 164026.5793 * parameters.num_of_wait_locks 
	+ 17.6146 * parameters.total_wait_locks 
	+ 0.0042 * parameters.mean_wait_of_all 
	+ 0 * parameters.avg_latency_of_same_past_second 
	+ 23521486.2518;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM35(work_wait &parameters) {
  double actual_remaining = 
	0.0548 * parameters.work_so_far 
	- 56.2248 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 164026.5793 * parameters.num_of_wait_locks 
	+ 969.1237 * parameters.total_wait_locks 
	- 14.4653 * parameters.mean_wait_of_all 
	+ 10957936.1065 * parameters.cpu_usage 
	- 0.0406 * parameters.avg_latency_of_same_past_second 
	+ 1490055482.9927;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM36(work_wait &parameters) {
  double actual_remaining = 
	0.0548 * parameters.work_so_far 
	- 25.0268 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 164026.5793 * parameters.num_of_wait_locks 
	+ 351442.415 * parameters.total_wait_locks 
	- 3.5527 * parameters.mean_wait_of_all 
	+ 4877617.9011 * parameters.cpu_usage 
	- 0.0181 * parameters.avg_latency_of_same_past_second 
	+ 209864059.5016;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM37(work_wait &parameters) {
  double actual_remaining = 
	0.0548 * parameters.work_so_far 
	+ 385.2638 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 26997650.7618 * parameters.num_of_wait_locks 
	+ 145037.8413 * parameters.total_wait_locks 
	- 0.4706 * parameters.mean_wait_of_all 
	+ 0 * parameters.avg_latency_of_same_past_second 
	- 99005417.7161;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM38(work_wait &parameters) {
  double actual_remaining = 
	0.1329 * parameters.work_so_far 
	- 0.018 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 22158.1323 * parameters.num_of_wait_locks 
	- 2059.996 * parameters.total_wait_locks 
	- 0.4177 * parameters.mean_wait_of_all 
	+ 17564546.9368 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_latency_of_same_past_second 
	+ 27810466.5363;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM39(work_wait &parameters) {
  double actual_remaining = 
	0.1329 * parameters.work_so_far 
	- 0.0049 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 22158.1323 * parameters.num_of_wait_locks 
	- 57749.5464 * parameters.total_wait_locks 
	- 10.8239 * parameters.mean_wait_of_all 
	- 15767663.6631 * parameters.cpu_usage 
	- 0.0095 * parameters.avg_latency_of_same_past_second 
	+ 689648550.7017;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM40(work_wait &parameters) {
  double actual_remaining = 
	0.1329 * parameters.work_so_far 
	- 0.0056 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 22158.1323 * parameters.num_of_wait_locks 
	- 57749.5464 * parameters.total_wait_locks 
	- 1.4358 * parameters.mean_wait_of_all 
	- 15767663.6631 * parameters.cpu_usage 
	- 0.0095 * parameters.avg_latency_of_same_past_second 
	+ 148749973.7205;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM41(work_wait &parameters) {
  double actual_remaining = 
	0.1329 * parameters.work_so_far 
	+ 0.0605 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 22158.1323 * parameters.num_of_wait_locks 
	- 86025.735 * parameters.total_wait_locks 
	- 6.0109 * parameters.mean_wait_of_all 
	- 15767663.6631 * parameters.cpu_usage 
	- 0.2559 * parameters.avg_latency_of_same_past_second 
	+ 580579365.9521;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM42(work_wait &parameters) {
  double actual_remaining = 
	-3119.6729 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 22158.1323 * parameters.num_of_wait_locks 
	- 86025.735 * parameters.total_wait_locks 
	+ 6.8503 * parameters.mean_wait_of_all 
	- 15767663.6631 * parameters.cpu_usage 
	- 0.4308 * parameters.avg_latency_of_same_past_second 
	- 74015705.3064;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM43(work_wait &parameters) {
  double actual_remaining = 
	0.1329 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	- 809361.3463 * parameters.num_of_wait_locks 
	+ 50821.6075 * parameters.total_wait_locks 
	- 0.5227 * parameters.mean_wait_of_all 
	- 26820760.7305 * parameters.cpu_usage 
	- 0.0095 * parameters.avg_latency_of_same_past_second 
	+ 69037306.2611;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM44(work_wait &parameters) {
  double actual_remaining = 
	0.1329 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	- 6767271.2776 * parameters.num_of_wait_locks 
	+ 88359.8794 * parameters.total_wait_locks 
	- 0.5227 * parameters.mean_wait_of_all 
	- 26820760.7305 * parameters.cpu_usage 
	- 0.0095 * parameters.avg_latency_of_same_past_second 
	+ 85769755.0548;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM45(work_wait &parameters) {
  double actual_remaining = 
	0.1329 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	- 3263443.1973 * parameters.num_of_wait_locks 
	- 17429.7959 * parameters.total_wait_locks 
	- 0.2818 * parameters.mean_wait_of_all 
	- 46318086.9843 * parameters.cpu_usage 
	- 0.0196 * parameters.avg_latency_of_same_past_second 
	+ 104422489.9041;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM46(work_wait &parameters) {
  double actual_remaining = 
	-607.0806 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 22158.1323 * parameters.num_of_wait_locks 
	- 334725.9699 * parameters.total_wait_locks 
	+ 1.1368 * parameters.mean_wait_of_all 
	- 3411601.672 * parameters.cpu_usage 
	+ 0.0598 * parameters.avg_latency_of_same_past_second 
	+ 52228649.7548;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM47(work_wait &parameters) {
  double actual_remaining = 
	0.1329 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 2605642.261 * parameters.num_of_wait_locks 
	- 21177.0741 * parameters.total_wait_locks 
	+ 0.0656 * parameters.mean_wait_of_all 
	- 2952908.3131 * parameters.cpu_usage 
	- 0.0021 * parameters.avg_latency_of_same_past_second 
	+ 23861992.284;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM48(work_wait &parameters) {
  double actual_remaining = 
	0.1329 * parameters.work_so_far 
	- 0.0021 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 105926.3358 * parameters.num_of_wait_locks 
	- 80879.3819 * parameters.total_wait_locks 
	+ 2.0618 * parameters.mean_wait_of_all 
	- 1511112.7048 * parameters.cpu_usage 
	+ 0.0417 * parameters.avg_latency_of_same_past_second 
	- 91108729.6157;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM49(work_wait &parameters) {
  double actual_remaining = 
	0.1329 * parameters.work_so_far 
	- 0.0119 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 105926.3358 * parameters.num_of_wait_locks 
	- 50153.1552 * parameters.total_wait_locks 
	+ 0.0474 * parameters.mean_wait_of_all 
	- 1511112.7048 * parameters.cpu_usage 
	+ 0.016 * parameters.avg_latency_of_same_past_second 
	+ 31578023.3125;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM50(work_wait &parameters) {
  double actual_remaining = 
	0.1329 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 105926.3358 * parameters.num_of_wait_locks 
	- 28135.6667 * parameters.total_wait_locks 
	+ 0.0474 * parameters.mean_wait_of_all 
	- 1511112.7048 * parameters.cpu_usage 
	- 0.0044 * parameters.avg_latency_of_same_past_second 
	+ 27046030.0661;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM51(work_wait &parameters) {
  double actual_remaining = 
	-954.5892 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 95258.8868 * parameters.num_of_wait_locks 
	- 8492.7388 * parameters.total_wait_locks 
	- 2.1331 * parameters.mean_wait_of_all 
	+ 0.0001 * parameters.avg_latency_of_same_past_second 
	+ 230859351.978;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM52(work_wait &parameters) {
  double actual_remaining = 
	0.1329 * parameters.work_so_far 
	+ 0.4105 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 249337.9531 * parameters.num_of_wait_locks 
	+ 7021.2871 * parameters.total_wait_locks 
	- 0.0603 * parameters.mean_wait_of_all 
	+ 0.0001 * parameters.avg_latency_of_same_past_second 
	+ 20603830.7571;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM53(work_wait &parameters) {
  double actual_remaining = 
	0.1329 * parameters.work_so_far 
	+ 0.0172 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 230606.1864 * parameters.num_of_wait_locks 
	+ 6164.8849 * parameters.total_wait_locks 
	- 0.0536 * parameters.mean_wait_of_all 
	+ 0.0001 * parameters.avg_latency_of_same_past_second 
	+ 30409179.8346;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM54(work_wait &parameters) {
  double actual_remaining = 
	0.1329 * parameters.work_so_far 
	+ 0.1997 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 92615.5051 * parameters.num_of_wait_locks 
	+ 60256.2496 * parameters.total_wait_locks 
	- 0.3373 * parameters.mean_wait_of_all 
	+ 0.0001 * parameters.avg_latency_of_same_past_second 
	+ 29782420.9012;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM55(work_wait &parameters) {
  double actual_remaining = 
	0.1329 * parameters.work_so_far 
	+ 0.341 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 92615.5051 * parameters.num_of_wait_locks 
	+ 106751.852 * parameters.total_wait_locks 
	- 0.584 * parameters.mean_wait_of_all 
	- 0.1764 * parameters.avg_latency_of_same_past_second 
	+ 113806847.7826;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM56(work_wait &parameters) {
  double actual_remaining = 
	0.1329 * parameters.work_so_far 
	- 0.0064 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 84598.2036 * parameters.num_of_wait_locks 
	- 11073.4044 * parameters.total_wait_locks 
	+ 0.0679 * parameters.mean_wait_of_all 
	- 0.0405 * parameters.avg_latency_of_same_past_second 
	+ 36178008.2396;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM57(work_wait &parameters) {
  double actual_remaining = 
	0.1329 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 2938033.6982 * parameters.num_of_wait_locks 
	- 872478.5948 * parameters.total_wait_locks 
	+ 6.1181 * parameters.mean_wait_of_all 
	+ 5045462.6384 * parameters.cpu_usage 
	+ 0.4233 * parameters.avg_latency_of_same_past_second 
	- 357499978.7408;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM58(work_wait &parameters) {
  double actual_remaining = 
	0.1329 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 3558209.1002 * parameters.num_of_wait_locks 
	- 574064.3891 * parameters.total_wait_locks 
	+ 3.9662 * parameters.mean_wait_of_all 
	- 733358341.9315 * parameters.cpu_usage 
	+ 1.7618 * parameters.avg_latency_of_same_past_second 
	- 148553854.5782;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM59(work_wait &parameters) {
  double actual_remaining = 
	0.1329 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 3558209.1002 * parameters.num_of_wait_locks 
	- 381384.0947 * parameters.total_wait_locks 
	+ 3.9662 * parameters.mean_wait_of_all 
	- 551261192.4445 * parameters.cpu_usage 
	+ 2.6315 * parameters.avg_latency_of_same_past_second 
	- 783086949.455;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM60(work_wait &parameters) {
  double actual_remaining = 
	0.1329 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 482501.4308 * parameters.num_of_wait_locks 
	- 125755.7782 * parameters.total_wait_locks 
	+ 1.3788 * parameters.mean_wait_of_all 
	+ 2940161.6814 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_latency_of_same_past_second 
	- 52650442.7905;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM61(work_wait &parameters) {
  double actual_remaining = 
	0.2622 * parameters.work_so_far 
	- 0.01 * parameters.wait_so_far 
	+ 26383.0739 * parameters.num_locks_so_far 
	+ 2140270.253 * parameters.num_of_wait_locks 
	- 176553.3905 * parameters.total_wait_locks 
	+ 0.8103 * parameters.mean_wait_of_all 
	+ 0 * parameters.avg_latency_of_same_past_second 
	+ 27757456.9936;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM62(work_wait &parameters) {
  double actual_remaining = 
	1.6867 * parameters.work_so_far 
	+ 0.1538 * parameters.wait_so_far 
	+ 252226.0217 * parameters.num_locks_so_far 
	+ 3016575.1289 * parameters.num_of_wait_locks 
	- 1032.3846 * parameters.total_wait_locks 
	- 0.0003 * parameters.mean_wait_of_all 
	- 0.0008 * parameters.avg_latency_of_same_past_second 
	+ 12939556.1078;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM63(work_wait &parameters) {
  double actual_remaining = 
	0.0386 * parameters.work_so_far 
	+ 0.2521 * parameters.wait_so_far 
	+ 1264395.052 * parameters.num_locks_so_far 
	+ 300006.8613 * parameters.num_of_wait_locks 
	- 5142.7162 * parameters.total_wait_locks 
	- 0.0003 * parameters.mean_wait_of_all 
	- 25062422.8043 * parameters.cpu_usage 
	- 0.0017 * parameters.avg_latency_of_same_past_second 
	+ 50997605.3247;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM64(work_wait &parameters) {
  double actual_remaining = 
	0.4936 * parameters.work_so_far 
	+ 1.1335 * parameters.wait_so_far 
	+ 2300645.7491 * parameters.num_locks_so_far 
	+ 300006.8613 * parameters.num_of_wait_locks 
	- 5142.7162 * parameters.total_wait_locks 
	- 0.0003 * parameters.mean_wait_of_all 
	- 10359317.8835 * parameters.cpu_usage 
	- 0.0747 * parameters.avg_latency_of_same_past_second 
	+ 54994680.6826;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM65(work_wait &parameters) {
  double actual_remaining = 
	0.074 * parameters.work_so_far 
	- 27001.3199 * parameters.wait_so_far 
	+ 14611108.9853 * parameters.num_locks_so_far 
	+ 300006.8613 * parameters.num_of_wait_locks 
	- 478401.604 * parameters.total_wait_locks 
	- 0.0003 * parameters.mean_wait_of_all 
	+ 170589078.9333 * parameters.cpu_usage 
	- 0.0754 * parameters.avg_latency_of_same_past_second 
	+ 35278152.8789;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM66(work_wait &parameters) {
  double actual_remaining = 
	0.074 * parameters.work_so_far 
	+ 0.0168 * parameters.wait_so_far 
	+ 7959650.8972 * parameters.num_locks_so_far 
	+ 300006.8613 * parameters.num_of_wait_locks 
	- 14375.1533 * parameters.total_wait_locks 
	- 0.0003 * parameters.mean_wait_of_all 
	+ 82135482.4494 * parameters.cpu_usage 
	- 0.0372 * parameters.avg_latency_of_same_past_second 
	- 20754208.1277;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM67(work_wait &parameters) {
  double actual_remaining = 
	0.0088 * parameters.work_so_far 
	+ 0.0191 * parameters.wait_so_far 
	+ 2419006.1866 * parameters.num_locks_so_far 
	+ 14692447.3563 * parameters.num_of_wait_locks 
	- 10448.0486 * parameters.total_wait_locks 
	- 0.0003 * parameters.mean_wait_of_all 
	- 0.0004 * parameters.avg_latency_of_same_past_second 
	- 7947350.6725;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM68(work_wait &parameters) {
  double actual_remaining = 
	0.8541 * parameters.work_so_far 
	+ 0.6107 * parameters.wait_so_far 
	+ 4096021.6715 * parameters.num_locks_so_far 
	+ 4587846.6638 * parameters.num_of_wait_locks 
	- 10448.0486 * parameters.total_wait_locks 
	- 0.0003 * parameters.mean_wait_of_all 
	- 0.0004 * parameters.avg_latency_of_same_past_second 
	- 834328.3595;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM69(work_wait &parameters) {
  double actual_remaining = 
	0.0088 * parameters.work_so_far 
	+ 0.0191 * parameters.wait_so_far 
	+ 8268553.1625 * parameters.num_locks_so_far 
	+ 1043833.4277 * parameters.num_of_wait_locks 
	- 287508.4399 * parameters.total_wait_locks 
	+ 1.5585 * parameters.mean_wait_of_all 
	- 0.0004 * parameters.avg_latency_of_same_past_second 
	+ 3625026.8803;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM70(work_wait &parameters) {
  double actual_remaining = 
	-0.3461 * parameters.work_so_far 
	+ 0.0257 * parameters.wait_so_far 
	+ 19918977.1642 * parameters.num_locks_so_far 
	+ 10307105.2981 * parameters.num_of_wait_locks 
	- 125537.3462 * parameters.total_wait_locks 
	- 0.0003 * parameters.mean_wait_of_all 
	- 0.1004 * parameters.avg_latency_of_same_past_second 
	+ 75039321.0538;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM71(work_wait &parameters) {
  double actual_remaining = 
	-0.0487 * parameters.work_so_far 
	+ 0.075 * parameters.wait_so_far 
	+ 1845408.806 * parameters.num_locks_so_far 
	+ 3441683.1093 * parameters.num_of_wait_locks 
	- 13545.2472 * parameters.total_wait_locks 
	- 0.0003 * parameters.mean_wait_of_all 
	- 0.0349 * parameters.avg_latency_of_same_past_second 
	+ 49173568.8837;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM72(work_wait &parameters) {
  double actual_remaining = 
	-0.6804 * parameters.work_so_far 
	+ 0.0789 * parameters.wait_so_far 
	+ 1845408.806 * parameters.num_locks_so_far 
	+ 41484405.7759 * parameters.num_of_wait_locks 
	- 13545.2472 * parameters.total_wait_locks 
	- 1.1468 * parameters.mean_wait_of_all 
	- 0.0677 * parameters.avg_latency_of_same_past_second 
	+ 90392678.2634;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM73(work_wait &parameters) {
  double actual_remaining = 
	-0.1826 * parameters.work_so_far 
	+ 0.0789 * parameters.wait_so_far 
	+ 1845408.806 * parameters.num_locks_so_far 
	+ 9304241.9469 * parameters.num_of_wait_locks 
	- 13545.2472 * parameters.total_wait_locks 
	- 0.1954 * parameters.mean_wait_of_all 
	- 0.0833 * parameters.avg_latency_of_same_past_second 
	+ 81864928.2008;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM74(work_wait &parameters) {
  double actual_remaining = 
	0.5023 * parameters.work_so_far 
	+ 0.4836 * parameters.wait_so_far 
	+ 2739079.8872 * parameters.num_locks_so_far 
	+ 34891462.2601 * parameters.num_of_wait_locks 
	- 361654.3254 * parameters.total_wait_locks 
	- 0.0003 * parameters.mean_wait_of_all 
	- 0.03 * parameters.avg_latency_of_same_past_second 
	+ 74086509.076;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM75(work_wait &parameters) {
  double actual_remaining = 
	0.0058 * parameters.work_so_far 
	+ 0.4594 * parameters.wait_so_far 
	+ 2785132.1046 * parameters.num_locks_so_far 
	+ 53707807.4557 * parameters.num_of_wait_locks 
	- 865759.5406 * parameters.total_wait_locks 
	+ 2.5446 * parameters.mean_wait_of_all 
	- 0.5212 * parameters.avg_latency_of_same_past_second 
	+ 33427972.6417;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM76(work_wait &parameters) {
  double actual_remaining = 
	0.7225 * parameters.work_so_far 
	+ 0.7761 * parameters.wait_so_far 
	+ 3261242.9828 * parameters.num_locks_so_far 
	+ 5199933.8567 * parameters.num_of_wait_locks 
	- 460520.5255 * parameters.total_wait_locks 
	- 0.0003 * parameters.mean_wait_of_all 
	- 0.6025 * parameters.avg_latency_of_same_past_second 
	+ 314261724.3259;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
payment_estimate(work_wait &parameters){

  if (parameters.work_so_far <= 350954.5) {

    if (parameters.total_wait_locks <= 202.5) {

      if (parameters.work_so_far <= 8344) {

        if (parameters.mean_wait_of_all <= 37035400) {
          return payment_LM1(parameters);
        } else {

          if (parameters.total_wait_locks <= 26.5) {
            return payment_LM2(parameters);
          } else {

            if (parameters.avg_latency_of_same_past_second <= 108464000) {
              return payment_LM3(parameters);
            } else {
              return payment_LM4(parameters);
            }
          }
        }
      } else {

        if (parameters.mean_wait_of_all <= 30070400) {

          if (parameters.mean_wait_of_all <= 28017000) {

            if (parameters.avg_latency_of_same_past_second <= 29186300) {

              if (parameters.cpu_usage <= 0.893) {
                return payment_LM5(parameters);
              } else {
                return payment_LM6(parameters);
              }
            } else {
              return payment_LM7(parameters);
            }
          } else {

            if (parameters.cpu_usage <= 0.957) {
              return payment_LM8(parameters);
            } else {
              return payment_LM9(parameters);
            }
          }
        } else {

          if (parameters.work_so_far <= 20067.5) {

            if (parameters.total_wait_locks <= 52.5) {
              return payment_LM10(parameters);
            } else {

              if (parameters.total_wait_locks <= 93.5) {

                if (parameters.mean_wait_of_all <= 31051900) {

                  if (parameters.cpu_usage <= 0.855) {
                    return payment_LM11(parameters);
                  } else {

                    if (parameters.avg_latency_of_same_past_second <= 22364400) {
                      return payment_LM12(parameters);
                    } else {

                      if (parameters.avg_latency_of_same_past_second <= 34945750) {
                        return payment_LM13(parameters);
                      } else {

                        if (parameters.wait_so_far <= 30476426) {

                          if (parameters.wait_so_far <= 10184469) {
                            return payment_LM14(parameters);
                          } else {
                            return payment_LM15(parameters);
                          }
                        } else {
                          return payment_LM16(parameters);
                        }
                      }
                    }
                  }
                } else {

                  if (parameters.cpu_usage <= 0.92) {

                    if (parameters.work_so_far <= 11711) {
                      return payment_LM17(parameters);
                    } else {

                      if (parameters.work_so_far <= 13065.5) {

                        if (parameters.avg_latency_of_same_past_second <= 29532500) {
                          return payment_LM18(parameters);
                        } else {

                          if (parameters.wait_so_far <= 6207715) {
                            return payment_LM19(parameters);
                          } else {
                            return payment_LM20(parameters);
                          }
                        }
                      } else {
                        return payment_LM21(parameters);
                      }
                    }
                  } else {

                    if (parameters.cpu_usage <= 0.974) {

                      if (parameters.mean_wait_of_all <= 232233500) {
                        return payment_LM22(parameters);
                      } else {

                        if (parameters.work_so_far <= 17626.5) {
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
              } else {

                if (parameters.total_wait_locks <= 156.5) {
                  return payment_LM26(parameters);
                } else {
                  return payment_LM27(parameters);
                }
              }
            }
          } else {

            if (parameters.avg_latency_of_same_past_second <= 64763250) {

              if (parameters.total_wait_locks <= 143.5) {
                return payment_LM28(parameters);
              } else {

                if (parameters.work_so_far <= 42937) {

                  if (parameters.total_wait_locks <= 197.5) {

                    if (parameters.cpu_usage <= 0.802) {
                      return payment_LM29(parameters);
                    } else {
                      return payment_LM30(parameters);
                    }
                  } else {
                    return payment_LM31(parameters);
                  }
                } else {
                  return payment_LM32(parameters);
                }
              }
            } else {
              return payment_LM33(parameters);
            }
          }
        }
      }
    } else {

      if (parameters.wait_so_far <= 137691.5) {

        if (parameters.num_of_wait_locks <= 3.5) {

          if (parameters.mean_wait_of_all <= 92123450) {
            return payment_LM34(parameters);
          } else {

            if (parameters.avg_latency_of_same_past_second <= 353447500) {
              return payment_LM35(parameters);
            } else {
              return payment_LM36(parameters);
            }
          }
        } else {
          return payment_LM37(parameters);
        }
      } else {

        if (parameters.work_so_far <= 38553.5) {

          if (parameters.mean_wait_of_all <= 52206000) {
            return payment_LM38(parameters);
          } else {

            if (parameters.mean_wait_of_all <= 64376800) {

              if (parameters.cpu_usage <= 0.997) {

                if (parameters.avg_latency_of_same_past_second <= 446978000) {

                  if (parameters.mean_wait_of_all <= 63163000) {

                    if (parameters.mean_wait_of_all <= 58257250) {

                      if (parameters.wait_so_far <= 97533801) {
                        return payment_LM39(parameters);
                      } else {
                        return payment_LM40(parameters);
                      }
                    } else {

                      if (parameters.mean_wait_of_all <= 59750950) {
                        return payment_LM41(parameters);
                      } else {
                        return payment_LM42(parameters);
                      }
                    }
                  } else {

                    if (parameters.total_wait_locks <= 305.5) {
                      return payment_LM43(parameters);
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
            } else {

              if (parameters.mean_wait_of_all <= 75438850) {

                if (parameters.cpu_usage <= 0.949) {
                  return payment_LM47(parameters);
                } else {

                  if (parameters.avg_latency_of_same_past_second <= 351002500) {

                    if (parameters.total_wait_locks <= 318.5) {
                      return payment_LM48(parameters);
                    } else {
                      return payment_LM49(parameters);
                    }
                  } else {
                    return payment_LM50(parameters);
                  }
                }
              } else {

                if (parameters.total_wait_locks <= 374.5) {
                  return payment_LM51(parameters);
                } else {

                  if (parameters.wait_so_far <= 40690696.5) {

                    if (parameters.wait_so_far <= 20047584.5) {

                      if (parameters.num_of_wait_locks <= 2.5) {
                        return payment_LM52(parameters);
                      } else {
                        return payment_LM53(parameters);
                      }
                    } else {

                      if (parameters.wait_so_far <= 33831053.5) {
                        return payment_LM54(parameters);
                      } else {
                        return payment_LM55(parameters);
                      }
                    }
                  } else {

                    if (parameters.avg_latency_of_same_past_second <= 436144000) {
                      return payment_LM56(parameters);
                    } else {

                      if (parameters.avg_latency_of_same_past_second <= 455141500) {

                        if (parameters.cpu_usage <= 0.951) {
                          return payment_LM57(parameters);
                        } else {

                          if (parameters.avg_latency_of_same_past_second <= 452440000) {
                            return payment_LM58(parameters);
                          } else {
                            return payment_LM59(parameters);
                          }
                        }
                      } else {
                        return payment_LM60(parameters);
                      }
                    }
                  }
                }
              }
            }
          }
        } else {
          return payment_LM61(parameters);
        }
      }
    }
  } else {

    if (parameters.wait_so_far <= 297260558.5) {

      if (parameters.wait_so_far <= 72450374) {

        if (parameters.work_so_far <= 14217388) {
          return payment_LM62(parameters);
        } else {

          if (parameters.work_so_far <= 99889976) {

            if (parameters.num_locks_so_far <= 3) {
              return payment_LM63(parameters);
            } else {
              return payment_LM64(parameters);
            }
          } else {

            if (parameters.wait_so_far <= 4505.5) {
              return payment_LM65(parameters);
            } else {
              return payment_LM66(parameters);
            }
          }
        }
      } else {

        if (parameters.wait_so_far <= 198621949.5) {

          if (parameters.total_wait_locks <= 290.5) {

            if (parameters.num_locks_so_far <= 2.5) {
              return payment_LM67(parameters);
            } else {
              return payment_LM68(parameters);
            }
          } else {
            return payment_LM69(parameters);
          }
        } else {
          return payment_LM70(parameters);
        }
      }
    } else {

      if (parameters.wait_so_far <= 586028246) {

        if (parameters.num_locks_so_far <= 2.5) {

          if (parameters.wait_so_far <= 435858763.5) {
            return payment_LM71(parameters);
          } else {

            if (parameters.avg_latency_of_same_past_second <= 389621500) {
              return payment_LM72(parameters);
            } else {
              return payment_LM73(parameters);
            }
          }
        } else {
          return payment_LM74(parameters);
        }
      } else {

        if (parameters.num_locks_so_far <= 2.5) {
          return payment_LM75(parameters);
        } else {
          return payment_LM76(parameters);
        }
      }
    }
  }
}
static
double
tpcc_LM1(work_wait &parameters) {
  double actual_remaining = 
	37.1268 * parameters.work_so_far 
	- 251.0848 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	+ 213422.3902 * parameters.num_of_wait_locks 
	+ 56647.4176 * parameters.total_wait_locks 
	+ 0.0201 * parameters.mean_wait_of_all 
	- 13558225.1157 * parameters.cpu_usage 
	+ 0.0238 * parameters.avg_latency_of_same_past_second 
	+ 13239575.3498;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM2(work_wait &parameters) {
  double actual_remaining = 
	37.1268 * parameters.work_so_far 
	- 251.0848 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	+ 213422.3902 * parameters.num_of_wait_locks 
	+ 56647.4176 * parameters.total_wait_locks 
	+ 0.0201 * parameters.mean_wait_of_all 
	- 13558225.1157 * parameters.cpu_usage 
	+ 0.0238 * parameters.avg_latency_of_same_past_second 
	+ 20603826.7151;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM3(work_wait &parameters) {
  double actual_remaining = 
	88.3327 * parameters.work_so_far 
	- 251.0848 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	+ 213422.3902 * parameters.num_of_wait_locks 
	+ 178404.8958 * parameters.total_wait_locks 
	+ 1.2831 * parameters.mean_wait_of_all 
	- 192594423.3896 * parameters.cpu_usage 
	+ 0.163 * parameters.avg_latency_of_same_past_second 
	+ 115545175.4388;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM4(work_wait &parameters) {
  double actual_remaining = 
	-4180.4363 * parameters.work_so_far 
	- 251.0848 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	+ 213422.3902 * parameters.num_of_wait_locks 
	+ 1281789.5686 * parameters.total_wait_locks 
	+ 3.113 * parameters.mean_wait_of_all 
	- 418949180.9071 * parameters.cpu_usage 
	+ 0.3168 * parameters.avg_latency_of_same_past_second 
	+ 286146904.7732;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM5(work_wait &parameters) {
  double actual_remaining = 
	6.3988 * parameters.work_so_far 
	- 3.5796 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	+ 455408.3296 * parameters.num_of_wait_locks 
	- 1431.9394 * parameters.total_wait_locks 
	- 0.002 * parameters.mean_wait_of_all 
	+ 127455.1352 * parameters.cpu_usage 
	+ 0.0021 * parameters.avg_latency_of_same_past_second 
	+ 14551378.9296;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM6(work_wait &parameters) {
  double actual_remaining = 
	6.3988 * parameters.work_so_far 
	- 43.1587 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	+ 5280694.9368 * parameters.num_of_wait_locks 
	- 43391.9525 * parameters.total_wait_locks 
	- 0.002 * parameters.mean_wait_of_all 
	+ 127455.1352 * parameters.cpu_usage 
	+ 0.0021 * parameters.avg_latency_of_same_past_second 
	+ 18969707.8867;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM7(work_wait &parameters) {
  double actual_remaining = 
	329.1178 * parameters.work_so_far 
	- 64.578 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	+ 429934.5246 * parameters.num_of_wait_locks 
	+ 207437.2863 * parameters.total_wait_locks 
	- 1.5048 * parameters.mean_wait_of_all 
	- 228719887.9495 * parameters.cpu_usage 
	+ 0.0817 * parameters.avg_latency_of_same_past_second 
	+ 252430338.721;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM8(work_wait &parameters) {
  double actual_remaining = 
	13.8012 * parameters.work_so_far 
	- 64.578 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	+ 429934.5246 * parameters.num_of_wait_locks 
	+ 70243.1893 * parameters.total_wait_locks 
	- 14.6946 * parameters.mean_wait_of_all 
	+ 418408468.902 * parameters.cpu_usage 
	+ 0.2145 * parameters.avg_latency_of_same_past_second 
	+ 997594184.7563;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM9(work_wait &parameters) {
  double actual_remaining = 
	13.8012 * parameters.work_so_far 
	- 64.578 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	+ 429934.5246 * parameters.num_of_wait_locks 
	+ 7171.8655 * parameters.total_wait_locks 
	- 0.0255 * parameters.mean_wait_of_all 
	+ 1421931.0072 * parameters.cpu_usage 
	- 0.0002 * parameters.avg_latency_of_same_past_second 
	+ 22605886.6172;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM10(work_wait &parameters) {
  double actual_remaining = 
	110.7523 * parameters.work_so_far 
	+ 763.0605 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	+ 4213445.4214 * parameters.num_of_wait_locks 
	+ 95995.5964 * parameters.total_wait_locks 
	- 0.4249 * parameters.mean_wait_of_all 
	+ 92736012.9681 * parameters.cpu_usage 
	+ 0.1078 * parameters.avg_latency_of_same_past_second 
	- 134419494.8926;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM11(work_wait &parameters) {
  double actual_remaining = 
	110.7523 * parameters.work_so_far 
	+ 763.0605 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	+ 4213445.4214 * parameters.num_of_wait_locks 
	+ 188176.8111 * parameters.total_wait_locks 
	- 0.8488 * parameters.mean_wait_of_all 
	+ 325714122.9897 * parameters.cpu_usage 
	+ 0.0163 * parameters.avg_latency_of_same_past_second 
	- 312011914.7145;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM12(work_wait &parameters) {
  double actual_remaining = 
	101.5701 * parameters.work_so_far 
	+ 677.8624 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	+ 46242398.6382 * parameters.num_of_wait_locks 
	+ 25236.3869 * parameters.total_wait_locks 
	- 0.1005 * parameters.mean_wait_of_all 
	+ 142146337.0487 * parameters.cpu_usage 
	+ 0.1748 * parameters.avg_latency_of_same_past_second 
	- 360758440.6934;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM13(work_wait &parameters) {
  double actual_remaining = 
	4.2053 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	- 22441.4694 * parameters.num_of_wait_locks 
	+ 1491.2808 * parameters.total_wait_locks 
	- 0.001 * parameters.mean_wait_of_all 
	- 196354.2294 * parameters.cpu_usage 
	+ 0.0006 * parameters.avg_latency_of_same_past_second 
	+ 7203867.3377;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM14(work_wait &parameters) {
  double actual_remaining = 
	13.8671 * parameters.work_so_far 
	+ 0.0025 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	- 22441.4694 * parameters.num_of_wait_locks 
	+ 18957.4345 * parameters.total_wait_locks 
	+ 0.0217 * parameters.mean_wait_of_all 
	- 12096337.5604 * parameters.cpu_usage 
	+ 0.0008 * parameters.avg_latency_of_same_past_second 
	+ 18252938.8797;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM15(work_wait &parameters) {
  double actual_remaining = 
	13.8671 * parameters.work_so_far 
	+ 0.0025 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	- 22441.4694 * parameters.num_of_wait_locks 
	+ 18776.834 * parameters.total_wait_locks 
	+ 0.0217 * parameters.mean_wait_of_all 
	- 39948525.6891 * parameters.cpu_usage 
	+ 0.0008 * parameters.avg_latency_of_same_past_second 
	+ 49036454.9995;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM16(work_wait &parameters) {
  double actual_remaining = 
	13.8671 * parameters.work_so_far 
	+ 0.0025 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	- 22441.4694 * parameters.num_of_wait_locks 
	+ 16194.0804 * parameters.total_wait_locks 
	+ 0.0385 * parameters.mean_wait_of_all 
	- 164649441.0963 * parameters.cpu_usage 
	+ 0.0008 * parameters.avg_latency_of_same_past_second 
	+ 155609030.0451;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM17(work_wait &parameters) {
  double actual_remaining = 
	413.0756 * parameters.work_so_far 
	+ 0.0538 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	- 22441.4694 * parameters.num_of_wait_locks 
	+ 1617.3317 * parameters.total_wait_locks 
	+ 0.0118 * parameters.mean_wait_of_all 
	- 2376666.2833 * parameters.cpu_usage 
	- 0.6042 * parameters.avg_latency_of_same_past_second 
	+ 28023814.7835;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM18(work_wait &parameters) {
  double actual_remaining = 
	89.4678 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	- 22441.4694 * parameters.num_of_wait_locks 
	+ 83968.4189 * parameters.total_wait_locks 
	- 0.001 * parameters.mean_wait_of_all 
	- 196354.2294 * parameters.cpu_usage 
	- 0.0142 * parameters.avg_latency_of_same_past_second 
	+ 7967088.4434;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM19(work_wait &parameters) {
  double actual_remaining = 
	2.813 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	- 22441.4694 * parameters.num_of_wait_locks 
	+ 37198.9679 * parameters.total_wait_locks 
	- 0.0042 * parameters.mean_wait_of_all 
	+ 12155036.8527 * parameters.cpu_usage 
	+ 0.1098 * parameters.avg_latency_of_same_past_second 
	- 2350550.7413;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM20(work_wait &parameters) {
  double actual_remaining = 
	2.813 * parameters.work_so_far 
	+ 0.0372 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	- 1941748.8055 * parameters.num_of_wait_locks 
	+ 110161.8345 * parameters.total_wait_locks 
	- 0.0042 * parameters.mean_wait_of_all 
	+ 91906027.6302 * parameters.cpu_usage 
	+ 0.1824 * parameters.avg_latency_of_same_past_second 
	- 84248375.0971;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM21(work_wait &parameters) {
  double actual_remaining = 
	2.813 * parameters.work_so_far 
	+ 0.0372 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	- 5354825.3533 * parameters.num_of_wait_locks 
	+ 110161.8345 * parameters.total_wait_locks 
	- 0.0042 * parameters.mean_wait_of_all 
	+ 96910570.6519 * parameters.cpu_usage 
	+ 0.1824 * parameters.avg_latency_of_same_past_second 
	- 77786652.2793;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM22(work_wait &parameters) {
  double actual_remaining = 
	2.813 * parameters.work_so_far 
	+ 0.0372 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	- 6066606.4564 * parameters.num_of_wait_locks 
	+ 110161.8345 * parameters.total_wait_locks 
	- 0.0042 * parameters.mean_wait_of_all 
	+ 96910570.6519 * parameters.cpu_usage 
	+ 0.1824 * parameters.avg_latency_of_same_past_second 
	- 75253142.941;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM23(work_wait &parameters) {
  double actual_remaining = 
	2.813 * parameters.work_so_far 
	+ 0.1037 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	- 22441.4694 * parameters.num_of_wait_locks 
	+ 247065.5445 * parameters.total_wait_locks 
	- 0.0042 * parameters.mean_wait_of_all 
	+ 96190041.3944 * parameters.cpu_usage 
	+ 0.1824 * parameters.avg_latency_of_same_past_second 
	- 114333511.3653;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM24(work_wait &parameters) {
  double actual_remaining = 
	-49.9531 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	- 22441.4694 * parameters.num_of_wait_locks 
	+ 63029.7781 * parameters.total_wait_locks 
	+ 0.1296 * parameters.mean_wait_of_all 
	- 196354.2294 * parameters.cpu_usage 
	+ 0.0033 * parameters.avg_latency_of_same_past_second 
	+ 4301265.1881;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM25(work_wait &parameters) {
  double actual_remaining = 
	-68.7982 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	- 22441.4694 * parameters.num_of_wait_locks 
	+ 77569.6389 * parameters.total_wait_locks 
	+ 0.7102 * parameters.mean_wait_of_all 
	- 196354.2294 * parameters.cpu_usage 
	- 0.2025 * parameters.avg_latency_of_same_past_second 
	+ 11666504.3537;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM26(work_wait &parameters) {
  double actual_remaining = 
	2.813 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	- 22441.4694 * parameters.num_of_wait_locks 
	+ 24269.4869 * parameters.total_wait_locks 
	- 0.0042 * parameters.mean_wait_of_all 
	- 196354.2294 * parameters.cpu_usage 
	+ 0.0033 * parameters.avg_latency_of_same_past_second 
	+ 10364594.1128;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM27(work_wait &parameters) {
  double actual_remaining = 
	-1720.744 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	- 22441.4694 * parameters.num_of_wait_locks 
	- 56667.1925 * parameters.total_wait_locks 
	- 0.0245 * parameters.mean_wait_of_all 
	- 259502053.254 * parameters.cpu_usage 
	+ 0.0455 * parameters.avg_latency_of_same_past_second 
	+ 323535804.589;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM28(work_wait &parameters) {
  double actual_remaining = 
	2.813 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	- 22441.4694 * parameters.num_of_wait_locks 
	- 56667.1925 * parameters.total_wait_locks 
	- 0.0245 * parameters.mean_wait_of_all 
	- 167982394.7747 * parameters.cpu_usage 
	+ 0.0455 * parameters.avg_latency_of_same_past_second 
	+ 184210819.5644;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM29(work_wait &parameters) {
  double actual_remaining = 
	2.813 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	- 22441.4694 * parameters.num_of_wait_locks 
	- 17449.1007 * parameters.total_wait_locks 
	- 0.0126 * parameters.mean_wait_of_all 
	- 196354.2294 * parameters.cpu_usage 
	- 0.0626 * parameters.avg_latency_of_same_past_second 
	+ 42675286.6708;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM30(work_wait &parameters) {
  double actual_remaining = 
	-6081.0368 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	- 22441.4694 * parameters.num_of_wait_locks 
	- 2533.383 * parameters.total_wait_locks 
	+ 0.0006 * parameters.mean_wait_of_all 
	- 149140677.1482 * parameters.cpu_usage 
	+ 0.2899 * parameters.avg_latency_of_same_past_second 
	+ 200286949.9443;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM31(work_wait &parameters) {
  double actual_remaining = 
	-47.6804 * parameters.work_so_far 
	- 0.0122 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	+ 2011338.5138 * parameters.num_of_wait_locks 
	- 43299.3103 * parameters.total_wait_locks 
	+ 0.1739 * parameters.mean_wait_of_all 
	- 951939.9012 * parameters.cpu_usage 
	+ 0.0033 * parameters.avg_latency_of_same_past_second 
	+ 25013395.3514;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM32(work_wait &parameters) {
  double actual_remaining = 
	1.2535 * parameters.work_so_far 
	- 0.017 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	- 22441.4694 * parameters.num_of_wait_locks 
	+ 19.7804 * parameters.total_wait_locks 
	- 0.0005 * parameters.mean_wait_of_all 
	- 197719.8504 * parameters.cpu_usage 
	+ 0.001 * parameters.avg_latency_of_same_past_second 
	+ 26056830.7739;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM33(work_wait &parameters) {
  double actual_remaining = 
	1.8697 * parameters.work_so_far 
	- 0.0174 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	- 22441.4694 * parameters.num_of_wait_locks 
	- 1747.9376 * parameters.total_wait_locks 
	+ 0.0268 * parameters.mean_wait_of_all 
	- 197719.8504 * parameters.cpu_usage 
	+ 0.0009 * parameters.avg_latency_of_same_past_second 
	+ 29424983.7895;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM34(work_wait &parameters) {
  double actual_remaining = 
	1.8697 * parameters.work_so_far 
	+ 0.0418 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	- 22441.4694 * parameters.num_of_wait_locks 
	- 1747.9376 * parameters.total_wait_locks 
	- 9.4861 * parameters.mean_wait_of_all 
	- 197719.8504 * parameters.cpu_usage 
	+ 0.0009 * parameters.avg_latency_of_same_past_second 
	+ 598080210.0586;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM35(work_wait &parameters) {
  double actual_remaining = 
	2.2972 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	+ 4980.7137 * parameters.num_of_wait_locks 
	- 4505.8523 * parameters.total_wait_locks 
	+ 0.0235 * parameters.mean_wait_of_all 
	- 197719.8504 * parameters.cpu_usage 
	+ 0.0009 * parameters.avg_latency_of_same_past_second 
	+ 25784933.5844;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM36(work_wait &parameters) {
  double actual_remaining = 
	3.725 * parameters.work_so_far 
	+ 0.0001 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	+ 3754183.6653 * parameters.num_of_wait_locks 
	- 554546.1655 * parameters.total_wait_locks 
	+ 2.8662 * parameters.mean_wait_of_all 
	- 197719.8504 * parameters.cpu_usage 
	+ 0.0009 * parameters.avg_latency_of_same_past_second 
	- 959582.3854;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM37(work_wait &parameters) {
  double actual_remaining = 
	2.0082 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	- 1295.7082 * parameters.num_of_wait_locks 
	- 212689.1208 * parameters.total_wait_locks 
	+ 0.8639 * parameters.mean_wait_of_all 
	- 197719.8504 * parameters.cpu_usage 
	+ 0.0012 * parameters.avg_latency_of_same_past_second 
	+ 31062487.5519;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM38(work_wait &parameters) {
  double actual_remaining = 
	2.0082 * parameters.work_so_far 
	- 0.009 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	- 1295.7082 * parameters.num_of_wait_locks 
	- 12799.421 * parameters.total_wait_locks 
	+ 0.0732 * parameters.mean_wait_of_all 
	- 57109850.4952 * parameters.cpu_usage 
	+ 0.0064 * parameters.avg_latency_of_same_past_second 
	+ 77765561.2045;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM39(work_wait &parameters) {
  double actual_remaining = 
	-757.1557 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	+ 14809228.147 * parameters.num_of_wait_locks 
	- 12799.421 * parameters.total_wait_locks 
	+ 0.0732 * parameters.mean_wait_of_all 
	- 197719.8504 * parameters.cpu_usage 
	+ 0.0143 * parameters.avg_latency_of_same_past_second 
	+ 30265404.6266;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM40(work_wait &parameters) {
  double actual_remaining = 
	-757.1557 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	+ 14232006.4609 * parameters.num_of_wait_locks 
	+ 40898.4352 * parameters.total_wait_locks 
	+ 0.0732 * parameters.mean_wait_of_all 
	- 197719.8504 * parameters.cpu_usage 
	+ 0.0143 * parameters.avg_latency_of_same_past_second 
	+ 11087870.8358;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM41(work_wait &parameters) {
  double actual_remaining = 
	-852.5953 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	+ 10939812.7579 * parameters.num_of_wait_locks 
	- 12799.421 * parameters.total_wait_locks 
	+ 0.0732 * parameters.mean_wait_of_all 
	- 197719.8504 * parameters.cpu_usage 
	+ 0.0143 * parameters.avg_latency_of_same_past_second 
	+ 40849111.5852;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM42(work_wait &parameters) {
  double actual_remaining = 
	-135.6133 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	- 1295.7082 * parameters.num_of_wait_locks 
	+ 283048.0223 * parameters.total_wait_locks 
	+ 0.0732 * parameters.mean_wait_of_all 
	- 197719.8504 * parameters.cpu_usage 
	+ 0.0616 * parameters.avg_latency_of_same_past_second 
	- 130462803.2485;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM43(work_wait &parameters) {
  double actual_remaining = 
	0.1154 * parameters.work_so_far 
	+ 0.2574 * parameters.wait_so_far 
	+ 5490.7856 * parameters.num_locks_so_far 
	+ 4416842.987 * parameters.num_of_wait_locks 
	- 103117.2911 * parameters.total_wait_locks 
	- 0.0009 * parameters.mean_wait_of_all 
	- 115971.3674 * parameters.cpu_usage 
	+ 0.0757 * parameters.avg_latency_of_same_past_second 
	+ 9254469.6005;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM44(work_wait &parameters) {
  double actual_remaining = 
	2.7735 * parameters.work_so_far 
	+ 0.0075 * parameters.wait_so_far 
	- 2336727.7334 * parameters.num_locks_so_far 
	- 2084438.0409 * parameters.num_of_wait_locks 
	+ 463726.1137 * parameters.total_wait_locks 
	- 0.0006 * parameters.mean_wait_of_all 
	- 3561270.2652 * parameters.cpu_usage 
	- 0.0012 * parameters.avg_latency_of_same_past_second 
	+ 62276448.7814;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM45(work_wait &parameters) {
  double actual_remaining = 
	0.1878 * parameters.work_so_far 
	+ 0.0218 * parameters.wait_so_far 
	- 199596.572 * parameters.num_locks_so_far 
	- 25640341.4763 * parameters.num_of_wait_locks 
	+ 1271876.118 * parameters.total_wait_locks 
	+ 0.804 * parameters.mean_wait_of_all 
	- 157988717.078 * parameters.cpu_usage 
	- 0.0234 * parameters.avg_latency_of_same_past_second 
	+ 182249182.85;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM46(work_wait &parameters) {
  double actual_remaining = 
	0.1878 * parameters.work_so_far 
	+ 0.0218 * parameters.wait_so_far 
	- 199596.572 * parameters.num_locks_so_far 
	- 37040660.4914 * parameters.num_of_wait_locks 
	+ 1666854.6529 * parameters.total_wait_locks 
	+ 0.9716 * parameters.mean_wait_of_all 
	- 224811052.1003 * parameters.cpu_usage 
	- 0.0234 * parameters.avg_latency_of_same_past_second 
	+ 345076645.7099;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM47(work_wait &parameters) {
  double actual_remaining = 
	0.1878 * parameters.work_so_far 
	+ 0.0218 * parameters.wait_so_far 
	- 199596.572 * parameters.num_locks_so_far 
	- 37040660.4914 * parameters.num_of_wait_locks 
	- 2927187.4191 * parameters.total_wait_locks 
	+ 0.9716 * parameters.mean_wait_of_all 
	- 197175408.9491 * parameters.cpu_usage 
	- 0.5418 * parameters.avg_latency_of_same_past_second 
	+ 671798074.9413;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM48(work_wait &parameters) {
  double actual_remaining = 
	0.1878 * parameters.work_so_far 
	+ 0.0218 * parameters.wait_so_far 
	- 199596.572 * parameters.num_locks_so_far 
	- 37040660.4914 * parameters.num_of_wait_locks 
	- 1450531.0388 * parameters.total_wait_locks 
	+ 0.9716 * parameters.mean_wait_of_all 
	- 197175408.9491 * parameters.cpu_usage 
	- 0.0234 * parameters.avg_latency_of_same_past_second 
	+ 533422001.9748;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM49(work_wait &parameters) {
  double actual_remaining = 
	0.1878 * parameters.work_so_far 
	+ 0.2535 * parameters.wait_so_far 
	- 199596.572 * parameters.num_locks_so_far 
	- 65071283.4755 * parameters.num_of_wait_locks 
	+ 2169247.6485 * parameters.total_wait_locks 
	+ 1.6416 * parameters.mean_wait_of_all 
	- 119507198.4895 * parameters.cpu_usage 
	- 0.0234 * parameters.avg_latency_of_same_past_second 
	+ 169571356.5071;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM50(work_wait &parameters) {
  double actual_remaining = 
	0.1878 * parameters.work_so_far 
	+ 0.0299 * parameters.wait_so_far 
	- 199596.572 * parameters.num_locks_so_far 
	- 8515949.8632 * parameters.num_of_wait_locks 
	+ 184439.9342 * parameters.total_wait_locks 
	- 0.0006 * parameters.mean_wait_of_all 
	- 55447791.7297 * parameters.cpu_usage 
	- 0.0226 * parameters.avg_latency_of_same_past_second 
	+ 127447799.1197;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM51(work_wait &parameters) {
  double actual_remaining = 
	6.4582 * parameters.work_so_far 
	+ 0.033 * parameters.wait_so_far 
	- 199596.572 * parameters.num_locks_so_far 
	- 28957878.5155 * parameters.num_of_wait_locks 
	+ 184439.9342 * parameters.total_wait_locks 
	- 0.0006 * parameters.mean_wait_of_all 
	- 66266518.2237 * parameters.cpu_usage 
	- 0.0226 * parameters.avg_latency_of_same_past_second 
	+ 209682635.3051;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM52(work_wait &parameters) {
  double actual_remaining = 
	264.846 * parameters.work_so_far 
	- 0.0118 * parameters.wait_so_far 
	- 192998.1527 * parameters.num_locks_so_far 
	- 6550590.9416 * parameters.num_of_wait_locks 
	+ 823130.8154 * parameters.total_wait_locks 
	- 2.1218 * parameters.mean_wait_of_all 
	- 480854144.8477 * parameters.cpu_usage 
	+ 0.0009 * parameters.avg_latency_of_same_past_second 
	+ 540168993.0836;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM53(work_wait &parameters) {
  double actual_remaining = 
	264.846 * parameters.work_so_far 
	- 0.0118 * parameters.wait_so_far 
	- 192998.1527 * parameters.num_locks_so_far 
	- 6550590.9416 * parameters.num_of_wait_locks 
	+ 1821268.6902 * parameters.total_wait_locks 
	- 1.1657 * parameters.mean_wait_of_all 
	- 374252469.3995 * parameters.cpu_usage 
	+ 0.0009 * parameters.avg_latency_of_same_past_second 
	+ 359349821.2516;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM54(work_wait &parameters) {
  double actual_remaining = 
	-1575.9406 * parameters.work_so_far 
	- 0.0118 * parameters.wait_so_far 
	- 192998.1527 * parameters.num_locks_so_far 
	- 6550590.9416 * parameters.num_of_wait_locks 
	+ 1250763.6797 * parameters.total_wait_locks 
	+ 6.64 * parameters.mean_wait_of_all 
	- 690374998.7279 * parameters.cpu_usage 
	+ 0.0009 * parameters.avg_latency_of_same_past_second 
	+ 564375051.9882;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM55(work_wait &parameters) {
  double actual_remaining = 
	-1575.9406 * parameters.work_so_far 
	- 0.0118 * parameters.wait_so_far 
	- 192998.1527 * parameters.num_locks_so_far 
	- 6550590.9416 * parameters.num_of_wait_locks 
	+ 909752.2002 * parameters.total_wait_locks 
	+ 7.0117 * parameters.mean_wait_of_all 
	- 798666880.7 * parameters.cpu_usage 
	+ 0.0009 * parameters.avg_latency_of_same_past_second 
	+ 702598735.6655;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM56(work_wait &parameters) {
  double actual_remaining = 
	-1644.1178 * parameters.work_so_far 
	- 0.0118 * parameters.wait_so_far 
	- 192998.1527 * parameters.num_locks_so_far 
	- 6550590.9416 * parameters.num_of_wait_locks 
	+ 909752.2002 * parameters.total_wait_locks 
	- 1.1657 * parameters.mean_wait_of_all 
	- 383032606.5525 * parameters.cpu_usage 
	+ 0.0009 * parameters.avg_latency_of_same_past_second 
	+ 558805173.8043;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM57(work_wait &parameters) {
  double actual_remaining = 
	130.0955 * parameters.work_so_far 
	- 0.0013 * parameters.wait_so_far 
	- 192998.1527 * parameters.num_locks_so_far 
	- 4879933.0586 * parameters.num_of_wait_locks 
	+ 512996.0497 * parameters.total_wait_locks 
	+ 0.0134 * parameters.mean_wait_of_all 
	- 22101702.9831 * parameters.cpu_usage 
	- 0.1181 * parameters.avg_latency_of_same_past_second 
	+ 77882979.3721;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM58(work_wait &parameters) {
  double actual_remaining = 
	181.521 * parameters.work_so_far 
	- 0.1207 * parameters.wait_so_far 
	- 192998.1527 * parameters.num_locks_so_far 
	- 40429862.3107 * parameters.num_of_wait_locks 
	+ 133617.2929 * parameters.total_wait_locks 
	+ 0.031 * parameters.mean_wait_of_all 
	- 8737581.2325 * parameters.cpu_usage 
	+ 0.0009 * parameters.avg_latency_of_same_past_second 
	+ 285582564.9658;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM59(work_wait &parameters) {
  double actual_remaining = 
	4.8287 * parameters.work_so_far 
	+ 0.5209 * parameters.wait_so_far 
	- 6958333.1644 * parameters.num_locks_so_far 
	- 14392506.8642 * parameters.num_of_wait_locks 
	+ 138057.4213 * parameters.total_wait_locks 
	+ 0.002 * parameters.mean_wait_of_all 
	- 24870602.6664 * parameters.cpu_usage 
	+ 0.0009 * parameters.avg_latency_of_same_past_second 
	+ 283305336.048;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM60(work_wait &parameters) {
  double actual_remaining = 
	1.0786 * parameters.work_so_far 
	- 0.0694 * parameters.wait_so_far 
	- 1203267.2384 * parameters.num_locks_so_far 
	+ 26099532.5245 * parameters.num_of_wait_locks 
	+ 1547272.5538 * parameters.total_wait_locks 
	+ 0.002 * parameters.mean_wait_of_all 
	- 24870602.6664 * parameters.cpu_usage 
	+ 0.0009 * parameters.avg_latency_of_same_past_second 
	- 57547819.7252;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM61(work_wait &parameters) {
  double actual_remaining = 
	0.6014 * parameters.work_so_far 
	- 0.1028 * parameters.wait_so_far 
	+ 4432831.0895 * parameters.num_locks_so_far 
	- 11330957.6927 * parameters.num_of_wait_locks 
	+ 178589.6615 * parameters.total_wait_locks 
	+ 0.002 * parameters.mean_wait_of_all 
	- 33206690.224 * parameters.cpu_usage 
	+ 0.4315 * parameters.avg_latency_of_same_past_second 
	+ 49766405.9381;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM62(work_wait &parameters) {
  double actual_remaining = 
	3.3194 * parameters.work_so_far 
	+ 0.7144 * parameters.wait_so_far 
	- 2568928.0425 * parameters.num_locks_so_far 
	- 5740445.0439 * parameters.num_of_wait_locks 
	+ 747282.8777 * parameters.total_wait_locks 
	- 0.2017 * parameters.mean_wait_of_all 
	- 184738072.0593 * parameters.cpu_usage 
	+ 0.0009 * parameters.avg_latency_of_same_past_second 
	+ 220392069.8887;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM63(work_wait &parameters) {
  double actual_remaining = 
	1.1824 * parameters.work_so_far 
	+ 0.9209 * parameters.wait_so_far 
	- 3874204.2831 * parameters.num_locks_so_far 
	- 1405395.5902 * parameters.num_of_wait_locks 
	+ 1006830.1036 * parameters.total_wait_locks 
	- 0.0004 * parameters.mean_wait_of_all 
	+ 201385480.8415 * parameters.cpu_usage 
	- 0.1431 * parameters.avg_latency_of_same_past_second 
	+ 22135037.3395;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM64(work_wait &parameters) {
  double actual_remaining = 
	1.6127 * parameters.work_so_far 
	- 0.1531 * parameters.wait_so_far 
	- 1595.192 * parameters.num_locks_so_far 
	- 34004904.1156 * parameters.num_of_wait_locks 
	+ 210522.4338 * parameters.total_wait_locks 
	- 0.0015 * parameters.mean_wait_of_all 
	- 119570171.2697 * parameters.cpu_usage 
	+ 0.094 * parameters.avg_latency_of_same_past_second 
	+ 445447636.8778;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM65(work_wait &parameters) {
  double actual_remaining = 
	0.0302 * parameters.work_so_far 
	- 0.1091 * parameters.wait_so_far 
	- 1595.192 * parameters.num_locks_so_far 
	- 37364297.0385 * parameters.num_of_wait_locks 
	+ 2079.0179 * parameters.total_wait_locks 
	+ 0.5755 * parameters.mean_wait_of_all 
	- 229473444.7288 * parameters.cpu_usage 
	+ 0.0016 * parameters.avg_latency_of_same_past_second 
	+ 532329105.9508;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM66(work_wait &parameters) {
  double actual_remaining = 
	0.7108 * parameters.work_so_far 
	- 0.1344 * parameters.wait_so_far 
	- 1595.192 * parameters.num_locks_so_far 
	- 33235570.8962 * parameters.num_of_wait_locks 
	+ 2079.0179 * parameters.total_wait_locks 
	+ 0.0053 * parameters.mean_wait_of_all 
	- 3887252.7855 * parameters.cpu_usage 
	+ 0.0016 * parameters.avg_latency_of_same_past_second 
	+ 398040175.3796;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM67(work_wait &parameters) {
  double actual_remaining = 
	0.0752 * parameters.work_so_far 
	- 0.0481 * parameters.wait_so_far 
	- 1595.192 * parameters.num_locks_so_far 
	- 177912280.4755 * parameters.num_of_wait_locks 
	+ 2079.0179 * parameters.total_wait_locks 
	+ 0.0053 * parameters.mean_wait_of_all 
	- 3887252.7855 * parameters.cpu_usage 
	+ 0.0688 * parameters.avg_latency_of_same_past_second 
	+ 946174437.8109;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM68(work_wait &parameters) {
  double actual_remaining = 
	0.0752 * parameters.work_so_far 
	+ 0.0083 * parameters.wait_so_far 
	- 1595.192 * parameters.num_locks_so_far 
	- 28691770.1913 * parameters.num_of_wait_locks 
	+ 2079.0179 * parameters.total_wait_locks 
	+ 0.0053 * parameters.mean_wait_of_all 
	- 3887252.7855 * parameters.cpu_usage 
	- 0.0034 * parameters.avg_latency_of_same_past_second 
	+ 282652569.3375;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM69(work_wait &parameters) {
  double actual_remaining = 
	0.0752 * parameters.work_so_far 
	+ 0.1507 * parameters.wait_so_far 
	- 1595.192 * parameters.num_locks_so_far 
	- 18844051.8914 * parameters.num_of_wait_locks 
	- 101136.5293 * parameters.total_wait_locks 
	+ 0.4762 * parameters.mean_wait_of_all 
	+ 493943857.4674 * parameters.cpu_usage 
	- 0.381 * parameters.avg_latency_of_same_past_second 
	+ 9805762.6558;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM70(work_wait &parameters) {
  double actual_remaining = 
	0.0752 * parameters.work_so_far 
	+ 0.1507 * parameters.wait_so_far 
	- 1595.192 * parameters.num_locks_so_far 
	- 18844051.8914 * parameters.num_of_wait_locks 
	- 101136.5293 * parameters.total_wait_locks 
	+ 0.4762 * parameters.mean_wait_of_all 
	- 432490546.8643 * parameters.cpu_usage 
	- 0.2818 * parameters.avg_latency_of_same_past_second 
	+ 715211031.5936;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM71(work_wait &parameters) {
  double actual_remaining = 
	0.0752 * parameters.work_so_far 
	+ 0.4158 * parameters.wait_so_far 
	- 1595.192 * parameters.num_locks_so_far 
	- 68635924.0215 * parameters.num_of_wait_locks 
	- 114717.5223 * parameters.total_wait_locks 
	+ 0.5382 * parameters.mean_wait_of_all 
	- 3887252.7855 * parameters.cpu_usage 
	- 1.5577 * parameters.avg_latency_of_same_past_second 
	+ 1000111089.7312;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM72(work_wait &parameters) {
  double actual_remaining = 
	-1.2751 * parameters.work_so_far 
	- 0.0302 * parameters.wait_so_far 
	- 1595.192 * parameters.num_locks_so_far 
	- 41477679.424 * parameters.num_of_wait_locks 
	- 114717.5223 * parameters.total_wait_locks 
	+ 0.5382 * parameters.mean_wait_of_all 
	+ 168914249.0652 * parameters.cpu_usage 
	- 0.4328 * parameters.avg_latency_of_same_past_second 
	+ 669814785.4378;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM73(work_wait &parameters) {
  double actual_remaining = 
	-0.6983 * parameters.work_so_far 
	+ 0.5634 * parameters.wait_so_far 
	- 1595.192 * parameters.num_locks_so_far 
	- 41477679.424 * parameters.num_of_wait_locks 
	- 114717.5223 * parameters.total_wait_locks 
	+ 0.5382 * parameters.mean_wait_of_all 
	+ 795539459.7238 * parameters.cpu_usage 
	- 0.4328 * parameters.avg_latency_of_same_past_second 
	- 409267737.6136;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM74(work_wait &parameters) {
  double actual_remaining = 
	-0.6983 * parameters.work_so_far 
	+ 0.5634 * parameters.wait_so_far 
	- 1595.192 * parameters.num_locks_so_far 
	- 41477679.424 * parameters.num_of_wait_locks 
	- 114717.5223 * parameters.total_wait_locks 
	+ 0.5382 * parameters.mean_wait_of_all 
	+ 701941506.8307 * parameters.cpu_usage 
	- 0.4328 * parameters.avg_latency_of_same_past_second 
	- 306794914.8185;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM75(work_wait &parameters) {
  double actual_remaining = 
	-0.4883 * parameters.work_so_far 
	+ 0.4563 * parameters.wait_so_far 
	- 1595.192 * parameters.num_locks_so_far 
	- 41477679.424 * parameters.num_of_wait_locks 
	- 114717.5223 * parameters.total_wait_locks 
	+ 0.5382 * parameters.mean_wait_of_all 
	- 3887252.7855 * parameters.cpu_usage 
	- 0.4328 * parameters.avg_latency_of_same_past_second 
	+ 277284559.011;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM76(work_wait &parameters) {
  double actual_remaining = 
	0.1262 * parameters.work_so_far 
	+ 0.0532 * parameters.wait_so_far 
	- 4736197.1637 * parameters.num_locks_so_far 
	- 7681366.9882 * parameters.num_of_wait_locks 
	+ 121519.1023 * parameters.total_wait_locks 
	- 0.5661 * parameters.mean_wait_of_all 
	- 3896399.6413 * parameters.cpu_usage 
	+ 0.0168 * parameters.avg_latency_of_same_past_second 
	+ 349908146.6181;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM77(work_wait &parameters) {
  double actual_remaining = 
	0.1262 * parameters.work_so_far 
	+ 0.0532 * parameters.wait_so_far 
	- 4313517.6213 * parameters.num_locks_so_far 
	- 7278657.65 * parameters.num_of_wait_locks 
	+ 113442.9469 * parameters.total_wait_locks 
	- 0.527 * parameters.mean_wait_of_all 
	- 3896399.6413 * parameters.cpu_usage 
	+ 0.0168 * parameters.avg_latency_of_same_past_second 
	+ 248386208.474;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM78(work_wait &parameters) {
  double actual_remaining = 
	0.1262 * parameters.work_so_far 
	+ 0.0404 * parameters.wait_so_far 
	- 532667.3497 * parameters.num_locks_so_far 
	- 37910827.3233 * parameters.num_of_wait_locks 
	+ 320706.9591 * parameters.total_wait_locks 
	- 1.1206 * parameters.mean_wait_of_all 
	- 3896399.6413 * parameters.cpu_usage 
	+ 0.2009 * parameters.avg_latency_of_same_past_second 
	+ 346624390.8277;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM79(work_wait &parameters) {
  double actual_remaining = 
	1.4045 * parameters.work_so_far 
	+ 0.8128 * parameters.wait_so_far 
	- 135178.9736 * parameters.num_locks_so_far 
	- 65461538.342 * parameters.num_of_wait_locks 
	+ 1581213.2185 * parameters.total_wait_locks 
	- 7.4875 * parameters.mean_wait_of_all 
	- 3896399.6413 * parameters.cpu_usage 
	+ 0.199 * parameters.avg_latency_of_same_past_second 
	+ 438641098.7134;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM80(work_wait &parameters) {
  double actual_remaining = 
	2.3245 * parameters.work_so_far 
	+ 0.8132 * parameters.wait_so_far 
	- 4015769.4704 * parameters.num_locks_so_far 
	- 19790937.3922 * parameters.num_of_wait_locks 
	+ 2540.2071 * parameters.total_wait_locks 
	- 0.0177 * parameters.mean_wait_of_all 
	- 150428636.5006 * parameters.cpu_usage 
	+ 0.0041 * parameters.avg_latency_of_same_past_second 
	+ 423898950.7679;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM81(work_wait &parameters) {
  double actual_remaining = 
	0.6745 * parameters.work_so_far 
	+ 0.6198 * parameters.wait_so_far 
	- 5352942.3996 * parameters.num_locks_so_far 
	- 1863923.5393 * parameters.num_of_wait_locks 
	+ 870060.1825 * parameters.total_wait_locks 
	- 3.7703 * parameters.mean_wait_of_all 
	- 367102082.5383 * parameters.cpu_usage 
	- 0.3236 * parameters.avg_latency_of_same_past_second 
	+ 880748735.234;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM82(work_wait &parameters) {
  double actual_remaining = 
	0.7896 * parameters.work_so_far 
	+ 0.0431 * parameters.wait_so_far 
	- 7068537.1506 * parameters.num_locks_so_far 
	- 3628121.0051 * parameters.num_of_wait_locks 
	+ 1631120.6717 * parameters.total_wait_locks 
	- 8.1391 * parameters.mean_wait_of_all 
	- 31653071.4307 * parameters.cpu_usage 
	+ 0.4572 * parameters.avg_latency_of_same_past_second 
	+ 453703070.1396;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM83(work_wait &parameters) {
  double actual_remaining = 
	7.2559 * parameters.work_so_far 
	+ 0.6666 * parameters.wait_so_far 
	+ 39190045.8278 * parameters.num_locks_so_far 
	- 80703369.8394 * parameters.num_of_wait_locks 
	- 350030.6524 * parameters.total_wait_locks 
	- 0.0353 * parameters.mean_wait_of_all 
	- 10183727.247 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_latency_of_same_past_second 
	+ 209042816.2618;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM84(work_wait &parameters) {
  double actual_remaining = 
	2.9066 * parameters.work_so_far 
	+ 0.4951 * parameters.wait_so_far 
	- 556459.7668 * parameters.num_locks_so_far 
	- 8981082.404 * parameters.num_of_wait_locks 
	- 299829.9723 * parameters.total_wait_locks 
	- 0.0353 * parameters.mean_wait_of_all 
	- 333355842.22 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_latency_of_same_past_second 
	+ 618551052.4963;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM85(work_wait &parameters) {
  double actual_remaining = 
	1.0868 * parameters.work_so_far 
	+ 0.0699 * parameters.wait_so_far 
	- 4673895.076 * parameters.num_locks_so_far 
	- 97683816.6617 * parameters.num_of_wait_locks 
	- 38727.9362 * parameters.total_wait_locks 
	- 0.0353 * parameters.mean_wait_of_all 
	- 24802131.083 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_latency_of_same_past_second 
	+ 937007356.7331;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM86(work_wait &parameters) {
  double actual_remaining = 
	0.0633 * parameters.work_so_far 
	+ 0.4233 * parameters.wait_so_far 
	- 72924.9833 * parameters.num_locks_so_far 
	- 128815474.5717 * parameters.num_of_wait_locks 
	+ 4034332.5847 * parameters.total_wait_locks 
	- 16.6238 * parameters.mean_wait_of_all 
	- 3487272.7952 * parameters.cpu_usage 
	- 0.0337 * parameters.avg_latency_of_same_past_second 
	+ 439259057.6196;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM87(work_wait &parameters) {
  double actual_remaining = 
	0.0633 * parameters.work_so_far 
	+ 0.1309 * parameters.wait_so_far 
	- 1290517.8201 * parameters.num_locks_so_far 
	- 147426578.5899 * parameters.num_of_wait_locks 
	+ 768738.2368 * parameters.total_wait_locks 
	- 0.1323 * parameters.mean_wait_of_all 
	- 1223237783.1016 * parameters.cpu_usage 
	- 0.0189 * parameters.avg_latency_of_same_past_second 
	+ 2073964257.4321;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM88(work_wait &parameters) {
  double actual_remaining = 
	0.0633 * parameters.work_so_far 
	+ 0.5104 * parameters.wait_so_far 
	- 911681.4638 * parameters.num_locks_so_far 
	- 24849882.9237 * parameters.num_of_wait_locks 
	+ 30621.1531 * parameters.total_wait_locks 
	- 0.1323 * parameters.mean_wait_of_all 
	- 93763626.9762 * parameters.cpu_usage 
	- 0.2274 * parameters.avg_latency_of_same_past_second 
	+ 653292640.547;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM89(work_wait &parameters) {
  double actual_remaining = 
	0.0633 * parameters.work_so_far 
	+ 0.2218 * parameters.wait_so_far 
	- 1140242.419 * parameters.num_locks_so_far 
	- 28938763.7403 * parameters.num_of_wait_locks 
	- 69813.4756 * parameters.total_wait_locks 
	+ 0.2393 * parameters.mean_wait_of_all 
	- 82705703.9987 * parameters.cpu_usage 
	- 0.0189 * parameters.avg_latency_of_same_past_second 
	+ 1032489348.2354;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
tpcc_estimate(work_wait &parameters){

  if (parameters.num_locks_so_far <= 2.5) {

    if (parameters.work_so_far <= 131137) {

      if (parameters.wait_so_far <= 15043.5) {

        if (parameters.wait_so_far <= 2380.5) {

          if (parameters.total_wait_locks <= 81.5) {

            if (parameters.work_so_far <= 8923.5) {
              return tpcc_LM1(parameters);
            } else {
              return tpcc_LM2(parameters);
            }
          } else {

            if (parameters.work_so_far <= 11418.5) {
              return tpcc_LM3(parameters);
            } else {
              return tpcc_LM4(parameters);
            }
          }
        } else {

          if (parameters.total_wait_locks <= 285.5) {

            if (parameters.wait_so_far <= 3700.5) {
              return tpcc_LM5(parameters);
            } else {
              return tpcc_LM6(parameters);
            }
          } else {

            if (parameters.num_of_wait_locks <= 3.5) {

              if (parameters.avg_latency_of_same_past_second <= 352982000) {

                if (parameters.mean_wait_of_all <= 92123450) {
                  return tpcc_LM7(parameters);
                } else {
                  return tpcc_LM8(parameters);
                }
              } else {
                return tpcc_LM9(parameters);
              }
            } else {

              if (parameters.work_so_far <= 31318) {

                if (parameters.wait_so_far <= 11834) {
                  return tpcc_LM10(parameters);
                } else {
                  return tpcc_LM11(parameters);
                }
              } else {
                return tpcc_LM12(parameters);
              }
            }
          }
        }
      } else {

        if (parameters.total_wait_locks <= 154.5) {

          if (parameters.work_so_far <= 8342) {
            return tpcc_LM13(parameters);
          } else {

            if (parameters.avg_latency_of_same_past_second <= 31626550) {

              if (parameters.cpu_usage <= 0.884) {

                if (parameters.mean_wait_of_all <= 36118900) {

                  if (parameters.work_so_far <= 13848.5) {
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
            } else {

              if (parameters.wait_so_far <= 127781549) {
                return tpcc_LM18(parameters);
              } else {

                if (parameters.avg_latency_of_same_past_second <= 197100000) {

                  if (parameters.avg_latency_of_same_past_second <= 57465150) {

                    if (parameters.avg_latency_of_same_past_second <= 48148150) {
                      return tpcc_LM19(parameters);
                    } else {

                      if (parameters.avg_latency_of_same_past_second <= 55232300) {

                        if (parameters.cpu_usage <= 0.91) {
                          return tpcc_LM20(parameters);
                        } else {

                          if (parameters.mean_wait_of_all <= 33495350) {
                            return tpcc_LM21(parameters);
                          } else {
                            return tpcc_LM22(parameters);
                          }
                        }
                      } else {
                        return tpcc_LM23(parameters);
                      }
                    }
                  } else {

                    if (parameters.cpu_usage <= 0.911) {

                      if (parameters.avg_latency_of_same_past_second <= 98827350) {
                        return tpcc_LM24(parameters);
                      } else {
                        return tpcc_LM25(parameters);
                      }
                    } else {
                      return tpcc_LM26(parameters);
                    }
                  }
                } else {

                  if (parameters.mean_wait_of_all <= 32208750) {

                    if (parameters.cpu_usage <= 0.99) {
                      return tpcc_LM27(parameters);
                    } else {
                      return tpcc_LM28(parameters);
                    }
                  } else {
                    return tpcc_LM29(parameters);
                  }
                }
              }
            }
          }
        } else {

          if (parameters.work_so_far <= 26306.5) {

            if (parameters.work_so_far <= 21477) {
              return tpcc_LM30(parameters);
            } else {
              return tpcc_LM31(parameters);
            }
          } else {

            if (parameters.total_wait_locks <= 244.5) {
              return tpcc_LM32(parameters);
            } else {

              if (parameters.mean_wait_of_all <= 61007600) {

                if (parameters.mean_wait_of_all <= 57424800) {
                  return tpcc_LM33(parameters);
                } else {
                  return tpcc_LM34(parameters);
                }
              } else {

                if (parameters.wait_so_far <= 228263845.5) {

                  if (parameters.work_so_far <= 38544.5) {
                    return tpcc_LM35(parameters);
                  } else {
                    return tpcc_LM36(parameters);
                  }
                } else {

                  if (parameters.mean_wait_of_all <= 92181950) {
                    return tpcc_LM37(parameters);
                  } else {

                    if (parameters.avg_latency_of_same_past_second <= 447033000) {
                      return tpcc_LM38(parameters);
                    } else {

                      if (parameters.avg_latency_of_same_past_second <= 455141500) {

                        if (parameters.work_so_far <= 48895) {

                          if (parameters.num_of_wait_locks <= 3.5) {
                            return tpcc_LM39(parameters);
                          } else {
                            return tpcc_LM40(parameters);
                          }
                        } else {
                          return tpcc_LM41(parameters);
                        }
                      } else {
                        return tpcc_LM42(parameters);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    } else {
      return tpcc_LM43(parameters);
    }
  } else {

    if (parameters.total_wait_locks <= 151.5) {

      if (parameters.work_so_far <= 52284775) {

        if (parameters.total_wait_locks <= 68.5) {

          if (parameters.wait_so_far <= 3020) {
            return tpcc_LM44(parameters);
          } else {

            if (parameters.avg_latency_of_same_past_second <= 67886450) {

              if (parameters.work_so_far <= 24493) {
                return tpcc_LM45(parameters);
              } else {

                if (parameters.wait_so_far <= 755407.5) {

                  if (parameters.total_wait_locks <= 42.5) {
                    return tpcc_LM46(parameters);
                  } else {

                    if (parameters.total_wait_locks <= 52.5) {
                      return tpcc_LM47(parameters);
                    } else {
                      return tpcc_LM48(parameters);
                    }
                  }
                } else {
                  return tpcc_LM49(parameters);
                }
              }
            } else {

              if (parameters.wait_so_far <= 81094118.5) {
                return tpcc_LM50(parameters);
              } else {
                return tpcc_LM51(parameters);
              }
            }
          }
        } else {

          if (parameters.work_so_far <= 61888.5) {

            if (parameters.avg_latency_of_same_past_second <= 356121500) {

              if (parameters.wait_so_far <= 7666305.5) {

                if (parameters.work_so_far <= 25300) {
                  return tpcc_LM52(parameters);
                } else {

                  if (parameters.work_so_far <= 34426) {
                    return tpcc_LM53(parameters);
                  } else {

                    if (parameters.work_so_far <= 42935.5) {

                      if (parameters.mean_wait_of_all <= 31272300) {
                        return tpcc_LM54(parameters);
                      } else {
                        return tpcc_LM55(parameters);
                      }
                    } else {
                      return tpcc_LM56(parameters);
                    }
                  }
                }
              } else {
                return tpcc_LM57(parameters);
              }
            } else {
              return tpcc_LM58(parameters);
            }
          } else {

            if (parameters.num_locks_so_far <= 21.5) {

              if (parameters.cpu_usage <= 0.954) {

                if (parameters.num_of_wait_locks <= 2.5) {
                  return tpcc_LM59(parameters);
                } else {
                  return tpcc_LM60(parameters);
                }
              } else {
                return tpcc_LM61(parameters);
              }
            } else {
              return tpcc_LM62(parameters);
            }
          }
        }
      } else {
        return tpcc_LM63(parameters);
      }
    } else {

      if (parameters.num_locks_so_far <= 4.5) {

        if (parameters.wait_so_far <= 224453664) {
          return tpcc_LM64(parameters);
        } else {

          if (parameters.work_so_far <= 71744) {
            return tpcc_LM65(parameters);
          } else {

            if (parameters.wait_so_far <= 654313880) {
              return tpcc_LM66(parameters);
            } else {

              if (parameters.work_so_far <= 909655.5) {

                if (parameters.wait_so_far <= 736827009.5) {
                  return tpcc_LM67(parameters);
                } else {
                  return tpcc_LM68(parameters);
                }
              } else {

                if (parameters.wait_so_far <= 853089968) {

                  if (parameters.avg_latency_of_same_past_second <= 361319500) {
                    return tpcc_LM69(parameters);
                  } else {
                    return tpcc_LM70(parameters);
                  }
                } else {

                  if (parameters.avg_latency_of_same_past_second <= 373407000) {
                    return tpcc_LM71(parameters);
                  } else {

                    if (parameters.cpu_usage <= 0.995) {

                      if (parameters.wait_so_far <= 1164478445.5) {
                        return tpcc_LM72(parameters);
                      } else {

                        if (parameters.cpu_usage <= 0.817) {
                          return tpcc_LM73(parameters);
                        } else {
                          return tpcc_LM74(parameters);
                        }
                      }
                    } else {
                      return tpcc_LM75(parameters);
                    }
                  }
                }
              }
            }
          }
        }
      } else {

        if (parameters.wait_so_far <= 356350698.5) {

          if (parameters.work_so_far <= 107464592) {

            if (parameters.num_locks_so_far <= 11.5) {

              if (parameters.work_so_far <= 7396165) {

                if (parameters.wait_so_far <= 16794157) {

                  if (parameters.work_so_far <= 1987362) {
                    return tpcc_LM76(parameters);
                  } else {
                    return tpcc_LM77(parameters);
                  }
                } else {
                  return tpcc_LM78(parameters);
                }
              } else {
                return tpcc_LM79(parameters);
              }
            } else {
              return tpcc_LM80(parameters);
            }
          } else {

            if (parameters.avg_latency_of_same_past_second <= 554848500) {
              return tpcc_LM81(parameters);
            } else {
              return tpcc_LM82(parameters);
            }
          }
        } else {

          if (parameters.wait_so_far <= 634577845.5) {

            if (parameters.work_so_far <= 33118690) {

              if (parameters.num_locks_so_far <= 10.5) {
                return tpcc_LM83(parameters);
              } else {
                return tpcc_LM84(parameters);
              }
            } else {
              return tpcc_LM85(parameters);
            }
          } else {

            if (parameters.num_locks_so_far <= 6.5) {
              return tpcc_LM86(parameters);
            } else {

              if (parameters.wait_so_far <= 1001262872.5) {

                if (parameters.num_locks_so_far <= 11.5) {
                  return tpcc_LM87(parameters);
                } else {
                  return tpcc_LM88(parameters);
                }
              } else {
                return tpcc_LM89(parameters);
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
	0.295 * parameters.work_so_far 
	- 0.0073 * parameters.wait_so_far 
	+ 8483523.137 * parameters.num_locks_so_far 
	+ 311868.5524 * parameters.total_wait_locks 
	- 0.0597 * parameters.mean_wait_of_all 
	+ 113057838.4426 * parameters.cpu_usage 
	- 0.0241 * parameters.avg_latency_of_same_past_second 
	+ 152246268.381;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM2(work_wait &parameters) {
  double actual_remaining = 
	0.295 * parameters.work_so_far 
	- 0.3093 * parameters.wait_so_far 
	+ 9496819.1055 * parameters.num_locks_so_far 
	+ 328858.4281 * parameters.total_wait_locks 
	- 0.0597 * parameters.mean_wait_of_all 
	+ 113057838.4426 * parameters.cpu_usage 
	- 0.0241 * parameters.avg_latency_of_same_past_second 
	+ 344854325.6641;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM3(work_wait &parameters) {
  double actual_remaining = 
	1.5074 * parameters.work_so_far 
	+ 0.296 * parameters.wait_so_far 
	- 4644028.0822 * parameters.num_locks_so_far 
	+ 533800.4665 * parameters.total_wait_locks 
	- 0.0597 * parameters.mean_wait_of_all 
	+ 649970286.4653 * parameters.cpu_usage 
	- 0.0131 * parameters.avg_latency_of_same_past_second 
	- 167042042.2452;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM4(work_wait &parameters) {
  double actual_remaining = 
	0.8625 * parameters.work_so_far 
	+ 0.0209 * parameters.wait_so_far 
	- 10063510.5859 * parameters.num_locks_so_far 
	+ 91138.8685 * parameters.total_wait_locks 
	- 0.1288 * parameters.mean_wait_of_all 
	+ 35604647.9938 * parameters.cpu_usage 
	- 0.0123 * parameters.avg_latency_of_same_past_second 
	+ 928388140.9699;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
delivery_estimate(work_wait &parameters){

  if (parameters.work_so_far <= 313523300.5) {

    if (parameters.work_so_far <= 625904) {

      if (parameters.total_wait_locks <= 258) {
        return delivery_LM1(parameters);
      } else {
        return delivery_LM2(parameters);
      }
    } else {
      return delivery_LM3(parameters);
    }
  } else {
    return delivery_LM4(parameters);
  }
}
static
double
stock_level_LM1(work_wait &parameters) {
  double actual_remaining = 
	228146.6313 * parameters.num_locks_so_far 
	- 13347944.7653;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
stock_level_estimate(work_wait &parameters){
  return stock_level_LM1(parameters);
}