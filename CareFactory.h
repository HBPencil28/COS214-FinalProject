#ifndef CAREFACTORY_H
#define CAREFACTORY_H

#include "StaffFactory.h"
#include "CareStaff.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class CareFactory :public StaffFactory{
    public:
        virtual Staff* createStaff() const {
            return new CareStaff();
        }
};

#endif