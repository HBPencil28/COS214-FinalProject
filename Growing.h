#ifndef GROWING_H
#define GROWING_H

#include "PlantState.h"

class Growing : public PlantState {
public:
    
    void water(Plant* plant, int amount) override;        // stronger effect
    void fertilize(Plant* plant, int amount) override;    // growth boost
    std::string getStateName() const override;
};

#endif // GROWING_H
