#ifndef CARESTRATEGY_H
#define CARESTRATEGY_H

#include "CareStaff.h"
#include "CareCommand.h"
#include "WaterPlant.h"
#include "FertilisePlant.h"

class CareStrategy{
    public:
        CareStrategy(int water, int fertiliser, Zone *zone, CareStaff *c);
        virtual ~CareStrategy();
        // virtual void care() = 0;
        virtual void care() = 0;
    protected:
        const int water;
        const int fertiliser;
        Zone *zone;
        CareCommand* waterCommand;
        CareCommand* fertiliseCommand;
};

#endif