#ifndef PLANT_H
#define PLANT_H
#include "Greenhouse.h"
#include <string>
#include <iostream>


class Plant : public Greenhouse{
    private:
        std::string type;
    public:
        virtual ~Plant();
        Plant(std::string);
        std::string getType() const;
        void execute() override;
};

#endif