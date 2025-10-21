#ifndef CUSTOMERCOMMAND_H
#define CUSTOMERCOMMAND_H

#include <iostream>
#include <string>

class CustomerCommand{

protected:
    std::string customerName;
    int customerID;

public:
    CustomerCommand(const std::string& name, int id);
    virtual void execute() = 0; 
};


#endif // CUSTOMERCOMMAND_H