#include "PlantIterator.h"
#include "Plant.h"

Plant* PlantIterator::first() {
    currentIndex = 0;
    return current();
}

Plant* PlantIterator::current() {
    if (currentIndex < Inventory->getInstance()->getPlants().size()) {
        return Inventory->getInstance()->getPlants()[currentIndex];
    }
    return nullptr;
}

bool PlantIterator::hasNext() {
    return currentIndex < Inventory->getInstance()->getPlants().size() - 1;
}

Plant* PlantIterator::next() {
    if (hasNext()) {
        currentIndex++;
        return current();
    }
    return nullptr;
}

Plant* PlantIterator::removeCurr() {
    if (currentIndex >= 0 && currentIndex < Inventory->getInstance()->getPlants().size()) {
        Plant* temp = current();
        Inventory->getInstance()->removePlant(temp);
        return temp;
    }
    return nullptr;
}