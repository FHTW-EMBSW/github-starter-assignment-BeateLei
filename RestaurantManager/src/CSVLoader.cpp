#include "CSVLoader.h"
#include <fstream>
#include <sstream>

std::vector<std::vector<std::string>> CSVLoader::loadCSV(const std::string &filePath)
{
    std::vector<std::vector<std::string>> data; // Vector to store the entire CSV data (rows and cells).
    std::ifstream file(filePath);               // Open the CSV file.
    std::string line;                           // String to hold each line of the CSV file as it's read.

    // Loop through each line in the file.
    while (std::getline(file, line))
    {
        std::istringstream input(line); // Create an input stream from the current line.
        std::vector<std::string> row;   // Vector to store the cells of the current row.
        std::string cell;               // String to hold each cell in the current row.

        // Loop through each cell in the line (split by commas).
        while (std::getline(input, cell, ','))
        {
            CSVLoader::removeTrailingNewline(cell, '\r'); // Remove any trailing newline characters from the cell (for Windows compatibility).
            row.push_back(cell);                          // Add the cell to the current row.
        }

        // If the row contains any data, add it to the data vector.
        if (!row.empty())
        {
            data.push_back(row);
        }
    }

    return data; // Return the vector containing all rows and their respective cells.
}

void CSVLoader::appendToCSV(const std::string &filePath, const std::vector<std::string> &row)
{
    std::ofstream file(filePath, std::ios::app); // Open the file in append mode.

    // Loop through each element in the row vector.
    for (size_t i = 0; i < row.size(); ++i)
    {
        file << row[i]; // Write the current cell to the file.
        if (i < row.size() - 1)
            file << ","; // Add a comma unless it's the last element in the row.
    }

    file << std::endl; // After writing all cells in the row, add a newline character.
}

void CSVLoader::removeTrailingNewline(std::string &str, const char newLineCharacter = '\n')
{
    // If the string is not empty and ends with the specified newline character, remove it.
    if (!str.empty() && str.back() == newLineCharacter)
    {
        str.pop_back(); // Remove the last character (the newline).
    }
}
