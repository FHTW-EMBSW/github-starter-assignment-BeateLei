#pragma once

#include <string>
#include <vector>

/**
 * @brief A utility class for loading and saving CSV files.
 *
 * The CSVLoader class provides static methods for loading data from a CSV file into a vector of
 * string vectors, as well as appending a new row to an existing CSV file. It is a utility class
 * that simplifies interactions with CSV files in the application.
 */
class CSVLoader
{
public:
    CSVLoader() = delete; ///< Prevent instantiation of the CSVLoader class since it only provides static methods.

    ~CSVLoader() = default; ///< Default destructor (no dynamic resources to release).

    /**
     * @brief Loads a CSV file into a vector of rows.
     *
     * This method reads the contents of a CSV file specified by `filePath` and returns a vector
     * where each element represents a row in the file. Each row is a vector of strings that contains
     * the columns in that row.
     *
     * @param filePath The path to the CSV file to be loaded.
     * @return A 2D vector (vector of vectors) where each inner vector represents a row in the CSV.
     */
    static std::vector<std::vector<std::string>> loadCSV(const std::string &filePath);

    /**
     * @brief Appends a row to an existing CSV file.
     *
     * This method appends a new row (represented as a vector of strings) to the specified CSV file.
     * If the file does not exist, it may be created.
     *
     * @param filePath The path to the CSV file to append the row to.
     * @param row The vector of strings representing the row to be appended to the CSV file.
     */
    static void appendToCSV(const std::string &filePath, const std::vector<std::string> &row);

private:
    /**
     * @brief Removes the trailing newline character from a string.
     *
     * This private method is used to remove the trailing newline character from a string. It ensures
     * that strings read from files do not have unwanted newline characters at the end.
     *
     * @param str The string from which the newline character will be removed.
     * @param newLineCharacter The character representing the newline (usually '\n' or '\r\n').
     */
    static void removeTrailingNewline(std::string &str, char newLineCharacter);
};
