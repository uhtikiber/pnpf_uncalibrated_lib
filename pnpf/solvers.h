//
// Created by elizaveta on 28.10.2019.
//

#ifndef PNP_TEST_SOLVERS_H
#define PNP_TEST_SOLVERS_H

#include "pnpf.h"
#include <Eigen/Dense>
#include <climits>

template <class SolverClass, class T> class Solver {
protected:
  T e;

public:
  Solver() { e = std::numeric_limits<T>::epsilon(); }
  void solve(Eigen::Matrix<T, 3, 4> &points_3d,
             Eigen::Matrix<T, 2, 4> &points_2d, int *n, T *fs,
             Eigen::Matrix<T, 3, 3> *Rs, Eigen::Matrix<T, 3, 1> *Cs,
             T diag = 1) {
    static_cast<SolverClass *>(this)->vSolve(points_3d, points_2d, n, fs, Rs,
                                             Cs, diag);
  };
};

template <class MatlabSolverClass, class T>
class MatlabSolver : public Solver<MatlabSolver<MatlabSolverClass, T>, T> {
public:
  T *X;
  T xy[8];
  int sol_num;
  int f_size[2], r_size[3], t_size[2];
  T f_data[10], r_data[90], t_data[30]; // todo: check sizes

  void dataEigenToMatlab(Eigen::Matrix<T, 3, 4> &points_3d,
                         Eigen::Matrix<T, 2, 4> &points_2d, T diag) {
    X = points_3d.data();
    Eigen::Map<Eigen::Matrix<T, 2, 4>>(xy, 2, 4) = points_2d / diag;
  }

  void dataMatlabToEigen(int *n, T *fs, Eigen::Matrix<T, 3, 3> *Rs,
                         Eigen::Matrix<T, 3, 1> *Cs, T diag) {
    *n = sol_num;
    for (int i = 0; i < *n; ++i) {
      fs[i] = f_data[i] * diag;
      Cs[i] = Eigen::Map<Eigen::Matrix<T, 3, 1>>(&(t_data[3 * i]));
      Rs[i] = Eigen::Map<Eigen::Matrix<T, 3, 3>>(&(r_data[9 * i]));
    }
  }
  void vSolve(Eigen::Matrix<T, 3, 4> &points_3d,
              Eigen::Matrix<T, 2, 4> &points_2d, int *n, T *fs,
              Eigen::Matrix<T, 3, 3> *Rs, Eigen::Matrix<T, 3, 1> *Cs, T diag) {
    dataEigenToMatlab(points_3d, points_2d, diag);
    static_cast<MatlabSolverClass *>(this)->vMatlabSolve();
    dataMatlabToEigen(n, fs, Rs, Cs, diag);
  }
};

template <class T> class P35PSolver : public MatlabSolver<P35PSolver<T>, T> {
public:
  void vMatlabSolve(){};
};

template <>
class P35PSolver<float> : public MatlabSolver<P35PSolver<float>, float> {
public:
  void vMatlabSolve() {
    p35pf_single(X, xy, e, &sol_num, f_data, f_size, r_data, r_size, t_data,
                 t_size);
  };
};

template <>
class P35PSolver<double> : public MatlabSolver<P35PSolver<double>, double> {
public:
  void vMatlabSolve() {
    p35pf_double(X, xy, e, &sol_num, f_data, f_size, r_data, r_size, t_data,
                 t_size);
  };
};

template <class T> class P4PSolver : public MatlabSolver<P4PSolver<T>, T> {
public:
  void vMatlabSolve(){};
};

template <>
class P4PSolver<float> : public MatlabSolver<P4PSolver<float>, float> {
public:
  void vMatlabSolve() {
    p4pf_single(X, xy, e, &sol_num, f_data, f_size, r_data, r_size, t_data,
                t_size);
  };
};

template <>
class P4PSolver<double> : public MatlabSolver<P4PSolver<double>, double> {
public:
  void vMatlabSolve() {
    p4pf_double(X, xy, e, &sol_num, f_data, f_size, r_data, r_size, t_data,
                t_size);
  };
};

#endif // PNP_TEST_SOLVERS_H