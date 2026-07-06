#include <pybind11/pybind11.h>
#include "vecta/analytic_geometry/analytic_geometry.hpp"

namespace py = pybind11;

void bind_analytic_geometry(py::module_ &m) {
    m.doc() = "Analytic Geometry -- Chapter 3: norms, inner products, orthogonality, projections, rotations";
    m.def("placeholder", &vecta::analytic_geometry::placeholder,
          "Temporary placeholder -- replace once you implement this chapter's content.");
}
