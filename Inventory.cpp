#include "Inventory.h"
#include "PlantIterator.h"
#include "Plant.h"

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
    if (!p) { std::cout << "Cannot add null Rose\n"; return; }

    if(lower(p->getName()) == "rose"){
    Roses.push_back(p);
    std::cout << "Added Rose to Roses in Inventory"<< '\n';
    }
    else{
        std::cout << "Added plant is NOT a Rose";
    }
};

Plant* Inventory::removeRose(Plant* p) {
    if (!p) { std::cout << "Cannot remove null Rose\n"; return nullptr; }
    auto it = std::find(Roses.begin(), Roses.end(), p);
    if (it != Roses.end()) { Plant* removed = *it; Roses.erase(it); return removed; }
    return nullptr;
}

bool Inventory::isDaisiesEmpty() const { return Daisies.empty(); }
void Inventory::addDaisy(Plant* p) {
    if (!p) { std::cout << "Cannot add null Daisy\n"; return; }
    if(lower(p->getName()) == "daisy"){
    Daisies.push_back(p);
    std::cout << "Added Daisy to Dasies in Inventory"<< '\n';
    }
    else{
        std::cout << "Added plant is NOT a Daisy";
    }
}
Plant* Inventory::removeDaisy(Plant* p) {
    if (!p) { std::cout << "Cannot remove null Daisy\n"; return nullptr; }
    auto it = std::find(Daisies.begin(), Daisies.end(), p);
    if (it != Daisies.end()) { Plant* removed = *it; Daisies.erase(it); return removed; }
    return nullptr;
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
Plant* Inventory::removeTulip(Plant* p) {
    if (!p) { std::cout << "Cannot remove null Tulip\n"; return nullptr; }
    auto it = std::find(Tulips.begin(), Tulips.end(), p);
    if (it != Tulips.end()) { Plant* removed = *it; Tulips.erase(it); return removed; }
    return nullptr;
}

////////////////////////
// Succulents & Cactuses
////////////////////////

bool Inventory::isSucculentsEmpty() const { return Succulents.empty(); }
void Inventory::addSucculent(Plant* p) {
    if (!p) { std::cout << "Cannot add null Succulent\n"; return; }
    if(lower(p->getName()) == "succulent"){
    Succulents.push_back(p);
    std::cout << "Added Succulent to Succulents in Inventory"<< '\n';
    }
    else{
        std::cout << "Added plant is NOT a Succulent";
    }
}
Plant* Inventory::removeSucculent(Plant* p) {
    if (!p) { std::cout << "Cannot remove null Succulent\n"; return nullptr; }
    auto it = std::find(Succulents.begin(), Succulents.end(), p);
    if (it != Succulents.end()) { Plant* removed = *it; Succulents.erase(it); return removed; }
    return nullptr;
}

bool Inventory::isCactusesEmpty() const { return Cactuses.empty(); }
void Inventory::addCactus(Plant* p) {
    if (!p) { std::cout << "Cannot add null Cactus\n"; return; }
    if(lower(p->getName()) == "cactus"){
    Cactuses.push_back(p);
    std::cout << "Added Cactus to Cactuses in Inventory"<< '\n';
    }
    else{
        std::cout << "Plant is NOT a Cactus";
    }
}
Plant* Inventory::removeCactus(Plant* p) {
    if (!p) { std::cout << "Cannot remove null Cactus\n"; return nullptr; }
    auto it = std::find(Cactuses.begin(), Cactuses.end(), p);
    if (it != Cactuses.end()) { Plant* removed = *it; Cactuses.erase(it); return removed; }
    return nullptr;
}

////////////////////////
// Herbs & Aromatics
////////////////////////

bool Inventory::isBasilsEmpty() const { return Basils.empty(); }
void Inventory::addBasil(Plant* p) {
    if (!p) { std::cout << "Cannot add null Basil\n"; return; }
   if(lower(p->getName()) == "basil"){
    Basils.push_back(p);
    std::cout << "Added Basil to Basils in Inventory"<< '\n';
    }
    else{
        std::cout << "Plant is NOT a Basil";
    }
}
Plant* Inventory::removeBasil(Plant* p) {
    if (!p) { std::cout << "Cannot remove null Basil\n"; return nullptr; }
    auto it = std::find(Basils.begin(), Basils.end(), p);
    if (it != Basils.end()) { Plant* removed = *it; Basils.erase(it); return removed; }
    return nullptr;
}

bool Inventory::isMintsEmpty() const { return Mints.empty(); }
void Inventory::addMint(Plant* p) {
    if (!p) { std::cout << "Cannot add null Mint\n"; return; }
    if(lower(p->getName()) == "mint"){
    Mints.push_back(p);
    std::cout << "Added Mint to Mints in Inventory"<< '\n';
    }
    else{
        std::cout << "Plant is NOT a Mint";
    }
}
Plant* Inventory::removeMint(Plant* p) {
    if (!p) { std::cout << "Cannot remove null Mint\n"; return nullptr; }
    auto it = std::find(Mints.begin(), Mints.end(), p);
    if (it != Mints.end()) { Plant* removed = *it; Mints.erase(it); return removed; }
    return nullptr;
}

bool Inventory::isParsleysEmpty() const { return Parsleys.empty(); }
void Inventory::addParsley(Plant* p) {
    if (!p) { std::cout << "Cannot add null Parsley\n"; return; }
    if(lower(p->getName()) == "parsley"){
    Parsleys.push_back(p);
    std::cout << "Added Parsley to Parsleys in Inventory"<< '\n';
    }
    else{
        std::cout << "Plant is NOT a Parsley";
    }
}
Plant* Inventory::removeParsley(Plant* p) {
    if (!p) { std::cout << "Cannot remove null Parsley\n"; return nullptr; }
    auto it = std::find(Parsleys.begin(), Parsleys.end(), p);
    if (it != Parsleys.end()) { Plant* removed = *it; Parsleys.erase(it); return removed; }
    return nullptr;
}

bool Inventory::isCoriandersEmpty() const { return Corianders.empty(); }
void Inventory::addCoriander(Plant* p) {
    if (!p) { std::cout << "Cannot add null Coriander\n"; return; }
    if(lower(p->getName()) == "coriander"){
    Corianders.push_back(p);
    std::cout << "Added Coriander to Corianders in Inventory"<< '\n';
    }
    else{
        std::cout << "Plant is NOT a Coriander";
    }
}
Plant* Inventory::removeCoriander(Plant* p) {
    if (!p) { std::cout << "Cannot remove null Coriander\n"; return nullptr; }
    auto it = std::find(Corianders.begin(), Corianders.end(), p);
    if (it != Corianders.end()) { Plant* removed = *it; Corianders.erase(it); return removed; }
    return nullptr;
}

bool Inventory::isLavendersEmpty() const { return Lavenders.empty(); }
void Inventory::addLavender(Plant* p) {
    if (!p) { std::cout << "Cannot add null Lavender\n"; return; }
    if(lower(p->getName()) == "lavender"){
    Lavenders.push_back(p);
    std::cout << "Added Lavender to Lavenders in Inventory"<< '\n';
    }
    else{
        std::cout << "Plant is NOT a Lavender";
    }
}
Plant* Inventory::removeLavender(Plant* p) {
    if (!p) { std::cout << "Cannot remove null Lavender\n"; return nullptr; }
    auto it = std::find(Lavenders.begin(), Lavenders.end(), p);
    if (it != Lavenders.end()) { Plant* removed = *it; Lavenders.erase(it); return removed; }
    return nullptr;
}

bool Inventory::isRosemaryEmpty() const { return Rosemary.empty(); }
void Inventory::addRosemary(Plant* p) {
    if (!p) { std::cout << "Cannot add null Rosemary\n"; return; }
    if(lower(p->getName()) == "rosemary"){
    Rosemary.push_back(p);
    std::cout << "Added Rosemary to Rosemary in Inventory"<< '\n';
    }
    else{
        std::cout << "Plant is NOT a Rosemary";
    }
}
Plant* Inventory::removeRosemary(Plant* p) {
    if (!p) { std::cout << "Cannot remove null Rosemary\n"; return nullptr; }
    auto it = std::find(Rosemary.begin(), Rosemary.end(), p);
    if (it != Rosemary.end()) { Plant* removed = *it; Rosemary.erase(it); return removed; }
    return nullptr;
}

bool Inventory::isLemonBalmsEmpty() const { return LemonBalms.empty(); }
void Inventory::addLemonBalm(Plant* p) {
    if (!p) { std::cout << "Cannot add null LemonBalm\n"; return; }
    if(lower(p->getName()) == "lemonbalm"){
    LemonBalms.push_back(p);
    std::cout << "Added LemonBalm to LemonBalms in Inventory"<< '\n';
    }
    else{
        std::cout << "Plant is NOT a LemonBalm";
    }
}
Plant* Inventory::removeLemonBalm(Plant* p) {
    if (!p) { std::cout << "Cannot remove null LemonBalm\n"; return nullptr; }
    auto it = std::find(LemonBalms.begin(), LemonBalms.end(), p);
    if (it != LemonBalms.end()) { Plant* removed = *it; LemonBalms.erase(it); return removed; }
    return nullptr;
}

////////////////////////
// Trees & Shrubs
////////////////////////

bool Inventory::isHibiscusEmpty() const { return Hibiscus.empty(); }
void Inventory::addHibiscus(Plant* p) {
    if (!p) { std::cout << "Cannot add null Hibiscus\n"; return; }
    if(lower(p->getName()) == "hibiscus"){
    Hibiscus.push_back(p);
    std::cout << "Added Hibiscus to Hibiscus in Inventory"<< '\n';
    }
    else{
        std::cout << "Plant is NOT a Hibiscus";
    }
}
Plant* Inventory::removeHibiscus(Plant* p) {
    if (!p) { std::cout << "Cannot remove null Hibiscus\n"; return nullptr; }
    auto it = std::find(Hibiscus.begin(), Hibiscus.end(), p);
    if (it != Hibiscus.end()) { Plant* removed = *it; Hibiscus.erase(it); return removed; }
    return nullptr;
}

bool Inventory::isHydrangeaEmpty() const { return Hydrangea.empty(); }
void Inventory::addHydrangea(Plant* p) {
    if (!p) { std::cout << "Cannot add null Hydrangea\n"; return; }
    if(lower(p->getName()) == "hydrangea"){
    Hydrangea.push_back(p);
    std::cout << "Added Hydrangea to Hydrangea in Inventory"<< '\n';
    }
    else{
        std::cout << "Plant is NOT a Hydrangea";
    }
}
Plant* Inventory::removeHydrangea(Plant* p) {
    if (!p) { std::cout << "Cannot remove null Hydrangea\n"; return nullptr; }
    auto it = std::find(Hydrangea.begin(), Hydrangea.end(), p);
    if (it != Hydrangea.end()) { Plant* removed = *it; Hydrangea.erase(it); return removed; }
    return nullptr;
}

bool Inventory::isBoxwoodEmpty() const { return Boxwood.empty(); }
void Inventory::addBoxwood(Plant* p) {
    if (!p) { std::cout << "Cannot add null Boxwood\n"; return; }
    if(lower(p->getName()) == "boxwood"){
    Boxwood.push_back(p);
    std::cout << "Added Boxwood to Boxwood in Inventory"<< '\n';
    }
    else{
        std::cout << "Plant is NOT a Boxwood";
    }
}
Plant* Inventory::removeBoxwood(Plant* p) {
    if (!p) { std::cout << "Cannot remove null Boxwood\n"; return nullptr; }
    auto it = std::find(Boxwood.begin(), Boxwood.end(), p);
    if (it != Boxwood.end()) { Plant* removed = *it; Boxwood.erase(it); return removed; }
    return nullptr;
}

bool Inventory::isOakEmpty() const { return Oak.empty(); }
void Inventory::addOak(Plant* p) {
    if (!p) { std::cout << "Cannot add null Oak\n"; return; }
    if(lower(p->getName()) == "oak"){
    Oak.push_back(p);
    std::cout << "Added Oak to Oak in Inventory"<< '\n';
    }
    else{
        std::cout << "Plant is NOT a Oak";
    }
}
Plant* Inventory::removeOak(Plant* p) {
    if (!p) { std::cout << "Cannot remove null Oak\n"; return nullptr; }
    auto it = std::find(Oak.begin(), Oak.end(), p);
    if (it != Oak.end()) { Plant* removed = *it; Oak.erase(it); return removed; }
    return nullptr;
}

bool Inventory::isBaobabEmpty() const { return Baobab.empty(); }
void Inventory::addBaobab(Plant* p) {
    if (!p) { std::cout << "Cannot add null Baobab\n"; return; }
    if(lower(p->getName()) == "baobab"){
    Baobab.push_back(p);
    std::cout << "Added Baobab to Baobab in Inventory"<< '\n';
    }
    else{
        std::cout << "Plant is NOT a Baobab";
    }
}
Plant* Inventory::removeBaobab(Plant* p) {
    if (!p) { std::cout << "Cannot remove null Baobab\n"; return nullptr; }
    auto it = std::find(Baobab.begin(), Baobab.end(), p);
    if (it != Baobab.end()) { Plant* removed = *it; Baobab.erase(it); return removed; }
    return nullptr;
}

////////////////////////
// Seeds
////////////////////////

bool Inventory::isSeedsEmpty() const { return seeds.empty(); }
void Inventory::addSeed(Plant* p) {
    if (!p) { std::cout << "Cannot add null Seed\n"; return; }
    if(lower(p->getStateName()) == "seedling"){
    seeds.push_back(p);
    std::cout << "Added Seed to Seeds in Inventory"<< '\n';
    }
    else{
        std::cout << "Plant is NOT a seed";
    }
}
Plant* Inventory::removeSeed(const std::string& type) {
    if (type.empty()) { 
        std::cout << "Cannot remove seed with empty type\n"; 
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
    return nullptr;
}

PlantIterator* Inventory::createIterator(std::vector<Plant*>* x){
    return new PlantIterator(x);
}