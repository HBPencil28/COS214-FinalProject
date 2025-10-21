#include "PlantClone.h"

PlantClone::PlantClone(){}

PlantClone::PlantClone(PlantClone *clone){}

PlantClone::~PlantClone(){}

Plant* PlantClone::clone(){
    return new PlantClone(this);
}
