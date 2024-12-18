#pragma once

#include <string>
#include <ctime>
#include <Table.h>

class Guest {
private:
    std::string name;       // Contact name
    std::string phone;      // Phone number for contact
    std::time_t sitTime;    // Time when the group sat down
    std::time_t leaveTime;  // Time when the group leaves
    int groupSize;          // Number of people in the group
    Table* table;
public:

    const std::string &getName() const;

    const std::string &getPhone() const;

    time_t getSitTime() const;

    time_t getLeaveTime() const;

    Table* getTable() const;

    int getGroupSize() const;

    bool isDuringTimeInterval(time_t start, time_t end) const;

    Guest(std::string name, std::string phone, time_t sitTime, time_t leaveTime, int groupSize, Table* table);

};
