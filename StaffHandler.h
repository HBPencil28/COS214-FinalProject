#ifndef STAFFHANDLER_H
#define STAFFHANDLER_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class StaffHandler{
    protected:
        StaffHandler* nextHandler;
    public:
        StaffHandler();
        
        void setNextHandler(StaffHandler* handler);

        virtual void handleRequest(const string& request) = 0;
        virtual ~StaffHandler();
};

#endif