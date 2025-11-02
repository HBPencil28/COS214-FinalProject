#ifndef PLANTBUILDER_H
#define PLANTBUILDER_H

#include <vector>
#include <iostream>

#include "Plant.h"
#include "PlantDecorator.h"
#include "PlantComponent.h"
#include "PlantPot.h"
#include "PlantSoil.h"
#include "PlantWrap.h"

class PlantBuilder{
    public:
        PlantBuilder(BasePlant *product);
        virtual ~PlantBuilder(){}
        virtual void addPot() = 0;
        virtual void addSoil() = 0;
        virtual void addWrap() = 0;
        BasePlant* getProduct();
    protected:
        BasePlant* product;
};

#endif