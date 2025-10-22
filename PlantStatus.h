#ifndef PLANTSTATUS_H
#define PLANTSTATUS_H
#include <string>

class PlantStatus {
public:
    virtual ~PlantStatus() = default;

    // --- Minimal “status” interface ---
    virtual std::string code() const = 0;   // e.g., "InStorage", "Sold"
    virtual void apply() = 0;               // when status is set
    virtual void revoke() = 0;              // when status ends / changes

    // Context wiring (keep commented until Plant is available).
    // virtual void setContext(Plant* p) { ctx = p; }

protected:
    PlantStatus() = default;

    // Aggregation back-pointer into the Plant context (commented for now).
    // Plant* ctx = nullptr;
};

#endif // PLANTSTATUS_H