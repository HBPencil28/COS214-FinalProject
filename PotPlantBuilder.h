#ifndef POTPLANTBUILDER_H
#define POTPLANTBUILDER_H

#include "PlantBuilder.h"
#include "PottedPlant.h"
// #include "BasePlant.h"

class PotPlantBuilder : public PlantBuilder{
    public:
        PotPlantBuilder(Plant *plant);
        void addPot() override;
        void addSoil() override;
        void addWrap(){}
};

#endif