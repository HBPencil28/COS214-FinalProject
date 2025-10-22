#ifndef PLANTWRAP
#define PLANTWRAP

#include <string>
#include "PlantComponent.h"

class PlantWrap : public PlantComponent{
    public:
        PlantWrap();
        ~PlantWrap();
        void changeType(std::string type);

    private:
        std::string type;
};

#endif