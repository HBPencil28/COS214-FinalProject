#ifndef CARESTAFF_H
#define CARESTAFF_H

#include "Staff.h"
#include "PlantObserver.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CareStaff : public Staff, public PlantObserver {
private:
    void insertToInventory(Plant* plant, bool& toUpdate);

public:
    void update() override;
    void update(Plant* p) override;
    void changed() override;
    std::map<std::string, bool> get() override;
    void set(std::map<std::string, bool>) override;
    Plant* removeFromInventory(Plant* plant, bool& toUpdate);
};

#endif