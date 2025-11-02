#ifndef BOW_H
#define BOW_H

#include <string>
#include <iostream>

#include "PlantDecorator.h"

class Bow : public PlantDecorator{
    public:
        Bow();
        ~Bow();
        void changeStyle(std::string newStyle);

    private:
        std::string style;
};

#endif