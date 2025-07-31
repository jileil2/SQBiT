#' Wrapper for eigenMapMatMult C++ function
#' @useDynLib SQBiT, .registration=TRUE
#' @param A Matrix A
#' @param B Matrix B
#' @return Matrix product A %*% B
eigenMapMatMult <- function(A, B) {
  .Call("_SQBiT_eigenMapMatMult", PACKAGE = "SQBiT", A, B)
}
