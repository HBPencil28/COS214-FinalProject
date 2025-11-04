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

void callDailyTicks(Zone& z, bool& running);
void print(const char* str){
    std::cout << str + '\0' << std::endl;
}

void buySetup(Customer*& you, Staff*& s);

void getAdvice(Customer*& you, Staff*& s);

void customiseBoughtPlant(Customer*& you, Staff*& s);

int getRandomInt(int min, int max) {
    static std::random_device rd;   // non-deterministic seed
    static std::mt19937 gen(rd());  // Mersenne Twister RNG
    std::uniform_int_distribution<> dist(min, max);
    return dist(gen);
}



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

    Inventory* inv = Inventory::getInstance();
    //create x Roses
    for(int i = 0; i < getRandomInt(1, 20); i++){
        Plant* p = new Plant("Rose","Flower");
        p->setState(new Mature());
        inv->addRose(p);
    }

    //create y Dasies
    for(int i = 0; i < getRandomInt(2, 20); i++){
        Plant* p = new Plant("Daisy","Flower");
        p->setState(new Mature());
        inv->addDaisy(p);
    }

    //create z Hibiscus
    for(int i = 0; i < getRandomInt(0,20); i++){
        Plant* p = new Plant("Hibiscus","Tree&Shrub");
        p->setState(new Mature());
        inv->addHibiscus(p);
    }

    //create a Basil
    for(int i = 0; i <getRandomInt(0,20); i++){
        Plant* p = new Plant("Basil","Herb&Aromatic");
        p->setState(new Mature());
        inv->addBasil(p);
    }

    Zone* z1 = new Zone(std::string("Zone-1"), std::string("Flower"), static_cast<CareStaff*>(sm[0]));
    Zone* z2 = new Zone(std::string("Zone-2"), std::string("Herbs&Aromatics"), static_cast<CareStaff*>(sm[0]));
    Zone* z3 = new Zone(std::string("Zone-3"), std::string("Trees&Shrubs"), static_cast<CareStaff*>(sm[0]));
    Zone* z4 = new Zone(std::string("Zone-4"), std::string("Succulents&Cactuses"), static_cast<CareStaff*>(sm[0]));



    Plant* p = nullptr;
    for(int i = 0; i < 3; i++){
        if(i == 0) p = new Plant("Daisy", "Flower");
        else if(i == 1) p = new Plant("Rose", "Flower");
        else p = new Plant("Tulip", "Flower");

        z1->add(p);
    }

    for(int i = 0; i < 3; i++){
        if(i == 0) p = new Plant("Mint", "Herbs&Aromatics");
        else if(i == 1) p = new Plant("Basil", "Herbs&Aromatics");
        else p = new Plant("Rosemary", "Herbs&Aromatics");

        z2->add(p);
    }

    for(int i = 0; i < 3; i++){
        if(i == 0) p = new Plant("Hibiscus", "Trees&Shrubs");
        else if(i == 1) p = new Plant("Oak", "Trees&Shrubs");
        else p = new Plant("Boxwood", "Trees&Shrubs");

        z3->add(p);
    }

    for(int i = 0; i < 2; i++){
        if(i == 0) p = new Plant("Succulent", "Succulents&Cactuses");
        else if(i == 1) p = new Plant("Cactus", "Succulents&Cactuses");

        z4->add(p);
    }

    // attach to mediator and zones
    NurseryMediator* nm = new Manager();
    for(Staff* s : sm)
        nm->attach(s);

    z1->attach(static_cast<CareStaff*>(sm[0]));
    z2->attach(static_cast<CareStaff*>(sm[0]));
    z3->attach(static_cast<CareStaff*>(sm[0]));
    z4->attach(static_cast<CareStaff*>(sm[0]));


    // ===================== "Game Loop" =====================
    
    Customer* c = new Customer();
    bool running = true;
    int opt;
    while(running){
        print("=================Welcome to Plantasy Gardens=============");
        print("What would you like to do ?");
        print("\t1: Buy a Plant");
        print("\t2: Get advice on what plant to get");
        print("\t3: Customise your Plant (MUST HAVE BOUGHT A PLANT)");
        print("\t>3: Any other number to quit");
        print("");
        std::cin >> opt;

        switch(opt){
            case 1: 
                buySetup(c, sm[1]);
                break;
            case 2: 
                getAdvice(c, sm[1]);
                break;
            case 3: 
                customiseBoughtPlant(c, sm[1]);
                break;

            default:
                print("See you again :)");
                running = false;
                break;
        }
    }



    // ============================================== Memory Management ====================================================    
    for(int i = 0; i < 2; i++){delete stf[i];}
    
    delete nm;
    delete z1;
    delete z2;
    delete z3;
    delete z4;
    for(Staff* s : sm){delete s;}
        
    delete c;
    Inventory::clearInventory();

    return 0;
}

