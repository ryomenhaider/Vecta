cmake_minimum_required(VERSION 3.15)
project(vecta)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Header-only core: no .cpp files exist for this yet, so this must be
# an INTERFACE library, not a compiled add_library().
add_library(vecta_core INTERFACE)
target_include_directories(vecta_core INTERFACE include)

include(FetchContent)
FetchContent_Declare(
  pybind11
  GIT_REPOSITORY https://github.com/pybind/pybind11.git
  GIT_TAG v2.13.6
)
FetchContent_MakeAvailable(pybind11)

pybind11_add_module(_vecta src/bindings.cpp)
target_link_libraries(_vecta PRIVATE vecta_core)
target_include_directories(_vecta PRIVATE include)
