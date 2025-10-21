#ifndef CARESTAFF_H
#define CARESTAFF_H

#include "Staff.h"
#include "PlantObserver.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CareStaff : public Staff, public PlantObserver {
    

public:
    CareStaff(string name, int id);
    void update(/*PlantState* state*/) override;
    void changed() override;
    string get() override;
    void set(string) override;

};

#endif