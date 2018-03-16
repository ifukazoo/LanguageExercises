#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

namespace {
void print_result(std::string path, const std::vector<std::string>& names) {
    std::ofstream ofs(path);
    ofs << "Total of " << names.size() << " names" << std::endl;
    ofs << "-----------------" << std::endl;
    for (auto it = names.begin(); it != names.end(); it++) {
        ofs << *it << std::endl;
    }
    ofs.close();
}
}  // namespace

int main() {
    std::vector<std::string> names;

    std::string line;
    while (std::getline(std::cin, line)) {
        names.push_back(line);
    }
    std::sort(names.begin(), names.end());
    print_result("result", names);

    return 0;
}
