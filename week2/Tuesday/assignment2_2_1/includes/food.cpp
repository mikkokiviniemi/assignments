#include "food.h"

std::string Food::get_name() {
    return name;
}

float Food::get_price() {
    return price;
}

std::vector<std::string> Food::get_ingredients() {
    return ingredients;
}
