/**
 * @file Manager.h
 * @brief Declares the Manager class for handling managerial-level requests.
 */

#ifndef MANAGER_H
#define MANAGER_H

#include "StaffHandler.h"
#include "NurseryMediator.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

/**
 * @class Manager
 * @brief Concrete handler for intermediate-level requests involving staff or inventory.
 */
class Manager : public StaffHandler, public NurseryMediator {
public:
    /**
     * @brief Handles managerial-level requests.
     * @param request The request description.
     */
    virtual void handleRequest(const string& request);
};

#endif
