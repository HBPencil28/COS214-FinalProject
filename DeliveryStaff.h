#ifndef DELIVERYSTAFF_H
#define DELIVERYSTAFF_H

#include "Staff.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class DeliveryStaff :public Staff {
    public:
        DeliveryStaff(string name) : Staff(name, "Delivery") {}
        ~DeliveryStaff() {}

        virtual void performDuty() const
        {
            cout << "Delivering packages to customers." << endl;
        }
};

#endif