#include "Inventory.h"
#include "PlantIterator.h"
#include "Plant.h"
#include <stdexcept>

/**
 * @file Inventory.cpp
 * @brief Implementation of Inventory singleton and per-category add/remove/isEmpty methods.
 */

Inventory::Inventory() {}

Inventory* Inventory::instance = nullptr;

Inventory* Inventory::getInstance() {
    if (instance == nullptr) {
        instance = new Inventory();
    }
    return instance;
}

Inventory::~Inventory() {
    // Deletes owned Plant pointers in every collection 
    //using lambda function
    //define anonymous function in var called cleanup
    
    auto cleanup = [](std::vector<Plant*>& v){ // cleanup all memory
        //takes in vector of plant* [](vector<Plant*>&)
        for (Plant* p : v) {
            delete p;
        }
        v.clear();
    };

    //my lazy body is NOT doing this over and over
    cleanup(Roses);
    cleanup(Daisies);
    cleanup(Tulips);

    cleanup(Succulents);
    cleanup(Cactuses);

    cleanup(Basils);
    cleanup(Mints);
    cleanup(Parsleys);
    cleanup(Corianders);
    cleanup(Lavenders);
    cleanup(Rosemary);
    cleanup(LemonBalms);

    cleanup(Hibiscus);
    cleanup(Hydrangea);
    cleanup(Boxwood);
    cleanup(Oak);
    cleanup(Baobab);

    cleanup(seeds);

    if(instance) delete instance;
}


std::string Inventory::lower(const std::string &s) { // lowercase comparison
    std::string result = s;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return result;
}

///////////////////////
// Flowers
///////////////////////

bool Inventory::isRosesEmpty() const { return Roses.empty(); }

void Inventory::addRose(Plant* p) {
    if (!p) { std::cout << "Cannot add null Rose\n";
            throw std::runtime_error("tried to add null"); 
             return; }

    if(lower(p->getName()) == "rose"){
    Roses.push_back(p);
    std::cout << "Added Rose to Roses in Inventory"<< '\n';
    }
    else{
        std::cout << "Added plant is NOT a Rose";
    }
};

Plant* Inventory::removeRose() {
    if (Roses.empty()) {
        std::cout << "No Roses to remove\n";
        throw std::runtime_error("tried to remove null"); 
        return nullptr;
    }
    Plant* removed = Roses.back();
    Roses.pop_back();
    return removed;
}

bool Inventory::isDaisiesEmpty() const { return Daisies.empty(); }
void Inventory::addDaisy(Plant* p) {
    if (!p) { std::cout << "Cannot add null Daisy\n";
            throw std::runtime_error("tried to add null"); 
             return; }
    if(lower(p->getName()) == "daisy"){
    Daisies.push_back(p);
    std::cout << "Added Daisy to Dasies in Inventory"<< '\n';
    }
    else{
        std::cout << "Added plant is NOT a Daisy";
    }
}
Plant* Inventory::removeDaisy() {
    if (Daisies.empty()) {
        std::cout << "No Daisies to remove\n";
        throw std::runtime_error("tried to remove null"); 
        return nullptr;
    }
    Plant* removed = Daisies.back();
    Daisies.pop_back();
    return removed;

}

bool Inventory::isTulipsEmpty() const { return Tulips.empty(); }
void Inventory::addTulip(Plant* p) {
    if (!p) { std::cout << "Cannot add null Tulip\n"; return; }
    if(lower(p->getName()) == "tulip"){
    Tulips.push_back(p);
    std::cout << "Added Tulip to Tulips in Inventory"<< '\n';
    }
    else{
        std::cout << "Added plant is NOT a Tulip";
    }
}
Plant* Inventory::removeTulip() {
    if (Tulips.empty()) {
        std::cout << "No Tulips to remove\n";
        return nullptr;
    }
    Plant* removed = Tulips.back();
    Tulips.pop_back();
    return removed;
}

////////////////////////
// Succulents & Cactuses
////////////////////////

