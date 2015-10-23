#include <cmath>
#include <iostream>
#include <string>

#include "functions.h"

typedef std::string String;

int main()
{
  String input_weight, input_gender, input_num, input_abv, input_after;
  std::cout << "What is your weight? ";
  std::cin >> input_weight;
  std::cout << "What is your gender 1:male 2:femail ? ";
  std::cin >> input_gender;
  std::cout << "How many drinks do you have? ";
  std::cin >> input_num;
  std::cout << "What is the amount of alcohol by volume? ";
  std::cin >> input_abv;
  std::cout << "How long passes after drinking? ";
  std::cin >> input_after;

  typedef std::pair<bool, int> IntResult;
  typedef std::pair<bool, double> DoubleResult;
  DoubleResult weight_result = str_to_f<double>(input_weight);
  if (!weight_result.first) {
    return EXIT_FAILURE;
  }
  double weight = weight_result.second;

  IntResult gender_result = str_to_i<int>(input_gender);
  if (!gender_result.first) {
    return EXIT_FAILURE;
  }
  double alcohol_distribution = gender_result.second == 1 ? 0.73 : 0.66;

  IntResult num_result = str_to_i<int>(input_num);
  if (!num_result.first) {
    return EXIT_FAILURE;
  }
  int number = num_result.second;

  IntResult abv_result = str_to_i<int>(input_abv);
  if (!abv_result.first) {
    return EXIT_FAILURE;
  }
  int abv = abv_result.second;

  IntResult after_result = str_to_i<int>(input_after);
  if (!after_result.first) {
    return EXIT_FAILURE;
  }
  int after = after_result.second;

  double consumed_alcohol_oz = number * abv / 100.0 * 0.035274;
  double bac = ((consumed_alcohol_oz * 5.14) / (weight * alcohol_distribution))
    - (0.015 * after);

  bac  = round(bac * 100) / 100.0;
  std::cout << "Your BAC is " << bac << std::endl;
  std::cout << "It is" << (bac <= 0.08 ? "" : " not") << " legal for you to drive" << std::endl;

  return EXIT_SUCCESS;
}
