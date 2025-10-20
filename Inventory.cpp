#include "Inventory.h"

Inventory::Inventory(){}

Inventory* Inventory::getInstance(){
    if(instance == nullptr){
        instance = new Inventory();
    }

    return instance;
}

//static variables must be initialise out of line
Inventory* Inventory::instance = nullptr;