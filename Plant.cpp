
#include "Plant.h"

Plant::Plant() : type("Generic Plant") {}

std::string Plant::getType() {
    return type;
}

void Plant::execute() {}// might do something might do nothing