#ifndef SOLD_H
#define SOLD_H

#include "PlantStatus.h"
#include <string>

class Sold : public PlantStatus {
public:
    Sold() = default;
    ~Sold() override = default;

    const char* code() const override { return "Sold"; }

    // allowed: sold -> returned (if customer brings it back)
    void onReturn(Plant& plant, const std::string& reason) override;
};

#endif // SOLD_H