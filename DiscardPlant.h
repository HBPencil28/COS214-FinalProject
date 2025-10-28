#ifndef DISCARDPLANT_H
#define DISCARDPLANT_H

#include "CareCommand.h"
#include <iostream>
using namespace std;

class DiscardPlant : public CareCommand {
private:
    Plant *plant;

public:
    DiscardPlant(CareStaff* c,Plant* p) : CareCommand(c) , plant(p) {}

    virtual void execute(Zone* z) {
        if (plant->getStateName() == "Wilted") 
        {
            cout << "[Command] " << this->staff->getName() << " discards wilted plant " << plant->getName() << "." << endl;
            plant->discard();
        } 
        else 
        {
            cout << "[Command] Plant " << plant->getName() << " is not wilted — discard aborted." << endl;
        }
    }
};

#endif
