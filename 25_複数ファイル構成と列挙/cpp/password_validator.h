#ifndef _PASSWORD_VALIDATOR_H_
#define _PASSWORD_VALIDATOR_H_

#include <string>

enum class Strength {
    VERY_WEAK,
    WEAK,
    NORMAL,
    STRONG,
    VERY_STRONG,
};

namespace {
const int kPasswordLenghtMin = 8;
};

Strength password_validator(const std::string& password);

#endif
