#include <ctime>
#include <iostream>
#include <vector>

#include "user_input.h"

namespace {

int generate_ramdom_index(int max) {
    static bool seed = false;
    if (!seed) {
        std::srand(std::time(nullptr));
        seed = true;
    }
    return std::rand() % max;
}

}  // namespace

int main() {
    std::vector<std::string> answers = {"Yes", "No", "Maybe",
                                        "Ask again later"};
    read_user_input("What's your question? ");

    std::cout << answers[generate_ramdom_index(answers.size())] << "."
              << std::endl;

    return 0;
}
