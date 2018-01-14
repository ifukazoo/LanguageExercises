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
bool read_user_input(const std::string& prompter,
                     const std::string& invalid_msg,
                     std::function<bool(const std::string&, T&)> converter,
                     T& read_value) {
retry:
    std::string user_input = input(prompter);
    if (std::cin.eof()) {
        // EOF入力.終了
        return false;
    }
    if (!converter(user_input, read_value)) {
        std::cout << invalid_msg << std::endl;
        goto retry;
    }
    // 変換結果OK.終了
    return true;
}
}  // namespace

#endif
