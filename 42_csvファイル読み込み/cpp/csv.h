#ifndef _CSV_H_
#define _CSV_H_

#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

namespace csv {

using Field = std::string;
using Record = std::vector<std::string>;

Record split(const std::string& comma_sep_line) {
    std::istringstream is(comma_sep_line);
    Record record;
    Field field;
    while (std::getline(is, field, ',')) {
        back_inserter(record) = field;
    }
    return record;
}

void read_csv(std::istream& is, std::vector<Record>& result) {
    std::string line;
    while (std::getline(is, line)) {
        auto record = csv::split(line);
        back_inserter(result) = record;
    }
}

void read_csv_file(const std::string& path, std::vector<Record>& result) {
    auto ifs = std::ifstream(path, std::ifstream::in);
    read_csv(ifs, result);
    ifs.close();
}

// 任意の列を集める.
std::vector<Field> get_cols(const std::vector<Record>& records, int colnum) {
    std::vector<Field> cols;
    std::transform(records.begin(), records.end(), std::back_inserter(cols),
                   [colnum](const Record& record) { return record[colnum]; });
    return cols;
}

// もっとも長い要素の長さ.
int get_max_length(const std::vector<Field>& cols) {
    auto max_field = *std::max_element(
        cols.begin(), cols.end(),
        [](const Field& a, const Field& b) { return a.length() < b.length(); });
    return max_field.length();
}
}

#endif
