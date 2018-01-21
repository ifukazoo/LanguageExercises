#include <ctime>
#include <iostream>
#include <vector>

#include "user_input.h"

namespace {

int gen_ramdom_num(int max) {
    static bool seed = false;
    if (!seed) {
        std::srand(std::time(nullptr));
        seed = true;
    }
    return std::rand() % max;
}
}

int main() {
    std::vector<std::string> contestants;

    for (;;) {
        auto name = read_user_input("Enter a name: ");
        if (name.empty()) {
            break;
        }
        contestants.push_back(name);
    }
    int max = contestants.size();
    if (max > 0) {
        auto winner = contestants[gen_ramdom_num(max)];
        std::cout << "The winner is .. " << winner << "." << std::endl;
    }

    return 0;
}
