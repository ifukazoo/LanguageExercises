#include <termios.h>
#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <map>

#include "functions.h"

typedef std::string String;
typedef std::map<String, String> StringMap;

int main()
{
  // c++11
  std::pair<String, String> pairs[] = {
    {"figaro",  "abcd"},
    {"susanna", "1234"},
    {"almaviva","ABCD"},
    {"rosina",  "5678"},
  };

  StringMap password_map(pairs, pairs + array_length(pairs));;

  String username;
  std::cout << "What is the usernames? ";
  std::cin >> username;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "What is the password? ";

  String password;
  struct termios oldt, newt;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~ (ICANON | ECHO);
  newt.c_cc[VTIME] = 0;
  newt.c_cc[VMIN] = 1;
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  while (true) {
    char c = std::cin.get();
    if (c == '\n') {
      std::cout << std::endl;
      break;
    } else {
      std::cout << '*';
      password.push_back(c);
    }
  }
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

  StringMap::iterator it = password_map.find(username);
  if (it != password_map.end() && (*it).second == password) {
    std::cout << "Welcome!" << std::endl;
  } else {
    std::cout << "I don't know you." << std::endl;
  }
  return EXIT_SUCCESS;
}
