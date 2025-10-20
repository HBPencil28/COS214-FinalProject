#ifndef STAFFFACTORY_H
#define STAFFFACTORY_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class StaffFactory{
    public:
        virtual ~StaffFactory() {}
        virtual void createStaff(const string& name) const = 0;
};

#endif