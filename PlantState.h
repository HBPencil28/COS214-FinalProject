#ifndef PLANTSTATE_H
#define PLANTSTATE_H
#include "PlantStatus.h"

class PlantState {
public:
    virtual ~PlantState() = default;

    // --- Minimal interface ---
    virtual std::string name() const = 0;   // e.g., "Seedling", "Growing"
    virtual void onEnter() = 0;             // hook when state becomes active
    virtual void update() = 0;              // handle event
    virtual void onExit() = 0;              // hook when state is replaced

    // Context wiring (keep commented until Plant is available).
    // virtual void setContext(Plant* p) { ctx = p; }

protected:
    PlantState() = default;

    // Aggregation back-pointer into the Plant context (commented for now).
    // Plant* ctx = NULL;
};


#endif // PLANTSTATE_H