# Vecta

A computational maths library for ML, built from scratch in C++ with Python bindings,
structured chapter-by-chapter after *Mathematics for Machine Learning* (Deisenroth, Faisal, Ong).

## Stack
- C++17 core (no external maths dependencies — everything implemented from scratch)
- [pybind11](https://github.com/pybind/pybind11) for Python bindings
- [scikit-build-core](https://github.com/scikit-build/scikit-build-core) + CMake for packaging
- [uv](https://docs.astral.sh/uv/) for the Python venv and all package installs (no pip commands)
- [Catch2](https://github.com/catchorg/Catch2) for C++ unit tests
- [pytest](https://docs.pytest.org/) for Python-level tests

## Layout

Each chapter gets matching folders across headers, sources, bindings, the Python
package, and both test suites:

```
include/vecta/<chapter>/      C++ headers
src/<chapter>/                C++ implementation
bindings/<chapter>_bindings.cpp   pybind11 binding code for that chapter
python/vecta/<chapter>/       Python package wrapper
tests/cpp/<chapter>/          Catch2 tests
tests/python/<chapter>/       pytest tests
```

Chapters (folder name → book chapter):

| Folder                      | Book chapter                                   | Status              |
|-----------------------------|-------------------------------------------------|---------------------|
| `linear_algebra`            | Ch 2 — Linear Algebra                          | Vector implemented  |
| `analytic_geometry`         | Ch 3 — Analytic Geometry                       | stub                |
| `matrix_decompositions`     | Ch 4 — Matrix Decompositions                   | stub                |
| `vector_calculus`           | Ch 5 — Vector Calculus                         | stub                |
| `probability`               | Ch 6 — Probability and Distributions           | stub                |
| `optimization`               | Ch 7 — Continuous Optimization                 | stub                |
| `linear_regression`         | Ch 9 — Linear Regression                       | stub                |
| `dimensionality_reduction`  | Ch 10 — Dimensionality Reduction (PCA)         | stub                |
| `density_estimation`        | Ch 11 — Density Estimation (GMM)               | stub                |
| `classification`            | Ch 12 — Classification (SVM)                   | stub                |

"stub" means: it compiles, links, imports from Python, and has a smoke test —
so the whole pipeline stays green as you go. Replace `placeholder()` with real
content in the header/source/bindings/tests for a chapter as you study it.

`examples/` is free scratch space for worked examples from the book.

## Adding real content to a stub chapter

1. Write the real implementation in `include/vecta/<chapter>/<chapter>.hpp` (and `.cpp` if needed).
2. Expose it to Python in `bindings/<chapter>_bindings.cpp`.
3. Delete the `placeholder()` smoke tests in `tests/cpp/<chapter>/` and `tests/python/<chapter>/`,
   replacing them with real tests.
4. CMake picks up new `.cpp` files automatically on the next build (globbing with
   `CONFIGURE_DEPENDS`) — no need to edit `CMakeLists.txt`.

## Dev workflow (uv-based, no pip)

Activate the venv created by setup_vecta.sh:
```bash
source .venv/bin/activate
```

Rebuild + reinstall the Python module after changing C++ code:
```bash
uv pip install -e . --no-build-isolation
```

Run Python tests:
```bash
pytest
```

Run C++ tests (separate dev build, not part of the Python wheel).
A plain `cmake` invocation doesn't automatically know where pybind11's CMake
config lives the way `pip`/`uv pip install` does, so point it there explicitly:
```bash
PYBIND11_CMAKE_DIR=$(python -c "import pybind11; print(pybind11.get_cmake_dir())")
cmake -S . -B build-tests -DVECTA_BUILD_TESTS=ON -DCMAKE_PREFIX_PATH="$PYBIND11_CMAKE_DIR"
cmake --build build-tests
ctest --test-dir build-tests --output-on-failure
```
