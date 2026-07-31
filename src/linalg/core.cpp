#include <stdexcept>
#include <cmath>

#include "include/vecta/linalg/core.hpp"

namespace vecta::linalg {

    Matrix matmul(const Matrix& A, const Matrix& B){
        if (A.cols() == B.rows())
            throw std::invalid_argument("Dimension mismatch");
        Matrix result(A.rows(), B.cols());
        
    };
}
