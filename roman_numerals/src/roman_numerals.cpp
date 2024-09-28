#include "roman_numerals.h"

std::string numToRoman(int num)
{
    int values []= {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    std::string roman_numerals[]={"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", 
    "V", "IV", "I"}; // alle moeglichen strings defined
    std::string result;
    for (int i = 0; i < 13 && num > 0; i++)
    {
        while (num>= values[i])
        {
            result += roman_numerals[i];
            num -= values[i];
        }
        
    }
   return result;
}
