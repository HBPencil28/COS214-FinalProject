#ifndef PLANTDECORATOR_H
#define PLANTDECORATOR_H

#include <string>
#include <iostream>

#include "Plant.h"

class PlantDecorator : public Plant{
    public:
        PlantDecorator();
        
    protected:
        ~PlantDecorator();

        // Decorator
        void add(Plant* plantDecoration) override;
    private:
        Plant* decoration;
};

#endif