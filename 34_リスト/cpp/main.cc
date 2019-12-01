#include <iostream>
#include <algorithm>
#include <list>

#include "user_input.h"

namespace {

    void disp_employees(const std::list<std::string>& list) {
        std::cout << "There are " << list.size() << " employees:" << std::endl;

        for (auto it = list.begin(); it != list.end(); it++) {
            std::cout << *it << std::endl;
        }
    }

}  // namespace

int main() {
    std::list<std::string> employees = {"Jhon Smith", "Jackie Jackson",
        "Chris Jones", "Amanda Cullen",
        "Jeremy Goodwin"};

    disp_employees(employees);

    std::cout << std::endl;
    auto name = read_user_input("Enter an employee name to remove: ");
    auto before = employees.size();
    employees.remove(name);
    auto after = employees.size();
    std::cout << std::endl;

    if (before == after) {
        std::cout << "Not found " << name << "." << std::endl;
    } else {
        disp_employees(employees);
    }
    return 0;
}
