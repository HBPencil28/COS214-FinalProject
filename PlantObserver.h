#ifndef PLANTOBSERVER_H
#define PLANTOBSERVER_H

#include "Greenhouse.h"
class Plant;

class PlantObserver{
protected:
    Greenhouse* zone;

public:
    void setSubject(Greenhouse* subject);
    
    virtual void update(/*PlantState* state*/) = 0;
    virtual void update(Plant* p) = 0;
};


#endif // PLANTOBSERVER_H