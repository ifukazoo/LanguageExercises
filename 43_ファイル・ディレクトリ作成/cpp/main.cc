#include <fstream>
#include <iostream>

#include <boost/filesystem.hpp>

#include "strings.h"
#include "user_input.h"

namespace fs = boost::filesystem;
namespace sys = boost::system;

namespace {

bool validate_not_empty(const std::string& s, std::string& value) {
    auto trimed_s = strings::trim(s);
    if (trimed_s.empty()) {
        return false;
    }
    value = trimed_s;
    return true;
}

bool validate_yes_no(const std::string& s, bool& value) {
    auto trimed_s = strings::trim(s);
    if (trimed_s.empty()) {
        return false;
    }
    value = std::tolower(trimed_s[0]) == 'y';
    return true;
}

void create_index_html(const std::string& path, const std::string& title,
                       const std::string& author_name) {
    std::ofstream ofs(path, std::ios_base::trunc);
    ofs << "<html>" << std::endl;
    ofs << "<head>" << std::endl;
    ofs << "<title>" << title << "</title>" << std::endl;
    ofs << "<meta name=\"author\" content=\"" << author_name << "\">"
        << std::endl;
    ofs << "</head>" << std::endl;
    ofs << "</html>" << std::endl;
    ofs.close();
}

void make_dirs(const fs::path& path) {
    sys::error_code err;
    fs::create_directories(path, err);
    if (err.value() != 0) {
        std::cerr << "error:" << err.message() << std::endl;
        exit(EXIT_FAILURE);
    }
    return;
}

}  // namespace

int main() {
    const std::string wrong_input_msg = "Sorry. That's not a valid input.";

    auto site_name = read_user_input_with_validator<std::string>(
        "Site name: ", validate_not_empty, wrong_input_msg);

    auto author_name = read_user_input_with_validator<std::string>(
        "Author: ", validate_not_empty, wrong_input_msg);

    auto has_js = read_user_input_with_validator<bool>(
        "Do you want a folder fo JavaScript? ", validate_yes_no,
        wrong_input_msg);

    auto has_css = read_user_input_with_validator<bool>(
        "Do you want a folder fo CSS? ", validate_yes_no, wrong_input_msg);

    fs::path site_dir_path("./" + site_name);
    make_dirs(site_dir_path);
    std::cout << "Created " << site_dir_path.string() << std::endl;

    auto index_path = site_dir_path.string() + "/index.html";
    create_index_html(index_path, site_name, author_name);
    std::cout << "Created " << index_path << std::endl;

    if (has_js) {
        fs::path site_js_dir_path(site_dir_path.string() + "/js");
        make_dirs(site_js_dir_path);
        std::cout << "Created " << site_js_dir_path.string() << std::endl;
    }
    if (has_css) {
        fs::path site_css_dir_path(site_dir_path.string() + "/css");
        make_dirs(site_css_dir_path);
        std::cout << "Created " << site_css_dir_path.string() << std::endl;
    }

    exit(EXIT_SUCCESS);
}
