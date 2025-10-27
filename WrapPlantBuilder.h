#ifndef POTPLANTBUILDER_H
#define POTPLANTBUILDER_H

#include "PlantBuilder.h"

class WrapPlantBuilder : public PlantBuilder{
    public:
        WrapPlantBuilder(BasePlant *product);
        void addWrap() override;
};

#endif