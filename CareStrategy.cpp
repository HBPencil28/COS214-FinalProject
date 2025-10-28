#include "CareStrategy.h"

CareStrategy::CareStrategy(int water, int fertiliser, Zone* zone, CareStaff* c) : water(water), fertilizer(fertilizer), zone(zone){
    this->waterCommand = new WaterPlant(c,water);
    this->fertiliseCommand = new FertilisePlant(c,fertilizer);
}