#ifndef PLANTSOIL
#define PLANTSOIL

#include <string>
#include "PlantComponents.h"

class PlantSoil : public PlantComponent{
    public:
        PlantSoil();
        ~PlantSoil();
        void changeType(std::string type);

    private:
        std::string type;
};

#endif