#include "vecta/linalg/matrix.hpp"

#include <vector>
#include <cstddef>

namespace vecta::linalg {

    Matrix::Matrix(std::size_t rows, std::size_t cols, double init)
        : rows_(rows), cols_(cols), data_(rows * cols, init) {}
    
    std::size_t Matrix::rows() const { return rows_; }
    std::size_t Matrix::cols() const { return cols_; }

    double& Matrix::operator()(std::size_t i, std::size_t j) {
        return data_[i * cols_ + j];
    };

    double Matrix::operator()(std::size_t i, std::size_t j) const {
            return data_[i * cols_ + j];
    };
}