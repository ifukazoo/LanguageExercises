#ifndef _VALIDATOR_H_
#define _VALIDATOR_H_

#include <string>

bool validate_input(const std::string first_name, const std::string last_name,
                    const std::string zip_code, const std::string employee_id,
                    std::string& err_msg);
bool validate_name(const std::string& input);
bool validate_empoyee_id(const std::string& input);
bool validate_zipcode(const std::string& input);

#endif
