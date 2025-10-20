#ifndef CARESTAFF_H
#define CARESTAFF_H

#include "Staff.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CareStaff : public Staff {
    public:
        CareStaff() : Staff("Care Team", "Caregiver") {}
        ~CareStaff() {}

        virtual void performDuty() const
        {
            cout << "Providing care and support to clients." << endl;
        }
};

#endif