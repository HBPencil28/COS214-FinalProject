#include "Zone.h"

Zone::Zone() : strategy(nullptr){}

Zone::~Zone(){
    // If main does not handle memory management
    // if (strategy){
    //     delete strategy;
    //     strategy = nullptr;
    // }
    
}

void Zone::useStrategy(){
    if (strategy){
        strategy->care();
    }
    
}

void Zone::setStrategy(CareStrategy *strategy){
    if (strategy == nullptr){
        std::cout << "Trying to set a nullptrStrategy";
        return;
    }
    // What should be done with the old strategy?
    // if (this->strategy != nullptr){
    //     delete this->strategy;
    //     this->strategy = nullptr;
    // }
    
    this->strategy = strategy;
    
}
