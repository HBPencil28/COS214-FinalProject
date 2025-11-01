#include "CareStaff.h"
#include "Zone.h"
#include "Plant.h"
#include "NurseryMediator.h"
#include "Inventory.h"

std::string toLowerCase(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), 
                   [](unsigned char c){ return std::tolower(c); });
    return str;
}

CareStaff::~CareStaff() {}

void CareStaff::performDuty() const {}

void CareStaff::water(int amount){
    if (!zone) return;
    Zone *z = static_cast<Zone *>(this->zone);
    if (z){
        for (Greenhouse *plant : z->getChildren()){
            Plant *p = static_cast<Plant *>(plant);
            if (p)
            {
                p->water(amount);
            }
        }
    }
}

void CareStaff::fertilise(int amount){
    if (!zone)
        return;
    Zone *z = static_cast<Zone *>(this->zone);
    if (z)
    {
        for (Greenhouse *plant : z->getChildren())
        {
            Plant *p = static_cast<Plant *>(plant);
            if (p)
            {
                p->fertilize(amount);
            }
        }
    }
}

void CareStaff::changed() {
    mediator->notify(this);
}

// CareStaff will say the plant they restocked, DeliveryStaff && CustomerStaff will say the plant they finished
std::map<std::string, bool> CareStaff::get() {
    // Return information about the plant they  would be: s (from the harvest command)]
    return stockAvailability;
}

