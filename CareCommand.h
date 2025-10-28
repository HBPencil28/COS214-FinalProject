#ifndef CARECOMMAND_H
#define CARECOMMAND_H

#include "CareStaff.h"
#include "Greenhouse.h"
#include "Plant.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class CareStaff;

class CareCommand{
protected:
    CareStaff *staff;

public:
    CareCommand(CareStaff* s) : staff(s) {}
    virtual void execute(Zone* z) = 0;
    virtual ~CareCommand() {}
};

#endif