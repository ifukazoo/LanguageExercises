#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

#include "employee.h"
#include "filter.h"
#include "user_input.h"

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
void print_result(const std::vector<Employee>& employees) {
    print_row("Name", " Position", " Separation Date");
    print_row("-----------------------", "----------------------",
              "----------------------");
    for (auto employee : employees) {
        print_row(employee.first_name + " " + employee.last_name,
                  " " + employee.position, " " + employee.separation_date);
    }
}

bool every_input_ok(const std::string& s, std::string& value) {
    value = s;
    return true;
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

    auto search_string = read_user_input_with_validator<std::string>(
        "Enter a search string: ", every_input_ok, "");

    std::vector<Employee> results;
    filter::filter_if<Employee>(
        employees,
        [&search_string](const Employee& e) {
            return (e.first_name.find(search_string) != std::string::npos) ||
                   (e.last_name.find(search_string) != std::string::npos);
        },
        results);

    print_result(results);

    return 0;
}
