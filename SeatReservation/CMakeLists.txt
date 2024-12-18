cmake_minimum_required(VERSION 3.16)
project(SeatReservation)

set(CMAKE_CXX_STANDARD 11)

add_executable(SeatReservation src/main.cpp
        src/Table.cpp
        src/Guest.cpp
        src/Restaurant.cpp)
include_directories(SeatReservation PUBLIC inc)