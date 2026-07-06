cmake_minimum_required(VERSION 3.15)
project(vecta LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

# Tests are only built for a normal dev `cmake` build.
# They're skipped automatically when scikit-build-core builds the wheel (SKBUILD is set).
option(VECTA_BUILD_TESTS "Build C++ unit tests (Catch2)" ON)
if(DEFINED SKBUILD)
    set(VECTA_BUILD_TESTS OFF)
endif()

find_package(pybind11 CONFIG REQUIRED)

# --- Core C++ library: one .cpp per chapter under src/<chapter>/ ---
# CONFIGURE_DEPENDS re-globs on build with Ninja/Makefiles, so new files
# under src/ are usually picked up without manually re-running cmake.
file(GLOB_RECURSE VECTA_CORE_SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")
add_library(vecta_core STATIC ${VECTA_CORE_SOURCES})
target_include_directories(vecta_core PUBLIC include)
target_compile_options(vecta_core PRIVATE -Wall -Wextra)

# --- Python extension module: main bindings.cpp + one *_bindings.cpp per chapter ---
file(GLOB_RECURSE VECTA_BINDING_SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/bindings/*.cpp")
pybind11_add_module(_vecta ${VECTA_BINDING_SOURCES})
target_link_libraries(_vecta PRIVATE vecta_core)
target_include_directories(_vecta PRIVATE bindings)

install(TARGETS _vecta DESTINATION vecta)

# --- C++ unit tests (Catch2, fetched automatically) ---
if(VECTA_BUILD_TESTS)
    include(FetchContent)
    FetchContent_Declare(
        catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.5.4
    )
    FetchContent_MakeAvailable(catch2)

    file(GLOB_RECURSE VECTA_TEST_SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/tests/cpp/*.cpp")
    add_executable(vecta_tests ${VECTA_TEST_SOURCES})
    target_link_libraries(vecta_tests PRIVATE vecta_core Catch2::Catch2WithMain)

    enable_testing()
    add_test(NAME vecta_cpp_tests COMMAND vecta_tests)
endif()
