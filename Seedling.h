#ifndef SEEDLING_H
#define SEEDLING_H
#include "PlantState.h"

class Seedling : public PlantState {
public:
    ~Seedling();

    std::string name() const ;
    void onEnter() ;
    void update() ;
    void onExit() ;
};


#endif // SEEDLING_H