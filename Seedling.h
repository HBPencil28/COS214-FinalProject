#ifndef SEEDLING_H
#define SEEDLING_H
#include "PlantState.h"

class Seedling : public PlantState {
public:
    Seedling() = default;
    ~Seedling() = default;

    std::string getStateName() const ;

    void onEnter(Plant* plant);
    void onExit(Plant* plant);

    void dailyTick(Plant* plant);        // age up then maybe go to Growing
    void water(Plant* plant);            // increase hydration
    void fertilize(Plant* plant);        // early nutrient boost
    void harvestAndStore(Plant* plant);  // no-op
    void discard(Plant* plant);  // wither away 

};


#endif // SEEDLING_H