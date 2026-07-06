#include <pybind11/pybind11.h>
#include "vecta/vector_calculus/vector_calculus.hpp"

namespace py = pybind11;

void bind_vector_calculus(py::module_ &m) {
    m.doc() = "Vector Calculus -- Chapter 5: differentiation rules, partial derivatives and gradients, Jacobian, Hessian, linearization, Taylor series";
    m.def("placeholder", &vecta::vector_calculus::placeholder,
          "Temporary placeholder -- replace once you implement this chapter's content.");
}
