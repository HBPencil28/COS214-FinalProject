#include "CareFactory.h"

Staff* CareFactory::createStaff(const string& name) const {
    cout << "Creating Care Staff: " << name << endl;
    return new CareStaff(name);
}