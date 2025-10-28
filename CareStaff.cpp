#include "CareStaff.h"

void CareStaff::update() {
    // Implementation for updating based on plant state changes
    bool toUpdate = false;
    for(std::vector<Greenhouse*>::iterator it = static_cast<Zone*>(zone)->getChildren().begin(); it != static_cast<Zone*>(zone)->getChildren().end(); ++it) {
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

void CareStaff::insertToInventory(Plant* plant, bool& toUpdate) {
    std::string plantName = toLowerCase(plant->getName());

        // flowers
        if(plantName.compare("rose") == 0){
            if(inv->isRosesEmpty()){
                toUpdate = true;
            }
            inv->addRose(plant);
            inv->addSeed(plant->clone());
        }
        else if(plantName.compare("daisy") == 0){
            if(inv->isDaisiesEmpty()){
            }
            inv->addDaisy(plant);
            inv->addSeed(plant->clone());
        }
        else if(plantName.compare("tulip") == 0){
            if(inv->isTulipsEmpty()){
            }
            inv->addTulip(plant);
            inv->addSeed(plant->clone());
        }
        // succulents & cactuses
        else if(plantName.compare("cactus") == 0){
            if(inv->isCactusesEmpty()){

            }
            inv->addCactus(plant);
            inv->addSeed(plant->clone());
        }
        else if(plantName.compare("succulent") == 0){
            if(inv->isSucculentsEmpty()){
            
            }
            inv->addSucculent(plant);
            inv->addSeed(plant->clone());
        }
        // herbs & aromatics
        else if(plantName.compare("basil") == 0){
            if(inv->isBasilsEmpty()){
                
            }
            inv->addBasil(plant);
            inv->addSeed(plant->clone());
        }
        else if(plantName.compare("mint") == 0){
            if(inv->isMintsEmpty()){
                
            }
            inv->addMint(plant);
            inv->addSeed(plant->clone());
        }
        else if(plantName.compare("parsley") == 0){
            if(inv->isParsleysEmpty()){
                
            }
            inv->addParsley(plant);
            inv->addSeed(plant->clone());
        }
        else if(plantName.compare("coriander") == 0){
            if(inv->isCoriandersEmpty()){
                
            }
            inv->addCoriander(plant);
            inv->addSeed(plant->clone());
        }
        else if(plantName.compare("lavender") == 0){
            if(inv->isLavendersEmpty()){
                
            }
            inv->addLavender(plant);
            inv->addSeed(plant->clone());
        }
        else if(plantName.compare("rosemary") == 0){
            if(inv->isRosemaryEmpty()){
                
            }
            inv->addRosemary(plant);
            inv->addSeed(plant->clone());
        }
        else if(plantName.compare("lemonbalm") == 0){
            if(inv->isLemonBalmsEmpty()){
                
            }
            inv->addLemonBalm(plant);
            inv->addSeed(plant->clone());
        }
        // trees & shrubs
        else if(plantName.compare("hibiscus") == 0){
            if(inv->isHibiscusEmpty()){
                
            }
            inv->addHibiscus(plant);
            inv->addSeed(plant->clone());
        }
        else if(plantName.compare("hydrangea") == 0){
            if(inv->isHydrangeaEmpty()){
                
            }
            inv->addHydrangea(plant);
            inv->addSeed(plant->clone());
        }
        else if(plantName.compare("boxwood") == 0){
            if(inv->isBoxwoodEmpty()){
                
            }
            inv->addBoxwood(plant);
            inv->addSeed(plant->clone());
        }
        else if(plantName.compare("oak") == 0){
            if(inv->isOakEmpty()){
                
            }
            inv->addOak(plant);
            inv->addSeed(plant->clone());
        }
        else if(plantName.compare("baobab") == 0){
            if(inv->isBaobabEmpty()){
                
            }
            inv->addBaobab(plant);
            inv->addSeed(plant->clone());
        }
}

void CareStaff::changed() {
    mediator->notify(this);
}

std::map<std::string, bool> CareStaff::get() {
    // Return information about the plant they  would be: s (from the harvest command)]
    return stockAvailability;
}

void CareStaff::set(std::map<std::string, bool> message) {
    // Receive notification from the mediator
    stockAvailability = message;
}

std::string toLowerCase(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), 
                   [](unsigned char c){ return std::tolower(c); });
    return str;
}