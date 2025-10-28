#ifndef PLANTSTATUS_H
#define PLANTSTATUS_H
#include <string>   

class Plant; // forward declaration to avoid circular dependency

class PlantStatus {
public:
    virtual ~PlantStatus() = default;

    virtual const char* code() const = 0;

    // lifecycle hooks when a state becomes active/inactive
    virtual void enter(Plant&) {}
    virtual void exit(Plant&)  {}

    // events the system can trigger
    virtual void onSell(Plant&) {}
    virtual void onReturn(Plant&, const std::string& reason) {}
};

#endif // PLANTSTATUS_H