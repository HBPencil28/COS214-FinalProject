#ifndef WATERPLANT_H
#define WATERPLANT_H

#include "CareCommand.h"
#include "CareStaff.h"
#include "Zone.h"

#include <iostream>

using namespace std;

class WaterPlant : public CareCommand {
    private:
        int water;

public:
    WaterPlant(CareStaff* c, int w);
    virtual void execute(Zone* z) override;
};

#endif
