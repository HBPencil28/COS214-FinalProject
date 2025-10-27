#ifndef FERTILISEPLANT_H
#define FERTILISEPLANT_H

#include "CareCommand.h"
#include <iostream>
using namespace std;

class FertilisePlant : public CareCommand {
public:
    FertilisePlant(Plant* p) : CareCommand(p) {}

    virtual void execute(CareStaff& staff, double waterAmount, double fertiliserAmount) {
        cout << "[Command] " << staff.getName() << " fertilises " << plant->getName()
             << " in " << plant->getStateName() << " with " << fertiliserAmount << "g." << endl;

        plant->ifertilise(fertiliserAmount);
        //plant->checkGrowth();
    }
};

#endif
