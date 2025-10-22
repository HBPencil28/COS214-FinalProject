//composite
#ifndef ZONE_H
#define ZONE_H
/**
 * @file Zone.h
 * @author Bandile Mnyandu (github: bandilem-git)
 * @brief 
 * @version 0.1
 * @date 2025-10-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "Greenhouse.h"
#include <algorithm>
#include <vector>
#include "Plant.h"

/**
 * @class Zone
 * @brief Composite in the Composite pattern that can contain other Greenhouse components
 */
class Zone : public Greenhouse {
private:
    std::vector<Greenhouse*> children; /**< Container for child components */
    std::string zoneName;
    std::string zoneCategory;

public:
    /**
     * @brief strategy to be used for all plants
     * 
     */
    CareStrategy* strategy;

    /**
     * @brief idk what this is ngl
     * 
     */
    std::vector<Plant*> plants;

    /** @brief Paramaterised constructor */
    Zone(std::string Z_Name, std::string C_Name);
    
    /** @brief Virtual destructor */
    virtual ~Zone() override = default;

    /**
     * @brief Add a child component
     * @param child Pointer to component to add
     */
    void add(Greenhouse* child) override;

    /**
     * @brief Remove a child component
     * @param child Pointer to component to remove
     */
    void remove(Greenhouse* child) override;

    /**
     * @brief Get child component at index
     * @param index Position of child to retrieve
     * @return Pointer to child component
     */
    Greenhouse* getChild(std::size_t index) override;

    /**
     * @brief Get all children components
     * @return Vector of child component pointers
     */
    const std::vector<Greenhouse*>& getChildren() const;

    /**
     * @brief Check if this is a composite component
     * @return true as Zone is a composite
     */
    bool isComposite() const override;

    /**
     * @brief Execute operation on this component and children
     */
    void execute() override;

    /**
     * @brief Set the Zone Name object
     * 
     * @param name 
     */
    void setZoneName(std::string name);

    /**
     * @brief Get the Zone Name object
     * 
     * @return std::string 
     */
    std::string getZoneName();

    /**
     * @brief Set the Zone Category object
     * 
     * @param category 
     */
    void setZoneCategory(std::string category);
};

#endif