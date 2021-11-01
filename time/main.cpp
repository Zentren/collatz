#include <iostream>
#include <stdexcept>
#include <string>

#include "collatz.hpp"

int main(int argc, char * argv[]) {
    if (argc > 1) {
        long long upper_limit;
        try {
            upper_limit = std::stoll(std::string(argv[1]));
        } catch (std::invalid_argument const & e) {
            std::cout << "Cannot parse the given argument '" << argv[1] << "' as an integer." << std::endl;
            return EXIT_FAILURE;
        } catch (std::out_of_range const & e) {
            std::cout << "Given argument " << argv[1] << " is outside the allowed range." << std::endl;
            return EXIT_FAILURE;
        }
        try {
            auto longest_collatz_sequence = get_longest_collatz_sequence_start(upper_limit);
            std::cout << "The longest Collatz sequence starting <= " << upper_limit << " starts at " << longest_collatz_sequence << '.' << std::endl;
        } catch (std::invalid_argument const & e) {
            std::cout << e.what();
            return EXIT_FAILURE;
        }
    } else {
        std::cout << "Expected an argument." << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}