#ifndef PLANTPOT
#define PLANTPOT

#include <string>
#include "PlantComponent.h"

class PlantPot: public PlantComponent{
    public:
        PlantPot();
        ~PlantPot();
        void changeType(std::string type);
    private:
        std::string type;
};

#endif