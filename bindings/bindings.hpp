#pragma once
#include <pybind11/pybind11.h>

void bind_linear_algebra(pybind11::module_ &m);
void bind_analytic_geometry(pybind11::module_ &m);
void bind_matrix_decompositions(pybind11::module_ &m);
void bind_vector_calculus(pybind11::module_ &m);
void bind_probability(pybind11::module_ &m);
void bind_optimization(pybind11::module_ &m);
void bind_linear_regression(pybind11::module_ &m);
void bind_dimensionality_reduction(pybind11::module_ &m);
void bind_density_estimation(pybind11::module_ &m);
void bind_classification(pybind11::module_ &m);
