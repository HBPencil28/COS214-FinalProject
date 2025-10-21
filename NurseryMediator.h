#ifndef NURSERYMEDIATOR_H
#define NURSERYMEDIATOR_H

#include <string>
#include <vector>
#include <iostream>

#include "Staff.h"

class NurseryMediator {
private:
    std::vector<Staff*> staffMembers;
public:
    void attach(Staff* staff);
    void detach(Staff* staff);
    void notify(Staff* sender);

};

#endif // NURSERYMEDIATOR_H