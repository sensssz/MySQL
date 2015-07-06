#include "my_global.h"
#include "m5p.h"
#include "trace_tool.h"

static
double
new_order_LM1(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0478 * parameters.wait_so_far 
	- 1823921.5889 * parameters.num_locks_so_far 
	+ 214521.5494 * parameters.total_wait_locks 
	- 0.2723 * parameters.mean_wait_of_all 
	- 32677567.2926 * parameters.cpu_usage 
	+ 0.2732 * parameters.avg_work_of_same_past_second 
	- 0.1833 * parameters.avg_wait_of_same_past_second 
	+ 0.2228 * parameters.avg_latency_of_same_last_20 
	+ 76559972.1323;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM2(work_wait &parameters) {
  double actual_remaining = 
	0.3327 * parameters.work_so_far 
	- 0.2591 * parameters.wait_so_far 
	- 6498328.4027 * parameters.num_locks_so_far 
	- 169553.7468 * parameters.total_wait_locks 
	+ 1.3135 * parameters.mean_wait_of_all 
	+ 0.2486 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.1853 * parameters.avg_latency_of_same_last_20 
	+ 148289462.2076;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM3(work_wait &parameters) {
  double actual_remaining = 
	0.0953 * parameters.work_so_far 
	- 0.0428 * parameters.wait_so_far 
	- 2664234.7441 * parameters.num_locks_so_far 
	- 63523.4354 * parameters.total_wait_locks 
	+ 1.0537 * parameters.mean_wait_of_all 
	+ 0.2107 * parameters.avg_work_of_same_past_second 
	- 0.1202 * parameters.avg_wait_of_same_past_second 
	+ 0.1217 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 52821969.0523;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM4(work_wait &parameters) {
  double actual_remaining = 
	2.0629 * parameters.work_so_far 
	- 0.0397 * parameters.wait_so_far 
	- 193423.1605 * parameters.num_locks_so_far 
	- 281349.4979 * parameters.total_wait_locks 
	+ 2.1112 * parameters.mean_wait_of_all 
	+ 0.0672 * parameters.avg_work_of_same_past_second 
	- 0.889 * parameters.avg_wait_of_same_past_second 
	+ 0.019 * parameters.avg_latency_of_same_last_20 
	- 0.0042 * parameters.max_latency_of_same_last_50 
	+ 301271378.5765;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM5(work_wait &parameters) {
  double actual_remaining = 
	9.4629 * parameters.work_so_far 
	- 0.0739 * parameters.wait_so_far 
	- 193423.1605 * parameters.num_locks_so_far 
	- 716431.7145 * parameters.total_wait_locks 
	+ 1.8656 * parameters.mean_wait_of_all 
	+ 0.0672 * parameters.avg_work_of_same_past_second 
	- 0.6855 * parameters.avg_wait_of_same_past_second 
	+ 0.019 * parameters.avg_latency_of_same_last_20 
	- 0.4666 * parameters.max_latency_of_same_last_50 
	+ 1369872732.9551;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM6(work_wait &parameters) {
  double actual_remaining = 
	1.6655 * parameters.work_so_far 
	- 0.2242 * parameters.wait_so_far 
	- 193423.1605 * parameters.num_locks_so_far 
	+ 58468.1933 * parameters.total_wait_locks 
	+ 1.3399 * parameters.mean_wait_of_all 
	+ 2.4726 * parameters.avg_work_of_same_past_second 
	- 0.3862 * parameters.avg_wait_of_same_past_second 
	+ 0.019 * parameters.avg_latency_of_same_last_20 
	- 0.0208 * parameters.max_latency_of_same_last_50 
	- 47883043.8116;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM7(work_wait &parameters) {
  double actual_remaining = 
	0.001 * parameters.work_so_far 
	- 0.0976 * parameters.wait_so_far 
	- 193423.1605 * parameters.num_locks_so_far 
	- 16423.255 * parameters.total_wait_locks 
	+ 0.1378 * parameters.mean_wait_of_all 
	+ 0.8593 * parameters.avg_work_of_same_past_second 
	- 0.4933 * parameters.avg_wait_of_same_past_second 
	+ 0.1141 * parameters.avg_latency_of_same_last_20 
	- 0.0021 * parameters.max_latency_of_same_last_50 
	+ 173525762.4382;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM8(work_wait &parameters) {
  double actual_remaining = 
	0.001 * parameters.work_so_far 
	+ 0.1086 * parameters.wait_so_far 
	- 461791.2784 * parameters.num_locks_so_far 
	- 41762.9602 * parameters.total_wait_locks 
	+ 0.3373 * parameters.mean_wait_of_all 
	+ 0.0433 * parameters.avg_work_of_same_past_second 
	- 0.0461 * parameters.avg_wait_of_same_past_second 
	+ 0.0383 * parameters.avg_latency_of_same_last_20 
	- 0.0026 * parameters.max_latency_of_same_last_50 
	+ 40223140.4834;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM9(work_wait &parameters) {
  double actual_remaining = 
	0.001 * parameters.work_so_far 
	- 0.0057 * parameters.wait_so_far 
	- 461791.2784 * parameters.num_locks_so_far 
	- 70513.1722 * parameters.total_wait_locks 
	+ 0.5252 * parameters.mean_wait_of_all 
	+ 0.0433 * parameters.avg_work_of_same_past_second 
	- 0.0461 * parameters.avg_wait_of_same_past_second 
	+ 0.0666 * parameters.avg_latency_of_same_last_20 
	+ 0.0121 * parameters.max_latency_of_same_last_50 
	+ 25970045.2654;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
new_order_LM10(work_wait &parameters) {
  double actual_remaining = 
	0.001 * parameters.work_so_far 
	- 0.0057 * parameters.wait_so_far 
	- 461791.2784 * parameters.num_locks_so_far 
	- 50328.2611 * parameters.total_wait_locks 
	+ 0.3866 * parameters.mean_wait_of_all 
	+ 0.0433 * parameters.avg_work_of_same_past_second 
	- 0.0461 * parameters.avg_wait_of_same_past_second 
	+ 0.2236 * parameters.avg_latency_of_same_last_20 
	+ 0.0043 * parameters.max_latency_of_same_last_50 
	- 18022929.5812;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
new_order_estimate(work_wait &parameters){

  if (parameters.total_wait_locks <= 173.5) {
    return new_order_LM1(parameters);
  } else {

    if (parameters.wait_so_far <= 392730132) {
      return new_order_LM2(parameters);
    } else {

      if (parameters.avg_latency_of_same_last_20 <= 529192000) {
        return new_order_LM3(parameters);
      } else {

        if (parameters.num_locks_so_far <= 4.5) {

          if (parameters.avg_wait_of_same_past_second <= 286452000) {

            if (parameters.mean_wait_of_all <= 64421350) {
              return new_order_LM4(parameters);
            } else {

              if (parameters.avg_wait_of_same_past_second <= 248489000) {
                return new_order_LM5(parameters);
              } else {
                return new_order_LM6(parameters);
              }
            }
          } else {
            return new_order_LM7(parameters);
          }
        } else {

          if (parameters.max_latency_of_same_last_50 <= 1455330000) {
            return new_order_LM8(parameters);
          } else {

            if (parameters.avg_wait_of_same_past_second <= 312323000) {
              return new_order_LM9(parameters);
            } else {
              return new_order_LM10(parameters);
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
	913.1575 * parameters.work_so_far 
	+ 0.0237 * parameters.wait_so_far 
	+ 21.0951 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 0.0006 * parameters.avg_work_of_same_past_second 
	- 0 * parameters.avg_wait_of_same_past_second 
	+ 0.0001 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 912166.5207;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM2(work_wait &parameters) {
  double actual_remaining = 
	9.0167 * parameters.work_so_far 
	+ 0.0133 * parameters.wait_so_far 
	+ 21.0951 * parameters.total_wait_locks 
	- 0.0001 * parameters.mean_wait_of_all 
	- 0.0006 * parameters.avg_work_of_same_past_second 
	- 0.0163 * parameters.avg_wait_of_same_past_second 
	+ 0.0155 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 11268902.6538;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM3(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 3433.6599 * parameters.total_wait_locks 
	- 0.0006 * parameters.mean_wait_of_all 
	- 108310.2876 * parameters.cpu_usage 
	- 0.0162 * parameters.avg_work_of_same_past_second 
	+ 0.0008 * parameters.avg_wait_of_same_past_second 
	+ 0.0396 * parameters.avg_latency_of_same_last_20 
	+ 0.0098 * parameters.max_latency_of_same_last_50 
	+ 5768083.9705;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM4(work_wait &parameters) {
  double actual_remaining = 
	1.3681 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 3433.6599 * parameters.total_wait_locks 
	- 0.0006 * parameters.mean_wait_of_all 
	- 108310.2876 * parameters.cpu_usage 
	- 0.0162 * parameters.avg_work_of_same_past_second 
	+ 0.0008 * parameters.avg_wait_of_same_past_second 
	+ 0.0396 * parameters.avg_latency_of_same_last_20 
	+ 0.0098 * parameters.max_latency_of_same_last_50 
	+ 6212066.0933;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM5(work_wait &parameters) {
  double actual_remaining = 
	1.6899 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 3433.6599 * parameters.total_wait_locks 
	- 0.0006 * parameters.mean_wait_of_all 
	- 108310.2876 * parameters.cpu_usage 
	- 0.0162 * parameters.avg_work_of_same_past_second 
	+ 0.0008 * parameters.avg_wait_of_same_past_second 
	+ 0.0396 * parameters.avg_latency_of_same_last_20 
	+ 0.0098 * parameters.max_latency_of_same_last_50 
	+ 6541764.6583;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM6(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 122957.0258 * parameters.total_wait_locks 
	- 0.0006 * parameters.mean_wait_of_all 
	- 108310.2876 * parameters.cpu_usage 
	- 0.0162 * parameters.avg_work_of_same_past_second 
	+ 0.0008 * parameters.avg_wait_of_same_past_second 
	+ 0.0396 * parameters.avg_latency_of_same_last_20 
	+ 0.0383 * parameters.max_latency_of_same_last_50 
	- 3158792.5821;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM7(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 3433.6599 * parameters.total_wait_locks 
	- 0.0006 * parameters.mean_wait_of_all 
	- 108310.2876 * parameters.cpu_usage 
	- 0.0162 * parameters.avg_work_of_same_past_second 
	+ 0.0915 * parameters.avg_wait_of_same_past_second 
	+ 0.0396 * parameters.avg_latency_of_same_last_20 
	+ 0.0404 * parameters.max_latency_of_same_last_50 
	+ 1092627.3923;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM8(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 3433.6599 * parameters.total_wait_locks 
	- 0.0006 * parameters.mean_wait_of_all 
	- 108310.2876 * parameters.cpu_usage 
	- 0.0162 * parameters.avg_work_of_same_past_second 
	+ 0.1066 * parameters.avg_wait_of_same_past_second 
	+ 0.0396 * parameters.avg_latency_of_same_last_20 
	+ 0.0404 * parameters.max_latency_of_same_last_50 
	+ 1683486.7969;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM9(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 3433.6599 * parameters.total_wait_locks 
	+ 1.1688 * parameters.mean_wait_of_all 
	- 108310.2876 * parameters.cpu_usage 
	- 0.0162 * parameters.avg_work_of_same_past_second 
	+ 0.0008 * parameters.avg_wait_of_same_past_second 
	+ 0.2241 * parameters.avg_latency_of_same_last_20 
	- 0.0047 * parameters.max_latency_of_same_last_50 
	- 36371322.8524;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM10(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 3433.6599 * parameters.total_wait_locks 
	- 0.5533 * parameters.mean_wait_of_all 
	- 108310.2876 * parameters.cpu_usage 
	- 0.0162 * parameters.avg_work_of_same_past_second 
	+ 0.0008 * parameters.avg_wait_of_same_past_second 
	+ 0.2602 * parameters.avg_latency_of_same_last_20 
	- 0.0735 * parameters.max_latency_of_same_last_50 
	+ 59994274.7592;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM11(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 3433.6599 * parameters.total_wait_locks 
	- 0.5533 * parameters.mean_wait_of_all 
	- 108310.2876 * parameters.cpu_usage 
	- 0.0162 * parameters.avg_work_of_same_past_second 
	+ 0.0008 * parameters.avg_wait_of_same_past_second 
	+ 0.2602 * parameters.avg_latency_of_same_last_20 
	- 0.0735 * parameters.max_latency_of_same_last_50 
	+ 71803130.3137;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM12(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 3433.6599 * parameters.total_wait_locks 
	- 0.5533 * parameters.mean_wait_of_all 
	- 108310.2876 * parameters.cpu_usage 
	- 0.0162 * parameters.avg_work_of_same_past_second 
	+ 0.0008 * parameters.avg_wait_of_same_past_second 
	+ 0.3392 * parameters.avg_latency_of_same_last_20 
	- 0.0735 * parameters.max_latency_of_same_last_50 
	+ 60117751.51;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM13(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 3433.6599 * parameters.total_wait_locks 
	- 0.2159 * parameters.mean_wait_of_all 
	- 108310.2876 * parameters.cpu_usage 
	- 0.0162 * parameters.avg_work_of_same_past_second 
	+ 0.0008 * parameters.avg_wait_of_same_past_second 
	+ 0.028 * parameters.avg_latency_of_same_last_20 
	+ 0.054 * parameters.max_latency_of_same_last_50 
	+ 14319589.5943;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM14(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 52791.9334 * parameters.total_wait_locks 
	- 0.0006 * parameters.mean_wait_of_all 
	- 108310.2876 * parameters.cpu_usage 
	- 0.0162 * parameters.avg_work_of_same_past_second 
	+ 0.0165 * parameters.avg_wait_of_same_past_second 
	+ 0.0007 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 10846183.7228;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM15(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0.0093 * parameters.wait_so_far 
	- 34652.7611 * parameters.total_wait_locks 
	- 0.2859 * parameters.mean_wait_of_all 
	+ 125639919.9181 * parameters.cpu_usage 
	+ 3.6072 * parameters.avg_work_of_same_past_second 
	+ 0.0064 * parameters.avg_wait_of_same_past_second 
	- 0.0013 * parameters.avg_latency_of_same_last_20 
	+ 0.1034 * parameters.max_latency_of_same_last_50 
	- 126311108.4654;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM16(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0.0093 * parameters.wait_so_far 
	- 34652.7611 * parameters.total_wait_locks 
	- 0.2859 * parameters.mean_wait_of_all 
	+ 71149020.1623 * parameters.cpu_usage 
	+ 5.53 * parameters.avg_work_of_same_past_second 
	+ 0.2039 * parameters.avg_wait_of_same_past_second 
	- 0.0013 * parameters.avg_latency_of_same_last_20 
	+ 0.0036 * parameters.max_latency_of_same_last_50 
	- 65703703.3803;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM17(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0.0167 * parameters.wait_so_far 
	+ 94247.6861 * parameters.total_wait_locks 
	- 0.2859 * parameters.mean_wait_of_all 
	+ 71149020.1623 * parameters.cpu_usage 
	+ 4.3443 * parameters.avg_work_of_same_past_second 
	+ 0.1381 * parameters.avg_wait_of_same_past_second 
	- 0.0013 * parameters.avg_latency_of_same_last_20 
	+ 0.0036 * parameters.max_latency_of_same_last_50 
	- 71552454.9919;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM18(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0.022 * parameters.wait_so_far 
	+ 72797.9088 * parameters.total_wait_locks 
	- 0.2859 * parameters.mean_wait_of_all 
	+ 71149020.1623 * parameters.cpu_usage 
	+ 4.3443 * parameters.avg_work_of_same_past_second 
	+ 0.1381 * parameters.avg_wait_of_same_past_second 
	- 0.0013 * parameters.avg_latency_of_same_last_20 
	+ 0.0036 * parameters.max_latency_of_same_last_50 
	- 62798355.0551;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM19(work_wait &parameters) {
  double actual_remaining = 
	30.8922 * parameters.work_so_far 
	- 0.0105 * parameters.wait_so_far 
	- 34652.7611 * parameters.total_wait_locks 
	- 2.7543 * parameters.mean_wait_of_all 
	+ 103689910.2369 * parameters.cpu_usage 
	- 0.1643 * parameters.avg_work_of_same_past_second 
	+ 0.0064 * parameters.avg_wait_of_same_past_second 
	- 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0.0278 * parameters.max_latency_of_same_last_50 
	+ 80046311.7384;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM20(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0.0531 * parameters.wait_so_far 
	- 699796.4358 * parameters.total_wait_locks 
	- 0.5457 * parameters.mean_wait_of_all 
	- 108310.2876 * parameters.cpu_usage 
	- 0.1643 * parameters.avg_work_of_same_past_second 
	+ 0.0064 * parameters.avg_wait_of_same_past_second 
	- 0.0013 * parameters.avg_latency_of_same_last_20 
	+ 0.0061 * parameters.max_latency_of_same_last_50 
	+ 227619382.1754;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM21(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0.0583 * parameters.wait_so_far 
	- 572727.8962 * parameters.total_wait_locks 
	- 0.8195 * parameters.mean_wait_of_all 
	- 108310.2876 * parameters.cpu_usage 
	- 0.1643 * parameters.avg_work_of_same_past_second 
	+ 0.0064 * parameters.avg_wait_of_same_past_second 
	- 0.0013 * parameters.avg_latency_of_same_last_20 
	+ 0.0061 * parameters.max_latency_of_same_last_50 
	+ 211889363.5068;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM22(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0.0578 * parameters.wait_so_far 
	- 572727.8962 * parameters.total_wait_locks 
	- 0.5457 * parameters.mean_wait_of_all 
	- 108310.2876 * parameters.cpu_usage 
	- 0.1643 * parameters.avg_work_of_same_past_second 
	+ 0.0064 * parameters.avg_wait_of_same_past_second 
	- 0.0013 * parameters.avg_latency_of_same_last_20 
	+ 0.0061 * parameters.max_latency_of_same_last_50 
	+ 194399172.2774;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM23(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0.0515 * parameters.wait_so_far 
	- 456836.9541 * parameters.total_wait_locks 
	- 0.5457 * parameters.mean_wait_of_all 
	- 108310.2876 * parameters.cpu_usage 
	- 0.1643 * parameters.avg_work_of_same_past_second 
	+ 0.0064 * parameters.avg_wait_of_same_past_second 
	- 0.0013 * parameters.avg_latency_of_same_last_20 
	+ 0.0061 * parameters.max_latency_of_same_last_50 
	+ 165835703.83;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM24(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0.0308 * parameters.wait_so_far 
	- 342021.1969 * parameters.total_wait_locks 
	- 0.5457 * parameters.mean_wait_of_all 
	- 108310.2876 * parameters.cpu_usage 
	- 0.1643 * parameters.avg_work_of_same_past_second 
	+ 0.0064 * parameters.avg_wait_of_same_past_second 
	- 0.0013 * parameters.avg_latency_of_same_last_20 
	+ 0.0061 * parameters.max_latency_of_same_last_50 
	+ 123950115.7253;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM25(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0.0246 * parameters.wait_so_far 
	- 342021.1969 * parameters.total_wait_locks 
	- 0.5457 * parameters.mean_wait_of_all 
	- 108310.2876 * parameters.cpu_usage 
	- 0.1643 * parameters.avg_work_of_same_past_second 
	+ 0.0064 * parameters.avg_wait_of_same_past_second 
	- 0.0013 * parameters.avg_latency_of_same_last_20 
	+ 0.0061 * parameters.max_latency_of_same_last_50 
	+ 124236873.1687;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM26(work_wait &parameters) {
  double actual_remaining = 
	0.0937 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 4246.3819 * parameters.total_wait_locks 
	- 0.002 * parameters.mean_wait_of_all 
	- 13039688.093 * parameters.cpu_usage 
	- 0.1651 * parameters.avg_work_of_same_past_second 
	+ 0.0083 * parameters.avg_wait_of_same_past_second 
	- 0.0008 * parameters.avg_latency_of_same_last_20 
	+ 0.0006 * parameters.max_latency_of_same_last_50 
	+ 33558029.7328;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM27(work_wait &parameters) {
  double actual_remaining = 
	1.1147 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 4246.3819 * parameters.total_wait_locks 
	- 0.002 * parameters.mean_wait_of_all 
	- 10974708.3037 * parameters.cpu_usage 
	+ 0.2332 * parameters.avg_work_of_same_past_second 
	+ 0.008 * parameters.avg_wait_of_same_past_second 
	- 0.0008 * parameters.avg_latency_of_same_last_20 
	+ 0.0006 * parameters.max_latency_of_same_last_50 
	+ 17323391.7781;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM28(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 109896.3146 * parameters.total_wait_locks 
	+ 0.3334 * parameters.mean_wait_of_all 
	+ 3851694.3789 * parameters.cpu_usage 
	- 3.159 * parameters.avg_work_of_same_past_second 
	- 5.926 * parameters.avg_wait_of_same_past_second 
	+ 0.0152 * parameters.avg_latency_of_same_last_20 
	+ 0.0006 * parameters.max_latency_of_same_last_50 
	+ 1830566690.1785;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM29(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 371725.3919 * parameters.total_wait_locks 
	+ 0.4613 * parameters.mean_wait_of_all 
	+ 3851694.3789 * parameters.cpu_usage 
	+ 0.1211 * parameters.avg_work_of_same_past_second 
	- 0.0459 * parameters.avg_wait_of_same_past_second 
	+ 0.019 * parameters.avg_latency_of_same_last_20 
	+ 0.0006 * parameters.max_latency_of_same_last_50 
	+ 73840483.6054;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM30(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 68849.5106 * parameters.total_wait_locks 
	- 0.3014 * parameters.mean_wait_of_all 
	+ 3851694.3789 * parameters.cpu_usage 
	- 4.8319 * parameters.avg_work_of_same_past_second 
	- 0.0158 * parameters.avg_wait_of_same_past_second 
	+ 0.0439 * parameters.avg_latency_of_same_last_20 
	+ 0.0006 * parameters.max_latency_of_same_last_50 
	+ 124488482.5425;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM31(work_wait &parameters) {
  double actual_remaining = 
	-1.2044 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 326025.3361 * parameters.total_wait_locks 
	- 0.6365 * parameters.mean_wait_of_all 
	+ 3851694.3789 * parameters.cpu_usage 
	- 3.0727 * parameters.avg_work_of_same_past_second 
	- 0.0158 * parameters.avg_wait_of_same_past_second 
	+ 0.0471 * parameters.avg_latency_of_same_last_20 
	+ 0.0006 * parameters.max_latency_of_same_last_50 
	+ 54496835.7216;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM32(work_wait &parameters) {
  double actual_remaining = 
	-5.3682 * parameters.work_so_far 
	+ 0.0036 * parameters.wait_so_far 
	+ 297602.451 * parameters.total_wait_locks 
	- 1.3734 * parameters.mean_wait_of_all 
	+ 3851694.3789 * parameters.cpu_usage 
	- 3.0727 * parameters.avg_work_of_same_past_second 
	- 0.0158 * parameters.avg_wait_of_same_past_second 
	+ 0.0471 * parameters.avg_latency_of_same_last_20 
	+ 0.0006 * parameters.max_latency_of_same_last_50 
	+ 93810005.418;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM33(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 32245.4982 * parameters.total_wait_locks 
	- 0.1305 * parameters.mean_wait_of_all 
	+ 49116908.2438 * parameters.cpu_usage 
	- 0.0161 * parameters.avg_work_of_same_past_second 
	- 0.0158 * parameters.avg_wait_of_same_past_second 
	+ 0.0039 * parameters.avg_latency_of_same_last_20 
	+ 0.0006 * parameters.max_latency_of_same_last_50 
	- 13432758.9249;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM34(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 9085.7344 * parameters.total_wait_locks 
	+ 0.029 * parameters.mean_wait_of_all 
	- 108310.2876 * parameters.cpu_usage 
	- 1.0124 * parameters.avg_work_of_same_past_second 
	+ 0.0463 * parameters.avg_wait_of_same_past_second 
	- 0.0635 * parameters.avg_latency_of_same_last_20 
	+ 0.0053 * parameters.max_latency_of_same_last_50 
	+ 75409787.2289;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM35(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 9085.7344 * parameters.total_wait_locks 
	- 4.0861 * parameters.mean_wait_of_all 
	- 108310.2876 * parameters.cpu_usage 
	+ 4.3642 * parameters.avg_work_of_same_past_second 
	+ 0.0463 * parameters.avg_wait_of_same_past_second 
	- 0.0353 * parameters.avg_latency_of_same_last_20 
	+ 0.0053 * parameters.max_latency_of_same_last_50 
	+ 132108417.4836;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM36(work_wait &parameters) {
  double actual_remaining = 
	-0.0221 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 317812.159 * parameters.total_wait_locks 
	+ 0.029 * parameters.mean_wait_of_all 
	- 108310.2876 * parameters.cpu_usage 
	+ 10.7364 * parameters.avg_work_of_same_past_second 
	+ 0.0463 * parameters.avg_wait_of_same_past_second 
	- 0.0353 * parameters.avg_latency_of_same_last_20 
	+ 0.0053 * parameters.max_latency_of_same_last_50 
	- 246167705.2539;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM37(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 158572.3932 * parameters.total_wait_locks 
	+ 0.2512 * parameters.mean_wait_of_all 
	- 108310.2876 * parameters.cpu_usage 
	- 1.9401 * parameters.avg_work_of_same_past_second 
	+ 0.0358 * parameters.avg_wait_of_same_past_second 
	- 0.0102 * parameters.avg_latency_of_same_last_20 
	+ 0.0108 * parameters.max_latency_of_same_last_50 
	+ 6043828.6702;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM38(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 275978.3808 * parameters.total_wait_locks 
	+ 0.1019 * parameters.mean_wait_of_all 
	- 108310.2876 * parameters.cpu_usage 
	- 1.9401 * parameters.avg_work_of_same_past_second 
	+ 0.0358 * parameters.avg_wait_of_same_past_second 
	- 0.0164 * parameters.avg_latency_of_same_last_20 
	+ 0.015 * parameters.max_latency_of_same_last_50 
	- 5862546.5247;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM39(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 112466.4081 * parameters.total_wait_locks 
	+ 0.1019 * parameters.mean_wait_of_all 
	- 108310.2876 * parameters.cpu_usage 
	- 1.9401 * parameters.avg_work_of_same_past_second 
	+ 0.0358 * parameters.avg_wait_of_same_past_second 
	- 0.0166 * parameters.avg_latency_of_same_last_20 
	+ 0.0108 * parameters.max_latency_of_same_last_50 
	+ 25448859.7038;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM40(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 9085.7344 * parameters.total_wait_locks 
	- 0.2917 * parameters.mean_wait_of_all 
	- 108310.2876 * parameters.cpu_usage 
	- 1.9401 * parameters.avg_work_of_same_past_second 
	+ 0.0358 * parameters.avg_wait_of_same_past_second 
	- 0.0102 * parameters.avg_latency_of_same_last_20 
	+ 0.0132 * parameters.max_latency_of_same_last_50 
	+ 54429288.401;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM41(work_wait &parameters) {
  double actual_remaining = 
	-76.6256 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 9085.7344 * parameters.total_wait_locks 
	- 0.2917 * parameters.mean_wait_of_all 
	- 108310.2876 * parameters.cpu_usage 
	- 1.9401 * parameters.avg_work_of_same_past_second 
	+ 0.0358 * parameters.avg_wait_of_same_past_second 
	- 0.0102 * parameters.avg_latency_of_same_last_20 
	+ 0.0132 * parameters.max_latency_of_same_last_50 
	+ 57291855.7177;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM42(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 560221.3714 * parameters.total_wait_locks 
	- 4.9191 * parameters.mean_wait_of_all 
	- 108310.2876 * parameters.cpu_usage 
	- 4.4436 * parameters.avg_work_of_same_past_second 
	+ 0.0358 * parameters.avg_wait_of_same_past_second 
	- 0.0102 * parameters.avg_latency_of_same_last_20 
	+ 0.0083 * parameters.max_latency_of_same_last_50 
	+ 212682548.1658;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM43(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 9085.7344 * parameters.total_wait_locks 
	- 1.3262 * parameters.mean_wait_of_all 
	- 108310.2876 * parameters.cpu_usage 
	- 4.1561 * parameters.avg_work_of_same_past_second 
	+ 0.0358 * parameters.avg_wait_of_same_past_second 
	- 0.0102 * parameters.avg_latency_of_same_last_20 
	+ 0.0083 * parameters.max_latency_of_same_last_50 
	+ 158029546.4144;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM44(work_wait &parameters) {
  double actual_remaining = 
	0.0003 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 399.3322 * parameters.total_wait_locks 
	- 0.1615 * parameters.mean_wait_of_all 
	- 17164384.0224 * parameters.cpu_usage 
	- 0.0065 * parameters.avg_work_of_same_past_second 
	+ 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0138 * parameters.avg_latency_of_same_last_20 
	- 0.0048 * parameters.max_latency_of_same_last_50 
	+ 43048679.1769;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM45(work_wait &parameters) {
  double actual_remaining = 
	0.0222 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 12038.1766 * parameters.total_wait_locks 
	- 0.0906 * parameters.mean_wait_of_all 
	+ 111381254.9406 * parameters.cpu_usage 
	- 0.4471 * parameters.avg_work_of_same_past_second 
	+ 0.0362 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.0082 * parameters.max_latency_of_same_last_50 
	- 81591023.2373;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM46(work_wait &parameters) {
  double actual_remaining = 
	-2.149 * parameters.work_so_far 
	- 0.6802 * parameters.wait_so_far 
	+ 62883.91 * parameters.total_wait_locks 
	- 0.3032 * parameters.mean_wait_of_all 
	- 3332181.492 * parameters.cpu_usage 
	- 0.0339 * parameters.avg_work_of_same_past_second 
	- 0.0018 * parameters.avg_wait_of_same_past_second 
	+ 0.0195 * parameters.avg_latency_of_same_last_20 
	- 0.0569 * parameters.max_latency_of_same_last_50 
	+ 137633259.4444;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM47(work_wait &parameters) {
  double actual_remaining = 
	0.0247 * parameters.work_so_far 
	- 0.0103 * parameters.wait_so_far 
	+ 16474.2563 * parameters.total_wait_locks 
	- 0.0819 * parameters.mean_wait_of_all 
	- 3332181.492 * parameters.cpu_usage 
	+ 1.0975 * parameters.avg_work_of_same_past_second 
	- 0.0018 * parameters.avg_wait_of_same_past_second 
	+ 0.0468 * parameters.avg_latency_of_same_last_20 
	- 0.0273 * parameters.max_latency_of_same_last_50 
	+ 19901999.8352;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM48(work_wait &parameters) {
  double actual_remaining = 
	0.0247 * parameters.work_so_far 
	- 0.0063 * parameters.wait_so_far 
	- 29450.4401 * parameters.total_wait_locks 
	+ 0.1366 * parameters.mean_wait_of_all 
	- 3332181.492 * parameters.cpu_usage 
	- 0.0339 * parameters.avg_work_of_same_past_second 
	- 0.0018 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.0027 * parameters.max_latency_of_same_last_50 
	+ 24316847.7759;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM49(work_wait &parameters) {
  double actual_remaining = 
	1.8163 * parameters.work_so_far 
	+ 0.0276 * parameters.wait_so_far 
	- 37453.4552 * parameters.total_wait_locks 
	+ 0.1743 * parameters.mean_wait_of_all 
	- 3332181.492 * parameters.cpu_usage 
	- 0.0339 * parameters.avg_work_of_same_past_second 
	- 0.0018 * parameters.avg_wait_of_same_past_second 
	- 0.0106 * parameters.avg_latency_of_same_last_20 
	+ 0.011 * parameters.max_latency_of_same_last_50 
	+ 16439073.4272;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM50(work_wait &parameters) {
  double actual_remaining = 
	0.0247 * parameters.work_so_far 
	+ 0.0543 * parameters.wait_so_far 
	- 73199.664 * parameters.total_wait_locks 
	+ 0.1743 * parameters.mean_wait_of_all 
	- 3332181.492 * parameters.cpu_usage 
	- 0.0339 * parameters.avg_work_of_same_past_second 
	- 0.0018 * parameters.avg_wait_of_same_past_second 
	- 0.0193 * parameters.avg_latency_of_same_last_20 
	+ 0.0164 * parameters.max_latency_of_same_last_50 
	+ 35773273.4867;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM51(work_wait &parameters) {
  double actual_remaining = 
	1.6507 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 367044.9854 * parameters.total_wait_locks 
	+ 12.3382 * parameters.mean_wait_of_all 
	- 226022256.664 * parameters.cpu_usage 
	- 0.2659 * parameters.avg_work_of_same_past_second 
	- 0.4052 * parameters.avg_wait_of_same_past_second 
	+ 0.0004 * parameters.avg_latency_of_same_last_20 
	+ 0.0018 * parameters.max_latency_of_same_last_50 
	- 295267795.7072;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM52(work_wait &parameters) {
  double actual_remaining = 
	0.1528 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 291280.6961 * parameters.total_wait_locks 
	+ 0.9231 * parameters.mean_wait_of_all 
	- 226022256.664 * parameters.cpu_usage 
	- 0.2659 * parameters.avg_work_of_same_past_second 
	- 0.1108 * parameters.avg_wait_of_same_past_second 
	+ 0.0127 * parameters.avg_latency_of_same_last_20 
	+ 0.0018 * parameters.max_latency_of_same_last_50 
	+ 307252129.4936;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM53(work_wait &parameters) {
  double actual_remaining = 
	0.1528 * parameters.work_so_far 
	- 0.0248 * parameters.wait_so_far 
	- 338670.89 * parameters.total_wait_locks 
	+ 1.0144 * parameters.mean_wait_of_all 
	- 226022256.664 * parameters.cpu_usage 
	- 0.2659 * parameters.avg_work_of_same_past_second 
	- 0.1605 * parameters.avg_wait_of_same_past_second 
	+ 0.0052 * parameters.avg_latency_of_same_last_20 
	+ 0.0018 * parameters.max_latency_of_same_last_50 
	+ 338833693.4974;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM54(work_wait &parameters) {
  double actual_remaining = 
	0.1528 * parameters.work_so_far 
	- 0.0146 * parameters.wait_so_far 
	- 298571.1358 * parameters.total_wait_locks 
	+ 0.6745 * parameters.mean_wait_of_all 
	- 226022256.664 * parameters.cpu_usage 
	- 0.2659 * parameters.avg_work_of_same_past_second 
	- 0.1124 * parameters.avg_wait_of_same_past_second 
	+ 0.0052 * parameters.avg_latency_of_same_last_20 
	+ 0.0018 * parameters.max_latency_of_same_last_50 
	+ 343490148.5514;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM55(work_wait &parameters) {
  double actual_remaining = 
	0.1528 * parameters.work_so_far 
	- 0.0146 * parameters.wait_so_far 
	- 298571.1358 * parameters.total_wait_locks 
	+ 0.6745 * parameters.mean_wait_of_all 
	- 226022256.664 * parameters.cpu_usage 
	- 0.2659 * parameters.avg_work_of_same_past_second 
	- 0.1124 * parameters.avg_wait_of_same_past_second 
	+ 0.0052 * parameters.avg_latency_of_same_last_20 
	+ 0.0018 * parameters.max_latency_of_same_last_50 
	+ 346765758.9508;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM56(work_wait &parameters) {
  double actual_remaining = 
	0.1528 * parameters.work_so_far 
	- 0.0146 * parameters.wait_so_far 
	- 298571.1358 * parameters.total_wait_locks 
	+ 0.7591 * parameters.mean_wait_of_all 
	- 226022256.664 * parameters.cpu_usage 
	- 0.2659 * parameters.avg_work_of_same_past_second 
	- 0.1124 * parameters.avg_wait_of_same_past_second 
	+ 0.0052 * parameters.avg_latency_of_same_last_20 
	+ 0.0018 * parameters.max_latency_of_same_last_50 
	+ 333448629.3796;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM57(work_wait &parameters) {
  double actual_remaining = 
	0.0247 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 264860.5983 * parameters.total_wait_locks 
	+ 1.0976 * parameters.mean_wait_of_all 
	- 651157854.7196 * parameters.cpu_usage 
	- 0.7087 * parameters.avg_work_of_same_past_second 
	+ 2.8727 * parameters.avg_wait_of_same_past_second 
	- 0.0667 * parameters.avg_latency_of_same_last_20 
	+ 0.0808 * parameters.max_latency_of_same_last_50 
	- 311680981.2982;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM58(work_wait &parameters) {
  double actual_remaining = 
	-4257.7146 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 264860.5983 * parameters.total_wait_locks 
	+ 1.7081 * parameters.mean_wait_of_all 
	- 651157854.7196 * parameters.cpu_usage 
	- 0.7087 * parameters.avg_work_of_same_past_second 
	+ 2.8727 * parameters.avg_wait_of_same_past_second 
	- 0.0667 * parameters.avg_latency_of_same_last_20 
	+ 0.0682 * parameters.max_latency_of_same_last_50 
	- 190948692.9362;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM59(work_wait &parameters) {
  double actual_remaining = 
	-305.6981 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 264860.5983 * parameters.total_wait_locks 
	+ 1.65 * parameters.mean_wait_of_all 
	- 651157854.7196 * parameters.cpu_usage 
	- 0.7087 * parameters.avg_work_of_same_past_second 
	+ 2.8727 * parameters.avg_wait_of_same_past_second 
	- 0.0667 * parameters.avg_latency_of_same_last_20 
	+ 0.0682 * parameters.max_latency_of_same_last_50 
	- 311847438.9373;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM60(work_wait &parameters) {
  double actual_remaining = 
	0.0247 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 264860.5983 * parameters.total_wait_locks 
	+ 1.0976 * parameters.mean_wait_of_all 
	- 651157854.7196 * parameters.cpu_usage 
	- 0.7087 * parameters.avg_work_of_same_past_second 
	+ 3.1807 * parameters.avg_wait_of_same_past_second 
	- 0.0739 * parameters.avg_latency_of_same_last_20 
	+ 0.0018 * parameters.max_latency_of_same_last_50 
	- 333344299.1976;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM61(work_wait &parameters) {
  double actual_remaining = 
	0.0029 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 25068.8004 * parameters.total_wait_locks 
	+ 0.1171 * parameters.mean_wait_of_all 
	- 8914573.7828 * parameters.cpu_usage 
	- 0.0523 * parameters.avg_work_of_same_past_second 
	- 0.677 * parameters.avg_wait_of_same_past_second 
	- 0.1656 * parameters.avg_latency_of_same_last_20 
	+ 0.0551 * parameters.max_latency_of_same_last_50 
	+ 256462194.3309;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM62(work_wait &parameters) {
  double actual_remaining = 
	0.0029 * parameters.work_so_far 
	- 0.2057 * parameters.wait_so_far 
	- 25068.8004 * parameters.total_wait_locks 
	+ 0.1171 * parameters.mean_wait_of_all 
	- 8914573.7828 * parameters.cpu_usage 
	- 0.0523 * parameters.avg_work_of_same_past_second 
	- 0.0622 * parameters.avg_wait_of_same_past_second 
	+ 0.0087 * parameters.avg_latency_of_same_last_20 
	+ 0.0089 * parameters.max_latency_of_same_last_50 
	+ 88531830.2093;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM63(work_wait &parameters) {
  double actual_remaining = 
	0.003 * parameters.work_so_far 
	- 0.0002 * parameters.wait_so_far 
	- 76516.8106 * parameters.total_wait_locks 
	+ 0.383 * parameters.mean_wait_of_all 
	- 719440.7378 * parameters.cpu_usage 
	- 0.2694 * parameters.avg_work_of_same_past_second 
	- 0.023 * parameters.avg_wait_of_same_past_second 
	+ 0.0005 * parameters.avg_latency_of_same_last_20 
	+ 0.0001 * parameters.max_latency_of_same_last_50 
	+ 36160652.526;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM64(work_wait &parameters) {
  double actual_remaining = 
	0.0146 * parameters.work_so_far 
	- 0.0008 * parameters.wait_so_far 
	- 88102.0769 * parameters.total_wait_locks 
	+ 0.5135 * parameters.mean_wait_of_all 
	- 204588043.7321 * parameters.cpu_usage 
	- 0.019 * parameters.avg_work_of_same_past_second 
	+ 0.0011 * parameters.avg_wait_of_same_past_second 
	+ 0.0006 * parameters.avg_latency_of_same_last_20 
	+ 0.0001 * parameters.max_latency_of_same_last_50 
	+ 215318749.7196;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM65(work_wait &parameters) {
  double actual_remaining = 
	1.11 * parameters.work_so_far 
	- 0.0016 * parameters.wait_so_far 
	- 281248.4884 * parameters.total_wait_locks 
	+ 1.7361 * parameters.mean_wait_of_all 
	- 719440.7378 * parameters.cpu_usage 
	- 1.1214 * parameters.avg_work_of_same_past_second 
	+ 0.0861 * parameters.avg_wait_of_same_past_second 
	+ 0.0006 * parameters.avg_latency_of_same_last_20 
	+ 0.0001 * parameters.max_latency_of_same_last_50 
	- 28480637.656;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM66(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 336034.6495 * parameters.total_wait_locks 
	+ 0.7792 * parameters.mean_wait_of_all 
	+ 62728022.94 * parameters.cpu_usage 
	- 0.2475 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0187 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 10126643.341;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM67(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	+ 515783.7423 * parameters.total_wait_locks 
	- 2.5661 * parameters.mean_wait_of_all 
	- 2521294742.7726 * parameters.cpu_usage 
	- 3.4595 * parameters.avg_work_of_same_past_second 
	+ 0.5198 * parameters.avg_wait_of_same_past_second 
	+ 0.0323 * parameters.avg_latency_of_same_last_20 
	- 0.0017 * parameters.max_latency_of_same_last_50 
	+ 2427511459.9943;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM68(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	+ 0.023 * parameters.wait_so_far 
	+ 676510.5594 * parameters.total_wait_locks 
	- 1.9176 * parameters.mean_wait_of_all 
	- 5802844931.3893 * parameters.cpu_usage 
	- 1.7093 * parameters.avg_work_of_same_past_second 
	+ 0.5792 * parameters.avg_wait_of_same_past_second 
	+ 0.0323 * parameters.avg_latency_of_same_last_20 
	+ 0.2176 * parameters.max_latency_of_same_last_50 
	+ 5295267047.1778;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM69(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	+ 0.0318 * parameters.wait_so_far 
	+ 322918.187 * parameters.total_wait_locks 
	- 1.9176 * parameters.mean_wait_of_all 
	- 6943208729.2873 * parameters.cpu_usage 
	- 1.7093 * parameters.avg_work_of_same_past_second 
	+ 0.5792 * parameters.avg_wait_of_same_past_second 
	+ 0.0323 * parameters.avg_latency_of_same_last_20 
	+ 0.3011 * parameters.max_latency_of_same_last_50 
	+ 6452991906.2714;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM70(work_wait &parameters) {
  double actual_remaining = 
	-0.3255 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 72191.2364 * parameters.total_wait_locks 
	+ 0.3173 * parameters.mean_wait_of_all 
	- 461575.3462 * parameters.cpu_usage 
	- 0.011 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0361 * parameters.avg_latency_of_same_last_20 
	- 0.0346 * parameters.max_latency_of_same_last_50 
	+ 32749086.0864;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM71(work_wait &parameters) {
  double actual_remaining = 
	0.0927 * parameters.work_so_far 
	+ 0.0083 * parameters.wait_so_far 
	- 78738.2514 * parameters.total_wait_locks 
	+ 0.091 * parameters.mean_wait_of_all 
	- 93489652.2489 * parameters.cpu_usage 
	+ 0.4264 * parameters.avg_work_of_same_past_second 
	- 0.0278 * parameters.avg_wait_of_same_past_second 
	- 0.0463 * parameters.avg_latency_of_same_last_20 
	+ 0.0893 * parameters.max_latency_of_same_last_50 
	+ 67850930.5941;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM72(work_wait &parameters) {
  double actual_remaining = 
	0.0927 * parameters.work_so_far 
	+ 0.0083 * parameters.wait_so_far 
	- 78738.2514 * parameters.total_wait_locks 
	+ 0.091 * parameters.mean_wait_of_all 
	- 93489652.2489 * parameters.cpu_usage 
	+ 0.4264 * parameters.avg_work_of_same_past_second 
	- 0.0278 * parameters.avg_wait_of_same_past_second 
	- 0.0562 * parameters.avg_latency_of_same_last_20 
	+ 0.0615 * parameters.max_latency_of_same_last_50 
	+ 94678306.4189;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM73(work_wait &parameters) {
  double actual_remaining = 
	0.1718 * parameters.work_so_far 
	+ 0.0268 * parameters.wait_so_far 
	+ 29328.007 * parameters.total_wait_locks 
	+ 0.2664 * parameters.mean_wait_of_all 
	- 578322509.9502 * parameters.cpu_usage 
	+ 0.72 * parameters.avg_work_of_same_past_second 
	- 0.1373 * parameters.avg_wait_of_same_past_second 
	- 0.0207 * parameters.avg_latency_of_same_last_20 
	+ 0.0056 * parameters.max_latency_of_same_last_50 
	+ 554395114.6755;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM74(work_wait &parameters) {
  double actual_remaining = 
	0.4535 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 76829.0341 * parameters.total_wait_locks 
	+ 0.6367 * parameters.mean_wait_of_all 
	+ 984318357.6983 * parameters.cpu_usage 
	+ 0.0346 * parameters.avg_work_of_same_past_second 
	- 0.0857 * parameters.avg_wait_of_same_past_second 
	+ 0.0462 * parameters.avg_latency_of_same_last_20 
	- 0.0022 * parameters.max_latency_of_same_last_50 
	- 952340851.0739;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM75(work_wait &parameters) {
  double actual_remaining = 
	0.136 * parameters.work_so_far 
	+ 0.0069 * parameters.wait_so_far 
	- 250568.5295 * parameters.total_wait_locks 
	+ 1.2665 * parameters.mean_wait_of_all 
	- 461575.3462 * parameters.cpu_usage 
	+ 0.0346 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	- 0.0015 * parameters.max_latency_of_same_last_50 
	- 13728117.524;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM76(work_wait &parameters) {
  double actual_remaining = 
	0.1247 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 132222.3132 * parameters.total_wait_locks 
	+ 0.604 * parameters.mean_wait_of_all 
	- 461575.3462 * parameters.cpu_usage 
	+ 0.0346 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0013 * parameters.avg_latency_of_same_last_20 
	+ 0.0011 * parameters.max_latency_of_same_last_50 
	+ 4846057.709;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM77(work_wait &parameters) {
  double actual_remaining = 
	0.0309 * parameters.work_so_far 
	- 0.0125 * parameters.wait_so_far 
	- 72064.4285 * parameters.total_wait_locks 
	+ 0.5979 * parameters.mean_wait_of_all 
	+ 198645193.9601 * parameters.cpu_usage 
	- 0.011 * parameters.avg_work_of_same_past_second 
	+ 0.0192 * parameters.avg_wait_of_same_past_second 
	+ 0.0679 * parameters.avg_latency_of_same_last_20 
	+ 0.034 * parameters.max_latency_of_same_last_50 
	- 279149337.0161;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM78(work_wait &parameters) {
  double actual_remaining = 
	0.0309 * parameters.work_so_far 
	- 0.0146 * parameters.wait_so_far 
	- 72064.4285 * parameters.total_wait_locks 
	+ 0.5979 * parameters.mean_wait_of_all 
	+ 198645193.9601 * parameters.cpu_usage 
	- 0.011 * parameters.avg_work_of_same_past_second 
	+ 0.0142 * parameters.avg_wait_of_same_past_second 
	+ 0.0679 * parameters.avg_latency_of_same_last_20 
	+ 0.034 * parameters.max_latency_of_same_last_50 
	- 275902967.7947;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM79(work_wait &parameters) {
  double actual_remaining = 
	0.0309 * parameters.work_so_far 
	- 0.0073 * parameters.wait_so_far 
	- 72064.4285 * parameters.total_wait_locks 
	+ 0.5979 * parameters.mean_wait_of_all 
	+ 198645193.9601 * parameters.cpu_usage 
	- 0.011 * parameters.avg_work_of_same_past_second 
	- 0.0147 * parameters.avg_wait_of_same_past_second 
	+ 0.0667 * parameters.avg_latency_of_same_last_20 
	+ 0.034 * parameters.max_latency_of_same_last_50 
	- 266687625.6167;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM80(work_wait &parameters) {
  double actual_remaining = 
	0.0309 * parameters.work_so_far 
	- 0.0073 * parameters.wait_so_far 
	- 72064.4285 * parameters.total_wait_locks 
	+ 0.5979 * parameters.mean_wait_of_all 
	+ 198645193.9601 * parameters.cpu_usage 
	- 0.011 * parameters.avg_work_of_same_past_second 
	- 0.0061 * parameters.avg_wait_of_same_past_second 
	+ 0.0667 * parameters.avg_latency_of_same_last_20 
	+ 0.034 * parameters.max_latency_of_same_last_50 
	- 269566757.6921;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM81(work_wait &parameters) {
  double actual_remaining = 
	0.0309 * parameters.work_so_far 
	- 0.0073 * parameters.wait_so_far 
	- 72064.4285 * parameters.total_wait_locks 
	+ 0.757 * parameters.mean_wait_of_all 
	+ 198645193.9601 * parameters.cpu_usage 
	- 0.011 * parameters.avg_work_of_same_past_second 
	- 0.012 * parameters.avg_wait_of_same_past_second 
	+ 0.0366 * parameters.avg_latency_of_same_last_20 
	+ 0.0283 * parameters.max_latency_of_same_last_50 
	- 268719856.1732;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM82(work_wait &parameters) {
  double actual_remaining = 
	0.1105 * parameters.work_so_far 
	- 0.0087 * parameters.wait_so_far 
	- 72064.4285 * parameters.total_wait_locks 
	+ 0.6425 * parameters.mean_wait_of_all 
	+ 913529638.5841 * parameters.cpu_usage 
	- 0.011 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.0425 * parameters.avg_latency_of_same_last_20 
	+ 0.0036 * parameters.max_latency_of_same_last_50 
	- 853300141.5569;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM83(work_wait &parameters) {
  double actual_remaining = 
	0.0309 * parameters.work_so_far 
	- 0.0087 * parameters.wait_so_far 
	- 72064.4285 * parameters.total_wait_locks 
	+ 0.6425 * parameters.mean_wait_of_all 
	+ 784819199.09 * parameters.cpu_usage 
	- 0.011 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0731 * parameters.avg_latency_of_same_last_20 
	+ 0.0036 * parameters.max_latency_of_same_last_50 
	- 794302190.0296;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM84(work_wait &parameters) {
  double actual_remaining = 
	0.0309 * parameters.work_so_far 
	- 0.0087 * parameters.wait_so_far 
	- 23551.6261 * parameters.total_wait_locks 
	+ 0.6425 * parameters.mean_wait_of_all 
	+ 784819199.09 * parameters.cpu_usage 
	- 0.011 * parameters.avg_work_of_same_past_second 
	+ 0.0276 * parameters.avg_wait_of_same_past_second 
	- 0.0425 * parameters.avg_latency_of_same_last_20 
	+ 0.0036 * parameters.max_latency_of_same_last_50 
	- 759506806.2454;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM85(work_wait &parameters) {
  double actual_remaining = 
	0.0309 * parameters.work_so_far 
	- 0.0087 * parameters.wait_so_far 
	- 16130.8892 * parameters.total_wait_locks 
	+ 0.6425 * parameters.mean_wait_of_all 
	+ 784819199.09 * parameters.cpu_usage 
	- 0.011 * parameters.avg_work_of_same_past_second 
	+ 0.0289 * parameters.avg_wait_of_same_past_second 
	- 0.0425 * parameters.avg_latency_of_same_last_20 
	+ 0.0036 * parameters.max_latency_of_same_last_50 
	- 762550895.5905;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM86(work_wait &parameters) {
  double actual_remaining = 
	0.0309 * parameters.work_so_far 
	- 0.0087 * parameters.wait_so_far 
	- 57582.8654 * parameters.total_wait_locks 
	+ 0.6425 * parameters.mean_wait_of_all 
	+ 661484605.4745 * parameters.cpu_usage 
	- 0.011 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.0733 * parameters.avg_latency_of_same_last_20 
	+ 0.0036 * parameters.max_latency_of_same_last_50 
	- 603073841.525;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM87(work_wait &parameters) {
  double actual_remaining = 
	0.0309 * parameters.work_so_far 
	- 0.0087 * parameters.wait_so_far 
	- 55169.2716 * parameters.total_wait_locks 
	+ 0.6425 * parameters.mean_wait_of_all 
	+ 661484605.4745 * parameters.cpu_usage 
	- 0.011 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.0733 * parameters.avg_latency_of_same_last_20 
	+ 0.0036 * parameters.max_latency_of_same_last_50 
	- 603920925.8474;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM88(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	- 0.0873 * parameters.wait_so_far 
	- 403537.097 * parameters.total_wait_locks 
	- 0.5306 * parameters.mean_wait_of_all 
	- 68035233.6204 * parameters.cpu_usage 
	- 3.3574 * parameters.avg_work_of_same_past_second 
	+ 0.0176 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 0.0058 * parameters.max_latency_of_same_last_50 
	+ 479338838.4549;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM89(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	- 0.0956 * parameters.wait_so_far 
	- 403537.097 * parameters.total_wait_locks 
	+ 1.539 * parameters.mean_wait_of_all 
	- 68035233.6204 * parameters.cpu_usage 
	- 3.3574 * parameters.avg_work_of_same_past_second 
	+ 0.0176 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 0.0058 * parameters.max_latency_of_same_last_50 
	+ 247422639.0157;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM90(work_wait &parameters) {
  double actual_remaining = 
	20.9613 * parameters.work_so_far 
	+ 0.0146 * parameters.wait_so_far 
	- 403537.097 * parameters.total_wait_locks 
	+ 1.539 * parameters.mean_wait_of_all 
	- 68035233.6204 * parameters.cpu_usage 
	- 3.4851 * parameters.avg_work_of_same_past_second 
	+ 0.0176 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 0.0219 * parameters.max_latency_of_same_last_50 
	+ 158829155.5663;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM91(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	+ 0.0139 * parameters.wait_so_far 
	- 403537.097 * parameters.total_wait_locks 
	+ 1.539 * parameters.mean_wait_of_all 
	- 68035233.6204 * parameters.cpu_usage 
	- 3.4851 * parameters.avg_work_of_same_past_second 
	+ 0.0176 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 0.0209 * parameters.max_latency_of_same_last_50 
	+ 167641320.8443;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM92(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	+ 0.0116 * parameters.wait_so_far 
	- 403537.097 * parameters.total_wait_locks 
	+ 1.539 * parameters.mean_wait_of_all 
	- 68035233.6204 * parameters.cpu_usage 
	- 4.1445 * parameters.avg_work_of_same_past_second 
	+ 0.0176 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 0.0155 * parameters.max_latency_of_same_last_50 
	+ 183986481.3492;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM93(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 443156.0891 * parameters.total_wait_locks 
	+ 2.2285 * parameters.mean_wait_of_all 
	- 68035233.6204 * parameters.cpu_usage 
	- 1.217 * parameters.avg_work_of_same_past_second 
	+ 0.0176 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 0.0058 * parameters.max_latency_of_same_last_50 
	+ 54311369.234;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM94(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	+ 0.0048 * parameters.wait_so_far 
	- 417666.3813 * parameters.total_wait_locks 
	+ 2.7238 * parameters.mean_wait_of_all 
	- 68035233.6204 * parameters.cpu_usage 
	- 0.7335 * parameters.avg_work_of_same_past_second 
	+ 0.0176 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 0.0058 * parameters.max_latency_of_same_last_50 
	- 17514854.9708;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM95(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	+ 0.004 * parameters.wait_so_far 
	- 417666.3813 * parameters.total_wait_locks 
	+ 2.7238 * parameters.mean_wait_of_all 
	- 68035233.6204 * parameters.cpu_usage 
	- 0.6527 * parameters.avg_work_of_same_past_second 
	+ 0.0176 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 0.0058 * parameters.max_latency_of_same_last_50 
	- 19186187.8098;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM96(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 417666.3813 * parameters.total_wait_locks 
	+ 2.7238 * parameters.mean_wait_of_all 
	- 68035233.6204 * parameters.cpu_usage 
	+ 0.3244 * parameters.avg_work_of_same_past_second 
	+ 0.0176 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 0.0058 * parameters.max_latency_of_same_last_50 
	- 36456218.4856;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM97(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 417666.3813 * parameters.total_wait_locks 
	+ 2.6841 * parameters.mean_wait_of_all 
	- 68035233.6204 * parameters.cpu_usage 
	- 1.4892 * parameters.avg_work_of_same_past_second 
	+ 0.0176 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 0.0058 * parameters.max_latency_of_same_last_50 
	+ 90446.7937;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM98(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 405115.0659 * parameters.total_wait_locks 
	- 18.3917 * parameters.mean_wait_of_all 
	- 616828453.096 * parameters.cpu_usage 
	- 0.1944 * parameters.avg_work_of_same_past_second 
	- 1.9834 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 0.0134 * parameters.max_latency_of_same_last_50 
	+ 4282101244.3285;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM99(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 509379.1106 * parameters.total_wait_locks 
	- 15.3674 * parameters.mean_wait_of_all 
	- 616828453.096 * parameters.cpu_usage 
	- 0.1944 * parameters.avg_work_of_same_past_second 
	- 1.9834 * parameters.avg_wait_of_same_past_second 
	- 0.0438 * parameters.avg_latency_of_same_last_20 
	+ 0.0134 * parameters.max_latency_of_same_last_50 
	+ 3973578694.0568;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM100(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 509379.1106 * parameters.total_wait_locks 
	+ 2.0727 * parameters.mean_wait_of_all 
	- 723149420.1611 * parameters.cpu_usage 
	- 0.1944 * parameters.avg_work_of_same_past_second 
	- 1.8478 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 0.0134 * parameters.max_latency_of_same_last_50 
	+ 1827193527.7851;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM101(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 553756.5273 * parameters.total_wait_locks 
	+ 3.1539 * parameters.mean_wait_of_all 
	+ 248727335.8868 * parameters.cpu_usage 
	- 1.5877 * parameters.avg_work_of_same_past_second 
	- 0.0597 * parameters.avg_wait_of_same_past_second 
	+ 0.0561 * parameters.avg_latency_of_same_last_20 
	+ 0.0012 * parameters.max_latency_of_same_last_50 
	- 275350702.2597;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM102(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	+ 0.0021 * parameters.wait_so_far 
	- 575161.3327 * parameters.total_wait_locks 
	+ 6.3482 * parameters.mean_wait_of_all 
	- 461575.3462 * parameters.cpu_usage 
	+ 0.0352 * parameters.avg_work_of_same_past_second 
	- 0.0502 * parameters.avg_wait_of_same_past_second 
	+ 0.0237 * parameters.avg_latency_of_same_last_20 
	+ 0.0004 * parameters.max_latency_of_same_last_50 
	- 383666627.5535;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM103(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	+ 0.0027 * parameters.wait_so_far 
	- 77152.4142 * parameters.total_wait_locks 
	+ 1.3966 * parameters.mean_wait_of_all 
	- 461575.3462 * parameters.cpu_usage 
	+ 0.0352 * parameters.avg_work_of_same_past_second 
	- 0.234 * parameters.avg_wait_of_same_past_second 
	+ 0.006 * parameters.avg_latency_of_same_last_20 
	+ 0.0004 * parameters.max_latency_of_same_last_50 
	+ 13720665.6117;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM104(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 319008.2335 * parameters.total_wait_locks 
	+ 1.7151 * parameters.mean_wait_of_all 
	- 461575.3462 * parameters.cpu_usage 
	+ 0.3197 * parameters.avg_work_of_same_past_second 
	- 0.0011 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 0.0004 * parameters.max_latency_of_same_last_50 
	- 36506056.1123;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
payment_LM105(work_wait &parameters) {
  double actual_remaining = 
	0.0002 * parameters.work_so_far 
	- 0 * parameters.wait_so_far 
	- 179735.2204 * parameters.total_wait_locks 
	+ 1.3473 * parameters.mean_wait_of_all 
	- 252860186.5536 * parameters.cpu_usage 
	- 0.0054 * parameters.avg_work_of_same_past_second 
	- 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0092 * parameters.avg_latency_of_same_last_20 
	+ 0.0001 * parameters.max_latency_of_same_last_50 
	+ 196785735.5768;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
payment_estimate(work_wait &parameters){

  if (parameters.work_so_far <= 15004.5) {

    if (parameters.work_so_far <= 9713) {
      return payment_LM1(parameters);
    } else {
      return payment_LM2(parameters);
    }
  } else {

    if (parameters.total_wait_locks <= 232.5) {

      if (parameters.mean_wait_of_all <= 50145950) {

        if (parameters.total_wait_locks <= 151.5) {

          if (parameters.max_latency_of_same_last_50 <= 329139000) {

            if (parameters.mean_wait_of_all <= 39098850) {

              if (parameters.avg_latency_of_same_last_20 <= 49673400) {

                if (parameters.wait_so_far <= 54507694.5) {
                  return payment_LM3(parameters);
                } else {

                  if (parameters.work_so_far <= 19971.5) {
                    return payment_LM4(parameters);
                  } else {
                    return payment_LM5(parameters);
                  }
                }
              } else {

                if (parameters.max_latency_of_same_last_50 <= 244535000) {
                  return payment_LM6(parameters);
                } else {

                  if (parameters.avg_wait_of_same_past_second <= 20657450) {
                    return payment_LM7(parameters);
                  } else {
                    return payment_LM8(parameters);
                  }
                }
              }
            } else {

              if (parameters.mean_wait_of_all <= 44025250) {

                if (parameters.avg_work_of_same_past_second <= 7027485) {
                  return payment_LM9(parameters);
                } else {

                  if (parameters.total_wait_locks <= 31) {
                    return payment_LM10(parameters);
                  } else {

                    if (parameters.avg_work_of_same_past_second <= 7603630) {
                      return payment_LM11(parameters);
                    } else {
                      return payment_LM12(parameters);
                    }
                  }
                }
              } else {
                return payment_LM13(parameters);
              }
            }
          } else {
            return payment_LM14(parameters);
          }
        } else {

          if (parameters.avg_work_of_same_past_second <= 13924100) {

            if (parameters.max_latency_of_same_last_50 <= 769962500) {

              if (parameters.avg_work_of_same_past_second <= 7980775) {

                if (parameters.avg_wait_of_same_past_second <= 18952550) {
                  return payment_LM15(parameters);
                } else {

                  if (parameters.avg_work_of_same_past_second <= 6670910) {
                    return payment_LM16(parameters);
                  } else {

                    if (parameters.avg_wait_of_same_past_second <= 45826150) {
                      return payment_LM17(parameters);
                    } else {
                      return payment_LM18(parameters);
                    }
                  }
                }
              } else {
                return payment_LM19(parameters);
              }
            } else {

              if (parameters.max_latency_of_same_last_50 <= 882392500) {

                if (parameters.cpu_usage <= 0.923) {

                  if (parameters.total_wait_locks <= 167) {
                    return payment_LM20(parameters);
                  } else {

                    if (parameters.wait_so_far <= 203469314) {
                      return payment_LM21(parameters);
                    } else {
                      return payment_LM22(parameters);
                    }
                  }
                } else {
                  return payment_LM23(parameters);
                }
              } else {

                if (parameters.work_so_far <= 30443.5) {
                  return payment_LM24(parameters);
                } else {
                  return payment_LM25(parameters);
                }
              }
            }
          } else {

            if (parameters.avg_wait_of_same_past_second <= 333058000) {

              if (parameters.avg_wait_of_same_past_second <= 288451000) {

                if (parameters.avg_work_of_same_past_second <= 17426850) {
                  return payment_LM26(parameters);
                } else {
                  return payment_LM27(parameters);
                }
              } else {

                if (parameters.avg_wait_of_same_past_second <= 295091000) {

                  if (parameters.work_so_far <= 38591) {
                    return payment_LM28(parameters);
                  } else {
                    return payment_LM29(parameters);
                  }
                } else {

                  if (parameters.mean_wait_of_all <= 40413150) {

                    if (parameters.avg_latency_of_same_last_20 <= 341770500) {
                      return payment_LM30(parameters);
                    } else {

                      if (parameters.total_wait_locks <= 181.5) {
                        return payment_LM31(parameters);
                      } else {
                        return payment_LM32(parameters);
                      }
                    }
                  } else {
                    return payment_LM33(parameters);
                  }
                }
              }
            } else {

              if (parameters.avg_work_of_same_past_second <= 21791950) {

                if (parameters.avg_work_of_same_past_second <= 19788750) {
                  return payment_LM34(parameters);
                } else {

                  if (parameters.avg_work_of_same_past_second <= 21396850) {
                    return payment_LM35(parameters);
                  } else {
                    return payment_LM36(parameters);
                  }
                }
              } else {

                if (parameters.max_latency_of_same_last_50 <= 1319830000) {

                  if (parameters.total_wait_locks <= 191) {

                    if (parameters.mean_wait_of_all <= 37538050) {
                      return payment_LM37(parameters);
                    } else {

                      if (parameters.max_latency_of_same_last_50 <= 1250005000) {
                        return payment_LM38(parameters);
                      } else {
                        return payment_LM39(parameters);
                      }
                    }
                  } else {

                    if (parameters.wait_so_far <= 297328746) {
                      return payment_LM40(parameters);
                    } else {
                      return payment_LM41(parameters);
                    }
                  }
                } else {

                  if (parameters.avg_work_of_same_past_second <= 25622350) {
                    return payment_LM42(parameters);
                  } else {
                    return payment_LM43(parameters);
                  }
                }
              }
            }
          }
        }
      } else {
        return payment_LM44(parameters);
      }
    } else {

      if (parameters.wait_so_far <= 258636968) {

        if (parameters.avg_wait_of_same_past_second <= 346041000) {

          if (parameters.wait_so_far <= 196520509.5) {

            if (parameters.work_so_far <= 33606) {
              return payment_LM45(parameters);
            } else {

              if (parameters.cpu_usage <= 0.975) {

                if (parameters.wait_so_far <= 61547634.5) {

                  if (parameters.avg_work_of_same_past_second <= 21622600) {
                    return payment_LM46(parameters);
                  } else {
                    return payment_LM47(parameters);
                  }
                } else {

                  if (parameters.avg_wait_of_same_past_second <= 329803500) {
                    return payment_LM48(parameters);
                  } else {

                    if (parameters.max_latency_of_same_last_50 <= 1349775000) {
                      return payment_LM49(parameters);
                    } else {
                      return payment_LM50(parameters);
                    }
                  }
                }
              } else {

                if (parameters.avg_wait_of_same_past_second <= 332631000) {

                  if (parameters.total_wait_locks <= 301.5) {
                    return payment_LM51(parameters);
                  } else {

                    if (parameters.wait_so_far <= 56933160) {
                      return payment_LM52(parameters);
                    } else {

                      if (parameters.mean_wait_of_all <= 78924650) {
                        return payment_LM53(parameters);
                      } else {

                        if (parameters.mean_wait_of_all <= 82275500) {

                          if (parameters.total_wait_locks <= 347.5) {
                            return payment_LM54(parameters);
                          } else {
                            return payment_LM55(parameters);
                          }
                        } else {
                          return payment_LM56(parameters);
                        }
                      }
                    }
                  }
                } else {

                  if (parameters.work_so_far <= 59710.5) {

                    if (parameters.max_latency_of_same_last_50 <= 1221530000) {
                      return payment_LM57(parameters);
                    } else {

                      if (parameters.work_so_far <= 34501.5) {
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
          } else {

            if (parameters.work_so_far <= 43832) {
              return payment_LM61(parameters);
            } else {
              return payment_LM62(parameters);
            }
          }
        } else {

          if (parameters.avg_latency_of_same_last_20 <= 414186500) {
            return payment_LM63(parameters);
          } else {

            if (parameters.avg_wait_of_same_past_second <= 467458000) {
              return payment_LM64(parameters);
            } else {
              return payment_LM65(parameters);
            }
          }
        }
      } else {

        if (parameters.mean_wait_of_all <= 97932650) {
          return payment_LM66(parameters);
        } else {

          if (parameters.total_wait_locks <= 534.5) {

            if (parameters.avg_work_of_same_past_second <= 31051650) {

              if (parameters.max_latency_of_same_last_50 <= 1350585000) {

                if (parameters.max_latency_of_same_last_50 <= 803719500) {

                  if (parameters.avg_wait_of_same_past_second <= 377345500) {

                    if (parameters.avg_wait_of_same_past_second <= 365166000) {
                      return payment_LM67(parameters);
                    } else {

                      if (parameters.cpu_usage <= 0.968) {
                        return payment_LM68(parameters);
                      } else {
                        return payment_LM69(parameters);
                      }
                    }
                  } else {
                    return payment_LM70(parameters);
                  }
                } else {

                  if (parameters.max_latency_of_same_last_50 <= 1230395000) {

                    if (parameters.cpu_usage <= 0.967) {

                      if (parameters.mean_wait_of_all <= 109429000) {

                        if (parameters.avg_latency_of_same_last_20 <= 440821500) {
                          return payment_LM71(parameters);
                        } else {
                          return payment_LM72(parameters);
                        }
                      } else {
                        return payment_LM73(parameters);
                      }
                    } else {

                      if (parameters.total_wait_locks <= 476.5) {

                        if (parameters.max_latency_of_same_last_50 <= 980427500) {
                          return payment_LM74(parameters);
                        } else {
                          return payment_LM75(parameters);
                        }
                      } else {
                        return payment_LM76(parameters);
                      }
                    }
                  } else {

                    if (parameters.avg_latency_of_same_last_20 <= 600015000) {

                      if (parameters.avg_wait_of_same_past_second <= 419586500) {

                        if (parameters.avg_latency_of_same_last_20 <= 475651500) {

                          if (parameters.avg_wait_of_same_past_second <= 375458000) {
                            return payment_LM77(parameters);
                          } else {
                            return payment_LM78(parameters);
                          }
                        } else {

                          if (parameters.total_wait_locks <= 386.5) {
                            return payment_LM79(parameters);
                          } else {
                            return payment_LM80(parameters);
                          }
                        }
                      } else {
                        return payment_LM81(parameters);
                      }
                    } else {

                      if (parameters.avg_latency_of_same_last_20 <= 658736500) {

                        if (parameters.cpu_usage <= 0.955) {
                          return payment_LM82(parameters);
                        } else {

                          if (parameters.work_so_far <= 32107) {
                            return payment_LM83(parameters);
                          } else {

                            if (parameters.work_so_far <= 36819.5) {
                              return payment_LM84(parameters);
                            } else {
                              return payment_LM85(parameters);
                            }
                          }
                        }
                      } else {

                        if (parameters.total_wait_locks <= 462) {
                          return payment_LM86(parameters);
                        } else {
                          return payment_LM87(parameters);
                        }
                      }
                    }
                  }
                }
              } else {

                if (parameters.avg_latency_of_same_last_20 <= 489368500) {

                  if (parameters.avg_wait_of_same_past_second <= 574227500) {

                    if (parameters.total_wait_locks <= 439.5) {

                      if (parameters.max_latency_of_same_last_50 <= 1499530000) {

                        if (parameters.wait_so_far <= 405095284.5) {
                          return payment_LM88(parameters);
                        } else {
                          return payment_LM89(parameters);
                        }
                      } else {

                        if (parameters.avg_work_of_same_past_second <= 27104000) {

                          if (parameters.max_latency_of_same_last_50 <= 1655940000) {
                            return payment_LM90(parameters);
                          } else {
                            return payment_LM91(parameters);
                          }
                        } else {
                          return payment_LM92(parameters);
                        }
                      }
                    } else {

                      if (parameters.mean_wait_of_all <= 110094500) {
                        return payment_LM93(parameters);
                      } else {

                        if (parameters.avg_work_of_same_past_second <= 24106000) {

                          if (parameters.mean_wait_of_all <= 114940000) {

                            if (parameters.avg_work_of_same_past_second <= 20638400) {
                              return payment_LM94(parameters);
                            } else {
                              return payment_LM95(parameters);
                            }
                          } else {
                            return payment_LM96(parameters);
                          }
                        } else {
                          return payment_LM97(parameters);
                        }
                      }
                    }
                  } else {

                    if (parameters.avg_wait_of_same_past_second <= 593417000) {

                      if (parameters.total_wait_locks <= 526.5) {
                        return payment_LM98(parameters);
                      } else {
                        return payment_LM99(parameters);
                      }
                    } else {
                      return payment_LM100(parameters);
                    }
                  }
                } else {
                  return payment_LM101(parameters);
                }
              }
            } else {

              if (parameters.total_wait_locks <= 421.5) {

                if (parameters.mean_wait_of_all <= 102090500) {
                  return payment_LM102(parameters);
                } else {
                  return payment_LM103(parameters);
                }
              } else {
                return payment_LM104(parameters);
              }
            }
          } else {
            return payment_LM105(parameters);
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
	1.2695 * parameters.work_so_far 
	- 0.1861 * parameters.wait_so_far 
	- 17085381.5335 * parameters.num_locks_so_far 
	+ 197173.5822 * parameters.total_wait_locks 
	+ 0.1767 * parameters.avg_work_of_same_past_second 
	- 0.2447 * parameters.avg_wait_of_same_past_second 
	+ 0.6847 * parameters.avg_latency_of_same_last_20 
	+ 158044556.3224;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
delivery_estimate(work_wait &parameters){
  return delivery_LM1(parameters);
}
static
double
stock_level_LM1(work_wait &parameters) {
  double actual_remaining = 
	-0.0512 * parameters.wait_so_far 
	- 116182.2031 * parameters.num_locks_so_far 
	+ 30718.8634 * parameters.total_wait_locks 
	+ 0.0523 * parameters.avg_latency_of_same_last_20 
	+ 11712879.2348;
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
	16.1933 * parameters.work_so_far 
	+ 0.0003 * parameters.wait_so_far 
	- 946.6199 * parameters.num_locks_so_far 
	+ 148.1797 * parameters.total_wait_locks 
	- 0.0003 * parameters.mean_wait_of_all 
	+ 0.0029 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 5480112.2989;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM2(work_wait &parameters) {
  double actual_remaining = 
	27.2019 * parameters.work_so_far 
	+ 0.0006 * parameters.wait_so_far 
	- 946.6199 * parameters.num_locks_so_far 
	+ 148.1797 * parameters.total_wait_locks 
	- 0.0003 * parameters.mean_wait_of_all 
	+ 0.0029 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 7161289.4858;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM3(work_wait &parameters) {
  double actual_remaining = 
	-11879.8067 * parameters.work_so_far 
	+ 0.0169 * parameters.wait_so_far 
	- 946.6199 * parameters.num_locks_so_far 
	- 154865.9417 * parameters.total_wait_locks 
	+ 1.0669 * parameters.mean_wait_of_all 
	- 18.628 * parameters.avg_work_of_same_past_second 
	- 0.0317 * parameters.avg_wait_of_same_past_second 
	- 0.0131 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 299335952.5671;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM4(work_wait &parameters) {
  double actual_remaining = 
	-4872.6124 * parameters.work_so_far 
	+ 0.0169 * parameters.wait_so_far 
	- 946.6199 * parameters.num_locks_so_far 
	- 165556.5708 * parameters.total_wait_locks 
	- 0.0003 * parameters.mean_wait_of_all 
	- 4.8454 * parameters.avg_work_of_same_past_second 
	- 0.0317 * parameters.avg_wait_of_same_past_second 
	- 0.0131 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 127338172.6268;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM5(work_wait &parameters) {
  double actual_remaining = 
	595.5402 * parameters.work_so_far 
	+ 0.0076 * parameters.wait_so_far 
	- 946.6199 * parameters.num_locks_so_far 
	+ 148.1797 * parameters.total_wait_locks 
	+ 0.0841 * parameters.mean_wait_of_all 
	+ 7767787.8917 * parameters.cpu_usage 
	- 0.0586 * parameters.avg_work_of_same_past_second 
	- 0.0111 * parameters.avg_wait_of_same_past_second 
	- 0.0043 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 7452577.8325;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM6(work_wait &parameters) {
  double actual_remaining = 
	324.6334 * parameters.work_so_far 
	+ 0.0076 * parameters.wait_so_far 
	- 946.6199 * parameters.num_locks_so_far 
	+ 148.1797 * parameters.total_wait_locks 
	+ 0.1075 * parameters.mean_wait_of_all 
	+ 10272262.1281 * parameters.cpu_usage 
	- 0.0586 * parameters.avg_work_of_same_past_second 
	- 0.0111 * parameters.avg_wait_of_same_past_second 
	- 0.0043 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 7063509.7943;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM7(work_wait &parameters) {
  double actual_remaining = 
	324.6334 * parameters.work_so_far 
	+ 0.0076 * parameters.wait_so_far 
	- 946.6199 * parameters.num_locks_so_far 
	+ 148.1797 * parameters.total_wait_locks 
	+ 0.2998 * parameters.mean_wait_of_all 
	- 89352258.734 * parameters.cpu_usage 
	- 0.0586 * parameters.avg_work_of_same_past_second 
	- 0.0111 * parameters.avg_wait_of_same_past_second 
	- 0.0043 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 79952292.4458;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM8(work_wait &parameters) {
  double actual_remaining = 
	324.6334 * parameters.work_so_far 
	+ 0.0076 * parameters.wait_so_far 
	- 946.6199 * parameters.num_locks_so_far 
	+ 148.1797 * parameters.total_wait_locks 
	- 0.2551 * parameters.mean_wait_of_all 
	- 89352258.734 * parameters.cpu_usage 
	- 0.0586 * parameters.avg_work_of_same_past_second 
	- 0.0111 * parameters.avg_wait_of_same_past_second 
	- 0.0043 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 110441729.0642;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM9(work_wait &parameters) {
  double actual_remaining = 
	324.6334 * parameters.work_so_far 
	+ 0.0076 * parameters.wait_so_far 
	- 946.6199 * parameters.num_locks_so_far 
	+ 148.1797 * parameters.total_wait_locks 
	+ 0.2998 * parameters.mean_wait_of_all 
	- 89352258.734 * parameters.cpu_usage 
	- 0.0586 * parameters.avg_work_of_same_past_second 
	- 0.0111 * parameters.avg_wait_of_same_past_second 
	- 0.0043 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 80953554.0519;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM10(work_wait &parameters) {
  double actual_remaining = 
	324.6334 * parameters.work_so_far 
	+ 0.0076 * parameters.wait_so_far 
	- 946.6199 * parameters.num_locks_so_far 
	+ 9284.284 * parameters.total_wait_locks 
	+ 0.4613 * parameters.mean_wait_of_all 
	- 173036856.2581 * parameters.cpu_usage 
	- 0.0586 * parameters.avg_work_of_same_past_second 
	- 0.0111 * parameters.avg_wait_of_same_past_second 
	- 0.0043 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 158629127.0131;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM11(work_wait &parameters) {
  double actual_remaining = 
	324.6334 * parameters.work_so_far 
	+ 0.0076 * parameters.wait_so_far 
	- 946.6199 * parameters.num_locks_so_far 
	+ 9821.7019 * parameters.total_wait_locks 
	+ 0.4613 * parameters.mean_wait_of_all 
	- 173036856.2581 * parameters.cpu_usage 
	- 0.0586 * parameters.avg_work_of_same_past_second 
	- 0.0111 * parameters.avg_wait_of_same_past_second 
	- 0.0043 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 158835504.5914;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM12(work_wait &parameters) {
  double actual_remaining = 
	547.7396 * parameters.work_so_far 
	+ 0.0076 * parameters.wait_so_far 
	- 946.6199 * parameters.num_locks_so_far 
	+ 148.1797 * parameters.total_wait_locks 
	+ 0.4613 * parameters.mean_wait_of_all 
	- 173036856.2581 * parameters.cpu_usage 
	- 0.0586 * parameters.avg_work_of_same_past_second 
	- 0.0111 * parameters.avg_wait_of_same_past_second 
	- 0.0043 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 155542477.8185;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM13(work_wait &parameters) {
  double actual_remaining = 
	560.8634 * parameters.work_so_far 
	+ 0.0076 * parameters.wait_so_far 
	- 946.6199 * parameters.num_locks_so_far 
	+ 148.1797 * parameters.total_wait_locks 
	+ 0.4613 * parameters.mean_wait_of_all 
	- 173036856.2581 * parameters.cpu_usage 
	- 0.0586 * parameters.avg_work_of_same_past_second 
	- 0.0111 * parameters.avg_wait_of_same_past_second 
	- 0.0043 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 155567072.0288;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM14(work_wait &parameters) {
  double actual_remaining = 
	48.0828 * parameters.work_so_far 
	+ 0.0026 * parameters.wait_so_far 
	- 946.6199 * parameters.num_locks_so_far 
	+ 148.1797 * parameters.total_wait_locks 
	- 0.0003 * parameters.mean_wait_of_all 
	- 0.0503 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0003 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 7691837.5931;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM15(work_wait &parameters) {
  double actual_remaining = 
	9.0073 * parameters.work_so_far 
	+ 0.0132 * parameters.wait_so_far 
	- 946.6199 * parameters.num_locks_so_far 
	+ 148.1797 * parameters.total_wait_locks 
	- 0.0003 * parameters.mean_wait_of_all 
	+ 0.0029 * parameters.avg_work_of_same_past_second 
	- 0.0166 * parameters.avg_wait_of_same_past_second 
	+ 0.0156 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 11266715.4865;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM16(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	- 5281.19 * parameters.num_locks_so_far 
	+ 780.0039 * parameters.total_wait_locks 
	- 0.0012 * parameters.mean_wait_of_all 
	+ 40014.7042 * parameters.cpu_usage 
	+ 0.0008 * parameters.avg_work_of_same_past_second 
	+ 0.0012 * parameters.avg_wait_of_same_past_second 
	+ 0.0019 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 4538827.1809;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM17(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0006 * parameters.wait_so_far 
	- 131415.5545 * parameters.num_locks_so_far 
	+ 30061.5464 * parameters.total_wait_locks 
	- 0.0012 * parameters.mean_wait_of_all 
	+ 40014.7042 * parameters.cpu_usage 
	- 0.2568 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0421 * parameters.avg_latency_of_same_last_20 
	- 0.008 * parameters.max_latency_of_same_last_50 
	+ 16253085.8864;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM18(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0029 * parameters.wait_so_far 
	- 13291.0497 * parameters.num_locks_so_far 
	- 38033.1327 * parameters.total_wait_locks 
	- 0.7799 * parameters.mean_wait_of_all 
	- 29341703.846 * parameters.cpu_usage 
	+ 1.8957 * parameters.avg_work_of_same_past_second 
	- 0.1456 * parameters.avg_wait_of_same_past_second 
	+ 0.0075 * parameters.avg_latency_of_same_last_20 
	- 0.0037 * parameters.max_latency_of_same_last_50 
	+ 92300274.3996;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM19(work_wait &parameters) {
  double actual_remaining = 
	-0.3425 * parameters.work_so_far 
	- 0.0029 * parameters.wait_so_far 
	- 13291.0497 * parameters.num_locks_so_far 
	- 38033.1327 * parameters.total_wait_locks 
	- 1.031 * parameters.mean_wait_of_all 
	- 41160570.3917 * parameters.cpu_usage 
	+ 3.2963 * parameters.avg_work_of_same_past_second 
	- 0.2246 * parameters.avg_wait_of_same_past_second 
	+ 0.0075 * parameters.avg_latency_of_same_last_20 
	- 0.0037 * parameters.max_latency_of_same_last_50 
	+ 131154581.8754;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM20(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0029 * parameters.wait_so_far 
	- 13291.0497 * parameters.num_locks_so_far 
	- 77496.1179 * parameters.total_wait_locks 
	- 0.5271 * parameters.mean_wait_of_all 
	- 7570107.5776 * parameters.cpu_usage 
	- 1.2767 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0075 * parameters.avg_latency_of_same_last_20 
	- 0.0037 * parameters.max_latency_of_same_last_50 
	+ 84630754.4969;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM21(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0029 * parameters.wait_so_far 
	- 13291.0497 * parameters.num_locks_so_far 
	+ 1429.8525 * parameters.total_wait_locks 
	- 0.053 * parameters.mean_wait_of_all 
	- 3668471.2808 * parameters.cpu_usage 
	- 0.0916 * parameters.avg_work_of_same_past_second 
	+ 0.0932 * parameters.avg_wait_of_same_past_second 
	+ 0.0075 * parameters.avg_latency_of_same_last_20 
	- 0.0018 * parameters.max_latency_of_same_last_50 
	+ 18431198.646;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM22(work_wait &parameters) {
  double actual_remaining = 
	0.9046 * parameters.work_so_far 
	- 0.1015 * parameters.wait_so_far 
	- 20829.661 * parameters.num_locks_so_far 
	- 127180.6992 * parameters.total_wait_locks 
	- 0.0012 * parameters.mean_wait_of_all 
	+ 40014.7042 * parameters.cpu_usage 
	- 5.1636 * parameters.avg_work_of_same_past_second 
	- 0.0003 * parameters.avg_wait_of_same_past_second 
	+ 0.0943 * parameters.avg_latency_of_same_last_20 
	- 0 * parameters.max_latency_of_same_last_50 
	+ 150975697.3279;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM23(work_wait &parameters) {
  double actual_remaining = 
	-4.9155 * parameters.work_so_far 
	- 0.0021 * parameters.wait_so_far 
	- 13829.6689 * parameters.num_locks_so_far 
	+ 15013.5037 * parameters.total_wait_locks 
	- 0.0145 * parameters.mean_wait_of_all 
	+ 40014.7042 * parameters.cpu_usage 
	+ 0.0139 * parameters.avg_work_of_same_past_second 
	- 0.7401 * parameters.avg_wait_of_same_past_second 
	+ 0.012 * parameters.avg_latency_of_same_last_20 
	+ 0.0516 * parameters.max_latency_of_same_last_50 
	+ 40082332.8462;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM24(work_wait &parameters) {
  double actual_remaining = 
	-2.578 * parameters.work_so_far 
	- 0.0021 * parameters.wait_so_far 
	- 13829.6689 * parameters.num_locks_so_far 
	+ 9420.6979 * parameters.total_wait_locks 
	+ 0.6553 * parameters.mean_wait_of_all 
	+ 40014.7042 * parameters.cpu_usage 
	+ 0.0139 * parameters.avg_work_of_same_past_second 
	- 0.0426 * parameters.avg_wait_of_same_past_second 
	+ 0.0072 * parameters.avg_latency_of_same_last_20 
	- 0.063 * parameters.max_latency_of_same_last_50 
	+ 68349128.1727;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM25(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0056 * parameters.wait_so_far 
	- 27985.9978 * parameters.num_locks_so_far 
	+ 10042.554 * parameters.total_wait_locks 
	- 0.0462 * parameters.mean_wait_of_all 
	+ 40014.7042 * parameters.cpu_usage 
	+ 1.1254 * parameters.avg_work_of_same_past_second 
	- 0.6398 * parameters.avg_wait_of_same_past_second 
	+ 0.0014 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	- 2390091.7826;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM26(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	+ 1.5108 * parameters.wait_so_far 
	- 45298.5229 * parameters.num_locks_so_far 
	+ 285980.2142 * parameters.total_wait_locks 
	- 1.3459 * parameters.mean_wait_of_all 
	+ 28726676.2876 * parameters.cpu_usage 
	+ 0.0139 * parameters.avg_work_of_same_past_second 
	- 0.0062 * parameters.avg_wait_of_same_past_second 
	+ 0.0014 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 24117072.258;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM27(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0459 * parameters.wait_so_far 
	- 147770.6578 * parameters.num_locks_so_far 
	- 75202.2539 * parameters.total_wait_locks 
	+ 0.3079 * parameters.mean_wait_of_all 
	+ 29982007.1482 * parameters.cpu_usage 
	- 0.0514 * parameters.avg_work_of_same_past_second 
	- 0.0062 * parameters.avg_wait_of_same_past_second 
	+ 0.0014 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 14811153.048;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM28(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0067 * parameters.wait_so_far 
	- 148356.8917 * parameters.num_locks_so_far 
	+ 103963.4839 * parameters.total_wait_locks 
	- 0.4492 * parameters.mean_wait_of_all 
	+ 409341560.4259 * parameters.cpu_usage 
	- 0.8059 * parameters.avg_work_of_same_past_second 
	- 0.0062 * parameters.avg_wait_of_same_past_second 
	+ 0.0014 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	- 339791440.3162;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM29(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0067 * parameters.wait_so_far 
	- 200939.6667 * parameters.num_locks_so_far 
	+ 474906.136 * parameters.total_wait_locks 
	- 1.9648 * parameters.mean_wait_of_all 
	+ 2079019062.7581 * parameters.cpu_usage 
	- 0.7755 * parameters.avg_work_of_same_past_second 
	+ 0.203 * parameters.avg_wait_of_same_past_second 
	+ 0.0014 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	- 1951000464.5409;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM30(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0067 * parameters.wait_so_far 
	- 200939.6667 * parameters.num_locks_so_far 
	+ 474906.136 * parameters.total_wait_locks 
	- 1.9648 * parameters.mean_wait_of_all 
	+ 2476032994.5138 * parameters.cpu_usage 
	- 0.7755 * parameters.avg_work_of_same_past_second 
	+ 0.3512 * parameters.avg_wait_of_same_past_second 
	+ 0.1005 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	- 2373152820.8639;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM31(work_wait &parameters) {
  double actual_remaining = 
	0.1416 * parameters.work_so_far 
	- 0.0067 * parameters.wait_so_far 
	- 200939.6667 * parameters.num_locks_so_far 
	+ 638289.9459 * parameters.total_wait_locks 
	+ 2.7782 * parameters.mean_wait_of_all 
	+ 1915054605.9451 * parameters.cpu_usage 
	- 0.7755 * parameters.avg_work_of_same_past_second 
	- 0.0062 * parameters.avg_wait_of_same_past_second 
	+ 0.0014 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	- 2510846089.5896;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM32(work_wait &parameters) {
  double actual_remaining = 
	0.1565 * parameters.work_so_far 
	- 0.0067 * parameters.wait_so_far 
	- 200939.6667 * parameters.num_locks_so_far 
	+ 638289.9459 * parameters.total_wait_locks 
	+ 3.3496 * parameters.mean_wait_of_all 
	+ 1915054605.9451 * parameters.cpu_usage 
	- 0.7755 * parameters.avg_work_of_same_past_second 
	- 0.0062 * parameters.avg_wait_of_same_past_second 
	+ 0.0014 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	- 2574598596.619;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM33(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0348 * parameters.wait_so_far 
	- 200939.6667 * parameters.num_locks_so_far 
	+ 482719.2381 * parameters.total_wait_locks 
	- 2.0268 * parameters.mean_wait_of_all 
	+ 1684447609.0359 * parameters.cpu_usage 
	- 0.7755 * parameters.avg_work_of_same_past_second 
	- 0.0062 * parameters.avg_wait_of_same_past_second 
	+ 0.0014 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	- 1554237217.816;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM34(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0067 * parameters.wait_so_far 
	+ 150518.2018 * parameters.num_locks_so_far 
	+ 214241.5351 * parameters.total_wait_locks 
	- 0.838 * parameters.mean_wait_of_all 
	+ 800695530.2965 * parameters.cpu_usage 
	- 0.7755 * parameters.avg_work_of_same_past_second 
	- 0.0062 * parameters.avg_wait_of_same_past_second 
	+ 0.0462 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	- 782812044.4199;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM35(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0067 * parameters.wait_so_far 
	- 222973.193 * parameters.num_locks_so_far 
	+ 151364.6711 * parameters.total_wait_locks 
	- 0.5423 * parameters.mean_wait_of_all 
	+ 706190006.3811 * parameters.cpu_usage 
	- 1.3522 * parameters.avg_work_of_same_past_second 
	- 0.0062 * parameters.avg_wait_of_same_past_second 
	+ 0.0014 * parameters.avg_latency_of_same_last_20 
	+ 0.0084 * parameters.max_latency_of_same_last_50 
	- 624664304.919;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM36(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0067 * parameters.wait_so_far 
	- 215207.1562 * parameters.num_locks_so_far 
	+ 151364.6711 * parameters.total_wait_locks 
	- 0.5423 * parameters.mean_wait_of_all 
	+ 706190006.3811 * parameters.cpu_usage 
	- 1.3522 * parameters.avg_work_of_same_past_second 
	- 0.0062 * parameters.avg_wait_of_same_past_second 
	+ 0.0014 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	- 612960340.7029;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM37(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0124 * parameters.wait_so_far 
	- 245596.6436 * parameters.num_locks_so_far 
	+ 17100.6592 * parameters.total_wait_locks 
	- 0.2086 * parameters.mean_wait_of_all 
	+ 143705796.5818 * parameters.cpu_usage 
	+ 0.0139 * parameters.avg_work_of_same_past_second 
	- 0.0062 * parameters.avg_wait_of_same_past_second 
	+ 0.0014 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	- 75089034.7398;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM38(work_wait &parameters) {
  double actual_remaining = 
	-0.1858 * parameters.work_so_far 
	- 0.0124 * parameters.wait_so_far 
	- 214824.8757 * parameters.num_locks_so_far 
	+ 17100.6592 * parameters.total_wait_locks 
	- 0.3903 * parameters.mean_wait_of_all 
	+ 675554284.7814 * parameters.cpu_usage 
	+ 0.0139 * parameters.avg_work_of_same_past_second 
	- 0.0062 * parameters.avg_wait_of_same_past_second 
	+ 0.0014 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	- 543112445.1069;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM39(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0124 * parameters.wait_so_far 
	- 70922.5196 * parameters.num_locks_so_far 
	+ 17100.6592 * parameters.total_wait_locks 
	- 0.3454 * parameters.mean_wait_of_all 
	+ 387162070.826 * parameters.cpu_usage 
	+ 0.0139 * parameters.avg_work_of_same_past_second 
	- 0.0062 * parameters.avg_wait_of_same_past_second 
	+ 0.0014 * parameters.avg_latency_of_same_last_20 
	+ 0.0078 * parameters.max_latency_of_same_last_50 
	- 326252727.2796;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM40(work_wait &parameters) {
  double actual_remaining = 
	0.0001 * parameters.work_so_far 
	- 0.0115 * parameters.wait_so_far 
	- 38986.2022 * parameters.num_locks_so_far 
	+ 17100.6592 * parameters.total_wait_locks 
	- 0.1056 * parameters.mean_wait_of_all 
	+ 22148700.04 * parameters.cpu_usage 
	+ 0.0139 * parameters.avg_work_of_same_past_second 
	- 0.0062 * parameters.avg_wait_of_same_past_second 
	+ 0.0014 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	- 6085560.1634;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM41(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	+ 0.0829 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	+ 47895.9242 * parameters.total_wait_locks 
	+ 0.3611 * parameters.mean_wait_of_all 
	- 34138732.5472 * parameters.cpu_usage 
	+ 0.0272 * parameters.avg_work_of_same_past_second 
	+ 0.9715 * parameters.avg_wait_of_same_past_second 
	- 0.0493 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 58000746.0845;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM42(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	+ 0.06 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	+ 47895.9242 * parameters.total_wait_locks 
	+ 0.5103 * parameters.mean_wait_of_all 
	- 34138732.5472 * parameters.cpu_usage 
	+ 0.0272 * parameters.avg_work_of_same_past_second 
	+ 0.9715 * parameters.avg_wait_of_same_past_second 
	- 0.0493 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 72754156.2369;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM43(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	+ 0.0273 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	+ 63297.0366 * parameters.total_wait_locks 
	+ 0.2263 * parameters.mean_wait_of_all 
	- 39943995.6126 * parameters.cpu_usage 
	+ 0.0272 * parameters.avg_work_of_same_past_second 
	+ 1.2865 * parameters.avg_wait_of_same_past_second 
	- 0.0655 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 85473279.7881;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM44(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	+ 0.0015 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	+ 409.1609 * parameters.total_wait_locks 
	- 0.112 * parameters.mean_wait_of_all 
	+ 131369389.8665 * parameters.cpu_usage 
	+ 0.0272 * parameters.avg_work_of_same_past_second 
	+ 0.0001 * parameters.avg_wait_of_same_past_second 
	+ 0.0005 * parameters.avg_latency_of_same_last_20 
	+ 0.0229 * parameters.max_latency_of_same_last_50 
	- 110260613.3427;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM45(work_wait &parameters) {
  double actual_remaining = 
	0.8838 * parameters.work_so_far 
	- 0.0045 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	+ 25012.2597 * parameters.total_wait_locks 
	- 0.3118 * parameters.mean_wait_of_all 
	+ 1653602.8068 * parameters.cpu_usage 
	+ 0.0187 * parameters.avg_work_of_same_past_second 
	+ 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.0002 * parameters.avg_latency_of_same_last_20 
	+ 0.0061 * parameters.max_latency_of_same_last_50 
	+ 19760721.6049;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM46(work_wait &parameters) {
  double actual_remaining = 
	0.2422 * parameters.work_so_far 
	- 0.0167 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	+ 9076.3253 * parameters.total_wait_locks 
	- 0.039 * parameters.mean_wait_of_all 
	+ 2674306.5579 * parameters.cpu_usage 
	- 0.3095 * parameters.avg_work_of_same_past_second 
	+ 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.0006 * parameters.avg_latency_of_same_last_20 
	+ 0.0171 * parameters.max_latency_of_same_last_50 
	+ 21711378.0169;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM47(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0167 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	+ 9076.3253 * parameters.total_wait_locks 
	- 0.039 * parameters.mean_wait_of_all 
	+ 2674306.5579 * parameters.cpu_usage 
	- 0.3095 * parameters.avg_work_of_same_past_second 
	+ 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.0006 * parameters.avg_latency_of_same_last_20 
	+ 0.0173 * parameters.max_latency_of_same_last_50 
	+ 24646739.232;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM48(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0241 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	+ 9076.3253 * parameters.total_wait_locks 
	- 0.039 * parameters.mean_wait_of_all 
	+ 2674306.5579 * parameters.cpu_usage 
	- 0.3095 * parameters.avg_work_of_same_past_second 
	+ 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.0006 * parameters.avg_latency_of_same_last_20 
	+ 0.0167 * parameters.max_latency_of_same_last_50 
	+ 18296649.6212;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM49(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	+ 9076.3253 * parameters.total_wait_locks 
	- 0.039 * parameters.mean_wait_of_all 
	+ 2674306.5579 * parameters.cpu_usage 
	+ 1.0951 * parameters.avg_work_of_same_past_second 
	+ 0.1929 * parameters.avg_wait_of_same_past_second 
	- 0.0006 * parameters.avg_latency_of_same_last_20 
	+ 0.0061 * parameters.max_latency_of_same_last_50 
	- 69793718.5966;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM50(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	+ 9076.3253 * parameters.total_wait_locks 
	- 0.039 * parameters.mean_wait_of_all 
	+ 2674306.5579 * parameters.cpu_usage 
	+ 0.8423 * parameters.avg_work_of_same_past_second 
	+ 0.1582 * parameters.avg_wait_of_same_past_second 
	- 0.0006 * parameters.avg_latency_of_same_last_20 
	+ 0.0084 * parameters.max_latency_of_same_last_50 
	- 52982520.8503;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM51(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	+ 9076.3253 * parameters.total_wait_locks 
	- 0.039 * parameters.mean_wait_of_all 
	+ 2674306.5579 * parameters.cpu_usage 
	+ 0.8423 * parameters.avg_work_of_same_past_second 
	+ 0.1582 * parameters.avg_wait_of_same_past_second 
	- 0.0006 * parameters.avg_latency_of_same_last_20 
	+ 0.0096 * parameters.max_latency_of_same_last_50 
	- 49067143.9445;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM52(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	+ 7263.0414 * parameters.total_wait_locks 
	- 0.0312 * parameters.mean_wait_of_all 
	+ 2674306.5579 * parameters.cpu_usage 
	+ 1.4912 * parameters.avg_work_of_same_past_second 
	+ 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.0006 * parameters.avg_latency_of_same_last_20 
	- 0.0015 * parameters.max_latency_of_same_last_50 
	- 17984178.7816;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM53(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	+ 7263.0414 * parameters.total_wait_locks 
	- 0.0312 * parameters.mean_wait_of_all 
	+ 2674306.5579 * parameters.cpu_usage 
	+ 0.4068 * parameters.avg_work_of_same_past_second 
	+ 0.0001 * parameters.avg_wait_of_same_past_second 
	- 0.0006 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 8030922.8886;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM54(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	+ 930.5864 * parameters.total_wait_locks 
	- 0.0044 * parameters.mean_wait_of_all 
	+ 1214645.6596 * parameters.cpu_usage 
	+ 7.1028 * parameters.avg_work_of_same_past_second 
	- 0.0696 * parameters.avg_wait_of_same_past_second 
	+ 0.0005 * parameters.avg_latency_of_same_last_20 
	+ 0.0004 * parameters.max_latency_of_same_last_50 
	- 115315311.3758;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM55(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0082 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	+ 9174.7651 * parameters.total_wait_locks 
	- 0.0028 * parameters.mean_wait_of_all 
	- 630184.8301 * parameters.cpu_usage 
	- 0.0142 * parameters.avg_work_of_same_past_second 
	+ 0.0004 * parameters.avg_wait_of_same_past_second 
	+ 0.0221 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 10555870.0516;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM56(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	+ 1605.0136 * parameters.total_wait_locks 
	- 0.0003 * parameters.mean_wait_of_all 
	- 165380.566 * parameters.cpu_usage 
	- 0.0265 * parameters.avg_work_of_same_past_second 
	- 0.0027 * parameters.avg_wait_of_same_past_second 
	+ 0.0017 * parameters.avg_latency_of_same_last_20 
	+ 0.0087 * parameters.max_latency_of_same_last_50 
	+ 7571578.0248;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM57(work_wait &parameters) {
  double actual_remaining = 
	4.853 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 95365.6335 * parameters.total_wait_locks 
	+ 0.5185 * parameters.mean_wait_of_all 
	- 165380.566 * parameters.cpu_usage 
	- 0.2083 * parameters.avg_work_of_same_past_second 
	+ 0.0908 * parameters.avg_wait_of_same_past_second 
	+ 0.0378 * parameters.avg_latency_of_same_last_20 
	- 0.0034 * parameters.max_latency_of_same_last_50 
	- 1651210.2149;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM58(work_wait &parameters) {
  double actual_remaining = 
	9.4941 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 208420.2289 * parameters.total_wait_locks 
	+ 0.5185 * parameters.mean_wait_of_all 
	- 165380.566 * parameters.cpu_usage 
	- 0.2083 * parameters.avg_work_of_same_past_second 
	- 0.0408 * parameters.avg_wait_of_same_past_second 
	+ 0.0378 * parameters.avg_latency_of_same_last_20 
	- 0.0034 * parameters.max_latency_of_same_last_50 
	+ 50305457.2617;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM59(work_wait &parameters) {
  double actual_remaining = 
	-5.7498 * parameters.work_so_far 
	- 0.0096 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 129440.7157 * parameters.total_wait_locks 
	+ 0.5185 * parameters.mean_wait_of_all 
	- 165380.566 * parameters.cpu_usage 
	- 0.2083 * parameters.avg_work_of_same_past_second 
	+ 0.0908 * parameters.avg_wait_of_same_past_second 
	+ 0.1391 * parameters.avg_latency_of_same_last_20 
	- 0.0077 * parameters.max_latency_of_same_last_50 
	- 30136927.2711;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM60(work_wait &parameters) {
  double actual_remaining = 
	-3.1029 * parameters.work_so_far 
	- 0.0084 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 129440.7157 * parameters.total_wait_locks 
	+ 0.5185 * parameters.mean_wait_of_all 
	- 165380.566 * parameters.cpu_usage 
	- 0.2083 * parameters.avg_work_of_same_past_second 
	+ 0.0908 * parameters.avg_wait_of_same_past_second 
	+ 0.1299 * parameters.avg_latency_of_same_last_20 
	- 0.018 * parameters.max_latency_of_same_last_50 
	- 8295004.9873;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM61(work_wait &parameters) {
  double actual_remaining = 
	0.4919 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	+ 835997.4831 * parameters.total_wait_locks 
	+ 0.5185 * parameters.mean_wait_of_all 
	- 165380.566 * parameters.cpu_usage 
	- 0.2083 * parameters.avg_work_of_same_past_second 
	+ 0.1358 * parameters.avg_wait_of_same_past_second 
	+ 0.0362 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 215429046.9135;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM62(work_wait &parameters) {
  double actual_remaining = 
	3.0404 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	+ 891696.611 * parameters.total_wait_locks 
	- 2.8703 * parameters.mean_wait_of_all 
	- 165380.566 * parameters.cpu_usage 
	- 0.2083 * parameters.avg_work_of_same_past_second 
	+ 0.9437 * parameters.avg_wait_of_same_past_second 
	- 0.0746 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 63786556.6607;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM63(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	+ 0.0058 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 5589.0777 * parameters.total_wait_locks 
	+ 0.5152 * parameters.mean_wait_of_all 
	- 165380.566 * parameters.cpu_usage 
	- 0.7347 * parameters.avg_work_of_same_past_second 
	+ 0.0624 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	+ 0.0094 * parameters.max_latency_of_same_last_50 
	- 6994222.5296;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM64(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	+ 0.0267 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 5589.0777 * parameters.total_wait_locks 
	+ 0.5152 * parameters.mean_wait_of_all 
	- 165380.566 * parameters.cpu_usage 
	- 1.2488 * parameters.avg_work_of_same_past_second 
	+ 0.0624 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	+ 0.0115 * parameters.max_latency_of_same_last_50 
	+ 7928045.1856;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM65(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	+ 0.0205 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 5589.0777 * parameters.total_wait_locks 
	+ 0.5152 * parameters.mean_wait_of_all 
	- 165380.566 * parameters.cpu_usage 
	- 1.3542 * parameters.avg_work_of_same_past_second 
	+ 0.0624 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	+ 0.0115 * parameters.max_latency_of_same_last_50 
	+ 9117505.8994;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM66(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 6615.9322 * parameters.total_wait_locks 
	+ 0.0431 * parameters.mean_wait_of_all 
	- 165380.566 * parameters.cpu_usage 
	- 0.0332 * parameters.avg_work_of_same_past_second 
	- 0.0038 * parameters.avg_wait_of_same_past_second 
	- 0.0015 * parameters.avg_latency_of_same_last_20 
	+ 0.001 * parameters.max_latency_of_same_last_50 
	+ 18338621.1316;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM67(work_wait &parameters) {
  double actual_remaining = 
	1.242 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 32221.7597 * parameters.total_wait_locks 
	+ 0.137 * parameters.mean_wait_of_all 
	- 165380.566 * parameters.cpu_usage 
	- 0.0332 * parameters.avg_work_of_same_past_second 
	- 0.0038 * parameters.avg_wait_of_same_past_second 
	- 0.0024 * parameters.avg_latency_of_same_last_20 
	+ 0.0006 * parameters.max_latency_of_same_last_50 
	+ 17137109.4367;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM68(work_wait &parameters) {
  double actual_remaining = 
	0.8972 * parameters.work_so_far 
	+ 0.0049 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 29977.7556 * parameters.total_wait_locks 
	+ 0.137 * parameters.mean_wait_of_all 
	- 165380.566 * parameters.cpu_usage 
	- 0.0332 * parameters.avg_work_of_same_past_second 
	- 0.0038 * parameters.avg_wait_of_same_past_second 
	- 0.0038 * parameters.avg_latency_of_same_last_20 
	+ 0.0006 * parameters.max_latency_of_same_last_50 
	+ 19751710.8518;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM69(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0023 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 35484.1279 * parameters.total_wait_locks 
	+ 0.1973 * parameters.mean_wait_of_all 
	- 165380.566 * parameters.cpu_usage 
	- 0.0332 * parameters.avg_work_of_same_past_second 
	- 0.0038 * parameters.avg_wait_of_same_past_second 
	- 0.0538 * parameters.avg_latency_of_same_last_20 
	+ 0.0006 * parameters.max_latency_of_same_last_50 
	+ 57535705.2114;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM70(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0023 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 35484.1279 * parameters.total_wait_locks 
	+ 0.1973 * parameters.mean_wait_of_all 
	- 165380.566 * parameters.cpu_usage 
	- 0.0332 * parameters.avg_work_of_same_past_second 
	- 0.5469 * parameters.avg_wait_of_same_past_second 
	+ 0.1439 * parameters.avg_latency_of_same_last_20 
	+ 0.0006 * parameters.max_latency_of_same_last_50 
	+ 160979921.456;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM71(work_wait &parameters) {
  double actual_remaining = 
	48.8417 * parameters.work_so_far 
	- 0.0023 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 35484.1279 * parameters.total_wait_locks 
	+ 408.3267 * parameters.mean_wait_of_all 
	- 165380.566 * parameters.cpu_usage 
	- 0.0332 * parameters.avg_work_of_same_past_second 
	- 0.5469 * parameters.avg_wait_of_same_past_second 
	+ 0.1033 * parameters.avg_latency_of_same_last_20 
	+ 0.0006 * parameters.max_latency_of_same_last_50 
	- 53253355919.9276;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM72(work_wait &parameters) {
  double actual_remaining = 
	51.9611 * parameters.work_so_far 
	- 0.0023 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 35484.1279 * parameters.total_wait_locks 
	+ 365.3657 * parameters.mean_wait_of_all 
	- 165380.566 * parameters.cpu_usage 
	- 0.0332 * parameters.avg_work_of_same_past_second 
	- 0.5469 * parameters.avg_wait_of_same_past_second 
	+ 0.1033 * parameters.avg_latency_of_same_last_20 
	+ 0.0006 * parameters.max_latency_of_same_last_50 
	- 47628336602.879;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM73(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0023 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	+ 36625.1623 * parameters.total_wait_locks 
	+ 0.1973 * parameters.mean_wait_of_all 
	- 165380.566 * parameters.cpu_usage 
	- 0.0332 * parameters.avg_work_of_same_past_second 
	- 0.6439 * parameters.avg_wait_of_same_past_second 
	- 0.0386 * parameters.avg_latency_of_same_last_20 
	+ 0.0006 * parameters.max_latency_of_same_last_50 
	+ 230696957.763;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM74(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0023 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 52599.2172 * parameters.total_wait_locks 
	+ 0.1973 * parameters.mean_wait_of_all 
	- 165380.566 * parameters.cpu_usage 
	- 0.0332 * parameters.avg_work_of_same_past_second 
	- 0.6439 * parameters.avg_wait_of_same_past_second 
	- 0.0386 * parameters.avg_latency_of_same_last_20 
	+ 0.0006 * parameters.max_latency_of_same_last_50 
	+ 260455693.7198;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM75(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0044 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 20392.7846 * parameters.total_wait_locks 
	+ 0.1084 * parameters.mean_wait_of_all 
	- 165380.566 * parameters.cpu_usage 
	- 0.0332 * parameters.avg_work_of_same_past_second 
	- 0.0038 * parameters.avg_wait_of_same_past_second 
	+ 0.016 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	+ 17793688.0666;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM76(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0057 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	+ 122699.2637 * parameters.total_wait_locks 
	+ 0.1084 * parameters.mean_wait_of_all 
	- 165380.566 * parameters.cpu_usage 
	+ 9.0086 * parameters.avg_work_of_same_past_second 
	- 0.4274 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	- 92276052.5807;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM77(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0132 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 20392.7846 * parameters.total_wait_locks 
	+ 0.1084 * parameters.mean_wait_of_all 
	- 165380.566 * parameters.cpu_usage 
	+ 0.1195 * parameters.avg_work_of_same_past_second 
	- 0.1654 * parameters.avg_wait_of_same_past_second 
	+ 0.0011 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	+ 75437007.5883;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM78(work_wait &parameters) {
  double actual_remaining = 
	0.0007 * parameters.work_so_far 
	- 0.0033 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 22952.5991 * parameters.total_wait_locks 
	+ 0.1084 * parameters.mean_wait_of_all 
	- 165380.566 * parameters.cpu_usage 
	- 0.0332 * parameters.avg_work_of_same_past_second 
	- 0.0038 * parameters.avg_wait_of_same_past_second 
	- 0.0074 * parameters.avg_latency_of_same_last_20 
	- 0.0026 * parameters.max_latency_of_same_last_50 
	+ 26862901.671;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM79(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	- 0.0047 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 223365.0012 * parameters.total_wait_locks 
	+ 0.6864 * parameters.mean_wait_of_all 
	+ 68325633.921 * parameters.cpu_usage 
	- 0.0017 * parameters.avg_work_of_same_past_second 
	- 0.029 * parameters.avg_wait_of_same_past_second 
	+ 0.0135 * parameters.avg_latency_of_same_last_20 
	+ 0.0001 * parameters.max_latency_of_same_last_50 
	- 13279746.0881;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM80(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	- 0.0374 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 1590983.6354 * parameters.total_wait_locks 
	+ 13.7186 * parameters.mean_wait_of_all 
	- 893365.4736 * parameters.cpu_usage 
	- 0.0361 * parameters.avg_work_of_same_past_second 
	- 0.3589 * parameters.avg_wait_of_same_past_second 
	+ 0.005 * parameters.avg_latency_of_same_last_20 
	+ 0.0008 * parameters.max_latency_of_same_last_50 
	- 561298335.3677;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM81(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	- 0.0021 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 35454.1373 * parameters.total_wait_locks 
	+ 0.3642 * parameters.mean_wait_of_all 
	- 893365.4736 * parameters.cpu_usage 
	- 0.1254 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0507 * parameters.avg_latency_of_same_last_20 
	+ 0.0008 * parameters.max_latency_of_same_last_50 
	- 11761294.6372;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM82(work_wait &parameters) {
  double actual_remaining = 
	0.0078 * parameters.work_so_far 
	- 0.0006 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 224121.2294 * parameters.total_wait_locks 
	+ 1.8985 * parameters.mean_wait_of_all 
	- 893365.4736 * parameters.cpu_usage 
	- 0.078 * parameters.avg_work_of_same_past_second 
	- 0.0022 * parameters.avg_wait_of_same_past_second 
	+ 0.004 * parameters.avg_latency_of_same_last_20 
	+ 0.0008 * parameters.max_latency_of_same_last_50 
	- 94946702.4833;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM83(work_wait &parameters) {
  double actual_remaining = 
	0.0239 * parameters.work_so_far 
	+ 0.0015 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 72263.171 * parameters.total_wait_locks 
	+ 0.8194 * parameters.mean_wait_of_all 
	- 893365.4736 * parameters.cpu_usage 
	+ 22.6428 * parameters.avg_work_of_same_past_second 
	- 0.007 * parameters.avg_wait_of_same_past_second 
	+ 0.1493 * parameters.avg_latency_of_same_last_20 
	+ 0.0008 * parameters.max_latency_of_same_last_50 
	- 612589945.5043;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM84(work_wait &parameters) {
  double actual_remaining = 
	0.0239 * parameters.work_so_far 
	+ 0.0116 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 72263.171 * parameters.total_wait_locks 
	+ 0.8194 * parameters.mean_wait_of_all 
	- 893365.4736 * parameters.cpu_usage 
	- 0.9234 * parameters.avg_work_of_same_past_second 
	- 0.007 * parameters.avg_wait_of_same_past_second 
	+ 0.0216 * parameters.avg_latency_of_same_last_20 
	+ 0.0008 * parameters.max_latency_of_same_last_50 
	- 25707692.3322;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM85(work_wait &parameters) {
  double actual_remaining = 
	-3.6091 * parameters.work_so_far 
	- 0.0005 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 1675242.9501 * parameters.total_wait_locks 
	+ 77710.8227 * parameters.mean_wait_of_all 
	- 126981897.8559 * parameters.cpu_usage 
	- 3.1547 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.1302 * parameters.avg_latency_of_same_last_20 
	- 0.0271 * parameters.max_latency_of_same_last_50 
	- 7917222903968.352;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM86(work_wait &parameters) {
  double actual_remaining = 
	-1.7373 * parameters.work_so_far 
	- 0.0071 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 777412.1498 * parameters.total_wait_locks 
	+ 1.3679 * parameters.mean_wait_of_all 
	- 194242614.2715 * parameters.cpu_usage 
	- 1.6131 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.0632 * parameters.avg_latency_of_same_last_20 
	+ 0.0108 * parameters.max_latency_of_same_last_50 
	+ 468115398.0863;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM87(work_wait &parameters) {
  double actual_remaining = 
	-1.7373 * parameters.work_so_far 
	- 0.0065 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 777412.1498 * parameters.total_wait_locks 
	+ 1.3679 * parameters.mean_wait_of_all 
	- 126981897.8559 * parameters.cpu_usage 
	- 1.6131 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.0632 * parameters.avg_latency_of_same_last_20 
	+ 0.0108 * parameters.max_latency_of_same_last_50 
	+ 401856364.0985;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM88(work_wait &parameters) {
  double actual_remaining = 
	-0.74 * parameters.work_so_far 
	- 0.0005 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 643532.3357 * parameters.total_wait_locks 
	+ 1.3679 * parameters.mean_wait_of_all 
	- 126981897.8559 * parameters.cpu_usage 
	+ 1.2252 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.0632 * parameters.avg_latency_of_same_last_20 
	+ 0.0046 * parameters.max_latency_of_same_last_50 
	+ 301447668.5513;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM89(work_wait &parameters) {
  double actual_remaining = 
	-1.7373 * parameters.work_so_far 
	- 0.0005 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 777412.1498 * parameters.total_wait_locks 
	+ 3.9655 * parameters.mean_wait_of_all 
	- 126981897.8559 * parameters.cpu_usage 
	- 1.6131 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.0632 * parameters.avg_latency_of_same_last_20 
	+ 0.0046 * parameters.max_latency_of_same_last_50 
	+ 150557313.0224;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM90(work_wait &parameters) {
  double actual_remaining = 
	-1.7373 * parameters.work_so_far 
	- 0.0005 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 777412.1498 * parameters.total_wait_locks 
	+ 4.4239 * parameters.mean_wait_of_all 
	- 126981897.8559 * parameters.cpu_usage 
	- 1.6131 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.0632 * parameters.avg_latency_of_same_last_20 
	+ 0.0046 * parameters.max_latency_of_same_last_50 
	+ 105479006.0542;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM91(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	- 0.0045 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 260874.988 * parameters.total_wait_locks 
	+ 1.2838 * parameters.mean_wait_of_all 
	- 193935922.764 * parameters.cpu_usage 
	- 1.3404 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.0319 * parameters.avg_latency_of_same_last_20 
	+ 0.0121 * parameters.max_latency_of_same_last_50 
	+ 208884577.9158;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM92(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	- 0.0045 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 260874.988 * parameters.total_wait_locks 
	+ 1.2838 * parameters.mean_wait_of_all 
	- 193935922.764 * parameters.cpu_usage 
	- 0.5709 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.0319 * parameters.avg_latency_of_same_last_20 
	+ 0.0121 * parameters.max_latency_of_same_last_50 
	+ 190189559.5513;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM93(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	- 0.0045 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 260874.988 * parameters.total_wait_locks 
	+ 1.2838 * parameters.mean_wait_of_all 
	- 193935922.764 * parameters.cpu_usage 
	+ 2.7502 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	- 0.2031 * parameters.avg_latency_of_same_last_20 
	+ 0.0121 * parameters.max_latency_of_same_last_50 
	+ 185270371.7166;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM94(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	- 0.0045 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 214560.9616 * parameters.total_wait_locks 
	+ 1.2838 * parameters.mean_wait_of_all 
	- 193935922.764 * parameters.cpu_usage 
	+ 0.1714 * parameters.avg_work_of_same_past_second 
	+ 0.0053 * parameters.avg_wait_of_same_past_second 
	+ 0.0125 * parameters.avg_latency_of_same_last_20 
	+ 0.0097 * parameters.max_latency_of_same_last_50 
	+ 133595660.8118;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM95(work_wait &parameters) {
  double actual_remaining = 
	-0.1766 * parameters.work_so_far 
	- 0.0001 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 208771.7083 * parameters.total_wait_locks 
	+ 1.2838 * parameters.mean_wait_of_all 
	- 193935922.764 * parameters.cpu_usage 
	+ 0.1714 * parameters.avg_work_of_same_past_second 
	+ 0.0232 * parameters.avg_wait_of_same_past_second 
	+ 0.0125 * parameters.avg_latency_of_same_last_20 
	+ 0.0095 * parameters.max_latency_of_same_last_50 
	+ 125184369.0261;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM96(work_wait &parameters) {
  double actual_remaining = 
	-0.1605 * parameters.work_so_far 
	- 0.0005 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 208771.7083 * parameters.total_wait_locks 
	+ 1.2838 * parameters.mean_wait_of_all 
	- 193935922.764 * parameters.cpu_usage 
	+ 0.1714 * parameters.avg_work_of_same_past_second 
	+ 0.0217 * parameters.avg_wait_of_same_past_second 
	+ 0.0125 * parameters.avg_latency_of_same_last_20 
	+ 0.0095 * parameters.max_latency_of_same_last_50 
	+ 130422814.5075;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM97(work_wait &parameters) {
  double actual_remaining = 
	0.4375 * parameters.work_so_far 
	- 0.0146 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 492985.8408 * parameters.total_wait_locks 
	+ 3.0699 * parameters.mean_wait_of_all 
	+ 187155122.649 * parameters.cpu_usage 
	+ 8.1505 * parameters.avg_work_of_same_past_second 
	+ 0.0276 * parameters.avg_wait_of_same_past_second 
	+ 0.0145 * parameters.avg_latency_of_same_last_20 
	+ 0.0132 * parameters.max_latency_of_same_last_50 
	- 485028778.1971;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM98(work_wait &parameters) {
  double actual_remaining = 
	0.4375 * parameters.work_so_far 
	- 0.0146 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 492985.8408 * parameters.total_wait_locks 
	+ 3.0699 * parameters.mean_wait_of_all 
	+ 173010654.4093 * parameters.cpu_usage 
	- 0.5629 * parameters.avg_work_of_same_past_second 
	+ 0.0276 * parameters.avg_wait_of_same_past_second 
	+ 0.0994 * parameters.avg_latency_of_same_last_20 
	+ 0.0132 * parameters.max_latency_of_same_last_50 
	- 304515744.6943;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM99(work_wait &parameters) {
  double actual_remaining = 
	0.4375 * parameters.work_so_far 
	- 0.0146 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 492985.8408 * parameters.total_wait_locks 
	+ 3.0699 * parameters.mean_wait_of_all 
	+ 201341820.533 * parameters.cpu_usage 
	- 1.3375 * parameters.avg_work_of_same_past_second 
	+ 0.0276 * parameters.avg_wait_of_same_past_second 
	+ 0.1178 * parameters.avg_latency_of_same_last_20 
	+ 0.0132 * parameters.max_latency_of_same_last_50 
	- 315906435.938;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM100(work_wait &parameters) {
  double actual_remaining = 
	0.4375 * parameters.work_so_far 
	- 0.0146 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 492985.8408 * parameters.total_wait_locks 
	+ 3.0699 * parameters.mean_wait_of_all 
	+ 201341820.533 * parameters.cpu_usage 
	- 1.5198 * parameters.avg_work_of_same_past_second 
	+ 0.0276 * parameters.avg_wait_of_same_past_second 
	+ 0.1178 * parameters.avg_latency_of_same_last_20 
	+ 0.0132 * parameters.max_latency_of_same_last_50 
	- 312231123.3;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM101(work_wait &parameters) {
  double actual_remaining = 
	0.4375 * parameters.work_so_far 
	- 0.0146 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 492985.8408 * parameters.total_wait_locks 
	+ 3.0699 * parameters.mean_wait_of_all 
	- 241118138.3569 * parameters.cpu_usage 
	- 0.5844 * parameters.avg_work_of_same_past_second 
	+ 0.0276 * parameters.avg_wait_of_same_past_second 
	+ 0.0145 * parameters.avg_latency_of_same_last_20 
	+ 0.0132 * parameters.max_latency_of_same_last_50 
	+ 125245432.9516;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM102(work_wait &parameters) {
  double actual_remaining = 
	0.4375 * parameters.work_so_far 
	- 0.0214 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 492985.8408 * parameters.total_wait_locks 
	+ 3.0699 * parameters.mean_wait_of_all 
	- 241118138.3569 * parameters.cpu_usage 
	- 0.5844 * parameters.avg_work_of_same_past_second 
	+ 0.0276 * parameters.avg_wait_of_same_past_second 
	+ 0.0145 * parameters.avg_latency_of_same_last_20 
	+ 0.0132 * parameters.max_latency_of_same_last_50 
	+ 132323269.5784;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM103(work_wait &parameters) {
  double actual_remaining = 
	0.4375 * parameters.work_so_far 
	- 0.0202 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 492985.8408 * parameters.total_wait_locks 
	+ 3.0699 * parameters.mean_wait_of_all 
	- 241118138.3569 * parameters.cpu_usage 
	- 0.5844 * parameters.avg_work_of_same_past_second 
	+ 0.0276 * parameters.avg_wait_of_same_past_second 
	+ 0.0145 * parameters.avg_latency_of_same_last_20 
	+ 0.0132 * parameters.max_latency_of_same_last_50 
	+ 130109495.4862;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM104(work_wait &parameters) {
  double actual_remaining = 
	0.7523 * parameters.work_so_far 
	- 0.0365 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 649481.5502 * parameters.total_wait_locks 
	+ 4.2909 * parameters.mean_wait_of_all 
	- 1882102834.8109 * parameters.cpu_usage 
	+ 0.3822 * parameters.avg_work_of_same_past_second 
	- 0.9964 * parameters.avg_wait_of_same_past_second 
	- 0.2268 * parameters.avg_latency_of_same_last_20 
	+ 0.0132 * parameters.max_latency_of_same_last_50 
	+ 2390719448.4545;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM105(work_wait &parameters) {
  double actual_remaining = 
	-17.8608 * parameters.work_so_far 
	- 0.0443 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 649481.5502 * parameters.total_wait_locks 
	+ 4.2909 * parameters.mean_wait_of_all 
	- 1225594299.9091 * parameters.cpu_usage 
	+ 0.3822 * parameters.avg_work_of_same_past_second 
	- 1.5412 * parameters.avg_wait_of_same_past_second 
	- 0.6305 * parameters.avg_latency_of_same_last_20 
	+ 0.0132 * parameters.max_latency_of_same_last_50 
	+ 2254416767.4266;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM106(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	- 0.0005 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 361461.7004 * parameters.total_wait_locks 
	+ 2.0092 * parameters.mean_wait_of_all 
	+ 231148395.8358 * parameters.cpu_usage 
	- 1.1675 * parameters.avg_work_of_same_past_second 
	- 0.0054 * parameters.avg_wait_of_same_past_second 
	+ 0.0542 * parameters.avg_latency_of_same_last_20 
	+ 0.0167 * parameters.max_latency_of_same_last_50 
	- 282101209.1622;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM107(work_wait &parameters) {
  double actual_remaining = 
	1.5807 * parameters.work_so_far 
	- 0.0005 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	+ 30485.4671 * parameters.total_wait_locks 
	- 0.3112 * parameters.mean_wait_of_all 
	- 893365.4736 * parameters.cpu_usage 
	- 1.784 * parameters.avg_work_of_same_past_second 
	+ 0.0284 * parameters.avg_wait_of_same_past_second 
	+ 0.0316 * parameters.avg_latency_of_same_last_20 
	+ 0.0166 * parameters.max_latency_of_same_last_50 
	+ 56472166.7772;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM108(work_wait &parameters) {
  double actual_remaining = 
	1.0451 * parameters.work_so_far 
	- 0.0005 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	+ 30485.4671 * parameters.total_wait_locks 
	- 0.3112 * parameters.mean_wait_of_all 
	- 893365.4736 * parameters.cpu_usage 
	- 1.1565 * parameters.avg_work_of_same_past_second 
	+ 0.0284 * parameters.avg_wait_of_same_past_second 
	+ 0.0316 * parameters.avg_latency_of_same_last_20 
	+ 0.0166 * parameters.max_latency_of_same_last_50 
	+ 26324867.3778;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM109(work_wait &parameters) {
  double actual_remaining = 
	1.2983 * parameters.work_so_far 
	- 0.0005 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	+ 123610.2063 * parameters.total_wait_locks 
	- 0.9804 * parameters.mean_wait_of_all 
	- 893365.4736 * parameters.cpu_usage 
	- 0.6724 * parameters.avg_work_of_same_past_second 
	+ 0.0284 * parameters.avg_wait_of_same_past_second 
	+ 0.0316 * parameters.avg_latency_of_same_last_20 
	+ 0.0321 * parameters.max_latency_of_same_last_50 
	+ 57365897.9762;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM110(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	- 0.0005 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 57737.9702 * parameters.total_wait_locks 
	+ 0.3228 * parameters.mean_wait_of_all 
	- 893365.4736 * parameters.cpu_usage 
	- 0.9987 * parameters.avg_work_of_same_past_second 
	+ 0.0567 * parameters.avg_wait_of_same_past_second 
	+ 0.0448 * parameters.avg_latency_of_same_last_20 
	- 0.0116 * parameters.max_latency_of_same_last_50 
	+ 14536605.4955;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM111(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	- 0.0147 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 325375.1576 * parameters.total_wait_locks 
	+ 2.3702 * parameters.mean_wait_of_all 
	+ 406820830.6371 * parameters.cpu_usage 
	- 0.1829 * parameters.avg_work_of_same_past_second 
	- 0.0144 * parameters.avg_wait_of_same_past_second 
	+ 0.012 * parameters.avg_latency_of_same_last_20 
	+ 0.0018 * parameters.max_latency_of_same_last_50 
	- 469835560.4101;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM112(work_wait &parameters) {
  double actual_remaining = 
	0.005 * parameters.work_so_far 
	- 0.0071 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 193145.5136 * parameters.total_wait_locks 
	+ 2.1329 * parameters.mean_wait_of_all 
	- 4149497.3784 * parameters.cpu_usage 
	- 0.7241 * parameters.avg_work_of_same_past_second 
	+ 0.0369 * parameters.avg_wait_of_same_past_second 
	+ 0.0005 * parameters.avg_latency_of_same_last_20 
	+ 0.0042 * parameters.max_latency_of_same_last_50 
	- 134103716.4303;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM113(work_wait &parameters) {
  double actual_remaining = 
	0.005 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 86083.6592 * parameters.total_wait_locks 
	+ 1.9983 * parameters.mean_wait_of_all 
	- 4149497.3784 * parameters.cpu_usage 
	- 4.3411 * parameters.avg_work_of_same_past_second 
	- 0.0258 * parameters.avg_wait_of_same_past_second 
	+ 0.0031 * parameters.avg_latency_of_same_last_20 
	+ 0.0069 * parameters.max_latency_of_same_last_50 
	- 67721445.3994;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM114(work_wait &parameters) {
  double actual_remaining = 
	0.005 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 86083.6592 * parameters.total_wait_locks 
	+ 1.9983 * parameters.mean_wait_of_all 
	- 4149497.3784 * parameters.cpu_usage 
	- 2.4611 * parameters.avg_work_of_same_past_second 
	- 0.0258 * parameters.avg_wait_of_same_past_second 
	+ 0.0031 * parameters.avg_latency_of_same_last_20 
	+ 0.0069 * parameters.max_latency_of_same_last_50 
	- 123400020.1218;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM115(work_wait &parameters) {
  double actual_remaining = 
	0.005 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	+ 72335.0659 * parameters.total_wait_locks 
	+ 3.5497 * parameters.mean_wait_of_all 
	- 4149497.3784 * parameters.cpu_usage 
	- 1.7231 * parameters.avg_work_of_same_past_second 
	- 1.1146 * parameters.avg_wait_of_same_past_second 
	+ 0.0171 * parameters.avg_latency_of_same_last_20 
	+ 0.0032 * parameters.max_latency_of_same_last_50 
	- 17169241.4316;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM116(work_wait &parameters) {
  double actual_remaining = 
	0.005 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	+ 110552.0566 * parameters.total_wait_locks 
	+ 2.8884 * parameters.mean_wait_of_all 
	- 4149497.3784 * parameters.cpu_usage 
	- 1.7231 * parameters.avg_work_of_same_past_second 
	- 1.1146 * parameters.avg_wait_of_same_past_second 
	+ 0.0171 * parameters.avg_latency_of_same_last_20 
	+ 0.0032 * parameters.max_latency_of_same_last_50 
	+ 48097101.7484;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM117(work_wait &parameters) {
  double actual_remaining = 
	0.005 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 86083.6592 * parameters.total_wait_locks 
	+ 2.8884 * parameters.mean_wait_of_all 
	- 4149497.3784 * parameters.cpu_usage 
	- 1.7231 * parameters.avg_work_of_same_past_second 
	- 1.1033 * parameters.avg_wait_of_same_past_second 
	+ 0.0171 * parameters.avg_latency_of_same_last_20 
	+ 0.0032 * parameters.max_latency_of_same_last_50 
	+ 169229854.0922;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM118(work_wait &parameters) {
  double actual_remaining = 
	-379.3313 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 86083.6592 * parameters.total_wait_locks 
	+ 2.8884 * parameters.mean_wait_of_all 
	- 4149497.3784 * parameters.cpu_usage 
	- 1.7231 * parameters.avg_work_of_same_past_second 
	- 1.1033 * parameters.avg_wait_of_same_past_second 
	+ 0.0171 * parameters.avg_latency_of_same_last_20 
	+ 0.0032 * parameters.max_latency_of_same_last_50 
	+ 183227544.0766;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM119(work_wait &parameters) {
  double actual_remaining = 
	0.005 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 86083.6592 * parameters.total_wait_locks 
	+ 2.8884 * parameters.mean_wait_of_all 
	- 4149497.3784 * parameters.cpu_usage 
	- 1.7231 * parameters.avg_work_of_same_past_second 
	- 1.0909 * parameters.avg_wait_of_same_past_second 
	+ 0.0171 * parameters.avg_latency_of_same_last_20 
	+ 0.0032 * parameters.max_latency_of_same_last_50 
	+ 162714160.9047;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM120(work_wait &parameters) {
  double actual_remaining = 
	0.005 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	+ 133622.4593 * parameters.total_wait_locks 
	+ 2.8884 * parameters.mean_wait_of_all 
	- 4149497.3784 * parameters.cpu_usage 
	- 8.8496 * parameters.avg_work_of_same_past_second 
	- 0.9077 * parameters.avg_wait_of_same_past_second 
	+ 0.0171 * parameters.avg_latency_of_same_last_20 
	+ 0.0032 * parameters.max_latency_of_same_last_50 
	+ 157248535.8681;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM121(work_wait &parameters) {
  double actual_remaining = 
	0.005 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	+ 46459.5165 * parameters.total_wait_locks 
	+ 2.8884 * parameters.mean_wait_of_all 
	- 4149497.3784 * parameters.cpu_usage 
	- 9.189 * parameters.avg_work_of_same_past_second 
	- 0.9077 * parameters.avg_wait_of_same_past_second 
	+ 0.0171 * parameters.avg_latency_of_same_last_20 
	+ 0.0032 * parameters.max_latency_of_same_last_50 
	+ 224200855.1549;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM122(work_wait &parameters) {
  double actual_remaining = 
	0.005 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	+ 108626.7838 * parameters.total_wait_locks 
	+ 2.8884 * parameters.mean_wait_of_all 
	- 4149497.3784 * parameters.cpu_usage 
	- 2.8228 * parameters.avg_work_of_same_past_second 
	- 1.0352 * parameters.avg_wait_of_same_past_second 
	+ 0.0171 * parameters.avg_latency_of_same_last_20 
	+ 0.0032 * parameters.max_latency_of_same_last_50 
	+ 58457002.6468;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM123(work_wait &parameters) {
  double actual_remaining = 
	0.005 * parameters.work_so_far 
	- 0.0007 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 86083.6592 * parameters.total_wait_locks 
	+ 4.733 * parameters.mean_wait_of_all 
	- 4149497.3784 * parameters.cpu_usage 
	- 1.6158 * parameters.avg_work_of_same_past_second 
	- 0.579 * parameters.avg_wait_of_same_past_second 
	+ 0.0314 * parameters.avg_latency_of_same_last_20 
	+ 0.0032 * parameters.max_latency_of_same_last_50 
	- 300059187.3842;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM124(work_wait &parameters) {
  double actual_remaining = 
	0.0765 * parameters.work_so_far 
	- 0.0029 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 123369.8767 * parameters.total_wait_locks 
	+ 0.311 * parameters.mean_wait_of_all 
	- 4149497.3784 * parameters.cpu_usage 
	- 0.6631 * parameters.avg_work_of_same_past_second 
	- 0.0189 * parameters.avg_wait_of_same_past_second 
	+ 0.0086 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	+ 84097203.4174;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM125(work_wait &parameters) {
  double actual_remaining = 
	0.0795 * parameters.work_so_far 
	- 0.0191 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 125649.6524 * parameters.total_wait_locks 
	+ 0.311 * parameters.mean_wait_of_all 
	- 4149497.3784 * parameters.cpu_usage 
	- 0.2416 * parameters.avg_work_of_same_past_second 
	+ 0.3538 * parameters.avg_wait_of_same_past_second 
	+ 0.0089 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	- 61136459.1216;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM126(work_wait &parameters) {
  double actual_remaining = 
	0.005 * parameters.work_so_far 
	- 0.0075 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 23375.1939 * parameters.total_wait_locks 
	+ 2.7497 * parameters.mean_wait_of_all 
	- 4149497.3784 * parameters.cpu_usage 
	- 0.9135 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0005 * parameters.avg_latency_of_same_last_20 
	+ 0.0002 * parameters.max_latency_of_same_last_50 
	- 319654338.3193;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM127(work_wait &parameters) {
  double actual_remaining = 
	1.0392 * parameters.work_so_far 
	- 0.0004 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 226227.783 * parameters.total_wait_locks 
	+ 1.1684 * parameters.mean_wait_of_all 
	- 9328294.881 * parameters.cpu_usage 
	- 0.0178 * parameters.avg_work_of_same_past_second 
	- 0.0002 * parameters.avg_wait_of_same_past_second 
	+ 0.0295 * parameters.avg_latency_of_same_last_20 
	- 0.0082 * parameters.max_latency_of_same_last_50 
	+ 22029131.2678;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM128(work_wait &parameters) {
  double actual_remaining = 
	0.0011 * parameters.work_so_far 
	- 0.0042 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	+ 13634.0125 * parameters.total_wait_locks 
	- 0.0436 * parameters.mean_wait_of_all 
	- 18833355.1017 * parameters.cpu_usage 
	- 0.0013 * parameters.avg_work_of_same_past_second 
	- 0.0006 * parameters.avg_wait_of_same_past_second 
	+ 0.0023 * parameters.avg_latency_of_same_last_20 
	+ 0.0068 * parameters.max_latency_of_same_last_50 
	+ 26081765.8345;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM129(work_wait &parameters) {
  double actual_remaining = 
	0.0011 * parameters.work_so_far 
	- 0.0133 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	+ 7838.9426 * parameters.total_wait_locks 
	- 0.0186 * parameters.mean_wait_of_all 
	- 18833355.1017 * parameters.cpu_usage 
	- 0.0013 * parameters.avg_work_of_same_past_second 
	- 0.1521 * parameters.avg_wait_of_same_past_second 
	+ 0.0023 * parameters.avg_latency_of_same_last_20 
	+ 0.0058 * parameters.max_latency_of_same_last_50 
	+ 97217018.4941;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM130(work_wait &parameters) {
  double actual_remaining = 
	0.7003 * parameters.work_so_far 
	- 0.0268 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 106525.2669 * parameters.total_wait_locks 
	+ 0.6573 * parameters.mean_wait_of_all 
	- 13520097.67 * parameters.cpu_usage 
	- 0.0013 * parameters.avg_work_of_same_past_second 
	- 0.3399 * parameters.avg_wait_of_same_past_second 
	+ 0.0023 * parameters.avg_latency_of_same_last_20 
	+ 0.0121 * parameters.max_latency_of_same_last_50 
	+ 137945604.0259;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM131(work_wait &parameters) {
  double actual_remaining = 
	-3.7037 * parameters.work_so_far 
	- 0.029 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 89513.9791 * parameters.total_wait_locks 
	+ 0.6666 * parameters.mean_wait_of_all 
	- 13520097.67 * parameters.cpu_usage 
	- 0.0013 * parameters.avg_work_of_same_past_second 
	- 0.153 * parameters.avg_wait_of_same_past_second 
	+ 0.0023 * parameters.avg_latency_of_same_last_20 
	+ 0.0233 * parameters.max_latency_of_same_last_50 
	+ 65234228.7574;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM132(work_wait &parameters) {
  double actual_remaining = 
	-4.3819 * parameters.work_so_far 
	- 0.0271 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 89513.9791 * parameters.total_wait_locks 
	+ 0.6666 * parameters.mean_wait_of_all 
	- 13520097.67 * parameters.cpu_usage 
	- 0.0013 * parameters.avg_work_of_same_past_second 
	- 0.153 * parameters.avg_wait_of_same_past_second 
	+ 0.0023 * parameters.avg_latency_of_same_last_20 
	+ 0.0233 * parameters.max_latency_of_same_last_50 
	+ 60522036.3251;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM133(work_wait &parameters) {
  double actual_remaining = 
	0.0011 * parameters.work_so_far 
	- 0.0025 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 64147.6423 * parameters.total_wait_locks 
	+ 0.1519 * parameters.mean_wait_of_all 
	- 13520097.67 * parameters.cpu_usage 
	- 0.0013 * parameters.avg_work_of_same_past_second 
	- 0.0053 * parameters.avg_wait_of_same_past_second 
	+ 0.0379 * parameters.avg_latency_of_same_last_20 
	+ 0.0029 * parameters.max_latency_of_same_last_50 
	+ 40117920.7159;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM134(work_wait &parameters) {
  double actual_remaining = 
	0.0011 * parameters.work_so_far 
	- 0.0015 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 4512.0732 * parameters.total_wait_locks 
	+ 0.0387 * parameters.mean_wait_of_all 
	- 11339319.6637 * parameters.cpu_usage 
	- 0.0646 * parameters.avg_work_of_same_past_second 
	- 0.0006 * parameters.avg_wait_of_same_past_second 
	+ 0.0435 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 16728977.7902;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM135(work_wait &parameters) {
  double actual_remaining = 
	0.0011 * parameters.work_so_far 
	- 0.0018 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 3748.8897 * parameters.total_wait_locks 
	+ 0.0387 * parameters.mean_wait_of_all 
	- 11339319.6637 * parameters.cpu_usage 
	- 0.0895 * parameters.avg_work_of_same_past_second 
	- 0.0006 * parameters.avg_wait_of_same_past_second 
	+ 0.0105 * parameters.avg_latency_of_same_last_20 
	- 0.0003 * parameters.max_latency_of_same_last_50 
	+ 21325970.7365;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM136(work_wait &parameters) {
  double actual_remaining = 
	0.0011 * parameters.work_so_far 
	- 0.0093 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 601004.6617 * parameters.total_wait_locks 
	+ 1.593 * parameters.mean_wait_of_all 
	+ 118752250.9431 * parameters.cpu_usage 
	+ 0.6311 * parameters.avg_work_of_same_past_second 
	- 0.0029 * parameters.avg_wait_of_same_past_second 
	+ 0.0014 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 35480525.0269;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM137(work_wait &parameters) {
  double actual_remaining = 
	0.0011 * parameters.work_so_far 
	- 0.0017 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	+ 254.7948 * parameters.total_wait_locks 
	- 0.0623 * parameters.mean_wait_of_all 
	+ 35313942.6851 * parameters.cpu_usage 
	+ 0.0135 * parameters.avg_work_of_same_past_second 
	- 0.0076 * parameters.avg_wait_of_same_past_second 
	+ 0.0014 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 12762999.2755;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM138(work_wait &parameters) {
  double actual_remaining = 
	0.0133 * parameters.work_so_far 
	+ 0.012 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 27221.5168 * parameters.total_wait_locks 
	+ 0.2301 * parameters.mean_wait_of_all 
	- 459031.8185 * parameters.cpu_usage 
	+ 0.0038 * parameters.avg_work_of_same_past_second 
	+ 0.2005 * parameters.avg_wait_of_same_past_second 
	- 0.0465 * parameters.avg_latency_of_same_last_20 
	+ 0.0072 * parameters.max_latency_of_same_last_50 
	- 66434167.9129;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM139(work_wait &parameters) {
  double actual_remaining = 
	0.0133 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 340226.4698 * parameters.total_wait_locks 
	+ 3.1108 * parameters.mean_wait_of_all 
	- 419275026.992 * parameters.cpu_usage 
	+ 0.0038 * parameters.avg_work_of_same_past_second 
	- 0.3585 * parameters.avg_wait_of_same_past_second 
	+ 0.0021 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 379276172.4049;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM140(work_wait &parameters) {
  double actual_remaining = 
	0.0877 * parameters.work_so_far 
	- 0.0003 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 47219.6651 * parameters.total_wait_locks 
	+ 0.3537 * parameters.mean_wait_of_all 
	- 1297884222.5307 * parameters.cpu_usage 
	+ 1.9891 * parameters.avg_work_of_same_past_second 
	- 0.1767 * parameters.avg_wait_of_same_past_second 
	+ 0.0037 * parameters.avg_latency_of_same_last_20 
	+ 0.0241 * parameters.max_latency_of_same_last_50 
	+ 1212589990.1991;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM141(work_wait &parameters) {
  double actual_remaining = 
	0.6075 * parameters.work_so_far 
	- 0.0415 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 66873.4266 * parameters.total_wait_locks 
	+ 0.4863 * parameters.mean_wait_of_all 
	- 459031.8185 * parameters.cpu_usage 
	- 6.3846 * parameters.avg_work_of_same_past_second 
	+ 0.0593 * parameters.avg_wait_of_same_past_second 
	+ 0.0037 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	+ 238016669.2943;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM142(work_wait &parameters) {
  double actual_remaining = 
	0.0011 * parameters.work_so_far 
	- 0.0045 * parameters.wait_so_far 
	- 868.7139 * parameters.num_locks_so_far 
	- 207457.9526 * parameters.total_wait_locks 
	+ 1.8904 * parameters.mean_wait_of_all 
	+ 107271812.3587 * parameters.cpu_usage 
	- 0.8365 * parameters.avg_work_of_same_past_second 
	+ 0.0584 * parameters.avg_wait_of_same_past_second 
	+ 0.0012 * parameters.avg_latency_of_same_last_20 
	+ 0 * parameters.max_latency_of_same_last_50 
	- 196352849.4469;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM143(work_wait &parameters) {
  double actual_remaining = 
	0.0013 * parameters.work_so_far 
	- 0.0185 * parameters.wait_so_far 
	- 2205902.9332 * parameters.num_locks_so_far 
	+ 162433.1354 * parameters.total_wait_locks 
	- 0.0046 * parameters.mean_wait_of_all 
	- 231047.5926 * parameters.cpu_usage 
	+ 0.6357 * parameters.avg_work_of_same_past_second 
	- 0.3349 * parameters.avg_wait_of_same_past_second 
	+ 0.2303 * parameters.avg_latency_of_same_last_20 
	- 0.0176 * parameters.max_latency_of_same_last_50 
	+ 26091043.5153;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM144(work_wait &parameters) {
  double actual_remaining = 
	0.0026 * parameters.work_so_far 
	- 0.0057 * parameters.wait_so_far 
	- 8793581.9627 * parameters.num_locks_so_far 
	+ 873766.0983 * parameters.total_wait_locks 
	- 0.0273 * parameters.mean_wait_of_all 
	- 658426.9975 * parameters.cpu_usage 
	+ 0.2647 * parameters.avg_work_of_same_past_second 
	- 0.6626 * parameters.avg_wait_of_same_past_second 
	+ 0.1971 * parameters.avg_latency_of_same_last_20 
	+ 0.002 * parameters.max_latency_of_same_last_50 
	+ 92980226.9007;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM145(work_wait &parameters) {
  double actual_remaining = 
	0.0247 * parameters.work_so_far 
	- 0.0071 * parameters.wait_so_far 
	- 10047170.2146 * parameters.num_locks_so_far 
	+ 362709.8815 * parameters.total_wait_locks 
	- 0.0457 * parameters.mean_wait_of_all 
	- 57137014.661 * parameters.cpu_usage 
	+ 0.019 * parameters.avg_work_of_same_past_second 
	- 0.0674 * parameters.avg_wait_of_same_past_second 
	+ 0.528 * parameters.avg_latency_of_same_last_20 
	+ 0.0052 * parameters.max_latency_of_same_last_50 
	+ 154401017.2429;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM146(work_wait &parameters) {
  double actual_remaining = 
	0.0247 * parameters.work_so_far 
	- 0.0071 * parameters.wait_so_far 
	- 5045456.5422 * parameters.num_locks_so_far 
	+ 225666.3093 * parameters.total_wait_locks 
	- 0.0601 * parameters.mean_wait_of_all 
	- 3848755.1732 * parameters.cpu_usage 
	+ 0.173 * parameters.avg_work_of_same_past_second 
	- 0.0808 * parameters.avg_wait_of_same_past_second 
	+ 0.0449 * parameters.avg_latency_of_same_last_20 
	+ 0.0411 * parameters.max_latency_of_same_last_50 
	+ 32133721.1735;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM147(work_wait &parameters) {
  double actual_remaining = 
	0.1949 * parameters.work_so_far 
	- 0.2231 * parameters.wait_so_far 
	- 513468.8322 * parameters.num_locks_so_far 
	+ 596434.0563 * parameters.total_wait_locks 
	- 0.0179 * parameters.mean_wait_of_all 
	+ 3043792.6607 * parameters.cpu_usage 
	+ 0.0276 * parameters.avg_work_of_same_past_second 
	- 0.7241 * parameters.avg_wait_of_same_past_second 
	+ 0.0232 * parameters.avg_latency_of_same_last_20 
	+ 0.004 * parameters.max_latency_of_same_last_50 
	+ 177707779.8633;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM148(work_wait &parameters) {
  double actual_remaining = 
	719.8156 * parameters.work_so_far 
	- 0.6977 * parameters.wait_so_far 
	- 513468.8322 * parameters.num_locks_so_far 
	+ 206411.6633 * parameters.total_wait_locks 
	- 0.4146 * parameters.mean_wait_of_all 
	+ 3043792.6607 * parameters.cpu_usage 
	- 0.7278 * parameters.avg_work_of_same_past_second 
	- 0.4459 * parameters.avg_wait_of_same_past_second 
	+ 0.0232 * parameters.avg_latency_of_same_last_20 
	+ 0.004 * parameters.max_latency_of_same_last_50 
	+ 474412790.0609;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM149(work_wait &parameters) {
  double actual_remaining = 
	290.5624 * parameters.work_so_far 
	- 0.3233 * parameters.wait_so_far 
	- 513468.8322 * parameters.num_locks_so_far 
	+ 206411.6633 * parameters.total_wait_locks 
	- 0.4146 * parameters.mean_wait_of_all 
	+ 3043792.6607 * parameters.cpu_usage 
	- 0.7278 * parameters.avg_work_of_same_past_second 
	- 0.4459 * parameters.avg_wait_of_same_past_second 
	+ 0.0232 * parameters.avg_latency_of_same_last_20 
	+ 0.004 * parameters.max_latency_of_same_last_50 
	+ 396441849.3075;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM150(work_wait &parameters) {
  double actual_remaining = 
	840.8686 * parameters.work_so_far 
	- 0.1876 * parameters.wait_so_far 
	- 513468.8322 * parameters.num_locks_so_far 
	+ 206411.6633 * parameters.total_wait_locks 
	- 0.4101 * parameters.mean_wait_of_all 
	+ 3043792.6607 * parameters.cpu_usage 
	- 0.2168 * parameters.avg_work_of_same_past_second 
	- 0.4428 * parameters.avg_wait_of_same_past_second 
	+ 0.0232 * parameters.avg_latency_of_same_last_20 
	+ 0.004 * parameters.max_latency_of_same_last_50 
	+ 246567084.0028;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM151(work_wait &parameters) {
  double actual_remaining = 
	-1.1695 * parameters.work_so_far 
	- 0.2208 * parameters.wait_so_far 
	- 513468.8322 * parameters.num_locks_so_far 
	+ 206411.6633 * parameters.total_wait_locks 
	- 0.3331 * parameters.mean_wait_of_all 
	+ 3043792.6607 * parameters.cpu_usage 
	+ 0.0276 * parameters.avg_work_of_same_past_second 
	- 0.365 * parameters.avg_wait_of_same_past_second 
	+ 0.09 * parameters.avg_latency_of_same_last_20 
	+ 0.004 * parameters.max_latency_of_same_last_50 
	+ 215102092.758;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM152(work_wait &parameters) {
  double actual_remaining = 
	-1.1695 * parameters.work_so_far 
	- 0.2232 * parameters.wait_so_far 
	- 513468.8322 * parameters.num_locks_so_far 
	+ 206411.6633 * parameters.total_wait_locks 
	- 0.3331 * parameters.mean_wait_of_all 
	+ 3043792.6607 * parameters.cpu_usage 
	+ 0.0276 * parameters.avg_work_of_same_past_second 
	- 0.365 * parameters.avg_wait_of_same_past_second 
	+ 0.0922 * parameters.avg_latency_of_same_last_20 
	+ 0.004 * parameters.max_latency_of_same_last_50 
	+ 193466270.5067;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM153(work_wait &parameters) {
  double actual_remaining = 
	0.6868 * parameters.work_so_far 
	- 0.0548 * parameters.wait_so_far 
	- 513468.8322 * parameters.num_locks_so_far 
	+ 177805.5137 * parameters.total_wait_locks 
	- 0.0179 * parameters.mean_wait_of_all 
	+ 3043792.6607 * parameters.cpu_usage 
	+ 0.5068 * parameters.avg_work_of_same_past_second 
	- 0.1934 * parameters.avg_wait_of_same_past_second 
	+ 0.0232 * parameters.avg_latency_of_same_last_20 
	+ 0.004 * parameters.max_latency_of_same_last_50 
	+ 16217241.0514;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM154(work_wait &parameters) {
  double actual_remaining = 
	8.103 * parameters.work_so_far 
	- 0.1426 * parameters.wait_so_far 
	- 513468.8322 * parameters.num_locks_so_far 
	+ 137208.1241 * parameters.total_wait_locks 
	+ 2.0722 * parameters.mean_wait_of_all 
	+ 8533290.7747 * parameters.cpu_usage 
	- 0.2064 * parameters.avg_work_of_same_past_second 
	- 0.1852 * parameters.avg_wait_of_same_past_second 
	+ 0.0232 * parameters.avg_latency_of_same_last_20 
	+ 0.004 * parameters.max_latency_of_same_last_50 
	+ 271781848.0666;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM155(work_wait &parameters) {
  double actual_remaining = 
	0.0021 * parameters.work_so_far 
	- 0.2682 * parameters.wait_so_far 
	- 1281073.5103 * parameters.num_locks_so_far 
	+ 430217.2458 * parameters.total_wait_locks 
	- 1.7146 * parameters.mean_wait_of_all 
	+ 2041810.9145 * parameters.cpu_usage 
	+ 1.264 * parameters.avg_work_of_same_past_second 
	- 0.2375 * parameters.avg_wait_of_same_past_second 
	+ 0.1629 * parameters.avg_latency_of_same_last_20 
	- 0.0419 * parameters.max_latency_of_same_last_50 
	+ 107367785.261;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM156(work_wait &parameters) {
  double actual_remaining = 
	0.4679 * parameters.work_so_far 
	- 0.2524 * parameters.wait_so_far 
	- 6768583.6832 * parameters.num_locks_so_far 
	- 320275.386 * parameters.total_wait_locks 
	+ 2.3375 * parameters.mean_wait_of_all 
	+ 1288692.15 * parameters.cpu_usage 
	+ 0.0063 * parameters.avg_work_of_same_past_second 
	- 0.2274 * parameters.avg_wait_of_same_past_second 
	+ 0.1701 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 238539810.6683;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM157(work_wait &parameters) {
  double actual_remaining = 
	0.001 * parameters.work_so_far 
	- 0.0801 * parameters.wait_so_far 
	- 46838280.5858 * parameters.num_locks_so_far 
	- 174311.3042 * parameters.total_wait_locks 
	+ 1.9589 * parameters.mean_wait_of_all 
	+ 971882.0362 * parameters.cpu_usage 
	+ 0.7975 * parameters.avg_work_of_same_past_second 
	- 0.6632 * parameters.avg_wait_of_same_past_second 
	+ 0.2639 * parameters.avg_latency_of_same_last_20 
	- 0.0272 * parameters.max_latency_of_same_last_50 
	+ 246209246.8643;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM158(work_wait &parameters) {
  double actual_remaining = 
	0.0987 * parameters.work_so_far 
	- 0.0021 * parameters.wait_so_far 
	- 1309439.8699 * parameters.num_locks_so_far 
	- 163481.6075 * parameters.total_wait_locks 
	+ 1.3163 * parameters.mean_wait_of_all 
	+ 971882.0362 * parameters.cpu_usage 
	+ 0.0138 * parameters.avg_work_of_same_past_second 
	- 0.0096 * parameters.avg_wait_of_same_past_second 
	+ 0.0686 * parameters.avg_latency_of_same_last_20 
	- 0.0005 * parameters.max_latency_of_same_last_50 
	+ 43613251.0312;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}

static
double
tpcc_LM159(work_wait &parameters) {
  double actual_remaining = 
	0.0009 * parameters.work_so_far 
	- 0.2001 * parameters.wait_so_far 
	- 7354158.21 * parameters.num_locks_so_far 
	- 483240.7204 * parameters.total_wait_locks 
	+ 3.2972 * parameters.mean_wait_of_all 
	+ 0.3328 * parameters.avg_work_of_same_past_second 
	- 0.5278 * parameters.avg_wait_of_same_past_second 
	+ 0.3308 * parameters.avg_latency_of_same_last_20 
	- 0.0001 * parameters.max_latency_of_same_last_50 
	+ 184386437.6715;
  return actual_remaining > 0 ? actual_remaining : parameters.work_so_far + parameters.wait_so_far;
}
double
tpcc_estimate(work_wait &parameters){

  if (parameters.avg_work_of_same_past_second <= 47348650) {

    if (parameters.work_so_far <= 15004.5) {

      if (parameters.work_so_far <= 9713) {

        if (parameters.wait_so_far <= 19825568) {
          return tpcc_LM1(parameters);
        } else {

          if (parameters.avg_wait_of_same_past_second <= 57428200) {
            return tpcc_LM2(parameters);
          } else {

            if (parameters.avg_work_of_same_past_second <= 13366100) {

              if (parameters.avg_wait_of_same_past_second <= 64789050) {

                if (parameters.total_wait_locks <= 108.5) {
                  return tpcc_LM3(parameters);
                } else {
                  return tpcc_LM4(parameters);
                }
              } else {

                if (parameters.avg_latency_of_same_last_20 <= 26440550) {
                  return tpcc_LM5(parameters);
                } else {

                  if (parameters.cpu_usage <= 0.944) {
                    return tpcc_LM6(parameters);
                  } else {

                    if (parameters.mean_wait_of_all <= 57858650) {

                      if (parameters.avg_latency_of_same_last_20 <= 40150350) {
                        return tpcc_LM7(parameters);
                      } else {

                        if (parameters.cpu_usage <= 0.947) {
                          return tpcc_LM8(parameters);
                        } else {
                          return tpcc_LM9(parameters);
                        }
                      }
                    } else {

                      if (parameters.total_wait_locks <= 152) {

                        if (parameters.total_wait_locks <= 138.5) {
                          return tpcc_LM10(parameters);
                        } else {
                          return tpcc_LM11(parameters);
                        }
                      } else {

                        if (parameters.work_so_far <= 8871) {
                          return tpcc_LM12(parameters);
                        } else {
                          return tpcc_LM13(parameters);
                        }
                      }
                    }
                  }
                }
              }
            } else {
              return tpcc_LM14(parameters);
            }
          }
        }
      } else {
        return tpcc_LM15(parameters);
      }
    } else {

      if (parameters.avg_wait_of_same_past_second <= 90310350) {

        if (parameters.avg_work_of_same_past_second <= 22521600) {

          if (parameters.avg_wait_of_same_past_second <= 9148040) {
            return tpcc_LM16(parameters);
          } else {

            if (parameters.max_latency_of_same_last_50 <= 822106000) {
              return tpcc_LM17(parameters);
            } else {

              if (parameters.total_wait_locks <= 249.5) {

                if (parameters.cpu_usage <= 0.922) {

                  if (parameters.avg_work_of_same_past_second <= 12612150) {

                    if (parameters.cpu_usage <= 0.906) {
                      return tpcc_LM18(parameters);
                    } else {
                      return tpcc_LM19(parameters);
                    }
                  } else {
                    return tpcc_LM20(parameters);
                  }
                } else {
                  return tpcc_LM21(parameters);
                }
              } else {
                return tpcc_LM22(parameters);
              }
            }
          }
        } else {

          if (parameters.work_so_far <= 945736.5) {

            if (parameters.avg_latency_of_same_last_20 <= 40019700) {
              return tpcc_LM23(parameters);
            } else {
              return tpcc_LM24(parameters);
            }
          } else {

            if (parameters.total_wait_locks <= 138) {
              return tpcc_LM25(parameters);
            } else {

              if (parameters.num_locks_so_far <= 140.5) {

                if (parameters.wait_so_far <= 24965468.5) {
                  return tpcc_LM26(parameters);
                } else {

                  if (parameters.avg_latency_of_same_last_20 <= 411937500) {
                    return tpcc_LM27(parameters);
                  } else {

                    if (parameters.cpu_usage <= 0.95) {
                      return tpcc_LM28(parameters);
                    } else {

                      if (parameters.avg_work_of_same_past_second <= 38639000) {

                        if (parameters.num_locks_so_far <= 92) {

                          if (parameters.avg_latency_of_same_last_20 <= 661131000) {

                            if (parameters.total_wait_locks <= 591.5) {

                              if (parameters.cpu_usage <= 0.986) {
                                return tpcc_LM29(parameters);
                              } else {
                                return tpcc_LM30(parameters);
                              }
                            } else {

                              if (parameters.mean_wait_of_all <= 135900000) {
                                return tpcc_LM31(parameters);
                              } else {
                                return tpcc_LM32(parameters);
                              }
                            }
                          } else {
                            return tpcc_LM33(parameters);
                          }
                        } else {
                          return tpcc_LM34(parameters);
                        }
                      } else {

                        if (parameters.num_locks_so_far <= 63) {
                          return tpcc_LM35(parameters);
                        } else {
                          return tpcc_LM36(parameters);
                        }
                      }
                    }
                  }
                }
              } else {

                if (parameters.wait_so_far <= 75472609.5) {

                  if (parameters.work_so_far <= 3064442.5) {
                    return tpcc_LM37(parameters);
                  } else {

                    if (parameters.mean_wait_of_all <= 76663250) {
                      return tpcc_LM38(parameters);
                    } else {
                      return tpcc_LM39(parameters);
                    }
                  }
                } else {
                  return tpcc_LM40(parameters);
                }
              }
            }
          }
        }
      } else {

        if (parameters.avg_wait_of_same_past_second <= 315209000) {

          if (parameters.avg_latency_of_same_last_20 <= 355333500) {

            if (parameters.avg_work_of_same_past_second <= 22700950) {

              if (parameters.max_latency_of_same_last_50 <= 684141500) {

                if (parameters.avg_wait_of_same_past_second <= 100971000) {

                  if (parameters.cpu_usage <= 0.947) {

                    if (parameters.avg_work_of_same_past_second <= 15515050) {
                      return tpcc_LM41(parameters);
                    } else {
                      return tpcc_LM42(parameters);
                    }
                  } else {
                    return tpcc_LM43(parameters);
                  }
                } else {
                  return tpcc_LM44(parameters);
                }
              } else {

                if (parameters.avg_work_of_same_past_second <= 21353600) {

                  if (parameters.avg_wait_of_same_past_second <= 291071500) {
                    return tpcc_LM45(parameters);
                  } else {

                    if (parameters.avg_work_of_same_past_second <= 19563200) {

                      if (parameters.avg_wait_of_same_past_second <= 292921000) {

                        if (parameters.wait_so_far <= 321096917) {

                          if (parameters.max_latency_of_same_last_50 <= 973007000) {
                            return tpcc_LM46(parameters);
                          } else {
                            return tpcc_LM47(parameters);
                          }
                        } else {
                          return tpcc_LM48(parameters);
                        }
                      } else {

                        if (parameters.avg_work_of_same_past_second <= 18552700) {
                          return tpcc_LM49(parameters);
                        } else {

                          if (parameters.avg_wait_of_same_past_second <= 304318000) {
                            return tpcc_LM50(parameters);
                          } else {
                            return tpcc_LM51(parameters);
                          }
                        }
                      }
                    } else {

                      if (parameters.avg_work_of_same_past_second <= 20364650) {
                        return tpcc_LM52(parameters);
                      } else {
                        return tpcc_LM53(parameters);
                      }
                    }
                  }
                } else {
                  return tpcc_LM54(parameters);
                }
              }
            } else {
              return tpcc_LM55(parameters);
            }
          } else {

            if (parameters.total_wait_locks <= 216) {
              return tpcc_LM56(parameters);
            } else {

              if (parameters.avg_wait_of_same_past_second <= 210004500) {

                if (parameters.avg_work_of_same_past_second <= 24042700) {

                  if (parameters.mean_wait_of_all <= 56180450) {

                    if (parameters.avg_wait_of_same_past_second <= 198152000) {

                      if (parameters.avg_latency_of_same_last_20 <= 549889500) {

                        if (parameters.avg_wait_of_same_past_second <= 126310500) {
                          return tpcc_LM57(parameters);
                        } else {
                          return tpcc_LM58(parameters);
                        }
                      } else {

                        if (parameters.avg_latency_of_same_last_20 <= 602775000) {
                          return tpcc_LM59(parameters);
                        } else {
                          return tpcc_LM60(parameters);
                        }
                      }
                    } else {
                      return tpcc_LM61(parameters);
                    }
                  } else {
                    return tpcc_LM62(parameters);
                  }
                } else {

                  if (parameters.max_latency_of_same_last_50 <= 1327390000) {
                    return tpcc_LM63(parameters);
                  } else {

                    if (parameters.total_wait_locks <= 279.5) {
                      return tpcc_LM64(parameters);
                    } else {
                      return tpcc_LM65(parameters);
                    }
                  }
                }
              } else {

                if (parameters.max_latency_of_same_last_50 <= 1085085000) {
                  return tpcc_LM66(parameters);
                } else {

                  if (parameters.avg_work_of_same_past_second <= 18759200) {

                    if (parameters.max_latency_of_same_last_50 <= 1282005000) {
                      return tpcc_LM67(parameters);
                    } else {
                      return tpcc_LM68(parameters);
                    }
                  } else {

                    if (parameters.avg_work_of_same_past_second <= 21037100) {

                      if (parameters.mean_wait_of_all <= 86395300) {
                        return tpcc_LM69(parameters);
                      } else {

                        if (parameters.avg_wait_of_same_past_second <= 305606000) {

                          if (parameters.total_wait_locks <= 626) {
                            return tpcc_LM70(parameters);
                          } else {

                            if (parameters.mean_wait_of_all <= 130911500) {
                              return tpcc_LM71(parameters);
                            } else {
                              return tpcc_LM72(parameters);
                            }
                          }
                        } else {

                          if (parameters.mean_wait_of_all <= 96019900) {
                            return tpcc_LM73(parameters);
                          } else {
                            return tpcc_LM74(parameters);
                          }
                        }
                      }
                    } else {

                      if (parameters.avg_latency_of_same_last_20 <= 518529000) {

                        if (parameters.avg_wait_of_same_past_second <= 287974000) {
                          return tpcc_LM75(parameters);
                        } else {

                          if (parameters.avg_wait_of_same_past_second <= 295687000) {
                            return tpcc_LM76(parameters);
                          } else {
                            return tpcc_LM77(parameters);
                          }
                        }
                      } else {
                        return tpcc_LM78(parameters);
                      }
                    }
                  }
                }
              }
            }
          }
        } else {

          if (parameters.avg_work_of_same_past_second <= 31260300) {

            if (parameters.total_wait_locks <= 558.5) {

              if (parameters.mean_wait_of_all <= 101893500) {
                return tpcc_LM79(parameters);
              } else {

                if (parameters.max_latency_of_same_last_50 <= 1350585000) {

                  if (parameters.mean_wait_of_all <= 109436500) {
                    return tpcc_LM80(parameters);
                  } else {

                    if (parameters.wait_so_far <= 210128520.5) {
                      return tpcc_LM81(parameters);
                    } else {

                      if (parameters.mean_wait_of_all <= 117168000) {
                        return tpcc_LM82(parameters);
                      } else {

                        if (parameters.avg_work_of_same_past_second <= 23449050) {
                          return tpcc_LM83(parameters);
                        } else {
                          return tpcc_LM84(parameters);
                        }
                      }
                    }
                  }
                } else {

                  if (parameters.avg_latency_of_same_last_20 <= 493852000) {

                    if (parameters.total_wait_locks <= 432.5) {

                      if (parameters.mean_wait_of_all <= 102345000) {
                        return tpcc_LM85(parameters);
                      } else {

                        if (parameters.max_latency_of_same_last_50 <= 1462630000) {

                          if (parameters.wait_so_far <= 166199149.5) {
                            return tpcc_LM86(parameters);
                          } else {
                            return tpcc_LM87(parameters);
                          }
                        } else {

                          if (parameters.avg_work_of_same_past_second <= 25133600) {
                            return tpcc_LM88(parameters);
                          } else {

                            if (parameters.mean_wait_of_all <= 107478500) {
                              return tpcc_LM89(parameters);
                            } else {
                              return tpcc_LM90(parameters);
                            }
                          }
                        }
                      }
                    } else {

                      if (parameters.avg_latency_of_same_last_20 <= 412000500) {

                        if (parameters.avg_work_of_same_past_second <= 25419400) {

                          if (parameters.avg_work_of_same_past_second <= 23191850) {

                            if (parameters.avg_work_of_same_past_second <= 20599100) {
                              return tpcc_LM91(parameters);
                            } else {
                              return tpcc_LM92(parameters);
                            }
                          } else {
                            return tpcc_LM93(parameters);
                          }
                        } else {

                          if (parameters.total_wait_locks <= 470.5) {
                            return tpcc_LM94(parameters);
                          } else {

                            if (parameters.work_so_far <= 32306.5) {
                              return tpcc_LM95(parameters);
                            } else {
                              return tpcc_LM96(parameters);
                            }
                          }
                        }
                      } else {

                        if (parameters.avg_wait_of_same_past_second <= 574155000) {

                          if (parameters.avg_work_of_same_past_second <= 26877200) {

                            if (parameters.work_so_far <= 31474) {
                              return tpcc_LM97(parameters);
                            } else {

                              if (parameters.avg_latency_of_same_last_20 <= 465664000) {
                                return tpcc_LM98(parameters);
                              } else {

                                if (parameters.avg_work_of_same_past_second <= 25189550) {
                                  return tpcc_LM99(parameters);
                                } else {
                                  return tpcc_LM100(parameters);
                                }
                              }
                            }
                          } else {

                            if (parameters.work_so_far <= 37766.5) {
                              return tpcc_LM101(parameters);
                            } else {

                              if (parameters.wait_so_far <= 168891182) {
                                return tpcc_LM102(parameters);
                              } else {
                                return tpcc_LM103(parameters);
                              }
                            }
                          }
                        } else {

                          if (parameters.avg_wait_of_same_past_second <= 590454000) {
                            return tpcc_LM104(parameters);
                          } else {
                            return tpcc_LM105(parameters);
                          }
                        }
                      }
                    }
                  } else {

                    if (parameters.avg_latency_of_same_last_20 <= 650354500) {
                      return tpcc_LM106(parameters);
                    } else {

                      if (parameters.avg_wait_of_same_past_second <= 468255000) {

                        if (parameters.cpu_usage <= 0.968) {

                          if (parameters.max_latency_of_same_last_50 <= 2182465000) {

                            if (parameters.avg_latency_of_same_last_20 <= 706656000) {
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
                  }
                }
              }
            } else {

              if (parameters.avg_wait_of_same_past_second <= 450080500) {

                if (parameters.mean_wait_of_all <= 132979500) {
                  return tpcc_LM112(parameters);
                } else {

                  if (parameters.mean_wait_of_all <= 138467500) {

                    if (parameters.avg_wait_of_same_past_second <= 396330000) {

                      if (parameters.avg_wait_of_same_past_second <= 372280500) {

                        if (parameters.avg_work_of_same_past_second <= 24251150) {
                          return tpcc_LM113(parameters);
                        } else {
                          return tpcc_LM114(parameters);
                        }
                      } else {

                        if (parameters.work_so_far <= 207973) {

                          if (parameters.max_latency_of_same_last_50 <= 1490445000) {

                            if (parameters.avg_work_of_same_past_second <= 29636850) {

                              if (parameters.mean_wait_of_all <= 137263000) {

                                if (parameters.avg_wait_of_same_past_second <= 374671000) {

                                  if (parameters.total_wait_locks <= 665) {
                                    return tpcc_LM115(parameters);
                                  } else {
                                    return tpcc_LM116(parameters);
                                  }
                                } else {

                                  if (parameters.avg_wait_of_same_past_second <= 395626000) {
                                    return tpcc_LM117(parameters);
                                  } else {
                                    return tpcc_LM118(parameters);
                                  }
                                }
                              } else {
                                return tpcc_LM119(parameters);
                              }
                            } else {

                              if (parameters.avg_work_of_same_past_second <= 29656350) {
                                return tpcc_LM120(parameters);
                              } else {
                                return tpcc_LM121(parameters);
                              }
                            }
                          } else {
                            return tpcc_LM122(parameters);
                          }
                        } else {
                          return tpcc_LM123(parameters);
                        }
                      }
                    } else {

                      if (parameters.avg_latency_of_same_last_20 <= 421049500) {
                        return tpcc_LM124(parameters);
                      } else {
                        return tpcc_LM125(parameters);
                      }
                    }
                  } else {
                    return tpcc_LM126(parameters);
                  }
                }
              } else {
                return tpcc_LM127(parameters);
              }
            }
          } else {

            if (parameters.avg_latency_of_same_last_20 <= 343090000) {

              if (parameters.max_latency_of_same_last_50 <= 1122135000) {

                if (parameters.mean_wait_of_all <= 102627500) {

                  if (parameters.avg_wait_of_same_past_second <= 385987500) {
                    return tpcc_LM128(parameters);
                  } else {
                    return tpcc_LM129(parameters);
                  }
                } else {

                  if (parameters.avg_wait_of_same_past_second <= 394381000) {

                    if (parameters.max_latency_of_same_last_50 <= 1073620000) {
                      return tpcc_LM130(parameters);
                    } else {

                      if (parameters.wait_so_far <= 92050035.5) {
                        return tpcc_LM131(parameters);
                      } else {
                        return tpcc_LM132(parameters);
                      }
                    }
                  } else {
                    return tpcc_LM133(parameters);
                  }
                }
              } else {

                if (parameters.cpu_usage <= 0.959) {
                  return tpcc_LM134(parameters);
                } else {
                  return tpcc_LM135(parameters);
                }
              }
            } else {

              if (parameters.mean_wait_of_all <= 102115000) {

                if (parameters.total_wait_locks <= 390.5) {
                  return tpcc_LM136(parameters);
                } else {
                  return tpcc_LM137(parameters);
                }
              } else {

                if (parameters.avg_wait_of_same_past_second <= 446326000) {

                  if (parameters.avg_latency_of_same_last_20 <= 595299000) {

                    if (parameters.avg_work_of_same_past_second <= 35126600) {
                      return tpcc_LM138(parameters);
                    } else {
                      return tpcc_LM139(parameters);
                    }
                  } else {

                    if (parameters.avg_wait_of_same_past_second <= 426615500) {
                      return tpcc_LM140(parameters);
                    } else {
                      return tpcc_LM141(parameters);
                    }
                  }
                } else {
                  return tpcc_LM142(parameters);
                }
              }
            }
          }
        }
      }
    }
  } else {

    if (parameters.total_wait_locks <= 173.5) {

      if (parameters.avg_work_of_same_past_second <= 130593000) {
        return tpcc_LM143(parameters);
      } else {

        if (parameters.mean_wait_of_all <= 47471250) {
          return tpcc_LM144(parameters);
        } else {

          if (parameters.avg_latency_of_same_last_20 <= 156138500) {

            if (parameters.avg_wait_of_same_past_second <= 52665200) {
              return tpcc_LM145(parameters);
            } else {
              return tpcc_LM146(parameters);
            }
          } else {

            if (parameters.avg_work_of_same_past_second <= 235825500) {

              if (parameters.wait_so_far <= 326414543.5) {

                if (parameters.work_so_far <= 40719) {
                  return tpcc_LM147(parameters);
                } else {

                  if (parameters.work_so_far <= 257571) {

                    if (parameters.avg_latency_of_same_last_20 <= 296465000) {

                      if (parameters.avg_work_of_same_past_second <= 146340000) {
                        return tpcc_LM148(parameters);
                      } else {
                        return tpcc_LM149(parameters);
                      }
                    } else {
                      return tpcc_LM150(parameters);
                    }
                  } else {

                    if (parameters.wait_so_far <= 133256615.5) {
                      return tpcc_LM151(parameters);
                    } else {
                      return tpcc_LM152(parameters);
                    }
                  }
                }
              } else {
                return tpcc_LM153(parameters);
              }
            } else {
              return tpcc_LM154(parameters);
            }
          }
        }
      }
    } else {

      if (parameters.avg_work_of_same_past_second <= 253981500) {

        if (parameters.wait_so_far <= 392730132) {

          if (parameters.avg_work_of_same_past_second <= 157546000) {
            return tpcc_LM155(parameters);
          } else {
            return tpcc_LM156(parameters);
          }
        } else {

          if (parameters.num_locks_so_far <= 4.5) {
            return tpcc_LM157(parameters);
          } else {
            return tpcc_LM158(parameters);
          }
        }
      } else {
        return tpcc_LM159(parameters);
      }
    }
  }
}