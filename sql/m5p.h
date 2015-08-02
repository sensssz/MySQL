#ifndef M5P_H
#define M5P_H

#include "my_global.h"                          /* NO_EMBEDDED_ACCESS_CHECKS */
#include "trace_tool.h"

double
new_order_estimate(
  work_wait &parameters);

double
payment_estimate(
  work_wait &parameters);

double
delivery_estimate(
  work_wait &parameters);

double
stock_level_estimate(
  work_wait &parameters);

double
tpcc_estimate(
  work_wait &parameters);

#endif