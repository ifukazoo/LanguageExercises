#include "guess_game.h"
#include <cstdlib>
#include <ctime>
#include "user_input.h"

namespace guessgame {

const std::string kInvalidMsg = "Sorry. That's not a valid input.";

bool validate_number(const std::string& s, int& value) {
    try {
        value = std::stoi(s);
    } catch (std::invalid_argument e) {
        return false;
    } catch (std::out_of_range e) {
        return false;
    }
    return true;
}

int generate_goal_number(int level) {
    static bool seed = false;
    if (!seed) {
        std::srand(std::time(nullptr));
        seed = true;
    }
    int max = 1;
    for (int i = 0; i < level; i++) {
        max *= 10;
    }
    return std::rand() % max + 1;
}

int start_guess(int level) {
    int goal = generate_goal_number(level);
    std::cout << "I have my number. ";

    int guess = read_user_input_with_validator<int>(
        "What's your guess? ", validate_number, kInvalidMsg);

    int try_count = 1;
    while (guess != goal) {
        std::cout << (guess < goal ? "Too low. " : "Too high. ");
        guess = read_user_input_with_validator<int>(
            "Guess again: ", validate_number, kInvalidMsg);
        try_count++;
    }
    return try_count;
}

bool validate_level(const std::string& input, int& level) {
    if (!validate_number(input, level)) {
        return false;
    }
    if (!(level == 1 || level == 2 || level == 3)) {
        return false;
    }
    return true;
}

void start_game() {
    std::cout << "Let's play Guess the Number." << std::endl;

    int level = read_user_input_with_validator<int>(
        "Pick a difficulty level (1, 2, or 3): ", validate_level, kInvalidMsg);
    int count = start_guess(level);
    std::cout << "You got it in " << count << " guess!" << std::endl;
}
}
