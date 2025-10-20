#ifndef PLANTITERATOR_H
#define PLANTITERATOR_H
#include "Inventory.h"
#include <vector>

class Plant;

class PlantIterator{
    private:
    int currentIndex;
    Inventory* Inventory;

    public:
    bool hasNext();
    Plant* next();
    Plant* current();
    Plant* removeCurr();
    Plant* first();
};

#endif