#include "Withered.h"
#include "Plant.h"
#include <iostream>

std::string Withered::getStateName() const { return "Withered"; }

void Withered::onEnter(Plant* plant)
{
    std::cout << "[Withered] onEnter: " << plant->getName() << " (dead/removed)\n";
}

void Withered::onExit(Plant* plant)
{
    std::cout << "[Withered] onExit: " << plant->getName() << std::endl;
}

void Withered::dailyTick(Plant* /*plant*/) {}

void Withered::water(Plant* /*plant*/)
{
    std::cout << "[Withered] water has no effect (by default)" << std::endl;
    // If you want revival, you could transition to new Seedling/Growing here.
}

void Withered::fertilize(Plant* /*plant*/)
{
    std::cout << "[Withered] fertilizer has no effect" << std::endl;
}

void Withered::harvestAndStore(Plant* /*plant*/)
{
    std::cout << "[Withered] harvest ignored " << std::endl;
}

void Withered::discard(Plant* /*plant*/)
{
    std::cout << "[Withered] already discarded" << std::endl;
}
