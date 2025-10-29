#ifndef PLANTSTATE_H
#define PLANTSTATE_H
#include "PlantStatus.h"

class Plant; // forward declare avoid cirlular includes

class PlantState {
public:
    virtual ~PlantState() = default;

    virtual std::string getStateName() const = 0;   // e.g., "Seedling", "Growing"
    virtual void onEnter(Plant* plant) = 0;
    virtual void onExit(Plant* plant) = 0;

    // Time/event-driven behavior the Plant forwards
    virtual void dailyTick(Plant* plant) = 0;
    virtual void water(Plant* plant) = 0;
    virtual void fertilize(Plant* plant) = 0;
    virtual void harvestAndStore(Plant* plant) = 0;
    virtual void discard(Plant* plant) = 0;
    

protected:
    PlantState() = default;

};


#endif // PLANTSTATE_H