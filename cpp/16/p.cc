#include <termios.h>
#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <map>

#include "functions.h"

typedef std::string String;
typedef std::map<String, String> StringMap;

const int kLegal_Driving_Age = 16;

int main()
{
  String input_age;
  std::cout << "What is your age? ";
  std::cin >> input_age;

  typedef std::pair<bool, int> Result;
  Result result = str_to_i<int>(input_age);
  if (!result.first) {
    std::cout << "input integer value." << std::endl;
    return EXIT_FAILURE;
  }
  int age = result.second;
  if (age <= 0) {
    std::cout << "input positive value." << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "You are "
    << (age < kLegal_Driving_Age ? "not " : "")
    << "old enough to legally drive." << std::endl;

  return EXIT_SUCCESS;
}
