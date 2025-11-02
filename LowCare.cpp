#include "LowCare.h"

LowCare::LowCare(Zone *zone, CareStaff *c) : CareStrategy(20, 2, zone,c) {}

LowCare::~LowCare(){}

// void LowCare::care(){
void LowCare::care(){
    // std::cout << "Begining the Low care process" << std::endl;
    // Low care operations
    fertiliseCommand->execute(this->zone);
    waterCommand->execute(this->zone);
}
