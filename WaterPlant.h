#ifndef WATERPLANT_H
#define WATERPLANT_H

#include "CareCommand.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class WaterPlant : public CareCommand{
    protected:
        Plant* plant;
    public:
        virtual void execute(CareStaff& staff) {
            // Implementation for watering a plant
            cout << "[Command] Watering plant (" << plant->getStateName()<< " (state)..." << endl;
            plant->water();
        }
};

#endif