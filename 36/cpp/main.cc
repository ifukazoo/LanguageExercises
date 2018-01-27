#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

#include "user_input.h"

namespace {

bool validate_number_or_done(const std::string& s, std::string& value) {
    if (s == "done") {
        value = s;
        return true;
    }

    try {
        // 数字であるかをチェック
        std::stoi(s);
        value = s;
        return true;
    } catch (std::invalid_argument e) {
        return false;
    } catch (std::out_of_range e) {
        return false;
    }
}

void disp_nums(const std::vector<int>& nums) {
    std::cout << "Numbers: ";
    auto sep = "";
    for (auto it = nums.begin(); it != nums.end(); it++) {
        std::cout << sep << *it;
        sep = ", ";
    }
    std::cout << std::endl;
}

int average(const std::vector<int>& nums) {
    assert(!nums.empty());
    return std::accumulate(nums.begin(), nums.end(), 0) / nums.size();
}
int min(const std::vector<int>& nums) {
    assert(!nums.empty());
    return std::accumulate(nums.begin() + 1, nums.end(), nums[0],
                           [](int min, int e) { return e < min ? e : min; });
}
int max(const std::vector<int>& nums) {
    assert(!nums.empty());
    return std::accumulate(nums.begin() + 1, nums.end(), nums[0],
                           [](int max, int e) { return max < e ? e : max; });
}
double standard_diviation(const std::vector<int>& nums) {
    assert(!nums.empty());
    double average =
        std::accumulate(nums.begin(), nums.end(), 0.0) / nums.size();
    double tmp_sum = std::accumulate(nums.begin(), nums.end(), 0.0,
                                     [average](double sum, int e) {
                                         double d = average - e;
                                         return sum + (d * d);
                                     });
    double variance = tmp_sum / nums.size();
    return std::sqrt(variance);
}

double round_pointn(double d, int n) {
    int multiplier = 1;
    for (int i = 0; i < n; i++) {
        multiplier *= 10;
    }
    double d1 = d * multiplier;
    double d2 = std::round(d1);
    return d2 / multiplier;
}

}  // namespace

int main() {
    std::vector<int> nums;

    for (;;) {
        auto input = read_user_input_with_validator<std::string>(
            "Enter a number: ", validate_number_or_done,
            "Sorry. That's not a valid input.");
        if (input == "done") {
            break;
        } else {
            nums.push_back(std::stoi(input));
        }
    }

    if (!nums.empty()) {
        disp_nums(nums);

        std::cout << "The average is " << average(nums) << std::endl;
        std::cout << "The minimum is " << min(nums) << std::endl;
        std::cout << "The maximum is " << max(nums) << std::endl;
        std::cout << "The standard diviation is "
                  << round_pointn(standard_diviation(nums), 2) << std::endl;
    }
    return 0;
}
