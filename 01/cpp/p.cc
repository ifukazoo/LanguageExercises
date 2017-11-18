#include <iostream>

int main()
{
  std::cout << "What is your name? ";

  std::string input;
  std::cin >> input;

  std::cout << "Hello, " << input << ", nice to meet you!" << std::endl;

  return 0;
}
