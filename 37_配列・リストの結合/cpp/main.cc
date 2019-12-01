#include <cassert>
#include <ctime>
#include <iostream>
#include <utility>
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

bool validate_number(const std::string& s, int& value) {
    try {
        // 数字であるかをチェック
        value = std::stoi(s);
        return true;
    } catch (std::invalid_argument e) {
        return false;
    } catch (std::out_of_range e) {
        return false;
    }
}

std::string generate_password(int num_special, int num_number, int num_min) {
    assert(num_special + num_number <= num_min);

    std::string alphabets =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string numbers = "0123456789";
    std::string special_chars = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~}";

    // パスワードに使う文字を集める
    std::vector<char> characters_selected;
    for (int i = 0; i < num_special; i++) {
        characters_selected.push_back(
            special_chars[generate_ramdom_index(special_chars.length())]);
    }
    for (int i = 0; i < num_number; i++) {
        characters_selected.push_back(
            numbers[generate_ramdom_index(numbers.length())]);
    }
    for (int i = 0; i < num_min - num_special - num_number; i++) {
        characters_selected.push_back(
            alphabets[generate_ramdom_index(alphabets.length())]);
    }

    // ランダムに並べ替える
    int remain = characters_selected.size();
    int iter_max = characters_selected.size() - 1;
    for (int i = 0; i < iter_max; i++) {
        int ridx = generate_ramdom_index(remain);
        // 入れ替える
        std::swap(characters_selected[i], characters_selected[i + ridx]);
        remain--;
    }
    return std::string(characters_selected.begin(), characters_selected.end());
}

}  // namespace

int main() {
    auto invalid_msg = "Sorry. That's not a valid input.";
    int num_min = read_user_input_with_validator<int>(
        "What's the minimum length? ", validate_number, invalid_msg);

    int num_special = read_user_input_with_validator<int>(
        "How many special characters? ", validate_number, invalid_msg);

    int num_number = read_user_input_with_validator<int>(
        "How many numbers? ", validate_number, invalid_msg);

    std::cout << generate_password(num_special, num_number, num_min)
              << std::endl;

    return 0;
}
