#include <iostream>

#include "validator.h"

namespace {
std::string input(const std::string& msg) {
    std::string user_input;
    std::cout << msg;
    std::getline(std::cin, user_input);
    return user_input;
}
}

int main() {
    auto first_name = input("Enter the first name: ");
    auto last_name = input("Enter the last name: ");
    auto zip_code = input("Enter the ZIP code: ");
    auto employee_id = input("Enter an employee ID: ");

    std::string err_msg;
    auto success =
        validate_input(first_name, last_name, zip_code, employee_id, err_msg);
    if (success) {
        std::cout << "There were no errors found.\n";
    } else {
        std::cout << err_msg;
    }
    return 0;
}
