#include "NormalStaff.h"

void NormalStaff::handleRequest(const string& request) {
    if (request. contains("care request") || request.contains("delivery") || request.contains( "customer"))
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