#ifndef MATURE_H
#define MATURE_H
#include "PlantState.h"

class Mature : public PlantState {
public:
    Mature() = default;
    ~Mature() = default;

    std::string getStateName() const override;

    void onEnter(Plant* plant) override;
    void onExit(Plant* plant) override;

    void dailyTick(Plant* plant) override;        // monitor decline → Withered
    void water(Plant* plant) override;            // sustain maturity
    void fertilize(Plant* plant) override;        // optional maintenance
    void harvestAndStore(Plant* plant) override;  // trigger logistics path
    void discard(Plant* plant) override;          // → Withered

};

#endif // MATURE_H