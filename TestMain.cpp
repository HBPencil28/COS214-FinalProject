#include "Plant.h"
#include "Seedling.h"
#include <iostream>

int main() {
    Plant p("Rosemary", "Herb");
    p.initState(new Seedling());

    for (int i = 0; i < 7; ++i) {
        p.dailyTick();
    }

    std::cout << "State before water: " << p.getStateName() << "\n";
    p.water(80);
    std::cout << "State after water:  " << p.getStateName() << "\n";

    return 0;
}
