#ifndef BuyPlant_H
#define BuyPlant_H

#include <iostream>
#include <string>  
#include "CustomerCommand.h"
#include "order.h"

class Customer;

class BuyPlant : public CustomerCommand {

private:
    Order plantDetails;
    Customer* customer;

public:
    BuyPlant(Order& plant, Staff* staff, Customer* rec) : 
    CustomerCommand(staff), plantDetails(plant), customer(rec) {};
    void execute() override;    
};


#endif // BuyPlant_H