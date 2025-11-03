/**
 * @file order.h
 * @brief Defines the Order struct that represents plant purchase details.
 */

#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>

/**
 * @struct Order
 * @brief Represents a customer's plant order.
 */
struct Order {
    std::string base;       /**< @brief Type of base, e.g., "Potted" or "Wrapped". */
    std::string flowerName; /**< @brief Name of the flower type, e.g., "rose", "tulip". */
    int num;                /**< @brief Number of plants in the order. */
};

#endif
