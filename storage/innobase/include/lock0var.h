/*
 @file include/lock0var.h
 The transaction lock system
 */

#ifndef lock0var_h
#define lock0var_h

#include "univ.i"
#include "lock0types.h"

#include <vector>
#include <fstream>

/*************************************************************//**
Do initilization for the min-variance scheduling algorithm. */
UNIV_INTERN
void
indi_init();

/*************************************************************//**
Estimate remaining time given total time so far
and transaction type. */
UNIV_INTERN
ulint
estimate(
  ulint time_so_far,     /*!< total time so far */
  transaction_type type);/*!< Transaction type */

/*************************************************************//**
Find the lock that gives minimum CTV. */
UNIV_INTERN
void
LVM_schedule(
  vector<lock_t *> &waiting_locks,  /*!< waiting locks */
  vector<lock_t *> &locks_to_grant);

/*************************************************************//**
Clean up resources. */
UNIV_INTERN
void
indi_cleanup();

#endif /* defined(lock0var_h) */
