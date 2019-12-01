#include <cmath>
#include <iostream>
#include <iomanip>

int main()
{
    std::string input;
    std::cout << "Enter the principal: ";
    std::getline(std::cin, input);
    int principal = std::stoi(input);

    std::cout << "Enter the rate of interest: ";
    std::getline(std::cin, input);
    double rate_of_interest = std::stof(input);

    std::cout << "Enter the number of years: ";
    std::getline(std::cin, input);
    int years = std::stoi(input);

    double amount = principal * (1 + ((rate_of_interest / 100.0) * years));
    amount = round(amount * 100.0) / 100.0;

    std::cout << std::fixed    << std::setprecision(2)
      << "After " << years << " years at " << rate_of_interest << "%,"
      << " the investment will be worth $" << amount << "." << std::endl;

    return 0;
}
