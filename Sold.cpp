#include "Sold.h"
#include "Returned.h"
#include "Plant.h"
#include <memory>
#include <iostream>

void Sold::onReturn(Plant& p, const std::string& reason) {
    std::cout << "[STATE] Transitioning from Sold to Returned. Reason: " << reason << "\n";
    p.changeStatus(std::make_unique<Returned>(reason));
}
