#ifndef FERTILISEPLANT_H
#define FERTILISEPLANT_H

#include "CareCommand.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class FertilisePlant : public CareCommand{
    protected:
        Plant* plant;
    public:
        virtual void execute() {
            // Implementation for fertilising a plant
            cout << "[Command] Fertilising plant (" << plant->getStateName() << " (state)..." << endl;
            plant->fertilise();
        }
};

#endif