#ifndef PLANT_H
#define PLANT_H

#include <iostream>

class Plant{
    public:
        Plant();
        virtual ~Plant();
        // Prototype
        virtual Plant* clone() = 0;

        // Decorator
        virtual void add(Plant*) = 0;
    private:
};

#endif