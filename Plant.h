#ifndef CARECOMMAND_H
#define CARECOMMAND_H

#include "CareStaff.h"
#include "CareCommand.h"

#include <string>
#include <vector>
#include <iostream>

#include "PlantState.h"

using namespace std;

class Seedling;
class Growing;
class Mature;
class Withered;

class Plant{
    private:
        string name; 
        PlantState* state;

    public: 
        Plant(const string& plantName) : name(plantName) {
            state = new Seedling();
        }

        ~Plant() {
            delete state;
        }

        string getName() const 
        {
            return name; 
        }

        string getStateName() const 
        {
            return state->getStateName();
        }

        void setState(PlantState* newState) 
        {
            if (state) 
            {
                delete state;
            }

            state = newState;
        }

        void water() {
            cout << "Watering plant: " << name << endl;
            state->water(this);
        }

        void fertilize() {
            cout << "Fertilizing plant: " << name << endl;
            state->fertilize(this);
        }

        void plantSeedlings() {
            cout << "Planting seeds for: " << name << endl;
            state->plantSeedlings(this);
        }

        void harvestAndStore() {
            cout << "Harvesting and storing plant: " << name << endl;
            state->harvestAndStore(this);
        }

        void discard() {
            cout << "Discarding plant: " << name << endl;
            state->discard(this);
        }
}