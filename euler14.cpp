// g++-10 -fopenmp euler14.cpp
/*
https://projecteuler.net/problem=14

The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/
#include <iostream>
#include <map>
#include <algorithm>
#include <omp.h>

size_t collatz_length(uint64_t n)
{
    size_t length = 1;
    while (n > 1)
    {
        if (n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            n = 3 * n + 1;
        }
        ++length;
        
    }
    return length;
}

int main()
{
    int n_threads = 16;
    std::map<uint64_t, size_t> collatz_lengths[n_threads];
    int end = 1e6+1;
    #pragma omp parallel num_threads(n_threads)
    {
        #pragma omp for
        for(uint64_t i = 0; i < end; ++i)
        {
            collatz_lengths[omp_get_thread_num()][i] = collatz_length(i);
        }
    }

    std::map<uint64_t, size_t> combined;
    for (int i = 0; i < n_threads; ++i)
    {
        combined.insert(collatz_lengths[i].begin(), collatz_lengths[i].end());
    }

    // for(auto const& pair : combined)
    // {
    //     std::cout << pair.first << ": " << pair.second << "\n";
    // }

    auto max = *std::max_element(combined.begin(), combined.end(),
            [](const auto& p1, const auto& p2)
            {
                return p1.second <= p2.second;
            }
            );
    std::cout << max.first << ": " << max.second << "\n";

    return 0;
}
