#ifndef STAFF_H 
#define STAFF_H

#include <string>
#include <vector>
#include <iostream>

#include "NurseryMediator.h"
#include "Inventory.h"


using namespace std;

class Staff{
protected:
    
    NurseryMediator* mediator;
    Inventory* inv;
public:
    Staff();
    void registerMediator(NurseryMediator* mediator);

    // this would be the method use to take or add to the inventory
    // CareStaff when they add a mature plant, DeliveryStaff && CustomerStaff when they take a plant
    virtual void changed() = 0; 

    // CareStaff will say the plant they restocked, DeliveryStaff && CustomerStaff will say the plant they finished
    virtual std::string get() = 0;

    // receive notification from the mediator
    virtual void set(std::string) = 0;


};

#endif