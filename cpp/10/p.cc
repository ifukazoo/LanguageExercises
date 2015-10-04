#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>

#include "functions.h"

typedef std::string String;
typedef std::pair<String, String> InputPair;
typedef std::pair<int, int> NumberPair;
typedef std::vector<InputPair> Inputs;

const double kTax = 5.5;

struct Sum {
  std::pair<bool, int> operator()(const std::pair<bool, int>& sum, const InputPair& input) {
    if (!sum.first) {
      // すでに失敗がわかっている
      return sum;
    }
    std::pair<bool, int> conv_piece = string_to_integer<int>(input.first);
    std::pair<bool, int> conv_quant = string_to_integer<int>(input.second);
    if (! (conv_piece.first && conv_quant.first)) {
      return std::make_pair(false, 0);
    }
    int piece = conv_piece.second;
    int quant = conv_quant.second;
    return std::make_pair(true, sum.second + piece * quant);
  }
};

struct GetInput {
  GetInput():idx_(0) {}
  void operator() (InputPair& input) {
    std::cout << "Enter the price of item " << idx_ + 1 << ": ";
    std::cin >> input.first;
    std::cout << "Enter the quantity of item " << idx_ + 1 << ": ";
    std::cin >> input.second;
    idx_++;
  }
  int idx_;
};

int main()
{
  Inputs inputs(3);
  std::for_each(inputs.begin(), inputs.end(), GetInput());
  std::pair<bool, int> result = std::accumulate(inputs.begin(), inputs.end(), std::make_pair(true, 0), Sum());
  if (!result.first) return EXIT_FAILURE;

  double subtotal = result.second;
  double tax      = subtotal * kTax / 100.0;
  double total    = subtotal + tax;

  std::cout << "Subtotal: $"
    << std::fixed << std::setprecision(2)
    << subtotal << std::endl;
  std::cout << "Tax: $"
    << std::fixed << std::setprecision(2)
    << tax << std::endl;
  std::cout << "Total: $"
    << std::fixed << std::setprecision(2)
    << total << std::endl;

  return EXIT_SUCCESS;
}
