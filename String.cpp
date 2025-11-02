#include "String.h"

String::String() : PlantDecorator(){
    // std::cout << "Creating a bow" << std::endl;
    this->type = "Basic";
}

String::~String(){}

void String::changeType(std::string newType){
    this->type = newType;
}