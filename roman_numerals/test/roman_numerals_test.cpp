#include <catch2/catch.hpp>
#include <roman_numerals.h>

TEST_CASE("numToRoman(10) returns X") //Namen geben die Beschreiben was zu erwarten ist
{
    // arrange
    // act
    std::string value = numToRoman(10);
    // assert
	REQUIRE(value == "X");
}

TEST_CASE("numToRoman(143) returns CXLIII")
{
    // arrange
    // act
    std::string value = numToRoman(143);
    // assert
	REQUIRE(value == "CXLIII");
}

TEST_CASE("numToRoman(1001) returns MI")
{
    // arrange
    // act
    std::string value = numToRoman(1001);
    // assert
	REQUIRE(value == "MI");
}

TEST_CASE("numToRoman(3999) returns MMMCMXCIX")
{
    // arrange
    // act
    std::string value = numToRoman(3999);
    // assert
	REQUIRE(value == "MMMCMXCIX");
}

TEST_CASE("numToRoman(0) returns """"")
{
    // arrange
    // act
    std::string value = numToRoman(0);
    // assert
	REQUIRE(value == "");
}

TEST_CASE("numToRoman(4000) returns MMMM")
{
    // arrange
    // act
    std::string value = numToRoman(4000);
    // assert
	REQUIRE(value == "MMMM");
}