#ifndef STAFF_H 
#define STAFF_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Staff{
    protected:
        string name;
        string position;

    public:
        Staff(string name, string position) : name(name), position(position) {}
        virtual ~Staff() {}

        string getName() const {
            return name;
        }
        
        string getPosition() const {
            return position;
        }

        virtual void performDuty() const = 0;
};

#endif