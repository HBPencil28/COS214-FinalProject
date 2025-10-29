#include <iostream>
#include "Withered.h"
#include "Plant.h"

void Withered::water(Plant* plant, int amount)
{
    if (!plant) return;
    std::cout << plant->getName() << ": watering as no effect on a withered plant " << std::endl;
}

void Withered::fertilize(Plant* plant, int amount)
{
    if (!plant) return;
    std::cout <<  plant->getName() << ": fertilizing has no on a withered plant " << std::endl;
}

void Withered::harvestAndStore(Plant* plant)
{
    if (!plant) return;
    std::cout <<  plant->getName() << ": cannot harvest a withered plant " << std::endl;
}

void Withered::discard(Plant* plant)
{
    if (!plant) return;
    std::cout <<  plant->getName() << ": in withered state and has been discarded " << std::endl;
}
