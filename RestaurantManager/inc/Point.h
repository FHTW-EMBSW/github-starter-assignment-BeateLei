#pragma once

/**
 * @brief Represents a 2D point in Cartesian coordinates.
 *
 * The Point class is used to represent a point in a 2D space with `x` and `y` coordinates.
 * It provides methods to calculate distances between points.
 */
class Point
{
public:
    /**
     * @brief Constructs a Point object with the specified coordinates.
     *
     * Initializes a Point object with the given `x` and `y` coordinates.
     *
     * @param x The x-coordinate of the point.
     * @param y The y-coordinate of the point.
     */
    Point(double x, double y);

    /**
     * @brief Calculates the Euclidean distance between this point and another point.
     *
     * This method computes the straight-line distance between the current point and the
     * given point `other` using the Euclidean distance formula.
     *
     * @param other The other Point object to which the distance will be calculated.
     * @return The Euclidean distance between the current point and `other`.
     */
    double distanceTo(const Point &other) const;

private:
    double x; ///< The x-coordinate of the point.
    double y; ///< The y-coordinate of the point.
};
