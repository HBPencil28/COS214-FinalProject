#include "CustomerFactory.h"

Staff* CustomerFactory::createStaff(const string& name) const {
    cout << "Creating Customer Staff: " << name << endl;
    return new CustomerStaff(name);
}