#include <iostream>
#include "Seedling.h"
#include "Plant.h"
#include "Growing.h"
#include "Withered.h"

namespace {
    // Nursery policy thresholds. We will have to tweak this along the way but this is just to get it running 
    constexpr int SEEDLING_MIN_AGE_FOR_GROWING   = 2;   // days
    constexpr int SEEDLING_MIN_HEIGHT_GROWING = 30;  // %
    // adding these conditions for growing 
}

void Seedling::water(Plant* plant, int amount)
{
    (void)amount;
    // Hydration was already incremented by Plant::water(amount).
    // transitions are based off of conditions
    if (!plant) return;

    const int age = plant->getAgeDays();
    const int h = plant->getHeight();

    if (age >= SEEDLING_MIN_AGE_FOR_GROWING && h >= SEEDLING_MIN_HEIGHT_GROWING) {
        std::cout <<  plant->getName() << ": conditions met. Go to Growing." << std::endl;
        plant->setState(new Growing());
    } else {
        std::cout << plant->getName() << ": watered; still a Seedling (age=" 
                  << age << ", height=" << h << ").\n";
    }
}

void Seedling::fertilize(Plant* plant, int amount)
{
    (void)amount;
    if (!plant) return;

    // because seedlings are delicate we will fertilize and use it as a checkpoint
    const int age = plant->getAgeDays();
    const int h = plant->getHydrationLevel();

    if (age >= SEEDLING_MIN_AGE_FOR_GROWING && h >= SEEDLING_MIN_HEIGHT_GROWING) {
        std::cout << plant->getName() << ": fertilize completed. Go to growing state." << std::endl;
        plant->setState(new Growing());
    } else {
        std::cout <<  plant->getName() << ": Lightly fertilized, conditions not met so it remains a Seedling " << std::endl;
    }
}
