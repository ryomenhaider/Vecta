#include <pybind11/pybind11.h>
#include "vecta/classification/classification.hpp"

namespace py = pybind11;

void bind_classification(py::module_ &m) {
    m.doc() = "Classification (SVM) -- Chapter 12: separating hyperplanes, primal and dual support vector machines, kernels";
    m.def("placeholder", &vecta::classification::placeholder,
          "Temporary placeholder -- replace once you implement this chapter's content.");
}
