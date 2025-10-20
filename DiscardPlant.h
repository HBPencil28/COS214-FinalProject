#ifndef DISCARDPLANT_H
#define DISCARDPLANT_H

#include "CareCommand.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class DiscardPlant : public CareCommand{
    protected:
        Plant* plant;
    public:
        DiscardPlant(Plant* p) : plant(p) {}
        
        virtual void execute() {
            // Implementation for discarding a plant
            cout << "Discarding plant..." << endl;
            plant->discard();
        }
};

#endif