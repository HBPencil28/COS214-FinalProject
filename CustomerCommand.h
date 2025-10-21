#ifndef CUSTOMERCOMMAND_H
#define CUSTOMERCOMMAND_H

#include <iostream>
#include <string>

#include "Staff.h"

class CustomerCommand{

protected:
    Staff* assistant;

public:
    CustomerCommand(Staff* staff) : assistant(staff) {};
    virtual void execute() = 0; 
};


#endif // CUSTOMERCOMMAND_H