#include <iostream>
#include <string>

int main()
{
    std::string first_number, second_number;
    std::cout << "What is the first number? ";
    std::getline(std::cin, first_number);

    long first = std::stoi(first_number);

    std::cout << "What is the second number? ";
    std::getline(std::cin, second_number);

    long second = std::stoi(second_number);

    std::cout << first << " + " << second << " = " << first + second << std::endl;
    std::cout << first << " - " << second << " = " << first - second << std::endl;
    std::cout << first << " * " << second << " = " << first * second << std::endl;
    std::cout << first << " / " << second << " = " << first / second << std::endl;

    return 0;
}
