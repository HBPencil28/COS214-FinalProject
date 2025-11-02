#include "PlantIterator.h"
#include "Plant.h"

PlantIterator::PlantIterator(const std::string& category) {
    this->category = category;
    Inventory* inventory = Inventory::getInstance();
    
    // Convert category to lowercase for case-insensitive comparison
    std::string lowerCat = category;
    std::transform(lowerCat.begin(), lowerCat.end(), lowerCat.begin(), ::tolower);

    // Initialize to null by default
    plants = nullptr;

    // Match exact categories as currently defined
    if(category == "Roses") {
        plants = &(inventory->Roses);
    }
    else if(category == "Daisies") {
        plants = &(inventory->Daisies);
    }
    else if(category == "Tulips") {
        plants = &(inventory->Tulips);
    }
    else if(category == "Succulents") {
        plants = &(inventory->Succulents);
    }
    else if(category == "Cactuses") {
        plants = &(inventory->Cactuses);
    }
    else if(category == "Basils") {
        plants = &(inventory->Basils);
    }
    else if(category == "Mints") {
        plants = &(inventory->Mints);
    }
    else if(category == "Parsleys") {
        plants = &(inventory->Parsleys);
    }
    else if(category == "Corianders") {
        plants = &(inventory->Corianders);
    }
    else if(category == "Lavenders") {
        plants = &(inventory->Lavenders);
    }
    else if(category == "Rosemary") {
        plants = &(inventory->Rosemary);
    }
    else if(category == "LemonBalms") {
        plants = &(inventory->LemonBalms);
    }
    else if(category == "Hibiscus") {
        plants = &(inventory->Hibiscus);
    }
    else if(category == "Hydrangea") {
        plants = &(inventory->Hydrangea);
    }
    else if(category == "Boxwood") {
        plants = &(inventory->Boxwood);
    }
    else if(category == "Oak") {
        plants = &(inventory->Oak);
    }
    else if(category == "Baobab") {
        plants = &(inventory->Baobab);
    }
    else if(category == "Seeds" || category == "seed" || category == "seedling" || 
            category == "Seedlings" || category == "Seed") {
        plants = &(inventory->seeds);
    }

    currentIndex = -1; // start before first element
}
bool PlantIterator::hasNext() const {
    if (!plants) return false;
    return (currentIndex + 1) < static_cast<int>(plants->size());// prevent Werrors
}

Plant* PlantIterator::next() {
    if (!plants) return nullptr;
    if (hasNext()) {
        ++currentIndex;
        return (*plants)[currentIndex];
    }
    return nullptr;
}

Plant* PlantIterator::current() const {
    if (!plants) return nullptr;
    if (currentIndex >= 0 && currentIndex < static_cast<int>(plants->size()))
        return (*plants)[currentIndex];
    return nullptr;
}

Plant* PlantIterator::removeCurr() {
    if (!plants) return nullptr;
    if (currentIndex < 0 || currentIndex >= static_cast<int>(plants->size()))
        return nullptr;
    Plant* removed = (*plants)[currentIndex];
    plants->erase(plants->begin() + currentIndex);
    // step back so that next() advances to the element that shifted into this index
    --currentIndex;
    return removed;
}

Plant* PlantIterator::first() {
    if (!plants || plants->empty()) {
        currentIndex = -1;
        return nullptr;
    }
    currentIndex = 0;
    return (*plants)[0];
}

int PlantIterator::count()const{
    if (!plants) return 0;
    return static_cast<int>(plants->size());
}

std::string PlantIterator::getCategory() const {
    return category;
}

