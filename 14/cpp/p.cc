#include <cmath>
#include <iomanip>
#include <iostream>

const double kTaxWI = 5.5;

int main()
{
    std::string input;

    std::cout << "What is the order amount? ";
    std::getline(std::cin, input);
    double amount = std::stof(input);

    std::cout << "What is the state? ";
    std::getline(std::cin, input);
    std::string state = input;

    double tax = 0.0;
    std::cout << std::fixed << std::showpoint << std::setprecision(2);
    if (state == "WI") {
        tax = amount * (kTaxWI / 100.0);
        std::cout
            << "The subtotal is $" << amount << "." << std::endl
            << "The tax is $"      << tax    << "." << std::endl;
    }
    double total_amount = round((amount + tax) * 100.0) / 100.0;
    std::cout << "The total is $" << total_amount << "." << std::endl;

    return 0;
}
