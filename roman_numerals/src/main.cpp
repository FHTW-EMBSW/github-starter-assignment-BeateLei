#include <cstring>
#include "roman_numerals.h"

int main ()
{
    printf("%s == X\n", numToRoman(10).c_str());
    printf("%s == I\n", numToRoman(1).c_str());
    printf("%s == MI\n", numToRoman(1001).c_str());
    printf("%s == CMXCIX\n", numToRoman(999).c_str());
    printf("%s == CXXIV\n", numToRoman(124).c_str());

    return 0;
}

