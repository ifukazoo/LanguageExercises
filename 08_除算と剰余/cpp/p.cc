#include <iostream>

// ピザ1枚あたりのピース
const int kPiecesPerPizza = 8;

int main()
{
    std::string input;

    std::cout << "How many people? ";
    std::getline(std::cin, input);
    int num_people = std::stoi(input);

    std::cout << "How many pizzas do you have? ";
    std::getline(std::cin, input);
    int num_pizzas = std::stoi(input);

    std::cout << num_people << " people with " << num_pizzas << " pizzas" << std::endl;

    int pieces =  num_pizzas * kPiecesPerPizza;
    auto div_mod = std::div(pieces, num_people);
    std::cout << "Each person gets " << div_mod.quot << " pieces of pizza." << std::endl;
    std::cout << "Threre are "       << div_mod.rem  << " leftover pieces." << std::endl;

    return 0;
}
