#include <catch2/catch.hpp>
#include <pascal.h>

TEST_CASE("numbers 0 to 10")
{
    std::vector<std::vector<int>> expected =
        {
            {1},
            {1, 1},
            {1, 2, 1},
            {1, 3, 3, 1},
            {1, 4, 6, 4, 1},
            {1, 5, 10, 10, 5, 1},
            {1, 6, 15, 20, 15, 6, 1},
            {1, 7, 21, 35, 35, 21, 7, 1},
            {1, 8, 28, 56, 70, 56, 28, 8, 1},
            {1, 9, 36, 84, 126, 126, 84, 36, 9, 1}};

    for (int i = 0; i < 11; i++)
    {
        REQUIRE(createTriangle(i) == std::vector<std::vector<int>>(expected.begin(),
                                                             expected.end() - (expected.size() - i)));
    }
}

TEST_CASE("number 11"){
    REQUIRE(createTriangle(11)==std::vector<std::vector<int>>());
}
