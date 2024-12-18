#include <catch2/catch.hpp>
#include "Point.h"
#include <cmath>

TEST_CASE("Point constructor", "[Point]") {
    SECTION("Initialize point with positive coordinates") {
        Point p(3.0, 4.0);

        // Verify the x and y coordinates are set correctly
        REQUIRE(p.distanceTo(Point(0.0, 0.0)) == Approx(5.0).epsilon(0.001));  // Expect the distance to be 5 (3-4-5 triangle)
    }

    SECTION("Initialize point with negative coordinates") {
        Point p(-3.0, -4.0);

        // Verify the distance from origin is still correct
        REQUIRE(p.distanceTo(Point(0.0, 0.0)) == Approx(5.0).epsilon(0.001));  // Distance should be the same as above
    }

    SECTION("Initialize point with zero coordinates") {
        Point p(0.0, 0.0);

        // Verify the point at the origin has a distance of 0 to itself
        REQUIRE(p.distanceTo(Point(0.0, 0.0)) == Approx(0.0).epsilon(0.001));  // Distance to itself should be 0
    }
}

TEST_CASE("Point distanceTo method", "[Point]") {
    SECTION("Calculate distance between two distinct points") {
        Point p1(1.0, 1.0);
        Point p2(4.0, 5.0);

        // The expected distance is sqrt((4-1)^2 + (5-1)^2) = sqrt(9 + 16) = sqrt(25) = 5
        REQUIRE(p1.distanceTo(p2) == Approx(5.0).epsilon(0.001));  // Expect distance to be 5
    }

    SECTION("Calculate distance between points with same coordinates") {
        Point p1(2.0, 3.0);
        Point p2(2.0, 3.0);

        // Distance between a point and itself should be 0
        REQUIRE(p1.distanceTo(p2) == Approx(0.0).epsilon(0.001));
    }

    SECTION("Calculate horizontal distance between two points") {
        Point p1(2.0, 3.0);
        Point p2(5.0, 3.0);

        // Horizontal distance should be the difference in x-coordinates
        REQUIRE(p1.distanceTo(p2) == Approx(3.0).epsilon(0.001));
    }

    SECTION("Calculate vertical distance between two points") {
        Point p1(3.0, 2.0);
        Point p2(3.0, 6.0);

        // Vertical distance should be the difference in y-coordinates
        REQUIRE(p1.distanceTo(p2) == Approx(4.0).epsilon(0.001));
    }

    SECTION("Calculate distance with negative coordinates") {
        Point p1(-1.0, -1.0);
        Point p2(1.0, 1.0);

        // Distance should be sqrt((1 - (-1))^2 + (1 - (-1))^2) = sqrt(4 + 4) = sqrt(8)
        REQUIRE(p1.distanceTo(p2) == Approx(std::sqrt(8)).epsilon(0.001));
    }
}
