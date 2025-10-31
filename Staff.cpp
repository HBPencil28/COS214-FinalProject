#include "Staff.h"

Staff::Staff(const string& staffName, const string& staffType) : name(staffName), type(staffType) {}

Staff::~Staff() {}

string Staff::getName() const {
    return name;
}

string Staff::getType() const {
    return type;
}