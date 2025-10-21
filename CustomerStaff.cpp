#include "CustomerStaff.h"

void CustomerStaff::changed() {
    // CustomerStaff would add a mature plant to the inventory
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

void CustomerStaff::advise(std::string issue) {
    // depending on the issue, give advice
    if (issue.compare("Plant dries out quickly") == 0){
        std::cout << "CustomerStaff advises: Ensure proper watering and humidity levels." << std::endl;    
    }
    else{
        return;
    }
}

void CustomerStaff::getRequestedPlant(std::string plantDetails) {
    // process the request to buy a plant
    std::cout << "CustomerStaff is processing the purchase of: " << plantDetails << std::endl;
    // inv->removePlant();
    // After processing, update inventory
    changed();
}

// void CustomerStaff::customise(Plant* plant, std::string accessory) {
//     // customise the plant with the given accessory
//     if(accessory.compare("Pot") == 0)
//         plant->addAccessory();
//     else if(accessory.compare("Decorative Stones") == 0)
//         plant->addAccessory();
//     else if(accessory.compare("Fertilizer") == 0)
//         plant->addAccessory();
//     std::cout << "CustomerStaff customised the plant with: " << accessory << std::endl;
// }