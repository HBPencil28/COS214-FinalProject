#ifndef WITHERED_H
#define WITHERED_H

#include "PlantState.h"

class Withered : public PlantState {
    public:
        Withered() = default;
        ~Withered() override = default;
        std::string getStateName() const ;

        void onEnter(Plant* plant)override;
        void onExit(Plant* plant)override;

        void dailyTick(Plant* plant)override;        // remains withered
        void water(Plant* plant)override;            // no effect
        void fertilize(Plant* plant)override;        // no effect
        void harvestAndStore(Plant* plant)override;  // no-op
        void discard(Plant* plant)override;          // already withered

};


#endif // WITHERED_H