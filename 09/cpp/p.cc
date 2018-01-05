#include <cmath>
#include <cstdlib>

#include <algorithm>  // min
#include <iostream>

const double kPaintablePerGallon = 350.0;

int main() {
    std::string input;

    std::cout << "What is the length of the room in feet? ";
    std::getline(std::cin, input);
    int length_room = std::stoi(input);

    std::cout << "What is the width of the room in feet? ";
    std::getline(std::cin, input);
    int width_room = std::stoi(input);

    int feet_room = length_room * width_room;
    double gallon = feet_room / kPaintablePerGallon;
    int num_gallon = static_cast<int>(ceil(gallon));

    std::cout << "You will need to purchase " << num_gallon
              << " gallons of paint to cover " << feet_room << " square feet."
              << std::endl;

    return 0;
}
