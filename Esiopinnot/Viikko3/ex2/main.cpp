#include <iostream>
#include "constants.h"

int main(){


    std::cout << "Fuel type (G/D/E): ";
    std::string type;
    std::getline(std::cin, type);

    std::cout << "Distance (km): ";
    std::string distance;
    std::getline(std::cin, distance);

    float cost;
    std::string consumption;

    if(type == "G"){
        cost = GAS_PRICE;
        std::cout << "Consumption (l/100km): ";
        std::getline(std::cin, consumption);
    }else if(type == "D"){
        cost = DIESEL_PRICE;
        std::cout << "Consumption (l/100km): ";
        std::getline(std::cin, consumption);
    }else if(type == "E"){
        cost = ELECTRIC_PRICE;
        std::cout << "Consumption (kWh/100km): ";
        std::getline(std::cin, consumption);
    }


    float d = std::stof(distance);
    float c = std::stof(consumption);

    std::cout << "Cost: "<< d*(c/100)* cost <<" €"<< std::endl;



    return 0;
}