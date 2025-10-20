#ifndef INVENTORY_H
#define INVENTORY_H
//singleton class

class Inventory{
    private:
        Inventory(); // default constructor to prevent the use of new keyword4
        static Inventory* instance; // only instance of said  inventory
    public:
        static Inventory* getInstance();
};


#endif