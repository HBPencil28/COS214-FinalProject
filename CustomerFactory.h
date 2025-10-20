#ifndef CUSTOMERFACTORY_H
#define CUSTOMERFACTORY_H

#include "StaffFactory.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class CustomerFactory :public StaffFactory{
    public:
        virtual void createStaff(const string& name) const {
            cout << "Creating Customer Staff: " << name << endl;
        }
};

#endif