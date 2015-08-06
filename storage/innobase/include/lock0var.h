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
Find the lock that gives minimum CTV. */
UNIV_INTERN
void
estimate(
  list<lock_t *> &wait_locks)  /*!< waiting locks */

/*************************************************************//**
Clean up resources. */
UNIV_INTERN
void
indi_cleanup();

#endif /* defined(lock0var_h) */
