#ifndef _UTILITY_H_
#define _UTILITY_H_

#include <sstream>
#include <string>
#include <vector>

namespace {

std::vector<std::string> split(const std::string& s) {
    std::vector<std::string> strings;
    std::istringstream is(s);
    std::string chunk;
    while (std::getline(is, chunk, ' ')) {
        if (chunk.empty()) {
            continue;
        }
        strings.push_back(chunk);
    }
    return strings;
}
}

#endif
