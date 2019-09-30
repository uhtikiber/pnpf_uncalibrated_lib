/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xnrm2.h
 *
 * Code generation for function 'xnrm2'
 *
 */

#ifndef XNRM2_H
#define XNRM2_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "solve_P4Pf_types.h"

/* Function Declarations */
extern double b_xnrm2(int n, const creal_T x_data[], int ix0);
extern double c_xnrm2(int n, const double x[9], int ix0);
extern double d_xnrm2(int n, const double x[36], int ix0);
extern double e_xnrm2(int n, const double x[4], int ix0);
extern double xnrm2(int n, const double x[64], int ix0);

#endif

/* End of code generation (xnrm2.h) */