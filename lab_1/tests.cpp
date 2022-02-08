// This tells doctest to provide a main() function
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "tasks.h"

// Note: comment out the tests to avoid lots of compile errors that will occur before you
// implement the functions. Uncomment the tests for the function that you are currently implementing.

TEST_CASE("Fibonacci") {
    REQUIRE(math::fibonacci(0) == 0);
    REQUIRE(math::fibonacci(1) == 1);
    REQUIRE(math::fibonacci(2) == 1);
    REQUIRE(math::fibonacci(3) == 2);
    REQUIRE(math::fibonacci(4) == 3);
    REQUIRE(math::fibonacci(5) == 5);
    REQUIRE(math::fibonacci(6) == 8);
    REQUIRE(math::fibonacci(40) == 102334155);
}


TEST_SUITE("Camel to snake conversion") {
    TEST_CASE("Empty string") {
        REQUIRE(strutils::camel_to_snake("") == "");
    }
    TEST_CASE("Single word") {
        REQUIRE(strutils::camel_to_snake("foo") == "foo");
    }
    TEST_CASE("Two words") {
        REQUIRE(strutils::camel_to_snake("fooBar") == "foo_bar");
    }
    TEST_CASE("Multiple words") {
        REQUIRE(strutils::camel_to_snake("fooBarBaz") == "foo_bar_baz");
    }
    TEST_CASE("Short words") {
        REQUIRE(strutils::camel_to_snake("aBCDEFGxH") == "a_b_c_d_e_f_gx_h");
    }
}


TEST_SUITE("Integer parsing") {
    TEST_CASE("Empty string") {
        uint32_t result = std::numeric_limits<uint32_t>::max();
        REQUIRE(!strutils::parse_uint("", result));
    }
    TEST_CASE("Zero") {
        uint32_t result = std::numeric_limits<uint32_t>::max();
        REQUIRE(strutils::parse_uint("0", result));
        REQUIRE(result == 0);
    }
    TEST_CASE("Single digit") {
        uint32_t result = std::numeric_limits<uint32_t>::max();
        REQUIRE(strutils::parse_uint("5", result));
        REQUIRE(result == 5);
    }
    TEST_CASE("Two digits") {
        uint32_t result = std::numeric_limits<uint32_t>::max();
        REQUIRE(strutils::parse_uint("99", result));
        REQUIRE(result == 99);
    }
    TEST_CASE("Two digits") {
        uint32_t result = std::numeric_limits<uint32_t>::max();
        REQUIRE(strutils::parse_uint("99", result));
        REQUIRE(result == 99);
    }
    TEST_CASE("Large number") {
        uint32_t result = std::numeric_limits<uint32_t>::max();
        REQUIRE(strutils::parse_uint("123456789", result));
        REQUIRE(result == 123456789);
    }
    TEST_CASE("Maximum") {
        uint32_t result = std::numeric_limits<uint32_t>::max();
        REQUIRE(strutils::parse_uint("4294967295", result));
        REQUIRE(result == 4294967295);
    }
    TEST_CASE("Overflow") {
        uint32_t result = std::numeric_limits<uint32_t>::max();
        REQUIRE(!strutils::parse_uint("4294967296", result));
    }
    TEST_CASE("Invalid prefix") {
        uint32_t result;
        REQUIRE(!strutils::parse_uint("   123456789", result));
    }
    TEST_CASE("Invalid character in the middle") {
        uint32_t result;
        REQUIRE(!strutils::parse_uint("1234x56789", result));
    }
    TEST_CASE("Invalid postfix") {
        uint32_t result;
        REQUIRE(!strutils::parse_uint("123456789 x", result));
    }
}
