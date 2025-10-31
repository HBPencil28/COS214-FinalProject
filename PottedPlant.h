#ifndef POTTEDPLANT_H
#define POTTEDPLANT_H

#include <iostream>

#include "BasePlant.h"

class PottedPlant : public BasePlant{
    public:
        PottedPlant(Plant *plant);
        ~PottedPlant();
        void add(BasePlant *bp){(void)bp; throw std::logic_error("add not supported");}
        void addPart(PlantComponent *plant);

    private:
        Plant *plant;
};

#endif