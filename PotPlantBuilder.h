#ifndef POTPLANTBUILDER_H
#define POTPLANTBUILDER_H

#include "PlantBuilder.h"

class PotPlantBuilder : public PlantBuilder{
    public:
        void addPot() override;
        void addSoil() override;
};

#endif