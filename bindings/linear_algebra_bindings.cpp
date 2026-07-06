#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "vecta/linear_algebra/vector.hpp"

namespace py = pybind11;

void bind_linear_algebra(py::module_ &m) {
    m.doc() = "Chapter 2: Linear Algebra";

    py::class_<vecta::linear_algebra::Vector>(m, "Vector")
        .def(py::init<std::size_t, double>(), py::arg("size"), py::arg("fill") = 0.0)
        .def(py::init<std::vector<double>>(), py::arg("values"))
        .def("__len__", &vecta::linear_algebra::Vector::size)
        .def("__getitem__", [](const vecta::linear_algebra::Vector& v, std::size_t i) { return v[i]; })
        .def("__setitem__", [](vecta::linear_algebra::Vector& v, std::size_t i, double val) { v[i] = val; })
        .def("__add__", &vecta::linear_algebra::Vector::operator+)
        .def("__sub__", &vecta::linear_algebra::Vector::operator-)
        .def("dot", &vecta::linear_algebra::Vector::dot)
        .def("norm", &vecta::linear_algebra::Vector::norm)
        .def("to_list", &vecta::linear_algebra::Vector::raw)
        .def("__repr__", [](const vecta::linear_algebra::Vector& v) {
            std::string s = "Vector([";
            for (std::size_t i = 0; i < v.size(); ++i) {
                s += std::to_string(v[i]);
                if (i + 1 < v.size()) s += ", ";
            }
            s += "])";
            return s;
        });
}
