#include "Zone.h"
#include "Plant.h"
#include "LowCare.h"
#include "MediumCare.h"
#include "HighCare.h"

void Zone::add(Greenhouse* child) {
    if (!child) {
        throw std::invalid_argument("Cannot add null child to Zone");
    }

    // if zoneCategory is non-empty enforce matching types (adjust policy as needed)
    if (!zoneCategory.empty() && static_cast<Plant*>(child)->getType() != zoneCategory) {
        throw std::invalid_argument("Cannot add child with type '" + static_cast<Plant*>(child)->getType()
                                  + "' to zone with category '" + zoneCategory + "'");
    }

    children.push_back(child);
}

void Zone::remove(Greenhouse* child) {
    auto it = std::find(children.begin(), children.end(), child);
    if (it == children.end()) {
        throw std::runtime_error("Child not found in Zone");
    }
    children.erase(it);
}

Greenhouse* Zone::getChild(std::size_t index) {
    if (index >= children.size()) {
        throw std::out_of_range("Index out of range in Zone::getChild");
    }
    return children[index];
}

const std::vector<Greenhouse*>& Zone::getChildren() const {
    return children;
}

bool Zone::isComposite() const {
    return true;
}

void Zone::execute() {
    // Execute operation on all children
    for (auto* child : children) {
        if (child) {
            child->execute();
        }
    }
    this->strategy->care();
}

Zone::Zone(std::string Z_Name, std::string C_Name, CareStaff *s) : zoneName(Z_Name), zoneCategory(C_Name), strategy(nullptr),staff(s) {
    this->strategy = new HighCare(this, this->staff);
}

void Zone::setZoneName(std::string name){
        this->zoneName = name;
    }

std::string Zone::getZoneName(){
        return this->zoneName;
}

void Zone::setZoneCategory(std::string category){
        this->zoneCategory = category;
}

std::string Zone::getZoneCategory(){
    return this->zoneCategory;
}

CareStrategy *Zone::getStrategy(){ return this->strategy;}

void Zone::setStrategy(CareStrategy *strategy){
    if (!strategy){
        return;
    }
    else{
        if (this->strategy)
        {
            delete this->strategy;
        }
        this->strategy = strategy;
    }
}

void Zone::setStaff(CareStaff *staff){
    if (staff){
        this->staff = staff;
    }
    
}

Zone::~Zone(){
    delete this->strategy;
    for (std::vector<Greenhouse*>::iterator it = children.begin(); it != children.end(); ++it){
        if (*it)
            delete *it;
    }
}
