#include "CareStaff.h"
#include "GUI.h"
#include "Inventory.h"
#include "Plant.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <map>
#include <utility>
#include "Mature.h"
#include <memory>
using namespace std;

#include <random>

int getRandomInt(int min, int max) {
    static std::random_device rd;   // non-deterministic seed
    static std::mt19937 gen(rd());  // Mersenne Twister RNG
    std::uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

int main() {
    // Create an Inventory instance and add some sample plants
    Inventory* inv = Inventory::getInstance();

    // Add a few example plants (adjust constructor if needed)

 vector<pair<string, string>> plantsInInventory = {
        // Flowers
        {"Rose", "Flowers"},
        {"Daisy", "Flowers"},
        {"Tulip", "Flowers"},

        // Cactus & Succulent
        {"Succulent", "Cactus&Succulent"},
        {"Cactus", "Cactus&Succulent"},

        // Herb & Aromatic
        {"Basil", "Herb&Aromatic"},
        {"Mint", "Herb&Aromatic"},
        {"Parsley", "Herb&Aromatic"},
        {"Coriander", "Herb&Aromatic"},
        {"Lavender", "Herb&Aromatic"},
        {"Rosemary", "Herb&Aromatic"},
        {"LemonBalm", "Herb&Aromatic"},

        // Tree & Shrub Garden
        {"Hibiscus", "Tree&ShrubGarden"},
        {"Hydrangea", "Tree&ShrubGarden"},
        {"Boxwood", "Tree&ShrubGarden"},
        {"Oak", "Tree&ShrubGarden"},
        {"Baobab", "Tree&ShrubGarden"}
    };

    //create x Roses
        for(int i = 0; i < getRandomInt(0, 20); i++){
            Plant* p = new Plant("Rose","Flower");
            p->setState(new Mature());
            inv->addRose(p);
        }

    //create y Dasies
        for(int i = 0; i < getRandomInt(0, 20); i++){
            Plant* p = new Plant("Daisy","Flower");
            p->setState(new Mature());
            inv->addDaisy(p);
        }

    //create z Hibiscus
        for(int i = 0; i < getRandomInt(0,20); i++){
            Plant* p = new Plant("Hibiscus","Tree&Shrub");
            p->setState(new Mature());
            inv->addHibiscus(p);
        }

    //create a Basil
        for(int i = 0; i <getRandomInt(0,20); i++){
            Plant* p = new Plant("Basil","Herb&Aromatic");
            p->setState(new Mature());
            inv->addBasil(p);
        }


    // InitCareStaff (for Zone)
    CareStaff* careGiver = new CareStaff();
    //Zone fuckery
    
    vector<Zone*> zones;
    zones.push_back(new Zone("Flower Bed", "Flower", careGiver));
    zones.push_back(new Zone("Desert","Cactus&Succulent",careGiver));
    zones.push_back(new Zone("Herbs and Aromatics","Herb&Aromatic",careGiver));
    zones.push_back(new Zone("Trees and Shrubs","Tree&Shrub",careGiver));

    //Generate Random num of plants in state seedling

    //FlowerBed
    vector<std::string> flowers ={"Rose","Tulip","Daisy"};
    for(int i = 0; i < getRandomInt(0, 6); i++){
        zones[0]->add(new Plant(flowers[getRandomInt(0,flowers.size()-1)],"Flower"));
    } 
   
    //Succulents and Cactuses
    vector<std::string> succulentsAndCactuses ={"Cactus","Succulent"};
    for(int i = 0; i < getRandomInt(0, 3); i++){
        zones[1]->add(new Plant(succulentsAndCactuses[getRandomInt(0,succulentsAndCactuses.size()-1)],"Cactus&Succulent"));
    } 

    //herbsandaromatics
    vector<std::string> herbsAndAromatics ={"Basil","Mint", "Parsley", "Coriander","Lavender", "Rosemary","LemonBalm"};
    for(int i = 0; i < getRandomInt(5, 52); i++){
        // cout << herbsAndAromatics[getRandomInt(0,herbsAndAromatics.size())]<< endl;
        zones[2]->add(new Plant(herbsAndAromatics[getRandomInt(0,herbsAndAromatics.size()-1)],"Herb&Aromatic"));
    } 

    //Tree & Shrub Garden
    vector<std::string> TreeAndShrubGarden ={"Hibiscus","Oak", "Hydrangea", "Boxwood","Baobab"};
    for(int i = 0; i < getRandomInt(5, 52); i++){
        zones[3]->add(new Plant(TreeAndShrubGarden[getRandomInt(0,TreeAndShrubGarden.size()-1)],"Tree&Shrub"));
    } 

    
    // Create the main GUI window
    gui window(VideoMode(1680, 820), "Nursery Management System", Style::Default, inv, &zones);

    // Run the GUI event loop (draws shelves, customers, and inventory)
    window.displayWindow();

    inv->clearInventory();

    std::cout << "Program exited successfully." << std::endl;
    return 0;
}
