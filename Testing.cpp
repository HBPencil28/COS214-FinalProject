// // TestMain.cpp
// #include <iostream>
// #include "Plant.h"
// #include "Seedling.h"
// #include "Growing.h"
// #include "Mature.h"
// #include "Withered.h"

// // Simple concrete plant just for testing
// class DemoPlant : public Plant {
// public:
//     DemoPlant(const std::string& name, const std::string& type)
//         : Plant(name, type) {}

//     // Plant* clone() override { return new DemoPlant(*this); }
// };

// int main() {
//     DemoPlant p("Rosemary", "Herb");

//     // Start as Seedling
//     p.initState(new Seedling());
//     std::cout << p.getName() << " initial state: " << p.getStateName() << "\n";

//     // Simulate 25 days; water every 3rd day
//     for (int day = 1; day <= 25; ++day) {
//         std::cout << "\n-- Day " << day << " --\n";
//         if (day % 3 == 0) {
//             std::cout << "Action: watering\n";
//             p.water();
//         }
//         p.dailyTick();
//         std::cout << "Now in state: " << p.getStateName()
//                   << " | ageDays=" << p.getAgeDays()
//                   << " | hydration=" << p.getHydrationLevel() << "\n";
//         if (p.getStateName() == "Mature" && day == 23) {
//             std::cout << "Action: harvest\n";
//             p.harvestAndStore();
//         }
//     }

//     // Force discard
//     std::cout << "\nAction: discard" << std::endl;
//     p.discard();
//     std::cout << "Final state: " << p.getStateName() << "\n";
//     return 0;
// }
