#pragma once

#include <vector>
#include <cstddef>


namespace vecta::linalg {
    template <typename T>
    class Matrix {
    public:
        Matrix(std::size_t rows, std::size_t cols, T init = 0.0);

        std::size_t rows() const;
        std::size_t cols() const;

        T& operator()(std::size_t i, std::size_t j);
        T operator()(std::size_t i, std::size_t j) const;

    private:
        std::size_t rows_, cols_;
        std::vector<T> data_;
    };
}
