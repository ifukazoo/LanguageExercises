#include <iostream>

namespace {

std::string input(const std::string& msg) {
    std::string user_input;
    std::cout << msg;
    std::getline(std::cin, user_input);
    return user_input;
}

void show_error_msg() { std::cout << "Sorry. That's not a valid input.\n"; }
}

int main() {
    for (;;) {
        auto user_input = input("What is the rate of return? ");
        try {
            int rate = std::stoi(user_input);
            if (rate == 0) {
                show_error_msg();
                continue;
            }
            int years = 72 / rate;
            std::cout << "It will take " << years
                      << " years to double your initial investment.\n";
            break;
        } catch (std::invalid_argument e) {
            show_error_msg();
            continue;
        } catch (std::out_of_range e) {
            show_error_msg();
            continue;
        }
    }
    return 0;
}
