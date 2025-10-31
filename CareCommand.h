#ifndef CARECOMMAND_H
#define CARECOMMAND_H

#include "CareStaff.h"
#include "Plant.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class CareStaff;

class CareCommand{
    protected:
        Plant* plant;
    public:
        CareCommand(Plant* p);

        virtual void execute(CareStaff& staff, double waterAmount, double fertiliseAmount) = 0;
        virtual ~CareCommand();
};

#endif