#include "vecta/linalg/core.hpp"
#include <stdexcept>
#include <cmath>

namespace vecta::linalg {

    Matrix matmul(const Matrix& A, const Matrix& B){
        if (A.cols() != B.rows()){
            throw std::invalid_argument("matmul: dimenstion mismatch");
        };

        Matrix result(A.rows(), B.cols());
    };
}