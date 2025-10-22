#ifndef PLANTCOMPONENT_H
#define PLANTCOMPONENT_H

#include <string>

class PlantComponent{
    public:
        PlantComponent(std::string name);
        ~PlantComponent();
    private:
        std::string name;
};

#endif