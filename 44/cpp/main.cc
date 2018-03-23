#include <fstream>
#include <iomanip>
#include <iostream>

#include "product.h"
#include "strings.h"
#include "user_input.h"

using namespace product;

namespace {

bool validate_not_empty(const std::string& s, std::string& value) {
    auto trimed_s = strings::trim(s);
    if (trimed_s.empty()) {
        return false;
    }
    value = trimed_s;
    return true;
}

}  // namespace

int main(int argc, char const* argv[]) {
    std::vector<Product> products;
    if (argc < 2) {
        std::cerr << "Usage: " << *argv << " <json file>" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::ifstream ifs(*++argv);
    bool success = product::parse(ifs, products);
    ifs.close();
    if (!success) {
        exit(EXIT_FAILURE);
    }

    const std::string not_found_msg =
        "Sorry, that product was not found in our inventory.";

    for (;;) {
        auto name = read_user_input_with_validator<std::string>(
            "What is the procuct name? ", validate_not_empty, not_found_msg);

        auto pred = [name](const Product& p) { return p.name() == name; };

        auto it = std::find_if(std::begin(products), std::end(products), pred);
        if (it != std::end(products)) {
            // found
            it->disp();
            break;
        }
        std::cout << not_found_msg << std::endl;
    }
    exit(EXIT_SUCCESS);
}
