#include "WrapPlantBuilder.h"

void WrapPlantBuilder::addWrap(){
    PlantComponent* wrap = new PlantWrap();
    this->product->addPart(wrap);
}