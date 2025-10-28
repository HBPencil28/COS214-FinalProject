#ifndef MEDIUMCARE_H
#define MEDIUMCARE_H

#include "CareStrategy.h"
#include <iostream>

class MediumCare : public CareStrategy{
    public:
        MediumCare(Zone *zone, CareStaff *c);
        ~MediumCare();
        // void care() override;
        void care() override;
    private:
};

#endif