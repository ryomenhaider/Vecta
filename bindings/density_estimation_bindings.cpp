#include <pybind11/pybind11.h>
#include "vecta/density_estimation/density_estimation.hpp"

namespace py = pybind11;

void bind_density_estimation(py::module_ &m) {
    m.doc() = "Density Estimation (GMM) -- Chapter 11: Gaussian mixture models, parameter learning via the EM algorithm";
    m.def("placeholder", &vecta::density_estimation::placeholder,
          "Temporary placeholder -- replace once you implement this chapter's content.");
}
