#ifndef CARESTAFF_H
#define CARESTAFF_H

#include "Staff.h"
#include "PlantObserver.h"

#include <iostream>
#include <string>
#include <vector>

class Greenhouse;
class Zone;
class Plant;

class CareStaff : public Staff, public PlantObserver{
        
    public:
        CareStaff(const string &name);
        ~CareStaff();

        virtual void performDuty() const;

        void water(int amount);

        void fertilise(int amount);


        void changed()override;

        // CareStaff will say the plant they restocked, DeliveryStaff && CustomerStaff will say the plant they finished
        std::map<std::string, bool> get()override;
        // receive notification from the mediator
        void set(std::map<std::string, bool>)override;

        void update(/*PlantState* state*/) override;
};

#endif