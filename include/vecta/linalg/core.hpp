#pragma once

#include <vector>
#include <cstddef>
#include <stdexcept>
#include "vecta/linalg/matrix.hpp"

namespace vecta::linalg {

    template <typename T>
    Matrix<T> matmul(const Matrix<T>& A, const Matrix<T>& B){
        if (A.cols() != B.rows()){
            throw std::invalid_argument("Dimension mismatch");
        }
        Matrix<T> result(A.rows(), B.cols());
        for (std::size_t i = 0; i < A.rows(); i++){
            for (std::size_t j = 0; j < B.cols(); j++){
                for (std::size_t k = 0; k < A.cols(); k++){
                    result(i, j) += A(i, k) * B(k, j);
                }
            }
        }
        return result;
    }

    template <typename T>
    Matrix<T> add(const Matrix<T>& A, const Matrix<T>& B){
        if (A.rows() != B.rows() || A.cols() != B.cols()){
            throw std::invalid_argument("Order mismatch");
        }
        Matrix<T> result(A.rows(), A.cols());
        for (std::size_t i = 0; i < A.rows(); i++){
            for (std::size_t j = 0; j < A.cols(); j++){
                result(i, j) = A(i, j) + B(i, j);
            }
        }
        return result;
    }

    template <typename T>
    Matrix<T> scalar_mul(const Matrix<T>& A, double k){
        Matrix<T> result(A.rows(), A.cols());
        for (std::size_t i = 0; i < A.rows(); i++){
            for (std::size_t j = 0; j < A.cols(); j++){
                result(i, j) = A(i, j) * k;
            }
        }
        return result;
    }

    template <typename T>
    Matrix<T> transpose(const Matrix<T>& A){
        Matrix<T> result(A.cols(), A.rows());
        for (std::size_t i = 0; i < A.rows(); i++){
            for (std::size_t j = 0; j < A.cols(); j++){
                result(j, i) = A(i, j);
            }
        }
        return result;
    }

    template <typename T>
    Matrix<T> identity(std::size_t n){
        Matrix<T> result(n, n, T(0));
        for (std::size_t i = 0; i < n; i++){
            result(i, i) = T(1);
        }
        return result;
    }

    template <typename T>
    bool is_symmetric(const Matrix<T>& A){
        if (A.rows() != A.cols()){
            return false;
        }
        for (std::size_t i = 0; i < A.rows(); i++){
            for (std::size_t j = 0; j < A.cols(); j++){
                if (A(i, j) != A(j, i)){
                    return false;
                }
            }
        }
        return true;
    }

}
