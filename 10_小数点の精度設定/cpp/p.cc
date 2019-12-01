#include <iostream>
#include <iomanip>

const double kTax = 5.5;
const int kRepeatCount = 3;

int main()
{
    std::string input;
    std::pair<int, int> items[kRepeatCount];

    for (int i = 0; i < kRepeatCount; i++) {
        std::cout << "Enter the price of item " << i + 1 << ": ";
        std::getline(std::cin, input);
        int price = std::stoi(input);

        std::cout << "Enter the quantity of item " << i + 1 << ": ";
        std::getline(std::cin, input);
        int quantity = std::stoi(input);

        auto pair = std::make_pair(price, quantity);
        items[i] = pair;
    }

    int subtotal = 0;
    for (int i = 0; i < kRepeatCount; i++) {
        int price = items[i].first * items[i].second;
        subtotal += price;
    }
    double tax = subtotal * kTax / 100.0;
    double total = subtotal + tax;

    std::cout << std::fixed    << std::setprecision(2)
              << "Subtotal: $" << static_cast<double>(subtotal) << std::endl
              << "Tax: $"      << tax                           << std::endl
              << "Total: $"    << total                         << std::endl
              ;

    return 0;
}

