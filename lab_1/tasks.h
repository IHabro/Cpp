#pragma once

#include <string>
#include <cstdint>

using std::string;

namespace math
{
	int fibonacci(int n);
}

namespace strutils
{
	string camel_to_snake(string input);
	bool parse_uint(string input, uint32_t result);
}

/*
 * Implement a function named `camel_to_snake` inside namespace `strutils`.
 * It will receive a string in camelCase and should return the input string converted to snake_case.
 *
 * Example:
 *  strutils::camel_to_snake("helloWorld); // "hello_world"
 **/

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
