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
            cout << "Harvesting and storing plant..." << endl;
            plant->harvestAndStore();
        }
};

#endif