// This tells doctest to provide a main() function
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "tasks.h"


TEST_SUITE("Checksum") {
    TEST_CASE("Int zero") {
        REQUIRE(calculate_checksum(0) == 0);
    }

    TEST_CASE("Int") {
        REQUIRE(calculate_checksum(0xDFABCAFE) == 850);
    }

    TEST_CASE("Int max") {
        REQUIRE(calculate_checksum(0xFFFFFFFF) == 1020);
    }

    TEST_CASE("String zero") {
        REQUIRE(calculate_checksum("0.0.0.0") == 0);
    }

    TEST_CASE("String") {
        REQUIRE(calculate_checksum("223.171.202.254") == 850);
    }

    TEST_CASE("String 2") {
        REQUIRE(calculate_checksum("85.16.2.255") == 358);
    }

    TEST_CASE("String max") {
        REQUIRE(calculate_checksum("223.171.202.254") == 850);
    }
}
/*
TEST_SUITE("Parser") {
    TEST_CASE("Parse digit") {
        REQUIRE(parse_digit("") == nullptr);
        REQUIRE(parse_digit("a") == nullptr);

        auto a = "1";
        REQUIRE(parse_digit(a) == a + 1);
    }

    TEST_CASE("Parse char") {
        auto parser1 = create_char_parser('x');

        REQUIRE(parser1("") == nullptr);
        REQUIRE(parser1("a") == nullptr);

        auto a = "x";
        REQUIRE(parser1(a) == a + 1);
    }

    TEST_CASE("Parse word single character") {
        auto parser1 = create_word_parser("x");

        REQUIRE(parser1("") == nullptr);
        REQUIRE(parser1("a") == nullptr);

        auto a = "x";
        REQUIRE(parser1(a) == a + 1);
    }

    TEST_CASE("Parse word multiple characters") {
        auto parser1 = create_word_parser("foo");

        REQUIRE(parser1("") == nullptr);
        REQUIRE(parser1("a") == nullptr);
        REQUIRE(parser1("f") == nullptr);
        REQUIRE(parser1("fo") == nullptr);
        REQUIRE(parser1("foa") == nullptr);
        REQUIRE(parser1("fo0ooo") == nullptr);

        auto a = "foo";
        REQUIRE(parser1(a) == a + 3);

        auto b = "foo";
        REQUIRE(parser1(b) == b + 3);
    }

    TEST_CASE("Parse any of") {
        auto parser1 = first_match(std::vector<Parser>{
                parse_digit,
                create_char_parser('x')
        });

        REQUIRE(parser1("") == nullptr);

        auto a = "x";
        REQUIRE(parser1(a) == a + 1);

        auto b = "1";
        REQUIRE(parser1(b) == b + 1);

        auto c = "y";
        REQUIRE(parser1(c) == nullptr);
    }

    TEST_CASE("Parse sequence") {
        auto parser1 = sequence(std::vector<Parser>{
                parse_digit,
                create_char_parser('x'),
                parse_digit,
                create_word_parser("end")
        });

        REQUIRE(parser1("") == nullptr);
        REQUIRE(parser1("1") == nullptr);
        REQUIRE(parser1("1x") == nullptr);
        REQUIRE(parser1("1x1") == nullptr);
        REQUIRE(parser1("1x1en") == nullptr);
        REQUIRE(parser1("1x1foo") == nullptr);
        REQUIRE(parser1("x1x2end") == nullptr);

        auto a = "1x1endbar";
        REQUIRE(parser1(a) == a + 6);
    }

    TEST_CASE("Parse repeat") {
        auto parser1 = repeat(parse_digit, 3);

        REQUIRE(parser1("") == nullptr);
        REQUIRE(parser1("1") == nullptr);
        REQUIRE(parser1("12") == nullptr);
        REQUIRE(parser1("12x") == nullptr);

        auto a = "123";
        REQUIRE(parser1(a) == a + 3);
    }
    TEST_CASE("Parse complex") {
        auto parser1 = first_match(std::vector<Parser>{
                parse_digit,
                create_char_parser('x'),
        });
        auto parser2 = repeat(parse_digit, 2);
        auto parser3 = sequence(std::vector<Parser>{parser1, parser2});

        REQUIRE(parser3("") == nullptr);
        REQUIRE(parser3("y23") == nullptr);
        REQUIRE(parser3("12") == nullptr);
        REQUIRE(parser3("x") == nullptr);

        auto a = "123";
        REQUIRE(parser3(a) == a + 3);

        auto b = "x34";
        REQUIRE(parser3(b) == b + 3);
    }
}
TEST_SUITE("UTF-8 validation") {
    TEST_CASE("Empty") {
        std::vector<uint8_t> input{};
        size_t result = std::numeric_limits<size_t>::max();
        REQUIRE(validate_utf8(input, result));
        REQUIRE(result == 0);
    }
    TEST_CASE("Simple") {
        std::vector<uint8_t> input{
            0b01100001,
            0b01101000,
            0b01101111,
            0b01101010
        };
        size_t result = std::numeric_limits<size_t>::max();
        REQUIRE(validate_utf8(input, result));
        REQUIRE(result == 4);
    }
    TEST_CASE("Complex points") {
        std::vector<uint8_t> input{
                0b01001100,
                0b11000011,
                0b10101101,
                0b01100010,
                0b11000011,
                0b10101101,
                0b00100000,
                0b01110011,
                0b01100101,
                0b00100000,
                0b01110100,
                0b01101001,
                0b00100000,
                0b01000011,
                0b00101011,
                0b00101011,
                0b00111111,
                0b00100000,
                0b11110000,
                0b10011111,
                0b10011000,
                0b10000000
        };
        size_t result = std::numeric_limits<size_t>::max();
        REQUIRE(validate_utf8(input, result));
        REQUIRE(result == 17);
    }
    TEST_CASE("Invalid input 1") {
        std::vector<uint8_t> input{0b11111111};
        size_t result = std::numeric_limits<size_t>::max();
        REQUIRE(!validate_utf8(input, result));
    }
    TEST_CASE("Invalid input 2") {
        std::vector<uint8_t> input{0b00001111, 0b10011001};
        size_t result = std::numeric_limits<size_t>::max();
        REQUIRE(!validate_utf8(input, result));
    }
    TEST_CASE("Invalid input 3") {
        std::vector<uint8_t> input{0b11000110, 0b10011001, 0b10010000};
        size_t result = std::numeric_limits<size_t>::max();
        REQUIRE(!validate_utf8(input, result));
    }
    TEST_CASE("Invalid input 4") {
        std::vector<uint8_t> input{0b11000110};
        size_t result = std::numeric_limits<size_t>::max();
        REQUIRE(!validate_utf8(input, result));
    }
    TEST_CASE("Invalid input 5") {
        std::vector<uint8_t> input{0b11000110, 0b00110110};
        size_t result = std::numeric_limits<size_t>::max();
        REQUIRE(!validate_utf8(input, result));
    }
    TEST_CASE("Invalid input 6") {
        std::vector<uint8_t> input{0b10110110};
        size_t result = std::numeric_limits<size_t>::max();
        REQUIRE(!validate_utf8(input, result));
    }
}
*/
