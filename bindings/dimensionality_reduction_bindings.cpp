#include <pybind11/pybind11.h>
#include "vecta/dimensionality_reduction/dimensionality_reduction.hpp"

namespace py = pybind11;

void bind_dimensionality_reduction(py::module_ &m) {
    m.doc() = "Dimensionality Reduction (PCA) -- Chapter 10: maximum-variance and projection perspectives of PCA, eigenvector computation for high-dimensional data";
    m.def("placeholder", &vecta::dimensionality_reduction::placeholder,
          "Temporary placeholder -- replace once you implement this chapter's content.");
}
