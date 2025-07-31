#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]
using namespace Rcpp;
using arma::mat;

// [[Rcpp::export]]
arma::mat armaInv(const arma::mat& x) {
  return arma::inv(x);
}
