#ifndef HIGHCARE_H
#define HIGHCARE_H

#include "CareStrategy.h"
#include <iostream>

class HighCare : public CareStrategy{
    public:
        HighCare(Zone *zone, CareStaff *c);
        ~HighCare();
        // void care() override;
        void care() override;
};

#endif