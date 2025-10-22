#ifndef STAFF_H 
#define STAFF_H

#include "Zone.h"
#include "Plant.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Staff{
    protected:
        string name;
        string type;

    public:
        Staff(const string& staffName, const string& staffType) : name(staffName), type(staffType) {}
        virtual ~Staff() {}

        string getName() const 
        {
            return name;
        }

        string getType() const 
        {
            return type;
        }
        
        virtual void performDuty() const = 0;
};

#endif