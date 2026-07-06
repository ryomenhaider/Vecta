#include <catch2/catch_test_macros.hpp>
#include "vecta/dimensionality_reduction/dimensionality_reduction.hpp"

// Smoke test only -- replace with real tests once you implement this chapter.
TEST_CASE("Dimensionality Reduction (PCA) module compiles and links", "[dimensionality_reduction][smoke]") {
    REQUIRE(vecta::dimensionality_reduction::placeholder() == 0);
}
