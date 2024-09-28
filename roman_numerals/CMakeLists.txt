project("roman_numerals")
cmake_minimum_required(VERSION 3.18)



add_executable(roman 
src/main.cpp 
src/roman_numerals.cpp 
)

add_executable(roman_tests
test/main.cpp 
test/roman_numerals_test.cpp
src/roman_numerals.cpp 
)

target_include_directories(roman PUBLIC include)
target_include_directories(roman_tests PUBLIC include)

add_test(NAME RomanNumeralsTests COMMAND roman_tests)
