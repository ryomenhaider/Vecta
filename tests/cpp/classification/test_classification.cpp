#include <catch2/catch_test_macros.hpp>
#include "vecta/classification/classification.hpp"

// Smoke test only -- replace with real tests once you implement this chapter.
TEST_CASE("Classification (SVM) module compiles and links", "[classification][smoke]") {
    REQUIRE(vecta::classification::placeholder() == 0);
}
