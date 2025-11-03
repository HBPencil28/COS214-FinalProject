/**
 * @file CustomisePlant.h
 * @brief Declares the CustomisePlant command for modifying a customer's plant.
 */

#ifndef CUSTOMISEPLANT_H
#define CUSTOMISEPLANT_H

#include <iostream>
#include <string>
#include "CustomerCommand.h"
#include "BasePlant.h"
#include "Customer.h"

/**
 * @class CustomisePlant
 * @brief Concrete command for plant customization requests.
 *
 * This command allows customers to customize or modify one of their purchased plants.
 * The command delegates customization handling to a CustomerStaff instance.
 */
class CustomisePlant : public CustomerCommand {

private:
    /** @brief Pointer to the plant that will be customized. */
    BasePlant* toBeCustomized;

    /** @brief Details describing the customization. */
    std::string customisationDetails;

    /** @brief Pointer to the customer owning the plant. */
    Customer* customer;

public:
    /**
     * @brief Constructs a CustomisePlant command.
     * @param details Description of the customization.
     * @param staff Pointer to the assisting staff member.
     * @param toCustomise Pointer to the plant being customized.
     * @param receiver Pointer to the customer receiving the customized plant.
     */
    CustomisePlant(const std::string& details, Staff* staff, BasePlant* toCustomise, Customer* receiver)
        : CustomerCommand(staff), toBeCustomized(toCustomise),
          customisationDetails(details), customer(receiver) {}

    /** @brief Executes the customization command. */
    void execute() override;
};

#endif // CUSTOMISEPLANT_H
