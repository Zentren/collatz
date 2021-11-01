#ifndef COLLATZ_H
#define COLLATZ_H

#include <vector>

long long get_longest_collatz_sequence_start(long long const upper_limit);
long long get_collatz_sequence_length(long long const start, std::vector<long long> const & sequence_length_cache);

#endif /* COLLATZ_H */