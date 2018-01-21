#ifndef _USER_INPUT_H_
#define _USER_INPUT_H_

#include <functional>
#include <iostream>

namespace {

using cstring = const std::string;

// input プロンプトを出してユーザー入力を取得する.
std::string input(cstring& prompter) {
    std::string user_input;
    std::cout << prompter;
    std::getline(std::cin, user_input);
    return user_input;
}

// read_user_input プロンプトを出してユーザー入力を取得する.
// EOFが入力された場合はプログラム終了する
std::string read_user_input(cstring& prompter) {
    auto user_input = input(prompter);
    if (std::cin.eof()) {
        exit(1);
    }
    return user_input;
}

// readUserInputWithValidator プロンプトを出してユーザー入力を取得して,
// 希望の型に変換する.希望に沿わない入力だった場合は再度入力をうながす.
template <typename T>
T read_user_input_with_validator(cstring& prompter,
                                 std::function<bool(cstring&, T&)> validator,
                                 cstring& invalid_msg) {
retry:
    auto user_input = read_user_input(prompter);
    T read_value;
    if (!validator(user_input, read_value)) {
        std::cout << invalid_msg << std::endl;
        goto retry;
    }
    return read_value;
}
}  // namespace

#endif
