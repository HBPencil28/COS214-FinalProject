#include "HighCare.h"

HighCare::HighCare(Zone *zone, CareStaff *c) : CareStrategy(100, 10, zone, c) {}

HighCare::~HighCare(){}

// void HighCare::care(){
void HighCare::care(){
    // std::cout << "Begining the High care process" << std::endl;
    // High care operations
    fertiliseCommand->execute(this->zone);
    waterCommand->execute(this->zone);
}