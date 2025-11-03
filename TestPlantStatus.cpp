// // TestPlantStatus.cpp
// #include <iostream>
// #include <string>

// #include "Plant.h"
// #include "InStorage.h"
// #include "Sold.h"
// #include "Returned.h"

// static void printStatus(const Plant& p, const std::string& label) {
//     std::cout << label << " -> status: " << p.getStatus() << "\n";
// }

// int main() {
//     std::cout << "=== Testing PlantStatus state machine ===\n";

//     // create a real Plant (your ctor wants 2 strings)
//     Plant p("Rosemary", "Herb");

//     // IMPORTANT: your current Plant ctor in Plant.cpp
//     // does NOT set the status yet, so we must do it here:
//     p.setStatus(new InStorage());
//     printStatus(p, "[init]");

//     // 1) sell the plant: InStorage -> Sold
//     std::cout << "\n-- Selling the plant --\n";
//     p.sell();
//     printStatus(p, "[after sell]");

//     // 2) return the plant: Sold -> Returned -> (auto) InStorage
//     std::cout << "\n-- Returning the plant (reason: 'pot cracked') --\n";
//     p.returnPlant("pot cracked");
//     // Returned::enter(...) immediately did plant.setStatus(new InStorage());
//     printStatus(p, "[after return]");

//     // 3) show we kept the reason on the Plant
//     std::cout << "[debug] lastReturnReason = " << p.getLastReturnReason() << "\n";

//     std::cout << "\n=== Done ===\n";
//     return 0;
// }
