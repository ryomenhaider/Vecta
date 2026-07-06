#include <catch2/catch_test_macros.hpp>
#include "vecta/optimization/optimization.hpp"

// Smoke test only -- replace with real tests once you implement this chapter.
TEST_CASE("Continuous Optimization module compiles and links", "[optimization][smoke]") {
    REQUIRE(vecta::optimization::placeholder() == 0);
}
