#include "PlantPot.h"

PlantPot::PlantPot() : PlantComponent("Pot"){
    this->type = "Basic";
}

PlantPot::~PlantPot(){}

void PlantPot::changeType(std::string type){
    this->type = type;
}