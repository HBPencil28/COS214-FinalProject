#ifndef CUSTOMERSTAFF_H
#define CUSTOMERSTAFF_H

#include "Staff.h"
#include "BasePlant.h"
#include "BuildPlantDirector.h"
#include "PotPlantBuilder.h"
#include "WrapPlantBuilder.h"
#include "PottedPlant.h"
#include "WrappedPlant.h"
#include "order.h"
#include "String.h"
#include "Ribbon.h"
#include "Bow.h"


#include <iostream>
#include "string.h"
#include <string>
#include <vector>

using namespace std;

class CustomerStaff : public Staff, public BuildPlantDirector {
private:
    Plant* getFromInventory(std::string, bool&);
public:    
    // handling buy plant command
    void changed() override;
    std::map<std::string, bool> get() override;
    void set(std::map<std::string, bool>) override;
    // handling request help command
    void advise(string issue); 

    // handling customise plant command
    BasePlant* customise(BasePlant* plant, string accessory);

    // handling buy plant command
    BasePlant* getRequestedPlant(Order plantDetails);

    bool checkAvailability(std::string);


};

#endif