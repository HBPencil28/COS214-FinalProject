#ifndef BASEPLANT_H
#define BASEPLANT_H

#include "Plant.h"
#include "PlantDecorator.h"
#include "PlantComponent.h"
#include <string>
#include <vector>

class BasePlant{
    public:
        BasePlant();
        virtual ~BasePlant();

        virtual void add(BasePlant *) = 0;
        virtual void addPart(PlantComponent* plant) = 0;
};

#endif