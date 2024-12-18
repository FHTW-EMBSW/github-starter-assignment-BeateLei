#include <catch2/catch.hpp>
#include "Guest.h"
#include "CSVLoader.h"
#include <fstream>
#include <experimental/filesystem>

// Utility function to write to a file (useful for testing)
void writeToFile(const std::string& filePath, const std::string& content) {
    std::ofstream file(filePath);
    file << content;
    file.close();
}

// Test the loadGuests method
TEST_CASE("Guest loadGuests", "[Guest]") {
    const std::string testFilePath = "test_guests.csv";
    std::experimental::filesystem::remove(testFilePath);
    SECTION("Load guests with valid data") {
        // Prepare test data
        std::string csvData = "1,John Doe,1234567890,4,2024-12-01 18:00,2024-12-01 20:00\n"
                              "2,Jane Smith,0987654321,2,2024-12-02 19:00,2024-12-02 21:00\n";
        writeToFile(testFilePath, csvData);

        auto guests = Guest::loadGuests(testFilePath);

        REQUIRE(guests.size() == 2); // Should load 2 guests
        REQUIRE(guests[0].tableID == 1); // Check first guest's table ID
        REQUIRE(guests[1].contactName == "Jane Smith"); // Check second guest's contact name
        REQUIRE(guests[0].groupSize == 4); // Check first guest's group size
        REQUIRE(guests[1].checkOut == "2024-12-02 21:00"); // Check second guest's check-out time
    }
    std::experimental::filesystem::remove(testFilePath);
    SECTION("Load guests from an empty file") {
        // Prepare an empty file
        writeToFile(testFilePath, "");

        auto guests = Guest::loadGuests(testFilePath);

        REQUIRE(guests.size() == 0); // Should load no guests
    }
    std::experimental::filesystem::remove(testFilePath);
    SECTION("Load guests with malformed data") {
        // Malformed CSV (missing check-out time for the second guest)
        std::string csvData = "1,John Doe,1234567890,4,2024-12-01 18:00\n"
                              "2,Jane Smith,0987654321,2,2024-12-02 19:00\n";
        writeToFile(testFilePath, csvData);

        auto guests = Guest::loadGuests(testFilePath);

        REQUIRE(guests.size() == 2); // Should load 2 guests
        REQUIRE(guests[1].checkOut == ""); // The second guest should have an empty check-out field
    }
}

// Test the save method
TEST_CASE("Guest save", "[Guest]") {
    const std::string testFilePath = "test_save_guests.csv";
    std::experimental::filesystem::remove(testFilePath);
    SECTION("Save a single guest to an empty file") {
        // Prepare the guest data
        Guest guest(1, "Alice Johnson", "5551234567", 3, "2024-12-01 18:00", "2024-12-01 20:00");
        guest.save(testFilePath);

        auto guests = Guest::loadGuests(testFilePath);

        REQUIRE(guests.size() == 1); // Should have saved one guest
        REQUIRE(guests[0].contactName == "Alice Johnson"); // Check contact name
        REQUIRE(guests[0].phone == "5551234567"); // Check phone
    }
    std::experimental::filesystem::remove(testFilePath);
    SECTION("Save multiple guests") {
        // Prepare guest data
        Guest guest1(1, "Alice Johnson", "5551234567", 3, "2024-12-01 18:00", "2024-12-01 20:00");
        Guest guest2(2, "Bob Brown", "5559876543", 5, "2024-12-02 19:00", "2024-12-02 21:00");

        guest1.save(testFilePath);
        guest2.save(testFilePath);

        auto guests = Guest::loadGuests(testFilePath);

        REQUIRE(guests.size() == 2); // Should have saved two guests
        REQUIRE(guests[1].contactName == "Bob Brown"); // Check second guest's name
    }
}
