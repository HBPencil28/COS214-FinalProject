#ifndef CUSTOMERSTAFF_H
#define CUSTOMERSTAFF_H

#include "Staff.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CustomerStaff :public Staff {
    public:
        CustomerStaff() : Staff("Customer Service", "Customer Support Representative") {}
        ~CustomerStaff() {}

        virtual void performDuty() const
        {
            cout << "Assisting customers with their needs." << endl;
        }
};

#endif