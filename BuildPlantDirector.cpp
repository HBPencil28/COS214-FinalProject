#include "BuildPlantDirector.h"

BuildPlantDirector::BuildPlantDirector(){
    this->builder = nullptr;
}

void BuildPlantDirector::construct(bool b){
    if (builder){
        if (b){
            this->builder->addPot();
            this->builder->addSoil();
        }else{
            this->builder->addWrap();
        }
    }
}

void BuildPlantDirector::setBuilder(PlantBuilder *builder){
    if (builder){
        this->builder = builder;
    }
    
}

PlantBuilder *BuildPlantDirector::getBuilder(){
    return this->builder;
}
