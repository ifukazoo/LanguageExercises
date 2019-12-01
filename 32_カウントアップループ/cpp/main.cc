#include <cctype>
#include <iostream>

#include "guess_game.h"
#include "user_input.h"

namespace {

bool user_want_to_continue() {
    auto answer = read_user_input("Play again? ");
    return toupper(answer[0]) == 'Y';
}

}  // namespace

int main() {
    for (;;) {
        guessgame::start_game();

        if (!user_want_to_continue()) {
            break;
        }
    }
    std::cout << "Goodbye!" << std::endl;

    return 0;
}
