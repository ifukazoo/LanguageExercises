#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>

#include "functions.h"

typedef std::string String;

int main()
{
  String input_principal, input_rate, input_years, input_compound_per_year;
  std::cout << "What is the pricipal amount? ";
  std::cin >> input_principal;
  std::cout << "What is the rate? ";
  std::cin >> input_rate;
  std::cout << "What is the number of years? ";
  std::cin >> input_years;
  std::cout << "What is the number of times the interest is compound per year? ";
  std::cin >> input_compound_per_year;

  typedef std::pair<bool, double> Result;

  double principal, rate;
  int years, compound_per_year;
  Result result;
  result = str_to_f<double>(input_principal);
  if (!result.first) return EXIT_FAILURE;
  principal = result.second;
  result = str_to_f<double>(input_rate);
  if (!result.first) return EXIT_FAILURE;
  rate = result.second;
  result = str_to_i<int>(input_years);
  if (!result.first) return EXIT_FAILURE;
  years = result.second;
  result = str_to_i<int>(input_compound_per_year);
  if (!result.first) return EXIT_FAILURE;
  compound_per_year = result.second;

  int count = years * compound_per_year;
  double rate_for_compound = 100 +  (rate / compound_per_year);
  double investment = principal;
  while (count) {
    investment = investment * rate_for_compound / 100;
    count--;
  }
  investment = round(investment * 100) / 100.0;

  std::cout << "$" << principal << " invested at "
    << rate << "% for "
    << years << " years compounded "
    << compound_per_year << " times per year is "
    << "$" << investment << "." << std::endl;

  return EXIT_SUCCESS;
}
