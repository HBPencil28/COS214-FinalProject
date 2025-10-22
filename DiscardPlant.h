#ifndef DISCARDPLANT_H
#define DISCARDPLANT_H

#include "CareCommand.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class DiscardPlant : public CareCommand{
    public:
        DiscardPlant(Plant* p) : plant(p) {}
        
        virtual void execute() {
            // Implementation for discarding a plant
            cout << "[Command] Discarding plant..." << plant->getName() << " (name) in" << plant->getStateName()<< " (state)..." << endl;
            plant->discard();
        }
};

#endif