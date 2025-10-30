#ifndef WRAPPEDPLANT_H
#define WRAPPEDPLANT_H

#include "BasePlant.h"
#include <iostream>
#include <string>

class WrappedPlant : public BasePlant{
    public:
        WrappedPlant();
        ~WrappedPlant();
        void add(BasePlant *bp) {}
        void addPart(PlantComponent *plant);
        void addPlant(Plant* plant);

    private:
        std::vector<Plant*> plants;
};

#endif