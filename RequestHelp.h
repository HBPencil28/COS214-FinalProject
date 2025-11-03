/**
 * @file RequestHelp.h
 * @brief Declares the RequestHelp command used by customers to seek assistance.
 */

#ifndef REQUESTHELP_H
#define REQUESTHELP_H

#include <iostream>
#include <string>
#include "CustomerCommand.h"

/**
 * @class RequestHelp
 * @brief Concrete command allowing a customer to request help from staff.
 *
 * This command uses the Command pattern to encapsulate a help request.
 * When executed, it delegates the handling of the request to a CustomerStaff member.
 */
class RequestHelp : public CustomerCommand {

private:
    /** @brief Description of the customer's issue or question. */
    std::string issueDescription;

public:
    /**
     * @brief Constructs a RequestHelp command.
     * @param issue The help request description.
     * @param staff Pointer to the staff member who will handle the request.
     */
    RequestHelp(const std::string& issue, Staff* staff)
        : CustomerCommand(staff), issueDescription(issue) {}

    /** @brief Executes the help request command. */
    void execute() override;
};

#endif // REQUESTHELP_H
