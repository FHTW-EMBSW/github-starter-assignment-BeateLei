#include <catch2/catch.hpp>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <experimental/filesystem>
#include "CSVLoader.h"

// Utility function to write to a file (useful for testing)
void writeToFile(const std::string& filePath, const std::string& content) {
    std::ofstream file(filePath);
    file << content;
    file.close();
}

// Test the loadCSV method
TEST_CASE("CSVLoader loadCSV", "[CSVLoader]") {
    const std::string testFilePath = "test_load.csv";
    std::experimental::filesystem::remove(testFilePath);
    SECTION("Load CSV with valid data") {
        // Prepare test data
        std::string csvData = "name,age,city\nJohn,25,New York\nJane,30,Los Angeles";
        writeToFile(testFilePath, csvData);

        auto result = CSVLoader::loadCSV(testFilePath);

        REQUIRE(result.size() == 3); // Should have 3 rows
        REQUIRE(result[0].size() == 3); // First row should have 3 columns
        REQUIRE(result[1][0] == "John"); // "First" column in "first" row
        REQUIRE(result[2][1] == "30"); // "Second" column in "second" row
    }
    std::experimental::filesystem::remove(testFilePath);
    SECTION("Load CSV with an empty file") {
        // Prepare an empty file
        writeToFile(testFilePath, "");

        auto result = CSVLoader::loadCSV(testFilePath);

        REQUIRE(result.size() == 0); // Should have no rows
    }
    std::experimental::filesystem::remove(testFilePath);
    SECTION("Load CSV with a malformed row") {
        // Malformed CSV with extra commas
        std::string csvData = "name,age,city\nJohn,,New York\nJane,30,";
        writeToFile(testFilePath, csvData);

        auto result = CSVLoader::loadCSV(testFilePath);

        REQUIRE(result.size() == 3); // Three rows present
        REQUIRE(result[0].size() == 3); // First row should still have 3 columns, even with missing data
        REQUIRE(result[1].size() == 3); // Second row should still have 3 columns (with a trailing comma)
    }
}

// Test the appendToCSV method
TEST_CASE("CSVLoader appendToCSV", "[CSVLoader]") {
    const std::string testFilePath = "test_append.csv";
    std::experimental::filesystem::remove(testFilePath);
    SECTION("Append a single row to an empty file") {
        // Prepare an empty file
        writeToFile(testFilePath, "");

        std::vector<std::string> row = {"Alice", "28", "Chicago"};
        CSVLoader::appendToCSV(testFilePath, row);

        auto result = CSVLoader::loadCSV(testFilePath);

        REQUIRE(result.size() == 1); // One row after appending
        REQUIRE(result[0].size() == 3); // The row should have 3 columns
        REQUIRE(result[0][0] == "Alice");
        REQUIRE(result[0][1] == "28");
        REQUIRE(result[0][2] == "Chicago");
    }
    std::experimental::filesystem::remove(testFilePath);
    SECTION("Append multiple rows to a file") {
        // Prepare the file with an initial row
        std::string initialData = "name,age,city\nAlice,28,Chicago\n";
        writeToFile(testFilePath, initialData);

        std::vector<std::string> row1 = {"Bob", "35", "Miami"};
        std::vector<std::string> row2 = {"Carol", "40", "Seattle"};

        CSVLoader::appendToCSV(testFilePath, row1);
        CSVLoader::appendToCSV(testFilePath, row2);

        auto result = CSVLoader::loadCSV(testFilePath);

        REQUIRE(result.size() == 4); // 4 rows after appending
        REQUIRE(result[1][0] == "Alice"); // Second row
        REQUIRE(result[2][0] == "Bob"); // Third row
        REQUIRE(result[3][0] == "Carol"); // Third row
    }
    std::experimental::filesystem::remove(testFilePath);
    SECTION("Check file after appending to an existing file") {
        // Prepare initial data in the file
        std::string initialData = "name,age,city\nTom,22,Boston\n";
        writeToFile(testFilePath, initialData);

        std::vector<std::string> newRow = {"Emma", "26", "Austin"};
        CSVLoader::appendToCSV(testFilePath, newRow);

        auto result = CSVLoader::loadCSV(testFilePath);

        REQUIRE(result.size() == 3); // Should have three rows after appending
        REQUIRE(result[2][0] == "Emma"); // The new row
    }
}

