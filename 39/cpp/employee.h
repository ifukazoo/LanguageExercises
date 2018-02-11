#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <string>

struct Employee {
    std::string first_name;
    std::string last_name;
    std::string position;
    std::string separation_date;

    std::string ToString();
};

#endif
