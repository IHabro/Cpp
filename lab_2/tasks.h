#pragma once

#include <string>
#include <cstdint>
#include <functional>
#include <iostream>  
#include <vector>  
#include <sstream> 

using std::string;
using std::cout;
using std::endl;

/*
 * TODO: implement the functions described below
 * Put their declaration here and their implementation into tasks.cpp.
 */

/*
 * Implement a function named `calculate_checksum`.
 * The function will receive a IPv4 address and return an unsigned 32-bit checksum, which will
 * be calculated as the sum of the four bytes of the address.
 *
 * The function will be able to receive IPv4 addresses represented in two forms - either an
 * unsigned 32-bit number or a string like "192.168.1.1". When the input is a string, you can assume
 * that the input is a valid IPv4 address, you don't have to consider invalid input.
 *
 * Example:
 *  calculate_checksum(0xFF110000);  // 272
 *  calculate_checksum("255.17.0.0"); // 272
 **/

uint32_t calculate_checksum(string input);
uint32_t calculate_checksum(uint32_t input);

using Parser = std::function<const char*(const char*)>;

/*
 * Implement a set of parsers and parser combinators that will be used to parse text.
 * `Parser` is a function that receives a C string and returns `const char*`.
 * `Parser combinator` is a function that creates (returns) `Parser`s.
 *
 * A Parser matches some input if a prefix of the input is recognized by the Parser.
 *
 * If the parser doesn't match, it will return a null pointer.
 * If the parser matches, it will return an address within the input string where parsing should
 * continue (after the recognized prefix).
 *
 * `parse_digit` is a Parser that recognizes a single digit.
 * Example:
 *  parse_digit("xa"); // 0
 *  parse_digit("1x"); // "x"
 *
 * `create_char_parser` is a Parser combinator that receives a character `c` and creates a parser
 * that recognizes that exact character.
 * Example:
 *  auto parser = create_char_parser('x');
 *  parser("y");   // 0
 *  parser("x1");  // "1"
 *
 * `first_match` is a Parser combinator that receives a vector of Parsers and returns a Parser that
 * will try to match the input parsers one by one and return the first found match
 * (or null if no parser matches).
 * Example:
 *  auto parser = first_match({create_char_parser('x'), parse_digit});
 *  parser("a");  // 0
 *  parser("1b"); // "b"
 *  parser("xy"); // "y"
 *
 * `sequence` is a parser combinator that receives a vector of Parsers and returns a Parser that
 * will try to match all the input parsers, applied one after another. It will match if all the
 * input parsers match in succession.
 * Example:
 *  autor parser = sequence({create_char_parser('x'), parse_digit, create_char_parser('z')});
 *  parser("a");    // 0
 *  parser("x1x");  // 0
 *  parser("x1zu"); // "u"
 *  parser("x2zy"); // "y"
 *
 * `repeat` is a Parser combinator that receives a Parser and a number of repetitions `n` and
 * returns a parser that will repeat the input parser `n` times.
 * Try to leverage some parser combinator above to implement this functino.
 * Example:
 *  auto parser = repeat(parse_digit, 3);
 *  parser("a");    // 0
 *  parser("1");    // 0
 *  parser("23");   // 0
 *  parser("1234"); // "4"
 *
 * `create_word_parser` is a Parser combinator that receives a string and returns a Parser that
 * will recognize that string.
 * Try to leverage some parser combinator above to implement this functino.
 * Example:
 *  auto parser = create_word_parser("foo");
 *  parser("a");    // 0
 *  parser("f");    // 0
 *  parser("fo");   // 0
 *  parser("foox"); // "x"
 **/

/*
 * Implement a function named `validate_utf8`, which will receive a vector of bytes (`uint8_t`).
 * It will validate if the byte sequence is a valid representation of some UTF-8 string and if yes,
 * it will count the number of Unicode code points contained within the string.
 *
 * See https://en.wikipedia.org/wiki/UTF-8#encoding for details.
 *
 * Example:
 *  size_t result;
 *  validate_utf8({0b00001100}, result);                         // true, result = 1
 *  validate_utf8({0b11000011, 0b10001101, 0b00001001}, result); // true, result = 2
 *  validate_utf8({0b10001001}, result);                         // false
 **/
