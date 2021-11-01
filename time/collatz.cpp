#include "collatz.hpp"

#include <stdexcept>
#include <string>

#include "doctest.h"

long long get_longest_collatz_sequence_start(long long const upper_limit) {
    if (upper_limit < 1) {
        using namespace std::string_literals;
        throw std::invalid_argument("Expected an integral upper limit > 0, but got: "s + std::to_string(upper_limit));
    }
    auto longest_start = 1LL;
    auto longest_sequence_length = 1LL;
    auto sequence_length_cache = std::vector<long long>(upper_limit); // cache calculated sequence lengths <= upper limit
    for (auto start = longest_start; start <= upper_limit; ++start) {
        auto sequence_length = get_collatz_sequence_length(start, sequence_length_cache);
        if (sequence_length > longest_sequence_length) {
            longest_start = start;
            longest_sequence_length = sequence_length;
        }
        if (start < upper_limit) {
            sequence_length_cache[start - 1] = sequence_length; // cache last calculated sequence length
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

long long get_collatz_sequence_length(long long const start, std::vector<long long> const & sequence_length_cache) {
    if (start < 1) {
        using namespace std::string_literals;
        throw std::invalid_argument("Expected an integral upper limit > 0, but got: "s + std::to_string(start));
    }
    auto n = start;
    auto sequence_length = 0LL;
    while (n > 1) {
        // Attempt to re-use a previously calculated sequence length:
        if (n <= sequence_length_cache.size() && sequence_length_cache[n - 1] > 0) {
            sequence_length += sequence_length_cache[n - 1];
            return sequence_length;
        }
        if (n % 2 == 0) { // n is even
            n /= 2;
        } else { // n is odd
            n = (3 * n) + 1;
        }
        sequence_length += 1;
    }
    sequence_length += 1; // account for the last element (1)
    return sequence_length;
}

TEST_CASE("Testing the Collatz sequence length algorithm") {
    auto sequence_length_cache = std::vector<long long>(5);
    sequence_length_cache[3] = 3; // start = 4, length = 3 (treating array as 1-indexed to suit algorithm)
    CHECK(get_collatz_sequence_length(5, sequence_length_cache) == 6);
    CHECK_THROWS_AS(get_collatz_sequence_length(0, sequence_length_cache), std::invalid_argument const &);
    CHECK_THROWS_AS(get_collatz_sequence_length(-1, sequence_length_cache), std::invalid_argument const &);
}