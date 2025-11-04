#include <iostream>
#include "Growing.h"
#include "Plant.h"
#include "Mature.h"
#include "Withered.h"

namespace {
    constexpr int GROWING_MIN_AGE_FOR_MATURE   = 8; // days
    constexpr int SEEDLING_MIN_HEIGHT_GROWING = 65; // %
}

void Growing::water(Plant* plant, int amount)
{
    (void)amount;
    if (!plant) return;

    const int age = plant->getAgeDays();
    const int h = plant->getHydrationLevel();

    if (age >= GROWING_MIN_AGE_FOR_MATURE && h >= SEEDLING_MIN_HEIGHT_GROWING) {
        std::cout << plant->getName() << ": this is well hydrated. Move to mature state"  << std::endl; 
        plant->setState(new Mature());
    } else {
        std::cout << plant->getName() << ": watered; still Growing (age="
                  << age << ", height=" << h << ").\n";
    }
}

void Growing::fertilize(Plant* plant, int amount)
{
    (void)amount;
    if (!plant) return;

    // Fertilizer supports the move to Mature if near thresholds.
    const int age = plant->getAgeDays();
    const int h = plant->getHydrationLevel();

    if (age >= GROWING_MIN_AGE_FOR_MATURE && h >= SEEDLING_MIN_HEIGHT_GROWING) {
        std::cout << plant->getName() << ": This plant been fertilized and ready to move to mature state " << std::endl;
        plant->setState(new Mature());
    } else {
        std::cout << plant->getName() << ": fertilized, but still growing " << std::endl;
    }
}

std::string Growing::getStateName() const {
    return "Growing";
}
