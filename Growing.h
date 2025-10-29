#ifndef GROWING_H
#define GROWING_H

#include "PlantState.h"

class Growing : public PlantState {
public:
    
    void water(Plant* plant, int amount) override;        // stronger effect
    void fertilize(Plant* plant, int amount) override;    // growth boost
    void harvestAndStore(Plant* plant) override;          // not yet (no-op)
    void discard(Plant* plant) override;                  // -> Withered
    // void handleChange(Plant* c) override;                 // if thresholds met -> Mature
    std::string getStateName() const override {return "Growing";}
};

#endif // GROWING_H
