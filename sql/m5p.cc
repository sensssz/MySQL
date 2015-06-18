#include "my_global.h"
#include "m5p.h"
#include "trace_tool.h"

static
double
new_order_LM1(work_wait &parameters) {
  double actual_remaining = 
	1815.7606 * parameters.work_so_far 
	- 0.0031 * parameters.wait_so_far 
	+ 3553514.0469 * parameters.num_of_wait_locks 
	+ 259523.3551 * parameters.total_wait_locks 
	+ 0.1899 * parameters.mean_wait_of_all 
	- 91054938.1113 * parameters.cpu_usage 
	+ 0.0007 * parameters.avg_latency_of_same_past_second 
	+ 55802304.8526;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM2(work_wait &parameters) {
  double actual_remaining = 
	0.9742 * parameters.work_so_far 
	- 0.1796 * parameters.wait_so_far 
	+ 70108.7861 * parameters.num_of_wait_locks 
	+ 719336.4297 * parameters.total_wait_locks 
	- 0.0024 * parameters.mean_wait_of_all 
	- 107972650.711 * parameters.cpu_usage 
	- 0.0987 * parameters.avg_latency_of_same_past_second 
	+ 198850330.6388;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM3(work_wait &parameters) {
  double actual_remaining = 
	4910.0677 * parameters.work_so_far 
	- 0.0029 * parameters.wait_so_far 
	- 38774.7889 * parameters.num_locks_so_far 
	- 168771.3112 * parameters.num_of_wait_locks 
	+ 164062.9935 * parameters.total_wait_locks 
	- 0.5335 * parameters.mean_wait_of_all 
	+ 147047818.8738 * parameters.cpu_usage 
	+ 0.1168 * parameters.avg_latency_of_same_past_second 
	- 176471117.3036;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM4(work_wait &parameters) {
  double actual_remaining = 
	0.0373 * parameters.work_so_far 
	- 0.0047 * parameters.wait_so_far 
	- 38774.7889 * parameters.num_locks_so_far 
	- 465036.0189 * parameters.num_of_wait_locks 
	- 1218.3238 * parameters.total_wait_locks 
	+ 0.0092 * parameters.mean_wait_of_all 
	- 658112.0386 * parameters.cpu_usage 
	+ 0.0053 * parameters.avg_latency_of_same_past_second 
	+ 299872095.6183;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM5(work_wait &parameters) {
  double actual_remaining = 
	3.7932 * parameters.work_so_far 
	- 0.0047 * parameters.wait_so_far 
	- 38774.7889 * parameters.num_locks_so_far 
	- 1386598.9547 * parameters.num_of_wait_locks 
	- 3599577.9531 * parameters.total_wait_locks 
	- 0.2665 * parameters.mean_wait_of_all 
	+ 530095168.0944 * parameters.cpu_usage 
	+ 0.0732 * parameters.avg_latency_of_same_past_second 
	+ 1169785776.6204;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM6(work_wait &parameters) {
  double actual_remaining = 
	0.1254 * parameters.work_so_far 
	- 0.0047 * parameters.wait_so_far 
	- 38774.7889 * parameters.num_locks_so_far 
	- 1386598.9547 * parameters.num_of_wait_locks 
	+ 34300.9865 * parameters.total_wait_locks 
	- 0.2665 * parameters.mean_wait_of_all 
	+ 181922245.4662 * parameters.cpu_usage 
	+ 0.093 * parameters.avg_latency_of_same_past_second 
	+ 219636526.7685;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM7(work_wait &parameters) {
  double actual_remaining = 
	0.1254 * parameters.work_so_far 
	- 0.0047 * parameters.wait_so_far 
	- 38774.7889 * parameters.num_locks_so_far 
	- 1386598.9547 * parameters.num_of_wait_locks 
	+ 34300.9865 * parameters.total_wait_locks 
	- 0.2665 * parameters.mean_wait_of_all 
	+ 313767431.3579 * parameters.cpu_usage 
	- 1.3419 * parameters.avg_latency_of_same_past_second 
	+ 1252538229.5656;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM8(work_wait &parameters) {
  double actual_remaining = 
	0.1254 * parameters.work_so_far 
	- 0.0047 * parameters.wait_so_far 
	- 38774.7889 * parameters.num_locks_so_far 
	- 1386598.9547 * parameters.num_of_wait_locks 
	+ 34300.9865 * parameters.total_wait_locks 
	- 0.2665 * parameters.mean_wait_of_all 
	+ 313767431.3579 * parameters.cpu_usage 
	- 0.7511 * parameters.avg_latency_of_same_past_second 
	+ 743583203.1725;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM9(work_wait &parameters) {
  double actual_remaining = 
	1.5196 * parameters.work_so_far 
	- 0.0047 * parameters.wait_so_far 
	- 38774.7889 * parameters.num_locks_so_far 
	- 16649404.4699 * parameters.num_of_wait_locks 
	+ 659797.0833 * parameters.total_wait_locks 
	- 4.1848 * parameters.mean_wait_of_all 
	- 658112.0386 * parameters.cpu_usage 
	+ 0.0045 * parameters.avg_latency_of_same_past_second 
	+ 533021194.3296;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM10(work_wait &parameters) {
  double actual_remaining = 
	0.0175 * parameters.work_so_far 
	- 0.0072 * parameters.wait_so_far 
	- 38774.7889 * parameters.num_locks_so_far 
	- 21875859.3791 * parameters.num_of_wait_locks 
	- 833670.7712 * parameters.total_wait_locks 
	+ 3.8317 * parameters.mean_wait_of_all 
	- 231351351.2794 * parameters.cpu_usage 
	+ 0.0036 * parameters.avg_latency_of_same_past_second 
	+ 571761245.4168;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM11(work_wait &parameters) {
  double actual_remaining = 
	0.6782 * parameters.work_so_far 
	- 0.0959 * parameters.wait_so_far 
	- 19177382.4887 * parameters.num_locks_so_far 
	- 26580322.8942 * parameters.num_of_wait_locks 
	- 647291.8013 * parameters.total_wait_locks 
	+ 2.766 * parameters.mean_wait_of_all 
	- 193804988.2545 * parameters.cpu_usage 
	+ 0.0009 * parameters.avg_latency_of_same_past_second 
	+ 599131932.2138;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
new_order_estimate(work_wait &parameters){

  if (parameters.total_wait_locks <= 165.5) {

    if (parameters.work_so_far <= 34763.5) {
      return new_order_LM1(parameters);
    } else {
      return new_order_LM2(parameters);
    }
  } else {

    if (parameters.wait_so_far <= 229877842.5) {

      if (parameters.work_so_far <= 50975.5) {
        return new_order_LM3(parameters);
      } else {

        if (parameters.wait_so_far <= 101704861.5) {

          if (parameters.total_wait_locks <= 350.5) {
            return new_order_LM4(parameters);
          } else {

            if (parameters.mean_wait_of_all <= 95049000) {

              if (parameters.avg_latency_of_same_past_second <= 546421000) {
                return new_order_LM5(parameters);
              } else {

                if (parameters.mean_wait_of_all <= 92479050) {
                  return new_order_LM6(parameters);
                } else {

                  if (parameters.avg_latency_of_same_past_second <= 604991000) {
                    return new_order_LM7(parameters);
                  } else {
                    return new_order_LM8(parameters);
                  }
                }
              }
            } else {
              return new_order_LM9(parameters);
            }
          }
        } else {
          return new_order_LM10(parameters);
        }
      }
    } else {
      return new_order_LM11(parameters);
    }
  }
}
static
double
payment_LM1(work_wait &parameters) {
  double actual_remaining = 
	1689.5224 * parameters.work_so_far 
	+ 0.0316 * parameters.wait_so_far 
	+ 29536.5644 * parameters.num_of_wait_locks 
	+ 1029.9655 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 148045.33 * parameters.cpu_usage 
	- 0.0001 * parameters.avg_latency_of_same_past_second 
	- 4717733.2934;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM2(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 2703533.4687 * parameters.num_of_wait_locks 
	+ 75213.0033 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 225297.0743 * parameters.cpu_usage 
	- 0.0002 * parameters.avg_latency_of_same_past_second 
	+ 13403578.4744;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM3(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 3384274.0156 * parameters.num_of_wait_locks 
	+ 7476.0406 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 86071.7892 * parameters.cpu_usage 
	- 0 * parameters.avg_latency_of_same_past_second 
	+ 8112629.088;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM4(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 60520.9762 * parameters.num_of_wait_locks 
	+ 10032.0443 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 86071.7892 * parameters.cpu_usage 
	+ 0.0145 * parameters.avg_latency_of_same_past_second 
	+ 9433845.2571;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM5(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 1632629.6769 * parameters.num_of_wait_locks 
	- 346133.2339 * parameters.total_wait_locks 
	- 0.7887 * parameters.mean_wait_of_all 
	- 86071.7892 * parameters.cpu_usage 
	- 0.0997 * parameters.avg_latency_of_same_past_second 
	+ 119504341.778;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM6(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 60520.9762 * parameters.num_of_wait_locks 
	- 346133.2339 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 86071.7892 * parameters.cpu_usage 
	- 0.0874 * parameters.avg_latency_of_same_past_second 
	+ 91794629.7458;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM7(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 60520.9762 * parameters.num_of_wait_locks 
	- 127957.7037 * parameters.total_wait_locks 
	- 0.9533 * parameters.mean_wait_of_all 
	+ 25703668.0778 * parameters.cpu_usage 
	+ 0.0041 * parameters.avg_latency_of_same_past_second 
	+ 40396110.2205;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM8(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 60520.9762 * parameters.num_of_wait_locks 
	- 127957.7037 * parameters.total_wait_locks 
	- 2.2489 * parameters.mean_wait_of_all 
	+ 21014624.4656 * parameters.cpu_usage 
	- 0.0254 * parameters.avg_latency_of_same_past_second 
	+ 111029491.9744;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM9(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 60520.9762 * parameters.num_of_wait_locks 
	- 276819.3305 * parameters.total_wait_locks 
	- 2.2489 * parameters.mean_wait_of_all 
	+ 21014624.4656 * parameters.cpu_usage 
	- 0.0254 * parameters.avg_latency_of_same_past_second 
	+ 124589625.5381;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM10(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.003 * parameters.wait_so_far 
	+ 60520.9762 * parameters.num_of_wait_locks 
	- 261933.1678 * parameters.total_wait_locks 
	- 2.2489 * parameters.mean_wait_of_all 
	+ 21014624.4656 * parameters.cpu_usage 
	- 0.0254 * parameters.avg_latency_of_same_past_second 
	+ 123041053.9078;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM11(work_wait &parameters) {
  double actual_remaining = 
	0.9967 * parameters.work_so_far 
	- 0.0184 * parameters.wait_so_far 
	+ 1598107.9249 * parameters.num_of_wait_locks 
	- 127957.7037 * parameters.total_wait_locks 
	- 1.648 * parameters.mean_wait_of_all 
	+ 21014624.4656 * parameters.cpu_usage 
	- 0.0133 * parameters.avg_latency_of_same_past_second 
	+ 77058846.4194;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM12(work_wait &parameters) {
  double actual_remaining = 
	0.9967 * parameters.work_so_far 
	- 0.0234 * parameters.wait_so_far 
	+ 1516936.6768 * parameters.num_of_wait_locks 
	- 127957.7037 * parameters.total_wait_locks 
	- 1.648 * parameters.mean_wait_of_all 
	+ 21014624.4656 * parameters.cpu_usage 
	- 0.0133 * parameters.avg_latency_of_same_past_second 
	+ 78679828.9051;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM13(work_wait &parameters) {
  double actual_remaining = 
	0.9635 * parameters.work_so_far 
	- 0.0046 * parameters.wait_so_far 
	+ 644501.3192 * parameters.num_of_wait_locks 
	- 127957.7037 * parameters.total_wait_locks 
	- 2.0292 * parameters.mean_wait_of_all 
	+ 21014624.4656 * parameters.cpu_usage 
	- 0.0133 * parameters.avg_latency_of_same_past_second 
	+ 90700346.7406;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM14(work_wait &parameters) {
  double actual_remaining = 
	0.9635 * parameters.work_so_far 
	- 0.0078 * parameters.wait_so_far 
	+ 644501.3192 * parameters.num_of_wait_locks 
	- 127957.7037 * parameters.total_wait_locks 
	- 1.9815 * parameters.mean_wait_of_all 
	+ 21014624.4656 * parameters.cpu_usage 
	- 0.0184 * parameters.avg_latency_of_same_past_second 
	+ 90606462.6877;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM15(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 60520.9762 * parameters.num_of_wait_locks 
	+ 274820.8584 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 86071.7892 * parameters.cpu_usage 
	+ 0.0325 * parameters.avg_latency_of_same_past_second 
	- 17804220.3536;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM16(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 1557511.3057 * parameters.num_of_wait_locks 
	+ 1432.0776 * parameters.total_wait_locks 
	- 0.4346 * parameters.mean_wait_of_all 
	- 86071.7892 * parameters.cpu_usage 
	- 0.0185 * parameters.avg_latency_of_same_past_second 
	+ 40044828.6845;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM17(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	+ 123958.3114 * parameters.num_of_wait_locks 
	+ 1432.0776 * parameters.total_wait_locks 
	- 0.0184 * parameters.mean_wait_of_all 
	- 86071.7892 * parameters.cpu_usage 
	+ 0.0053 * parameters.avg_latency_of_same_past_second 
	+ 28819050.6633;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM18(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	+ 123958.3114 * parameters.num_of_wait_locks 
	+ 1432.0776 * parameters.total_wait_locks 
	- 0.0462 * parameters.mean_wait_of_all 
	+ 52345071.6189 * parameters.cpu_usage 
	+ 0.0136 * parameters.avg_latency_of_same_past_second 
	- 4704910.3507;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM19(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 62985.8482 * parameters.num_of_wait_locks 
	+ 61010.9667 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 86071.7892 * parameters.cpu_usage 
	- 0.2354 * parameters.avg_latency_of_same_past_second 
	+ 83105198.2199;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM20(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 1797697.1321 * parameters.num_of_wait_locks 
	+ 2517.6471 * parameters.total_wait_locks 
	+ 0.1297 * parameters.mean_wait_of_all 
	- 86071.7892 * parameters.cpu_usage 
	+ 0.0023 * parameters.avg_latency_of_same_past_second 
	+ 13383803.1722;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM21(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 18508.3822 * parameters.num_of_wait_locks 
	- 20661.8115 * parameters.total_wait_locks 
	+ 0.0408 * parameters.mean_wait_of_all 
	- 86071.7892 * parameters.cpu_usage 
	- 0 * parameters.avg_latency_of_same_past_second 
	+ 32922704.0211;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM22(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 18508.3822 * parameters.num_of_wait_locks 
	- 58109.9064 * parameters.total_wait_locks 
	+ 0.0408 * parameters.mean_wait_of_all 
	- 86071.7892 * parameters.cpu_usage 
	- 0 * parameters.avg_latency_of_same_past_second 
	+ 38603216.412;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM23(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 18508.3822 * parameters.num_of_wait_locks 
	- 118589.1981 * parameters.total_wait_locks 
	+ 0.0408 * parameters.mean_wait_of_all 
	- 86071.7892 * parameters.cpu_usage 
	- 0.1764 * parameters.avg_latency_of_same_past_second 
	+ 140416231.1957;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM24(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 18508.3822 * parameters.num_of_wait_locks 
	- 118589.1981 * parameters.total_wait_locks 
	+ 0.0408 * parameters.mean_wait_of_all 
	- 86071.7892 * parameters.cpu_usage 
	- 0.2785 * parameters.avg_latency_of_same_past_second 
	+ 203356388.2785;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM25(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 18508.3822 * parameters.num_of_wait_locks 
	- 94538.641 * parameters.total_wait_locks 
	+ 0.0408 * parameters.mean_wait_of_all 
	- 86071.7892 * parameters.cpu_usage 
	- 0.0398 * parameters.avg_latency_of_same_past_second 
	+ 71041522.8024;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM26(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 2215703.5181 * parameters.num_of_wait_locks 
	- 583252.8939 * parameters.total_wait_locks 
	+ 0.1461 * parameters.mean_wait_of_all 
	- 86071.7892 * parameters.cpu_usage 
	- 0.0595 * parameters.avg_latency_of_same_past_second 
	+ 208828242.6752;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM27(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 18508.3822 * parameters.num_of_wait_locks 
	- 485006.2822 * parameters.total_wait_locks 
	+ 0.1461 * parameters.mean_wait_of_all 
	- 86071.7892 * parameters.cpu_usage 
	- 0.0595 * parameters.avg_latency_of_same_past_second 
	+ 228641297.7836;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM28(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 18508.3822 * parameters.num_of_wait_locks 
	- 541504.7086 * parameters.total_wait_locks 
	+ 0.8599 * parameters.mean_wait_of_all 
	- 86071.7892 * parameters.cpu_usage 
	- 0.0595 * parameters.avg_latency_of_same_past_second 
	+ 175797395.8334;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM29(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 18508.3822 * parameters.num_of_wait_locks 
	- 544072.8189 * parameters.total_wait_locks 
	+ 0.8923 * parameters.mean_wait_of_all 
	- 86071.7892 * parameters.cpu_usage 
	- 0.0595 * parameters.avg_latency_of_same_past_second 
	+ 179181132.8731;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM30(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.021 * parameters.wait_so_far 
	+ 18508.3822 * parameters.num_of_wait_locks 
	+ 308152.7479 * parameters.total_wait_locks 
	- 0.4738 * parameters.mean_wait_of_all 
	+ 366048238.6823 * parameters.cpu_usage 
	- 0.0366 * parameters.avg_latency_of_same_past_second 
	- 351779803.3696;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM31(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	- 0.0073 * parameters.wait_so_far 
	+ 30930.0448 * parameters.num_of_wait_locks 
	- 208119.3449 * parameters.total_wait_locks 
	+ 0.4374 * parameters.mean_wait_of_all 
	- 0.0426 * parameters.avg_latency_of_same_past_second 
	+ 84361345.3389;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM32(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 10305539.4625 * parameters.num_of_wait_locks 
	- 991493.4866 * parameters.total_wait_locks 
	+ 2.5985 * parameters.mean_wait_of_all 
	- 0.0036 * parameters.avg_latency_of_same_past_second 
	+ 121184629.0827;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM33(work_wait &parameters) {
  double actual_remaining = 
	0.0079 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 71406.9947 * parameters.num_of_wait_locks 
	+ 15483.2699 * parameters.total_wait_locks 
	+ 1.0717 * parameters.mean_wait_of_all 
	+ 11638165.6046 * parameters.cpu_usage 
	- 0.0038 * parameters.avg_latency_of_same_past_second 
	- 76630601.1163;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM34(work_wait &parameters) {
  double actual_remaining = 
	0.0079 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 71406.9947 * parameters.num_of_wait_locks 
	+ 26775.3685 * parameters.total_wait_locks 
	- 4.3233 * parameters.mean_wait_of_all 
	- 640965482.7266 * parameters.cpu_usage 
	- 0.0038 * parameters.avg_latency_of_same_past_second 
	+ 1038041584.8029;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM35(work_wait &parameters) {
  double actual_remaining = 
	0.2391 * parameters.work_so_far 
	- 0.0089 * parameters.wait_so_far 
	+ 71406.9947 * parameters.num_of_wait_locks 
	- 11913.9529 * parameters.total_wait_locks 
	+ 0.0377 * parameters.mean_wait_of_all 
	- 0.0026 * parameters.avg_latency_of_same_past_second 
	+ 34720472.3147;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM36(work_wait &parameters) {
  double actual_remaining = 
	65.0076 * parameters.work_so_far 
	- 0.7144 * parameters.wait_so_far 
	- 18984285.8605 * parameters.num_of_wait_locks 
	- 219595.5615 * parameters.total_wait_locks 
	+ 2.4159 * parameters.mean_wait_of_all 
	- 0.0042 * parameters.avg_latency_of_same_past_second 
	+ 50263917.9885;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM37(work_wait &parameters) {
  double actual_remaining = 
	-0.4105 * parameters.work_so_far 
	- 0.4914 * parameters.wait_so_far 
	- 23628863.0682 * parameters.num_of_wait_locks 
	- 219595.5615 * parameters.total_wait_locks 
	+ 2.4159 * parameters.mean_wait_of_all 
	- 0.0042 * parameters.avg_latency_of_same_past_second 
	+ 58755995.7326;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM38(work_wait &parameters) {
  double actual_remaining = 
	1249.2559 * parameters.work_so_far 
	- 0.0346 * parameters.wait_so_far 
	+ 15806544.93 * parameters.num_of_wait_locks 
	- 219595.5615 * parameters.total_wait_locks 
	+ 5.299 * parameters.mean_wait_of_all 
	+ 0.5731 * parameters.avg_latency_of_same_past_second 
	- 695290036.4406;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM39(work_wait &parameters) {
  double actual_remaining = 
	1249.2559 * parameters.work_so_far 
	- 0.0346 * parameters.wait_so_far 
	+ 15806544.93 * parameters.num_of_wait_locks 
	- 219595.5615 * parameters.total_wait_locks 
	+ 5.299 * parameters.mean_wait_of_all 
	+ 0.5731 * parameters.avg_latency_of_same_past_second 
	- 695272509.7593;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM40(work_wait &parameters) {
  double actual_remaining = 
	1377.1028 * parameters.work_so_far 
	- 0.0346 * parameters.wait_so_far 
	+ 16809964.8049 * parameters.num_of_wait_locks 
	- 219595.5615 * parameters.total_wait_locks 
	+ 5.299 * parameters.mean_wait_of_all 
	+ 0.5872 * parameters.avg_latency_of_same_past_second 
	- 708148143.2374;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM41(work_wait &parameters) {
  double actual_remaining = 
	1399.5253 * parameters.work_so_far 
	- 0.0346 * parameters.wait_so_far 
	+ 16776933.9358 * parameters.num_of_wait_locks 
	- 219595.5615 * parameters.total_wait_locks 
	+ 5.299 * parameters.mean_wait_of_all 
	+ 0.5872 * parameters.avg_latency_of_same_past_second 
	- 708586833.0904;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM42(work_wait &parameters) {
  double actual_remaining = 
	1320.6312 * parameters.work_so_far 
	- 0.0346 * parameters.wait_so_far 
	+ 17126055.6838 * parameters.num_of_wait_locks 
	- 219595.5615 * parameters.total_wait_locks 
	+ 5.299 * parameters.mean_wait_of_all 
	+ 0.6023 * parameters.avg_latency_of_same_past_second 
	- 711824378.6052;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM43(work_wait &parameters) {
  double actual_remaining = 
	467.029 * parameters.work_so_far 
	- 0.0342 * parameters.wait_so_far 
	+ 9499077.6353 * parameters.num_of_wait_locks 
	- 105628.3692 * parameters.total_wait_locks 
	+ 9.2593 * parameters.mean_wait_of_all 
	+ 0.4163 * parameters.avg_latency_of_same_past_second 
	- 976294378.1099;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM44(work_wait &parameters) {
  double actual_remaining = 
	-1.7649 * parameters.work_so_far 
	- 0.0247 * parameters.wait_so_far 
	+ 5841263.7687 * parameters.num_of_wait_locks 
	- 219595.5615 * parameters.total_wait_locks 
	+ 2.9263 * parameters.mean_wait_of_all 
	+ 0.34 * parameters.avg_latency_of_same_past_second 
	- 301020661.0907;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM45(work_wait &parameters) {
  double actual_remaining = 
	-0.6309 * parameters.work_so_far 
	- 0.0226 * parameters.wait_so_far 
	+ 3359447.0847 * parameters.num_of_wait_locks 
	- 24400.4285 * parameters.total_wait_locks 
	+ 5.4911 * parameters.mean_wait_of_all 
	+ 0.1701 * parameters.avg_latency_of_same_past_second 
	- 498656503.8155;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM46(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	- 0.0032 * parameters.wait_so_far 
	- 201758.7019 * parameters.num_of_wait_locks 
	- 142140.4603 * parameters.total_wait_locks 
	+ 5.3707 * parameters.mean_wait_of_all 
	+ 0.7776 * parameters.avg_latency_of_same_past_second 
	- 695300557.6474;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM47(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	- 0.0032 * parameters.wait_so_far 
	- 201758.7019 * parameters.num_of_wait_locks 
	- 142140.4603 * parameters.total_wait_locks 
	+ 0.4917 * parameters.mean_wait_of_all 
	+ 0.1475 * parameters.avg_latency_of_same_past_second 
	- 12161446.0622;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM48(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	+ 0.0073 * parameters.wait_so_far 
	- 880300.6751 * parameters.num_of_wait_locks 
	+ 238236.0408 * parameters.total_wait_locks 
	- 2.1408 * parameters.mean_wait_of_all 
	- 0.0042 * parameters.avg_latency_of_same_past_second 
	+ 138203926.8428;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM49(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	- 0.0275 * parameters.wait_so_far 
	- 14282993.1814 * parameters.num_of_wait_locks 
	- 935378.7328 * parameters.total_wait_locks 
	+ 7.8228 * parameters.mean_wait_of_all 
	- 0.0042 * parameters.avg_latency_of_same_past_second 
	- 247736741.9964;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM50(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	- 0.0278 * parameters.wait_so_far 
	+ 58464.4166 * parameters.num_of_wait_locks 
	- 29665.1383 * parameters.total_wait_locks 
	+ 1.5862 * parameters.mean_wait_of_all 
	- 70051853.1058 * parameters.cpu_usage 
	- 0.0002 * parameters.avg_latency_of_same_past_second 
	- 53378902.1497;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM51(work_wait &parameters) {
  double actual_remaining = 
	5.9603 * parameters.work_so_far 
	+ 0.0408 * parameters.wait_so_far 
	+ 58464.4166 * parameters.num_of_wait_locks 
	- 764552.7884 * parameters.total_wait_locks 
	+ 2.2964 * parameters.mean_wait_of_all 
	- 446056352.2171 * parameters.cpu_usage 
	- 0.0002 * parameters.avg_latency_of_same_past_second 
	+ 556682022.9172;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM52(work_wait &parameters) {
  double actual_remaining = 
	8366.9302 * parameters.work_so_far 
	+ 0.0185 * parameters.wait_so_far 
	+ 58464.4166 * parameters.num_of_wait_locks 
	+ 776731.0531 * parameters.total_wait_locks 
	+ 1.143 * parameters.mean_wait_of_all 
	- 589175929.3742 * parameters.cpu_usage 
	- 0.0002 * parameters.avg_latency_of_same_past_second 
	- 23728398.5449;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM53(work_wait &parameters) {
  double actual_remaining = 
	-0.155 * parameters.work_so_far 
	+ 0.0185 * parameters.wait_so_far 
	+ 58464.4166 * parameters.num_of_wait_locks 
	- 610602.1515 * parameters.total_wait_locks 
	+ 1.143 * parameters.mean_wait_of_all 
	- 589175929.3742 * parameters.cpu_usage 
	- 0.0002 * parameters.avg_latency_of_same_past_second 
	+ 760204983.04;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM54(work_wait &parameters) {
  double actual_remaining = 
	-0.9065 * parameters.work_so_far 
	+ 0.0185 * parameters.wait_so_far 
	+ 58464.4166 * parameters.num_of_wait_locks 
	- 367544.5177 * parameters.total_wait_locks 
	+ 1.143 * parameters.mean_wait_of_all 
	- 2055038972.969 * parameters.cpu_usage 
	- 0.0002 * parameters.avg_latency_of_same_past_second 
	+ 2087650907.4657;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM55(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	+ 0.1258 * parameters.wait_so_far 
	+ 58464.4166 * parameters.num_of_wait_locks 
	+ 437487.9779 * parameters.total_wait_locks 
	+ 6.2981 * parameters.mean_wait_of_all 
	- 54537816.6089 * parameters.cpu_usage 
	- 0.0002 * parameters.avg_latency_of_same_past_second 
	- 719004931.5971;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM56(work_wait &parameters) {
  double actual_remaining = 
	-300.3305 * parameters.work_so_far 
	- 0.021 * parameters.wait_so_far 
	+ 58464.4166 * parameters.num_of_wait_locks 
	+ 221271.291 * parameters.total_wait_locks 
	+ 2.8993 * parameters.mean_wait_of_all 
	- 54537816.6089 * parameters.cpu_usage 
	- 0.0002 * parameters.avg_latency_of_same_past_second 
	- 282869346.7918;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM57(work_wait &parameters) {
  double actual_remaining = 
	-638.1915 * parameters.work_so_far 
	+ 0.1248 * parameters.wait_so_far 
	+ 58464.4166 * parameters.num_of_wait_locks 
	+ 1250885.6247 * parameters.total_wait_locks 
	+ 0.1613 * parameters.mean_wait_of_all 
	- 54537816.6089 * parameters.cpu_usage 
	- 0.0002 * parameters.avg_latency_of_same_past_second 
	- 441282580.3723;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM58(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	+ 0.1616 * parameters.wait_so_far 
	+ 58464.4166 * parameters.num_of_wait_locks 
	+ 1250885.6247 * parameters.total_wait_locks 
	+ 0.1613 * parameters.mean_wait_of_all 
	- 54537816.6089 * parameters.cpu_usage 
	- 0.0002 * parameters.avg_latency_of_same_past_second 
	- 456259288.6659;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM59(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	- 0.0336 * parameters.wait_so_far 
	+ 58464.4166 * parameters.num_of_wait_locks 
	+ 173773.0071 * parameters.total_wait_locks 
	+ 0.1613 * parameters.mean_wait_of_all 
	- 54537816.6089 * parameters.cpu_usage 
	- 0.0002 * parameters.avg_latency_of_same_past_second 
	- 2806753.0849;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM60(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	- 0.0005 * parameters.wait_so_far 
	+ 58464.4166 * parameters.num_of_wait_locks 
	- 29665.1383 * parameters.total_wait_locks 
	+ 0.1613 * parameters.mean_wait_of_all 
	- 54537816.6089 * parameters.cpu_usage 
	- 0.0002 * parameters.avg_latency_of_same_past_second 
	+ 77390418.383;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM61(work_wait &parameters) {
  double actual_remaining = 
	1.0874 * parameters.work_so_far 
	- 0.0233 * parameters.wait_so_far 
	+ 4122902.3318 * parameters.num_of_wait_locks 
	- 36456.8398 * parameters.total_wait_locks 
	+ 0.112 * parameters.mean_wait_of_all 
	- 26558521.7382 * parameters.cpu_usage 
	- 0.0002 * parameters.avg_latency_of_same_past_second 
	+ 38816674.8871;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM62(work_wait &parameters) {
  double actual_remaining = 
	0.6476 * parameters.work_so_far 
	- 0.0006 * parameters.wait_so_far 
	- 3054210.56 * parameters.num_of_wait_locks 
	+ 249415.7432 * parameters.total_wait_locks 
	+ 0.2142 * parameters.mean_wait_of_all 
	- 2293353.2236 * parameters.cpu_usage 
	- 0.005 * parameters.avg_latency_of_same_past_second 
	- 84058113.9905;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM63(work_wait &parameters) {
  double actual_remaining = 
	1.4707 * parameters.work_so_far 
	- 0.0006 * parameters.wait_so_far 
	+ 78640.4521 * parameters.num_of_wait_locks 
	- 209506.9396 * parameters.total_wait_locks 
	- 5.6313 * parameters.mean_wait_of_all 
	- 2293353.2236 * parameters.cpu_usage 
	- 0.005 * parameters.avg_latency_of_same_past_second 
	+ 702626079.6272;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM64(work_wait &parameters) {
  double actual_remaining = 
	1.2382 * parameters.work_so_far 
	- 0.0137 * parameters.wait_so_far 
	+ 4415178.2732 * parameters.num_of_wait_locks 
	- 209506.9396 * parameters.total_wait_locks 
	+ 0.2142 * parameters.mean_wait_of_all 
	- 2293353.2236 * parameters.cpu_usage 
	+ 0.2968 * parameters.avg_latency_of_same_past_second 
	- 14990822.5364;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM65(work_wait &parameters) {
  double actual_remaining = 
	0.932 * parameters.work_so_far 
	- 0.0006 * parameters.wait_so_far 
	+ 78640.4521 * parameters.num_of_wait_locks 
	- 271691.8864 * parameters.total_wait_locks 
	+ 0.2142 * parameters.mean_wait_of_all 
	- 2293353.2236 * parameters.cpu_usage 
	- 0.005 * parameters.avg_latency_of_same_past_second 
	+ 125910576.2725;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM66(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	- 0.0006 * parameters.wait_so_far 
	+ 78640.4521 * parameters.num_of_wait_locks 
	- 49602.7906 * parameters.total_wait_locks 
	+ 0.2142 * parameters.mean_wait_of_all 
	- 2293353.2236 * parameters.cpu_usage 
	- 0.0025 * parameters.avg_latency_of_same_past_second 
	+ 24589155.3094;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM67(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	- 0.0006 * parameters.wait_so_far 
	+ 78640.4521 * parameters.num_of_wait_locks 
	- 1030118.6799 * parameters.total_wait_locks 
	+ 0.6241 * parameters.mean_wait_of_all 
	- 117589662.8631 * parameters.cpu_usage 
	- 0.7232 * parameters.avg_latency_of_same_past_second 
	+ 815191363.3262;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM68(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	- 0.0006 * parameters.wait_so_far 
	+ 78640.4521 * parameters.num_of_wait_locks 
	- 167391.7635 * parameters.total_wait_locks 
	+ 0.6241 * parameters.mean_wait_of_all 
	- 8717531.0713 * parameters.cpu_usage 
	- 0.0002 * parameters.avg_latency_of_same_past_second 
	+ 46358084.9101;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM69(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	- 0.0006 * parameters.wait_so_far 
	+ 78640.4521 * parameters.num_of_wait_locks 
	- 154088.4019 * parameters.total_wait_locks 
	+ 0.8239 * parameters.mean_wait_of_all 
	- 10775733.7045 * parameters.cpu_usage 
	+ 0.0543 * parameters.avg_latency_of_same_past_second 
	+ 723740.953;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM70(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	+ 0.0152 * parameters.wait_so_far 
	+ 78640.4521 * parameters.num_of_wait_locks 
	- 154088.4019 * parameters.total_wait_locks 
	+ 5.6122 * parameters.mean_wait_of_all 
	- 45416223.1413 * parameters.cpu_usage 
	+ 0.044 * parameters.avg_latency_of_same_past_second 
	- 483059558.1837;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM71(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	+ 0.0544 * parameters.wait_so_far 
	+ 78640.4521 * parameters.num_of_wait_locks 
	- 154088.4019 * parameters.total_wait_locks 
	+ 5.6122 * parameters.mean_wait_of_all 
	- 35525554.1108 * parameters.cpu_usage 
	+ 0.044 * parameters.avg_latency_of_same_past_second 
	- 504353415.2701;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM72(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	+ 0.0544 * parameters.wait_so_far 
	+ 78640.4521 * parameters.num_of_wait_locks 
	- 154088.4019 * parameters.total_wait_locks 
	+ 5.6122 * parameters.mean_wait_of_all 
	- 35525554.1108 * parameters.cpu_usage 
	+ 0.044 * parameters.avg_latency_of_same_past_second 
	- 509282811.63;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM73(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	+ 0.19 * parameters.wait_so_far 
	+ 78640.4521 * parameters.num_of_wait_locks 
	- 154088.4019 * parameters.total_wait_locks 
	+ 9.4885 * parameters.mean_wait_of_all 
	- 55561123.0112 * parameters.cpu_usage 
	+ 0.044 * parameters.avg_latency_of_same_past_second 
	- 984453062.5995;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM74(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	+ 0.19 * parameters.wait_so_far 
	+ 78640.4521 * parameters.num_of_wait_locks 
	- 154088.4019 * parameters.total_wait_locks 
	+ 9.4885 * parameters.mean_wait_of_all 
	- 55561123.0112 * parameters.cpu_usage 
	+ 0.044 * parameters.avg_latency_of_same_past_second 
	- 980730543.0202;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM75(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	- 0.0006 * parameters.wait_so_far 
	+ 78640.4521 * parameters.num_of_wait_locks 
	- 154088.4019 * parameters.total_wait_locks 
	+ 0.8239 * parameters.mean_wait_of_all 
	- 10775733.7045 * parameters.cpu_usage 
	+ 0.044 * parameters.avg_latency_of_same_past_second 
	+ 12534577.6031;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM76(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	- 0.0006 * parameters.wait_so_far 
	+ 78640.4521 * parameters.num_of_wait_locks 
	- 19761.4334 * parameters.total_wait_locks 
	- 2.2522 * parameters.mean_wait_of_all 
	+ 373968.1458 * parameters.cpu_usage 
	- 0.0002 * parameters.avg_latency_of_same_past_second 
	+ 274399711.7961;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM77(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	- 0.0006 * parameters.wait_so_far 
	+ 78640.4521 * parameters.num_of_wait_locks 
	+ 219514.9441 * parameters.total_wait_locks 
	- 1.3588 * parameters.mean_wait_of_all 
	- 2676517.5085 * parameters.cpu_usage 
	- 0.0002 * parameters.avg_latency_of_same_past_second 
	+ 70121573.6383;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM78(work_wait &parameters) {
  double actual_remaining = 
	0.0562 * parameters.work_so_far 
	- 0.0013 * parameters.wait_so_far 
	+ 7590041.0252 * parameters.num_of_wait_locks 
	- 314659.4646 * parameters.total_wait_locks 
	+ 5.6412 * parameters.mean_wait_of_all 
	+ 4498365.9363 * parameters.cpu_usage 
	- 0.0781 * parameters.avg_latency_of_same_past_second 
	- 457200281.4551;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM79(work_wait &parameters) {
  double actual_remaining = 
	0.0562 * parameters.work_so_far 
	- 0.0574 * parameters.wait_so_far 
	+ 24779044.0774 * parameters.num_of_wait_locks 
	- 125318.4175 * parameters.total_wait_locks 
	+ 11.2198 * parameters.mean_wait_of_all 
	+ 4498365.9363 * parameters.cpu_usage 
	- 0.2894 * parameters.avg_latency_of_same_past_second 
	- 1054225954.9435;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM80(work_wait &parameters) {
  double actual_remaining = 
	0.0562 * parameters.work_so_far 
	- 0.0574 * parameters.wait_so_far 
	+ 24779044.0774 * parameters.num_of_wait_locks 
	- 125318.4175 * parameters.total_wait_locks 
	+ 11.2198 * parameters.mean_wait_of_all 
	+ 4498365.9363 * parameters.cpu_usage 
	- 0.2894 * parameters.avg_latency_of_same_past_second 
	- 1054432386.8123;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM81(work_wait &parameters) {
  double actual_remaining = 
	0.0562 * parameters.work_so_far 
	- 0.0013 * parameters.wait_so_far 
	+ 24779044.0774 * parameters.num_of_wait_locks 
	- 125318.4175 * parameters.total_wait_locks 
	+ 11.2198 * parameters.mean_wait_of_all 
	+ 4498365.9363 * parameters.cpu_usage 
	- 0.2894 * parameters.avg_latency_of_same_past_second 
	- 1052934727.4249;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM82(work_wait &parameters) {
  double actual_remaining = 
	0.0562 * parameters.work_so_far 
	- 0.0013 * parameters.wait_so_far 
	+ 24779044.0774 * parameters.num_of_wait_locks 
	- 125318.4175 * parameters.total_wait_locks 
	+ 11.2198 * parameters.mean_wait_of_all 
	+ 4498365.9363 * parameters.cpu_usage 
	- 0.2894 * parameters.avg_latency_of_same_past_second 
	- 1052924938.9207;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM83(work_wait &parameters) {
  double actual_remaining = 
	0.0562 * parameters.work_so_far 
	- 0.0013 * parameters.wait_so_far 
	+ 25602939.6725 * parameters.num_of_wait_locks 
	+ 160062.2448 * parameters.total_wait_locks 
	+ 11.2198 * parameters.mean_wait_of_all 
	+ 4498365.9363 * parameters.cpu_usage 
	- 0.2894 * parameters.avg_latency_of_same_past_second 
	- 1158180338.6434;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM84(work_wait &parameters) {
  double actual_remaining = 
	0.0562 * parameters.work_so_far 
	- 0.0013 * parameters.wait_so_far 
	+ 10627155.7439 * parameters.num_of_wait_locks 
	- 342296.6913 * parameters.total_wait_locks 
	+ 10.2158 * parameters.mean_wait_of_all 
	+ 4498365.9363 * parameters.cpu_usage 
	- 0.1271 * parameters.avg_latency_of_same_past_second 
	- 943567450.4885;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM85(work_wait &parameters) {
  double actual_remaining = 
	311.1884 * parameters.work_so_far 
	+ 0.0247 * parameters.wait_so_far 
	+ 16438758.5558 * parameters.num_of_wait_locks 
	- 458995.5853 * parameters.total_wait_locks 
	- 14.1242 * parameters.mean_wait_of_all 
	+ 4498365.9363 * parameters.cpu_usage 
	- 0.1271 * parameters.avg_latency_of_same_past_second 
	+ 1880754818.7539;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM86(work_wait &parameters) {
  double actual_remaining = 
	350.3817 * parameters.work_so_far 
	+ 0.0247 * parameters.wait_so_far 
	+ 16438758.5558 * parameters.num_of_wait_locks 
	- 458995.5853 * parameters.total_wait_locks 
	- 14.1242 * parameters.mean_wait_of_all 
	+ 4498365.9363 * parameters.cpu_usage 
	- 0.1271 * parameters.avg_latency_of_same_past_second 
	+ 1874155759.5812;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM87(work_wait &parameters) {
  double actual_remaining = 
	0.4228 * parameters.work_so_far 
	+ 0.0894 * parameters.wait_so_far 
	+ 15477856.7074 * parameters.num_of_wait_locks 
	- 351443.7003 * parameters.total_wait_locks 
	+ 10.6592 * parameters.mean_wait_of_all 
	+ 4498365.9363 * parameters.cpu_usage 
	- 0.1271 * parameters.avg_latency_of_same_past_second 
	- 972092652.1878;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM88(work_wait &parameters) {
  double actual_remaining = 
	7.8339 * parameters.work_so_far 
	- 0.0015 * parameters.wait_so_far 
	+ 356073.6744 * parameters.num_of_wait_locks 
	- 70758.416 * parameters.total_wait_locks 
	+ 0.6384 * parameters.mean_wait_of_all 
	+ 1245147.6912 * parameters.cpu_usage 
	+ 0.0743 * parameters.avg_latency_of_same_past_second 
	- 41078372.5478;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM89(work_wait &parameters) {
  double actual_remaining = 
	0.7763 * parameters.work_so_far 
	- 0.0015 * parameters.wait_so_far 
	+ 11253787.5184 * parameters.num_of_wait_locks 
	- 70758.416 * parameters.total_wait_locks 
	- 3.0351 * parameters.mean_wait_of_all 
	+ 1245147.6912 * parameters.cpu_usage 
	+ 0.0604 * parameters.avg_latency_of_same_past_second 
	+ 343956829.1711;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM90(work_wait &parameters) {
  double actual_remaining = 
	0.7763 * parameters.work_so_far 
	- 0.0015 * parameters.wait_so_far 
	+ 13281444.5595 * parameters.num_of_wait_locks 
	- 70758.416 * parameters.total_wait_locks 
	- 3.0351 * parameters.mean_wait_of_all 
	+ 1245147.6912 * parameters.cpu_usage 
	+ 0.0604 * parameters.avg_latency_of_same_past_second 
	+ 341613187.1225;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM91(work_wait &parameters) {
  double actual_remaining = 
	0.5851 * parameters.work_so_far 
	- 0.0015 * parameters.wait_so_far 
	+ 1997334.3919 * parameters.num_of_wait_locks 
	- 70758.416 * parameters.total_wait_locks 
	- 3.0351 * parameters.mean_wait_of_all 
	+ 1245147.6912 * parameters.cpu_usage 
	+ 0.1293 * parameters.avg_latency_of_same_past_second 
	+ 349900787.6652;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM92(work_wait &parameters) {
  double actual_remaining = 
	46.5692 * parameters.work_so_far 
	- 0.0015 * parameters.wait_so_far 
	+ 356073.6744 * parameters.num_of_wait_locks 
	- 70758.416 * parameters.total_wait_locks 
	- 7.6883 * parameters.mean_wait_of_all 
	+ 1245147.6912 * parameters.cpu_usage 
	+ 0.1171 * parameters.avg_latency_of_same_past_second 
	+ 904523807.3407;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM93(work_wait &parameters) {
  double actual_remaining = 
	0.2261 * parameters.work_so_far 
	- 0.0015 * parameters.wait_so_far 
	+ 356073.6744 * parameters.num_of_wait_locks 
	- 70758.416 * parameters.total_wait_locks 
	+ 4.0969 * parameters.mean_wait_of_all 
	+ 1245147.6912 * parameters.cpu_usage 
	- 0.0002 * parameters.avg_latency_of_same_past_second 
	- 404644473.3361;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM94(work_wait &parameters) {
  double actual_remaining = 
	0.111 * parameters.work_so_far 
	- 0.0016 * parameters.wait_so_far 
	+ 356073.6744 * parameters.num_of_wait_locks 
	- 347645.2728 * parameters.total_wait_locks 
	+ 3.4154 * parameters.mean_wait_of_all 
	+ 1245147.6912 * parameters.cpu_usage 
	- 0.0002 * parameters.avg_latency_of_same_past_second 
	- 190158503.6427;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM95(work_wait &parameters) {
  double actual_remaining = 
	0.115 * parameters.work_so_far 
	- 0.0176 * parameters.wait_so_far 
	+ 5506889.6144 * parameters.num_of_wait_locks 
	- 81937.938 * parameters.total_wait_locks 
	+ 145.8386 * parameters.mean_wait_of_all 
	+ 1245147.6912 * parameters.cpu_usage 
	- 0.6274 * parameters.avg_latency_of_same_past_second 
	- 16593274048.8792;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM96(work_wait &parameters) {
  double actual_remaining = 
	0.115 * parameters.work_so_far 
	- 0.0176 * parameters.wait_so_far 
	+ 10590884.8836 * parameters.num_of_wait_locks 
	- 81937.938 * parameters.total_wait_locks 
	+ 14.6786 * parameters.mean_wait_of_all 
	+ 1245147.6912 * parameters.cpu_usage 
	- 0.0452 * parameters.avg_latency_of_same_past_second 
	- 1634436155.4158;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM97(work_wait &parameters) {
  double actual_remaining = 
	0.115 * parameters.work_so_far 
	- 0.0176 * parameters.wait_so_far 
	+ 8444309.1033 * parameters.num_of_wait_locks 
	- 81937.938 * parameters.total_wait_locks 
	+ 21.8599 * parameters.mean_wait_of_all 
	+ 1245147.6912 * parameters.cpu_usage 
	- 0.1405 * parameters.avg_latency_of_same_past_second 
	- 2430574367.457;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM98(work_wait &parameters) {
  double actual_remaining = 
	5.0261 * parameters.work_so_far 
	- 0.0111 * parameters.wait_so_far 
	+ 3171544.9069 * parameters.num_of_wait_locks 
	- 81937.938 * parameters.total_wait_locks 
	+ 24.0225 * parameters.mean_wait_of_all 
	+ 1245147.6912 * parameters.cpu_usage 
	- 0.1213 * parameters.avg_latency_of_same_past_second 
	- 2676592572.511;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM99(work_wait &parameters) {
  double actual_remaining = 
	0.3179 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 11211.3366 * parameters.num_of_wait_locks 
	- 84026.9265 * parameters.total_wait_locks 
	+ 0.0245 * parameters.mean_wait_of_all 
	- 0.0006 * parameters.avg_latency_of_same_past_second 
	+ 74756162.3128;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM100(work_wait &parameters) {
  double actual_remaining = 
	0.0018 * parameters.work_so_far 
	+ 0.0096 * parameters.wait_so_far 
	+ 1966295.1711 * parameters.num_of_wait_locks 
	- 305901.0908 * parameters.total_wait_locks 
	+ 1.369 * parameters.mean_wait_of_all 
	- 0.0592 * parameters.avg_latency_of_same_past_second 
	+ 34422523.1772;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM101(work_wait &parameters) {
  double actual_remaining = 
	0.0018 * parameters.work_so_far 
	- 0.0227 * parameters.wait_so_far 
	+ 11211.3366 * parameters.num_of_wait_locks 
	- 29869.1612 * parameters.total_wait_locks 
	- 0.5859 * parameters.mean_wait_of_all 
	+ 0.0088 * parameters.avg_latency_of_same_past_second 
	+ 123589754.9368;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM102(work_wait &parameters) {
  double actual_remaining = 
	0.0018 * parameters.work_so_far 
	+ 0.0104 * parameters.wait_so_far 
	+ 2816171.6827 * parameters.num_of_wait_locks 
	+ 408511.26 * parameters.total_wait_locks 
	+ 1.4913 * parameters.mean_wait_of_all 
	- 45596941.3829 * parameters.cpu_usage 
	- 0.0518 * parameters.avg_latency_of_same_past_second 
	- 363518595.6032;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM103(work_wait &parameters) {
  double actual_remaining = 
	0.0018 * parameters.work_so_far 
	- 0.0555 * parameters.wait_so_far 
	+ 2716048.9276 * parameters.num_of_wait_locks 
	- 110546.2147 * parameters.total_wait_locks 
	+ 10.4674 * parameters.mean_wait_of_all 
	- 0.1086 * parameters.avg_latency_of_same_past_second 
	- 1175766522.0135;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM104(work_wait &parameters) {
  double actual_remaining = 
	0.0018 * parameters.work_so_far 
	- 0.0555 * parameters.wait_so_far 
	+ 11211.3366 * parameters.num_of_wait_locks 
	- 110546.2147 * parameters.total_wait_locks 
	+ 5.8943 * parameters.mean_wait_of_all 
	- 0.1086 * parameters.avg_latency_of_same_past_second 
	- 583744226.045;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM105(work_wait &parameters) {
  double actual_remaining = 
	0.0018 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 11211.3366 * parameters.num_of_wait_locks 
	- 110546.2147 * parameters.total_wait_locks 
	- 2.7865 * parameters.mean_wait_of_all 
	- 0.0031 * parameters.avg_latency_of_same_past_second 
	+ 457659616.5969;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM106(work_wait &parameters) {
  double actual_remaining = 
	0.0018 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 11211.3366 * parameters.num_of_wait_locks 
	- 35181.8396 * parameters.total_wait_locks 
	- 16.1871 * parameters.mean_wait_of_all 
	+ 0.3025 * parameters.avg_latency_of_same_past_second 
	+ 2049831200.1858;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM107(work_wait &parameters) {
  double actual_remaining = 
	0.0018 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 11211.3366 * parameters.num_of_wait_locks 
	+ 21325.5625 * parameters.total_wait_locks 
	- 8.2902 * parameters.mean_wait_of_all 
	- 0.0474 * parameters.avg_latency_of_same_past_second 
	+ 1106803666.9763;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
payment_estimate(work_wait &parameters){

  if (parameters.total_wait_locks <= 283.5) {

    if (parameters.work_so_far <= 9779) {
      return payment_LM1(parameters);
    } else {

      if (parameters.avg_latency_of_same_past_second <= 46293450) {
        return payment_LM2(parameters);
      } else {

        if (parameters.total_wait_locks <= 119.5) {

          if (parameters.avg_latency_of_same_past_second <= 69023350) {
            return payment_LM3(parameters);
          } else {

            if (parameters.total_wait_locks <= 92.5) {
              return payment_LM4(parameters);
            } else {

              if (parameters.mean_wait_of_all <= 38299150) {

                if (parameters.total_wait_locks <= 95.5) {

                  if (parameters.mean_wait_of_all <= 38279850) {
                    return payment_LM5(parameters);
                  } else {
                    return payment_LM6(parameters);
                  }
                } else {

                  if (parameters.cpu_usage <= 0.997) {
                    return payment_LM7(parameters);
                  } else {

                    if (parameters.avg_latency_of_same_past_second <= 263505500) {

                      if (parameters.mean_wait_of_all <= 33679500) {
                        return payment_LM8(parameters);
                      } else {

                        if (parameters.total_wait_locks <= 100.5) {
                          return payment_LM9(parameters);
                        } else {
                          return payment_LM10(parameters);
                        }
                      }
                    } else {

                      if (parameters.work_so_far <= 21175.5) {

                        if (parameters.num_of_wait_locks <= 3.5) {
                          return payment_LM11(parameters);
                        } else {
                          return payment_LM12(parameters);
                        }
                      } else {

                        if (parameters.mean_wait_of_all <= 35765800) {
                          return payment_LM13(parameters);
                        } else {
                          return payment_LM14(parameters);
                        }
                      }
                    }
                  }
                }
              } else {
                return payment_LM15(parameters);
              }
            }
          }
        } else {

          if (parameters.avg_latency_of_same_past_second <= 368109000) {

            if (parameters.avg_latency_of_same_past_second <= 287016500) {

              if (parameters.mean_wait_of_all <= 43053700) {
                return payment_LM16(parameters);
              } else {

                if (parameters.avg_latency_of_same_past_second <= 240182500) {
                  return payment_LM17(parameters);
                } else {
                  return payment_LM18(parameters);
                }
              }
            } else {

              if (parameters.avg_latency_of_same_past_second <= 333230500) {
                return payment_LM19(parameters);
              } else {
                return payment_LM20(parameters);
              }
            }
          } else {

            if (parameters.mean_wait_of_all <= 56496350) {

              if (parameters.cpu_usage <= 0.964) {
                return payment_LM21(parameters);
              } else {

                if (parameters.avg_latency_of_same_past_second <= 380387000) {
                  return payment_LM22(parameters);
                } else {

                  if (parameters.mean_wait_of_all <= 49939050) {

                    if (parameters.mean_wait_of_all <= 45379400) {
                      return payment_LM23(parameters);
                    } else {
                      return payment_LM24(parameters);
                    }
                  } else {
                    return payment_LM25(parameters);
                  }
                }
              }
            } else {

              if (parameters.cpu_usage <= 0.954) {

                if (parameters.mean_wait_of_all <= 60125450) {
                  return payment_LM26(parameters);
                } else {

                  if (parameters.mean_wait_of_all <= 60232850) {
                    return payment_LM27(parameters);
                  } else {

                    if (parameters.mean_wait_of_all <= 70935600) {
                      return payment_LM28(parameters);
                    } else {
                      return payment_LM29(parameters);
                    }
                  }
                }
              } else {
                return payment_LM30(parameters);
              }
            }
          }
        }
      }
    }
  } else {

    if (parameters.mean_wait_of_all <= 116959500) {

      if (parameters.mean_wait_of_all <= 90253350) {

        if (parameters.mean_wait_of_all <= 76118350) {
          return payment_LM31(parameters);
        } else {

          if (parameters.total_wait_locks <= 340.5) {
            return payment_LM32(parameters);
          } else {

            if (parameters.avg_latency_of_same_past_second <= 378415000) {

              if (parameters.cpu_usage <= 0.964) {
                return payment_LM33(parameters);
              } else {
                return payment_LM34(parameters);
              }
            } else {
              return payment_LM35(parameters);
            }
          }
        }
      } else {

        if (parameters.mean_wait_of_all <= 111001500) {

          if (parameters.total_wait_locks <= 413.5) {

            if (parameters.avg_latency_of_same_past_second <= 487436500) {

              if (parameters.total_wait_locks <= 387.5) {

                if (parameters.wait_so_far <= 94201127.5) {

                  if (parameters.wait_so_far <= 27241363) {
                    return payment_LM36(parameters);
                  } else {
                    return payment_LM37(parameters);
                  }
                } else {

                  if (parameters.mean_wait_of_all <= 97111550) {

                    if (parameters.work_so_far <= 64265) {

                      if (parameters.wait_so_far <= 538292283) {

                        if (parameters.work_so_far <= 26934.5) {

                          if (parameters.work_so_far <= 24816) {
                            return payment_LM38(parameters);
                          } else {
                            return payment_LM39(parameters);
                          }
                        } else {

                          if (parameters.avg_latency_of_same_past_second <= 483154000) {

                            if (parameters.num_of_wait_locks <= 3.5) {
                              return payment_LM40(parameters);
                            } else {
                              return payment_LM41(parameters);
                            }
                          } else {
                            return payment_LM42(parameters);
                          }
                        }
                      } else {
                        return payment_LM43(parameters);
                      }
                    } else {
                      return payment_LM44(parameters);
                    }
                  } else {
                    return payment_LM45(parameters);
                  }
                }
              } else {

                if (parameters.avg_latency_of_same_past_second <= 388598500) {
                  return payment_LM46(parameters);
                } else {
                  return payment_LM47(parameters);
                }
              }
            } else {

              if (parameters.work_so_far <= 41756) {
                return payment_LM48(parameters);
              } else {
                return payment_LM49(parameters);
              }
            }
          } else {

            if (parameters.wait_so_far <= 354114141) {

              if (parameters.mean_wait_of_all <= 107292500) {

                if (parameters.cpu_usage <= 0.907) {
                  return payment_LM50(parameters);
                } else {

                  if (parameters.cpu_usage <= 0.979) {

                    if (parameters.wait_so_far <= 35869663.5) {
                      return payment_LM51(parameters);
                    } else {

                      if (parameters.work_so_far <= 33535) {

                        if (parameters.work_so_far <= 26359.5) {
                          return payment_LM52(parameters);
                        } else {
                          return payment_LM53(parameters);
                        }
                      } else {
                        return payment_LM54(parameters);
                      }
                    }
                  } else {

                    if (parameters.mean_wait_of_all <= 101696500) {

                      if (parameters.work_so_far <= 32197.5) {

                        if (parameters.total_wait_locks <= 431.5) {

                          if (parameters.wait_so_far <= 102512603.5) {
                            return payment_LM55(parameters);
                          } else {
                            return payment_LM56(parameters);
                          }
                        } else {

                          if (parameters.wait_so_far <= 178800397.5) {
                            return payment_LM57(parameters);
                          } else {
                            return payment_LM58(parameters);
                          }
                        }
                      } else {
                        return payment_LM59(parameters);
                      }
                    } else {
                      return payment_LM60(parameters);
                    }
                  }
                }
              } else {
                return payment_LM61(parameters);
              }
            } else {

              if (parameters.mean_wait_of_all <= 103738000) {

                if (parameters.avg_latency_of_same_past_second <= 368935000) {

                  if (parameters.mean_wait_of_all <= 100788000) {
                    return payment_LM62(parameters);
                  } else {

                    if (parameters.total_wait_locks <= 435.5) {

                      if (parameters.mean_wait_of_all <= 101970000) {
                        return payment_LM63(parameters);
                      } else {
                        return payment_LM64(parameters);
                      }
                    } else {
                      return payment_LM65(parameters);
                    }
                  }
                } else {
                  return payment_LM66(parameters);
                }
              } else {

                if (parameters.mean_wait_of_all <= 109293000) {

                  if (parameters.mean_wait_of_all <= 107219500) {

                    if (parameters.avg_latency_of_same_past_second <= 406816000) {
                      return payment_LM67(parameters);
                    } else {
                      return payment_LM68(parameters);
                    }
                  } else {

                    if (parameters.avg_latency_of_same_past_second <= 415107500) {
                      return payment_LM69(parameters);
                    } else {

                      if (parameters.wait_so_far <= 815618256) {

                        if (parameters.wait_so_far <= 547309813.5) {

                          if (parameters.wait_so_far <= 445771448.5) {

                            if (parameters.wait_so_far <= 430380580.5) {
                              return payment_LM70(parameters);
                            } else {
                              return payment_LM71(parameters);
                            }
                          } else {
                            return payment_LM72(parameters);
                          }
                        } else {

                          if (parameters.wait_so_far <= 677767864.5) {
                            return payment_LM73(parameters);
                          } else {
                            return payment_LM74(parameters);
                          }
                        }
                      } else {
                        return payment_LM75(parameters);
                      }
                    }
                  }
                } else {

                  if (parameters.cpu_usage <= 0.957) {
                    return payment_LM76(parameters);
                  } else {
                    return payment_LM77(parameters);
                  }
                }
              }
            }
          }
        } else {

          if (parameters.total_wait_locks <= 479.5) {

            if (parameters.avg_latency_of_same_past_second <= 324939000) {
              return payment_LM78(parameters);
            } else {

              if (parameters.mean_wait_of_all <= 111052000) {

                if (parameters.num_of_wait_locks <= 4.5) {

                  if (parameters.wait_so_far <= 153580307) {

                    if (parameters.work_so_far <= 32788) {

                      if (parameters.wait_so_far <= 15457538.5) {
                        return payment_LM79(parameters);
                      } else {
                        return payment_LM80(parameters);
                      }
                    } else {
                      return payment_LM81(parameters);
                    }
                  } else {
                    return payment_LM82(parameters);
                  }
                } else {
                  return payment_LM83(parameters);
                }
              } else {

                if (parameters.mean_wait_of_all <= 113708500) {
                  return payment_LM84(parameters);
                } else {

                  if (parameters.avg_latency_of_same_past_second <= 440092000) {

                    if (parameters.mean_wait_of_all <= 114149500) {
                      return payment_LM85(parameters);
                    } else {
                      return payment_LM86(parameters);
                    }
                  } else {
                    return payment_LM87(parameters);
                  }
                }
              }
            }
          } else {

            if (parameters.mean_wait_of_all <= 115676000) {

              if (parameters.wait_so_far <= 241530418.5) {

                if (parameters.total_wait_locks <= 497.5) {

                  if (parameters.mean_wait_of_all <= 112682000) {
                    return payment_LM88(parameters);
                  } else {

                    if (parameters.total_wait_locks <= 495.5) {

                      if (parameters.mean_wait_of_all <= 113059000) {

                        if (parameters.num_of_wait_locks <= 5.5) {
                          return payment_LM89(parameters);
                        } else {
                          return payment_LM90(parameters);
                        }
                      } else {
                        return payment_LM91(parameters);
                      }
                    } else {
                      return payment_LM92(parameters);
                    }
                  }
                } else {
                  return payment_LM93(parameters);
                }
              } else {
                return payment_LM94(parameters);
              }
            } else {

              if (parameters.avg_latency_of_same_past_second <= 519445000) {

                if (parameters.wait_so_far <= 313524624.5) {
                  return payment_LM95(parameters);
                } else {

                  if (parameters.work_so_far <= 33489) {
                    return payment_LM96(parameters);
                  } else {
                    return payment_LM97(parameters);
                  }
                }
              } else {
                return payment_LM98(parameters);
              }
            }
          }
        }
      }
    } else {

      if (parameters.wait_so_far <= 212922053) {
        return payment_LM99(parameters);
      } else {

        if (parameters.mean_wait_of_all <= 126764500) {
          return payment_LM100(parameters);
        } else {

          if (parameters.avg_latency_of_same_past_second <= 338725500) {
            return payment_LM101(parameters);
          } else {

            if (parameters.cpu_usage <= 0.957) {
              return payment_LM102(parameters);
            } else {

              if (parameters.mean_wait_of_all <= 129418000) {

                if (parameters.avg_latency_of_same_past_second <= 380992500) {

                  if (parameters.work_so_far <= 30602) {

                    if (parameters.wait_so_far <= 467500759.5) {
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
              } else {
                return payment_LM107(parameters);
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
stock_level_LM1(work_wait &parameters) {
  double actual_remaining = 
	+ 9980792.1667;
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
	65.244 * parameters.work_so_far 
	+ 0.0011 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 29503.4344 * parameters.num_of_wait_locks 
	+ 1064.4789 * parameters.total_wait_locks 
	- 0.0005 * parameters.mean_wait_of_all 
	- 212201.5454 * parameters.cpu_usage 
	+ 0.0003 * parameters.avg_latency_of_same_past_second 
	+ 5603635.0819;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM2(work_wait &parameters) {
  double actual_remaining = 
	-9.2839 * parameters.work_so_far 
	+ 0.0054 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 29503.4344 * parameters.num_of_wait_locks 
	+ 1064.4789 * parameters.total_wait_locks 
	- 0.0005 * parameters.mean_wait_of_all 
	- 1283558.6286 * parameters.cpu_usage 
	+ 0.0003 * parameters.avg_latency_of_same_past_second 
	+ 6724231.6971;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM3(work_wait &parameters) {
  double actual_remaining = 
	-3003.6252 * parameters.work_so_far 
	+ 0.0301 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 29503.4344 * parameters.num_of_wait_locks 
	+ 1064.4789 * parameters.total_wait_locks 
	- 0.0005 * parameters.mean_wait_of_all 
	- 1283558.6286 * parameters.cpu_usage 
	+ 0.0003 * parameters.avg_latency_of_same_past_second 
	+ 24869621.2586;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM4(work_wait &parameters) {
  double actual_remaining = 
	-28057.1662 * parameters.work_so_far 
	+ 0.0509 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 29503.4344 * parameters.num_of_wait_locks 
	+ 1064.4789 * parameters.total_wait_locks 
	- 0.0005 * parameters.mean_wait_of_all 
	- 1283558.6286 * parameters.cpu_usage 
	+ 0.0003 * parameters.avg_latency_of_same_past_second 
	+ 195208241.864;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM5(work_wait &parameters) {
  double actual_remaining = 
	396.3726 * parameters.work_so_far 
	+ 0.0066 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 29503.4344 * parameters.num_of_wait_locks 
	+ 1064.4789 * parameters.total_wait_locks 
	- 0.0351 * parameters.mean_wait_of_all 
	- 2379524.9992 * parameters.cpu_usage 
	+ 0.0003 * parameters.avg_latency_of_same_past_second 
	+ 9214132.1567;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM6(work_wait &parameters) {
  double actual_remaining = 
	317.9944 * parameters.work_so_far 
	+ 0.0116 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 29503.4344 * parameters.num_of_wait_locks 
	+ 403766.2217 * parameters.total_wait_locks 
	+ 2.3616 * parameters.mean_wait_of_all 
	- 2379524.9992 * parameters.cpu_usage 
	+ 0.0003 * parameters.avg_latency_of_same_past_second 
	- 86360740.2224;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM7(work_wait &parameters) {
  double actual_remaining = 
	317.9944 * parameters.work_so_far 
	+ 0.0324 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 29503.4344 * parameters.num_of_wait_locks 
	+ 1064.4789 * parameters.total_wait_locks 
	- 0.2534 * parameters.mean_wait_of_all 
	- 2379524.9992 * parameters.cpu_usage 
	+ 0.0003 * parameters.avg_latency_of_same_past_second 
	+ 18007782.7305;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM8(work_wait &parameters) {
  double actual_remaining = 
	87.0962 * parameters.work_so_far 
	+ 0.002 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 29503.4344 * parameters.num_of_wait_locks 
	+ 1064.4789 * parameters.total_wait_locks 
	- 0.0005 * parameters.mean_wait_of_all 
	- 2379524.9992 * parameters.cpu_usage 
	+ 0.0003 * parameters.avg_latency_of_same_past_second 
	+ 12296533.2437;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM9(work_wait &parameters) {
  double actual_remaining = 
	87.0962 * parameters.work_so_far 
	+ 0.002 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 29503.4344 * parameters.num_of_wait_locks 
	+ 1064.4789 * parameters.total_wait_locks 
	- 1.6104 * parameters.mean_wait_of_all 
	- 2379524.9992 * parameters.cpu_usage 
	+ 0.0003 * parameters.avg_latency_of_same_past_second 
	+ 120028033.6644;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM10(work_wait &parameters) {
  double actual_remaining = 
	87.0962 * parameters.work_so_far 
	+ 0.0023 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 29503.4344 * parameters.num_of_wait_locks 
	+ 1064.4789 * parameters.total_wait_locks 
	- 0.0005 * parameters.mean_wait_of_all 
	- 2865474.5797 * parameters.cpu_usage 
	+ 0.0003 * parameters.avg_latency_of_same_past_second 
	+ 10673528.5457;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM11(work_wait &parameters) {
  double actual_remaining = 
	-392.0156 * parameters.work_so_far 
	+ 0.0085 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 29503.4344 * parameters.num_of_wait_locks 
	+ 1064.4789 * parameters.total_wait_locks 
	- 0.0005 * parameters.mean_wait_of_all 
	- 13810337.3987 * parameters.cpu_usage 
	+ 0.0164 * parameters.avg_latency_of_same_past_second 
	+ 24237929.0745;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM12(work_wait &parameters) {
  double actual_remaining = 
	-392.0156 * parameters.work_so_far 
	+ 0.014 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 29503.4344 * parameters.num_of_wait_locks 
	+ 1064.4789 * parameters.total_wait_locks 
	- 0.0005 * parameters.mean_wait_of_all 
	- 94488781.412 * parameters.cpu_usage 
	+ 0.0233 * parameters.avg_latency_of_same_past_second 
	+ 105608216.8592;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM13(work_wait &parameters) {
  double actual_remaining = 
	-2050.4373 * parameters.work_so_far 
	+ 0.0023 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 29503.4344 * parameters.num_of_wait_locks 
	- 27576.1733 * parameters.total_wait_locks 
	- 0.0005 * parameters.mean_wait_of_all 
	- 13810337.3987 * parameters.cpu_usage 
	+ 0.01 * parameters.avg_latency_of_same_past_second 
	+ 50356516.7201;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM14(work_wait &parameters) {
  double actual_remaining = 
	-2050.4373 * parameters.work_so_far 
	- 0.0135 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 29503.4344 * parameters.num_of_wait_locks 
	- 27576.1733 * parameters.total_wait_locks 
	- 1.0013 * parameters.mean_wait_of_all 
	- 13810337.3987 * parameters.cpu_usage 
	+ 0.01 * parameters.avg_latency_of_same_past_second 
	+ 94510716.2966;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM15(work_wait &parameters) {
  double actual_remaining = 
	-2050.4373 * parameters.work_so_far 
	+ 0.0023 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 29503.4344 * parameters.num_of_wait_locks 
	- 27576.1733 * parameters.total_wait_locks 
	+ 0.72 * parameters.mean_wait_of_all 
	- 13810337.3987 * parameters.cpu_usage 
	+ 0.01 * parameters.avg_latency_of_same_past_second 
	+ 22203599.701;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM16(work_wait &parameters) {
  double actual_remaining = 
	-2050.4373 * parameters.work_so_far 
	+ 0.0023 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 29503.4344 * parameters.num_of_wait_locks 
	- 27576.1733 * parameters.total_wait_locks 
	+ 1.2196 * parameters.mean_wait_of_all 
	- 13810337.3987 * parameters.cpu_usage 
	+ 0.01 * parameters.avg_latency_of_same_past_second 
	+ 3101621.7644;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM17(work_wait &parameters) {
  double actual_remaining = 
	-2050.4373 * parameters.work_so_far 
	+ 0.0023 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 29503.4344 * parameters.num_of_wait_locks 
	- 27576.1733 * parameters.total_wait_locks 
	- 0.0005 * parameters.mean_wait_of_all 
	- 13810337.3987 * parameters.cpu_usage 
	+ 0.01 * parameters.avg_latency_of_same_past_second 
	+ 48975315.2429;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM18(work_wait &parameters) {
  double actual_remaining = 
	-2984.9241 * parameters.work_so_far 
	+ 0.0023 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 29503.4344 * parameters.num_of_wait_locks 
	- 44581.5605 * parameters.total_wait_locks 
	- 0.0005 * parameters.mean_wait_of_all 
	- 13810337.3987 * parameters.cpu_usage 
	+ 0.01 * parameters.avg_latency_of_same_past_second 
	+ 55208521.1749;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM19(work_wait &parameters) {
  double actual_remaining = 
	87.0962 * parameters.work_so_far 
	+ 0.0023 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 29503.4344 * parameters.num_of_wait_locks 
	+ 1064.4789 * parameters.total_wait_locks 
	- 0.0005 * parameters.mean_wait_of_all 
	- 31407959.9704 * parameters.cpu_usage 
	+ 0.0003 * parameters.avg_latency_of_same_past_second 
	+ 38704513.0915;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM20(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 2700501.0151 * parameters.num_of_wait_locks 
	+ 75164.3083 * parameters.total_wait_locks 
	- 0.0005 * parameters.mean_wait_of_all 
	- 289366.6392 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_latency_of_same_past_second 
	+ 13426256.3052;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM21(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 3380478.0005 * parameters.num_of_wait_locks 
	+ 7503.3238 * parameters.total_wait_locks 
	- 0.0005 * parameters.mean_wait_of_all 
	- 150297.518 * parameters.cpu_usage 
	+ 0.0003 * parameters.avg_latency_of_same_past_second 
	+ 8141241.5813;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM22(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 60453.0921 * parameters.num_of_wait_locks 
	+ 10056.4604 * parameters.total_wait_locks 
	- 0.0005 * parameters.mean_wait_of_all 
	- 150297.518 * parameters.cpu_usage 
	+ 0.0149 * parameters.avg_latency_of_same_past_second 
	+ 9460975.7909;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM23(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	- 1630798.4165 * parameters.num_of_wait_locks 
	- 345709.3203 * parameters.total_wait_locks 
	- 0.7882 * parameters.mean_wait_of_all 
	- 150297.518 * parameters.cpu_usage 
	- 0.0993 * parameters.avg_latency_of_same_past_second 
	+ 119408010.3027;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM24(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 60453.0921 * parameters.num_of_wait_locks 
	- 345709.3203 * parameters.total_wait_locks 
	- 0.0005 * parameters.mean_wait_of_all 
	- 150297.518 * parameters.cpu_usage 
	- 0.087 * parameters.avg_latency_of_same_past_second 
	+ 91729379.2307;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM25(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 60453.0921 * parameters.num_of_wait_locks 
	- 127778.5096 * parameters.total_wait_locks 
	- 0.9526 * parameters.mean_wait_of_all 
	+ 25610514.9507 * parameters.cpu_usage 
	+ 0.0045 * parameters.avg_latency_of_same_past_second 
	+ 40388511.5257;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM26(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 60453.0921 * parameters.num_of_wait_locks 
	- 127778.5096 * parameters.total_wait_locks 
	- 2.2468 * parameters.mean_wait_of_all 
	+ 20926730.8655 * parameters.cpu_usage 
	- 0.025 * parameters.avg_latency_of_same_past_second 
	+ 110942666.4251;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM27(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 60453.0921 * parameters.num_of_wait_locks 
	- 276473.1637 * parameters.total_wait_locks 
	- 2.2468 * parameters.mean_wait_of_all 
	+ 20926730.8655 * parameters.cpu_usage 
	- 0.025 * parameters.avg_latency_of_same_past_second 
	+ 124487590.088;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM28(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0031 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 60453.0921 * parameters.num_of_wait_locks 
	- 261603.6983 * parameters.total_wait_locks 
	- 2.2468 * parameters.mean_wait_of_all 
	+ 20926730.8655 * parameters.cpu_usage 
	- 0.025 * parameters.avg_latency_of_same_past_second 
	+ 122940755.4332;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM29(work_wait &parameters) {
  double actual_remaining = 
	0.9962 * parameters.work_so_far 
	- 0.0185 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 1596315.3862 * parameters.num_of_wait_locks 
	- 127778.5096 * parameters.total_wait_locks 
	- 1.6465 * parameters.mean_wait_of_all 
	+ 20926730.8655 * parameters.cpu_usage 
	- 0.013 * parameters.avg_latency_of_same_past_second 
	+ 77010124.4881;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM30(work_wait &parameters) {
  double actual_remaining = 
	0.9962 * parameters.work_so_far 
	- 0.0235 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 1515235.185 * parameters.num_of_wait_locks 
	- 127778.5096 * parameters.total_wait_locks 
	- 1.6465 * parameters.mean_wait_of_all 
	+ 20926730.8655 * parameters.cpu_usage 
	- 0.013 * parameters.avg_latency_of_same_past_second 
	+ 78629288.7776;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM31(work_wait &parameters) {
  double actual_remaining = 
	0.963 * parameters.work_so_far 
	- 0.0047 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 643778.4059 * parameters.num_of_wait_locks 
	- 127778.5096 * parameters.total_wait_locks 
	- 2.0273 * parameters.mean_wait_of_all 
	+ 20926730.8655 * parameters.cpu_usage 
	- 0.013 * parameters.avg_latency_of_same_past_second 
	+ 90636323.6424;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM32(work_wait &parameters) {
  double actual_remaining = 
	0.963 * parameters.work_so_far 
	- 0.0079 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 643778.4059 * parameters.num_of_wait_locks 
	- 127778.5096 * parameters.total_wait_locks 
	- 1.9797 * parameters.mean_wait_of_all 
	+ 20926730.8655 * parameters.cpu_usage 
	- 0.013 * parameters.avg_latency_of_same_past_second 
	+ 89107328.0979;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM33(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 60453.0921 * parameters.num_of_wait_locks 
	+ 274548.2708 * parameters.total_wait_locks 
	- 0.0005 * parameters.mean_wait_of_all 
	- 150297.518 * parameters.cpu_usage 
	+ 0.0328 * parameters.avg_latency_of_same_past_second 
	- 17746537.8879;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM34(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 1555764.3028 * parameters.num_of_wait_locks 
	+ 1466.14 * parameters.total_wait_locks 
	- 0.4345 * parameters.mean_wait_of_all 
	- 150297.518 * parameters.cpu_usage 
	- 0.0182 * parameters.avg_latency_of_same_past_second 
	+ 40037624.0092;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM35(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0005 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 123819.272 * parameters.num_of_wait_locks 
	+ 1466.14 * parameters.total_wait_locks 
	- 0.0188 * parameters.mean_wait_of_all 
	- 150297.518 * parameters.cpu_usage 
	+ 0.0056 * parameters.avg_latency_of_same_past_second 
	+ 28824437.5285;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM36(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0005 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 123819.272 * parameters.num_of_wait_locks 
	- 210730.3147 * parameters.total_wait_locks 
	- 0.4691 * parameters.mean_wait_of_all 
	- 150297.518 * parameters.cpu_usage 
	+ 0.0139 * parameters.avg_latency_of_same_past_second 
	+ 111737448.2193;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM37(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 62915.1993 * parameters.num_of_wait_locks 
	+ 60978.2017 * parameters.total_wait_locks 
	- 0.0005 * parameters.mean_wait_of_all 
	- 150297.518 * parameters.cpu_usage 
	- 0.2348 * parameters.avg_latency_of_same_past_second 
	+ 83049694.3191;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM38(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 1795680.7217 * parameters.num_of_wait_locks 
	+ 2550.4918 * parameters.total_wait_locks 
	+ 0.1291 * parameters.mean_wait_of_all 
	- 150297.518 * parameters.cpu_usage 
	+ 0.0026 * parameters.avg_latency_of_same_past_second 
	+ 13406503.1842;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM39(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 18487.622 * parameters.num_of_wait_locks 
	- 20602.9672 * parameters.total_wait_locks 
	+ 0.0403 * parameters.mean_wait_of_all 
	- 150297.518 * parameters.cpu_usage 
	+ 0.0003 * parameters.avg_latency_of_same_past_second 
	+ 32923487.97;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM40(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 18487.622 * parameters.num_of_wait_locks 
	- 58009.058 * parameters.total_wait_locks 
	+ 0.0403 * parameters.mean_wait_of_all 
	- 150297.518 * parameters.cpu_usage 
	+ 0.0003 * parameters.avg_latency_of_same_past_second 
	+ 38597628.74;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM41(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 18487.622 * parameters.num_of_wait_locks 
	- 118420.5123 * parameters.total_wait_locks 
	+ 0.0403 * parameters.mean_wait_of_all 
	- 150297.518 * parameters.cpu_usage 
	- 0.1758 * parameters.avg_latency_of_same_past_second 
	+ 140296443.6268;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM42(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 18487.622 * parameters.num_of_wait_locks 
	- 118420.5123 * parameters.total_wait_locks 
	+ 0.0403 * parameters.mean_wait_of_all 
	- 150297.518 * parameters.cpu_usage 
	- 0.2778 * parameters.avg_latency_of_same_past_second 
	+ 203166003.0608;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM43(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 18487.622 * parameters.num_of_wait_locks 
	- 94396.9317 * parameters.total_wait_locks 
	+ 0.0403 * parameters.mean_wait_of_all 
	- 150297.518 * parameters.cpu_usage 
	- 0.0394 * parameters.avg_latency_of_same_past_second 
	+ 70999550.2806;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM44(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 2213218.2453 * parameters.num_of_wait_locks 
	- 582563.0119 * parameters.total_wait_locks 
	+ 0.1455 * parameters.mean_wait_of_all 
	- 150297.518 * parameters.cpu_usage 
	- 0.0591 * parameters.avg_latency_of_same_past_second 
	+ 208631719.8806;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM45(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 18487.622 * parameters.num_of_wait_locks 
	- 484426.5998 * parameters.total_wait_locks 
	+ 0.1455 * parameters.mean_wait_of_all 
	- 150297.518 * parameters.cpu_usage 
	- 0.0591 * parameters.avg_latency_of_same_past_second 
	+ 228422551.4171;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM46(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 18487.622 * parameters.num_of_wait_locks 
	- 540861.654 * parameters.total_wait_locks 
	+ 0.8585 * parameters.mean_wait_of_all 
	- 150297.518 * parameters.cpu_usage 
	- 0.0591 * parameters.avg_latency_of_same_past_second 
	+ 175637922.5193;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM47(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 18487.622 * parameters.num_of_wait_locks 
	- 543426.8838 * parameters.total_wait_locks 
	+ 0.891 * parameters.mean_wait_of_all 
	- 150297.518 * parameters.cpu_usage 
	- 0.0591 * parameters.avg_latency_of_same_past_second 
	+ 179017864.1462;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM48(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0211 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 18487.622 * parameters.num_of_wait_locks 
	+ 307842.7731 * parameters.total_wait_locks 
	- 0.4737 * parameters.mean_wait_of_all 
	+ 365573333.6253 * parameters.cpu_usage 
	- 0.0363 * parameters.avg_latency_of_same_past_second 
	- 351347512.8321;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM49(work_wait &parameters) {
  double actual_remaining = 
	0.0008 * parameters.work_so_far 
	- 0.0074 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 30895.3517 * parameters.num_of_wait_locks 
	- 207850.2364 * parameters.total_wait_locks 
	+ 0.4365 * parameters.mean_wait_of_all 
	- 64322.2723 * parameters.cpu_usage 
	- 0.0422 * parameters.avg_latency_of_same_past_second 
	+ 84304432.4643;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM50(work_wait &parameters) {
  double actual_remaining = 
	0.0008 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 10293980.1197 * parameters.num_of_wait_locks 
	- 990345.6963 * parameters.total_wait_locks 
	+ 2.5952 * parameters.mean_wait_of_all 
	- 64322.2723 * parameters.cpu_usage 
	- 0.0033 * parameters.avg_latency_of_same_past_second 
	+ 121086412.8913;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM51(work_wait &parameters) {
  double actual_remaining = 
	0.0085 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 71326.9001 * parameters.num_of_wait_locks 
	+ 15501.5716 * parameters.total_wait_locks 
	+ 1.0701 * parameters.mean_wait_of_all 
	+ 11560789.2319 * parameters.cpu_usage 
	- 0.0034 * parameters.avg_latency_of_same_past_second 
	- 76506935.2728;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM52(work_wait &parameters) {
  double actual_remaining = 
	0.0085 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 71326.9001 * parameters.num_of_wait_locks 
	+ 26781.0043 * parameters.total_wait_locks 
	- 4.3189 * parameters.mean_wait_of_all 
	- 640310857.699 * parameters.cpu_usage 
	- 0.0034 * parameters.avg_latency_of_same_past_second 
	+ 1036914964.0399;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM53(work_wait &parameters) {
  double actual_remaining = 
	0.2394 * parameters.work_so_far 
	- 0.009 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 71326.9001 * parameters.num_of_wait_locks 
	- 11864.9207 * parameters.total_wait_locks 
	+ 0.0373 * parameters.mean_wait_of_all 
	- 64322.2723 * parameters.cpu_usage 
	- 0.0023 * parameters.avg_latency_of_same_past_second 
	+ 34719239.7732;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM54(work_wait &parameters) {
  double actual_remaining = 
	64.9352 * parameters.work_so_far 
	- 0.7137 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	- 18962991.8884 * parameters.num_of_wait_locks 
	- 219313.5805 * parameters.total_wait_locks 
	+ 2.4128 * parameters.mean_wait_of_all 
	- 64322.2723 * parameters.cpu_usage 
	- 0.0038 * parameters.avg_latency_of_same_past_second 
	+ 50245250.9383;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM55(work_wait &parameters) {
  double actual_remaining = 
	-0.4095 * parameters.work_so_far 
	- 0.4909 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	- 23602359.4456 * parameters.num_of_wait_locks 
	- 219313.5805 * parameters.total_wait_locks 
	+ 2.4128 * parameters.mean_wait_of_all 
	- 64322.2723 * parameters.cpu_usage 
	- 0.0038 * parameters.avg_latency_of_same_past_second 
	+ 58727803.4326;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM56(work_wait &parameters) {
  double actual_remaining = 
	1247.8552 * parameters.work_so_far 
	- 0.0347 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 15788815.3125 * parameters.num_of_wait_locks 
	- 219313.5805 * parameters.total_wait_locks 
	+ 5.2926 * parameters.mean_wait_of_all 
	- 64322.2723 * parameters.cpu_usage 
	+ 0.5728 * parameters.avg_latency_of_same_past_second 
	- 694463689.6553;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM57(work_wait &parameters) {
  double actual_remaining = 
	1375.5587 * parameters.work_so_far 
	- 0.0347 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 16791109.6885 * parameters.num_of_wait_locks 
	- 219313.5805 * parameters.total_wait_locks 
	+ 5.2926 * parameters.mean_wait_of_all 
	- 64322.2723 * parameters.cpu_usage 
	+ 0.5869 * parameters.avg_latency_of_same_past_second 
	- 707316127.4999;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM58(work_wait &parameters) {
  double actual_remaining = 
	1397.9561 * parameters.work_so_far 
	- 0.0347 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 16758115.8689 * parameters.num_of_wait_locks 
	- 219313.5805 * parameters.total_wait_locks 
	+ 5.2926 * parameters.mean_wait_of_all 
	- 64322.2723 * parameters.cpu_usage 
	+ 0.5869 * parameters.avg_latency_of_same_past_second 
	- 707754325.2908;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM59(work_wait &parameters) {
  double actual_remaining = 
	1319.1505 * parameters.work_so_far 
	- 0.0347 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 17106846.0199 * parameters.num_of_wait_locks 
	- 219313.5805 * parameters.total_wait_locks 
	+ 5.2926 * parameters.mean_wait_of_all 
	- 64322.2723 * parameters.cpu_usage 
	+ 0.602 * parameters.avg_latency_of_same_past_second 
	- 710988239.3704;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM60(work_wait &parameters) {
  double actual_remaining = 
	466.5057 * parameters.work_so_far 
	- 0.0343 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 9488422.8708 * parameters.num_of_wait_locks 
	- 105474.221 * parameters.total_wait_locks 
	+ 9.2485 * parameters.mean_wait_of_all 
	- 64322.2723 * parameters.cpu_usage 
	+ 0.4161 * parameters.avg_latency_of_same_past_second 
	- 975161592.6482;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM61(work_wait &parameters) {
  double actual_remaining = 
	-1.7623 * parameters.work_so_far 
	- 0.0248 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 5834711.839 * parameters.num_of_wait_locks 
	- 219313.5805 * parameters.total_wait_locks 
	+ 2.9226 * parameters.mean_wait_of_all 
	- 64322.2723 * parameters.cpu_usage 
	+ 0.34 * parameters.avg_latency_of_same_past_second 
	- 300645305.2076;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM62(work_wait &parameters) {
  double actual_remaining = 
	-0.6296 * parameters.work_so_far 
	- 0.0227 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 3355678.9171 * parameters.num_of_wait_locks 
	- 24337.3907 * parameters.total_wait_locks 
	+ 5.4846 * parameters.mean_wait_of_all 
	- 64322.2723 * parameters.cpu_usage 
	+ 0.1702 * parameters.avg_latency_of_same_past_second 
	- 498059467.1098;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM63(work_wait &parameters) {
  double actual_remaining = 
	0.0008 * parameters.work_so_far 
	- 0.0033 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	- 201532.3966 * parameters.num_of_wait_locks 
	- 141945.3579 * parameters.total_wait_locks 
	+ 5.3642 * parameters.mean_wait_of_all 
	- 64322.2723 * parameters.cpu_usage 
	+ 0.7771 * parameters.avg_latency_of_same_past_second 
	- 694482952.572;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM64(work_wait &parameters) {
  double actual_remaining = 
	0.0008 * parameters.work_so_far 
	- 0.0033 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	- 201532.3966 * parameters.num_of_wait_locks 
	- 141945.3579 * parameters.total_wait_locks 
	+ 0.4907 * parameters.mean_wait_of_all 
	- 64322.2723 * parameters.cpu_usage 
	+ 0.1477 * parameters.avg_latency_of_same_past_second 
	- 12110092.888;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM65(work_wait &parameters) {
  double actual_remaining = 
	0.0008 * parameters.work_so_far 
	+ 0.0072 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	- 879313.2743 * parameters.num_of_wait_locks 
	+ 238004.489 * parameters.total_wait_locks 
	- 2.1388 * parameters.mean_wait_of_all 
	- 64322.2723 * parameters.cpu_usage 
	- 0.0038 * parameters.avg_latency_of_same_past_second 
	+ 138086620.7339;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM66(work_wait &parameters) {
  double actual_remaining = 
	0.0008 * parameters.work_so_far 
	- 0.0276 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	- 14266972.4757 * parameters.num_of_wait_locks 
	- 934293.8843 * parameters.total_wait_locks 
	+ 7.8136 * parameters.mean_wait_of_all 
	- 64322.2723 * parameters.cpu_usage 
	- 0.0038 * parameters.avg_latency_of_same_past_second 
	- 247421152.7167;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM67(work_wait &parameters) {
  double actual_remaining = 
	0.0008 * parameters.work_so_far 
	- 0.0279 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 58398.8392 * parameters.num_of_wait_locks 
	- 29596.1953 * parameters.total_wait_locks 
	+ 1.584 * parameters.mean_wait_of_all 
	- 70037600.8027 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_latency_of_same_past_second 
	- 53281316.8778;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM68(work_wait &parameters) {
  double actual_remaining = 
	5.9542 * parameters.work_so_far 
	+ 0.0406 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 58398.8392 * parameters.num_of_wait_locks 
	- 763659.5491 * parameters.total_wait_locks 
	+ 2.2935 * parameters.mean_wait_of_all 
	- 445620349.5598 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_latency_of_same_past_second 
	+ 556095325.3897;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM69(work_wait &parameters) {
  double actual_remaining = 
	8357.5458 * parameters.work_so_far 
	+ 0.0184 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 58398.8392 * parameters.num_of_wait_locks 
	+ 775895.4913 * parameters.total_wait_locks 
	+ 1.1413 * parameters.mean_wait_of_all 
	- 588579394.7752 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_latency_of_same_past_second 
	- 23664071.1474;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM70(work_wait &parameters) {
  double actual_remaining = 
	-0.1542 * parameters.work_so_far 
	+ 0.0184 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 58398.8392 * parameters.num_of_wait_locks 
	- 609881.5929 * parameters.total_wait_locks 
	+ 1.1413 * parameters.mean_wait_of_all 
	- 588579394.7752 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_latency_of_same_past_second 
	+ 759390001.3278;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM71(work_wait &parameters) {
  double actual_remaining = 
	0.4269 * parameters.work_so_far 
	+ 0.004 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 58398.8392 * parameters.num_of_wait_locks 
	- 985574.5683 * parameters.total_wait_locks 
	+ 4.9919 * parameters.mean_wait_of_all 
	- 1168148750.186 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_latency_of_same_past_second 
	+ 1122787924.0512;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM72(work_wait &parameters) {
  double actual_remaining = 
	-0.5969 * parameters.work_so_far 
	+ 0.004 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 58398.8392 * parameters.num_of_wait_locks 
	- 985574.5683 * parameters.total_wait_locks 
	+ 5.0321 * parameters.mean_wait_of_all 
	- 1168148750.186 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_latency_of_same_past_second 
	+ 1120415710.1232;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM73(work_wait &parameters) {
  double actual_remaining = 
	-0.6074 * parameters.work_so_far 
	+ 0.004 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 58398.8392 * parameters.num_of_wait_locks 
	- 985574.5683 * parameters.total_wait_locks 
	+ 4.6103 * parameters.mean_wait_of_all 
	- 1168148750.186 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_latency_of_same_past_second 
	+ 1160524070.7013;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM74(work_wait &parameters) {
  double actual_remaining = 
	-0.5553 * parameters.work_so_far 
	- 0.0278 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 58398.8392 * parameters.num_of_wait_locks 
	- 985574.5683 * parameters.total_wait_locks 
	+ 5.0803 * parameters.mean_wait_of_all 
	- 1168148750.186 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_latency_of_same_past_second 
	+ 1110846857.7013;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM75(work_wait &parameters) {
  double actual_remaining = 
	-0.6284 * parameters.work_so_far 
	+ 0.0872 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 58398.8392 * parameters.num_of_wait_locks 
	- 1418509.1546 * parameters.total_wait_locks 
	+ 5.6585 * parameters.mean_wait_of_all 
	- 1168148750.186 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_latency_of_same_past_second 
	+ 1240381553.8696;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM76(work_wait &parameters) {
  double actual_remaining = 
	-0.6097 * parameters.work_so_far 
	+ 0.0184 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 58398.8392 * parameters.num_of_wait_locks 
	+ 1003775.3608 * parameters.total_wait_locks 
	+ 1.1413 * parameters.mean_wait_of_all 
	- 1477776069.5048 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_latency_of_same_past_second 
	+ 938532350.5976;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM77(work_wait &parameters) {
  double actual_remaining = 
	0.0008 * parameters.work_so_far 
	- 0.0416 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 58398.8392 * parameters.num_of_wait_locks 
	+ 161271.7435 * parameters.total_wait_locks 
	+ 5.6305 * parameters.mean_wait_of_all 
	- 54540965.8274 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_latency_of_same_past_second 
	- 532492839.8385;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM78(work_wait &parameters) {
  double actual_remaining = 
	-637.4751 * parameters.work_so_far 
	+ 0.1245 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 58398.8392 * parameters.num_of_wait_locks 
	+ 1249518.2212 * parameters.total_wait_locks 
	+ 0.1607 * parameters.mean_wait_of_all 
	- 54540965.8274 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_latency_of_same_past_second 
	- 440749897.8767;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM79(work_wait &parameters) {
  double actual_remaining = 
	0.0008 * parameters.work_so_far 
	+ 0.1613 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 58398.8392 * parameters.num_of_wait_locks 
	+ 1249518.2212 * parameters.total_wait_locks 
	+ 0.1607 * parameters.mean_wait_of_all 
	- 54540965.8274 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_latency_of_same_past_second 
	- 455709807.3499;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM80(work_wait &parameters) {
  double actual_remaining = 
	0.0008 * parameters.work_so_far 
	- 0.0337 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 58398.8392 * parameters.num_of_wait_locks 
	+ 173613.7611 * parameters.total_wait_locks 
	+ 0.1607 * parameters.mean_wait_of_all 
	- 54540965.8274 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_latency_of_same_past_second 
	- 2765892.7241;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM81(work_wait &parameters) {
  double actual_remaining = 
	0.0008 * parameters.work_so_far 
	- 0.0006 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 58398.8392 * parameters.num_of_wait_locks 
	- 29596.1953 * parameters.total_wait_locks 
	+ 0.1607 * parameters.mean_wait_of_all 
	- 54540965.8274 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_latency_of_same_past_second 
	+ 77341324.5396;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM82(work_wait &parameters) {
  double actual_remaining = 
	1.0868 * parameters.work_so_far 
	- 0.0234 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 4118277.8246 * parameters.num_of_wait_locks 
	- 36380.2787 * parameters.total_wait_locks 
	+ 0.1115 * parameters.mean_wait_of_all 
	- 26593054.298 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_latency_of_same_past_second 
	+ 38810847.7866;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM83(work_wait &parameters) {
  double actual_remaining = 
	0.6474 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 78552.244 * parameters.num_of_wait_locks 
	- 49511.4843 * parameters.total_wait_locks 
	+ 0.2135 * parameters.mean_wait_of_all 
	- 2355103.1263 * parameters.cpu_usage 
	- 0.0046 * parameters.avg_latency_of_same_past_second 
	+ 28358064.9617;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM84(work_wait &parameters) {
  double actual_remaining = 
	1.4696 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 78552.244 * parameters.num_of_wait_locks 
	- 209236.2747 * parameters.total_wait_locks 
	- 5.6254 * parameters.mean_wait_of_all 
	- 2355103.1263 * parameters.cpu_usage 
	- 0.0046 * parameters.avg_latency_of_same_past_second 
	+ 701875682.0436;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM85(work_wait &parameters) {
  double actual_remaining = 
	1.2374 * parameters.work_so_far 
	- 0.0063 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 78552.244 * parameters.num_of_wait_locks 
	+ 98983.3839 * parameters.total_wait_locks 
	+ 0.2135 * parameters.mean_wait_of_all 
	- 2355103.1263 * parameters.cpu_usage 
	- 0.0046 * parameters.avg_latency_of_same_past_second 
	- 25897613.1461;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM86(work_wait &parameters) {
  double actual_remaining = 
	1.2374 * parameters.work_so_far 
	- 0.0072 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 78552.244 * parameters.num_of_wait_locks 
	+ 148298.5293 * parameters.total_wait_locks 
	+ 0.2135 * parameters.mean_wait_of_all 
	- 2355103.1263 * parameters.cpu_usage 
	+ 0.1548 * parameters.avg_latency_of_same_past_second 
	- 100430004.4404;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM87(work_wait &parameters) {
  double actual_remaining = 
	0.9315 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 78552.244 * parameters.num_of_wait_locks 
	- 271351.4709 * parameters.total_wait_locks 
	+ 0.2135 * parameters.mean_wait_of_all 
	- 2355103.1263 * parameters.cpu_usage 
	- 0.0046 * parameters.avg_latency_of_same_past_second 
	+ 125807059.1607;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM88(work_wait &parameters) {
  double actual_remaining = 
	0.0008 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 78552.244 * parameters.num_of_wait_locks 
	- 49511.4843 * parameters.total_wait_locks 
	+ 0.2135 * parameters.mean_wait_of_all 
	- 2355103.1263 * parameters.cpu_usage 
	- 0.0022 * parameters.avg_latency_of_same_past_second 
	+ 24599286.6919;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM89(work_wait &parameters) {
  double actual_remaining = 
	0.0008 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 78552.244 * parameters.num_of_wait_locks 
	- 1028927.5651 * parameters.total_wait_locks 
	+ 0.623 * parameters.mean_wait_of_all 
	- 117522089.1552 * parameters.cpu_usage 
	- 0.722 * parameters.avg_latency_of_same_past_second 
	+ 814314705.4228;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM90(work_wait &parameters) {
  double actual_remaining = 
	0.0008 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 78552.244 * parameters.num_of_wait_locks 
	- 167168.3376 * parameters.total_wait_locks 
	+ 0.623 * parameters.mean_wait_of_all 
	- 8772075.2111 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_latency_of_same_past_second 
	+ 46343798.8886;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM91(work_wait &parameters) {
  double actual_remaining = 
	0.0008 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 78552.244 * parameters.num_of_wait_locks 
	- 153879.8979 * parameters.total_wait_locks 
	+ 0.8225 * parameters.mean_wait_of_all 
	- 10827969.2344 * parameters.cpu_usage 
	+ 0.0546 * parameters.avg_latency_of_same_past_second 
	+ 760641.289;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM92(work_wait &parameters) {
  double actual_remaining = 
	0.0008 * parameters.work_so_far 
	+ 0.015 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 78552.244 * parameters.num_of_wait_locks 
	- 153879.8979 * parameters.total_wait_locks 
	+ 5.6055 * parameters.mean_wait_of_all 
	- 45429603.7141 * parameters.cpu_usage 
	+ 0.0443 * parameters.avg_latency_of_same_past_second 
	- 482480015.9957;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM93(work_wait &parameters) {
  double actual_remaining = 
	0.0008 * parameters.work_so_far 
	+ 0.0543 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 78552.244 * parameters.num_of_wait_locks 
	- 153879.8979 * parameters.total_wait_locks 
	+ 5.6055 * parameters.mean_wait_of_all 
	- 35550028.6817 * parameters.cpu_usage 
	+ 0.0443 * parameters.avg_latency_of_same_past_second 
	- 503749988.5493;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM94(work_wait &parameters) {
  double actual_remaining = 
	0.0008 * parameters.work_so_far 
	+ 0.0543 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 78552.244 * parameters.num_of_wait_locks 
	- 153879.8979 * parameters.total_wait_locks 
	+ 5.6055 * parameters.mean_wait_of_all 
	- 35550028.6817 * parameters.cpu_usage 
	+ 0.0443 * parameters.avg_latency_of_same_past_second 
	- 508673855.7874;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM95(work_wait &parameters) {
  double actual_remaining = 
	0.0008 * parameters.work_so_far 
	+ 0.1897 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 78552.244 * parameters.num_of_wait_locks 
	- 153879.8979 * parameters.total_wait_locks 
	+ 9.4774 * parameters.mean_wait_of_all 
	- 55563124.4247 * parameters.cpu_usage 
	+ 0.0443 * parameters.avg_latency_of_same_past_second 
	- 983311125.8428;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM96(work_wait &parameters) {
  double actual_remaining = 
	0.0008 * parameters.work_so_far 
	+ 0.1897 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 78552.244 * parameters.num_of_wait_locks 
	- 153879.8979 * parameters.total_wait_locks 
	+ 9.4774 * parameters.mean_wait_of_all 
	- 55563124.4247 * parameters.cpu_usage 
	+ 0.0443 * parameters.avg_latency_of_same_past_second 
	- 979592781.6762;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM97(work_wait &parameters) {
  double actual_remaining = 
	0.0008 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 78552.244 * parameters.num_of_wait_locks 
	- 153879.8979 * parameters.total_wait_locks 
	+ 0.8225 * parameters.mean_wait_of_all 
	- 10827969.2344 * parameters.cpu_usage 
	+ 0.0443 * parameters.avg_latency_of_same_past_second 
	+ 12558230.1601;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM98(work_wait &parameters) {
  double actual_remaining = 
	0.0008 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 78552.244 * parameters.num_of_wait_locks 
	- 19703.599 * parameters.total_wait_locks 
	- 2.2501 * parameters.mean_wait_of_all 
	+ 309226.4073 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_latency_of_same_past_second 
	+ 274129639.9073;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM99(work_wait &parameters) {
  double actual_remaining = 
	0.0008 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 78552.244 * parameters.num_of_wait_locks 
	+ 219304.391 * parameters.total_wait_locks 
	- 1.3577 * parameters.mean_wait_of_all 
	- 2737837.63 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_latency_of_same_past_second 
	+ 70080632.9895;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM100(work_wait &parameters) {
  double actual_remaining = 
	0.0567 * parameters.work_so_far 
	- 0.0015 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 7581527.5566 * parameters.num_of_wait_locks 
	- 314270.854 * parameters.total_wait_locks 
	+ 5.6344 * parameters.mean_wait_of_all 
	+ 4428998.0132 * parameters.cpu_usage 
	- 0.0777 * parameters.avg_latency_of_same_past_second 
	- 456649744.6623;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM101(work_wait &parameters) {
  double actual_remaining = 
	0.0567 * parameters.work_so_far 
	- 0.0575 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 24751250.3391 * parameters.num_of_wait_locks 
	- 125142.1837 * parameters.total_wait_locks 
	+ 11.2069 * parameters.mean_wait_of_all 
	+ 4428998.0132 * parameters.cpu_usage 
	- 0.2887 * parameters.avg_latency_of_same_past_second 
	- 1053005756.5114;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM102(work_wait &parameters) {
  double actual_remaining = 
	0.0567 * parameters.work_so_far 
	- 0.0575 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 24751250.3391 * parameters.num_of_wait_locks 
	- 125142.1837 * parameters.total_wait_locks 
	+ 11.2069 * parameters.mean_wait_of_all 
	+ 4428998.0132 * parameters.cpu_usage 
	- 0.2887 * parameters.avg_latency_of_same_past_second 
	- 1053211956.8332;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM103(work_wait &parameters) {
  double actual_remaining = 
	0.0567 * parameters.work_so_far 
	- 0.0015 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 24751250.3391 * parameters.num_of_wait_locks 
	- 125142.1837 * parameters.total_wait_locks 
	+ 11.2069 * parameters.mean_wait_of_all 
	+ 4428998.0132 * parameters.cpu_usage 
	- 0.2887 * parameters.avg_latency_of_same_past_second 
	- 1051715977.315;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM104(work_wait &parameters) {
  double actual_remaining = 
	0.0567 * parameters.work_so_far 
	- 0.0015 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 24751250.3391 * parameters.num_of_wait_locks 
	- 125142.1837 * parameters.total_wait_locks 
	+ 11.2069 * parameters.mean_wait_of_all 
	+ 4428998.0132 * parameters.cpu_usage 
	- 0.2887 * parameters.avg_latency_of_same_past_second 
	- 1051706199.7903;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM105(work_wait &parameters) {
  double actual_remaining = 
	0.0567 * parameters.work_so_far 
	- 0.0015 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 25574221.8011 * parameters.num_of_wait_locks 
	+ 159918.3776 * parameters.total_wait_locks 
	+ 11.2069 * parameters.mean_wait_of_all 
	+ 4428998.0132 * parameters.cpu_usage 
	- 0.2887 * parameters.avg_latency_of_same_past_second 
	- 1156843538.42;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM106(work_wait &parameters) {
  double actual_remaining = 
	0.0567 * parameters.work_so_far 
	- 0.0015 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 10615235.6559 * parameters.num_of_wait_locks 
	- 341877.081 * parameters.total_wait_locks 
	+ 10.2039 * parameters.mean_wait_of_all 
	+ 4428998.0132 * parameters.cpu_usage 
	- 0.1267 * parameters.avg_latency_of_same_past_second 
	- 942471373.6123;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM107(work_wait &parameters) {
  double actual_remaining = 
	310.8399 * parameters.work_so_far 
	+ 0.0245 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 16420319.8077 * parameters.num_of_wait_locks 
	- 458445.0782 * parameters.total_wait_locks 
	- 14.1088 * parameters.mean_wait_of_all 
	+ 4428998.0132 * parameters.cpu_usage 
	- 0.1267 * parameters.avg_latency_of_same_past_second 
	+ 1878682957.6925;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM108(work_wait &parameters) {
  double actual_remaining = 
	349.9892 * parameters.work_so_far 
	+ 0.0245 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 16420319.8077 * parameters.num_of_wait_locks 
	- 458445.0782 * parameters.total_wait_locks 
	- 14.1088 * parameters.mean_wait_of_all 
	+ 4428998.0132 * parameters.cpu_usage 
	- 0.1267 * parameters.avg_latency_of_same_past_second 
	+ 1872091300.4407;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM109(work_wait &parameters) {
  double actual_remaining = 
	0.4229 * parameters.work_so_far 
	+ 0.0892 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 15460495.7674 * parameters.num_of_wait_locks 
	- 351013.8302 * parameters.total_wait_locks 
	+ 10.6468 * parameters.mean_wait_of_all 
	+ 4428998.0132 * parameters.cpu_usage 
	- 0.1267 * parameters.avg_latency_of_same_past_second 
	- 970964579.6468;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM110(work_wait &parameters) {
  double actual_remaining = 
	7.8257 * parameters.work_so_far 
	- 0.0016 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 355674.2797 * parameters.num_of_wait_locks 
	- 70643.3802 * parameters.total_wait_locks 
	+ 0.6373 * parameters.mean_wait_of_all 
	+ 1179428.7827 * parameters.cpu_usage 
	+ 0.0746 * parameters.avg_latency_of_same_past_second 
	- 40994584.3255;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM111(work_wait &parameters) {
  double actual_remaining = 
	0.776 * parameters.work_so_far 
	- 0.0016 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 11241164.5608 * parameters.num_of_wait_locks 
	- 70643.3802 * parameters.total_wait_locks 
	- 3.0321 * parameters.mean_wait_of_all 
	+ 1179428.7827 * parameters.cpu_usage 
	+ 0.0606 * parameters.avg_latency_of_same_past_second 
	+ 343608737.6337;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM112(work_wait &parameters) {
  double actual_remaining = 
	0.776 * parameters.work_so_far 
	- 0.0016 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 13266547.2539 * parameters.num_of_wait_locks 
	- 70643.3802 * parameters.total_wait_locks 
	- 3.0321 * parameters.mean_wait_of_all 
	+ 1179428.7827 * parameters.cpu_usage 
	+ 0.0606 * parameters.avg_latency_of_same_past_second 
	+ 341267724.3618;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM113(work_wait &parameters) {
  double actual_remaining = 
	0.585 * parameters.work_so_far 
	- 0.0016 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 1995094.0558 * parameters.num_of_wait_locks 
	- 70643.3802 * parameters.total_wait_locks 
	- 3.0321 * parameters.mean_wait_of_all 
	+ 1179428.7827 * parameters.cpu_usage 
	+ 0.1295 * parameters.avg_latency_of_same_past_second 
	+ 349546029.0092;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM114(work_wait &parameters) {
  double actual_remaining = 
	46.5175 * parameters.work_so_far 
	- 0.0016 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 355674.2797 * parameters.num_of_wait_locks 
	- 70643.3802 * parameters.total_wait_locks 
	- 7.6801 * parameters.mean_wait_of_all 
	+ 1179428.7827 * parameters.cpu_usage 
	+ 0.1173 * parameters.avg_latency_of_same_past_second 
	+ 903546948.5355;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM115(work_wait &parameters) {
  double actual_remaining = 
	0.2264 * parameters.work_so_far 
	- 0.0016 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 355674.2797 * parameters.num_of_wait_locks 
	- 70643.3802 * parameters.total_wait_locks 
	+ 4.0919 * parameters.mean_wait_of_all 
	+ 1179428.7827 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_latency_of_same_past_second 
	- 404152886.4515;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM116(work_wait &parameters) {
  double actual_remaining = 
	0.1115 * parameters.work_so_far 
	- 0.0017 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 355674.2797 * parameters.num_of_wait_locks 
	- 347219.6633 * parameters.total_wait_locks 
	+ 3.4112 * parameters.mean_wait_of_all 
	+ 1179428.7827 * parameters.cpu_usage 
	+ 0.0002 * parameters.avg_latency_of_same_past_second 
	- 189907497.7456;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM117(work_wait &parameters) {
  double actual_remaining = 
	0.1155 * parameters.work_so_far 
	- 0.0177 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 5500712.7398 * parameters.num_of_wait_locks 
	- 81810.3625 * parameters.total_wait_locks 
	+ 145.6746 * parameters.mean_wait_of_all 
	+ 1179428.7827 * parameters.cpu_usage 
	- 0.6263 * parameters.avg_latency_of_same_past_second 
	- 16574624274.3304;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM118(work_wait &parameters) {
  double actual_remaining = 
	0.1155 * parameters.work_so_far 
	- 0.0177 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 5500712.7398 * parameters.num_of_wait_locks 
	- 81810.3625 * parameters.total_wait_locks 
	+ 11.1309 * parameters.mean_wait_of_all 
	+ 1179428.7827 * parameters.cpu_usage 
	- 0.0244 * parameters.avg_latency_of_same_past_second 
	- 1208057063.0057;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM119(work_wait &parameters) {
  double actual_remaining = 
	0.1155 * parameters.work_so_far 
	- 0.0177 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 5500712.7398 * parameters.num_of_wait_locks 
	- 81810.3625 * parameters.total_wait_locks 
	+ 19.795 * parameters.mean_wait_of_all 
	+ 1179428.7827 * parameters.cpu_usage 
	- 0.1283 * parameters.avg_latency_of_same_past_second 
	- 2182539026.8751;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM120(work_wait &parameters) {
  double actual_remaining = 
	0.1155 * parameters.work_so_far 
	- 0.0112 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 3167987.5022 * parameters.num_of_wait_locks 
	- 81810.3625 * parameters.total_wait_locks 
	- 24.7619 * parameters.mean_wait_of_all 
	+ 1179428.7827 * parameters.cpu_usage 
	- 0.1208 * parameters.avg_latency_of_same_past_second 
	+ 3011249067.1078;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM121(work_wait &parameters) {
  double actual_remaining = 
	0.3181 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 11198.7612 * parameters.num_of_wait_locks 
	- 83897.0078 * parameters.total_wait_locks 
	+ 0.024 * parameters.mean_wait_of_all 
	- 64322.2723 * parameters.cpu_usage 
	- 0.0002 * parameters.avg_latency_of_same_past_second 
	+ 74710023.2171;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM122(work_wait &parameters) {
  double actual_remaining = 
	0.0024 * parameters.work_so_far 
	+ 0.0094 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 1964089.6505 * parameters.num_of_wait_locks 
	- 305522.3041 * parameters.total_wait_locks 
	+ 1.3671 * parameters.mean_wait_of_all 
	- 64322.2723 * parameters.cpu_usage 
	- 0.0588 * parameters.avg_latency_of_same_past_second 
	+ 34421624.8343;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM123(work_wait &parameters) {
  double actual_remaining = 
	0.0024 * parameters.work_so_far 
	- 0.0228 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 11198.7612 * parameters.num_of_wait_locks 
	- 29799.9894 * parameters.total_wait_locks 
	- 0.5857 * parameters.mean_wait_of_all 
	- 64322.2723 * parameters.cpu_usage 
	+ 0.0091 * parameters.avg_latency_of_same_past_second 
	+ 123488841.0046;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM124(work_wait &parameters) {
  double actual_remaining = 
	0.0024 * parameters.work_so_far 
	- 0.0085 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 905394.7588 * parameters.num_of_wait_locks 
	+ 256452.23 * parameters.total_wait_locks 
	+ 2.0277 * parameters.mean_wait_of_all 
	- 14600214.925 * parameters.cpu_usage 
	- 0.0485 * parameters.avg_latency_of_same_past_second 
	- 360692701.5641;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM125(work_wait &parameters) {
  double actual_remaining = 
	0.0024 * parameters.work_so_far 
	- 0.008 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 905394.7588 * parameters.num_of_wait_locks 
	+ 256452.23 * parameters.total_wait_locks 
	+ 1.9913 * parameters.mean_wait_of_all 
	- 14600214.925 * parameters.cpu_usage 
	- 0.0613 * parameters.avg_latency_of_same_past_second 
	- 349465961.2194;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM126(work_wait &parameters) {
  double actual_remaining = 
	0.0024 * parameters.work_so_far 
	+ 0.0031 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 905394.7588 * parameters.num_of_wait_locks 
	+ 375621.0554 * parameters.total_wait_locks 
	+ 2.824 * parameters.mean_wait_of_all 
	- 67239737.3262 * parameters.cpu_usage 
	- 0.0536 * parameters.avg_latency_of_same_past_second 
	- 484246843.1829;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM127(work_wait &parameters) {
  double actual_remaining = 
	0.0024 * parameters.work_so_far 
	+ 0.0031 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 905394.7588 * parameters.num_of_wait_locks 
	+ 375621.0554 * parameters.total_wait_locks 
	+ 2.824 * parameters.mean_wait_of_all 
	- 70164155.2374 * parameters.cpu_usage 
	- 0.0536 * parameters.avg_latency_of_same_past_second 
	- 482700080.2405;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM128(work_wait &parameters) {
  double actual_remaining = 
	0.0024 * parameters.work_so_far 
	+ 0.002 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 603131.323 * parameters.num_of_wait_locks 
	+ 63696.0655 * parameters.total_wait_locks 
	- 1.6427 * parameters.mean_wait_of_all 
	- 9686673.7466 * parameters.cpu_usage 
	+ 0.0073 * parameters.avg_latency_of_same_past_second 
	+ 208183993.7868;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM129(work_wait &parameters) {
  double actual_remaining = 
	0.0024 * parameters.work_so_far 
	- 0.0556 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 2713002.4358 * parameters.num_of_wait_locks 
	- 110386.5503 * parameters.total_wait_locks 
	+ 10.4552 * parameters.mean_wait_of_all 
	- 64322.2723 * parameters.cpu_usage 
	- 0.1082 * parameters.avg_latency_of_same_past_second 
	- 1174409996.018;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM130(work_wait &parameters) {
  double actual_remaining = 
	0.0024 * parameters.work_so_far 
	- 0.0556 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 11198.7612 * parameters.num_of_wait_locks 
	- 110386.5503 * parameters.total_wait_locks 
	+ 6.4246 * parameters.mean_wait_of_all 
	- 64322.2723 * parameters.cpu_usage 
	- 0.1082 * parameters.avg_latency_of_same_past_second 
	- 652139119.2513;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM131(work_wait &parameters) {
  double actual_remaining = 
	0.0024 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 11198.7612 * parameters.num_of_wait_locks 
	- 110386.5503 * parameters.total_wait_locks 
	- 2.7837 * parameters.mean_wait_of_all 
	- 64322.2723 * parameters.cpu_usage 
	- 0.0028 * parameters.avg_latency_of_same_past_second 
	+ 457183988.8439;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM132(work_wait &parameters) {
  double actual_remaining = 
	0.0024 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 11198.7612 * parameters.num_of_wait_locks 
	- 35106.7087 * parameters.total_wait_locks 
	- 16.1694 * parameters.mean_wait_of_all 
	- 64322.2723 * parameters.cpu_usage 
	+ 0.3025 * parameters.avg_latency_of_same_past_second 
	+ 2047569692.3944;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM133(work_wait &parameters) {
  double actual_remaining = 
	0.0024 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	+ 22122.331 * parameters.num_locks_so_far 
	+ 11198.7612 * parameters.num_of_wait_locks 
	- 28551.9661 * parameters.total_wait_locks 
	- 8.2813 * parameters.mean_wait_of_all 
	- 64322.2723 * parameters.cpu_usage 
	+ 0.0237 * parameters.avg_latency_of_same_past_second 
	+ 1101458838.9395;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM134(work_wait &parameters) {
  double actual_remaining = 
	1812.9441 * parameters.work_so_far 
	- 0.0032 * parameters.wait_so_far 
	+ 18514.9342 * parameters.num_locks_so_far 
	+ 3548338.4166 * parameters.num_of_wait_locks 
	+ 259146.7823 * parameters.total_wait_locks 
	+ 0.189 * parameters.mean_wait_of_all 
	- 91002008.3975 * parameters.cpu_usage 
	+ 0.0012 * parameters.avg_latency_of_same_past_second 
	+ 55814739.8717;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM135(work_wait &parameters) {
  double actual_remaining = 
	0.9748 * parameters.work_so_far 
	- 0.1798 * parameters.wait_so_far 
	+ 18514.9342 * parameters.num_locks_so_far 
	+ 70237.3417 * parameters.num_of_wait_locks 
	+ 716044.1406 * parameters.total_wait_locks 
	- 0.0029 * parameters.mean_wait_of_all 
	- 108174489.2155 * parameters.cpu_usage 
	- 0.0966 * parameters.avg_latency_of_same_past_second 
	+ 198808320.2716;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM136(work_wait &parameters) {
  double actual_remaining = 
	4902.4577 * parameters.work_so_far 
	- 0.003 * parameters.wait_so_far 
	+ 135.3228 * parameters.num_locks_so_far 
	- 165490.2459 * parameters.num_of_wait_locks 
	+ 163867.753 * parameters.total_wait_locks 
	- 0.5333 * parameters.mean_wait_of_all 
	+ 146731030.9152 * parameters.cpu_usage 
	+ 0.1171 * parameters.avg_latency_of_same_past_second 
	- 176207219.4115;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM137(work_wait &parameters) {
  double actual_remaining = 
	0.0381 * parameters.work_so_far 
	- 0.0049 * parameters.wait_so_far 
	- 52682.09 * parameters.num_locks_so_far 
	- 459114.4331 * parameters.num_of_wait_locks 
	+ 49243.7945 * parameters.total_wait_locks 
	- 0.1512 * parameters.mean_wait_of_all 
	- 508525952.4234 * parameters.cpu_usage 
	- 0.1804 * parameters.avg_latency_of_same_past_second 
	+ 797209859.5084;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM138(work_wait &parameters) {
  double actual_remaining = 
	0.0381 * parameters.work_so_far 
	- 0.0049 * parameters.wait_so_far 
	- 52682.09 * parameters.num_locks_so_far 
	- 62000453.3893 * parameters.num_of_wait_locks 
	+ 25125.5458 * parameters.total_wait_locks 
	- 0.5478 * parameters.mean_wait_of_all 
	- 745950.0199 * parameters.cpu_usage 
	+ 0.0059 * parameters.avg_latency_of_same_past_second 
	+ 690859977.327;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM139(work_wait &parameters) {
  double actual_remaining = 
	0.0381 * parameters.work_so_far 
	- 0.0049 * parameters.wait_so_far 
	- 52682.09 * parameters.num_locks_so_far 
	- 459114.4331 * parameters.num_of_wait_locks 
	+ 25125.5458 * parameters.total_wait_locks 
	- 0.2072 * parameters.mean_wait_of_all 
	- 745950.0199 * parameters.cpu_usage 
	+ 0.0059 * parameters.avg_latency_of_same_past_second 
	+ 297137737.7038;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM140(work_wait &parameters) {
  double actual_remaining = 
	3.7883 * parameters.work_so_far 
	- 0.0049 * parameters.wait_so_far 
	- 2203568.724 * parameters.num_locks_so_far 
	- 1385426.2608 * parameters.num_of_wait_locks 
	- 3616640.2853 * parameters.total_wait_locks 
	- 0.2661 * parameters.mean_wait_of_all 
	+ 531898746.9786 * parameters.cpu_usage 
	+ 0.0763 * parameters.avg_latency_of_same_past_second 
	+ 1181505405.8405;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM141(work_wait &parameters) {
  double actual_remaining = 
	0.1257 * parameters.work_so_far 
	- 0.0049 * parameters.wait_so_far 
	- 192620.1739 * parameters.num_locks_so_far 
	- 1385426.2608 * parameters.num_of_wait_locks 
	+ 34231.5418 * parameters.total_wait_locks 
	- 0.2661 * parameters.mean_wait_of_all 
	+ 182116943.2441 * parameters.cpu_usage 
	+ 0.0975 * parameters.avg_latency_of_same_past_second 
	+ 217269087.3871;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM142(work_wait &parameters) {
  double actual_remaining = 
	0.1257 * parameters.work_so_far 
	- 0.0049 * parameters.wait_so_far 
	- 192620.1739 * parameters.num_locks_so_far 
	- 1385426.2608 * parameters.num_of_wait_locks 
	+ 34231.5418 * parameters.total_wait_locks 
	- 0.2661 * parameters.mean_wait_of_all 
	+ 313799553.2945 * parameters.cpu_usage 
	- 1.3356 * parameters.avg_latency_of_same_past_second 
	+ 1248897138.3463;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM143(work_wait &parameters) {
  double actual_remaining = 
	0.1257 * parameters.work_so_far 
	- 0.0049 * parameters.wait_so_far 
	- 192620.1739 * parameters.num_locks_so_far 
	- 1385426.2608 * parameters.num_of_wait_locks 
	+ 34231.5418 * parameters.total_wait_locks 
	- 0.2661 * parameters.mean_wait_of_all 
	+ 313799553.2945 * parameters.cpu_usage 
	- 0.7455 * parameters.avg_latency_of_same_past_second 
	+ 740569694.91;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM144(work_wait &parameters) {
  double actual_remaining = 
	1.5181 * parameters.work_so_far 
	- 0.0049 * parameters.wait_so_far 
	- 84349.9497 * parameters.num_locks_so_far 
	- 16622441.5501 * parameters.num_of_wait_locks 
	+ 658905.3282 * parameters.total_wait_locks 
	- 4.1793 * parameters.mean_wait_of_all 
	- 745950.0199 * parameters.cpu_usage 
	+ 0.0051 * parameters.avg_latency_of_same_past_second 
	+ 532522530.9697;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM145(work_wait &parameters) {
  double actual_remaining = 
	0.0183 * parameters.work_so_far 
	- 0.0074 * parameters.wait_so_far 
	- 30648.8535 * parameters.num_locks_so_far 
	- 19828357.5868 * parameters.num_of_wait_locks 
	- 842350.5547 * parameters.total_wait_locks 
	+ 3.8838 * parameters.mean_wait_of_all 
	- 228005826.759 * parameters.cpu_usage 
	+ 0.0041 * parameters.avg_latency_of_same_past_second 
	+ 557135614.3389;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM146(work_wait &parameters) {
  double actual_remaining = 
	0.6778 * parameters.work_so_far 
	- 0.0959 * parameters.wait_so_far 
	- 19083802.2637 * parameters.num_locks_so_far 
	- 26536187.693 * parameters.num_of_wait_locks 
	- 646236.2526 * parameters.total_wait_locks 
	+ 2.7611 * parameters.mean_wait_of_all 
	- 193593352.5589 * parameters.cpu_usage 
	+ 0.0014 * parameters.avg_latency_of_same_past_second 
	+ 598104102.2584;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
tpcc_estimate(work_wait &parameters){

  if (parameters.num_locks_so_far <= 3) {

    if (parameters.total_wait_locks <= 283.5) {

      if (parameters.work_so_far <= 9779) {

        if (parameters.wait_so_far <= 14847738) {
          return tpcc_LM1(parameters);
        } else {

          if (parameters.work_so_far <= 7035.5) {

            if (parameters.wait_so_far <= 63895135.5) {
              return tpcc_LM2(parameters);
            } else {

              if (parameters.wait_so_far <= 199456039.5) {
                return tpcc_LM3(parameters);
              } else {
                return tpcc_LM4(parameters);
              }
            }
          } else {

            if (parameters.avg_latency_of_same_past_second <= 46542050) {

              if (parameters.avg_latency_of_same_past_second <= 34116600) {

                if (parameters.total_wait_locks <= 51.5) {
                  return tpcc_LM5(parameters);
                } else {

                  if (parameters.mean_wait_of_all <= 38871950) {
                    return tpcc_LM6(parameters);
                  } else {
                    return tpcc_LM7(parameters);
                  }
                }
              } else {

                if (parameters.mean_wait_of_all <= 40409900) {
                  return tpcc_LM8(parameters);
                } else {
                  return tpcc_LM9(parameters);
                }
              }
            } else {

              if (parameters.cpu_usage <= 0.91) {
                return tpcc_LM10(parameters);
              } else {

                if (parameters.cpu_usage <= 0.997) {

                  if (parameters.total_wait_locks <= 55) {

                    if (parameters.wait_so_far <= 95251810) {
                      return tpcc_LM11(parameters);
                    } else {
                      return tpcc_LM12(parameters);
                    }
                  } else {

                    if (parameters.work_so_far <= 8966) {

                      if (parameters.total_wait_locks <= 89.5) {

                        if (parameters.mean_wait_of_all <= 35798250) {
                          return tpcc_LM13(parameters);
                        } else {

                          if (parameters.mean_wait_of_all <= 38682000) {
                            return tpcc_LM14(parameters);
                          } else {

                            if (parameters.mean_wait_of_all <= 40150350) {
                              return tpcc_LM15(parameters);
                            } else {
                              return tpcc_LM16(parameters);
                            }
                          }
                        }
                      } else {
                        return tpcc_LM17(parameters);
                      }
                    } else {
                      return tpcc_LM18(parameters);
                    }
                  }
                } else {
                  return tpcc_LM19(parameters);
                }
              }
            }
          }
        }
      } else {

        if (parameters.avg_latency_of_same_past_second <= 46293450) {
          return tpcc_LM20(parameters);
        } else {

          if (parameters.total_wait_locks <= 119.5) {

            if (parameters.avg_latency_of_same_past_second <= 69023350) {
              return tpcc_LM21(parameters);
            } else {

              if (parameters.total_wait_locks <= 92.5) {
                return tpcc_LM22(parameters);
              } else {

                if (parameters.mean_wait_of_all <= 38299150) {

                  if (parameters.total_wait_locks <= 95.5) {

                    if (parameters.mean_wait_of_all <= 38279850) {
                      return tpcc_LM23(parameters);
                    } else {
                      return tpcc_LM24(parameters);
                    }
                  } else {

                    if (parameters.cpu_usage <= 0.997) {
                      return tpcc_LM25(parameters);
                    } else {

                      if (parameters.avg_latency_of_same_past_second <= 263505500) {

                        if (parameters.mean_wait_of_all <= 33679500) {
                          return tpcc_LM26(parameters);
                        } else {

                          if (parameters.total_wait_locks <= 100.5) {
                            return tpcc_LM27(parameters);
                          } else {
                            return tpcc_LM28(parameters);
                          }
                        }
                      } else {

                        if (parameters.work_so_far <= 21175.5) {

                          if (parameters.num_of_wait_locks <= 3.5) {
                            return tpcc_LM29(parameters);
                          } else {
                            return tpcc_LM30(parameters);
                          }
                        } else {

                          if (parameters.mean_wait_of_all <= 35765800) {
                            return tpcc_LM31(parameters);
                          } else {
                            return tpcc_LM32(parameters);
                          }
                        }
                      }
                    }
                  }
                } else {
                  return tpcc_LM33(parameters);
                }
              }
            }
          } else {

            if (parameters.avg_latency_of_same_past_second <= 368109000) {

              if (parameters.avg_latency_of_same_past_second <= 287016500) {

                if (parameters.mean_wait_of_all <= 43053700) {
                  return tpcc_LM34(parameters);
                } else {

                  if (parameters.avg_latency_of_same_past_second <= 240182500) {
                    return tpcc_LM35(parameters);
                  } else {
                    return tpcc_LM36(parameters);
                  }
                }
              } else {

                if (parameters.avg_latency_of_same_past_second <= 333230500) {
                  return tpcc_LM37(parameters);
                } else {
                  return tpcc_LM38(parameters);
                }
              }
            } else {

              if (parameters.mean_wait_of_all <= 56496350) {

                if (parameters.cpu_usage <= 0.964) {
                  return tpcc_LM39(parameters);
                } else {

                  if (parameters.avg_latency_of_same_past_second <= 380387000) {
                    return tpcc_LM40(parameters);
                  } else {

                    if (parameters.mean_wait_of_all <= 49939050) {

                      if (parameters.mean_wait_of_all <= 45379400) {
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

                if (parameters.cpu_usage <= 0.954) {

                  if (parameters.mean_wait_of_all <= 60125450) {
                    return tpcc_LM44(parameters);
                  } else {

                    if (parameters.mean_wait_of_all <= 60232850) {
                      return tpcc_LM45(parameters);
                    } else {

                      if (parameters.mean_wait_of_all <= 70935600) {
                        return tpcc_LM46(parameters);
                      } else {
                        return tpcc_LM47(parameters);
                      }
                    }
                  }
                } else {
                  return tpcc_LM48(parameters);
                }
              }
            }
          }
        }
      }
    } else {

      if (parameters.mean_wait_of_all <= 116959500) {

        if (parameters.mean_wait_of_all <= 90253350) {

          if (parameters.mean_wait_of_all <= 76118350) {
            return tpcc_LM49(parameters);
          } else {

            if (parameters.total_wait_locks <= 340.5) {
              return tpcc_LM50(parameters);
            } else {

              if (parameters.avg_latency_of_same_past_second <= 378415000) {

                if (parameters.cpu_usage <= 0.964) {
                  return tpcc_LM51(parameters);
                } else {
                  return tpcc_LM52(parameters);
                }
              } else {
                return tpcc_LM53(parameters);
              }
            }
          }
        } else {

          if (parameters.mean_wait_of_all <= 111001500) {

            if (parameters.total_wait_locks <= 413.5) {

              if (parameters.avg_latency_of_same_past_second <= 487436500) {

                if (parameters.total_wait_locks <= 387.5) {

                  if (parameters.wait_so_far <= 94201127.5) {

                    if (parameters.wait_so_far <= 27241363) {
                      return tpcc_LM54(parameters);
                    } else {
                      return tpcc_LM55(parameters);
                    }
                  } else {

                    if (parameters.mean_wait_of_all <= 97111550) {

                      if (parameters.work_so_far <= 64265) {

                        if (parameters.wait_so_far <= 538292283) {

                          if (parameters.work_so_far <= 26934.5) {
                            return tpcc_LM56(parameters);
                          } else {

                            if (parameters.avg_latency_of_same_past_second <= 483154000) {

                              if (parameters.num_of_wait_locks <= 3.5) {
                                return tpcc_LM57(parameters);
                              } else {
                                return tpcc_LM58(parameters);
                              }
                            } else {
                              return tpcc_LM59(parameters);
                            }
                          }
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
                } else {

                  if (parameters.avg_latency_of_same_past_second <= 388598500) {
                    return tpcc_LM63(parameters);
                  } else {
                    return tpcc_LM64(parameters);
                  }
                }
              } else {

                if (parameters.work_so_far <= 41756) {
                  return tpcc_LM65(parameters);
                } else {
                  return tpcc_LM66(parameters);
                }
              }
            } else {

              if (parameters.wait_so_far <= 354114141) {

                if (parameters.mean_wait_of_all <= 107292500) {

                  if (parameters.cpu_usage <= 0.907) {
                    return tpcc_LM67(parameters);
                  } else {

                    if (parameters.cpu_usage <= 0.979) {

                      if (parameters.wait_so_far <= 35869663.5) {
                        return tpcc_LM68(parameters);
                      } else {

                        if (parameters.work_so_far <= 33535) {

                          if (parameters.work_so_far <= 26359.5) {
                            return tpcc_LM69(parameters);
                          } else {
                            return tpcc_LM70(parameters);
                          }
                        } else {

                          if (parameters.cpu_usage <= 0.967) {

                            if (parameters.wait_so_far <= 269862809.5) {

                              if (parameters.wait_so_far <= 153443493) {

                                if (parameters.mean_wait_of_all <= 104682500) {

                                  if (parameters.mean_wait_of_all <= 104256000) {
                                    return tpcc_LM71(parameters);
                                  } else {
                                    return tpcc_LM72(parameters);
                                  }
                                } else {
                                  return tpcc_LM73(parameters);
                                }
                              } else {
                                return tpcc_LM74(parameters);
                              }
                            } else {
                              return tpcc_LM75(parameters);
                            }
                          } else {
                            return tpcc_LM76(parameters);
                          }
                        }
                      }
                    } else {

                      if (parameters.mean_wait_of_all <= 101696500) {

                        if (parameters.work_so_far <= 32197.5) {

                          if (parameters.total_wait_locks <= 431.5) {
                            return tpcc_LM77(parameters);
                          } else {

                            if (parameters.wait_so_far <= 178800397.5) {
                              return tpcc_LM78(parameters);
                            } else {
                              return tpcc_LM79(parameters);
                            }
                          }
                        } else {
                          return tpcc_LM80(parameters);
                        }
                      } else {
                        return tpcc_LM81(parameters);
                      }
                    }
                  }
                } else {
                  return tpcc_LM82(parameters);
                }
              } else {

                if (parameters.mean_wait_of_all <= 103738000) {

                  if (parameters.avg_latency_of_same_past_second <= 368935000) {

                    if (parameters.mean_wait_of_all <= 100788000) {
                      return tpcc_LM83(parameters);
                    } else {

                      if (parameters.total_wait_locks <= 435.5) {

                        if (parameters.mean_wait_of_all <= 101970000) {
                          return tpcc_LM84(parameters);
                        } else {

                          if (parameters.total_wait_locks <= 432.5) {
                            return tpcc_LM85(parameters);
                          } else {
                            return tpcc_LM86(parameters);
                          }
                        }
                      } else {
                        return tpcc_LM87(parameters);
                      }
                    }
                  } else {
                    return tpcc_LM88(parameters);
                  }
                } else {

                  if (parameters.mean_wait_of_all <= 109293000) {

                    if (parameters.mean_wait_of_all <= 107219500) {

                      if (parameters.avg_latency_of_same_past_second <= 406816000) {
                        return tpcc_LM89(parameters);
                      } else {
                        return tpcc_LM90(parameters);
                      }
                    } else {

                      if (parameters.avg_latency_of_same_past_second <= 415107500) {
                        return tpcc_LM91(parameters);
                      } else {

                        if (parameters.wait_so_far <= 815618256) {

                          if (parameters.wait_so_far <= 547309813.5) {

                            if (parameters.wait_so_far <= 445771448.5) {

                              if (parameters.wait_so_far <= 430380580.5) {
                                return tpcc_LM92(parameters);
                              } else {
                                return tpcc_LM93(parameters);
                              }
                            } else {
                              return tpcc_LM94(parameters);
                            }
                          } else {

                            if (parameters.wait_so_far <= 677767864.5) {
                              return tpcc_LM95(parameters);
                            } else {
                              return tpcc_LM96(parameters);
                            }
                          }
                        } else {
                          return tpcc_LM97(parameters);
                        }
                      }
                    }
                  } else {

                    if (parameters.cpu_usage <= 0.957) {
                      return tpcc_LM98(parameters);
                    } else {
                      return tpcc_LM99(parameters);
                    }
                  }
                }
              }
            }
          } else {

            if (parameters.total_wait_locks <= 479.5) {

              if (parameters.avg_latency_of_same_past_second <= 324939000) {
                return tpcc_LM100(parameters);
              } else {

                if (parameters.mean_wait_of_all <= 111052000) {

                  if (parameters.num_of_wait_locks <= 4.5) {

                    if (parameters.wait_so_far <= 153580307) {

                      if (parameters.work_so_far <= 32788) {

                        if (parameters.wait_so_far <= 15457538.5) {
                          return tpcc_LM101(parameters);
                        } else {
                          return tpcc_LM102(parameters);
                        }
                      } else {
                        return tpcc_LM103(parameters);
                      }
                    } else {
                      return tpcc_LM104(parameters);
                    }
                  } else {
                    return tpcc_LM105(parameters);
                  }
                } else {

                  if (parameters.mean_wait_of_all <= 113708500) {
                    return tpcc_LM106(parameters);
                  } else {

                    if (parameters.avg_latency_of_same_past_second <= 440092000) {

                      if (parameters.mean_wait_of_all <= 114149500) {
                        return tpcc_LM107(parameters);
                      } else {
                        return tpcc_LM108(parameters);
                      }
                    } else {
                      return tpcc_LM109(parameters);
                    }
                  }
                }
              }
            } else {

              if (parameters.mean_wait_of_all <= 115676000) {

                if (parameters.wait_so_far <= 241530418.5) {

                  if (parameters.total_wait_locks <= 497.5) {

                    if (parameters.mean_wait_of_all <= 112682000) {
                      return tpcc_LM110(parameters);
                    } else {

                      if (parameters.total_wait_locks <= 495.5) {

                        if (parameters.mean_wait_of_all <= 113059000) {

                          if (parameters.num_of_wait_locks <= 5.5) {
                            return tpcc_LM111(parameters);
                          } else {
                            return tpcc_LM112(parameters);
                          }
                        } else {
                          return tpcc_LM113(parameters);
                        }
                      } else {
                        return tpcc_LM114(parameters);
                      }
                    }
                  } else {
                    return tpcc_LM115(parameters);
                  }
                } else {
                  return tpcc_LM116(parameters);
                }
              } else {

                if (parameters.avg_latency_of_same_past_second <= 519445000) {

                  if (parameters.wait_so_far <= 313524624.5) {
                    return tpcc_LM117(parameters);
                  } else {

                    if (parameters.work_so_far <= 33489) {
                      return tpcc_LM118(parameters);
                    } else {
                      return tpcc_LM119(parameters);
                    }
                  }
                } else {
                  return tpcc_LM120(parameters);
                }
              }
            }
          }
        }
      } else {

        if (parameters.wait_so_far <= 212922053) {
          return tpcc_LM121(parameters);
        } else {

          if (parameters.mean_wait_of_all <= 126764500) {
            return tpcc_LM122(parameters);
          } else {

            if (parameters.avg_latency_of_same_past_second <= 338725500) {
              return tpcc_LM123(parameters);
            } else {

              if (parameters.cpu_usage <= 0.957) {

                if (parameters.wait_so_far <= 397097003.5) {

                  if (parameters.total_wait_locks <= 595.5) {

                    if (parameters.mean_wait_of_all <= 128996500) {
                      return tpcc_LM124(parameters);
                    } else {
                      return tpcc_LM125(parameters);
                    }
                  } else {

                    if (parameters.cpu_usage <= 0.831) {
                      return tpcc_LM126(parameters);
                    } else {
                      return tpcc_LM127(parameters);
                    }
                  }
                } else {
                  return tpcc_LM128(parameters);
                }
              } else {

                if (parameters.mean_wait_of_all <= 129418000) {

                  if (parameters.avg_latency_of_same_past_second <= 380992500) {

                    if (parameters.work_so_far <= 30602) {

                      if (parameters.wait_so_far <= 467500759.5) {
                        return tpcc_LM129(parameters);
                      } else {
                        return tpcc_LM130(parameters);
                      }
                    } else {
                      return tpcc_LM131(parameters);
                    }
                  } else {
                    return tpcc_LM132(parameters);
                  }
                } else {
                  return tpcc_LM133(parameters);
                }
              }
            }
          }
        }
      }
    }
  } else {

    if (parameters.total_wait_locks <= 165.5) {

      if (parameters.work_so_far <= 34763.5) {
        return tpcc_LM134(parameters);
      } else {
        return tpcc_LM135(parameters);
      }
    } else {

      if (parameters.wait_so_far <= 229877842.5) {

        if (parameters.work_so_far <= 50975.5) {
          return tpcc_LM136(parameters);
        } else {

          if (parameters.wait_so_far <= 101704861.5) {

            if (parameters.total_wait_locks <= 350.5) {

              if (parameters.mean_wait_of_all <= 48556500) {
                return tpcc_LM137(parameters);
              } else {

                if (parameters.mean_wait_of_all <= 56248200) {
                  return tpcc_LM138(parameters);
                } else {
                  return tpcc_LM139(parameters);
                }
              }
            } else {

              if (parameters.mean_wait_of_all <= 95049000) {

                if (parameters.avg_latency_of_same_past_second <= 546421000) {
                  return tpcc_LM140(parameters);
                } else {

                  if (parameters.mean_wait_of_all <= 92479050) {
                    return tpcc_LM141(parameters);
                  } else {

                    if (parameters.avg_latency_of_same_past_second <= 604991000) {
                      return tpcc_LM142(parameters);
                    } else {
                      return tpcc_LM143(parameters);
                    }
                  }
                }
              } else {
                return tpcc_LM144(parameters);
              }
            }
          } else {
            return tpcc_LM145(parameters);
          }
        }
      } else {
        return tpcc_LM146(parameters);
      }
    }
  }
}