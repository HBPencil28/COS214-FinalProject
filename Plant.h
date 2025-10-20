#ifndef CARECOMMAND_H
#define CARECOMMAND_H

#include "CareStaff.h"
#include "CareCommand.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Plant{
    private:
        string name; 
    public: 
        Plant(const string& plantName) : name(plantName) {}
        string getName() const { return name; }

        void water() {
            cout << "Watering plant: " << name << endl;
        }

        void fertilize() {
            cout << "Fertilizing plant: " << name << endl;
        }

        void plantSeeds() {
            cout << "Planting seeds for: " << name << endl;
        }

        void harvestAndStore() {
            cout << "Harvesting and storing plant: " << name << endl;
        }

        void discard() {
            cout << "Discarding plant: " << name << endl;
        }
}