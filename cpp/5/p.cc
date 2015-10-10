#include <cstdlib>
#include <cctype>
#include <cerrno>
#include <string>
#include <iostream>
#include <numeric>
#include <limits>

#include "functions.h"

typedef std::string String;

int main()
{
  long first, second;
  String first_in, second_in;
  while (true) {
    std::cout << "What is the first number? ";
    std::cin >> first_in;
    std::cout << "What is the second number? ";
    std::cin >> second_in;

    std::pair<bool, long> result_first = str_to_i<long>(first_in);
    if (!result_first.first) {
      std::cout << "illegal first number" << std::endl;
      continue;
    }
    std::pair<bool, long> result_second = str_to_i<long>(second_in);
    if (!result_second.first) {
      std::cout << "illegal second number" << std::endl;
      continue;
    }
    first = result_first.second;
    second = result_second.second;
    break;
  }

  std::cout << first << " + " << second << " = " << first + second << std::endl;
  std::cout << first << " - " << second << " = " << first - second << std::endl;
  std::cout << first << " * " << second << " = " << first * second << std::endl;
  std::cout << first << " / " << second << " = " << first / second << std::endl;

  return 0;
}
