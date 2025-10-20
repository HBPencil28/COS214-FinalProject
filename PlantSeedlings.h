#ifndef PLANTSEEDLINGS_H
#define PLANTSEEDLINGS_H

#include "CareCommand.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class PlantSeedlings : public CareCommand{
    protected:
        Plant* plant;
    public:
        virtual void execute(CareStaff& staff) {
            // Implementation for planting seedlings
            cout << "Planting seedlings..." << endl;
            plant->plantSeedlings();
        }
};

#endif