#include "Plant.h"
#include "Seedling.h"
#include "CareStrategy.h"
#include "Withered.h"

inline std::string toLowerCase(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), 
                   [](unsigned char c){ return std::tolower(c); });
    return str;
}

// Plant::Plant(const string& plantName = "Unknown", const string& plantType = "Generic", CareStrategy strat = NULL)  
Plant::Plant(const string& plantName, const string& plantType)  
    : name(plantName), type(plantType), state(new Seedling()), zone(nullptr), ageDays(0), hydrationLevel(0),
    status(nullptr), lastReturnReason(""), height(0), fertiliserAmount(0), timesWatered(0) {
        
        fDec = 15;
        hBoost = 2;
        hInc = 5;
        gInterval = 5.0f;
        aInterval = 20.0f;
        if(toLowerCase(plantType).compare("flowers") != std::string::npos){
            // high care
            wDec = 20;
        }
        else if(toLowerCase(plantType).compare("herbs&aromatics") != std::string::npos){
            // medium care
            wDec = 10;
        }
        else{
            // low care
            wDec = 5;
            if(toLowerCase(plantName).compare("baobab") != std::string::npos ||
            toLowerCase(plantName).compare("oak") != std::string::npos){
                hInc = 12;
            }
        }
}


void Plant::dailyTick() 
{
    // Need to increase height (decrement water, fertiliser)
    if(!status){
        if(hTimer.getElapsedTime().asSeconds() >= gInterval){
            height += hInc * ((fertiliserAmount > 0) ? hBoost : 1);
            hydrationLevel -= wDec;
            fertiliserAmount -= fDec;
            if(needsWatering() && needsFertilizing()){
                zone->getStrategy()->care();
            }

            hTimer.restart();
        }
    }

    if(aTimer.getElapsedTime().asSeconds() >= aInterval){
        ageDays++;
        if(ageDays > 16)
            setState(new Withered());
        aTimer.restart();
    }
}


Plant::Plant(const Plant& plant){
    this->name = plant.getName();
    this->type = plant.getType();
    this->state = new Seedling();
    this->zone = nullptr;
    this->ageDays = 0;
    this->hydrationLevel = 0;
    this->lastReturnReason = "";
    this->fertiliserAmount = 0;
    this->status = nullptr;
    this->fDec = plant.fDec;
    this->wDec = plant.wDec;
    this->hBoost = plant.hBoost;
    this->height = 0;
    this->timesWatered = 0;
    this->hInc = plant.hInc;
}

Plant::~Plant()
{
    delete state;
    delete status;
}

void Plant::setZone(Zone *zone)
{
    this->zone = zone;
}

void Plant::initState(PlantState *initialState)
{
    if (state)
    {
        delete state;
    }
    state = initialState;
}

string Plant::getName() const
{
    return name;
}

string Plant::getStateName() const
{
    return state->getStateName();
}

string Plant::getType() const
{
    return type;
}

int Plant::getAgeDays() const
{
    return ageDays;
}

int Plant::getHydrationLevel() const
{
    return hydrationLevel;
}

int Plant::getHeight() const {return height;}

int Plant::getFertiliserAmount() const {return fertiliserAmount;}

int Plant::getTimesWatered() const {return timesWatered;}

void Plant::setState(PlantState *newState)
{
    if (state)
    {
        delete state;
    }
    state = newState;

    if (zone && isMature()){
        zone->notify();
    }
    else if (state->getStateName() == "Withered"){
        notify();
    }
}

void Plant::display() const 
{
    std::cout << "🌿 " << name << " (" << type << ") - State: " << getStateName();
        if (zone) {
            std::cout << " [Zone: " << zone->getZoneName() << "]";
            std::cout << std::endl;
        }
}

void Plant::water(int amount) 
{
    // hydrationLevel = std::min(100, hydrationLevel + 50);
    timesWatered++;
    hydrationLevel += std::min(100, amount);
    state->water(this, amount);
}

void Plant::fertilize(int amount) 
{
    fertiliserAmount += amount;
    state->fertilize(this, amount);
}

bool Plant::needsWatering() const{
    return hydrationLevel < 30; // Default threshold
}

bool Plant::needsFertilizing() const {
    return fertiliserAmount < 45; // Default: needs fertilizing every 7 days
} 

bool Plant::isMature() const {
    return state->getStateName() == "Mature";
}

Greenhouse* Plant::clone(){
    return new Plant(*this);
}

void Plant::notify()
{
    for (auto observer : observers)
    {
        observer->update(this);
    }
}

// functionality added for status
void Plant::setStatus(PlantStatus *newStatus)
{
    PlantStatus* old = status;

    status = newStatus;

    if(status){
        status->enter(*this);
    }
    delete old;
}

void Plant::sell()
{
    if (status)
        status->onSell(*this);
}

void Plant::returnPlant(const std::string &reason)
{
    if (status)
        status->onReturn(*this, reason);
}

string Plant::getStatus() const
{
    return status ? status->code() : "UNKNOWN";
}

void Plant::setLastReturnReason(const std::string &r)
{
    lastReturnReason = r;
}

const std::string &Plant::getLastReturnReason() const
{
    return lastReturnReason;
}

void Plant::execute(){}