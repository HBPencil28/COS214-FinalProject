#ifndef MEDIUMCARE_H
#define MEDIUMCARE_H

#include "CareStrategy.h"
#include <iostream>

class MediumCare : public CareStrategy{
    public:
        MediumCare(Plant *plant);
        ~MediumCare();
        // void care() override;
        void care(CareStaff* staff) override;
    private:
};

#endif