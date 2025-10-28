#ifndef LOWCARE_H
#define LOWCARE_H

#include "CareStrategy.h"
#include <iostream>
#include <string>

class LowCare : public CareStrategy{
    public:
        LowCare(Zone *zone, CareStaff *c);
        ~LowCare();
        // void care() override;
        void care() override;

    private:
};

#endif