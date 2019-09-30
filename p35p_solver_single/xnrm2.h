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
#include "p35p_solver_types.h"

/* Function Declarations */
extern float b_xnrm2(int n, const float x[3]);
extern float c_xnrm2(int n, const float x[12], int ix0);
extern float xnrm2(int n, const float x[100], int ix0);

#endif

/* End of code generation (xnrm2.h) */