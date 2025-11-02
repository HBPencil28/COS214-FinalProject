#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "doctest.h"
#include "Timer.h"

// Mediator stuff
#include "NurseryMediator.h"
#include "Manager.h"
#include "Staff.h"
#include "CustomerStaff.h"
#include "CareStaff.h"

// Observer Stuff
#include "PlantObserver.h"
#include "Greenhouse.h"
#include "Zone.h"
#include "Plant.h"

// CustomerCommand Stuff
#include "CustomerCommand.h"
#include "BuyPlant.h"
#include "RequestHelp.h"
#include "CustomisePlant.h"
#include "Customer.h"

// necessary files too...
#include "BasePlant.h"
#include "Inventory.h"

TEST_CASE("TESTNG MEDIATOR PATTERN:"){
    int x = 6;
    CHECK(x == 6);
}



