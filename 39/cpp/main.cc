#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

#include "employee.h"

namespace {
void print_cel(const std::string& content) {
    std::cout << std::left << std::setw(23);
    std::cout << content;
}
void print_row(const std::string& left, const std::string& middle,
               const std::string& right) {
    print_cel(left);
    print_cel("|" + middle);
    print_cel("|" + right);
    std::cout << std::endl;
}
}  // namespace

int main() {
    auto employees = std::vector<Employee>{
        Employee{
            "John", "Johnson", "Manager", "2016-12-31",
        },
        Employee{
            "Tou", "Xiong", "Software Engineer", "2016-10-05",
        },
        Employee{
            "Michaela", "Michaelson", "District Manager", "2015-12-19",
        },
        Employee{
            "Jake", "Jacobson", "Programmer", "",
        },
        Employee{
            "Jacquelyn", "Jackson", "DBA", "",
        },
        Employee{
            "Sally", "Weber", "Web Developer", "2015-12-18",
        },
    };

    std::sort(employees.begin(), employees.end(),
              [](const Employee& lhs, const Employee& rhs) {
                  return lhs.last_name < rhs.last_name;
              });

    print_row("Name", " Position", " Separation Date");
    print_row("-----------------------", "----------------------",
              "----------------------");
    for (auto employee : employees) {
        print_row(employee.first_name + " " + employee.last_name,
                  " " + employee.position, " " + employee.separation_date);
    }
    return 0;
}
