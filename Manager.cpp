/**
 * @file Manager.cpp
 * @brief Implements the Manager request handler.
 */

#include "Manager.h"

void Manager::handleRequest(const string &request) {
    if (request.find("inventory") != std::string::npos ||
        request.find("staff") != std::string::npos ||
        request.find("financial report") != std::string::npos) {
        cout << "Request handled by Manager." << endl;
    } else if (nextHandler) {
        nextHandler->handleRequest(request);
    } else {
        cout << "No handler available for the request." << endl;
    }
}
