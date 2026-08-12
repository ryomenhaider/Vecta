#include <pybind11/pybind11.h>
#include <pybind11/operators.h>
#include "vecta/linalg/matrix.hpp"
#include "vecta/linalg/core.hpp"

namespace py = pybind11;
using namespace vecta::linalg;

PYBIND11_MODULE(_vecta, m) {
    m.doc() = "vecta C++ core bindings";

    py::class_<Matrix<double>>(m, "Matrix")
        .def(py::init<std::size_t, std::size_t, double>(),
             py::arg("rows"), py::arg("cols"), py::arg("init") = 0.0)
        .def("rows", &Matrix<double>::rows)
        .def("cols", &Matrix<double>::cols)
        .def("__call__",
             [](const Matrix<double>& self, std::size_t i, std::size_t j) {
                 return self(i, j);
             })
        .def("set",
             [](Matrix<double>& self, std::size_t i, std::size_t j, double v) {
                 self(i, j) = v;
             })
        .def("__repr__", [](const Matrix<double>& self) {
            return "<vecta.Matrix " + std::to_string(self.rows()) + "x"
                 + std::to_string(self.cols()) + ">";
        });

    m.def("matmul", &matmul<double>, "Matrix multiplication");
    m.def("add", &add<double>, "Elementwise matrix addition");
    m.def("scalar_mul", &scalar_mul<double>, "Scalar multiplication");
    m.def("transpose", &transpose<double>, "Matrix transpose");
    m.def("identity", &identity<double>, "Identity matrix");
    m.def("is_symmetric", &is_symmetric<double>, "Check symmetry");
}
