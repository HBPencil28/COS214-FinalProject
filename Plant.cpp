#include "Plant.h"

Plant::Plant(const string& plantName = "Unknown", const string& plantType = "Generic", CareStrategy strat = NULL)  
    : name(plantName), type(plantType), state(nullptr), careStrat(strat), ageDays(0), hydrationLevel(50)
{
    state = nullptr;
}

Plant::~Plant() 
{
    delete state;

    for(size_t i = 0; i < decorations.size(); i++) 
    {
        delete decorations[i];
    }
}

void Plant::initState(PlantState* initialState) 
{
    if(state)
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

void setCareStrategy(CareStrategy strat) 
{
    careStrat = strat;
}

CareStrategy* getCareStrategy() const 
{
    return careStrat;
}

void Plant::setState(PlantState* newState) 
{
    if (state)  
    {  
        delete state; 
    }  

    state = newState; 
}


void add (Plant* extraDecoration) 
{
    decorations.push_back(extraDecoration);
}

void Plant::display() const 
{
    std::string pad(indent, ' ');
    cout << pad << "- " << name << " (" << type << ") - State: " << state->getStateName()
         << pad << "  Age (days): " << ageDays << ", Hydration Level: " << hydrationLevel << endl;

    for (size_t i = 0; i < decorations.size(); i++) 
    {
        decorations[i]->display(indent + 2);
    }
}

void Plant::water() 
{
    hydrationLevel = std::min(100, hydrationLevel + 50);
    state->water(this);
}

void Plant::fertilize() 
{
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
    hydration = std::max(0, hydration - 10); // plants lose hydration each day
    // strategy may decide watering needed (caller will check needsWater)
}

bool Plant::needsWatering() 
{
    return careStrat ? careStrat->needsWatering(this) : false; 
    return hydrationLevel < 50;
}


