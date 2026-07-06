#include <catch2/catch_test_macros.hpp>
#include "vecta/linear_regression/linear_regression.hpp"

// Smoke test only -- replace with real tests once you implement this chapter.
TEST_CASE("Linear Regression module compiles and links", "[linear_regression][smoke]") {
    REQUIRE(vecta::linear_regression::placeholder() == 0);
}
