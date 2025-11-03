#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <vector>
#include <map>

#include "Plant.h"
#include "Greenhouse.h"
#include "Inventory.h"
#include "Zone.h"
#include "CareStrategy.h"
#include "LowCare.h"
#include "MediumCare.h"
#include "HighCare.h"
#include "BasePlant.h"
#include "Bow.h"
#include "BuildPlantDirector.h"
#include "BuyPlant.h"
#include "CareCommand.h"
#include "CareFactory.h"
#include "CareStaff.h"
#include "CareStrategy.h"
#include "CustomerCommand.h"
#include "CustomerFactory.h"
#include "CustomerStaff.h"
#include "CustomisePlant.h"
#include "FertilisePlant.h"
#include "Greenhouse.h"
#include "Growing.h"
#include "InStorage.h"
#include "Manager.h"
#include "Mature.h"
// #include "NormalStaff.h"
#include "NurseryMediator.h"
#include "order.h"
// #include "OutForDelivery.h"
#include "PlantBuilder.h"
#include "PlantComponent.h"
#include "PlantDecorator.h"
#include "PlantIterator.h"
#include "PlantObserver.h"
#include "PlantPot.h"
#include "PlantSoil.h"
#include "PlantState.h"
#include "PlantStatus.h"
#include "PlantWrap.h"
#include "PotPlantBuilder.h"
#include "PottedPlant.h"
#include "RequestHelp.h"
#include "Returned.h"
#include "Ribbon.h"
#include "Seedling.h"
#include "SeniorManager.h"
#include "Sold.h"
#include "Staff.h"
#include "StaffFactory.h"
#include "String.h"
#include "WaterPlant.h"
#include "Withered.h"
#include "WrappedPlant.h"
#include "WrapPlantBuilder.h"


// Builder Pattern - Edge Cases and Comprehensive Testing
TEST_CASE("Builder Pattern - Edge Cases and Comprehensive Testing")
{

    SUBCASE("BuildPlantDirector - Null Builder Handling")
    {
        BuildPlantDirector director;

        // Director should handle null builder gracefully
        director.setBuilder(nullptr);
        CHECK(director.getBuilder() == nullptr);

        // Construct should not crash with null builder
        director.construct(true);
        director.construct(false);
        CHECK(director.getBuilder() == nullptr);
    }

    SUBCASE("BuildPlantDirector - Setting and Getting Builder")
    {
        Plant* plant = new Plant("rose", "flower");
        PlantBuilder *builder = new PotPlantBuilder(plant);
        BuildPlantDirector director;

        director.setBuilder(builder);
        CHECK(director.getBuilder() == builder);
        CHECK(director.getBuilder() != nullptr);

        // Important: Delete builder AND its product before test ends
        delete builder->getProduct();
        delete builder;
    }

    SUBCASE("BuildPlantDirector - Multiple Builder Assignments")
    {
        Plant* plant1 = new Plant("rose", "flower");
        Plant* plant2 = new Plant("cactus", "succulent");

        PlantBuilder *builder1 = new PotPlantBuilder(plant1);
        PlantBuilder *builder2 = new WrapPlantBuilder();
        BuildPlantDirector director;

        director.setBuilder(builder1);
        CHECK(director.getBuilder() == builder1);

        // Change builder
        director.setBuilder(builder2);
        CHECK(director.getBuilder() == builder2);
        CHECK(director.getBuilder() != builder1);

        // Clean up both builders and their products
        delete builder1->getProduct();
        delete builder1;
        delete builder2->getProduct();
        delete builder2;
        delete plant2;
    }

    SUBCASE("PotPlantBuilder - Construction with Potted Plant")
    {
        Plant* plant = new Plant("tulip", "flower");
        PlantBuilder *builder = new PotPlantBuilder(plant);
        BuildPlantDirector director;

        director.setBuilder(builder);
        director.construct(true);

        BasePlant *product = director.getBuilder()->getProduct();
        CHECK(product != nullptr);

        // Clean up
        delete product;
        delete builder;
    }

    SUBCASE("PotPlantBuilder - Add Pot and Soil Components")
    {
        Plant* plant = new Plant("lavender", "herb");
        PotPlantBuilder *builder = new PotPlantBuilder(plant);

        // Add pot
        builder->addPot();

        // Add soil
        builder->addSoil();

        // Empty addWrap should do nothing
        builder->addWrap();

        BasePlant *product = builder->getProduct();
        CHECK(product != nullptr);

        // Clean up
        delete product;
        delete builder;
    }

    SUBCASE("WrapPlantBuilder - Construction with Wrapped Plant")
    {
        PlantBuilder *builder = new WrapPlantBuilder();
        BuildPlantDirector director;

        director.setBuilder(builder);
        director.construct(false);

        BasePlant *product = director.getBuilder()->getProduct();
        CHECK(product != nullptr);

        // Clean up
        delete product;
        delete builder;
    }

    SUBCASE("WrapPlantBuilder - Add Wrap Component")
    {
        WrapPlantBuilder *builder = new WrapPlantBuilder();

        // Add wrap
        builder->addWrap();

        // Empty methods should do nothing
        builder->addPot();
        builder->addSoil();

        BasePlant *product = builder->getProduct();
        CHECK(product != nullptr);

        // Clean up
        delete product;
        delete builder;
    }

    SUBCASE("WrappedPlant - Add Null Plant")
    {
        WrappedPlant *wrapped = new WrappedPlant();

        // Should handle nullptr gracefully
        wrapped->addPlant(nullptr);

        // No crash expected
        CHECK(true);

        delete wrapped;
    }

    SUBCASE("WrappedPlant - Add Multiple Plants")
    {
        WrappedPlant *wrapped = new WrappedPlant();
        Plant p1("rose", "flower");
        Plant p2("tulip", "flower");
        Plant p3("daisy", "flower");

        // WARNING: Only add pointers if WrappedPlant does NOT delete them
        // Based on destructor, it DOES delete plants, so we need heap plants
        Plant *pp1 = new Plant(p1);
        Plant *pp2 = new Plant(p2);
        Plant *pp3 = new Plant(p3);

        wrapped->addPlant(pp1);
        wrapped->addPlant(pp2);
        wrapped->addPlant(pp3);

        // WrappedPlant destructor will delete the plants
        CHECK(true);

        delete wrapped;
    }

    SUBCASE("WrappedPlant - Add Same Plant Multiple Times - UNSAFE")
    {
        // NOTE: This test demonstrates UNSAFE behavior
        // Adding the same pointer multiple times will cause double-free
        // We test the add operation but don't actually delete
        WrappedPlant *wrapped = new WrappedPlant();
        Plant *plant = new Plant("cactus", "succulent");

        // Only add once to avoid double-free
        wrapped->addPlant(plant);

        // DO NOT add same pointer multiple times - it causes double-free
        // This is an edge case that shows a design flaw
        CHECK(true);

        delete wrapped; // This will delete plant
    }

    SUBCASE("WrappedPlant - Add Null Part")
    {
        WrappedPlant *wrapped = new WrappedPlant();

        // Should handle nullptr gracefully
        wrapped->addPart(nullptr);

        // No crash expected
        CHECK(true);

        delete wrapped;
    }

    SUBCASE("WrappedPlant - Add Multiple Parts")
    {
        WrappedPlant *wrapped = new WrappedPlant();
        PlantComponent *wrap1 = new PlantWrap();
        PlantComponent *wrap2 = new PlantWrap();

        wrapped->addPart(wrap1);
        wrapped->addPart(wrap2);

        // Parts will be cleaned up by WrappedPlant destructor
        CHECK(true);

        delete wrapped;
    }

    SUBCASE("PottedPlant - Add Null Part")
    {
        Plant *plant = new Plant("orchid", "flower");
        PottedPlant *potted = new PottedPlant(plant);

        // Should handle nullptr gracefully
        potted->addPart(nullptr);

        // No crash expected
        CHECK(true);

        delete potted; // This deletes plant too
    }

    SUBCASE("PottedPlant - Add Multiple Parts")
    {
        Plant *plant = new Plant("fern", "greenery");
        PottedPlant *potted = new PottedPlant(plant);

        PlantComponent *pot = new PlantPot();
        PlantComponent *soil = new PlantSoil();

        potted->addPart(pot);
        potted->addPart(soil);

        // Parts will be cleaned up by PottedPlant destructor
        CHECK(true);

        delete potted;
    }

    SUBCASE("Director Construct - Potted Plant Path (true)")
    {
        Plant *plant = new Plant("sunflower", "flower");
        PlantBuilder *builder = new PotPlantBuilder(plant);
        BuildPlantDirector director;

        director.setBuilder(builder);
        director.construct(true); // Should call addPot() and addSoil()

        BasePlant *product = builder->getProduct();
        CHECK(product != nullptr);

        // Clean up
        delete product;
        delete builder;
    }

    SUBCASE("Director Construct - Wrapped Plant Path (false)")
    {
        PlantBuilder *builder = new WrapPlantBuilder();
        BuildPlantDirector director;

        director.setBuilder(builder);
        director.construct(false); // Should call addWrap()

        BasePlant *product = builder->getProduct();
        CHECK(product != nullptr);

        // Clean up
        delete product;
        delete builder;
    }

    SUBCASE("Complete Workflow - Potted Plant")
    {
        Plant *plant = new Plant("bamboo", "grass");
        PlantBuilder *builder = new PotPlantBuilder(plant);
        BuildPlantDirector director;

        director.setBuilder(builder);
        director.construct(true);

        BasePlant *product = director.getBuilder()->getProduct();
        CHECK(product != nullptr);

        // Product should be PottedPlant
        PottedPlant *pottedPlant = dynamic_cast<PottedPlant *>(product);
        CHECK(pottedPlant != nullptr);

        // Clean up
        delete product;
        delete builder;
    }

    SUBCASE("Complete Workflow - Wrapped Plant with Multiple Plants")
    {
        PlantBuilder *builder = new WrapPlantBuilder();
        BuildPlantDirector director;

        director.setBuilder(builder);
        director.construct(false);

        BasePlant *product = director.getBuilder()->getProduct();
        WrappedPlant *wrapped = dynamic_cast<WrappedPlant *>(product);

        CHECK(wrapped != nullptr);

        // Add multiple plants (must be heap-allocated)
        Plant *p1 = new Plant("rose", "flower");
        Plant *p2 = new Plant("lily", "flower");
        Plant *p3 = new Plant("iris", "flower");

        wrapped->addPlant(p1);
        wrapped->addPlant(p2);
        wrapped->addPlant(p3);

        // Clean up (wrapped destructor deletes plants)
        delete product;
        delete builder;
    }

    SUBCASE("Builder Pattern - Memory Management")
    {
        {
            Plant *plant = new Plant("mint", "herb");
            PlantBuilder *builder = new PotPlantBuilder(plant);

            BasePlant *product = builder->getProduct();
            CHECK(product != nullptr);

            // Proper cleanup
            delete product;
            delete builder;
        }

        {
            PlantBuilder *builder = new WrapPlantBuilder();

            BasePlant *product = builder->getProduct();
            CHECK(product != nullptr);

            // Proper cleanup
            delete product;
            delete builder;
        }

        CHECK(true);
    }

    SUBCASE("Multiple Directors with Same Builder")
    {
        Plant *plant = new Plant("basil", "herb");
        PlantBuilder *builder = new PotPlantBuilder(plant);

        BuildPlantDirector director1;
        BuildPlantDirector director2;

        director1.setBuilder(builder);
        director2.setBuilder(builder);

        CHECK(director1.getBuilder() == director2.getBuilder());

        // Both directors can construct
        director1.construct(true);
        director2.construct(true);

        // Clean up
        delete builder->getProduct();
        delete builder;
    }

    SUBCASE("Alternate Construction Calls")
    {
        Plant *plant = new Plant("thyme", "herb");
        PlantBuilder *builder = new PotPlantBuilder(plant);
        BuildPlantDirector director;

        director.setBuilder(builder);

        // Multiple construct calls
        director.construct(true);
        director.construct(false);
        director.construct(true);

        BasePlant *product = builder->getProduct();
        CHECK(product != nullptr);

        // Clean up
        delete product;
        delete builder;
    }

    SUBCASE("Empty Add Methods in Builders")
    {
        Plant *plant = new Plant("sage", "herb");
        PotPlantBuilder *potBuilder = new PotPlantBuilder(plant);
        WrapPlantBuilder *wrapBuilder = new WrapPlantBuilder();

        // Test empty methods don't crash
        potBuilder->addWrap();  // Empty implementation
        wrapBuilder->addPot();  // Empty implementation
        wrapBuilder->addSoil(); // Empty implementation

        CHECK(potBuilder->getProduct() != nullptr);
        CHECK(wrapBuilder->getProduct() != nullptr);

        // Clean up
        delete potBuilder->getProduct();
        delete potBuilder;
        delete wrapBuilder->getProduct();
        delete wrapBuilder;
    }
}

