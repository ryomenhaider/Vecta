#include <catch2/catch_test_macros.hpp>
#include "vecta/vector_calculus/vector_calculus.hpp"

// Smoke test only -- replace with real tests once you implement this chapter.
TEST_CASE("Vector Calculus module compiles and links", "[vector_calculus][smoke]") {
    REQUIRE(vecta::vector_calculus::placeholder() == 0);
}
