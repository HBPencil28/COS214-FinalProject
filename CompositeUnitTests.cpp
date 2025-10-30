#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Zone.h"
#include "Greenhouse.h"
#include "Plant.h"

TEST_CASE("Plant tests") {
    Plant* plant = new Plant("Rose");
    
    CHECK(plant->getType() == "Rose");
    CHECK_FALSE(plant->isComposite());
    
    // Test that leaf operations throw
    CHECK_THROWS_AS(plant->add(nullptr), std::logic_error);
    CHECK_THROWS_AS(plant->remove(nullptr), std::logic_error);
    CHECK_THROWS_AS(plant->getChild(0), std::logic_error);
    
    delete plant;
}

TEST_CASE("Zone tests") {
    Greenhouse* zone = new Zone("Flower Zone", "Flower");
    Plant* rose = new Plant("Flower");
    Plant* cactus = new Plant("Cactus");
    
    CHECK(zone->isComposite());
    
    // Test adding valid child
    CHECK_NOTHROW(zone->add(rose));
    CHECK(zone->getChild(0) == rose);
    
    // Test adding invalid child type
    CHECK_THROWS_AS(zone->add(cactus), std::invalid_argument);
    
    // Test remove
    CHECK_NOTHROW(zone->remove(rose));
    CHECK_THROWS_AS(zone->getChild(0), std::out_of_range);
    
    delete zone;
    delete rose;
    delete cactus;
}

TEST_CASE("Nested zones") {
    Greenhouse* greenhouse = new Zone("Main", "");
    Greenhouse* flowerZone = new Zone("Flowers", "Flower");
    Greenhouse* desertZone = new Zone("Desert", "Cactus");
    
    Plant* rose = new Plant("Flower");
    Plant* cactus = new Plant("Cactus");
    
    CHECK_NOTHROW(flowerZone->add(rose));
    CHECK_NOTHROW(desertZone->add(cactus));
    CHECK_NOTHROW(greenhouse->add(flowerZone));
    CHECK_NOTHROW(greenhouse->add(desertZone));
    
    delete greenhouse;
    delete flowerZone;
    delete desertZone;
    delete rose;
    delete cactus;
}