#ifndef RETURNED_H
#define RETURNED_H
#include "PlantStatus.h"
class Returned : public PlantStatus {
public:
    ~Returned();

    std::string code() const;
    void apply();
    void revoke();
};

#endif // RETURNED_H 