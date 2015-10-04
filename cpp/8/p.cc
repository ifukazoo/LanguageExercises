#include <cstdlib>

#include <iostream>
#include <algorithm> // min

#include "functions.h"


typedef std::string String;

int main()
{
  String people, pizzas;
  std::cout << "How many people? ";
  std::cin >> people;
  std::cout << "How many pizzas do you have? ";
  std::cin >> pizzas;

  std::pair<bool, int> result;
  int peopleN = 0;
  result = string_to_integer<int>(people);
  if (!result.first || result.second < 0) return EXIT_FAILURE;

  peopleN = result.second;

  int pizzasN = 0;
  result = string_to_integer<int>(pizzas);
  if (!result.first || result.second < 0) return EXIT_FAILURE;
  pizzasN = result.second;

  std::cout << peopleN << " people with " << pizzasN << " pizzas" << std::endl;

  int pieces = std::max(0, pizzasN * 8);
  div_t dm = div(pieces, peopleN); // no check zero div

  std::cout << "Each person gets " << dm.quot << " pieces of pizza." << std::endl;
  std::cout << "Threre are "       << dm.rem  << " leftover pieces." << std::endl;

  return EXIT_SUCCESS;
}
