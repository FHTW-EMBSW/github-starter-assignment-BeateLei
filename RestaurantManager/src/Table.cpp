#include "Table.h"

#include <vector>
#include <string>
#include <fstream>

#include "CSVLoader.h"

Table::Table(int id, const Point &location, const std::string &description)
    : id(id), location(location), description(description)
{
}

std::vector<Table> Table::loadTables(const std::string &filePath)
{
    std::vector<Table> tables;                // Vector to store the loaded Table objects.
    auto data = CSVLoader::loadCSV(filePath); // Load the CSV data into a 2D vector of strings.

    // Loop through each row of data from the CSV and create a Table object for each.
    for (auto row : data)
    {
        tables.emplace_back(
            std::stoi(row[0]),                           // Convert the table ID from string to integer.
            Point(std::stod(row[1]), std::stod(row[2])), // Convert the x and y coordinates to double and create a Point object.
            row[3]                                       // Use the description from the CSV as a string.
        );
    }

    return tables; // Return the vector of Table objects.
}
