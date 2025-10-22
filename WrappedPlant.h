#ifndef WRAPPEDPLANT_H
#define WRAPPEDPLANT_H

#include "BasePlant.h"
#include <iostream>
#include <string>

class WrappedPlant : public BasePlant{
    public:
        WrappedPlant();
        ~WrappedPlant();
        void add(BasePlant *) {}
        void addPart(PlantComponent *plant);
        void addPlant(Plant* plant);

    private:
        std::string type;
        std::vector<PlantComponent *> parts;
        std::vector<Plant*> plants;
};

#endif