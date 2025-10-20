#ifndef GROWING_H
#define GROWING_H
#include "PlantState.h"

class Growing : public PlantState {
public:
    ~Growing();

    std::string name() const;
    void onEnter();
    void update();
    void onExit();
};

#endif // GROWING_H
