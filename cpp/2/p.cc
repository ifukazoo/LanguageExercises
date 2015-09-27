#include <limits>
#include <iostream>

int main()
{
  std::string input;
  std::cin.unsetf(std::ios::skipws);
  while (1) {
    std::cout << "What is the input string? ";
    std::cin >> input;
    if (input.empty()) {
      std::cout << "Enter something." << std::endl;
      // そのままループすると，cinに入った先頭文字をもう一度読もうとしてしまう.
      // よって，改行の直後まで無視する
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }
    break;
  }
  std::cout << input << " has " << input.size() << " characters." << std::endl;
  return 0;
}
