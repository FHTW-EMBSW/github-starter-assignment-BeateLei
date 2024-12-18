#include <catch2/catch.hpp>
#include "Table.h"
#include "Point.h"
#include "CSVLoader.h"
#include <vector>
#include <string>

TEST_CASE("Table Constructor", "[Table]") {
    Point location(3.0, 4.0);
    Table t(1, location, "Near the bar");

    SECTION("Test table initialization") {
        REQUIRE(t.id == 1);
        REQUIRE(t.location.distanceTo(Point(3.0, 4.0)) == Approx(0.0).epsilon(0.001));
        REQUIRE(t.description == "Near the bar");
    }
}

TEST_CASE("Table loadTables method", "[Table]") {

    SECTION("Test loading valid tables") {
        std::vector<Table> tables = Table::loadTables("tables_test.csv");

        REQUIRE(tables.size() == 3);  // We have 3 rows in our CSV

        // Check the first table
        REQUIRE(tables[0].id == 1);
        REQUIRE(tables[0].description == "Near window");

        // Check the second table
        REQUIRE(tables[1].id == 2);
        REQUIRE(tables[1].description == "Corner table");

        // Check the third table
        REQUIRE(tables[2].id == 3);
        REQUIRE(tables[2].description == "VIP section");

        // Check distance between Tables
        REQUIRE(tables[0].location.distanceTo(tables[1].location) == Approx(7.0).epsilon(0.1));
        REQUIRE(tables[1].location.distanceTo(tables[2].location) == Approx(14.0).epsilon(0.1));
        REQUIRE(tables[2].location.distanceTo(tables[2].location) == Approx(0.0));
        
    }

    SECTION("Test loading from an empty file") {
        std::vector<Table> tables = Table::loadTables("empty.csv");
        REQUIRE(tables.empty());  // Expecting an empty vector when file is empty
    }

}
