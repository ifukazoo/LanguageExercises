#include "anagram.h"

bool is_anagram(const std::string& lhs, const std::string& rhs)
{
    if (lhs.length() != rhs.length()) {
        return false;
    }

    for (auto it = lhs.cbegin(); it != lhs.cend(); it++) {
        if (rhs.find(*it) == std::string::npos) {
            return false;
        }
    }
    return true;
}
