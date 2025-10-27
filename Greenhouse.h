#ifndef GREENHOUSE_H
#define GREENHOUSE_H
#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>

#include "PlantObserver.h"
#include <vector>

/**
 * @file Greenhouse.h
 * @brief Component interface for the Composite pattern representing greenhouse elements.
 */

/**
 * @class Greenhouse
 * @brief Abstract base class (Component) in the Composite pattern.
 *
 * Derived classes represent Leaves or Composites. Provides a common operation
 * (execute) implementations for leaf components.
 */
class Greenhouse{
protected:
    std::vector<PlantObserver*> observers; /**< Observers monitoring this zone */

public:
    /**
     * @brief Virtual destructor to allow polymorphic deletion.
     */
    virtual ~Greenhouse() = default;

    /**
     * @brief Perform the component's operation.
     *
     * Implemented by both Leaf and Composite subclasses.
     */
    virtual void execute() = 0;

    /**
     * @brief Add a child component.
     *
     * Default: not supported for leaves (throws). Composite subclasses should override.
     * @param child Pointer to the child to add.
     */
    virtual void add(Greenhouse* child) { throw std::logic_error("add not supported"); }

    /**
     * @brief Remove a child component.
     *
     * Default: not supported for leaves (throws). Composite subclasses should override.
     * @param child Pointer to the child to remove.
     */
    virtual void remove(Greenhouse* child) { throw std::logic_error("remove not supported"); }

    /**
     * @brief Get a child component by index.
     *
     * Default: not supported for leaves (throws). Composite subclasses should override.
     * @param index Zero-based index of the child.
     * @return Pointer to the child component.
     */
    virtual Greenhouse* getChild(std::size_t index) { throw std::logic_error("getChild not supported"); }

    /**
     * @brief Whether this component can contain children.
     * @return true if component is a composite (default: false).
     */
    virtual bool isComposite() const { return false; }

    void attach(PlantObserver* observer);
    void detach(PlantObserver* observer);
    void notify();
};

#endif