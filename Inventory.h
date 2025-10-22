#ifndef INVENTORY_H
#define INVENTORY_H
/**
 * @file Inventory.h
 * @author Bandile Mnyandu (bandile-m on github)
 * @brief Singleton representation of the Inventory where plants will be added, removed or fetched
 * @version 0.2
 * @date 2025-10-21
 *
 * @copyright Copyright (c) 2025
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include "Plant.h"


class PlantIterator; ///< Forward declaration for PlantIterator

/**
 * @class Inventory
 * @brief Singleton manager for categorized collections of Plant pointers.
 *
 * Inventory owns collections of plants grouped by category and provides
 * per-category helpers (isEmpty / add / remove) plus generic operations.
 * Use Inventory::getInstance() to access the single global instance.
 */
class Inventory {
private:
    /**
     * @brief Private constructor to enforce Singleton pattern.
     */
    Inventory();

    /**
     * @brief Pointer to the singleton instance.
     */
    static Inventory* instance;

    ///////////////////////
    // Flowers
    ///////////////////////
    std::vector<Plant*> Roses;   ///< Collection of roses
    std::vector<Plant*> Daisies; ///< Collection of daisies
    std::vector<Plant*> Tulips;  ///< Collection of tulips

    ///////////////////////
    // Succulents & Cactuses
    ///////////////////////
    std::vector<Plant*> Succulents; ///< Collection of succulents
    std::vector<Plant*> Cactuses;   ///< Collection of cactuses

    ///////////////////////
    // Herbs & Aromatics
    ///////////////////////
    std::vector<Plant*> Basils;      ///< Collection of basils
    std::vector<Plant*> Mints;       ///< Collection of mints
    std::vector<Plant*> Parsleys;    ///< Collection of parsleys
    std::vector<Plant*> Corianders;  ///< Collection of corianders
    std::vector<Plant*> Lavenders;   ///< Collection of lavenders
    std::vector<Plant*> Rosemary;    ///< Collection of rosemary
    std::vector<Plant*> LemonBalms;  ///< Collection of lemon balms

    ///////////////////////
    // Trees & Shrubs
    ///////////////////////
    std::vector<Plant*> Hibiscus;   ///< Collection of hibiscus
    std::vector<Plant*> Hydrangea;  ///< Collection of hydrangea
    std::vector<Plant*> Boxwood;    ///< Collection of boxwood
    std::vector<Plant*> Oak;        ///< Collection of oak trees
    std::vector<Plant*> Baobab;     ///< Collection of baobab trees

    ///////////////////////
    // Seeds (seedlings)
    ///////////////////////
    std::vector<Plant*> seeds; ///< Collection of seedling plants

public:
    /**
     * @brief Destructor - deletes owned Plant pointers in all collections.
     */
    ~Inventory();

    /**
     * @brief Get the singleton instance of Inventory.
     * @return Pointer to the Inventory instance.
     */
    static Inventory* getInstance();

    /**
     * @brief checks to see if roses is empty
     * 
     * @return true 
     * @return false 
     */
    bool isRosesEmpty() const;

    /**
     * @brief Add a Plant to the Roses collection.
     * @param p Pointer to the Plant to add.
     */
    void addRose(Plant* p);

    /**
     * @brief Remove a Plant from the Roses collection.
     * @param p Pointer to the Plant to remove.
     * @return Pointer to the removed Plant if found, otherwise nullptr.
     */
    Plant* removeRose(Plant* p);

    /**
     * @brief Check whether the Daisies collection is empty.
     * @return true if Daisies is empty, false otherwise.
     */
    bool isDaisiesEmpty() const;

    /**
     * @brief Add a Plant to the Daisies collection.
     * @param p Pointer to the Plant to add.
     */
    void addDaisy(Plant* p);

    /**
     * @brief Remove a Plant from the Daisies collection.
     * @param p Pointer to the Plant to remove.
     * @return Pointer to the removed Plant if found, otherwise nullptr.
     */
    Plant* removeDaisy(Plant* p);

    /**
     * @brief Check whether the Tulips collection is empty.
     * @return true if Tulips is empty, false otherwise.
     */
    bool isTulipsEmpty() const;

    /**
     * @brief Add a Plant to the Tulips collection.
     * @param p Pointer to the Plant to add.
     */
    void addTulip(Plant* p);

