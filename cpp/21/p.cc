#include <iostream>
#include <string>
#include <unordered_map>

using String = std::string;
using MonthMap = std::unordered_map<String, String>;

int main()
{
  String input_month;
  MonthMap map =  {
    {"1",    "January"},
    {"2",    "February"},
    {"3",    "March"},
    {"4",    "April"},
    {"5",    "May"},
    {"6",    "June"},
    {"7",    "July"},
    {"8",    "August"},
    {"9",    "September"},
    {"10",    "October"},
    {"11",    "November"},
    {"12",    "December"},
  };

  std::cout << "Enter the number of the month: ";
  std::cin >> input_month;

  String month = map[input_month];
  if (!month.empty()) {
    std::cout << "The name of the month is " << month << "." << std::endl;
  }

  return EXIT_SUCCESS;
}
