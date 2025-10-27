#include "Greenhouse.h"

void Greenhouse::attach(PlantObserver* observer) {
    observers.push_back(observer);
    observer->setSubject(this);
}

void Greenhouse::detach(PlantObserver* observer) {
    observers.erase(
        std::remove(observers.begin(), observers.end(), observer),
         observers.end());
}

void Greenhouse::notify() {
    for (PlantObserver* observer : observers) {
        observer->update();
    }
}