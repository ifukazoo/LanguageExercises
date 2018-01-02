#include <iostream>

namespace {
std::string input(const std::string& msg) {
    std::string user_input;
    std::cout << msg;
    std::getline(std::cin, user_input);
    return user_input;
}
}

int main() {
    int total = 0;
    for (int i = 0; i < 5; i++) {
        auto user_input = input("Enter a number: ");
        total += std::stoi(user_input);
    }

    std::cout << "The total is " << total << ".\n";

    return 0;
}
