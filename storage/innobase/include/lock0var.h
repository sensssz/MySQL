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
Estimate remaining time given total time so far. */
UNIV_INTERN
ulint
estimate(ulint time_so_far); /*!< total time so far */

/*************************************************************//**
Clean up resources. */
UNIV_INTERN
void
indi_cleanup();

#endif /* defined(lock0var_h) */