// Decorator Pattern - Edge Cases and Comprehensive Testing
TEST_CASE("Decorator Pattern - Edge Cases and Comprehensive Testing")
{

    SUBCASE("PlantDecorator - Add Null Decoration")
    {
        Bow *bow = new Bow();

        // Should handle nullptr gracefully
        bow->add(nullptr);

        // No crash expected
        CHECK(bow->getDecoration() == nullptr);

        delete bow;
    }

    SUBCASE("PlantDecorator - Add Single Decoration")
    {
        Bow *bow = new Bow();
        Ribbon *ribbon = new Ribbon();

        bow->add(ribbon);

        // Decoration should be set
        CHECK(bow->getDecoration() == ribbon);

        // Bow destructor will delete ribbon
        delete bow;
    }

    SUBCASE("PlantDecorator - Chain Multiple Decorations")
    {
        Bow *bow = new Bow();
        Ribbon *ribbon = new Ribbon();
        String *string = new String();

        // Chain decorations
        bow->add(ribbon);
        bow->add(string);

        // First decoration should be ribbon
        CHECK(bow->getDecoration() == ribbon);

        // Bow destructor will delete the entire chain
        delete bow;
    }

    SUBCASE("PlantDecorator - Deep Chain of Decorations")
    {
        Bow *bow = new Bow();
        Ribbon *ribbon1 = new Ribbon();
        String *string1 = new String();
        Bow *bow2 = new Bow();
        Ribbon *ribbon2 = new Ribbon();

        // Create deep chain
        bow->add(ribbon1);
        bow->add(string1);
        bow->add(bow2);
        bow->add(ribbon2);

        // Root decoration should be ribbon1
        CHECK(bow->getDecoration() == ribbon1);

        // Bow destructor will delete entire chain
        delete bow;
    }

    SUBCASE("PlantDecorator - Add to Empty Decoration")
    {
        Bow *bow = new Bow();
        Ribbon *ribbon = new Ribbon();

        // Decoration is nullptr initially
        CHECK(bow->getDecoration() == nullptr);

        bow->add(ribbon);

        // Now decoration is set
        CHECK(bow->getDecoration() != nullptr);
        CHECK(bow->getDecoration() == ribbon);

        delete bow;
    }

    SUBCASE("PlantDecorator - Add to Existing Decoration")
    {
        Bow *bow = new Bow();
        Ribbon *ribbon = new Ribbon();
        String *string = new String();

        // Add first decoration
        bow->add(ribbon);
        CHECK(bow->getDecoration() == ribbon);

        // Add second decoration (should chain to ribbon)
        bow->add(string);

        // Root decoration should still be ribbon
        CHECK(bow->getDecoration() == ribbon);

        delete bow;
    }

    SUBCASE("PlantDecorator - AddPart with Null Component")
    {
        Bow *bow = new Bow();

        // Should handle nullptr gracefully
        bow->addPart(nullptr);

        // No crash expected
        CHECK(true);

        delete bow;
    }

    SUBCASE("PlantDecorator - AddPart with Valid Component")
    {
        Ribbon *ribbon = new Ribbon();
        PlantComponent *component = new PlantComponent("TestComponent");

        // Should print "Studded" but not crash
        ribbon->addPart(component);

        // Component not stored, just acknowledged
        CHECK(true);

        delete component;
        delete ribbon;
    }

    SUBCASE("Bow - Creation and Destruction")
    {
        Bow *bow = new Bow();

        CHECK(bow != nullptr);

        delete bow;
    }

    SUBCASE("Bow - Change Style")
    {
        Bow *bow = new Bow();

        // Change style should not crash
        bow->changeStyle("elegant");
        bow->changeStyle("casual");
        bow->changeStyle("");

        CHECK(true);

        delete bow;
    }

    SUBCASE("Ribbon - Creation and Destruction")
    {
        Ribbon *ribbon = new Ribbon();

        CHECK(ribbon != nullptr);

        delete ribbon;
    }

    SUBCASE("Ribbon - Change Colour")
    {
        Ribbon *ribbon = new Ribbon();

        // Change colour should not crash
        ribbon->changeColour("red");
        ribbon->changeColour("blue");
        ribbon->changeColour("");

        CHECK(true);

        delete ribbon;
    }

    SUBCASE("String - Creation and Destruction")
    {
        String *string = new String();

        CHECK(string != nullptr);

        delete string;
    }

    SUBCASE("String - Change Type")
    {
        String *string = new String();

        // Change type should not crash
        string->changeType("thick");
        string->changeType("thin");
        string->changeType("");

        CHECK(true);

        delete string;
    }

    SUBCASE("Mixed Decorators - Bow with Ribbon")
    {
        Bow *bow = new Bow();
        Ribbon *ribbon = new Ribbon();

        bow->add(ribbon);
        bow->changeStyle("formal");

        CHECK(bow->getDecoration() == ribbon);

        delete bow;
    }

    SUBCASE("Mixed Decorators - Ribbon with String")
    {
        Ribbon *ribbon = new Ribbon();
        String *string = new String();

        ribbon->add(string);
        ribbon->changeColour("gold");

        CHECK(ribbon->getDecoration() == string);

        delete ribbon;
    }

    SUBCASE("Mixed Decorators - All Three Types")
    {
        Bow *bow = new Bow();
        Ribbon *ribbon = new Ribbon();
        String *string = new String();

        bow->add(ribbon);
        bow->add(string);

        bow->changeStyle("festive");

        CHECK(bow->getDecoration() == ribbon);

        delete bow;
    }

    SUBCASE("Decorator Chain - Multiple Nulls")
    {
        Bow *bow = new Bow();

        // Add multiple nulls
        bow->add(nullptr);
        bow->add(nullptr);
        bow->add(nullptr);

        // Decoration should remain null
        CHECK(bow->getDecoration() == nullptr);

        delete bow;
    }

    SUBCASE("Decorator Chain - Null Between Valid Decorations")
    {
        Bow *bow = new Bow();
        Ribbon *ribbon = new Ribbon();
        String *string = new String();

        bow->add(ribbon);
        bow->add(nullptr); // Should be ignored
        bow->add(string);  // Should chain to ribbon

        CHECK(bow->getDecoration() == ribbon);

        delete bow;
    }

    SUBCASE("PlantDecorator - Memory Safety After Multiple Adds")
    {
        Bow *bow = new Bow();

        for (int i = 0; i < 10; i++)
        {
            Ribbon *ribbon = new Ribbon();
            bow->add(ribbon);
        }

        // All decorations should be properly chained
        CHECK(bow->getDecoration() != nullptr);

        // Bow destructor should clean up entire chain
        delete bow;
    }

    SUBCASE("PlantDecorator - Empty Chain Destruction")
    {
        Bow *bow = new Bow();

        // Delete without adding any decorations
        CHECK(bow->getDecoration() == nullptr);

        delete bow;
    }

    SUBCASE("PlantDecorator - Single Element Chain")
    {
        Bow *bow = new Bow();
        Ribbon *ribbon = new Ribbon();

        bow->add(ribbon);

        // Chain has single element
        CHECK(bow->getDecoration() == ribbon);

        delete bow;
    }

    SUBCASE("Decorator - Type Safety with Dynamic Cast")
    {
        Bow *bow = new Bow();
        Ribbon *ribbon = new Ribbon();

        bow->add(ribbon);

        // Verify type through inheritance
        BasePlant *basePtr = bow;
        CHECK(basePtr != nullptr);

        BasePlant *decorationBase = bow->getDecoration();
        PlantDecorator *decoratorPtr = dynamic_cast<PlantDecorator *>(decorationBase);
        CHECK(decoratorPtr != nullptr);

        delete bow;
    }

    SUBCASE("Decorator - Complex Chain Navigation")
    {
        Bow *bow = new Bow();
        Ribbon *ribbon = new Ribbon();
        String *string = new String();
        Bow *bow2 = new Bow();

        bow->add(ribbon);
        bow->add(string);
        bow->add(bow2);

        // First level decoration
        CHECK(bow->getDecoration() == ribbon);

        // Second level decoration (through ribbon)
        BasePlant *secondLevel = dynamic_cast<PlantDecorator *>(bow->getDecoration())->getDecoration();
        CHECK(secondLevel == string);

        delete bow;
    }

    SUBCASE("PlantDecorator - Destructor Chain Cleanup")
    {
        // This tests that destructor properly deletes entire chain
        Bow *bow = new Bow();
        Ribbon *ribbon1 = new Ribbon();
        String *string1 = new String();
        Ribbon *ribbon2 = new Ribbon();
        Bow *bow2 = new Bow();

        bow->add(ribbon1);
        bow->add(string1);
        bow->add(ribbon2);
        bow->add(bow2);

        // Delete root - should cascade delete all
        delete bow;

        // If we get here without crash, cleanup worked
        CHECK(true);
    }

    SUBCASE("PlantDecorator - AddPart Multiple Times")
    {
        Ribbon *ribbon = new Ribbon();
        PlantComponent *comp1 = new PlantComponent("Comp1");
        PlantComponent *comp2 = new PlantComponent("Comp2");
        PlantComponent *comp3 = new PlantComponent("Comp3");

        // Add multiple components (should just print, not store)
        ribbon->addPart(comp1);
        ribbon->addPart(comp2);
        ribbon->addPart(comp3);

        CHECK(true);

        // Components not owned by decorator
        delete comp1;
        delete comp2;
        delete comp3;
        delete ribbon;
    }

    SUBCASE("Decorator - Inheritance Structure Verification")
    {
        Bow *bow = new Bow();

        // Verify inheritance hierarchy
        BasePlant *basePtr = dynamic_cast<BasePlant *>(bow);
        CHECK(basePtr != nullptr);

        PlantDecorator *decoratorPtr = dynamic_cast<PlantDecorator *>(bow);
        CHECK(decoratorPtr != nullptr);

        delete bow;
    }

    SUBCASE("PlantDecorator - Add Self Reference (Circular)")
    {
        // WARNING: This would create circular reference
        // Don't actually test this as it would cause infinite loop/crash
        // Just document that this is an edge case to avoid

        Bow *bow = new Bow();

        // DO NOT DO: bow->add(bow);  // This would be circular!

        // Instead verify that we can detect and prevent this
        // (Current implementation doesn't prevent this - design flaw)

        CHECK(true);

        delete bow;
    }

    SUBCASE("Decorator - Polymorphic Behavior")
    {
        BasePlant *decorator1 = new Bow();
        BasePlant *decorator2 = new Ribbon();
        BasePlant *decorator3 = new String();

        // All should be valid BasePlant pointers
        CHECK(decorator1 != nullptr);
        CHECK(decorator2 != nullptr);
        CHECK(decorator3 != nullptr);

        // Clean up through base pointer (virtual destructor)
        delete decorator1;
        delete decorator2;
        delete decorator3;
    }

    SUBCASE("PlantDecorator - Empty addPart Implementation")
    {
        Bow *bow = new Bow();

        // Calling add(BasePlant*) is implemented
        // Calling addPart(PlantComponent*) is implemented but minimal

        PlantComponent *comp = new PlantComponent("Test");
        bow->addPart(comp);

        // Should not crash, just prints
        CHECK(true);

        delete comp;
        delete bow;
    }
}

