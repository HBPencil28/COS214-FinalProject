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
 * @brief Iterator class for traversing plants in the inventory
 * 
 * This class implements the Iterator design pattern to provide
 * sequential access to plants stored in the Inventory without
 * exposing the underlying implementation details.
 */
class PlantIterator {
private:
    /** @brief Current position in the plant collection */
    int currentIndex;
    
    /** @brief Pointer to the Inventory singleton instance */
    Inventory* Inventory;

public:
    /**
     * @brief Default constructor
     * Initializes the iterator with currentIndex set to -1
     */
    PlantIterator() : currentIndex(-1) {}

    /**
     * @brief Checks if there is a next element in the collection
     * @return true if there is a next element, false otherwise
     */
    bool hasNext();

    /**
     * @brief Advances to the next element in the collection
     * @return Pointer to the next Plant or nullptr if at the end
     */
    Plant* next();

    /**
     * @brief Gets the current element without moving the iterator
     * @return Pointer to the current Plant or nullptr if invalid position
     */
    Plant* current();

    /**
     * @brief Removes the current element from the collection
     * @return Pointer to the removed Plant or nullptr if operation failed
     */
    Plant* removeCurr();

    /**
     * @brief Resets the iterator to the first element
     * @return Pointer to the first Plant or nullptr if collection is empty
     */
    Plant* first();
};

#endif