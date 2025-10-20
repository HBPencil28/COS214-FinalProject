#ifndef MATURE_H
#define MATURE_H
#include "PlantState.h"

class Mature : public PlantState {
public:
    ~Mature();

    std::string name() const ;
    void onEnter();
    void update();
    void onExit();
};

#endif // MATURE_H