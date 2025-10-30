#include "CareStaff.h"
#include "Zone.h"
#include "Plant.h"

CareStaff::CareStaff(const string &name){
    std::cout << name << std::endl;
    this->setSubject(nullptr);
}
CareStaff::~CareStaff() {}

void CareStaff::performDuty() const {}

void CareStaff::water(int amount){
    if (!zone) return;
    Zone *z = dynamic_cast<Zone *>(this->zone);
    if (z){
        for (Greenhouse *plant : z->getChildren()){
            Plant *p = dynamic_cast<Plant *>(plant);
            if (p)
            {
                p->water(amount);
            }
        }
    }
}

void CareStaff::fertilise(int amount){
    if (!zone)
        return;
    Zone *z = dynamic_cast<Zone *>(this->zone);
    if (z)
    {
        for (Greenhouse *plant : z->getChildren())
        {
            Plant *p = dynamic_cast<Plant *>(plant);
            if (p)
            {
                p->fertilize(amount);
            }
        }
    }
}

void CareStaff::changed() {}

// CareStaff will say the plant they restocked, DeliveryStaff && CustomerStaff will say the plant they finished
std::map<std::string, bool> CareStaff::get(){
    return std::map<std::string, bool>();
}

// receive notification from the mediator
void CareStaff::set(std::map<std::string, bool>) {}

void CareStaff::update(/*PlantState* state*/) {}