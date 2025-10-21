#ifndef INVENTORY_H
#define INVENTORY_H
/**
 * @file Inventory.h
 * @author Bandile Mnyandu (bandile-m on github)
 * @brief  Singleton representation of the Inventory where plants will be added and removed or fetched from
 * @version 0.1
 * @date 2025-10-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */
//singleton class
#include <vector>
#include <iostream>
#include <algorithm> // i am not making any find function squad


class Plant;// FWD declaration
class PlantIterator; // FWD declaration

/**
 * @brief Inventory class with private an public methods and variables
 * @class Inventory
 */
class Inventory{
    /**
     * @private private Member variables plants and Member functions getPlants
     * 
     */
    private:
        Inventory(); // default constructor to prevent the use of new keyword
        static Inventory* instance; // only instance of said  inventory
        std::vector<Plant*> plants;
        std::vector<Plant*>& getPlants();

        /**
     * @public Member functions
     * 
     */
    public:
        /**
     * @brief Destroy the Inventory object
     * 
     */
        ~Inventory();
        /**
     * @brief Get the Instance object
     * 
     * @return Inventory* 
     */
        static Inventory* getInstance();
        /**
         * @brief add plant to the inventory
         * @return void
         */
        void addPlant(Plant*);      //this line only works once plants actually exists
        /**
         * @brief Removes plant from plants vector
         * 
         * @return Plant*
         */
        Plant* removePlant(Plant*);   //this line only works once plants actually exists
        /**
         * @brief Create a Iterator object
         * 
         * @return PlantIterator* 
         */
        PlantIterator* createIterator(); // Iterator for plants

        //i need access to plants (lowkey though)
        friend class PlantIterator;
};


#endif