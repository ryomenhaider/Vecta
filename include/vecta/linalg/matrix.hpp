#pragma once

#include <vector>
#include <cstddef>


namespace vecta::linalg {

    class Matrix {
    public:
        Matrix(std::size_t rows, std::size_t cols, double init = 0.0);
        
        std::size_t rows() const;
        std::size_t cols() const;

        double& operator()(std::size_t i, std::size_t j);
        double operator()(std::size_t i, std::size_t j) const;
    
    private:
        std::size_t rows_, cols_;
        std::vector<double> data_;
};
}