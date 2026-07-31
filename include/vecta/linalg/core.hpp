#pragma once

#include <vector>
#include <cstddef>

#include "vecta/linalg/matrix.hpp"

namespace vecta::linalg {
    Matrix matmul(const Matrix& A, const Matrix& B);    
    Matrix add(const Matrix& A, const Matrix& B);
    Matrix scalar_mul(const Matrix& A, double k);
    Matrix transpose(const Matrix& A);
    Matrix identity(std::size_t n);
    bool is_symmetric(const Matrix& A, double tol = 1e-9);
}
