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


///////////////////////
// Flowers
///////////////////////

bool Inventory::isRosesEmpty() const { return Roses.empty(); }
void Inventory::addRose(Plant* p) {
    if (!p) { std::cout << "Cannot add null Rose\n"; return; }
    Roses.push_back(p);
    std::cout << "Added Rose: " << p->getType() << '\n';
}
Plant* Inventory::removeRose(Plant* p) {
    if (!p) { std::cout << "Cannot remove null Rose\n"; return nullptr; }
    auto it = std::find(Roses.begin(), Roses.end(), p);
    if (it != Roses.end()) { Plant* removed = *it; Roses.erase(it); return removed; }
    return nullptr;
}

bool Inventory::isDaisiesEmpty() const { return Daisies.empty(); }
void Inventory::addDaisy(Plant* p) {
    if (!p) { std::cout << "Cannot add null Daisy\n"; return; }
    Daisies.push_back(p);
    std::cout << "Added Daisy: " << p->getType() << '\n';
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
    Tulips.push_back(p);
    std::cout << "Added Tulip: " << p->getType() << '\n';
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
    Succulents.push_back(p);
    std::cout << "Added Succulent: " << p->getType() << '\n';
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
    Cactuses.push_back(p);
    std::cout << "Added Cactus: " << p->getType() << '\n';
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
    Basils.push_back(p);
    std::cout << "Added Basil: " << p->getType() << '\n';
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
    Mints.push_back(p);
    std::cout << "Added Mint: " << p->getType() << '\n';
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
    Parsleys.push_back(p);
    std::cout << "Added Parsley: " << p->getType() << '\n';
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
    Corianders.push_back(p);
    std::cout << "Added Coriander: " << p->getType() << '\n';
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
    Lavenders.push_back(p);
    std::cout << "Added Lavender: " << p->getType() << '\n';
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
    Rosemary.push_back(p);
    std::cout << "Added Rosemary: " << p->getType() << '\n';
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
    LemonBalms.push_back(p);
    std::cout << "Added LemonBalm: " << p->getType() << '\n';
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
    Hibiscus.push_back(p);
    std::cout << "Added Hibiscus: " << p->getType() << '\n';
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
    Hydrangea.push_back(p);
    std::cout << "Added Hydrangea: " << p->getType() << '\n';
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
    Boxwood.push_back(p);
    std::cout << "Added Boxwood: " << p->getType() << '\n';
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
    Oak.push_back(p);
    std::cout << "Added Oak: " << p->getType() << '\n';
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
    Baobab.push_back(p);
    std::cout << "Added Baobab: " << p->getType() << '\n';
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
    seeds.push_back(p);
    std::cout << "Added Seed: " << p->getType() << '\n';
}
Plant* Inventory::removeSeed(Plant* p) {
    if (!p) { std::cout << "Cannot remove null Seed\n"; return nullptr; }
    auto it = std::find(seeds.begin(), seeds.end(), p);
    if (it != seeds.end()) { Plant* removed = *it; seeds.erase(it); return removed; }
    return nullptr;
}

PlantIterator* Inventory::createIterator(std::vector<Plant*>* x){
    return new PlantIterator(x);
}