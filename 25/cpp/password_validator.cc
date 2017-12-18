#include <cctype>
#include <algorithm>

#include "password_validator.h"

Strength password_validator(const std::string& password)
{
    auto number_only      = std::all_of(password.begin(), password.end(), isdigit);
    auto letter_only      = std::all_of(password.begin(), password.end(), isalpha);
    auto contains_special = std::any_of(password.begin(), password.end(), ispunct);
    auto contains_letter  = std::any_of(password.begin(), password.end(), isalpha);
    auto contains_number  = std::any_of(password.begin(), password.end(), isdigit);
    auto too_short = password.length() < kPasswordLenghtMin;
    if (too_short) {
        if (number_only) {
            return Strength::VERY_WEAK;
        } else if (letter_only) {
            return Strength::WEAK;
        }
    } else {
        if (contains_letter && contains_number && contains_special) {
            return Strength::VERY_STRONG;
        }
        if (contains_letter && contains_number) {
            return Strength::STRONG;
        }
    }
    return Strength::NORMAL;
}
