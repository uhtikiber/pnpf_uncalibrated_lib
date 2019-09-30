/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xger.h
 *
 * Code generation for function 'xger'
 *
 */

#ifndef XGER_H
#define XGER_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "solve_P4Pf_types.h"

/* Function Declarations */
extern void b_xger(int m, int n, float alpha1, int ix0, const float y[3], float
                   A[9], int ia0);
extern void xger(int m, int n, float alpha1, int ix0, const float y[8], float A
                 [64], int ia0);

#endif

/* End of code generation (xger.h) */
