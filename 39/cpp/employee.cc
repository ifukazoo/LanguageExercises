#include "employee.h"

#include <sstream>

std::string Employee::ToString() {
    std::ostringstream os;
    os << "{"
       << "first_name:" << first_name << ", "
       << "last_name:" << last_name << ", "
       << "position:" << position << ", "
       << "separation_date:" << separation_date << "}";
    return os.str();
}
