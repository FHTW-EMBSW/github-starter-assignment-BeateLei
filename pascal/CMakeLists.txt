cmake_minimum_required(VERSION 3.25)

project(pascal)

find_package(Catch2 REQUIRED)

include(CTest)
include(Catch)

add_executable(pascal src/main.cpp src/pascal.cpp)
target_include_directories(pascal PUBLIC inc)

add_executable(pascal_test test/main.cpp test/pascal_test.cpp src/pascal.cpp)
target_include_directories(pascal_test PUBLIC inc)

add_test(NAME pascal_triangle_test COMMAND pascal_test)