#include "Returned.h"
#include "InStorage.h"
#include "Plant.h"

void Returned::enter(Plant& plant) {
    // here you could read plant.getLastReturnReason() and log it
    // then immediately make it available again:
    plant.setStatus(new InStorage());
}
