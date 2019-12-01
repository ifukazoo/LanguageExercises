#include <cmath>
#include <iostream>

int main()
{
    std::string input;

    std::cout << "How many euros are you exchanging? ";
    std::getline(std::cin, input);
    int euros = std::stoi(input);

    std::cout << "What is the exchange rate? ";
    std::getline(std::cin, input);
    double rate = std::stof(input);

    auto usdollars = euros * rate / 100.0;
    usdollars = round(usdollars * 100) / 100.0;

    std::cout << euros << " euros at an exchante rate of " << rate << " is "
        << usdollars << " U.S. dollars." << std::endl;
}
