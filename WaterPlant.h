#ifndef WATERPLANT_H
#define WATERPLANT_H

#include "CareCommand.h"
#include <iostream>
using namespace std;

class WaterPlant : public CareCommand {
public:
    WaterPlant(Plant* p) : CareCommand(p) {}

    virtual void execute(CareStaff& staff, double waterAmount, double fertiliserAmount) {
        cout << "[Command] " << staff.getName() << " waters " << plant->getName()
             << " in " << plant->getStateName() << " with " << waterAmount << "L." << endl;

        // Increase the water level of the plant
        plant->water(waterAmount);
    }
};

#endif