bool Inventory::isSucculentsEmpty() const { return Succulents.empty(); }
void Inventory::addSucculent(Plant* p) {
    if (!p) { std::cout << "Cannot add null Succulent\n"; 
            throw std::runtime_error("tried to add null"); 
            return; }
    if(lower(p->getName()) == "succulent"){
    Succulents.push_back(p);
    std::cout << "Added Succulent to Succulents in Inventory"<< '\n';
    }
    else{
        std::cout << "Added plant is NOT a Succulent";
    }
}
Plant* Inventory::removeSucculent() {
    if (Succulents.empty()) {
        std::cout << "No Succulents to remove\n";
        throw std::runtime_error("tried to remover null"); 
        return nullptr;
    }
    Plant* removed = Succulents.back();
    Succulents.pop_back();
    return removed;
}

bool Inventory::isCactusesEmpty() const { return Cactuses.empty(); }
void Inventory::addCactus(Plant* p) {
    if (!p) { std::cout << "Cannot add null Cactus\n"; return; }
    if(lower(p->getName()) == "cactus"){
    throw std::runtime_error("tried to add null"); 
    Cactuses.push_back(p);
    std::cout << "Added Cactus to Cactuses in Inventory"<< '\n';
    }
    else{
        std::cout << "Plant is NOT a Cactus";
    }
}
Plant* Inventory::removeCactus() {
    if (Cactuses.empty()) {
        std::cout << "No Cactuses to remove\n";
        throw std::runtime_error("tried to remove null"); 
        return nullptr;
    }
    Plant* removed = Cactuses.back();
    Cactuses.pop_back();
    return removed;
}

////////////////////////
// Herbs & Aromatics
////////////////////////

bool Inventory::isBasilsEmpty() const { return Basils.empty(); }
void Inventory::addBasil(Plant* p) {
    if (!p) { std::cout << "Cannot add null Basil\n";
            throw std::runtime_error("tried to add null"); 
            return; }
    if(lower(p->getName()) == "basil"){
        Basils.push_back(p);
        std::cout << "Added Basil to Basils in Inventory"<< '\n';
        }
    else{
        std::cout << "Plant is NOT a Basil";
    }
}
Plant* Inventory::removeBasil() {
    if (Basils.empty()) {
        std::cout << "No Basils to remove\n";
        throw std::runtime_error("tried to remove null"); 

        return nullptr;
    }
    Plant* removed = Basils.back();
    Basils.pop_back();
    return removed;
}

bool Inventory::isMintsEmpty() const { return Mints.empty(); }
void Inventory::addMint(Plant* p) {
    if (!p) { std::cout << "Cannot add null Mint\n";
        throw std::runtime_error("tried to add null"); 
        return; }
    if(lower(p->getName()) == "mint"){
    Mints.push_back(p);
    std::cout << "Added Mint to Mints in Inventory"<< '\n';
    }
    else{
        std::cout << "Plant is NOT a Mint";
    }
}
Plant* Inventory::removeMint() {
    if (Mints.empty()) {
        std::cout << "No Mints to remove\n";
        throw std::runtime_error("tried to remove null"); 
        return nullptr;
    }
    Plant* removed = Mints.back();
    Mints.pop_back();
    return removed;
}

bool Inventory::isParsleysEmpty() const { return Parsleys.empty(); }
void Inventory::addParsley(Plant* p) {
    if (!p) { std::cout << "Cannot add null Parsley\n";
        throw std::runtime_error("tried to add null"); 
        return; }
    if(lower(p->getName()) == "parsley"){
    Parsleys.push_back(p);
    std::cout << "Added Parsley to Parsleys in Inventory"<< '\n';
    }
    else{
        std::cout << "Plant is NOT a Parsley";
    }
}
Plant* Inventory::removeParsley() {
    if (Parsleys.empty()) {
        std::cout << "No Parsleys to remove\n";
        throw std::runtime_error("tried to remove null"); 
        return nullptr;
    }
    Plant* removed = Parsleys.back();
    Parsleys.pop_back();
    return removed;
}

bool Inventory::isCoriandersEmpty() const { return Corianders.empty(); }
void Inventory::addCoriander(Plant* p) {
    if (!p) { std::cout << "Cannot add null Coriander\n";
        throw std::runtime_error("tried to add null");         
        return; }
    if(lower(p->getName()) == "coriander"){
    Corianders.push_back(p);
    std::cout << "Added Coriander to Corianders in Inventory"<< '\n';
    }
    else{
        std::cout << "Plant is NOT a Coriander";
    }
}
Plant* Inventory::removeCoriander() {
    if (Corianders.empty()) {
        std::cout << "No Corianders to remove\n";
        throw std::runtime_error("tried to remove null"); 

        return nullptr;
    }
    Plant* removed = Corianders.back();
    Corianders.pop_back();
    return removed;
}

