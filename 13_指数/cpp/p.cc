#include <cmath>
#include <iostream>

int main()
{
    std::string input;
    std::cout << "What is the pricipal amount? ";
    std::getline(std::cin, input);
    int principal_amount = std::stoi(input);

    std::cout << "What is the rate? ";
    std::getline(std::cin, input);
    double rate = std::stof(input);

    std::cout << "What is the number of years? ";
    std::getline(std::cin, input);
    int number_of_years = std::stoi(input);

    std::cout << "What is the number of times the interest is compound per year? ";
    std::getline(std::cin, input);
    int number_of_years_per_year = std::stoi(input);

    // percent := rate / 100.0
    // exponent := numberOfYears * numberOfYearsPerYear
    // amount := float64(principalAmount) * math.Pow(1.0+(percent/float64(numberOfYearsPerYear)), float64(exponent))
    // amount = math.Ceil(amount*100) / 100

    double percent = static_cast<double>(rate) / 100.0;
    double exponent = static_cast<double>(number_of_years * number_of_years_per_year);
    double amount = static_cast<double>(principal_amount) * pow(1.0 + (percent / number_of_years_per_year), exponent);
    amount = ceil(amount * 100) / 100;

    std::cout << "$" << principal_amount << " invested at "
        << rate << "% for "
        << number_of_years << " years compounded "
        << number_of_years_per_year << " times per year is "
        << "$" << amount << "." << std::endl;

    return 0;
}
