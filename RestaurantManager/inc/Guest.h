#pragma once

#include <string>
#include <vector>

/**
 * @brief A class that represents a guest in a reservation system.
 *
 * The Guest class holds information about a guest's reservation, including their contact details,
 * group size, check-in, and check-out times, and the table ID assigned to them.
 */
class Guest
{
public:
    int tableID;             ///< The ID of the table assigned to the guest.
    std::string contactName; ///< The name of the guest or contact person.
    std::string phone;       ///< The phone number of the guest.
    int groupSize;           ///< The number of people in the guest's party.
    std::string checkIn;     ///< The check-in date and time for the reservation.
    std::string checkOut;    ///< The check-out date and time for the reservation.

    /**
     * @brief Constructs a Guest object with the specified details.
     *
     * @param tableID The ID of the table assigned to the guest.
     * @param contactName The name of the guest or the contact person.
     * @param phone The phone number of the guest.
     * @param groupSize The number of people in the guest's party.
     * @param checkIn The check-in date and time.
     * @param checkOut The check-out date and time.
     */
    Guest(int tableID, const std::string &contactName, const std::string &phone,
          int groupSize, const std::string &checkIn, const std::string &checkOut);

    /**
     * @brief Loads a list of guests from a file.
     *
     * This function reads the guest data from the specified file and returns a list of Guest objects
     * based on the data.
     *
     * @param filePath The path to the file containing the guest data.
     * @return A vector of Guest objects loaded from the file.
     */
    static std::vector<Guest> loadGuests(const std::string &filePath);

    /**
     * @brief Saves the guest's data to a file.
     *
     * This function saves the guest's details (such as table ID, contact name, phone, group size,
     * check-in, and check-out times) to the specified file in a format suitable for future loading.
     *
     * @param filePath The path to the file where the guest's data will be saved.
     */
    void save(const std::string &filePath) const;
};
