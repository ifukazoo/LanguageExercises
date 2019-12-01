#include <ctime>
#include <iostream>

int main()
{
    std::string input;

    std::cout << "What is your current age? ";
    std::getline(std::cin, input);
    int age = std::stoi(input);

    std::cout << "At What age would you like to retire? ";
    std::getline(std::cin, input);
    int retire_age = std::stoi(input);

    int remain = retire_age - age;

    std::time_t t = std::time(nullptr);
    std::tm* tm = std::localtime(&t);
    int this_year = 1900 + tm->tm_year;
    std::cout << "You have " << remain << " years left until you can retire." << std::endl;
    std::cout << "It's " << this_year << ", so you can retire in "<< this_year + remain << std::endl;

    return 0;
}
