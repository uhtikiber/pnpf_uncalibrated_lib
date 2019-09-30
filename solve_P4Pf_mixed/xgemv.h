/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgemv.h
 *
 * Code generation for function 'xgemv'
 *
 */

#ifndef XGEMV_H
#define XGEMV_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "solve_P4Pf_types.h"

/* Function Declarations */
extern void b_xgemv(int m, int n, const float A[9], int ia0, const float x[9],
                    int ix0, float y[3]);
extern void xgemv(int m, int n, const float A[64], int ia0, const float x[64],
                  int ix0, float y[8]);

#endif

/* End of code generation (xgemv.h) */