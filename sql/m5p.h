#include "my_global.h"
#include "trace_tool.h"

static
double
new_order_LM1(work_wait &parameters) {
  double actual_remaining = 
	1.0651 * parameters.work_so_far 
	- 0.0929 * parameters.wait_so_far 
	+ 273646.2425 * parameters.total_wait_locks 
	+ 0.0013 * parameters.mean_wait_of_all 
	- 203870108.6289 * parameters.cpu_usage 
	+ 0.0043 * parameters.avg_work_of_same_past_second 
	- 0.0019 * parameters.avg_wait_of_same_past_second 
	+ 0.4378 * parameters.avg_latency_of_same_last_20 
	+ 213896936.3557;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM2(work_wait &parameters) {
  double actual_remaining = 
	662.1529 * parameters.work_so_far 
	- 0.2443 * parameters.wait_so_far 
	+ 206585.6639 * parameters.total_wait_locks 
	+ 0.1717 * parameters.mean_wait_of_all 
	+ 0.4806 * parameters.avg_work_of_same_past_second 
	- 0.1819 * parameters.avg_wait_of_same_past_second 
	+ 0.0018 * parameters.avg_latency_of_same_last_20 
	- 0.0214 * parameters.max_latency_of_same_last_50 
	+ 94230070.8072;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM3(work_wait &parameters) {
  double actual_remaining = 
	0.0219 * parameters.work_so_far 
	- 0.008 * parameters.wait_so_far 
	+ 347246.2944 * parameters.total_wait_locks 
	+ 0.0027 * parameters.mean_wait_of_all 
	+ 0.0217 * parameters.avg_work_of_same_past_second 
	- 0.3667 * parameters.avg_wait_of_same_past_second 
	+ 0.1545 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 137273355.0114;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM4(work_wait &parameters) {
  double actual_remaining = 
	0.0219 * parameters.work_so_far 
	- 0.0073 * parameters.wait_so_far 
	+ 6706.6874 * parameters.total_wait_locks 
	+ 0.0027 * parameters.mean_wait_of_all 
	+ 0.0195 * parameters.avg_work_of_same_past_second 
	- 0.0077 * parameters.avg_wait_of_same_past_second 
	+ 0.1287 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 241444616.0977;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM5(work_wait &parameters) {
  double actual_remaining = 
	0.0026 * parameters.work_so_far 
	- 0.005 * parameters.wait_so_far 
	+ 197706.6742 * parameters.total_wait_locks 
	+ 0.0013 * parameters.mean_wait_of_all 
	+ 0.3958 * parameters.avg_work_of_same_past_second 
	- 0.2388 * parameters.avg_wait_of_same_past_second 
	+ 0.0035 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 81019523.1688;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM6(work_wait &parameters) {
  double actual_remaining = 
	0.0026 * parameters.work_so_far 
	- 0.05 * parameters.wait_so_far 
	+ 3583.8202 * parameters.total_wait_locks 
	+ 0.2391 * parameters.mean_wait_of_all 
	+ 0.0163 * parameters.avg_work_of_same_past_second 
	- 0.0094 * parameters.avg_wait_of_same_past_second 
	+ 0.0035 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	+ 97048099.6799;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM7(work_wait &parameters) {
  double actual_remaining = 
	0.0026 * parameters.work_so_far 
	- 0.0055 * parameters.wait_so_far 
	+ 9676240.0098 * parameters.num_locks_so_far 
	+ 47670.2758 * parameters.total_wait_locks 
	+ 0.0068 * parameters.mean_wait_of_all 
	+ 0.0158 * parameters.avg_work_of_same_past_second 
	- 0.0437 * parameters.avg_wait_of_same_past_second 
	+ 0.0035 * parameters.avg_latency_of_same_last_20 
	- 0.0164 * parameters.max_latency_of_same_last_50 
	+ 58103319.0387;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM8(work_wait &parameters) {
  double actual_remaining = 
	0.0026 * parameters.work_so_far 
	- 0.0444 * parameters.wait_so_far 
	+ 6282334.9317 * parameters.num_locks_so_far 
	+ 190341.0182 * parameters.total_wait_locks 
	- 0.4997 * parameters.mean_wait_of_all 
	+ 0.0158 * parameters.avg_work_of_same_past_second 
	- 0.1849 * parameters.avg_wait_of_same_past_second 
	+ 0.0035 * parameters.avg_latency_of_same_last_20 
	- 0.012 * parameters.max_latency_of_same_last_50 
	+ 181047006.4713;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM9(work_wait &parameters) {
  double actual_remaining = 
	0.0026 * parameters.work_so_far 
	- 0.0193 * parameters.wait_so_far 
	+ 6282334.9317 * parameters.num_locks_so_far 
	+ 88272.7722 * parameters.total_wait_locks 
	- 0.1728 * parameters.mean_wait_of_all 
	+ 0.0158 * parameters.avg_work_of_same_past_second 
	- 0.3096 * parameters.avg_wait_of_same_past_second 
	+ 0.0035 * parameters.avg_latency_of_same_last_20 
	- 0.012 * parameters.max_latency_of_same_last_50 
	+ 140831210.338;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM10(work_wait &parameters) {
  double actual_remaining = 
	0.0026 * parameters.work_so_far 
	- 0.3206 * parameters.wait_so_far 
	- 3712.6414 * parameters.total_wait_locks 
	+ 0.2296 * parameters.mean_wait_of_all 
	+ 0.0158 * parameters.avg_work_of_same_past_second 
	- 0.009 * parameters.avg_wait_of_same_past_second 
	+ 0.0035 * parameters.avg_latency_of_same_last_20 
	- 0.0043 * parameters.max_latency_of_same_last_50 
	+ 239751889.0421;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM11(work_wait &parameters) {
  double actual_remaining = 
	0.0026 * parameters.work_so_far 
	+ 1.4961 * parameters.wait_so_far 
	- 21990.6464 * parameters.total_wait_locks 
	+ 0.0068 * parameters.mean_wait_of_all 
	+ 0.0158 * parameters.avg_work_of_same_past_second 
	- 0.009 * parameters.avg_wait_of_same_past_second 
	+ 0.0035 * parameters.avg_latency_of_same_last_20 
	- 0.0093 * parameters.max_latency_of_same_last_50 
	- 648008243.9274;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM12(work_wait &parameters) {
  double actual_remaining = 
	2123.9845 * parameters.work_so_far 
	- 0.3864 * parameters.wait_so_far 
	- 21990.6464 * parameters.total_wait_locks 
	+ 0.0068 * parameters.mean_wait_of_all 
	- 517767092.5229 * parameters.cpu_usage 
	+ 0.0158 * parameters.avg_work_of_same_past_second 
	- 0.009 * parameters.avg_wait_of_same_past_second 
	+ 0.0035 * parameters.avg_latency_of_same_last_20 
	- 0.0093 * parameters.max_latency_of_same_last_50 
	+ 854699369.2841;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM13(work_wait &parameters) {
  double actual_remaining = 
	0.0026 * parameters.work_so_far 
	- 0.0515 * parameters.wait_so_far 
	- 21990.6464 * parameters.total_wait_locks 
	+ 0.0068 * parameters.mean_wait_of_all 
	- 786071668.0516 * parameters.cpu_usage 
	+ 0.0158 * parameters.avg_work_of_same_past_second 
	+ 0.4951 * parameters.avg_wait_of_same_past_second 
	+ 0.1911 * parameters.avg_latency_of_same_last_20 
	- 0.0272 * parameters.max_latency_of_same_last_50 
	+ 778884839.7333;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM14(work_wait &parameters) {
  double actual_remaining = 
	0.0026 * parameters.work_so_far 
	- 0.0515 * parameters.wait_so_far 
	- 21990.6464 * parameters.total_wait_locks 
	+ 0.0068 * parameters.mean_wait_of_all 
	- 249684529.5621 * parameters.cpu_usage 
	+ 0.0158 * parameters.avg_work_of_same_past_second 
	+ 0.1888 * parameters.avg_wait_of_same_past_second 
	+ 0.0891 * parameters.avg_latency_of_same_last_20 
	- 0.0463 * parameters.max_latency_of_same_last_50 
	+ 355581283.3697;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM15(work_wait &parameters) {
  double actual_remaining = 
	0.0026 * parameters.work_so_far 
	- 0.0856 * parameters.wait_so_far 
	+ 3932.071 * parameters.total_wait_locks 
	+ 0.0013 * parameters.mean_wait_of_all 
	+ 309717282.0839 * parameters.cpu_usage 
	+ 0.7223 * parameters.avg_work_of_same_past_second 
	- 0.3379 * parameters.avg_wait_of_same_past_second 
	+ 0.1983 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	- 242294170.4682;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM16(work_wait &parameters) {
  double actual_remaining = 
	30.6257 * parameters.work_so_far 
	- 0.0019 * parameters.wait_so_far 
	+ 9914418.0643 * parameters.num_locks_so_far 
	- 149973.913 * parameters.total_wait_locks 
	+ 1.2036 * parameters.mean_wait_of_all 
	- 25647884.4615 * parameters.cpu_usage 
	- 0.0277 * parameters.avg_work_of_same_past_second 
	- 0.0014 * parameters.avg_wait_of_same_past_second 
	+ 0.1564 * parameters.avg_latency_of_same_last_20 
	- 0.0029 * parameters.max_latency_of_same_last_50 
	+ 78249323.6803;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM17(work_wait &parameters) {
  double actual_remaining = 
	30.6257 * parameters.work_so_far 
	- 0.0019 * parameters.wait_so_far 
	+ 288110140.2984 * parameters.num_locks_so_far 
	- 197898.3961 * parameters.total_wait_locks 
	- 3.2884 * parameters.mean_wait_of_all 
	- 38197579.9067 * parameters.cpu_usage 
	- 0.0638 * parameters.avg_work_of_same_past_second 
	- 0.0014 * parameters.avg_wait_of_same_past_second 
	+ 0.2669 * parameters.avg_latency_of_same_last_20 
	- 0.0008 * parameters.max_latency_of_same_last_50 
	- 277187600.3796;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM18(work_wait &parameters) {
  double actual_remaining = 
	30.6257 * parameters.work_so_far 
	- 0.0019 * parameters.wait_so_far 
	+ 6166015.2873 * parameters.num_locks_so_far 
	- 2740400.9779 * parameters.total_wait_locks 
	+ 22.0053 * parameters.mean_wait_of_all 
	- 18313149.4265 * parameters.cpu_usage 
	- 0.0292 * parameters.avg_work_of_same_past_second 
	- 0.0014 * parameters.avg_wait_of_same_past_second 
	+ 0.1442 * parameters.avg_latency_of_same_last_20 
	- 0.0008 * parameters.max_latency_of_same_last_50 
	- 1559265253.5916;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM19(work_wait &parameters) {
  double actual_remaining = 
	2508.0055 * parameters.work_so_far 
	- 0.0019 * parameters.wait_so_far 
	- 11419790.4045 * parameters.num_locks_so_far 
	- 1044959.1592 * parameters.total_wait_locks 
	+ 7.3476 * parameters.mean_wait_of_all 
	+ 461835553.6437 * parameters.cpu_usage 
	- 0.0766 * parameters.avg_work_of_same_past_second 
	- 3.8283 * parameters.avg_wait_of_same_past_second 
	+ 0.0049 * parameters.avg_latency_of_same_last_20 
	+ 498426420.0511;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM20(work_wait &parameters) {
  double actual_remaining = 
	2508.0055 * parameters.work_so_far 
	- 0.0019 * parameters.wait_so_far 
	- 11419790.4045 * parameters.num_locks_so_far 
	- 1044959.1592 * parameters.total_wait_locks 
	+ 7.3476 * parameters.mean_wait_of_all 
	+ 852198428.3127 * parameters.cpu_usage 
	- 0.0766 * parameters.avg_work_of_same_past_second 
	- 0.2449 * parameters.avg_wait_of_same_past_second 
	+ 0.0049 * parameters.avg_latency_of_same_last_20 
	- 684200691.423;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM21(work_wait &parameters) {
  double actual_remaining = 
	5093.3669 * parameters.work_so_far 
	- 0.0019 * parameters.wait_so_far 
	- 11419790.4045 * parameters.num_locks_so_far 
	- 2345819.5014 * parameters.total_wait_locks 
	+ 22.7195 * parameters.mean_wait_of_all 
	- 233978259.2583 * parameters.cpu_usage 
	+ 0.9657 * parameters.avg_work_of_same_past_second 
	- 1.4471 * parameters.avg_wait_of_same_past_second 
	- 0.096 * parameters.avg_latency_of_same_last_20 
	+ 0.0525 * parameters.max_latency_of_same_last_50 
	- 1561937584.1268;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM22(work_wait &parameters) {
  double actual_remaining = 
	5856.825 * parameters.work_so_far 
	- 0.0019 * parameters.wait_so_far 
	- 11419790.4045 * parameters.num_locks_so_far 
	- 2718294.6487 * parameters.total_wait_locks 
	+ 27.0855 * parameters.mean_wait_of_all 
	- 297567763.894 * parameters.cpu_usage 
	+ 1.25 * parameters.avg_work_of_same_past_second 
	- 1.782 * parameters.avg_wait_of_same_past_second 
	- 0.1236 * parameters.avg_latency_of_same_last_20 
	+ 0.0668 * parameters.max_latency_of_same_last_50 
	- 1856844511.8345;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM23(work_wait &parameters) {
  double actual_remaining = 
	217.5915 * parameters.work_so_far 
	- 0.0019 * parameters.wait_so_far 
	- 12419128.5546 * parameters.num_locks_so_far 
	- 356001.6559 * parameters.total_wait_locks 
	+ 1.6843 * parameters.mean_wait_of_all 
	- 816742.2604 * parameters.cpu_usage 
	- 0.124 * parameters.avg_work_of_same_past_second 
	+ 0.049 * parameters.avg_wait_of_same_past_second 
	+ 0.0049 * parameters.avg_latency_of_same_last_20 
	+ 362661140.2043;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM24(work_wait &parameters) {
  double actual_remaining = 
	217.5915 * parameters.work_so_far 
	- 0.0019 * parameters.wait_so_far 
	- 13540846.999 * parameters.num_locks_so_far 
	- 379255.3128 * parameters.total_wait_locks 
	+ 1.815 * parameters.mean_wait_of_all 
	- 816742.2604 * parameters.cpu_usage 
	- 0.1368 * parameters.avg_work_of_same_past_second 
	+ 0.056 * parameters.avg_wait_of_same_past_second 
	+ 0.0049 * parameters.avg_latency_of_same_last_20 
	+ 275088275.7353;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM25(work_wait &parameters) {
  double actual_remaining = 
	1.6846 * parameters.work_so_far 
	- 0.0019 * parameters.wait_so_far 
	- 309125.4057 * parameters.total_wait_locks 
	+ 2.4011 * parameters.mean_wait_of_all 
	- 816742.2604 * parameters.cpu_usage 
	- 0.6422 * parameters.avg_work_of_same_past_second 
	- 0.0014 * parameters.avg_wait_of_same_past_second 
	+ 0.2353 * parameters.avg_latency_of_same_last_20 
	+ 0.0473 * parameters.max_latency_of_same_last_50 
	+ 165929705.8285;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM26(work_wait &parameters) {
  double actual_remaining = 
	0.0147 * parameters.work_so_far 
	- 0.116 * parameters.wait_so_far 
	- 144724.5551 * parameters.total_wait_locks 
	+ 1.2864 * parameters.mean_wait_of_all 
	- 198560736.1283 * parameters.cpu_usage 
	- 0.0011 * parameters.avg_work_of_same_past_second 
	- 0.4021 * parameters.avg_wait_of_same_past_second 
	+ 0.251 * parameters.avg_latency_of_same_last_20 
	+ 341276077.2767;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
new_order_estimate(work_wait &parameters){

  if (parameters.total_wait_locks <= 421.5) {

    if (parameters.avg_latency_of_same_last_20 <= 215079500) {
      return new_order_LM1(parameters);
    } else {

      if (parameters.wait_so_far <= 196179902.5) {

        if (parameters.work_so_far <= 77178.5) {
          return new_order_LM2(parameters);
        } else {

          if (parameters.avg_work_of_same_past_second <= 160460000) {
            return new_order_LM3(parameters);
          } else {
            return new_order_LM4(parameters);
          }
        }
      } else {

        if (parameters.avg_latency_of_same_last_20 <= 486055000) {

          if (parameters.wait_so_far <= 322162297) {
            return new_order_LM5(parameters);
          } else {

            if (parameters.work_so_far <= 54140) {
              return new_order_LM6(parameters);
            } else {

              if (parameters.avg_work_of_same_past_second <= 143693500) {

                if (parameters.total_wait_locks <= 250.5) {
                  return new_order_LM7(parameters);
                } else {

                  if (parameters.max_latency_of_same_last_50 <= 825215000) {
                    return new_order_LM8(parameters);
                  } else {
                    return new_order_LM9(parameters);
                  }
                }
              } else {

                if (parameters.wait_so_far <= 632978695) {
                  return new_order_LM10(parameters);
                } else {

                  if (parameters.work_so_far <= 73893) {

                    if (parameters.wait_so_far <= 719361144) {
                      return new_order_LM11(parameters);
                    } else {
                      return new_order_LM12(parameters);
                    }
                  } else {

                    if (parameters.max_latency_of_same_last_50 <= 1585690000) {
                      return new_order_LM13(parameters);
                    } else {
                      return new_order_LM14(parameters);
                    }
                  }
                }
              }
            }
          }
        } else {
          return new_order_LM15(parameters);
        }
      }
    }
  } else {

    if (parameters.wait_so_far <= 142520377.5) {

      if (parameters.work_so_far <= 64481.5) {

        if (parameters.mean_wait_of_all <= 158627000) {

          if (parameters.total_wait_locks <= 453.5) {
            return new_order_LM16(parameters);
          } else {

            if (parameters.avg_work_of_same_past_second <= 202700000) {
              return new_order_LM17(parameters);
            } else {
              return new_order_LM18(parameters);
            }
          }
        } else {

          if (parameters.total_wait_locks <= 712.5) {

            if (parameters.avg_wait_of_same_past_second <= 316890000) {

              if (parameters.avg_wait_of_same_past_second <= 294959500) {
                return new_order_LM19(parameters);
              } else {
                return new_order_LM20(parameters);
              }
            } else {

              if (parameters.max_latency_of_same_last_50 <= 1532895000) {
                return new_order_LM21(parameters);
              } else {
                return new_order_LM22(parameters);
              }
            }
          } else {

            if (parameters.avg_work_of_same_past_second <= 223867000) {
              return new_order_LM23(parameters);
            } else {
              return new_order_LM24(parameters);
            }
          }
        }
      } else {
        return new_order_LM25(parameters);
      }
    } else {
      return new_order_LM26(parameters);
    }
  }
}
static
double
payment_LM1(work_wait &parameters) {
  double actual_remaining = 
	31.7639 * parameters.work_so_far 
	+ 0.0162 * parameters.wait_so_far 
	+ 801.8117 * parameters.total_wait_locks 
	- 0.0079 * parameters.avg_work_of_same_past_second 
	+ 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0397 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 3573519.3929;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM2(work_wait &parameters) {
  double actual_remaining = 
	58.7751 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 104378.0678 * parameters.total_wait_locks 
	- 0.0044 * parameters.mean_wait_of_all 
	- 0.0272 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0016 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 1962803.7379;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM3(work_wait &parameters) {
  double actual_remaining = 
	791.3842 * parameters.work_so_far 
	- 0.0135 * parameters.wait_so_far 
	+ 49676.0488 * parameters.total_wait_locks 
	- 0.1615 * parameters.mean_wait_of_all 
	- 36277704.3982 * parameters.cpu_usage 
	- 0.342 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0035 * parameters.avg_latency_of_same_last_20 
	+ 0.0057 * parameters.max_latency_of_same_last_50 
	+ 43345149.3223;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM4(work_wait &parameters) {
  double actual_remaining = 
	791.3842 * parameters.work_so_far 
	- 0.0135 * parameters.wait_so_far 
	+ 49676.0488 * parameters.total_wait_locks 
	- 0.1615 * parameters.mean_wait_of_all 
	- 36277704.3982 * parameters.cpu_usage 
	- 0.3718 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0035 * parameters.avg_latency_of_same_last_20 
	+ 0.0062 * parameters.max_latency_of_same_last_50 
	+ 45512897.9023;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM5(work_wait &parameters) {
  double actual_remaining = 
	1334.7469 * parameters.work_so_far 
	- 0.074 * parameters.wait_so_far 
	+ 97240.9953 * parameters.total_wait_locks 
	- 0.7957 * parameters.mean_wait_of_all 
	- 26317795.317 * parameters.cpu_usage 
	- 0.0243 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.5048 * parameters.avg_latency_of_same_last_20 
	+ 0.0886 * parameters.max_latency_of_same_last_50 
	+ 90862132.8214;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM6(work_wait &parameters) {
  double actual_remaining = 
	1334.7469 * parameters.work_so_far 
	- 0.074 * parameters.wait_so_far 
	+ 97240.9953 * parameters.total_wait_locks 
	- 0.7957 * parameters.mean_wait_of_all 
	- 26317795.317 * parameters.cpu_usage 
	- 0.0243 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.5048 * parameters.avg_latency_of_same_last_20 
	+ 0.091 * parameters.max_latency_of_same_last_50 
	+ 90203787.9843;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM7(work_wait &parameters) {
  double actual_remaining = 
	1334.7469 * parameters.work_so_far 
	- 0.0938 * parameters.wait_so_far 
	+ 97240.9953 * parameters.total_wait_locks 
	- 0.9154 * parameters.mean_wait_of_all 
	- 26317795.317 * parameters.cpu_usage 
	- 1.3686 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.3826 * parameters.avg_latency_of_same_last_20 
	+ 0.0626 * parameters.max_latency_of_same_last_50 
	+ 116972780.4751;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM8(work_wait &parameters) {
  double actual_remaining = 
	1334.7469 * parameters.work_so_far 
	+ 0.014 * parameters.wait_so_far 
	+ 97240.9953 * parameters.total_wait_locks 
	- 1.0069 * parameters.mean_wait_of_all 
	- 26317795.317 * parameters.cpu_usage 
	- 1.0101 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.3826 * parameters.avg_latency_of_same_last_20 
	+ 0.0626 * parameters.max_latency_of_same_last_50 
	+ 117100589.048;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM9(work_wait &parameters) {
  double actual_remaining = 
	1334.7469 * parameters.work_so_far 
	- 0.1001 * parameters.wait_so_far 
	+ 97240.9953 * parameters.total_wait_locks 
	- 1.0139 * parameters.mean_wait_of_all 
	- 26317795.317 * parameters.cpu_usage 
	- 1.0101 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.3826 * parameters.avg_latency_of_same_last_20 
	+ 0.0626 * parameters.max_latency_of_same_last_50 
	+ 117654074.4566;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM10(work_wait &parameters) {
  double actual_remaining = 
	1334.7469 * parameters.work_so_far 
	- 0.0444 * parameters.wait_so_far 
	+ 249534.4553 * parameters.total_wait_locks 
	- 0.6153 * parameters.mean_wait_of_all 
	- 26317795.317 * parameters.cpu_usage 
	- 0.0243 * parameters.avg_work_of_same_past_second 
	- 0.215 * parameters.avg_wait_of_same_past_second 
	- 0.227 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 67681659.072;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM11(work_wait &parameters) {
  double actual_remaining = 
	1853.1848 * parameters.work_so_far 
	- 0.0289 * parameters.wait_so_far 
	+ 33799.8915 * parameters.total_wait_locks 
	- 0.3654 * parameters.mean_wait_of_all 
	- 26317795.317 * parameters.cpu_usage 
	- 0.0243 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.1268 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 48949346.2504;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM12(work_wait &parameters) {
  double actual_remaining = 
	1853.1848 * parameters.work_so_far 
	- 0.0289 * parameters.wait_so_far 
	+ 33799.8915 * parameters.total_wait_locks 
	- 0.3654 * parameters.mean_wait_of_all 
	- 26317795.317 * parameters.cpu_usage 
	- 0.0243 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.0828 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 46918270.9086;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM13(work_wait &parameters) {
  double actual_remaining = 
	213.2781 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 3173.0028 * parameters.total_wait_locks 
	+ 0.049 * parameters.mean_wait_of_all 
	- 5474227.1604 * parameters.cpu_usage 
	- 0.0243 * parameters.avg_work_of_same_past_second 
	- 0.0741 * parameters.avg_wait_of_same_past_second 
	+ 0.0035 * parameters.avg_latency_of_same_last_20 
	+ 0.0132 * parameters.max_latency_of_same_last_50 
	+ 6919735.4289;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM14(work_wait &parameters) {
  double actual_remaining = 
	167.6912 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 1051.0375 * parameters.total_wait_locks 
	- 0.1289 * parameters.mean_wait_of_all 
	- 1116266.5987 * parameters.cpu_usage 
	- 0.0243 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0058 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 25255411.9973;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM15(work_wait &parameters) {
  double actual_remaining = 
	15288.4696 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 34335.9687 * parameters.total_wait_locks 
	- 0.0012 * parameters.mean_wait_of_all 
	- 1116266.5987 * parameters.cpu_usage 
	- 0.0243 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0058 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 99379806.7448;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM16(work_wait &parameters) {
  double actual_remaining = 
	14625.0368 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 39941.8568 * parameters.total_wait_locks 
	- 0.0012 * parameters.mean_wait_of_all 
	- 1116266.5987 * parameters.cpu_usage 
	- 0.0243 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0058 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 89866764.8995;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM17(work_wait &parameters) {
  double actual_remaining = 
	5779.252 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 1051.0375 * parameters.total_wait_locks 
	- 0.0012 * parameters.mean_wait_of_all 
	- 1116266.5987 * parameters.cpu_usage 
	- 0.0243 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0058 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 27379962.829;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM18(work_wait &parameters) {
  double actual_remaining = 
	5779.252 * parameters.work_so_far 
	- 0.0116 * parameters.wait_so_far 
	+ 1051.0375 * parameters.total_wait_locks 
	- 0.0012 * parameters.mean_wait_of_all 
	- 1116266.5987 * parameters.cpu_usage 
	- 0.0243 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0058 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 20864482.0343;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM19(work_wait &parameters) {
  double actual_remaining = 
	5779.252 * parameters.work_so_far 
	- 0.0116 * parameters.wait_so_far 
	+ 1051.0375 * parameters.total_wait_locks 
	- 0.0012 * parameters.mean_wait_of_all 
	- 1116266.5987 * parameters.cpu_usage 
	- 0.0243 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0058 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 21547996.4573;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM20(work_wait &parameters) {
  double actual_remaining = 
	167.6912 * parameters.work_so_far 
	- 0.0355 * parameters.wait_so_far 
	+ 68632.3053 * parameters.total_wait_locks 
	- 0.0012 * parameters.mean_wait_of_all 
	- 1116266.5987 * parameters.cpu_usage 
	+ 5.7712 * parameters.avg_work_of_same_past_second 
	- 0.2664 * parameters.avg_wait_of_same_past_second 
	+ 0.0058 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 19279893.7192;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM21(work_wait &parameters) {
  double actual_remaining = 
	453.0952 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 1051.0375 * parameters.total_wait_locks 
	- 0.0012 * parameters.mean_wait_of_all 
	- 971296.9106 * parameters.cpu_usage 
	- 0.0227 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0189 * parameters.avg_latency_of_same_last_20 
	- 0.0052 * parameters.max_latency_of_same_last_50 
	+ 8235955.4068;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM22(work_wait &parameters) {
  double actual_remaining = 
	2103.5381 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 90585.2122 * parameters.total_wait_locks 
	- 0.3396 * parameters.mean_wait_of_all 
	+ 17231838.4414 * parameters.cpu_usage 
	+ 0.7742 * parameters.avg_work_of_same_past_second 
	+ 0.0004 * parameters.avg_wait_of_same_past_second 
	- 0.0271 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	- 10332765.5033;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM23(work_wait &parameters) {
  double actual_remaining = 
	1350.9316 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 192542.5311 * parameters.total_wait_locks 
	+ 0.0145 * parameters.mean_wait_of_all 
	- 2092407894.3675 * parameters.cpu_usage 
	+ 2.3129 * parameters.avg_work_of_same_past_second 
	+ 0.0004 * parameters.avg_wait_of_same_past_second 
	- 0.0712 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	+ 1996037411.5199;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM24(work_wait &parameters) {
  double actual_remaining = 
	76.361 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 39065.4731 * parameters.total_wait_locks 
	+ 0.0092 * parameters.mean_wait_of_all 
	+ 24134058.6694 * parameters.cpu_usage 
	- 1.1988 * parameters.avg_work_of_same_past_second 
	- 0.0241 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	+ 10831679.0068;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM25(work_wait &parameters) {
  double actual_remaining = 
	2076.4866 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 24069.1219 * parameters.total_wait_locks 
	- 0.6373 * parameters.mean_wait_of_all 
	+ 572991399.5878 * parameters.cpu_usage 
	- 0.3657 * parameters.avg_work_of_same_past_second 
	+ 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	- 467538374.9915;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM26(work_wait &parameters) {
  double actual_remaining = 
	4051.5388 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 24069.1219 * parameters.total_wait_locks 
	+ 0.0092 * parameters.mean_wait_of_all 
	+ 506182887.4633 * parameters.cpu_usage 
	- 0.3657 * parameters.avg_work_of_same_past_second 
	+ 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	- 505177910.183;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM27(work_wait &parameters) {
  double actual_remaining = 
	3619.7065 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 138987.7871 * parameters.total_wait_locks 
	+ 0.0092 * parameters.mean_wait_of_all 
	+ 506182887.4633 * parameters.cpu_usage 
	- 0.3657 * parameters.avg_work_of_same_past_second 
	+ 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	- 533194699.7129;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM28(work_wait &parameters) {
  double actual_remaining = 
	-519.7909 * parameters.work_so_far 
	- 0.0224 * parameters.wait_so_far 
	- 211233.579 * parameters.total_wait_locks 
	- 4.0336 * parameters.mean_wait_of_all 
	+ 192983199.1786 * parameters.cpu_usage 
	- 1.1517 * parameters.avg_work_of_same_past_second 
	+ 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0151 * parameters.avg_latency_of_same_last_20 
	+ 0.0146 * parameters.max_latency_of_same_last_50 
	+ 443400416.6729;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM29(work_wait &parameters) {
  double actual_remaining = 
	-519.7909 * parameters.work_so_far 
	- 0.0246 * parameters.wait_so_far 
	- 176239.452 * parameters.total_wait_locks 
	- 4.0399 * parameters.mean_wait_of_all 
	+ 192983199.1786 * parameters.cpu_usage 
	- 1.2795 * parameters.avg_work_of_same_past_second 
	+ 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0151 * parameters.avg_latency_of_same_last_20 
	+ 0.0116 * parameters.max_latency_of_same_last_50 
	+ 440035549.7668;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM30(work_wait &parameters) {
  double actual_remaining = 
	-167.0623 * parameters.work_so_far 
	- 0.025 * parameters.wait_so_far 
	- 176239.452 * parameters.total_wait_locks 
	- 4.0338 * parameters.mean_wait_of_all 
	+ 192983199.1786 * parameters.cpu_usage 
	- 1.2949 * parameters.avg_work_of_same_past_second 
	+ 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0151 * parameters.avg_latency_of_same_last_20 
	+ 0.0116 * parameters.max_latency_of_same_last_50 
	+ 433743536.934;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM31(work_wait &parameters) {
  double actual_remaining = 
	-167.0623 * parameters.work_so_far 
	- 0.025 * parameters.wait_so_far 
	- 176239.452 * parameters.total_wait_locks 
	- 4.0338 * parameters.mean_wait_of_all 
	+ 192983199.1786 * parameters.cpu_usage 
	- 1.2949 * parameters.avg_work_of_same_past_second 
	+ 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0151 * parameters.avg_latency_of_same_last_20 
	+ 0.0116 * parameters.max_latency_of_same_last_50 
	+ 433708260.2505;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM32(work_wait &parameters) {
  double actual_remaining = 
	-111.3683 * parameters.work_so_far 
	- 0.0252 * parameters.wait_so_far 
	- 176239.452 * parameters.total_wait_locks 
	- 4.0707 * parameters.mean_wait_of_all 
	+ 192983199.1786 * parameters.cpu_usage 
	- 1.3699 * parameters.avg_work_of_same_past_second 
	+ 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0151 * parameters.avg_latency_of_same_last_20 
	+ 0.0116 * parameters.max_latency_of_same_last_50 
	+ 439570578.7885;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM33(work_wait &parameters) {
  double actual_remaining = 
	-817.8668 * parameters.work_so_far 
	- 0.0141 * parameters.wait_so_far 
	- 176660.4771 * parameters.total_wait_locks 
	- 2.695 * parameters.mean_wait_of_all 
	+ 192983199.1786 * parameters.cpu_usage 
	- 0.9219 * parameters.avg_work_of_same_past_second 
	+ 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0222 * parameters.avg_latency_of_same_last_20 
	+ 0.009 * parameters.max_latency_of_same_last_50 
	+ 260273122.04;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM34(work_wait &parameters) {
  double actual_remaining = 
	449.8743 * parameters.work_so_far 
	- 0.0053 * parameters.wait_so_far 
	- 4880.0241 * parameters.total_wait_locks 
	+ 0.0095 * parameters.mean_wait_of_all 
	- 0.078 * parameters.avg_work_of_same_past_second 
	+ 0.0098 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	- 0.0018 * parameters.max_latency_of_same_last_50 
	+ 2560224.8805;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM35(work_wait &parameters) {
  double actual_remaining = 
	1496.023 * parameters.work_so_far 
	- 0.0012 * parameters.wait_so_far 
	- 6090.9394 * parameters.total_wait_locks 
	+ 0.0095 * parameters.mean_wait_of_all 
	- 1.2479 * parameters.avg_work_of_same_past_second 
	+ 0.0048 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	- 0.002 * parameters.max_latency_of_same_last_50 
	+ 18702002.4804;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM36(work_wait &parameters) {
  double actual_remaining = 
	419.6306 * parameters.work_so_far 
	- 0.0012 * parameters.wait_so_far 
	- 4029.7576 * parameters.total_wait_locks 
	+ 0.0095 * parameters.mean_wait_of_all 
	- 0.1374 * parameters.avg_work_of_same_past_second 
	+ 0.0048 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	- 0.0016 * parameters.max_latency_of_same_last_50 
	+ 6273902.0242;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM37(work_wait &parameters) {
  double actual_remaining = 
	2210.2389 * parameters.work_so_far 
	- 0.0018 * parameters.wait_so_far 
	+ 2479.1866 * parameters.total_wait_locks 
	+ 0.0487 * parameters.mean_wait_of_all 
	- 0.0343 * parameters.avg_work_of_same_past_second 
	+ 0.0031 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	- 29172309.2937;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM38(work_wait &parameters) {
  double actual_remaining = 
	210.1573 * parameters.work_so_far 
	- 0.0126 * parameters.wait_so_far 
	+ 2479.1866 * parameters.total_wait_locks 
	+ 0.043 * parameters.mean_wait_of_all 
	+ 1.2328 * parameters.avg_work_of_same_past_second 
	- 0.0458 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 2389901.9715;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM39(work_wait &parameters) {
  double actual_remaining = 
	357.104 * parameters.work_so_far 
	+ 0.0661 * parameters.wait_so_far 
	+ 2479.1866 * parameters.total_wait_locks 
	+ 0.043 * parameters.mean_wait_of_all 
	+ 3.2013 * parameters.avg_work_of_same_past_second 
	+ 0.0267 * parameters.avg_wait_of_same_past_second 
	+ 0.04 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	- 72635246.8766;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM40(work_wait &parameters) {
  double actual_remaining = 
	210.1573 * parameters.work_so_far 
	+ 0.1636 * parameters.wait_so_far 
	+ 2479.1866 * parameters.total_wait_locks 
	+ 0.0734 * parameters.mean_wait_of_all 
	+ 2.5225 * parameters.avg_work_of_same_past_second 
	+ 0.0186 * parameters.avg_wait_of_same_past_second 
	+ 0.0626 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	- 64116194.2133;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM41(work_wait &parameters) {
  double actual_remaining = 
	210.1573 * parameters.work_so_far 
	- 0.018 * parameters.wait_so_far 
	+ 2479.1866 * parameters.total_wait_locks 
	+ 0.043 * parameters.mean_wait_of_all 
	+ 0.4686 * parameters.avg_work_of_same_past_second 
	+ 0.0031 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 178851.3618;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM42(work_wait &parameters) {
  double actual_remaining = 
	0.0611 * parameters.work_so_far 
	- 0.0075 * parameters.wait_so_far 
	+ 7459.0309 * parameters.total_wait_locks 
	- 0.1554 * parameters.avg_work_of_same_past_second 
	- 0.0065 * parameters.avg_wait_of_same_past_second 
	+ 0.0095 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 21797700.2284;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM43(work_wait &parameters) {
  double actual_remaining = 
	-0.0995 * parameters.work_so_far 
	+ 0.0022 * parameters.wait_so_far 
	- 53171.0986 * parameters.total_wait_locks 
	+ 0.3579 * parameters.mean_wait_of_all 
	+ 0.1958 * parameters.avg_work_of_same_past_second 
	- 0.0203 * parameters.avg_wait_of_same_past_second 
	+ 0.0127 * parameters.avg_latency_of_same_last_20 
	+ 0.0006 * parameters.max_latency_of_same_last_50 
	- 4705363.9688;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM44(work_wait &parameters) {
  double actual_remaining = 
	-1.1362 * parameters.work_so_far 
	+ 0.0979 * parameters.wait_so_far 
	- 83976.1599 * parameters.total_wait_locks 
	+ 0.6633 * parameters.mean_wait_of_all 
	- 0.5965 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.0163 * parameters.avg_latency_of_same_last_20 
	+ 0.0006 * parameters.max_latency_of_same_last_50 
	+ 78763633.3871;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM45(work_wait &parameters) {
  double actual_remaining = 
	-1.1072 * parameters.work_so_far 
	+ 0.031 * parameters.wait_so_far 
	- 86853.7283 * parameters.total_wait_locks 
	+ 1.6194 * parameters.mean_wait_of_all 
	- 0.5384 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.0163 * parameters.avg_latency_of_same_last_20 
	+ 0.0006 * parameters.max_latency_of_same_last_50 
	- 91372849.1697;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM46(work_wait &parameters) {
  double actual_remaining = 
	-1.3527 * parameters.work_so_far 
	+ 0.0308 * parameters.wait_so_far 
	- 184548.2113 * parameters.total_wait_locks 
	+ 0.6633 * parameters.mean_wait_of_all 
	+ 1.767 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.0496 * parameters.avg_latency_of_same_last_20 
	+ 0.0006 * parameters.max_latency_of_same_last_50 
	+ 41253181.2194;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM47(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0097 * parameters.wait_so_far 
	- 109513.3373 * parameters.total_wait_locks 
	+ 0.7353 * parameters.mean_wait_of_all 
	+ 1960479.3475 * parameters.cpu_usage 
	+ 0.3202 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	+ 0.0001 * parameters.max_latency_of_same_last_50 
	- 33920164.2905;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM48(work_wait &parameters) {
  double actual_remaining = 
	-481.048 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	- 8629.3644 * parameters.total_wait_locks 
	+ 0.0534 * parameters.mean_wait_of_all 
	+ 324312338.7375 * parameters.cpu_usage 
	+ 1.4949 * parameters.avg_work_of_same_past_second 
	- 0.0629 * parameters.avg_wait_of_same_past_second 
	+ 0.0022 * parameters.avg_latency_of_same_last_20 
	- 0.0024 * parameters.max_latency_of_same_last_50 
	- 274741745.0591;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM49(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	- 8629.3644 * parameters.total_wait_locks 
	+ 0.0534 * parameters.mean_wait_of_all 
	+ 37628882.1398 * parameters.cpu_usage 
	+ 0.5636 * parameters.avg_work_of_same_past_second 
	- 0.0095 * parameters.avg_wait_of_same_past_second 
	+ 0.2059 * parameters.avg_latency_of_same_last_20 
	- 0.006 * parameters.max_latency_of_same_last_50 
	- 101981153.7994;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM50(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	- 8629.3644 * parameters.total_wait_locks 
	+ 0.0534 * parameters.mean_wait_of_all 
	+ 37628882.1398 * parameters.cpu_usage 
	+ 0.5636 * parameters.avg_work_of_same_past_second 
	- 0.0095 * parameters.avg_wait_of_same_past_second 
	+ 0.1006 * parameters.avg_latency_of_same_last_20 
	- 0.006 * parameters.max_latency_of_same_last_50 
	- 52765135.9537;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM51(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	- 8629.3644 * parameters.total_wait_locks 
	+ 0.0534 * parameters.mean_wait_of_all 
	+ 37628882.1398 * parameters.cpu_usage 
	+ 0.5636 * parameters.avg_work_of_same_past_second 
	- 0.0095 * parameters.avg_wait_of_same_past_second 
	+ 0.0022 * parameters.avg_latency_of_same_last_20 
	- 0.006 * parameters.max_latency_of_same_last_50 
	- 7860372.0734;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM52(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0146 * parameters.wait_so_far 
	- 8629.3644 * parameters.total_wait_locks 
	+ 0.0534 * parameters.mean_wait_of_all 
	+ 49183733.8142 * parameters.cpu_usage 
	+ 0.1717 * parameters.avg_work_of_same_past_second 
	- 0.013 * parameters.avg_wait_of_same_past_second 
	+ 0.0022 * parameters.avg_latency_of_same_last_20 
	+ 0.0102 * parameters.max_latency_of_same_last_50 
	- 38661035.9024;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM53(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0033 * parameters.wait_so_far 
	+ 10801.6077 * parameters.total_wait_locks 
	- 0.0003 * parameters.mean_wait_of_all 
	+ 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0.0056 * parameters.max_latency_of_same_last_50 
	+ 7555296.6655;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM54(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 21.2325 * parameters.total_wait_locks 
	- 0.446 * parameters.mean_wait_of_all 
	- 982325287.1334 * parameters.cpu_usage 
	+ 0.3861 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 877245476.2119;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM55(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0055 * parameters.wait_so_far 
	- 18022.2721 * parameters.total_wait_locks 
	- 0.0033 * parameters.mean_wait_of_all 
	- 2723627.7202 * parameters.cpu_usage 
	- 0.0025 * parameters.avg_work_of_same_past_second 
	+ 0.001 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 33889622.6785;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM56(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	- 87167.7407 * parameters.total_wait_locks 
	- 0.0051 * parameters.mean_wait_of_all 
	- 2723627.7202 * parameters.cpu_usage 
	- 1.1008 * parameters.avg_work_of_same_past_second 
	+ 0.1013 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0.0089 * parameters.max_latency_of_same_last_50 
	+ 69996972.835;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
payment_estimate(work_wait &parameters){

  if (parameters.total_wait_locks <= 412.5) {

    if (parameters.work_so_far <= 17608.5) {

      if (parameters.work_so_far <= 7645) {
        return payment_LM1(parameters);
      } else {

        if (parameters.avg_wait_of_same_past_second <= 116018000) {

          if (parameters.total_wait_locks <= 61.5) {
            return payment_LM2(parameters);
          } else {

            if (parameters.avg_work_of_same_past_second <= 9809510) {

              if (parameters.avg_latency_of_same_last_20 <= 92056350) {

                if (parameters.mean_wait_of_all <= 77257500) {

                  if (parameters.total_wait_locks <= 74.5) {

                    if (parameters.max_latency_of_same_last_50 <= 178813500) {
                      return payment_LM3(parameters);
                    } else {
                      return payment_LM4(parameters);
                    }
                  } else {

                    if (parameters.total_wait_locks <= 134.5) {

                      if (parameters.max_latency_of_same_last_50 <= 223859000) {

                        if (parameters.avg_work_of_same_past_second <= 5746395) {

                          if (parameters.max_latency_of_same_last_50 <= 112813500) {
                            return payment_LM5(parameters);
                          } else {
                            return payment_LM6(parameters);
                          }
                        } else {

                          if (parameters.avg_work_of_same_past_second <= 6624820) {
                            return payment_LM7(parameters);
                          } else {

                            if (parameters.wait_so_far <= 36958722) {
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

                      if (parameters.work_so_far <= 10459) {
                        return payment_LM11(parameters);
                      } else {
                        return payment_LM12(parameters);
                      }
                    }
                  }
                } else {
                  return payment_LM13(parameters);
                }
              } else {

                if (parameters.wait_so_far <= 64182226.5) {
                  return payment_LM14(parameters);
                } else {

                  if (parameters.work_so_far <= 10643) {

                    if (parameters.wait_so_far <= 140282867) {

                      if (parameters.work_so_far <= 8908) {
                        return payment_LM15(parameters);
                      } else {
                        return payment_LM16(parameters);
                      }
                    } else {

                      if (parameters.cpu_usage <= 0.927) {
                        return payment_LM17(parameters);
                      } else {

                        if (parameters.wait_so_far <= 350207169.5) {
                          return payment_LM18(parameters);
                        } else {
                          return payment_LM19(parameters);
                        }
                      }
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

          if (parameters.cpu_usage <= 0.99) {

            if (parameters.avg_work_of_same_past_second <= 15913600) {

              if (parameters.avg_work_of_same_past_second <= 15224150) {
                return payment_LM22(parameters);
              } else {
                return payment_LM23(parameters);
              }
            } else {

              if (parameters.total_wait_locks <= 296) {
                return payment_LM24(parameters);
              } else {

                if (parameters.wait_so_far <= 83041315) {

                  if (parameters.cpu_usage <= 0.964) {
                    return payment_LM25(parameters);
                  } else {

                    if (parameters.work_so_far <= 11528.5) {
                      return payment_LM26(parameters);
                    } else {
                      return payment_LM27(parameters);
                    }
                  }
                } else {

                  if (parameters.work_so_far <= 16228) {

                    if (parameters.max_latency_of_same_last_50 <= 549463500) {
                      return payment_LM28(parameters);
                    } else {

                      if (parameters.work_so_far <= 12237) {
                        return payment_LM29(parameters);
                      } else {

                        if (parameters.work_so_far <= 15762.5) {

                          if (parameters.wait_so_far <= 419317863.5) {
                            return payment_LM30(parameters);
                          } else {
                            return payment_LM31(parameters);
                          }
                        } else {
                          return payment_LM32(parameters);
                        }
                      }
                    }
                  } else {
                    return payment_LM33(parameters);
                  }
                }
              }
            }
          } else {

            if (parameters.work_so_far <= 14750) {

              if (parameters.avg_wait_of_same_past_second <= 182434000) {
                return payment_LM34(parameters);
              } else {

                if (parameters.total_wait_locks <= 109.5) {
                  return payment_LM35(parameters);
                } else {
                  return payment_LM36(parameters);
                }
              }
            } else {

              if (parameters.mean_wait_of_all <= 96884850) {
                return payment_LM37(parameters);
              } else {

                if (parameters.wait_so_far <= 127908843) {

                  if (parameters.avg_work_of_same_past_second <= 20285500) {
                    return payment_LM38(parameters);
                  } else {

                    if (parameters.avg_wait_of_same_past_second <= 157839500) {
                      return payment_LM39(parameters);
                    } else {
                      return payment_LM40(parameters);
                    }
                  }
                } else {
                  return payment_LM41(parameters);
                }
              }
            }
          }
        }
      }
    } else {
      return payment_LM42(parameters);
    }
  } else {

    if (parameters.avg_wait_of_same_past_second <= 468529000) {

      if (parameters.cpu_usage <= 0.94) {

        if (parameters.avg_work_of_same_past_second <= 20071300) {
          return payment_LM43(parameters);
        } else {

          if (parameters.total_wait_locks <= 646.5) {

            if (parameters.avg_work_of_same_past_second <= 23324700) {
              return payment_LM44(parameters);
            } else {
              return payment_LM45(parameters);
            }
          } else {
            return payment_LM46(parameters);
          }
        }
      } else {

        if (parameters.avg_latency_of_same_last_20 <= 475217000) {
          return payment_LM47(parameters);
        } else {

          if (parameters.avg_wait_of_same_past_second <= 446219000) {

            if (parameters.work_so_far <= 67074) {
              return payment_LM48(parameters);
            } else {

              if (parameters.max_latency_of_same_last_50 <= 1240360000) {

                if (parameters.work_so_far <= 347970) {
                  return payment_LM49(parameters);
                } else {
                  return payment_LM50(parameters);
                }
              } else {
                return payment_LM51(parameters);
              }
            }
          } else {
            return payment_LM52(parameters);
          }
        }
      }
    } else {

      if (parameters.cpu_usage <= 0.979) {
        return payment_LM53(parameters);
      } else {

        if (parameters.avg_wait_of_same_past_second <= 518082500) {
          return payment_LM54(parameters);
        } else {

          if (parameters.total_wait_locks <= 642.5) {
            return payment_LM55(parameters);
          } else {
            return payment_LM56(parameters);
          }
        }
      }
    }
  }
}
static
double
stock_level_LM1(work_wait &parameters) {
  double actual_remaining = 
	-0.0223 * parameters.wait_so_far 
	- 56105.7212 * parameters.num_locks_so_far 
	+ 1.0244 * parameters.avg_work_of_same_past_second 
	- 7023499.4069;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
stock_level_LM2(work_wait &parameters) {
  double actual_remaining = 
	-0.0306 * parameters.wait_so_far 
	- 77145.3667 * parameters.num_locks_so_far 
	+ 0.4533 * parameters.avg_work_of_same_past_second 
	+ 6333961.4456;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
stock_level_estimate(work_wait &parameters){

  if (parameters.wait_so_far <= 188226859.5) {
    return stock_level_LM1(parameters);
  } else {
    return stock_level_LM2(parameters);
  }
}
static
double
tpcc_LM1(work_wait &parameters) {
  double actual_remaining = 
	31.733 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 902.9299 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	+ 60757.4053 * parameters.cpu_usage 
	- 0.0071 * parameters.avg_work_of_same_past_second 
	+ 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 5642407.0431;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM2(work_wait &parameters) {
  double actual_remaining = 
	58.7175 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 2213.3433 * parameters.total_wait_locks 
	- 0.0044 * parameters.mean_wait_of_all 
	+ 60757.4053 * parameters.cpu_usage 
	- 0.0263 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0017 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 6856113.3089;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM3(work_wait &parameters) {
  double actual_remaining = 
	273.9583 * parameters.work_so_far 
	- 0.014 * parameters.wait_so_far 
	+ 1151.9101 * parameters.total_wait_locks 
	- 0.0012 * parameters.mean_wait_of_all 
	- 1054408.6283 * parameters.cpu_usage 
	- 0.0234 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0037 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 10248543.8558;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM4(work_wait &parameters) {
  double actual_remaining = 
	273.9583 * parameters.work_so_far 
	- 0.075 * parameters.wait_so_far 
	+ 1151.9101 * parameters.total_wait_locks 
	- 0.0012 * parameters.mean_wait_of_all 
	- 1054408.6283 * parameters.cpu_usage 
	- 0.0234 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	- 0.1584 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 32296594.281;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM5(work_wait &parameters) {
  double actual_remaining = 
	273.9583 * parameters.work_so_far 
	- 0.0897 * parameters.wait_so_far 
	+ 1151.9101 * parameters.total_wait_locks 
	- 0.0012 * parameters.mean_wait_of_all 
	- 1054408.6283 * parameters.cpu_usage 
	- 1.2182 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	- 0.1584 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 49127381.5681;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM6(work_wait &parameters) {
  double actual_remaining = 
	273.9583 * parameters.work_so_far 
	+ 0.0212 * parameters.wait_so_far 
	+ 1151.9101 * parameters.total_wait_locks 
	- 0.0012 * parameters.mean_wait_of_all 
	- 1054408.6283 * parameters.cpu_usage 
	- 0.8996 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	- 0.1584 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 42670798.7801;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM7(work_wait &parameters) {
  double actual_remaining = 
	273.9583 * parameters.work_so_far 
	- 0.0925 * parameters.wait_so_far 
	+ 1151.9101 * parameters.total_wait_locks 
	- 0.0012 * parameters.mean_wait_of_all 
	- 1054408.6283 * parameters.cpu_usage 
	- 0.8996 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	- 0.1584 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 42702073.762;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM8(work_wait &parameters) {
  double actual_remaining = 
	273.9583 * parameters.work_so_far 
	- 0.0469 * parameters.wait_so_far 
	+ 121605.9412 * parameters.total_wait_locks 
	- 0.0012 * parameters.mean_wait_of_all 
	- 1054408.6283 * parameters.cpu_usage 
	- 0.0234 * parameters.avg_work_of_same_past_second 
	- 0.215 * parameters.avg_wait_of_same_past_second 
	- 0.2004 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 24810543.7552;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM9(work_wait &parameters) {
  double actual_remaining = 
	273.9583 * parameters.work_so_far 
	- 0.0304 * parameters.wait_so_far 
	+ 1151.9101 * parameters.total_wait_locks 
	- 0.0012 * parameters.mean_wait_of_all 
	- 1054408.6283 * parameters.cpu_usage 
	- 0.0234 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	- 0.1301 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 20827809.9536;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM10(work_wait &parameters) {
  double actual_remaining = 
	215.7508 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 1151.9101 * parameters.total_wait_locks 
	- 0.0012 * parameters.mean_wait_of_all 
	- 1054408.6283 * parameters.cpu_usage 
	- 0.0234 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0037 * parameters.avg_latency_of_same_last_20 
	+ 0.002 * parameters.max_latency_of_same_last_50 
	+ 6827779.15;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM11(work_wait &parameters) {
  double actual_remaining = 
	722.0917 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 1151.9101 * parameters.total_wait_locks 
	- 0.0012 * parameters.mean_wait_of_all 
	- 1054408.6283 * parameters.cpu_usage 
	- 0.0234 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0037 * parameters.avg_latency_of_same_last_20 
	+ 0.0019 * parameters.max_latency_of_same_last_50 
	+ 4072363.4475;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM12(work_wait &parameters) {
  double actual_remaining = 
	1698.1479 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 22607.484 * parameters.total_wait_locks 
	- 0.0012 * parameters.mean_wait_of_all 
	- 1054408.6283 * parameters.cpu_usage 
	- 0.0234 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0037 * parameters.avg_latency_of_same_last_20 
	+ 0.0019 * parameters.max_latency_of_same_last_50 
	+ 3158323.7909;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM13(work_wait &parameters) {
  double actual_remaining = 
	514.5094 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 1151.9101 * parameters.total_wait_locks 
	- 0.0012 * parameters.mean_wait_of_all 
	- 1054408.6283 * parameters.cpu_usage 
	- 0.0234 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0037 * parameters.avg_latency_of_same_last_20 
	+ 0.0019 * parameters.max_latency_of_same_last_50 
	+ 4658672.6304;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM14(work_wait &parameters) {
  double actual_remaining = 
	167.5263 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 1151.9101 * parameters.total_wait_locks 
	- 0.1287 * parameters.mean_wait_of_all 
	- 1054408.6283 * parameters.cpu_usage 
	- 0.0234 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0059 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 25191248.7559;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM15(work_wait &parameters) {
  double actual_remaining = 
	15273.3966 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 34200.2069 * parameters.total_wait_locks 
	- 0.0012 * parameters.mean_wait_of_all 
	- 1054408.6283 * parameters.cpu_usage 
	- 0.0234 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0059 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 99321087.8853;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM16(work_wait &parameters) {
  double actual_remaining = 
	14610.6179 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 39800.5679 * parameters.total_wait_locks 
	- 0.0012 * parameters.mean_wait_of_all 
	- 1054408.6283 * parameters.cpu_usage 
	- 0.0234 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0059 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 89817425.2715;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM17(work_wait &parameters) {
  double actual_remaining = 
	7862.7395 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 1151.9101 * parameters.total_wait_locks 
	- 0.0012 * parameters.mean_wait_of_all 
	- 1054408.6283 * parameters.cpu_usage 
	- 0.0234 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0059 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 45470639.3171;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM18(work_wait &parameters) {
  double actual_remaining = 
	5773.5545 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 1151.9101 * parameters.total_wait_locks 
	- 0.0012 * parameters.mean_wait_of_all 
	- 1054408.6283 * parameters.cpu_usage 
	- 0.0234 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0059 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 27631131.5259;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM19(work_wait &parameters) {
  double actual_remaining = 
	5773.5545 * parameters.work_so_far 
	- 0.0117 * parameters.wait_so_far 
	+ 1151.9101 * parameters.total_wait_locks 
	- 0.0012 * parameters.mean_wait_of_all 
	- 1054408.6283 * parameters.cpu_usage 
	- 0.0234 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0059 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 20883174.1036;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM20(work_wait &parameters) {
  double actual_remaining = 
	5773.5545 * parameters.work_so_far 
	- 0.0117 * parameters.wait_so_far 
	+ 1151.9101 * parameters.total_wait_locks 
	- 0.0012 * parameters.mean_wait_of_all 
	- 1054408.6283 * parameters.cpu_usage 
	- 0.0234 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0059 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 21566014.6265;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM21(work_wait &parameters) {
  double actual_remaining = 
	167.5263 * parameters.work_so_far 
	- 0.0356 * parameters.wait_so_far 
	+ 68666.5472 * parameters.total_wait_locks 
	- 0.0012 * parameters.mean_wait_of_all 
	- 1054408.6283 * parameters.cpu_usage 
	+ 5.7664 * parameters.avg_work_of_same_past_second 
	- 0.2663 * parameters.avg_wait_of_same_past_second 
	+ 0.0059 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	- 19300148.088;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM22(work_wait &parameters) {
  double actual_remaining = 
	452.6489 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 1151.9101 * parameters.total_wait_locks 
	- 0.0012 * parameters.mean_wait_of_all 
	- 909581.8707 * parameters.cpu_usage 
	- 0.0218 * parameters.avg_work_of_same_past_second 
	+ 0 * parameters.avg_wait_of_same_past_second 
	+ 0.019 * parameters.avg_latency_of_same_last_20 
	- 0.0052 * parameters.max_latency_of_same_last_50 
	+ 8188572.2266;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM23(work_wait &parameters) {
  double actual_remaining = 
	1245.9991 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 44934.4182 * parameters.total_wait_locks 
	- 0.1415 * parameters.mean_wait_of_all 
	+ 17275606.3911 * parameters.cpu_usage 
	+ 0.7743 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.027 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	- 16334451.6066;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM24(work_wait &parameters) {
  double actual_remaining = 
	2509.5502 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 27455.608 * parameters.total_wait_locks 
	- 0.3943 * parameters.mean_wait_of_all 
	+ 161606859.8066 * parameters.cpu_usage 
	+ 0.7743 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.1537 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	- 120237744.8817;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM25(work_wait &parameters) {
  double actual_remaining = 
	1349.6001 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 192454.6057 * parameters.total_wait_locks 
	+ 0.0146 * parameters.mean_wait_of_all 
	- 2090284160.8602 * parameters.cpu_usage 
	+ 2.3115 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.071 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	+ 1994030187.2827;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM26(work_wait &parameters) {
  double actual_remaining = 
	76.2861 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 39128.8659 * parameters.total_wait_locks 
	+ 0.0092 * parameters.mean_wait_of_all 
	+ 24171021.4854 * parameters.cpu_usage 
	- 1.1968 * parameters.avg_work_of_same_past_second 
	- 0.0243 * parameters.avg_wait_of_same_past_second 
	+ 0.001 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	+ 10781736.6144;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM27(work_wait &parameters) {
  double actual_remaining = 
	2074.4397 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 24147.3002 * parameters.total_wait_locks 
	- 0.6366 * parameters.mean_wait_of_all 
	+ 572487225.2858 * parameters.cpu_usage 
	- 0.3644 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.001 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	- 467116676.0792;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM28(work_wait &parameters) {
  double actual_remaining = 
	4047.5447 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 24147.3002 * parameters.total_wait_locks 
	+ 0.0092 * parameters.mean_wait_of_all 
	+ 505744581.9455 * parameters.cpu_usage 
	- 0.3644 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.001 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	- 504719101.173;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM29(work_wait &parameters) {
  double actual_remaining = 
	3616.1382 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 138952.6632 * parameters.total_wait_locks 
	+ 0.0092 * parameters.mean_wait_of_all 
	+ 505744581.9455 * parameters.cpu_usage 
	- 0.3644 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.001 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	- 532708267.9972;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM30(work_wait &parameters) {
  double actual_remaining = 
	-534.2231 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 24147.3002 * parameters.total_wait_locks 
	+ 0.0092 * parameters.mean_wait_of_all 
	+ 192853687.8848 * parameters.cpu_usage 
	- 0.3644 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.001 * parameters.avg_latency_of_same_last_20 
	+ 0.0106 * parameters.max_latency_of_same_last_50 
	- 163339599.8179;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM31(work_wait &parameters) {
  double actual_remaining = 
	-534.2231 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 24147.3002 * parameters.total_wait_locks 
	+ 0.0092 * parameters.mean_wait_of_all 
	+ 192853687.8848 * parameters.cpu_usage 
	- 0.6079 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.001 * parameters.avg_latency_of_same_last_20 
	+ 0.0086 * parameters.max_latency_of_same_last_50 
	- 154484908.9491;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM32(work_wait &parameters) {
  double actual_remaining = 
	-164.3146 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 24147.3002 * parameters.total_wait_locks 
	+ 0.0092 * parameters.mean_wait_of_all 
	+ 192853687.8848 * parameters.cpu_usage 
	- 0.6221 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.001 * parameters.avg_latency_of_same_last_20 
	+ 0.0086 * parameters.max_latency_of_same_last_50 
	- 160488542.7226;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM33(work_wait &parameters) {
  double actual_remaining = 
	-105.908 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 24147.3002 * parameters.total_wait_locks 
	+ 0.0092 * parameters.mean_wait_of_all 
	+ 192853687.8848 * parameters.cpu_usage 
	- 0.6956 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.001 * parameters.avg_latency_of_same_last_20 
	+ 0.0086 * parameters.max_latency_of_same_last_50 
	- 159389593.3178;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM34(work_wait &parameters) {
  double actual_remaining = 
	-839.4777 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 24147.3002 * parameters.total_wait_locks 
	+ 0.0092 * parameters.mean_wait_of_all 
	+ 192853687.8848 * parameters.cpu_usage 
	- 0.3644 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.001 * parameters.avg_latency_of_same_last_20 
	+ 0.0076 * parameters.max_latency_of_same_last_50 
	- 158704058.9842;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM35(work_wait &parameters) {
  double actual_remaining = 
	360.7134 * parameters.work_so_far 
	- 0.0013 * parameters.wait_so_far 
	- 4047.8383 * parameters.total_wait_locks 
	+ 0.0096 * parameters.mean_wait_of_all 
	+ 60757.4053 * parameters.cpu_usage 
	- 0.0334 * parameters.avg_work_of_same_past_second 
	+ 0.0071 * parameters.avg_wait_of_same_past_second 
	+ 0.001 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 2013899.4802;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM36(work_wait &parameters) {
  double actual_remaining = 
	1703.3166 * parameters.work_so_far 
	- 0.0013 * parameters.wait_so_far 
	- 5540.2969 * parameters.total_wait_locks 
	+ 0.0096 * parameters.mean_wait_of_all 
	+ 60757.4053 * parameters.cpu_usage 
	- 0.0334 * parameters.avg_work_of_same_past_second 
	+ 0.0037 * parameters.avg_wait_of_same_past_second 
	+ 0.001 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	- 5871782.2385;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM37(work_wait &parameters) {
  double actual_remaining = 
	340.9786 * parameters.work_so_far 
	- 0.0013 * parameters.wait_so_far 
	- 3548.844 * parameters.total_wait_locks 
	+ 0.0096 * parameters.mean_wait_of_all 
	+ 60757.4053 * parameters.cpu_usage 
	- 0.0334 * parameters.avg_work_of_same_past_second 
	+ 0.0037 * parameters.avg_wait_of_same_past_second 
	+ 0.001 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 4618423.5731;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM38(work_wait &parameters) {
  double actual_remaining = 
	2208.0602 * parameters.work_so_far 
	- 0.0019 * parameters.wait_so_far 
	+ 2578.6511 * parameters.total_wait_locks 
	+ 0.0487 * parameters.mean_wait_of_all 
	+ 60757.4053 * parameters.cpu_usage 
	- 0.0334 * parameters.avg_work_of_same_past_second 
	+ 0.0029 * parameters.avg_wait_of_same_past_second 
	+ 0.001 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	- 29182810.3936;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM39(work_wait &parameters) {
  double actual_remaining = 
	209.9505 * parameters.work_so_far 
	- 0.0127 * parameters.wait_so_far 
	+ 2578.6511 * parameters.total_wait_locks 
	+ 0.043 * parameters.mean_wait_of_all 
	+ 60757.4053 * parameters.cpu_usage 
	+ 1.2325 * parameters.avg_work_of_same_past_second 
	- 0.0587 * parameters.avg_wait_of_same_past_second 
	+ 0.001 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 5803299.1598;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM40(work_wait &parameters) {
  double actual_remaining = 
	209.9505 * parameters.work_so_far 
	- 0.0127 * parameters.wait_so_far 
	+ 2578.6511 * parameters.total_wait_locks 
	+ 0.043 * parameters.mean_wait_of_all 
	+ 60757.4053 * parameters.cpu_usage 
	+ 1.2325 * parameters.avg_work_of_same_past_second 
	- 0.053 * parameters.avg_wait_of_same_past_second 
	+ 0.001 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 3758522.8509;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM41(work_wait &parameters) {
  double actual_remaining = 
	209.9505 * parameters.work_so_far 
	- 0.0127 * parameters.wait_so_far 
	+ 2578.6511 * parameters.total_wait_locks 
	+ 0.043 * parameters.mean_wait_of_all 
	+ 60757.4053 * parameters.cpu_usage 
	+ 1.2325 * parameters.avg_work_of_same_past_second 
	- 0.0264 * parameters.avg_wait_of_same_past_second 
	+ 0.001 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	- 4038193.1149;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM42(work_wait &parameters) {
  double actual_remaining = 
	209.9505 * parameters.work_so_far 
	+ 0.0951 * parameters.wait_so_far 
	+ 2578.6511 * parameters.total_wait_locks 
	+ 0.043 * parameters.mean_wait_of_all 
	+ 60757.4053 * parameters.cpu_usage 
	+ 1.2325 * parameters.avg_work_of_same_past_second 
	+ 0.037 * parameters.avg_wait_of_same_past_second 
	+ 0.001 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	- 21088450.4022;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM43(work_wait &parameters) {
  double actual_remaining = 
	209.9505 * parameters.work_so_far 
	+ 0.1824 * parameters.wait_so_far 
	+ 2578.6511 * parameters.total_wait_locks 
	+ 0.0734 * parameters.mean_wait_of_all 
	+ 60757.4053 * parameters.cpu_usage 
	+ 1.2325 * parameters.avg_work_of_same_past_second 
	+ 0.0253 * parameters.avg_wait_of_same_past_second 
	+ 0.037 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	- 31878123.5886;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM44(work_wait &parameters) {
  double actual_remaining = 
	209.9505 * parameters.work_so_far 
	- 0.018 * parameters.wait_so_far 
	+ 2578.6511 * parameters.total_wait_locks 
	+ 0.043 * parameters.mean_wait_of_all 
	+ 60757.4053 * parameters.cpu_usage 
	+ 0.469 * parameters.avg_work_of_same_past_second 
	+ 0.0029 * parameters.avg_wait_of_same_past_second 
	+ 0.001 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	+ 139411.9545;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM45(work_wait &parameters) {
  double actual_remaining = 
	0.0615 * parameters.work_so_far 
	- 0.0076 * parameters.wait_so_far 
	+ 7553.5856 * parameters.total_wait_locks 
	+ 0.0001 * parameters.mean_wait_of_all 
	+ 60757.4053 * parameters.cpu_usage 
	- 0.1543 * parameters.avg_work_of_same_past_second 
	- 0.0067 * parameters.avg_wait_of_same_past_second 
	+ 0.0096 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 21736946.0627;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM46(work_wait &parameters) {
  double actual_remaining = 
	-0.099 * parameters.work_so_far 
	+ 0.0021 * parameters.wait_so_far 
	- 53016.7666 * parameters.total_wait_locks 
	+ 0.3576 * parameters.mean_wait_of_all 
	+ 60757.4053 * parameters.cpu_usage 
	+ 0.1965 * parameters.avg_work_of_same_past_second 
	- 0.0023 * parameters.avg_wait_of_same_past_second 
	+ 0.0025 * parameters.avg_latency_of_same_last_20 
	+ 0.0006 * parameters.max_latency_of_same_last_50 
	- 5165302.332;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM47(work_wait &parameters) {
  double actual_remaining = 
	-0.099 * parameters.work_so_far 
	+ 0.0021 * parameters.wait_so_far 
	- 53016.7666 * parameters.total_wait_locks 
	+ 0.3576 * parameters.mean_wait_of_all 
	+ 60757.4053 * parameters.cpu_usage 
	+ 0.1965 * parameters.avg_work_of_same_past_second 
	- 0.0058 * parameters.avg_wait_of_same_past_second 
	+ 0.0045 * parameters.avg_latency_of_same_last_20 
	+ 0.0006 * parameters.max_latency_of_same_last_50 
	- 10743382.4487;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM48(work_wait &parameters) {
  double actual_remaining = 
	-1.1347 * parameters.work_so_far 
	+ 0.0977 * parameters.wait_so_far 
	- 83791.4561 * parameters.total_wait_locks 
	+ 0.6627 * parameters.mean_wait_of_all 
	+ 60757.4053 * parameters.cpu_usage 
	- 0.595 * parameters.avg_work_of_same_past_second 
	- 0.0004 * parameters.avg_wait_of_same_past_second 
	- 0.0161 * parameters.avg_latency_of_same_last_20 
	+ 0.0006 * parameters.max_latency_of_same_last_50 
	+ 78646714.5706;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM49(work_wait &parameters) {
  double actual_remaining = 
	-1.1056 * parameters.work_so_far 
	+ 0.0309 * parameters.wait_so_far 
	- 86666.1874 * parameters.total_wait_locks 
	+ 1.6179 * parameters.mean_wait_of_all 
	+ 60757.4053 * parameters.cpu_usage 
	- 0.537 * parameters.avg_work_of_same_past_second 
	- 0.0004 * parameters.avg_wait_of_same_past_second 
	- 0.0161 * parameters.avg_latency_of_same_last_20 
	+ 0.0006 * parameters.max_latency_of_same_last_50 
	- 91322024.642;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM50(work_wait &parameters) {
  double actual_remaining = 
	-1.3509 * parameters.work_so_far 
	+ 0.0307 * parameters.wait_so_far 
	- 184264.3502 * parameters.total_wait_locks 
	+ 0.6627 * parameters.mean_wait_of_all 
	+ 60757.4053 * parameters.cpu_usage 
	+ 1.7417 * parameters.avg_work_of_same_past_second 
	- 0.0004 * parameters.avg_wait_of_same_past_second 
	- 0.0436 * parameters.avg_latency_of_same_last_20 
	+ 0.0006 * parameters.max_latency_of_same_last_50 
	+ 37464142.4289;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM51(work_wait &parameters) {
  double actual_remaining = 
	0.0006 * parameters.work_so_far 
	- 0.0098 * parameters.wait_so_far 
	- 109303.4556 * parameters.total_wait_locks 
	+ 0.7346 * parameters.mean_wait_of_all 
	+ 2019303.8495 * parameters.cpu_usage 
	+ 0.3208 * parameters.avg_work_of_same_past_second 
	- 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.001 * parameters.avg_latency_of_same_last_20 
	+ 0.0001 * parameters.max_latency_of_same_last_50 
	- 33925984.3187;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM52(work_wait &parameters) {
  double actual_remaining = 
	-480.5733 * parameters.work_so_far 
	- 0.0008 * parameters.wait_so_far 
	- 8518.9476 * parameters.total_wait_locks 
	+ 0.0534 * parameters.mean_wait_of_all 
	+ 324053345.5788 * parameters.cpu_usage 
	+ 1.4943 * parameters.avg_work_of_same_past_second 
	- 0.063 * parameters.avg_wait_of_same_past_second 
	+ 0.0023 * parameters.avg_latency_of_same_last_20 
	- 0.0024 * parameters.max_latency_of_same_last_50 
	- 274510130.9009;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM53(work_wait &parameters) {
  double actual_remaining = 
	0.0006 * parameters.work_so_far 
	- 0.0008 * parameters.wait_so_far 
	- 8518.9476 * parameters.total_wait_locks 
	+ 0.0534 * parameters.mean_wait_of_all 
	+ 37652539.9505 * parameters.cpu_usage 
	+ 0.5639 * parameters.avg_work_of_same_past_second 
	- 0.0097 * parameters.avg_wait_of_same_past_second 
	+ 0.2058 * parameters.avg_latency_of_same_last_20 
	- 0.006 * parameters.max_latency_of_same_last_50 
	- 101919870.1834;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM54(work_wait &parameters) {
  double actual_remaining = 
	0.0006 * parameters.work_so_far 
	- 0.0008 * parameters.wait_so_far 
	- 8518.9476 * parameters.total_wait_locks 
	+ 0.0534 * parameters.mean_wait_of_all 
	+ 37652539.9505 * parameters.cpu_usage 
	+ 0.5639 * parameters.avg_work_of_same_past_second 
	- 0.0097 * parameters.avg_wait_of_same_past_second 
	+ 0.1006 * parameters.avg_latency_of_same_last_20 
	- 0.006 * parameters.max_latency_of_same_last_50 
	- 52752376.0835;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM55(work_wait &parameters) {
  double actual_remaining = 
	0.0006 * parameters.work_so_far 
	+ 0.775 * parameters.wait_so_far 
	- 8518.9476 * parameters.total_wait_locks 
	+ 0.0534 * parameters.mean_wait_of_all 
	+ 37652539.9505 * parameters.cpu_usage 
	+ 0.5639 * parameters.avg_work_of_same_past_second 
	- 0.0097 * parameters.avg_wait_of_same_past_second 
	+ 0.0023 * parameters.avg_latency_of_same_last_20 
	- 0.006 * parameters.max_latency_of_same_last_50 
	- 13184539.1897;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM56(work_wait &parameters) {
  double actual_remaining = 
	0.0006 * parameters.work_so_far 
	+ 0.001 * parameters.wait_so_far 
	- 8518.9476 * parameters.total_wait_locks 
	+ 0.0534 * parameters.mean_wait_of_all 
	+ 37652539.9505 * parameters.cpu_usage 
	+ 0.5639 * parameters.avg_work_of_same_past_second 
	- 0.0097 * parameters.avg_wait_of_same_past_second 
	+ 0.0023 * parameters.avg_latency_of_same_last_20 
	- 0.006 * parameters.max_latency_of_same_last_50 
	- 9850973.9897;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM57(work_wait &parameters) {
  double actual_remaining = 
	0.0006 * parameters.work_so_far 
	+ 0.001 * parameters.wait_so_far 
	- 8518.9476 * parameters.total_wait_locks 
	+ 0.0534 * parameters.mean_wait_of_all 
	+ 37652539.9505 * parameters.cpu_usage 
	+ 0.5639 * parameters.avg_work_of_same_past_second 
	- 0.0097 * parameters.avg_wait_of_same_past_second 
	+ 0.0023 * parameters.avg_latency_of_same_last_20 
	- 0.006 * parameters.max_latency_of_same_last_50 
	- 9021442.7258;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM58(work_wait &parameters) {
  double actual_remaining = 
	0.0006 * parameters.work_so_far 
	- 0.013 * parameters.wait_so_far 
	+ 246422.4733 * parameters.total_wait_locks 
	- 0.8991 * parameters.mean_wait_of_all 
	+ 49195999.3037 * parameters.cpu_usage 
	+ 0.1724 * parameters.avg_work_of_same_past_second 
	- 0.0132 * parameters.avg_wait_of_same_past_second 
	+ 0.0179 * parameters.avg_latency_of_same_last_20 
	+ 0.0028 * parameters.max_latency_of_same_last_50 
	- 29227171.1651;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM59(work_wait &parameters) {
  double actual_remaining = 
	0.0006 * parameters.work_so_far 
	- 0.013 * parameters.wait_so_far 
	+ 627231.0848 * parameters.total_wait_locks 
	- 0.7917 * parameters.mean_wait_of_all 
	+ 49195999.3037 * parameters.cpu_usage 
	+ 0.1724 * parameters.avg_work_of_same_past_second 
	- 0.0132 * parameters.avg_wait_of_same_past_second 
	+ 0.0179 * parameters.avg_latency_of_same_last_20 
	+ 0.0028 * parameters.max_latency_of_same_last_50 
	- 234513051.6812;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM60(work_wait &parameters) {
  double actual_remaining = 
	0.0006 * parameters.work_so_far 
	- 0.0262 * parameters.wait_so_far 
	+ 334333.3081 * parameters.total_wait_locks 
	- 1.6429 * parameters.mean_wait_of_all 
	+ 49195999.3037 * parameters.cpu_usage 
	+ 0.1724 * parameters.avg_work_of_same_past_second 
	- 0.0132 * parameters.avg_wait_of_same_past_second 
	+ 0.0488 * parameters.avg_latency_of_same_last_20 
	+ 0.0028 * parameters.max_latency_of_same_last_50 
	+ 22152856.2483;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM61(work_wait &parameters) {
  double actual_remaining = 
	0.0006 * parameters.work_so_far 
	- 0.0037 * parameters.wait_so_far 
	- 8518.9476 * parameters.total_wait_locks 
	+ 0.0534 * parameters.mean_wait_of_all 
	+ 79483301.5048 * parameters.cpu_usage 
	+ 0.1724 * parameters.avg_work_of_same_past_second 
	- 0.0877 * parameters.avg_wait_of_same_past_second 
	+ 0.0023 * parameters.avg_latency_of_same_last_20 
	+ 0.0021 * parameters.max_latency_of_same_last_50 
	- 29826011.4785;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM62(work_wait &parameters) {
  double actual_remaining = 
	0.0006 * parameters.work_so_far 
	- 0.0037 * parameters.wait_so_far 
	- 8518.9476 * parameters.total_wait_locks 
	+ 0.0534 * parameters.mean_wait_of_all 
	+ 111933982.4346 * parameters.cpu_usage 
	+ 0.1724 * parameters.avg_work_of_same_past_second 
	- 0.1674 * parameters.avg_wait_of_same_past_second 
	+ 0.0023 * parameters.avg_latency_of_same_last_20 
	+ 0.0021 * parameters.max_latency_of_same_last_50 
	- 21342497.0091;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM63(work_wait &parameters) {
  double actual_remaining = 
	0.0006 * parameters.work_so_far 
	- 0.0034 * parameters.wait_so_far 
	+ 10892.8669 * parameters.total_wait_locks 
	- 0.0002 * parameters.mean_wait_of_all 
	+ 60757.4053 * parameters.cpu_usage 
	+ 0.0009 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	+ 0.0056 * parameters.max_latency_of_same_last_50 
	+ 7508584.5698;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM64(work_wait &parameters) {
  double actual_remaining = 
	0.0006 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 15808.1118 * parameters.total_wait_locks 
	- 0.1492 * parameters.mean_wait_of_all 
	- 137156340.4392 * parameters.cpu_usage 
	+ 0.0009 * parameters.avg_work_of_same_past_second 
	+ 0.0264 * parameters.avg_wait_of_same_past_second 
	+ 0.0034 * parameters.avg_latency_of_same_last_20 
	- 0.0434 * parameters.max_latency_of_same_last_50 
	+ 189827305.7694;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM65(work_wait &parameters) {
  double actual_remaining = 
	0.0006 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 10174.7698 * parameters.total_wait_locks 
	- 0.1067 * parameters.mean_wait_of_all 
	- 115638290.6272 * parameters.cpu_usage 
	+ 0.0009 * parameters.avg_work_of_same_past_second 
	+ 0.0264 * parameters.avg_wait_of_same_past_second 
	+ 0.0419 * parameters.avg_latency_of_same_last_20 
	- 0.0176 * parameters.max_latency_of_same_last_50 
	+ 142079655.7735;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM66(work_wait &parameters) {
  double actual_remaining = 
	0.0006 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 28451.2226 * parameters.total_wait_locks 
	- 0.0537 * parameters.mean_wait_of_all 
	- 126943969.2493 * parameters.cpu_usage 
	- 1.9754 * parameters.avg_work_of_same_past_second 
	+ 0.9655 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 226051642.1783;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM67(work_wait &parameters) {
  double actual_remaining = 
	0.0006 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 52943.5166 * parameters.total_wait_locks 
	- 0.0537 * parameters.mean_wait_of_all 
	- 126943969.2493 * parameters.cpu_usage 
	- 0.6414 * parameters.avg_work_of_same_past_second 
	+ 0.2437 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 78154421.7999;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM68(work_wait &parameters) {
  double actual_remaining = 
	0.0006 * parameters.work_so_far 
	- 0.0056 * parameters.wait_so_far 
	- 17902.5945 * parameters.total_wait_locks 
	- 0.0033 * parameters.mean_wait_of_all 
	- 2660184.9978 * parameters.cpu_usage 
	- 0.0016 * parameters.avg_work_of_same_past_second 
	+ 0.0008 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 33816946.6752;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM69(work_wait &parameters) {
  double actual_remaining = 
	0.0006 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	- 86979.8902 * parameters.total_wait_locks 
	- 0.0051 * parameters.mean_wait_of_all 
	- 2660184.9978 * parameters.cpu_usage 
	- 1.0989 * parameters.avg_work_of_same_past_second 
	+ 0.101 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0.0088 * parameters.max_latency_of_same_last_50 
	+ 69888697.3673;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM70(work_wait &parameters) {
  double actual_remaining = 
	1.0429 * parameters.work_so_far 
	- 0.0899 * parameters.wait_so_far 
	- 16699.769 * parameters.num_locks_so_far 
	+ 286007.1093 * parameters.total_wait_locks 
	+ 0.0013 * parameters.mean_wait_of_all 
	- 189745495.2088 * parameters.cpu_usage 
	+ 0.0054 * parameters.avg_work_of_same_past_second 
	- 0.0021 * parameters.avg_wait_of_same_past_second 
	+ 0.5089 * parameters.avg_latency_of_same_last_20 
	- 0.022 * parameters.max_latency_of_same_last_50 
	+ 201951944.1426;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM71(work_wait &parameters) {
  double actual_remaining = 
	661.4221 * parameters.work_so_far 
	- 0.2441 * parameters.wait_so_far 
	- 24785.3685 * parameters.num_locks_so_far 
	+ 206443.0511 * parameters.total_wait_locks 
	+ 0.1715 * parameters.mean_wait_of_all 
	+ 69168.1505 * parameters.cpu_usage 
	+ 0.4812 * parameters.avg_work_of_same_past_second 
	- 0.1819 * parameters.avg_wait_of_same_past_second 
	+ 0.0019 * parameters.avg_latency_of_same_last_20 
	- 0.0213 * parameters.max_latency_of_same_last_50 
	+ 94178674.1608;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM72(work_wait &parameters) {
  double actual_remaining = 
	0.0214 * parameters.work_so_far 
	- 0.0081 * parameters.wait_so_far 
	- 2965688.8794 * parameters.num_locks_so_far 
	+ 342820.3033 * parameters.total_wait_locks 
	+ 0.0028 * parameters.mean_wait_of_all 
	+ 69168.1505 * parameters.cpu_usage 
	+ 0.0234 * parameters.avg_work_of_same_past_second 
	- 0.3566 * parameters.avg_wait_of_same_past_second 
	+ 0.0057 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 202322815.9398;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM73(work_wait &parameters) {
  double actual_remaining = 
	0.0214 * parameters.work_so_far 
	- 0.0074 * parameters.wait_so_far 
	- 84462.9154 * parameters.num_locks_so_far 
	+ 6577.3504 * parameters.total_wait_locks 
	+ 0.0028 * parameters.mean_wait_of_all 
	+ 69168.1505 * parameters.cpu_usage 
	+ 0.0214 * parameters.avg_work_of_same_past_second 
	- 0.0078 * parameters.avg_wait_of_same_past_second 
	+ 0.1285 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 241470658.4054;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM74(work_wait &parameters) {
  double actual_remaining = 
	0.003 * parameters.work_so_far 
	- 0.0051 * parameters.wait_so_far 
	- 30428.7944 * parameters.num_locks_so_far 
	+ 197816.7827 * parameters.total_wait_locks 
	+ 0.0013 * parameters.mean_wait_of_all 
	+ 69168.1505 * parameters.cpu_usage 
	+ 0.415 * parameters.avg_work_of_same_past_second 
	- 0.2421 * parameters.avg_wait_of_same_past_second 
	+ 0.0036 * parameters.avg_latency_of_same_last_20 
	- 0.0002 * parameters.max_latency_of_same_last_50 
	+ 78505471.6523;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM75(work_wait &parameters) {
  double actual_remaining = 
	0.003 * parameters.work_so_far 
	- 0.0501 * parameters.wait_so_far 
	- 30428.7944 * parameters.num_locks_so_far 
	+ 3670.4602 * parameters.total_wait_locks 
	+ 0.2389 * parameters.mean_wait_of_all 
	+ 69168.1505 * parameters.cpu_usage 
	+ 0.0175 * parameters.avg_work_of_same_past_second 
	- 0.0096 * parameters.avg_wait_of_same_past_second 
	+ 0.0036 * parameters.avg_latency_of_same_last_20 
	- 0.0009 * parameters.max_latency_of_same_last_50 
	+ 97002323.6955;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM76(work_wait &parameters) {
  double actual_remaining = 
	0.003 * parameters.work_so_far 
	- 0.0056 * parameters.wait_so_far 
	+ 9635164.9451 * parameters.num_locks_so_far 
	+ 47708.4098 * parameters.total_wait_locks 
	+ 0.0069 * parameters.mean_wait_of_all 
	+ 69168.1505 * parameters.cpu_usage 
	+ 0.017 * parameters.avg_work_of_same_past_second 
	- 0.0439 * parameters.avg_wait_of_same_past_second 
	+ 0.0036 * parameters.avg_latency_of_same_last_20 
	- 0.0164 * parameters.max_latency_of_same_last_50 
	+ 58100391.9976;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM77(work_wait &parameters) {
  double actual_remaining = 
	0.003 * parameters.work_so_far 
	- 0.0444 * parameters.wait_so_far 
	+ 6244994.0067 * parameters.num_locks_so_far 
	+ 190222.1789 * parameters.total_wait_locks 
	- 0.4991 * parameters.mean_wait_of_all 
	+ 69168.1505 * parameters.cpu_usage 
	+ 0.017 * parameters.avg_work_of_same_past_second 
	- 0.1849 * parameters.avg_wait_of_same_past_second 
	+ 0.0036 * parameters.avg_latency_of_same_last_20 
	- 0.012 * parameters.max_latency_of_same_last_50 
	+ 180908810.8009;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM78(work_wait &parameters) {
  double actual_remaining = 
	0.003 * parameters.work_so_far 
	- 0.0194 * parameters.wait_so_far 
	+ 6244994.0067 * parameters.num_locks_so_far 
	+ 88266.2334 * parameters.total_wait_locks 
	- 0.1725 * parameters.mean_wait_of_all 
	+ 69168.1505 * parameters.cpu_usage 
	+ 0.017 * parameters.avg_work_of_same_past_second 
	- 0.3095 * parameters.avg_wait_of_same_past_second 
	+ 0.0036 * parameters.avg_latency_of_same_last_20 
	- 0.012 * parameters.max_latency_of_same_last_50 
	+ 140737262.044;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM79(work_wait &parameters) {
  double actual_remaining = 
	0.003 * parameters.work_so_far 
	- 0.3203 * parameters.wait_so_far 
	- 30428.7944 * parameters.num_locks_so_far 
	- 3617.9735 * parameters.total_wait_locks 
	+ 0.2294 * parameters.mean_wait_of_all 
	+ 69168.1505 * parameters.cpu_usage 
	+ 0.017 * parameters.avg_work_of_same_past_second 
	- 0.0092 * parameters.avg_wait_of_same_past_second 
	+ 0.0036 * parameters.avg_latency_of_same_last_20 
	- 0.0043 * parameters.max_latency_of_same_last_50 
	+ 239549103.4024;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM80(work_wait &parameters) {
  double actual_remaining = 
	0.003 * parameters.work_so_far 
	+ 1.4943 * parameters.wait_so_far 
	- 30428.7944 * parameters.num_locks_so_far 
	- 21875.8681 * parameters.total_wait_locks 
	+ 0.0069 * parameters.mean_wait_of_all 
	+ 69168.1505 * parameters.cpu_usage 
	+ 0.017 * parameters.avg_work_of_same_past_second 
	- 0.0092 * parameters.avg_wait_of_same_past_second 
	+ 0.0036 * parameters.avg_latency_of_same_last_20 
	- 0.0093 * parameters.max_latency_of_same_last_50 
	- 647234272.6563;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM81(work_wait &parameters) {
  double actual_remaining = 
	2121.648 * parameters.work_so_far 
	- 0.386 * parameters.wait_so_far 
	- 30428.7944 * parameters.num_locks_so_far 
	- 21875.8681 * parameters.total_wait_locks 
	+ 0.0069 * parameters.mean_wait_of_all 
	- 517128251.8144 * parameters.cpu_usage 
	+ 0.017 * parameters.avg_work_of_same_past_second 
	- 0.0092 * parameters.avg_wait_of_same_past_second 
	+ 0.0036 * parameters.avg_latency_of_same_last_20 
	- 0.0093 * parameters.max_latency_of_same_last_50 
	+ 853819988.4935;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM82(work_wait &parameters) {
  double actual_remaining = 
	0.003 * parameters.work_so_far 
	- 0.0515 * parameters.wait_so_far 
	- 30428.7944 * parameters.num_locks_so_far 
	- 21875.8681 * parameters.total_wait_locks 
	+ 0.0069 * parameters.mean_wait_of_all 
	- 785137625.5892 * parameters.cpu_usage 
	+ 0.017 * parameters.avg_work_of_same_past_second 
	+ 0.4943 * parameters.avg_wait_of_same_past_second 
	+ 0.191 * parameters.avg_latency_of_same_last_20 
	- 0.0272 * parameters.max_latency_of_same_last_50 
	+ 778088873.7785;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM83(work_wait &parameters) {
  double actual_remaining = 
	0.003 * parameters.work_so_far 
	- 0.0515 * parameters.wait_so_far 
	- 30428.7944 * parameters.num_locks_so_far 
	- 21875.8681 * parameters.total_wait_locks 
	+ 0.0069 * parameters.mean_wait_of_all 
	- 249340646.3385 * parameters.cpu_usage 
	+ 0.017 * parameters.avg_work_of_same_past_second 
	+ 0.1883 * parameters.avg_wait_of_same_past_second 
	+ 0.1116 * parameters.avg_latency_of_same_last_20 
	- 0.0463 * parameters.max_latency_of_same_last_50 
	+ 346516337.3224;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM84(work_wait &parameters) {
  double actual_remaining = 
	0.003 * parameters.work_so_far 
	- 0.0828 * parameters.wait_so_far 
	- 62021.3614 * parameters.num_locks_so_far 
	+ 3994.7478 * parameters.total_wait_locks 
	+ 0.0013 * parameters.mean_wait_of_all 
	+ 312559331.1778 * parameters.cpu_usage 
	+ 0.7871 * parameters.avg_work_of_same_past_second 
	- 0.3272 * parameters.avg_wait_of_same_past_second 
	+ 0.1807 * parameters.avg_latency_of_same_last_20 
	- 0.0006 * parameters.max_latency_of_same_last_50 
	- 250455240.6633;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM85(work_wait &parameters) {
  double actual_remaining = 
	30.5916 * parameters.work_so_far 
	- 0.002 * parameters.wait_so_far 
	+ 9839607.9271 * parameters.num_locks_so_far 
	- 149764.6432 * parameters.total_wait_locks 
	+ 1.2028 * parameters.mean_wait_of_all 
	- 25538838.7277 * parameters.cpu_usage 
	- 0.0264 * parameters.avg_work_of_same_past_second 
	- 0.0017 * parameters.avg_wait_of_same_past_second 
	+ 0.1563 * parameters.avg_latency_of_same_last_20 
	- 0.0029 * parameters.max_latency_of_same_last_50 
	+ 78298099.2421;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM86(work_wait &parameters) {
  double actual_remaining = 
	30.5916 * parameters.work_so_far 
	- 0.002 * parameters.wait_so_far 
	+ 287726529.3058 * parameters.num_locks_so_far 
	- 197635.9294 * parameters.total_wait_locks 
	- 3.2842 * parameters.mean_wait_of_all 
	- 38074603.8484 * parameters.cpu_usage 
	- 0.0625 * parameters.avg_work_of_same_past_second 
	- 0.0017 * parameters.avg_wait_of_same_past_second 
	+ 0.2667 * parameters.avg_latency_of_same_last_20 
	- 0.0008 * parameters.max_latency_of_same_last_50 
	- 276744285.2277;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM87(work_wait &parameters) {
  double actual_remaining = 
	30.5916 * parameters.work_so_far 
	- 0.002 * parameters.wait_so_far 
	+ 6095365.9258 * parameters.num_locks_so_far 
	- 2737316.3004 * parameters.total_wait_locks 
	+ 21.9814 * parameters.mean_wait_of_all 
	- 18212245.3436 * parameters.cpu_usage 
	- 0.028 * parameters.avg_work_of_same_past_second 
	- 0.0017 * parameters.avg_wait_of_same_past_second 
	+ 0.1441 * parameters.avg_latency_of_same_last_20 
	- 0.0008 * parameters.max_latency_of_same_last_50 
	- 1557398815.6362;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM88(work_wait &parameters) {
  double actual_remaining = 
	2505.2216 * parameters.work_so_far 
	- 0.002 * parameters.wait_so_far 
	- 11470919.2938 * parameters.num_locks_so_far 
	- 1043756.4441 * parameters.total_wait_locks 
	+ 7.34 * parameters.mean_wait_of_all 
	+ 461403486.4462 * parameters.cpu_usage 
	- 0.0753 * parameters.avg_work_of_same_past_second 
	- 3.8243 * parameters.avg_wait_of_same_past_second 
	+ 0.005 * parameters.avg_latency_of_same_last_20 
	+ 498008793.5928;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM89(work_wait &parameters) {
  double actual_remaining = 
	2505.2216 * parameters.work_so_far 
	- 0.002 * parameters.wait_so_far 
	- 11470919.2938 * parameters.num_locks_so_far 
	- 1043756.4441 * parameters.total_wait_locks 
	+ 7.34 * parameters.mean_wait_of_all 
	+ 851333053.2675 * parameters.cpu_usage 
	- 0.0753 * parameters.avg_work_of_same_past_second 
	- 0.2449 * parameters.avg_wait_of_same_past_second 
	+ 0.005 * parameters.avg_latency_of_same_last_20 
	- 683305586.4675;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM90(work_wait &parameters) {
  double actual_remaining = 
	5087.7131 * parameters.work_so_far 
	- 0.002 * parameters.wait_so_far 
	- 11470919.2938 * parameters.num_locks_so_far 
	- 2343172.8145 * parameters.total_wait_locks 
	+ 22.6948 * parameters.mean_wait_of_all 
	- 233637964.1097 * parameters.cpu_usage 
	+ 0.9658 * parameters.avg_work_of_same_past_second 
	- 1.4457 * parameters.avg_wait_of_same_past_second 
	- 0.0958 * parameters.avg_latency_of_same_last_20 
	+ 0.0524 * parameters.max_latency_of_same_last_50 
	- 1560068179.8499;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM91(work_wait &parameters) {
  double actual_remaining = 
	5850.3238 * parameters.work_so_far 
	- 0.002 * parameters.wait_so_far 
	- 11470919.2938 * parameters.num_locks_so_far 
	- 2715234.5095 * parameters.total_wait_locks 
	+ 27.056 * parameters.mean_wait_of_all 
	- 297156883.5715 * parameters.cpu_usage 
	+ 1.2498 * parameters.avg_work_of_same_past_second 
	- 1.7802 * parameters.avg_wait_of_same_past_second 
	- 0.1233 * parameters.avg_latency_of_same_last_20 
	+ 0.0667 * parameters.max_latency_of_same_last_50 
	- 1854647757.0475;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM92(work_wait &parameters) {
  double actual_remaining = 
	217.35 * parameters.work_so_far 
	- 0.002 * parameters.wait_so_far 
	- 12469148.1657 * parameters.num_locks_so_far 
	- 355563.6926 * parameters.total_wait_locks 
	+ 1.683 * parameters.mean_wait_of_all 
	- 735259.4161 * parameters.cpu_usage 
	- 0.1227 * parameters.avg_work_of_same_past_second 
	+ 0.0487 * parameters.avg_wait_of_same_past_second 
	+ 0.005 * parameters.avg_latency_of_same_last_20 
	+ 362394214.9654;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM93(work_wait &parameters) {
  double actual_remaining = 
	217.35 * parameters.work_so_far 
	- 0.002 * parameters.wait_so_far 
	- 13589621.4881 * parameters.num_locks_so_far 
	- 378791.5376 * parameters.total_wait_locks 
	+ 1.8135 * parameters.mean_wait_of_all 
	- 735259.4161 * parameters.cpu_usage 
	- 0.1354 * parameters.avg_work_of_same_past_second 
	+ 0.0557 * parameters.avg_wait_of_same_past_second 
	+ 0.005 * parameters.avg_latency_of_same_last_20 
	+ 274918557.5104;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM94(work_wait &parameters) {
  double actual_remaining = 
	1.6592 * parameters.work_so_far 
	- 0.3197 * parameters.wait_so_far 
	- 69428.3777 * parameters.num_locks_so_far 
	- 402005.8933 * parameters.total_wait_locks 
	+ 3.1045 * parameters.mean_wait_of_all 
	- 735259.4161 * parameters.cpu_usage 
	- 0.4904 * parameters.avg_work_of_same_past_second 
	- 0.0017 * parameters.avg_wait_of_same_past_second 
	+ 0.2266 * parameters.avg_latency_of_same_last_20 
	+ 0.0353 * parameters.max_latency_of_same_last_50 
	+ 108616339.1255;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM95(work_wait &parameters) {
  double actual_remaining = 
	2.1789 * parameters.work_so_far 
	- 0.139 * parameters.wait_so_far 
	- 11838598.8695 * parameters.num_locks_so_far 
	- 257426.4919 * parameters.total_wait_locks 
	+ 1.9494 * parameters.mean_wait_of_all 
	- 3300571.2845 * parameters.cpu_usage 
	+ 0.0001 * parameters.avg_work_of_same_past_second 
	- 0.0064 * parameters.avg_wait_of_same_past_second 
	+ 0.2004 * parameters.avg_latency_of_same_last_20 
	+ 77603066.4478;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM96(work_wait &parameters) {
  double actual_remaining = 
	-1.3857 * parameters.work_so_far 
	- 0.0731 * parameters.wait_so_far 
	- 369375.9027 * parameters.num_locks_so_far 
	- 3855604.1795 * parameters.total_wait_locks 
	+ 29.1429 * parameters.mean_wait_of_all 
	+ 140952601.0404 * parameters.cpu_usage 
	- 0.262 * parameters.avg_work_of_same_past_second 
	+ 0.2085 * parameters.avg_wait_of_same_past_second 
	+ 0.0094 * parameters.avg_latency_of_same_last_20 
	- 0.0011 * parameters.max_latency_of_same_last_50 
	- 1812335740.0474;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM97(work_wait &parameters) {
  double actual_remaining = 
	-1.3857 * parameters.work_so_far 
	- 0.0731 * parameters.wait_so_far 
	- 369375.9027 * parameters.num_locks_so_far 
	- 2610098.5046 * parameters.total_wait_locks 
	+ 21.3687 * parameters.mean_wait_of_all 
	+ 140952601.0404 * parameters.cpu_usage 
	- 0.262 * parameters.avg_work_of_same_past_second 
	+ 0.2085 * parameters.avg_wait_of_same_past_second 
	+ 0.0094 * parameters.avg_latency_of_same_last_20 
	- 0.0011 * parameters.max_latency_of_same_last_50 
	- 1448392651.9011;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM98(work_wait &parameters) {
  double actual_remaining = 
	-2.9509 * parameters.work_so_far 
	- 0.1305 * parameters.wait_so_far 
	- 369375.9027 * parameters.num_locks_so_far 
	- 10661780.5132 * parameters.total_wait_locks 
	+ 107.8268 * parameters.mean_wait_of_all 
	+ 140952601.0404 * parameters.cpu_usage 
	- 0.262 * parameters.avg_work_of_same_past_second 
	+ 0.2085 * parameters.avg_wait_of_same_past_second 
	- 0.7203 * parameters.avg_latency_of_same_last_20 
	- 0.0011 * parameters.max_latency_of_same_last_50 
	- 9249990546.8468;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM99(work_wait &parameters) {
  double actual_remaining = 
	0.0146 * parameters.work_so_far 
	- 0.0217 * parameters.wait_so_far 
	- 369375.9027 * parameters.num_locks_so_far 
	- 1040945.2269 * parameters.total_wait_locks 
	+ 9.1637 * parameters.mean_wait_of_all 
	+ 147402673.8137 * parameters.cpu_usage 
	- 0.262 * parameters.avg_work_of_same_past_second 
	+ 0.2085 * parameters.avg_wait_of_same_past_second 
	+ 0.0094 * parameters.avg_latency_of_same_last_20 
	- 0.0011 * parameters.max_latency_of_same_last_50 
	- 529523843.0154;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM100(work_wait &parameters) {
  double actual_remaining = 
	0.0146 * parameters.work_so_far 
	- 0.1689 * parameters.wait_so_far 
	- 369375.9027 * parameters.num_locks_so_far 
	- 1434128.4041 * parameters.total_wait_locks 
	+ 11.6797 * parameters.mean_wait_of_all 
	- 48249533.6422 * parameters.cpu_usage 
	- 1.5662 * parameters.avg_work_of_same_past_second 
	+ 0.1137 * parameters.avg_wait_of_same_past_second 
	+ 0.0094 * parameters.avg_latency_of_same_last_20 
	- 0.1462 * parameters.max_latency_of_same_last_50 
	+ 82696447.2439;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM101(work_wait &parameters) {
  double actual_remaining = 
	0.0146 * parameters.work_so_far 
	- 0.0821 * parameters.wait_so_far 
	- 369375.9027 * parameters.num_locks_so_far 
	- 1434128.4041 * parameters.total_wait_locks 
	+ 11.6797 * parameters.mean_wait_of_all 
	- 48249533.6422 * parameters.cpu_usage 
	- 1.4301 * parameters.avg_work_of_same_past_second 
	+ 0.2071 * parameters.avg_wait_of_same_past_second 
	+ 0.0094 * parameters.avg_latency_of_same_last_20 
	- 0.2225 * parameters.max_latency_of_same_last_50 
	+ 10455326.3044;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM102(work_wait &parameters) {
  double actual_remaining = 
	-3.9764 * parameters.work_so_far 
	- 0.0082 * parameters.wait_so_far 
	- 244115.1954 * parameters.num_locks_so_far 
	+ 840515.383 * parameters.total_wait_locks 
	- 5.2943 * parameters.mean_wait_of_all 
	- 27730180.069 * parameters.cpu_usage 
	- 0.0171 * parameters.avg_work_of_same_past_second 
	- 0.0212 * parameters.avg_wait_of_same_past_second 
	+ 0.1777 * parameters.avg_latency_of_same_last_20 
	- 0.06 * parameters.max_latency_of_same_last_50 
	+ 615194454.1701;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM103(work_wait &parameters) {
  double actual_remaining = 
	0.0146 * parameters.work_so_far 
	- 0.023 * parameters.wait_so_far 
	- 236979.8492 * parameters.num_locks_so_far 
	+ 129054.118 * parameters.total_wait_locks 
	- 0.4581 * parameters.mean_wait_of_all 
	- 43383055.6907 * parameters.cpu_usage 
	+ 0.1587 * parameters.avg_work_of_same_past_second 
	- 0.1872 * parameters.avg_wait_of_same_past_second 
	+ 0.0129 * parameters.avg_latency_of_same_last_20 
	- 0.0024 * parameters.max_latency_of_same_last_50 
	+ 291913477.6606;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM104(work_wait &parameters) {
  double actual_remaining = 
	0.0146 * parameters.work_so_far 
	- 0.023 * parameters.wait_so_far 
	- 236979.8492 * parameters.num_locks_so_far 
	- 9130569.1288 * parameters.total_wait_locks 
	+ 52.6946 * parameters.mean_wait_of_all 
	- 205417694.7907 * parameters.cpu_usage 
	+ 0.583 * parameters.avg_work_of_same_past_second 
	- 0.8495 * parameters.avg_wait_of_same_past_second 
	+ 0.0129 * parameters.avg_latency_of_same_last_20 
	- 0.0024 * parameters.max_latency_of_same_last_50 
	- 1640572482.6375;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM105(work_wait &parameters) {
  double actual_remaining = 
	0.0146 * parameters.work_so_far 
	- 0.023 * parameters.wait_so_far 
	- 236979.8492 * parameters.num_locks_so_far 
	+ 129054.118 * parameters.total_wait_locks 
	- 0.4535 * parameters.mean_wait_of_all 
	- 150490698.4856 * parameters.cpu_usage 
	+ 0.4396 * parameters.avg_work_of_same_past_second 
	- 0.6254 * parameters.avg_wait_of_same_past_second 
	+ 0.0129 * parameters.avg_latency_of_same_last_20 
	- 0.0024 * parameters.max_latency_of_same_last_50 
	+ 481000433.7729;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM106(work_wait &parameters) {
  double actual_remaining = 
	0.0146 * parameters.work_so_far 
	- 0.0223 * parameters.wait_so_far 
	- 236979.8492 * parameters.num_locks_so_far 
	+ 122382.5558 * parameters.total_wait_locks 
	- 0.7898 * parameters.mean_wait_of_all 
	- 273519047.0999 * parameters.cpu_usage 
	+ 0.0518 * parameters.avg_work_of_same_past_second 
	- 0.0834 * parameters.avg_wait_of_same_past_second 
	+ 0.0129 * parameters.avg_latency_of_same_last_20 
	- 0.0024 * parameters.max_latency_of_same_last_50 
	+ 478623309.5724;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
tpcc_estimate(work_wait &parameters){

  if (parameters.num_locks_so_far <= 3) {

    if (parameters.total_wait_locks <= 412.5) {

      if (parameters.work_so_far <= 17608.5) {

        if (parameters.work_so_far <= 7645) {
          return tpcc_LM1(parameters);
        } else {

          if (parameters.avg_wait_of_same_past_second <= 116018000) {

            if (parameters.total_wait_locks <= 61.5) {
              return tpcc_LM2(parameters);
            } else {

              if (parameters.avg_work_of_same_past_second <= 9809510) {

                if (parameters.avg_latency_of_same_last_20 <= 92056350) {

                  if (parameters.mean_wait_of_all <= 77257500) {

                    if (parameters.total_wait_locks <= 74.5) {
                      return tpcc_LM3(parameters);
                    } else {

                      if (parameters.total_wait_locks <= 134.5) {

                        if (parameters.max_latency_of_same_last_50 <= 223859000) {

                          if (parameters.avg_work_of_same_past_second <= 5746395) {
                            return tpcc_LM4(parameters);
                          } else {

                            if (parameters.avg_work_of_same_past_second <= 6624820) {
                              return tpcc_LM5(parameters);
                            } else {

                              if (parameters.wait_so_far <= 36958722) {
                                return tpcc_LM6(parameters);
                              } else {
                                return tpcc_LM7(parameters);
                              }
                            }
                          }
                        } else {
                          return tpcc_LM8(parameters);
                        }
                      } else {
                        return tpcc_LM9(parameters);
                      }
                    }
                  } else {

                    if (parameters.max_latency_of_same_last_50 <= 222646000) {
                      return tpcc_LM10(parameters);
                    } else {

                      if (parameters.avg_latency_of_same_last_20 <= 73609400) {

                        if (parameters.mean_wait_of_all <= 87564300) {
                          return tpcc_LM11(parameters);
                        } else {
                          return tpcc_LM12(parameters);
                        }
                      } else {
                        return tpcc_LM13(parameters);
                      }
                    }
                  }
                } else {

                  if (parameters.wait_so_far <= 64182226.5) {
                    return tpcc_LM14(parameters);
                  } else {

                    if (parameters.work_so_far <= 10643) {

                      if (parameters.wait_so_far <= 140282867) {

                        if (parameters.work_so_far <= 8908) {
                          return tpcc_LM15(parameters);
                        } else {
                          return tpcc_LM16(parameters);
                        }
                      } else {

                        if (parameters.cpu_usage <= 0.927) {

                          if (parameters.work_so_far <= 9132.5) {
                            return tpcc_LM17(parameters);
                          } else {
                            return tpcc_LM18(parameters);
                          }
                        } else {

                          if (parameters.wait_so_far <= 350207169.5) {
                            return tpcc_LM19(parameters);
                          } else {
                            return tpcc_LM20(parameters);
                          }
                        }
                      }
                    } else {
                      return tpcc_LM21(parameters);
                    }
                  }
                }
              } else {
                return tpcc_LM22(parameters);
              }
            }
          } else {

            if (parameters.cpu_usage <= 0.99) {

              if (parameters.avg_work_of_same_past_second <= 15913600) {

                if (parameters.avg_work_of_same_past_second <= 15224150) {

                  if (parameters.total_wait_locks <= 97.5) {
                    return tpcc_LM23(parameters);
                  } else {
                    return tpcc_LM24(parameters);
                  }
                } else {
                  return tpcc_LM25(parameters);
                }
              } else {

                if (parameters.total_wait_locks <= 296) {
                  return tpcc_LM26(parameters);
                } else {

                  if (parameters.wait_so_far <= 83041315) {

                    if (parameters.cpu_usage <= 0.964) {
                      return tpcc_LM27(parameters);
                    } else {

                      if (parameters.work_so_far <= 11528.5) {
                        return tpcc_LM28(parameters);
                      } else {
                        return tpcc_LM29(parameters);
                      }
                    }
                  } else {

                    if (parameters.work_so_far <= 16228) {

                      if (parameters.max_latency_of_same_last_50 <= 549463500) {
                        return tpcc_LM30(parameters);
                      } else {

                        if (parameters.work_so_far <= 12237) {
                          return tpcc_LM31(parameters);
                        } else {

                          if (parameters.work_so_far <= 15762.5) {
                            return tpcc_LM32(parameters);
                          } else {
                            return tpcc_LM33(parameters);
                          }
                        }
                      }
                    } else {
                      return tpcc_LM34(parameters);
                    }
                  }
                }
              }
            } else {

              if (parameters.work_so_far <= 14750) {

                if (parameters.avg_wait_of_same_past_second <= 182434000) {
                  return tpcc_LM35(parameters);
                } else {

                  if (parameters.total_wait_locks <= 109.5) {
                    return tpcc_LM36(parameters);
                  } else {
                    return tpcc_LM37(parameters);
                  }
                }
              } else {

                if (parameters.mean_wait_of_all <= 96884850) {
                  return tpcc_LM38(parameters);
                } else {

                  if (parameters.wait_so_far <= 127908843) {

                    if (parameters.avg_work_of_same_past_second <= 20285500) {

                      if (parameters.avg_wait_of_same_past_second <= 262302500) {

                        if (parameters.avg_wait_of_same_past_second <= 196395500) {
                          return tpcc_LM39(parameters);
                        } else {
                          return tpcc_LM40(parameters);
                        }
                      } else {
                        return tpcc_LM41(parameters);
                      }
                    } else {

                      if (parameters.avg_wait_of_same_past_second <= 157839500) {
                        return tpcc_LM42(parameters);
                      } else {
                        return tpcc_LM43(parameters);
                      }
                    }
                  } else {
                    return tpcc_LM44(parameters);
                  }
                }
              }
            }
          }
        }
      } else {
        return tpcc_LM45(parameters);
      }
    } else {

      if (parameters.avg_wait_of_same_past_second <= 468529000) {

        if (parameters.cpu_usage <= 0.94) {

          if (parameters.avg_work_of_same_past_second <= 20071300) {

            if (parameters.mean_wait_of_all <= 173500500) {
              return tpcc_LM46(parameters);
            } else {
              return tpcc_LM47(parameters);
            }
          } else {

            if (parameters.total_wait_locks <= 646.5) {

              if (parameters.avg_work_of_same_past_second <= 23324700) {
                return tpcc_LM48(parameters);
              } else {
                return tpcc_LM49(parameters);
              }
            } else {
              return tpcc_LM50(parameters);
            }
          }
        } else {

          if (parameters.avg_latency_of_same_last_20 <= 475217000) {
            return tpcc_LM51(parameters);
          } else {

            if (parameters.avg_wait_of_same_past_second <= 446219000) {

              if (parameters.work_so_far <= 67074) {
                return tpcc_LM52(parameters);
              } else {

                if (parameters.max_latency_of_same_last_50 <= 1240360000) {

                  if (parameters.work_so_far <= 347970) {
                    return tpcc_LM53(parameters);
                  } else {
                    return tpcc_LM54(parameters);
                  }
                } else {

                  if (parameters.wait_so_far <= 14372713.5) {
                    return tpcc_LM55(parameters);
                  } else {

                    if (parameters.wait_so_far <= 399188674.5) {
                      return tpcc_LM56(parameters);
                    } else {
                      return tpcc_LM57(parameters);
                    }
                  }
                }
              }
            } else {

              if (parameters.total_wait_locks <= 517.5) {

                if (parameters.max_latency_of_same_last_50 <= 1597380000) {

                  if (parameters.mean_wait_of_all <= 144375500) {
                    return tpcc_LM58(parameters);
                  } else {
                    return tpcc_LM59(parameters);
                  }
                } else {
                  return tpcc_LM60(parameters);
                }
              } else {

                if (parameters.cpu_usage <= 0.98) {
                  return tpcc_LM61(parameters);
                } else {
                  return tpcc_LM62(parameters);
                }
              }
            }
          }
        }
      } else {

        if (parameters.cpu_usage <= 0.979) {
          return tpcc_LM63(parameters);
        } else {

          if (parameters.avg_wait_of_same_past_second <= 518082500) {

            if (parameters.avg_work_of_same_past_second <= 25537650) {

              if (parameters.max_latency_of_same_last_50 <= 988806000) {
                return tpcc_LM64(parameters);
              } else {
                return tpcc_LM65(parameters);
              }
            } else {

              if (parameters.total_wait_locks <= 533.5) {
                return tpcc_LM66(parameters);
              } else {
                return tpcc_LM67(parameters);
              }
            }
          } else {

            if (parameters.total_wait_locks <= 642.5) {
              return tpcc_LM68(parameters);
            } else {
              return tpcc_LM69(parameters);
            }
          }
        }
      }
    }
  } else {

    if (parameters.total_wait_locks <= 421.5) {

      if (parameters.avg_latency_of_same_last_20 <= 215079500) {
        return tpcc_LM70(parameters);
      } else {

        if (parameters.wait_so_far <= 196179902.5) {

          if (parameters.work_so_far <= 77178.5) {
            return tpcc_LM71(parameters);
          } else {

            if (parameters.avg_work_of_same_past_second <= 160460000) {
              return tpcc_LM72(parameters);
            } else {
              return tpcc_LM73(parameters);
            }
          }
        } else {

          if (parameters.avg_latency_of_same_last_20 <= 486055000) {

            if (parameters.wait_so_far <= 322162297) {
              return tpcc_LM74(parameters);
            } else {

              if (parameters.work_so_far <= 54140) {
                return tpcc_LM75(parameters);
              } else {

                if (parameters.avg_work_of_same_past_second <= 143693500) {

                  if (parameters.total_wait_locks <= 250.5) {
                    return tpcc_LM76(parameters);
                  } else {

                    if (parameters.max_latency_of_same_last_50 <= 825215000) {
                      return tpcc_LM77(parameters);
                    } else {
                      return tpcc_LM78(parameters);
                    }
                  }
                } else {

                  if (parameters.wait_so_far <= 632978695) {
                    return tpcc_LM79(parameters);
                  } else {

                    if (parameters.work_so_far <= 73893) {

                      if (parameters.wait_so_far <= 719361144) {
                        return tpcc_LM80(parameters);
                      } else {
                        return tpcc_LM81(parameters);
                      }
                    } else {

                      if (parameters.max_latency_of_same_last_50 <= 1585690000) {
                        return tpcc_LM82(parameters);
                      } else {
                        return tpcc_LM83(parameters);
                      }
                    }
                  }
                }
              }
            }
          } else {
            return tpcc_LM84(parameters);
          }
        }
      }
    } else {

      if (parameters.wait_so_far <= 142520377.5) {

        if (parameters.work_so_far <= 64481.5) {

          if (parameters.mean_wait_of_all <= 158627000) {

            if (parameters.total_wait_locks <= 453.5) {
              return tpcc_LM85(parameters);
            } else {

              if (parameters.avg_work_of_same_past_second <= 202700000) {
                return tpcc_LM86(parameters);
              } else {
                return tpcc_LM87(parameters);
              }
            }
          } else {

            if (parameters.total_wait_locks <= 712.5) {

              if (parameters.avg_wait_of_same_past_second <= 316890000) {

                if (parameters.avg_wait_of_same_past_second <= 294959500) {
                  return tpcc_LM88(parameters);
                } else {
                  return tpcc_LM89(parameters);
                }
              } else {

                if (parameters.max_latency_of_same_last_50 <= 1532895000) {
                  return tpcc_LM90(parameters);
                } else {
                  return tpcc_LM91(parameters);
                }
              }
            } else {

              if (parameters.avg_work_of_same_past_second <= 223867000) {
                return tpcc_LM92(parameters);
              } else {
                return tpcc_LM93(parameters);
              }
            }
          }
        } else {
          return tpcc_LM94(parameters);
        }
      } else {

        if (parameters.avg_latency_of_same_last_20 <= 518056000) {
          return tpcc_LM95(parameters);
        } else {

          if (parameters.avg_wait_of_same_past_second <= 307043000) {

            if (parameters.cpu_usage <= 0.894) {

              if (parameters.total_wait_locks <= 721.5) {

                if (parameters.avg_work_of_same_past_second <= 247902500) {

                  if (parameters.mean_wait_of_all <= 160968500) {

                    if (parameters.cpu_usage <= 0.846) {
                      return tpcc_LM96(parameters);
                    } else {
                      return tpcc_LM97(parameters);
                    }
                  } else {
                    return tpcc_LM98(parameters);
                  }
                } else {
                  return tpcc_LM99(parameters);
                }
              } else {

                if (parameters.avg_work_of_same_past_second <= 229227500) {
                  return tpcc_LM100(parameters);
                } else {
                  return tpcc_LM101(parameters);
                }
              }
            } else {
              return tpcc_LM102(parameters);
            }
          } else {

            if (parameters.wait_so_far <= 434798571) {

              if (parameters.total_wait_locks <= 667.5) {
                return tpcc_LM103(parameters);
              } else {

                if (parameters.avg_wait_of_same_past_second <= 344510000) {
                  return tpcc_LM104(parameters);
                } else {
                  return tpcc_LM105(parameters);
                }
              }
            } else {
              return tpcc_LM106(parameters);
            }
          }
        }
      }
    }
  }
}