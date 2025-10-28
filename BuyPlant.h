#ifndef BuyPlant_H
#define BuyPlant_H

#include <iostream>
#include <string>  
#include "CustomerCommand.h"
#include "order.h"

class BuyPlant : public CustomerCommand {

private:
    Order plantDetails;

public:
    BuyPlant(Order& plant, Staff* staff) : CustomerCommand(staff), plantDetails(plant) {};
    void execute() override;    
};


#endif // BuyPlant_H