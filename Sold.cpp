#include "Sold.h"
#include "Returned.h"
#include "Plant.h"

void Sold::onReturn(Plant& plant, const std::string& reason) {
    // keep the reason ON THE PLANT
    plant.setLastReturnReason(reason);

    // move to Returned
    plant.setStatus(new Returned());
}
