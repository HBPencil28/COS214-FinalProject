#include "PlantDecorator.h"
#include "Plant.h"
#include "PlantComponent.h"

PlantDecorator::PlantDecorator() : BasePlant("Decorator"), decoration(nullptr){}

PlantDecorator::~PlantDecorator(){
    if (decoration){
        delete decoration;
    }
    decoration = nullptr;
}

BasePlant* PlantDecorator::getDecoration() { return this->decoration; }

void PlantDecorator::add(BasePlant *plantDecoration){
    if (plantDecoration == nullptr){
        std::cout << "Trying to add nullptr decoration" << std::endl;
        return;
    }
    
    if (this->decoration == nullptr){
        decoration = plantDecoration;
    }else{
        this->decoration->add(plantDecoration);
    }
}

void PlantDecorator::addPart(PlantComponent *plant){
    /* Add implementation here if needed */
    if(plant){
        std::cout << "Studded" << std::endl;
    }
}