#ifndef RETURNED_H
#define RETURNED_H

#include "PlantStatus.h"
#include <string>

class Returned : public PlantStatus {
public:
    explicit Returned(std::string reason) : reason_(std::move(reason)) {}
    const char* code() const override { return "Returned"; }

    // As soon as we enter this state, we record the reason and go back to InStorage
    void enter(Plant& p) override;

private:
    std::string reason_;
};

#endif // RETURNED_H