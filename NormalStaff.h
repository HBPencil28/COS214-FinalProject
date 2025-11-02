#ifndef NORMALSTAFF_H
#define NORMALSTAFF_H

#include "StaffHandler.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class NormalStaff : public StaffHandler{
    public:
        virtual void handleRequest(const string& request);
};

#endif