#ifndef DELIVERYFACTORY_H
#define DELIVERYFACTORY_H

#include "StaffFactory.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class DeliveryFactory :public StaffFactory{
    public:
        virtual Staff* createStaff(const string& name) const {
            cout << "Creating Delivery Staff: " << name << endl;
            return new DeliveryStaff(name);
        }

};

#endif