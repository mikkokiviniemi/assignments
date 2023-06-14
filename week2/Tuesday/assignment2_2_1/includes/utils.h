#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "food.h"

void print_menu (std::vector<Food> menu);

void print_order (std::vector<Food> order);

std::vector<Food> ordering_function (std::vector<Food>& menu);

Food new_food();

#endif  // FOOD_H