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
    CustomisePlant(const std::string& name, int id, const std::string& details/*, Plant* toCustomise*/);
    void execute() override;    
};


#endif // CustomisePlant_H