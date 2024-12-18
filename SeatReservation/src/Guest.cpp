#include <utility>

#include <Guest.h>

const std::string &Guest::getName() const
{
    return name;
}

const std::string &Guest::getPhone() const
{
    return phone;
}

time_t Guest::getSitTime() const
{
    return sitTime;
}

time_t Guest::getLeaveTime() const
{
    return leaveTime;
}

int Guest::getGroupSize() const
{
    return groupSize;
}

Table *Guest::getTable() const
{
    return table;
};

bool Guest::isDuringTimeInterval(time_t start, time_t end) const
{
    // Check if guest's visit overlaps with the time interval [start, end]
    return (sitTime <= end && leaveTime >= start);
}

Guest::Guest(std::string name, std::string phone, time_t sitTime, time_t leaveTime, int groupSize, Table *table) : name(std::move(
                                                                                                                       name)),
                                                                                                                   phone(std::move(phone)), sitTime(sitTime), leaveTime(leaveTime), groupSize(groupSize), table(std::move(table)) {}
