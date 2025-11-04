#include <iostream>
#include "Mature.h"
#include "Plant.h"
#include "Withered.h"

namespace {
    // Optional: thresholds for decline if poorly maintained; used in fertilize/water decisions.
    constexpr int MATURE_MIN_HYDRATION_OK = 16; // %
}

void Mature::water(Plant* plant, int amount)
{
    (void)amount;
    if (!plant) return;

    // Mature plants mostly maintain; no automatic transition on watering alone.
    std::cout << plant->getName() << ": watered; remains Mature (hydration=" << plant->getHydrationLevel() << ").\n";
}

void Mature::fertilize(Plant* plant, int amount)
{
    (void)amount;
    if (!plant) return;

    // Keep it simple: if hydration is very low, warn, but remain Mature.
    if (plant->getHydrationLevel() < MATURE_MIN_HYDRATION_OK) {
        std::cout << "Warning "<< plant->getName() << ": fertilized but hydration is low; consider watering.\n";
    } else {
        std::cout << plant->getName() << ": has been fertilized stays in mature state." << std::endl;
    }
}

std::string Mature::getStateName() const{
    return "Mature";
}
