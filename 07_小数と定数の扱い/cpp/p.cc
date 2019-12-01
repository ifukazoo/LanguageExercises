#include <iostream>
#include <cmath>

const double kFeetToMeterCoff = 0.09290304;

int main()
{
    std::string input;
    int length, width;

    std::cout << "What is the length of the room in feet? ";
    std::getline(std::cin, input);
    length = std::stoi(input);

    std::cout << "What is the width of the room in feet? ";
    std::getline(std::cin, input);
    width = std::stoi(input);

    /*
     * 例:小数点以下3桁にしたい
r    * 乗数 0.09290304
     * 1) 整数にする
     *    0.09290304 x 100,000,000 = 9290304
     * 2) 3けた残して割る
     *    計算結果が 123456789とすると,
     *    123456789 / 100,000 = 1234.56789
     * 3) 小数を四捨五入する
     *    1234.56789 => 1235.0
     * 4) 残しておいた3けたで割る
     *    1235.0 / 1000 = 1.235
     */

    int square_feet = length * width;
    double square_meters = square_feet * kFeetToMeterCoff * 100000000;
    square_meters /= 100000.0;
    square_meters = round(square_meters);
    square_meters /= 1000.0;

    std::cout << "The area is" << std::endl;
    std::cout << square_feet   << " square feet"   << std::endl;
    std::cout << square_meters << " square_meters" << std::endl;

    return 0;
}
