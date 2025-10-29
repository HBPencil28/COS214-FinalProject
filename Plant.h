#ifndef PLANT_H
#define PLANT_H

// #include "CareStaff.h"
// #include "CareCommand.h"
#include "PlantState.h"
// #include "Zone.h"

#include <string>
#include <vector>
#include <memory>
#include <iostream>

#include "PlantState.h"

using namespace std;

// Forward declarations of concrete states
class Seedling;
class Growing;
class Mature;
class Withered;

// Forward declaration for Greenhouse (if Composite pattern
class Greenhouse;

class Plant{
    private:
        string name;
        string type; 
        PlantState* state;
        // Zone* zone;
        int ageDays;
        int hydrationLevel;
        //vector<Plant*> decorations; // For Decorator pattern
        std::unique_ptr<PlantStatus> status_;

    public: 
        // Plant(const string& plantName, const string& plantType);
        virtual ~Plant();

        void initState(PlantState* initialState);

        string getName() const;
        string getStateName() const;
        string getType() const;
        int getAgeDays() const;
        int getHydrationLevel() const;

        void setState(PlantState* newState);

        void water();
        void fertilize();
        void harvestAndStore();
        void discard();
        
        // ----- Prototype Pattern -----
        virtual Plant* clone() = 0;

        // ----- Decorator / Composite Pattern -----
        //virtual void add(Plant* extraDecoration);

        virtual void display() const;

        void dailyTick();
        bool needsWatering();
        bool needsFertilizing();
        bool isMature();

        void sell();                                 // InStorage -> Sold
        void markReturned(const std::string& why);   // Sold -> Returned -> InStorage
        const char* statusCode() const;              // e.g., "InStorage"

        // --- Used by states ---
        void changeStatus(std::unique_ptr<PlantStatus> next);
        void auditStatusChange(const char* from, const char* to, const std::string& why = "");
        

};

#endif