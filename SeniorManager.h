/**
 * @file SeniorManager.h
 * @brief Declares the SeniorManager class for reviewing high-level requests.
 */

#ifndef SENIORMANAGER_H
#define SENIORMANAGER_H

#include "StaffHandler.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

/**
 * @class SeniorManager
 * @brief Concrete handler for top-level managerial or escalated requests.
 */
class SeniorManager : public StaffHandler {
public:
    /**
     * @brief Reviews or finalizes senior management-level requests.
     * @param request The request description.
     */
    virtual void handleRequest(const string& request);
};

#endif
