#ifndef PLANTOBSERVER_H
#define PLANTOBSERVER_H

class PlantObserver{
public:
    virtual void update(/*PlantState* state*/) = 0;
};


#endif // PLANTOBSERVER_H