void callDailyTicks(Zone& z, bool& running){
    for(size_t i = 0; i < z.getChildren().size(); i++){
        Plant* p = dynamic_cast<Plant*>(z.getChild(i));
        if(p){
            std::cout << p->getName() << " age: " << p->getAgeDays() << std::endl;
            std::cout << p->getName() << " height: " << p->getHeight() << std::endl;
            std::cout << p->getName() << " hydration level: " << p->getHydrationLevel() << std::endl;
            std::cout << p->getName() << " Fertiliser amount: " << p->getFertiliserAmount() << std::endl;

            if(p->isMature()) running = false;
            p->dailyTick();
        }
    }
}

void buySetup(Customer*& you, Staff*& s){
    int opt;
    Order deets;
    print("Would you like your plant potted or wrapped?");
    print("\t1: Potted");
    print("\t2: Wrapped");
    std::cin >> opt;

    if(opt == 1) deets.base = "Potted";
    else if(opt == 2) deets.base = "Wrapped";

    print("What plant would like to get?");
    print("\t1: Rose");
    print("\t2: Daisy");
    print("\t3: Basil");
    print("\t4: Hibiscus");
    print("\t5: Oak");
    print("\t6: Baobab");
    print("\t7: Mint");
    print("\t8: Rosemary");
    std::cin >> opt;
    
    if(opt == 1) deets.flowerName = "Rose";
    else if(opt == 2) deets.flowerName = "Daisy";
    else if(opt == 3) deets.flowerName = "Basil";
    else if(opt == 4) deets.flowerName = "Hibiscus";
    else if(opt == 5) deets.flowerName = "Oak";
    else if(opt == 6) deets.flowerName = "Baobab";
    else if(opt == 7) deets.flowerName = "Mint";
    else if(opt == 8) deets.flowerName = "Rosemary";

    if(deets.base == "Potted") deets.num = 1;
    else{
        print("How many of these would you like in your wrapping?");
        std::cin >> deets.num;
    }

    you->buyPlant(s, &deets);
}

void getAdvice(Customer*& you, Staff*& s){
    std::string query;
    int opt;

    print("What are you looking for in your plant?");
    print("\n1: beautiful petals");
    print("\n2: bright blossoms");
    print("\n3: spring charm");
    print("\n4: low maintenance");
    print("\n5: cooking flavor");
    print("\n6: fresh aroma");
    print("\n7: thick trunk tree");
    print("\n8: tropical color");
    std::cin >> opt;

    if(opt == 1) query = "beautiful petals";
    else if(opt == 2) query = "bright blossoms";
    else if(opt == 3) query = "spring charm";
    else if(opt == 4) query = "low maintenance";
    else if(opt == 5) query = "cooking flavor";
    else if(opt == 6) query = "fresh aroma";
    else if(opt == 7) query = "thick trunk tree";
    else if(opt == 8) query = "tropical color";

    you->requestHelp(s, query);
}

void customiseBoughtPlant(Customer*& you, Staff*& s){
    std::string query;
    int opt;

    print("What accessory would you like to put on your plant?");
    print("\t1: Ribbon");
    print("\t2: Bow");
    print("\t3: String");
    std::cin >> opt;

    if(opt == 1) query = "ribbon";
    else if(opt == 2) query = "bow";
    else if(opt == 3) query = "string";
    
    you->customiseMyPlant(s, query);
}