bool Inventory::isLavendersEmpty() const { return Lavenders.empty(); }
void Inventory::addLavender(Plant* p) {
    if (!p) { std::cout << "Cannot add null Lavender\n";
            throw std::runtime_error("tried to add null"); 
            return; }
    if(lower(p->getName()) == "lavender"){
    Lavenders.push_back(p);
    std::cout << "Added Lavender to Lavenders in Inventory"<< '\n';
    }
    else{
        std::cout << "Plant is NOT a Lavender";
    }
}
Plant* Inventory::removeLavender() {
    if (Lavenders.empty()) {
        std::cout << "No Lavenders to remove\n";
        throw std::runtime_error("tried to remove null"); 

        return nullptr;
    }
    Plant* removed = Lavenders.back();
    Lavenders.pop_back();
    return removed;
}

bool Inventory::isRosemaryEmpty() const { return Rosemary.empty(); }
void Inventory::addRosemary(Plant* p) {
    if (!p) { std::cout << "Cannot add null Rosemary\n";
            throw std::runtime_error("tried to add null"); 
            return; }
    if(lower(p->getName()) == "rosemary"){
    Rosemary.push_back(p);
    std::cout << "Added Rosemary to Rosemary in Inventory"<< '\n';
    }
    else{
        std::cout << "Plant is NOT a Rosemary";
    }
}
Plant* Inventory::removeRosemary() {
    if (Rosemary.empty()) {
        std::cout << "No Rosemary to remove\n";
        throw std::runtime_error("tried to remove null"); 

        return nullptr;
    }
    Plant* removed = Rosemary.back();
    Rosemary.pop_back();
    return removed;
}

bool Inventory::isLemonBalmsEmpty() const { return LemonBalms.empty(); }
void Inventory::addLemonBalm(Plant* p) {
    if (!p) { std::cout << "Cannot add null LemonBalm\n";
            throw std::runtime_error("tried to add null"); 
            return; }
    if(lower(p->getName()) == "lemonbalm"){
    LemonBalms.push_back(p);
    std::cout << "Added LemonBalm to LemonBalms in Inventory"<< '\n';
    }
    else{
        std::cout << "Plant is NOT a LemonBalm";
    }
}
Plant* Inventory::removeLemonBalm() {
    if (LemonBalms.empty()) {
        std::cout << "No LemonBalms to remove\n";
        throw std::runtime_error("tried to remove null"); 
        return nullptr;
    }
    Plant* removed = LemonBalms.back();
    LemonBalms.pop_back();
    return removed;
}

////////////////////////
// Trees & Shrubs
////////////////////////

bool Inventory::isHibiscusEmpty() const { return Hibiscus.empty(); }
void Inventory::addHibiscus(Plant* p) {
    if (!p) { std::cout << "Cannot add null Hibiscus\n";
        throw std::runtime_error("tried to add null"); 
        return; 
    }
    if(lower(p->getName()) == "hibiscus"){
    Hibiscus.push_back(p);
    std::cout << "Added Hibiscus to Hibiscus in Inventory"<< '\n';
    }
    else{
        std::cout << "Plant is NOT a Hibiscus";
    }
}
Plant* Inventory::removeHibiscus() {
    if (Hibiscus.empty()) {
        std::cout << "No Hibiscus to remove\n";
        throw std::runtime_error("tried to remove null"); 
        return nullptr;
    }
    Plant* removed = Hibiscus.back();
    Hibiscus.pop_back();
    return removed;
}

bool Inventory::isHydrangeaEmpty() const { return Hydrangea.empty(); }
void Inventory::addHydrangea(Plant* p) {
    if (!p) { std::cout << "Cannot add null Hydrangea\n";
        throw std::runtime_error("tried to add null");  
        return; }
    if(lower(p->getName()) == "hydrangea"){
    Hydrangea.push_back(p);
    std::cout << "Added Hydrangea to Hydrangea in Inventory"<< '\n';
    }
    else{
        std::cout << "Plant is NOT a Hydrangea";
    }
}
Plant* Inventory::removeHydrangea() {
    if (Hydrangea.empty()) {
        std::cout << "No Hydrangea to remove\n";
        throw std::runtime_error("tried to remove null"); 
        return nullptr;
    }
    Plant* removed = Hydrangea.back();
    Hydrangea.pop_back();
    return removed;
}

