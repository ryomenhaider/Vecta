#include <pybind11/pybind11.h>
#include "vecta/matrix_decompositions/matrix_decompositions.hpp"

namespace py = pybind11;

void bind_matrix_decompositions(py::module_ &m) {
    m.doc() = "Matrix Decompositions -- Chapter 4: determinant, trace, eigenvalues and eigenvectors, Cholesky decomposition, eigendecomposition, SVD";
    m.def("placeholder", &vecta::matrix_decompositions::placeholder,
          "Temporary placeholder -- replace once you implement this chapter's content.");
}
