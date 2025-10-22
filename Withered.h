#ifndef WILTED_H
#define WILTED_H

#include "PlantState.h"

class Wilted : public PlantState {
    public:
        ~Wilted() override;
        std::string name() const override;
        void onEnter() override;
        void update() override;
        void onExit() override;

};


#endif // WILTED_H