void CareStaff::insertToInventory(Plant* plant, bool& toUpdate) {
    std::string plantName = toLowerCase(plant->getName());

    // flowers
    if(plantName.compare("rose") == 0){
        if(inv->isRosesEmpty()){
            toUpdate = true;
        }
        inv->addRose(plant);
        inv->addSeed(static_cast<Plant*>(plant->clone()));
        stockAvailability["rose"] = true;
    }
    else if(plantName.compare("daisy") == 0){
        if(inv->isDaisiesEmpty()){
            toUpdate = true;
        }
        inv->addDaisy(plant);
        inv->addSeed(static_cast<Plant*>(plant->clone()));
        stockAvailability["daisy"] = true;
    }
    else if(plantName.compare("tulip") == 0){
        if(inv->isTulipsEmpty()){
            toUpdate = true;
        }
        inv->addTulip(plant);
        inv->addSeed(static_cast<Plant*>(plant->clone()));
        stockAvailability["tulip"] = true;
    }
    // succulents & cactuses
    else if(plantName.compare("cactus") == 0){
        if(inv->isCactusesEmpty()){
            toUpdate = true;
        }
        inv->addCactus(plant);
        inv->addSeed(static_cast<Plant*>(plant->clone()));
        stockAvailability["cactus"] = true;
    }
    else if(plantName.compare("succulent") == 0){
        if(inv->isSucculentsEmpty()){
            toUpdate = true;    
        }
        inv->addSucculent(plant);
        inv->addSeed(static_cast<Plant*>(plant->clone()));
        stockAvailability["succulent"] = true;
    }
    // herbs & aromatics
    else if(plantName.compare("basil") == 0){
        if(inv->isBasilsEmpty()){
            toUpdate = true;
        }
        inv->addBasil(plant);
        inv->addSeed(static_cast<Plant*>(plant->clone()));
        stockAvailability["basil"] = true;
    }
    else if(plantName.compare("mint") == 0){
        if(inv->isMintsEmpty()){
            toUpdate = true;
        }
        inv->addMint(plant);
        inv->addSeed(static_cast<Plant*>(plant->clone()));
        stockAvailability["mint"] = true;
    }
    else if(plantName.compare("parsley") == 0){
        if(inv->isParsleysEmpty()){
            toUpdate = true;
        }
        inv->addParsley(plant);
        inv->addSeed(static_cast<Plant*>(plant->clone()));
        stockAvailability["parsley"] = true;
    }
    else if(plantName.compare("coriander") == 0){
        if(inv->isCoriandersEmpty()){
            toUpdate = true;    
        }
        inv->addCoriander(plant);
        inv->addSeed(static_cast<Plant*>(plant->clone()));
        stockAvailability["coriander"] = true;
    }
    else if(plantName.compare("lavender") == 0){
        if(inv->isLavendersEmpty()){
            toUpdate = true;   
        }
        inv->addLavender(plant);
        inv->addSeed(static_cast<Plant*>(plant->clone()));
        stockAvailability["lavender"] = true;
    }
    else if(plantName.compare("rosemary") == 0){
        if(inv->isRosemaryEmpty()){
            toUpdate = true;
        }
        inv->addRosemary(plant);
        inv->addSeed(static_cast<Plant*>(plant->clone()));
        stockAvailability["rosemary"] = true;
    }
    else if(plantName.compare("lemonbalm") == 0){
        if(inv->isLemonBalmsEmpty()){
            toUpdate = true;
        }
        inv->addLemonBalm(plant);
        inv->addSeed(static_cast<Plant*>(plant->clone()));
        stockAvailability["lemonbalm"] = true;
    }
    // trees & shrubs
    else if(plantName.compare("hibiscus") == 0){
        if(inv->isHibiscusEmpty()){
            toUpdate = true;
        }
        inv->addHibiscus(plant);
        inv->addSeed(static_cast<Plant*>(plant->clone()));
        stockAvailability["hibiscus"] = true;
    }
    else if(plantName.compare("hydrangea") == 0){
        if(inv->isHydrangeaEmpty()){
            toUpdate = true;
        }
        inv->addHydrangea(plant);
        inv->addSeed(static_cast<Plant*>(plant->clone()));
        stockAvailability["hydrangea"] = true;
    }
    else if(plantName.compare("boxwood") == 0){
        if(inv->isBoxwoodEmpty()){
            toUpdate = true;
        }
        inv->addBoxwood(plant);
        inv->addSeed(static_cast<Plant*>(plant->clone()));
        stockAvailability["boxwood"] = true;
    }
    else if(plantName.compare("oak") == 0){
        if(inv->isOakEmpty()){
            toUpdate = true;
        }
        inv->addOak(plant);
        inv->addSeed(static_cast<Plant*>(plant->clone()));
        stockAvailability["oak"] = true;
    }
    else if(plantName.compare("baobab") == 0){
        if(inv->isBaobabEmpty()){
            toUpdate = true;
        }
        inv->addBaobab(plant);
        inv->addSeed(static_cast<Plant*>(plant->clone()));
        stockAvailability["baobab"] = true;
    }
}

