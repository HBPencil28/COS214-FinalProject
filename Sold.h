#ifndef SOLD_H
#define SOLD_H

#include "PlantStatus.h"

class Sold : public PlantStatus {
public:
    const char* code() const override { return "Sold"; }
    void onReturn(Plant& p, const std::string& reason) override; // -> Returned
};

#endif // SOLD_H