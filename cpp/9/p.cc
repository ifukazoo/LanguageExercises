#include <cstdlib>
#include <cmath>

#include <iostream>
#include <algorithm> // min

#include "functions.h"


typedef std::string String;
const double kPaintablePerGallon = 350.0;

int main()
{
  String length, width;
  std::cout << "What is the length of the room in feet? ";
  std::cin >> length;
  std::cout << "What is the width of the room in feet? ";
  std::cin >> width;

  std::pair<bool, int> result;
  int ilength = 0;
  result = str_to_i<int>(length);
  if (!result.first || result.second < 0) return EXIT_FAILURE;

  ilength = result.second;

  int iwidth = 0;
  result = str_to_i<int>(width);
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
  double step1 = square_of_feet / kPaintablePerGallon;
  int step3 = ceil(step1);

  std::cout << "You will need to purchase " << step3 << std::endl;
  std::cout << "paint to cover " << square_of_feet << " square feet." << std::endl;

  return EXIT_SUCCESS;
}
