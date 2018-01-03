#include <functional>
#include <iomanip>
#include <iostream>

namespace {

void table_printer(std::function<void()> begin,
                   std::function<void(int col)> do_work,
                   std::function<void()> end) {
    begin();
    for (int col = 0; col <= 12; col++) {
        do_work(col);
    }
    end();
}

void print_header() {
    table_printer([]() { std::cout << "|" << std::setw(4) << "    "; },
                  [](int col) { std::cout << "|" << std::setw(4) << col; },
                  []() { std::cout << "|" << std::endl; });
}

void print_horizontal_line() {
    table_printer([]() { std::cout << "+----"; },
                  [](int) { std::cout << "+----"; },
                  []() { std::cout << "+" << std::endl; });
}

void print_row(int row) {
    // row はコピー形式でキャプチャ
    table_printer(
        [=]() { std::cout << "|" << std::setw(4) << row; },
        [=](int col) { std::cout << "|" << std::setw(4) << row * col; },
        []() { std::cout << "|" << std::endl; });
}
}  // namespace

int main() {
    print_horizontal_line();
    print_header();
    for (int i = 0; i <= 12; i++) {
        print_horizontal_line();
        print_row(i);
    }
    print_horizontal_line();
    return 0;
}
