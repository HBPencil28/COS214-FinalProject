#include "PlantComponent.h"

PlantComponent::PlantComponent(std::string name) : name(name){}

PlantComponent::~PlantComponent(){}

std::string PlantComponent::getName(){ return this->name;}

std::string PlantComponent::getType(){ return this->type;}

void PlantComponent::changeType(std::string type){
    this->type = type;
}