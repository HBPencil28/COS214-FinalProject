#include "WaterPlant.h"
#include "CareStaff.h"
#include "Zone.h"
#include <iostream>

using namespace std;

WaterPlant::WaterPlant(CareStaff *c, int w) : CareCommand(c), water(w) {}

void WaterPlant::execute(Zone *z){
    // cout << "[Command] " << staff.getName() << " waters " << plant->getName()
    //      << " in " << plant->getStateName() << " with " << waterAmount << "L." << endl;
    staff->setSubject(z);
    staff->water(this->water);

    // cout << "[Command] " << this->staff->getName() << " waters zone:" << z->getZoneName()
    // cout << "[Command] " << " waters zone:" << z->getZoneName()
    //      << " amount: " << this->water << endl;

    // Increase the water level of the plant
    // plant->water(waterAmount);
}
