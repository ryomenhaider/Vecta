#include <pybind11/pybind11.h>
#include "vecta/linear_regression/linear_regression.hpp"

namespace py = pybind11;

void bind_linear_regression(py::module_ &m) {
    m.doc() = "Linear Regression -- Chapter 9: parameter estimation, maximum likelihood estimation, overfitting, MAP estimation, Bayesian linear regression";
    m.def("placeholder", &vecta::linear_regression::placeholder,
          "Temporary placeholder -- replace once you implement this chapter's content.");
}
