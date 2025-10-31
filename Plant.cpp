#include "Plant.h"

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

void Plant::initState(PlantState* initialState) 
{
    if(state)
    {
        delete state;
    }
    state = initialState;
}

string Plant::getName() const {
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

void Plant::setState(PlantState* newState) 
{
    if (state)  
    {  
        delete state; 
    }  

    state = newState; 
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
    state->water(this);
}

void Plant::fertilize(int amount) 
{
    (void)amount;
    // std::cout << amount << std::endl;
    state->fertilize(this);
}

void Plant::harvestAndStore() 
{
    state->harvestAndStore(this);
}

void Plant::discard() 
{
    state->discard(this);
}

void Plant::dailyTick() 
{
    ageDays++;
    hydrationLevel = std::max(0, hydrationLevel - 10); // plants lose hydration each day
    // strategy may decide watering needed (caller will check needsWater)
}

bool Plant::needsWatering() const{
    if(zone && zone->getStrategy())
    {
        // return zone->getStrategy()->needsWatering(*this);
        return true;
    }
    return hydrationLevel < 50; // Default threshold
}

bool Plant::needsFertilizing() const 
{
    if(zone && zone->getStrategy())
    {
        // return zone->getStrategy()->needsFertilizing(*this);
        return true;
    }
    return ageDays % 7 == 0; // Default: needs fertilizing every 7 days
}

bool Plant::isMature() const {
    return state->getStateName() == "Mature";
}

Greenhouse* Plant::clone(){
    return new Plant(*this);
}
