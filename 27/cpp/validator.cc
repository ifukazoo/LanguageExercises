#include <algorithm>
#include <regex>

#include "validator.h"

namespace {
bool validate_name_and_make_error(const std::string& user_input,
                                  const std::string& first_or_last,
                                  std::string& err_msg) {
    err_msg = "";

    std::ostringstream msg;
    if (user_input.length() == 0) {
        msg << "The " << first_or_last << " name must be filled in.\n";
        err_msg = msg.str();
        return false;
    }

    if (!validate_name(user_input)) {
        msg << "\"" << user_input << "\" is not a valid " << first_or_last
            << " name. It is too short.\n";
        err_msg = msg.str();
        return false;
    }

    return true;
}
}

bool validate_input(const std::string first_name, const std::string last_name,
                    const std::string zip_code, const std::string employee_id,
                    std::string& err_msg) {
    std::ostringstream msg_joined;
    std::string msg_tmp;
    auto success = true;

    err_msg = "";

    success = validate_name_and_make_error(first_name, "first", msg_tmp);
    if (!success) {
        msg_joined << msg_tmp;
    }
    success = validate_name_and_make_error(last_name, "last", msg_tmp);
    if (!success) {
        msg_joined << msg_tmp;
    }
    success = validate_zipcode(zip_code);
    if (!success) {
        msg_joined << "The ZIP code must be numeric.\n";
    }
    success = validate_empoyee_id(employee_id);
    if (!success) {
        msg_joined << employee_id << " is not a valid ID.\n";
    }

    err_msg = msg_joined.str();
    return err_msg.length() == 0;
}

bool validate_name(const std::string& input) { return input.length() >= 2; }

bool validate_empoyee_id(const std::string& input) {
    std::regex pattern("^[a-zA-Z]{2}-\\d{4}$");
    return std::regex_match(input, pattern);
}

bool validate_zipcode(const std::string& input) {
    if (input.length() == 0) {
        return false;
    }
    return std::all_of(input.begin(), input.end(), isdigit);
}
