#include <catch2/catch_test_macros.hpp>
#include "vecta/linear_algebra/vector.hpp"

TEST_CASE("Vector addition", "[linear_algebra]") {
    vecta::linear_algebra::Vector a({1.0, 2.0, 3.0});
    vecta::linear_algebra::Vector b({4.0, 5.0, 6.0});
    vecta::linear_algebra::Vector c = a + b;
    REQUIRE(c[0] == 5.0);
    REQUIRE(c[1] == 7.0);
    REQUIRE(c[2] == 9.0);
}

TEST_CASE("Vector dot product", "[linear_algebra]") {
    vecta::linear_algebra::Vector a({1.0, 2.0, 3.0});
    vecta::linear_algebra::Vector b({4.0, 5.0, 6.0});
    REQUIRE(a.dot(b) == 32.0);
}

TEST_CASE("Vector norm", "[linear_algebra]") {
    vecta::linear_algebra::Vector a({3.0, 4.0});
    REQUIRE(a.norm() == 5.0);
}
