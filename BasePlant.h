#ifndef BASEPLANT_H
#define BASEPLANT_H

#include "Plant.h"
#include <string>

class BasePlant : public Plant{
    public:
        BasePlant();
        virtual ~BasePlant();

        virtual void add(Plant*);
    protected:
        std::string type = std::to_string("base");
};

#endif