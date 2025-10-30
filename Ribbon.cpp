#include "Ribbon.h"

Ribbon::Ribbon() : PlantDecorator(){
    std::cout << "Creating a ribbon" << std::endl;
    this->colour = "Bland";
}

Ribbon::~Ribbon(){}
void Ribbon::changeColour(std::string newColour){
    this->colour = newColour;
}