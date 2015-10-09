#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>

#include "functions.h"

typedef std::string String;

int main()
{
  String inputEuro, inputRate;
  std::cout << "How many euros are you exchanging? " << std::endl;
  std::cin >> inputEuro;
  std::cout << "What is the exchange rate? " << std::endl;
  std::cin >> inputRate;

  std::pair<bool, double> conv_euro = str_to_f<double>(inputEuro);
  if (!conv_euro.first) return EXIT_FAILURE;
  std::pair<bool, double> conv_rate = str_to_f<double>(inputRate);
  if (!conv_rate.first) return EXIT_FAILURE;

  double euro = conv_euro.second;
  double rate = conv_rate.second;

  double dollar = round(euro * rate) / 100.0;

  std::cout << inputEuro
    << " euros at an exchante rate of "
    << inputRate
    << " is" << std::endl
    << dollar << " U.S. dollars." << std::endl;

  return EXIT_SUCCESS;
}
