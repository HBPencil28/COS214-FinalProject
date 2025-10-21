#ifndef REQUESTHELP_H
#define REQUESTHELP_H

#include <iostream>
#include <string>  
#include "CustomerCommand.h"

class RequestHelp : public CustomerCommand {

private:
    std::string issueDescription;

public:
    RequestHelp(const std::string& issue, Staff* staff) : CustomerCommand(staff), issueDescription(issue) {};
    void execute() override;    
};


#endif // REQUESTHELP_H