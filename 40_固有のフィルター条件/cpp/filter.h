#ifndef _FILTER_H_
#define _FILTER_H_

#include <algorithm>
#include <functional>
#include <vector>

namespace filter {

template <typename T>
void filter_if(const std::vector<T>& input,
               std::function<bool(const T&)> filter_func,
               std::vector<T>& results) {
    auto it = input.begin();
    while (it != input.end()) {
        it = std::find_if(it, input.end(), filter_func);
        if (it != input.end()) {
            results.push_back(*it);
            it++;
        }
    }
}
}

#endif
