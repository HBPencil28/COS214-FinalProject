/**
 * @file BuyPlant.h
 * @brief Declares the BuyPlant command for purchasing a plant.
 */

#ifndef BUYPLANT_H
#define BUYPLANT_H

#include <iostream>
#include <string>  
#include "CustomerCommand.h"
#include "order.h"
#include "Customer.h"

/**
 * @class BuyPlant
 * @brief Concrete command that handles the process of purchasing a plant.
 */
class BuyPlant : public CustomerCommand {

private:
    Order plantDetails;  /**< @brief Details of the plant order. */
    Customer* customer;  /**< @brief Pointer to the customer making the purchase. */

public:
    /**
     * @brief Constructs a BuyPlant command.
     * @param plant The order details.
     * @param staff Pointer to the assisting staff member.
     * @param rec Pointer to the customer receiving the plant.
     */
    BuyPlant(Order& plant, Staff* staff, Customer* rec)
        : CustomerCommand(staff), plantDetails(plant), customer(rec) {}

    /** @brief Executes the purchase operation. */
    void execute() override;    
};

#endif // BUYPLANT_H
