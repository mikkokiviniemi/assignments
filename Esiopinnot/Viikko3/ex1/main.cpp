#include <iostream>
#include "constants.h"

int main(){

    std::cout << "Distance (km): ";
    std::string distance;
    std::getline(std::cin, distance);

    std::cout << "Consumption (l/100km): ";
    std::string consumption;
    std::getline(std::cin, consumption);

    std::cout << "Fuel type (G/D): ";
    std::string type;
    std::getline(std::cin, type);

    float d = std::stof(distance);
    float c = std::stof(consumption);
    float cost;

    if(type == "G"){
        cost = GAS_PRICE;
    }else if(type == "D"){
        cost = DIESEL_PRICE;
    }


    std::cout << "Cost: "<< d*(c/100)* cost <<" €"<< std::endl;



    return 0;
}