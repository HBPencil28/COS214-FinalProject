#include "Customer.h"
#include "CustomerCommand.h"
#include "BuyPlant.h"
#include "RequestHelp.h"
#include "CustomisePlant.h"

Customer::~Customer(){
    for(BasePlant* b : purchases){
        if(b)
            delete b;
    }
}

void Customer::buyPlant(Staff* attender, Order* purchaseDetails){
    CustomerCommand* c = new BuyPlant(*purchaseDetails, attender, this);
    c->execute();
}

void Customer::requestHelp(Staff* attender, std::string& question){
    CustomerCommand* c = new RequestHelp(question, attender);
    c->execute();
}

void Customer::customiseMyPlant(Staff* attender, std::string& accessory){
    BasePlant* p = purchases.at(0);
    CustomerCommand* c = new CustomisePlant(accessory, attender, p, this);
    c->execute();
}

void Customer::addPurchases(BasePlant* p){
    purchases.push_back(p);
}