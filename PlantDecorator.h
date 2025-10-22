#ifndef PLANTDECORATOR_H
#define PLANTDECORATOR_H

#include <string>
#include <iostream>

#include "Plant.h"
#include "BasePlant.h"

class PlantDecorator : public BasePlant{
    public:
        PlantDecorator();
        
    protected:
        ~PlantDecorator();
        BasePlant* getDecoration();
            // Decorator
            void add(BasePlant *plantDecoration) override;

    private:
        BasePlant* decoration;
};

#endif