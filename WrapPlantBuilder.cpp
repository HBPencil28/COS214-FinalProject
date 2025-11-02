#include "WrapPlantBuilder.h"

WrapPlantBuilder::WrapPlantBuilder() : PlantBuilder(new WrappedPlant()) {}

void WrapPlantBuilder::addWrap(){
    PlantComponent* wrap = new PlantWrap();
    this->product->addPart(wrap);
}