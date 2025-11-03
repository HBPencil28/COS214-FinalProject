#ifndef RETURNED_H
#define RETURNED_H

#include "PlantStatus.h"

class Returned : public PlantStatus {
public:
    Returned() = default;
    ~Returned() override = default;

    const char* code() const override { return "Returned"; }

    // as soon as we enter Returned, push back to InStorage
    void enter(Plant& plant) override;
};

#endif // RETURNED_H