#include <fstream>
#include <iostream>

#include "RestaurantManager.h"

int main()
{
    const std::string tableFilePath = "../data/tables.csv";
    const std::string guestDirectory = "../guests/";
    const std::string today = RestaurantManager::today();
    const std::string guestFilePath_today = guestDirectory + today + ".csv";

    const std::string guestFilePath_14 = guestDirectory + "2024-11-14.csv";
    const std::string guestFilePath_12 = guestDirectory + "2024-11-12.csv";
    const std::string guestFilePath_16 = guestDirectory + "2024-11-16.csv";
    const std::string guestFilePath_17 = guestDirectory + "2024-11-17.csv";

    RestaurantManager manager(tableFilePath);

    manager.registerGuest(Guest(1, "Bob Smith", "+1111111111", 2, today + " 12:15", ""), guestFilePath_today);
    manager.registerGuest(Guest(2, "Charlie Brown", "+2222222222", 4, today + " 12:30", ""), guestFilePath_today);
    manager.registerGuest(Guest(3, "Alice Johnson", "+3333333333", 6, today + " 12:00", ""), guestFilePath_today);
    manager.registerGuest(Guest(4, "John Smith", "+4444444444", 3, today + " 11:00", today + " 13:30"), guestFilePath_today);

    manager.registerGuest(Guest(2, "Molly McMiller", "+5555555555", 3, "2024-11-14 11:00", "2024-11-14 13:30"), guestFilePath_14);
    manager.registerGuest(Guest(2, "Donny Brown", "+6666666666", 3, "2024-11-12 11:00", "2024-11-12 13:30"), guestFilePath_12);
    manager.registerGuest(Guest(4, "Don McMurphy", "+7777777777", 3, "2024-11-16 11:00", "2024-11-16 13:30"), guestFilePath_16);
    manager.registerGuest(Guest(4, "Jane Doe", "+8888888888", 3, "2024-11-17 11:00", "2024-11-17 13:30"), guestFilePath_17);

    std::vector<Guest> updatedGuests;
    auto guests = Guest::loadGuests(guestFilePath_today);
    for (auto &guest : guests)
    {
        if (guest.tableID == 2 && guest.checkOut.empty())
        {
            guest.checkOut = today + " 14:00";
        }
        updatedGuests.push_back(guest);
    }

    std::ofstream updateFile(guestFilePath_today, std::ios::trunc);
    for (const auto &guest : updatedGuests)
    {
        guest.save(guestFilePath_today);
    }

    int tableID = 1;
    double maxDistance = 15;
    auto nearGuests = manager.findGuestsNearTable(guestFilePath_today, tableID, maxDistance, today + " 12:00", today + " 14:00");

    std::cout << "Guests near table " << tableID << " (range: " << maxDistance << " units):" << std::endl;
    for (const auto &guest : nearGuests)
    {
        std::cout << "Name: " << guest.contactName << ", Phone: " << guest.phone
                  << ", Group Size: " << guest.groupSize << ", Table: " << guest.tableID << std::endl;
    }

    manager.deleteOldGuestFiles(guestDirectory, 14);

    return 0;
}
