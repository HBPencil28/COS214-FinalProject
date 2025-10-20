#ifndef SOLD_H
#define SOLD_H

#include "PlantStatus.h"

class Sold : public PlantStatus {
public:
    ~Sold();

    std::string code() const ;
    void apply() ;
    void revoke() ;
};

#endif // SOLD_H