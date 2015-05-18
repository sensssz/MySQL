/*
 @file include/lock0var.h
 The transaction lock system
 */

#ifndef lock0var_h
#define lock0var_h

#include "univ.i"
#include "lock0types.h"

#include <vector>

/*************************************************************//**
Do initilization for the min-variance scheduling algorithm. */
UNIV_INTERN
void
indi_init();

/*************************************************************//**
Find the lock request that minimizes variance. */
UNIV_INTERN
lock_t *
find_min_var_lock(
  const vector<lock_t *> &locks); /*!<  list of locks on the same record */

/*************************************************************//**
Update the last access time for one of the buckets of remaining time. */
UNIV_INTERN
void
update_access(
  ulint remaining_time); /*!< real remaining time */

/*************************************************************//**
Clean up resources. */
UNIV_INTERN
void
indi_cleanup();

#endif /* defined(lock0var_h) */
