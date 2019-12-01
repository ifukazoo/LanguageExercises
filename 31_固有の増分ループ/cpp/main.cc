#include <iostream>
#include <sstream>

#include "karvonen.h"
#include "user_input.h"

namespace {
std::string partition_format(const std::string& left,
                             const std::string& right) {
    return std::string(left + "|" + right + "\n");
}

std::string title() { return partition_format("Intensity\t", " Rate"); }

std::string separator() {
    return partition_format("----------------", "----------");
}

std::string heart_rate_line(int intensity, int rate) {
    std::ostringstream left, right;
    left << intensity << "%\t\t";
    right << " " << rate << " bpm";
    return partition_format(left.str(), right.str());
}

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

const std::string INVALID_MSG = "Sorry. That's not a valid input.";

}  // namespace

int main() {
    int age = read_user_input_with_validator<int>("Enter your age: ",
                                                  validate_number, INVALID_MSG);
    int resting_pulse = read_user_input_with_validator<int>(
        "Enter your resting pulse: ", validate_number, INVALID_MSG);

    std::cout << title();
    std::cout << separator();
    for (int intensity = 55; intensity <= 95; intensity += 5) {
        int rate = calc_heart_rate(age, resting_pulse, intensity);
        std::cout << heart_rate_line(intensity, rate);
    }
    return EXIT_SUCCESS;
}
