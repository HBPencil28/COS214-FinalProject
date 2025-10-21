#include "DeliveryStaff.h"

void DeliveryStaff::changed() {
    // DeliveryStaff would add a mature plant to the inventory
    // inv->removePlant();
    // tell the mediator about the change, to notify other staff
    mediator->notify(this);
}

std::string DeliveryStaff::get() {
    // Return information about the plant they depleted from inventory
    // message would be: Out of Stock: [Plant details (from the harvest command)]
    return "Out of Stock: a mature plant.";
}

void DeliveryStaff::set(std::string message) {
    // Receive notification from the mediator
    std::cout << "DeliveryStaff received notification: " << message << std::endl;

    // Will halt operations if plant to deliver is out of stock (based on notification)
}