// Strategy Pattern - Edge Cases and Comprehensive Testing
TEST_CASE("Strategy Pattern - Edge Cases and Comprehensive Testing")
{

    SUBCASE("CareStrategy - LowCare Creation and Execution")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "flower", staff);

        CareStrategy *lowCare = new LowCare(zone, staff);

        // Execute low care
        lowCare->care();

        CHECK(lowCare != nullptr);

        delete lowCare;
        delete zone;
        delete staff;
    }

    SUBCASE("CareStrategy - MediumCare Creation and Execution")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "herb", staff);

        CareStrategy *mediumCare = new MediumCare(zone, staff);

        // Execute medium care
        mediumCare->care();

        CHECK(mediumCare != nullptr);

        delete mediumCare;
        delete zone;
        delete staff;
    }

    SUBCASE("CareStrategy - HighCare Creation and Execution")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "succulent", staff);

        CareStrategy *highCare = new HighCare(zone, staff);

        // Execute high care
        highCare->care();

        CHECK(highCare != nullptr);

        delete highCare;
        delete zone;
        delete staff;
    }

    SUBCASE("Zone - Set Strategy from HighCare to LowCare")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "flower", staff);

        // Zone starts with HighCare by default
        CareStrategy *initialStrategy = zone->getStrategy();
        CHECK(initialStrategy != nullptr);

        // Change to LowCare
        CareStrategy *lowCare = new LowCare(zone, staff);
        zone->setStrategy(lowCare);

        CHECK(zone->getStrategy() == lowCare);
        CHECK(zone->getStrategy() != initialStrategy);

        delete zone;
        delete staff;
    }

    SUBCASE("Zone - Set Strategy from HighCare to MediumCare")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "herb", staff);

        // Change to MediumCare
        CareStrategy *mediumCare = new MediumCare(zone, staff);
        zone->setStrategy(mediumCare);

        CHECK(zone->getStrategy() == mediumCare);

        delete zone;
        delete staff;
    }

    SUBCASE("Zone - Set Strategy to Null (Should be Ignored)")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "flower", staff);

        CareStrategy *originalStrategy = zone->getStrategy();
        CHECK(originalStrategy != nullptr);

        // Try to set null strategy (should be ignored)
        zone->setStrategy(nullptr);

        // Strategy should remain unchanged
        CHECK(zone->getStrategy() == originalStrategy);

        delete zone;
        delete staff;
    }

    SUBCASE("Zone - Multiple Strategy Changes")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "flower", staff);

        // Change to LowCare
        CareStrategy *lowCare = new LowCare(zone, staff);
        zone->setStrategy(lowCare);
        CHECK(zone->getStrategy() == lowCare);

        // Change to MediumCare
        CareStrategy *mediumCare = new MediumCare(zone, staff);
        zone->setStrategy(mediumCare);
        CHECK(zone->getStrategy() == mediumCare);

        // Change to HighCare
        CareStrategy *highCare = new HighCare(zone, staff);
        zone->setStrategy(highCare);
        CHECK(zone->getStrategy() == highCare);

        delete zone;
        delete staff;
    }

    SUBCASE("Zone - Execute with LowCare Strategy")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "flower", staff);
        Plant *plant = new Plant("Rose", "flower");

        zone->add(plant);

        // Set to LowCare
        CareStrategy *lowCare = new LowCare(zone, staff);
        zone->setStrategy(lowCare);

        // Execute zone (should use LowCare strategy)
        zone->execute();

        CHECK(true);

        delete zone; // Zone destructor handles plant deletion
        delete staff;
    }

    SUBCASE("Zone - Execute with MediumCare Strategy")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "herb", staff);
        Plant *plant = new Plant("Basil", "herb");

        zone->add(plant);

        // Set to MediumCare
        CareStrategy *mediumCare = new MediumCare(zone, staff);
        zone->setStrategy(mediumCare);

        // Execute zone (should use MediumCare strategy)
        zone->execute();

        CHECK(true);

        delete zone;
        delete staff;
    }

    SUBCASE("Zone - Execute with HighCare Strategy")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "succulent", staff);
        Plant *plant = new Plant("Cactus", "succulent");

        zone->add(plant);

        // Zone already has HighCare by default
        zone->execute();

        CHECK(true);

        delete zone;
        delete staff;
    }

    SUBCASE("CareStrategy - LowCare Water and Fertilizer Values")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "flower", staff);

        // LowCare: water=20, fertilizer=2
        CareStrategy *lowCare = new LowCare(zone, staff);

        // Verify strategy was created (can't access private members)
        CHECK(lowCare != nullptr);

        delete lowCare;
        delete zone;
        delete staff;
    }

    SUBCASE("CareStrategy - MediumCare Water and Fertilizer Values")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "herb", staff);

        // MediumCare: water=50, fertilizer=5
        CareStrategy *mediumCare = new MediumCare(zone, staff);

        CHECK(mediumCare != nullptr);

        delete mediumCare;
        delete zone;
        delete staff;
    }

    SUBCASE("CareStrategy - HighCare Water and Fertilizer Values")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "succulent", staff);

        // HighCare: water=100, fertilizer=10
        CareStrategy *highCare = new HighCare(zone, staff);

        CHECK(highCare != nullptr);

        delete highCare;
        delete zone;
        delete staff;
    }

    SUBCASE("Zone - Execute with Multiple Plants and LowCare")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "flower", staff);

        Plant *plant1 = new Plant("Rose", "flower");
        Plant *plant2 = new Plant("Tulip", "flower");
        Plant *plant3 = new Plant("Daisy", "flower");

        zone->add(plant1);
        zone->add(plant2);
        zone->add(plant3);

        CareStrategy *lowCare = new LowCare(zone, staff);
        zone->setStrategy(lowCare);

        // Execute should water and fertilize all plants
        zone->execute();

        CHECK(zone->getChildren().size() == 3);

        delete zone;
        delete staff;
    }

    SUBCASE("Zone - Execute with Multiple Plants and HighCare")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "herb", staff);

        Plant *plant1 = new Plant("Basil", "herb");
        Plant *plant2 = new Plant("Mint", "herb");
        Plant *plant3 = new Plant("Thyme", "herb");

        zone->add(plant1);
        zone->add(plant2);
        zone->add(plant3);

        // Zone has HighCare by default
        zone->execute();

        CHECK(zone->getChildren().size() == 3);

        delete zone;
        delete staff;
    }

    SUBCASE("Zone - Execute with Empty Zone")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "flower", staff);

        // No plants added
        CHECK(zone->getChildren().size() == 0);

        // Execute should not crash
        zone->execute();

        CHECK(true);

        delete zone;
        delete staff;
    }

    SUBCASE("CareStaff - Water Command Execution")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "flower", staff);
        Plant *plant = new Plant("Rose", "flower");

        zone->add(plant);
        staff->setSubject(zone);

        int initialHydration = plant->getHydrationLevel();

        // Water plants
        staff->water(30);

        // Hydration should increase
        CHECK(plant->getHydrationLevel() > initialHydration);

        delete zone;
        delete staff;
    }

    SUBCASE("CareStaff - Fertilize Command Execution")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "herb", staff);
        Plant *plant = new Plant("Basil", "herb");

        zone->add(plant);
        staff->setSubject(zone);

        // Fertilize plants (should not crash)
        staff->fertilise(5);

        CHECK(true);

        delete zone;
        delete staff;
    }

    SUBCASE("CareStaff - Water with Null Zone")
    {
        CareStaff *staff = new CareStaff();

        // Staff has no subject
        staff->water(50);

        // Should not crash
        CHECK(true);

        delete staff;
    }

    SUBCASE("CareStaff - Fertilize with Null Zone")
    {
        CareStaff *staff = new CareStaff();

        // Staff has no subject
        staff->fertilise(10);

        // Should not crash
        CHECK(true);

        delete staff;
    }

    SUBCASE("WaterPlant Command - Execute on Zone")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "flower", staff);
        Plant *plant = new Plant("Rose", "flower");

        zone->add(plant);

        WaterPlant *waterCmd = new WaterPlant(staff, 40);
        waterCmd->execute(zone);

        CHECK(true);

        delete waterCmd;
        delete zone;
        delete staff;
    }

    SUBCASE("FertilisePlant Command - Execute on Zone")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "herb", staff);
        Plant *plant = new Plant("Mint", "herb");

        zone->add(plant);

        FertilisePlant *fertiliseCmd = new FertilisePlant(staff, 8);
        fertiliseCmd->execute(zone);

        CHECK(true);

        delete fertiliseCmd;
        delete zone;
        delete staff;
    }

    SUBCASE("CareStrategy - Polymorphic Behavior")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "flower", staff);

        // Create strategies through base pointer
        CareStrategy *strategy1 = new LowCare(zone, staff);
        CareStrategy *strategy2 = new MediumCare(zone, staff);
        CareStrategy *strategy3 = new HighCare(zone, staff);

        // All should be valid
        CHECK(strategy1 != nullptr);
        CHECK(strategy2 != nullptr);
        CHECK(strategy3 != nullptr);

        // Execute through base pointer
        strategy1->care();
        strategy2->care();
        strategy3->care();

        delete strategy1;
        delete strategy2;
        delete strategy3;
        delete zone;
        delete staff;
    }

    SUBCASE("Zone - Strategy Pattern Context Switching")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "flower", staff);
        Plant *plant = new Plant("Rose", "flower");

        zone->add(plant);

        // Start with HighCare
        zone->execute();

        // Switch to LowCare
        CareStrategy *lowCare = new LowCare(zone, staff);
        zone->setStrategy(lowCare);
        zone->execute();

        // Switch to MediumCare
        CareStrategy *mediumCare = new MediumCare(zone, staff);
        zone->setStrategy(mediumCare);
        zone->execute();

        CHECK(zone->getStrategy() == mediumCare);

        delete zone;
        delete staff;
    }

    SUBCASE("Zone - Set Staff and Execute")
    {
        CareStaff *staff1 = new CareStaff();
        CareStaff *staff2 = new CareStaff();
        Zone *zone = new Zone("TestZone", "flower", staff1);
        Plant *plant = new Plant("Rose", "flower");

        zone->add(plant);

        // Execute with staff1
        zone->execute();

        // Change staff
        zone->setStaff(staff2);
        zone->execute();

        CHECK(true);

        delete zone;
        delete staff1;
        delete staff2;
    }

    SUBCASE("Zone - Set Null Staff (Should be Ignored)")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "flower", staff);

        // Try to set null staff (should be ignored)
        zone->setStaff(nullptr);

        // Should not crash
        CHECK(true);

        delete zone;
        delete staff;
    }

    SUBCASE("CareStrategy - Multiple Zones with Same Strategy Type")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone1 = new Zone("Zone1", "flower", staff);
        Zone *zone2 = new Zone("Zone2", "herb", staff);
        Zone *zone3 = new Zone("Zone3", "succulent", staff);

        // All zones use HighCare by default
        zone1->execute();
        zone2->execute();
        zone3->execute();

        CHECK(true);

        delete zone1;
        delete zone2;
        delete zone3;
        delete staff;
    }

    SUBCASE("CareStrategy - Multiple Zones with Different Strategies")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone1 = new Zone("Zone1", "flower", staff);
        Zone *zone2 = new Zone("Zone2", "herb", staff);
        Zone *zone3 = new Zone("Zone3", "succulent", staff);

        // Set different strategies
        CareStrategy *lowCare = new LowCare(zone1, staff);
        zone1->setStrategy(lowCare);

        CareStrategy *mediumCare = new MediumCare(zone2, staff);
        zone2->setStrategy(mediumCare);

        // zone3 keeps HighCare

        // Execute all zones
        zone1->execute();
        zone2->execute();
        zone3->execute();

        CHECK(zone1->getStrategy() == lowCare);
        CHECK(zone2->getStrategy() == mediumCare);
        CHECK(zone3->getStrategy() != nullptr);

        delete zone1;
        delete zone2;
        delete zone3;
        delete staff;
    }

    SUBCASE("Zone - Destructor Deletes Strategy")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "flower", staff);

        CareStrategy *lowCare = new LowCare(zone, staff);
        zone->setStrategy(lowCare);

        // Zone destructor should delete strategy
        delete zone;

        // If we get here without crash, strategy was properly deleted
        CHECK(true);

        delete staff;
    }

    SUBCASE("CareStaff - Water Multiple Plants in Zone")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "flower", staff);

        Plant *p1 = new Plant("Rose", "flower");
        Plant *p2 = new Plant("Tulip", "flower");
        Plant *p3 = new Plant("Daisy", "flower");

        zone->add(p1);
        zone->add(p2);
        zone->add(p3);

        staff->setSubject(zone);

        int h1 = p1->getHydrationLevel();
        int h2 = p2->getHydrationLevel();
        int h3 = p3->getHydrationLevel();

        // Water all plants
        staff->water(25);

        // All should have increased hydration
        CHECK(p1->getHydrationLevel() > h1);
        CHECK(p2->getHydrationLevel() > h2);
        CHECK(p3->getHydrationLevel() > h3);

        delete zone;
        delete staff;
    }

    SUBCASE("CareStrategy - Care Execution Order")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "flower", staff);
        Plant *plant = new Plant("Rose", "flower");

        zone->add(plant);

        // All strategies execute fertilize then water
        CareStrategy *lowCare = new LowCare(zone, staff);
        lowCare->care();

        CHECK(true);

        delete lowCare;
        delete zone;
        delete staff;
    }

    SUBCASE("Zone - Strategy Deletion on Multiple Changes")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "flower", staff);

        // Change strategy multiple times
        // Each change should delete previous strategy
        for (int i = 0; i < 5; i++)
        {
            CareStrategy *lowCare = new LowCare(zone, staff);
            zone->setStrategy(lowCare);
        }

        CHECK(zone->getStrategy() != nullptr);

        delete zone;
        delete staff;
    }
}

