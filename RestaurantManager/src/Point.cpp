#include "Point.h"

#include <cmath>

Point::Point(const double x, const double y) : x(x), y(y) {
}

double Point::distanceTo(const Point &other) const {
    return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
}
