#include "WrappedPlant.h"

WrappedPlant::WrappedPlant() : BasePlant("Wrapped"){
    // std::cout << "Creating a wrappedPlant plant" << std::endl;
}

WrappedPlant::~WrappedPlant(){
    for (std::vector<Plant *>::iterator it = plants.begin(); it != plants.end(); ++it){
        delete *it;
    }

    for (std::vector<PlantComponent *>::iterator it = parts.begin(); it != parts.end(); ++it){
        delete *it;
    }
}

void WrappedPlant::addPlant(Plant* plant){
    if (plant == nullptr){
        // std::cout << "Adding a nullptr plant" << std::endl;
        return;
    }
    this->plants.push_back(plant);
}

void WrappedPlant::addPart(PlantComponent *plant){
    if (plant == nullptr){
        // std::cout << "Adding a nullptr plant" << std::endl;
        return;
    }
    this->parts.push_back(plant);
}
