#include <iostream>
#include <map>

int main()
{
    std::map<std::string, std::string> password_map = {
        {"figaro",  "abcd"},
        {"susanna", "1234"},
        {"almaviva","ABCD"},
        {"rosina",  "5678"},
    };

    std::string input_name;
    std::cout << "What is the usernames? ";
    std::getline(std::cin, input_name);

    std::string input_password;
    std::cout << "What is the password? ";
    std::getline(std::cin, input_password);

    // map[]は, 存在しないキーアクセスするとデフォルト値を作成する
    auto password = password_map[input_name];
    if (password == "") {
        std::cout << "I don't know you." << std::endl;
    } else {
        if (input_password == password) {
            std::cout << "Welcome!" << std::endl;
        } else {
            std::cout << "I don't know you." << std::endl;
        }
    }
    return 0;
}
