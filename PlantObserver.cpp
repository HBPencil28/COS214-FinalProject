#include "PlantObserver.h"
#include "Greenhouse.h"
#include "Plant.h"

PlantObserver::~PlantObserver(){}

void PlantObserver::setSubject(Greenhouse *subject) { this->zone = subject; }

