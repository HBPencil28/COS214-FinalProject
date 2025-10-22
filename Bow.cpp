#include "Bow.h"

Bow::Bow(){
    std::cout << "Creating a bow" << std::endl;
    this->style = "Basic";
}
Bow::~Bow(){}

void Bow::changeStyle(std::string newStyle){
    this->style = newStyle;
}