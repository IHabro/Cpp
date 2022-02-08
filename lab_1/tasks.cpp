#include "tasks.h"

#include <iostream>
#include <cstring>
#include <string>

using std::cout;
using std::endl;

int math::fibonacci(int n)
{

    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

//  strutils::camel_to_snake("helloWorld); // "hello_world"
string strutils::camel_to_snake(string input)
{
    string result = "";

    for(int i = 0;i < (int) input.size();i++)
    {
        if(input[i] >= 'A' && input[i] <= 'Z')
        {
            result.push_back('_');
            result.push_back(tolower(input[i]));
        }
        else
        {
            result.push_back(input[i]);
        }
    }

    return result;
}

/*
 * Implement a function named `parse_uint` inside namespace `strutils`.
 * It will receive a string, it should parse that string as a 32-bit unsigned int.
 * If the parsing is successful, the function should return `true`. Otherwise it will return `false`.
 *
 * For the parsing to be successful, the input string has to contain a valid decimal
 * representation of a 32-bit unsigned integer.
 * If it contains any character other than a digit (0-9) anywhere in the string, parsing fails.
 * If the string is empty, parsing fails.
 * If the contained number is too large (it overflows 32-bit unsigned integer), parsing fails.
 *
 * Note: DO NOT use any library function (atoi, strtol, from_chars, etc.) when implementing this
 * function. Try to implement it "from scratch" :)
 *
 * Example:
 *  strutils::parse_uint("helloWorld", result);         // false
 *  strutils::parse_uint("123", result);                // true, result == 123
 *  strutils::parse_uint("999999999999999999", result); // false
 **/
bool strutils::parse_uint(string input, uint32_t result)
{
    if(input.empty())
    {
        return false;
    }
    else if(input.size() > 10)
    {
        return false;
    }
    else
    {
        for(int i = 0;i < (int) input.size();i++)
        {
            if(!(input[i] >= '0' && input[i] <= '9'))
            {
                return false;
            }
        }
    }

    return true;
}