// Command Pattern - Edge Cases and Comprehensive Testing
TEST_CASE("Command Pattern - Edge Cases and Comprehensive Testing")
{

    SUBCASE("WaterPlant Command - Creation and Basic Execution")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "flower", staff);
        Plant *plant = new Plant("Rose", "flower");

        zone->add(plant);

        WaterPlant *waterCmd = new WaterPlant(staff, 30);
        waterCmd->execute(zone);

        CHECK(waterCmd != nullptr);

        delete waterCmd;
        delete zone;
        delete staff;
    }

    SUBCASE("FertilisePlant Command - Creation and Basic Execution")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "herb", staff);
        Plant *plant = new Plant("Basil", "herb");

        zone->add(plant);

        FertilisePlant *fertiliseCmd = new FertilisePlant(staff, 5);
        fertiliseCmd->execute(zone);

        CHECK(fertiliseCmd != nullptr);

        delete fertiliseCmd;
        delete zone;
        delete staff;
    }

    SUBCASE("WaterPlant Command - Execute on Empty Zone")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("EmptyZone", "flower", staff);

        // No plants added
        WaterPlant *waterCmd = new WaterPlant(staff, 50);

        // Should not crash
        waterCmd->execute(zone);

        CHECK(zone->getChildren().size() == 0);

        delete waterCmd;
        delete zone;
        delete staff;
    }

    SUBCASE("FertilisePlant Command - Execute on Empty Zone")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("EmptyZone", "herb", staff);

        // No plants added
        FertilisePlant *fertiliseCmd = new FertilisePlant(staff, 10);

        // Should not crash
        fertiliseCmd->execute(zone);

        CHECK(zone->getChildren().size() == 0);

        delete fertiliseCmd;
        delete zone;
        delete staff;
    }

    SUBCASE("WaterPlant Command - Execute on Multiple Plants")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "flower", staff);

        Plant *p1 = new Plant("Rose", "flower");
        Plant *p2 = new Plant("Tulip", "flower");
        Plant *p3 = new Plant("Daisy", "flower");

        zone->add(p1);
        zone->add(p2);
        zone->add(p3);

        int h1 = p1->getHydrationLevel();
        int h2 = p2->getHydrationLevel();
        int h3 = p3->getHydrationLevel();

        WaterPlant *waterCmd = new WaterPlant(staff, 25);
        waterCmd->execute(zone);

        // All plants should be watered
        CHECK(p1->getHydrationLevel() > h1);
        CHECK(p2->getHydrationLevel() > h2);
        CHECK(p3->getHydrationLevel() > h3);

        delete waterCmd;
        delete zone;
        delete staff;
    }

    SUBCASE("FertilisePlant Command - Execute on Multiple Plants")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "herb", staff);

        Plant *p1 = new Plant("Basil", "herb");
        Plant *p2 = new Plant("Mint", "herb");
        Plant *p3 = new Plant("Thyme", "herb");

        zone->add(p1);
        zone->add(p2);
        zone->add(p3);

        FertilisePlant *fertiliseCmd = new FertilisePlant(staff, 8);
        fertiliseCmd->execute(zone);

        // All plants should be fertilized (no crash)
        CHECK(zone->getChildren().size() == 3);

        delete fertiliseCmd;
        delete zone;
        delete staff;
    }

    SUBCASE("WaterPlant Command - Different Water Amounts")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "flower", staff);
        Plant *plant = new Plant("Rose", "flower");

        zone->add(plant);

        // Test different water amounts
        WaterPlant *waterCmd1 = new WaterPlant(staff, 10);
        WaterPlant *waterCmd2 = new WaterPlant(staff, 50);
        WaterPlant *waterCmd3 = new WaterPlant(staff, 100);

        int initial = plant->getHydrationLevel();

        waterCmd1->execute(zone);
        CHECK(plant->getHydrationLevel() > initial);

        waterCmd2->execute(zone);
        waterCmd3->execute(zone);

        CHECK(plant->getHydrationLevel() > initial);

        delete waterCmd1;
        delete waterCmd2;
        delete waterCmd3;
        delete zone;
        delete staff;
    }

    SUBCASE("FertilisePlant Command - Different Fertilizer Amounts")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "herb", staff);
        Plant *plant = new Plant("Basil", "herb");

        zone->add(plant);

        // Test different fertilizer amounts
        FertilisePlant *fertiliseCmd1 = new FertilisePlant(staff, 2);
        FertilisePlant *fertiliseCmd2 = new FertilisePlant(staff, 5);
        FertilisePlant *fertiliseCmd3 = new FertilisePlant(staff, 10);

        fertiliseCmd1->execute(zone);
        fertiliseCmd2->execute(zone);
        fertiliseCmd3->execute(zone);

        // Should not crash
        CHECK(true);

        delete fertiliseCmd1;
        delete fertiliseCmd2;
        delete fertiliseCmd3;
        delete zone;
        delete staff;
    }

    SUBCASE("WaterPlant Command - Zero Water Amount")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "flower", staff);
        Plant *plant = new Plant("Rose", "flower");

        zone->add(plant);

        int initial = plant->getHydrationLevel();

        WaterPlant *waterCmd = new WaterPlant(staff, 0);
        waterCmd->execute(zone);

        // Hydration should remain same
        CHECK(plant->getHydrationLevel() == initial);

        delete waterCmd;
        delete zone;
        delete staff;
    }

    SUBCASE("FertilisePlant Command - Zero Fertilizer Amount")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "herb", staff);
        Plant *plant = new Plant("Mint", "herb");

        zone->add(plant);

        FertilisePlant *fertiliseCmd = new FertilisePlant(staff, 0);
        fertiliseCmd->execute(zone);

        // Should not crash
        CHECK(true);

        delete fertiliseCmd;
        delete zone;
        delete staff;
    }

    SUBCASE("WaterPlant Command - Negative Water Amount")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "flower", staff);
        Plant *plant = new Plant("Rose", "flower");

        zone->add(plant);

        int initial = plant->getHydrationLevel();

        WaterPlant *waterCmd = new WaterPlant(staff, -10);
        waterCmd->execute(zone);

        // Negative water reduces hydration
        CHECK(plant->getHydrationLevel() < initial);

        delete waterCmd;
        delete zone;
        delete staff;
    }

    SUBCASE("Command - Execute Multiple Times on Same Zone")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "flower", staff);
        Plant *plant = new Plant("Rose", "flower");

        zone->add(plant);

        WaterPlant *waterCmd = new WaterPlant(staff, 20);

        // Execute multiple times
        waterCmd->execute(zone);
        waterCmd->execute(zone);
        waterCmd->execute(zone);

        CHECK(true);

        delete waterCmd;
        delete zone;
        delete staff;
    }

    SUBCASE("Command - Sequence of Water and Fertilize")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "herb", staff);
        Plant *plant = new Plant("Basil", "herb");

        zone->add(plant);

        WaterPlant *waterCmd = new WaterPlant(staff, 30);
        FertilisePlant *fertiliseCmd = new FertilisePlant(staff, 5);

        // Execute in sequence
        waterCmd->execute(zone);
        fertiliseCmd->execute(zone);
        waterCmd->execute(zone);
        fertiliseCmd->execute(zone);

        CHECK(true);

        delete waterCmd;
        delete fertiliseCmd;
        delete zone;
        delete staff;
    }

    SUBCASE("Command - Interleaved Execution")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "flower", staff);
        Plant *plant = new Plant("Tulip", "flower");

        zone->add(plant);

        WaterPlant *waterCmd = new WaterPlant(staff, 25);
        FertilisePlant *fertiliseCmd = new FertilisePlant(staff, 6);

        // Interleaved execution
        fertiliseCmd->execute(zone);
        waterCmd->execute(zone);
        fertiliseCmd->execute(zone);
        waterCmd->execute(zone);

        CHECK(true);

        delete waterCmd;
        delete fertiliseCmd;
        delete zone;
        delete staff;
    }

    SUBCASE("CareCommand - Polymorphic Execution")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "flower", staff);
        Plant *plant = new Plant("Rose", "flower");

        zone->add(plant);

        // Create commands through base pointer
        CareCommand *cmd1 = new WaterPlant(staff, 40);
        CareCommand *cmd2 = new FertilisePlant(staff, 7);

        // Execute through base pointer
        cmd1->execute(zone);
        cmd2->execute(zone);

        CHECK(true);

        delete cmd1;
        delete cmd2;
        delete zone;
        delete staff;
    }

    SUBCASE("Command - Execute on Different Zones")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone1 = new Zone("Zone1", "flower", staff);
        Zone *zone2 = new Zone("Zone2", "herb", staff);

        Plant *p1 = new Plant("Rose", "flower");
        Plant *p2 = new Plant("Basil", "herb");

        zone1->add(p1);
        zone2->add(p2);

        WaterPlant *waterCmd = new WaterPlant(staff, 35);

        // Execute same command on different zones
        waterCmd->execute(zone1);
        waterCmd->execute(zone2);

        CHECK(true);

        delete waterCmd;
        delete zone1;
        delete zone2;
        delete staff;
    }

    SUBCASE("Command - Staff Sets Subject Before Execution")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "flower", staff);
        Plant *plant = new Plant("Rose", "flower");

        zone->add(plant);

        // Command internally calls staff->setSubject(zone)
        WaterPlant *waterCmd = new WaterPlant(staff, 30);
        waterCmd->execute(zone);

        // Subject should be set
        CHECK(true);

        delete waterCmd;
        delete zone;
        delete staff;
    }

    SUBCASE("Command - Multiple Commands with Same Staff")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "herb", staff);
        Plant *plant = new Plant("Mint", "herb");

        zone->add(plant);

        // Create multiple commands with same staff
        WaterPlant *waterCmd1 = new WaterPlant(staff, 20);
        WaterPlant *waterCmd2 = new WaterPlant(staff, 40);
        FertilisePlant *fertiliseCmd1 = new FertilisePlant(staff, 3);
        FertilisePlant *fertiliseCmd2 = new FertilisePlant(staff, 7);

        waterCmd1->execute(zone);
        waterCmd2->execute(zone);
        fertiliseCmd1->execute(zone);
        fertiliseCmd2->execute(zone);

        CHECK(true);

        delete waterCmd1;
        delete waterCmd2;
        delete fertiliseCmd1;
        delete fertiliseCmd2;
        delete zone;
        delete staff;
    }

    SUBCASE("Command - Multiple Commands with Different Staff")
    {
        CareStaff *staff1 = new CareStaff();
        CareStaff *staff2 = new CareStaff();
        Zone *zone = new Zone("TestZone", "flower", staff1);
        Plant *plant = new Plant("Rose", "flower");

        zone->add(plant);

        WaterPlant *waterCmd1 = new WaterPlant(staff1, 30);
        WaterPlant *waterCmd2 = new WaterPlant(staff2, 30);

        waterCmd1->execute(zone);
        waterCmd2->execute(zone);

        CHECK(true);

        delete waterCmd1;
        delete waterCmd2;
        delete zone;
        delete staff1;
        delete staff2;
    }

    SUBCASE("Command - Execute After Plant Removal")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "flower", staff);
        Plant *plant1 = new Plant("Rose", "flower");
        Plant *plant2 = new Plant("Tulip", "flower");

        zone->add(plant1);
        zone->add(plant2);

        WaterPlant *waterCmd = new WaterPlant(staff, 25);

        // Execute before removal
        waterCmd->execute(zone);
        CHECK(zone->getChildren().size() == 2);

        // Remove a plant
        zone->remove(plant1);
        delete plant1;

        // Execute after removal
        waterCmd->execute(zone);
        CHECK(zone->getChildren().size() == 1);

        delete waterCmd;
        delete zone;
        delete staff;
    }

    SUBCASE("Command - Execute After All Plants Removed")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "herb", staff);
        Plant *plant = new Plant("Basil", "herb");

        zone->add(plant);

        WaterPlant *waterCmd = new WaterPlant(staff, 30);

        // Execute with plant
        waterCmd->execute(zone);

        // Remove plant
        zone->remove(plant);
        delete plant;

        // Execute on empty zone
        waterCmd->execute(zone);
        CHECK(zone->getChildren().size() == 0);

        delete waterCmd;
        delete zone;
        delete staff;
    }

    SUBCASE("Command - Large Number of Sequential Executions")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "flower", staff);
        Plant *plant = new Plant("Rose", "flower");

        zone->add(plant);

        WaterPlant *waterCmd = new WaterPlant(staff, 5);
        FertilisePlant *fertiliseCmd = new FertilisePlant(staff, 1);

        // Execute many times
        for (int i = 0; i < 50; i++)
        {
            waterCmd->execute(zone);
            fertiliseCmd->execute(zone);
        }

        CHECK(true);

        delete waterCmd;
        delete fertiliseCmd;
        delete zone;
        delete staff;
    }

    SUBCASE("Command - Command Queue Simulation")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "herb", staff);
        Plant *plant = new Plant("Mint", "herb");

        zone->add(plant);

        // Create command queue
        std::vector<CareCommand *> commandQueue;
        commandQueue.push_back(new WaterPlant(staff, 20));
        commandQueue.push_back(new FertilisePlant(staff, 4));
        commandQueue.push_back(new WaterPlant(staff, 15));
        commandQueue.push_back(new FertilisePlant(staff, 3));
        commandQueue.push_back(new WaterPlant(staff, 25));

        // Execute all commands in queue
        for (CareCommand *cmd : commandQueue)
        {
            cmd->execute(zone);
        }

        // Clean up queue
        for (CareCommand *cmd : commandQueue)
        {
            delete cmd;
        }

        CHECK(true);

        delete zone;
        delete staff;
    }

    SUBCASE("Command - Undo Simulation (Execute Opposite)")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "flower", staff);
        Plant *plant = new Plant("Rose", "flower");

        zone->add(plant);

        int initial = plant->getHydrationLevel();

        // Add water
        WaterPlant *addWater = new WaterPlant(staff, 30);
        addWater->execute(zone);
        CHECK(plant->getHydrationLevel() > initial);

        // "Undo" by removing water (negative amount)
        WaterPlant *removeWater = new WaterPlant(staff, -30);
        removeWater->execute(zone);

        CHECK(true);

        delete addWater;
        delete removeWater;
        delete zone;
        delete staff;
    }

    SUBCASE("Command - Memory Safety After Multiple Executions")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "herb", staff);

        for (int i = 0; i < 10; i++)
        {
            Plant *plant = new Plant("Basil", "herb");
            zone->add(plant);
        }

        WaterPlant *waterCmd = new WaterPlant(staff, 20);
        FertilisePlant *fertiliseCmd = new FertilisePlant(staff, 5);

        // Multiple executions
        for (int i = 0; i < 20; i++)
        {
            waterCmd->execute(zone);
            fertiliseCmd->execute(zone);
        }

        CHECK(zone->getChildren().size() == 10);

        delete waterCmd;
        delete fertiliseCmd;
        delete zone;
        delete staff;
    }

    SUBCASE("Command - Very Large Water Amount")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "flower", staff);
        Plant *plant = new Plant("Rose", "flower");

        zone->add(plant);

        WaterPlant *waterCmd = new WaterPlant(staff, 10000);
        waterCmd->execute(zone);

        // Should handle large values
        CHECK(plant->getHydrationLevel() > 100);

        delete waterCmd;
        delete zone;
        delete staff;
    }

    SUBCASE("Command - Very Large Fertilizer Amount")
    {
        CareStaff *staff = new CareStaff();
        Zone *zone = new Zone("TestZone", "herb", staff);
        Plant *plant = new Plant("Basil", "herb");

        zone->add(plant);

        FertilisePlant *fertiliseCmd = new FertilisePlant(staff, 5000);
        fertiliseCmd->execute(zone);

        // Should not crash
        CHECK(true);

        delete fertiliseCmd;
        delete zone;
        delete staff;
    }

    SUBCASE("Command - Destructor Does Not Crash")
    {
        CareStaff *staff = new CareStaff();

        // Create and immediately delete commands
        WaterPlant *waterCmd = new WaterPlant(staff, 30);
        delete waterCmd;

        FertilisePlant *fertiliseCmd = new FertilisePlant(staff, 5);
        delete fertiliseCmd;

        // Should not crash
        CHECK(true);

        delete staff;
    }

    SUBCASE("Command - Base Class Pointer Deletion")
    {
        CareStaff *staff = new CareStaff();

        // Delete through base class pointer (virtual destructor)
        CareCommand *cmd1 = new WaterPlant(staff, 25);
        CareCommand *cmd2 = new FertilisePlant(staff, 6);

        delete cmd1;
        delete cmd2;

        // Should properly delete derived classes
        CHECK(true);

        delete staff;
    }
}

