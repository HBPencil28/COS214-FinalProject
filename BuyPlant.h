#ifndef BuyPlant_H
#define BuyPlant_H

#include <iostream>
#include <string>  
#include "CustomerCommand.h"

class BuyPlant : public CustomerCommand {

private:
    std::string plantToPurchase;

public:
    BuyPlant(const std::string& name, int id, const std::string& plant);
    void execute() override;    
};


#endif // BuyPlant_H