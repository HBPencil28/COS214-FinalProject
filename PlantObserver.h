#ifndef PLANTOBSERVER_H
#define PLANTOBSERVER_H

#include "Greenhouse.h"

class PlantObserver{
protected:
    Greenhouse* zone;

public:
    void setSubject(Greenhouse* subject){ this->zone = subject; }
    
    virtual void update(/*PlantState* state*/) = 0;
};


#endif // PLANTOBSERVER_H