#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include <boost/algorithm/string.hpp>

using Pair = std::pair<std::string, int>;
using FreqMap = std::unordered_map<std::string, int>;

namespace {

bool my_isspace(char c) { return std::isspace(static_cast<int>(c)); }

bool maybe_word(const std::string& word) {
    return std::any_of(word.begin(), word.end(),
                       [](char c) { return std::isalpha(c); });
}

FreqMap count_word_freq(const std::string& path) {
    std::ifstream ifs(path);
    std::string line;
    std::vector<std::string> words;
    FreqMap map;
    while (std::getline(ifs, line)) {
        boost::split(words, line, my_isspace, boost::token_compress_on);
        for (const auto& w : words) {
            if (!w.empty() && maybe_word(w)) {
                map[w]++;
            }
        }
    }
    ifs.close();
    return map;
}

int get_max_length(const std::vector<Pair>& freq) {
    auto max_it = std::max_element(
        freq.begin(), freq.end(), [](const Pair& a, const Pair& b) {
            return a.first.length() < b.first.length();
        });
    return max_it->first.length();
}

void disp_hist(const std::vector<Pair>& freq) {
    int max_wordlen = get_max_length(freq);
    for (const auto& pair : freq) {
        auto title = pair.first + ": ";  // +2
        std::cout << std::setw(max_wordlen + 2) << std::left << title;
        for (int i = 0; i < pair.second; i++) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
}
}

int main(int argc, char const* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << *argv << " <input file name>" << std::endl;
        exit(EXIT_FAILURE);
    }

    auto map = count_word_freq(*++argv);

    std::vector<Pair> freq;
    std::copy(map.begin(), map.end(), std::back_inserter(freq));

    std::sort(freq.begin(), freq.end(), [](const Pair& lhs, const Pair& rhs) {
        return lhs.second > rhs.second;
    });
    disp_hist(freq);

    exit(EXIT_SUCCESS);
}
