#ifndef WITHERED_H
#define WITHERED_H

#include "PlantState.h"

class Withered : public PlantState {
public:
    void water(Plant* plant, int amount) override;        // usually no effect (policy)
    void fertilize(Plant* plant, int amount) override;    // no effect
    void harvestAndStore(Plant* plant) override;          // no-op
    void discard(Plant* plant) override;
    // void handleChange(Plant* c) override;                 // typically remains Withered
    std::string getStateName() const override {return "Withered";}
};

#endif // WITHERED_H
