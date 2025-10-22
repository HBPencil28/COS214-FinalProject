#ifndef MANAGER_H
#define MANAGER_H\

#include "StaffHandler.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Manager : public StaffHandler{
    public:
        virtual void handleRequest(const string& request) {
            if (request.contains("inventory") || request.contains("staff") || request.contains("financial report")) {
                cout << "Request handled by Manager." << endl;
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