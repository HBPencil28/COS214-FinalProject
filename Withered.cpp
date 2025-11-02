#include <iostream>
#include "Withered.h"
#include "Plant.h"

void Withered::water(Plant* plant, int amount)
{
    (void)amount;
    if (!plant) return;
    std::cout << plant->getName() << ": watering as no effect on a withered plant " << std::endl;
}

void Withered::fertilize(Plant* plant, int amount)
{
    (void)amount;
    if (!plant) return;
    std::cout <<  plant->getName() << ": fertilizing has no on a withered plant " << std::endl;
}

std::string Withered::getStateName() const {
    return "Withered";
}
