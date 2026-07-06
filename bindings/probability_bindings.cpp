#include <pybind11/pybind11.h>
#include "vecta/probability/probability.hpp"

namespace py = pybind11;

void bind_probability(py::module_ &m) {
    m.doc() = "Probability and Distributions -- Chapter 6: random variables, sum and product rules, Bayes' theorem, Gaussian distribution, conjugacy, exponential family";
    m.def("placeholder", &vecta::probability::placeholder,
          "Temporary placeholder -- replace once you implement this chapter's content.");
}