Plant* CareStaff::removeFromInventory(Plant* plant, bool& toUpdate) {
    std::string plantName = toLowerCase(plant->getName());
    Plant* removedPlant = nullptr;

    // flowers
    if (plantName.compare("rose") == 0) {
        removedPlant = inv->removeRose(plant);
        if (inv->isRosesEmpty()) {
            stockAvailability["rose"] = false;
            toUpdate = true;
        }
    } else if (plantName.compare("daisy") == 0) {
        removedPlant = inv->removeDaisy(plant);
        if (inv->isDaisiesEmpty()) {
            stockAvailability["daisy"] = false;
            toUpdate = true;
        }
    } else if (plantName.compare("tulip") == 0) {
        removedPlant = inv->removeTulip(plant);
        if (inv->isTulipsEmpty()) {
            stockAvailability["tulip"] = false;
            toUpdate = true;
        }
    }
    // succulents & cactuses
    else if (plantName.compare("cactus") == 0) {
        removedPlant = inv->removeCactus(plant);
        if (inv->isCactusesEmpty()) {
            stockAvailability["cactus"] = false;
            toUpdate = true;
        }
    } else if (plantName.compare("succulent") == 0) {
        removedPlant = inv->removeSucculent(plant);
        if (inv->isSucculentsEmpty()) {
            stockAvailability["succulent"] = false;
            toUpdate = true;
        }
    }
    // herbs & aromatics
    else if (plantName.compare("basil") == 0) {
        removedPlant = inv->removeBasil(plant);
        if (inv->isBasilsEmpty()) {
            stockAvailability["basil"] = false;
            toUpdate = true;
        }
    } else if (plantName.compare("mint") == 0) {
        removedPlant = inv->removeMint(plant);
        if (inv->isMintsEmpty()) {
            stockAvailability["mint"] = false;
            toUpdate = true;
        }
    } else if (plantName.compare("parsley") == 0) {
        removedPlant = inv->removeParsley(plant);
        if (inv->isParsleysEmpty()) {
            stockAvailability["parsley"] = false;
            toUpdate = true;
        }
    } else if (plantName.compare("coriander") == 0) {
        removedPlant = inv->removeCoriander(plant);
        if (inv->isCoriandersEmpty()) {
            stockAvailability["coriander"] = false;
            toUpdate = true;
        }
    } else if (plantName.compare("lavender") == 0) {
        removedPlant = inv->removeLavender(plant);
        if (inv->isLavendersEmpty()) {
            stockAvailability["lavender"] = false;
            toUpdate = true;
        }
    } else if (plantName.compare("rosemary") == 0) {
        removedPlant = inv->removeRosemary(plant);
        if (inv->isRosemaryEmpty()) {
            stockAvailability["rosemary"] = false;
            toUpdate = true;
        }
    } else if (plantName.compare("lemonbalm") == 0) {
        removedPlant = inv->removeLemonBalm(plant);
        if (inv->isLemonBalmsEmpty()) {
            stockAvailability["lemonbalm"] = false;
            toUpdate = true;
        }
    }
    // trees & shrubs
    else if (plantName.compare("hibiscus") == 0) {
        removedPlant = inv->removeHibiscus(plant);
        if (inv->isHibiscusEmpty()) {
            stockAvailability["hibiscus"] = false;
            toUpdate = true;
        }
    } else if (plantName.compare("hydrangea") == 0) {
        removedPlant = inv->removeHydrangea(plant);
        if (inv->isHydrangeaEmpty()) {
            stockAvailability["hydrangea"] = false;
            toUpdate = true;
        }
    } else if (plantName.compare("boxwood") == 0) {
        removedPlant = inv->removeBoxwood(plant);
        if (inv->isBoxwoodEmpty()) {
            stockAvailability["boxwood"] = false;
            toUpdate = true;
        }
    } else if (plantName.compare("oak") == 0) {
        removedPlant = inv->removeOak(plant);
        if (inv->isOakEmpty()) {
            stockAvailability["oak"] = false;
            toUpdate = true;
        }
    } else if (plantName.compare("baobab") == 0) {
        removedPlant = inv->removeBaobab(plant);
        if (inv->isBaobabEmpty()) {
            stockAvailability["baobab"] = false;
            toUpdate = true;
        }
    }

    return removedPlant;
}

// receive notification from the mediator
void CareStaff::set(std::map<std::string, bool> message) {
    // Receive notification from the mediator
    stockAvailability = message;
}

void CareStaff::update(Plant* p){
    bool toUpdate = false;
    Plant* toRemove = removeFromInventory(p, toUpdate);
    delete toRemove;
    
    if(toUpdate)
        changed();
}

void CareStaff::update() {
    // Implementation for updating based on plant state changes
    bool toUpdate = false;
    for(std::vector<Greenhouse*>::const_iterator it = static_cast<Zone*>(zone)->getChildren().begin(); it != static_cast<Zone*>(zone)->getChildren().end(); ++it) {
        Plant* plant = static_cast<Plant*>(*it);
        std::string plantName = toLowerCase(plant->getName());

        // flowers
        if(plant->isMature()) {
            insertToInventory(plant, toUpdate);
        }
        
        // After processing, remove the plant from the zone
        zone->remove(*it); 
    }
    if(toUpdate){
        changed();
    }
}

