#ifndef BASEPLANT_H
#define BASEPLANT_H

#include "Plant.h"
#include "PlantComponent.h"
#include <string>
#include <vector>

class BasePlant{
    public:
        BasePlant(std::string type);
        virtual ~BasePlant();

        virtual void add(BasePlant *bp) = 0;
        virtual void addPart(PlantComponent* plant) = 0;
    protected:
        std::string type;
        std::vector<PlantComponent *> parts;
};

#endif