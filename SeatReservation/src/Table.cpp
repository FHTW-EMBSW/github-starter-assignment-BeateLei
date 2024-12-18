//
// Created by lukas on 15.11.2024.
//

#include "../inc/Table.h"

double Table::distanceTo(const Table &other) const {
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
}

int Table::getId() const {
    return id;
}

float Table::getX() const {
    return x;
}

float Table::getY() const {
    return y;
}

Table::Table(int id, float x, float y) : id(id), x(x), y(y) {}
