#include <iostream>
#include "user_input.h"

namespace {

bool validate_number(const std::string& s, int& value) {
    try {
        value = std::stoi(s);
    } catch (std::invalid_argument e) {
        return false;
    } catch (std::out_of_range e) {
        return false;
    }
    return true;
}

bool validate_rate(const std::string& s, int& value) {
    if (!validate_number(s, value)) {
        return false;
    }
    if (value == 0) {
        return false;
    }
    return true;
}
}
int main() {
    auto invalid_msg = "Sorry. That's not a valid input.";

    int rate = read_user_input_with_validator<int>(
        "What is the rate of return? ", validate_rate, invalid_msg);
    int years = 72 / rate;
    std::cout << "It will take " << years
              << " years to double your initial investment.\n";

    exit(EXIT_SUCCESS);
}
