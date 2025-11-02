#ifndef MANAGER_H
#define MANAGER_H\

#include "StaffHandler.h"
#include "NurseryMediator.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Manager : public StaffHandler, public NurseryMediator {
    public:
        virtual void handleRequest(const string& request);
};

#endif