/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xztgevc.cpp
 *
 * Code generation for function 'xztgevc'
 *
 */

/* Include files */
#include <cmath>
#include "rt_nonfinite.h"
#include "p35p_solver.h"
#include "xztgevc.h"

/* Function Definitions */
void xztgevc(const creal32_T A[100], creal32_T V[100])
{
  int i;
  float anorm;
  float rworka[10];
  int j;
  float xmx;
  float d_re;
  float ascale;
  int je;
  int x_tmp;
  float temp;
  float salpha_re;
  float salpha_im;
  float acoeff;
  boolean_T lscalea;
  float z;
  boolean_T lscaleb;
  float scale;
  int jr;
  creal32_T work1[10];
  float dmin;
  int i22;
  creal32_T work2[10];
  float d_im;
  int i23;
  for (i = 0; i < 10; i++) {
    rworka[i] = 0.0F;
  }

  anorm = std::abs(A[0].re) + std::abs(A[0].im);
  for (j = 0; j < 9; j++) {
    for (i = 0; i <= j; i++) {
      rworka[j + 1] += std::abs(A[i + 10 * (j + 1)].re) + std::abs(A[i + 10 * (j
        + 1)].im);
    }

    d_re = rworka[j + 1] + (std::abs(A[(j + 10 * (j + 1)) + 1].re) + std::abs(A
      [(j + 10 * (j + 1)) + 1].im));
    if (d_re > anorm) {
      anorm = d_re;
    }
  }

  xmx = anorm;
  if (1.17549435E-38F > anorm) {
    xmx = 1.17549435E-38F;
  }

  ascale = 1.0F / xmx;
  for (je = 0; je < 10; je++) {
    x_tmp = 10 * (9 - je);
    xmx = (std::abs(A[(x_tmp - je) + 9].re) + std::abs(A[(10 * (9 - je) - je) +
            9].im)) * ascale;
    if (1.0F > xmx) {
      xmx = 1.0F;
    }

    temp = 1.0F / xmx;
    salpha_re = ascale * (temp * A[(10 * (9 - je) - je) + 9].re);
    salpha_im = ascale * (temp * A[(10 * (9 - je) - je) + 9].im);
    acoeff = temp * ascale;
    if ((temp >= 1.17549435E-38F) && (acoeff < 9.86076132E-31F)) {
      lscalea = true;
    } else {
      lscalea = false;
    }

    z = std::abs(salpha_re) + std::abs(salpha_im);
    if ((z >= 1.17549435E-38F) && (z < 9.86076132E-31F)) {
      lscaleb = true;
    } else {
      lscaleb = false;
    }

    scale = 1.0F;
    if (lscalea) {
      xmx = anorm;
      if (1.0141205E+30F < anorm) {
        xmx = 1.0141205E+30F;
      }

      scale = 9.86076132E-31F / temp * xmx;
    }

    if (lscaleb) {
      d_re = 9.86076132E-31F / z;
      if (d_re > scale) {
        scale = d_re;
      }
    }

    if (lscalea || lscaleb) {
      xmx = acoeff;
      if (1.0F > acoeff) {
        xmx = 1.0F;
      }

      if (z > xmx) {
        xmx = z;
      }

      d_re = 1.0F / (1.17549435E-38F * xmx);
      if (d_re < scale) {
        scale = d_re;
      }

      if (lscalea) {
        acoeff = ascale * (scale * temp);
      } else {
        acoeff *= scale;
      }

      salpha_re *= scale;
      salpha_im *= scale;
    }

    for (jr = 0; jr < 10; jr++) {
      work1[jr].re = 0.0F;
      work1[jr].im = 0.0F;
    }

    work1[9 - je].re = 1.0F;
    work1[9 - je].im = 0.0F;
    d_re = 1.1920929E-7F * (std::abs(salpha_re) + std::abs(salpha_im));
    dmin = 1.1920929E-7F * acoeff * anorm;
    if (d_re > dmin) {
      dmin = d_re;
    }

    if (1.17549435E-38F > dmin) {
      dmin = 1.17549435E-38F;
    }

    i22 = 8 - je;
    for (jr = 0; jr <= i22; jr++) {
      work1[jr].re = acoeff * A[jr + x_tmp].re;
      work1[jr].im = acoeff * A[jr + 10 * (9 - je)].im;
    }

    work1[9 - je].re = 1.0F;
    work1[9 - je].im = 0.0F;
    i22 = static_cast<int>(((1.0 + (-1.0 - ((10.0 + -static_cast<double>(je)) -
      1.0))) / -1.0));
    for (j = 0; j < i22; j++) {
      i = 8 - (je + j);
      d_re = acoeff * A[i + 10 * i].re - salpha_re;
      d_im = acoeff * A[i + 10 * i].im - salpha_im;
      if (std::abs(d_re) + std::abs(d_im) <= dmin) {
        d_re = dmin;
        d_im = 0.0F;
      }

      xmx = std::abs(d_re) + std::abs(d_im);
      if (xmx < 1.0F) {
        z = std::abs(work1[i].re) + std::abs(work1[i].im);
        if (z >= 8.5070593E+36F * xmx) {
          temp = 1.0F / z;
          i23 = 9 - je;
          for (jr = 0; jr <= i23; jr++) {
            work1[jr].re *= temp;
            work1[jr].im *= temp;
          }
        }
      }

      temp = -work1[i].re;
      if (d_im == 0.0F) {
        if (-work1[i].im == 0.0F) {
          work1[i].re = -work1[i].re / d_re;
          work1[i].im = 0.0F;
        } else if (-work1[i].re == 0.0F) {
          work1[i].re = 0.0F;
          work1[i].im = -work1[i].im / d_re;
        } else {
          work1[i].re = -work1[i].re / d_re;
          work1[i].im = -work1[i].im / d_re;
        }
      } else if (d_re == 0.0F) {
        if (-work1[i].re == 0.0F) {
          work1[i].re = -work1[i].im / d_im;
          work1[i].im = 0.0F;
        } else if (-work1[i].im == 0.0F) {
          work1[i].re = 0.0F;
          work1[i].im = -(temp / d_im);
        } else {
          work1[i].re = -work1[i].im / d_im;
          work1[i].im = -(temp / d_im);
        }
      } else {
        scale = std::abs(d_re);
        xmx = std::abs(d_im);
        if (scale > xmx) {
          scale = d_im / d_re;
          z = d_re + scale * d_im;
          work1[i].re = (-work1[i].re + scale * -work1[i].im) / z;
          work1[i].im = (-work1[i].im - scale * temp) / z;
        } else if (xmx == scale) {
          if (d_re > 0.0F) {
            z = 0.5F;
          } else {
            z = -0.5F;
          }

          if (d_im > 0.0F) {
            xmx = 0.5F;
          } else {
            xmx = -0.5F;
          }

          work1[i].re = (-work1[i].re * z + -work1[i].im * xmx) / scale;
          work1[i].im = (-work1[i].im * z - temp * xmx) / scale;
        } else {
          scale = d_re / d_im;
          z = d_im + scale * d_re;
          xmx = scale * -work1[i].im - (-work1[i].re);
          work1[i].re = (scale * -work1[i].re + -work1[i].im) / z;
          work1[i].im = xmx / z;
        }
      }

      if (i + 1 > 1) {
        xmx = std::abs(work1[i].re) + std::abs(work1[i].im);
        if (xmx > 1.0F) {
          temp = 1.0F / xmx;
          if (acoeff * rworka[i] >= 8.5070593E+36F * temp) {
            i23 = 9 - je;
            for (jr = 0; jr <= i23; jr++) {
              work1[jr].re *= temp;
              work1[jr].im *= temp;
            }
          }
        }

        d_re = acoeff * work1[i].re;
        d_im = acoeff * work1[i].im;
        for (jr = 0; jr < i; jr++) {
          work1[jr].re += d_re * A[jr + 10 * i].re - d_im * A[jr + 10 * i].im;
          work1[jr].im += d_re * A[jr + 10 * i].im + d_im * A[jr + 10 * i].re;
        }
      }
    }

    for (jr = 0; jr < 10; jr++) {
      work2[jr].re = 0.0F;
      work2[jr].im = 0.0F;
    }

    i22 = 9 - je;
    for (i = 0; i <= i22; i++) {
      for (jr = 0; jr < 10; jr++) {
        work2[jr].re += V[jr + 10 * i].re * work1[i].re - V[jr + 10 * i].im *
          work1[i].im;
        work2[jr].im += V[jr + 10 * i].re * work1[i].im + V[jr + 10 * i].im *
          work1[i].re;
      }
    }

    xmx = std::abs(work2[0].re) + std::abs(work2[0].im);
    for (jr = 0; jr < 9; jr++) {
      d_re = std::abs(work2[jr + 1].re) + std::abs(work2[jr + 1].im);
      if (d_re > xmx) {
        xmx = d_re;
      }
    }

    if (xmx > 1.17549435E-38F) {
      temp = 1.0F / xmx;
      for (jr = 0; jr < 10; jr++) {
        i22 = jr + x_tmp;
        V[i22].re = temp * work2[jr].re;
        V[i22].im = temp * work2[jr].im;
      }
    } else {
      for (jr = 0; jr < 10; jr++) {
        i22 = jr + x_tmp;
        V[i22].re = 0.0F;
        V[i22].im = 0.0F;
      }
    }
  }
}

/* End of code generation (xztgevc.cpp) */
