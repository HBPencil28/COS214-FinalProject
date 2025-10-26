#include "CareStrategy.h"

CareStrategy::CareStrategy(int water, int fertilizer, Plant* plant) : water(water), fertilizer(fertilizer){
    this->waterCommand = new WaterPlant(plant);
    this->fertiliseCommand = new FertilisePlant(plant);
}