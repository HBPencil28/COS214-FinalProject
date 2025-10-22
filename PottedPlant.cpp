#include "PottedPlant.h"

PottedPlant::PottedPlant(Plant *plant){
    std::cout << "Creating a potted plant" << std::endl;
    this->type = "Potted";
    this->plant = plant;
}

PottedPlant::~PottedPlant(){
    if (plant){
        delete plant;
        plant = nullptr;
    }
    for (std::vector<PlantComponent *>::iterator it = parts.begin(); it != parts.end(); ++it){
        delete *it;
    }
}

void PottedPlant::addPart(PlantComponent *plant){
    if (plant == nullptr)
    {
        std::cout << "Adding a nullptr plant" << std::endl;
        return;
    }
    this->parts.push_back(plant);
}