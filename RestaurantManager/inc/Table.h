#pragma once

#include <string>
#include <vector>

#include "Point.h"

/**
 * @brief Represents a table in a restaurant.
 *
 * The Table class holds information about a specific table in the restaurant, including its
 * unique ID, location (using a `Point` object to store coordinates), and an optional description
 * that could detail the table's features (e.g., location within the restaurant).
 */
class Table
{
public:
    int id;                  ///< The unique ID of the table.
    Point location;          ///< The location of the table represented by coordinates.
    std::string description; ///< A description of the table (e.g., location, type, etc.).

    /**
     * @brief Constructs a Table object with the specified details.
     *
     * Initializes a new Table object with the given `id`, `location`, and `description`.
     *
     * @param id The unique identifier for the table.
     * @param location The location of the table represented as a `Point` object.
     * @param description A description of the table (optional).
     */
    Table(int id, const Point &location, const std::string &description);

    /**
     * @brief Loads a list of tables from a file.
     *
     * This method loads table information from a file (e.g., CSV or other formats) and returns
     * a vector of Table objects based on the data contained in the file.
     *
     * @param filePath The path to the file containing the table information.
     * @return A vector of Table objects loaded from the file.
     */
    static std::vector<Table> loadTables(const std::string &filePath);
};
