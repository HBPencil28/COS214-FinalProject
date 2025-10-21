#ifndef HARVESTANDSTORE_H
#define HARVESTANDSTORE_H

#include "CareCommand.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class HarvestAndStore : public CareCommand{
    protected:
        Plant* plant;
    public:
        virtual void execute(CareStaff& staff) {
            // Implementation for harvesting and storing a plant
            cout << "[Command] Harvesting and storing plant (" << plant->getStateName() << " (state)..." << endl;
            plant->harvestAndStore();
        }
};

#endif