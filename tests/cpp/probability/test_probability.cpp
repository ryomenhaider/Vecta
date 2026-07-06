#include <catch2/catch_test_macros.hpp>
#include "vecta/probability/probability.hpp"

// Smoke test only -- replace with real tests once you implement this chapter.
TEST_CASE("Probability and Distributions module compiles and links", "[probability][smoke]") {
    REQUIRE(vecta::probability::placeholder() == 0);
}
