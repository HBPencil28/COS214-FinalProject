#include <iostream>
#include <vector>
#include <string>
#include <random>

// Strategy
#include "CareStrategy.h"
#include "LowCare.h"
#include "MediumCare.h"
#include "HighCare.h"

// Mediator & Observer
#include "Staff.h"
#include "PlantObserver.h"
#include "NurseryMediator.h"
#include "CareStaff.h"
#include "CustomerStaff.h"

// Composite (Prototype is involved here but yea...)
#include "Greenhouse.h"
#include "Plant.h"
#include "Zone.h"

// Singleton & Iterator
#include "Inventory.h"
#include "PlantIterator.h"

// Care & Customer Command
#include "CareCommand.h"
#include "CustomerCommand.h"
#include "WaterPlant.h"
#include "FertilisePlant.h"
#include "RequestHelp.h"
#include "BuyPlant.h"
#include "CustomisePlant.h"

// State 
#include "PlantState.h"
#include "PlantStatus.h"
#include "Seedling.h"
#include "Growing.h"
#include "Mature.h"
#include "Withered.h"
#include "InStorage.h"
#include "Sold.h"
#include "Returned.h"

// Builder
#include "BuildPlantDirector.h"
#include "PotPlantBuilder.h"
#include "WrapPlantBuilder.h"
#include "PlantPot.h"
#include "PlantSoil.h"
#include "PlantWrap.h"

// Decorator
#include "BasePlant.h"
#include "PottedPlant.h"
#include "WrappedPlant.h"
#include "PlantDecorator.h"
#include "Bow.h"
#include "Ribbon.h"
#include "String.h"

// chain of responsibility
#include "StaffHandler.h"
#include "NormalStaff.h"
#include "Manager.h"
#include "SeniorManager.h"

// Factory
#include "StaffFactory.h"
#include "CustomerFactory.h"
#include "CareFactory.h"
#include <SFML/System.hpp>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dist(0, 10);

int main(){
    // ================================================ Initialisation =======================================
    StaffFactory* stf[2];
    for(int i = 0; i < 2; i++){
        if(i == 0) stf[i] = new CareFactory();
        else stf[i] = new CustomerFactory();
    }

    Staff* sm[2]; // 0 - carestaff, 1 - customerstaff
    for(int i = 0; i < 2; i++){
        sm[i] = stf[i]->createStaff();
    }

    Zone zone(std::string("Zone-1"), std::string("Flower"), static_cast<CareStaff*>(sm[0]));

    Plant* p = nullptr;
    for(int i = 0; i < 3; i++){
        if(i == 0) p = new Plant("Daisy", "Flower");
        else if(i == 1) p = new Plant("Rose", "Flower");
        else p = new Plant("Tulip", "Flower");

        zone.add(p);
    }

    // ===================== "Game Loop" =====================
    
    int counter = 0;
    while(counter < 1000){
        for(size_t i = 0; i < zone.getChildren().size(); i++){
            Plant* p = dynamic_cast<Plant*>(zone.getChild(i));
            if(p)
                p->dailyTick();
        }

        sf::sleep(sf::milliseconds(16));
        counter++;
    }



    // ============================================== Memory Management ====================================================    
    for(int i = 0; i < 2; i++)
        delete stf[i];
    
    return 0;
}
