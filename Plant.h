#ifndef PLANT_H
#define PLANT_H

#include "CareStaff.h"
#include "CareCommand.h"
#include "PlantState.h"
#include "Zone.h"
#include "Greenhouse.h"
#include "Seedling.h"

#include <string>
#include <vector>
#include <iostream>

#include "PlantState.h"

using namespace std;

// Forward declarations of concrete states
// class Seedling;
// class Growing;
// class Mature;
// class Withered;

// // Forward declaration for Greenhouse (if Composite pattern
// class Greenhouse;

class Plant: public Greenhouse{
    private:
        string name;
        string type; 
        PlantState* state;
        Zone* zone;
        int ageDays;
        int hydrationLevel;
        //vector<Plant*> decorations; // For Decorator pattern

    public: 
        Plant(const string& plantName, const string& plantType);
        Plant(const Plant& plant);
        virtual ~Plant();

        void initState(PlantState* initialState);

        string getName() const;
        string getStateName() const;
        string getType() const;
        int getAgeDays() const;
        int getHydrationLevel() const;

        void setState(PlantState* newState);

        void water(int amount);
        void fertilize(int amount);
        void harvestAndStore();
        void discard();
        
        // ----- Prototype Pattern -----
        Greenhouse* clone() override;

        // ----- Decorator / Composite Pattern -----
        //virtual void add(Plant* extraDecoration);

        virtual void display() const;

        void dailyTick();
        bool needsWatering() const;
        bool needsFertilizing() const;
        bool isMature() const;
        void notify() override;

        void execute(){};
};

#endif