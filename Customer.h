/**
 * @file Customer.h
 * @brief Declares the Customer class that manages plant purchases and requests.
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>

#include "order.h"
#include "BasePlant.h"
#include "Staff.h"
#include "CustomerStaff.h"

/**
 * @class Customer
 * @brief Represents a customer who can interact with nursery staff and purchase plants.
 *
 * The Customer class encapsulates purchasing, requesting help, and customizing plants.
 * It uses the Command pattern to delegate these operations to staff members.
 */
class Customer {
private:
    /** @brief Stores the list of purchased plants. */
    std::vector<BasePlant*> purchases;

    /** @brief Represents the customer's available balance (wallet). */
    double wallet;

public:
    /** @brief Destructor. Cleans up dynamically allocated purchased plants. */
    ~Customer();

    /**
     * @brief Allows the customer to buy a plant.
     * @param attender Pointer to the staff attending the customer.
     * @param purchaseDetails Pointer to the Order object describing the purchase.
     */
    void buyPlant(Staff* attender, Order* purchaseDetails);

    /**
     * @brief Allows the customer to request help from a staff member.
     * @param attender Pointer to the staff member to assist.
     * @param question The help question or issue description.
     */
    void requestHelp(Staff* attender, std::string& question);

    /**
     * @brief Allows the customer to customize their plant.
     * @param attender Pointer to the staff member performing the customization.
     * @param accessory Description of the customization or accessory.
     */
    void customiseMyPlant(Staff* attender, std::string& accessory);

    /**
     * @brief Adds a purchased plant to the customer's purchase list.
     * @param p Pointer to the BasePlant object purchased.
     */
    void addPurchases(BasePlant* p);

    void replacePurchase(BasePlant *oldPlant, BasePlant *newPlant);
};

#endif // CUSTOMER_H
