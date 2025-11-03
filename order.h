#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>

struct Order{
    std::string base; // {values : ["Potted", "Wrapped"]}
    std::string flowerName; // {values : [rose, tulip, ectetera]}
    int num;
};

#endif