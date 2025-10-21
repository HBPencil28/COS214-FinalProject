#ifndef CARESTRATEGY_H
#define CARESTRATEGY_H

class CareStrategy{
    public:
        CareStrategy(){};
        virtual ~CareStrategy(){};
        virtual void care() = 0;
    private:
};

#endif