#include <iostream>
#include "Mature.h"
#include "Plant.h"
#include "Withered.h"

namespace {
    // Optional: thresholds for decline if poorly maintained; used in fertilize/water decisions.
    constexpr int MATURE_MIN_HYDRATION_OK = 40; // %
}

void Mature::water(Plant* plant, int amount)
{
    if (!plant) return;

    // Mature plants mostly maintain; no automatic transition on watering alone.
    std::cout << plant->getName() << ": watered; remains Mature (hydration=" << plant->getHydrationLevel() << ").\n";
}

void Mature::fertilize(Plant* plant, int amount)
{
    if (!plant) return;

    // Keep it simple: if hydration is very low, warn, but remain Mature.
    if (plant->getHydrationLevel() < MATURE_MIN_HYDRATION_OK) {
        std::cout << "Warning "<< plant->getName() << ": fertilized but hydration is low; consider watering.\n";
    } else {
        std::cout << plant->getName() << ": has been fertilized stays in mature state." << std::endl;
    }
}

void Mature::harvestAndStore(Plant* plant)
{
    if (!plant) return;

    // Harvesting a Mature plant: simulate logistics, then mark as Withered (post-harvest).
    std::cout << plant->getName() << ": harvested and sent to storage";

    // question on this one. move from harvest 
}

void Mature::discard(Plant* plant)
{
    if (!plant) return;
    std::cout << plant->getName() << ": plant has been discarded and goes to withered state " << std::endl;
    plant->setState(new Withered());
}
