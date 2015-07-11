#include "my_global.h"
#include "trace_tool.h"

static
double
new_order_LM1(work_wait &parameters) {
  double actual_remaining = 
	1942.5034 * parameters.work_so_far 
	- 0.0903 * parameters.wait_so_far 
	+ 7701.6889 * parameters.total_wait_locks 
	- 4123646.6163 * parameters.cpu_usage 
	+ 0.4323 * parameters.avg_work_of_same_past_second 
	- 0.389 * parameters.avg_wait_of_same_past_second 
	+ 0.2489 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	- 10485781.0819;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM2(work_wait &parameters) {
  double actual_remaining = 
	35.1969 * parameters.work_so_far 
	- 0.1137 * parameters.wait_so_far 
	+ 885189.4087 * parameters.total_wait_locks 
	- 3.6275 * parameters.mean_wait_of_all 
	- 343285174.973 * parameters.cpu_usage 
	+ 0.0086 * parameters.avg_work_of_same_past_second 
	- 0.004 * parameters.avg_wait_of_same_past_second 
	+ 0.0051 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 630351260.9832;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM3(work_wait &parameters) {
  double actual_remaining = 
	0.0065 * parameters.work_so_far 
	- 0.1893 * parameters.wait_so_far 
	+ 326160.176 * parameters.total_wait_locks 
	+ 0.0038 * parameters.mean_wait_of_all 
	- 145739919.4723 * parameters.cpu_usage 
	- 0.382 * parameters.avg_work_of_same_past_second 
	- 0.0018 * parameters.avg_wait_of_same_past_second 
	+ 0.1181 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 294816551.2596;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM4(work_wait &parameters) {
  double actual_remaining = 
	0.0115 * parameters.work_so_far 
	- 0.1588 * parameters.wait_so_far 
	+ 2038.6684 * parameters.total_wait_locks 
	+ 0.006 * parameters.mean_wait_of_all 
	- 430732.4526 * parameters.cpu_usage 
	+ 0.0045 * parameters.avg_work_of_same_past_second 
	- 0.0015 * parameters.avg_wait_of_same_past_second 
	+ 0.003 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 252870621.6698;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM5(work_wait &parameters) {
  double actual_remaining = 
	0.0194 * parameters.work_so_far 
	- 0.2552 * parameters.wait_so_far 
	+ 2038.6684 * parameters.total_wait_locks 
	+ 0.0097 * parameters.mean_wait_of_all 
	- 430732.4526 * parameters.cpu_usage 
	+ 0.0045 * parameters.avg_work_of_same_past_second 
	- 0.0015 * parameters.avg_wait_of_same_past_second 
	+ 0.2023 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 227285548.5995;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM6(work_wait &parameters) {
  double actual_remaining = 
	0.0037 * parameters.work_so_far 
	- 0.0053 * parameters.wait_so_far 
	+ 4876.9134 * parameters.total_wait_locks 
	+ 0.0016 * parameters.mean_wait_of_all 
	- 430732.4526 * parameters.cpu_usage 
	+ 0.0036 * parameters.avg_work_of_same_past_second 
	- 0.0034 * parameters.avg_wait_of_same_past_second 
	+ 0.0058 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 101161360.0104;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM7(work_wait &parameters) {
  double actual_remaining = 
	0.0037 * parameters.work_so_far 
	- 0.0126 * parameters.wait_so_far 
	+ 15525.3699 * parameters.total_wait_locks 
	- 0.0776 * parameters.mean_wait_of_all 
	- 430732.4526 * parameters.cpu_usage 
	+ 1.0374 * parameters.avg_work_of_same_past_second 
	- 0.0159 * parameters.avg_wait_of_same_past_second 
	+ 0.0049 * parameters.avg_latency_of_same_last_20 
	- 0.0713 * parameters.max_latency_of_same_last_50 
	+ 85693555.4497;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM8(work_wait &parameters) {
  double actual_remaining = 
	0.0037 * parameters.work_so_far 
	- 0.0126 * parameters.wait_so_far 
	+ 15525.3699 * parameters.total_wait_locks 
	- 0.0776 * parameters.mean_wait_of_all 
	- 430732.4526 * parameters.cpu_usage 
	+ 1.3349 * parameters.avg_work_of_same_past_second 
	- 0.0159 * parameters.avg_wait_of_same_past_second 
	+ 0.0049 * parameters.avg_latency_of_same_last_20 
	- 0.1231 * parameters.max_latency_of_same_last_50 
	+ 199606040.0451;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM9(work_wait &parameters) {
  double actual_remaining = 
	0.0037 * parameters.work_so_far 
	- 0.0126 * parameters.wait_so_far 
	+ 15525.3699 * parameters.total_wait_locks 
	- 0.0776 * parameters.mean_wait_of_all 
	- 430732.4526 * parameters.cpu_usage 
	+ 1.3349 * parameters.avg_work_of_same_past_second 
	- 0.0159 * parameters.avg_wait_of_same_past_second 
	+ 0.148 * parameters.avg_latency_of_same_last_20 
	- 0.1231 * parameters.max_latency_of_same_last_50 
	+ 90963157.7882;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM10(work_wait &parameters) {
  double actual_remaining = 
	0.0037 * parameters.work_so_far 
	- 0.0126 * parameters.wait_so_far 
	+ 15525.3699 * parameters.total_wait_locks 
	- 0.0776 * parameters.mean_wait_of_all 
	- 430732.4526 * parameters.cpu_usage 
	+ 1.3349 * parameters.avg_work_of_same_past_second 
	- 0.0159 * parameters.avg_wait_of_same_past_second 
	+ 0.1909 * parameters.avg_latency_of_same_last_20 
	- 0.1231 * parameters.max_latency_of_same_last_50 
	+ 86010849.6061;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM11(work_wait &parameters) {
  double actual_remaining = 
	0.0037 * parameters.work_so_far 
	- 0.0126 * parameters.wait_so_far 
	- 549328.3867 * parameters.total_wait_locks 
	- 0.0776 * parameters.mean_wait_of_all 
	- 430732.4526 * parameters.cpu_usage 
	+ 1.2709 * parameters.avg_work_of_same_past_second 
	- 0.0159 * parameters.avg_wait_of_same_past_second 
	- 0.1341 * parameters.avg_latency_of_same_last_20 
	- 0.1163 * parameters.max_latency_of_same_last_50 
	+ 281303052.6344;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM12(work_wait &parameters) {
  double actual_remaining = 
	0.0037 * parameters.work_so_far 
	- 0.1598 * parameters.wait_so_far 
	+ 15525.3699 * parameters.total_wait_locks 
	- 0.3653 * parameters.mean_wait_of_all 
	- 430732.4526 * parameters.cpu_usage 
	+ 0.0238 * parameters.avg_work_of_same_past_second 
	- 0.0159 * parameters.avg_wait_of_same_past_second 
	+ 0.0049 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 225666171.4992;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM13(work_wait &parameters) {
  double actual_remaining = 
	-368.8604 * parameters.work_so_far 
	- 0.1372 * parameters.wait_so_far 
	+ 459947.6856 * parameters.total_wait_locks 
	- 1.2293 * parameters.mean_wait_of_all 
	- 430732.4526 * parameters.cpu_usage 
	+ 0.0164 * parameters.avg_work_of_same_past_second 
	- 0.2042 * parameters.avg_wait_of_same_past_second 
	+ 0.1194 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 205038903.4937;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM14(work_wait &parameters) {
  double actual_remaining = 
	-8.7889 * parameters.work_so_far 
	- 0.0157 * parameters.wait_so_far 
	+ 4541054.3066 * parameters.total_wait_locks 
	- 20.9846 * parameters.mean_wait_of_all 
	- 430732.4526 * parameters.cpu_usage 
	+ 0.037 * parameters.avg_work_of_same_past_second 
	- 0.0261 * parameters.avg_wait_of_same_past_second 
	+ 0.0049 * parameters.avg_latency_of_same_last_20 
	+ 0.5618 * parameters.max_latency_of_same_last_50 
	+ 643790987.1282;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM15(work_wait &parameters) {
  double actual_remaining = 
	0.0037 * parameters.work_so_far 
	- 0.0157 * parameters.wait_so_far 
	+ 3287920.4097 * parameters.total_wait_locks 
	- 15.5568 * parameters.mean_wait_of_all 
	- 430732.4526 * parameters.cpu_usage 
	+ 0.037 * parameters.avg_work_of_same_past_second 
	- 0.0261 * parameters.avg_wait_of_same_past_second 
	+ 0.2067 * parameters.avg_latency_of_same_last_20 
	+ 0.0384 * parameters.max_latency_of_same_last_50 
	+ 653889348.6005;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM16(work_wait &parameters) {
  double actual_remaining = 
	0.0037 * parameters.work_so_far 
	- 0.0157 * parameters.wait_so_far 
	+ 3287920.4097 * parameters.total_wait_locks 
	- 15.5568 * parameters.mean_wait_of_all 
	- 430732.4526 * parameters.cpu_usage 
	+ 0.037 * parameters.avg_work_of_same_past_second 
	- 0.0261 * parameters.avg_wait_of_same_past_second 
	+ 0.23 * parameters.avg_latency_of_same_last_20 
	+ 0.0384 * parameters.max_latency_of_same_last_50 
	+ 701398888.1294;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM17(work_wait &parameters) {
  double actual_remaining = 
	0.0037 * parameters.work_so_far 
	- 0.0157 * parameters.wait_so_far 
	+ 382381.3514 * parameters.total_wait_locks 
	- 5.557 * parameters.mean_wait_of_all 
	- 430732.4526 * parameters.cpu_usage 
	- 0.0509 * parameters.avg_work_of_same_past_second 
	- 0.3635 * parameters.avg_wait_of_same_past_second 
	+ 0.0049 * parameters.avg_latency_of_same_last_20 
	+ 0.0234 * parameters.max_latency_of_same_last_50 
	+ 632555812.0584;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM18(work_wait &parameters) {
  double actual_remaining = 
	0.0037 * parameters.work_so_far 
	- 0.0157 * parameters.wait_so_far 
	+ 390668.5966 * parameters.total_wait_locks 
	- 1.5531 * parameters.mean_wait_of_all 
	- 430732.4526 * parameters.cpu_usage 
	- 0.0571 * parameters.avg_work_of_same_past_second 
	- 0.0261 * parameters.avg_wait_of_same_past_second 
	+ 0.0049 * parameters.avg_latency_of_same_last_20 
	+ 0.0242 * parameters.max_latency_of_same_last_50 
	+ 227248335.6126;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM19(work_wait &parameters) {
  double actual_remaining = 
	0.0037 * parameters.work_so_far 
	- 0.0098 * parameters.wait_so_far 
	+ 8910.5093 * parameters.total_wait_locks 
	+ 0.0016 * parameters.mean_wait_of_all 
	- 430732.4526 * parameters.cpu_usage 
	+ 0.0036 * parameters.avg_work_of_same_past_second 
	- 0.0021 * parameters.avg_wait_of_same_past_second 
	+ 0.1672 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 18864436.0455;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM20(work_wait &parameters) {
  double actual_remaining = 
	1.3855 * parameters.work_so_far 
	- 0.7132 * parameters.wait_so_far 
	- 2583557.9505 * parameters.total_wait_locks 
	+ 23.3492 * parameters.mean_wait_of_all 
	- 612671205.9924 * parameters.cpu_usage 
	+ 0.0006 * parameters.avg_work_of_same_past_second 
	+ 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0059 * parameters.avg_latency_of_same_last_20 
	- 0.07 * parameters.max_latency_of_same_last_50 
	- 801024288.0407;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM21(work_wait &parameters) {
  double actual_remaining = 
	-0.196 * parameters.work_so_far 
	- 0.0239 * parameters.wait_so_far 
	- 504402.5835 * parameters.total_wait_locks 
	+ 4.4007 * parameters.mean_wait_of_all 
	- 18848782.5191 * parameters.cpu_usage 
	+ 0.0006 * parameters.avg_work_of_same_past_second 
	+ 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0117 * parameters.avg_latency_of_same_last_20 
	- 0.0255 * parameters.max_latency_of_same_last_50 
	+ 201562823.9008;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM22(work_wait &parameters) {
  double actual_remaining = 
	-0.196 * parameters.work_so_far 
	- 0.0239 * parameters.wait_so_far 
	- 406143.3022 * parameters.total_wait_locks 
	+ 3.5169 * parameters.mean_wait_of_all 
	- 18848782.5191 * parameters.cpu_usage 
	+ 0.0006 * parameters.avg_work_of_same_past_second 
	+ 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0117 * parameters.avg_latency_of_same_last_20 
	- 0.0187 * parameters.max_latency_of_same_last_50 
	+ 159203171.5964;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM23(work_wait &parameters) {
  double actual_remaining = 
	-5.2747 * parameters.work_so_far 
	- 0.0239 * parameters.wait_so_far 
	+ 277971.7413 * parameters.total_wait_locks 
	- 3.5323 * parameters.mean_wait_of_all 
	- 18848782.5191 * parameters.cpu_usage 
	+ 0.0006 * parameters.avg_work_of_same_past_second 
	+ 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0117 * parameters.avg_latency_of_same_last_20 
	- 2.3665 * parameters.max_latency_of_same_last_50 
	+ 5858217633.754;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM24(work_wait &parameters) {
  double actual_remaining = 
	-8.6202 * parameters.work_so_far 
	- 0.0239 * parameters.wait_so_far 
	+ 277971.7413 * parameters.total_wait_locks 
	- 3.5323 * parameters.mean_wait_of_all 
	- 18848782.5191 * parameters.cpu_usage 
	+ 0.0006 * parameters.avg_work_of_same_past_second 
	+ 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0117 * parameters.avg_latency_of_same_last_20 
	- 0.0884 * parameters.max_latency_of_same_last_50 
	+ 1333902095.5166;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM25(work_wait &parameters) {
  double actual_remaining = 
	-0.3681 * parameters.work_so_far 
	- 0.0239 * parameters.wait_so_far 
	- 28798.43 * parameters.total_wait_locks 
	- 0.2992 * parameters.mean_wait_of_all 
	- 18848782.5191 * parameters.cpu_usage 
	+ 0.0006 * parameters.avg_work_of_same_past_second 
	+ 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0117 * parameters.avg_latency_of_same_last_20 
	- 0.1767 * parameters.max_latency_of_same_last_50 
	+ 985200950.0685;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM26(work_wait &parameters) {
  double actual_remaining = 
	-0.1534 * parameters.wait_so_far 
	- 905733.358 * parameters.total_wait_locks 
	+ 7.4692 * parameters.mean_wait_of_all 
	- 483173833.986 * parameters.cpu_usage 
	+ 0.0006 * parameters.avg_work_of_same_past_second 
	+ 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.1911 * parameters.avg_latency_of_same_last_20 
	- 0.0242 * parameters.max_latency_of_same_last_50 
	+ 176981430.6637;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
new_order_estimate(work_wait &parameters){

  if (parameters.total_wait_locks <= 437.5) {

    if (parameters.work_so_far <= 41776) {

      if (parameters.total_wait_locks <= 169.5) {
        return new_order_LM1(parameters);
      } else {
        return new_order_LM2(parameters);
      }
    } else {

      if (parameters.wait_so_far <= 276337370.5) {

        if (parameters.avg_work_of_same_past_second <= 161019000) {
          return new_order_LM3(parameters);
        } else {

          if (parameters.work_so_far <= 82879) {
            return new_order_LM4(parameters);
          } else {
            return new_order_LM5(parameters);
          }
        }
      } else {

        if (parameters.avg_latency_of_same_last_20 <= 294101500) {
          return new_order_LM6(parameters);
        } else {

          if (parameters.wait_so_far <= 622640183.5) {

            if (parameters.total_wait_locks <= 213.5) {

              if (parameters.avg_work_of_same_past_second <= 141337500) {

                if (parameters.max_latency_of_same_last_50 <= 811925500) {
                  return new_order_LM7(parameters);
                } else {

                  if (parameters.max_latency_of_same_last_50 <= 1112910000) {

                    if (parameters.work_so_far <= 61465.5) {
                      return new_order_LM8(parameters);
                    } else {

                      if (parameters.avg_latency_of_same_last_20 <= 438826000) {
                        return new_order_LM9(parameters);
                      } else {
                        return new_order_LM10(parameters);
                      }
                    }
                  } else {
                    return new_order_LM11(parameters);
                  }
                }
              } else {
                return new_order_LM12(parameters);
              }
            } else {

              if (parameters.work_so_far <= 289441) {
                return new_order_LM13(parameters);
              } else {

                if (parameters.mean_wait_of_all <= 94704050) {

                  if (parameters.avg_latency_of_same_last_20 <= 351019500) {
                    return new_order_LM14(parameters);
                  } else {

                    if (parameters.avg_latency_of_same_last_20 <= 511151500) {
                      return new_order_LM15(parameters);
                    } else {
                      return new_order_LM16(parameters);
                    }
                  }
                } else {

                  if (parameters.total_wait_locks <= 372.5) {
                    return new_order_LM17(parameters);
                  } else {
                    return new_order_LM18(parameters);
                  }
                }
              }
            }
          } else {
            return new_order_LM19(parameters);
          }
        }
      }
    }
  } else {

    if (parameters.wait_so_far <= 123401387) {

      if (parameters.avg_latency_of_same_last_20 <= 635629500) {
        return new_order_LM20(parameters);
      } else {

        if (parameters.max_latency_of_same_last_50 <= 2018765000) {

          if (parameters.max_latency_of_same_last_50 <= 1602850000) {
            return new_order_LM21(parameters);
          } else {
            return new_order_LM22(parameters);
          }
        } else {

          if (parameters.max_latency_of_same_last_50 <= 2122975000) {

            if (parameters.max_latency_of_same_last_50 <= 2100160000) {
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
  }
}
static
double
payment_LM1(work_wait &parameters) {
  double actual_remaining = 
	1310.4683 * parameters.work_so_far 
	+ 0.0156 * parameters.wait_so_far 
	+ 24509.4346 * parameters.total_wait_locks 
	- 0.0005 * parameters.mean_wait_of_all 
	- 66048.5623 * parameters.cpu_usage 
	- 0.0004 * parameters.avg_work_of_same_past_second 
	- 0.0218 * parameters.avg_wait_of_same_past_second 
	+ 0.0254 * parameters.avg_latency_of_same_last_20 
	- 0.0071 * parameters.max_latency_of_same_last_50 
	- 3357227.2689;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM2(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	+ 0.0584 * parameters.wait_so_far 
	+ 33012.1289 * parameters.total_wait_locks 
	+ 0.0199 * parameters.mean_wait_of_all 
	+ 67932735.3169 * parameters.cpu_usage 
	- 0.5084 * parameters.avg_work_of_same_past_second 
	+ 0.0011 * parameters.avg_wait_of_same_past_second 
	+ 0.0021 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 41109314.5391;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM3(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	+ 0.064 * parameters.wait_so_far 
	+ 33012.1289 * parameters.total_wait_locks 
	+ 0.0199 * parameters.mean_wait_of_all 
	- 96799.6349 * parameters.cpu_usage 
	- 0.5084 * parameters.avg_work_of_same_past_second 
	+ 0.0011 * parameters.avg_wait_of_same_past_second 
	+ 0.0021 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 26662981.3342;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM4(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	+ 0.064 * parameters.wait_so_far 
	+ 33012.1289 * parameters.total_wait_locks 
	+ 0.0199 * parameters.mean_wait_of_all 
	- 96799.6349 * parameters.cpu_usage 
	- 0.5084 * parameters.avg_work_of_same_past_second 
	+ 0.0011 * parameters.avg_wait_of_same_past_second 
	+ 0.0021 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 29362233.9579;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM5(work_wait &parameters) {
  double actual_remaining = 
	-97.2284 * parameters.work_so_far 
	+ 0.0103 * parameters.wait_so_far 
	+ 178455.1035 * parameters.total_wait_locks 
	- 0.6016 * parameters.mean_wait_of_all 
	- 96799.6349 * parameters.cpu_usage 
	- 0.5084 * parameters.avg_work_of_same_past_second 
	+ 0.0011 * parameters.avg_wait_of_same_past_second 
	- 0.0687 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 67911851.644;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM6(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0017 * parameters.wait_so_far 
	+ 152543.2768 * parameters.total_wait_locks 
	+ 0.0199 * parameters.mean_wait_of_all 
	- 96799.6349 * parameters.cpu_usage 
	- 0.4182 * parameters.avg_work_of_same_past_second 
	+ 0.0011 * parameters.avg_wait_of_same_past_second 
	+ 0.0039 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 6071862.2433;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM7(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0204 * parameters.wait_so_far 
	+ 38400.4922 * parameters.total_wait_locks 
	+ 0.0199 * parameters.mean_wait_of_all 
	- 96799.6349 * parameters.cpu_usage 
	- 0.6757 * parameters.avg_work_of_same_past_second 
	+ 0.0011 * parameters.avg_wait_of_same_past_second 
	+ 0.0405 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 11777605.9566;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM8(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0008 * parameters.wait_so_far 
	+ 182427.3926 * parameters.total_wait_locks 
	- 2.8327 * parameters.mean_wait_of_all 
	- 96799.6349 * parameters.cpu_usage 
	+ 1.4349 * parameters.avg_work_of_same_past_second 
	- 0.0622 * parameters.avg_wait_of_same_past_second 
	+ 0.0021 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 245357138.7484;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM9(work_wait &parameters) {
  double actual_remaining = 
	-288.6021 * parameters.work_so_far 
	- 0.0008 * parameters.wait_so_far 
	+ 198196.3203 * parameters.total_wait_locks 
	- 2.8327 * parameters.mean_wait_of_all 
	- 96799.6349 * parameters.cpu_usage 
	+ 1.4349 * parameters.avg_work_of_same_past_second 
	- 0.0622 * parameters.avg_wait_of_same_past_second 
	+ 0.0021 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 254840859.5622;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM10(work_wait &parameters) {
  double actual_remaining = 
	-27.3997 * parameters.work_so_far 
	- 0.0008 * parameters.wait_so_far 
	+ 314413.6056 * parameters.total_wait_locks 
	- 1.1138 * parameters.mean_wait_of_all 
	- 96799.6349 * parameters.cpu_usage 
	+ 0.3898 * parameters.avg_work_of_same_past_second 
	- 0.0395 * parameters.avg_wait_of_same_past_second 
	+ 0.0276 * parameters.avg_latency_of_same_last_20 
	- 0.0294 * parameters.max_latency_of_same_last_50 
	+ 113314418.2361;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM11(work_wait &parameters) {
  double actual_remaining = 
	-32.9245 * parameters.work_so_far 
	+ 0.0092 * parameters.wait_so_far 
	+ 314413.6056 * parameters.total_wait_locks 
	- 1.1138 * parameters.mean_wait_of_all 
	- 96799.6349 * parameters.cpu_usage 
	+ 0.3898 * parameters.avg_work_of_same_past_second 
	- 0.0395 * parameters.avg_wait_of_same_past_second 
	+ 0.0288 * parameters.avg_latency_of_same_last_20 
	- 0.0294 * parameters.max_latency_of_same_last_50 
	+ 115465862.9263;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM12(work_wait &parameters) {
  double actual_remaining = 
	1342.1935 * parameters.work_so_far 
	- 0.0008 * parameters.wait_so_far 
	+ 245247.4045 * parameters.total_wait_locks 
	- 1.1138 * parameters.mean_wait_of_all 
	- 96799.6349 * parameters.cpu_usage 
	+ 0.3898 * parameters.avg_work_of_same_past_second 
	- 0.0395 * parameters.avg_wait_of_same_past_second 
	+ 0.0021 * parameters.avg_latency_of_same_last_20 
	- 0.0416 * parameters.max_latency_of_same_last_50 
	+ 118637885.3435;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM13(work_wait &parameters) {
  double actual_remaining = 
	1638.0841 * parameters.work_so_far 
	- 0.0008 * parameters.wait_so_far 
	+ 245247.4045 * parameters.total_wait_locks 
	- 1.7239 * parameters.mean_wait_of_all 
	- 96799.6349 * parameters.cpu_usage 
	+ 0.3898 * parameters.avg_work_of_same_past_second 
	- 0.0395 * parameters.avg_wait_of_same_past_second 
	+ 0.0021 * parameters.avg_latency_of_same_last_20 
	- 0.0387 * parameters.max_latency_of_same_last_50 
	+ 163121748.1987;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM14(work_wait &parameters) {
  double actual_remaining = 
	-15.2663 * parameters.work_so_far 
	- 0.0008 * parameters.wait_so_far 
	+ 245247.4045 * parameters.total_wait_locks 
	- 2.7665 * parameters.mean_wait_of_all 
	- 96799.6349 * parameters.cpu_usage 
	+ 0.3898 * parameters.avg_work_of_same_past_second 
	- 0.0395 * parameters.avg_wait_of_same_past_second 
	+ 0.0021 * parameters.avg_latency_of_same_last_20 
	- 0.0299 * parameters.max_latency_of_same_last_50 
	+ 286397521.0282;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM15(work_wait &parameters) {
  double actual_remaining = 
	-16.6192 * parameters.work_so_far 
	- 0.0008 * parameters.wait_so_far 
	+ 245247.4045 * parameters.total_wait_locks 
	- 1.1138 * parameters.mean_wait_of_all 
	- 96799.6349 * parameters.cpu_usage 
	+ 0.3898 * parameters.avg_work_of_same_past_second 
	- 0.0395 * parameters.avg_wait_of_same_past_second 
	+ 0.0021 * parameters.avg_latency_of_same_last_20 
	- 0.0323 * parameters.max_latency_of_same_last_50 
	+ 134711210.9657;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM16(work_wait &parameters) {
  double actual_remaining = 
	-8.9353 * parameters.work_so_far 
	- 0.0008 * parameters.wait_so_far 
	+ 258574.2958 * parameters.total_wait_locks 
	- 1.1138 * parameters.mean_wait_of_all 
	- 96799.6349 * parameters.cpu_usage 
	+ 0.3898 * parameters.avg_work_of_same_past_second 
	- 0.0755 * parameters.avg_wait_of_same_past_second 
	+ 0.035 * parameters.avg_latency_of_same_last_20 
	- 0.0162 * parameters.max_latency_of_same_last_50 
	+ 108904954.578;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM17(work_wait &parameters) {
  double actual_remaining = 
	0.0693 * parameters.work_so_far 
	- 0.0145 * parameters.wait_so_far 
	+ 1145.6543 * parameters.total_wait_locks 
	+ 0.6342 * parameters.mean_wait_of_all 
	- 96799.6349 * parameters.cpu_usage 
	- 2.1437 * parameters.avg_work_of_same_past_second 
	+ 0.0248 * parameters.avg_wait_of_same_past_second 
	+ 0.0397 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 13698648.7444;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM18(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0005 * parameters.wait_so_far 
	+ 65213.0418 * parameters.total_wait_locks 
	+ 0.0007 * parameters.mean_wait_of_all 
	- 54029510.9945 * parameters.cpu_usage 
	- 0.0939 * parameters.avg_work_of_same_past_second 
	+ 0.0008 * parameters.avg_wait_of_same_past_second 
	+ 0.0017 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 58244293.2112;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM19(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	+ 0.0009 * parameters.wait_so_far 
	+ 1634.3137 * parameters.total_wait_locks 
	+ 0.0007 * parameters.mean_wait_of_all 
	+ 5515261.1484 * parameters.cpu_usage 
	+ 0.4238 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0025 * parameters.avg_latency_of_same_last_20 
	- 0.0109 * parameters.max_latency_of_same_last_50 
	+ 12776592.4632;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM20(work_wait &parameters) {
  double actual_remaining = 
	0.2387 * parameters.work_so_far 
	+ 0.0187 * parameters.wait_so_far 
	+ 22046.3678 * parameters.total_wait_locks 
	- 2.6766 * parameters.mean_wait_of_all 
	+ 1868254.2892 * parameters.cpu_usage 
	+ 0.3932 * parameters.avg_work_of_same_past_second 
	- 0.0033 * parameters.avg_wait_of_same_past_second 
	+ 0.0097 * parameters.avg_latency_of_same_last_20 
	- 0.003 * parameters.max_latency_of_same_last_50 
	+ 244031082.4591;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM21(work_wait &parameters) {
  double actual_remaining = 
	1.4578 * parameters.work_so_far 
	+ 0.0013 * parameters.wait_so_far 
	+ 7952.3304 * parameters.total_wait_locks 
	- 0.1348 * parameters.mean_wait_of_all 
	+ 1868254.2892 * parameters.cpu_usage 
	+ 0.3932 * parameters.avg_work_of_same_past_second 
	- 0.0033 * parameters.avg_wait_of_same_past_second 
	+ 0.0287 * parameters.avg_latency_of_same_last_20 
	- 0.0016 * parameters.max_latency_of_same_last_50 
	+ 13191200.378;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM22(work_wait &parameters) {
  double actual_remaining = 
	4.1575 * parameters.work_so_far 
	+ 0.0106 * parameters.wait_so_far 
	+ 1634.3137 * parameters.total_wait_locks 
	+ 0.4427 * parameters.mean_wait_of_all 
	+ 1868254.2892 * parameters.cpu_usage 
	+ 8.0861 * parameters.avg_work_of_same_past_second 
	- 0.0092 * parameters.avg_wait_of_same_past_second 
	- 0.0157 * parameters.avg_latency_of_same_last_20 
	- 0.0019 * parameters.max_latency_of_same_last_50 
	- 168800364.4485;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM23(work_wait &parameters) {
  double actual_remaining = 
	-0.2193 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 403165.9958 * parameters.total_wait_locks 
	- 14.5296 * parameters.mean_wait_of_all 
	- 172411815.2734 * parameters.cpu_usage 
	+ 0.1507 * parameters.avg_work_of_same_past_second 
	- 0.1839 * parameters.avg_wait_of_same_past_second 
	- 0.184 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 1653184248.9949;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM24(work_wait &parameters) {
  double actual_remaining = 
	-0.0571 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 10446.1243 * parameters.total_wait_locks 
	- 0.5894 * parameters.mean_wait_of_all 
	- 96799.6349 * parameters.cpu_usage 
	+ 0.2823 * parameters.avg_work_of_same_past_second 
	- 0.2549 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 92569943.7986;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM25(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0089 * parameters.wait_so_far 
	+ 150232.226 * parameters.total_wait_locks 
	- 2.9225 * parameters.mean_wait_of_all 
	- 96799.6349 * parameters.cpu_usage 
	- 0.9254 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	- 0.0071 * parameters.max_latency_of_same_last_50 
	+ 309255417.2136;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM26(work_wait &parameters) {
  double actual_remaining = 
	4.5163 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 433666.7536 * parameters.total_wait_locks 
	+ 2.3672 * parameters.mean_wait_of_all 
	- 96799.6349 * parameters.cpu_usage 
	- 0.0756 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 74586830.1391;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM27(work_wait &parameters) {
  double actual_remaining = 
	-0.0001 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 22118.1699 * parameters.total_wait_locks 
	- 0.1265 * parameters.mean_wait_of_all 
	- 51030.5958 * parameters.cpu_usage 
	- 0.0003 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 28879950.4698;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM28(work_wait &parameters) {
  double actual_remaining = 
	-0.0031 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	- 70595.7471 * parameters.total_wait_locks 
	- 0.0351 * parameters.mean_wait_of_all 
	+ 90945473.7679 * parameters.cpu_usage 
	+ 0.0785 * parameters.avg_work_of_same_past_second 
	- 0.0316 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 43946137.2532;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM29(work_wait &parameters) {
  double actual_remaining = 
	-0.0031 * parameters.work_so_far 
	- 0.0051 * parameters.wait_so_far 
	- 79766.1576 * parameters.total_wait_locks 
	- 0.0424 * parameters.mean_wait_of_all 
	+ 2294448.5213 * parameters.cpu_usage 
	+ 0.1001 * parameters.avg_work_of_same_past_second 
	- 0.031 * parameters.avg_wait_of_same_past_second 
	+ 0.0241 * parameters.avg_latency_of_same_last_20 
	+ 0.0024 * parameters.max_latency_of_same_last_50 
	+ 48016710.699;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM30(work_wait &parameters) {
  double actual_remaining = 
	-0.0031 * parameters.work_so_far 
	- 0.0051 * parameters.wait_so_far 
	+ 789.5134 * parameters.total_wait_locks 
	- 0.0424 * parameters.mean_wait_of_all 
	+ 2294448.5213 * parameters.cpu_usage 
	+ 0.1001 * parameters.avg_work_of_same_past_second 
	- 0.031 * parameters.avg_wait_of_same_past_second 
	+ 0.0387 * parameters.avg_latency_of_same_last_20 
	+ 0.0024 * parameters.max_latency_of_same_last_50 
	+ 34389883.3247;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM31(work_wait &parameters) {
  double actual_remaining = 
	-0.0031 * parameters.work_so_far 
	- 0.0345 * parameters.wait_so_far 
	+ 789.5134 * parameters.total_wait_locks 
	- 2.5569 * parameters.mean_wait_of_all 
	+ 2294448.5213 * parameters.cpu_usage 
	+ 0.1001 * parameters.avg_work_of_same_past_second 
	- 0.031 * parameters.avg_wait_of_same_past_second 
	+ 0.0387 * parameters.avg_latency_of_same_last_20 
	+ 0.0024 * parameters.max_latency_of_same_last_50 
	+ 260765078.658;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM32(work_wait &parameters) {
  double actual_remaining = 
	-0.0031 * parameters.work_so_far 
	- 0.0051 * parameters.wait_so_far 
	+ 789.5134 * parameters.total_wait_locks 
	- 0.0424 * parameters.mean_wait_of_all 
	+ 2294448.5213 * parameters.cpu_usage 
	+ 0.1001 * parameters.avg_work_of_same_past_second 
	+ 0.1037 * parameters.avg_wait_of_same_past_second 
	+ 0.0132 * parameters.avg_latency_of_same_last_20 
	+ 0.0024 * parameters.max_latency_of_same_last_50 
	- 40029518.7243;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM33(work_wait &parameters) {
  double actual_remaining = 
	-0.0031 * parameters.work_so_far 
	- 0.0041 * parameters.wait_so_far 
	+ 789.5134 * parameters.total_wait_locks 
	- 0.0424 * parameters.mean_wait_of_all 
	+ 2294448.5213 * parameters.cpu_usage 
	+ 0.1001 * parameters.avg_work_of_same_past_second 
	- 0.0111 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0.0018 * parameters.max_latency_of_same_last_50 
	+ 21467800.4356;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM34(work_wait &parameters) {
  double actual_remaining = 
	-0.0741 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 17265.9088 * parameters.total_wait_locks 
	- 0.0029 * parameters.mean_wait_of_all 
	- 51030.5958 * parameters.cpu_usage 
	- 0.1905 * parameters.avg_work_of_same_past_second 
	- 0.0176 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 24631149.103;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM35(work_wait &parameters) {
  double actual_remaining = 
	0.0047 * parameters.work_so_far 
	- 0.0056 * parameters.wait_so_far 
	- 854.2996 * parameters.total_wait_locks 
	+ 0.0042 * parameters.mean_wait_of_all 
	- 51030.5958 * parameters.cpu_usage 
	- 0.0003 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0172 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 16421615.3034;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM36(work_wait &parameters) {
  double actual_remaining = 
	1.7174 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	- 126325.8268 * parameters.total_wait_locks 
	+ 2.8809 * parameters.mean_wait_of_all 
	- 91442889.8823 * parameters.cpu_usage 
	- 5.6329 * parameters.avg_work_of_same_past_second 
	- 0.0019 * parameters.avg_wait_of_same_past_second 
	+ 0.0855 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 34523584.5688;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM37(work_wait &parameters) {
  double actual_remaining = 
	0.1303 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	- 18020.1319 * parameters.total_wait_locks 
	- 0.6736 * parameters.mean_wait_of_all 
	- 321354608.073 * parameters.cpu_usage 
	- 0.1215 * parameters.avg_work_of_same_past_second 
	- 0.0019 * parameters.avg_wait_of_same_past_second 
	+ 0.0007 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 427368253.1056;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM38(work_wait &parameters) {
  double actual_remaining = 
	0.0129 * parameters.work_so_far 
	+ 0.3163 * parameters.wait_so_far 
	- 13185.4018 * parameters.total_wait_locks 
	- 6.6251 * parameters.mean_wait_of_all 
	- 51030.5958 * parameters.cpu_usage 
	- 1.6567 * parameters.avg_work_of_same_past_second 
	- 0.002 * parameters.avg_wait_of_same_past_second 
	+ 0.045 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 785064491.7053;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM39(work_wait &parameters) {
  double actual_remaining = 
	0.0129 * parameters.work_so_far 
	- 0.0014 * parameters.wait_so_far 
	- 13185.4018 * parameters.total_wait_locks 
	- 0.1332 * parameters.mean_wait_of_all 
	- 51030.5958 * parameters.cpu_usage 
	- 0.0715 * parameters.avg_work_of_same_past_second 
	- 0.002 * parameters.avg_wait_of_same_past_second 
	+ 0.0029 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 40087792.8763;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM40(work_wait &parameters) {
  double actual_remaining = 
	0.0267 * parameters.work_so_far 
	- 0.0089 * parameters.wait_so_far 
	- 173259.2377 * parameters.total_wait_locks 
	+ 0.5639 * parameters.mean_wait_of_all 
	- 51030.5958 * parameters.cpu_usage 
	- 0.0003 * parameters.avg_work_of_same_past_second 
	- 0.0667 * parameters.avg_wait_of_same_past_second 
	+ 0.0202 * parameters.avg_latency_of_same_last_20 
	+ 0.0141 * parameters.max_latency_of_same_last_50 
	+ 34219579.4258;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM41(work_wait &parameters) {
  double actual_remaining = 
	7.2443 * parameters.work_so_far 
	+ 0.0332 * parameters.wait_so_far 
	- 31424.4454 * parameters.total_wait_locks 
	- 1.1833 * parameters.mean_wait_of_all 
	- 51030.5958 * parameters.cpu_usage 
	- 6.4786 * parameters.avg_work_of_same_past_second 
	+ 0.032 * parameters.avg_wait_of_same_past_second 
	- 0.0532 * parameters.avg_latency_of_same_last_20 
	+ 0.0011 * parameters.max_latency_of_same_last_50 
	+ 405549968.219;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM42(work_wait &parameters) {
  double actual_remaining = 
	2.8979 * parameters.work_so_far 
	- 0.0146 * parameters.wait_so_far 
	- 31424.4454 * parameters.total_wait_locks 
	- 1.1833 * parameters.mean_wait_of_all 
	- 51030.5958 * parameters.cpu_usage 
	- 5.3645 * parameters.avg_work_of_same_past_second 
	+ 0.032 * parameters.avg_wait_of_same_past_second 
	- 0.0424 * parameters.avg_latency_of_same_last_20 
	+ 0.0011 * parameters.max_latency_of_same_last_50 
	+ 370852828.4543;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM43(work_wait &parameters) {
  double actual_remaining = 
	0.2226 * parameters.work_so_far 
	- 0.0204 * parameters.wait_so_far 
	- 31424.4454 * parameters.total_wait_locks 
	- 0.4514 * parameters.mean_wait_of_all 
	- 51030.5958 * parameters.cpu_usage 
	- 0.3894 * parameters.avg_work_of_same_past_second 
	+ 0.0131 * parameters.avg_wait_of_same_past_second 
	+ 0.0006 * parameters.avg_latency_of_same_last_20 
	+ 0.0011 * parameters.max_latency_of_same_last_50 
	+ 103272568.6708;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM44(work_wait &parameters) {
  double actual_remaining = 
	0.0489 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	- 17586.8623 * parameters.total_wait_locks 
	+ 0.063 * parameters.mean_wait_of_all 
	+ 336802135.4279 * parameters.cpu_usage 
	- 0.6571 * parameters.avg_work_of_same_past_second 
	- 0.0011 * parameters.avg_wait_of_same_past_second 
	+ 0.0175 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 303844257.5318;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM45(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 65.8608 * parameters.total_wait_locks 
	- 0.0008 * parameters.mean_wait_of_all 
	+ 1172759.4433 * parameters.cpu_usage 
	+ 0.001 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0222 * parameters.avg_latency_of_same_last_20 
	+ 0.0003 * parameters.max_latency_of_same_last_50 
	+ 14130654.0542;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM46(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0189 * parameters.wait_so_far 
	- 81279.9174 * parameters.total_wait_locks 
	+ 0.0716 * parameters.mean_wait_of_all 
	+ 2262611.8409 * parameters.cpu_usage 
	- 1.1138 * parameters.avg_work_of_same_past_second 
	- 0.0101 * parameters.avg_wait_of_same_past_second 
	- 0.1912 * parameters.avg_latency_of_same_last_20 
	+ 0.0005 * parameters.max_latency_of_same_last_50 
	+ 184766940.692;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM47(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0262 * parameters.wait_so_far 
	- 54740.6547 * parameters.total_wait_locks 
	+ 0.0716 * parameters.mean_wait_of_all 
	+ 2262611.8409 * parameters.cpu_usage 
	- 1.1138 * parameters.avg_work_of_same_past_second 
	- 0.0101 * parameters.avg_wait_of_same_past_second 
	- 0.1912 * parameters.avg_latency_of_same_last_20 
	+ 0.0005 * parameters.max_latency_of_same_last_50 
	+ 173679869.667;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM48(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	+ 0.0129 * parameters.wait_so_far 
	+ 25173.7291 * parameters.total_wait_locks 
	+ 0.0716 * parameters.mean_wait_of_all 
	+ 2262611.8409 * parameters.cpu_usage 
	- 1.1138 * parameters.avg_work_of_same_past_second 
	- 0.0101 * parameters.avg_wait_of_same_past_second 
	- 0.1912 * parameters.avg_latency_of_same_last_20 
	+ 0.0005 * parameters.max_latency_of_same_last_50 
	+ 164426957.908;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM49(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 73214.2024 * parameters.total_wait_locks 
	+ 0.4524 * parameters.mean_wait_of_all 
	+ 2262611.8409 * parameters.cpu_usage 
	- 0.4751 * parameters.avg_work_of_same_past_second 
	- 0.0101 * parameters.avg_wait_of_same_past_second 
	- 0.0888 * parameters.avg_latency_of_same_last_20 
	+ 0.0005 * parameters.max_latency_of_same_last_50 
	+ 45886220.797;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM50(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 4251.6453 * parameters.total_wait_locks 
	+ 0.0411 * parameters.mean_wait_of_all 
	+ 2262611.8409 * parameters.cpu_usage 
	- 0.0374 * parameters.avg_work_of_same_past_second 
	- 0.0059 * parameters.avg_wait_of_same_past_second 
	- 0.0138 * parameters.avg_latency_of_same_last_20 
	+ 0.0005 * parameters.max_latency_of_same_last_50 
	+ 25704721.5847;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM51(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 65.8608 * parameters.total_wait_locks 
	- 0.0008 * parameters.mean_wait_of_all 
	- 125586.4564 * parameters.cpu_usage 
	+ 0.001 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0176 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 22824967.5445;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM52(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 26475.5878 * parameters.total_wait_locks 
	- 0.3073 * parameters.mean_wait_of_all 
	- 2834130.7888 * parameters.cpu_usage 
	+ 0.0026 * parameters.avg_work_of_same_past_second 
	+ 0.0598 * parameters.avg_wait_of_same_past_second 
	+ 0.0014 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 56164838.9335;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM53(work_wait &parameters) {
  double actual_remaining = 
	-0.0077 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 385446.3843 * parameters.total_wait_locks 
	- 9.0145 * parameters.mean_wait_of_all 
	- 7494358.8815 * parameters.cpu_usage 
	- 1.7553 * parameters.avg_work_of_same_past_second 
	- 0.3672 * parameters.avg_wait_of_same_past_second 
	+ 0.0057 * parameters.avg_latency_of_same_last_20 
	- 0.0026 * parameters.max_latency_of_same_last_50 
	+ 1434468076.2243;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM54(work_wait &parameters) {
  double actual_remaining = 
	-269.8079 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 296212.1496 * parameters.total_wait_locks 
	- 10.9909 * parameters.mean_wait_of_all 
	- 7494358.8815 * parameters.cpu_usage 
	+ 0.0026 * parameters.avg_work_of_same_past_second 
	+ 0.5999 * parameters.avg_wait_of_same_past_second 
	+ 0.0084 * parameters.avg_latency_of_same_last_20 
	- 0.0041 * parameters.max_latency_of_same_last_50 
	+ 1414211851.4688;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM55(work_wait &parameters) {
  double actual_remaining = 
	-0.0077 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 1089271.7335 * parameters.total_wait_locks 
	- 10.9909 * parameters.mean_wait_of_all 
	- 7494358.8815 * parameters.cpu_usage 
	+ 0.0026 * parameters.avg_work_of_same_past_second 
	+ 0.5999 * parameters.avg_wait_of_same_past_second 
	+ 0.0084 * parameters.avg_latency_of_same_last_20 
	- 0.0041 * parameters.max_latency_of_same_last_50 
	+ 776986757.1356;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM56(work_wait &parameters) {
  double actual_remaining = 
	-4.9475 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 425.6558 * parameters.total_wait_locks 
	- 10.9909 * parameters.mean_wait_of_all 
	- 7494358.8815 * parameters.cpu_usage 
	+ 0.0026 * parameters.avg_work_of_same_past_second 
	+ 0.725 * parameters.avg_wait_of_same_past_second 
	+ 0.0084 * parameters.avg_latency_of_same_last_20 
	- 0.0041 * parameters.max_latency_of_same_last_50 
	+ 1604965002.9738;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM57(work_wait &parameters) {
  double actual_remaining = 
	0.3537 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 425.6558 * parameters.total_wait_locks 
	- 20.1475 * parameters.mean_wait_of_all 
	- 7494358.8815 * parameters.cpu_usage 
	+ 0.0026 * parameters.avg_work_of_same_past_second 
	+ 0.5509 * parameters.avg_wait_of_same_past_second 
	+ 0.0084 * parameters.avg_latency_of_same_last_20 
	- 0.0412 * parameters.max_latency_of_same_last_50 
	+ 3254510828.3367;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM58(work_wait &parameters) {
  double actual_remaining = 
	-0.0025 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 141765.7667 * parameters.total_wait_locks 
	- 0.003 * parameters.mean_wait_of_all 
	- 45312513.8297 * parameters.cpu_usage 
	+ 0.0026 * parameters.avg_work_of_same_past_second 
	+ 0.0468 * parameters.avg_wait_of_same_past_second 
	+ 0.0012 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	- 71255496.4722;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
payment_estimate(work_wait &parameters){

  if (parameters.mean_wait_of_all <= 130459000) {

    if (parameters.work_so_far <= 18233.5) {
      return payment_LM1(parameters);
    } else {

      if (parameters.avg_work_of_same_past_second <= 19449350) {

        if (parameters.mean_wait_of_all <= 97634500) {

          if (parameters.avg_work_of_same_past_second <= 18009300) {

            if (parameters.mean_wait_of_all <= 92180450) {

              if (parameters.total_wait_locks <= 191.5) {

                if (parameters.mean_wait_of_all <= 87993900) {

                  if (parameters.avg_work_of_same_past_second <= 7908880) {

                    if (parameters.avg_work_of_same_past_second <= 6156325) {

                      if (parameters.avg_latency_of_same_last_20 <= 56187600) {
                        return payment_LM2(parameters);
                      } else {

                        if (parameters.total_wait_locks <= 66) {
                          return payment_LM3(parameters);
                        } else {
                          return payment_LM4(parameters);
                        }
                      }
                    } else {
                      return payment_LM5(parameters);
                    }
                  } else {

                    if (parameters.avg_work_of_same_past_second <= 16239100) {
                      return payment_LM6(parameters);
                    } else {
                      return payment_LM7(parameters);
                    }
                  }
                } else {

                  if (parameters.avg_work_of_same_past_second <= 7712630) {

                    if (parameters.total_wait_locks <= 182.5) {
                      return payment_LM8(parameters);
                    } else {
                      return payment_LM9(parameters);
                    }
                  } else {

                    if (parameters.wait_so_far <= 255659903) {

                      if (parameters.total_wait_locks <= 124) {

                        if (parameters.avg_latency_of_same_last_20 <= 101535600) {
                          return payment_LM10(parameters);
                        } else {
                          return payment_LM11(parameters);
                        }
                      } else {

                        if (parameters.avg_latency_of_same_last_20 <= 311152000) {

                          if (parameters.work_so_far <= 38122) {

                            if (parameters.max_latency_of_same_last_50 <= 330699000) {
                              return payment_LM12(parameters);
                            } else {
                              return payment_LM13(parameters);
                            }
                          } else {
                            return payment_LM14(parameters);
                          }
                        } else {
                          return payment_LM15(parameters);
                        }
                      }
                    } else {
                      return payment_LM16(parameters);
                    }
                  }
                }
              } else {
                return payment_LM17(parameters);
              }
            } else {
              return payment_LM18(parameters);
            }
          } else {

            if (parameters.avg_wait_of_same_past_second <= 207343000) {
              return payment_LM19(parameters);
            } else {

              if (parameters.avg_wait_of_same_past_second <= 382791500) {

                if (parameters.mean_wait_of_all <= 89161100) {
                  return payment_LM20(parameters);
                } else {
                  return payment_LM21(parameters);
                }
              } else {
                return payment_LM22(parameters);
              }
            }
          }
        } else {

          if (parameters.avg_wait_of_same_past_second <= 61140800) {

            if (parameters.mean_wait_of_all <= 105268000) {
              return payment_LM23(parameters);
            } else {
              return payment_LM24(parameters);
            }
          } else {

            if (parameters.total_wait_locks <= 345.5) {
              return payment_LM25(parameters);
            } else {
              return payment_LM26(parameters);
            }
          }
        }
      } else {

        if (parameters.mean_wait_of_all <= 106485500) {

          if (parameters.wait_so_far <= 197539345) {
            return payment_LM27(parameters);
          } else {

            if (parameters.mean_wait_of_all <= 87967900) {

              if (parameters.avg_work_of_same_past_second <= 23285350) {
                return payment_LM28(parameters);
              } else {

                if (parameters.wait_so_far <= 378738762.5) {

                  if (parameters.avg_wait_of_same_past_second <= 447409500) {

                    if (parameters.avg_latency_of_same_last_20 <= 442141000) {
                      return payment_LM29(parameters);
                    } else {

                      if (parameters.mean_wait_of_all <= 81195350) {
                        return payment_LM30(parameters);
                      } else {
                        return payment_LM31(parameters);
                      }
                    }
                  } else {
                    return payment_LM32(parameters);
                  }
                } else {
                  return payment_LM33(parameters);
                }
              }
            } else {
              return payment_LM34(parameters);
            }
          }
        } else {

          if (parameters.cpu_usage <= 0.968) {
            return payment_LM35(parameters);
          } else {

            if (parameters.total_wait_locks <= 363.5) {

              if (parameters.total_wait_locks <= 333.5) {
                return payment_LM36(parameters);
              } else {
                return payment_LM37(parameters);
              }
            } else {

              if (parameters.mean_wait_of_all <= 112996500) {

                if (parameters.wait_so_far <= 42023256.5) {
                  return payment_LM38(parameters);
                } else {
                  return payment_LM39(parameters);
                }
              } else {

                if (parameters.max_latency_of_same_last_50 <= 1346290000) {

                  if (parameters.avg_work_of_same_past_second <= 31190350) {
                    return payment_LM40(parameters);
                  } else {

                    if (parameters.mean_wait_of_all <= 119512000) {

                      if (parameters.avg_wait_of_same_past_second <= 389428500) {
                        return payment_LM41(parameters);
                      } else {
                        return payment_LM42(parameters);
                      }
                    } else {
                      return payment_LM43(parameters);
                    }
                  }
                } else {
                  return payment_LM44(parameters);
                }
              }
            }
          }
        }
      }
    }
  } else {

    if (parameters.mean_wait_of_all <= 164539000) {

      if (parameters.avg_latency_of_same_last_20 <= 349319000) {

        if (parameters.max_latency_of_same_last_50 <= 1236335000) {
          return payment_LM45(parameters);
        } else {

          if (parameters.avg_wait_of_same_past_second <= 482827500) {

            if (parameters.avg_work_of_same_past_second <= 27681050) {

              if (parameters.avg_work_of_same_past_second <= 26743500) {

                if (parameters.total_wait_locks <= 744) {
                  return payment_LM46(parameters);
                } else {
                  return payment_LM47(parameters);
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
      } else {
        return payment_LM51(parameters);
      }
    } else {

      if (parameters.total_wait_locks <= 721.5) {
        return payment_LM52(parameters);
      } else {

        if (parameters.avg_wait_of_same_past_second <= 453160000) {

          if (parameters.mean_wait_of_all <= 168991500) {
            return payment_LM53(parameters);
          } else {

            if (parameters.mean_wait_of_all <= 169439000) {

              if (parameters.cpu_usage <= 0.882) {

                if (parameters.work_so_far <= 46599) {
                  return payment_LM54(parameters);
                } else {
                  return payment_LM55(parameters);
                }
              } else {
                return payment_LM56(parameters);
              }
            } else {
              return payment_LM57(parameters);
            }
          }
        } else {
          return payment_LM58(parameters);
        }
      }
    }
  }
}
static
double
stock_level_LM1(work_wait &parameters) {
  double actual_remaining = 
	-75044.0999 * parameters.num_locks_so_far 
	+ 0.5667 * parameters.avg_wait_of_same_past_second 
	- 2625646.537;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
stock_level_LM2(work_wait &parameters) {
  double actual_remaining = 
	-0.159 * parameters.work_so_far 
	- 98134.5922 * parameters.num_locks_so_far 
	+ 1.917 * parameters.avg_wait_of_same_past_second 
	- 18477749.2372;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
stock_level_estimate(work_wait &parameters){

  if (parameters.work_so_far <= 10665932) {
    return stock_level_LM1(parameters);
  } else {
    return stock_level_LM2(parameters);
  }
}
static
double
tpcc_LM1(work_wait &parameters) {
  double actual_remaining = 
	1309.1436 * parameters.work_so_far 
	+ 0.0155 * parameters.wait_so_far 
	+ 24567.2935 * parameters.total_wait_locks 
	- 0.0005 * parameters.mean_wait_of_all 
	- 110010.4078 * parameters.cpu_usage 
	+ 0.0006 * parameters.avg_work_of_same_past_second 
	- 0.0219 * parameters.avg_wait_of_same_past_second 
	+ 0.0255 * parameters.avg_latency_of_same_last_20 
	- 0.0071 * parameters.max_latency_of_same_last_50 
	- 3288433.6682;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM2(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	+ 0.0582 * parameters.wait_so_far 
	+ 33061.3929 * parameters.total_wait_locks 
	+ 0.0198 * parameters.mean_wait_of_all 
	+ 67820036.915 * parameters.cpu_usage 
	- 0.5069 * parameters.avg_work_of_same_past_second 
	+ 0.001 * parameters.avg_wait_of_same_past_second 
	+ 0.0022 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 41002359.249;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM3(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	+ 0.0638 * parameters.wait_so_far 
	+ 33061.3929 * parameters.total_wait_locks 
	+ 0.0198 * parameters.mean_wait_of_all 
	- 140730.3958 * parameters.cpu_usage 
	- 0.5069 * parameters.avg_work_of_same_past_second 
	+ 0.001 * parameters.avg_wait_of_same_past_second 
	+ 0.0022 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 26701429.0135;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM4(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	+ 0.0638 * parameters.wait_so_far 
	+ 33061.3929 * parameters.total_wait_locks 
	+ 0.0198 * parameters.mean_wait_of_all 
	- 140730.3958 * parameters.cpu_usage 
	- 0.5069 * parameters.avg_work_of_same_past_second 
	+ 0.001 * parameters.avg_wait_of_same_past_second 
	+ 0.0022 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 29397953.0982;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM5(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	+ 0.0102 * parameters.wait_so_far 
	+ 92203.58 * parameters.total_wait_locks 
	+ 0.0198 * parameters.mean_wait_of_all 
	- 140730.3958 * parameters.cpu_usage 
	- 0.5069 * parameters.avg_work_of_same_past_second 
	+ 0.001 * parameters.avg_wait_of_same_past_second 
	+ 0.0022 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 15851202.7602;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM6(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	+ 0.0102 * parameters.wait_so_far 
	+ 97816.1754 * parameters.total_wait_locks 
	+ 0.6008 * parameters.mean_wait_of_all 
	- 140730.3958 * parameters.cpu_usage 
	- 0.5069 * parameters.avg_work_of_same_past_second 
	+ 0.001 * parameters.avg_wait_of_same_past_second 
	+ 0.0022 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 24696958.1165;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM7(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	+ 0.0102 * parameters.wait_so_far 
	+ 79660.69 * parameters.total_wait_locks 
	+ 0.0198 * parameters.mean_wait_of_all 
	- 140730.3958 * parameters.cpu_usage 
	- 0.5069 * parameters.avg_work_of_same_past_second 
	+ 0.001 * parameters.avg_wait_of_same_past_second 
	+ 0.0022 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 13939430.0265;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM8(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0018 * parameters.wait_so_far 
	+ 152471.7127 * parameters.total_wait_locks 
	+ 0.0198 * parameters.mean_wait_of_all 
	- 140730.3958 * parameters.cpu_usage 
	- 0.4168 * parameters.avg_work_of_same_past_second 
	+ 0.001 * parameters.avg_wait_of_same_past_second 
	+ 0.004 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 6131124.4509;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM9(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0038 * parameters.wait_so_far 
	+ 38444.3093 * parameters.total_wait_locks 
	+ 0.0198 * parameters.mean_wait_of_all 
	- 140730.3958 * parameters.cpu_usage 
	- 0.674 * parameters.avg_work_of_same_past_second 
	+ 0.001 * parameters.avg_wait_of_same_past_second 
	+ 0.0076 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 15969023.0287;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM10(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0009 * parameters.wait_so_far 
	+ 182325.6202 * parameters.total_wait_locks 
	- 2.8298 * parameters.mean_wait_of_all 
	- 140730.3958 * parameters.cpu_usage 
	+ 1.4345 * parameters.avg_work_of_same_past_second 
	- 0.0623 * parameters.avg_wait_of_same_past_second 
	+ 0.0022 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 245174519.485;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM11(work_wait &parameters) {
  double actual_remaining = 
	-288.3104 * parameters.work_so_far 
	- 0.0009 * parameters.wait_so_far 
	+ 198078.6079 * parameters.total_wait_locks 
	- 2.8298 * parameters.mean_wait_of_all 
	- 140730.3958 * parameters.cpu_usage 
	+ 1.4345 * parameters.avg_work_of_same_past_second 
	- 0.0623 * parameters.avg_wait_of_same_past_second 
	+ 0.0022 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 254648653.6817;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM12(work_wait &parameters) {
  double actual_remaining = 
	-13.8957 * parameters.work_so_far 
	+ 0.0383 * parameters.wait_so_far 
	+ 314178.4149 * parameters.total_wait_locks 
	- 1.1127 * parameters.mean_wait_of_all 
	- 140730.3958 * parameters.cpu_usage 
	+ 0.3904 * parameters.avg_work_of_same_past_second 
	- 0.0396 * parameters.avg_wait_of_same_past_second 
	+ 0.0022 * parameters.avg_latency_of_same_last_20 
	- 0.0294 * parameters.max_latency_of_same_last_50 
	+ 111986665.1161;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM13(work_wait &parameters) {
  double actual_remaining = 
	-13.8957 * parameters.work_so_far 
	+ 0.0402 * parameters.wait_so_far 
	+ 314178.4149 * parameters.total_wait_locks 
	- 1.1127 * parameters.mean_wait_of_all 
	- 140730.3958 * parameters.cpu_usage 
	+ 0.3904 * parameters.avg_work_of_same_past_second 
	- 0.0396 * parameters.avg_wait_of_same_past_second 
	+ 0.0022 * parameters.avg_latency_of_same_last_20 
	- 0.0294 * parameters.max_latency_of_same_last_50 
	+ 114520788.3939;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM14(work_wait &parameters) {
  double actual_remaining = 
	1340.8368 * parameters.work_so_far 
	- 0.0009 * parameters.wait_so_far 
	+ 245082.1305 * parameters.total_wait_locks 
	- 1.1127 * parameters.mean_wait_of_all 
	- 140730.3958 * parameters.cpu_usage 
	+ 0.3904 * parameters.avg_work_of_same_past_second 
	- 0.0396 * parameters.avg_wait_of_same_past_second 
	+ 0.0022 * parameters.avg_latency_of_same_last_20 
	- 0.0416 * parameters.max_latency_of_same_last_50 
	+ 118583360.2106;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM15(work_wait &parameters) {
  double actual_remaining = 
	1636.4283 * parameters.work_so_far 
	- 0.0009 * parameters.wait_so_far 
	+ 245082.1305 * parameters.total_wait_locks 
	- 1.7222 * parameters.mean_wait_of_all 
	- 140730.3958 * parameters.cpu_usage 
	+ 0.3904 * parameters.avg_work_of_same_past_second 
	- 0.0396 * parameters.avg_wait_of_same_past_second 
	+ 0.0022 * parameters.avg_latency_of_same_last_20 
	- 0.0387 * parameters.max_latency_of_same_last_50 
	+ 163022256.5624;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM16(work_wait &parameters) {
  double actual_remaining = 
	-15.2509 * parameters.work_so_far 
	- 0.0009 * parameters.wait_so_far 
	+ 245082.1305 * parameters.total_wait_locks 
	- 2.7637 * parameters.mean_wait_of_all 
	- 140730.3958 * parameters.cpu_usage 
	+ 0.3904 * parameters.avg_work_of_same_past_second 
	- 0.0396 * parameters.avg_wait_of_same_past_second 
	+ 0.0022 * parameters.avg_latency_of_same_last_20 
	- 0.0299 * parameters.max_latency_of_same_last_50 
	+ 286173416.1031;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM17(work_wait &parameters) {
  double actual_remaining = 
	-16.6024 * parameters.work_so_far 
	- 0.0009 * parameters.wait_so_far 
	+ 245082.1305 * parameters.total_wait_locks 
	- 1.1127 * parameters.mean_wait_of_all 
	- 140730.3958 * parameters.cpu_usage 
	+ 0.3904 * parameters.avg_work_of_same_past_second 
	- 0.0396 * parameters.avg_wait_of_same_past_second 
	+ 0.0022 * parameters.avg_latency_of_same_last_20 
	- 0.0323 * parameters.max_latency_of_same_last_50 
	+ 134640438.115;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM18(work_wait &parameters) {
  double actual_remaining = 
	-8.9262 * parameters.work_so_far 
	- 0.0009 * parameters.wait_so_far 
	+ 258395.5503 * parameters.total_wait_locks 
	- 1.1127 * parameters.mean_wait_of_all 
	- 140730.3958 * parameters.cpu_usage 
	+ 0.3904 * parameters.avg_work_of_same_past_second 
	- 0.0756 * parameters.avg_wait_of_same_past_second 
	+ 0.0351 * parameters.avg_latency_of_same_last_20 
	- 0.0162 * parameters.max_latency_of_same_last_50 
	+ 108860267.976;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM19(work_wait &parameters) {
  double actual_remaining = 
	0.0072 * parameters.work_so_far 
	- 0.0023 * parameters.wait_so_far 
	+ 1227.1305 * parameters.total_wait_locks 
	+ 0.8144 * parameters.mean_wait_of_all 
	- 140730.3958 * parameters.cpu_usage 
	- 3.4459 * parameters.avg_work_of_same_past_second 
	+ 0.0351 * parameters.avg_wait_of_same_past_second 
	+ 0.0061 * parameters.avg_latency_of_same_last_20 
	+ 0.0194 * parameters.max_latency_of_same_last_50 
	- 16687750.0367;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM20(work_wait &parameters) {
  double actual_remaining = 
	0.0049 * parameters.work_so_far 
	+ 0.0012 * parameters.wait_so_far 
	+ 26841.4532 * parameters.total_wait_locks 
	+ 0.062 * parameters.mean_wait_of_all 
	- 140730.3958 * parameters.cpu_usage 
	- 0.5706 * parameters.avg_work_of_same_past_second 
	+ 0.0026 * parameters.avg_wait_of_same_past_second 
	+ 0.0048 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 10459986.82;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM21(work_wait &parameters) {
  double actual_remaining = 
	0.0049 * parameters.work_so_far 
	- 0.0008 * parameters.wait_so_far 
	+ 131092.7706 * parameters.total_wait_locks 
	+ 0.062 * parameters.mean_wait_of_all 
	- 140730.3958 * parameters.cpu_usage 
	- 1.5621 * parameters.avg_work_of_same_past_second 
	+ 0.0026 * parameters.avg_wait_of_same_past_second 
	+ 0.0048 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 7732304.5573;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM22(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0006 * parameters.wait_so_far 
	+ 81737.0269 * parameters.total_wait_locks 
	+ 0.0007 * parameters.mean_wait_of_all 
	- 140730.3958 * parameters.cpu_usage 
	- 0.7023 * parameters.avg_work_of_same_past_second 
	+ 0.0006 * parameters.avg_wait_of_same_past_second 
	+ 0.0018 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 12513041.1966;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM23(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	+ 0.0008 * parameters.wait_so_far 
	+ 1715.2959 * parameters.total_wait_locks 
	+ 0.0007 * parameters.mean_wait_of_all 
	+ 5465657.4371 * parameters.cpu_usage 
	+ 0.4244 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0026 * parameters.avg_latency_of_same_last_20 
	- 0.0109 * parameters.max_latency_of_same_last_50 
	+ 12829077.1957;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM24(work_wait &parameters) {
  double actual_remaining = 
	0.2384 * parameters.work_so_far 
	+ 0.0186 * parameters.wait_so_far 
	+ 22106.7165 * parameters.total_wait_locks 
	- 2.6739 * parameters.mean_wait_of_all 
	+ 1822337.154 * parameters.cpu_usage 
	+ 0.3938 * parameters.avg_work_of_same_past_second 
	- 0.0035 * parameters.avg_wait_of_same_past_second 
	+ 0.0097 * parameters.avg_latency_of_same_last_20 
	- 0.0031 * parameters.max_latency_of_same_last_50 
	+ 243849803.6395;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM25(work_wait &parameters) {
  double actual_remaining = 
	0.248 * parameters.work_so_far 
	+ 0.0012 * parameters.wait_so_far 
	+ 8026.9261 * parameters.total_wait_locks 
	- 0.1347 * parameters.mean_wait_of_all 
	+ 1822337.154 * parameters.cpu_usage 
	+ 0.3938 * parameters.avg_work_of_same_past_second 
	- 0.0035 * parameters.avg_wait_of_same_past_second 
	+ 0.0271 * parameters.avg_latency_of_same_last_20 
	- 0.0016 * parameters.max_latency_of_same_last_50 
	+ 12606228.7377;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM26(work_wait &parameters) {
  double actual_remaining = 
	0.3822 * parameters.work_so_far 
	- 0.0067 * parameters.wait_so_far 
	+ 39338.1423 * parameters.total_wait_locks 
	- 0.1347 * parameters.mean_wait_of_all 
	+ 1822337.154 * parameters.cpu_usage 
	+ 0.3938 * parameters.avg_work_of_same_past_second 
	- 0.0035 * parameters.avg_wait_of_same_past_second 
	+ 0.0095 * parameters.avg_latency_of_same_last_20 
	- 0.0016 * parameters.max_latency_of_same_last_50 
	+ 13898744.2414;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM27(work_wait &parameters) {
  double actual_remaining = 
	0.3822 * parameters.work_so_far 
	- 0.0249 * parameters.wait_so_far 
	+ 31970.7973 * parameters.total_wait_locks 
	- 0.1347 * parameters.mean_wait_of_all 
	+ 1822337.154 * parameters.cpu_usage 
	+ 0.3938 * parameters.avg_work_of_same_past_second 
	- 0.0035 * parameters.avg_wait_of_same_past_second 
	+ 0.0095 * parameters.avg_latency_of_same_last_20 
	- 0.0016 * parameters.max_latency_of_same_last_50 
	+ 26980609.05;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM28(work_wait &parameters) {
  double actual_remaining = 
	1.3004 * parameters.work_so_far 
	+ 0.0039 * parameters.wait_so_far 
	+ 1715.2959 * parameters.total_wait_locks 
	+ 0.0007 * parameters.mean_wait_of_all 
	+ 1822337.154 * parameters.cpu_usage 
	+ 2.9058 * parameters.avg_work_of_same_past_second 
	- 0.0093 * parameters.avg_wait_of_same_past_second 
	+ 0.0042 * parameters.avg_latency_of_same_last_20 
	- 0.0019 * parameters.max_latency_of_same_last_50 
	- 40897223.79;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM29(work_wait &parameters) {
  double actual_remaining = 
	1.7915 * parameters.work_so_far 
	+ 0.0047 * parameters.wait_so_far 
	+ 1715.2959 * parameters.total_wait_locks 
	+ 0.0007 * parameters.mean_wait_of_all 
	+ 1822337.154 * parameters.cpu_usage 
	- 22.059 * parameters.avg_work_of_same_past_second 
	- 0.0093 * parameters.avg_wait_of_same_past_second 
	+ 0.0042 * parameters.avg_latency_of_same_last_20 
	- 0.0019 * parameters.max_latency_of_same_last_50 
	+ 448931780.3165;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM30(work_wait &parameters) {
  double actual_remaining = 
	1.7915 * parameters.work_so_far 
	+ 0.0047 * parameters.wait_so_far 
	+ 1715.2959 * parameters.total_wait_locks 
	+ 0.0007 * parameters.mean_wait_of_all 
	+ 1822337.154 * parameters.cpu_usage 
	- 11.5865 * parameters.avg_work_of_same_past_second 
	- 0.0093 * parameters.avg_wait_of_same_past_second 
	+ 0.0042 * parameters.avg_latency_of_same_last_20 
	- 0.0019 * parameters.max_latency_of_same_last_50 
	+ 241761679.7251;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM31(work_wait &parameters) {
  double actual_remaining = 
	-0.2191 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 402841.0898 * parameters.total_wait_locks 
	- 14.5149 * parameters.mean_wait_of_all 
	- 172281561.4373 * parameters.cpu_usage 
	+ 0.1516 * parameters.avg_work_of_same_past_second 
	- 0.1839 * parameters.avg_wait_of_same_past_second 
	- 0.1837 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 1651578527.996;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM32(work_wait &parameters) {
  double actual_remaining = 
	-0.057 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 10518.199 * parameters.total_wait_locks 
	- 0.5888 * parameters.mean_wait_of_all 
	- 140730.3958 * parameters.cpu_usage 
	+ 0.283 * parameters.avg_work_of_same_past_second 
	- 0.2548 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 92541769.4388;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM33(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0097 * parameters.wait_so_far 
	+ 132742.7027 * parameters.total_wait_locks 
	- 2.8313 * parameters.mean_wait_of_all 
	- 140730.3958 * parameters.cpu_usage 
	- 1.0531 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 301056708.1973;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM34(work_wait &parameters) {
  double actual_remaining = 
	4.5117 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 433145.7474 * parameters.total_wait_locks 
	+ 2.3648 * parameters.mean_wait_of_all 
	- 140730.3958 * parameters.cpu_usage 
	- 0.0745 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 74446034.1095;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM35(work_wait &parameters) {
  double actual_remaining = 
	-0.0001 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 22178.446 * parameters.total_wait_locks 
	- 0.1264 * parameters.mean_wait_of_all 
	- 95007.6223 * parameters.cpu_usage 
	+ 0.0007 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 28916157.1263;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM36(work_wait &parameters) {
  double actual_remaining = 
	-0.0031 * parameters.work_so_far 
	- 0.0008 * parameters.wait_so_far 
	- 70441.7511 * parameters.total_wait_locks 
	- 0.0351 * parameters.mean_wait_of_all 
	+ 90809512.9443 * parameters.cpu_usage 
	+ 0.0795 * parameters.avg_work_of_same_past_second 
	- 0.0318 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	- 43836314.3614;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM37(work_wait &parameters) {
  double actual_remaining = 
	-0.0031 * parameters.work_so_far 
	- 0.0052 * parameters.wait_so_far 
	- 79602.8917 * parameters.total_wait_locks 
	- 0.0423 * parameters.mean_wait_of_all 
	+ 2248100.5677 * parameters.cpu_usage 
	+ 0.101 * parameters.avg_work_of_same_past_second 
	- 0.0311 * parameters.avg_wait_of_same_past_second 
	+ 0.0242 * parameters.avg_latency_of_same_last_20 
	+ 0.0024 * parameters.max_latency_of_same_last_50 
	+ 48033572.9654;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM38(work_wait &parameters) {
  double actual_remaining = 
	-0.0031 * parameters.work_so_far 
	- 0.0052 * parameters.wait_so_far 
	+ 871.3496 * parameters.total_wait_locks 
	- 0.0423 * parameters.mean_wait_of_all 
	+ 2248100.5677 * parameters.cpu_usage 
	+ 0.101 * parameters.avg_work_of_same_past_second 
	- 0.0311 * parameters.avg_wait_of_same_past_second 
	+ 0.0387 * parameters.avg_latency_of_same_last_20 
	+ 0.0024 * parameters.max_latency_of_same_last_50 
	+ 34420520.2667;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM39(work_wait &parameters) {
  double actual_remaining = 
	-0.0031 * parameters.work_so_far 
	- 0.0346 * parameters.wait_so_far 
	+ 871.3496 * parameters.total_wait_locks 
	- 2.5543 * parameters.mean_wait_of_all 
	+ 2248100.5677 * parameters.cpu_usage 
	+ 0.101 * parameters.avg_work_of_same_past_second 
	- 0.0311 * parameters.avg_wait_of_same_past_second 
	+ 0.0387 * parameters.avg_latency_of_same_last_20 
	+ 0.0024 * parameters.max_latency_of_same_last_50 
	+ 260566884.2818;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM40(work_wait &parameters) {
  double actual_remaining = 
	-0.0031 * parameters.work_so_far 
	- 0.0052 * parameters.wait_so_far 
	+ 871.3496 * parameters.total_wait_locks 
	- 0.0423 * parameters.mean_wait_of_all 
	+ 2248100.5677 * parameters.cpu_usage 
	+ 0.101 * parameters.avg_work_of_same_past_second 
	- 0.0418 * parameters.avg_wait_of_same_past_second 
	+ 0.0133 * parameters.avg_latency_of_same_last_20 
	+ 0.0024 * parameters.max_latency_of_same_last_50 
	+ 30559919.4492;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM41(work_wait &parameters) {
  double actual_remaining = 
	-0.0031 * parameters.work_so_far 
	- 0.0042 * parameters.wait_so_far 
	+ 871.3496 * parameters.total_wait_locks 
	- 0.0423 * parameters.mean_wait_of_all 
	+ 2248100.5677 * parameters.cpu_usage 
	+ 0.101 * parameters.avg_work_of_same_past_second 
	- 0.0113 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	+ 0.0018 * parameters.max_latency_of_same_last_50 
	+ 21511499.6623;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM42(work_wait &parameters) {
  double actual_remaining = 
	-0.074 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 17331.0898 * parameters.total_wait_locks 
	- 0.0029 * parameters.mean_wait_of_all 
	- 95007.6223 * parameters.cpu_usage 
	- 0.1893 * parameters.avg_work_of_same_past_second 
	- 0.0177 * parameters.avg_wait_of_same_past_second 
	+ 0.0002 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 24671650.6594;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM43(work_wait &parameters) {
  double actual_remaining = 
	0.0047 * parameters.work_so_far 
	- 0.0057 * parameters.wait_so_far 
	- 770.8017 * parameters.total_wait_locks 
	+ 0.0042 * parameters.mean_wait_of_all 
	- 95007.6223 * parameters.cpu_usage 
	+ 0.0007 * parameters.avg_work_of_same_past_second 
	- 0.0005 * parameters.avg_wait_of_same_past_second 
	+ 0.0173 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 16470415.4653;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM44(work_wait &parameters) {
  double actual_remaining = 
	1.4209 * parameters.work_so_far 
	- 0.0005 * parameters.wait_so_far 
	- 149813.7055 * parameters.total_wait_locks 
	+ 0.022 * parameters.mean_wait_of_all 
	- 95007.6223 * parameters.cpu_usage 
	- 1.335 * parameters.avg_work_of_same_past_second 
	- 0.002 * parameters.avg_wait_of_same_past_second 
	+ 0.0009 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 110097969.5962;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM45(work_wait &parameters) {
  double actual_remaining = 
	0.0129 * parameters.work_so_far 
	+ 0.3195 * parameters.wait_so_far 
	- 13089.4391 * parameters.total_wait_locks 
	- 4.3063 * parameters.mean_wait_of_all 
	- 95007.6223 * parameters.cpu_usage 
	- 0.1478 * parameters.avg_work_of_same_past_second 
	- 0.0022 * parameters.avg_wait_of_same_past_second 
	+ 0.0431 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 491728237.0511;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM46(work_wait &parameters) {
  double actual_remaining = 
	0.0129 * parameters.work_so_far 
	- 0.0015 * parameters.wait_so_far 
	- 13089.4391 * parameters.total_wait_locks 
	- 0.133 * parameters.mean_wait_of_all 
	- 95007.6223 * parameters.cpu_usage 
	- 0.0704 * parameters.avg_work_of_same_past_second 
	- 0.0022 * parameters.avg_wait_of_same_past_second 
	+ 0.003 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 40112670.0876;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM47(work_wait &parameters) {
  double actual_remaining = 
	0.0267 * parameters.work_so_far 
	- 0.0121 * parameters.wait_so_far 
	- 36047.768 * parameters.total_wait_locks 
	+ 0.1207 * parameters.mean_wait_of_all 
	- 95007.6223 * parameters.cpu_usage 
	- 0.7151 * parameters.avg_work_of_same_past_second 
	+ 0.0441 * parameters.avg_wait_of_same_past_second 
	+ 0.0032 * parameters.avg_latency_of_same_last_20 
	+ 0.0021 * parameters.max_latency_of_same_last_50 
	+ 51810877.9336;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM48(work_wait &parameters) {
  double actual_remaining = 
	0.0267 * parameters.work_so_far 
	- 0.0121 * parameters.wait_so_far 
	- 36047.768 * parameters.total_wait_locks 
	+ 0.1207 * parameters.mean_wait_of_all 
	- 95007.6223 * parameters.cpu_usage 
	- 0.7151 * parameters.avg_work_of_same_past_second 
	+ 0.0441 * parameters.avg_wait_of_same_past_second 
	+ 0.0032 * parameters.avg_latency_of_same_last_20 
	+ 0.0021 * parameters.max_latency_of_same_last_50 
	+ 50550637.9566;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM49(work_wait &parameters) {
  double actual_remaining = 
	0.0267 * parameters.work_so_far 
	- 0.0121 * parameters.wait_so_far 
	- 36047.768 * parameters.total_wait_locks 
	+ 0.1207 * parameters.mean_wait_of_all 
	- 95007.6223 * parameters.cpu_usage 
	- 0.7151 * parameters.avg_work_of_same_past_second 
	+ 0.0441 * parameters.avg_wait_of_same_past_second 
	+ 0.0032 * parameters.avg_latency_of_same_last_20 
	+ 0.0237 * parameters.max_latency_of_same_last_50 
	+ 21807590.6717;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM50(work_wait &parameters) {
  double actual_remaining = 
	-2.6678 * parameters.work_so_far 
	- 0.0071 * parameters.wait_so_far 
	- 186443.6164 * parameters.total_wait_locks 
	+ 0.5219 * parameters.mean_wait_of_all 
	- 95007.6223 * parameters.cpu_usage 
	- 0.7151 * parameters.avg_work_of_same_past_second 
	+ 0.0441 * parameters.avg_wait_of_same_past_second 
	+ 0.0032 * parameters.avg_latency_of_same_last_20 
	+ 0.0021 * parameters.max_latency_of_same_last_50 
	+ 42944588.1814;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM51(work_wait &parameters) {
  double actual_remaining = 
	-1.9731 * parameters.work_so_far 
	- 0.0071 * parameters.wait_so_far 
	- 153717.2217 * parameters.total_wait_locks 
	+ 0.1979 * parameters.mean_wait_of_all 
	- 95007.6223 * parameters.cpu_usage 
	- 0.7151 * parameters.avg_work_of_same_past_second 
	+ 0.0441 * parameters.avg_wait_of_same_past_second 
	+ 0.0032 * parameters.avg_latency_of_same_last_20 
	+ 0.0021 * parameters.max_latency_of_same_last_50 
	+ 65566470.3543;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM52(work_wait &parameters) {
  double actual_remaining = 
	-1.5654 * parameters.work_so_far 
	- 0.0071 * parameters.wait_so_far 
	- 771302.2923 * parameters.total_wait_locks 
	+ 1.8952 * parameters.mean_wait_of_all 
	- 95007.6223 * parameters.cpu_usage 
	- 0.7151 * parameters.avg_work_of_same_past_second 
	- 0.2849 * parameters.avg_wait_of_same_past_second 
	+ 0.0032 * parameters.avg_latency_of_same_last_20 
	+ 0.0021 * parameters.max_latency_of_same_last_50 
	+ 241696161.6686;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM53(work_wait &parameters) {
  double actual_remaining = 
	0.0267 * parameters.work_so_far 
	- 0.0017 * parameters.wait_so_far 
	- 36047.768 * parameters.total_wait_locks 
	+ 0.1207 * parameters.mean_wait_of_all 
	+ 484867020.7241 * parameters.cpu_usage 
	- 0.7259 * parameters.avg_work_of_same_past_second 
	+ 0.0449 * parameters.avg_wait_of_same_past_second 
	+ 0.0032 * parameters.avg_latency_of_same_last_20 
	+ 0.0021 * parameters.max_latency_of_same_last_50 
	- 451395320.6329;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM54(work_wait &parameters) {
  double actual_remaining = 
	0.0267 * parameters.work_so_far 
	- 0.001 * parameters.wait_so_far 
	- 296946.0453 * parameters.total_wait_locks 
	+ 1.9497 * parameters.mean_wait_of_all 
	- 202507723.1134 * parameters.cpu_usage 
	+ 0.0007 * parameters.avg_work_of_same_past_second 
	- 0.0895 * parameters.avg_wait_of_same_past_second 
	+ 0.0165 * parameters.avg_latency_of_same_last_20 
	+ 0.0145 * parameters.max_latency_of_same_last_50 
	+ 122953365.207;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM55(work_wait &parameters) {
  double actual_remaining = 
	7.237 * parameters.work_so_far 
	+ 0.0331 * parameters.wait_so_far 
	- 31310.0457 * parameters.total_wait_locks 
	- 1.1821 * parameters.mean_wait_of_all 
	- 95007.6223 * parameters.cpu_usage 
	- 6.4711 * parameters.avg_work_of_same_past_second 
	+ 0.0318 * parameters.avg_wait_of_same_past_second 
	- 0.053 * parameters.avg_latency_of_same_last_20 
	+ 0.0011 * parameters.max_latency_of_same_last_50 
	+ 405205418.068;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM56(work_wait &parameters) {
  double actual_remaining = 
	2.895 * parameters.work_so_far 
	- 0.0147 * parameters.wait_so_far 
	- 31310.0457 * parameters.total_wait_locks 
	- 1.1821 * parameters.mean_wait_of_all 
	- 95007.6223 * parameters.cpu_usage 
	- 5.3581 * parameters.avg_work_of_same_past_second 
	+ 0.0318 * parameters.avg_wait_of_same_past_second 
	- 0.0422 * parameters.avg_latency_of_same_last_20 
	+ 0.0011 * parameters.max_latency_of_same_last_50 
	+ 370543351.8996;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM57(work_wait &parameters) {
  double actual_remaining = 
	0.2224 * parameters.work_so_far 
	- 0.0205 * parameters.wait_so_far 
	- 31310.0457 * parameters.total_wait_locks 
	- 0.451 * parameters.mean_wait_of_all 
	- 95007.6223 * parameters.cpu_usage 
	- 0.388 * parameters.avg_work_of_same_past_second 
	+ 0.0129 * parameters.avg_wait_of_same_past_second 
	+ 0.0007 * parameters.avg_latency_of_same_last_20 
	+ 0.0011 * parameters.max_latency_of_same_last_50 
	+ 103233575.5649;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM58(work_wait &parameters) {
  double actual_remaining = 
	0.0488 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	- 17486.4503 * parameters.total_wait_locks 
	+ 0.0629 * parameters.mean_wait_of_all 
	- 95007.6223 * parameters.cpu_usage 
	+ 0.0007 * parameters.avg_work_of_same_past_second 
	- 0.0013 * parameters.avg_wait_of_same_past_second 
	+ 0.0165 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 12187301.036;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM59(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 148.4284 * parameters.total_wait_locks 
	- 0.0008 * parameters.mean_wait_of_all 
	+ 1127545.3489 * parameters.cpu_usage 
	+ 0.002 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0223 * parameters.avg_latency_of_same_last_20 
	+ 0.0003 * parameters.max_latency_of_same_last_50 
	+ 14181770.0338;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM60(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0315 * parameters.wait_so_far 
	- 35665.232 * parameters.total_wait_locks 
	+ 0.0715 * parameters.mean_wait_of_all 
	+ 2216296.0694 * parameters.cpu_usage 
	- 1.1117 * parameters.avg_work_of_same_past_second 
	- 0.0103 * parameters.avg_wait_of_same_past_second 
	- 0.1909 * parameters.avg_latency_of_same_last_20 
	+ 0.0005 * parameters.max_latency_of_same_last_50 
	+ 158497880.6541;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM61(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	+ 0.0128 * parameters.wait_so_far 
	+ 25230.9165 * parameters.total_wait_locks 
	+ 0.0715 * parameters.mean_wait_of_all 
	+ 2216296.0694 * parameters.cpu_usage 
	- 1.1117 * parameters.avg_work_of_same_past_second 
	- 0.0103 * parameters.avg_wait_of_same_past_second 
	- 0.1909 * parameters.avg_latency_of_same_last_20 
	+ 0.0005 * parameters.max_latency_of_same_last_50 
	+ 164326146.9008;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM62(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 73057.5596 * parameters.total_wait_locks 
	+ 0.4519 * parameters.mean_wait_of_all 
	+ 2216296.0694 * parameters.cpu_usage 
	- 0.4736 * parameters.avg_work_of_same_past_second 
	- 0.0103 * parameters.avg_wait_of_same_past_second 
	- 0.0886 * parameters.avg_latency_of_same_last_20 
	+ 0.0005 * parameters.max_latency_of_same_last_50 
	+ 45905236.6687;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM63(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 4164.7133 * parameters.total_wait_locks 
	+ 0.0411 * parameters.mean_wait_of_all 
	+ 2216296.0694 * parameters.cpu_usage 
	- 0.0364 * parameters.avg_work_of_same_past_second 
	- 0.0061 * parameters.avg_wait_of_same_past_second 
	- 0.0136 * parameters.avg_latency_of_same_last_20 
	+ 0.0005 * parameters.max_latency_of_same_last_50 
	+ 25744137.9206;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM64(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 148.4284 * parameters.total_wait_locks 
	- 0.0008 * parameters.mean_wait_of_all 
	- 169488.1182 * parameters.cpu_usage 
	+ 0.002 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0177 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 22867294.8792;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM65(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	- 26366.1907 * parameters.total_wait_locks 
	- 0.307 * parameters.mean_wait_of_all 
	- 2875294.519 * parameters.cpu_usage 
	+ 0.0036 * parameters.avg_work_of_same_past_second 
	+ 0.0596 * parameters.avg_wait_of_same_past_second 
	+ 0.0015 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 56173464.6663;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM66(work_wait &parameters) {
  double actual_remaining = 
	-0.0077 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 385139.3901 * parameters.total_wait_locks 
	- 9.0054 * parameters.mean_wait_of_all 
	- 7530811.8212 * parameters.cpu_usage 
	- 1.7526 * parameters.avg_work_of_same_past_second 
	- 0.367 * parameters.avg_wait_of_same_past_second 
	+ 0.0058 * parameters.avg_latency_of_same_last_20 
	- 0.0027 * parameters.max_latency_of_same_last_50 
	+ 1433083444.4222;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM67(work_wait &parameters) {
  double actual_remaining = 
	-269.5352 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 295995.3578 * parameters.total_wait_locks 
	- 10.9798 * parameters.mean_wait_of_all 
	- 7530811.8212 * parameters.cpu_usage 
	+ 0.0036 * parameters.avg_work_of_same_past_second 
	+ 0.5992 * parameters.avg_wait_of_same_past_second 
	+ 0.0085 * parameters.avg_latency_of_same_last_20 
	- 0.0041 * parameters.max_latency_of_same_last_50 
	+ 1412847695.6672;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM68(work_wait &parameters) {
  double actual_remaining = 
	-0.0077 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 1088253.2777 * parameters.total_wait_locks 
	- 10.9798 * parameters.mean_wait_of_all 
	- 7530811.8212 * parameters.cpu_usage 
	+ 0.0036 * parameters.avg_work_of_same_past_second 
	+ 0.5992 * parameters.avg_wait_of_same_past_second 
	+ 0.0085 * parameters.avg_latency_of_same_last_20 
	- 0.0041 * parameters.max_latency_of_same_last_50 
	+ 776266740.1854;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM69(work_wait &parameters) {
  double actual_remaining = 
	-4.9425 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 507.8598 * parameters.total_wait_locks 
	- 10.9798 * parameters.mean_wait_of_all 
	- 7530811.8212 * parameters.cpu_usage 
	+ 0.0036 * parameters.avg_work_of_same_past_second 
	+ 0.7241 * parameters.avg_wait_of_same_past_second 
	+ 0.0085 * parameters.avg_latency_of_same_last_20 
	- 0.0041 * parameters.max_latency_of_same_last_50 
	+ 1603408024.3895;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM70(work_wait &parameters) {
  double actual_remaining = 
	0.2385 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 507.8598 * parameters.total_wait_locks 
	- 20.1271 * parameters.mean_wait_of_all 
	- 7530811.8212 * parameters.cpu_usage 
	+ 0.0036 * parameters.avg_work_of_same_past_second 
	+ 0.5502 * parameters.avg_wait_of_same_past_second 
	+ 0.0085 * parameters.avg_latency_of_same_last_20 
	- 0.0294 * parameters.max_latency_of_same_last_50 
	+ 3239797593.0988;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM71(work_wait &parameters) {
  double actual_remaining = 
	0.2278 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 507.8598 * parameters.total_wait_locks 
	- 20.1271 * parameters.mean_wait_of_all 
	- 7530811.8212 * parameters.cpu_usage 
	+ 0.0036 * parameters.avg_work_of_same_past_second 
	+ 0.5502 * parameters.avg_wait_of_same_past_second 
	+ 0.0085 * parameters.avg_latency_of_same_last_20 
	- 0.0283 * parameters.max_latency_of_same_last_50 
	+ 3233988347.9037;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM72(work_wait &parameters) {
  double actual_remaining = 
	-0.0025 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 141705.0971 * parameters.total_wait_locks 
	- 0.003 * parameters.mean_wait_of_all 
	- 45310738.2955 * parameters.cpu_usage 
	+ 0.0036 * parameters.avg_work_of_same_past_second 
	+ 0.0466 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	- 71118067.9205;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM73(work_wait &parameters) {
  double actual_remaining = 
	1940.0862 * parameters.work_so_far 
	- 0.0903 * parameters.wait_so_far 
	- 16201.162 * parameters.num_locks_so_far 
	+ 7766.5442 * parameters.total_wait_locks 
	- 4177065.5639 * parameters.cpu_usage 
	+ 0.4332 * parameters.avg_work_of_same_past_second 
	- 0.3888 * parameters.avg_wait_of_same_past_second 
	+ 0.2487 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	- 10329807.6778;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM74(work_wait &parameters) {
  double actual_remaining = 
	35.1526 * parameters.work_so_far 
	- 0.1136 * parameters.wait_so_far 
	- 16201.162 * parameters.num_locks_so_far 
	+ 884162.5271 * parameters.total_wait_locks 
	- 3.623 * parameters.mean_wait_of_all 
	- 342916622.0213 * parameters.cpu_usage 
	+ 0.01 * parameters.avg_work_of_same_past_second 
	- 0.0042 * parameters.avg_wait_of_same_past_second 
	+ 0.0052 * parameters.avg_latency_of_same_last_20 
	- 0.0004 * parameters.max_latency_of_same_last_50 
	+ 629709929.2653;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM75(work_wait &parameters) {
  double actual_remaining = 
	0.0058 * parameters.work_so_far 
	- 0.1785 * parameters.wait_so_far 
	- 25201.4591 * parameters.num_locks_so_far 
	+ 296819.1789 * parameters.total_wait_locks 
	+ 0.0038 * parameters.mean_wait_of_all 
	- 145170017.8132 * parameters.cpu_usage 
	+ 0.3375 * parameters.avg_work_of_same_past_second 
	- 0.1599 * parameters.avg_wait_of_same_past_second 
	+ 0.1131 * parameters.avg_latency_of_same_last_20 
	- 0.0331 * parameters.max_latency_of_same_last_50 
	+ 260055142.1608;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM76(work_wait &parameters) {
  double actual_remaining = 
	0.0109 * parameters.work_so_far 
	- 0.1587 * parameters.wait_so_far 
	- 22255.3011 * parameters.num_locks_so_far 
	+ 2089.0328 * parameters.total_wait_locks 
	+ 0.006 * parameters.mean_wait_of_all 
	- 483944.9962 * parameters.cpu_usage 
	+ 0.006 * parameters.avg_work_of_same_past_second 
	- 0.0017 * parameters.avg_wait_of_same_past_second 
	+ 0.0031 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 252710724.9588;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM77(work_wait &parameters) {
  double actual_remaining = 
	0.0188 * parameters.work_so_far 
	- 0.255 * parameters.wait_so_far 
	- 22255.3011 * parameters.num_locks_so_far 
	+ 2089.0328 * parameters.total_wait_locks 
	+ 0.0097 * parameters.mean_wait_of_all 
	- 483944.9962 * parameters.cpu_usage 
	+ 0.006 * parameters.avg_work_of_same_past_second 
	- 0.0017 * parameters.avg_wait_of_same_past_second 
	+ 0.2021 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 227156895.6059;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM78(work_wait &parameters) {
  double actual_remaining = 
	0.0033 * parameters.work_so_far 
	- 0.0054 * parameters.wait_so_far 
	- 19345.5066 * parameters.num_locks_so_far 
	+ 5115.5481 * parameters.total_wait_locks 
	+ 0.0017 * parameters.mean_wait_of_all 
	- 483944.9962 * parameters.cpu_usage 
	+ 0.0101 * parameters.avg_work_of_same_past_second 
	- 0.0056 * parameters.avg_wait_of_same_past_second 
	+ 0.0055 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 100601604.8;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM79(work_wait &parameters) {
  double actual_remaining = 
	0.0033 * parameters.work_so_far 
	- 0.0124 * parameters.wait_so_far 
	- 19345.5066 * parameters.num_locks_so_far 
	+ 16120.5096 * parameters.total_wait_locks 
	+ 0.0017 * parameters.mean_wait_of_all 
	- 483944.9962 * parameters.cpu_usage 
	+ 0.0329 * parameters.avg_work_of_same_past_second 
	+ 0.1291 * parameters.avg_wait_of_same_past_second 
	- 0.4343 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 291459821.2687;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM80(work_wait &parameters) {
  double actual_remaining = 
	0.0033 * parameters.work_so_far 
	- 0.0124 * parameters.wait_so_far 
	- 19345.5066 * parameters.num_locks_so_far 
	+ 16120.5096 * parameters.total_wait_locks 
	+ 0.0017 * parameters.mean_wait_of_all 
	- 483944.9962 * parameters.cpu_usage 
	+ 0.0329 * parameters.avg_work_of_same_past_second 
	+ 0.1291 * parameters.avg_wait_of_same_past_second 
	- 0.416 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 269722246.0276;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM81(work_wait &parameters) {
  double actual_remaining = 
	-2792.7553 * parameters.work_so_far 
	- 0.2612 * parameters.wait_so_far 
	- 19345.5066 * parameters.num_locks_so_far 
	+ 16120.5096 * parameters.total_wait_locks 
	+ 0.0017 * parameters.mean_wait_of_all 
	- 483944.9962 * parameters.cpu_usage 
	+ 0.0329 * parameters.avg_work_of_same_past_second 
	+ 0.1291 * parameters.avg_wait_of_same_past_second 
	+ 0.0047 * parameters.avg_latency_of_same_last_20 
	- 0.1523 * parameters.max_latency_of_same_last_50 
	+ 615115861.7388;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM82(work_wait &parameters) {
  double actual_remaining = 
	-2792.7553 * parameters.work_so_far 
	- 0.2612 * parameters.wait_so_far 
	- 19345.5066 * parameters.num_locks_so_far 
	+ 16120.5096 * parameters.total_wait_locks 
	+ 0.0017 * parameters.mean_wait_of_all 
	- 483944.9962 * parameters.cpu_usage 
	+ 0.0329 * parameters.avg_work_of_same_past_second 
	+ 0.1291 * parameters.avg_wait_of_same_past_second 
	+ 0.0047 * parameters.avg_latency_of_same_last_20 
	- 0.1523 * parameters.max_latency_of_same_last_50 
	+ 595551161.5589;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM83(work_wait &parameters) {
  double actual_remaining = 
	0.0033 * parameters.work_so_far 
	- 0.0124 * parameters.wait_so_far 
	- 19345.5066 * parameters.num_locks_so_far 
	+ 16120.5096 * parameters.total_wait_locks 
	+ 0.0017 * parameters.mean_wait_of_all 
	- 483944.9962 * parameters.cpu_usage 
	+ 0.0329 * parameters.avg_work_of_same_past_second 
	+ 0.0948 * parameters.avg_wait_of_same_past_second 
	+ 0.0047 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 103812888.0636;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM84(work_wait &parameters) {
  double actual_remaining = 
	0.0033 * parameters.work_so_far 
	- 0.1595 * parameters.wait_so_far 
	- 19345.5066 * parameters.num_locks_so_far 
	+ 16120.5096 * parameters.total_wait_locks 
	- 0.3333 * parameters.mean_wait_of_all 
	- 483944.9962 * parameters.cpu_usage 
	+ 0.0329 * parameters.avg_work_of_same_past_second 
	- 0.0196 * parameters.avg_wait_of_same_past_second 
	+ 0.0047 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 221355536.113;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM85(work_wait &parameters) {
  double actual_remaining = 
	-379.3496 * parameters.work_so_far 
	- 0.1364 * parameters.wait_so_far 
	- 19345.5066 * parameters.num_locks_so_far 
	+ 457317.9686 * parameters.total_wait_locks 
	- 1.2128 * parameters.mean_wait_of_all 
	- 483944.9962 * parameters.cpu_usage 
	+ 0.0246 * parameters.avg_work_of_same_past_second 
	- 0.2077 * parameters.avg_wait_of_same_past_second 
	+ 0.1203 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 203569138.2219;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM86(work_wait &parameters) {
  double actual_remaining = 
	-11.5229 * parameters.work_so_far 
	- 0.8741 * parameters.wait_so_far 
	- 19345.5066 * parameters.num_locks_so_far 
	+ 679979.5326 * parameters.total_wait_locks 
	- 3.9032 * parameters.mean_wait_of_all 
	- 483944.9962 * parameters.cpu_usage 
	+ 1.6931 * parameters.avg_work_of_same_past_second 
	- 1.1699 * parameters.avg_wait_of_same_past_second 
	+ 0.0047 * parameters.avg_latency_of_same_last_20 
	+ 0.7285 * parameters.max_latency_of_same_last_50 
	+ 179440288.4689;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM87(work_wait &parameters) {
  double actual_remaining = 
	-0.253 * parameters.work_so_far 
	- 0.0154 * parameters.wait_so_far 
	- 19345.5066 * parameters.num_locks_so_far 
	+ 679979.5326 * parameters.total_wait_locks 
	- 3.9032 * parameters.mean_wait_of_all 
	- 483944.9962 * parameters.cpu_usage 
	+ 1.1961 * parameters.avg_work_of_same_past_second 
	- 0.8118 * parameters.avg_wait_of_same_past_second 
	+ 0.2141 * parameters.avg_latency_of_same_last_20 
	+ 0.1145 * parameters.max_latency_of_same_last_50 
	+ 103558047.0851;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM88(work_wait &parameters) {
  double actual_remaining = 
	-0.6029 * parameters.work_so_far 
	- 0.0154 * parameters.wait_so_far 
	- 19345.5066 * parameters.num_locks_so_far 
	+ 679979.5326 * parameters.total_wait_locks 
	- 3.9032 * parameters.mean_wait_of_all 
	- 483944.9962 * parameters.cpu_usage 
	+ 1.1961 * parameters.avg_work_of_same_past_second 
	- 0.8118 * parameters.avg_wait_of_same_past_second 
	+ 0.2141 * parameters.avg_latency_of_same_last_20 
	+ 0.1145 * parameters.max_latency_of_same_last_50 
	+ 174601604.45;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM89(work_wait &parameters) {
  double actual_remaining = 
	0.0033 * parameters.work_so_far 
	- 0.0154 * parameters.wait_so_far 
	- 19345.5066 * parameters.num_locks_so_far 
	+ 825317.7722 * parameters.total_wait_locks 
	- 1.4147 * parameters.mean_wait_of_all 
	- 483944.9962 * parameters.cpu_usage 
	+ 0.1393 * parameters.avg_work_of_same_past_second 
	- 0.0819 * parameters.avg_wait_of_same_past_second 
	+ 0.0047 * parameters.avg_latency_of_same_last_20 
	+ 0.0113 * parameters.max_latency_of_same_last_50 
	+ 11654115.4999;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM90(work_wait &parameters) {
  double actual_remaining = 
	0.0033 * parameters.work_so_far 
	- 0.0098 * parameters.wait_so_far 
	- 19345.5066 * parameters.num_locks_so_far 
	+ 10462.5357 * parameters.total_wait_locks 
	+ 0.0017 * parameters.mean_wait_of_all 
	- 483944.9962 * parameters.cpu_usage 
	+ 0.0198 * parameters.avg_work_of_same_past_second 
	- 0.0123 * parameters.avg_wait_of_same_past_second 
	+ 0.1662 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 18260401.0296;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM91(work_wait &parameters) {
  double actual_remaining = 
	1.3837 * parameters.work_so_far 
	- 0.7125 * parameters.wait_so_far 
	- 66314.7245 * parameters.num_locks_so_far 
	- 2580214.7731 * parameters.total_wait_locks 
	+ 23.32 * parameters.mean_wait_of_all 
	- 611915715.4989 * parameters.cpu_usage 
	+ 0.0019 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.006 * parameters.avg_latency_of_same_last_20 
	- 0.0699 * parameters.max_latency_of_same_last_50 
	- 799727619.1363;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM92(work_wait &parameters) {
  double actual_remaining = 
	-0.1958 * parameters.work_so_far 
	- 0.024 * parameters.wait_so_far 
	- 66314.7245 * parameters.num_locks_so_far 
	- 503646.6552 * parameters.total_wait_locks 
	+ 4.3951 * parameters.mean_wait_of_all 
	- 18832229.8323 * parameters.cpu_usage 
	+ 0.0019 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0118 * parameters.avg_latency_of_same_last_20 
	- 0.0255 * parameters.max_latency_of_same_last_50 
	+ 201611898.4195;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM93(work_wait &parameters) {
  double actual_remaining = 
	-0.1958 * parameters.work_so_far 
	- 0.024 * parameters.wait_so_far 
	- 66314.7245 * parameters.num_locks_so_far 
	- 405509.6453 * parameters.total_wait_locks 
	+ 3.5123 * parameters.mean_wait_of_all 
	- 18832229.8323 * parameters.cpu_usage 
	+ 0.0019 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0118 * parameters.avg_latency_of_same_last_20 
	- 0.0187 * parameters.max_latency_of_same_last_50 
	+ 159304957.4095;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM94(work_wait &parameters) {
  double actual_remaining = 
	-5.2682 * parameters.work_so_far 
	- 0.024 * parameters.wait_so_far 
	- 66314.7245 * parameters.num_locks_so_far 
	+ 277754.1025 * parameters.total_wait_locks 
	- 3.528 * parameters.mean_wait_of_all 
	- 18832229.8323 * parameters.cpu_usage 
	+ 0.0019 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0118 * parameters.avg_latency_of_same_last_20 
	- 2.3635 * parameters.max_latency_of_same_last_50 
	+ 5851227708.1711;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM95(work_wait &parameters) {
  double actual_remaining = 
	-8.6094 * parameters.work_so_far 
	- 0.024 * parameters.wait_so_far 
	- 66314.7245 * parameters.num_locks_so_far 
	+ 277754.1025 * parameters.total_wait_locks 
	- 3.528 * parameters.mean_wait_of_all 
	- 18832229.8323 * parameters.cpu_usage 
	+ 0.0019 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0118 * parameters.avg_latency_of_same_last_20 
	- 0.0883 * parameters.max_latency_of_same_last_50 
	+ 1332542115.2996;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM96(work_wait &parameters) {
  double actual_remaining = 
	-0.3677 * parameters.work_so_far 
	- 0.024 * parameters.wait_so_far 
	- 66314.7245 * parameters.num_locks_so_far 
	- 28634.3316 * parameters.total_wait_locks 
	- 0.299 * parameters.mean_wait_of_all 
	- 18832229.8323 * parameters.cpu_usage 
	+ 0.0019 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0118 * parameters.avg_latency_of_same_last_20 
	- 0.1765 * parameters.max_latency_of_same_last_50 
	+ 984274884.8561;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM97(work_wait &parameters) {
  double actual_remaining = 
	-0.1534 * parameters.wait_so_far 
	- 5641449.6002 * parameters.num_locks_so_far 
	- 902130.4618 * parameters.total_wait_locks 
	+ 7.4653 * parameters.mean_wait_of_all 
	- 474737408.5062 * parameters.cpu_usage 
	+ 0.0019 * parameters.avg_work_of_same_past_second 
	+ 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.1901 * parameters.avg_latency_of_same_last_20 
	- 0.0234 * parameters.max_latency_of_same_last_50 
	+ 189170967.4685;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
tpcc_estimate(work_wait &parameters){

  if (parameters.num_locks_so_far <= 3) {

    if (parameters.mean_wait_of_all <= 130459000) {

      if (parameters.work_so_far <= 18233.5) {
        return tpcc_LM1(parameters);
      } else {

        if (parameters.avg_work_of_same_past_second <= 19449350) {

          if (parameters.mean_wait_of_all <= 97634500) {

            if (parameters.avg_work_of_same_past_second <= 18009300) {

              if (parameters.mean_wait_of_all <= 92180450) {

                if (parameters.total_wait_locks <= 191.5) {

                  if (parameters.mean_wait_of_all <= 87993900) {

                    if (parameters.avg_work_of_same_past_second <= 7908880) {

                      if (parameters.avg_work_of_same_past_second <= 6156325) {

                        if (parameters.avg_latency_of_same_last_20 <= 56187600) {
                          return tpcc_LM2(parameters);
                        } else {

                          if (parameters.total_wait_locks <= 66) {
                            return tpcc_LM3(parameters);
                          } else {
                            return tpcc_LM4(parameters);
                          }
                        }
                      } else {

                        if (parameters.mean_wait_of_all <= 84938700) {

                          if (parameters.wait_so_far <= 147629199.5) {
                            return tpcc_LM5(parameters);
                          } else {
                            return tpcc_LM6(parameters);
                          }
                        } else {
                          return tpcc_LM7(parameters);
                        }
                      }
                    } else {

                      if (parameters.avg_work_of_same_past_second <= 16239100) {
                        return tpcc_LM8(parameters);
                      } else {
                        return tpcc_LM9(parameters);
                      }
                    }
                  } else {

                    if (parameters.avg_work_of_same_past_second <= 7712630) {

                      if (parameters.total_wait_locks <= 182.5) {
                        return tpcc_LM10(parameters);
                      } else {
                        return tpcc_LM11(parameters);
                      }
                    } else {

                      if (parameters.wait_so_far <= 255659903) {

                        if (parameters.total_wait_locks <= 124) {

                          if (parameters.avg_latency_of_same_last_20 <= 101535600) {
                            return tpcc_LM12(parameters);
                          } else {
                            return tpcc_LM13(parameters);
                          }
                        } else {

                          if (parameters.avg_latency_of_same_last_20 <= 311152000) {

                            if (parameters.work_so_far <= 38122) {

                              if (parameters.max_latency_of_same_last_50 <= 330699000) {
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
                        return tpcc_LM18(parameters);
                      }
                    }
                  }
                } else {

                  if (parameters.wait_so_far <= 137350932) {
                    return tpcc_LM19(parameters);
                  } else {

                    if (parameters.wait_so_far <= 224803533) {
                      return tpcc_LM20(parameters);
                    } else {
                      return tpcc_LM21(parameters);
                    }
                  }
                }
              } else {
                return tpcc_LM22(parameters);
              }
            } else {

              if (parameters.avg_wait_of_same_past_second <= 207343000) {
                return tpcc_LM23(parameters);
              } else {

                if (parameters.avg_wait_of_same_past_second <= 382791500) {

                  if (parameters.mean_wait_of_all <= 89161100) {
                    return tpcc_LM24(parameters);
                  } else {

                    if (parameters.work_so_far <= 39548) {
                      return tpcc_LM25(parameters);
                    } else {

                      if (parameters.mean_wait_of_all <= 90555950) {
                        return tpcc_LM26(parameters);
                      } else {
                        return tpcc_LM27(parameters);
                      }
                    }
                  }
                } else {

                  if (parameters.avg_work_of_same_past_second <= 19052850) {
                    return tpcc_LM28(parameters);
                  } else {

                    if (parameters.avg_work_of_same_past_second <= 19091700) {
                      return tpcc_LM29(parameters);
                    } else {
                      return tpcc_LM30(parameters);
                    }
                  }
                }
              }
            }
          } else {

            if (parameters.avg_wait_of_same_past_second <= 61140800) {

              if (parameters.mean_wait_of_all <= 105268000) {
                return tpcc_LM31(parameters);
              } else {
                return tpcc_LM32(parameters);
              }
            } else {

              if (parameters.total_wait_locks <= 345.5) {
                return tpcc_LM33(parameters);
              } else {
                return tpcc_LM34(parameters);
              }
            }
          }
        } else {

          if (parameters.mean_wait_of_all <= 106485500) {

            if (parameters.wait_so_far <= 197539345) {
              return tpcc_LM35(parameters);
            } else {

              if (parameters.mean_wait_of_all <= 87967900) {

                if (parameters.avg_work_of_same_past_second <= 23285350) {
                  return tpcc_LM36(parameters);
                } else {

                  if (parameters.wait_so_far <= 378738762.5) {

                    if (parameters.avg_wait_of_same_past_second <= 447409500) {

                      if (parameters.avg_latency_of_same_last_20 <= 442141000) {
                        return tpcc_LM37(parameters);
                      } else {

                        if (parameters.mean_wait_of_all <= 81195350) {
                          return tpcc_LM38(parameters);
                        } else {
                          return tpcc_LM39(parameters);
                        }
                      }
                    } else {
                      return tpcc_LM40(parameters);
                    }
                  } else {
                    return tpcc_LM41(parameters);
                  }
                }
              } else {
                return tpcc_LM42(parameters);
              }
            }
          } else {

            if (parameters.cpu_usage <= 0.968) {
              return tpcc_LM43(parameters);
            } else {

              if (parameters.total_wait_locks <= 363.5) {
                return tpcc_LM44(parameters);
              } else {

                if (parameters.mean_wait_of_all <= 112996500) {

                  if (parameters.wait_so_far <= 42023256.5) {
                    return tpcc_LM45(parameters);
                  } else {
                    return tpcc_LM46(parameters);
                  }
                } else {

                  if (parameters.max_latency_of_same_last_50 <= 1346290000) {

                    if (parameters.avg_work_of_same_past_second <= 31190350) {

                      if (parameters.total_wait_locks <= 387.5) {

                        if (parameters.mean_wait_of_all <= 116092500) {

                          if (parameters.wait_so_far <= 43155078) {

                            if (parameters.work_so_far <= 40431.5) {

                              if (parameters.max_latency_of_same_last_50 <= 1174865000) {
                                return tpcc_LM47(parameters);
                              } else {
                                return tpcc_LM48(parameters);
                              }
                            } else {
                              return tpcc_LM49(parameters);
                            }
                          } else {

                            if (parameters.mean_wait_of_all <= 114345000) {

                              if (parameters.mean_wait_of_all <= 114159500) {
                                return tpcc_LM50(parameters);
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

                      if (parameters.mean_wait_of_all <= 119512000) {

                        if (parameters.avg_wait_of_same_past_second <= 389428500) {
                          return tpcc_LM55(parameters);
                        } else {
                          return tpcc_LM56(parameters);
                        }
                      } else {
                        return tpcc_LM57(parameters);
                      }
                    }
                  } else {
                    return tpcc_LM58(parameters);
                  }
                }
              }
            }
          }
        }
      }
    } else {

      if (parameters.mean_wait_of_all <= 164539000) {

        if (parameters.avg_latency_of_same_last_20 <= 349319000) {

          if (parameters.max_latency_of_same_last_50 <= 1236335000) {
            return tpcc_LM59(parameters);
          } else {

            if (parameters.avg_wait_of_same_past_second <= 482827500) {

              if (parameters.avg_work_of_same_past_second <= 27681050) {

                if (parameters.avg_work_of_same_past_second <= 26743500) {
                  return tpcc_LM60(parameters);
                } else {
                  return tpcc_LM61(parameters);
                }
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

        if (parameters.total_wait_locks <= 721.5) {
          return tpcc_LM65(parameters);
        } else {

          if (parameters.avg_wait_of_same_past_second <= 453160000) {

            if (parameters.mean_wait_of_all <= 168991500) {
              return tpcc_LM66(parameters);
            } else {

              if (parameters.mean_wait_of_all <= 169439000) {

                if (parameters.cpu_usage <= 0.882) {

                  if (parameters.work_so_far <= 46599) {
                    return tpcc_LM67(parameters);
                  } else {
                    return tpcc_LM68(parameters);
                  }
                } else {
                  return tpcc_LM69(parameters);
                }
              } else {

                if (parameters.max_latency_of_same_last_50 <= 1143580000) {
                  return tpcc_LM70(parameters);
                } else {
                  return tpcc_LM71(parameters);
                }
              }
            }
          } else {
            return tpcc_LM72(parameters);
          }
        }
      }
    }
  } else {

    if (parameters.total_wait_locks <= 437.5) {

      if (parameters.work_so_far <= 41776) {

        if (parameters.total_wait_locks <= 169.5) {
          return tpcc_LM73(parameters);
        } else {
          return tpcc_LM74(parameters);
        }
      } else {

        if (parameters.wait_so_far <= 276337370.5) {

          if (parameters.avg_work_of_same_past_second <= 161019000) {
            return tpcc_LM75(parameters);
          } else {

            if (parameters.work_so_far <= 82879) {
              return tpcc_LM76(parameters);
            } else {
              return tpcc_LM77(parameters);
            }
          }
        } else {

          if (parameters.avg_latency_of_same_last_20 <= 294101500) {
            return tpcc_LM78(parameters);
          } else {

            if (parameters.wait_so_far <= 622640183.5) {

              if (parameters.total_wait_locks <= 213.5) {

                if (parameters.avg_work_of_same_past_second <= 141337500) {

                  if (parameters.work_so_far <= 61943.5) {

                    if (parameters.avg_latency_of_same_last_20 <= 378580500) {

                      if (parameters.avg_latency_of_same_last_20 <= 322578500) {
                        return tpcc_LM79(parameters);
                      } else {
                        return tpcc_LM80(parameters);
                      }
                    } else {

                      if (parameters.max_latency_of_same_last_50 <= 1133765000) {
                        return tpcc_LM81(parameters);
                      } else {
                        return tpcc_LM82(parameters);
                      }
                    }
                  } else {
                    return tpcc_LM83(parameters);
                  }
                } else {
                  return tpcc_LM84(parameters);
                }
              } else {

                if (parameters.work_so_far <= 293152) {
                  return tpcc_LM85(parameters);
                } else {

                  if (parameters.mean_wait_of_all <= 93008450) {

                    if (parameters.avg_latency_of_same_last_20 <= 351019500) {
                      return tpcc_LM86(parameters);
                    } else {

                      if (parameters.avg_latency_of_same_last_20 <= 511151500) {
                        return tpcc_LM87(parameters);
                      } else {
                        return tpcc_LM88(parameters);
                      }
                    }
                  } else {
                    return tpcc_LM89(parameters);
                  }
                }
              }
            } else {
              return tpcc_LM90(parameters);
            }
          }
        }
      }
    } else {

      if (parameters.wait_so_far <= 123401387) {

        if (parameters.avg_latency_of_same_last_20 <= 635629500) {
          return tpcc_LM91(parameters);
        } else {

          if (parameters.max_latency_of_same_last_50 <= 2018765000) {

            if (parameters.max_latency_of_same_last_50 <= 1602850000) {
              return tpcc_LM92(parameters);
            } else {
              return tpcc_LM93(parameters);
            }
          } else {

            if (parameters.max_latency_of_same_last_50 <= 2122975000) {

              if (parameters.max_latency_of_same_last_50 <= 2100160000) {
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
        return tpcc_LM97(parameters);
      }
    }
  }
}