#include "WrapPlantBuilder.h"

WrapPlantBuilder::WrapPlantBuilder(BasePlant *product) : PlantBuilder(product){}

void WrapPlantBuilder::addWrap(){
    PlantComponent* wrap = new PlantWrap();
    this->product->addPart(wrap);
}