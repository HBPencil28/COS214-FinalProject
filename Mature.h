#ifndef MATURE_H
#define MATURE_H

#include "PlantState.h"

class Mature : public PlantState {
public:
    void water(Plant* plant, int amount) override;        // maintenance
    void fertilize(Plant* plant, int amount) override;    // maintenance/quality
    void harvestAndStore(Plant* plant) override;          // trigger logistics; may -> Withered
    void discard(Plant* plant) override;                  // -> Withered
    // void handleChange(Plant* c) override;                 // if neglected -> Withered
    std::string getStateName() const override {return "Mature";}
};

#endif // MATURE_H
