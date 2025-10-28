#ifndef WATERPLANT_H
#define WATERPLANT_H

#include "CareCommand.h"
#include <iostream>
using namespace std;

class WaterPlant : public CareCommand {
    private:
        int water;

public:
    WaterPlant(CareStaff* c, int w) : CareCommand(c), water(w){}

    virtual void execute(Zone* z) {
        // cout << "[Command] " << staff.getName() << " waters " << plant->getName()
        //      << " in " << plant->getStateName() << " with " << waterAmount << "L." << endl;
        staff->setZone(z);
        staff->water(this->water);
        
        cout << "[Command] " << this->staff->getName() << " waters zone:" << z->getZoneName()
             << " amount: " << this->water << endl;

        // Increase the water level of the plant
        // plant->water(waterAmount);
    }
};

#endif
