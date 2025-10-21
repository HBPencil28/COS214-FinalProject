#include "Inventory.h"
#include "PlantIterator.h"
#include "Plant.h"

Inventory::Inventory(){}

Inventory* Inventory::getInstance(){ // initialises and gets alr existing
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

Plant* Inventory::removePlant(Plant* p) {
    if(p == nullptr) {
        std::cout << "Cannot remove null plant from inventory" << std::endl;
        return nullptr;
    }

    PlantIterator* itr = createIterator();
    Plant* removedPlant = nullptr;
    
    // Start from the first element
    Plant* current = itr->first();
    
    while(current != nullptr && itr->hasNext()) {
        if(current == p) {
            // Find the plant in the vector and remove it
            auto it = std::find(plants.begin(), plants.end(), p);
            if(it != plants.end()) {
                removedPlant = *it;
                plants.erase(it);
                std::cout << "Successfully removed plant: " << p->getType() << " from inventory\n";
                break;
            }
        }
        current = itr->next();
    }

    // Check the last element if not found yet
    if(removedPlant == nullptr && current == p) {
        auto it = std::find(plants.begin(), plants.end(), p);
        if(it != plants.end()) {
            removedPlant = *it;
            plants.erase(it);
            std::cout << "Successfully removed plant: " << p->getType() << " from inventory\n";
        }
    }

    delete itr; // Clean up iterator
    
    if(removedPlant == nullptr) {
        std::cout << "Plant not found in inventory" << std::endl;
    }
    
    return removedPlant;
}

PlantIterator* Inventory::createIterator(){
    return new PlantIterator;
}

std::vector<Plant*>& Inventory::getPlants() { return plants; }

Inventory::~Inventory() {
    // Clean up plants if needed
    for(Plant* plant : plants) {
        delete plant;
    }
}