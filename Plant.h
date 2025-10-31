#ifndef PLANT_H
#define PLANT_H

// #include "CareStaff.h"
// #include "CareCommand.h"
#include "PlantState.h"
// #include "Zone.h"
#include "Greenhouse.h"
#include "Seedling.h"

#include <string>
#include <vector>
#include <iostream>

#include "PlantStatus.h"

using namespace std;

// Forward declarations of concrete states
class Seedling;
class Growing;
class Mature;
class Withered;



class Plant : public Greenhouse{
    private:
        string name;
        string type; 
        PlantState* state;
        // Zone* zone;
        int ageDays;
        int hydrationLevel;
        //vector<Plant*> decorations; // For Decorator pattern
        PlantStatus* status;
        string lastReturnReason;

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
        // Plant* clone() override;

        // ----- Decorator / Composite Pattern -----
        //virtual void add(Plant* extraDecoration);

        // virtual void display() const;

        void dailyTick();
        bool needsWatering() const;
        bool needsFertilizing() const;
        bool isMature() const;

        void execute(){};

        //adding PlantStatus functionality
        void setStatus(PlantStatus* newStatus);
        std::string getStatus() const;
        void returnPlant(const std::string& reason);
        void sell();
        void setLastReturnReason(const std::string& r);
        const std::string& getLastReturnReason() const ;
        
};

#endif