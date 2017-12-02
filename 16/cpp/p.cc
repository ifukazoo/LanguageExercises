#include <iostream>

const int kLegalDrivingAge = 16;

int main()
{
    std::string input;
    std::cout << "What is your age? ";
    std::getline(std::cin, input);
    int age = std::stoi(input);
    std::cout
        << "You are " << (age < kLegalDrivingAge ? "not " : "")
        << "old enough to legally drive." << std::endl;

    return 0;
}
