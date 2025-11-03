#ifndef INSTORAGE_H
#define INSTORAGE_H

#include "PlantStatus.h"

class InStorage : public PlantStatus {
public:
    InStorage() = default;
    ~InStorage() override = default;

    const char* code() const override { return "InStorage"; }
    void onSell(Plant& p) override; // -> Sold
    void enter(Plant& p) override;// No action on enter
};

#endif // INSTORAGE_H