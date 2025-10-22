#ifndef PLANTWRAP
#define PLANTWRAP

#include <string>
#include "PlantComponents.h"

class PlantWrap : public PlantComponent{
    public:
        PlantWrap();
        ~PlantWrap();
        void changeType(std::string type);

    private:
        std::string type;
};

#endif