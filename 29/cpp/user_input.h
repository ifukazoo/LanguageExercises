#ifndef _USER_INPUT_H_
#define _USER_INPUT_H_

#include <functional>
#include <iostream>

namespace {
std::string input(const std::string& prompter) {
    std::string user_input;
    std::cout << prompter;
    std::getline(std::cin, user_input);
    return user_input;
}

template <typename T>
T read_user_input(const std::string& prompter,
                  std::function<bool(const std::string&, T&)> converter,
                  bool& eof) {
    T output;
retry:
    std::string user_input = input(prompter);
    if (std::cin.eof()) {
        // EOF入力.終了
        eof = true;
        return output;
    }
    if (converter(user_input, output)) {
        // 変換結果OK.終了
        eof = false;
        return output;
    }
    std::cout << "Sorry. That's not a valid input." << std::endl;
    goto retry;
}

bool safe_stoi(const std::string& s, int& value) {
    try {
        value = std::stoi(s);
    } catch (std::invalid_argument e) {
        return false;
    } catch (std::out_of_range e) {
        return false;
    }
    return true;
}

int read_user_input_int(const std::string& prompter, bool& eof) {
    return read_user_input<int>(prompter, safe_stoi, eof);
}

void exit_by_eof() {
    std::cerr << "failed to read user input.\n";
    exit(EXIT_FAILURE);
}
}  // namespace

#endif
