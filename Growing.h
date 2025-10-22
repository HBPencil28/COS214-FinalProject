#ifndef GROWING_H
#define GROWING_H
#include "PlantState.h"

class Growing : public PlantState {
public:
    Growing() = default;
    ~Growing() = default;

     std::string getStateName() const override;

    void onEnter(Plant* plant) override;
    void onExit(Plant* plant) override;

    void dailyTick(Plant* plant) override;        // age up then maybe go to mature
    void water(Plant* plant) override;            // maintain hydration
    void fertilize(Plant* plant) override;        // accelerate growth
    void harvestAndStore(Plant* plant) override;  // not ready yet
    void discard(Plant* plant) override; 
};

#endif // GROWING_H
