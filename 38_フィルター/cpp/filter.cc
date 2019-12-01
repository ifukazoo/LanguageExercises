#include "filter.h"

namespace filter {
std::vector<int> filter_even_numbers(const std::vector<int>& numbers) {
    std::vector<int> evens;
    for (auto it = numbers.begin(); it != numbers.end(); it++) {
        if (*it % 2 == 0) {
            evens.push_back(*it);
        }
    }
    return evens;
}
}
