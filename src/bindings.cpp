#include <pybind11/pybind11.h>
#include "vecta/linalg/core.hpp"
#include "vecta/linalg/matrix.hpp"

namespace py = pybind11;
using namespace vecta::linalg;

PYBIND11_MODULE(_vecta, m) {
    m.doc() = "Vecta computational math library";

    py::class_<Matrix>(m, "Matrix")
        .def(py::init<std::size_t, std::size_t, double>(),
             py::arg("rows"), py::arg("cols"), py::arg("init") = 0.0)
        .def("rows", &Matrix::rows)
        .def("cols", &Matrix::cols)
        .def("__getitem__", [](const Matrix& m, std::pair<std::size_t, std::size_t> idx) {
            return m(idx.first, idx.second);
        })
        .def("__setitem__", [](Matrix& m, std::pair<std::size_t, std::size_t> idx, double val) {
            m(idx.first, idx.second) = val;
        });

    m.def("matmul", &matmul);
    m.def("add", &add);
    m.def("scalar_mul", &scalar_mul);
    m.def("transpose", &transpose);
    m.def("identity", &identity);
    m.def("is_symmetric", &is_symmetric, py::arg("A"), py::arg("tol") = 1e-9);
}