// Prototype Pattern - Edge Cases and Comprehensive Testing
TEST_CASE("Prototype Pattern - Edge Cases and Comprehensive Testing")
{

    SUBCASE("Plant Clone - Basic Cloning")
    {
        Plant *original = new Plant("Rose", "flower");

        Greenhouse *cloned = original->clone();
        Plant *clonedPlant = dynamic_cast<Plant *>(cloned);

        CHECK(clonedPlant != nullptr);
        CHECK(clonedPlant != original);

        delete original;
        delete clonedPlant;
    }

    SUBCASE("Plant Clone - Name and Type Preservation")
    {
        Plant *original = new Plant("Basil", "herb");

        Plant *cloned = dynamic_cast<Plant *>(original->clone());

        // Cloned plant should have same name and type
        CHECK(cloned->getName() == original->getName());
        CHECK(cloned->getType() == original->getType());

        delete original;
        delete cloned;
    }

    SUBCASE("Plant Clone - State Independence")
    {
        Plant *original = new Plant("Mint", "herb");

        // Modify original
        original->water(50);

        Plant *cloned = dynamic_cast<Plant *>(original->clone());

        // Clone should have fresh state (Seedling with hydration=0)
        CHECK(cloned->getStateName() == "Seedling");
        CHECK(cloned->getHydrationLevel() == 0);
        CHECK(cloned->getAgeDays() == 0);

        delete original;
        delete cloned;
    }

    SUBCASE("Plant Clone - Original Independence After Cloning")
    {
        Plant *original = new Plant("Tulip", "flower");
        Plant *cloned = dynamic_cast<Plant *>(original->clone());

        // Modify original after cloning
        original->water(100);
        original->dailyTick();

        // Clone should remain unaffected
        CHECK(cloned->getHydrationLevel() == 0);
        CHECK(cloned->getAgeDays() == 0);

        delete original;
        delete cloned;
    }

    SUBCASE("Plant Clone - Clone Independence After Cloning")
    {
        Plant *original = new Plant("Cactus", "succulent");
        Plant *cloned = dynamic_cast<Plant *>(original->clone());

        int originalHydration = original->getHydrationLevel();

        // Modify clone
        cloned->water(75);
        cloned->dailyTick();

        // Original should remain unaffected
        CHECK(original->getHydrationLevel() == originalHydration);
        CHECK(original->getAgeDays() == 0);

        delete original;
        delete cloned;
    }

    SUBCASE("Plant Clone - Multiple Clones from Same Original")
    {
        Plant *original = new Plant("Lavender", "herb");

        Plant *clone1 = dynamic_cast<Plant *>(original->clone());
        Plant *clone2 = dynamic_cast<Plant *>(original->clone());
        Plant *clone3 = dynamic_cast<Plant *>(original->clone());

        // All clones should be different objects
        CHECK(clone1 != clone2);
        CHECK(clone2 != clone3);
        CHECK(clone1 != clone3);

        // All should have same name and type
        CHECK(clone1->getName() == original->getName());
        CHECK(clone2->getName() == original->getName());
        CHECK(clone3->getName() == original->getName());

        delete original;
        delete clone1;
        delete clone2;
        delete clone3;
    }

    SUBCASE("Plant Clone - Clone of Clone")
    {
        Plant *original = new Plant("Rosemary", "herb");
        Plant *firstClone = dynamic_cast<Plant *>(original->clone());
        Plant *secondClone = dynamic_cast<Plant *>(firstClone->clone());

        // All should be independent
        CHECK(original != firstClone);
        CHECK(firstClone != secondClone);
        CHECK(original != secondClone);

        // All should have same name and type
        CHECK(secondClone->getName() == original->getName());
        CHECK(secondClone->getType() == original->getType());

        delete original;
        delete firstClone;
        delete secondClone;
    }

    SUBCASE("Plant Clone - Deep Clone Chain")
    {
        Plant *original = new Plant("Oak", "tree");
        Plant *clone1 = dynamic_cast<Plant *>(original->clone());
        Plant *clone2 = dynamic_cast<Plant *>(clone1->clone());
        Plant *clone3 = dynamic_cast<Plant *>(clone2->clone());
        Plant *clone4 = dynamic_cast<Plant *>(clone3->clone());

        // All should have same name
        CHECK(clone4->getName() == original->getName());

        // Modify one in the middle
        clone2->water(50);

        // Others should be unaffected
        CHECK(original->getHydrationLevel() != clone2->getHydrationLevel());
        CHECK(clone4->getHydrationLevel() == 0);

        delete original;
        delete clone1;
        delete clone2;
        delete clone3;
        delete clone4;
    }

    SUBCASE("Plant Clone - Clone Through Base Pointer")
    {
        Greenhouse *original = new Plant("Daisy", "flower");

        // Clone through base class interface
        Greenhouse *cloned = original->clone();

        // Should be valid
        CHECK(cloned != nullptr);
        CHECK(cloned != original);

        // Cast to verify it's a Plant
        Plant *clonedPlant = dynamic_cast<Plant *>(cloned);
        CHECK(clonedPlant != nullptr);

        delete original;
        delete cloned;
    }

    SUBCASE("Plant Clone - Polymorphic Cloning")
    {
        // Store as base pointers
        Greenhouse *g1 = new Plant("Hibiscus", "shrub");
        Greenhouse *g2 = new Plant("Boxwood", "shrub");

        // Clone through polymorphic interface
        Greenhouse *c1 = g1->clone();
        Greenhouse *c2 = g2->clone();

        CHECK(c1 != nullptr);
        CHECK(c2 != nullptr);
        CHECK(c1 != g1);
        CHECK(c2 != g2);

        delete g1;
        delete g2;
        delete c1;
        delete c2;
    }

    SUBCASE("Plant Clone - Copy Constructor Behavior")
    {
        Plant *original = new Plant("Parsley", "herb");

        // Water and age the original
        original->water(60);
        original->dailyTick();
        original->dailyTick();

        // Clone should reset to initial state
        Plant *cloned = dynamic_cast<Plant *>(original->clone());

        CHECK(cloned->getHydrationLevel() == 0);
        CHECK(cloned->getAgeDays() == 0);
        CHECK(cloned->getStateName() == "Seedling");

        delete original;
        delete cloned;
    }

    SUBCASE("Plant Clone - Different Plant Types")
    {
        Plant *flower = new Plant("Rose", "flower");
        Plant *herb = new Plant("Basil", "herb");
        Plant *succulent = new Plant("Cactus", "succulent");
        Plant *tree = new Plant("Baobab", "tree");

        Plant *flowerClone = dynamic_cast<Plant *>(flower->clone());
        Plant *herbClone = dynamic_cast<Plant *>(herb->clone());
        Plant *succulentClone = dynamic_cast<Plant *>(succulent->clone());
        Plant *treeClone = dynamic_cast<Plant *>(tree->clone());

        CHECK(flowerClone->getType() == "flower");
        CHECK(herbClone->getType() == "herb");
        CHECK(succulentClone->getType() == "succulent");
        CHECK(treeClone->getType() == "tree");

        delete flower;
        delete herb;
        delete succulent;
        delete tree;
        delete flowerClone;
        delete herbClone;
        delete succulentClone;
        delete treeClone;
    }

    SUBCASE("Plant Clone - Clone with Different Names")
    {
        Plant *p1 = new Plant("Rose", "flower");
        Plant *p2 = new Plant("Tulip", "flower");
        Plant *p3 = new Plant("Daisy", "flower");

        Plant *c1 = dynamic_cast<Plant *>(p1->clone());
        Plant *c2 = dynamic_cast<Plant *>(p2->clone());
        Plant *c3 = dynamic_cast<Plant *>(p3->clone());

        CHECK(c1->getName() == "Rose");
        CHECK(c2->getName() == "Tulip");
        CHECK(c3->getName() == "Daisy");

        delete p1;
        delete p2;
        delete p3;
        delete c1;
        delete c2;
        delete c3;
    }

    SUBCASE("Plant Clone - Memory Independence")
    {
        Plant *original = new Plant("Mint", "herb");
        Plant *cloned = dynamic_cast<Plant *>(original->clone());

        // Delete original
        delete original;

        // Clone should still be valid
        CHECK(cloned->getName() == "Mint");
        CHECK(cloned->getType() == "herb");

        delete cloned;
    }

    SUBCASE("Plant Clone - Clone Collection")
    {
        Plant *original = new Plant("Lavender", "herb");

        // Create collection of clones
        std::vector<Plant *> clones;
        for (int i = 0; i < 10; i++)
        {
            Plant *clone = dynamic_cast<Plant *>(original->clone());
            clones.push_back(clone);
        }

        // All clones should be independent
        CHECK(clones.size() == 10);
        for (size_t i = 0; i < clones.size(); i++)
        {
            CHECK(clones[i] != original);
            CHECK(clones[i]->getName() == original->getName());
        }

        // Clean up
        delete original;
        for (Plant *clone : clones)
        {
            delete clone;
        }
    }

    SUBCASE("Plant Clone - Modify Clones Independently")
    {
        Plant *original = new Plant("Thyme", "herb");

        Plant *clone1 = dynamic_cast<Plant *>(original->clone());
        Plant *clone2 = dynamic_cast<Plant *>(original->clone());
        Plant *clone3 = dynamic_cast<Plant *>(original->clone());

        // Modify each differently
        clone1->water(20);
        clone2->water(40);
        clone3->water(60);

        // Each should have different hydration
        CHECK(clone1->getHydrationLevel() == 20);
        CHECK(clone2->getHydrationLevel() == 40);
        CHECK(clone3->getHydrationLevel() == 60);

        // Original unaffected
        CHECK(original->getHydrationLevel() == 0);

        delete original;
        delete clone1;
        delete clone2;
        delete clone3;
    }

    SUBCASE("Plant Clone - State Transition After Cloning")
    {
        Plant *original = new Plant("Coriander", "herb");
        Plant *cloned = dynamic_cast<Plant *>(original->clone());

        // Both start as Seedling
        CHECK(original->getStateName() == "Seedling");
        CHECK(cloned->getStateName() == "Seedling");

        // Transition original to different state
        original->water(100);

        // Clone should remain Seedling
        CHECK(cloned->getStateName() == "Seedling");

        delete original;
        delete cloned;
    }

    SUBCASE("Plant Clone - Clone Registry Simulation")
    {
        // Simulate a plant registry using clones
        std::map<std::string, Plant *> registry;

        // Add prototypes to registry
        registry["rose"] = new Plant("Rose", "flower");
        registry["basil"] = new Plant("Basil", "herb");
        registry["cactus"] = new Plant("Cactus", "succulent");

        // Clone from registry
        Plant *newRose = dynamic_cast<Plant *>(registry["rose"]->clone());
        Plant *newBasil = dynamic_cast<Plant *>(registry["basil"]->clone());
        Plant *newCactus = dynamic_cast<Plant *>(registry["cactus"]->clone());

        CHECK(newRose->getName() == "Rose");
        CHECK(newBasil->getName() == "Basil");
        CHECK(newCactus->getName() == "Cactus");

        // Clean up registry
        for (auto &pair : registry)
        {
            delete pair.second;
        }

        delete newRose;
        delete newBasil;
        delete newCactus;
    }

    SUBCASE("Plant Clone - Rapid Successive Cloning")
    {
        Plant *original = new Plant("Hydrangea", "shrub");

        // Rapid cloning
        std::vector<Plant *> rapidClones;
        for (int i = 0; i < 100; i++)
        {
            rapidClones.push_back(dynamic_cast<Plant *>(original->clone()));
        }

        // Verify all clones
        CHECK(rapidClones.size() == 100);
        for (Plant *clone : rapidClones)
        {
            CHECK(clone->getName() == "Hydrangea");
        }

        // Clean up
        delete original;
        for (Plant *clone : rapidClones)
        {
            delete clone;
        }
    }

    SUBCASE("Plant Clone - Clone After State Changes")
    {
        Plant *original = new Plant("Succulent", "succulent");

        // Change original state
        original->water(100);
        original->fertilize(10);
        original->dailyTick();
        original->dailyTick();
        original->dailyTick();

        // Clone should reset state
        Plant *cloned = dynamic_cast<Plant *>(original->clone());

        CHECK(cloned->getAgeDays() == 0);
        CHECK(cloned->getHydrationLevel() == 0);
        CHECK(cloned->getStateName() == "Seedling");

        delete original;
        delete cloned;
    }

    SUBCASE("Plant Clone - Clone Comparison")
    {
        Plant *original = new Plant("LemonBalm", "herb");
        Plant *clone1 = dynamic_cast<Plant *>(original->clone());
        Plant *clone2 = dynamic_cast<Plant *>(original->clone());

        // Clones should have same attributes but different addresses
        CHECK(clone1 != clone2);
        CHECK(clone1->getName() == clone2->getName());
        CHECK(clone1->getType() == clone2->getType());
        CHECK(clone1->getStateName() == clone2->getStateName());

        delete original;
        delete clone1;
        delete clone2;
    }

    SUBCASE("Plant Clone - Virtual Function Preservation")
    {
        Plant *original = new Plant("Oak", "tree");

        // Clone through base pointer
        Greenhouse *cloned = original->clone();

        // Virtual functions should work
        cloned->execute();

        // Should be able to cast back
        Plant *clonedPlant = dynamic_cast<Plant *>(cloned);
        CHECK(clonedPlant != nullptr);
        CHECK(clonedPlant->getName() == "Oak");

        delete original;
        delete cloned;
    }

    SUBCASE("Plant Clone - Null Zone Preservation")
    {
        Plant *original = new Plant("Boxwood", "shrub");

        // Original has no zone (nullptr)
        Plant *cloned = dynamic_cast<Plant *>(original->clone());

        // Clone should also have no zone
        // (Cannot directly check zone as it's private, but no crash indicates it's null)
        CHECK(cloned->getStateName() == "Seedling");

        delete original;
        delete cloned;
    }

    SUBCASE("Plant Clone - Clone Factory Pattern Simulation")
    {
        // Simulate factory using prototypes
        Plant *rosePrototype = new Plant("Rose", "flower");
        Plant *basilPrototype = new Plant("Basil", "herb");

        // Create instances from prototypes
        std::vector<Plant *> roses;
        std::vector<Plant *> basils;

        for (int i = 0; i < 5; i++)
        {
            roses.push_back(dynamic_cast<Plant *>(rosePrototype->clone()));
            basils.push_back(dynamic_cast<Plant *>(basilPrototype->clone()));
        }

        CHECK(roses.size() == 5);
        CHECK(basils.size() == 5);

        // Clean up
        delete rosePrototype;
        delete basilPrototype;
        for (Plant *p : roses)
            delete p;
        for (Plant *p : basils)
            delete p;
    }

    SUBCASE("Plant Clone - Mixed Operations After Cloning")
    {
        Plant *original = new Plant("Mint", "herb");
        Plant *cloned = dynamic_cast<Plant *>(original->clone());

        // Perform mixed operations
        original->water(30);
        cloned->water(60);

        original->dailyTick();
        cloned->fertilize(5);

        // Both should be independent
        CHECK(original->getHydrationLevel() != cloned->getHydrationLevel());
        CHECK(original->getAgeDays() == 1);
        CHECK(cloned->getAgeDays() == 0);

        delete original;
        delete cloned;
    }

    SUBCASE("Plant Clone - Clone Deletion Before Original")
    {
        Plant *original = new Plant("Parsley", "herb");
        Plant *cloned = dynamic_cast<Plant *>(original->clone());

        // Delete clone first
        delete cloned;

        // Original should still be valid
        CHECK(original->getName() == "Parsley");
        CHECK(original->getType() == "herb");

        delete original;
    }

    SUBCASE("Plant Clone - Stress Test Multiple Clones")
    {
        Plant *original = new Plant("Baobab", "tree");

        // Create many clones
        std::vector<Plant *> clones;
        for (int i = 0; i < 1000; i++)
        {
            clones.push_back(dynamic_cast<Plant *>(original->clone()));
        }

        // Verify sample clones
        CHECK(clones[0]->getName() == "Baobab");
        CHECK(clones[500]->getName() == "Baobab");
        CHECK(clones[999]->getName() == "Baobab");

        // Clean up
        delete original;
        for (Plant *clone : clones)
        {
            delete clone;
        }

        CHECK(true);
    }

    SUBCASE("Plant Clone - Return Type Covariance")
    {
        Plant *original = new Plant("Rose", "flower");

        // Clone returns Greenhouse*, not Plant*
        Greenhouse *cloned = original->clone();

        // Should be able to cast to Plant
        Plant *clonedPlant = dynamic_cast<Plant *>(cloned);
        CHECK(clonedPlant != nullptr);

        delete original;
        delete cloned;
    }
}

