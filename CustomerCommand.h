/**
 * @file CustomerCommand.h
 * @brief Defines the abstract base class for all customer-related commands.
 */

#ifndef CUSTOMERCOMMAND_H
#define CUSTOMERCOMMAND_H

#include <iostream>
#include <string>
#include "Staff.h"

/**
 * @class CustomerCommand
 * @brief Abstract base class representing a command executed by a customer.
 *
 * The CustomerCommand class defines a uniform interface for executing customer
 * requests. Concrete command classes (e.g., BuyPlant, RequestHelp, CustomisePlant)
 * will derive from this class and implement the `execute()` method.
 */
class CustomerCommand {

protected:
    /** @brief Pointer to the staff member responsible for executing the command. */
    Staff* assistant;

public:
    /**
     * @brief Constructs a CustomerCommand with a given staff assistant.
     * @param staff Pointer to the staff member associated with the command.
     */
    CustomerCommand(Staff* staff) : assistant(staff) {}

    /** @brief Virtual destructor. */
    virtual ~CustomerCommand() {}

    /**
     * @brief Executes the command.
     * 
     * This pure virtual function must be implemented by all derived command classes.
     */
    virtual void execute() = 0;
};

#endif // CUSTOMERCOMMAND_H
