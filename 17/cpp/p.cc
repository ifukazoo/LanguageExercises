#include <iostream>
#include <iomanip>

int main()
{
    std::string input;
    int gender, num_hours;
    double weight, amount_of_alcohol;

    std::cout << "What is your weight? ";
    std::getline(std::cin, input);
    weight = std::stof(input);

    std::cout << "Which is your gender 1:male 2:femail ? ";
    std::getline(std::cin, input);
    gender = std::stoi(input);

    std::cout << "What is the amount of alcohol by volume? ";
    std::getline(std::cin, input);
    amount_of_alcohol = std::stof(input);

    std::cout << "How long has it passed since you drunk? ";
    std::getline(std::cin, input);
    num_hours = std::stoi(input);

    double A = amount_of_alcohol;
    double W = weight;
    double r = (gender == 1) ? 0.73 : 0.66;
    double H = static_cast<double>(num_hours);
    double bac = (A * 5.14 / W * r) - 0.015 * H;
    // A is total alcohol consumed, in ounces (oz).
    // W is body weight in pounds.
    // r is the alcohol distribution ratio:
    //   0.73 for men
    //   0.66 for women
    // H is number of hours since the last drink.

    std::cout << std::fixed << std::setprecision(2)
     << "Your BAC is " << bac << std::endl
     << "It is" << (bac <= 0.08 ? "" : " not") << " legal for you to drive." << std::endl;

    return 0;
}
