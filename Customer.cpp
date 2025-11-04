/**
 * @file Customer.cpp
 * @brief Implements the Customer class methods.
 */

#include "Customer.h"
#include "CustomerCommand.h"
#include "BuyPlant.h"
#include "RequestHelp.h"
#include "CustomisePlant.h"

Customer::~Customer() {
    for (BasePlant* b : purchases) {
        if (b)
            delete b;
    }
}

void Customer::buyPlant(Staff* attender, Order* purchaseDetails) {
    CustomerCommand* c = new BuyPlant(*purchaseDetails, attender, this);
    c->execute();
    delete c;
}

void Customer::requestHelp(Staff* attender, std::string& question) {
    CustomerCommand* c = new RequestHelp(question, attender);
    c->execute();
    delete c;
}

void Customer::customiseMyPlant(Staff* attender, std::string& accessory) {
    BasePlant* p = purchases.at(0);
    CustomerCommand* c = new CustomisePlant(accessory, attender, p, this);
    c->execute();
    delete c;
}

void Customer::addPurchases(BasePlant* p) {
    purchases.push_back(p);
}

void Customer::replacePurchase(BasePlant *oldPlant, BasePlant *newPlant){
    auto it = std::find(purchases.begin(), purchases.end(), oldPlant);
    if (it != purchases.end())
    {
        // Remove the old plant (but don't delete it - the decorator owns it now)
        purchases.erase(it);
        // Add the new decorated plant
        purchases.push_back(newPlant);
    }
}