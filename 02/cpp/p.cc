#include <limits>
#include <iostream>

int main()
{
    std::cout << "What is the input string? ";
    std::string input;
    std::getline(std::cin, input);
    std::cout << input << " has " << input.size() << " characters." << std::endl;
    return 0;
}
