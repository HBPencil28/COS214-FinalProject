#ifndef CAREFACTORY_H
#define CAREFACTORY_H

#include "StaffFactory.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class CareFactory :public StaffFactory{
    public:
        virtual Staff* createStaff(const string& name) const {
            cout << "Creating Care Staff: " << name << endl;
            return new CareStaff(name);
        }
};

#endif