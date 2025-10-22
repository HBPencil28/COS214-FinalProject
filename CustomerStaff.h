#ifndef CUSTOMERSTAFF_H
#define CUSTOMERSTAFF_H

#include "Staff.h"
#include "CustomerCommand.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CustomerStaff :public Staff {
    private: 
        vector<string> requests;
    public:
        CustomerStaff(string name) : Staff(name, "Customer") {}
        ~CustomerStaff() {}

        virtual void performDuty() const
        {
            
        }
};

#endif