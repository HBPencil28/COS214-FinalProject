#ifndef HIGHCARE_H
#define HIGHCARE_H

#include "CareStrategy.h"
#include <iostream>

class HighCare : public CareStrategy{
    public:
        HighCare(Plant *plant);
        ~HighCare();
        // void care() override;
        void care(CareStaff *staff) override;

    private:
};

#endif