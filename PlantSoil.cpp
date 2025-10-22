#include "PlantSoil.h"

PlantSoil::PlantSoil() : PlantComponent("Soil"){
    this->type = "Basic";
}

PlantSoil::~PlantSoil() {}

void PlantSoil::changeType(std::string type)
{
    this->type = type;
}