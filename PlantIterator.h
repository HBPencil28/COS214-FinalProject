#ifndef PLANTITERATOR_H
#define PLANTITERATOR_H
/**
 * @file PlantIterator.h
 * @author Bandile Mnyandu (github: bandilem-git)
 * @brief Plant Iterator class that implements the Iterator pattern for traversing plants in the inventory
 * @version 0.1
 * @date 2025-10-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "Inventory.h"
#include <vector>

class Plant;

/**
 * @class PlantIterator
 * @brief Iterator for a vector<Plant*> that operates on the actual container.
 */
class PlantIterator {
private:
    int currentIndex;
    std::string category;
    std::vector<Plant*>* plants; ///< pointer to container being iterated

public:
    /** Construct iterator for given container (nullptr allowed). */
    /**
     * @brief Construct a new Plant Iterator object
     * @param category
     */
    PlantIterator(const std::string& category);

    /**
     * @brief returns category of plants being iterated
     * 
     * @return std::string 
     */
    std::string getCategory() const;
    /**
     * @brief returns count of plants in the vector
     * 
     * @return int 
     */
    
    int count() const;
    /**
     * @brief checks if vector has next (for loops)
     * 
     * @return true 
     * @return false 
     */
    bool hasNext() const;
    /**
     * @brief moves index to next value ()
     * 
     * @return Plant* 
     * @return nullptr
     */
    Plant* next();
    /**
     * @brief returns current index-s value
     * 
     * @return * Plant*
     * @return nullptr 
     */
    Plant* current() const;
    /**
     * @brief removes current and returns the removed Plant
     * 
     * @return Plant* 
     * @return nullptr
     */
    Plant* removeCurr();   // removes current element and returns it
    /**
     * @brief  return's first Plant*
     * 
     * @return Plant* 
     * @return nullptr
     */
    Plant* first();        // reset to first and return it
};
#endif