#ifndef POTTEDPLANT_H
#define POTTEDPLANT_H

#include <iostream>

#include "BasePlant.h"

class PottedPlant : public BasePlant{
    public:
        PottedPlant(Plant *plant);
        ~PottedPlant();
        void add(BasePlant *){}
        void addPart(PlantComponent *plant);

    private:
        std::string type;
        std::vector<PlantComponent *> parts;
        Plant *plant;
};

#endif