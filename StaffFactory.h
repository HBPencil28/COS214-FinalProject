#ifndef STAFFFACTORY_H
#define STAFFFACTORY_H

#include "Staff.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class StaffFactory{
    public:
        virtual ~StaffFactory() {}
        virtual Staff* createStaff() const = 0;
};

#endif