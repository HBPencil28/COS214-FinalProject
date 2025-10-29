#include <iostream>
#include "Seedling.h"
#include "Plant.h"
#include "Growing.h"
#include "Withered.h"

namespace {
    // Nursery policy thresholds. We will have to tweak this along the way but this is just to get it running 
    constexpr int SEEDLING_MIN_AGE_FOR_GROWING   = 7;   // days
    constexpr int SEEDLING_MIN_HYDRATION_GROWING = 60;  // %
    // adding these conditions for growing 
}

void Seedling::water(Plant* plant, int amount)
{
    // Hydration was already incremented by Plant::water(amount).
    // transitions are based off of conditions
    if (!plant) return;

    const int age = plant->getAgeDays();
    const int h2o = plant->getHydrationLevel();

    if (age >= SEEDLING_MIN_AGE_FOR_GROWING && h2o >= SEEDLING_MIN_HYDRATION_GROWING) {
        std::cout <<  plant->getName() << ": conditions met. Go to Growing." << std::endl;
        plant->setState(new Growing());
    } else {
        std::cout << plant->getName() << ": watered; still a Seedling (age=" 
                  << age << ", hydration=" << h2o << ").\n";
    }
}

void Seedling::fertilize(Plant* plant, int amount)
{
    if (!plant) return;

    // because seedlings are delicate we will fertilize and use it as a checkpoint
    const int age = plant->getAgeDays();
    const int h2o = plant->getHydrationLevel();

    if (age >= SEEDLING_MIN_AGE_FOR_GROWING && h2o >= SEEDLING_MIN_HYDRATION_GROWING) {
        std::cout << plant->getName() << ": fertilize completed. Go to growing state." << std::endl;
        plant->setState(new Growing());
    } else {
        std::cout <<  plant->getName() << ": Lightly fertilized, conditions not met so it remains a Seedling " << std::endl;
    }
}

void Seedling::harvestAndStore(Plant* plant)
{
    if (!plant) return;
    std::cout << plant->getName() << ": Note that you cannot harvest a Seedling." << std::endl;;
}

void Seedling::discard(Plant* plant)
{
    if (!plant) return;
    std::cout << plant->getName() << ": this plant has been discarded and goes to witherd state " << std::endl;
    plant->setState(new Withered());
}
