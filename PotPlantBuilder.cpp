#include "PotPlantBuilder.h"

void PotPlantBuilder::addPot(){
    PlantComponent* pot = new PlantPot();
    this->product->addPart(pot);
}

void PotPlantBuilder::addSoil(){
    PlantComponent *soil = new PlantSoil();
    this->product->addPart(soil);
}