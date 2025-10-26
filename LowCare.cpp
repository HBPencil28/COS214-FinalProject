#include "LowCare.h"

LowCare::LowCare(Plant *plant) : CareStrategy(20, 2, plant) {}

LowCare::~LowCare(){}

// void LowCare::care(){
void LowCare::care(CareStaff *staff){
    std::cout << "Begining the Low care process" << std::endl;
    // Low care operations
    // waterCommand->execute(this->water);
    waterCommand->execute(*staff);
    // fertiliseCommand->execute(this->fertilizer);
    fertiliseCommand->execute(*staff);
}
