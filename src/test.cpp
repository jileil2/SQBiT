// [[Rcpp::depends(RcppArmadillo, RcppEigen)]]
#include <RcppArmadillo.h>
#include <RcppEigen.h>
#include <algorithm>
#include <vector>

using namespace Rcpp;
using namespace arma;

// [[Rcpp::export]]
Eigen::MatrixXd cppkp(Eigen::Map<Eigen::MatrixXd> a, Eigen::Map<Eigen::MatrixXd> b) {
  return kroneckerProduct(a, b);
}

// [[Rcpp::export]]
SEXP eigenMatMult(Eigen::MatrixXd A, Eigen::MatrixXd B) {
  Eigen::MatrixXd C = A * B;
  return Rcpp::wrap(C);
}

// [[Rcpp::export]]
SEXP eigenMapMatMult(const Eigen::Map<Eigen::MatrixXd> A, Eigen::Map<Eigen::MatrixXd> B) {
  Eigen::MatrixXd C = A * B;
  return Rcpp::wrap(C);
}

// [[Rcpp::export]]
SEXP eigenMapMatMult2(const Eigen::Map<Eigen::MatrixXd> A,
                      Eigen::Map<Eigen::MatrixXd> B,
                      int n_cores) {
  Eigen::setNbThreads(n_cores);
  Eigen::MatrixXd C = A * B;
  return Rcpp::wrap(C);
}

// [[Rcpp::export]]
double neg(double x) {
  return x < 0 ? 1 : 0;
}

// [[Rcpp::export]]
double sum_cpp(NumericVector x) {
  double result = 0;
  for (int i = 0; i < x.size(); i++) {
    result += x[i];
  }
  return result;
}

// [[Rcpp::export]]
double sum_rhotau(NumericVector x, const double tau) {
  double result = 0;
  for (int i = 0; i < x.size(); i++) {
    result += x[i] * (tau - neg(x[i]));
  }
  return result;
}

// [[Rcpp::export]]
arma::mat arma_dist(const arma::mat& X) {
  int n = X.n_rows;
  arma::mat D(n, n, arma::fill::zeros);
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < i; k++) {
      D(i, k) = sqrt(arma::sum(arma::pow(X.row(i) - X.row(k), 2)));
      D(k, i) = D(i, k);
    }
  }
  return D;
}
