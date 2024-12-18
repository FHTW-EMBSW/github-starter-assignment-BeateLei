#include "Guest.h"
#include "CSVLoader.h"

Guest::Guest(int tableID, const std::string &contactName, const std::string &phone,
             int groupSize, const std::string &checkIn, const std::string &checkOut)
    : tableID(tableID), contactName(contactName), phone(phone),
      groupSize(groupSize), checkIn(checkIn), checkOut(checkOut)
{
}

std::vector<Guest> Guest::loadGuests(const std::string &filePath)
{
    std::vector<Guest> guests;                // Vector to store the loaded Guest objects.
    auto data = CSVLoader::loadCSV(filePath); // Load the CSV data into a 2D vector of strings.

    // Loop through each row of data from the CSV and create a Guest object for each.
    for (const auto &row : data)
    {
        guests.emplace_back(
            std::stoi(row[0]), row[1], row[2], // Convert and assign the first three columns to tableID, contactName, phone.
            std::stoi(row[3]), row[4],         // Convert and assign groupSize, checkIn.
            row.size() == 6 ? row[5] : ""      // If there are 6 columns, assign checkOut, otherwise use an empty string.
        );
    }

    return guests; // Return the vector of Guest objects.
}

void Guest::save(const std::string &filePath) const
{
    CSVLoader::appendToCSV(
        filePath,
        {std::to_string(tableID), contactName, phone, std::to_string(groupSize), checkIn, checkOut}); // Convert guest properties to strings and append to the CSV file.
}
