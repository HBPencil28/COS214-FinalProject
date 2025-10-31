#include "CustomerStaff.h"


void CustomerStaff::changed() {
    // CustomerStaff would add a mature plant to the inventory
    // tell the mediator about the change, to notify other staff
    mediator->notify(this);
}

std::map<std::string, bool> CustomerStaff::get() {
    // ret = information about the plant they depleted from inventory
    // message would be: Out of Stock: [Plant details (from the harvest command)]
    return stockAvailability;
}

void CustomerStaff::set(std::map<std::string, bool> message) {
    // Receive notification from the mediator
    stockAvailability = message;
}

void CustomerStaff::advise(std::string issue) {
    if (issue.find("colorful flowers") != std::string::npos || 
        issue.find("romantic") != std::string::npos || 
        issue.find("beautiful petals") != std::string::npos) {
        std::cout << "You might like a Rose." << std::endl;
    } else if (issue.find("cheerful simplicity") != std::string::npos || 
               issue.find("bright blossoms") != std::string::npos || 
               issue.find("happy garden") != std::string::npos) {
        std::cout << "You might like a Daisy." << std::endl;
    } else if (issue.find("elegance and beauty") != std::string::npos || 
               issue.find("spring charm") != std::string::npos || 
               issue.find("colorful blooms") != std::string::npos) {
        std::cout << "You might like a Tulip." << std::endl;
    } else if (issue.find("low maintenance") != std::string::npos || 
               issue.find("desert resilience") != std::string::npos || 
               issue.find("strong survival") != std::string::npos) {
        std::cout << "You might like a Cactus." << std::endl;
    } else if (issue.find("drought tolerance") != std::string::npos || 
               issue.find("easy care") != std::string::npos || 
               issue.find("minimal watering") != std::string::npos) {
        std::cout << "You might like a Succulent." << std::endl;
    } else if (issue.find("cooking flavor") != std::string::npos || 
               issue.find("culinary herb") != std::string::npos || 
               issue.find("Italian aroma") != std::string::npos) {
        std::cout << "You might like Basil." << std::endl;
    } else if (issue.find("fresh aroma") != std::string::npos || 
               issue.find("cooling herb") != std::string::npos || 
               issue.find("refreshing scent") != std::string::npos) {
        std::cout << "You might like Mint." << std::endl;
    } else if (issue.find("garnish herbs") != std::string::npos || 
               issue.find("green decoration") != std::string::npos || 
               issue.find("natural seasoning") != std::string::npos) {
        std::cout << "You might like Parsley." << std::endl;
    } else if (issue.find("citrus scent") != std::string::npos || 
               issue.find("refreshing leaves") != std::string::npos || 
               issue.find("gentle fragrance") != std::string::npos) {
        std::cout << "You might like Lemon Balm." << std::endl;
    } else if (issue.find("calming fragrance") != std::string::npos || 
               issue.find("relaxing aroma") != std::string::npos || 
               issue.find("scented flowers") != std::string::npos) {
        std::cout << "You might like Lavender." << std::endl;
    } else if (issue.find("garden fragrance") != std::string::npos || 
               issue.find("herbal aroma") != std::string::npos || 
               issue.find("fresh seasoning") != std::string::npos) {
        std::cout << "You might like Rosemary." << std::endl;
    } else if (issue.find("exotic flavor") != std::string::npos || 
               issue.find("spicy aroma") != std::string::npos || 
               issue.find("flavorful herb") != std::string::npos) {
        std::cout << "You might like Coriander." << std::endl;
    } else if (issue.find("decorative greenery") != std::string::npos || 
               issue.find("garden borders") != std::string::npos || 
               issue.find("neat hedges") != std::string::npos) {
        std::cout << "You might like Boxwood." << std::endl;
    } else if (issue.find("large shade tree") != std::string::npos || 
               issue.find("strong trunk") != std::string::npos || 
               issue.find("classic tree") != std::string::npos) {
        std::cout << "You might like Oak." << std::endl;
    } else if (issue.find("African beauty") != std::string::npos || 
               issue.find("majestic presence") != std::string::npos || 
               issue.find("thick trunk tree") != std::string::npos) {
        std::cout << "You might like Baobab." << std::endl;
    } else if (issue.find("tropical color") != std::string::npos || 
               issue.find("exotic appeal") != std::string::npos || 
               issue.find("vibrant petals") != std::string::npos) {
        std::cout << "You might like Hibiscus." << std::endl;
    } else if (issue.find("lush flowers") != std::string::npos || 
               issue.find("rich blossoms") != std::string::npos || 
               issue.find("vivid clusters") != std::string::npos) {
        std::cout << "You might like Hydrangea." << std::endl;
    } else {
        std::cout << "Sorry, we couldn't find a match for your request." << std::endl;
    }
}

BasePlant* CustomerStaff::getRequestedPlant(Order plantDetails) {
    if(!checkAvailability(plantDetails.flowerName)) return nullptr;
    // process the request to buy a plant
    PlantBuilder* builder = nullptr;
    BasePlant* plant = nullptr;
    bool toPot, toUpdate = false;

    if(plantDetails.base == "Potted"){
        plant = new PottedPlant(getFromInventory(plantDetails.flowerName, toUpdate));
        builder = new PotPlantBuilder(plant);
        toPot = true;
    }
    else if(plantDetails.base == "Wrapped"){
        plant = new WrappedPlant();
        builder = new WrapPlantBuilder(plant);
        toPot = false;
    }

    setBuilder(builder);
    construct(toPot);
    plant = getBuilder()->getProduct();

    if(plantDetails.num > 1){
        for(int i = 0; i < plantDetails.num; i++){
            Plant* p = getFromInventory(plantDetails.flowerName, toUpdate);
            static_cast<WrappedPlant*>(plant)->addPlant(p);
        }
    }
    
    // After processing, update inventory
    if(toUpdate){
        changed();
    }

    return plant;
}

