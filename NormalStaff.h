#ifndef NORMALSTAFF_H
#define NORMALSTAFF_H

#include "StaffHandler.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class NormalStaff : public StaffHandler{
    public:
        virtual void handleRequest(const string& request) {
            if (request. contains("care request") || request.contains("delivery") || request.contains( "customer")){
                cout << "Request handled by Normal Staff." << endl;
            } 
            else if (nextHandler) {
                nextHandler->handleRequest(request);
            } 
            else {
                cout << "No handler available for the request." << endl;
            }
        }
};

#endif