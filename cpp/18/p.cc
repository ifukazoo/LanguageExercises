#include <cctype>
#include <iostream>
#include <string>
#include <map>
#include <functional>

#include "functions.h"

double f_to_c(double before) {
    return (before - 32) * 5.0 / 9.0;
}
double c_to_f(double before) {
    return (before * 9.0 / 5.0) + 32;
}

int main()
{
  typedef std::string String;
  typedef std::map<char, String> StringMap;
  typedef std::map<char, double (*)(double)> FunctionMap;
  typedef StringMap::iterator MapIt;


  String input_choice, input_number;

  StringMap abbr   = { {'C', "Celsius"}, {'F', "Fahrenheit"} };
  FunctionMap fmap = { {'C', &f_to_c},   {'F', &c_to_f} };
  for (MapIt it = abbr.begin(); it != abbr.end(); it++) {
    std::cout << "Press " << it->first
      << " to convert from " << abbr[it->first == 'C' ? 'F' : 'C']
      << " to " << abbr[it->first]
      << "." << std::endl;
  }
  std::cout << "Your choice: ";
  std::cin >> input_choice;

  if (!isalpha(input_choice[0])) {
    return EXIT_FAILURE;
  }
  char choice = toupper(input_choice[0]);
  if (! (choice == 'C' || choice == 'F')) {
    return EXIT_FAILURE;
  }

  std::cout << "Please enter the temperature in " << abbr[choice == 'C' ? 'F' : 'C'] << ": ";
  std::cin >> input_number;

  typedef std::pair<bool, double> DoubleResult;
  DoubleResult temperature_result = str_to_f<double>(input_number);
  if (!temperature_result.first) {
    return EXIT_FAILURE;
  }
  double before = temperature_result.second;

  double (*func)(double) = fmap[choice];
  double result = (*func)(before);
  std::cout << "The temperature in " << abbr[choice] << " is " << result << std::endl;

  return EXIT_SUCCESS;
}
