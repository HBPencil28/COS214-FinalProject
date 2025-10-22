#include "PlantWrap.h"

PlantWrap::PlantWrap() : PlantComponent("Wrap"){
    this->type = "Basic";
}

PlantWrap::~PlantWrap(){}

void PlantWrap::changeType(std::string type){
    this->type = type;
}