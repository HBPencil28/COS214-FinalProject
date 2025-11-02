#ifndef CARECOMMAND_H
#define CARECOMMAND_H


#include <string>
#include <vector>
#include <iostream>

using namespace std;

class CareStaff;
class Zone;

class CareCommand{
protected:
    CareStaff *staff;

public:
    CareCommand(CareStaff* s) : staff(s) {}
    virtual void execute(Zone* z) = 0;
    virtual ~CareCommand() {}
};

#endif