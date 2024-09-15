#include <catch2/catch.hpp>
#include <greeting.h>

TEST_CASE("greet() returns Hello World!")
{
    // arrange
    // act
    std::string value = greet();
    // assert
    REQUIRE(value == "Hello World!");
}

TEST_CASE("greet(\"\") returns Hello World!")
{
    // arrange
    // act
    std::string value = greet("");
    //assert
    REQUIRE(value == "Hello World!");
}

TEST_CASE("greet(Franz) returns Hello Franz!")
{
    // arrange
    const char *name = "Franz";
    // act
    std::string value = greet(name);
    // assert
    REQUIRE(value == "Hello Franz!");
}