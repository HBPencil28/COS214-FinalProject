/**
 * @file StaffHandler.h
 * @brief Declares the abstract base class for handling staff requests in a chain.
 */

#ifndef STAFFHANDLER_H
#define STAFFHANDLER_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

/**
 * @class StaffHandler
 * @brief Abstract base class implementing the Chain of Responsibility pattern.
 *
 * Each StaffHandler represents a level of staff (e.g., NormalStaff, Manager, SeniorManager)
 * capable of processing certain types of requests. If a handler cannot process a request,
 * it passes it to the next handler in the chain.
 */
class StaffHandler {
protected:
    /** @brief Pointer to the next handler in the chain. */
    StaffHandler* nextHandler;

public:
    /** @brief Default constructor initializing the next handler to nullptr. */
    StaffHandler();

    /**
     * @brief Sets the next handler in the chain.
     * @param handler Pointer to the next StaffHandler.
     */
    void setNextHandler(StaffHandler* handler);

    /**
     * @brief Handles a given request.
     * @param request The request description.
     *
     * Must be implemented by all concrete subclasses.
     */
    virtual void handleRequest(const string& request) = 0;

    /** @brief Virtual destructor. */
    virtual ~StaffHandler();
};

#endif
