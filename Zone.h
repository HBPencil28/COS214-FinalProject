#ifndef ZONE_H
#define ZONE_H

#include <iostream>

#include "CareStrategy.h"

class Zone{
    public:
        Zone();
        ~Zone();
        void useStrategy();
        void setStrategy(CareStrategy* strategy);
    private:
        CareStrategy* strategy;
};

#endif