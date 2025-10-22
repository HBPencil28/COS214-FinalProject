#ifndef WATERPLANT_H
#define WATERPLANT_H

#include "CareCommand.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class WaterPlant : public CareCommand{
    public:
        WaterPlant(Plant* p) : plant(p) {}
        virtual void execute(CareStaff& staff) 
        {
            // Implementation for watering a plant
            cout << "[Command] Watering plant (" << plant->getName() << " (name) in" << plant->getStateName()<< " (state)..." << endl;
            plant->water();
        }
};

#endif