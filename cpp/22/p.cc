#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

#include "functions.h"

using String = std::string;
using IntVector = std::vector<int>;
using Iterator  = IntVector::iterator;
using Result = std::pair<bool, int>;

int main()
{
  IntVector inputs;
  String line;
  while (true) {
    std::cout << "Enter number: ";
    if (!std::getline(std::cin, line)) {
      std::cout << std::endl;
      break;
    }
    Result result = str_to_i<int>(line);
    if (!result.first) {
      return EXIT_FAILURE;
    }

    // 入力済みの値は無視
    if (std::find(inputs.begin(), inputs.end(), result.second) == inputs.end()) {
      inputs.push_back(result.second);
    }
  }
  int max = std::numeric_limits<int>::min();
  for (Iterator it = inputs.begin(); it != inputs.end(); it++) {
    max = max < *it ? *it : max;
  }
  std::cout << "The largest number is " << max << "." << std::endl;

  return EXIT_SUCCESS;
}
