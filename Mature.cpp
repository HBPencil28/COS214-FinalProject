#include "Mature.h"
#include "Withered.h"
#include "Plant.h"
#include <iostream>

std::string Mature::getStateName() const { return "Mature"; }

void Mature::onEnter(Plant* plant)
{
    std::cout << "[Mature] onEnter: " << plant->getName() << " (ready for harvest)\n";
}

void Mature::onExit(Plant* plant)
{
    std::cout << "[Mature] onExit: " << plant->getName() << "\n";
}

void Mature::dailyTick(Plant* plant)
{
    // If neglected for too long at maturity, wither.
    if (plant->getHydrationLevel() <= 5)
    {
        plant->setState(new Withered());
        return;
    }
}

void Mature::water(Plant* plant)
{
    std::cout << "[Mature] watered: " << plant->getName()
              << " (level=" << plant->getHydrationLevel() << ")\n";
}

void Mature::fertilize(Plant* /*plant*/)
{
    std::cout << "[Mature] fertilized (minor effect)\n";
}

void Mature::harvestAndStore(Plant* plant)
{
    // This is where you’d hand off to PlantStatus (logistics) in your app layer.
    std::cout << "[Mature] harvest & store triggered for " << plant->getName() << "\n";
    // (state may remain Mature; or you might create a post-harvest state if needed)
}

void Mature::discard(Plant* plant)
{
    plant->setState(new Withered());
}
