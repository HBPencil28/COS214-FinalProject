#ifndef PLANTDECORATOR_H
#define PLANTDECORATOR_H

#include <string>
#include <iostream>
#include "BasePlant.h"

class PlantComponent;

class PlantDecorator : public BasePlant{
    public:
        PlantDecorator();
        ~PlantDecorator();
        BasePlant *getDecoration();
        // Decorator
        void add(BasePlant *plantDecoration) override;
        void addPart(PlantComponent *plant) override;

    private:
        BasePlant* decoration;
};

#endif