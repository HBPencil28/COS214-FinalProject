#ifndef CustomisePlant_H
#define CustomisePlant_H

#include <iostream>
#include <string>  
#include "CustomerCommand.h"
#include "BasePlant.h"
#include "Customer.h"

class CustomisePlant : public CustomerCommand {

private:
    BasePlant* toBeCustomized;
    std::string customisationDetails;
    Customer* customer;

public:
    CustomisePlant( const std::string& details, Staff* staff , BasePlant* toCustomise, Customer* receiver):
        CustomerCommand(staff), customisationDetails(details) , toBeCustomized(toCustomise), customer(receiver) {};
    void execute() override;    
};


#endif // CustomisePlant_H