#ifndef OUTFORDELIVERY_H
#define OUTFORDELIVERY_H
#include "PlantStatus.h"

class OutForDelivery : public PlantStatus {
public:
    ~OutForDelivery();

    std::string code() const;
    void apply();
    void revoke();
};


#endif // OUTFORDELIVERY_H