#ifndef CARESTAFF_H
#define CARESTAFF_H

#include "Staff.h"
#include "CareCommand.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CareStaff : public Staff {
    public:
        CareStaff(const string &name) : Staff(name, "Care") {}
        ~CareStaff() {}

        virtual void performDuty() const
        {
            
        }
};

#endif