/**
 * @file NormalStaff.h
 * @brief Declares the NormalStaff class for handling general requests.
 */

#ifndef NORMALSTAFF_H
#define NORMALSTAFF_H

#include "StaffHandler.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

/**
 * @class NormalStaff
 * @brief Concrete handler for basic requests such as customer service or deliveries.
 */
class NormalStaff : public StaffHandler {
public:
    /**
     * @brief Handles normal staff-level requests.
     * @param request The incoming request description.
     */
    virtual void handleRequest(const string& request);
};

#endif
