#ifndef SENIORMANAGER_H
#define SENIORMANAGER_H

#include "StaffHandler.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class SeniorManager{
    public:
        virtual void handleRequest(const string& request);
};

#endif