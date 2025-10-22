
#include "Plant.h"

Plant::Plant(std::string typeIndiv, std::string name, std::string state) : type(typeIndiv), name(name), stateName(state) {}

std::string Plant::getType() const {
    return type;
}

void Plant::execute() {
    std::cout << "Type: " << type <<std::endl;
}// might do something might do nothing

Plant::~Plant(){}