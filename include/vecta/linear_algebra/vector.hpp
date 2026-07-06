#pragma once
#include <vector>
#include <stdexcept>
#include <cstddef>
#include <cmath>

// Chapter 2: Linear Algebra — vectors, matrices, spans, basis, rank, linear mappings.
// This Vector class is the seed. Add Matrix, span/basis/rank helpers, and linear
// mapping utilities here as you work through the chapter.
namespace vecta::linear_algebra {

class Vector {
public:
    explicit Vector(std::size_t size, double fill = 0.0)
        : data_(size, fill) {}

    explicit Vector(std::vector<double> values)
        : data_(std::move(values)) {}

    std::size_t size() const { return data_.size(); }

    double& operator[](std::size_t i) { return data_.at(i); }
    double operator[](std::size_t i) const { return data_.at(i); }

    Vector operator+(const Vector& other) const {
        check_same_size(other);
        Vector result(size());
        for (std::size_t i = 0; i < size(); ++i) {
            result[i] = data_[i] + other[i];
        }
        return result;
    }

    Vector operator-(const Vector& other) const {
        check_same_size(other);
        Vector result(size());
        for (std::size_t i = 0; i < size(); ++i) {
            result[i] = data_[i] - other[i];
        }
        return result;
    }

    double dot(const Vector& other) const {
        check_same_size(other);
        double sum = 0.0;
        for (std::size_t i = 0; i < size(); ++i) {
            sum += data_[i] * other[i];
        }
        return sum;
    }

    // Euclidean (L2) norm.
    double norm() const {
        double sum_sq = 0.0;
        for (double v : data_) {
            sum_sq += v * v;
        }
        return std::sqrt(sum_sq);
    }

    const std::vector<double>& raw() const { return data_; }

private:
    void check_same_size(const Vector& other) const {
        if (other.size() != size()) {
            throw std::invalid_argument("Vector size mismatch");
        }
    }

    std::vector<double> data_;
};

} // namespace vecta::linear_algebra
