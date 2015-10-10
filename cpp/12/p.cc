#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>

#include "functions.h"

typedef std::string String;

int main()
{
  String input_principal, input_interest, input_years;
  std::cout << "Enter the principal: ";
  std::cin >> input_principal;
  std::cout << "Enter the rate of interest: ";
  std::cin >> input_interest;
  std::cout << "Enter the number of years: ";
  std::cin >> input_years;

  typedef std::pair<bool, double> Result;

  double principal, interest;
  int years;
  Result result;
  result = str_to_f<double>(input_principal);
  if (!result.first) return EXIT_FAILURE;
  principal = result.second;
  result = str_to_f<double>(input_interest);
  if (!result.first) return EXIT_FAILURE;
  interest = result.second;
  result = str_to_i<int>(input_years);
  if (!result.first) return EXIT_FAILURE;
  years = result.second;

  double investment = principal * (100 + (interest * years));
  investment = round(investment) / 100.0;

  std::cout << "After " << years << " years at " << interest << "%,  the investment will be worth $" << investment << "." << std::endl;

  return EXIT_SUCCESS;
}
