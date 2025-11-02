#include "Plant.h"
#include "Seedling.h"

// Plant::Plant(const string& plantName = "Unknown", const string& plantType = "Generic", CareStrategy strat = NULL)  
Plant::Plant(const string& plantName = "Unknown", const string& plantType = "Generic")  
    : name(plantName), type(plantType), state(new Seedling()), zone(nullptr), ageDays(0), hydrationLevel(0) {}

Plant::Plant(const Plant& plant){
    this->name = plant.getName();
    this->type = plant.getType();
    this->state = new Seedling();
    this->zone = nullptr;
    this->ageDays = 0;
    this->hydrationLevel = 0;
}

Plant::~Plant()
{
    delete state;

    // for(size_t i = 0; i < decorations.size(); i++)
    // {
    //     delete decorations[i];
    // }
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

void Plant::setState(PlantState *newState)
{
    if (state)
    {
        delete state;
    }
    state = newState;

    if (isMature())
        zone->notify();
    else if (state->getStateName() == "Withered")
        notify();
}

void Plant::display() const 
{
    std::cout << "🌿 " << name << " (" << type << ") - State: " << getStateName();
        if (zone) {
            std::cout << " [Zone: " << zone->getZoneName() << "]";
            std::cout << std::endl;
        }

    // for (size_t i = 0; i < decorations.size(); i++) 
    // {
    //     decorations[i]->display(indent + 2);
    // }
}

void Plant::water(int amount) 
{
    // hydrationLevel = std::min(100, hydrationLevel + 50);
    hydrationLevel += amount;
    state->water(this, amount);
}

void Plant::fertilize(int amount) 
{
    state->fertilize(this, amount);
}

void Plant::dailyTick() 
{
    ageDays++;
    hydrationLevel = std::max(0, hydrationLevel - 10); // plants lose hydration each day
    // strategy may decide watering needed (caller will check needsWater)
}

bool Plant::needsWatering() const{
    return hydrationLevel < 50; // Default threshold
}

bool Plant::needsFertilizing() const {
    return ageDays % 7 == 0; // Default: needs fertilizing every 7 days
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
    if (status)
    {
        status->exit(*this);
        delete status; // should help keep track of memeory and not leak after changinging state each time
    }
    status = newStatus;
    if (status)
    {
        status->enter(*this);
    }
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
