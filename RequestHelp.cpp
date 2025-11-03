/**
 * @file RequestHelp.cpp
 * @brief Implements the RequestHelp command.
 */

#include "RequestHelp.h"
#include "CustomerStaff.h"

void RequestHelp::execute() {
    // Downcast Staff* to CustomerStaff*
    CustomerStaff* customerStaff = dynamic_cast<CustomerStaff*>(assistant);
    if (customerStaff) {
        customerStaff->advise(issueDescription);
    } else {
        std::cerr << "Error: Staff member is not a CustomerStaff." << std::endl;
    }
}
