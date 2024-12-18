#include "RestaurantManager.h"
#include <Table.h>
#include <experimental/filesystem>
#include <string>
#include <chrono>
#include <iostream>
#include <iomanip>

RestaurantManager::RestaurantManager(const std::string &tableFilePath)
{
    tables = Table::loadTables(tableFilePath); // Load tables data from the file.
}

void RestaurantManager::registerGuest(const Guest &guest, const std::string &filePath)
{
    guest.save(filePath); // Save the guest's data to the CSV file.
}

std::vector<Guest> RestaurantManager::findGuestsNearTable(const std::string &guestFilePath,
                                                          int tableID,
                                                          double maxDistance,
                                                          const std::string &startTime,
                                                          const std::string &endTime)
{
    std::vector<Guest> results;                     // Vector to store guests that match the criteria.
    auto guests = Guest::loadGuests(guestFilePath); // Load the guests from the file.

    // Find the target table by tableID.
    Table *targetTable = nullptr;
    for (auto &table : tables)
    {
        if (table.id == tableID)
        {
            targetTable = &table;
            break;
        }
    }

    if (!targetTable)
    {
        std::cerr << "Table not found!" << std::endl; // If the table is not found, log an error.
        return results;
    }

    auto startTimePoint = parseDatetime(startTime); // Parse the start time string into a time point.
    auto endTimePoint = parseDatetime(endTime);     // Parse the end time string into a time point.

    // Loop through all guests to find those who are near the target table and within the time range.
    for (const auto &guest : guests)
    {
        auto guestCheckInTime = parseDatetime(guest.checkIn);                                            // Parse guest check-in time.
        auto guestCheckOutTime = parseDatetime(guest.checkOut.empty() ? guest.checkIn : guest.checkOut); // Parse check-out time or use check-in if empty.

        // Check the table assigned to the guest.
        for (const auto &table : tables)
        {
            if (guest.tableID != table.id)
            {
                continue; // Skip if the guest is not assigned to the current table.
            }

            // Calculate the distance between the guest's table and the target table.
            double distance = table.location.distanceTo(targetTable->location);
            // Check if the guest is within the distance and their stay overlaps with the provided time range.
            if (distance > maxDistance || guestCheckInTime > endTimePoint || guestCheckOutTime < startTimePoint)
            {
                break; // Skip this guest if they don't meet the criteria.
            }

            results.push_back(guest); // Add this guest to the results if they match all criteria.
        }
    }

    return results; // Return the list of guests found.
}

void RestaurantManager::deleteOldGuestFiles(const std::string &directory, int retentionDays)
{
    // Iterate over the directory and check each file's age.
    for (const auto &entry : std::experimental::filesystem::directory_iterator(directory))
    {
        const auto &path = entry.path();
        const std::string filename = path.filename().string();
        if (!isFileOlderThan(filename, retentionDays))
        {
            continue; // Skip files that are not older than the retention period.
        }

        std::experimental::filesystem::remove(path);     // Delete the old file.
        std::cout << "Delete " << filename << std::endl; // Log the file deletion.
    }
}

std::string RestaurantManager::today()
{
    std::ostringstream outputStringStream;                      // Stream to format the date as a string.
    auto now = std::chrono::system_clock::now();                // Get the current system time.
    auto nowAsTime = std::chrono::system_clock::to_time_t(now); // Convert to time_t.
    auto nowAsTimeStruct = *std::localtime(&nowAsTime);         // Convert to a tm structure representing local time.

    // Format the time as "YYYY-MM-DD" and store it in the output stream.
    outputStringStream << std::put_time(&nowAsTimeStruct, "%Y-%m-%d");
    return outputStringStream.str(); // Return the formatted date string.
}

std::tm RestaurantManager::parseDateFromFilename(const std::string &filename)
{
    std::tm tm = {};                               // Initialize tm structure to hold the parsed date.
    std::istringstream ss(filename.substr(0, 10)); // Extract the first 10 characters (assumed to be the date).
    ss >> std::get_time(&tm, "%Y-%m-%d");          // Parse the date in "YYYY-MM-DD" format into tm.
    return tm;
}

std::chrono::system_clock::time_point RestaurantManager::parseDatetime(const std::string &dateTimeString)
{
    std::tm timeStruct = {};                              // Structure to hold the parsed time.
    std::istringstream inputStringStream(dateTimeString); // Create a stringstream from the input datetime string.

    inputStringStream >> std::get_time(&timeStruct, "%Y-%m-%d %H:%M"); // Parse the datetime string.

    std::time_t time = std::mktime(&timeStruct);         // Convert the tm structure to time_t.
    return std::chrono::system_clock::from_time_t(time); // Convert time_t to a time_point and return it.
}

bool RestaurantManager::isFileOlderThan(const std::string &filename, int retentionDays)
{
    std::tm fileDate = parseDateFromFilename(filename);                             // Parse the date from the filename.
    auto fileTime = std::chrono::system_clock::from_time_t(std::mktime(&fileDate)); // Convert the date to time_point.

    auto now = std::chrono::system_clock::now();                                                  // Get the current time.
    auto ageInDays = std::chrono::duration_cast<std::chrono::hours>(now - fileTime).count() / 24; // Calculate the file's age in days.
    return ageInDays > retentionDays;                                                             // Return true if the file is older than the retention period.
}
