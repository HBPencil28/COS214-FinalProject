#ifndef LOWCARE_H
#define LOWCARE_H

#include "CareStrategy.h"
#include <iostream>

class LowCare : public CareStrategy{
    public:
        LowCare();
        ~LowCare();
        void care() override;
    private:
};

#endif