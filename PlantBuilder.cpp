#include "PlantBuilder.h"

PlantBuilder::PlantBuilder(BasePlant *product) : product(product){}

BasePlant *PlantBuilder::getProduct(){
    return this->product;
}
