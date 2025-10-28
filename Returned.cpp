#include "Returned.h"
#include "InStorage.h"
#include "Plant.h"
#include <memory>
#include <iostream>

void Returned::enter(Plant& p) {
    std::cout << "[STATE] Plant marked as Returned. Logging reason and restocking...\n";
    p.auditStatusChange("Returned", "InStorage", reason_);

    // Automatically transition back to InStorage after logging
    p.changeStatus(std::make_unique<InStorage>());
}
