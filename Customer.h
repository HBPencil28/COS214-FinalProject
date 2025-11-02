#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>

#include "order.h"
#include "BasePlant.h"
#include "Staff.h"
#include "CustomerStaff.h"



class Customer{
private:
    std::vector<BasePlant*> purchases;
    double wallet;

public:
    ~Customer();
    void buyPlant(Staff* attender, Order* purchaseDetails);
    void requestHelp(Staff* attender, std::string& question);
    void customiseMyPlant(Staff* attender, std::string& accessory);
    void addPurchases(BasePlant* p);

};



#endif // CUSTOMER_H