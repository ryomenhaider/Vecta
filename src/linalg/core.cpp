#include "vecta/linalg/core.hpp"
#include <stdexcept>
#include <cmath>

namespace vecta::linalg {

Matrix matmul(const Matrix& A, const Matrix& B) {
    if (A.cols() != B.rows())
        throw std::invalid_argument("matmul: dimension mismatch");

    Matrix result(A.rows(), B.cols());
    for (std::size_t i = 0; i < A.rows(); ++i)
        for (std::size_t j = 0; j < B.cols(); ++j) {
            double sum = 0.0;
            for (std::size_t k = 0; k < A.cols(); ++k)
                sum += A(i, k) * B(k, j);
            result(i, j) = sum;
        }
    return result;
}

Matrix add(const Matrix& A, const Matrix& B) {
    if (A.rows() != B.rows() || A.cols() != B.cols())
        throw std::invalid_argument("add: dimension mismatch");

    Matrix result(A.rows(), A.cols());
    for (std::size_t i = 0; i < A.rows(); ++i)
        for (std::size_t j = 0; j < A.cols(); ++j)
            result(i, j) = A(i, j) + B(i, j);
    return result;
}

Matrix scalar_mul(const Matrix& A, double k) {
    Matrix result(A.rows(), A.cols());
    for (std::size_t i = 0; i < A.rows(); ++i)
        for (std::size_t j = 0; j < A.cols(); ++j)
            result(i, j) = A(i, j) * k;
    return result;
}

Matrix transpose(const Matrix& A) {
    Matrix result(A.cols(), A.rows());
    for (std::size_t i = 0; i < A.rows(); ++i)
        for (std::size_t j = 0; j < A.cols(); ++j)
            result(j, i) = A(i, j);
    return result;
}

Matrix identity(std::size_t n) {
    Matrix result(n, n, 0.0);
    for (std::size_t i = 0; i < n; ++i)
        result(i, i) = 1.0;
    return result;
}

bool is_symmetric(const Matrix& A, double tol) {
    if (A.rows() != A.cols()) return false;
    for (std::size_t i = 0; i < A.rows(); ++i)
        for (std::size_t j = i + 1; j < A.cols(); ++j)
            if (std::abs(A(i, j) - A(j, i)) > tol)
                return false;
    return true;
}

} // namespace vecta::linear_algebra
