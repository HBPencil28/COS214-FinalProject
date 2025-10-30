#include "FertilisePlant.h"
#include "CareStaff.h"
#include "Zone.h"
#include <iostream>

using namespace std;

FertilisePlant::FertilisePlant(CareStaff *c, int f) : CareCommand(c), fertilizer(f) {}

void FertilisePlant::execute(Zone *z){
    // cout << "[Command] " << staff.getName() << " fertilises " << plant->getName()
    //      << " in " << plant->getStateName() << " with " << fertiliserAmount << "g." << endl;
    staff->setSubject(z);
    staff->fertilise(this->fertilizer);

    // cout << "[Command] " << this->staff->getName() << " fertilises zone:" << z->getZoneName()
    cout << "[Command] " << " fertilises zone:" << z->getZoneName()
         << " amount: " << this->fertilizer << endl;

    // plant->ifertilise(fertiliserAmount);
    // plant->checkGrowth();
}