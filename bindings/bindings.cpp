#include "bindings.hpp"

PYBIND11_MODULE(_vecta, m) {
    m.doc() = "Vecta: computational maths library following Mathematics for Machine Learning";

    auto linear_algebra = m.def_submodule("linear_algebra", "Chapter 2: Linear Algebra");
    bind_linear_algebra(linear_algebra);

    auto analytic_geometry = m.def_submodule("analytic_geometry", "Analytic Geometry");
    bind_analytic_geometry(analytic_geometry);

    auto matrix_decompositions = m.def_submodule("matrix_decompositions", "Matrix Decompositions");
    bind_matrix_decompositions(matrix_decompositions);

    auto vector_calculus = m.def_submodule("vector_calculus", "Vector Calculus");
    bind_vector_calculus(vector_calculus);

    auto probability = m.def_submodule("probability", "Probability and Distributions");
    bind_probability(probability);

    auto optimization = m.def_submodule("optimization", "Continuous Optimization");
    bind_optimization(optimization);

    auto linear_regression = m.def_submodule("linear_regression", "Linear Regression");
    bind_linear_regression(linear_regression);

    auto dimensionality_reduction = m.def_submodule("dimensionality_reduction", "Dimensionality Reduction (PCA)");
    bind_dimensionality_reduction(dimensionality_reduction);

    auto density_estimation = m.def_submodule("density_estimation", "Density Estimation (GMM)");
    bind_density_estimation(density_estimation);

    auto classification = m.def_submodule("classification", "Classification (SVM)");
    bind_classification(classification);

}
