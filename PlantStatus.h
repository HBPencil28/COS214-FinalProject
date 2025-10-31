#ifndef PLANTSTATUS_H
#define PLANTSTATUS_H
#include <string>   

class Plant; // forward declaration 

class PlantStatus {
public:
    virtual ~PlantStatus() = default;
    virtual const char* code() const = 0;

    // called when Plant switches to this state
    virtual void enter(Plant&) {}
    // called when Plant leaves this state
    virtual void exit(Plant&) {}

    // events the system can trigger on a plant
    virtual void onSell(Plant&) {}
    virtual void onReturn(Plant&, const std::string& reason) {}
};

#endif // PLANTSTATUS_H