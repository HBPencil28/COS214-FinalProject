#ifndef WITHERED_H
#define WITHERED_H

#include "PlantState.h"

class Withered : public PlantState {
public:
    void water(Plant* plant, int amount) override;        // usually no effect (policy)
    void fertilize(Plant* plant, int amount) override;    // no effect              
    std::string getStateName() const override;
};

#endif // WITHERED_H
