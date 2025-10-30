#ifndef BUILDPLANTDIRECTOR_H
#define BUILDPLANTDIRECTOR_H

#include <vector>
#include <iostream>

#include "Plant.h"
#include "PlantDecorator.h"
#include "PlantBuilder.h"
#include "BasePlant.h"

class BuildPlantDirector{
    public:
        BuildPlantDirector();
        virtual ~BuildPlantDirector(){}
        void construct(bool b);
        void setBuilder(PlantBuilder* builder);
        PlantBuilder* getBuilder();
        // void setOrder();
    private:
        PlantBuilder* builder;
        // std::vector<Plant*> order; // Struct?
};


#endif