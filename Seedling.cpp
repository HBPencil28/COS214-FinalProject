#include "Seedling.h"
#include "Growing.h"
#include "Withered.h"
#include "Plant.h"
#include <iostream>

std::string Seedling::getStateName() const { return "Seedling"; }

void Seedling::onEnter(Plant* plant)
{
    std::cout << "[Seedling] onEnter: " << plant->getName() << "\n";
}

void Seedling::onExit(Plant* plant)
{
    std::cout << "[Seedling] onExit: " << plant->getName() << "\n";
}

void Seedling::dailyTick(Plant* plant)
{
    // Example rule-of-thumb: after 7 days and decent hydration, start Growing
    if (plant->getAgeDays() >= 7 && plant->getHydrationLevel() >= 40)
    {
        plant->setState(new Growing());
        return;
    }

    // Neglect rule-of-thumb: if hydration very low for a while, wither
    if (plant->getHydrationLevel() <= 10 && plant->getAgeDays() > 3)
    {
        plant->setState(new Withered());
        return;
    }
}

void Seedling::water(Plant* plant)
{
    // We can’t change hydration directly (no setter), so just log for now.
    std::cout << "[Seedling] watered: " << plant->getName()
              << " (level=" << plant->getHydrationLevel() << ")\n";
}

void Seedling::fertilize(Plant* plant)
{
    std::cout << "[Seedling] fertilized (mild effect)\n";
}

void Seedling::harvestAndStore(Plant* /*plant*/)
{
    std::cout << "[Seedling] harvest ignored (too early)\n";
}

void Seedling::discard(Plant* plant)
{
    plant->setState(new Withered());
}
