#include "MediumCare.h"

MediumCare::MediumCare(Zone *zone, CareStaff *c) : CareStrategy(50, 5, zone, c) {}

MediumCare::~MediumCare(){}

// void MediumCare::care(){
void MediumCare::care(){
    // std::cout << "Begining the Medium care process" << std::endl;
    // Medium care operations
    fertiliseCommand->execute(this->zone);
    waterCommand->execute(this->zone);
}