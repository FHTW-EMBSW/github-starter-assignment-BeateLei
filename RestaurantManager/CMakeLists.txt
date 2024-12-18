cmake_minimum_required(VERSION 3.16)
project(RestaurantManager)

set(CMAKE_CXX_STANDARD 11)

find_package(Catch2 REQUIRED)

include(CTest)
include(Catch)

add_executable(RestaurantManager src/main.cpp
        src/Table.cpp
        src/CSVLoader.cpp
        src/CSVLoader.cpp
        src/Guest.cpp
        src/RestaurantManager.cpp
        src/Point.cpp
)

target_include_directories(RestaurantManager PUBLIC inc)
target_link_libraries(RestaurantManager stdc++fs)

add_executable(CSVLoaderTest test/main.cpp
        test/CSVLoaderTest.cpp
        src/CSVLoader.cpp
)
target_include_directories(CSVLoaderTest PUBLIC inc)
target_link_libraries(CSVLoaderTest stdc++fs)

add_executable(GuestTest test/main.cpp
        test/GuestTest.cpp
        src/Guest.cpp
        src/CSVLoader.cpp
)
target_include_directories(GuestTest PUBLIC inc)
target_link_libraries(GuestTest stdc++fs)

add_executable(PointTest test/main.cpp
        test/PointTest.cpp
        src/Point.cpp
)
target_include_directories(PointTest PUBLIC inc)
target_link_libraries(PointTest stdc++fs)

add_executable(TableTest test/main.cpp
        test/TableTest.cpp
        src/CSVLoader.cpp
        src/Table.cpp
        src/Point.cpp
)
target_include_directories(TableTest PUBLIC inc)
target_link_libraries(TableTest stdc++fs)

add_test(NAME CSVLoaderTest COMMAND CSVLoaderTest)
add_test(NAME GuestTest COMMAND GuestTest)
add_test(NAME PointTest COMMAND PointTest)
add_test(NAME TableTest COMMAND TableTest)
