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

}  // namespace

int main() {
    bool eof;
    int age = read_user_input_int("Enter your age: ", eof);
    if (eof) {
        exit_by_eof();
    }
    int resting_pulse = read_user_input_int("Enter your resting pulse: ", eof);
    if (eof) {
        exit_by_eof();
    }

    std::cout << title();
    std::cout << separator();
    for (int intensity = 55; intensity <= 95; intensity += 5) {
        int rate = calc_heart_rate(age, resting_pulse, intensity);
        std::cout << heart_rate_line(intensity, rate);
    }
    return EXIT_SUCCESS;
}