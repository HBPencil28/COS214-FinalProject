#include "InStorage.h"
#include "Sold.h"
#include "Plant.h"

void InStorage::onSell(Plant& plant) {
    // Move to Sold state
    plant.setStatus(new Sold());
}

void InStorage::enter(Plant& p){
    p.setLastReturnReason("");
}