#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Inventory.h"
#include "Plant.h"
#include "PlantIterator.h"

// Test Plant class functionality
TEST_SUITE("Plant Tests") {
    TEST_CASE("Plant Creation and Basic Functions") {
        Plant* p = new Plant("Seedling", "Rose", "Seedling");
        
        // Positive testing
        CHECK(p->getType() == "Seedling");
        CHECK(p->getName() == "Rose");
        CHECK(p->getStateName() == "Seedling");
        
        delete p;
    }
}

// Test Inventory Singleton
TEST_SUITE("Inventory Tests") {
    TEST_CASE("Singleton Instance") {
        Inventory* inv1 = Inventory::getInstance();
        Inventory* inv2 = Inventory::getInstance();
        
        // Positive testing - same instance
        CHECK(inv1 == inv2);
    }
    
    TEST_CASE("Seed Operations") {
        Inventory* inv = Inventory::getInstance();
        
        // Test empty operations
        CHECK(inv->isSeedsEmpty());
        
        // Add seed
        Plant* seed = new Plant("Seedling", "Rose", "Seedling");
        inv->addSeed(seed);
        
        // Positive testing
        CHECK_FALSE(inv->isSeedsEmpty());
        
        // Remove seed
        Plant* removed = inv->removeSeed("Rose");
        CHECK(removed == seed);
        CHECK(inv->isSeedsEmpty());
        
        delete removed;
    }
    
    TEST_CASE("Edge Cases") {
        Inventory* inv = Inventory::getInstance();
        
        // Test null pointer handling
        CHECK_THROWS_AS(inv->addSeed(nullptr), std::runtime_error);
        
        // Test empty string removal
        CHECK_THROWS_AS(inv->removeSeed(""), std::runtime_error );
        
        // Test non-existent plant removal
        CHECK_THROWS_AS(inv->removeSeed("NonExistent"), std::runtime_error );
    }
}

// Test Iterator functionality
TEST_SUITE("Iterator Tests") {
   TEST_CASE("Iterator Operations") {
    Inventory* inv = Inventory::getInstance();
    
    // Add test plants - make sure plants match the expected type for Roses
    Plant* p1 = new Plant("Rose", "Rose", "Grown");  // Changed type to "Roses"
    Plant* p2 = new Plant("Rose", "Rose", "Grown"); // Changed type to "Roses"
    
    // Add plants and verify they were added
    inv->addRose(p1);
    CHECK_FALSE(inv->isRosesEmpty());
    inv->addRose(p2);
    CHECK_FALSE(inv->isRosesEmpty());
    
    // Create iterator and test
    PlantIterator* it = inv->createIterator("Roses");
    CHECK(it != nullptr);
    
    // Test iterator operations
    CHECK(it->hasNext());
    CHECK(it->count() == 2);
    
    Plant* first = it->first();
    CHECK(first != nullptr);
    CHECK(first->getName() == "Rose");
    CHECK(it->hasNext());
    
    Plant* next = it->next();
    CHECK(next != nullptr);
    CHECK(next->getName() == "Rose");
    CHECK_FALSE(it->hasNext());
    
    // Cleanup
    while(!inv->isRosesEmpty()) {
        Plant* p = inv->removeRose();
        delete p;
    }
    delete it;
}
    
    TEST_CASE("Empty Iterator") {
        Inventory* inv = Inventory::getInstance();
        PlantIterator* it = inv->createIterator("NonExistentCategory");
        
        // Negative testing
        CHECK_FALSE(it->hasNext());
        CHECK(it->count() == 0);
        CHECK(it->next() == nullptr);
        
        delete it;
    }
}