#include "Inventory.h"
#include "PlantIterator.h"
#include "Plant.h"
Inventory::Inventory(){}

Inventory* Inventory::getInstance(){
    if(instance == nullptr){
        instance = new Inventory();
    }

    return instance;
}

//static variables must be initialise out of line
Inventory* Inventory::instance = nullptr;

void Inventory::addPlant(Plant* p){
    //TODO: ensure plants getter prints some type of name or type
    if(p == nullptr){
        std::cout << "There is no plant to be added"<< std::endl; 
        return;
    }
    plants.push_back(p);
    std::cout << "Successfully added plant: "<< p->getName() << " to the inventory\n";
}

bool Inventory::removePlant(Plant* p) {

    if(p == nullptr) {
        std::cout << "The plant entered is not in stock" << std::endl;
        return false;
    }

    PlantIterator* itr = createIterator();
    bool found = false;
    
    for(itr->first(); !itr->hasNext(); itr->next()) {
        if(itr->current() == p) {
            // Find the plant in the vector and remove it
            auto it = std::find(plants.begin(), plants.end(), p);
            if(it != plants.end()) {
                plants.erase(it);
                std::cout << "Successfully removed plant: " << p->getName() << " from inventory\n";
                found = true;
                break;
            }
        }
    }

    delete itr; // Clean up iterator
    return found;
}

PlantIterator* Inventory::createIterator(){
    return new PlantIterator;
}

std::vector<Plant*>& Inventory::getPlants() { return plants; }
