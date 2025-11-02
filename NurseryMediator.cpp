#include "NurseryMediator.h"
#include "Staff.h"

NurseryMediator::~NurseryMediator() {
    for(Staff* staff : staffMembers) {
        detach(staff);
    }
    staffMembers.clear();
}

void NurseryMediator::attach(Staff* staff) {
    if(staff == nullptr) return;

    staffMembers.push_back(staff);
    staff->registerMediator(this);
}

void NurseryMediator::detach(Staff* staff) {
    std::vector<Staff*>::iterator it = std::find(staffMembers.begin(), staffMembers.end(), staff);
    if(it != staffMembers.end()) {
        (*it)->deregisterMediator();
        staffMembers.erase(it);
    }
}

void NurseryMediator::notify(Staff* sender) {
    for(Staff* staff : staffMembers) {
        if(staff != sender) {
            staff->set(sender->get());
        }
    }
}