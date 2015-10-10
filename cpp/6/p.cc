#include <ctime>
#include <cstdlib>

#include <iostream>
#include <algorithm> // min

#include "functions.h"


typedef std::string String;

int main()
{
  String age, retire;
  std::cout << "What is your current age? ";
  std::cin >> age;
  std::cout << "At What age would you like to retire? ";
  std::cin >> retire;

  std::pair<bool, int> result;
  int iage = 0;
  result = str_to_i<int>(age);
  if (!result.first || result.second < 0) return EXIT_FAILURE;

  iage = result.second;

  int iretire = 0;
  result = str_to_i<int>(retire);
  if (!result.first || result.second < 0) return EXIT_FAILURE;
  iretire = result.second;

  int diff = iretire - iage;

  if (diff < 0) {
    std::cout << "You don't have any years left until you can retire." << std::endl;
  } else {
    std::cout << "You have " << diff << " years left until you can retire." << std::endl;
    struct tm tm;
    time_t now = time(NULL);
    if (!localtime_r(&now, &tm)) return EXIT_FAILURE;

    int year = 1900 + tm.tm_year;
    std::cout << "It's "<< year <<", so you can retire in " << (year + diff) << "." << std::endl;
  }

  return EXIT_SUCCESS;
}
