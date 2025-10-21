#include "CustomerStaff.h"

void CustomerStaff::changed() {
    // CustomerStaff would add a mature plant to the inventory
    // inv->removePlant();
    // tell the mediator about the change, to notify other staff
    mediator->notify(this);
}

std::string CustomerStaff::get() {
    // Return information about the plant they depleted from inventory
    // message would be: Out of Stock: [Plant details (from the harvest command)]
    return "Out of Stock: a mature plant.";
}

void CustomerStaff::set(std::string message) {
    // Receive notification from the mediator
    std::cout << "CustomerStaff received notification: " << message << std::endl;

    // Will not sell plant if out of stock
}