bool CustomerStaff::checkAvailability(std::string plantName) {
    // check if the requested plant is available in inventory
    for(auto& pair : stockAvailability){
        if(pair.first == plantName){
            return pair.second;
        }
    }
    return true;
}

BasePlant* CustomerStaff::customise(BasePlant* plant, std::string accessory) {
    // customise the plant with the given accessory
    accessory = toLowerCase(accessory);
    BasePlant* decor = NULL;

    if(accessory.compare("bow") == 0) {
        decor = new Bow();
    }
    else if(accessory.compare("ribbon") == 0){
        decor = new Ribbon();
    }
    else if(accessory.compare("string") == 0){
        decor = new String();
    }

    decor->add(plant);
    return decor;
}

std::string toLowerCase(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), 
                   [](unsigned char c){ return std::tolower(c); });
    return str;
}

Plant* CustomerStaff::getFromInventory(std::string plantName, bool& depleted) {
    // flowers
    Plant* ret = NULL;
    if(plantName.compare("rose") == 0){
        ret = inv->removeRose();
        if(inv->isRosesEmpty()){ 
            stockAvailability.insert(std::pair<std::string, bool>("rose", false));
            depleted = true;
        }
        
    }
    else if(plantName.compare("daisy") == 0){
        ret = inv->removeDaisy();
        if(inv->isRosesEmpty()){ 
            stockAvailability.insert(std::pair<std::string, bool>("daisy", false));
            depleted = true;
        }
    }
    else if(plantName.compare("tulip") == 0){
        ret = inv->removeTulip();
        if(inv->isRosesEmpty()){ 
            stockAvailability.insert(std::pair<std::string, bool>("tulip", false));
            depleted = true;
        }
    }
    // succulents & cactuses
    else if(plantName.compare("cactus") == 0){
        ret = inv->removeCactus();
        if(inv->isRosesEmpty()){ 
            stockAvailability.insert(std::pair<std::string, bool>("cactus", false));
            depleted = true;
        }
    }
    else if(plantName.compare("succulent") == 0){
        ret = inv->removeSucculent();
        if(inv->isRosesEmpty()){ 
            stockAvailability.insert(std::pair<std::string, bool>("succulent", false));
            depleted = true;
        }
    }
    // herbs & aromatics
    else if(plantName.compare("basil") == 0){
        ret = inv->removeBasil();
        if(inv->isRosesEmpty()){ 
            stockAvailability.insert(std::pair<std::string, bool>("basil", false));
            depleted = true;
        }
    }
    else if(plantName.compare("mint") == 0){
        ret = inv->removeMint();
        if(inv->isRosesEmpty()){ 
            stockAvailability.insert(std::pair<std::string, bool>("mint", false));
            depleted = true;
        }
    }
    else if(plantName.compare("parsley") == 0){
        ret = inv->removeParsley();
        if(inv->isRosesEmpty()){ 
            stockAvailability.insert(std::pair<std::string, bool>("parsley", false));
            depleted = true;
        }
    }
    else if(plantName.compare("coriander") == 0){
        ret = inv->removeCoriander();
        if(inv->isRosesEmpty()){ 
            stockAvailability.insert(std::pair<std::string, bool>("coriander", false));
            depleted = true;
        }
    }
    else if(plantName.compare("lavender") == 0){
        ret = inv->removeLavender();
        if(inv->isRosesEmpty()){ 
            stockAvailability.insert(std::pair<std::string, bool>("lavender", false));
            depleted = true;
        }
    }
    else if(plantName.compare("rosemary") == 0){
        ret = inv->removeRosemary();
        if(inv->isRosesEmpty()){ 
            stockAvailability.insert(std::pair<std::string, bool>("rosemary", false));
            depleted = true;
        }
    }
    else if(plantName.compare("lemonbalm") == 0){
        ret = inv->removeLemonBalm();
        if(inv->isRosesEmpty()){ 
            stockAvailability.insert(std::pair<std::string, bool>("lemonbalm", false));
            depleted = true;
        }
    }
    // trees & shrubs
    else if(plantName.compare("hibiscus") == 0){
        ret = inv->removeHibiscus();
        if(inv->isRosesEmpty()){ 
            stockAvailability.insert(std::pair<std::string, bool>("hibiscus", false));
            depleted = true;
        }
    }
    else if(plantName.compare("hydrangea") == 0){
        ret = inv->removeHydrangea();
        if(inv->isRosesEmpty()){ 
            stockAvailability.insert(std::pair<std::string, bool>("hydrangea", false));
            depleted = true;
        }
    }
    else if(plantName.compare("boxwood") == 0){
        ret = inv->removeBoxwood();
        if(inv->isRosesEmpty()){ 
            stockAvailability.insert(std::pair<std::string, bool>("boxwood", false));
            depleted = true;
        }
    }
    else if(plantName.compare("oak") == 0){
        ret = inv->removeOak();
        if(inv->isRosesEmpty()){ 
            stockAvailability.insert(std::pair<std::string, bool>("oak", false));
            depleted = true;
        }
    }
    else if(plantName.compare("baobab") == 0){
        ret = inv->removeBaobab();
        if(inv->isRosesEmpty()){ 
            stockAvailability.insert(std::pair<std::string, bool>("baobab", false));
            depleted = true;
        }
    }
    return ret;
}