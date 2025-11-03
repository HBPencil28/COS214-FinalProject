#ifndef STRING_H
#define STRING_H

#include <string>
#include <iostream>

#include "PlantDecorator.h"

class String : public PlantDecorator{
    public:
        String();
        ~String();
        void changeType(std::string newType);
    private:
        std::string type;
};

#endif