#ifndef WRAPPLANTBUILDER_H
#define WRAPPLANTBUILDER_H

#include "PlantBuilder.h"
#include "WrappedPlant.h"

class WrapPlantBuilder : public PlantBuilder{
    public:
        WrapPlantBuilder();
        void addPot(){}
        void addSoil(){}
        void addWrap() override;
};

#endif