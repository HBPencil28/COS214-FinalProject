#ifndef POTPLANTBUILDER_H
#define POTPLANTBUILDER_H

#include "PlantBuilder.h"

class WrapPlantBuilder : public PlantBuilder{
    public:
        WrapPlantBuilder(BasePlant *product);
        void addPot(){}
        void addSoil(){}
        void addWrap() override;
};

#endif