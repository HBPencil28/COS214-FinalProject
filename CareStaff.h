#ifndef CARESTAFF_H
#define CARESTAFF_H

#include "Staff.h"
#include "CareCommand.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CareStaff : public Staff {
    private:
        Greenhouse* zone;
    public:
        CareStaff(const string &name) : Staff(name, "Care"), zone(nullptr) {}
        ~CareStaff() {}

        virtual void performDuty() const
        {
            
        }

        void water(int amount){
            for (Greenhouse *plant : static_cast<Zone*>(this->zone)->getChildren()){
                static_cast<Plant *>(plant)->water(amount);
            }
        }

        void fertilise(int amount){
            for (Greenhouse *plant : static_cast<Zone*>(this->zone)->getChildren()){
                static_cast<Plant *>(plant)->water(amount);
            }
        }

        void setZone(Greenhouse* zone){
            if (zone){
                this->zone = zone;
            }
            
        }
};

#endif