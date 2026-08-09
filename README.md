# Vecta

A computational maths library for ML, built from scratch in C++ with Python bindings.
The long-term goal is to work chapter-by-chapter through *Mathematics for Machine
Learning* (Deisenroth, Faisal, Ong), implementing every concept myself instead of
reaching for a library.

## Current state

The linear-algebra core is up and running as a header-only C++ template library,
exposed to Python through a single pybind11 module:

- `Matrix<T>` — row-major dense matrix with `(i, j)` access
- `matmul`, `add`, `scalar_mul` — arithmetic (with dimension checking)
- `transpose`, `identity`, `is_symmetric`

C++ and Python test suites are planned but not written yet.

## Stack

- C++17 header-only core (no external maths dependencies — everything implemented from scratch)
- [pybind11](https://github.com/pybind/pybind11) for Python bindings (fetched via CMake `FetchContent`)
- [scikit-build-core](https://github.com/scikit-build/scikit-build-core) + CMake for packaging
- [uv](https://docs.astral.sh/uv/) for the Python venv and all package installs (no pip commands)

## Layout

```
include/vecta/linalg/        C++ headers (header-only core)
    matrix.hpp               Matrix<T> class
    ops.hpp                  matmul, add, scalar_mul, transpose, identity, is_symmetric
src/bindings.cpp             pybind11 binding code (module `_vecta`)
python/vecta/                Python package wrapper (imports `_vecta`)
examples/                    scratch space for worked examples from the book
tests/cpp/                   Catch2 tests (planned)
tests/python/                pytest tests (planned)
```

## Dev workflow (uv-based, no pip)

Create the venv and install the package in editable mode:
```bash
uv venv
source .venv/bin/activate
uv pip install -e . --no-build-isolation
```

Rebuild + reinstall the Python module after changing C++ code:
```bash
uv pip install -e . --no-build-isolation
```

Try it from Python:
```python
from vecta import _vecta as v

A = v.Matrix(2, 2)
A.set(0, 0, 1); A.set(1, 1, 1)
print(v.matmul(A, v.identity(2)))
print(v.is_symmetric(A))
```

## Roadmap

Follow the book chapter by chapter, folding each topic into `include/vecta/<chapter>/`,
`src/bindings.cpp`, and `python/vecta/`:

| Topic                          | Book chapter                          | Status              |
|--------------------------------|----------------------------------------|---------------------|
| Linear Algebra                 | Ch 2 — Linear Algebra                 | Matrix + core ops   |
| Analytic Geometry              | Ch 3 — Analytic Geometry              | not started         |
| Matrix Decompositions          | Ch 4 — Matrix Decompositions          | not started         |
| Vector Calculus                | Ch 5 — Vector Calculus                | not started         |
| Probability and Distributions  | Ch 6 — Probability and Distributions  | not started         |
| Continuous Optimization        | Ch 7 — Continuous Optimization        | not started         |
| Linear Regression              | Ch 9 — Linear Regression              | not started         |
| Dimensionality Reduction (PCA) | Ch 10 — Dimensionality Reduction      | not started         |
| Density Estimation (GMM)       | Ch 11 — Density Estimation            | not started         |
| Classification (SVM)           | Ch 12 — Classification                | not started         |
