#ifndef FERTILISEPLANT_H
#define FERTILISEPLANT_H

#include "CareCommand.h"
#include <iostream>
using namespace std;

class FertilisePlant : public CareCommand {
private:
    int fertilizer;

public:
    FertilisePlant(CareStaff *c, int f) : CareCommand(c),fertilizer(f) {}

    virtual void execute(Zone* z) {
        // cout << "[Command] " << staff.getName() << " fertilises " << plant->getName()
        //      << " in " << plant->getStateName() << " with " << fertiliserAmount << "g." << endl;
        staff->setZone(z);
        staff->fertilise(this->fertilizer);

        cout << "[Command] " << this->staff->getName() << " fertilises zone:" << z->getZoneName()
             << " amount: " << this->fertilizer << endl;

        // plant->ifertilise(fertiliserAmount);
        //plant->checkGrowth();
    }
};

#endif
