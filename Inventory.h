#ifndef INVENTORY_H
#define INVENTORY_H
//singleton class
#include <vector>
#include <iostream>
#include <algorithm> // i am not making any find function squad

class Plant;// FWD declaration
class PlantIterator; // FWD declaration

class Inventory{
    private:
        Inventory(); // default constructor to prevent the use of new keyword
        static Inventory* instance; // only instance of said  inventory
        std::vector<Plant*> plants;
        std::vector<Plant*>& getPlants();

    public:
        ~Inventory();
        static Inventory* getInstance();
        void addPlant(Plant*);      //this line only works once plants actually exists
        bool removePlant(Plant*);   //this line only works once plants actually exists
        PlantIterator* createIterator(); // Iterator for plants

        //i need access to plants (lowkey though)
        friend class PlantIterator;
};


#endif