bool Inventory::isBoxwoodEmpty() const { return Boxwood.empty(); }
void Inventory::addBoxwood(Plant* p) {
    if (!p) { std::cout << "Cannot add null Boxwood\n";
            throw std::runtime_error("tried to add null"); 
            return; }
    if(lower(p->getName()) == "boxwood"){
    Boxwood.push_back(p);
    std::cout << "Added Boxwood to Boxwood in Inventory"<< '\n';
    }
    else{
        std::cout << "Plant is NOT a Boxwood";
    }
}
Plant* Inventory::removeBoxwood() {
    if (Boxwood.empty()) {
        std::cout << "No Boxwood to remove\n";
        throw std::runtime_error("tried to remove null"); 
        return nullptr;
    }
    Plant* removed = Boxwood.back();
    Boxwood.pop_back();
    return removed;
}

bool Inventory::isOakEmpty() const { return Oak.empty(); }
void Inventory::addOak(Plant* p) {
    if (!p) { std::cout << "Cannot add null Oak\n";
                throw std::runtime_error("tried to add null"); 
                return; }
    if(lower(p->getName()) == "oak"){
    Oak.push_back(p);
    std::cout << "Added Oak to Oak in Inventory"<< '\n';
    }
    else{
        std::cout << "Plant is NOT a Oak";
    }
}
Plant* Inventory::removeOak() {
    if (Oak.empty()) {
        std::cout << "No Oak to remove\n";
        throw std::runtime_error("tried to remove null"); 
        return nullptr;
    }
    Plant* removed = Oak.back();
    Oak.pop_back();
    return removed;
}

bool Inventory::isBaobabEmpty() const { return Baobab.empty(); }
void Inventory::addBaobab(Plant* p) {
    if (!p) { std::cout << "Cannot add null Baobab\n";
                throw std::runtime_error("tried to add null"); 
                return; }
    if(lower(p->getName()) == "baobab"){
    Baobab.push_back(p);
    std::cout << "Added Baobab to Baobab in Inventory"<< '\n';
    }
    else{
        std::cout << "Plant is NOT a Baobab";
    }
}
Plant* Inventory::removeBaobab() {
    if (Baobab.empty()) {
        std::cout << "No Baobab to remove\n";
        throw std::runtime_error("tried to remove null"); 
        return nullptr;
    }
    Plant* removed = Baobab.back();
    Baobab.pop_back();
    return removed;
}

////////////////////////
// Seeds
////////////////////////

bool Inventory::isSeedsEmpty() const { return seeds.empty(); }
void Inventory::addSeed(Plant* p) {
    if (!p) { 
        std::cout << "Cannot add null Seed\n"; 
        throw std::runtime_error("tried to add null"); 
        return; }
    if(lower(p->getStateName()) == "seedling"){
    seeds.push_back(p);
    std::cout << "Added Seed to Seeds in Inventory"<< '\n';
    }
    else{
        std::cout << "Plant is NOT a seed";
    }
}
Plant* Inventory::removeSeed(const std::string& type) {
    if (type.empty() || type.length() == 0) { 
        std::cout << "Cannot remove seed with empty type\n"; 
        throw std::runtime_error("tried to remove null"); 
        return nullptr; 
    }
    
    for (auto it = seeds.begin(); it != seeds.end(); ++it) {
        if (lower((*it)->getName()) == lower(type)) {
            Plant* removed = *it;
            seeds.erase(it);
            std::cout << "Removed seed of type: " << type << '\n';
            return removed;
        }
    }
    
    std::cout << "No seed found of type: " << type << '\n';
    throw std::runtime_error("tried to remove nonexistent seed"); 

    return nullptr;
}

PlantIterator* Inventory::createIterator(const std::string& category) {
    // Pass the category string to PlantIterator constructor
    return new PlantIterator(category);
}

 Plant* Inventory::removeRose(Plant* p){
        auto it = std::find(Roses.begin(), Roses.end(), p);
        if (it != Roses.end()) {
            Roses.erase(it);
            return p;
        }
        return nullptr; // Return nullptr if the plant was not found
    }

Plant* Inventory::removeDaisy(Plant* p){
        auto it = std::find(Daisies.begin(), Daisies.end(), p);
        if (it != Daisies.end()) {
            Daisies.erase(it);
            return p;
        }
        return nullptr; // Return nullptr if the plant was not found
    }
