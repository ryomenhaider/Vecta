#include <catch2/catch_test_macros.hpp>
#include "vecta/analytic_geometry/analytic_geometry.hpp"

// Smoke test only -- replace with real tests once you implement this chapter.
TEST_CASE("Analytic Geometry module compiles and links", "[analytic_geometry][smoke]") {
    REQUIRE(vecta::analytic_geometry::placeholder() == 0);
}
