#include "MediumCare.h"

MediumCare::MediumCare(Plant *plant) : CareStrategy(50, 5, plant) {}

MediumCare::~MediumCare(){}

// void MediumCare::care(){
void MediumCare::care(CareStaff *staff){
    std::cout << "Begining the Medium care process" << std::endl;
    // Medium care operations
    // waterCommand->execute(this->water);
    waterCommand->execute(*staff);
    // fertiliseCommand->execute(this->fertilizer);
    fertiliseCommand->execute(*staff);
}