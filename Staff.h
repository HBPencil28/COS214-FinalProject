#ifndef STAFF_H 
#define STAFF_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Staff{
    protected:
        string name;

    public:
        Staff(string name) : name(name) {}
        virtual ~Staff() {}

        string getName() const {
            return name;
        }
        
        virtual void performDuty() const = 0;
};

#endif