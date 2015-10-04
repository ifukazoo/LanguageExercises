#include <ctime>
#include <cstdlib>
#include <cmath>

#include <iostream>
#include <algorithm> // min

#include "functions.h"


typedef std::string String;
const double kFeetToMeterCoff = 0.09290304;

int main()
{
  String length, width;
  std::cout << "What is the length of the room in feet? ";
  std::cin >> length;
  std::cout << "What is the width of the room in feet? ";
  std::cin >> width;

  std::pair<bool, int> result;
  int ilength = 0;
  result = string_to_integer<int>(length);
  if (!result.first || result.second < 0) return EXIT_FAILURE;

  ilength = result.second;

  int iwidth = 0;
  result = string_to_integer<int>(width);
  if (!result.first || result.second < 0) return EXIT_FAILURE;
  iwidth = result.second;

  /*
   *
   * 下３桁にしたい
   * => 整数を最終的に 1000.0 で除算する
   * => 1000.0で除算する前にroundをかける
   * => 桁を合わせを戻す際に一旦roundが入る
   */

  int square_of_feet = iwidth * ilength;
  double step1 = square_of_feet * kFeetToMeterCoff * 100000000.0;
  double step2 = step1 / 100000.0;
  double step3 = round(step2);
  double step4 = step3 / 1000.0;
  double square_of_meter = step4;

  if (square_of_feet < 0) {
    std::cout << "too large input." << std::endl;
  } else {
    std::cout << square_of_feet << " square feet" << std::endl;
    std::cout << square_of_meter << " square meters" << std::endl;
  }

  return EXIT_SUCCESS;
}
