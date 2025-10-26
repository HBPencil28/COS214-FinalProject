#ifndef LOWCARE_H
#define LOWCARE_H

#include "CareStrategy.h"
#include <iostream>
#include <string>

class LowCare : public CareStrategy{
    public:
        LowCare(Plant* plant);
        ~LowCare();
        // void care() override;
        void care(CareStaff *staff) override;

    private:
};

#endif