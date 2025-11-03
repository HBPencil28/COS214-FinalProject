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
#include <exception>

class Plant;

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

    /**
     * @brief Destructor - deletes owned Plant pointers in all collections.
     */
    ~Inventory();

public:

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
     * @return Pointer to the removed Plant if found, otherwise nullptr.
     */

    Plant* removeRose();

    /**
     * @brief remove Wilted Rose from inventory
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
     * @return Pointer to the removed Plant if found, otherwise nullptr.
     */
    Plant* removeDaisy();

        /**
     * @brief remove Wilted Daisy from inventory
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
     * @return Pointer to the removed Plant if found, otherwise nullptr.
     */
    Plant* removeTulip();

    /**
     * @brief remove Wilted Tulip from inventory
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
     * @return Pointer to the removed Plant if found, otherwise nullptr.
     */
    Plant* removeSucculent();

    /**
     * @brief remove Wilted Succulent from inventory
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
     * @return Pointer to the removed Plant if found, otherwise nullptr.
     */
    Plant* removeCactus();

    /**
     * @brief remove Wilted Cactus from inventory
     * @param p Pointer to the Plant to remove.
     * @return Pointer to the removed Plant if found, otherwise nullptr.
     */
    Plant* removeCactus(Plant* p);
    // --------------------
    // Herbs & Aromatics
    // --------------------

    /**
     * @brief checks to see if basils is empty
     * 
     * @return true 
     * @return false 
     */
    bool isBasilsEmpty() const;
    /**
     * @brief adds basil to inventory
     * 
     * @param p 
     */
    void addBasil(Plant* p);
    /**
     * @brief removes basil from inventory
     * 
     * @return Plant* 
     */
    Plant* removeBasil();
    /**
     * @brief remove Wilted Basil from inventory
     * @param p Pointer to the Plant to remove.
     * @return Pointer to the removed Plant if found, otherwise nullptr.
     */
    Plant* removeBasil(Plant* p);

    /**
     * @brief checks to see if mints is empty
     * 
     * @return true 
     * @return false 
     */
    bool isMintsEmpty() const;
    /**
     * @brief adds mint to inventory
     * 
     * @param p 
     */
    void addMint(Plant* p);
    /**
     * @brief removes mint from inventory
     * 
     * @return Plant* 
     */
    Plant* removeMint();
    /**
     * @brief remove Wilted Mint from inventory
     * @param p Pointer to the Plant to remove.
     * @return Pointer to the removed Plant if found, otherwise nullptr.
     */
    Plant* removeMint(Plant* p);

    /**
     * @brief checks to see if parsleys is empty
     * 
     * @return true 
     * @return false 
     */
    bool isParsleysEmpty() const;
    /**
     * @brief adds parsley to inventory
     * 
     * @param p 
     */
    void addParsley(Plant* p);

    /**
     * @brief removes parsley from inventory
     * 
     * @return Plant* 
     */
    Plant* removeParsley();
    /**
     * @brief remove Wilted Succulent from inventory
     * @param p Pointer to the Plant to remove.
     * @return Pointer to the removed Plant if found, otherwise nullptr.
     */
    Plant* removeParsley(Plant* p);

    /**
     * @brief checks to see if corianders is empty
     * 
     * @return true 
     * @return false 
     */
    bool isCoriandersEmpty() const;
    /**
     * @brief adds coriander to inventory
     * 
     * @param p 
     */
    void addCoriander(Plant* p);
    /**
     * @brief removes coriander from inventory
     * 
     * @return Plant* 
     */
    Plant* removeCoriander();
    /**
     * @brief remove Wilted Coriander from inventory
     * @param p Pointer to the Plant to remove.
     * @return Pointer to the removed Plant if found, otherwise nullptr.
     */
    Plant* removeCoriander(Plant* p);

    /**
     * @brief checks to see if lavenders is empty
     * 
     * @return true 
     * @return false 
     */
    bool isLavendersEmpty() const;
    /**
     * @brief adds lavender to inventory
     * 
     * @param p 
     */
    void addLavender(Plant* p);
    /**
     * @brief removes lavender from inventory
     * 
     * @return Plant* 
     */
    Plant* removeLavender();
    /**
     * @brief remove Wilted Lavender from inventory
     * @param p Pointer to the Plant to remove.
     * @return Pointer to the removed Plant if found, otherwise nullptr.
     */
    Plant* removeLavender(Plant* p);

    /**
     * @brief checks to see if rosemary is empty
     * 
     * @return true 
     * @return false 
     */
    bool isRosemaryEmpty() const;
    /**
     * @brief adds rosemary to inventory
     * 
     * @param p 
     */
    void addRosemary(Plant* p);
    /**
     * @brief removes rosemary from inventory
     * 
     * @return Plant* 
     */
    Plant* removeRosemary();
    /**
     * @brief remove Wilted Rosemary from inventory
     * @param p Pointer to the Plant to remove.
     * @return Pointer to the removed Plant if found, otherwise nullptr.
     */
    Plant* removeRosemary(Plant* p);

    /**
     * @brief checks to see if lemon balms is empty
     * 
     * @return true 
     * @return false 
     */
    bool isLemonBalmsEmpty() const;
    /**
     * @brief adds lemon balm to inventory
     * 
     * @param p 
     */
    void addLemonBalm(Plant* p);
    /**
     * @brief removes lemon balm from inventory
     * 
     * @return Plant* 
     */
    Plant* removeLemonBalm();
    /**
     * @brief remove Wilted LemonBalm from inventory
     * @param p Pointer to the Plant to remove.
     * @return Pointer to the removed Plant if found, otherwise nullptr.
     */
    Plant* removeLemonBalm(Plant* p);

    // --------------------
    // Trees & Shrubs
    // --------------------

    /**
     * @brief checks to see if hibiscus is empty
     * 
     * @return true 
     * @return false 
     */
    bool isHibiscusEmpty() const;
    /**
     * @brief adds hibiscus to inventory
     * 
     * @param p 
     */
    void addHibiscus(Plant* p);
    /**
     * @brief removes hibiscus from inventory
     * 
     * @return Plant* 
     */
    Plant* removeHibiscus();
    /**
     * @brief remove Wilted Hibiscus from inventory
     * @param p Pointer to the Plant to remove.
     * @return Pointer to the removed Plant if found, otherwise nullptr.
     */
    Plant* removeHibiscus(Plant* p);

    /**
     * @brief checks to see if hydrangea is empty
     * 
     * @return true 
     * @return false 
     */
    bool isHydrangeaEmpty() const;
    /**
     * @brief adds hydrangea to inventory
     * 
     * @param p 
     */
    void addHydrangea(Plant* p);
    /**
     * @brief removes hydrangea from inventory
     * 
     * @return Plant* 
     */
    Plant* removeHydrangea();
    /**
     * @brief remove Wilted Hydrangea from inventory
     * @param p Pointer to the Plant to remove.
     * @return Pointer to the removed Plant if found, otherwise nullptr.
     */
    Plant* removeHydrangea(Plant* p);

    /**
     * @brief checks to see if boxwood is empty
     * 
     * @return true 
     * @return false 
     */
    bool isBoxwoodEmpty() const;
    /**
     * @brief adds boxwood to inventory
     * 
     * @param p 
     */
    void addBoxwood(Plant* p);
    /**
     * @brief removes boxwood from inventory
     * 
     * @return Plant* 
     */
    Plant* removeBoxwood();
    /**
     * @brief remove Wilted Boxwood from inventory
     * @param p Pointer to the Plant to remove.
     * @return Pointer to the removed Plant if found, otherwise nullptr.
     */
    Plant* removeBoxwood(Plant* p);

    /**
     * @brief checks to see if oak is empty
     * 
     * @return true 
     * @return false 
     */
    bool isOakEmpty() const;
    /**
     * @brief adds oak to inventory
     * 
     * @param p 
     */
    void addOak(Plant* p);
    /**
     * @brief removes oak from inventory
     * 
     * @return Plant* 
     */
    Plant* removeOak();
    /**
     * @brief remove Wilted Oak from inventory
     * @param p Pointer to the Plant to remove.
     * @return Pointer to the removed Plant if found, otherwise nullptr.
     */
    Plant* removeOak(Plant* p);

    /**
     * @brief checks to see if baobab is empty
     * 
     * @return true 
     * @return false 
     */
    bool isBaobabEmpty() const;
    /**
     * @brief adds baobab to inventory
     * 
     * @param p 
     */
    void addBaobab(Plant* p);
    /**
     * @brief removes baobab from inventory
     * 
     * @return Plant* 
     */
    Plant* removeBaobab();
    /**
     * @brief remove Wilted Baobab from inventory
     * @param p Pointer to the Plant to remove.
     * @return Pointer to the removed Plant if found, otherwise nullptr.
     */
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
     * @param type The type of seed to remove.
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
    PlantIterator* createIterator(const std::string& );

    /**
     * @brief turns string to all lowercase
     * 
     * @param s 
     * @return std::string 
     */
    std::string lower(const std::string&);
    friend class PlantIterator;
};


#endif // INVENTORY_H



