/**
 * @file CustomisePlant.cpp
 * @brief Implements the CustomisePlant command.
 */

#include "CustomisePlant.h"
#include "CustomerStaff.h"

void CustomisePlant::execute() {
    // Downcast Staff* to CustomerStaff*
    CustomerStaff* customerStaff = dynamic_cast<CustomerStaff*>(assistant);
    if (customerStaff) {
        // Perform customization through the staff member
        BasePlant* p = customerStaff->customise(toBeCustomized, customisationDetails);
        // customer->addPurchases(p);
        customer->replacePurchase(toBeCustomized, p);
    } else {
        std::cerr << "Error: Staff member is not a CustomerStaff." << std::endl;
    }
}
