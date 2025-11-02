#ifndef SEEDLING_H
#define SEEDLING_H
#include "PlantState.h"



class Seedling : public PlantState {
public:
    
    void water(Plant* plant, int amount) override;        // modest absorption
    void fertilize(Plant* plant, int amount) override;    // guarded boost  
    std::string getStateName() const override {return "Seedling";}
};


#endif // SEEDLING_H