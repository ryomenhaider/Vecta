#include <catch2/catch_test_macros.hpp>
#include "vecta/matrix_decompositions/matrix_decompositions.hpp"

// Smoke test only -- replace with real tests once you implement this chapter.
TEST_CASE("Matrix Decompositions module compiles and links", "[matrix_decompositions][smoke]") {
    REQUIRE(vecta::matrix_decompositions::placeholder() == 0);
}
