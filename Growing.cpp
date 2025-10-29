#include "Growing.h"
#include "Mature.h"
#include "Withered.h"
#include "Plant.h"
#include <iostream>

std::string Growing::getStateName() const { return "Growing"; }

void Growing::onEnter(Plant* plant)
{
    std::cout << "[Growing] onEnter: " << plant->getName() << std::endl;
}

void Growing::onExit(Plant* plant)
{
    std::cout << "[Growing] onExit: " << plant->getName() << std::endl;
}

void Growing::dailyTick(Plant* plant)
{
    // Mature once age crosses 21 days and hydration is healthy
    if (plant->getAgeDays() >= 21 && plant->getHydrationLevel() >= 40)
    {
        plant->setState(new Mature());
        return;
    }

    // Severe neglect wither
    if (plant->getHydrationLevel() <= 5)
    {
        plant->setState(new Withered());
        return;
    }
}

void Growing::water(Plant* plant)
{
    std::cout << "[Growing] watered: " << plant->getName()
              << " (level=" << plant->getHydrationLevel() << ")\n";
}

void Growing::fertilize(Plant* /*plant*/)
{
    std::cout << "[Growing] fertilized (accelerates growth)\n";
}

void Growing::harvestAndStore(Plant* /*plant*/)
{
    std::cout << "[Growing] harvest ignored (not mature)\n";
}

void Growing::discard(Plant* plant)
{
    plant->setState(new Withered());
}
