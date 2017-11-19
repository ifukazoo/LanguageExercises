#include <iostream>

int main()
{
    std::string noun, verb, adjective, adverb;

    std::cout << "Enter a noun: ";
    std::getline(std::cin, noun);

    std::cout << "Enter a verb: ";
    std::getline(std::cin, verb);

    std::cout << "Enter an adjective: ";
    std::getline(std::cin, adjective);

    std::cout << "Enter an adverb: ";
    std::getline(std::cin, adverb);

    std::cout << "Do you " << verb << " your " << adjective << " " << noun << " " << adverb << "? That's hilarious!" << std::endl;

    return 0;
}
