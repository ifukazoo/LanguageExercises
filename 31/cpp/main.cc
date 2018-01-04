#include <functional>
#include <iostream>
#include <sstream>

#include "karvonen.h"

namespace {
std::string input(const std::string& prompter) {
    std::string user_input;
    std::cout << prompter;
    std::getline(std::cin, user_input);
    return user_input;
}

template <typename T>
T read_user_input(const std::string& prompter,
                  std::function<bool(const std::string&, T&)> converter) {
    T output;
    for (;;) {
        std::string user_input = input(prompter);
        if (std::cin.eof()) {
            break;
        }
        if (!converter(user_input, output)) {
            std::cout << "Sorry. That's not a valid input." << std::endl;
            continue;
        }
        break;
    }
    return output;
}

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

void check_and_exit_if_eof() {
    if (std::cin.eof()) {
        std::cerr << "failed to read user input.\n";
        exit(EXIT_FAILURE);
    }
}
}  // namespace

int main() {
    int age = read_user_input<int>("Enter your age: ", safe_stoi);
    check_and_exit_if_eof();
    int resting_pulse =
        read_user_input<int>("Enter your resting pulse: ", safe_stoi);
    check_and_exit_if_eof();

    std::cout << title();
    std::cout << separator();
    for (int intensity = 55; intensity <= 95; intensity += 5) {
        int rate = calc_heart_rate(age, resting_pulse, intensity);
        std::cout << heart_rate_line(intensity, rate);
    }
    return EXIT_SUCCESS;
}
