#pragma once

#include <vector>
#include <cstddef>

namespace vecta::linalg {

    template <typename T>
    class Matrix {
    public:
        Matrix(std::size_t rows, std::size_t cols, T init = T(0))
            : rows_(rows), cols_(cols), data_(rows * cols, init) {}

        std::size_t rows() const { return rows_; }
        std::size_t cols() const { return cols_; }

        T& operator()(std::size_t i, std::size_t j) {
            return data_[i * cols_ + j];
        }

        T operator()(std::size_t i, std::size_t j) const {
            return data_[i * cols_ + j];
        }

    private:
        std::size_t rows_, cols_;
        std::vector<T> data_;
    };

}
