#include "Staff.h"
#include "NurseryMediator.h"
#include "Inventory.h"

Staff::Staff(){
    mediator = nullptr;
    inv = Inventory::getInstance();
}

void Staff::registerMediator(NurseryMediator* med){
    mediator = med;
}

void Staff::deregisterMediator(){
    mediator = nullptr;
}

