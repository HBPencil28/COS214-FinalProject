#ifndef POTPLANTBUILDER_H
#define POTPLANTBUILDER_H

#include "PlantBuilder.h"
// #include "BasePlant.h"

class PotPlantBuilder : public PlantBuilder{
    public:
        PotPlantBuilder(BasePlant *product);
        void addPot() override;
        void addSoil() override;
        void addWrap(){}
};

#endif