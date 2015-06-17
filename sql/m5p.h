#ifndef M5P_H
#define M5P_H

#include "trace_tool.h"

static
double
new_order_estimate(
  work_wait &parameters);

static
double
payment_estimate(
  work_wait &parameters);

static
double
delivery_estimate(
  work_wait &parameters);

static
double
stock_level_estimate(
  work_wait &parameters);

static
double
tpcc_estimate(
  work_wait &parameters);

#endif