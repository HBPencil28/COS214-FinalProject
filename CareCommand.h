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
        virtual void execute(CareStaff& staff) = 0;
        virtual ~CareCommand(){}
};

#endif