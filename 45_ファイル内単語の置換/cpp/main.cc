#include <fstream>
#include <iostream>

#include <boost/algorithm/string.hpp>

#include "user_input.h"

namespace {

bool validate_not_empty(const std::string& s, std::string& value) {
    auto ss = s;
    boost::trim(ss);
    if (ss.empty()) {
        return false;
    }
    value = ss;
    return true;
}
}
int main(int argc, char const* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << *argv << " <input file name>" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::ifstream ifs(*++argv);

    const std::string wrong_input_msg = "Sorry. That's not a valid input.";
    auto name = read_user_input_with_validator<std::string>(
        "What is the output file name? ", validate_not_empty, wrong_input_msg);

    std::ofstream ofs(name);

    std::string line;
    while (std::getline(ifs, line)) {
        boost::replace_all(line, "utilize", "use");
        ofs << line << std::endl;
    }
    ifs.close();
    ofs.flush();
    ofs.close();

    exit(EXIT_SUCCESS);
}
