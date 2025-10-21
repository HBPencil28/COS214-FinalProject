#include "CareStaff.h"

void CareStaff::update(/*PlantState* state*/) {
    // Implementation for updating based on plant state changes
}

void CareStaff::changed() {
    // CareStaff would add a mature plant to the inventory
    // inv->addPlant();
    // tell the mediator about the change, to notify other staff
    mediator->notify(this);
}

std::string CareStaff::get() {
    // Return information about the plant they restocked
    // message would be: Restocked: [Plant details (from the harvest command)]
    return "Restocked: a mature plant.";
}

void CareStaff::set(std::string message) {
    // Receive notification from the mediator
    std::cout << "CareStaff received notification: " << message << std::endl;

    // Will possibly attempt to restock more plants based on the notification
}