Plant* Inventory::removeTulip(Plant* p){
        auto it = std::find(Tulips.begin(), Tulips.end(), p);
        if (it != Tulips.end()) {
            Tulips.erase(it);
            return p;
        }
        return nullptr; // Return nullptr if the plant was not found
    }
Plant* Inventory::removeSucculent(Plant* p){
        auto it = std::find(Succulents.begin(), Succulents.end(), p);
        if (it != Succulents.end()) {
            Succulents.erase(it);
            return p;
        }
        return nullptr; // Return nullptr if the plant was not found
    }
Plant* Inventory::removeCactus(Plant* p){
        auto it = std::find(Cactuses.begin(), Cactuses.end(), p);
        if (it != Cactuses.end()) {
            Cactuses.erase(it);
            return p;
        }
        return nullptr; // Return nullptr if the plant was not found
    }
Plant* Inventory::removeBasil(Plant* p){
        auto it = std::find(Basils.begin(), Basils.end(), p);
        if (it != Basils.end()) {   
            Basils.erase(it);
            return p;
        }
        return nullptr; // Return nullptr if the plant was not found
    }
Plant* Inventory::removeMint(Plant* p){
        auto it = std::find(Mints.begin(), Mints.end(), p);
        if (it != Mints.end()) {
            Mints.erase(it);
            return p;
        }
        return nullptr; // Return nullptr if the plant was not found
    }
Plant* Inventory::removeParsley(Plant* p){
        auto it = std::find(Parsleys.begin(), Parsleys.end(), p);
        if (it != Parsleys.end()) {
            Parsleys.erase(it);
            return p;
        }
        return nullptr; // Return nullptr if the plant was not found
    }
Plant* Inventory::removeCoriander(Plant* p){
        auto it = std::find(Corianders.begin(), Corianders.end(), p);
        if (it != Corianders.end()) {
            Corianders.erase(it);
            return p;  
        }
        return nullptr; // Return nullptr if the plant was not found
    }
Plant* Inventory::removeLavender(Plant* p){
        auto it = std::find(Lavenders.begin(), Lavenders.end(), p);
        if (it != Lavenders.end()) {
            Lavenders.erase(it);
            return p;
        }
        return nullptr; // Return nullptr if the plant was not found
    }
Plant* Inventory::removeRosemary(Plant* p){ 
        auto it = std::find(Rosemary.begin(), Rosemary.end(), p);
        if (it != Rosemary.end()) {
            Rosemary.erase(it);
            return p;
        }
        return nullptr; // Return nullptr if the plant was not found
    }
Plant* Inventory::removeLemonBalm(Plant* p){
        auto it = std::find(LemonBalms.begin(), LemonBalms.end(), p);
        if (it != LemonBalms.end()) {
            LemonBalms.erase(it);
            return p;
        }
        return nullptr; // Return nullptr if the plant was not found
    }
Plant* Inventory::removeHibiscus(Plant* p){ 
        auto it = std::find(Hibiscus.begin(), Hibiscus.end(), p);
        if (it != Hibiscus.end()) {
            Hibiscus.erase(it);
            return p;
        }
        return nullptr; // Return nullptr if the plant was not found
    }
Plant* Inventory::removeHydrangea(Plant* p){
        auto it = std::find(Hydrangea.begin(), Hydrangea.end(), p);
        if (it != Hydrangea.end()) {
            Hydrangea.erase(it);
            return p;
        }
        return nullptr; // Return nullptr if the plant was not found
    }
Plant* Inventory::removeBoxwood(Plant* p){
        auto it = std::find(Boxwood.begin(), Boxwood.end(), p);
        if (it != Boxwood.end()) {
            Boxwood.erase(it);
            return p;
        }
        return nullptr; // Return nullptr if the plant was not found
    }
Plant* Inventory::removeOak(Plant* p){
        auto it = std::find(Oak.begin(), Oak.end(), p);
        if (it != Oak.end()) {
            Oak.erase(it);
            return p;
        }
        return nullptr; // Return nullptr if the plant was not found
    }
Plant* Inventory::removeBaobab(Plant* p){
        auto it = std::find(Baobab.begin(), Baobab.end(), p);
        if (it != Baobab.end()) {
            Baobab.erase(it);
            return p;
        }
        return nullptr; // Return nullptr if the plant was not found
    }   
    