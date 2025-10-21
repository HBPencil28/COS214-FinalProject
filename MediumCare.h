#ifndef MEDIUMCARE_H
#define MEDIUMCARE_H

#include "CareStrategy.h"
#include <iostream>

class MediumCare : public CareStrategy{
    public:
        MediumCare();
        ~MediumCare();
        void care() override;
    private:
};

#endif