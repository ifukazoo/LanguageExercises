#include <iomanip>
#include <iostream>
#include <vector>

#include "csv.h"

namespace {

// 1行出力
void print_row(std::string left, std::string mid, std::string right, int left_w,
               int mid_w, int right_w) {
    std::cout << std::setw(left_w) << std::left << left << std::setw(mid_w)
              << std::left << mid << std::setw(right_w) << std::left << right
              << std::endl;
}
void print_hr(int left_w, int mid_w, int right_w) {
    int line_width = left_w + mid_w + right_w;
    for (int i = 0; i < line_width; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
}

// 結果出力
void print_result(const std::vector<csv::Record>& records) {
    //各フィールドの最大長を取得する
    int last_col_w = csv::get_max_length(csv::get_cols(records, 0));
    int first_cols_w = csv::get_max_length(csv::get_cols(records, 1));
    int salary_cols_w = csv::get_max_length(csv::get_cols(records, 2));

    print_row("Last", "First", "Salary", last_col_w + 1, first_cols_w + 1,
              salary_cols_w + 1);
    print_hr(last_col_w + 1, first_cols_w + 1, salary_cols_w + 1);

    for (auto it = records.begin(); it != records.end(); it++) {
        print_row((*it)[0], (*it)[1], (*it)[2], last_col_w + 1,
                  first_cols_w + 1, salary_cols_w + 1);
    }
}

}  // namespace

int main(int argc, char const* argv[]) {
    std::vector<csv::Record> records;
    if (argc == 1) {
        csv::read_csv(std::cin, records);
    } else {
        csv::read_csv_file(*(++argv), records);
    }
    print_result(records);

    return 0;
}
