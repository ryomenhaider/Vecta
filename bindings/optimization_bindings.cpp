#include <pybind11/pybind11.h>
#include "vecta/optimization/optimization.hpp"

namespace py = pybind11;

void bind_optimization(py::module_ &m) {
    m.doc() = "Continuous Optimization -- Chapter 7: gradient descent, momentum, stochastic gradient descent, constrained optimization, Lagrange multipliers, convex optimization";
    m.def("placeholder", &vecta::optimization::placeholder,
          "Temporary placeholder -- replace once you implement this chapter's content.");
}
