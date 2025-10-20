#ifndef INVENTORY_H
#define INVENTORY_H
//singleton class
#include <vector>

class Inventory{
    private:
        Inventory(); // default constructor to prevent the use of new keyword
        static Inventory* instance; // only instance of said  inventory
        std::vector<Plant*> plants;

    public:
        ~Inventory();
        static Inventory* getInstance();
        void addPlant(Plant*);      //this line only works once plants actually exists
        bool removePlant(Plant*);   //this line only works once plants actually exists
        Iterator* createIterator(); // Iterator for plants
};


#endif