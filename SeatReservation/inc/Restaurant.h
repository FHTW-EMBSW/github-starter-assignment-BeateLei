#pragma once

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <Table.h>
#include <Guest.h>

class Restaurant {
private:
    std::vector<Table> tables;
    std::vector<Guest> guests;
    
public:

    std::vector<Table> getTables();
    
    void loadTables(const std::string& filename) {
        std::ifstream file(filename);
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            int id;
            double x, y;
            ss >> id >> x >> y;
            tables.push_back(Table(id, x, y));
        }
    }

    void loadGuests(const std::string& filename) {
        std::ifstream file(filename);
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string name, phone;
            int groupSize, tableId;
            std::string timeSeatedStr, timeLeftStr;
            
            ss >> name >> phone >> groupSize >> tableId >> timeSeatedStr >> timeLeftStr;
            
            // Convert time strings to system_clock::time_point (you can use chrono::parse or a library)
            time_t timeSeated = parseTime(timeSeatedStr);
            time_t timeLeft = parseTime(timeLeftStr);
            
            Table* table = &tables[tableId];  // assuming tableId is 0-indexed
            guests.push_back(Guest(name, phone, groupSize, timeSeated, timeLeft, table));
        }
    }

    std::vector<Guest> findGuestsNearby(const Table& table, 
                                        time_t start, 
                                        time_t end, 
                                        double maxDistance) {
        std::vector<Guest> nearbyGuests;
        for (const auto& guest : guests) {
            if (guest.isDuringTimeInterval(start, end) && 
                table.distanceTo(*guest.getTable()) <= maxDistance) {
                nearbyGuests.push_back(guest);
            }
        }
        return nearbyGuests;
    }

private:
    time_t parseTime(const std::string& timeStr) {
        // Parse time string "YYYY-MM-DD HH:MM:SS" into time_t
        struct tm tm = {};
        strptime(timeStr.c_str(), "%Y-%m-%d %H:%M:%S", &tm);  // Use strptime to parse
        return mktime(&tm);  // Convert to time_t
    }
};
