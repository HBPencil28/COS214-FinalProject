#ifndef PLANT_H
#define PLANT_H
#include "Greenhouse.h"
#include <string>
#include <iostream>


class Plant : public Greenhouse{
    private:
        std::string type;
        std::string name;
        std::string stateName;
    public:
        virtual ~Plant();
        Plant(std::string,std::string,std::string);
        std::string getType() const override;
        std::string getName()const{return name;}; 
        std::string getStateName()const {
            return stateName;
        }
        void execute() override;
};

#endif