#include "collatz.hpp"

#include <stdexcept>
#include <string>

#include "doctest.h"

using namespace std::string_literals;

long long get_longest_collatz_sequence_start(long long const upper_limit) {
    if (upper_limit < 1) {
        throw std::invalid_argument("Expected an integral upper limit > 0, but got: "s + std::to_string(upper_limit));
    }
    auto longest_start = 1LL;
    auto longest_sequence_length = 1LL;
    for (auto start = longest_start; start <= upper_limit; ++start) {
        auto sequence_length = get_collatz_sequence_length(start);
        if (sequence_length > longest_sequence_length) {
            longest_start = start;
            longest_sequence_length = sequence_length;
        }
    }
    return longest_start;
}

TEST_CASE("Testing the longest Collatz sequence length algorithm") {
    CHECK(get_longest_collatz_sequence_start(1) == 1);
    CHECK(get_longest_collatz_sequence_start(10) == 9);
    CHECK(get_longest_collatz_sequence_start(100) == 97);
    CHECK(get_longest_collatz_sequence_start(1000) == 871);
    CHECK(get_longest_collatz_sequence_start(10000) == 6171);
    CHECK(get_longest_collatz_sequence_start(1000000) == 837799);
    CHECK_THROWS_AS(get_longest_collatz_sequence_start(0), std::invalid_argument const &);
    CHECK_THROWS_AS(get_longest_collatz_sequence_start(-1), std::invalid_argument const &);
}

long long get_collatz_sequence_length(long long const start) {
    if (start < 1) {
        throw std::invalid_argument("Expected an integral upper limit > 0, but got: "s + std::to_string(start));
    }
    auto n = start;
    auto sequence_length = 1LL; // account for the last element (1)
    while (n > 1) {
        if (n % 2 == 0) { // n is even
            n /= 2;
        } else { // n is odd
            n = (3 * n) + 1;
        }
        sequence_length += 1;
    }
    return sequence_length;
}

TEST_CASE("Testing the Collatz sequence length algorithm") {
    CHECK(get_collatz_sequence_length(1) == 1);
    CHECK(get_collatz_sequence_length(13) == 10);
    CHECK(get_collatz_sequence_length(16) == 5);
    CHECK(get_collatz_sequence_length(17) == 13);
    CHECK(get_collatz_sequence_length(27) == 112);
    CHECK(get_collatz_sequence_length(100) == 26);
    CHECK(get_collatz_sequence_length(639) == 132);
    CHECK_THROWS_AS(get_collatz_sequence_length(0), std::invalid_argument const &);
    CHECK_THROWS_AS(get_collatz_sequence_length(-1), std::invalid_argument const &);
}