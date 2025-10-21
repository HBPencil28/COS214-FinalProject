#ifndef CUSTOMERSTAFF_H
#define CUSTOMERSTAFF_H

#include "Staff.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CustomerStaff : public Staff {
public:    
    // handling buy plant command
    void changed() override;
    string get() override;
    void set(string) override;
    
    // handling request help command
    void advise(string issue); 

    // handling customise plant command
    void customise(Plant* plant, string accessory);

    // handling buy plant command
    void getRequestedPlant(std::string plantDetails);
};

#endif