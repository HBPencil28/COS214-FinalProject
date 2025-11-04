#ifndef PLANT_H
#define PLANT_H

#include "CareStaff.h"
#include "CareCommand.h"
#include "PlantState.h"
#include "PlantStatus.h"
#include "Zone.h"
#include "Greenhouse.h"

#include <string>
#include <vector>
#include <iostream>
#include <SFML/System.hpp>

#include "PlantStatus.h"

using namespace std;

// Forward declarations of concrete states
class Seedling;
class Growing;
class Mature;
class Withered;

// // Forward declaration for Greenhouse (if Composite pattern
// class Greenhouse;

class Plant: public Greenhouse{
    private:
        string name;
        string type;
        PlantState *state;
        Zone *zone;
        int ageDays;
        int hydrationLevel;
        PlantStatus *status;
        string lastReturnReason;
        sf::Clock hTimer; // for height inc, water & fertiliser dec
        sf::Clock aTimer; // for aging plant 
        
        // Permanent... Only possibly
        float gInterval;
        float aInterval;
        int fertiliserAmount; // how much fertiliser is in soil
        int height; // height of the plant
        int hInc; // how much to increment (will have a "bonus" if plant is fertiliser)
        int hBoost; // growth rate inc for when plant is fertilised
        int wDec; // water decrement amount
        int fDec; // fertiliser decrement amount
        int timesWatered; // times plant was watered

    public: 
        Plant(const string& plantName = "Unknown", const string& plantType = "Generic");
        Plant(const Plant& plant);
        virtual ~Plant();

        void initState(PlantState* initialState);

        string getName() const;
        string getStateName() const;
        string getType() const;
        int getAgeDays() const;
        int getHydrationLevel() const;
        int getHeight() const;
        int getFertiliserAmount() const;
        int getTimesWatered() const;

        void setState(PlantState* newState);

        void water(int amount);
        void fertilize(int amount);
        void setZone(Zone *zone);

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

        void execute();

        // adding PlantStatus functionality
        void setStatus(PlantStatus *newStatus);
        std::string getStatus() const;
        void returnPlant(const std::string &reason);
        void sell();
        void setLastReturnReason(const std::string &r);
        const std::string &getLastReturnReason() const;
};

#endif
