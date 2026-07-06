#include <catch2/catch_test_macros.hpp>
#include "vecta/density_estimation/density_estimation.hpp"

// Smoke test only -- replace with real tests once you implement this chapter.
TEST_CASE("Density Estimation (GMM) module compiles and links", "[density_estimation][smoke]") {
    REQUIRE(vecta::density_estimation::placeholder() == 0);
}
