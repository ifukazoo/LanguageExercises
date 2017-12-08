#include <cmath>
#include <iostream>

int main()
{
    std::string input;

  std::cout << "Enter your height(inch): ";
  std::getline(std::cin, input);
  auto height = std::stof(input);

  std::cout << "Enter your weight(pound): ";
  std::getline(std::cin, input);
  auto weight = std::stof(input);

  auto bmi = (weight / (height * height)) * 703;
  bmi = round(bmi * 10) / 10.0;

  std::cout << "Yor BMI is " << bmi << "." << std::endl;

  if (bmi < 18.5) {
    std::cout << "Yor are underweight. You should see your doctor." << std::endl;
  } else if (18.5 <= bmi && bmi <= 25) {
    std::cout << "Yor are whthin the ideal weight range." << std::endl;
  } else {
    std::cout << "Yor are overweight. You should see your doctor." << std::endl;
  }
  return 0;
}