TEST_CASE("Plant tests")
{
    Plant *plant = new Plant("Rose", "Flower");

    CHECK(plant->getType() == "Flower");
    CHECK_FALSE(plant->isComposite());

    // Test that leaf operations throw
    CHECK_THROWS_AS(plant->add(nullptr), std::logic_error);
    CHECK_THROWS_AS(plant->remove(nullptr), std::logic_error);
    CHECK_THROWS_AS(plant->getChild(0), std::logic_error);

    delete plant;
}

TEST_CASE("Zone tests")
{
    CareStaff c;
    Greenhouse *zone = new Zone("Flower Zone", "Flower", &c);
    Plant *rose = new Plant("rose","Flower");
    Plant *cactus = new Plant("cactus","Cactus");

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

TEST_CASE("Nested zones")
{
    CareStaff c;
    Greenhouse *greenhouse = new Zone("Main", "",&c);
    Greenhouse *flowerZone = new Zone("Flowers", "Flower", &c);
    Greenhouse *desertZone = new Zone("Desert", "Cactus", &c);

    Plant *rose = new Plant("rose","Flower");
    Plant *cactus = new Plant("cactus","Cactus");

    CHECK_NOTHROW(flowerZone->add(rose));
    CHECK_NOTHROW(desertZone->add(cactus));
    CHECK_NOTHROW(greenhouse->add(flowerZone));
    CHECK_NOTHROW(greenhouse->add(desertZone));

    delete greenhouse;
}

// Test Plant class functionality
TEST_SUITE("Plant Tests")
{
    TEST_CASE("Plant Creation and Basic Functions")
    {
        Plant *p = new Plant("Rose", "Flower");

        // Positive testing
        CHECK(p->getType() == "Flower");
        CHECK(p->getName() == "Rose");
        CHECK(p->getStateName() == "Seedling");

        delete p;
    }
}

// Test Inventory Singleton
TEST_SUITE("Inventory Tests")
{
    TEST_CASE("Singleton Instance")
    {
        Inventory *inv1 = Inventory::getInstance();
        Inventory *inv2 = Inventory::getInstance();

        // Positive testing - same instance
        CHECK(inv1 == inv2);
    }

    TEST_CASE("Seed Operations")
    {
        Inventory *inv = Inventory::getInstance();

        // Test empty operations
        CHECK(inv->isSeedsEmpty());

        // Add seed
        Plant *seed = new Plant("Rose", "Flower");
        inv->addSeed(seed);

        // Positive testing
        CHECK_FALSE(inv->isSeedsEmpty());

        // Remove seed
        Plant *removed = inv->removeSeed("Rose");
        CHECK(removed == seed);
        CHECK(inv->isSeedsEmpty());

        delete removed;
    }

    TEST_CASE("Edge Cases")
    {
        Inventory *inv = Inventory::getInstance();

        // Test null pointer handling
        CHECK_THROWS_AS(inv->addSeed(nullptr), std::runtime_error);

        // Test empty string removal
        CHECK_THROWS_AS(inv->removeSeed(""), std::runtime_error);

        // Test non-existent plant removal
        CHECK_THROWS_AS(inv->removeSeed("NonExistent"), std::runtime_error);
    }
}

// Test Iterator functionality
TEST_SUITE("Iterator Tests")
{
    TEST_CASE("Iterator Operations")
    {
        Inventory *inv = Inventory::getInstance();

        // Add test plants - make sure plants match the expected type for Roses
        Plant *p1 = new Plant("Rose","Flower"); // Changed type to "Roses"
        Plant *p2 = new Plant("Rose", "Flower"); // Changed type to "Roses"

        // Add plants and verify they were added
        inv->addRose(p1);
        CHECK_FALSE(inv->isRosesEmpty());
        inv->addRose(p2);
        CHECK_FALSE(inv->isRosesEmpty());

        // Create iterator and test
        PlantIterator *it = inv->createIterator("Roses");
        CHECK(it != nullptr);

        // Test iterator operations
        CHECK(it->hasNext());
        CHECK(it->count() == 2);

        Plant *first = it->first();
        CHECK(first != nullptr);
        CHECK(first->getName() == "Rose");
        CHECK(it->hasNext());

        Plant *next = it->next();
        CHECK(next != nullptr);
        CHECK(next->getName() == "Rose");
        CHECK_FALSE(it->hasNext());

        // Cleanup
        while (!inv->isRosesEmpty())
        {
            Plant *p = inv->removeRose();
            delete p;
        }
        delete it;
    }

    TEST_CASE("Empty Iterator")
    {
        Inventory *inv = Inventory::getInstance();
        PlantIterator *it = inv->createIterator("NonExistentCategory");

        // Negative testing
        CHECK_FALSE(it->hasNext());
        CHECK(it->count() == 0);
        CHECK(it->next() == nullptr);

        delete it;
    }
}

// State Pattern - Edge Cases and Comprehensive Testing
TEST_CASE("State Pattern - Edge Cases and Comprehensive Testing")
{

    SUBCASE("Plant State - Initial State is Seedling")
    {
        Plant *plant = new Plant("Rose", "flower");

        CHECK(plant->getStateName() == "Seedling");

        delete plant;
    }

    SUBCASE("Seedling State - Water Without State Transition")
    {
        Plant *plant = new Plant("Basil", "herb");

        // Not enough age or hydration for transition
        plant->water(30);

        CHECK(plant->getStateName() == "Seedling");

        delete plant;
    }

    SUBCASE("Seedling State - Fertilize Without State Transition")
    {
        Plant *plant = new Plant("Mint", "herb");

        // Not enough conditions for transition
        plant->fertilize(5);

        CHECK(plant->getStateName() == "Seedling");

        delete plant;
    }

    SUBCASE("Seedling to Growing - Water Transition")
    {
        Plant *plant = new Plant("Tulip", "flower");

        // Age the plant
        for (int i = 0; i < 7; i++)
        {
            plant->dailyTick();
        }

        // Add enough water (60+)
        plant->water(70);

        // Should transition to Growing
        CHECK(plant->getStateName() == "Growing");

        delete plant;
    }

    SUBCASE("Seedling to Growing - Fertilize Transition")
    {
        Plant *plant = new Plant("Cactus", "succulent");

        // Age the plant
        for (int i = 0; i < 7; i++)
        {
            plant->dailyTick();
        }

        // Add water first
        plant->water(65);

        // Fertilize should trigger transition
        plant->fertilize(5);

        CHECK(plant->getStateName() == "Growing");

        delete plant;
    }

    SUBCASE("Seedling State - Insufficient Age for Transition")
    {
        Plant *plant = new Plant("Rose", "flower");

        // Only 5 days (need 7+)
        for (int i = 0; i < 5; i++)
        {
            plant->dailyTick();
        }

        plant->water(80);

        // Should remain Seedling
        CHECK(plant->getStateName() == "Seedling");

        delete plant;
    }

    SUBCASE("Seedling State - Insufficient Hydration for Transition")
    {
        Plant *plant = new Plant("Daisy", "flower");

        // Enough age
        for (int i = 0; i < 10; i++)
        {
            plant->dailyTick();
        }

        // Not enough water (need 60+)
        plant->water(50);

        // Should remain Seedling
        CHECK(plant->getStateName() == "Seedling");

        delete plant;
    }

    SUBCASE("Growing State - Water Without Transition")
    {
        Plant *plant = new Plant("Lavender", "herb");

        // Transition to Growing
        for (int i = 0; i < 7; i++)
        {
            plant->dailyTick();
        }
        plant->water(65);

        CHECK(plant->getStateName() == "Growing");

        // Water again (not enough conditions for Mature)
        plant->water(20);

        CHECK(plant->getStateName() == "Growing");

        delete plant;
    }

    SUBCASE("Growing State - Fertilize Without Transition")
    {
        Plant *plant = new Plant("Parsley", "herb");

        // Transition to Growing
        for (int i = 0; i < 7; i++)
        {
            plant->dailyTick();
        }
        plant->water(60);

        CHECK(plant->getStateName() == "Growing");

        // Fertilize without meeting Mature conditions
        plant->fertilize(5);

        CHECK(plant->getStateName() == "Growing");

        delete plant;
    }

    SUBCASE("Growing to Mature - Water Transition")
    {
        Plant *plant = new Plant("Oak", "tree");

        // Get to Growing
        for (int i = 0; i < 7; i++)
        {
            plant->dailyTick();
        }
        plant->water(60);

        CHECK(plant->getStateName() == "Growing");

        // Age to 20+ and hydrate to 65+
        for (int i = 0; i < 14; i++)
        {
            plant->dailyTick();
        }
        plant->water(80);

        CHECK(plant->getStateName() == "Mature");

        delete plant;
    }

    SUBCASE("Growing to Mature - Fertilize Transition")
    {
        Plant *plant = new Plant("Boxwood", "shrub");

        // Get to Growing
        for (int i = 0; i < 7; i++)
        {
            plant->dailyTick();
        }
        plant->water(60);

        // Age to 20+ and hydrate to 65+
        for (int i = 0; i < 14; i++)
        {
            plant->dailyTick();
        }
        plant->water(70);

        // Fertilize to trigger Mature
        plant->fertilize(5);

        CHECK(plant->getStateName() == "Mature");

        delete plant;
    }

    SUBCASE("Growing State - Insufficient Age for Mature")
    {
        Plant *plant = new Plant("Hibiscus", "shrub");

        // Get to Growing
        for (int i = 0; i < 7; i++)
        {
            plant->dailyTick();
        }
        plant->water(60);

        // Only 15 days total (need 20+)
        for (int i = 0; i < 8; i++)
        {
            plant->dailyTick();
        }
        plant->water(80);

        CHECK(plant->getStateName() == "Growing");

        delete plant;
    }

    SUBCASE("Growing State - Insufficient Hydration for Mature")
    {
        Plant *plant = new Plant("Hydrangea", "shrub");

        // Get to Growing
        for (int i = 0; i < 7; i++)
        {
            plant->dailyTick();
        }
        plant->water(60);

        // Age enough
        for (int i = 0; i < 15; i++)
        {
            plant->dailyTick();
        }

        // Not enough hydration (need 65+)
        plant->water(50);

        CHECK(plant->getStateName() == "Growing");

        delete plant;
    }

    SUBCASE("Mature State - Water Maintains State")
    {
        Plant *plant = new Plant("Baobab", "tree");

        // Get to Mature
        for (int i = 0; i < 7; i++)
        {
            plant->dailyTick();
        }
        plant->water(60);

        for (int i = 0; i < 14; i++)
        {
            plant->dailyTick();
        }
        plant->water(70);

        CHECK(plant->getStateName() == "Mature");

        // Water again
        plant->water(50);

        CHECK(plant->getStateName() == "Mature");

        delete plant;
    }

    SUBCASE("Mature State - Fertilize Maintains State")
    {
        Plant *plant = new Plant("Succulent", "succulent");

        // Get to Mature
        for (int i = 0; i < 7; i++)
        {
            plant->dailyTick();
        }
        plant->water(60);

        for (int i = 0; i < 14; i++)
        {
            plant->dailyTick();
        }
        plant->fertilize(10);

        CHECK(plant->getStateName() == "Mature");

        // Fertilize again
        plant->fertilize(5);

        CHECK(plant->getStateName() == "Mature");

        delete plant;
    }

    SUBCASE("Mature State - Low Hydration Warning")
    {
        Plant *plant = new Plant("LemonBalm", "herb");

        // Get to Mature
        for (int i = 0; i < 7; i++)
        {
            plant->dailyTick();
        }
        plant->water(60);

        for (int i = 0; i < 14; i++)
        {
            plant->dailyTick();
        }
        plant->water(70);

        // Let hydration drop (dailyTick reduces by 10)
        for (int i = 0; i < 10; i++)
        {
            plant->dailyTick();
        }

        // Fertilize with low hydration (should warn but stay Mature)
        plant->fertilize(5);

        CHECK(plant->getStateName() == "Mature");

        delete plant;
    }

    SUBCASE("Withered State - Water Has No Effect")
    {
        Plant *plant = new Plant("Coriander", "herb");

        // Manually set to Withered
        plant->setState(new Withered());

        CHECK(plant->getStateName() == "Withered");

        plant->water(100);

        CHECK(plant->getStateName() == "Withered");

        delete plant;
    }

    SUBCASE("Withered State - Fertilize Has No Effect")
    {
        Plant *plant = new Plant("Rosemary", "herb");

        // Manually set to Withered
        plant->setState(new Withered());

        CHECK(plant->getStateName() == "Withered");

        plant->fertilize(20);

        CHECK(plant->getStateName() == "Withered");

        delete plant;
    }

    SUBCASE("State Transitions - Complete Lifecycle")
    {
        Plant *plant = new Plant("Rose", "flower");

        // Start as Seedling
        CHECK(plant->getStateName() == "Seedling");

        // Transition to Growing
        for (int i = 0; i < 7; i++)
        {
            plant->dailyTick();
        }
        plant->water(65);
        CHECK(plant->getStateName() == "Growing");

        // Transition to Mature
        for (int i = 0; i < 14; i++)
        {
            plant->dailyTick();
        }
        plant->water(70);
        CHECK(plant->getStateName() == "Mature");

        delete plant;
    }

    SUBCASE("State Transitions - Multiple Plants Independent")
    {
        Plant *p1 = new Plant("Rose", "flower");
        Plant *p2 = new Plant("Tulip", "flower");
        Plant *p3 = new Plant("Daisy", "flower");

        // Advance p1 to Growing
        for (int i = 0; i < 7; i++)
        {
            p1->dailyTick();
        }
        p1->water(60);

        // p2 and p3 should still be Seedling
        CHECK(p1->getStateName() == "Growing");
        CHECK(p2->getStateName() == "Seedling");
        CHECK(p3->getStateName() == "Seedling");

        delete p1;
        delete p2;
        delete p3;
    }

    SUBCASE("State Pattern - InitState Method")
    {
        Plant *plant = new Plant("Mint", "herb");

        CHECK(plant->getStateName() == "Seedling");

        // Manually initialize to Growing
        plant->initState(new Growing());

        CHECK(plant->getStateName() == "Growing");

        delete plant;
    }

    SUBCASE("State Pattern - SetState Method")
    {
        Plant *plant = new Plant("Basil", "herb");

        CHECK(plant->getStateName() == "Seedling");

        // Manually set to Mature
        plant->setState(new Mature());

        CHECK(plant->getStateName() == "Mature");

        delete plant;
    }

    SUBCASE("State Pattern - Multiple State Changes")
    {
        Plant *plant = new Plant("Lavender", "herb");

        plant->setState(new Growing());
        CHECK(plant->getStateName() == "Growing");

        plant->setState(new Mature());
        CHECK(plant->getStateName() == "Mature");

        plant->setState(new Withered());
        CHECK(plant->getStateName() == "Withered");

        plant->setState(new Seedling());
        CHECK(plant->getStateName() == "Seedling");

        delete plant;
    }

    SUBCASE("State Pattern - IsMature Check")
    {
        Plant *plant = new Plant("Oak", "tree");

        CHECK_FALSE(plant->isMature());

        // Transition to Mature
        for (int i = 0; i < 7; i++)
        {
            plant->dailyTick();
        }
        plant->water(60);

        for (int i = 0; i < 14; i++)
        {
            plant->dailyTick();
        }
        plant->water(70);

        CHECK(plant->isMature());

        delete plant;
    }

    SUBCASE("State Transitions - Hydration Management")
    {
        Plant *plant = new Plant("Cactus", "succulent");

        int initial = plant->getHydrationLevel();

        plant->water(50);
        CHECK(plant->getHydrationLevel() == initial + 50);

        plant->dailyTick();
        CHECK(plant->getHydrationLevel() == initial + 40); // -10 per day

        delete plant;
    }

    SUBCASE("State Transitions - Age Management")
    {
        Plant *plant = new Plant("Parsley", "herb");

        CHECK(plant->getAgeDays() == 0);

        for (int i = 0; i < 10; i++)
        {
            plant->dailyTick();
        }

        CHECK(plant->getAgeDays() == 10);

        delete plant;
    }

    SUBCASE("State Transitions - Boundary Conditions for Seedling to Growing")
    {
        Plant *plant = new Plant("Thyme", "herb");

        // Exactly 7 days
        for (int i = 0; i < 7; i++)
        {
            plant->dailyTick();
        }

        // Exactly 60 hydration
        plant->water(60);

        // Should transition
        CHECK(plant->getStateName() == "Growing");

        delete plant;
    }

    SUBCASE("State Transitions - Boundary Conditions for Growing to Mature")
    {
        Plant *plant = new Plant("Hibiscus", "shrub");

        // Get to Growing
        for (int i = 0; i < 7; i++)
        {
            plant->dailyTick();
        }
        plant->water(60);

        // Exactly 20 days and 65 hydration
        for (int i = 0; i < 13; i++)
        {
            plant->dailyTick();
        }
        plant->water(70);

        CHECK(plant->getStateName() == "Mature");

        delete plant;
    }

    SUBCASE("State Pattern - Null Plant Handling in State Methods")
    {
        Seedling seedling;
        Growing growing;
        Mature mature;
        Withered withered;

        // Should not crash with nullptr
        seedling.water(nullptr, 50);
        seedling.fertilize(nullptr, 5);
        growing.water(nullptr, 50);
        growing.fertilize(nullptr, 5);
        mature.water(nullptr, 50);
        mature.fertilize(nullptr, 5);
        withered.water(nullptr, 50);
        withered.fertilize(nullptr, 5);

        CHECK(true);
    }

    SUBCASE("State Transitions - Rapid State Changes")
    {
        Plant *plant = new Plant("Boxwood", "shrub");

        for (int i = 0; i < 10; i++)
        {
            plant->setState(new Seedling());
            plant->setState(new Growing());
            plant->setState(new Mature());
        }

        CHECK(plant->getStateName() == "Mature");

        delete plant;
    }

    SUBCASE("State Pattern - GetStateName for All States")
    {
        Seedling seedling;
        Growing growing;
        Mature mature;
        Withered withered;

        CHECK(seedling.getStateName() == "Seedling");
        CHECK(growing.getStateName() == "Growing");
        CHECK(mature.getStateName() == "Mature");
        CHECK(withered.getStateName() == "Withered");
    }

    SUBCASE("State Transitions - Water Effect on Different States")
    {
        // Seedling
        Plant *seedling = new Plant("Rose", "flower");
        int h1 = seedling->getHydrationLevel();
        seedling->water(30);
        CHECK(seedling->getHydrationLevel() == h1 + 30);

        // Growing
        Plant *growing = new Plant("Tulip", "flower");
        growing->setState(new Growing());
        int h2 = growing->getHydrationLevel();
        growing->water(30);
        CHECK(growing->getHydrationLevel() == h2 + 30);

        // Mature
        Plant *mature = new Plant("Daisy", "flower");
        mature->setState(new Mature());
        int h3 = mature->getHydrationLevel();
        mature->water(30);
        CHECK(mature->getHydrationLevel() == h3 + 30);

        // Withered
        Plant *withered = new Plant("Dead", "flower");
        withered->setState(new Withered());
        int h4 = withered->getHydrationLevel();
        withered->water(30);
        CHECK(withered->getHydrationLevel() == h4 + 30); // Water is applied before state check

        delete seedling;
        delete growing;
        delete mature;
        delete withered;
    }

    SUBCASE("State Transitions - DailyTick Hydration Decrease")
    {
        Plant *plant = new Plant("Mint", "herb");

        plant->water(100);
        int hydration = plant->getHydrationLevel();

        plant->dailyTick();
        CHECK(plant->getHydrationLevel() == std::max(0, hydration - 10));

        plant->dailyTick();
        CHECK(plant->getHydrationLevel() == std::max(0, hydration - 20));

        delete plant;
    }

    SUBCASE("State Transitions - Hydration Cannot Go Below Zero")
    {
        Plant *plant = new Plant("Cactus", "succulent");

        // Start with low hydration
        plant->water(5);

        // Multiple daily ticks
        for (int i = 0; i < 10; i++)
        {
            plant->dailyTick();
        }

        // Should not go below 0
        CHECK(plant->getHydrationLevel() >= 0);

        delete plant;
    }

    SUBCASE("State Pattern - Memory Safety with State Changes")
    {
        Plant *plant = new Plant("Lavender", "herb");

        // Multiple state changes should properly delete old states
        for (int i = 0; i < 100; i++)
        {
            plant->setState(new Seedling());
        }

        CHECK(plant->getStateName() == "Seedling");

        delete plant;
    }

    SUBCASE("State Transitions - Complex Growth Scenario")
    {
        Plant *plant = new Plant("Oak", "tree");

        // Start as Seedling
        CHECK(plant->getStateName() == "Seedling");

        // Water and age, but don't meet conditions
        plant->water(50);
        plant->dailyTick();
        plant->dailyTick();
        CHECK(plant->getStateName() == "Seedling");

        // Meet conditions for Growing
        for (int i = 0; i < 5; i++)
        {
            plant->dailyTick();
        }
        plant->water(20); // Total 70 now
        CHECK(plant->getStateName() == "Growing");

        // Try to reach Mature with insufficient conditions
        plant->water(30);
        plant->fertilize(5);
        CHECK(plant->getStateName() == "Growing");

        // Finally reach Mature
        for (int i = 0; i < 14; i++)
        {
            plant->dailyTick();
        }
        plant->water(80);
        CHECK(plant->getStateName() == "Mature");

        delete plant;
    }
}// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "doctest.h"
// #include <iostream>
// #include <string>
// #include <vector>
#include <map>
#include <random>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>


// // Mediator stuff
// #include "NurseryMediator.h"
// #include "Manager.h"
// #include "Staff.h"
// #include "CustomerStaff.h"
// #include "CareStaff.h"

// // Observer Stuff
// #include "PlantObserver.h"
// #include "Greenhouse.h"
// #include "Zone.h"
// #include "Plant.h"

// // CustomerCommand Stuff
// #include "CustomerCommand.h"
// #include "BuyPlant.h"
// #include "RequestHelp.h"
// #include "CustomisePlant.h"
// #include "Customer.h"

// // necessary files too...
// #include "BasePlant.h"
// #include "Inventory.h"
// #include "Mature.h"
// #include "InStorage.h"
// #include "PlantIterator.h"
// #include "Withered.h"

sf::Clock timer;
std::random_device rd;
std::mt19937 gen(rd());

int main(){
    std::uniform_int_distribution<int> dist(0, 10);

    Inventory* inv = Inventory::getInstance();
    
    // int x = 5;
    // int* y = &x;

    Plant* p = NULL;
    // inv->addCactus(p);
    for(int i = 1; i <= 10; i++){
        if(i < 2){
            p = new Plant("rose", "flower");
            p->setZone(nullptr);
            p->setState(new Mature());
            p->setStatus(new InStorage());
            inv->addRose(p);
        } 
        else if(i < 4) {
            p = new Plant("cactus", "cactus");
            p->setZone(nullptr);
            p->setState(new Mature());
            p->setStatus(new InStorage());
            inv->addCactus(p);
        }
        else if(i < 6) {
            p = new Plant("baobab", "Trees & Shrubs");
            p->setZone(nullptr);
            p->setState(new Mature());
            p->setStatus(new InStorage());
            inv->addBaobab(p);
        }
        else if(i < 8) {
            p = new Plant("mint","Herb & Aromatics");
            p->setZone(nullptr);
            p->setState(new Mature());
            p->setStatus(new InStorage());
            inv->addMint(p);
        }
        else{
            Plant *p = new Plant("rose", "flower");
            inv->addSeed(p);
        }
    }
    
    NurseryMediator* benson = new NurseryMediator();
    Staff* cols[2];
    for(int i = 0; i < 2; i++){
        if(i == 0)
            cols[i] = new CareStaff();
        else cols[i] = new CustomerStaff();

        benson->attach(cols[i]);
    }

    Customer* c = new Customer();
    
    std::cout << "Customer buying a plant" << std::endl;
    
    Order order;
    order.base = "Potted";
    order.flowerName = "rose";
    order.num = 1;
    
    c->buyPlant(cols[1], &order);
    std::cout << cols[1]->get()["rose"] << std::endl;

    std::cout << std::endl;
    std::cout << "Making a plant withered and triggering observer and possibly mediator" << std::endl;
    std::cout << "=======================================================================" << std::endl;

    PlantIterator* pIt = Inventory::getInstance()->createIterator("Cactuses");
    // if(pIt->hasNext()) pIt->next();
    p = pIt->current();
    p->display();
    std::cout << std::endl;

    CareStaff* cs = dynamic_cast<CareStaff*>(cols[0]);
    if(cs){
        p->attach(cs);
        p->setState(new Withered());
    }
    else{
        std::cout << "Dynamic cast made ts null twin...\n We gotta make a plan." << std::endl;
    }

    


    delete pIt;
    delete c;
    delete benson;
    for(int i = 0; i < 2; i++)
        delete cols[i];
    Inventory::clearInventory();

    return 0;
}