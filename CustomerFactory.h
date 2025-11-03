#ifndef CUSTOMERFACTORY_H
#define CUSTOMERFACTORY_H

#include "StaffFactory.h"
#include "CustomerStaff.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class CustomerFactory :public StaffFactory{
    public:
        virtual Staff* createStaff() const {
            //cout << "Creating Customer Staff: " << endl;
            return new CustomerStaff();
        }
};

#endif