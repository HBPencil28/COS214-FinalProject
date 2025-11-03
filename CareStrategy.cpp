#include "CareStrategy.h"
#include "Plant.h"
#include  "WaterPlant.h"
#include "FertilisePlant.h"

CareStrategy::CareStrategy(int water, int fertiliser, Zone* zone, CareStaff* c) : water(water), fertiliser(fertiliser), zone(zone){
    this->waterCommand = new WaterPlant(c,water);
    this->fertiliseCommand = new FertilisePlant(c,fertiliser);
}

CareStrategy::~CareStrategy(){
    if (waterCommand){
        delete waterCommand;
    }
    if(fertiliseCommand){
        delete fertiliseCommand;
    }
    
}