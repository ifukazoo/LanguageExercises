#include <cmath>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include "functions.h"

typedef std::string String;
typedef std::pair<bool, double> Result;

const double tax_wi = 5.5;

int main()
{
  String input_amount, input_state;
  std::cout << "What is the order amount? ";
  std::cin >> input_amount;
  std::cout << "What is the state? ";
  std::cin >> input_state;

  Result result;
  result = str_to_f<double>(input_amount);
  if (!result.first) return EXIT_FAILURE;
  double amount = result.second;
  std::transform(input_state.begin(), input_state.end(), input_state.begin(), toupper);

  if (input_state == "WI") {
    std::cout << std::fixed << std::showpoint << std::setprecision(2);
    std::cout << "The subtotal is $" << amount << "." << std::endl;
    std::cout << "The tax is $" << tax_wi / 10.0 << "." << std::endl;
    amount = amount * (100 + tax_wi) / 100;
  }
  amount = round(amount * 100) / 100.0;
  std::cout << "The total is $" << std::showpoint << amount << std::endl;

  return EXIT_SUCCESS;
}
