#include <cassert>
#include <iostream>

#include "calculator.h"

int main()
{
    std::string input;

    std::cout << "What is your balance? ";
    std::getline(std::cin, input);
    int balance = std::stoi(input);

    std::cout << "What is the ARP on the card (as a percent)? ";
    std::getline(std::cin, input);
    int arp = std::stoi(input);

    std::cout << "What is the monthly payment you can make? ";
    std::getline(std::cin, input);
    int payment = std::stoi(input);

    int months = calculate_months_until_paid_off(balance, arp, payment);
    if (months < 0) {
        std::cerr << "You can't pay off this card." << std::endl;
        exit(1);
    }
    std::cout << "It will take you " << months << " months to pay off this card." << std::endl;

    return 0;
}

