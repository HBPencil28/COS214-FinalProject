#ifndef STAFF_H 
#define STAFF_H

#include <string>
#include <vector>
#include <map>
#include <iostream>


#include "Inventory.h"

class NurseryMediator;
using namespace std;

class Staff{
protected:
    NurseryMediator* mediator;
    Inventory* inv;
    map<string, bool> stockAvailability; // keeps track of available stock, true = available, false = out of stock
public:
    Staff();
    void registerMediator(NurseryMediator* mediator);
    void deregisterMediator();

    // this would be the method use to take or add to the inventory
    // CareStaff when they add a mature plant, DeliveryStaff && CustomerStaff when they take a plant
    virtual void changed() = 0; 

    // CareStaff will say the plant they restocked, DeliveryStaff && CustomerStaff will say the plant they finished
    virtual std::map<std::string, bool> get() = 0;

    // receive notification from the mediator
    virtual void set(std::map<std::string, bool>) = 0;


};

#endif