#ifndef HIGHCARE_H
#define HIGHCARE_H

#include "CareStrategy.h"
#include <iostream>

class HighCare : public CareStrategy{
    public:
        HighCare();
        ~HighCare();
        void care() override;
    private:
};

#endif