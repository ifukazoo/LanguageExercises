#include <cassert>
#include <iostream>

#include "password_validator.h"

inline std::string strength_to_string(Strength strength)
{
    switch(strength) {
    case Strength::VERY_WEAK:
        return "very weak";
    case Strength::WEAK:
        return "weak";
    case Strength::NORMAL:
        return "normal";
    case Strength::STRONG:
        return "strong";
    case Strength::VERY_STRONG:
        return "very strong";
    default:
        break;
    }
    assert(true);
}

inline void output(const std::string& s)
{
    auto strength = password_validator(s);
    std::cout << "The password '" << s << "' is a " << strength_to_string(strength) << " password." << std::endl;
}

int main()
{
    output("12345");
    output("abcdef");
    output("abc123xyz");
    output("1337h@xor!");

    return 0;
}

