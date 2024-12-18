#pragma once

#include <cmath>

class Table
{
private:
    int id;     // Unique identifier for each table
    float x, y; // Location of the table in the restaurant

public:
    int getId() const;

    float getX() const;

    float getY() const;

    // Calculate distance between two tables (using Euclidean distance)
    double distanceTo(const Table &other) const;

    Table(int id, float x, float y);
};
