/**
 * @file BuyPlant.cpp
 * @brief Implements the BuyPlant command.
 */

#include "BuyPlant.h"
#include "CustomerStaff.h"

void BuyPlant::execute() {
    // Notify the staff to handle the buy plant request
    BasePlant* p = static_cast<CustomerStaff*>(assistant)->getRequestedPlant(plantDetails);
    customer->addPurchases(p);
}
