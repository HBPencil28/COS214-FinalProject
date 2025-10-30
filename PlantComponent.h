#ifndef PLANTCOMPONENT_H
#define PLANTCOMPONENT_H

#include <string>

class PlantComponent{
    public:
        PlantComponent(std::string name);
        ~PlantComponent();
        std::string getName();
        std::string getType();
        void changeType(std::string type);
    protected:
        std::string type;
    private:
        std::string name;
};

#endif