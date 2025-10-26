#include "HighCare.h"

HighCare::HighCare(Plant *plant) : CareStrategy(100, 10, plant) {}

HighCare::~HighCare(){}

// void HighCare::care(){
void HighCare::care(CareStaff *staff){
    std::cout << "Begining the High care process" << std::endl;
    // High care operations
    // waterCommand->execute(this->water);
    waterCommand->execute(*staff);
    // fertiliseCommand->execute(this->fertilizer);
    fertiliseCommand->execute(*staff);
}