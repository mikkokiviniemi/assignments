#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <string>
#include <vector>

struct Food {
    std::string name;
    float price;
    std::vector<std::string> ingredients;

    std::string get_name();
    float get_price();
    std::vector<std::string> get_ingredients();
};

#endif  // FOOD_H
