#include "PlantIterator.h"
#include "Plant.h"

PlantIterator::PlantIterator(std::vector<Plant*>* container)
    : currentIndex(-1), plants(container) { }

bool PlantIterator::hasNext() const {
    if (!plants) return false;
    return (currentIndex + 1) < static_cast<int>(plants->size());// prevent Werrors
}

Plant* PlantIterator::next() {
    if (!plants) return nullptr;
    if (hasNext()) {
        ++currentIndex;
        return (*plants)[currentIndex];
    }
    return nullptr;
}

Plant* PlantIterator::current() const {
    if (!plants) return nullptr;
    if (currentIndex >= 0 && currentIndex < static_cast<int>(plants->size()))
        return (*plants)[currentIndex];
    return nullptr;
}

Plant* PlantIterator::removeCurr() {
    if (!plants) return nullptr;
    if (currentIndex < 0 || currentIndex >= static_cast<int>(plants->size()))
        return nullptr;
    Plant* removed = (*plants)[currentIndex];
    plants->erase(plants->begin() + currentIndex);
    // step back so that next() advances to the element that shifted into this index
    --currentIndex;
    return removed;
}

Plant* PlantIterator::first() {
    if (!plants || plants->empty()) {
        currentIndex = -1;
        return nullptr;
    }
    currentIndex = 0;
    return (*plants)[0];
}