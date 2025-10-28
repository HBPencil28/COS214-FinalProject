#include "BuyPlant.h"
#include "CustomerStaff.h"

void BuyPlant::execute() {
    // Notify the staff to handle the buy plant request
    static_cast<CustomerStaff*>(assistant)->getRequestedPlant(plantDetails);
}