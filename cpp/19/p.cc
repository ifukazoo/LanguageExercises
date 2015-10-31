#include <cctype>
#include <cmath>
#include <iostream>
#include <string>

#include "functions.h"

int main()
{
  typedef std::string String;
  String input_height, input_weight;

  std::cout << "Enter your height:";
  std::cin >> input_height;
  std::cout << "Enter your weight:";
  std::cin >> input_weight;

  std::pair<bool, double> result;
  result = str_to_f<double>(input_height);
  if (!result.first) {
    return EXIT_FAILURE;
  }
  double height = result.second;

  result = str_to_f<double>(input_weight);
  if (!result.first) {
    return EXIT_FAILURE;
  }
  double weight = result.second;

  double bmi = (weight / (height * height)) * 703;
  double bmi10 = round(bmi * 10);

  std::cout << "Yor BMI is " << bmi10 / 10.0 << "." << std::endl;
  if (185 <= bmi10 && bmi10 <= 250) {
    std::cout << "Yor are whthin the ideal weight range." << std::endl;
  } else {
    std::cout << "Yor are " << (bmi10 < 185 ? "underweight" : "overweight") << ". You should see your doctor." << std::endl;
  }
  return EXIT_SUCCESS;
}
