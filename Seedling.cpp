#include "Seedling.h"
// #include "Growing.h"
#include "Plant.h"
#include <iostream>

std::string Seedling::getStateName() const {
    return "Seedling";
}
void Seedling::onEnter(Plant* plant) {
    // Initialize seedling-specific attributes
    std::cout << "[Seedling] onEnter: " << plant->getName() << " has entered Seedling state." << std::endl;
}


