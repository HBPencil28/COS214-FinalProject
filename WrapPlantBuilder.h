#ifndef POTPLANTBUILDER_H
#define POTPLANTBUILDER_H

#include "PlantBuilder.h"

class WrapPlantBuilder : public PlantBuilder{
    public:
        void addWrap() override;
};

#endif