    /**
     * @brief Remove a Plant from the Tulips collection.
     * @param p Pointer to the Plant to remove.
     * @return Pointer to the removed Plant if found, otherwise nullptr.
     */
    Plant* removeTulip(Plant* p);

    // --------------------
    // Succulents & Cactuses
    // --------------------

    /**
     * @brief Check whether the Succulents collection is empty.
     * @return true if Succulents is empty, false otherwise.
     */
    bool isSucculentsEmpty() const;

    /**
     * @brief Add a Plant to the Succulents collection.
     * @param p Pointer to the Plant to add.
     */
    void addSucculent(Plant* p);

    /**
     * @brief Remove a Plant from the Succulents collection.
     * @param p Pointer to the Plant to remove.
     * @return Pointer to the removed Plant if found, otherwise nullptr.
     */
    Plant* removeSucculent(Plant* p);

    /**
     * @brief Check whether the Cactuses collection is empty.
     * @return true if Cactuses is empty, false otherwise.
     */
    bool isCactusesEmpty() const;

    /**
     * @brief Add a Plant to the Cactuses collection.
     * @param p Pointer to the Plant to add.
     */
    void addCactus(Plant* p);

    /**
     * @brief Remove a Plant from the Cactuses collection.
     * @param p Pointer to the Plant to remove.
     * @return Pointer to the removed Plant if found, otherwise nullptr.
     */
    Plant* removeCactus(Plant* p);

    // --------------------
    // Herbs & Aromatics
    // --------------------

    bool isBasilsEmpty() const;
    void addBasil(Plant* p);
    Plant* removeBasil(Plant* p);

    bool isMintsEmpty() const;
    void addMint(Plant* p);
    Plant* removeMint(Plant* p);

    bool isParsleysEmpty() const;
    void addParsley(Plant* p);
    Plant* removeParsley(Plant* p);

    bool isCoriandersEmpty() const;
    void addCoriander(Plant* p);
    Plant* removeCoriander(Plant* p);

    bool isLavendersEmpty() const;
    void addLavender(Plant* p);
    Plant* removeLavender(Plant* p);

    bool isRosemaryEmpty() const;
    void addRosemary(Plant* p);
    Plant* removeRosemary(Plant* p);

    bool isLemonBalmsEmpty() const;
    void addLemonBalm(Plant* p);
    Plant* removeLemonBalm(Plant* p);

    // --------------------
    // Trees & Shrubs
    // --------------------

    bool isHibiscusEmpty() const;
    void addHibiscus(Plant* p);
    Plant* removeHibiscus(Plant* p);

    bool isHydrangeaEmpty() const;
    void addHydrangea(Plant* p);
    Plant* removeHydrangea(Plant* p);

    bool isBoxwoodEmpty() const;
    void addBoxwood(Plant* p);
    Plant* removeBoxwood(Plant* p);

    bool isOakEmpty() const;
    void addOak(Plant* p);
    Plant* removeOak(Plant* p);

    bool isBaobabEmpty() const;
    void addBaobab(Plant* p);
    Plant* removeBaobab(Plant* p);

    // --------------------
    // Seeds
    // --------------------

    /**
     * @brief Check whether the seeds collection is empty.
     * @return true if seeds is empty, false otherwise.
     */
    bool isSeedsEmpty() const;

    /**
     * @brief Add a Plant to the seeds collection.
     * @param p Pointer to the Plant to add.
     */
    void addSeed(Plant* p);

    /**
     * @brief Remove a Plant from the seeds collection.
     * @param p Pointer to the Plant to remove.
     * @return Pointer to the removed Plant if found, otherwise nullptr.
     */
    Plant* removeSeed(const std::string& type);

    /**
     * @brief Grant PlantIterator access to Inventory internals.
     */


     ///////////////////////
     // Iterator
     ///////////////////////

     /**
      * @brief Create a Iterator object
      * 
      * @param x 
      * @return PlantIterator* 
      */
    PlantIterator* createIterator(std::vector<Plant*>* x);

    /**
     * @brief turns string to all lowercase
     * 
     * @param s 
     * @return std::string 
     */
    std::string lower(const std::string &s);
    friend class PlantIterator;
};

#endif // INVENTORY_H