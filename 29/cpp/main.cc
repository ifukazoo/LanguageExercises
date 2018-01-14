#include <iostream>
#include "user_input.h"

namespace {
bool safe_stoi(const std::string& s, int& value) {
    try {
        value = std::stoi(s);
    } catch (std::invalid_argument e) {
        return false;
    } catch (std::out_of_range e) {
        return false;
    }
    return true;
}

int read_user_input_int(const std::string& prompter,
                        const std::string& invalid_msg) {
    int value;
    if (!read_user_input<int>(prompter, invalid_msg, safe_stoi, value)) {
        exit(EXIT_FAILURE);
    }
    return value;
}
}
int main() {
    auto invalid_msg = "Sorry. That's not a valid input.";

retry:
    int rate = read_user_input_int("What is the rate of return? ", invalid_msg);
    if (rate == 0) {
        std::cout << invalid_msg << std::endl;
        goto retry;
    }
    int years = 72 / rate;
    std::cout << "It will take " << years
              << " years to double your initial investment.\n";

    exit(EXIT_SUCCESS);
}
