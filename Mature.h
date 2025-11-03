#ifndef MATURE_H
#define MATURE_H

#include "PlantState.h"

class Mature : public PlantState {
public:
    void water(Plant* plant, int amount) override;        // maintenance
    void fertilize(Plant* plant, int amount) override;    // maintenance/quality
    std::string getStateName() const override;
};

#endif // MATURE_H
