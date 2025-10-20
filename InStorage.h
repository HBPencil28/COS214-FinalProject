#ifndef INSTORAGE_H
#define INSTORAGE_H

#include "PlantStatus.h"
class InStorage : public PlantStatus {
public:
    ~InStorage();

    std::string code();
    void apply();
    void revoke();
};

#endif // INSTORAGE_H