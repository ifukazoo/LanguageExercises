#include <iostream>
#include <vector>

#include "filter.h"
#include "user_input.h"
#include "utility.h"

namespace {

bool validate_num_vector(const std::string& s, std::vector<int>& value) {
    auto strings = split(s);
    for (auto s : strings) {
        try {
            int n = std::stoi(s);
            value.push_back(n);
        } catch (std::invalid_argument e) {
            return false;
        } catch (std::out_of_range e) {
            return false;
        }
    }
    return true;
}

}  // namespace

int main() {
    auto invalid_msg = "Sorry. That's not a valid input.";
    auto input_array = read_user_input_with_validator<std::vector<int>>(
        "Enter a list of numbers, separated by spaces: ", validate_num_vector,
        invalid_msg);
    auto evens = filter::filter_even_numbers(input_array);

    std::cout << "The even numbers are";
    for (auto n : evens) {
        std::cout << " " << n;
    }
    std::cout << std::endl;

    return 0;
}
