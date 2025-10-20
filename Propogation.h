#ifndef PROPOGATION_H
#define PROPOGATION_H

#include <string>
class PropagationRoom {
public:
    virtual ~PropagationRoom() = default;

    // --- Abstract interface for propagation rooms ---
    virtual std::string id() const = 0;
    virtual void scheduleBatch() = 0;   // schedule a propagation batch
    virtual void beginCycle() = 0;      // start a propagation cycle
    virtual void endCycle() = 0;        // end a propagation cycle and cleanup

    // Context wiring (commented until Greenhouse exists)
    // virtual void setGreenhouse(Greenhouse* g) { greenhouse = g; }

protected:
    PropagationRoom() = default;

    // Aggregation pointer to greenhouse (commented until Greenhouse exists)
    // Greenhouse* greenhouse = nullptr;
};

class Propagation : public PropagationRoom {
public:
    ~Propagation() ;

    std::string id() const;
    void scheduleBatch();
    void beginCycle();
    void endCycle();
};

#endif // PROPOGATION_H