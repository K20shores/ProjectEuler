// g++-10 -fopenmp euler14.cpp
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
    std::map<uint64_t, size_t> collatz_lengths[16];
    int end = 1e6+1;
    #pragma omp parallel num_threads(16)
    {
        #pragma omp for
        for(uint64_t i = 0; i < end; ++i)
        {
            collatz_lengths[omp_get_thread_num()][i] = collatz_length(i);
        }
    }

    std::map<uint64_t, size_t> combined;
    for (int i = 0; i < 16; ++i)
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
