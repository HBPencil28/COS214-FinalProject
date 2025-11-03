#ifndef RIBBON_H
#define RIBBON_H

#include <string>
#include <iostream>

#include "PlantDecorator.h"

class Ribbon : public PlantDecorator{
    public:
        Ribbon();
        ~Ribbon();
        void changeColour(std::string newColour);
    private:
        std::string colour;
};

#endif