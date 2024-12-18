#include <iostream>
#include <vector>
#include <ctime>
#include <Restaurant.h>
#include <Guest.h>
#include <Table.h>

int main() {
    Restaurant restaurant;
    
    // Load data from CSV files
    restaurant.loadTables("../tables.csv");
    restaurant.loadGuests("../guests.csv");

    // Define a time interval and table for query
    struct tm tm_start = {};
    tm_start.tm_year = 2024 - 1900;  // Year since 1900
    tm_start.tm_mon = 10;  // November
    tm_start.tm_mday = 15;  // 15th day
    tm_start.tm_hour = 18;
    tm_start.tm_min = 30;
    tm_start.tm_sec = 0;
    time_t start = mktime(&tm_start);

    struct tm tm_end = tm_start;
    tm_end.tm_hour = 20;
    time_t end = mktime(&tm_end);

    double maxDistance = 10.0;  // Example distance threshold

    // Find guests nearby to a specific table
    Table table = restaurant.getTables()[0];  // Example table
    auto nearbyGuests = restaurant.findGuestsNearby(table, start, end, maxDistance);
    
    // Notify the guests
    for (const auto& guest : nearbyGuests) {
        std::cout << "Notifying " << guest.getName() << " at phone: " 
                  << guest.getPhone() << std::endl;
    }

    return 0;
}
