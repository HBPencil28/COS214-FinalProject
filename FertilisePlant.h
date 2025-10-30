#ifndef FERTILISEPLANT_H
#define FERTILISEPLANT_H

#include "CareCommand.h"
#include "CareStaff.h"
#include "Zone.h"

#include <iostream>

using namespace std;

class FertilisePlant : public CareCommand {
private:
    int fertilizer;

public:
    FertilisePlant(CareStaff *c, int f);
    virtual void execute(Zone* z) override;
};

#endif
