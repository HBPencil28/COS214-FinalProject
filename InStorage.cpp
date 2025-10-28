#include "InStorage.h"
#include "Sold.h"
#include "Plant.h"
#include <memory>

void InStorage::onSell(Plant& p) {
    p.changeStatus(std::make_unique<Sold>()); // legal: InStorage -> Sold
}
