#ifndef CustomisePlant_H
#define CustomisePlant_H

#include <iostream>
#include <string>  
#include "CustomerCommand.h"

class CustomisePlant : public CustomerCommand {

private:
    // Plant* toBeCustomized;
    std::string customisationDetails;

public:
    CustomisePlant( const std::string& details, Staff* staff /*, Plant* toCustomise*/):
        CustomerCommand(staff), customisationDetails(details) /*, toBeCustomized(toCustomise)*/ {};
    void execute() override;    
};


#endif // CustomisePlant_H