#ifndef PLANTCLONE_H
#define PLANTCLONE_H

#include "Plant.h"

class PlantClone : public Plant{
    public:
        PlantClone();
        PlantClone(PlantClone* clone);
        ~PlantClone();
        Plant* clone();
    private:
};

#endif