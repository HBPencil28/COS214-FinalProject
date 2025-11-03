// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "doctest.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <random>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>


// Mediator stuff
#include "NurseryMediator.h"
#include "Manager.h"
#include "Staff.h"
#include "CustomerStaff.h"
#include "CareStaff.h"

// Observer Stuff
#include "PlantObserver.h"
#include "Greenhouse.h"
#include "Zone.h"
#include "Plant.h"

// CustomerCommand Stuff
#include "CustomerCommand.h"
#include "BuyPlant.h"
#include "RequestHelp.h"
#include "CustomisePlant.h"
#include "Customer.h"

// necessary files too...
#include "BasePlant.h"
#include "Inventory.h"
#include "Mature.h"
#include "InStorage.h"
#include "PlantIterator.h"
#include "Withered.h"

sf::Clock timer;
std::random_device rd;
std::mt19937 gen(rd());

int main(){
    std::uniform_int_distribution<int> dist(0, 10);

    Inventory* inv = Inventory::getInstance();
    
    // int x = 5;
    // int* y = &x;

    Plant* p = NULL;
    // inv->addCactus(p);
    for(int i = 1; i <= 10; i++){
        if(i < 2){
            p = new Plant("rose", "flower");
            p->setZone(nullptr);
            p->setState(new Mature());
            p->setStatus(new InStorage());
            inv->addRose(p);
        } 
        else if(i < 4) {
            p = new Plant("cactus", "cactus");
            p->setZone(nullptr);
            p->setState(new Mature());
            p->setStatus(new InStorage());
            inv->addCactus(p);
        }
        else if(i < 6) {
            p = new Plant("baobab", "Trees & Shrubs");
            p->setZone(nullptr);
            p->setState(new Mature());
            p->setStatus(new InStorage());
            inv->addBaobab(p);
        }
        else if(i < 8) {
            p = new Plant("mint","Herb & Aromatics");
            p->setZone(nullptr);
            p->setState(new Mature());
            p->setStatus(new InStorage());
            inv->addMint(p);
        }
        else{
            Plant *p = new Plant("rose", "flower");
            inv->addSeed(p);
        }
    }
    
    NurseryMediator* benson = new NurseryMediator();
    Staff* cols[2];
    for(int i = 0; i < 2; i++){
        if(i == 0)
            cols[i] = new CareStaff();
        else cols[i] = new CustomerStaff();

        benson->attach(cols[i]);
    }

    Customer* c = new Customer();
    
    std::cout << "Customer buying a plant" << std::endl;
    
    Order order;
    order.base = "Potted";
    order.flowerName = "rose";
    order.num = 1;
    
    c->buyPlant(cols[1], &order);
    std::cout << cols[1]->get()["rose"] << std::endl;

    std::cout << std::endl;
    std::cout << "Making a plant withered and triggering observer and possibly mediator" << std::endl;
    std::cout << "=======================================================================" << std::endl;

    PlantIterator* pIt = Inventory::getInstance()->createIterator("Cactuses");
    // if(pIt->hasNext()) pIt->next();
    p = pIt->current();
    p->display();
    std::cout << std::endl;

    CareStaff* cs = dynamic_cast<CareStaff*>(cols[0]);
    if(cs){
        p->attach(cs);
        p->setState(new Withered());
    }
    else{
        std::cout << "Dynamic cast made ts null twin...\n We gotta make a plan." << std::endl;
    }

    


    delete pIt;
    delete c;
    delete benson;
    for(int i = 0; i < 2; i++)
        delete cols[i];
    Inventory::clearInventory();

    return 0;
}