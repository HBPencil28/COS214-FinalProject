// #include <iostream>
// #include <string>
// #include <vector>
// #include <map>
// #include <SFML/System

// #include "Plant.h"
// #include "Greenhouse.h"
// #include "Inventory.h"
// #include "Zone.h"
// #include "CareStrategy.h"
// #include "LowCare.h"
// #include "MediumCare.h"
// #include "HighCare.h"
// #include "BasePlant.h"
// #include "Bow.h"
// #include "BuildPlantDirector.h"
// #include "BuyPlant.h"
// #include "CareCommand.h"
// #include "CareFactory.h"
// #include "CareStaff.h"
// #include "CareStrategy.h"
// #include "CustomerCommand.h"
// #include "CustomerFactory.h"
// #include "CustomerStaff.h"
// #include "CustomisePlant.h"
// #include "FertilisePlant.h"
// #include "Greenhouse.h"
// #include "Growing.h"
// #include "InStorage.h"
// #include "Manager.h"
// #include "Mature.h"
// // #include "NormalStaff.h"
// #include "NurseryMediator.h"
// #include "order.h"
// // #include "OutForDelivery.h"
// #include "PlantBuilder.h"
// #include "PlantComponent.h"
// #include "PlantDecorator.h"
// #include "PlantIterator.h"
// #include "PlantObserver.h"
// #include "PlantPot.h"
// #include "PlantSoil.h"
// #include "PlantState.h"
// #include "PlantStatus.h"
// #include "PlantWrap.h"
// #include "PotPlantBuilder.h"
// #include "PottedPlant.h"
// #include "RequestHelp.h"
// #include "Returned.h"
// #include "Ribbon.h"
// #include "Seedling.h"
// #include "SeniorManager.h"
// #include "Sold.h"
// #include "Staff.h"
// #include "StaffFactory.h"
// #include "String.h"
// #include "WaterPlant.h"
// #include "Withered.h"
// #include "WrappedPlant.h"
// #include "WrapPlantBuilder.h"

// int main() {
//     std::cout << "===== SUBSYSTEM 1: GREENHOUSE/GARDEN AREA TESTING =====\n\n";
//     // Setup
//     CareStaff careStaff;
//     std::vector<Zone*> zones;
//     zones.push_back(new Zone("Rose","Flowers",&careStaff));
//     zones.push_back(new Zone("Daisy","Flowers",&careStaff));
//     zones.push_back(new Zone("Tulip","Flowers",&careStaff));
//     zones.push_back(new Zone("Succulent","Succulents&Cactuses",&careStaff));
//     zones.push_back(new Zone("Cactus","Succulents&Cactuses",&careStaff));
//     zones.push_back(new Zone("Basil","Herbs&Aromatics",&careStaff));
//     zones.push_back(new Zone("Mint","Herbs&Aromatics",&careStaff));
//     zones.push_back(new Zone("Parsley","Herbs&Aromatics",&careStaff));
//     zones.push_back(new Zone("Coriander","Herbs&Aromatics",&careStaff));
//     zones.push_back(new Zone("Lavender","Herbs&Aromatics",&careStaff));
//     zones.push_back(new Zone("Rosemary","Herbs&Aromatics",&careStaff));
//     zones.push_back(new Zone("LemonBalm","Herbs&Aromatics",&careStaff));
//     zones.push_back(new Zone("Hibiscus","Trees&Shrubs",&careStaff));
//     zones.push_back(new Zone("Hydrangea","Trees&Shrubs",&careStaff));
//     zones.push_back(new Zone("Boxwood","Trees&Shrubs",&careStaff));
//     zones.push_back(new Zone("Oak","Trees&Shrubs",&careStaff));
//     zones.push_back(new Zone("Baobab","Trees&Shrubs",&careStaff));

//     // Planting the Seeds
//     for(Zone* zone:zones){
//         // Attach observer
//         zone->attach(&careStaff);

//         // Plant seeds
//         zone->add(new Plant(zone->getZoneName(), zone->getZoneCategory()));
//         zone->add(new Plant(*static_cast<Plant*>(zone->getChild(0))));
//         zone->add(new Plant(*static_cast<Plant*>(zone->getChild(0))));
//         zone->add(new Plant(*static_cast<Plant*>(zone->getChild(0))));
//         zone->add(new Plant(*static_cast<Plant*>(zone->getChild(0))));
//         zone->add(new Plant(*static_cast<Plant*>(zone->getChild(0))));
//         zone->add(new Plant(*static_cast<Plant*>(zone->getChild(0))));
//         zone->add(new Plant(*static_cast<Plant*>(zone->getChild(0))));
//         zone->add(new Plant(*static_cast<Plant*>(zone->getChild(0))));


//     }

//     // Cleanup
//     for(std::vector<Zone*>::iterator it = zones.begin(); it != zones.end(); ++it){
//         delete (*it);
//     }
//     std::cout << "\n===== GREENHOUSE SUBSYSTEM TESTING COMPLETE =====\n";
//     return 0;
// }
