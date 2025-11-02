#include "NormalStaff.h"

void NormalStaff::handleRequest(const string& request) {
    if (request.compare("care request") == 0 || request.compare("delivery") == 0 || request.compare( "customer") == 0)
    {
        cout << "Request handled by Normal Staff." << endl;
    } 
    else if (nextHandler) {
        nextHandler->handleRequest(request);
    } 
    else {
        cout << "No handler available for the request." << endl;
    }
}