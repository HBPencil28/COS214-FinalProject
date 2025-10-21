#ifndef POTTEDPLANT_H
#define POTTEDPLANT_H

#include <iostream>

#include "BasePlant.h"

class PottedPlant : public BasePlant{
    public:
        PottedPlant(std::string type);
        ~PottedPlant();
    private:
};

#endif