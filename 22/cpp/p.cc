#include <iostream>
#include <limits>

int main()
{
    std::string input;

    std::cout << "Enter the first number: ";
    std::getline(std::cin, input);
    auto first = stoi(input);

    std::cout << "Enter the second number: ";
    std::getline(std::cin, input);
    auto second = stoi(input);

    std::cout << "Enter the third number: ";
    std::getline(std::cin, input);
    auto third = stoi(input);

    if ((first == second) || (first == third) || (second == third)) {
        // exit
        return 1;
    }

    auto max = std::numeric_limits<int>::min();
    if (max < first) {
        max = first;
    }
    if (max < second) {
        max = second;
    }
    if (max < third) {
        max = third;
    }
    std::cout << "The largest number is " << max << "." << std::endl;

    return 0;
}
