#ifndef WITHERED_H
#define WITHERED_H

#include "PlantState.h"

class Withered : public PlantState {
    public:
        Withered();
        ~Withered();
        std::string getStateName() const ;

        void onEnter(Plant* plant);
        void onExit(Plant* plant);

        void dailyTick(Plant* plant);        // remains withered
        void water(Plant* plant);            // no effect
        void fertilize(Plant* plant);        // no effect
        void harvestAndStore(Plant* plant);  // no-op
        void discard(Plant* plant);          // already withered

};


#endif // WITHERED_H