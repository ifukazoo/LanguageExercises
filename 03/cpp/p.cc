#include <iostream>

int main()
{
    std::string the_quote = "These aren't the droids you're looking for.";
    std::cout << "What is the quote? " + the_quote << std::endl;
    std::cout << "Who said it? ";
    std::string who;
    std::getline(std::cin, who);
    std::cout << who + " says, \"" + the_quote + "\"" << std::endl;
    return 0;
}
