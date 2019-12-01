#include <iostream>

int main()
{
    std::string input;
    std::cout
        << "Press C to convert from Fahrenheit to Celsius." << std::endl
        << "Press F to convert from Celsius to Fahrenheit." << std::endl
        << "Your choice: ";
    std::getline(std::cin, input);

    std::string from, to;
    if (std::toupper(input.at(0)) == 'C') {
        from = "Fahrenheit";
        to =   "Celsius";
    } else {
        from = "Celsius";
        to =   "Fahrenheit";
    }

    std::cout << "Please enter the temperature in " << from << ": ";
    std::getline(std::cin, input);
    double source = std::stof(input);

    double result;
    if (to == "Celsius") {
        result = (source - 32.0) * 5.0 / 9.0;
    } else {
        result = (source * 9.0 / 5.0) + 32.0;
    }
    std::cout << "The temperature in " << to << " is " << result << std::endl;

    return 0;
}
