#ifndef WRAPPEDPLANT_H
#define WRAPPEDPLANT_H

#include "BasePlant.h"
#include <iostream>
#include <string>

class WrappedPlant : public BasePlant{
    public:
        WrappedPlant();
        ~WrappedPlant();
    private:
        std::string type;
};

#endif