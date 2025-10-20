#ifndef PLANT_H
#define PLANT_H
#include "Greenhouse.h"
#include <string>
#include <iostream>


class Plant : public Greenhouse{
    private:
        std::string type;
    public:
        Plant();
        std::string getType();
        void execute() override;
};

#endif