#ifndef PLANTSTATE_H
#define PLANTSTATE_H
// #include "PlantStatus.h"
#include <string>

class Plant; // forward declare avoid cirlular includes

class PlantState{
    public:
        virtual ~PlantState() = default;

        virtual void water(Plant* plant, int amount) = 0;
        virtual void fertilize(Plant* plant, int amount) = 0;
        /* the following function will get removed
        virtual void harvestAndStore(Plant* plant) = 0;
        virtual void discard(Plant* plant) = 0; 
        */

        //virtual void handleChange(Plant* c) =0; // saw this in the notes
        virtual std::string getStateName() const = 0;

};

#endif // PLANTSTATE_H