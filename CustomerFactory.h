#ifndef CUSTOMERFACTORY_H
#define CUSTOMERFACTORY_H

#include "StaffFactory.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class CustomerFactory :public StaffFactory{
    public:
        virtual Staff* createStaff(const string& name) const {
            cout << "Creating Customer Staff: " << name << endl;
            return new CustomerStaff(name);
        }
};

#endif