#include "my_global.h"
#include "m5p.h"
#include "trace_tool.h"

static
double
new_order_LM1(work_wait &parameters) {
  double actual_remaining = 
	2.8437 * parameters.work_so_far 
	- 3643793.2241 * parameters.num_locks_so_far 
	+ 940907.2654 * parameters.total_wait_locks 
	- 171141919.0353 * parameters.cpu_usage 
	- 0.1365 * parameters.avg_latency_of_same_past_second 
	+ 251840048.3158;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM2(work_wait &parameters) {
  double actual_remaining = 
	0.9843 * parameters.work_so_far 
	- 2207041.1551 * parameters.num_locks_so_far 
	+ 1244888.7367 * parameters.total_wait_locks 
	- 236888878.213 * parameters.cpu_usage 
	- 0.3354 * parameters.avg_latency_of_same_past_second 
	+ 385072363.5525;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM3(work_wait &parameters) {
  double actual_remaining = 
	45.432 * parameters.work_so_far 
	- 23071554.7163 * parameters.num_locks_so_far 
	+ 2380.5517 * parameters.total_wait_locks 
	- 612442.6021 * parameters.cpu_usage 
	+ 355930356.7386;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM4(work_wait &parameters) {
  double actual_remaining = 
	0.2428 * parameters.work_so_far 
	- 527233.6671 * parameters.num_locks_so_far 
	+ 197792.7021 * parameters.total_wait_locks 
	- 612442.6021 * parameters.cpu_usage 
	+ 448911172.3472;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM5(work_wait &parameters) {
  double actual_remaining = 
	9.0656 * parameters.work_so_far 
	- 8576308.4237 * parameters.num_locks_so_far 
	- 91576.6082 * parameters.total_wait_locks 
	+ 160272664.1098 * parameters.cpu_usage 
	+ 84228431.5207;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM6(work_wait &parameters) {
  double actual_remaining = 
	0.522 * parameters.work_so_far 
	- 2241729.5387 * parameters.num_locks_so_far 
	+ 382286.0568 * parameters.total_wait_locks 
	- 612442.6021 * parameters.cpu_usage 
	+ 350898303.1036;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM7(work_wait &parameters) {
  double actual_remaining = 
	1.348 * parameters.work_so_far 
	- 2469425.9093 * parameters.num_locks_so_far 
	+ 398398.5814 * parameters.total_wait_locks 
	+ 784657681.3152 * parameters.cpu_usage 
	- 0.2575 * parameters.avg_latency_of_same_past_second 
	- 346983121.469;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM8(work_wait &parameters) {
  double actual_remaining = 
	1.1578 * parameters.work_so_far 
	- 2469425.9093 * parameters.num_locks_so_far 
	+ 398398.5814 * parameters.total_wait_locks 
	- 612442.6021 * parameters.cpu_usage 
	- 0.164 * parameters.avg_latency_of_same_past_second 
	+ 234859243.8582;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM9(work_wait &parameters) {
  double actual_remaining = 
	1.7919 * parameters.work_so_far 
	- 12600213.9424 * parameters.num_locks_so_far 
	+ 685585.643 * parameters.total_wait_locks 
	- 909402475.412 * parameters.cpu_usage 
	- 0.0486 * parameters.avg_latency_of_same_past_second 
	+ 1423497277.7259;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM10(work_wait &parameters) {
  double actual_remaining = 
	2.0418 * parameters.work_so_far 
	- 11881504.7297 * parameters.num_locks_so_far 
	+ 685585.643 * parameters.total_wait_locks 
	- 640131354.5795 * parameters.cpu_usage 
	- 0.0486 * parameters.avg_latency_of_same_past_second 
	+ 1104656812.909;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM11(work_wait &parameters) {
  double actual_remaining = 
	2.4694 * parameters.work_so_far 
	- 13820474.3383 * parameters.num_locks_so_far 
	+ 685585.643 * parameters.total_wait_locks 
	- 612442.6021 * parameters.cpu_usage 
	- 0.0486 * parameters.avg_latency_of_same_past_second 
	+ 601912829.7152;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM12(work_wait &parameters) {
  double actual_remaining = 
	0.9896 * parameters.work_so_far 
	- 2508001.7162 * parameters.num_locks_so_far 
	+ 482907.3562 * parameters.total_wait_locks 
	- 612442.6021 * parameters.cpu_usage 
	- 0.0976 * parameters.avg_latency_of_same_past_second 
	+ 199672030.6059;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM13(work_wait &parameters) {
  double actual_remaining = 
	1.1651 * parameters.work_so_far 
	- 1185254.0106 * parameters.num_locks_so_far 
	+ 2380.5517 * parameters.total_wait_locks 
	- 612442.6021 * parameters.cpu_usage 
	+ 0.1642 * parameters.avg_latency_of_same_past_second 
	+ 120450119.5511;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM14(work_wait &parameters) {
  double actual_remaining = 
	0.6295 * parameters.work_so_far 
	- 938393.0756 * parameters.num_locks_so_far 
	+ 372002.5445 * parameters.total_wait_locks 
	- 612442.6021 * parameters.cpu_usage 
	+ 488178704.489;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM15(work_wait &parameters) {
  double actual_remaining = 
	0.7919 * parameters.work_so_far 
	- 469195.8662 * parameters.num_locks_so_far 
	- 13330157.022 * parameters.num_of_wait_locks 
	+ 4616.204 * parameters.total_wait_locks 
	- 612442.6021 * parameters.cpu_usage 
	+ 330249514.4771;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
new_order_estimate(work_wait &parameters){

  if (parameters.total_wait_locks <= 97.5) {

    if (parameters.work_so_far <= 49320551.5) {
      return new_order_LM1(parameters);
    } else {
      return new_order_LM2(parameters);
    }
  } else {

    if (parameters.work_so_far <= 112014222.5) {

      if (parameters.num_locks_so_far <= 11.5) {

        if (parameters.work_so_far <= 5432358.5) {
          return new_order_LM3(parameters);
        } else {
          return new_order_LM4(parameters);
        }
      } else {

        if (parameters.work_so_far <= 28758327.5) {
          return new_order_LM5(parameters);
        } else {

          if (parameters.num_locks_so_far <= 21.5) {
            return new_order_LM6(parameters);
          } else {

            if (parameters.total_wait_locks <= 207) {

              if (parameters.cpu_usage <= 0.99) {

                if (parameters.avg_latency_of_same_past_second <= 275269000) {

                  if (parameters.avg_latency_of_same_past_second <= 72686900) {
                    return new_order_LM7(parameters);
                  } else {
                    return new_order_LM8(parameters);
                  }
                } else {

                  if (parameters.cpu_usage <= 0.985) {

                    if (parameters.cpu_usage <= 0.936) {
                      return new_order_LM9(parameters);
                    } else {
                      return new_order_LM10(parameters);
                    }
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
      }
    } else {

      if (parameters.num_locks_so_far <= 16.5) {
        return new_order_LM14(parameters);
      } else {
        return new_order_LM15(parameters);
      }
    }
  }
}
static
double
payment_LM1(work_wait &parameters) {
  double actual_remaining = 
	1.2746 * parameters.work_so_far 
	- 1758415.037 * parameters.num_locks_so_far 
	+ 61848.5509 * parameters.total_wait_locks 
	+ 36876656.4568;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
payment_estimate(work_wait &parameters){
  return payment_LM1(parameters);
}
static
double
delivery_LM1(work_wait &parameters) {
  double actual_remaining = 
	1.1009 * parameters.work_so_far 
	- 10512127.5348 * parameters.num_locks_so_far 
	+ 0.1479 * parameters.avg_latency_of_same_past_second 
	+ 781986576.9778;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
delivery_estimate(work_wait &parameters){
  return delivery_LM1(parameters);
}
static
double
tpcc_LM1(work_wait &parameters) {
  double actual_remaining = 
	3.4421 * parameters.work_so_far 
	- 3554285.2715 * parameters.num_locks_so_far 
	- 127444.9462 * parameters.num_of_wait_locks 
	+ 446147.5541 * parameters.total_wait_locks 
	- 177048462.6306 * parameters.cpu_usage 
	+ 0.113 * parameters.avg_latency_of_same_past_second 
	+ 234137970.4151;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM2(work_wait &parameters) {
  double actual_remaining = 
	-4.2812 * parameters.work_so_far 
	- 4425755.5551 * parameters.num_locks_so_far 
	- 127444.9462 * parameters.num_of_wait_locks 
	- 1855819.1411 * parameters.total_wait_locks 
	- 273354923.7046 * parameters.cpu_usage 
	+ 1.9317 * parameters.avg_latency_of_same_past_second 
	+ 654316232.4687;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM3(work_wait &parameters) {
  double actual_remaining = 
	1.8403 * parameters.work_so_far 
	- 901144.9076 * parameters.num_locks_so_far 
	- 127444.9462 * parameters.num_of_wait_locks 
	- 1170607.2766 * parameters.total_wait_locks 
	- 398356891.1619 * parameters.cpu_usage 
	+ 1.1683 * parameters.avg_latency_of_same_past_second 
	+ 408541865.1711;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM4(work_wait &parameters) {
  double actual_remaining = 
	2.4581 * parameters.work_so_far 
	- 901144.9076 * parameters.num_locks_so_far 
	- 127444.9462 * parameters.num_of_wait_locks 
	- 1170607.2766 * parameters.total_wait_locks 
	- 605451815.8435 * parameters.cpu_usage 
	+ 1.1683 * parameters.avg_latency_of_same_past_second 
	+ 583734017.3363;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM5(work_wait &parameters) {
  double actual_remaining = 
	2.4581 * parameters.work_so_far 
	- 901144.9076 * parameters.num_locks_so_far 
	- 127444.9462 * parameters.num_of_wait_locks 
	- 1170607.2766 * parameters.total_wait_locks 
	- 584977294.6937 * parameters.cpu_usage 
	+ 1.1683 * parameters.avg_latency_of_same_past_second 
	+ 561553818.0899;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM6(work_wait &parameters) {
  double actual_remaining = 
	0.3303 * parameters.work_so_far 
	- 901144.9076 * parameters.num_locks_so_far 
	- 127444.9462 * parameters.num_of_wait_locks 
	- 119949.0843 * parameters.total_wait_locks 
	- 139587363.6302 * parameters.cpu_usage 
	- 0.1645 * parameters.avg_latency_of_same_past_second 
	+ 262956144.5815;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM7(work_wait &parameters) {
  double actual_remaining = 
	0.3303 * parameters.work_so_far 
	- 835947.27 * parameters.num_locks_so_far 
	- 127444.9462 * parameters.num_of_wait_locks 
	- 99067.3071 * parameters.total_wait_locks 
	- 65933134.5432 * parameters.cpu_usage 
	- 0.0023 * parameters.avg_latency_of_same_past_second 
	+ 152274561.3343;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM8(work_wait &parameters) {
  double actual_remaining = 
	2.8069 * parameters.work_so_far 
	- 2659122.5334 * parameters.num_locks_so_far 
	- 127444.9462 * parameters.num_of_wait_locks 
	+ 1602921.991 * parameters.total_wait_locks 
	- 10511122.7576 * parameters.cpu_usage 
	- 0.2265 * parameters.avg_latency_of_same_past_second 
	+ 45601510.7046;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM9(work_wait &parameters) {
  double actual_remaining = 
	1.4409 * parameters.work_so_far 
	- 178526.4311 * parameters.num_locks_so_far 
	- 127444.9462 * parameters.num_of_wait_locks 
	+ 790445.3695 * parameters.total_wait_locks 
	- 222927243.1419 * parameters.cpu_usage 
	- 0.0008 * parameters.avg_latency_of_same_past_second 
	+ 261235333.1282;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM10(work_wait &parameters) {
  double actual_remaining = 
	0.1647 * parameters.work_so_far 
	- 587296.6211 * parameters.num_locks_so_far 
	- 127444.9462 * parameters.num_of_wait_locks 
	+ 2619016.1619 * parameters.total_wait_locks 
	- 128369471.0328 * parameters.cpu_usage 
	- 6.803 * parameters.avg_latency_of_same_past_second 
	+ 506899089.0201;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM11(work_wait &parameters) {
  double actual_remaining = 
	-0.2676 * parameters.work_so_far 
	- 587296.6211 * parameters.num_locks_so_far 
	- 127444.9462 * parameters.num_of_wait_locks 
	- 1361615.2707 * parameters.total_wait_locks 
	- 128369471.0328 * parameters.cpu_usage 
	- 0.7412 * parameters.avg_latency_of_same_past_second 
	+ 641823242.7828;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM12(work_wait &parameters) {
  double actual_remaining = 
	-2.3436 * parameters.work_so_far 
	- 587296.6211 * parameters.num_locks_so_far 
	- 127444.9462 * parameters.num_of_wait_locks 
	+ 188066.7942 * parameters.total_wait_locks 
	- 128369471.0328 * parameters.cpu_usage 
	- 0.0008 * parameters.avg_latency_of_same_past_second 
	+ 686303323.8968;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM13(work_wait &parameters) {
  double actual_remaining = 
	0.1647 * parameters.work_so_far 
	- 2921618.3283 * parameters.num_locks_so_far 
	- 127444.9462 * parameters.num_of_wait_locks 
	+ 188066.7942 * parameters.total_wait_locks 
	- 164746882.3096 * parameters.cpu_usage 
	- 0.0008 * parameters.avg_latency_of_same_past_second 
	+ 436614403.1774;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM14(work_wait &parameters) {
  double actual_remaining = 
	1.0109 * parameters.work_so_far 
	- 1662393.014 * parameters.num_locks_so_far 
	- 127444.9462 * parameters.num_of_wait_locks 
	+ 699183.9933 * parameters.total_wait_locks 
	- 233247430.2587 * parameters.cpu_usage 
	- 0.0008 * parameters.avg_latency_of_same_past_second 
	+ 372330701.2241;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM15(work_wait &parameters) {
  double actual_remaining = 
	16.2139 * parameters.work_so_far 
	+ 616715.4762 * parameters.num_locks_so_far 
	+ 4493262.8539 * parameters.num_of_wait_locks 
	- 6132.6734 * parameters.total_wait_locks 
	- 666898.5575 * parameters.cpu_usage 
	+ 0.3568 * parameters.avg_latency_of_same_past_second 
	+ 82649715.1226;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM16(work_wait &parameters) {
  double actual_remaining = 
	1.0986 * parameters.work_so_far 
	+ 13033431.5094 * parameters.num_locks_so_far 
	+ 61189635.0232 * parameters.num_of_wait_locks 
	+ 354734.8865 * parameters.total_wait_locks 
	- 666898.5575 * parameters.cpu_usage 
	+ 0.0215 * parameters.avg_latency_of_same_past_second 
	+ 119456777.8874;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM17(work_wait &parameters) {
  double actual_remaining = 
	7.3275 * parameters.work_so_far 
	- 7608463.0458 * parameters.num_locks_so_far 
	- 103237.1821 * parameters.num_of_wait_locks 
	- 179924.3192 * parameters.total_wait_locks 
	- 666898.5575 * parameters.cpu_usage 
	+ 0.1697 * parameters.avg_latency_of_same_past_second 
	+ 200613807.935;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM18(work_wait &parameters) {
  double actual_remaining = 
	1.2489 * parameters.work_so_far 
	- 7785021.5598 * parameters.num_locks_so_far 
	- 31394177.8267 * parameters.num_of_wait_locks 
	- 207524.346 * parameters.total_wait_locks 
	- 666898.5575 * parameters.cpu_usage 
	+ 0.3044 * parameters.avg_latency_of_same_past_second 
	+ 492247074.2241;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM19(work_wait &parameters) {
  double actual_remaining = 
	1.0055 * parameters.work_so_far 
	- 5746669.1131 * parameters.num_locks_so_far 
	- 42237400.4145 * parameters.num_of_wait_locks 
	- 251788.8776 * parameters.total_wait_locks 
	- 666898.5575 * parameters.cpu_usage 
	+ 0.4131 * parameters.avg_latency_of_same_past_second 
	+ 477110697.6502;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
tpcc_estimate(work_wait &parameters){

  if (parameters.total_wait_locks <= 97.5) {

    if (parameters.work_so_far <= 49320551.5) {

      if (parameters.total_wait_locks <= 47.5) {

        if (parameters.work_so_far <= 27300541) {
          return tpcc_LM1(parameters);
        } else {

          if (parameters.num_locks_so_far <= 34.5) {

            if (parameters.avg_latency_of_same_past_second <= 58844400) {

              if (parameters.total_wait_locks <= 17.5) {
                return tpcc_LM2(parameters);
              } else {

                if (parameters.work_so_far <= 41244295.5) {
                  return tpcc_LM3(parameters);
                } else {

                  if (parameters.cpu_usage <= 0.828) {
                    return tpcc_LM4(parameters);
                  } else {
                    return tpcc_LM5(parameters);
                  }
                }
              }
            } else {
              return tpcc_LM6(parameters);
            }
          } else {
            return tpcc_LM7(parameters);
          }
        }
      } else {
        return tpcc_LM8(parameters);
      }
    } else {

      if (parameters.work_so_far <= 140254609) {

        if (parameters.total_wait_locks <= 65.5) {
          return tpcc_LM9(parameters);
        } else {

          if (parameters.cpu_usage <= 0.913) {

            if (parameters.avg_latency_of_same_past_second <= 56305250) {
              return tpcc_LM10(parameters);
            } else {

              if (parameters.cpu_usage <= 0.898) {
                return tpcc_LM11(parameters);
              } else {
                return tpcc_LM12(parameters);
              }
            }
          } else {
            return tpcc_LM13(parameters);
          }
        }
      } else {
        return tpcc_LM14(parameters);
      }
    }
  } else {

    if (parameters.work_so_far <= 231629953.5) {

      if (parameters.num_locks_so_far <= 11.5) {

        if (parameters.work_so_far <= 7617534) {
          return tpcc_LM15(parameters);
        } else {
          return tpcc_LM16(parameters);
        }
      } else {

        if (parameters.work_so_far <= 39703695.5) {
          return tpcc_LM17(parameters);
        } else {
          return tpcc_LM18(parameters);
        }
      }
    } else {
      return tpcc_LM19(parameters);
    }
  }
}