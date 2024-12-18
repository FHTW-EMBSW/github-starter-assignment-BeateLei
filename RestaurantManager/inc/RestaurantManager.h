#pragma once

#include <string>
#include <chrono>

#include "Guest.h"
#include "Table.h"

/**
 * @brief Manages restaurant operations such as guest registrations and table assignments.
 *
 * The RestaurantManager class handles the registration of guests, finding guests near a specific
 * table, deleting old guest files, and managing date-related operations. It interacts with the
 * `Guest` and `Table` classes for guest information and table assignments.
 */
class RestaurantManager
{
public:
    /**
     * @brief Constructs a RestaurantManager object with the path to the table file.
     *
     * Initializes the RestaurantManager with the file path that contains table data.
     * This is used to load and manage table information.
     *
     * @param tableFilePath The path to the file containing the table information.
     */
    explicit RestaurantManager(const std::string &tableFilePath);

    /**
     * @brief Registers a guest and appends their information to the specified file.
     *
     * This method registers a new guest by adding their reservation details to a given file.
     * The guest is associated with a table, and the details are saved in the file for record-keeping.
     *
     * @param guest The Guest object containing the guest's reservation details.
     * @param filePath The file path where the guest information will be saved.
     */
    void registerGuest(const Guest &guest, const std::string &filePath);

    /**
     * @brief Finds guests who are within a specified distance of a table and within a given time range.
     *
     * This method searches for guests that are near a specified table ID and whose reservation
     * times overlap with the provided start and end times. The maximum allowed distance between
     * the guest and the table is also considered.
     *
     * @param guestFilePath The path to the file containing the guest information.
     * @param tableID The table ID to search around.
     * @param maxDistance The maximum distance a guest can be from the table.
     * @param startTime The start time of the search window.
     * @param endTime The end time of the search window.
     * @return A vector of guests who meet the search criteria.
     */
    std::vector<Guest> findGuestsNearTable(const std::string &guestFilePath, int tableID,
                                           double maxDistance, const std::string &startTime,
                                           const std::string &endTime);

    /**
     * @brief Deletes guest files that are older than the specified retention period.
     *
     * This method deletes guest files from the specified directory that are older than the
     * given retention period, in days. The retention period helps to manage the system's file storage.
     *
     * @param directory The directory containing the guest files to delete.
     * @param retentionDays The number of days after which files should be deleted.
     */
    void deleteOldGuestFiles(const std::string &directory, int retentionDays);

    /**
     * @brief Gets the current date in string format (YYYY-MM-DD).
     *
     * This method returns the current date as a string in the format "YYYY-MM-DD".
     *
     * @return The current date in "YYYY-MM-DD" format.
     */
    static std::string today();

private:
    /**
     * @brief Parses a date from a filename into a std::tm structure.
     *
     * This private method parses a date encoded in a filename into a `std::tm` structure for
     * easier manipulation. It is used for determining file dates from filenames.
     *
     * @param filename The name of the file containing the date.
     * @return A `std::tm` structure representing the parsed date.
     */
    static std::tm parseDateFromFilename(const std::string &filename);

    /**
     * @brief Parses a datetime string into a system time point.
     *
     * This method converts a datetime string (in a specific format) into a `std::chrono::system_clock::time_point`.
     *
     * @param datetimeStr The datetime string to parse.
     * @return A `std::chrono::system_clock::time_point` representing the parsed datetime.
     */
    static std::chrono::system_clock::time_point parseDatetime(const std::string &datetimeStr);

    /**
     * @brief Checks if a file is older than the specified retention period.
     *
     * This method checks whether a file's timestamp is older than the given retention period in days.
     * It is used for cleaning up old files.
     *
     * @param filename The name of the file to check.
     * @param retentionDays The number of days to compare against.
     * @return True if the file is older than the retention period, false otherwise.
     */
    static bool isFileOlderThan(const std::string &filename, int retentionDays);

    std::vector<Table> tables{}; ///< A collection of tables in the restaurant.
};
