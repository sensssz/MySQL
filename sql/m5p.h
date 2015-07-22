#include "my_global.h"
#include "trace_tool.h"

static
double
new_order_LM1(work_wait &parameters) {
  double actual_remaining = 
	0.0067 * parameters.work_so_far 
	- 0.0013 * parameters.wait_so_far 
	- 76204.5863 * parameters.num_locks_so_far 
	+ 4303.1228 * parameters.total_wait_locks 
	- 0.0016 * parameters.mean_wait_of_all 
	- 7913905.8712 * parameters.cpu_usage 
	+ 0.2122 * parameters.avg_work_of_same_past_second 
	- 0.0956 * parameters.avg_wait_of_same_past_second 
	+ 0.2617 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 29201548.4754;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM2(work_wait &parameters) {
  double actual_remaining = 
	0.229 * parameters.work_so_far 
	- 0.0013 * parameters.wait_so_far 
	- 2886362.9618 * parameters.num_locks_so_far 
	+ 85624.0752 * parameters.total_wait_locks 
	- 0.172 * parameters.mean_wait_of_all 
	- 305966725.1489 * parameters.cpu_usage 
	+ 0.0031 * parameters.avg_work_of_same_past_second 
	- 0.001 * parameters.avg_wait_of_same_past_second 
	+ 0.2032 * parameters.avg_latency_of_same_last_20 
	- 0.0198 * parameters.max_latency_of_same_last_50 
	+ 375162642.0957;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM3(work_wait &parameters) {
  double actual_remaining = 
	0.2873 * parameters.work_so_far 
	- 0.0019 * parameters.wait_so_far 
	- 4884465.3949 * parameters.num_locks_so_far 
	+ 326968.0103 * parameters.total_wait_locks 
	+ 0.4841 * parameters.mean_wait_of_all 
	- 669994.0522 * parameters.cpu_usage 
	+ 0.6884 * parameters.avg_work_of_same_past_second 
	- 0.298 * parameters.avg_wait_of_same_past_second 
	+ 0.3044 * parameters.avg_latency_of_same_last_20 
	- 0.028 * parameters.max_latency_of_same_last_50 
	- 16878953.685;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM4(work_wait &parameters) {
  double actual_remaining = 
	-0.0037 * parameters.work_so_far 
	- 0.0059 * parameters.wait_so_far 
	- 97282.9758 * parameters.num_locks_so_far 
	+ 936003.2107 * parameters.total_wait_locks 
	- 1.9979 * parameters.mean_wait_of_all 
	+ 812800191.9804 * parameters.cpu_usage 
	+ 1.8929 * parameters.avg_work_of_same_past_second 
	- 1.0916 * parameters.avg_wait_of_same_past_second 
	+ 0.0471 * parameters.avg_latency_of_same_last_20 
	- 0.156 * parameters.max_latency_of_same_last_50 
	- 626927683.9805;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM5(work_wait &parameters) {
  double actual_remaining = 
	-0.0037 * parameters.work_so_far 
	- 0.0059 * parameters.wait_so_far 
	- 97282.9758 * parameters.num_locks_so_far 
	+ 28133.4329 * parameters.total_wait_locks 
	+ 0.007 * parameters.mean_wait_of_all 
	- 9501262.0466 * parameters.cpu_usage 
	+ 0.0297 * parameters.avg_work_of_same_past_second 
	- 0.0222 * parameters.avg_wait_of_same_past_second 
	+ 0.1996 * parameters.avg_latency_of_same_last_20 
	- 0.0047 * parameters.max_latency_of_same_last_50 
	+ 44628922.2347;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM6(work_wait &parameters) {
  double actual_remaining = 
	-0.0014 * parameters.work_so_far 
	- 0.1583 * parameters.wait_so_far 
	- 3536164.0674 * parameters.num_locks_so_far 
	+ 244952.3769 * parameters.total_wait_locks 
	+ 0.007 * parameters.mean_wait_of_all 
	- 669994.0522 * parameters.cpu_usage 
	+ 0.0261 * parameters.avg_work_of_same_past_second 
	- 0.2504 * parameters.avg_wait_of_same_past_second 
	+ 0.151 * parameters.avg_latency_of_same_last_20 
	- 0.002 * parameters.max_latency_of_same_last_50 
	+ 127222520.6647;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM7(work_wait &parameters) {
  double actual_remaining = 
	3.1979 * parameters.work_so_far 
	- 0.335 * parameters.wait_so_far 
	- 1601923.1207 * parameters.num_locks_so_far 
	+ 1211792.6095 * parameters.total_wait_locks 
	- 0.2173 * parameters.mean_wait_of_all 
	- 74982775.9119 * parameters.cpu_usage 
	- 0.1159 * parameters.avg_work_of_same_past_second 
	+ 4.4566 * parameters.avg_wait_of_same_past_second 
	+ 0.0102 * parameters.avg_latency_of_same_last_20 
	- 0.002 * parameters.max_latency_of_same_last_50 
	- 580052276.8609;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM8(work_wait &parameters) {
  double actual_remaining = 
	3.1979 * parameters.work_so_far 
	- 0.335 * parameters.wait_so_far 
	- 1601923.1207 * parameters.num_locks_so_far 
	+ 1507314.8111 * parameters.total_wait_locks 
	- 0.2173 * parameters.mean_wait_of_all 
	- 74982775.9119 * parameters.cpu_usage 
	- 0.1159 * parameters.avg_work_of_same_past_second 
	+ 3.6774 * parameters.avg_wait_of_same_past_second 
	+ 0.0102 * parameters.avg_latency_of_same_last_20 
	- 0.002 * parameters.max_latency_of_same_last_50 
	- 442327773.0207;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM9(work_wait &parameters) {
  double actual_remaining = 
	3.371 * parameters.work_so_far 
	- 0.335 * parameters.wait_so_far 
	- 1601923.1207 * parameters.num_locks_so_far 
	- 677742.498 * parameters.total_wait_locks 
	- 0.2173 * parameters.mean_wait_of_all 
	- 74982775.9119 * parameters.cpu_usage 
	- 0.1159 * parameters.avg_work_of_same_past_second 
	- 0.0238 * parameters.avg_wait_of_same_past_second 
	+ 0.0102 * parameters.avg_latency_of_same_last_20 
	- 0.002 * parameters.max_latency_of_same_last_50 
	+ 549264780.5474;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM10(work_wait &parameters) {
  double actual_remaining = 
	-12.6681 * parameters.work_so_far 
	- 0.5181 * parameters.wait_so_far 
	- 1601923.1207 * parameters.num_locks_so_far 
	- 718055.153 * parameters.total_wait_locks 
	- 0.2378 * parameters.mean_wait_of_all 
	- 74982775.9119 * parameters.cpu_usage 
	- 0.1159 * parameters.avg_work_of_same_past_second 
	- 0.0238 * parameters.avg_wait_of_same_past_second 
	+ 0.0102 * parameters.avg_latency_of_same_last_20 
	- 0.002 * parameters.max_latency_of_same_last_50 
	+ 582313999.9279;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM11(work_wait &parameters) {
  double actual_remaining = 
	1.0933 * parameters.work_so_far 
	- 0.4617 * parameters.wait_so_far 
	- 1601923.1207 * parameters.num_locks_so_far 
	- 718055.153 * parameters.total_wait_locks 
	- 0.2378 * parameters.mean_wait_of_all 
	- 74982775.9119 * parameters.cpu_usage 
	- 0.1159 * parameters.avg_work_of_same_past_second 
	- 0.0238 * parameters.avg_wait_of_same_past_second 
	+ 0.0102 * parameters.avg_latency_of_same_last_20 
	- 0.002 * parameters.max_latency_of_same_last_50 
	+ 542789755.7941;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM12(work_wait &parameters) {
  double actual_remaining = 
	-0.2235 * parameters.work_so_far 
	- 0.0424 * parameters.wait_so_far 
	- 6300100.2993 * parameters.num_locks_so_far 
	+ 27728.9637 * parameters.total_wait_locks 
	+ 0.4026 * parameters.mean_wait_of_all 
	- 317613400.412 * parameters.cpu_usage 
	- 0.5249 * parameters.avg_work_of_same_past_second 
	- 0.0238 * parameters.avg_wait_of_same_past_second 
	+ 0.0102 * parameters.avg_latency_of_same_last_20 
	- 0.002 * parameters.max_latency_of_same_last_50 
	+ 556847642.3389;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM13(work_wait &parameters) {
  double actual_remaining = 
	0.3441 * parameters.work_so_far 
	- 0.0038 * parameters.wait_so_far 
	- 123069.3473 * parameters.num_locks_so_far 
	+ 45511.7529 * parameters.total_wait_locks 
	+ 0.0088 * parameters.mean_wait_of_all 
	- 14466077.1748 * parameters.cpu_usage 
	+ 0.0139 * parameters.avg_work_of_same_past_second 
	- 0.0098 * parameters.avg_wait_of_same_past_second 
	+ 0.0119 * parameters.avg_latency_of_same_last_20 
	- 0.0016 * parameters.max_latency_of_same_last_50 
	+ 80145109.7504;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM14(work_wait &parameters) {
  double actual_remaining = 
	0.0491 * parameters.work_so_far 
	+ 0.1124 * parameters.wait_so_far 
	- 123069.3473 * parameters.num_locks_so_far 
	+ 71024.467 * parameters.total_wait_locks 
	- 2.0655 * parameters.mean_wait_of_all 
	- 14466077.1748 * parameters.cpu_usage 
	+ 1.0361 * parameters.avg_work_of_same_past_second 
	- 0.7788 * parameters.avg_wait_of_same_past_second 
	+ 0.0119 * parameters.avg_latency_of_same_last_20 
	- 0.0016 * parameters.max_latency_of_same_last_50 
	+ 185520943.5606;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM15(work_wait &parameters) {
  double actual_remaining = 
	0.0107 * parameters.work_so_far 
	- 0.0038 * parameters.wait_so_far 
	- 123069.3473 * parameters.num_locks_so_far 
	+ 21926.0088 * parameters.total_wait_locks 
	+ 0.0088 * parameters.mean_wait_of_all 
	- 16141714.8011 * parameters.cpu_usage 
	+ 0.0139 * parameters.avg_work_of_same_past_second 
	- 0.0098 * parameters.avg_wait_of_same_past_second 
	+ 0.0123 * parameters.avg_latency_of_same_last_20 
	- 0.0016 * parameters.max_latency_of_same_last_50 
	+ 73209908.9453;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM16(work_wait &parameters) {
  double actual_remaining = 
	0.2023 * parameters.work_so_far 
	- 0.0031 * parameters.wait_so_far 
	- 7666990.2766 * parameters.num_locks_so_far 
	+ 470782.9781 * parameters.total_wait_locks 
	+ 0.4307 * parameters.mean_wait_of_all 
	- 669994.0522 * parameters.cpu_usage 
	+ 0.0102 * parameters.avg_work_of_same_past_second 
	- 0.0078 * parameters.avg_wait_of_same_past_second 
	+ 0.129 * parameters.avg_latency_of_same_last_20 
	- 0.0635 * parameters.max_latency_of_same_last_50 
	+ 73808562.4468;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM17(work_wait &parameters) {
  double actual_remaining = 
	0.9678 * parameters.work_so_far 
	- 0.4181 * parameters.wait_so_far 
	- 6800103.993 * parameters.num_locks_so_far 
	+ 55512.9212 * parameters.total_wait_locks 
	- 12.2543 * parameters.mean_wait_of_all 
	- 2943448.546 * parameters.cpu_usage 
	+ 1.5209 * parameters.avg_work_of_same_past_second 
	- 1.1729 * parameters.avg_wait_of_same_past_second 
	+ 0.3557 * parameters.avg_latency_of_same_last_20 
	- 0.0848 * parameters.max_latency_of_same_last_50 
	+ 1275531187.0236;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM18(work_wait &parameters) {
  double actual_remaining = 
	0.3852 * parameters.work_so_far 
	- 0.3716 * parameters.wait_so_far 
	- 5455463.7477 * parameters.num_locks_so_far 
	+ 1581398.5038 * parameters.total_wait_locks 
	- 7.0032 * parameters.mean_wait_of_all 
	- 2943448.546 * parameters.cpu_usage 
	+ 0.002 * parameters.avg_work_of_same_past_second 
	- 0.0043 * parameters.avg_wait_of_same_past_second 
	+ 0.0043 * parameters.avg_latency_of_same_last_20 
	- 0.0008 * parameters.max_latency_of_same_last_50 
	+ 387620924.8867;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM19(work_wait &parameters) {
  double actual_remaining = 
	0.0018 * parameters.work_so_far 
	- 0.0585 * parameters.wait_so_far 
	- 3843486.8917 * parameters.num_locks_so_far 
	+ 7601.3013 * parameters.total_wait_locks 
	- 0.0392 * parameters.mean_wait_of_all 
	- 339290450.7904 * parameters.cpu_usage 
	+ 0.002 * parameters.avg_work_of_same_past_second 
	- 0.001 * parameters.avg_wait_of_same_past_second 
	+ 0.2061 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 441145591.7065;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM20(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	- 0.344 * parameters.wait_so_far 
	- 51402.5237 * parameters.num_locks_so_far 
	- 1298037.8405 * parameters.total_wait_locks 
	+ 8.2326 * parameters.mean_wait_of_all 
	- 828116.72 * parameters.cpu_usage 
	+ 0.0042 * parameters.avg_work_of_same_past_second 
	+ 0.1436 * parameters.avg_wait_of_same_past_second 
	+ 0.0034 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	- 25069293.3832;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM21(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	- 0.1814 * parameters.wait_so_far 
	- 66602.3605 * parameters.num_locks_so_far 
	- 842320.0696 * parameters.total_wait_locks 
	+ 3.1501 * parameters.mean_wait_of_all 
	- 828116.72 * parameters.cpu_usage 
	+ 0.3998 * parameters.avg_work_of_same_past_second 
	- 0.4802 * parameters.avg_wait_of_same_past_second 
	+ 0.0049 * parameters.avg_latency_of_same_last_20 
	- 0.0601 * parameters.max_latency_of_same_last_50 
	+ 654224993.6351;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM22(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	- 0.0765 * parameters.wait_so_far 
	- 6744619.1769 * parameters.num_locks_so_far 
	- 7925.1206 * parameters.total_wait_locks 
	- 1.8337 * parameters.mean_wait_of_all 
	- 828116.72 * parameters.cpu_usage 
	+ 0.3423 * parameters.avg_work_of_same_past_second 
	- 0.3619 * parameters.avg_wait_of_same_past_second 
	+ 0.1305 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 522391867.6369;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
new_order_estimate(work_wait &parameters){

  if (parameters.total_wait_locks <= 275.5) {

    if (parameters.avg_latency_of_same_last_20 <= 113155000) {

      if (parameters.work_so_far <= 25347) {
        return new_order_LM1(parameters);
      } else {
        return new_order_LM2(parameters);
      }
    } else {

      if (parameters.wait_so_far <= 154735172) {
        return new_order_LM3(parameters);
      } else {

        if (parameters.max_latency_of_same_last_50 <= 1193015000) {

          if (parameters.wait_so_far <= 459237003) {

            if (parameters.work_so_far <= 50306) {

              if (parameters.cpu_usage <= 0.938) {
                return new_order_LM4(parameters);
              } else {
                return new_order_LM5(parameters);
              }
            } else {

              if (parameters.avg_work_of_same_past_second <= 156892000) {
                return new_order_LM6(parameters);
              } else {

                if (parameters.avg_latency_of_same_last_20 <= 235691000) {

                  if (parameters.total_wait_locks <= 235) {

                    if (parameters.avg_wait_of_same_past_second <= 217198000) {

                      if (parameters.avg_wait_of_same_past_second <= 173601500) {
                        return new_order_LM7(parameters);
                      } else {
                        return new_order_LM8(parameters);
                      }
                    } else {
                      return new_order_LM9(parameters);
                    }
                  } else {

                    if (parameters.wait_so_far <= 248916098.5) {
                      return new_order_LM10(parameters);
                    } else {
                      return new_order_LM11(parameters);
                    }
                  }
                } else {
                  return new_order_LM12(parameters);
                }
              }
            }
          } else {

            if (parameters.cpu_usage <= 0.99) {

              if (parameters.total_wait_locks <= 240.5) {
                return new_order_LM13(parameters);
              } else {
                return new_order_LM14(parameters);
              }
            } else {
              return new_order_LM15(parameters);
            }
          }
        } else {
          return new_order_LM16(parameters);
        }
      }
    }
  } else {

    if (parameters.mean_wait_of_all <= 100481500) {

      if (parameters.wait_so_far <= 209992124) {

        if (parameters.avg_wait_of_same_past_second <= 162244000) {
          return new_order_LM17(parameters);
        } else {
          return new_order_LM18(parameters);
        }
      } else {
        return new_order_LM19(parameters);
      }
    } else {

      if (parameters.wait_so_far <= 500536641) {

        if (parameters.avg_latency_of_same_last_20 <= 530001500) {
          return new_order_LM20(parameters);
        } else {
          return new_order_LM21(parameters);
        }
      } else {
        return new_order_LM22(parameters);
      }
    }
  }
}
static
double
payment_LM1(work_wait &parameters) {
  double actual_remaining = 
	7.3417 * parameters.work_so_far 
	+ 0.0007 * parameters.wait_so_far 
	+ 158.5231 * parameters.total_wait_locks 
	- 0.0003 * parameters.mean_wait_of_all 
	- 369640.635 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 5108485.5695;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM2(work_wait &parameters) {
  double actual_remaining = 
	21.579 * parameters.work_so_far 
	+ 0.0007 * parameters.wait_so_far 
	+ 158.5231 * parameters.total_wait_locks 
	- 0.0003 * parameters.mean_wait_of_all 
	- 369640.635 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 5743403.443;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM3(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	+ 0.0041 * parameters.wait_so_far 
	+ 11895.9738 * parameters.total_wait_locks 
	- 0.0003 * parameters.mean_wait_of_all 
	- 369640.635 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0086 * parameters.avg_latency_of_same_last_20 
	- 0.0064 * parameters.max_latency_of_same_last_50 
	+ 6253985.3922;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM4(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	+ 0.007 * parameters.wait_so_far 
	+ 158.5231 * parameters.total_wait_locks 
	- 0.0003 * parameters.mean_wait_of_all 
	+ 8392243.6881 * parameters.cpu_usage 
	- 0.0497 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0776 * parameters.avg_latency_of_same_last_20 
	- 0.0222 * parameters.max_latency_of_same_last_50 
	+ 1561171.8076;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM5(work_wait &parameters) {
  double actual_remaining = 
	1008.3812 * parameters.work_so_far 
	+ 0.007 * parameters.wait_so_far 
	+ 158.5231 * parameters.total_wait_locks 
	- 0.0003 * parameters.mean_wait_of_all 
	- 369640.635 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0495 * parameters.avg_latency_of_same_last_20 
	- 0.0247 * parameters.max_latency_of_same_last_50 
	+ 16551299.294;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM6(work_wait &parameters) {
  double actual_remaining = 
	-179.285 * parameters.work_so_far 
	+ 0.007 * parameters.wait_so_far 
	+ 14428.5636 * parameters.total_wait_locks 
	- 0.0003 * parameters.mean_wait_of_all 
	- 369640.635 * parameters.cpu_usage 
	+ 0.1933 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0495 * parameters.avg_latency_of_same_last_20 
	- 0.0247 * parameters.max_latency_of_same_last_50 
	+ 16782502.9827;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM7(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	+ 0.007 * parameters.wait_so_far 
	+ 13239.3936 * parameters.total_wait_locks 
	- 0.0003 * parameters.mean_wait_of_all 
	- 369640.635 * parameters.cpu_usage 
	+ 0.238 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0495 * parameters.avg_latency_of_same_last_20 
	- 0.0247 * parameters.max_latency_of_same_last_50 
	+ 15905195.996;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM8(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	+ 0.007 * parameters.wait_so_far 
	+ 13239.3936 * parameters.total_wait_locks 
	- 0.0003 * parameters.mean_wait_of_all 
	- 369640.635 * parameters.cpu_usage 
	+ 0.2412 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0495 * parameters.avg_latency_of_same_last_20 
	- 0.0247 * parameters.max_latency_of_same_last_50 
	+ 16314311.8851;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM9(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	+ 0.007 * parameters.wait_so_far 
	+ 158.5231 * parameters.total_wait_locks 
	- 0.0003 * parameters.mean_wait_of_all 
	- 369640.635 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0495 * parameters.avg_latency_of_same_last_20 
	- 0.0247 * parameters.max_latency_of_same_last_50 
	+ 17605951.6401;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM10(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	+ 0.007 * parameters.wait_so_far 
	+ 158.5231 * parameters.total_wait_locks 
	- 0.0003 * parameters.mean_wait_of_all 
	- 369640.635 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0495 * parameters.avg_latency_of_same_last_20 
	- 0.0279 * parameters.max_latency_of_same_last_50 
	+ 14106773.4118;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM11(work_wait &parameters) {
  double actual_remaining = 
	0.0457 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 775.8566 * parameters.total_wait_locks 
	- 0.0006 * parameters.mean_wait_of_all 
	- 523392.8078 * parameters.cpu_usage 
	+ 0.0708 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0658 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 3792644.4854;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM12(work_wait &parameters) {
  double actual_remaining = 
	1344.6692 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 412.7083 * parameters.total_wait_locks 
	- 0.0006 * parameters.mean_wait_of_all 
	- 523392.8078 * parameters.cpu_usage 
	- 0.0189 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0064 * parameters.avg_latency_of_same_last_20 
	- 0.002 * parameters.max_latency_of_same_last_50 
	- 4110831.8942;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM13(work_wait &parameters) {
  double actual_remaining = 
	14989.9859 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 412.7083 * parameters.total_wait_locks 
	- 0.0006 * parameters.mean_wait_of_all 
	- 523392.8078 * parameters.cpu_usage 
	- 0.0189 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0064 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	- 108387708.2494;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM14(work_wait &parameters) {
  double actual_remaining = 
	17635.2481 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 412.7083 * parameters.total_wait_locks 
	- 0.0006 * parameters.mean_wait_of_all 
	- 523392.8078 * parameters.cpu_usage 
	- 0.0189 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0064 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	- 127699974.4481;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM15(work_wait &parameters) {
  double actual_remaining = 
	11443.2538 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 412.7083 * parameters.total_wait_locks 
	- 0.0006 * parameters.mean_wait_of_all 
	- 523392.8078 * parameters.cpu_usage 
	- 0.0189 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0064 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	- 79088515.002;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM16(work_wait &parameters) {
  double actual_remaining = 
	0.1671 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 3555.8355 * parameters.total_wait_locks 
	- 0.0006 * parameters.mean_wait_of_all 
	- 523392.8078 * parameters.cpu_usage 
	- 0.0189 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0064 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 7957194.0543;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM17(work_wait &parameters) {
  double actual_remaining = 
	0.1671 * parameters.work_so_far 
	+ 0.0123 * parameters.wait_so_far 
	+ 412.7083 * parameters.total_wait_locks 
	- 0.0006 * parameters.mean_wait_of_all 
	- 523392.8078 * parameters.cpu_usage 
	- 0.0189 * parameters.avg_work_of_same_past_second 
	+ 0.0015 * parameters.avg_wait_of_same_past_second 
	+ 0.0064 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 5997111.9565;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM18(work_wait &parameters) {
  double actual_remaining = 
	0.1671 * parameters.work_so_far 
	+ 0.0275 * parameters.wait_so_far 
	+ 15604.3756 * parameters.total_wait_locks 
	- 0.0006 * parameters.mean_wait_of_all 
	- 523392.8078 * parameters.cpu_usage 
	- 0.0189 * parameters.avg_work_of_same_past_second 
	+ 0.0161 * parameters.avg_wait_of_same_past_second 
	+ 0.0064 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 2570483.4383;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM19(work_wait &parameters) {
  double actual_remaining = 
	1.3401 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 412.7083 * parameters.total_wait_locks 
	- 0.0278 * parameters.mean_wait_of_all 
	- 20221437.1532 * parameters.cpu_usage 
	- 0.0296 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0067 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 29956988.7266;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM20(work_wait &parameters) {
  double actual_remaining = 
	1.3401 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 412.7083 * parameters.total_wait_locks 
	- 0.0278 * parameters.mean_wait_of_all 
	- 91015789.2643 * parameters.cpu_usage 
	- 0.0296 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0067 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 97186552.6896;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM21(work_wait &parameters) {
  double actual_remaining = 
	1.3401 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 412.7083 * parameters.total_wait_locks 
	- 0.0278 * parameters.mean_wait_of_all 
	- 177807885.6573 * parameters.cpu_usage 
	- 0.0296 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.197 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 187688208.5455;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM22(work_wait &parameters) {
  double actual_remaining = 
	-461.9227 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 48812.7978 * parameters.total_wait_locks 
	- 0.0132 * parameters.mean_wait_of_all 
	- 523392.8078 * parameters.cpu_usage 
	+ 1.3053 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0067 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 12418573.007;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM23(work_wait &parameters) {
  double actual_remaining = 
	-461.9227 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 176675.8617 * parameters.total_wait_locks 
	+ 0.0608 * parameters.mean_wait_of_all 
	- 48518022.0577 * parameters.cpu_usage 
	+ 1.1212 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0067 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 44670639.0324;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM24(work_wait &parameters) {
  double actual_remaining = 
	-461.9227 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 138398.8182 * parameters.total_wait_locks 
	+ 0.0608 * parameters.mean_wait_of_all 
	- 48518022.0577 * parameters.cpu_usage 
	+ 1.4734 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0067 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 44146270.0846;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM25(work_wait &parameters) {
  double actual_remaining = 
	-461.9227 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 121934.2964 * parameters.total_wait_locks 
	+ 0.2107 * parameters.mean_wait_of_all 
	- 69087148.8791 * parameters.cpu_usage 
	+ 3.5576 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0067 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 44251338.4027;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM26(work_wait &parameters) {
  double actual_remaining = 
	-461.9227 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 121934.2964 * parameters.total_wait_locks 
	+ 0.2107 * parameters.mean_wait_of_all 
	- 69087148.8791 * parameters.cpu_usage 
	+ 3.5576 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0067 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 44952348.2812;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM27(work_wait &parameters) {
  double actual_remaining = 
	-484.5669 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 48812.7978 * parameters.total_wait_locks 
	- 0.0132 * parameters.mean_wait_of_all 
	- 523392.8078 * parameters.cpu_usage 
	+ 1.3704 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0067 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 9622947.9156;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM28(work_wait &parameters) {
  double actual_remaining = 
	4.8955 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 341238.645 * parameters.total_wait_locks 
	- 0.0132 * parameters.mean_wait_of_all 
	- 523392.8078 * parameters.cpu_usage 
	- 7.0285 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0067 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 46667688.0887;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM29(work_wait &parameters) {
  double actual_remaining = 
	1.6073 * parameters.work_so_far 
	+ 0.2668 * parameters.wait_so_far 
	+ 412.7083 * parameters.total_wait_locks 
	- 0.0132 * parameters.mean_wait_of_all 
	- 523392.8078 * parameters.cpu_usage 
	- 0.0296 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0067 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 12134628.5958;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM30(work_wait &parameters) {
  double actual_remaining = 
	0.1604 * parameters.work_so_far 
	+ 0.0809 * parameters.wait_so_far 
	+ 1840.7693 * parameters.total_wait_locks 
	- 0.0006 * parameters.mean_wait_of_all 
	- 523392.8078 * parameters.cpu_usage 
	- 0.0145 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0738 * parameters.avg_latency_of_same_last_20 
	- 0.0057 * parameters.max_latency_of_same_last_50 
	+ 5109620.7702;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM31(work_wait &parameters) {
  double actual_remaining = 
	0.3032 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 127651.6055 * parameters.total_wait_locks 
	- 0.5686 * parameters.mean_wait_of_all 
	- 523392.8078 * parameters.cpu_usage 
	- 0.0145 * parameters.avg_work_of_same_past_second 
	+ 0.0109 * parameters.avg_wait_of_same_past_second 
	- 0.1094 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 38955242.2643;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM32(work_wait &parameters) {
  double actual_remaining = 
	0.3032 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 149699.5862 * parameters.total_wait_locks 
	- 0.5686 * parameters.mean_wait_of_all 
	- 523392.8078 * parameters.cpu_usage 
	- 0.0145 * parameters.avg_work_of_same_past_second 
	+ 0.0194 * parameters.avg_wait_of_same_past_second 
	- 0.1094 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 34897897.6327;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM33(work_wait &parameters) {
  double actual_remaining = 
	-10.1601 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 98196.9794 * parameters.total_wait_locks 
	- 0.4361 * parameters.mean_wait_of_all 
	- 523392.8078 * parameters.cpu_usage 
	- 0.6803 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.4163 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 75620807.3091;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM34(work_wait &parameters) {
  double actual_remaining = 
	-10.1601 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 98196.9794 * parameters.total_wait_locks 
	- 0.4361 * parameters.mean_wait_of_all 
	- 523392.8078 * parameters.cpu_usage 
	- 0.6803 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.3569 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 63877843.8355;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM35(work_wait &parameters) {
  double actual_remaining = 
	-13.7569 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 98196.9794 * parameters.total_wait_locks 
	- 0.4361 * parameters.mean_wait_of_all 
	- 523392.8078 * parameters.cpu_usage 
	- 0.9092 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.2458 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 58165103.0035;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM36(work_wait &parameters) {
  double actual_remaining = 
	0.2784 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 1417.4936 * parameters.total_wait_locks 
	- 0.0006 * parameters.mean_wait_of_all 
	- 3293903.0655 * parameters.cpu_usage 
	- 0.0145 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.008 * parameters.avg_latency_of_same_last_20 
	- 0.0049 * parameters.max_latency_of_same_last_50 
	+ 14043589.8936;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM37(work_wait &parameters) {
  double actual_remaining = 
	1.0852 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	+ 1417.4936 * parameters.total_wait_locks 
	- 0.0006 * parameters.mean_wait_of_all 
	- 59285936.1929 * parameters.cpu_usage 
	- 0.0145 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.1085 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 59537523.9039;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM38(work_wait &parameters) {
  double actual_remaining = 
	0.0051 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 170.2604 * parameters.total_wait_locks 
	- 0.1049 * parameters.mean_wait_of_all 
	- 2048021.2734 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0082 * parameters.avg_latency_of_same_last_20 
	- 0.0011 * parameters.max_latency_of_same_last_50 
	+ 22284015.0198;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM39(work_wait &parameters) {
  double actual_remaining = 
	0.0051 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	+ 170.2604 * parameters.total_wait_locks 
	- 3.6921 * parameters.mean_wait_of_all 
	+ 189891658.784 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.015 * parameters.avg_latency_of_same_last_20 
	- 0.0527 * parameters.max_latency_of_same_last_50 
	+ 100891927.4946;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM40(work_wait &parameters) {
  double actual_remaining = 
	0.1101 * parameters.work_so_far 
	+ 0.0076 * parameters.wait_so_far 
	+ 16663.2778 * parameters.total_wait_locks 
	- 0.001 * parameters.mean_wait_of_all 
	- 69269075.8036 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	+ 0.0042 * parameters.max_latency_of_same_last_50 
	+ 73516509.4875;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM41(work_wait &parameters) {
  double actual_remaining = 
	0.0029 * parameters.work_so_far 
	+ 1.645 * parameters.wait_so_far 
	+ 5532.8761 * parameters.total_wait_locks 
	+ 0.0011 * parameters.mean_wait_of_all 
	- 68539886.6274 * parameters.cpu_usage 
	+ 0.2718 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	+ 0.0618 * parameters.max_latency_of_same_last_50 
	+ 32050200.6328;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM42(work_wait &parameters) {
  double actual_remaining = 
	0.0029 * parameters.work_so_far 
	+ 1.645 * parameters.wait_so_far 
	+ 5532.8761 * parameters.total_wait_locks 
	+ 0.0011 * parameters.mean_wait_of_all 
	- 63425373.8606 * parameters.cpu_usage 
	+ 0.2718 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0035 * parameters.max_latency_of_same_last_50 
	+ 52096786.237;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM43(work_wait &parameters) {
  double actual_remaining = 
	0.0029 * parameters.work_so_far 
	+ 8.4598 * parameters.wait_so_far 
	+ 5532.8761 * parameters.total_wait_locks 
	+ 0.0011 * parameters.mean_wait_of_all 
	- 7165733.4252 * parameters.cpu_usage 
	+ 0.3829 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0035 * parameters.max_latency_of_same_last_50 
	- 23998324.3526;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM44(work_wait &parameters) {
  double actual_remaining = 
	0.0029 * parameters.work_so_far 
	+ 0.0599 * parameters.wait_so_far 
	+ 70530.8401 * parameters.total_wait_locks 
	+ 0.0011 * parameters.mean_wait_of_all 
	- 7165733.4252 * parameters.cpu_usage 
	- 0.057 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0035 * parameters.max_latency_of_same_last_50 
	+ 14160934.4056;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM45(work_wait &parameters) {
  double actual_remaining = 
	0.0165 * parameters.work_so_far 
	+ 0.0037 * parameters.wait_so_far 
	+ 6416.7594 * parameters.total_wait_locks 
	+ 0.0076 * parameters.mean_wait_of_all 
	- 2483564.8561 * parameters.cpu_usage 
	+ 0.2156 * parameters.avg_work_of_same_past_second 
	- 0.0289 * parameters.avg_wait_of_same_past_second 
	+ 0.0058 * parameters.avg_latency_of_same_last_20 
	+ 0.0282 * parameters.max_latency_of_same_last_50 
	- 6166634.1403;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM46(work_wait &parameters) {
  double actual_remaining = 
	0.0951 * parameters.work_so_far 
	+ 0.0066 * parameters.wait_so_far 
	+ 73467.0766 * parameters.total_wait_locks 
	+ 0.0743 * parameters.mean_wait_of_all 
	- 37725775.0169 * parameters.cpu_usage 
	- 0.1886 * parameters.avg_work_of_same_past_second 
	- 0.0247 * parameters.avg_wait_of_same_past_second 
	+ 0.0027 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	+ 39301684.5865;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM47(work_wait &parameters) {
  double actual_remaining = 
	235.6159 * parameters.work_so_far 
	+ 0.0479 * parameters.wait_so_far 
	+ 146710.1873 * parameters.total_wait_locks 
	+ 0.1966 * parameters.mean_wait_of_all 
	- 17073364.5898 * parameters.cpu_usage 
	- 0.1002 * parameters.avg_work_of_same_past_second 
	- 0.1689 * parameters.avg_wait_of_same_past_second 
	+ 0.0027 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	+ 25948629.1325;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM48(work_wait &parameters) {
  double actual_remaining = 
	184.4095 * parameters.work_so_far 
	+ 0.065 * parameters.wait_so_far 
	+ 146710.1873 * parameters.total_wait_locks 
	+ 0.1966 * parameters.mean_wait_of_all 
	- 17073364.5898 * parameters.cpu_usage 
	- 0.1002 * parameters.avg_work_of_same_past_second 
	- 0.1689 * parameters.avg_wait_of_same_past_second 
	+ 0.0027 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	+ 28867367.267;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM49(work_wait &parameters) {
  double actual_remaining = 
	0.0668 * parameters.work_so_far 
	+ 0.0066 * parameters.wait_so_far 
	+ 140194.616 * parameters.total_wait_locks 
	+ 0.1966 * parameters.mean_wait_of_all 
	- 17073364.5898 * parameters.cpu_usage 
	- 0.1002 * parameters.avg_work_of_same_past_second 
	- 0.1608 * parameters.avg_wait_of_same_past_second 
	+ 0.0027 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	+ 20519514.3238;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM50(work_wait &parameters) {
  double actual_remaining = 
	0.0668 * parameters.work_so_far 
	+ 0.0066 * parameters.wait_so_far 
	+ 140194.616 * parameters.total_wait_locks 
	+ 0.1966 * parameters.mean_wait_of_all 
	- 17073364.5898 * parameters.cpu_usage 
	- 0.1002 * parameters.avg_work_of_same_past_second 
	- 0.1608 * parameters.avg_wait_of_same_past_second 
	+ 0.0027 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	+ 21935257.1826;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM51(work_wait &parameters) {
  double actual_remaining = 
	0.0184 * parameters.work_so_far 
	+ 0.0048 * parameters.wait_so_far 
	+ 26528.0354 * parameters.total_wait_locks 
	+ 0.0041 * parameters.mean_wait_of_all 
	- 2483564.8561 * parameters.cpu_usage 
	- 0.1751 * parameters.avg_work_of_same_past_second 
	- 0.005 * parameters.avg_wait_of_same_past_second 
	+ 0.0527 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	+ 5799171.4532;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM52(work_wait &parameters) {
  double actual_remaining = 
	0.0012 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 145.9357 * parameters.total_wait_locks 
	+ 0.0007 * parameters.mean_wait_of_all 
	- 281293.3459 * parameters.cpu_usage 
	+ 0.0725 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0128 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 14408273.2677;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM53(work_wait &parameters) {
  double actual_remaining = 
	0.0012 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 245.0796 * parameters.total_wait_locks 
	+ 0.0012 * parameters.mean_wait_of_all 
	- 281293.3459 * parameters.cpu_usage 
	+ 0.0028 * parameters.avg_work_of_same_past_second 
	+ 0.005 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 17025986.0356;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM54(work_wait &parameters) {
  double actual_remaining = 
	0.0012 * parameters.work_so_far 
	- 0.0115 * parameters.wait_so_far 
	- 245.0796 * parameters.total_wait_locks 
	+ 0.0012 * parameters.mean_wait_of_all 
	- 65793563.7327 * parameters.cpu_usage 
	+ 0.0028 * parameters.avg_work_of_same_past_second 
	+ 0.0156 * parameters.avg_wait_of_same_past_second 
	+ 0.0574 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 78964852.8371;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM55(work_wait &parameters) {
  double actual_remaining = 
	0.0012 * parameters.work_so_far 
	- 0.011 * parameters.wait_so_far 
	- 245.0796 * parameters.total_wait_locks 
	+ 0.0012 * parameters.mean_wait_of_all 
	- 65793563.7327 * parameters.cpu_usage 
	+ 0.0028 * parameters.avg_work_of_same_past_second 
	+ 0.0156 * parameters.avg_wait_of_same_past_second 
	+ 0.0574 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 79006076.0584;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM56(work_wait &parameters) {
  double actual_remaining = 
	0.0012 * parameters.work_so_far 
	- 0.0224 * parameters.wait_so_far 
	- 245.0796 * parameters.total_wait_locks 
	+ 0.0012 * parameters.mean_wait_of_all 
	- 65793563.7327 * parameters.cpu_usage 
	+ 0.0028 * parameters.avg_work_of_same_past_second 
	+ 0.0156 * parameters.avg_wait_of_same_past_second 
	+ 0.0631 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 80023685.7078;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM57(work_wait &parameters) {
  double actual_remaining = 
	0.0012 * parameters.work_so_far 
	- 0.0228 * parameters.wait_so_far 
	- 245.0796 * parameters.total_wait_locks 
	+ 0.0012 * parameters.mean_wait_of_all 
	- 65793563.7327 * parameters.cpu_usage 
	+ 0.0028 * parameters.avg_work_of_same_past_second 
	+ 0.0156 * parameters.avg_wait_of_same_past_second 
	+ 0.0631 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 79934307.9084;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM58(work_wait &parameters) {
  double actual_remaining = 
	0.0012 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 33730.6733 * parameters.total_wait_locks 
	+ 0.2933 * parameters.mean_wait_of_all 
	- 65793563.7327 * parameters.cpu_usage 
	+ 0.0028 * parameters.avg_work_of_same_past_second 
	+ 0.0156 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	- 0.0741 * parameters.max_latency_of_same_last_50 
	+ 135195603.7609;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM59(work_wait &parameters) {
  double actual_remaining = 
	0.0012 * parameters.work_so_far 
	+ 0.0506 * parameters.wait_so_far 
	+ 19038.4559 * parameters.total_wait_locks 
	+ 0.2584 * parameters.mean_wait_of_all 
	- 65793563.7327 * parameters.cpu_usage 
	+ 0.0028 * parameters.avg_work_of_same_past_second 
	+ 0.0156 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	- 0.0421 * parameters.max_latency_of_same_last_50 
	+ 96353485.7685;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM60(work_wait &parameters) {
  double actual_remaining = 
	0.0012 * parameters.work_so_far 
	+ 0.1418 * parameters.wait_so_far 
	+ 19038.4559 * parameters.total_wait_locks 
	+ 0.2736 * parameters.mean_wait_of_all 
	- 65793563.7327 * parameters.cpu_usage 
	+ 0.0028 * parameters.avg_work_of_same_past_second 
	+ 0.0156 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	- 0.0421 * parameters.max_latency_of_same_last_50 
	+ 90078653.7966;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM61(work_wait &parameters) {
  double actual_remaining = 
	0.0012 * parameters.work_so_far 
	+ 0.1376 * parameters.wait_so_far 
	+ 19038.4559 * parameters.total_wait_locks 
	+ 0.2736 * parameters.mean_wait_of_all 
	- 65793563.7327 * parameters.cpu_usage 
	+ 0.0028 * parameters.avg_work_of_same_past_second 
	+ 0.0156 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	- 0.0421 * parameters.max_latency_of_same_last_50 
	+ 92960502.1012;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM62(work_wait &parameters) {
  double actual_remaining = 
	0.0012 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 245.0796 * parameters.total_wait_locks 
	+ 0.0012 * parameters.mean_wait_of_all 
	- 100369484.2146 * parameters.cpu_usage 
	+ 0.0028 * parameters.avg_work_of_same_past_second 
	+ 0.0156 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	- 0.0128 * parameters.max_latency_of_same_last_50 
	+ 129579390.3207;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM63(work_wait &parameters) {
  double actual_remaining = 
	0.1273 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 18121.0297 * parameters.total_wait_locks 
	+ 0.0012 * parameters.mean_wait_of_all 
	- 8989351.58 * parameters.cpu_usage 
	- 0.0232 * parameters.avg_work_of_same_past_second 
	+ 0.0105 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	- 0.0385 * parameters.max_latency_of_same_last_50 
	+ 69700161.5803;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM64(work_wait &parameters) {
  double actual_remaining = 
	0.1273 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 116585.8056 * parameters.total_wait_locks 
	+ 0.5986 * parameters.mean_wait_of_all 
	- 9081087.1029 * parameters.cpu_usage 
	+ 2.4994 * parameters.avg_work_of_same_past_second 
	+ 0.0105 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	- 0.0028 * parameters.max_latency_of_same_last_50 
	- 38896537.0905;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM65(work_wait &parameters) {
  double actual_remaining = 
	0.1273 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 192636.2078 * parameters.total_wait_locks 
	+ 1.0611 * parameters.mean_wait_of_all 
	- 9081087.1029 * parameters.cpu_usage 
	+ 0.3053 * parameters.avg_work_of_same_past_second 
	+ 0.0105 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	- 0.0235 * parameters.max_latency_of_same_last_50 
	+ 22953069.108;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM66(work_wait &parameters) {
  double actual_remaining = 
	0.1273 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 130847.7827 * parameters.total_wait_locks 
	+ 0.7033 * parameters.mean_wait_of_all 
	- 9081087.1029 * parameters.cpu_usage 
	- 0.0234 * parameters.avg_work_of_same_past_second 
	+ 0.0105 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	- 0.0028 * parameters.max_latency_of_same_last_50 
	+ 14690058.8805;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM67(work_wait &parameters) {
  double actual_remaining = 
	2.5404 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 22184.057 * parameters.total_wait_locks 
	+ 0.1011 * parameters.mean_wait_of_all 
	- 11828733.0377 * parameters.cpu_usage 
	- 0.0361 * parameters.avg_work_of_same_past_second 
	+ 0.0186 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 8233909.3572;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM68(work_wait &parameters) {
  double actual_remaining = 
	5.6156 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 20581.9758 * parameters.total_wait_locks 
	+ 0.0939 * parameters.mean_wait_of_all 
	- 11828733.0377 * parameters.cpu_usage 
	- 0.0361 * parameters.avg_work_of_same_past_second 
	+ 0.0186 * parameters.avg_wait_of_same_past_second 
	+ 0.1049 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 12752546.1007;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM69(work_wait &parameters) {
  double actual_remaining = 
	-3383.706 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 47337.0179 * parameters.total_wait_locks 
	+ 1.5839 * parameters.mean_wait_of_all 
	+ 15585979.4566 * parameters.cpu_usage 
	- 3.2379 * parameters.avg_work_of_same_past_second 
	+ 0.0036 * parameters.avg_wait_of_same_past_second 
	+ 0.1989 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 88524172.4792;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM70(work_wait &parameters) {
  double actual_remaining = 
	0.0012 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 47337.0179 * parameters.total_wait_locks 
	+ 0.87 * parameters.mean_wait_of_all 
	+ 15585979.4566 * parameters.cpu_usage 
	+ 0.0028 * parameters.avg_work_of_same_past_second 
	+ 0.0036 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 91226231.4648;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM71(work_wait &parameters) {
  double actual_remaining = 
	-1.6413 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 52768.1254 * parameters.total_wait_locks 
	- 0.7366 * parameters.mean_wait_of_all 
	+ 17452717.4334 * parameters.cpu_usage 
	+ 0.0028 * parameters.avg_work_of_same_past_second 
	+ 0.1172 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 89257269.4767;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM72(work_wait &parameters) {
  double actual_remaining = 
	0.0019 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 154.5602 * parameters.total_wait_locks 
	+ 0.0005 * parameters.mean_wait_of_all 
	- 150417.9894 * parameters.cpu_usage 
	+ 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0142 * parameters.avg_latency_of_same_last_20 
	+ 0.0001 * parameters.max_latency_of_same_last_50 
	+ 23884917.4587;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM73(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 127408.8525 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	+ 494710405.3229 * parameters.cpu_usage 
	+ 1.3978 * parameters.avg_work_of_same_past_second 
	- 0.152 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 447319301.7568;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM74(work_wait &parameters) {
  double actual_remaining = 
	0.1328 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 73860.215 * parameters.total_wait_locks 
	+ 0.1481 * parameters.mean_wait_of_all 
	+ 253846944.5168 * parameters.cpu_usage 
	- 0.0799 * parameters.avg_work_of_same_past_second 
	+ 0.0055 * parameters.avg_wait_of_same_past_second 
	+ 0.0022 * parameters.avg_latency_of_same_last_20 
	- 0.0027 * parameters.max_latency_of_same_last_50 
	- 223735019.0445;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM75(work_wait &parameters) {
  double actual_remaining = 
	0.0038 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 137112.0362 * parameters.total_wait_locks 
	+ 0.4529 * parameters.mean_wait_of_all 
	- 90663965.4444 * parameters.cpu_usage 
	- 0.279 * parameters.avg_work_of_same_past_second 
	+ 0.0253 * parameters.avg_wait_of_same_past_second 
	+ 0.0022 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	+ 100065283.691;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM76(work_wait &parameters) {
  double actual_remaining = 
	-0.0505 * parameters.work_so_far 
	+ 0.0873 * parameters.wait_so_far 
	- 154955.3069 * parameters.total_wait_locks 
	- 0.4155 * parameters.mean_wait_of_all 
	- 43409021.8076 * parameters.cpu_usage 
	- 0.0929 * parameters.avg_work_of_same_past_second 
	+ 0.0063 * parameters.avg_wait_of_same_past_second 
	- 0.0448 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 140901041.9173;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM77(work_wait &parameters) {
  double actual_remaining = 
	-0.0505 * parameters.work_so_far 
	+ 0.101 * parameters.wait_so_far 
	- 185508.5602 * parameters.total_wait_locks 
	- 0.4155 * parameters.mean_wait_of_all 
	- 43409021.8076 * parameters.cpu_usage 
	- 0.1031 * parameters.avg_work_of_same_past_second 
	+ 0.0063 * parameters.avg_wait_of_same_past_second 
	- 0.0448 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 149146275.5969;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM78(work_wait &parameters) {
  double actual_remaining = 
	-0.0257 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 148047.0257 * parameters.total_wait_locks 
	- 1.3305 * parameters.mean_wait_of_all 
	- 43409021.8076 * parameters.cpu_usage 
	- 0.3291 * parameters.avg_work_of_same_past_second 
	+ 0.0403 * parameters.avg_wait_of_same_past_second 
	- 0.0949 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 174960746.7321;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM79(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 31161.6588 * parameters.total_wait_locks 
	- 0.002 * parameters.mean_wait_of_all 
	- 79577367.0584 * parameters.cpu_usage 
	+ 0.0004 * parameters.avg_work_of_same_past_second 
	+ 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0062 * parameters.max_latency_of_same_last_50 
	+ 94836171.2807;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM80(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0228 * parameters.wait_so_far 
	+ 190.4632 * parameters.total_wait_locks 
	- 0.7165 * parameters.mean_wait_of_all 
	- 4871165.1946 * parameters.cpu_usage 
	+ 0.0004 * parameters.avg_work_of_same_past_second 
	+ 0.0008 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 77413857.8608;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM81(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	+ 190.4632 * parameters.total_wait_locks 
	+ 1.2628 * parameters.mean_wait_of_all 
	- 93109882.3857 * parameters.cpu_usage 
	- 0.1454 * parameters.avg_work_of_same_past_second 
	- 0.0235 * parameters.avg_wait_of_same_past_second 
	+ 0.0375 * parameters.avg_latency_of_same_last_20 
	- 0.005 * parameters.max_latency_of_same_last_50 
	+ 40621219.8847;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM82(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	+ 176909.0851 * parameters.total_wait_locks 
	+ 1.2628 * parameters.mean_wait_of_all 
	- 93109882.3857 * parameters.cpu_usage 
	- 0.1454 * parameters.avg_work_of_same_past_second 
	- 0.0235 * parameters.avg_wait_of_same_past_second 
	+ 0.038 * parameters.avg_latency_of_same_last_20 
	- 0.0051 * parameters.max_latency_of_same_last_50 
	+ 13562510.4787;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM83(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	+ 190.4632 * parameters.total_wait_locks 
	+ 1.2628 * parameters.mean_wait_of_all 
	- 93109882.3857 * parameters.cpu_usage 
	- 0.1454 * parameters.avg_work_of_same_past_second 
	- 0.0235 * parameters.avg_wait_of_same_past_second 
	+ 0.038 * parameters.avg_latency_of_same_last_20 
	- 0.0051 * parameters.max_latency_of_same_last_50 
	+ 44703747.367;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM84(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.0512 * parameters.wait_so_far 
	+ 190.4632 * parameters.total_wait_locks 
	+ 2.2385 * parameters.mean_wait_of_all 
	- 161179749.9331 * parameters.cpu_usage 
	- 0.2578 * parameters.avg_work_of_same_past_second 
	- 0.191 * parameters.avg_wait_of_same_past_second 
	+ 0.032 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	+ 98352293.9916;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM85(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.0267 * parameters.wait_so_far 
	+ 190.4632 * parameters.total_wait_locks 
	+ 1.8274 * parameters.mean_wait_of_all 
	- 161179749.9331 * parameters.cpu_usage 
	- 0.2578 * parameters.avg_work_of_same_past_second 
	+ 0.713 * parameters.avg_wait_of_same_past_second 
	+ 0.032 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	- 202501003.1291;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM86(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.0229 * parameters.wait_so_far 
	+ 190.4632 * parameters.total_wait_locks 
	+ 1.8665 * parameters.mean_wait_of_all 
	- 161179749.9331 * parameters.cpu_usage 
	- 0.2578 * parameters.avg_work_of_same_past_second 
	+ 0.6269 * parameters.avg_wait_of_same_past_second 
	+ 0.032 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	- 173024950.5379;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM87(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	+ 133648.7736 * parameters.total_wait_locks 
	+ 3.8376 * parameters.mean_wait_of_all 
	- 4871165.1946 * parameters.cpu_usage 
	+ 0.3317 * parameters.avg_work_of_same_past_second 
	- 0.2606 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0028 * parameters.max_latency_of_same_last_50 
	- 209841721.7372;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM88(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	+ 131754.9049 * parameters.total_wait_locks 
	+ 3.7894 * parameters.mean_wait_of_all 
	- 4871165.1946 * parameters.cpu_usage 
	+ 0.157 * parameters.avg_work_of_same_past_second 
	- 0.2755 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	- 194825905.2219;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM89(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0053 * parameters.wait_so_far 
	+ 160089.4119 * parameters.total_wait_locks 
	+ 4.6072 * parameters.mean_wait_of_all 
	- 4871165.1946 * parameters.cpu_usage 
	+ 0.157 * parameters.avg_work_of_same_past_second 
	- 0.3387 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	- 235302710.5121;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM90(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0059 * parameters.wait_so_far 
	+ 160089.4119 * parameters.total_wait_locks 
	+ 4.6072 * parameters.mean_wait_of_all 
	- 4871165.1946 * parameters.cpu_usage 
	+ 0.157 * parameters.avg_work_of_same_past_second 
	- 0.3387 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	- 235825826.5781;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM91(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	+ 160089.4119 * parameters.total_wait_locks 
	+ 4.6072 * parameters.mean_wait_of_all 
	- 4871165.1946 * parameters.cpu_usage 
	+ 0.157 * parameters.avg_work_of_same_past_second 
	- 0.3387 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	- 240464660.6121;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM92(work_wait &parameters) {
  double actual_remaining = 
	0.0239 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	+ 190.4632 * parameters.total_wait_locks 
	- 0.002 * parameters.mean_wait_of_all 
	- 4871165.1946 * parameters.cpu_usage 
	+ 0.0004 * parameters.avg_work_of_same_past_second 
	+ 0.0008 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0023 * parameters.max_latency_of_same_last_50 
	+ 23382794.1477;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM93(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.0062 * parameters.wait_so_far 
	+ 190.4632 * parameters.total_wait_locks 
	+ 1.2776 * parameters.mean_wait_of_all 
	- 719771.8648 * parameters.cpu_usage 
	- 0.3389 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 82611657.1322;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM94(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 317.5668 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 828474.6576 * parameters.cpu_usage 
	+ 0.0003 * parameters.avg_work_of_same_past_second 
	+ 0.0112 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 15995833.722;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM95(work_wait &parameters) {
  double actual_remaining = 
	-0.1667 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 166360.9039 * parameters.total_wait_locks 
	+ 1.1328 * parameters.mean_wait_of_all 
	- 39080282.5322 * parameters.cpu_usage 
	+ 0.0003 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 11393686.9838;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM96(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 1238.9341 * parameters.total_wait_locks 
	+ 0.2843 * parameters.mean_wait_of_all 
	+ 1560354.4973 * parameters.cpu_usage 
	+ 0.0097 * parameters.avg_work_of_same_past_second 
	- 0.05 * parameters.avg_wait_of_same_past_second 
	+ 0.0018 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 7307130.4971;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM97(work_wait &parameters) {
  double actual_remaining = 
	-0.444 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 16178.1945 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 306859609.1777 * parameters.cpu_usage 
	+ 0.0044 * parameters.avg_work_of_same_past_second 
	+ 0.011 * parameters.avg_wait_of_same_past_second 
	+ 0.0204 * parameters.avg_latency_of_same_last_20 
	- 0.0065 * parameters.max_latency_of_same_last_50 
	+ 337715531.5884;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM98(work_wait &parameters) {
  double actual_remaining = 
	-0.5224 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 2480.1896 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 306859609.1777 * parameters.cpu_usage 
	+ 0.0044 * parameters.avg_work_of_same_past_second 
	+ 0.011 * parameters.avg_wait_of_same_past_second 
	+ 0.0204 * parameters.avg_latency_of_same_last_20 
	- 0.0065 * parameters.max_latency_of_same_last_50 
	+ 331833692.7169;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM99(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 2480.1896 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 306859609.1777 * parameters.cpu_usage 
	+ 0.0044 * parameters.avg_work_of_same_past_second 
	+ 0.011 * parameters.avg_wait_of_same_past_second 
	+ 0.0204 * parameters.avg_latency_of_same_last_20 
	- 0.0065 * parameters.max_latency_of_same_last_50 
	+ 324191469.5538;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM100(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 2480.1896 * parameters.total_wait_locks 
	+ 0.1375 * parameters.mean_wait_of_all 
	- 197302257.7062 * parameters.cpu_usage 
	+ 0.0044 * parameters.avg_work_of_same_past_second 
	+ 0.011 * parameters.avg_wait_of_same_past_second 
	+ 0.0204 * parameters.avg_latency_of_same_last_20 
	+ 0.0063 * parameters.max_latency_of_same_last_50 
	+ 180914409.9089;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM101(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 8507.3934 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 193502315.9003 * parameters.cpu_usage 
	+ 0.4766 * parameters.avg_work_of_same_past_second 
	+ 0.0253 * parameters.avg_wait_of_same_past_second 
	+ 0.0204 * parameters.avg_latency_of_same_last_20 
	- 0.0111 * parameters.max_latency_of_same_last_50 
	+ 196592667.7197;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM102(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 8507.3934 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 193502315.9003 * parameters.cpu_usage 
	+ 0.0044 * parameters.avg_work_of_same_past_second 
	+ 0.0253 * parameters.avg_wait_of_same_past_second 
	+ 0.0204 * parameters.avg_latency_of_same_last_20 
	- 0.0111 * parameters.max_latency_of_same_last_50 
	+ 204293796.6008;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM103(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 2272.0288 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 84235382.8155 * parameters.cpu_usage 
	+ 0.0044 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0366 * parameters.avg_latency_of_same_last_20 
	+ 0.0222 * parameters.max_latency_of_same_last_50 
	+ 91068265.9846;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM104(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 46790.1992 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 84235382.8155 * parameters.cpu_usage 
	+ 0.0044 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0366 * parameters.avg_latency_of_same_last_20 
	+ 0.0222 * parameters.max_latency_of_same_last_50 
	+ 80533132.6119;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM105(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 2272.0288 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 84235382.8155 * parameters.cpu_usage 
	+ 0.0044 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0366 * parameters.avg_latency_of_same_last_20 
	+ 0.0222 * parameters.max_latency_of_same_last_50 
	+ 92570618.021;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM106(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 2272.0288 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 84235382.8155 * parameters.cpu_usage 
	+ 0.0044 * parameters.avg_work_of_same_past_second 
	+ 0.1354 * parameters.avg_wait_of_same_past_second 
	+ 0.0366 * parameters.avg_latency_of_same_last_20 
	+ 0.0087 * parameters.max_latency_of_same_last_50 
	+ 40609991.003;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM107(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 33215.3584 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 2423779.8306 * parameters.cpu_usage 
	+ 0.0044 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0021 * parameters.avg_latency_of_same_last_20 
	- 0.0054 * parameters.max_latency_of_same_last_50 
	+ 22327522.7194;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM108(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.0011 * parameters.wait_so_far 
	- 90226.4256 * parameters.total_wait_locks 
	+ 0.3187 * parameters.mean_wait_of_all 
	+ 17951786.1481 * parameters.cpu_usage 
	+ 0.001 * parameters.avg_wait_of_same_past_second 
	+ 0.0012 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 5886978.2349;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM109(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0069 * parameters.wait_so_far 
	- 15407.0988 * parameters.total_wait_locks 
	+ 0.2892 * parameters.mean_wait_of_all 
	+ 15292126.3124 * parameters.cpu_usage 
	+ 0.001 * parameters.avg_wait_of_same_past_second 
	+ 0.0012 * parameters.avg_latency_of_same_last_20 
	- 0.0032 * parameters.max_latency_of_same_last_50 
	- 14584172.8153;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM110(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0041 * parameters.wait_so_far 
	- 92041.8618 * parameters.total_wait_locks 
	+ 0.5526 * parameters.mean_wait_of_all 
	+ 15292126.3124 * parameters.cpu_usage 
	+ 0.001 * parameters.avg_wait_of_same_past_second 
	+ 0.0012 * parameters.avg_latency_of_same_last_20 
	- 0.0032 * parameters.max_latency_of_same_last_50 
	- 9670501.8242;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM111(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.0009 * parameters.wait_so_far 
	+ 112396.3054 * parameters.total_wait_locks 
	- 3.6229 * parameters.mean_wait_of_all 
	+ 15292126.3124 * parameters.cpu_usage 
	+ 0.3363 * parameters.avg_work_of_same_past_second 
	+ 0.001 * parameters.avg_wait_of_same_past_second 
	- 0.0591 * parameters.avg_latency_of_same_last_20 
	- 0.0066 * parameters.max_latency_of_same_last_50 
	+ 416738710.7752;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM112(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.0009 * parameters.wait_so_far 
	- 198324.7096 * parameters.total_wait_locks 
	+ 0.2892 * parameters.mean_wait_of_all 
	+ 15292126.3124 * parameters.cpu_usage 
	+ 0.4589 * parameters.avg_work_of_same_past_second 
	+ 0.001 * parameters.avg_wait_of_same_past_second 
	- 0.044 * parameters.avg_latency_of_same_last_20 
	- 0.0022 * parameters.max_latency_of_same_last_50 
	+ 84724337.8638;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM113(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.0009 * parameters.wait_so_far 
	- 198324.7096 * parameters.total_wait_locks 
	+ 0.2892 * parameters.mean_wait_of_all 
	+ 15292126.3124 * parameters.cpu_usage 
	+ 0.5933 * parameters.avg_work_of_same_past_second 
	+ 0.001 * parameters.avg_wait_of_same_past_second 
	- 0.044 * parameters.avg_latency_of_same_last_20 
	- 0.0027 * parameters.max_latency_of_same_last_50 
	+ 89410964.2521;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM114(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.0009 * parameters.wait_so_far 
	- 231325.4687 * parameters.total_wait_locks 
	+ 0.2892 * parameters.mean_wait_of_all 
	+ 15292126.3124 * parameters.cpu_usage 
	+ 0.5226 * parameters.avg_work_of_same_past_second 
	+ 0.001 * parameters.avg_wait_of_same_past_second 
	- 0.044 * parameters.avg_latency_of_same_last_20 
	- 0.0027 * parameters.max_latency_of_same_last_50 
	+ 104700156.3;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM115(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.0009 * parameters.wait_so_far 
	- 271305.3997 * parameters.total_wait_locks 
	+ 0.2892 * parameters.mean_wait_of_all 
	+ 15292126.3124 * parameters.cpu_usage 
	+ 0.2373 * parameters.avg_work_of_same_past_second 
	+ 0.001 * parameters.avg_wait_of_same_past_second 
	- 0.0531 * parameters.avg_latency_of_same_last_20 
	- 0.0053 * parameters.max_latency_of_same_last_50 
	+ 134049478.7349;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM116(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 25725.0493 * parameters.total_wait_locks 
	+ 0.352 * parameters.mean_wait_of_all 
	+ 3462895.8627 * parameters.cpu_usage 
	+ 0.001 * parameters.avg_wait_of_same_past_second 
	+ 0.0012 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 19774932.2921;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM117(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0076 * parameters.wait_so_far 
	+ 219568.4984 * parameters.total_wait_locks 
	- 1.0643 * parameters.mean_wait_of_all 
	+ 253216265.7963 * parameters.cpu_usage 
	- 0.1352 * parameters.avg_work_of_same_past_second 
	+ 0.321 * parameters.avg_wait_of_same_past_second 
	+ 0.0742 * parameters.avg_latency_of_same_last_20 
	- 0.0353 * parameters.max_latency_of_same_last_50 
	- 303167947.5398;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM118(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.004 * parameters.wait_so_far 
	+ 123111.3108 * parameters.total_wait_locks 
	- 0.4406 * parameters.mean_wait_of_all 
	+ 847309.2116 * parameters.cpu_usage 
	- 0.1352 * parameters.avg_work_of_same_past_second 
	+ 0.1275 * parameters.avg_wait_of_same_past_second 
	+ 0.0528 * parameters.avg_latency_of_same_last_20 
	+ 0.006 * parameters.max_latency_of_same_last_50 
	- 89775447.0725;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM119(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.004 * parameters.wait_so_far 
	+ 126317.1695 * parameters.total_wait_locks 
	- 0.0855 * parameters.mean_wait_of_all 
	+ 847309.2116 * parameters.cpu_usage 
	- 0.1352 * parameters.avg_work_of_same_past_second 
	+ 0.1275 * parameters.avg_wait_of_same_past_second 
	+ 0.1279 * parameters.avg_latency_of_same_last_20 
	+ 0.0069 * parameters.max_latency_of_same_last_50 
	- 182815946.4;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM120(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.004 * parameters.wait_so_far 
	+ 126317.1695 * parameters.total_wait_locks 
	- 0.2163 * parameters.mean_wait_of_all 
	+ 847309.2116 * parameters.cpu_usage 
	- 0.1352 * parameters.avg_work_of_same_past_second 
	+ 0.1275 * parameters.avg_wait_of_same_past_second 
	+ 0.1017 * parameters.avg_latency_of_same_last_20 
	+ 0.0069 * parameters.max_latency_of_same_last_50 
	- 139030728.4511;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM121(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0032 * parameters.wait_so_far 
	+ 133315.5416 * parameters.total_wait_locks 
	- 0.5916 * parameters.mean_wait_of_all 
	+ 847309.2116 * parameters.cpu_usage 
	- 0.2629 * parameters.avg_work_of_same_past_second 
	+ 0.001 * parameters.avg_wait_of_same_past_second 
	- 0.0091 * parameters.avg_latency_of_same_last_20 
	- 0.0096 * parameters.max_latency_of_same_last_50 
	+ 54821127.4192;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM122(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0032 * parameters.wait_so_far 
	+ 148861.9097 * parameters.total_wait_locks 
	- 0.4304 * parameters.mean_wait_of_all 
	+ 847309.2116 * parameters.cpu_usage 
	- 0.2629 * parameters.avg_work_of_same_past_second 
	+ 0.001 * parameters.avg_wait_of_same_past_second 
	- 0.0091 * parameters.avg_latency_of_same_last_20 
	- 0.007 * parameters.max_latency_of_same_last_50 
	+ 25548849.8848;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM123(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.0157 * parameters.wait_so_far 
	+ 564630.3966 * parameters.total_wait_locks 
	+ 0.2663 * parameters.mean_wait_of_all 
	- 144072558.5343 * parameters.cpu_usage 
	- 2.0001 * parameters.avg_work_of_same_past_second 
	- 0.1666 * parameters.avg_wait_of_same_past_second 
	- 0.1123 * parameters.avg_latency_of_same_last_20 
	+ 0.1 * parameters.max_latency_of_same_last_50 
	+ 83980856.6171;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM124(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.0157 * parameters.wait_so_far 
	+ 170119.7332 * parameters.total_wait_locks 
	+ 0.2663 * parameters.mean_wait_of_all 
	- 144072558.5343 * parameters.cpu_usage 
	- 2.0001 * parameters.avg_work_of_same_past_second 
	- 0.1666 * parameters.avg_wait_of_same_past_second 
	- 0.0539 * parameters.avg_latency_of_same_last_20 
	+ 0.1131 * parameters.max_latency_of_same_last_50 
	+ 148417916.0517;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM125(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.0222 * parameters.wait_so_far 
	+ 274500.2054 * parameters.total_wait_locks 
	+ 0.2663 * parameters.mean_wait_of_all 
	- 144072558.5343 * parameters.cpu_usage 
	- 2.8119 * parameters.avg_work_of_same_past_second 
	- 0.1666 * parameters.avg_wait_of_same_past_second 
	+ 0.0501 * parameters.avg_latency_of_same_last_20 
	+ 0.007 * parameters.max_latency_of_same_last_50 
	+ 188995546.7351;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM126(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.0222 * parameters.wait_so_far 
	- 758923.7069 * parameters.total_wait_locks 
	+ 0.2663 * parameters.mean_wait_of_all 
	- 144072558.5343 * parameters.cpu_usage 
	- 2.7141 * parameters.avg_work_of_same_past_second 
	- 0.1666 * parameters.avg_wait_of_same_past_second 
	+ 0.0501 * parameters.avg_latency_of_same_last_20 
	+ 0.0095 * parameters.max_latency_of_same_last_50 
	+ 608501896.3078;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM127(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0054 * parameters.wait_so_far 
	- 782415.9174 * parameters.total_wait_locks 
	+ 13.8086 * parameters.mean_wait_of_all 
	+ 784306.6006 * parameters.cpu_usage 
	- 1.9438 * parameters.avg_work_of_same_past_second 
	+ 0.0303 * parameters.avg_wait_of_same_past_second 
	+ 0.0069 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	- 1019729522.6953;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM128(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0054 * parameters.wait_so_far 
	- 1171202.341 * parameters.total_wait_locks 
	+ 17.5775 * parameters.mean_wait_of_all 
	+ 784306.6006 * parameters.cpu_usage 
	- 1.9438 * parameters.avg_work_of_same_past_second 
	+ 0.0303 * parameters.avg_wait_of_same_past_second 
	+ 0.0069 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	- 1242571077.7619;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM129(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0054 * parameters.wait_so_far 
	- 1171202.341 * parameters.total_wait_locks 
	+ 17.5775 * parameters.mean_wait_of_all 
	+ 784306.6006 * parameters.cpu_usage 
	- 1.9438 * parameters.avg_work_of_same_past_second 
	+ 0.0303 * parameters.avg_wait_of_same_past_second 
	+ 0.0069 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	- 1240765730.0894;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM130(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0054 * parameters.wait_so_far 
	- 43721.7124 * parameters.total_wait_locks 
	+ 7.2859 * parameters.mean_wait_of_all 
	+ 784306.6006 * parameters.cpu_usage 
	- 2.3386 * parameters.avg_work_of_same_past_second 
	+ 0.0303 * parameters.avg_wait_of_same_past_second 
	+ 0.0069 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	- 641161513.12;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM131(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0021 * parameters.wait_so_far 
	+ 270393.5698 * parameters.total_wait_locks 
	+ 0.2663 * parameters.mean_wait_of_all 
	+ 79951417.5235 * parameters.cpu_usage 
	- 0.4925 * parameters.avg_work_of_same_past_second 
	+ 0.1013 * parameters.avg_wait_of_same_past_second 
	+ 0.0069 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	- 228266792.4951;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM132(work_wait &parameters) {
  double actual_remaining = 
	0.1406 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	- 48880.9901 * parameters.total_wait_locks 
	+ 0.3181 * parameters.mean_wait_of_all 
	- 3859475.3116 * parameters.cpu_usage 
	- 0.0842 * parameters.avg_work_of_same_past_second 
	+ 0.0678 * parameters.avg_wait_of_same_past_second 
	+ 0.0021 * parameters.avg_latency_of_same_last_20 
	- 0.0013 * parameters.max_latency_of_same_last_50 
	- 23848099.1329;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM133(work_wait &parameters) {
  double actual_remaining = 
	0.0806 * parameters.work_so_far 
	- 0.003 * parameters.wait_so_far 
	- 48880.9901 * parameters.total_wait_locks 
	- 0.061 * parameters.mean_wait_of_all 
	- 3859475.3116 * parameters.cpu_usage 
	+ 0.9079 * parameters.avg_work_of_same_past_second 
	- 0.0467 * parameters.avg_wait_of_same_past_second 
	+ 0.0021 * parameters.avg_latency_of_same_last_20 
	+ 0.0023 * parameters.max_latency_of_same_last_50 
	+ 64391171.3743;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM134(work_wait &parameters) {
  double actual_remaining = 
	0.0806 * parameters.work_so_far 
	- 0.0074 * parameters.wait_so_far 
	- 48880.9901 * parameters.total_wait_locks 
	+ 0.4583 * parameters.mean_wait_of_all 
	- 110000669.1363 * parameters.cpu_usage 
	- 0.0545 * parameters.avg_work_of_same_past_second 
	- 0.0467 * parameters.avg_wait_of_same_past_second 
	+ 0.0021 * parameters.avg_latency_of_same_last_20 
	+ 0.0124 * parameters.max_latency_of_same_last_50 
	+ 109192741.031;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM135(work_wait &parameters) {
  double actual_remaining = 
	0.0235 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	- 48880.9901 * parameters.total_wait_locks 
	+ 0.3181 * parameters.mean_wait_of_all 
	- 3859475.3116 * parameters.cpu_usage 
	+ 0.3016 * parameters.avg_work_of_same_past_second 
	+ 0.0821 * parameters.avg_wait_of_same_past_second 
	+ 0.0021 * parameters.avg_latency_of_same_last_20 
	- 0.0012 * parameters.max_latency_of_same_last_50 
	- 48971719.2041;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM136(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	- 159116.966 * parameters.total_wait_locks 
	+ 1.1603 * parameters.mean_wait_of_all 
	- 8731991.9201 * parameters.cpu_usage 
	+ 0.1901 * parameters.avg_work_of_same_past_second 
	- 0.0186 * parameters.avg_wait_of_same_past_second 
	+ 0.0021 * parameters.avg_latency_of_same_last_20 
	+ 0.0073 * parameters.max_latency_of_same_last_50 
	- 37288197.319;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM137(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	- 126239.5696 * parameters.total_wait_locks 
	+ 0.4448 * parameters.mean_wait_of_all 
	- 8731991.9201 * parameters.cpu_usage 
	+ 0.465 * parameters.avg_work_of_same_past_second 
	- 0.1211 * parameters.avg_wait_of_same_past_second 
	+ 0.0021 * parameters.avg_latency_of_same_last_20 
	+ 0.0293 * parameters.max_latency_of_same_last_50 
	+ 58615766.6584;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM138(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0018 * parameters.wait_so_far 
	- 57818.2119 * parameters.total_wait_locks 
	+ 0.2522 * parameters.mean_wait_of_all 
	+ 24382990.5522 * parameters.cpu_usage 
	+ 0.5848 * parameters.avg_work_of_same_past_second 
	+ 0.0824 * parameters.avg_wait_of_same_past_second 
	+ 0.0086 * parameters.avg_latency_of_same_last_20 
	- 0.0108 * parameters.max_latency_of_same_last_50 
	- 32186178.2556;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM139(work_wait &parameters) {
  double actual_remaining = 
	9.0776 * parameters.work_so_far 
	- 0.0018 * parameters.wait_so_far 
	- 4466.5935 * parameters.total_wait_locks 
	- 0.2781 * parameters.mean_wait_of_all 
	+ 24382990.5522 * parameters.cpu_usage 
	- 0.0051 * parameters.avg_work_of_same_past_second 
	+ 0.0824 * parameters.avg_wait_of_same_past_second 
	- 0.0689 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 85899593.2979;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM140(work_wait &parameters) {
  double actual_remaining = 
	-47.7823 * parameters.work_so_far 
	- 0.0018 * parameters.wait_so_far 
	+ 55880.8045 * parameters.total_wait_locks 
	+ 0.6293 * parameters.mean_wait_of_all 
	+ 24382990.5522 * parameters.cpu_usage 
	- 0.0051 * parameters.avg_work_of_same_past_second 
	+ 0.1396 * parameters.avg_wait_of_same_past_second 
	+ 0.0015 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 116992218.2297;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM141(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0018 * parameters.wait_so_far 
	+ 81878.2194 * parameters.total_wait_locks 
	+ 0.6293 * parameters.mean_wait_of_all 
	+ 24382990.5522 * parameters.cpu_usage 
	- 0.0051 * parameters.avg_work_of_same_past_second 
	+ 0.1396 * parameters.avg_wait_of_same_past_second 
	+ 0.0015 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 132300255.4521;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM142(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0018 * parameters.wait_so_far 
	+ 30856.7652 * parameters.total_wait_locks 
	+ 0.6293 * parameters.mean_wait_of_all 
	+ 24382990.5522 * parameters.cpu_usage 
	- 0.0051 * parameters.avg_work_of_same_past_second 
	+ 0.1396 * parameters.avg_wait_of_same_past_second 
	+ 0.0015 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 111139202.3583;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM143(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0067 * parameters.wait_so_far 
	+ 118463.6768 * parameters.total_wait_locks 
	- 1.1225 * parameters.mean_wait_of_all 
	+ 24382990.5522 * parameters.cpu_usage 
	- 0.0051 * parameters.avg_work_of_same_past_second 
	+ 0.1396 * parameters.avg_wait_of_same_past_second 
	- 0.0367 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 65624253.4453;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM144(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0018 * parameters.wait_so_far 
	+ 254281.8207 * parameters.total_wait_locks 
	- 2.7024 * parameters.mean_wait_of_all 
	+ 24382990.5522 * parameters.cpu_usage 
	- 0.0051 * parameters.avg_work_of_same_past_second 
	+ 0.1396 * parameters.avg_wait_of_same_past_second 
	- 0.0433 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 203150725.4086;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM145(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0018 * parameters.wait_so_far 
	+ 143118.9346 * parameters.total_wait_locks 
	- 2.958 * parameters.mean_wait_of_all 
	+ 24382990.5522 * parameters.cpu_usage 
	- 0.0051 * parameters.avg_work_of_same_past_second 
	+ 0.1396 * parameters.avg_wait_of_same_past_second 
	- 0.0433 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 289287339.0081;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM146(work_wait &parameters) {
  double actual_remaining = 
	-150.5726 * parameters.work_so_far 
	- 0.0042 * parameters.wait_so_far 
	- 249284.5954 * parameters.total_wait_locks 
	+ 1.6039 * parameters.mean_wait_of_all 
	+ 139497746.2548 * parameters.cpu_usage 
	+ 0.1938 * parameters.avg_work_of_same_past_second 
	+ 0.0007 * parameters.avg_wait_of_same_past_second 
	+ 0.0015 * parameters.avg_latency_of_same_last_20 
	+ 0.0054 * parameters.max_latency_of_same_last_50 
	- 169374712.016;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM147(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0042 * parameters.wait_so_far 
	- 341117.1407 * parameters.total_wait_locks 
	+ 1.7331 * parameters.mean_wait_of_all 
	+ 159519697.6245 * parameters.cpu_usage 
	+ 0.2308 * parameters.avg_work_of_same_past_second 
	+ 0.1133 * parameters.avg_wait_of_same_past_second 
	+ 0.0015 * parameters.avg_latency_of_same_last_20 
	+ 0.006 * parameters.max_latency_of_same_last_50 
	- 226890569.7065;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM148(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.006 * parameters.wait_so_far 
	- 182957.1408 * parameters.total_wait_locks 
	+ 1.0786 * parameters.mean_wait_of_all 
	+ 31879757.6428 * parameters.cpu_usage 
	- 0.0051 * parameters.avg_work_of_same_past_second 
	+ 0.0213 * parameters.avg_wait_of_same_past_second 
	+ 0.0015 * parameters.avg_latency_of_same_last_20 
	+ 0.0037 * parameters.max_latency_of_same_last_50 
	- 58991011.632;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM149(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0109 * parameters.wait_so_far 
	- 48661.707 * parameters.total_wait_locks 
	+ 0.3122 * parameters.mean_wait_of_all 
	+ 302465.9582 * parameters.cpu_usage 
	- 0.0051 * parameters.avg_work_of_same_past_second 
	- 0.0045 * parameters.avg_wait_of_same_past_second 
	+ 0.0015 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 27670002.8689;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM150(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.009 * parameters.wait_so_far 
	- 198515.8694 * parameters.total_wait_locks 
	+ 1.2837 * parameters.mean_wait_of_all 
	+ 4898578.306 * parameters.cpu_usage 
	- 0.0189 * parameters.avg_wait_of_same_past_second 
	+ 0.0145 * parameters.avg_latency_of_same_last_20 
	- 0.0067 * parameters.max_latency_of_same_last_50 
	- 26363111.8819;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM151(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 265140.86 * parameters.total_wait_locks 
	+ 1.345 * parameters.mean_wait_of_all 
	+ 4898578.306 * parameters.cpu_usage 
	- 0.0885 * parameters.avg_wait_of_same_past_second 
	+ 0.0152 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 45323567.1729;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM152(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 238020.0954 * parameters.total_wait_locks 
	+ 1.345 * parameters.mean_wait_of_all 
	+ 4898578.306 * parameters.cpu_usage 
	- 0.0885 * parameters.avg_wait_of_same_past_second 
	+ 0.0152 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 39433714.5693;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM153(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.0018 * parameters.wait_so_far 
	- 237062.1341 * parameters.total_wait_locks 
	+ 1.345 * parameters.mean_wait_of_all 
	- 240880914.3082 * parameters.cpu_usage 
	- 0.0871 * parameters.avg_wait_of_same_past_second 
	+ 0.0376 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 244024126.4546;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM154(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.0018 * parameters.wait_so_far 
	- 237062.1341 * parameters.total_wait_locks 
	+ 1.345 * parameters.mean_wait_of_all 
	+ 4898578.306 * parameters.cpu_usage 
	- 0.1263 * parameters.avg_wait_of_same_past_second 
	+ 0.037 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 33890239.0524;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM155(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.0057 * parameters.wait_so_far 
	+ 555160.5335 * parameters.total_wait_locks 
	+ 0.6725 * parameters.mean_wait_of_all 
	+ 4898578.306 * parameters.cpu_usage 
	- 30.1701 * parameters.avg_work_of_same_past_second 
	+ 0.0321 * parameters.avg_wait_of_same_past_second 
	- 0.1546 * parameters.avg_latency_of_same_last_20 
	+ 0.2229 * parameters.max_latency_of_same_last_50 
	+ 460845794.8282;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM156(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0128 * parameters.wait_so_far 
	- 174750.0131 * parameters.total_wait_locks 
	+ 0.6071 * parameters.mean_wait_of_all 
	+ 4898578.306 * parameters.cpu_usage 
	- 0.6153 * parameters.avg_work_of_same_past_second 
	+ 0.0204 * parameters.avg_wait_of_same_past_second 
	+ 0.0295 * parameters.avg_latency_of_same_last_20 
	- 0.0021 * parameters.max_latency_of_same_last_50 
	+ 70291111.6205;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM157(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.0036 * parameters.wait_so_far 
	- 109711.6087 * parameters.total_wait_locks 
	+ 0.6127 * parameters.mean_wait_of_all 
	+ 4898578.306 * parameters.cpu_usage 
	- 0.6029 * parameters.avg_work_of_same_past_second 
	+ 0.0204 * parameters.avg_wait_of_same_past_second 
	+ 0.0286 * parameters.avg_latency_of_same_last_20 
	- 0.0017 * parameters.max_latency_of_same_last_50 
	+ 9222017.4614;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM158(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 483748.7225 * parameters.total_wait_locks 
	+ 3.7876 * parameters.mean_wait_of_all 
	+ 133085.0225 * parameters.cpu_usage 
	+ 0.1031 * parameters.avg_work_of_same_past_second 
	+ 0.0585 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 0.0048 * parameters.max_latency_of_same_last_50 
	- 197207014.2554;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM159(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0027 * parameters.wait_so_far 
	+ 363177.6467 * parameters.total_wait_locks 
	- 4.079 * parameters.mean_wait_of_all 
	+ 133085.0225 * parameters.cpu_usage 
	- 2.2568 * parameters.avg_work_of_same_past_second 
	+ 0.8336 * parameters.avg_wait_of_same_past_second 
	- 0.0195 * parameters.avg_latency_of_same_last_20 
	- 0.0063 * parameters.max_latency_of_same_last_50 
	+ 6471935.6842;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM160(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0027 * parameters.wait_so_far 
	+ 292428.9249 * parameters.total_wait_locks 
	- 5.8231 * parameters.mean_wait_of_all 
	+ 133085.0225 * parameters.cpu_usage 
	- 2.2568 * parameters.avg_work_of_same_past_second 
	+ 0.8403 * parameters.avg_wait_of_same_past_second 
	- 0.0195 * parameters.avg_latency_of_same_last_20 
	- 0.0063 * parameters.max_latency_of_same_last_50 
	+ 231718778.0956;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM161(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0031 * parameters.wait_so_far 
	+ 164791.1741 * parameters.total_wait_locks 
	+ 14.5487 * parameters.mean_wait_of_all 
	+ 133085.0225 * parameters.cpu_usage 
	- 2.5107 * parameters.avg_work_of_same_past_second 
	+ 0.7348 * parameters.avg_wait_of_same_past_second 
	- 0.0195 * parameters.avg_latency_of_same_last_20 
	- 0.0063 * parameters.max_latency_of_same_last_50 
	- 1967402401.6133;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM162(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 115593.4716 * parameters.total_wait_locks 
	- 12.0414 * parameters.mean_wait_of_all 
	+ 133085.0225 * parameters.cpu_usage 
	- 0.8285 * parameters.avg_work_of_same_past_second 
	+ 0.6214 * parameters.avg_wait_of_same_past_second 
	- 0.0162 * parameters.avg_latency_of_same_last_20 
	- 0.0063 * parameters.max_latency_of_same_last_50 
	+ 1066566832.5141;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM163(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 115593.4716 * parameters.total_wait_locks 
	- 12.0414 * parameters.mean_wait_of_all 
	+ 133085.0225 * parameters.cpu_usage 
	- 0.8285 * parameters.avg_work_of_same_past_second 
	+ 0.6214 * parameters.avg_wait_of_same_past_second 
	- 0.0156 * parameters.avg_latency_of_same_last_20 
	- 0.0063 * parameters.max_latency_of_same_last_50 
	+ 1067082206.033;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM164(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0096 * parameters.wait_so_far 
	+ 499188.6097 * parameters.total_wait_locks 
	+ 0.8819 * parameters.mean_wait_of_all 
	+ 133085.0225 * parameters.cpu_usage 
	+ 0.1519 * parameters.avg_work_of_same_past_second 
	+ 0.4579 * parameters.avg_wait_of_same_past_second 
	- 0.0366 * parameters.avg_latency_of_same_last_20 
	- 0.0063 * parameters.max_latency_of_same_last_50 
	- 459350418.4851;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM165(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.0188 * parameters.wait_so_far 
	+ 310036.1173 * parameters.total_wait_locks 
	+ 0.8819 * parameters.mean_wait_of_all 
	+ 133085.0225 * parameters.cpu_usage 
	+ 0.1519 * parameters.avg_work_of_same_past_second 
	+ 0.4579 * parameters.avg_wait_of_same_past_second 
	- 0.0366 * parameters.avg_latency_of_same_last_20 
	- 0.0063 * parameters.max_latency_of_same_last_50 
	- 374682691.0971;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM166(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 110943.1687 * parameters.total_wait_locks 
	+ 0.8406 * parameters.mean_wait_of_all 
	+ 133085.0225 * parameters.cpu_usage 
	+ 0.0076 * parameters.avg_wait_of_same_past_second 
	+ 0.0152 * parameters.avg_latency_of_same_last_20 
	- 0.0008 * parameters.max_latency_of_same_last_50 
	- 31689649.7378;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
payment_estimate(work_wait &parameters){

  if (parameters.avg_latency_of_same_last_20 <= 146044500) {

    if (parameters.work_so_far <= 7549.5) {

      if (parameters.wait_so_far <= 39682365) {

        if (parameters.avg_latency_of_same_last_20 <= 32896350) {
          return payment_LM1(parameters);
        } else {
          return payment_LM2(parameters);
        }
      } else {

        if (parameters.wait_so_far <= 102917997) {
          return payment_LM3(parameters);
        } else {

          if (parameters.avg_latency_of_same_last_20 <= 42074000) {
            return payment_LM4(parameters);
          } else {

            if (parameters.max_latency_of_same_last_50 <= 255333000) {

              if (parameters.cpu_usage <= 0.968) {

                if (parameters.avg_wait_of_same_past_second <= 11809160) {
                  return payment_LM5(parameters);
                } else {

                  if (parameters.total_wait_locks <= 104) {
                    return payment_LM6(parameters);
                  } else {

                    if (parameters.cpu_usage <= 0.942) {
                      return payment_LM7(parameters);
                    } else {
                      return payment_LM8(parameters);
                    }
                  }
                }
              } else {
                return payment_LM9(parameters);
              }
            } else {
              return payment_LM10(parameters);
            }
          }
        }
      }
    } else {

      if (parameters.wait_so_far <= 29604588) {

        if (parameters.max_latency_of_same_last_50 <= 134757000) {
          return payment_LM11(parameters);
        } else {

          if (parameters.work_so_far <= 8438.5) {

            if (parameters.avg_wait_of_same_past_second <= 41596000) {
              return payment_LM12(parameters);
            } else {

              if (parameters.avg_wait_of_same_past_second <= 64931000) {

                if (parameters.max_latency_of_same_last_50 <= 161587500) {

                  if (parameters.work_so_far <= 8097.5) {
                    return payment_LM13(parameters);
                  } else {
                    return payment_LM14(parameters);
                  }
                } else {

                  if (parameters.work_so_far <= 7911.5) {
                    return payment_LM15(parameters);
                  } else {
                    return payment_LM16(parameters);
                  }
                }
              } else {

                if (parameters.wait_so_far <= 22331534) {
                  return payment_LM17(parameters);
                } else {
                  return payment_LM18(parameters);
                }
              }
            }
          } else {

            if (parameters.avg_work_of_same_past_second <= 7963055) {

              if (parameters.avg_latency_of_same_last_20 <= 51543800) {

                if (parameters.work_so_far <= 11192) {
                  return payment_LM19(parameters);
                } else {

                  if (parameters.total_wait_locks <= 91.5) {
                    return payment_LM20(parameters);
                  } else {
                    return payment_LM21(parameters);
                  }
                }
              } else {

                if (parameters.total_wait_locks <= 161.5) {

                  if (parameters.work_so_far <= 18018.5) {

                    if (parameters.work_so_far <= 10663) {

                      if (parameters.cpu_usage <= 0.883) {
                        return payment_LM22(parameters);
                      } else {

                        if (parameters.avg_work_of_same_past_second <= 7105540) {

                          if (parameters.avg_work_of_same_past_second <= 5765090) {
                            return payment_LM23(parameters);
                          } else {
                            return payment_LM24(parameters);
                          }
                        } else {

                          if (parameters.mean_wait_of_all <= 72855350) {
                            return payment_LM25(parameters);
                          } else {
                            return payment_LM26(parameters);
                          }
                        }
                      }
                    } else {
                      return payment_LM27(parameters);
                    }
                  } else {
                    return payment_LM28(parameters);
                  }
                } else {
                  return payment_LM29(parameters);
                }
              }
            } else {

              if (parameters.total_wait_locks <= 134.5) {
                return payment_LM30(parameters);
              } else {

                if (parameters.max_latency_of_same_last_50 <= 253856000) {

                  if (parameters.avg_work_of_same_past_second <= 11139750) {

                    if (parameters.avg_wait_of_same_past_second <= 58011350) {
                      return payment_LM31(parameters);
                    } else {
                      return payment_LM32(parameters);
                    }
                  } else {

                    if (parameters.avg_work_of_same_past_second <= 14644850) {

                      if (parameters.avg_latency_of_same_last_20 <= 36134850) {
                        return payment_LM33(parameters);
                      } else {
                        return payment_LM34(parameters);
                      }
                    } else {
                      return payment_LM35(parameters);
                    }
                  }
                } else {

                  if (parameters.work_so_far <= 14266) {
                    return payment_LM36(parameters);
                  } else {
                    return payment_LM37(parameters);
                  }
                }
              }
            }
          }
        }
      } else {

        if (parameters.mean_wait_of_all <= 66640450) {

          if (parameters.total_wait_locks <= 112.5) {
            return payment_LM38(parameters);
          } else {
            return payment_LM39(parameters);
          }
        } else {
          return payment_LM40(parameters);
        }
      }
    }
  } else {

    if (parameters.avg_wait_of_same_past_second <= 467286000) {

      if (parameters.wait_so_far <= 205684195.5) {

        if (parameters.max_latency_of_same_last_50 <= 1210405000) {

          if (parameters.max_latency_of_same_last_50 <= 690715500) {

            if (parameters.max_latency_of_same_last_50 <= 483976500) {

              if (parameters.wait_so_far <= 22991327) {

                if (parameters.avg_wait_of_same_past_second <= 95077500) {

                  if (parameters.cpu_usage <= 0.903) {
                    return payment_LM41(parameters);
                  } else {
                    return payment_LM42(parameters);
                  }
                } else {
                  return payment_LM43(parameters);
                }
              } else {
                return payment_LM44(parameters);
              }
            } else {

              if (parameters.avg_latency_of_same_last_20 <= 176618000) {
                return payment_LM45(parameters);
              } else {

                if (parameters.cpu_usage <= 0.943) {

                  if (parameters.mean_wait_of_all <= 92315350) {
                    return payment_LM46(parameters);
                  } else {

                    if (parameters.avg_work_of_same_past_second <= 13069650) {

                      if (parameters.work_so_far <= 20854) {
                        return payment_LM47(parameters);
                      } else {
                        return payment_LM48(parameters);
                      }
                    } else {

                      if (parameters.work_so_far <= 34180.5) {
                        return payment_LM49(parameters);
                      } else {
                        return payment_LM50(parameters);
                      }
                    }
                  }
                } else {
                  return payment_LM51(parameters);
                }
              }
            }
          } else {

            if (parameters.mean_wait_of_all <= 98333350) {
              return payment_LM52(parameters);
            } else {

              if (parameters.total_wait_locks <= 657.5) {

                if (parameters.avg_work_of_same_past_second <= 21753300) {
                  return payment_LM53(parameters);
                } else {

                  if (parameters.avg_latency_of_same_last_20 <= 260229500) {

                    if (parameters.cpu_usage <= 0.997) {

                      if (parameters.max_latency_of_same_last_50 <= 843768500) {

                        if (parameters.avg_latency_of_same_last_20 <= 238823000) {

                          if (parameters.wait_so_far <= 132974864.5) {
                            return payment_LM54(parameters);
                          } else {
                            return payment_LM55(parameters);
                          }
                        } else {

                          if (parameters.wait_so_far <= 96651262) {
                            return payment_LM56(parameters);
                          } else {
                            return payment_LM57(parameters);
                          }
                        }
                      } else {

                        if (parameters.mean_wait_of_all <= 98751350) {
                          return payment_LM58(parameters);
                        } else {

                          if (parameters.mean_wait_of_all <= 120184000) {
                            return payment_LM59(parameters);
                          } else {

                            if (parameters.wait_so_far <= 94572866.5) {
                              return payment_LM60(parameters);
                            } else {
                              return payment_LM61(parameters);
                            }
                          }
                        }
                      }
                    } else {
                      return payment_LM62(parameters);
                    }
                  } else {

                    if (parameters.avg_wait_of_same_past_second <= 390323500) {

                      if (parameters.total_wait_locks <= 394) {
                        return payment_LM63(parameters);
                      } else {

                        if (parameters.avg_work_of_same_past_second <= 38168350) {

                          if (parameters.wait_so_far <= 61095077) {
                            return payment_LM64(parameters);
                          } else {
                            return payment_LM65(parameters);
                          }
                        } else {
                          return payment_LM66(parameters);
                        }
                      }
                    } else {

                      if (parameters.mean_wait_of_all <= 135674000) {
                        return payment_LM67(parameters);
                      } else {
                        return payment_LM68(parameters);
                      }
                    }
                  }
                }
              } else {

                if (parameters.avg_wait_of_same_past_second <= 400753000) {

                  if (parameters.work_so_far <= 27945) {
                    return payment_LM69(parameters);
                  } else {
                    return payment_LM70(parameters);
                  }
                } else {
                  return payment_LM71(parameters);
                }
              }
            }
          }
        } else {
          return payment_LM72(parameters);
        }
      } else {

        if (parameters.mean_wait_of_all <= 82107150) {

          if (parameters.cpu_usage <= 0.919) {

            if (parameters.avg_latency_of_same_last_20 <= 285045000) {
              return payment_LM73(parameters);
            } else {

              if (parameters.avg_latency_of_same_last_20 <= 511015500) {

                if (parameters.max_latency_of_same_last_50 <= 766053500) {
                  return payment_LM74(parameters);
                } else {
                  return payment_LM75(parameters);
                }
              } else {

                if (parameters.wait_so_far <= 398893744.5) {

                  if (parameters.wait_so_far <= 359638101.5) {
                    return payment_LM76(parameters);
                  } else {
                    return payment_LM77(parameters);
                  }
                } else {
                  return payment_LM78(parameters);
                }
              }
            }
          } else {

            if (parameters.mean_wait_of_all <= 76712450) {

              if (parameters.avg_wait_of_same_past_second <= 312984500) {
                return payment_LM79(parameters);
              } else {

                if (parameters.max_latency_of_same_last_50 <= 946307500) {
                  return payment_LM80(parameters);
                } else {

                  if (parameters.avg_latency_of_same_last_20 <= 434117500) {

                    if (parameters.mean_wait_of_all <= 70799450) {

                      if (parameters.mean_wait_of_all <= 65192850) {

                        if (parameters.avg_latency_of_same_last_20 <= 323401000) {
                          return payment_LM81(parameters);
                        } else {

                          if (parameters.total_wait_locks <= 227.5) {
                            return payment_LM82(parameters);
                          } else {
                            return payment_LM83(parameters);
                          }
                        }
                      } else {

                        if (parameters.avg_wait_of_same_past_second <= 364527500) {
                          return payment_LM84(parameters);
                        } else {

                          if (parameters.mean_wait_of_all <= 65369000) {
                            return payment_LM85(parameters);
                          } else {
                            return payment_LM86(parameters);
                          }
                        }
                      }
                    } else {

                      if (parameters.mean_wait_of_all <= 73848300) {
                        return payment_LM87(parameters);
                      } else {

                        if (parameters.total_wait_locks <= 277.5) {
                          return payment_LM88(parameters);
                        } else {

                          if (parameters.avg_wait_of_same_past_second <= 380951500) {

                            if (parameters.wait_so_far <= 635823357.5) {
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
                  } else {
                    return payment_LM92(parameters);
                  }
                }
              }
            } else {
              return payment_LM93(parameters);
            }
          }
        } else {

          if (parameters.avg_latency_of_same_last_20 <= 503771000) {

            if (parameters.total_wait_locks <= 273.5) {
              return payment_LM94(parameters);
            } else {
              return payment_LM95(parameters);
            }
          } else {

            if (parameters.cpu_usage <= 0.928) {
              return payment_LM96(parameters);
            } else {

              if (parameters.avg_wait_of_same_past_second <= 349532000) {

                if (parameters.avg_work_of_same_past_second <= 26586650) {

                  if (parameters.max_latency_of_same_last_50 <= 1723840000) {

                    if (parameters.cpu_usage <= 0.96) {

                      if (parameters.total_wait_locks <= 351.5) {

                        if (parameters.work_so_far <= 592885.5) {
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
                  } else {

                    if (parameters.avg_work_of_same_past_second <= 21338900) {
                      return payment_LM101(parameters);
                    } else {
                      return payment_LM102(parameters);
                    }
                  }
                } else {

                  if (parameters.mean_wait_of_all <= 89730250) {

                    if (parameters.total_wait_locks <= 306) {

                      if (parameters.work_so_far <= 26316.5) {
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
              } else {
                return payment_LM107(parameters);
              }
            }
          }
        }
      }
    } else {

      if (parameters.avg_wait_of_same_past_second <= 492302500) {

        if (parameters.avg_latency_of_same_last_20 <= 600719500) {

          if (parameters.mean_wait_of_all <= 124000000) {

            if (parameters.mean_wait_of_all <= 112142500) {
              return payment_LM108(parameters);
            } else {

              if (parameters.avg_latency_of_same_last_20 <= 329749500) {

                if (parameters.wait_so_far <= 164655763.5) {
                  return payment_LM109(parameters);
                } else {
                  return payment_LM110(parameters);
                }
              } else {

                if (parameters.avg_latency_of_same_last_20 <= 520858500) {

                  if (parameters.max_latency_of_same_last_50 <= 1121575000) {
                    return payment_LM111(parameters);
                  } else {

                    if (parameters.max_latency_of_same_last_50 <= 1853055000) {
                      return payment_LM112(parameters);
                    } else {

                      if (parameters.avg_latency_of_same_last_20 <= 345811000) {
                        return payment_LM113(parameters);
                      } else {
                        return payment_LM114(parameters);
                      }
                    }
                  }
                } else {
                  return payment_LM115(parameters);
                }
              }
            }
          } else {
            return payment_LM116(parameters);
          }
        } else {

          if (parameters.avg_latency_of_same_last_20 <= 794958500) {

            if (parameters.wait_so_far <= 287184554) {
              return payment_LM117(parameters);
            } else {

              if (parameters.max_latency_of_same_last_50 <= 1873020000) {
                return payment_LM118(parameters);
              } else {

                if (parameters.avg_latency_of_same_last_20 <= 680767000) {
                  return payment_LM119(parameters);
                } else {
                  return payment_LM120(parameters);
                }
              }
            }
          } else {

            if (parameters.avg_work_of_same_past_second <= 26880350) {
              return payment_LM121(parameters);
            } else {
              return payment_LM122(parameters);
            }
          }
        }
      } else {

        if (parameters.cpu_usage <= 0.989) {

          if (parameters.cpu_usage <= 0.966) {

            if (parameters.mean_wait_of_all <= 106818500) {

              if (parameters.avg_wait_of_same_past_second <= 514521000) {

                if (parameters.total_wait_locks <= 413.5) {

                  if (parameters.avg_latency_of_same_last_20 <= 477632000) {
                    return payment_LM123(parameters);
                  } else {
                    return payment_LM124(parameters);
                  }
                } else {

                  if (parameters.total_wait_locks <= 420.5) {
                    return payment_LM125(parameters);
                  } else {
                    return payment_LM126(parameters);
                  }
                }
              } else {

                if (parameters.wait_so_far <= 182088859.5) {

                  if (parameters.max_latency_of_same_last_50 <= 1821105000) {

                    if (parameters.avg_latency_of_same_last_20 <= 636167500) {
                      return payment_LM127(parameters);
                    } else {

                      if (parameters.mean_wait_of_all <= 106114500) {
                        return payment_LM128(parameters);
                      } else {
                        return payment_LM129(parameters);
                      }
                    }
                  } else {
                    return payment_LM130(parameters);
                  }
                } else {
                  return payment_LM131(parameters);
                }
              }
            } else {

              if (parameters.avg_latency_of_same_last_20 <= 476265500) {

                if (parameters.avg_wait_of_same_past_second <= 571597000) {

                  if (parameters.max_latency_of_same_last_50 <= 1608665000) {

                    if (parameters.avg_wait_of_same_past_second <= 520584500) {
                      return payment_LM132(parameters);
                    } else {

                      if (parameters.avg_work_of_same_past_second <= 35388450) {
                        return payment_LM133(parameters);
                      } else {
                        return payment_LM134(parameters);
                      }
                    }
                  } else {
                    return payment_LM135(parameters);
                  }
                } else {

                  if (parameters.mean_wait_of_all <= 118089500) {
                    return payment_LM136(parameters);
                  } else {
                    return payment_LM137(parameters);
                  }
                }
              } else {

                if (parameters.cpu_usage <= 0.929) {

                  if (parameters.avg_wait_of_same_past_second <= 559657500) {

                    if (parameters.avg_wait_of_same_past_second <= 541276000) {

                      if (parameters.avg_latency_of_same_last_20 <= 866567500) {
                        return payment_LM138(parameters);
                      } else {
                        return payment_LM139(parameters);
                      }
                    } else {

                      if (parameters.avg_wait_of_same_past_second <= 543048500) {

                        if (parameters.total_wait_locks <= 593.5) {

                          if (parameters.work_so_far <= 43129.5) {
                            return payment_LM140(parameters);
                          } else {
                            return payment_LM141(parameters);
                          }
                        } else {
                          return payment_LM142(parameters);
                        }
                      } else {

                        if (parameters.total_wait_locks <= 503.5) {
                          return payment_LM143(parameters);
                        } else {

                          if (parameters.avg_latency_of_same_last_20 <= 484969000) {
                            return payment_LM144(parameters);
                          } else {
                            return payment_LM145(parameters);
                          }
                        }
                      }
                    }
                  } else {

                    if (parameters.wait_so_far <= 746990675) {

                      if (parameters.work_so_far <= 70495) {
                        return payment_LM146(parameters);
                      } else {
                        return payment_LM147(parameters);
                      }
                    } else {
                      return payment_LM148(parameters);
                    }
                  }
                } else {
                  return payment_LM149(parameters);
                }
              }
            }
          } else {

            if (parameters.avg_work_of_same_past_second <= 31996350) {

              if (parameters.avg_latency_of_same_last_20 <= 635110500) {
                return payment_LM150(parameters);
              } else {

                if (parameters.max_latency_of_same_last_50 <= 1626155000) {

                  if (parameters.avg_wait_of_same_past_second <= 518053500) {
                    return payment_LM151(parameters);
                  } else {
                    return payment_LM152(parameters);
                  }
                } else {

                  if (parameters.avg_latency_of_same_last_20 <= 790201500) {
                    return payment_LM153(parameters);
                  } else {
                    return payment_LM154(parameters);
                  }
                }
              }
            } else {

              if (parameters.avg_work_of_same_past_second <= 38088800) {
                return payment_LM155(parameters);
              } else {

                if (parameters.max_latency_of_same_last_50 <= 1883875000) {
                  return payment_LM156(parameters);
                } else {
                  return payment_LM157(parameters);
                }
              }
            }
          }
        } else {

          if (parameters.mean_wait_of_all <= 117056000) {

            if (parameters.mean_wait_of_all <= 112122000) {
              return payment_LM158(parameters);
            } else {

              if (parameters.mean_wait_of_all <= 116973000) {

                if (parameters.mean_wait_of_all <= 114634000) {

                  if (parameters.avg_work_of_same_past_second <= 40953950) {

                    if (parameters.mean_wait_of_all <= 113901500) {
                      return payment_LM159(parameters);
                    } else {
                      return payment_LM160(parameters);
                    }
                  } else {
                    return payment_LM161(parameters);
                  }
                } else {

                  if (parameters.avg_latency_of_same_last_20 <= 360756000) {
                    return payment_LM162(parameters);
                  } else {
                    return payment_LM163(parameters);
                  }
                }
              } else {

                if (parameters.total_wait_locks <= 440.5) {
                  return payment_LM164(parameters);
                } else {
                  return payment_LM165(parameters);
                }
              }
            }
          } else {
            return payment_LM166(parameters);
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
	0.075 * parameters.work_so_far 
	- 0.0047 * parameters.wait_so_far 
	- 407075.0856 * parameters.num_locks_so_far 
	+ 14001.1543 * parameters.total_wait_locks 
	+ 0.0094 * parameters.mean_wait_of_all 
	- 333805966.9777 * parameters.cpu_usage 
	- 0.1046 * parameters.avg_work_of_same_past_second 
	- 0.0042 * parameters.avg_wait_of_same_past_second 
	+ 0.5609 * parameters.avg_latency_of_same_last_20 
	- 0.0031 * parameters.max_latency_of_same_last_50 
	+ 466472175.0882;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM2(work_wait &parameters) {
  double actual_remaining = 
	1.2174 * parameters.work_so_far 
	+ 0.2284 * parameters.wait_so_far 
	- 897147.0595 * parameters.num_locks_so_far 
	+ 482039.0895 * parameters.total_wait_locks 
	- 3.1773 * parameters.mean_wait_of_all 
	- 720773574.5809 * parameters.cpu_usage 
	+ 0.0036 * parameters.avg_work_of_same_past_second 
	- 0.0042 * parameters.avg_wait_of_same_past_second 
	+ 0.8648 * parameters.avg_latency_of_same_last_20 
	- 0.1682 * parameters.max_latency_of_same_last_50 
	+ 1041183621.0729;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM3(work_wait &parameters) {
  double actual_remaining = 
	1.5199 * parameters.work_so_far 
	- 0.0199 * parameters.wait_so_far 
	- 897147.0595 * parameters.num_locks_so_far 
	+ 680761.7523 * parameters.total_wait_locks 
	- 3.8955 * parameters.mean_wait_of_all 
	- 32733151.7853 * parameters.cpu_usage 
	+ 0.0493 * parameters.avg_work_of_same_past_second 
	- 0.0042 * parameters.avg_wait_of_same_past_second 
	+ 0.1318 * parameters.avg_latency_of_same_last_20 
	- 0.0831 * parameters.max_latency_of_same_last_50 
	+ 544368073.7534;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM4(work_wait &parameters) {
  double actual_remaining = 
	1.5199 * parameters.work_so_far 
	- 0.0199 * parameters.wait_so_far 
	- 897147.0595 * parameters.num_locks_so_far 
	+ 680761.7523 * parameters.total_wait_locks 
	- 7.8552 * parameters.mean_wait_of_all 
	- 32733151.7853 * parameters.cpu_usage 
	+ 0.2726 * parameters.avg_work_of_same_past_second 
	- 0.0042 * parameters.avg_wait_of_same_past_second 
	+ 0.1318 * parameters.avg_latency_of_same_last_20 
	- 0.0831 * parameters.max_latency_of_same_last_50 
	+ 754143496.4777;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM5(work_wait &parameters) {
  double actual_remaining = 
	1.6064 * parameters.work_so_far 
	- 0.3527 * parameters.wait_so_far 
	- 897147.0595 * parameters.num_locks_so_far 
	+ 732575.9236 * parameters.total_wait_locks 
	- 16.2048 * parameters.mean_wait_of_all 
	- 32733151.7853 * parameters.cpu_usage 
	+ 0.1633 * parameters.avg_work_of_same_past_second 
	- 0.0042 * parameters.avg_wait_of_same_past_second 
	+ 0.1318 * parameters.avg_latency_of_same_last_20 
	- 0.3715 * parameters.max_latency_of_same_last_50 
	+ 1979174734.4298;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM6(work_wait &parameters) {
  double actual_remaining = 
	1.6064 * parameters.work_so_far 
	- 0.2827 * parameters.wait_so_far 
	- 897147.0595 * parameters.num_locks_so_far 
	+ 732575.9236 * parameters.total_wait_locks 
	- 10.6779 * parameters.mean_wait_of_all 
	- 32733151.7853 * parameters.cpu_usage 
	+ 0.1143 * parameters.avg_work_of_same_past_second 
	- 0.0042 * parameters.avg_wait_of_same_past_second 
	+ 0.1318 * parameters.avg_latency_of_same_last_20 
	- 0.1546 * parameters.max_latency_of_same_last_50 
	+ 1244290378.2412;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM7(work_wait &parameters) {
  double actual_remaining = 
	1.0506 * parameters.work_so_far 
	- 0.0401 * parameters.wait_so_far 
	- 897147.0595 * parameters.num_locks_so_far 
	+ 104657.0906 * parameters.total_wait_locks 
	- 2.0392 * parameters.mean_wait_of_all 
	- 32733151.7853 * parameters.cpu_usage 
	+ 0.0036 * parameters.avg_work_of_same_past_second 
	- 0.0042 * parameters.avg_wait_of_same_past_second 
	+ 1.8864 * parameters.avg_latency_of_same_last_20 
	- 0.0379 * parameters.max_latency_of_same_last_50 
	+ 213913930.4718;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM8(work_wait &parameters) {
  double actual_remaining = 
	-2.74 * parameters.work_so_far 
	- 0.0401 * parameters.wait_so_far 
	- 897147.0595 * parameters.num_locks_so_far 
	+ 185039.6387 * parameters.total_wait_locks 
	- 2.0392 * parameters.mean_wait_of_all 
	- 32733151.7853 * parameters.cpu_usage 
	+ 0.0036 * parameters.avg_work_of_same_past_second 
	- 0.0042 * parameters.avg_wait_of_same_past_second 
	+ 0.4751 * parameters.avg_latency_of_same_last_20 
	- 0.0379 * parameters.max_latency_of_same_last_50 
	+ 350697827.632;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM9(work_wait &parameters) {
  double actual_remaining = 
	2.5067 * parameters.work_so_far 
	- 0.0257 * parameters.wait_so_far 
	- 4362344.3245 * parameters.num_locks_so_far 
	+ 29474.131 * parameters.total_wait_locks 
	+ 0.0601 * parameters.mean_wait_of_all 
	- 284540370.4224 * parameters.cpu_usage 
	+ 0.371 * parameters.avg_work_of_same_past_second 
	- 1.5744 * parameters.avg_wait_of_same_past_second 
	+ 0.0696 * parameters.avg_latency_of_same_last_20 
	- 0.0076 * parameters.max_latency_of_same_last_50 
	+ 512741674.7704;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM10(work_wait &parameters) {
  double actual_remaining = 
	54.0258 * parameters.work_so_far 
	- 0.0257 * parameters.wait_so_far 
	- 46479280.3097 * parameters.num_locks_so_far 
	+ 29474.131 * parameters.total_wait_locks 
	+ 0.0601 * parameters.mean_wait_of_all 
	- 1889635257.3552 * parameters.cpu_usage 
	+ 0.0391 * parameters.avg_work_of_same_past_second 
	- 0.0055 * parameters.avg_wait_of_same_past_second 
	+ 0.0696 * parameters.avg_latency_of_same_last_20 
	- 0.0076 * parameters.max_latency_of_same_last_50 
	+ 2320009688.2679;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM11(work_wait &parameters) {
  double actual_remaining = 
	-0.6154 * parameters.wait_so_far 
	- 1531707.0534 * parameters.num_locks_so_far 
	+ 637284.4517 * parameters.total_wait_locks 
	+ 1.3475 * parameters.mean_wait_of_all 
	- 1522436554.7954 * parameters.cpu_usage 
	+ 0.0302 * parameters.avg_work_of_same_past_second 
	+ 0.9004 * parameters.avg_wait_of_same_past_second 
	+ 0.0887 * parameters.avg_latency_of_same_last_20 
	- 0.0107 * parameters.max_latency_of_same_last_50 
	+ 1636980110.7026;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM12(work_wait &parameters) {
  double actual_remaining = 
	1.9709 * parameters.work_so_far 
	- 0.1985 * parameters.wait_so_far 
	- 5315488.0523 * parameters.num_locks_so_far 
	+ 279600.6763 * parameters.total_wait_locks 
	+ 0.6127 * parameters.mean_wait_of_all 
	- 52683341.7448 * parameters.cpu_usage 
	+ 0.0087 * parameters.avg_work_of_same_past_second 
	- 0.0055 * parameters.avg_wait_of_same_past_second 
	+ 0.0664 * parameters.avg_latency_of_same_last_20 
	- 0.0029 * parameters.max_latency_of_same_last_50 
	+ 291476255.3242;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM13(work_wait &parameters) {
  double actual_remaining = 
	0.4501 * parameters.wait_so_far 
	- 323707.6797 * parameters.num_locks_so_far 
	+ 11645.9152 * parameters.total_wait_locks 
	+ 0.3994 * parameters.mean_wait_of_all 
	- 3496179098.1991 * parameters.cpu_usage 
	+ 0.0087 * parameters.avg_work_of_same_past_second 
	- 0.4339 * parameters.avg_wait_of_same_past_second 
	+ 0.2115 * parameters.avg_latency_of_same_last_20 
	- 0.0029 * parameters.max_latency_of_same_last_50 
	+ 3436712608.1655;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM14(work_wait &parameters) {
  double actual_remaining = 
	6.4037 * parameters.work_so_far 
	- 0.1353 * parameters.wait_so_far 
	- 323707.6797 * parameters.num_locks_so_far 
	+ 11645.9152 * parameters.total_wait_locks 
	+ 0.2467 * parameters.mean_wait_of_all 
	- 322495181.8984 * parameters.cpu_usage 
	+ 0.0087 * parameters.avg_work_of_same_past_second 
	- 0.239 * parameters.avg_wait_of_same_past_second 
	+ 1.2866 * parameters.avg_latency_of_same_last_20 
	- 0.0029 * parameters.max_latency_of_same_last_50 
	+ 124943368.3575;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM15(work_wait &parameters) {
  double actual_remaining = 
	-26.3947 * parameters.work_so_far 
	- 0.0217 * parameters.wait_so_far 
	- 323707.6797 * parameters.num_locks_so_far 
	+ 11645.9152 * parameters.total_wait_locks 
	+ 0.2827 * parameters.mean_wait_of_all 
	- 364983696.9039 * parameters.cpu_usage 
	+ 0.0087 * parameters.avg_work_of_same_past_second 
	- 0.3189 * parameters.avg_wait_of_same_past_second 
	+ 0.4154 * parameters.avg_latency_of_same_last_20 
	- 0.0029 * parameters.max_latency_of_same_last_50 
	+ 737989540.3975;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM16(work_wait &parameters) {
  double actual_remaining = 
	-0.1265 * parameters.work_so_far 
	- 0.0247 * parameters.wait_so_far 
	+ 69231.2742 * parameters.num_locks_so_far 
	- 4330806.725 * parameters.total_wait_locks 
	+ 21.0366 * parameters.mean_wait_of_all 
	+ 2541665796.8343 * parameters.cpu_usage 
	+ 0.0074 * parameters.avg_work_of_same_past_second 
	- 0.0175 * parameters.avg_wait_of_same_past_second 
	+ 0.1026 * parameters.avg_latency_of_same_last_20 
	- 0.0022 * parameters.max_latency_of_same_last_50 
	- 1968392193.006;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM17(work_wait &parameters) {
  double actual_remaining = 
	-0.1265 * parameters.work_so_far 
	- 0.0138 * parameters.wait_so_far 
	+ 69231.2742 * parameters.num_locks_so_far 
	- 3833004.469 * parameters.total_wait_locks 
	+ 23.875 * parameters.mean_wait_of_all 
	+ 1293371216.066 * parameters.cpu_usage 
	+ 0.0074 * parameters.avg_work_of_same_past_second 
	- 0.0175 * parameters.avg_wait_of_same_past_second 
	+ 0.7226 * parameters.avg_latency_of_same_last_20 
	- 0.0022 * parameters.max_latency_of_same_last_50 
	- 1855950335.9951;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
delivery_LM18(work_wait &parameters) {
  double actual_remaining = 
	-2.2214 * parameters.work_so_far 
	- 0.0151 * parameters.wait_so_far 
	+ 753392.1788 * parameters.num_locks_so_far 
	+ 2529172.5504 * parameters.total_wait_locks 
	- 23.0637 * parameters.mean_wait_of_all 
	+ 95350221.841 * parameters.cpu_usage 
	- 0.2662 * parameters.avg_work_of_same_past_second 
	- 0.6144 * parameters.avg_wait_of_same_past_second 
	+ 0.081 * parameters.avg_latency_of_same_last_20 
	- 0.0022 * parameters.max_latency_of_same_last_50 
	+ 2524720927.0539;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
delivery_estimate(work_wait &parameters){

  if (parameters.avg_latency_of_same_last_20 <= 188879000) {

    if (parameters.total_wait_locks <= 206.5) {
      return delivery_LM1(parameters);
    } else {

      if (parameters.wait_so_far <= 467296657) {

        if (parameters.work_so_far <= 12197) {
          return delivery_LM2(parameters);
        } else {

          if (parameters.total_wait_locks <= 232.5) {

            if (parameters.avg_work_of_same_past_second <= 204824500) {
              return delivery_LM3(parameters);
            } else {
              return delivery_LM4(parameters);
            }
          } else {

            if (parameters.mean_wait_of_all <= 90435050) {
              return delivery_LM5(parameters);
            } else {
              return delivery_LM6(parameters);
            }
          }
        }
      } else {

        if (parameters.total_wait_locks <= 227.5) {
          return delivery_LM7(parameters);
        } else {
          return delivery_LM8(parameters);
        }
      }
    }
  } else {

    if (parameters.total_wait_locks <= 406.5) {

      if (parameters.wait_so_far <= 352392449.5) {

        if (parameters.avg_latency_of_same_last_20 <= 351303500) {

          if (parameters.avg_work_of_same_past_second <= 534211500) {
            return delivery_LM9(parameters);
          } else {
            return delivery_LM10(parameters);
          }
        } else {
          return delivery_LM11(parameters);
        }
      } else {

        if (parameters.avg_latency_of_same_last_20 <= 400799000) {
          return delivery_LM12(parameters);
        } else {

          if (parameters.avg_latency_of_same_last_20 <= 568990000) {

            if (parameters.avg_latency_of_same_last_20 <= 425207500) {
              return delivery_LM13(parameters);
            } else {
              return delivery_LM14(parameters);
            }
          } else {
            return delivery_LM15(parameters);
          }
        }
      }
    } else {

      if (parameters.avg_latency_of_same_last_20 <= 623985500) {

        if (parameters.wait_so_far <= 223897209) {
          return delivery_LM16(parameters);
        } else {
          return delivery_LM17(parameters);
        }
      } else {
        return delivery_LM18(parameters);
      }
    }
  }
}
static
double
stock_level_LM1(work_wait &parameters) {
  double actual_remaining = 
	0.1408 * parameters.work_so_far 
	- 0.0013 * parameters.wait_so_far 
	- 4981.1782 * parameters.num_locks_so_far 
	+ 885.4611 * parameters.total_wait_locks 
	+ 0.0049 * parameters.avg_work_of_same_past_second 
	+ 0.1078 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	+ 2589580.1499;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
stock_level_LM2(work_wait &parameters) {
  double actual_remaining = 
	-0.0449 * parameters.wait_so_far 
	- 238667.5599 * parameters.num_locks_so_far 
	+ 399.2624 * parameters.total_wait_locks 
	+ 0.1295 * parameters.mean_wait_of_all 
	+ 0.0022 * parameters.avg_work_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 44308100.1941;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
stock_level_estimate(work_wait &parameters){

  if (parameters.avg_latency_of_same_last_20 <= 160805000) {
    return stock_level_LM1(parameters);
  } else {
    return stock_level_LM2(parameters);
  }
}
static
double
tpcc_LM1(work_wait &parameters) {
  double actual_remaining = 
	11.6854 * parameters.work_so_far 
	+ 0 * parameters.wait_so_far 
	- 909.511 * parameters.num_locks_so_far 
	+ 181.7145 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 188775.9019 * parameters.cpu_usage 
	+ 0.0009 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0006 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 6024894.5161;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM2(work_wait &parameters) {
  double actual_remaining = 
	83.6414 * parameters.work_so_far 
	+ 0.0472 * parameters.wait_so_far 
	- 909.511 * parameters.num_locks_so_far 
	+ 200158.9408 * parameters.total_wait_locks 
	- 0.0292 * parameters.mean_wait_of_all 
	+ 250914372.0498 * parameters.cpu_usage 
	- 0.438 * parameters.avg_work_of_same_past_second 
	- 0.1434 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 0.0867 * parameters.max_latency_of_same_last_50 
	- 193308845.049;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM3(work_wait &parameters) {
  double actual_remaining = 
	2252.538 * parameters.work_so_far 
	+ 0.0192 * parameters.wait_so_far 
	- 909.511 * parameters.num_locks_so_far 
	+ 181.7145 * parameters.total_wait_locks 
	- 0.0345 * parameters.mean_wait_of_all 
	+ 4742352.1857 * parameters.cpu_usage 
	- 0.1806 * parameters.avg_work_of_same_past_second 
	- 0.0548 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 0.0018 * parameters.max_latency_of_same_last_50 
	- 9367620.8443;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM4(work_wait &parameters) {
  double actual_remaining = 
	3176.7802 * parameters.work_so_far 
	+ 0.0227 * parameters.wait_so_far 
	- 909.511 * parameters.num_locks_so_far 
	+ 181.7145 * parameters.total_wait_locks 
	- 0.0345 * parameters.mean_wait_of_all 
	+ 4742352.1857 * parameters.cpu_usage 
	- 0.1806 * parameters.avg_work_of_same_past_second 
	- 0.0548 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 0.0178 * parameters.max_latency_of_same_last_50 
	- 3835856.232;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM5(work_wait &parameters) {
  double actual_remaining = 
	217.8727 * parameters.work_so_far 
	+ 0.0086 * parameters.wait_so_far 
	- 909.511 * parameters.num_locks_so_far 
	+ 181.7145 * parameters.total_wait_locks 
	- 0.0191 * parameters.mean_wait_of_all 
	+ 4742352.1857 * parameters.cpu_usage 
	- 0.1806 * parameters.avg_work_of_same_past_second 
	- 0.0548 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 0.0018 * parameters.max_latency_of_same_last_50 
	+ 7811420.5254;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM6(work_wait &parameters) {
  double actual_remaining = 
	7934.5098 * parameters.work_so_far 
	+ 0.019 * parameters.wait_so_far 
	- 909.511 * parameters.num_locks_so_far 
	- 22015.9147 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 188775.9019 * parameters.cpu_usage 
	- 8.4216 * parameters.avg_work_of_same_past_second 
	- 0.1272 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 27272831.2792;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM7(work_wait &parameters) {
  double actual_remaining = 
	5171.9608 * parameters.work_so_far 
	+ 0.019 * parameters.wait_so_far 
	- 909.511 * parameters.num_locks_so_far 
	- 22015.9147 * parameters.total_wait_locks 
	+ 0.371 * parameters.mean_wait_of_all 
	- 188775.9019 * parameters.cpu_usage 
	- 9.8055 * parameters.avg_work_of_same_past_second 
	- 0.1272 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 48839050.8343;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM8(work_wait &parameters) {
  double actual_remaining = 
	5171.9608 * parameters.work_so_far 
	+ 0.019 * parameters.wait_so_far 
	- 909.511 * parameters.num_locks_so_far 
	- 22015.9147 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 188775.9019 * parameters.cpu_usage 
	- 8.9334 * parameters.avg_work_of_same_past_second 
	- 0.1272 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 61937370.4024;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM9(work_wait &parameters) {
  double actual_remaining = 
	518.146 * parameters.work_so_far 
	+ 0.0668 * parameters.wait_so_far 
	- 909.511 * parameters.num_locks_so_far 
	- 7719.1366 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 188775.9019 * parameters.cpu_usage 
	- 0.0218 * parameters.avg_work_of_same_past_second 
	- 0.0454 * parameters.avg_wait_of_same_past_second 
	+ 0.0008 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 8475339.3206;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM10(work_wait &parameters) {
  double actual_remaining = 
	1442.2109 * parameters.work_so_far 
	+ 0.0005 * parameters.wait_so_far 
	- 909.511 * parameters.num_locks_so_far 
	+ 181.7145 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 188775.9019 * parameters.cpu_usage 
	- 0.0116 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0197 * parameters.avg_latency_of_same_last_20 
	- 0.0058 * parameters.max_latency_of_same_last_50 
	- 2564508.4328;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM11(work_wait &parameters) {
  double actual_remaining = 
	486.0455 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 887.767 * parameters.num_locks_so_far 
	+ 10302.4682 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 621659.6228 * parameters.cpu_usage 
	- 0.2169 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 0.004 * parameters.max_latency_of_same_last_50 
	+ 5058339.7197;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM12(work_wait &parameters) {
  double actual_remaining = 
	264.7987 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 887.767 * parameters.num_locks_so_far 
	+ 8074.7962 * parameters.total_wait_locks 
	- 0.2038 * parameters.mean_wait_of_all 
	+ 696714388.4077 * parameters.cpu_usage 
	- 1.6031 * parameters.avg_work_of_same_past_second 
	+ 0.1342 * parameters.avg_wait_of_same_past_second 
	- 0.1051 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 556193483.6871;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM13(work_wait &parameters) {
  double actual_remaining = 
	264.7987 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 887.767 * parameters.num_locks_so_far 
	+ 8074.7962 * parameters.total_wait_locks 
	- 0.2038 * parameters.mean_wait_of_all 
	+ 131339149.2017 * parameters.cpu_usage 
	- 1.4229 * parameters.avg_work_of_same_past_second 
	+ 0.1128 * parameters.avg_wait_of_same_past_second 
	- 0.0864 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 64420779.9746;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM14(work_wait &parameters) {
  double actual_remaining = 
	780.662 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 887.767 * parameters.num_locks_so_far 
	+ 8074.7962 * parameters.total_wait_locks 
	- 0.0997 * parameters.mean_wait_of_all 
	- 6666508.7676 * parameters.cpu_usage 
	- 1.496 * parameters.avg_work_of_same_past_second 
	+ 0.0118 * parameters.avg_wait_of_same_past_second 
	- 0.0063 * parameters.avg_latency_of_same_last_20 
	+ 0.0096 * parameters.max_latency_of_same_last_50 
	+ 25607925.2003;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM15(work_wait &parameters) {
  double actual_remaining = 
	260.1676 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 887.767 * parameters.num_locks_so_far 
	+ 19977.6593 * parameters.total_wait_locks 
	- 0.1262 * parameters.mean_wait_of_all 
	- 6666508.7676 * parameters.cpu_usage 
	- 0.4072 * parameters.avg_work_of_same_past_second 
	+ 0.1152 * parameters.avg_wait_of_same_past_second 
	- 0.1237 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 43962102.443;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM16(work_wait &parameters) {
  double actual_remaining = 
	260.1676 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 887.767 * parameters.num_locks_so_far 
	+ 121189.9225 * parameters.total_wait_locks 
	+ 3.5052 * parameters.mean_wait_of_all 
	- 6666508.7676 * parameters.cpu_usage 
	- 0.4072 * parameters.avg_work_of_same_past_second 
	+ 0.079 * parameters.avg_wait_of_same_past_second 
	- 0.1179 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 297889859.0973;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM17(work_wait &parameters) {
  double actual_remaining = 
	-594.5774 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 887.767 * parameters.num_locks_so_far 
	+ 19977.6593 * parameters.total_wait_locks 
	+ 6.0949 * parameters.mean_wait_of_all 
	- 6666508.7676 * parameters.cpu_usage 
	- 0.4072 * parameters.avg_work_of_same_past_second 
	+ 0.079 * parameters.avg_wait_of_same_past_second 
	- 0.1179 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 485183800.4247;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM18(work_wait &parameters) {
  double actual_remaining = 
	260.1676 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 887.767 * parameters.num_locks_so_far 
	+ 19977.6593 * parameters.total_wait_locks 
	- 0.1262 * parameters.mean_wait_of_all 
	- 6666508.7676 * parameters.cpu_usage 
	- 0.4072 * parameters.avg_work_of_same_past_second 
	+ 0.079 * parameters.avg_wait_of_same_past_second 
	- 0.0898 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 45160499.045;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM19(work_wait &parameters) {
  double actual_remaining = 
	3.8699 * parameters.work_so_far 
	+ 0.012 * parameters.wait_so_far 
	- 887.767 * parameters.num_locks_so_far 
	+ 40404.6147 * parameters.total_wait_locks 
	- 0.1353 * parameters.mean_wait_of_all 
	- 83558665.7718 * parameters.cpu_usage 
	+ 0.0012 * parameters.avg_work_of_same_past_second 
	- 0.0327 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 97394699.1263;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM20(work_wait &parameters) {
  double actual_remaining = 
	3.8699 * parameters.work_so_far 
	- 0.0211 * parameters.wait_so_far 
	- 887.767 * parameters.num_locks_so_far 
	- 17912.6843 * parameters.total_wait_locks 
	+ 0.1322 * parameters.mean_wait_of_all 
	- 89825495.9296 * parameters.cpu_usage 
	+ 0.0012 * parameters.avg_work_of_same_past_second 
	+ 0.1506 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	- 0.0647 * parameters.max_latency_of_same_last_50 
	+ 169429277.1129;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM21(work_wait &parameters) {
  double actual_remaining = 
	-212.4275 * parameters.work_so_far 
	- 0.0015 * parameters.wait_so_far 
	- 887.767 * parameters.num_locks_so_far 
	- 208714.05 * parameters.total_wait_locks 
	+ 1.2809 * parameters.mean_wait_of_all 
	- 53579317.5432 * parameters.cpu_usage 
	+ 0.0012 * parameters.avg_work_of_same_past_second 
	+ 0.0133 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	- 0.002 * parameters.max_latency_of_same_last_50 
	+ 31112006.3824;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM22(work_wait &parameters) {
  double actual_remaining = 
	-291.1162 * parameters.work_so_far 
	- 0.0015 * parameters.wait_so_far 
	- 887.767 * parameters.num_locks_so_far 
	- 58468.6504 * parameters.total_wait_locks 
	+ 0.3735 * parameters.mean_wait_of_all 
	- 53579317.5432 * parameters.cpu_usage 
	+ 0.0012 * parameters.avg_work_of_same_past_second 
	+ 0.0133 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	- 0.002 * parameters.max_latency_of_same_last_50 
	+ 58851152.3505;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM23(work_wait &parameters) {
  double actual_remaining = 
	-296.9794 * parameters.work_so_far 
	- 0.0457 * parameters.wait_so_far 
	- 887.767 * parameters.num_locks_so_far 
	- 7425.2354 * parameters.total_wait_locks 
	+ 0.0629 * parameters.mean_wait_of_all 
	- 53579317.5432 * parameters.cpu_usage 
	+ 0.0012 * parameters.avg_work_of_same_past_second 
	+ 0.0233 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	- 0.002 * parameters.max_latency_of_same_last_50 
	+ 97984653.6593;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM24(work_wait &parameters) {
  double actual_remaining = 
	2.5253 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 887.767 * parameters.num_locks_so_far 
	+ 12260.0305 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 671244.6693 * parameters.cpu_usage 
	+ 0.0012 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0099 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 13521710.1836;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM25(work_wait &parameters) {
  double actual_remaining = 
	-415.7284 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 887.767 * parameters.num_locks_so_far 
	+ 215.4294 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 353723.8668 * parameters.cpu_usage 
	- 1.3144 * parameters.avg_work_of_same_past_second 
	+ 0.0337 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	- 0.0057 * parameters.max_latency_of_same_last_50 
	+ 61225841.6986;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM26(work_wait &parameters) {
  double actual_remaining = 
	0.0129 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	+ 8410.1521 * parameters.total_wait_locks 
	+ 0.0011 * parameters.mean_wait_of_all 
	- 6982694.9885 * parameters.cpu_usage 
	- 0.3798 * parameters.avg_work_of_same_past_second 
	+ 0.0058 * parameters.avg_wait_of_same_past_second 
	+ 0.0369 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 18649315.9942;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM27(work_wait &parameters) {
  double actual_remaining = 
	-4.0834 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	+ 8410.1521 * parameters.total_wait_locks 
	+ 0.0011 * parameters.mean_wait_of_all 
	- 6982694.9885 * parameters.cpu_usage 
	- 0.3798 * parameters.avg_work_of_same_past_second 
	+ 0.0058 * parameters.avg_wait_of_same_past_second 
	+ 0.0369 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 30185964.0539;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM28(work_wait &parameters) {
  double actual_remaining = 
	-3.1929 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	+ 8410.1521 * parameters.total_wait_locks 
	+ 0.0011 * parameters.mean_wait_of_all 
	- 6982694.9885 * parameters.cpu_usage 
	- 0.3798 * parameters.avg_work_of_same_past_second 
	+ 0.0058 * parameters.avg_wait_of_same_past_second 
	+ 0.0369 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 25822089.9213;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM29(work_wait &parameters) {
  double actual_remaining = 
	0.0129 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	+ 8410.1521 * parameters.total_wait_locks 
	+ 0.0011 * parameters.mean_wait_of_all 
	- 6982694.9885 * parameters.cpu_usage 
	- 0.2281 * parameters.avg_work_of_same_past_second 
	+ 0.0058 * parameters.avg_wait_of_same_past_second 
	+ 0.016 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 16015154.6805;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM30(work_wait &parameters) {
  double actual_remaining = 
	0.0226 * parameters.work_so_far 
	- 0.0336 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	+ 16853.7231 * parameters.total_wait_locks 
	- 0.0401 * parameters.mean_wait_of_all 
	- 11207218.1797 * parameters.cpu_usage 
	- 0.1385 * parameters.avg_work_of_same_past_second 
	+ 0.1375 * parameters.avg_wait_of_same_past_second 
	+ 0.0019 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 44126868.2267;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM31(work_wait &parameters) {
  double actual_remaining = 
	0.0188 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	+ 13817.1227 * parameters.total_wait_locks 
	- 0.0916 * parameters.mean_wait_of_all 
	- 9704910.8656 * parameters.cpu_usage 
	- 0.1385 * parameters.avg_work_of_same_past_second 
	+ 0.0027 * parameters.avg_wait_of_same_past_second 
	+ 0.013 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 24855074.0467;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM32(work_wait &parameters) {
  double actual_remaining = 
	0.0188 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	+ 13817.1227 * parameters.total_wait_locks 
	- 0.3116 * parameters.mean_wait_of_all 
	- 9704910.8656 * parameters.cpu_usage 
	- 0.1385 * parameters.avg_work_of_same_past_second 
	+ 0.0027 * parameters.avg_wait_of_same_past_second 
	+ 0.0062 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 49403150.6951;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM33(work_wait &parameters) {
  double actual_remaining = 
	1.9998 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	+ 12232.6844 * parameters.total_wait_locks 
	+ 0.0011 * parameters.mean_wait_of_all 
	- 133312821.7869 * parameters.cpu_usage 
	- 2.7563 * parameters.avg_work_of_same_past_second 
	+ 0.0571 * parameters.avg_wait_of_same_past_second 
	+ 0.1514 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 157361608.425;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM34(work_wait &parameters) {
  double actual_remaining = 
	0.3565 * parameters.work_so_far 
	- 0.0103 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	- 96111.5476 * parameters.total_wait_locks 
	+ 0.8306 * parameters.mean_wait_of_all 
	- 141018998.0456 * parameters.cpu_usage 
	- 6.3803 * parameters.avg_work_of_same_past_second 
	+ 0.1551 * parameters.avg_wait_of_same_past_second 
	+ 0.0019 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 242335880.6811;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM35(work_wait &parameters) {
  double actual_remaining = 
	0.3565 * parameters.work_so_far 
	- 0.0284 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	- 96111.5476 * parameters.total_wait_locks 
	+ 0.8306 * parameters.mean_wait_of_all 
	- 141018998.0456 * parameters.cpu_usage 
	- 3.2884 * parameters.avg_work_of_same_past_second 
	+ 0.1274 * parameters.avg_wait_of_same_past_second 
	- 0.0683 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 191259001.3915;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM36(work_wait &parameters) {
  double actual_remaining = 
	0.3565 * parameters.work_so_far 
	- 0.0284 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	- 40574.0637 * parameters.total_wait_locks 
	+ 0.8306 * parameters.mean_wait_of_all 
	- 141018998.0456 * parameters.cpu_usage 
	- 3.2884 * parameters.avg_work_of_same_past_second 
	+ 0.1274 * parameters.avg_wait_of_same_past_second 
	- 0.0683 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 173579921.6673;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM37(work_wait &parameters) {
  double actual_remaining = 
	0.3565 * parameters.work_so_far 
	- 0.0284 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	- 40574.0637 * parameters.total_wait_locks 
	+ 0.8306 * parameters.mean_wait_of_all 
	- 141018998.0456 * parameters.cpu_usage 
	- 3.2884 * parameters.avg_work_of_same_past_second 
	+ 0.1274 * parameters.avg_wait_of_same_past_second 
	- 0.0683 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 173735162.8718;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM38(work_wait &parameters) {
  double actual_remaining = 
	0.3565 * parameters.work_so_far 
	- 0.0305 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	+ 99762.0501 * parameters.total_wait_locks 
	+ 0.8306 * parameters.mean_wait_of_all 
	- 141018998.0456 * parameters.cpu_usage 
	- 3.4201 * parameters.avg_work_of_same_past_second 
	+ 0.1274 * parameters.avg_wait_of_same_past_second 
	- 0.0633 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 121389829.9179;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM39(work_wait &parameters) {
  double actual_remaining = 
	0.3565 * parameters.work_so_far 
	- 0.0253 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	+ 51414.2613 * parameters.total_wait_locks 
	+ 0.8306 * parameters.mean_wait_of_all 
	- 141018998.0456 * parameters.cpu_usage 
	- 3.4201 * parameters.avg_work_of_same_past_second 
	+ 0.1274 * parameters.avg_wait_of_same_past_second 
	- 0.0633 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 143459409.7109;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM40(work_wait &parameters) {
  double actual_remaining = 
	0.3565 * parameters.work_so_far 
	- 0.0157 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	- 155526.1264 * parameters.total_wait_locks 
	+ 1.2855 * parameters.mean_wait_of_all 
	- 141018998.0456 * parameters.cpu_usage 
	- 4.1847 * parameters.avg_work_of_same_past_second 
	+ 0.0956 * parameters.avg_wait_of_same_past_second 
	+ 0.0019 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 166929727.8392;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM41(work_wait &parameters) {
  double actual_remaining = 
	0.0018 * parameters.work_so_far 
	- 0.0078 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	+ 482.8494 * parameters.total_wait_locks 
	+ 0.0008 * parameters.mean_wait_of_all 
	- 856887.0271 * parameters.cpu_usage 
	- 0.0037 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 23465800.9503;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM42(work_wait &parameters) {
  double actual_remaining = 
	0.0018 * parameters.work_so_far 
	- 0.0101 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	+ 652.008 * parameters.total_wait_locks 
	+ 0.0016 * parameters.mean_wait_of_all 
	- 856887.0271 * parameters.cpu_usage 
	- 0.0037 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0293 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 19286025.5051;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM43(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	+ 334.5251 * parameters.total_wait_locks 
	+ 0.1922 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	- 3.5602 * parameters.avg_work_of_same_past_second 
	+ 0.1012 * parameters.avg_wait_of_same_past_second 
	- 0.0123 * parameters.avg_latency_of_same_last_20 
	- 0.0038 * parameters.max_latency_of_same_last_50 
	+ 54650661.1762;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM44(work_wait &parameters) {
  double actual_remaining = 
	-2.4619 * parameters.work_so_far 
	+ 0.0154 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	+ 334.5251 * parameters.total_wait_locks 
	+ 0.4058 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	- 3.5602 * parameters.avg_work_of_same_past_second 
	+ 0.1012 * parameters.avg_wait_of_same_past_second 
	+ 0.066 * parameters.avg_latency_of_same_last_20 
	- 0.0038 * parameters.max_latency_of_same_last_50 
	+ 18571549.1454;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM45(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	- 314024.863 * parameters.total_wait_locks 
	+ 1.1047 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	- 16.3475 * parameters.avg_work_of_same_past_second 
	+ 0.2581 * parameters.avg_wait_of_same_past_second 
	- 0.1188 * parameters.avg_latency_of_same_last_20 
	- 0.0038 * parameters.max_latency_of_same_last_50 
	+ 367071148.4539;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM46(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	- 296555.7603 * parameters.total_wait_locks 
	+ 1.1047 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	- 16.3475 * parameters.avg_work_of_same_past_second 
	+ 0.2581 * parameters.avg_wait_of_same_past_second 
	- 0.1188 * parameters.avg_latency_of_same_last_20 
	- 0.0038 * parameters.max_latency_of_same_last_50 
	+ 354713646.6213;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM47(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	- 150612.6044 * parameters.total_wait_locks 
	+ 1.1047 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	- 16.3475 * parameters.avg_work_of_same_past_second 
	+ 0.2581 * parameters.avg_wait_of_same_past_second 
	- 0.1188 * parameters.avg_latency_of_same_last_20 
	- 0.0038 * parameters.max_latency_of_same_last_50 
	+ 314741999.5537;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM48(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	- 233666.9906 * parameters.total_wait_locks 
	+ 1.1047 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	- 16.3475 * parameters.avg_work_of_same_past_second 
	+ 0.2581 * parameters.avg_wait_of_same_past_second 
	- 0.1404 * parameters.avg_latency_of_same_last_20 
	- 0.0038 * parameters.max_latency_of_same_last_50 
	+ 326701741.2789;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM49(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	- 125448.6968 * parameters.total_wait_locks 
	+ 0.8285 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	- 14.1278 * parameters.avg_work_of_same_past_second 
	+ 0.2321 * parameters.avg_wait_of_same_past_second 
	- 0.0058 * parameters.avg_latency_of_same_last_20 
	- 0.0038 * parameters.max_latency_of_same_last_50 
	+ 193806774.2825;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM50(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	- 0.0071 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	- 125927.5315 * parameters.total_wait_locks 
	+ 0.8285 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	- 14.1278 * parameters.avg_work_of_same_past_second 
	+ 0.2321 * parameters.avg_wait_of_same_past_second 
	+ 0.0164 * parameters.avg_latency_of_same_last_20 
	- 0.0038 * parameters.max_latency_of_same_last_50 
	+ 190368995.5487;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM51(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	- 0.0059 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	- 115145.666 * parameters.total_wait_locks 
	+ 0.8285 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	- 14.1278 * parameters.avg_work_of_same_past_second 
	+ 0.2321 * parameters.avg_wait_of_same_past_second 
	+ 0.0164 * parameters.avg_latency_of_same_last_20 
	- 0.0038 * parameters.max_latency_of_same_last_50 
	+ 183363295.8435;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM52(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	- 67608.7145 * parameters.total_wait_locks 
	+ 0.8285 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	- 14.1278 * parameters.avg_work_of_same_past_second 
	+ 0.2321 * parameters.avg_wait_of_same_past_second 
	+ 0.0176 * parameters.avg_latency_of_same_last_20 
	- 0.0038 * parameters.max_latency_of_same_last_50 
	+ 168314601.9186;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM53(work_wait &parameters) {
  double actual_remaining = 
	-50.5487 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	- 77374.7385 * parameters.total_wait_locks 
	+ 0.8285 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	- 14.1278 * parameters.avg_work_of_same_past_second 
	+ 0.2321 * parameters.avg_wait_of_same_past_second 
	+ 0.0176 * parameters.avg_latency_of_same_last_20 
	- 0.0038 * parameters.max_latency_of_same_last_50 
	+ 177962213.523;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM54(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	- 72792.3648 * parameters.total_wait_locks 
	+ 0.8285 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	- 14.1278 * parameters.avg_work_of_same_past_second 
	+ 0.2321 * parameters.avg_wait_of_same_past_second 
	+ 0.0176 * parameters.avg_latency_of_same_last_20 
	- 0.0038 * parameters.max_latency_of_same_last_50 
	+ 174455233.8904;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM55(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	- 50296.771 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	- 13.7057 * parameters.avg_work_of_same_past_second 
	+ 0.2561 * parameters.avg_wait_of_same_past_second 
	- 0.018 * parameters.avg_latency_of_same_last_20 
	- 0.0306 * parameters.max_latency_of_same_last_50 
	+ 265689741.7556;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM56(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	- 50296.771 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	- 13.7057 * parameters.avg_work_of_same_past_second 
	+ 0.2561 * parameters.avg_wait_of_same_past_second 
	- 0.018 * parameters.avg_latency_of_same_last_20 
	- 0.0226 * parameters.max_latency_of_same_last_50 
	+ 251994366.3113;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM57(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	- 0.0088 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	+ 334.5251 * parameters.total_wait_locks 
	+ 0.0569 * parameters.mean_wait_of_all 
	- 139093056.4664 * parameters.cpu_usage 
	- 0.9896 * parameters.avg_work_of_same_past_second 
	+ 0.0268 * parameters.avg_wait_of_same_past_second 
	+ 0.0181 * parameters.avg_latency_of_same_last_20 
	- 0.0038 * parameters.max_latency_of_same_last_50 
	+ 159602048.6594;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM58(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	+ 334.5251 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	- 0.288 * parameters.avg_work_of_same_past_second 
	+ 0.0008 * parameters.avg_wait_of_same_past_second 
	+ 0.0078 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 26490790.2203;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM59(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	+ 4197.2464 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	- 1.0424 * parameters.avg_work_of_same_past_second 
	- 0.0049 * parameters.avg_wait_of_same_past_second 
	+ 0.0462 * parameters.avg_latency_of_same_last_20 
	- 0.0114 * parameters.max_latency_of_same_last_50 
	+ 51741341.1947;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM60(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	+ 4197.2464 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	- 4.4572 * parameters.avg_work_of_same_past_second 
	- 0.0049 * parameters.avg_wait_of_same_past_second 
	+ 0.0126 * parameters.avg_latency_of_same_last_20 
	- 0.0154 * parameters.max_latency_of_same_last_50 
	+ 158649833.9677;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM61(work_wait &parameters) {
  double actual_remaining = 
	1.8956 * parameters.work_so_far 
	- 0.6755 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	+ 4197.2464 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	- 1.0424 * parameters.avg_work_of_same_past_second 
	- 0.0049 * parameters.avg_wait_of_same_past_second 
	+ 0.0831 * parameters.avg_latency_of_same_last_20 
	- 0.0627 * parameters.max_latency_of_same_last_50 
	+ 178653169.245;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM62(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	- 22961.4289 * parameters.total_wait_locks 
	+ 0.1562 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	- 1.0424 * parameters.avg_work_of_same_past_second 
	- 0.0049 * parameters.avg_wait_of_same_past_second 
	+ 0.0798 * parameters.avg_latency_of_same_last_20 
	- 0.0212 * parameters.max_latency_of_same_last_50 
	+ 52020334.0102;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM63(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	- 22961.4289 * parameters.total_wait_locks 
	+ 0.1562 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	- 1.0424 * parameters.avg_work_of_same_past_second 
	- 0.0049 * parameters.avg_wait_of_same_past_second 
	+ 0.0805 * parameters.avg_latency_of_same_last_20 
	- 0.0212 * parameters.max_latency_of_same_last_50 
	+ 51168045.0068;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM64(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	- 30505.5054 * parameters.total_wait_locks 
	+ 0.1996 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	- 1.0424 * parameters.avg_work_of_same_past_second 
	- 0.0049 * parameters.avg_wait_of_same_past_second 
	+ 0.0787 * parameters.avg_latency_of_same_last_20 
	- 0.0212 * parameters.max_latency_of_same_last_50 
	+ 51336972.2689;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM65(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	+ 4197.2464 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	- 1.6007 * parameters.avg_work_of_same_past_second 
	- 0.0049 * parameters.avg_wait_of_same_past_second 
	+ 0.0295 * parameters.avg_latency_of_same_last_20 
	- 0.006 * parameters.max_latency_of_same_last_50 
	+ 61942395.81;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM66(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	+ 2756.9097 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	- 0.2594 * parameters.avg_work_of_same_past_second 
	- 0.0028 * parameters.avg_wait_of_same_past_second 
	+ 0.0073 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 30964662.9943;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM67(work_wait &parameters) {
  double actual_remaining = 
	31.3975 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	+ 30439.7097 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	- 0.2594 * parameters.avg_work_of_same_past_second 
	- 0.0028 * parameters.avg_wait_of_same_past_second 
	+ 0.0073 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 18457752.4564;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM68(work_wait &parameters) {
  double actual_remaining = 
	59.2569 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	+ 23295.7613 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	- 0.2594 * parameters.avg_work_of_same_past_second 
	- 0.0028 * parameters.avg_wait_of_same_past_second 
	+ 0.0073 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 24781915.4444;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM69(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	+ 2756.9097 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	- 0.2594 * parameters.avg_work_of_same_past_second 
	- 0.0028 * parameters.avg_wait_of_same_past_second 
	+ 0.0073 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 32246058.3065;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM70(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	+ 334.5251 * parameters.total_wait_locks 
	+ 0.0555 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	+ 0.0574 * parameters.avg_work_of_same_past_second 
	+ 0.0008 * parameters.avg_wait_of_same_past_second 
	+ 0.002 * parameters.avg_latency_of_same_last_20 
	- 0.0137 * parameters.max_latency_of_same_last_50 
	+ 31885365.9306;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM71(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	- 19558.5847 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	+ 0.2788 * parameters.avg_work_of_same_past_second 
	+ 0.0506 * parameters.avg_wait_of_same_past_second 
	+ 0.0014 * parameters.avg_latency_of_same_last_20 
	+ 0.0053 * parameters.max_latency_of_same_last_50 
	+ 73164.0477;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM72(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	+ 39674.5184 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	+ 4.7315 * parameters.avg_work_of_same_past_second 
	- 0.2245 * parameters.avg_wait_of_same_past_second 
	+ 0.0014 * parameters.avg_latency_of_same_last_20 
	+ 0.0072 * parameters.max_latency_of_same_last_50 
	- 17097561.4862;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM73(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	- 7253.5017 * parameters.total_wait_locks 
	+ 0.0492 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	+ 0.0404 * parameters.avg_work_of_same_past_second 
	+ 0.0008 * parameters.avg_wait_of_same_past_second 
	+ 0.0024 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 16380654.8786;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM74(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	- 222816.7035 * parameters.total_wait_locks 
	+ 1.5077 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	+ 0.0404 * parameters.avg_work_of_same_past_second 
	+ 0.0008 * parameters.avg_wait_of_same_past_second 
	+ 0.0026 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	- 41029987.1002;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM75(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	- 24145.2685 * parameters.total_wait_locks 
	- 1.1718 * parameters.mean_wait_of_all 
	- 28904620.2674 * parameters.cpu_usage 
	- 1.9854 * parameters.avg_work_of_same_past_second 
	- 0.0129 * parameters.avg_wait_of_same_past_second 
	- 0.004 * parameters.avg_latency_of_same_last_20 
	+ 0.0236 * parameters.max_latency_of_same_last_50 
	+ 246536559.861;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM76(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	- 24145.2685 * parameters.total_wait_locks 
	- 0.7911 * parameters.mean_wait_of_all 
	- 28904620.2674 * parameters.cpu_usage 
	- 2.6475 * parameters.avg_work_of_same_past_second 
	- 0.0129 * parameters.avg_wait_of_same_past_second 
	- 0.004 * parameters.avg_latency_of_same_last_20 
	+ 0.015 * parameters.max_latency_of_same_last_50 
	+ 231477083.4657;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM77(work_wait &parameters) {
  double actual_remaining = 
	0.0015 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	- 24145.2685 * parameters.total_wait_locks 
	- 0.1113 * parameters.mean_wait_of_all 
	- 38059631.1043 * parameters.cpu_usage 
	- 0.5076 * parameters.avg_work_of_same_past_second 
	- 0.0251 * parameters.avg_wait_of_same_past_second 
	- 0.0057 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 116188093.9616;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM78(work_wait &parameters) {
  double actual_remaining = 
	-436.5659 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	+ 38665.8328 * parameters.total_wait_locks 
	- 0.2196 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	- 1.0404 * parameters.avg_work_of_same_past_second 
	+ 0.0477 * parameters.avg_wait_of_same_past_second 
	+ 0.0014 * parameters.avg_latency_of_same_last_20 
	+ 0.027 * parameters.max_latency_of_same_last_50 
	+ 10293420.9472;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM79(work_wait &parameters) {
  double actual_remaining = 
	-335.1722 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	+ 38665.8328 * parameters.total_wait_locks 
	- 0.2196 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	- 1.0404 * parameters.avg_work_of_same_past_second 
	+ 0.0477 * parameters.avg_wait_of_same_past_second 
	+ 0.0014 * parameters.avg_latency_of_same_last_20 
	+ 0.027 * parameters.max_latency_of_same_last_50 
	+ 4105719.0232;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM80(work_wait &parameters) {
  double actual_remaining = 
	8.5035 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	- 1284.5229 * parameters.num_locks_so_far 
	+ 28708.3872 * parameters.total_wait_locks 
	- 0.2196 * parameters.mean_wait_of_all 
	- 676670.1872 * parameters.cpu_usage 
	- 1.0404 * parameters.avg_work_of_same_past_second 
	+ 0.0477 * parameters.avg_wait_of_same_past_second 
	+ 0.0014 * parameters.avg_latency_of_same_last_20 
	+ 0.0239 * parameters.max_latency_of_same_last_50 
	+ 8854310.9229;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM81(work_wait &parameters) {
  double actual_remaining = 
	0.008 * parameters.work_so_far 
	- 0.0016 * parameters.wait_so_far 
	- 6663.4056 * parameters.num_locks_so_far 
	+ 1710.692 * parameters.total_wait_locks 
	- 0.0066 * parameters.mean_wait_of_all 
	- 532148.2573 * parameters.cpu_usage 
	+ 0.0017 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0034 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 4113985.8355;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM82(work_wait &parameters) {
  double actual_remaining = 
	0.1083 * parameters.work_so_far 
	- 0.0027 * parameters.wait_so_far 
	- 11938.5516 * parameters.num_locks_so_far 
	+ 1031.3666 * parameters.total_wait_locks 
	- 0.0113 * parameters.mean_wait_of_all 
	- 63813511.7755 * parameters.cpu_usage 
	+ 0.0017 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0056 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 68011630.7834;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM83(work_wait &parameters) {
  double actual_remaining = 
	0.7174 * parameters.work_so_far 
	- 0.0516 * parameters.wait_so_far 
	- 17678.5901 * parameters.num_locks_so_far 
	+ 48270.1023 * parameters.total_wait_locks 
	- 1.6774 * parameters.mean_wait_of_all 
	- 532148.2573 * parameters.cpu_usage 
	+ 0.0017 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.0207 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 148404802.4877;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM84(work_wait &parameters) {
  double actual_remaining = 
	2.4789 * parameters.work_so_far 
	- 0.0035 * parameters.wait_so_far 
	- 17678.5901 * parameters.num_locks_so_far 
	+ 134480.7951 * parameters.total_wait_locks 
	- 0.0081 * parameters.mean_wait_of_all 
	- 532148.2573 * parameters.cpu_usage 
	+ 0.0017 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.3999 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 163121532.7785;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM85(work_wait &parameters) {
  double actual_remaining = 
	0.0094 * parameters.work_so_far 
	+ 0.6762 * parameters.wait_so_far 
	- 17678.5901 * parameters.num_locks_so_far 
	+ 1031.3666 * parameters.total_wait_locks 
	- 0.0081 * parameters.mean_wait_of_all 
	- 532148.2573 * parameters.cpu_usage 
	- 0.2926 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.1115 * parameters.avg_latency_of_same_last_20 
	- 0.0405 * parameters.max_latency_of_same_last_50 
	+ 36013999.725;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM86(work_wait &parameters) {
  double actual_remaining = 
	0.0094 * parameters.work_so_far 
	+ 3.2568 * parameters.wait_so_far 
	- 17678.5901 * parameters.num_locks_so_far 
	+ 1031.3666 * parameters.total_wait_locks 
	- 0.0081 * parameters.mean_wait_of_all 
	- 532148.2573 * parameters.cpu_usage 
	- 0.2926 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.1787 * parameters.avg_latency_of_same_last_20 
	- 0.0715 * parameters.max_latency_of_same_last_50 
	+ 20630818.6306;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM87(work_wait &parameters) {
  double actual_remaining = 
	0.0094 * parameters.work_so_far 
	+ 4.0283 * parameters.wait_so_far 
	- 17678.5901 * parameters.num_locks_so_far 
	+ 1031.3666 * parameters.total_wait_locks 
	- 0.0081 * parameters.mean_wait_of_all 
	- 532148.2573 * parameters.cpu_usage 
	- 0.2926 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.1787 * parameters.avg_latency_of_same_last_20 
	- 0.0715 * parameters.max_latency_of_same_last_50 
	+ 17195753.5745;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM88(work_wait &parameters) {
  double actual_remaining = 
	0.0094 * parameters.work_so_far 
	- 0.0079 * parameters.wait_so_far 
	- 17678.5901 * parameters.num_locks_so_far 
	+ 1031.3666 * parameters.total_wait_locks 
	- 0.0081 * parameters.mean_wait_of_all 
	- 532148.2573 * parameters.cpu_usage 
	- 0.1304 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.018 * parameters.avg_latency_of_same_last_20 
	- 0.0024 * parameters.max_latency_of_same_last_50 
	+ 21024788.3596;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM89(work_wait &parameters) {
  double actual_remaining = 
	0.022 * parameters.work_so_far 
	- 0.0077 * parameters.wait_so_far 
	- 26681.9159 * parameters.num_locks_so_far 
	+ 4742.86 * parameters.total_wait_locks 
	- 0.0081 * parameters.mean_wait_of_all 
	- 532148.2573 * parameters.cpu_usage 
	+ 0.0017 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0041 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 9084823.5837;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM90(work_wait &parameters) {
  double actual_remaining = 
	0.0286 * parameters.work_so_far 
	- 0.0385 * parameters.wait_so_far 
	- 26681.9159 * parameters.num_locks_so_far 
	+ 6686.9756 * parameters.total_wait_locks 
	- 0.0081 * parameters.mean_wait_of_all 
	- 532148.2573 * parameters.cpu_usage 
	+ 0.0017 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0041 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 25166123.1456;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM91(work_wait &parameters) {
  double actual_remaining = 
	69.8498 * parameters.work_so_far 
	+ 0.062 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	+ 270.6093 * parameters.total_wait_locks 
	+ 17.8161 * parameters.mean_wait_of_all 
	+ 1953707.4274 * parameters.cpu_usage 
	- 0.6668 * parameters.avg_work_of_same_past_second 
	- 0.0009 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	+ 0.0013 * parameters.max_latency_of_same_last_50 
	- 1067499778.4087;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM92(work_wait &parameters) {
  double actual_remaining = 
	79.9968 * parameters.work_so_far 
	+ 0.0814 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	+ 270.6093 * parameters.total_wait_locks 
	+ 24.9427 * parameters.mean_wait_of_all 
	+ 1953707.4274 * parameters.cpu_usage 
	- 0.6668 * parameters.avg_work_of_same_past_second 
	- 0.0009 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	+ 0.0013 * parameters.max_latency_of_same_last_50 
	- 1502590006.1128;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM93(work_wait &parameters) {
  double actual_remaining = 
	31.2322 * parameters.work_so_far 
	+ 0.0093 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	+ 270.6093 * parameters.total_wait_locks 
	- 0.0005 * parameters.mean_wait_of_all 
	+ 1953707.4274 * parameters.cpu_usage 
	- 0.4797 * parameters.avg_work_of_same_past_second 
	- 0.0009 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	+ 0.0013 * parameters.max_latency_of_same_last_50 
	+ 23506068.8541;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM94(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	+ 270.6093 * parameters.total_wait_locks 
	- 0.0005 * parameters.mean_wait_of_all 
	+ 1953707.4274 * parameters.cpu_usage 
	- 0.0127 * parameters.avg_work_of_same_past_second 
	- 0.0009 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	+ 0.0013 * parameters.max_latency_of_same_last_50 
	+ 9284121.3753;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM95(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	+ 270.6093 * parameters.total_wait_locks 
	- 0.0005 * parameters.mean_wait_of_all 
	+ 37361870.5497 * parameters.cpu_usage 
	+ 0.0004 * parameters.avg_work_of_same_past_second 
	- 0.0009 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	- 0.0254 * parameters.max_latency_of_same_last_50 
	+ 8517319.8724;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM96(work_wait &parameters) {
  double actual_remaining = 
	51.3124 * parameters.work_so_far 
	- 0.0038 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	+ 41401.5546 * parameters.total_wait_locks 
	- 0.0116 * parameters.mean_wait_of_all 
	- 21140641.9017 * parameters.cpu_usage 
	- 1.2766 * parameters.avg_work_of_same_past_second 
	- 0.0008 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 109632040.0763;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM97(work_wait &parameters) {
  double actual_remaining = 
	-0.072 * parameters.work_so_far 
	- 0.0038 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	+ 41401.5546 * parameters.total_wait_locks 
	- 0.0116 * parameters.mean_wait_of_all 
	- 21140641.9017 * parameters.cpu_usage 
	- 1.2766 * parameters.avg_work_of_same_past_second 
	- 0.0008 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 109715900.7294;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM98(work_wait &parameters) {
  double actual_remaining = 
	-0.0526 * parameters.work_so_far 
	- 0.0038 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	+ 89679.4571 * parameters.total_wait_locks 
	- 0.0116 * parameters.mean_wait_of_all 
	- 21140641.9017 * parameters.cpu_usage 
	- 1.2766 * parameters.avg_work_of_same_past_second 
	- 0.0008 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 107003030.9528;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM99(work_wait &parameters) {
  double actual_remaining = 
	-0.0526 * parameters.work_so_far 
	- 0.0038 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	+ 14463.4954 * parameters.total_wait_locks 
	- 0.0116 * parameters.mean_wait_of_all 
	- 21140641.9017 * parameters.cpu_usage 
	- 1.2766 * parameters.avg_work_of_same_past_second 
	- 0.0008 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 119781313.0305;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM100(work_wait &parameters) {
  double actual_remaining = 
	-0.0526 * parameters.work_so_far 
	- 0.0038 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	+ 29820.7014 * parameters.total_wait_locks 
	- 0.0116 * parameters.mean_wait_of_all 
	- 21140641.9017 * parameters.cpu_usage 
	- 1.2766 * parameters.avg_work_of_same_past_second 
	- 0.0008 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 119077386.2341;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM101(work_wait &parameters) {
  double actual_remaining = 
	-0.0176 * parameters.work_so_far 
	- 0.0038 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 12642.4269 * parameters.total_wait_locks 
	+ 0.5323 * parameters.mean_wait_of_all 
	- 21140641.9017 * parameters.cpu_usage 
	- 1.0549 * parameters.avg_work_of_same_past_second 
	- 0.0008 * parameters.avg_wait_of_same_past_second 
	- 0.0516 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 73372729.0426;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM102(work_wait &parameters) {
  double actual_remaining = 
	1.2797 * parameters.work_so_far 
	- 0.0055 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 2054.0658 * parameters.total_wait_locks 
	- 0.0049 * parameters.mean_wait_of_all 
	- 18171343.3257 * parameters.cpu_usage 
	- 0.0297 * parameters.avg_work_of_same_past_second 
	+ 0.0112 * parameters.avg_wait_of_same_past_second 
	+ 0.0053 * parameters.avg_latency_of_same_last_20 
	+ 0.0259 * parameters.max_latency_of_same_last_50 
	+ 7212070.6882;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM103(work_wait &parameters) {
  double actual_remaining = 
	0.0045 * parameters.work_so_far 
	- 0.0031 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 2054.0658 * parameters.total_wait_locks 
	- 0.002 * parameters.mean_wait_of_all 
	- 10730232.5042 * parameters.cpu_usage 
	- 0.0297 * parameters.avg_work_of_same_past_second 
	+ 0.0032 * parameters.avg_wait_of_same_past_second 
	+ 0.0043 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 25363369.0594;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM104(work_wait &parameters) {
  double actual_remaining = 
	0.0042 * parameters.work_so_far 
	- 0.0063 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 2054.0658 * parameters.total_wait_locks 
	+ 0.0059 * parameters.mean_wait_of_all 
	- 10730232.5042 * parameters.cpu_usage 
	- 0.0297 * parameters.avg_work_of_same_past_second 
	+ 0.0032 * parameters.avg_wait_of_same_past_second 
	+ 0.0235 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 19390271.6772;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM105(work_wait &parameters) {
  double actual_remaining = 
	0.0042 * parameters.work_so_far 
	- 0.014 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 2054.0658 * parameters.total_wait_locks 
	+ 0.0093 * parameters.mean_wait_of_all 
	- 10730232.5042 * parameters.cpu_usage 
	- 0.0297 * parameters.avg_work_of_same_past_second 
	+ 0.0032 * parameters.avg_wait_of_same_past_second 
	+ 0.0129 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 32331363.8529;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM106(work_wait &parameters) {
  double actual_remaining = 
	0.0042 * parameters.work_so_far 
	- 0.0058 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 2054.0658 * parameters.total_wait_locks 
	- 0.0022 * parameters.mean_wait_of_all 
	- 10730232.5042 * parameters.cpu_usage 
	- 0.0297 * parameters.avg_work_of_same_past_second 
	+ 0.0032 * parameters.avg_wait_of_same_past_second 
	+ 0.0099 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 24720667.0877;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM107(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.14 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 46033.4231 * parameters.total_wait_locks 
	- 0.3036 * parameters.mean_wait_of_all 
	+ 35367091.2094 * parameters.cpu_usage 
	- 1.8041 * parameters.avg_work_of_same_past_second 
	+ 0.0403 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	- 0.0901 * parameters.max_latency_of_same_last_50 
	+ 233781149.2668;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM108(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.14 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 46033.4231 * parameters.total_wait_locks 
	- 0.3036 * parameters.mean_wait_of_all 
	+ 35367091.2094 * parameters.cpu_usage 
	- 1.9356 * parameters.avg_work_of_same_past_second 
	+ 0.0403 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	- 0.0331 * parameters.max_latency_of_same_last_50 
	+ 160919715.0866;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM109(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.1344 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 46033.4231 * parameters.total_wait_locks 
	- 0.2649 * parameters.mean_wait_of_all 
	+ 35367091.2094 * parameters.cpu_usage 
	- 0.9623 * parameters.avg_work_of_same_past_second 
	+ 0.0403 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	- 0.0306 * parameters.max_latency_of_same_last_50 
	+ 102294686.18;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM110(work_wait &parameters) {
  double actual_remaining = 
	186.0899 * parameters.work_so_far 
	+ 0.1391 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 46033.4231 * parameters.total_wait_locks 
	+ 0.2125 * parameters.mean_wait_of_all 
	+ 35367091.2094 * parameters.cpu_usage 
	- 0.3159 * parameters.avg_work_of_same_past_second 
	+ 0.0403 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	- 0.0748 * parameters.max_latency_of_same_last_50 
	+ 103086928.672;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM111(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0011 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 347987.4104 * parameters.total_wait_locks 
	+ 2.144 * parameters.mean_wait_of_all 
	+ 15747091.2435 * parameters.cpu_usage 
	- 1.0452 * parameters.avg_work_of_same_past_second 
	+ 0.1385 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	- 63047671.9507;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM112(work_wait &parameters) {
  double actual_remaining = 
	0.2228 * parameters.work_so_far 
	- 0.0006 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	+ 53403.2841 * parameters.total_wait_locks 
	- 0.4517 * parameters.mean_wait_of_all 
	+ 61976401.6849 * parameters.cpu_usage 
	- 0.0014 * parameters.avg_work_of_same_past_second 
	+ 0.0823 * parameters.avg_wait_of_same_past_second 
	+ 0.0033 * parameters.avg_latency_of_same_last_20 
	+ 0.0127 * parameters.max_latency_of_same_last_50 
	- 70298220.3745;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM113(work_wait &parameters) {
  double actual_remaining = 
	0.0041 * parameters.work_so_far 
	- 0.0006 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 3736.5608 * parameters.total_wait_locks 
	- 0.2912 * parameters.mean_wait_of_all 
	+ 4786600.291 * parameters.cpu_usage 
	- 0.0014 * parameters.avg_work_of_same_past_second 
	+ 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0041 * parameters.avg_latency_of_same_last_20 
	- 0.0029 * parameters.max_latency_of_same_last_50 
	+ 66107315.3054;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM114(work_wait &parameters) {
  double actual_remaining = 
	0.0041 * parameters.work_so_far 
	- 0.0006 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 3736.5608 * parameters.total_wait_locks 
	+ 0.0109 * parameters.mean_wait_of_all 
	+ 4786600.291 * parameters.cpu_usage 
	- 4.1076 * parameters.avg_work_of_same_past_second 
	+ 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0041 * parameters.avg_latency_of_same_last_20 
	- 0.0029 * parameters.max_latency_of_same_last_50 
	+ 162602347.1445;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM115(work_wait &parameters) {
  double actual_remaining = 
	-251.6874 * parameters.work_so_far 
	- 0.0006 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 3736.5608 * parameters.total_wait_locks 
	+ 0.0109 * parameters.mean_wait_of_all 
	+ 4786600.291 * parameters.cpu_usage 
	- 4.1076 * parameters.avg_work_of_same_past_second 
	+ 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0041 * parameters.avg_latency_of_same_last_20 
	- 0.0029 * parameters.max_latency_of_same_last_50 
	+ 173014151.7572;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM116(work_wait &parameters) {
  double actual_remaining = 
	0.0041 * parameters.work_so_far 
	- 0.0006 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 3736.5608 * parameters.total_wait_locks 
	+ 0.0109 * parameters.mean_wait_of_all 
	+ 4786600.291 * parameters.cpu_usage 
	- 4.4987 * parameters.avg_work_of_same_past_second 
	+ 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0041 * parameters.avg_latency_of_same_last_20 
	- 0.0029 * parameters.max_latency_of_same_last_50 
	+ 167991444.2216;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM117(work_wait &parameters) {
  double actual_remaining = 
	0.4987 * parameters.work_so_far 
	- 0.0006 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 3736.5608 * parameters.total_wait_locks 
	- 0.2123 * parameters.mean_wait_of_all 
	+ 4786600.291 * parameters.cpu_usage 
	+ 0.233 * parameters.avg_work_of_same_past_second 
	+ 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0041 * parameters.avg_latency_of_same_last_20 
	- 0.0023 * parameters.max_latency_of_same_last_50 
	+ 40228937.35;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM118(work_wait &parameters) {
  double actual_remaining = 
	0.0041 * parameters.work_so_far 
	+ 0.0302 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 37507.0274 * parameters.total_wait_locks 
	+ 0.2391 * parameters.mean_wait_of_all 
	- 102391020.262 * parameters.cpu_usage 
	- 1.3127 * parameters.avg_work_of_same_past_second 
	- 0.1724 * parameters.avg_wait_of_same_past_second 
	+ 0.0038 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 276759963.6286;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM119(work_wait &parameters) {
  double actual_remaining = 
	0.0041 * parameters.work_so_far 
	- 0.0022 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 37507.0274 * parameters.total_wait_locks 
	+ 0.2391 * parameters.mean_wait_of_all 
	- 102391020.262 * parameters.cpu_usage 
	- 1.3127 * parameters.avg_work_of_same_past_second 
	- 0.1724 * parameters.avg_wait_of_same_past_second 
	+ 0.0513 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 244685299.8667;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM120(work_wait &parameters) {
  double actual_remaining = 
	0.0041 * parameters.work_so_far 
	- 0.019 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 37507.0274 * parameters.total_wait_locks 
	+ 0.2391 * parameters.mean_wait_of_all 
	- 42094650.7814 * parameters.cpu_usage 
	- 0.5466 * parameters.avg_work_of_same_past_second 
	- 0.0714 * parameters.avg_wait_of_same_past_second 
	+ 0.0038 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 124632259.4434;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM121(work_wait &parameters) {
  double actual_remaining = 
	0.2097 * parameters.work_so_far 
	- 0.0019 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 21445.4374 * parameters.total_wait_locks 
	+ 0.1409 * parameters.mean_wait_of_all 
	+ 808535.1953 * parameters.cpu_usage 
	- 0.0014 * parameters.avg_work_of_same_past_second 
	+ 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0235 * parameters.avg_latency_of_same_last_20 
	- 0.0187 * parameters.max_latency_of_same_last_50 
	+ 32676253.0704;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM122(work_wait &parameters) {
  double actual_remaining = 
	-1.0627 * parameters.work_so_far 
	- 0.0064 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	+ 24015.7161 * parameters.total_wait_locks 
	- 0.1465 * parameters.mean_wait_of_all 
	+ 808535.1953 * parameters.cpu_usage 
	+ 1.7263 * parameters.avg_work_of_same_past_second 
	- 0.6548 * parameters.avg_wait_of_same_past_second 
	+ 0.0104 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 377081971.1846;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM123(work_wait &parameters) {
  double actual_remaining = 
	0.0041 * parameters.work_so_far 
	- 0.0064 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	+ 24015.7161 * parameters.total_wait_locks 
	- 0.1465 * parameters.mean_wait_of_all 
	+ 808535.1953 * parameters.cpu_usage 
	+ 0.8175 * parameters.avg_work_of_same_past_second 
	- 0.6765 * parameters.avg_wait_of_same_past_second 
	+ 0.0104 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 419321330.3236;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM124(work_wait &parameters) {
  double actual_remaining = 
	0.0041 * parameters.work_so_far 
	- 0.0064 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	+ 44332.5909 * parameters.total_wait_locks 
	- 0.2031 * parameters.mean_wait_of_all 
	+ 808535.1953 * parameters.cpu_usage 
	- 0.0014 * parameters.avg_work_of_same_past_second 
	- 0.1133 * parameters.avg_wait_of_same_past_second 
	+ 0.0265 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 89244673.4013;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM125(work_wait &parameters) {
  double actual_remaining = 
	0.0041 * parameters.work_so_far 
	- 0.0064 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	+ 68204.0027 * parameters.total_wait_locks 
	- 0.3092 * parameters.mean_wait_of_all 
	+ 808535.1953 * parameters.cpu_usage 
	- 0.0014 * parameters.avg_work_of_same_past_second 
	- 0.1133 * parameters.avg_wait_of_same_past_second 
	+ 0.0335 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 86972416.7822;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM126(work_wait &parameters) {
  double actual_remaining = 
	0.0041 * parameters.work_so_far 
	- 0.0064 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	+ 64487.8723 * parameters.total_wait_locks 
	- 0.2923 * parameters.mean_wait_of_all 
	+ 808535.1953 * parameters.cpu_usage 
	- 0.0014 * parameters.avg_work_of_same_past_second 
	- 0.1133 * parameters.avg_wait_of_same_past_second 
	+ 0.0425 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 86665104.6827;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM127(work_wait &parameters) {
  double actual_remaining = 
	0.0041 * parameters.work_so_far 
	- 0.0069 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 12177.104 * parameters.total_wait_locks 
	+ 0.0957 * parameters.mean_wait_of_all 
	+ 808535.1953 * parameters.cpu_usage 
	- 0.0014 * parameters.avg_work_of_same_past_second 
	- 0.1111 * parameters.avg_wait_of_same_past_second 
	+ 0.0281 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 74228369.2542;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM128(work_wait &parameters) {
  double actual_remaining = 
	0.0041 * parameters.work_so_far 
	- 0.0069 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 12177.104 * parameters.total_wait_locks 
	+ 0.0957 * parameters.mean_wait_of_all 
	+ 808535.1953 * parameters.cpu_usage 
	- 0.0014 * parameters.avg_work_of_same_past_second 
	- 0.1111 * parameters.avg_wait_of_same_past_second 
	+ 0.024 * parameters.avg_latency_of_same_last_20 
	- 0.039 * parameters.max_latency_of_same_last_50 
	+ 144832705.0531;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM129(work_wait &parameters) {
  double actual_remaining = 
	0.0041 * parameters.work_so_far 
	- 0.0069 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 12177.104 * parameters.total_wait_locks 
	+ 0.0957 * parameters.mean_wait_of_all 
	+ 808535.1953 * parameters.cpu_usage 
	- 0.0014 * parameters.avg_work_of_same_past_second 
	- 0.1137 * parameters.avg_wait_of_same_past_second 
	+ 0.011 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 81522005.9625;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM130(work_wait &parameters) {
  double actual_remaining = 
	0.5073 * parameters.work_so_far 
	- 0.01 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	+ 125.4668 * parameters.total_wait_locks 
	+ 0.2673 * parameters.mean_wait_of_all 
	+ 67556016.2791 * parameters.cpu_usage 
	+ 0.0031 * parameters.avg_work_of_same_past_second 
	+ 0.0024 * parameters.avg_wait_of_same_past_second 
	+ 0.0452 * parameters.avg_latency_of_same_last_20 
	- 0.0148 * parameters.max_latency_of_same_last_50 
	- 66419048.3624;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM131(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0011 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 62027.3829 * parameters.total_wait_locks 
	+ 0.4636 * parameters.mean_wait_of_all 
	+ 23266812.9283 * parameters.cpu_usage 
	+ 0.3247 * parameters.avg_work_of_same_past_second 
	+ 0.0102 * parameters.avg_wait_of_same_past_second 
	+ 0.0129 * parameters.avg_latency_of_same_last_20 
	- 0.001 * parameters.max_latency_of_same_last_50 
	- 44382753.1927;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM132(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0011 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 21009.975 * parameters.total_wait_locks 
	+ 0.4636 * parameters.mean_wait_of_all 
	+ 177765511.6833 * parameters.cpu_usage 
	+ 0.3247 * parameters.avg_work_of_same_past_second 
	+ 0.0102 * parameters.avg_wait_of_same_past_second 
	+ 0.0129 * parameters.avg_latency_of_same_last_20 
	- 0.1388 * parameters.max_latency_of_same_last_50 
	+ 117497571.2282;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM133(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0011 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	+ 456143.4706 * parameters.total_wait_locks 
	- 0.0049 * parameters.mean_wait_of_all 
	+ 23266812.9283 * parameters.cpu_usage 
	+ 0.3247 * parameters.avg_work_of_same_past_second 
	- 0.229 * parameters.avg_wait_of_same_past_second 
	+ 0.0354 * parameters.avg_latency_of_same_last_20 
	- 0.0044 * parameters.max_latency_of_same_last_50 
	- 77823693.4678;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM134(work_wait &parameters) {
  double actual_remaining = 
	-0.6693 * parameters.work_so_far 
	- 0.0011 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	+ 291887.1829 * parameters.total_wait_locks 
	+ 0.4445 * parameters.mean_wait_of_all 
	+ 23266812.9283 * parameters.cpu_usage 
	- 0.6329 * parameters.avg_work_of_same_past_second 
	- 0.1259 * parameters.avg_wait_of_same_past_second 
	+ 0.0361 * parameters.avg_latency_of_same_last_20 
	- 0.0293 * parameters.max_latency_of_same_last_50 
	- 19310227.3156;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM135(work_wait &parameters) {
  double actual_remaining = 
	-0.2236 * parameters.work_so_far 
	- 0.0011 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	+ 110082.4769 * parameters.total_wait_locks 
	+ 0.4445 * parameters.mean_wait_of_all 
	+ 23266812.9283 * parameters.cpu_usage 
	- 0.6329 * parameters.avg_work_of_same_past_second 
	- 0.1259 * parameters.avg_wait_of_same_past_second 
	+ 0.0361 * parameters.avg_latency_of_same_last_20 
	- 0.0177 * parameters.max_latency_of_same_last_50 
	+ 31383949.4465;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM136(work_wait &parameters) {
  double actual_remaining = 
	-0.1822 * parameters.work_so_far 
	- 0.0011 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 24065.9723 * parameters.total_wait_locks 
	+ 0.5374 * parameters.mean_wait_of_all 
	+ 23266812.9283 * parameters.cpu_usage 
	- 0.6329 * parameters.avg_work_of_same_past_second 
	- 0.1259 * parameters.avg_wait_of_same_past_second 
	+ 0.0399 * parameters.avg_latency_of_same_last_20 
	- 0.009 * parameters.max_latency_of_same_last_50 
	+ 65990498.6346;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM137(work_wait &parameters) {
  double actual_remaining = 
	-0.1635 * parameters.work_so_far 
	- 0.0011 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 45815.9077 * parameters.total_wait_locks 
	+ 0.1911 * parameters.mean_wait_of_all 
	+ 23266812.9283 * parameters.cpu_usage 
	- 1.7379 * parameters.avg_work_of_same_past_second 
	- 0.1259 * parameters.avg_wait_of_same_past_second 
	+ 0.0256 * parameters.avg_latency_of_same_last_20 
	- 0.0044 * parameters.max_latency_of_same_last_50 
	+ 139724778.5953;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM138(work_wait &parameters) {
  double actual_remaining = 
	-7.4184 * parameters.work_so_far 
	- 0.0291 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	+ 74570.3459 * parameters.total_wait_locks 
	+ 0.3492 * parameters.mean_wait_of_all 
	+ 23266812.9283 * parameters.cpu_usage 
	- 8.9781 * parameters.avg_work_of_same_past_second 
	- 0.069 * parameters.avg_wait_of_same_past_second 
	+ 0.0153 * parameters.avg_latency_of_same_last_20 
	- 0.0053 * parameters.max_latency_of_same_last_50 
	+ 378300871.8598;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM139(work_wait &parameters) {
  double actual_remaining = 
	-7.6323 * parameters.work_so_far 
	- 0.1015 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 45809.78 * parameters.total_wait_locks 
	+ 0.3492 * parameters.mean_wait_of_all 
	+ 23266812.9283 * parameters.cpu_usage 
	- 8.9781 * parameters.avg_work_of_same_past_second 
	- 0.069 * parameters.avg_wait_of_same_past_second 
	+ 0.0153 * parameters.avg_latency_of_same_last_20 
	- 0.0053 * parameters.max_latency_of_same_last_50 
	+ 424708815.9191;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM140(work_wait &parameters) {
  double actual_remaining = 
	-7.6323 * parameters.work_so_far 
	- 0.0975 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 45809.78 * parameters.total_wait_locks 
	+ 0.3492 * parameters.mean_wait_of_all 
	+ 23266812.9283 * parameters.cpu_usage 
	- 8.9781 * parameters.avg_work_of_same_past_second 
	- 0.069 * parameters.avg_wait_of_same_past_second 
	+ 0.0153 * parameters.avg_latency_of_same_last_20 
	- 0.0053 * parameters.max_latency_of_same_last_50 
	+ 422102182.4543;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM141(work_wait &parameters) {
  double actual_remaining = 
	-6.4792 * parameters.work_so_far 
	- 0.0328 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 45809.78 * parameters.total_wait_locks 
	+ 0.3492 * parameters.mean_wait_of_all 
	+ 23266812.9283 * parameters.cpu_usage 
	- 11.0924 * parameters.avg_work_of_same_past_second 
	- 0.069 * parameters.avg_wait_of_same_past_second 
	+ 0.0153 * parameters.avg_latency_of_same_last_20 
	- 0.0053 * parameters.max_latency_of_same_last_50 
	+ 463046256.1564;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM142(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0061 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 45809.78 * parameters.total_wait_locks 
	+ 0.3492 * parameters.mean_wait_of_all 
	+ 23266812.9283 * parameters.cpu_usage 
	+ 0.3247 * parameters.avg_work_of_same_past_second 
	- 0.2042 * parameters.avg_wait_of_same_past_second 
	+ 0.0153 * parameters.avg_latency_of_same_last_20 
	- 0.0053 * parameters.max_latency_of_same_last_50 
	+ 109399683.5285;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM143(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.0182 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	+ 63586.0124 * parameters.total_wait_locks 
	+ 0.2289 * parameters.mean_wait_of_all 
	- 249663522.3899 * parameters.cpu_usage 
	+ 0.8361 * parameters.avg_work_of_same_past_second 
	+ 0.2626 * parameters.avg_wait_of_same_past_second 
	+ 0.0446 * parameters.avg_latency_of_same_last_20 
	- 0.005 * parameters.max_latency_of_same_last_50 
	+ 50758720.4355;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM144(work_wait &parameters) {
  double actual_remaining = 
	-49.2345 * parameters.work_so_far 
	+ 0.0182 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	+ 63586.0124 * parameters.total_wait_locks 
	+ 0.2289 * parameters.mean_wait_of_all 
	- 249663522.3899 * parameters.cpu_usage 
	+ 0.8361 * parameters.avg_work_of_same_past_second 
	+ 0.2626 * parameters.avg_wait_of_same_past_second 
	+ 0.0446 * parameters.avg_latency_of_same_last_20 
	- 0.005 * parameters.max_latency_of_same_last_50 
	+ 54727200.4948;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM145(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.0093 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	+ 63586.0124 * parameters.total_wait_locks 
	+ 1.158 * parameters.mean_wait_of_all 
	- 249663522.3899 * parameters.cpu_usage 
	+ 0.8361 * parameters.avg_work_of_same_past_second 
	+ 0.1914 * parameters.avg_wait_of_same_past_second 
	+ 0.0446 * parameters.avg_latency_of_same_last_20 
	- 0.005 * parameters.max_latency_of_same_last_50 
	+ 4779383.8598;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM146(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.0093 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	+ 922832.7045 * parameters.total_wait_locks 
	- 6.0802 * parameters.mean_wait_of_all 
	- 249663522.3899 * parameters.cpu_usage 
	- 1.7739 * parameters.avg_work_of_same_past_second 
	+ 0.1914 * parameters.avg_wait_of_same_past_second 
	+ 0.0446 * parameters.avg_latency_of_same_last_20 
	- 0.005 * parameters.max_latency_of_same_last_50 
	+ 609260790.2761;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM147(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.0093 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	+ 1110269.5271 * parameters.total_wait_locks 
	- 6.2961 * parameters.mean_wait_of_all 
	- 249663522.3899 * parameters.cpu_usage 
	- 1.7739 * parameters.avg_work_of_same_past_second 
	+ 0.1914 * parameters.avg_wait_of_same_past_second 
	+ 0.0446 * parameters.avg_latency_of_same_last_20 
	- 0.005 * parameters.max_latency_of_same_last_50 
	+ 524654440.829;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM148(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.0093 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	+ 627746.0166 * parameters.total_wait_locks 
	- 1.0273 * parameters.mean_wait_of_all 
	- 249663522.3899 * parameters.cpu_usage 
	- 0.998 * parameters.avg_work_of_same_past_second 
	+ 0.1914 * parameters.avg_wait_of_same_past_second 
	+ 0.0446 * parameters.avg_latency_of_same_last_20 
	- 0.005 * parameters.max_latency_of_same_last_50 
	+ 52219506.5473;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM149(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0081 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	+ 96762.9195 * parameters.total_wait_locks 
	+ 0.3686 * parameters.mean_wait_of_all 
	- 437227411.2765 * parameters.cpu_usage 
	- 2.806 * parameters.avg_work_of_same_past_second 
	+ 0.1845 * parameters.avg_wait_of_same_past_second 
	+ 0.0631 * parameters.avg_latency_of_same_last_20 
	+ 0.0098 * parameters.max_latency_of_same_last_50 
	+ 309690358.9144;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM150(work_wait &parameters) {
  double actual_remaining = 
	-0.3023 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	+ 82236.0743 * parameters.total_wait_locks 
	+ 0.9685 * parameters.mean_wait_of_all 
	+ 2691798.8981 * parameters.cpu_usage 
	- 0.3616 * parameters.avg_work_of_same_past_second 
	+ 0.0957 * parameters.avg_wait_of_same_past_second 
	+ 0.0035 * parameters.avg_latency_of_same_last_20 
	- 0.0021 * parameters.max_latency_of_same_last_50 
	- 118593828.755;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM151(work_wait &parameters) {
  double actual_remaining = 
	-0.3023 * parameters.work_so_far 
	+ 0.0014 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 223914.8714 * parameters.total_wait_locks 
	+ 0.9685 * parameters.mean_wait_of_all 
	+ 2691798.8981 * parameters.cpu_usage 
	+ 0.1575 * parameters.avg_work_of_same_past_second 
	+ 0.0957 * parameters.avg_wait_of_same_past_second 
	+ 0.0035 * parameters.avg_latency_of_same_last_20 
	- 0.0021 * parameters.max_latency_of_same_last_50 
	- 16208630.4288;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM152(work_wait &parameters) {
  double actual_remaining = 
	-0.3023 * parameters.work_so_far 
	+ 0.0002 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 223914.8714 * parameters.total_wait_locks 
	+ 0.9685 * parameters.mean_wait_of_all 
	+ 2691798.8981 * parameters.cpu_usage 
	+ 0.1575 * parameters.avg_work_of_same_past_second 
	+ 0.0866 * parameters.avg_wait_of_same_past_second 
	+ 0.0035 * parameters.avg_latency_of_same_last_20 
	- 0.0021 * parameters.max_latency_of_same_last_50 
	- 8207158.5381;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM153(work_wait &parameters) {
  double actual_remaining = 
	-0.3023 * parameters.work_so_far 
	+ 0.0004 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 223914.8714 * parameters.total_wait_locks 
	+ 0.9685 * parameters.mean_wait_of_all 
	+ 2691798.8981 * parameters.cpu_usage 
	+ 0.1575 * parameters.avg_work_of_same_past_second 
	+ 0.0866 * parameters.avg_wait_of_same_past_second 
	+ 0.0035 * parameters.avg_latency_of_same_last_20 
	- 0.0021 * parameters.max_latency_of_same_last_50 
	- 8499021.7309;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM154(work_wait &parameters) {
  double actual_remaining = 
	-0.3023 * parameters.work_so_far 
	+ 0.0014 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 223914.8714 * parameters.total_wait_locks 
	+ 0.9685 * parameters.mean_wait_of_all 
	+ 2691798.8981 * parameters.cpu_usage 
	+ 0.1575 * parameters.avg_work_of_same_past_second 
	+ 0.0857 * parameters.avg_wait_of_same_past_second 
	+ 0.0035 * parameters.avg_latency_of_same_last_20 
	- 0.0021 * parameters.max_latency_of_same_last_50 
	- 9847823.9697;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM155(work_wait &parameters) {
  double actual_remaining = 
	-1.0056 * parameters.work_so_far 
	+ 0.0057 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 259189.4301 * parameters.total_wait_locks 
	+ 0.9685 * parameters.mean_wait_of_all 
	+ 2691798.8981 * parameters.cpu_usage 
	+ 4.6513 * parameters.avg_work_of_same_past_second 
	+ 0.1523 * parameters.avg_wait_of_same_past_second 
	+ 0.0035 * parameters.avg_latency_of_same_last_20 
	- 0.0021 * parameters.max_latency_of_same_last_50 
	- 178528885.4132;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM156(work_wait &parameters) {
  double actual_remaining = 
	-0.9543 * parameters.work_so_far 
	+ 0.0057 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 259189.4301 * parameters.total_wait_locks 
	+ 0.9685 * parameters.mean_wait_of_all 
	+ 2691798.8981 * parameters.cpu_usage 
	+ 4.6513 * parameters.avg_work_of_same_past_second 
	+ 0.1523 * parameters.avg_wait_of_same_past_second 
	+ 0.0035 * parameters.avg_latency_of_same_last_20 
	- 0.0021 * parameters.max_latency_of_same_last_50 
	- 172616819.7609;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM157(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.0154 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 171157.6305 * parameters.total_wait_locks 
	+ 0.8714 * parameters.mean_wait_of_all 
	+ 2691798.8981 * parameters.cpu_usage 
	- 0.0349 * parameters.avg_work_of_same_past_second 
	+ 0.0463 * parameters.avg_wait_of_same_past_second 
	+ 0.0035 * parameters.avg_latency_of_same_last_20 
	- 0.0021 * parameters.max_latency_of_same_last_50 
	- 14138707.2588;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM158(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.0156 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 160614.9913 * parameters.total_wait_locks 
	+ 0.8714 * parameters.mean_wait_of_all 
	+ 2691798.8981 * parameters.cpu_usage 
	- 0.0349 * parameters.avg_work_of_same_past_second 
	+ 0.0463 * parameters.avg_wait_of_same_past_second 
	+ 0.0035 * parameters.avg_latency_of_same_last_20 
	- 0.0021 * parameters.max_latency_of_same_last_50 
	- 15602763.3965;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM159(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.0156 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 161075.9412 * parameters.total_wait_locks 
	+ 0.8714 * parameters.mean_wait_of_all 
	+ 2691798.8981 * parameters.cpu_usage 
	- 0.0349 * parameters.avg_work_of_same_past_second 
	+ 0.0463 * parameters.avg_wait_of_same_past_second 
	+ 0.0035 * parameters.avg_latency_of_same_last_20 
	- 0.0021 * parameters.max_latency_of_same_last_50 
	- 13668491.6854;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM160(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.0127 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 158061.3455 * parameters.total_wait_locks 
	+ 0.7048 * parameters.mean_wait_of_all 
	+ 2691798.8981 * parameters.cpu_usage 
	- 0.0349 * parameters.avg_work_of_same_past_second 
	+ 0.0463 * parameters.avg_wait_of_same_past_second 
	+ 0.0035 * parameters.avg_latency_of_same_last_20 
	- 0.0021 * parameters.max_latency_of_same_last_50 
	- 3324815.0382;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM161(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 78529.8893 * parameters.total_wait_locks 
	+ 0.5117 * parameters.mean_wait_of_all 
	- 122937001.7983 * parameters.cpu_usage 
	- 0.186 * parameters.avg_work_of_same_past_second 
	+ 0.003 * parameters.avg_wait_of_same_past_second 
	+ 0.0035 * parameters.avg_latency_of_same_last_20 
	- 0.0012 * parameters.max_latency_of_same_last_50 
	+ 132665347.8702;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM162(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 78529.8893 * parameters.total_wait_locks 
	+ 0.5117 * parameters.mean_wait_of_all 
	+ 2691798.8981 * parameters.cpu_usage 
	- 0.2071 * parameters.avg_work_of_same_past_second 
	+ 0.003 * parameters.avg_wait_of_same_past_second 
	+ 0.0035 * parameters.avg_latency_of_same_last_20 
	- 0.0012 * parameters.max_latency_of_same_last_50 
	+ 4879364.2846;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM163(work_wait &parameters) {
  double actual_remaining = 
	-0.0856 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 163351.2589 * parameters.total_wait_locks 
	+ 1.1894 * parameters.mean_wait_of_all 
	- 8248102.5454 * parameters.cpu_usage 
	- 0.0349 * parameters.avg_work_of_same_past_second 
	+ 0.003 * parameters.avg_wait_of_same_past_second 
	+ 0.0345 * parameters.avg_latency_of_same_last_20 
	- 0.0012 * parameters.max_latency_of_same_last_50 
	- 40689095.6268;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM164(work_wait &parameters) {
  double actual_remaining = 
	-0.0569 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 554170.6814 * parameters.total_wait_locks 
	+ 1.8344 * parameters.mean_wait_of_all 
	- 8248102.5454 * parameters.cpu_usage 
	- 0.0349 * parameters.avg_work_of_same_past_second 
	+ 0.1327 * parameters.avg_wait_of_same_past_second 
	+ 0.0035 * parameters.avg_latency_of_same_last_20 
	+ 0.0074 * parameters.max_latency_of_same_last_50 
	+ 32742145.187;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM165(work_wait &parameters) {
  double actual_remaining = 
	-0.0569 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	+ 42897.6635 * parameters.total_wait_locks 
	- 9.3234 * parameters.mean_wait_of_all 
	+ 28967611.1011 * parameters.cpu_usage 
	- 0.0349 * parameters.avg_work_of_same_past_second 
	+ 0.003 * parameters.avg_wait_of_same_past_second 
	+ 0.0035 * parameters.avg_latency_of_same_last_20 
	+ 0.0024 * parameters.max_latency_of_same_last_50 
	+ 1050720340.6889;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM166(work_wait &parameters) {
  double actual_remaining = 
	-0.0569 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 107640.5772 * parameters.total_wait_locks 
	- 14.6016 * parameters.mean_wait_of_all 
	+ 28967611.1011 * parameters.cpu_usage 
	- 0.0349 * parameters.avg_work_of_same_past_second 
	+ 0.003 * parameters.avg_wait_of_same_past_second 
	+ 0.0035 * parameters.avg_latency_of_same_last_20 
	+ 0.0024 * parameters.max_latency_of_same_last_50 
	+ 1723710550.3387;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM167(work_wait &parameters) {
  double actual_remaining = 
	-0.0569 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 107640.5772 * parameters.total_wait_locks 
	+ 0.7051 * parameters.mean_wait_of_all 
	+ 28967611.1011 * parameters.cpu_usage 
	- 0.0349 * parameters.avg_work_of_same_past_second 
	+ 0.003 * parameters.avg_wait_of_same_past_second 
	+ 0.0035 * parameters.avg_latency_of_same_last_20 
	+ 0.0024 * parameters.max_latency_of_same_last_50 
	- 30928506.6871;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM168(work_wait &parameters) {
  double actual_remaining = 
	-0.0569 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 57130.0504 * parameters.total_wait_locks 
	- 0.9139 * parameters.mean_wait_of_all 
	+ 59615845.8689 * parameters.cpu_usage 
	- 0.0349 * parameters.avg_work_of_same_past_second 
	+ 0.003 * parameters.avg_wait_of_same_past_second 
	- 0.0147 * parameters.avg_latency_of_same_last_20 
	+ 0.0024 * parameters.max_latency_of_same_last_50 
	+ 125957222.1235;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM169(work_wait &parameters) {
  double actual_remaining = 
	-0.0325 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 42321.3471 * parameters.total_wait_locks 
	+ 0.5784 * parameters.mean_wait_of_all 
	- 11824608.7866 * parameters.cpu_usage 
	- 0.0349 * parameters.avg_work_of_same_past_second 
	- 0.0301 * parameters.avg_wait_of_same_past_second 
	+ 0.0035 * parameters.avg_latency_of_same_last_20 
	- 0.0012 * parameters.max_latency_of_same_last_50 
	- 4229016.3333;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM170(work_wait &parameters) {
  double actual_remaining = 
	-0.0325 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	- 2632.9234 * parameters.num_locks_so_far 
	- 42321.3471 * parameters.total_wait_locks 
	+ 0.4009 * parameters.mean_wait_of_all 
	- 11824608.7866 * parameters.cpu_usage 
	- 0.0349 * parameters.avg_work_of_same_past_second 
	- 0.1083 * parameters.avg_wait_of_same_past_second 
	+ 0.0035 * parameters.avg_latency_of_same_last_20 
	- 0.0012 * parameters.max_latency_of_same_last_50 
	+ 71370349.2095;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM171(work_wait &parameters) {
  double actual_remaining = 
	0.2515 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	- 13148.295 * parameters.num_locks_so_far 
	+ 8545.5584 * parameters.total_wait_locks 
	- 0.0156 * parameters.mean_wait_of_all 
	- 16994805.6268 * parameters.cpu_usage 
	+ 0.007 * parameters.avg_work_of_same_past_second 
	- 0.1065 * parameters.avg_wait_of_same_past_second 
	+ 0.0481 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 56180015.3486;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM172(work_wait &parameters) {
  double actual_remaining = 
	0.2515 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	- 13148.295 * parameters.num_locks_so_far 
	+ 8545.5584 * parameters.total_wait_locks 
	- 0.0156 * parameters.mean_wait_of_all 
	+ 331161505.7546 * parameters.cpu_usage 
	+ 0.007 * parameters.avg_work_of_same_past_second 
	- 0.1065 * parameters.avg_wait_of_same_past_second 
	+ 0.3935 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 267586954.8905;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM173(work_wait &parameters) {
  double actual_remaining = 
	0.425 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	- 13148.295 * parameters.num_locks_so_far 
	+ 19693.7791 * parameters.total_wait_locks 
	- 0.0123 * parameters.mean_wait_of_all 
	- 44491387.2288 * parameters.cpu_usage 
	- 1.6198 * parameters.avg_work_of_same_past_second 
	- 0.2637 * parameters.avg_wait_of_same_past_second 
	+ 0.0493 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 211965111.2467;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM174(work_wait &parameters) {
  double actual_remaining = 
	0.6553 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	- 13148.295 * parameters.num_locks_so_far 
	+ 32830.3611 * parameters.total_wait_locks 
	- 0.0123 * parameters.mean_wait_of_all 
	- 544434877.634 * parameters.cpu_usage 
	+ 0.007 * parameters.avg_work_of_same_past_second 
	- 4.2846 * parameters.avg_wait_of_same_past_second 
	+ 0.699 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 612843169.8678;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM175(work_wait &parameters) {
  double actual_remaining = 
	0.0982 * parameters.work_so_far 
	- 0.0245 * parameters.wait_so_far 
	- 301043.3766 * parameters.num_locks_so_far 
	+ 125.4668 * parameters.total_wait_locks 
	+ 0.0897 * parameters.mean_wait_of_all 
	- 5365145.7478 * parameters.cpu_usage 
	+ 0.007 * parameters.avg_work_of_same_past_second 
	- 0.0058 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 58106830.6594;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM176(work_wait &parameters) {
  double actual_remaining = 
	29.9998 * parameters.work_so_far 
	+ 0.0883 * parameters.wait_so_far 
	- 961163.9029 * parameters.num_locks_so_far 
	+ 10510.3839 * parameters.total_wait_locks 
	+ 0.0049 * parameters.mean_wait_of_all 
	- 8456965.3926 * parameters.cpu_usage 
	+ 1.144 * parameters.avg_work_of_same_past_second 
	- 2.9165 * parameters.avg_wait_of_same_past_second 
	+ 0.4892 * parameters.avg_latency_of_same_last_20 
	- 0.1068 * parameters.max_latency_of_same_last_50 
	+ 57953560.724;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM177(work_wait &parameters) {
  double actual_remaining = 
	1715.2575 * parameters.work_so_far 
	- 0.0032 * parameters.wait_so_far 
	- 303492.4907 * parameters.num_locks_so_far 
	+ 135134.3014 * parameters.total_wait_locks 
	+ 0.0049 * parameters.mean_wait_of_all 
	- 139217593.0545 * parameters.cpu_usage 
	+ 0.0448 * parameters.avg_work_of_same_past_second 
	- 0.263 * parameters.avg_wait_of_same_past_second 
	+ 0.0974 * parameters.avg_latency_of_same_last_20 
	- 0.0197 * parameters.max_latency_of_same_last_50 
	+ 135509415.1172;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM178(work_wait &parameters) {
  double actual_remaining = 
	7262.4304 * parameters.work_so_far 
	- 0.0057 * parameters.wait_so_far 
	- 303492.4907 * parameters.num_locks_so_far 
	+ 16961.0443 * parameters.total_wait_locks 
	+ 0.0049 * parameters.mean_wait_of_all 
	- 5395159.7471 * parameters.cpu_usage 
	+ 0.2123 * parameters.avg_work_of_same_past_second 
	- 0.035 * parameters.avg_wait_of_same_past_second 
	+ 0.7843 * parameters.avg_latency_of_same_last_20 
	- 0.181 * parameters.max_latency_of_same_last_50 
	- 99891357.6497;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM179(work_wait &parameters) {
  double actual_remaining = 
	-800.0949 * parameters.work_so_far 
	+ 0.0145 * parameters.wait_so_far 
	- 303492.4907 * parameters.num_locks_so_far 
	+ 16961.0443 * parameters.total_wait_locks 
	+ 0.0049 * parameters.mean_wait_of_all 
	- 5395159.7471 * parameters.cpu_usage 
	+ 0.2264 * parameters.avg_work_of_same_past_second 
	- 0.035 * parameters.avg_wait_of_same_past_second 
	+ 0.0556 * parameters.avg_latency_of_same_last_20 
	- 0.0212 * parameters.max_latency_of_same_last_50 
	+ 86464026.7382;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM180(work_wait &parameters) {
  double actual_remaining = 
	467.9501 * parameters.work_so_far 
	+ 0.0459 * parameters.wait_so_far 
	- 303492.4907 * parameters.num_locks_so_far 
	+ 521066.1048 * parameters.total_wait_locks 
	- 1.9539 * parameters.mean_wait_of_all 
	- 5395159.7471 * parameters.cpu_usage 
	+ 0.3186 * parameters.avg_work_of_same_past_second 
	- 0.035 * parameters.avg_wait_of_same_past_second 
	+ 0.0556 * parameters.avg_latency_of_same_last_20 
	- 0.2531 * parameters.max_latency_of_same_last_50 
	+ 323662587.8473;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM181(work_wait &parameters) {
  double actual_remaining = 
	61.1811 * parameters.work_so_far 
	- 0.036 * parameters.wait_so_far 
	+ 28100736.713 * parameters.num_locks_so_far 
	+ 11757.9165 * parameters.total_wait_locks 
	+ 0.0049 * parameters.mean_wait_of_all 
	- 5395159.7471 * parameters.cpu_usage 
	+ 0.0454 * parameters.avg_work_of_same_past_second 
	- 0.0239 * parameters.avg_wait_of_same_past_second 
	+ 0.1138 * parameters.avg_latency_of_same_last_20 
	+ 0.0211 * parameters.max_latency_of_same_last_50 
	- 71443237.0819;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM182(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.1681 * parameters.wait_so_far 
	- 21732.9461 * parameters.num_locks_so_far 
	+ 262419.7364 * parameters.total_wait_locks 
	+ 0.3489 * parameters.mean_wait_of_all 
	- 4329689.6823 * parameters.cpu_usage 
	+ 0.7343 * parameters.avg_work_of_same_past_second 
	- 0.4254 * parameters.avg_wait_of_same_past_second 
	+ 0.1158 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 51758510.4234;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM183(work_wait &parameters) {
  double actual_remaining = 
	0.0021 * parameters.work_so_far 
	- 0.0032 * parameters.wait_so_far 
	- 75942.114 * parameters.num_locks_so_far 
	+ 94688.8086 * parameters.total_wait_locks 
	+ 0.0051 * parameters.mean_wait_of_all 
	- 4299855.0349 * parameters.cpu_usage 
	+ 0.0385 * parameters.avg_work_of_same_past_second 
	- 0.0101 * parameters.avg_wait_of_same_past_second 
	+ 0.2533 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	+ 19872013.5929;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM184(work_wait &parameters) {
  double actual_remaining = 
	0.006 * parameters.work_so_far 
	- 0.0293 * parameters.wait_so_far 
	- 597083.3128 * parameters.num_locks_so_far 
	+ 193029.1343 * parameters.total_wait_locks 
	+ 0.0134 * parameters.mean_wait_of_all 
	- 4299855.0349 * parameters.cpu_usage 
	+ 0.0777 * parameters.avg_work_of_same_past_second 
	- 0.0181 * parameters.avg_wait_of_same_past_second 
	+ 0.006 * parameters.avg_latency_of_same_last_20 
	- 0.0026 * parameters.max_latency_of_same_last_50 
	+ 44081842.8336;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM185(work_wait &parameters) {
  double actual_remaining = 
	0.0045 * parameters.work_so_far 
	- 0.0081 * parameters.wait_so_far 
	- 165692.0647 * parameters.num_locks_so_far 
	+ 274787.5431 * parameters.total_wait_locks 
	- 1.3107 * parameters.mean_wait_of_all 
	- 4299855.0349 * parameters.cpu_usage 
	+ 0.1109 * parameters.avg_work_of_same_past_second 
	- 0.0262 * parameters.avg_wait_of_same_past_second 
	+ 0.006 * parameters.avg_latency_of_same_last_20 
	- 0.045 * parameters.max_latency_of_same_last_50 
	+ 166849730.8529;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM186(work_wait &parameters) {
  double actual_remaining = 
	0.0045 * parameters.work_so_far 
	- 0.0345 * parameters.wait_so_far 
	- 598088.5217 * parameters.num_locks_so_far 
	+ 319583.121 * parameters.total_wait_locks 
	+ 0.0321 * parameters.mean_wait_of_all 
	+ 2214237752.0249 * parameters.cpu_usage 
	+ 0.7003 * parameters.avg_work_of_same_past_second 
	- 0.2118 * parameters.avg_wait_of_same_past_second 
	- 0.9826 * parameters.avg_latency_of_same_last_20 
	+ 1.0284 * parameters.max_latency_of_same_last_50 
	- 2305146138.2027;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM187(work_wait &parameters) {
  double actual_remaining = 
	0.0045 * parameters.work_so_far 
	- 0.0345 * parameters.wait_so_far 
	- 598088.5217 * parameters.num_locks_so_far 
	- 434136.1436 * parameters.total_wait_locks 
	+ 0.0321 * parameters.mean_wait_of_all 
	+ 2214237752.0249 * parameters.cpu_usage 
	+ 0.7003 * parameters.avg_work_of_same_past_second 
	- 0.2118 * parameters.avg_wait_of_same_past_second 
	- 0.9826 * parameters.avg_latency_of_same_last_20 
	+ 1.0284 * parameters.max_latency_of_same_last_50 
	- 2100813035.1828;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM188(work_wait &parameters) {
  double actual_remaining = 
	0.0045 * parameters.work_so_far 
	- 0.0544 * parameters.wait_so_far 
	- 598088.5217 * parameters.num_locks_so_far 
	+ 319583.121 * parameters.total_wait_locks 
	+ 0.0321 * parameters.mean_wait_of_all 
	+ 1678297584.135 * parameters.cpu_usage 
	+ 0.7003 * parameters.avg_work_of_same_past_second 
	- 0.2118 * parameters.avg_wait_of_same_past_second 
	- 0.7046 * parameters.avg_latency_of_same_last_20 
	- 0.0074 * parameters.max_latency_of_same_last_50 
	- 1449443312.7042;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM189(work_wait &parameters) {
  double actual_remaining = 
	0.0045 * parameters.work_so_far 
	- 0.0188 * parameters.wait_so_far 
	- 951796.2358 * parameters.num_locks_so_far 
	+ 152178.5206 * parameters.total_wait_locks 
	+ 0.0321 * parameters.mean_wait_of_all 
	+ 106486893.8761 * parameters.cpu_usage 
	+ 0.3397 * parameters.avg_work_of_same_past_second 
	- 0.0965 * parameters.avg_wait_of_same_past_second 
	+ 0.006 * parameters.avg_latency_of_same_last_20 
	- 0.0074 * parameters.max_latency_of_same_last_50 
	- 25753109.2597;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM190(work_wait &parameters) {
  double actual_remaining = 
	0.2933 * parameters.work_so_far 
	- 0.3781 * parameters.wait_so_far 
	- 2191548.7451 * parameters.num_locks_so_far 
	+ 1167329.4796 * parameters.total_wait_locks 
	- 5.6717 * parameters.mean_wait_of_all 
	- 387999403.1303 * parameters.cpu_usage 
	+ 0.843 * parameters.avg_work_of_same_past_second 
	- 0.3309 * parameters.avg_wait_of_same_past_second 
	+ 0.1222 * parameters.avg_latency_of_same_last_20 
	- 0.0451 * parameters.max_latency_of_same_last_50 
	+ 715979817.8284;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM191(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0821 * parameters.wait_so_far 
	- 2606096.313 * parameters.num_locks_so_far 
	+ 5140.0459 * parameters.total_wait_locks 
	- 0.0112 * parameters.mean_wait_of_all 
	- 234615795.448 * parameters.cpu_usage 
	+ 0.4665 * parameters.avg_work_of_same_past_second 
	- 0.2229 * parameters.avg_wait_of_same_past_second 
	+ 0.1582 * parameters.avg_latency_of_same_last_20 
	- 0.0248 * parameters.max_latency_of_same_last_50 
	+ 354921134.9039;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM192(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0079 * parameters.wait_so_far 
	- 117919.9987 * parameters.num_locks_so_far 
	- 457487.0658 * parameters.total_wait_locks 
	+ 2.9652 * parameters.mean_wait_of_all 
	- 6506590.058 * parameters.cpu_usage 
	+ 1.4978 * parameters.avg_work_of_same_past_second 
	- 0.0051 * parameters.avg_wait_of_same_past_second 
	+ 0.0142 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	- 185923564.7775;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM193(work_wait &parameters) {
  double actual_remaining = 
	-0.006 * parameters.work_so_far 
	- 0.1097 * parameters.wait_so_far 
	- 75838.9522 * parameters.num_locks_so_far 
	+ 11350.3185 * parameters.total_wait_locks 
	- 0.0516 * parameters.mean_wait_of_all 
	- 6506590.058 * parameters.cpu_usage 
	- 1.4941 * parameters.avg_work_of_same_past_second 
	+ 0.7478 * parameters.avg_wait_of_same_past_second 
	+ 0.0139 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	+ 291446270.1108;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM194(work_wait &parameters) {
  double actual_remaining = 
	-0.021 * parameters.work_so_far 
	- 0.168 * parameters.wait_so_far 
	- 75838.9522 * parameters.num_locks_so_far 
	- 2045381.8025 * parameters.total_wait_locks 
	+ 11.9377 * parameters.mean_wait_of_all 
	- 6506590.058 * parameters.cpu_usage 
	- 0.0576 * parameters.avg_work_of_same_past_second 
	+ 0.0507 * parameters.avg_wait_of_same_past_second 
	+ 0.0288 * parameters.avg_latency_of_same_last_20 
	- 0.1435 * parameters.max_latency_of_same_last_50 
	+ 280181698.3502;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM195(work_wait &parameters) {
  double actual_remaining = 
	0.189 * parameters.work_so_far 
	- 0.1584 * parameters.wait_so_far 
	- 3443255.7095 * parameters.num_locks_so_far 
	+ 413242.8224 * parameters.total_wait_locks 
	+ 0.4473 * parameters.mean_wait_of_all 
	+ 150125471.0242 * parameters.cpu_usage 
	+ 0.1461 * parameters.avg_work_of_same_past_second 
	- 0.5458 * parameters.avg_wait_of_same_past_second 
	+ 0.3285 * parameters.avg_latency_of_same_last_20 
	+ 0.031 * parameters.max_latency_of_same_last_50 
	- 86648367.5695;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM196(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.2374 * parameters.wait_so_far 
	- 3873041.6017 * parameters.num_locks_so_far 
	- 1647258.435 * parameters.total_wait_locks 
	+ 11.0882 * parameters.mean_wait_of_all 
	+ 377076.8677 * parameters.cpu_usage 
	+ 0.2306 * parameters.avg_work_of_same_past_second 
	- 0.295 * parameters.avg_wait_of_same_past_second 
	+ 0.2469 * parameters.avg_latency_of_same_last_20 
	- 0.0301 * parameters.max_latency_of_same_last_50 
	- 123522945.0161;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM197(work_wait &parameters) {
  double actual_remaining = 
	0 * parameters.work_so_far 
	- 0.0042 * parameters.wait_so_far 
	- 7173743.3318 * parameters.num_locks_so_far 
	- 140438.0643 * parameters.total_wait_locks 
	+ 0.1488 * parameters.mean_wait_of_all 
	+ 377076.8677 * parameters.cpu_usage 
	+ 0.0072 * parameters.avg_work_of_same_past_second 
	- 0.3388 * parameters.avg_wait_of_same_past_second 
	+ 0.1158 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	+ 360043260.5962;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM198(work_wait &parameters) {
  double actual_remaining = 
	-0.0493 * parameters.work_so_far 
	- 0.2673 * parameters.wait_so_far 
	- 59556.075 * parameters.num_locks_so_far 
	+ 450532.7121 * parameters.total_wait_locks 
	+ 0.0155 * parameters.mean_wait_of_all 
	- 1095184222.5827 * parameters.cpu_usage 
	+ 0.1617 * parameters.avg_work_of_same_past_second 
	- 0.0029 * parameters.avg_wait_of_same_past_second 
	+ 0.4866 * parameters.avg_latency_of_same_last_20 
	- 0.0557 * parameters.max_latency_of_same_last_50 
	+ 1186568877.7564;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM199(work_wait &parameters) {
  double actual_remaining = 
	53.3953 * parameters.work_so_far 
	- 0.024 * parameters.wait_so_far 
	- 59556.075 * parameters.num_locks_so_far 
	+ 579.2396 * parameters.total_wait_locks 
	- 1.7902 * parameters.mean_wait_of_all 
	+ 2821306109.2004 * parameters.cpu_usage 
	+ 0.046 * parameters.avg_work_of_same_past_second 
	- 0.0404 * parameters.avg_wait_of_same_past_second 
	+ 0.0828 * parameters.avg_latency_of_same_last_20 
	- 0.0017 * parameters.max_latency_of_same_last_50 
	- 1900737622.7548;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM200(work_wait &parameters) {
  double actual_remaining = 
	-0.1095 * parameters.work_so_far 
	- 0.0161 * parameters.wait_so_far 
	- 59556.075 * parameters.num_locks_so_far 
	+ 579.2396 * parameters.total_wait_locks 
	- 0.0649 * parameters.mean_wait_of_all 
	+ 834139031.4962 * parameters.cpu_usage 
	+ 0.1675 * parameters.avg_work_of_same_past_second 
	- 0.0202 * parameters.avg_wait_of_same_past_second 
	+ 0.7472 * parameters.avg_latency_of_same_last_20 
	- 0.0017 * parameters.max_latency_of_same_last_50 
	- 735497170.6764;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM201(work_wait &parameters) {
  double actual_remaining = 
	-0.6633 * parameters.work_so_far 
	- 0.0131 * parameters.wait_so_far 
	- 4597102.4402 * parameters.num_locks_so_far 
	- 1034099.4008 * parameters.total_wait_locks 
	+ 14.202 * parameters.mean_wait_of_all 
	+ 65529886.5529 * parameters.cpu_usage 
	- 0.3526 * parameters.avg_work_of_same_past_second 
	- 0.0029 * parameters.avg_wait_of_same_past_second 
	+ 0.0985 * parameters.avg_latency_of_same_last_20 
	- 0.0017 * parameters.max_latency_of_same_last_50 
	- 28147088.047;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM202(work_wait &parameters) {
  double actual_remaining = 
	-0.6633 * parameters.work_so_far 
	- 0.0131 * parameters.wait_so_far 
	- 8792095.8538 * parameters.num_locks_so_far 
	- 1034099.4008 * parameters.total_wait_locks 
	+ 14.202 * parameters.mean_wait_of_all 
	- 2126841149.0889 * parameters.cpu_usage 
	- 0.2896 * parameters.avg_work_of_same_past_second 
	- 0.0029 * parameters.avg_wait_of_same_past_second 
	+ 0.0985 * parameters.avg_latency_of_same_last_20 
	+ 0.2239 * parameters.max_latency_of_same_last_50 
	+ 1424921287.9137;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM203(work_wait &parameters) {
  double actual_remaining = 
	-0.5084 * parameters.work_so_far 
	- 0.162 * parameters.wait_so_far 
	- 1968128.7075 * parameters.num_locks_so_far 
	- 735689.0677 * parameters.total_wait_locks 
	+ 9.5496 * parameters.mean_wait_of_all 
	+ 1186161954.7685 * parameters.cpu_usage 
	- 0.3008 * parameters.avg_work_of_same_past_second 
	+ 1.5049 * parameters.avg_wait_of_same_past_second 
	+ 0.0985 * parameters.avg_latency_of_same_last_20 
	- 0.0017 * parameters.max_latency_of_same_last_50 
	- 649045573.4956;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM204(work_wait &parameters) {
  double actual_remaining = 
	-0.5084 * parameters.work_so_far 
	- 0.0131 * parameters.wait_so_far 
	+ 27822725.3311 * parameters.num_locks_so_far 
	- 735689.0677 * parameters.total_wait_locks 
	+ 9.5496 * parameters.mean_wait_of_all 
	+ 65529886.5529 * parameters.cpu_usage 
	- 1.5276 * parameters.avg_work_of_same_past_second 
	- 0.0029 * parameters.avg_wait_of_same_past_second 
	+ 0.0985 * parameters.avg_latency_of_same_last_20 
	+ 0.1005 * parameters.max_latency_of_same_last_50 
	+ 1552164811.0901;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM205(work_wait &parameters) {
  double actual_remaining = 
	-0.1756 * parameters.work_so_far 
	- 0.0131 * parameters.wait_so_far 
	- 1209755.4761 * parameters.num_locks_so_far 
	- 59438.4071 * parameters.total_wait_locks 
	- 0.3034 * parameters.mean_wait_of_all 
	+ 65529886.5529 * parameters.cpu_usage 
	+ 0.0016 * parameters.avg_work_of_same_past_second 
	- 0.9291 * parameters.avg_wait_of_same_past_second 
	+ 0.0826 * parameters.avg_latency_of_same_last_20 
	- 0.0017 * parameters.max_latency_of_same_last_50 
	+ 799126284.9687;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
tpcc_estimate(work_wait &parameters){

  if (parameters.avg_work_of_same_past_second <= 59319250) {

    if (parameters.avg_work_of_same_past_second <= 28111800) {

      if (parameters.work_so_far <= 10768) {

        if (parameters.avg_latency_of_same_last_20 <= 49744300) {
          return tpcc_LM1(parameters);
        } else {

          if (parameters.avg_work_of_same_past_second <= 9632835) {

            if (parameters.avg_wait_of_same_past_second <= 26358100) {

              if (parameters.avg_wait_of_same_past_second <= 11397700) {
                return tpcc_LM2(parameters);
              } else {

                if (parameters.mean_wait_of_all <= 64781800) {

                  if (parameters.work_so_far <= 9605) {
                    return tpcc_LM3(parameters);
                  } else {
                    return tpcc_LM4(parameters);
                  }
                } else {
                  return tpcc_LM5(parameters);
                }
              }
            } else {

              if (parameters.avg_wait_of_same_past_second <= 32296550) {

                if (parameters.work_so_far <= 8379.5) {
                  return tpcc_LM6(parameters);
                } else {

                  if (parameters.avg_work_of_same_past_second <= 7959430) {
                    return tpcc_LM7(parameters);
                  } else {
                    return tpcc_LM8(parameters);
                  }
                }
              } else {
                return tpcc_LM9(parameters);
              }
            }
          } else {
            return tpcc_LM10(parameters);
          }
        }
      } else {

        if (parameters.work_so_far <= 34148.5) {

          if (parameters.avg_work_of_same_past_second <= 22769850) {

            if (parameters.wait_so_far <= 56013597.5) {
              return tpcc_LM11(parameters);
            } else {

              if (parameters.cpu_usage <= 0.936) {

                if (parameters.wait_so_far <= 112572972.5) {

                  if (parameters.mean_wait_of_all <= 91286850) {

                    if (parameters.mean_wait_of_all <= 63507900) {

                      if (parameters.avg_latency_of_same_last_20 <= 84273100) {
                        return tpcc_LM12(parameters);
                      } else {
                        return tpcc_LM13(parameters);
                      }
                    } else {
                      return tpcc_LM14(parameters);
                    }
                  } else {

                    if (parameters.avg_wait_of_same_past_second <= 45238550) {
                      return tpcc_LM15(parameters);
                    } else {

                      if (parameters.avg_latency_of_same_last_20 <= 261455500) {

                        if (parameters.mean_wait_of_all <= 92270500) {
                          return tpcc_LM16(parameters);
                        } else {
                          return tpcc_LM17(parameters);
                        }
                      } else {
                        return tpcc_LM18(parameters);
                      }
                    }
                  }
                } else {

                  if (parameters.max_latency_of_same_last_50 <= 1076495000) {
                    return tpcc_LM19(parameters);
                  } else {

                    if (parameters.cpu_usage <= 0.912) {
                      return tpcc_LM20(parameters);
                    } else {

                      if (parameters.avg_wait_of_same_past_second <= 394447500) {

                        if (parameters.work_so_far <= 30874) {
                          return tpcc_LM21(parameters);
                        } else {
                          return tpcc_LM22(parameters);
                        }
                      } else {
                        return tpcc_LM23(parameters);
                      }
                    }
                  }
                }
              } else {
                return tpcc_LM24(parameters);
              }
            }
          } else {
            return tpcc_LM25(parameters);
          }
        } else {

          if (parameters.num_locks_so_far <= 4) {

            if (parameters.max_latency_of_same_last_50 <= 1240610000) {

              if (parameters.max_latency_of_same_last_50 <= 703974000) {

                if (parameters.avg_latency_of_same_last_20 <= 86510350) {

                  if (parameters.avg_work_of_same_past_second <= 7732485) {

                    if (parameters.avg_latency_of_same_last_20 <= 51543800) {
                      return tpcc_LM26(parameters);
                    } else {

                      if (parameters.work_so_far <= 280884.5) {
                        return tpcc_LM27(parameters);
                      } else {
                        return tpcc_LM28(parameters);
                      }
                    }
                  } else {
                    return tpcc_LM29(parameters);
                  }
                } else {

                  if (parameters.mean_wait_of_all <= 92102850) {

                    if (parameters.cpu_usage <= 0.911) {
                      return tpcc_LM30(parameters);
                    } else {

                      if (parameters.avg_latency_of_same_last_20 <= 161057500) {
                        return tpcc_LM31(parameters);
                      } else {
                        return tpcc_LM32(parameters);
                      }
                    }
                  } else {

                    if (parameters.total_wait_locks <= 300.5) {
                      return tpcc_LM33(parameters);
                    } else {

                      if (parameters.avg_work_of_same_past_second <= 23281100) {

                        if (parameters.avg_wait_of_same_past_second <= 203667500) {
                          return tpcc_LM34(parameters);
                        } else {

                          if (parameters.avg_work_of_same_past_second <= 22357150) {

                            if (parameters.avg_latency_of_same_last_20 <= 286007000) {
                              return tpcc_LM35(parameters);
                            } else {

                              if (parameters.total_wait_locks <= 324.5) {
                                return tpcc_LM36(parameters);
                              } else {
                                return tpcc_LM37(parameters);
                              }
                            }
                          } else {

                            if (parameters.total_wait_locks <= 440.5) {
                              return tpcc_LM38(parameters);
                            } else {
                              return tpcc_LM39(parameters);
                            }
                          }
                        }
                      } else {
                        return tpcc_LM40(parameters);
                      }
                    }
                  }
                }
              } else {

                if (parameters.mean_wait_of_all <= 98335350) {
                  return tpcc_LM41(parameters);
                } else {
                  return tpcc_LM42(parameters);
                }
              }
            } else {

              if (parameters.avg_work_of_same_past_second <= 20104950) {

                if (parameters.max_latency_of_same_last_50 <= 1437565000) {

                  if (parameters.avg_wait_of_same_past_second <= 230605500) {

                    if (parameters.mean_wait_of_all <= 84234850) {
                      return tpcc_LM43(parameters);
                    } else {
                      return tpcc_LM44(parameters);
                    }
                  } else {

                    if (parameters.cpu_usage <= 0.985) {

                      if (parameters.avg_work_of_same_past_second <= 18223900) {

                        if (parameters.avg_latency_of_same_last_20 <= 435665500) {

                          if (parameters.mean_wait_of_all <= 100932000) {

                            if (parameters.total_wait_locks <= 242) {
                              return tpcc_LM45(parameters);
                            } else {
                              return tpcc_LM46(parameters);
                            }
                          } else {
                            return tpcc_LM47(parameters);
                          }
                        } else {
                          return tpcc_LM48(parameters);
                        }
                      } else {

                        if (parameters.mean_wait_of_all <= 97328150) {
                          return tpcc_LM49(parameters);
                        } else {

                          if (parameters.avg_latency_of_same_last_20 <= 596446500) {

                            if (parameters.wait_so_far <= 298805319) {
                              return tpcc_LM50(parameters);
                            } else {
                              return tpcc_LM51(parameters);
                            }
                          } else {

                            if (parameters.cpu_usage <= 0.923) {
                              return tpcc_LM52(parameters);
                            } else {

                              if (parameters.work_so_far <= 50914) {
                                return tpcc_LM53(parameters);
                              } else {
                                return tpcc_LM54(parameters);
                              }
                            }
                          }
                        }
                      }
                    } else {

                      if (parameters.max_latency_of_same_last_50 <= 1265360000) {
                        return tpcc_LM55(parameters);
                      } else {
                        return tpcc_LM56(parameters);
                      }
                    }
                  }
                } else {
                  return tpcc_LM57(parameters);
                }
              } else {

                if (parameters.wait_so_far <= 237512882) {

                  if (parameters.avg_latency_of_same_last_20 <= 370132500) {
                    return tpcc_LM58(parameters);
                  } else {

                    if (parameters.wait_so_far <= 90214569) {

                      if (parameters.avg_work_of_same_past_second <= 25832150) {

                        if (parameters.total_wait_locks <= 367.5) {
                          return tpcc_LM59(parameters);
                        } else {

                          if (parameters.avg_wait_of_same_past_second <= 521917500) {

                            if (parameters.avg_latency_of_same_last_20 <= 530840500) {
                              return tpcc_LM60(parameters);
                            } else {
                              return tpcc_LM61(parameters);
                            }
                          } else {

                            if (parameters.mean_wait_of_all <= 130835000) {

                              if (parameters.total_wait_locks <= 467) {
                                return tpcc_LM62(parameters);
                              } else {
                                return tpcc_LM63(parameters);
                              }
                            } else {
                              return tpcc_LM64(parameters);
                            }
                          }
                        }
                      } else {
                        return tpcc_LM65(parameters);
                      }
                    } else {

                      if (parameters.wait_so_far <= 206654121.5) {
                        return tpcc_LM66(parameters);
                      } else {

                        if (parameters.work_so_far <= 1065496) {

                          if (parameters.total_wait_locks <= 324) {
                            return tpcc_LM67(parameters);
                          } else {
                            return tpcc_LM68(parameters);
                          }
                        } else {
                          return tpcc_LM69(parameters);
                        }
                      }
                    }
                  }
                } else {

                  if (parameters.avg_latency_of_same_last_20 <= 389121000) {
                    return tpcc_LM70(parameters);
                  } else {

                    if (parameters.max_latency_of_same_last_50 <= 1554425000) {

                      if (parameters.max_latency_of_same_last_50 <= 1425510000) {
                        return tpcc_LM71(parameters);
                      } else {
                        return tpcc_LM72(parameters);
                      }
                    } else {

                      if (parameters.mean_wait_of_all <= 132927000) {

                        if (parameters.avg_latency_of_same_last_20 <= 675603000) {
                          return tpcc_LM73(parameters);
                        } else {
                          return tpcc_LM74(parameters);
                        }
                      } else {

                        if (parameters.avg_wait_of_same_past_second <= 498578500) {

                          if (parameters.max_latency_of_same_last_50 <= 1987235000) {

                            if (parameters.max_latency_of_same_last_50 <= 1629175000) {
                              return tpcc_LM75(parameters);
                            } else {
                              return tpcc_LM76(parameters);
                            }
                          } else {
                            return tpcc_LM77(parameters);
                          }
                        } else {

                          if (parameters.max_latency_of_same_last_50 <= 2122060000) {

                            if (parameters.work_so_far <= 42573.5) {
                              return tpcc_LM78(parameters);
                            } else {
                              return tpcc_LM79(parameters);
                            }
                          } else {
                            return tpcc_LM80(parameters);
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          } else {

            if (parameters.avg_work_of_same_past_second <= 5004790) {
              return tpcc_LM81(parameters);
            } else {

              if (parameters.avg_latency_of_same_last_20 <= 185990500) {
                return tpcc_LM82(parameters);
              } else {

                if (parameters.num_locks_so_far <= 111.5) {

                  if (parameters.mean_wait_of_all <= 88659050) {

                    if (parameters.total_wait_locks <= 274.5) {
                      return tpcc_LM83(parameters);
                    } else {
                      return tpcc_LM84(parameters);
                    }
                  } else {

                    if (parameters.wait_so_far <= 27381028.5) {

                      if (parameters.avg_latency_of_same_last_20 <= 405596500) {
                        return tpcc_LM85(parameters);
                      } else {

                        if (parameters.work_so_far <= 1426863) {
                          return tpcc_LM86(parameters);
                        } else {
                          return tpcc_LM87(parameters);
                        }
                      }
                    } else {
                      return tpcc_LM88(parameters);
                    }
                  }
                } else {

                  if (parameters.work_so_far <= 5537633) {
                    return tpcc_LM89(parameters);
                  } else {
                    return tpcc_LM90(parameters);
                  }
                }
              }
            }
          }
        }
      }
    } else {

      if (parameters.num_locks_so_far <= 3) {

        if (parameters.max_latency_of_same_last_50 <= 1738110000) {

          if (parameters.max_latency_of_same_last_50 <= 1014425000) {

            if (parameters.max_latency_of_same_last_50 <= 746976000) {

              if (parameters.mean_wait_of_all <= 61851900) {

                if (parameters.avg_work_of_same_past_second <= 31725300) {

                  if (parameters.wait_so_far <= 71781491) {
                    return tpcc_LM91(parameters);
                  } else {
                    return tpcc_LM92(parameters);
                  }
                } else {
                  return tpcc_LM93(parameters);
                }
              } else {
                return tpcc_LM94(parameters);
              }
            } else {
              return tpcc_LM95(parameters);
            }
          } else {

            if (parameters.avg_wait_of_same_past_second <= 395813500) {

              if (parameters.total_wait_locks <= 368.5) {

                if (parameters.avg_wait_of_same_past_second <= 174710500) {

                  if (parameters.avg_work_of_same_past_second <= 40497950) {

                    if (parameters.total_wait_locks <= 170.5) {

                      if (parameters.work_so_far <= 24187.5) {
                        return tpcc_LM96(parameters);
                      } else {
                        return tpcc_LM97(parameters);
                      }
                    } else {

                      if (parameters.total_wait_locks <= 311.5) {

                        if (parameters.total_wait_locks <= 225) {
                          return tpcc_LM98(parameters);
                        } else {
                          return tpcc_LM99(parameters);
                        }
                      } else {
                        return tpcc_LM100(parameters);
                      }
                    }
                  } else {
                    return tpcc_LM101(parameters);
                  }
                } else {

                  if (parameters.wait_so_far <= 101588241) {
                    return tpcc_LM102(parameters);
                  } else {

                    if (parameters.avg_work_of_same_past_second <= 31531250) {
                      return tpcc_LM103(parameters);
                    } else {

                      if (parameters.mean_wait_of_all <= 275518500) {

                        if (parameters.avg_wait_of_same_past_second <= 351460500) {
                          return tpcc_LM104(parameters);
                        } else {
                          return tpcc_LM105(parameters);
                        }
                      } else {
                        return tpcc_LM106(parameters);
                      }
                    }
                  }
                }
              } else {

                if (parameters.wait_so_far <= 149393691.5) {

                  if (parameters.max_latency_of_same_last_50 <= 1324550000) {

                    if (parameters.mean_wait_of_all <= 120820500) {

                      if (parameters.avg_work_of_same_past_second <= 38168350) {
                        return tpcc_LM107(parameters);
                      } else {
                        return tpcc_LM108(parameters);
                      }
                    } else {
                      return tpcc_LM109(parameters);
                    }
                  } else {
                    return tpcc_LM110(parameters);
                  }
                } else {
                  return tpcc_LM111(parameters);
                }
              }
            } else {

              if (parameters.avg_wait_of_same_past_second <= 498407500) {

                if (parameters.avg_latency_of_same_last_20 <= 580720000) {
                  return tpcc_LM112(parameters);
                } else {

                  if (parameters.work_so_far <= 49552) {

                    if (parameters.mean_wait_of_all <= 143302000) {
                      return tpcc_LM113(parameters);
                    } else {

                      if (parameters.avg_work_of_same_past_second <= 29311550) {

                        if (parameters.max_latency_of_same_last_50 <= 1276675000) {
                          return tpcc_LM114(parameters);
                        } else {
                          return tpcc_LM115(parameters);
                        }
                      } else {
                        return tpcc_LM116(parameters);
                      }
                    }
                  } else {
                    return tpcc_LM117(parameters);
                  }
                }
              } else {

                if (parameters.total_wait_locks <= 414.5) {

                  if (parameters.avg_work_of_same_past_second <= 31425550) {

                    if (parameters.work_so_far <= 32659) {
                      return tpcc_LM118(parameters);
                    } else {
                      return tpcc_LM119(parameters);
                    }
                  } else {
                    return tpcc_LM120(parameters);
                  }
                } else {

                  if (parameters.avg_wait_of_same_past_second <= 572130500) {
                    return tpcc_LM121(parameters);
                  } else {

                    if (parameters.wait_so_far <= 418138439) {

                      if (parameters.avg_wait_of_same_past_second <= 592884500) {

                        if (parameters.avg_wait_of_same_past_second <= 587810000) {
                          return tpcc_LM122(parameters);
                        } else {
                          return tpcc_LM123(parameters);
                        }
                      } else {

                        if (parameters.avg_wait_of_same_past_second <= 604264500) {
                          return tpcc_LM124(parameters);
                        } else {

                          if (parameters.max_latency_of_same_last_50 <= 1515745000) {
                            return tpcc_LM125(parameters);
                          } else {
                            return tpcc_LM126(parameters);
                          }
                        }
                      }
                    } else {

                      if (parameters.avg_wait_of_same_past_second <= 617837500) {

                        if (parameters.max_latency_of_same_last_50 <= 1485880000) {
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
            }
          }
        } else {

          if (parameters.avg_work_of_same_past_second <= 31417650) {
            return tpcc_LM130(parameters);
          } else {

            if (parameters.avg_work_of_same_past_second <= 38088800) {

              if (parameters.cpu_usage <= 0.964) {

                if (parameters.avg_latency_of_same_last_20 <= 681367500) {

                  if (parameters.avg_wait_of_same_past_second <= 548798000) {

                    if (parameters.max_latency_of_same_last_50 <= 2179540000) {
                      return tpcc_LM131(parameters);
                    } else {
                      return tpcc_LM132(parameters);
                    }
                  } else {

                    if (parameters.avg_wait_of_same_past_second <= 550142500) {
                      return tpcc_LM133(parameters);
                    } else {

                      if (parameters.mean_wait_of_all <= 123336500) {

                        if (parameters.mean_wait_of_all <= 113242000) {

                          if (parameters.max_latency_of_same_last_50 <= 1943890000) {
                            return tpcc_LM134(parameters);
                          } else {
                            return tpcc_LM135(parameters);
                          }
                        } else {
                          return tpcc_LM136(parameters);
                        }
                      } else {
                        return tpcc_LM137(parameters);
                      }
                    }
                  }
                } else {

                  if (parameters.mean_wait_of_all <= 106715000) {

                    if (parameters.avg_work_of_same_past_second <= 34630150) {

                      if (parameters.total_wait_locks <= 350) {
                        return tpcc_LM138(parameters);
                      } else {

                        if (parameters.wait_so_far <= 186707395) {
                          return tpcc_LM139(parameters);
                        } else {
                          return tpcc_LM140(parameters);
                        }
                      }
                    } else {
                      return tpcc_LM141(parameters);
                    }
                  } else {
                    return tpcc_LM142(parameters);
                  }
                }
              } else {

                if (parameters.cpu_usage <= 0.989) {

                  if (parameters.avg_wait_of_same_past_second <= 487475500) {

                    if (parameters.wait_so_far <= 702571448.5) {
                      return tpcc_LM143(parameters);
                    } else {
                      return tpcc_LM144(parameters);
                    }
                  } else {

                    if (parameters.total_wait_locks <= 552.5) {
                      return tpcc_LM145(parameters);
                    } else {

                      if (parameters.avg_work_of_same_past_second <= 36825800) {

                        if (parameters.mean_wait_of_all <= 133188500) {
                          return tpcc_LM146(parameters);
                        } else {
                          return tpcc_LM147(parameters);
                        }
                      } else {
                        return tpcc_LM148(parameters);
                      }
                    }
                  }
                } else {
                  return tpcc_LM149(parameters);
                }
              }
            } else {

              if (parameters.max_latency_of_same_last_50 <= 1862290000) {

                if (parameters.avg_work_of_same_past_second <= 46671650) {

                  if (parameters.avg_work_of_same_past_second <= 43440250) {

                    if (parameters.avg_work_of_same_past_second <= 39060500) {
                      return tpcc_LM150(parameters);
                    } else {

                      if (parameters.avg_wait_of_same_past_second <= 390966500) {
                        return tpcc_LM151(parameters);
                      } else {

                        if (parameters.avg_wait_of_same_past_second <= 559246500) {

                          if (parameters.wait_so_far <= 422010798) {
                            return tpcc_LM152(parameters);
                          } else {
                            return tpcc_LM153(parameters);
                          }
                        } else {
                          return tpcc_LM154(parameters);
                        }
                      }
                    }
                  } else {

                    if (parameters.total_wait_locks <= 392.5) {
                      return tpcc_LM155(parameters);
                    } else {
                      return tpcc_LM156(parameters);
                    }
                  }
                } else {

                  if (parameters.avg_wait_of_same_past_second <= 583662000) {

                    if (parameters.wait_so_far <= 518483722) {
                      return tpcc_LM157(parameters);
                    } else {

                      if (parameters.total_wait_locks <= 401.5) {
                        return tpcc_LM158(parameters);
                      } else {
                        return tpcc_LM159(parameters);
                      }
                    }
                  } else {
                    return tpcc_LM160(parameters);
                  }
                }
              } else {

                if (parameters.total_wait_locks <= 416.5) {

                  if (parameters.avg_wait_of_same_past_second <= 514543500) {
                    return tpcc_LM161(parameters);
                  } else {
                    return tpcc_LM162(parameters);
                  }
                } else {

                  if (parameters.mean_wait_of_all <= 129280500) {

                    if (parameters.mean_wait_of_all <= 113891000) {
                      return tpcc_LM163(parameters);
                    } else {

                      if (parameters.cpu_usage <= 0.911) {
                        return tpcc_LM164(parameters);
                      } else {

                        if (parameters.cpu_usage <= 0.967) {

                          if (parameters.avg_work_of_same_past_second <= 40088150) {

                            if (parameters.mean_wait_of_all <= 114516500) {
                              return tpcc_LM165(parameters);
                            } else {
                              return tpcc_LM166(parameters);
                            }
                          } else {
                            return tpcc_LM167(parameters);
                          }
                        } else {
                          return tpcc_LM168(parameters);
                        }
                      }
                    }
                  } else {

                    if (parameters.mean_wait_of_all <= 134043000) {
                      return tpcc_LM169(parameters);
                    } else {
                      return tpcc_LM170(parameters);
                    }
                  }
                }
              }
            }
          }
        }
      } else {

        if (parameters.num_locks_so_far <= 4.5) {

          if (parameters.work_so_far <= 25856.5) {

            if (parameters.work_so_far <= 24323.5) {
              return tpcc_LM171(parameters);
            } else {
              return tpcc_LM172(parameters);
            }
          } else {

            if (parameters.work_so_far <= 46970.5) {
              return tpcc_LM173(parameters);
            } else {
              return tpcc_LM174(parameters);
            }
          }
        } else {
          return tpcc_LM175(parameters);
        }
      }
    }
  } else {

    if (parameters.avg_work_of_same_past_second <= 203334500) {

      if (parameters.total_wait_locks <= 255.5) {

        if (parameters.num_locks_so_far <= 9) {

          if (parameters.work_so_far <= 43189.5) {

            if (parameters.avg_wait_of_same_past_second <= 21386000) {
              return tpcc_LM176(parameters);
            } else {

              if (parameters.avg_work_of_same_past_second <= 86909550) {
                return tpcc_LM177(parameters);
              } else {

                if (parameters.avg_wait_of_same_past_second <= 78008950) {

                  if (parameters.wait_so_far <= 39811568) {
                    return tpcc_LM178(parameters);
                  } else {

                    if (parameters.wait_so_far <= 266290266) {
                      return tpcc_LM179(parameters);
                    } else {
                      return tpcc_LM180(parameters);
                    }
                  }
                } else {
                  return tpcc_LM181(parameters);
                }
              }
            }
          } else {
            return tpcc_LM182(parameters);
          }
        } else {

          if (parameters.avg_latency_of_same_last_20 <= 117743500) {
            return tpcc_LM183(parameters);
          } else {

            if (parameters.work_so_far <= 2661122.5) {
              return tpcc_LM184(parameters);
            } else {

              if (parameters.mean_wait_of_all <= 88009250) {
                return tpcc_LM185(parameters);
              } else {

                if (parameters.max_latency_of_same_last_50 <= 698438500) {

                  if (parameters.max_latency_of_same_last_50 <= 484156000) {

                    if (parameters.max_latency_of_same_last_50 <= 437392500) {
                      return tpcc_LM186(parameters);
                    } else {
                      return tpcc_LM187(parameters);
                    }
                  } else {
                    return tpcc_LM188(parameters);
                  }
                } else {
                  return tpcc_LM189(parameters);
                }
              }
            }
          }
        }
      } else {

        if (parameters.wait_so_far <= 163478191) {
          return tpcc_LM190(parameters);
        } else {

          if (parameters.total_wait_locks <= 390.5) {
            return tpcc_LM191(parameters);
          } else {

            if (parameters.avg_work_of_same_past_second <= 156410500) {
              return tpcc_LM192(parameters);
            } else {

              if (parameters.avg_latency_of_same_last_20 <= 528731500) {
                return tpcc_LM193(parameters);
              } else {
                return tpcc_LM194(parameters);
              }
            }
          }
        }
      }
    } else {

      if (parameters.avg_work_of_same_past_second <= 565839000) {

        if (parameters.total_wait_locks <= 268.5) {
          return tpcc_LM195(parameters);
        } else {

          if (parameters.wait_so_far <= 676038280) {
            return tpcc_LM196(parameters);
          } else {
            return tpcc_LM197(parameters);
          }
        }
      } else {

        if (parameters.mean_wait_of_all <= 100672000) {
          return tpcc_LM198(parameters);
        } else {

          if (parameters.avg_latency_of_same_last_20 <= 544144000) {

            if (parameters.wait_so_far <= 256360537.5) {
              return tpcc_LM199(parameters);
            } else {
              return tpcc_LM200(parameters);
            }
          } else {

            if (parameters.mean_wait_of_all <= 118278000) {

              if (parameters.mean_wait_of_all <= 107254500) {

                if (parameters.max_latency_of_same_last_50 <= 1505430000) {
                  return tpcc_LM201(parameters);
                } else {
                  return tpcc_LM202(parameters);
                }
              } else {

                if (parameters.avg_wait_of_same_past_second <= 159472000) {
                  return tpcc_LM203(parameters);
                } else {
                  return tpcc_LM204(parameters);
                }
              }
            } else {
              return tpcc_LM205(parameters);
            }
          }
        }
      }
    }
  }
}