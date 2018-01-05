#include <iostream>
#include "user_input.h"

int main() {
    bool eof;
    int rate = read_user_input_int("What is the rate of return? ", eof);
    if (eof) {
        exit_by_eof();
    }
    int years = 72 / rate;
    std::cout << "It will take " << years
              << " years to double your initial investment.\n";
    return 0;
}
