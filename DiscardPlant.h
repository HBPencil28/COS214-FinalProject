#ifndef DISCARDPLANT_H
#define DISCARDPLANT_H

#include "CareCommand.h"
#include <iostream>
using namespace std;

class DiscardPlant : public CareCommand {
public:
    DiscardPlant(Plant* p) : CareCommand(p) {}

    virtual void execute(CareStaff& staff, double waterAmount, double fertiliserAmount) {
        if (plant->getStateName() == "Wilted") 
        {
            cout << "[Command] " << staff.getName() << " discards wilted plant " << plant->getName() << "." << endl;
            plant->discard();
        } 
        else 
        {
            cout << "[Command] Plant " << plant->getName() << " is not wilted — discard aborted." << endl;
        }
    }
};

#endif
