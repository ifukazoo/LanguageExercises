#include <iostream>
#include <unordered_map>

int main()
{
    std::unordered_map<int, std::string> map =  {
        {1,  "January"},
        {2,  "February"},
        {3,  "March"},
        {4,  "April"},
        {5,  "May"},
        {6,  "June"},
        {7,  "July"},
        {8,  "August"},
        {9,  "September"},
        {10, "October"},
        {11, "November"},
        {12, "December"},
    };

    std::string input;
    std::cout << "Enter the number of the month: ";
    std::getline(std::cin, input);

    int number = std::stoi(input);
    auto month = map[number];
    if (! month.empty()) {
        std::cout << "The name of the month is " << month << "." << std::endl;
    }

    return 0;
}
