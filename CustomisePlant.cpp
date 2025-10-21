#include "CustomisePlant.h"
#include "CustomerStaff.h"

void CustomisePlant::execute() {
    // Downcast Staff* to CustomerStaff*
    CustomerStaff* customerStaff = dynamic_cast<CustomerStaff*>(assistant);
    if (customerStaff) {
        // it is going to be nullptr for now, other there should be a Plant* passed here
        customerStaff->customise(nullptr, customisationDetails);
    } else {
        std::cerr << "Error: Staff member is not a CustomerStaff." << std::endl;
    }
}